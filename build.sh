#!/bin/bash
cmake .
mkdir -p build && cd build
cmake --build ..
