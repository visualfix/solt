//
// chat_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <asio.hpp>
#include <RootTest_generated.h>
#include <Monster_generated.h>

using asio::ip::tcp;

typedef std::deque<std::string> chat_message_queue;

void Log(const std::string& log)
{
  std::cout << log << std::endl;
}

class chat_client
{
public:
  chat_client(asio::io_context& io_context,
      const tcp::resolver::results_type& endpoints)
    : io_context_(io_context),
      socket_(io_context)
  {
    do_connect(endpoints);
  }

  void write(const std::string& msg)
  {
    Log("write :" + msg);

    asio::post(io_context_,
        [this, msg]()
        {
          bool write_in_progress = !write_msgs_.empty();
          write_msgs_.push_back(msg + "\n");
          if (!write_in_progress)
          {
            do_write();
          }
        });
  }

  void close()
  {
    asio::post(io_context_, [this]() { socket_.close(); });
  }

private:
  void do_connect(const tcp::resolver::results_type& endpoints)
  {
    Log("do_connect");
    asio::async_connect(socket_, endpoints,
        [this](std::error_code ec, tcp::endpoint)
        {
          if (!ec)
          {
            do_read_body();
          }
        });
  }

  void do_read_body()
  {
    Log("do_read_body");

    asio::async_read(socket_, asio::dynamic_buffer(buffer_),
        [this](std::error_code ec, std::size_t length)
        {
          auto buff = (uint8_t*)buffer_.data();
          auto verifier = flatbuffers::Verifier(buff, length);
          if (!ec && VerifyRootTestBuffer(verifier))
          {
            auto test = GetRootTest(buff);

            //std::cout.write(buffer_, length);
            std::cout << "HP: " << test->hp() << std::endl;
            std::cout << "Mana: " << test->mana() << std::endl;
            std::cout << "Pos: " << test->pos()->z() << std::endl;
            buffer_.clear();
            do_read_body();
          }
          else
          {
            socket_.close();
          }
        });
  }

  void do_write()
  {
    Log("do_write");

    flatbuffers::FlatBufferBuilder builder;
    auto data = Vec3(1,2,3);
    auto packet = CreateRootTest(builder, &data, 10, 10);
    
    builder.Finish(packet);

    n = builder.GetSize();
    memcpy(sendBuffer, builder.GetBufferPointer(), builder.GetSize());

    asio::async_write(socket_,
        asio::buffer(sendBuffer, n),
        [this](std::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
              do_write();
            }
          }
          else
          {
            socket_.close();
          }
        });
  }

private:
  char sendBuffer[1024];
  size_t n;

  asio::io_context& io_context_;
  tcp::socket socket_;
  std::string buffer_;
  chat_message_queue write_msgs_;
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: chat_client <host> <port>\n";
      return 1;
    }

    asio::io_context io_context;

    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(argv[1], argv[2]);
    chat_client c(io_context, endpoints);

    std::thread t([&io_context](){ io_context.run(); });

    char line[1024 + 1];
    while (std::cin.getline(line, 1024 + 1))
    {
      c.write(std::string(line));
    }

    c.close();
    t.join();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}