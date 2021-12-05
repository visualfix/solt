// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MONSTER_MYNAMESPACE_H_
#define FLATBUFFERS_GENERATED_MONSTER_MYNAMESPACE_H_

#include "flatbuffers/flatbuffers.h"

#include "Vec3_generated.h"

namespace MyNameSpace {

struct Monster;
struct MonsterBuilder;

enum Color : int8_t {
  Color_Red = 1,
  Color_Green = 2,
  Color_Blue = 3,
  Color_MIN = Color_Red,
  Color_MAX = Color_Blue
};

inline const Color (&EnumValuesColor())[3] {
  static const Color values[] = {
    Color_Red,
    Color_Green,
    Color_Blue
  };
  return values;
}

inline const char * const *EnumNamesColor() {
  static const char * const names[4] = {
    "Red",
    "Green",
    "Blue",
    nullptr
  };
  return names;
}

inline const char *EnumNameColor(Color e) {
  if (flatbuffers::IsOutRange(e, Color_Red, Color_Blue)) return "";
  const size_t index = static_cast<size_t>(e) - static_cast<size_t>(Color_Red);
  return EnumNamesColor()[index];
}

struct Monster FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MonsterBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POS = 4,
    VT_MANA = 6,
    VT_HP = 8,
    VT_NAME = 10,
    VT_INVENTORY = 12,
    VT_COLOR = 14
  };
  const Vec3 *pos() const {
    return GetStruct<const Vec3 *>(VT_POS);
  }
  int16_t mana() const {
    return GetField<int16_t>(VT_MANA, 150);
  }
  int16_t hp() const {
    return GetField<int16_t>(VT_HP, 100);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<uint8_t> *inventory() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_INVENTORY);
  }
  MyNameSpace::Color color() const {
    return static_cast<MyNameSpace::Color>(GetField<int8_t>(VT_COLOR, 3));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<Vec3>(verifier, VT_POS) &&
           VerifyField<int16_t>(verifier, VT_MANA) &&
           VerifyField<int16_t>(verifier, VT_HP) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_INVENTORY) &&
           verifier.VerifyVector(inventory()) &&
           VerifyField<int8_t>(verifier, VT_COLOR) &&
           verifier.EndTable();
  }
};

struct MonsterBuilder {
  typedef Monster Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pos(const Vec3 *pos) {
    fbb_.AddStruct(Monster::VT_POS, pos);
  }
  void add_mana(int16_t mana) {
    fbb_.AddElement<int16_t>(Monster::VT_MANA, mana, 150);
  }
  void add_hp(int16_t hp) {
    fbb_.AddElement<int16_t>(Monster::VT_HP, hp, 100);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Monster::VT_NAME, name);
  }
  void add_inventory(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory) {
    fbb_.AddOffset(Monster::VT_INVENTORY, inventory);
  }
  void add_color(MyNameSpace::Color color) {
    fbb_.AddElement<int8_t>(Monster::VT_COLOR, static_cast<int8_t>(color), 3);
  }
  explicit MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Monster> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Monster>(end);
    return o;
  }
};

inline flatbuffers::Offset<Monster> CreateMonster(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Vec3 *pos = nullptr,
    int16_t mana = 150,
    int16_t hp = 100,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> inventory = 0,
    MyNameSpace::Color color = MyNameSpace::Color_Blue) {
  MonsterBuilder builder_(_fbb);
  builder_.add_inventory(inventory);
  builder_.add_name(name);
  builder_.add_pos(pos);
  builder_.add_hp(hp);
  builder_.add_mana(mana);
  builder_.add_color(color);
  return builder_.Finish();
}

inline flatbuffers::Offset<Monster> CreateMonsterDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Vec3 *pos = nullptr,
    int16_t mana = 150,
    int16_t hp = 100,
    const char *name = nullptr,
    const std::vector<uint8_t> *inventory = nullptr,
    MyNameSpace::Color color = MyNameSpace::Color_Blue) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto inventory__ = inventory ? _fbb.CreateVector<uint8_t>(*inventory) : 0;
  return MyNameSpace::CreateMonster(
      _fbb,
      pos,
      mana,
      hp,
      name__,
      inventory__,
      color);
}

inline const MyNameSpace::Monster *GetMonster(const void *buf) {
  return flatbuffers::GetRoot<MyNameSpace::Monster>(buf);
}

inline const MyNameSpace::Monster *GetSizePrefixedMonster(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<MyNameSpace::Monster>(buf);
}

inline bool VerifyMonsterBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<MyNameSpace::Monster>(nullptr);
}

inline bool VerifySizePrefixedMonsterBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<MyNameSpace::Monster>(nullptr);
}

inline void FinishMonsterBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<MyNameSpace::Monster> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedMonsterBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<MyNameSpace::Monster> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace MyNameSpace

#endif  // FLATBUFFERS_GENERATED_MONSTER_MYNAMESPACE_H_