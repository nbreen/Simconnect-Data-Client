// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simconnectData.proto

#include "simconnectData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace simConnect {
PROTOBUF_CONSTEXPR simData::simData(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.sztitle_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.dabsolutetime_)*/0
  , /*decltype(_impl_.dtime_)*/0
  , /*decltype(_impl_.usimonground_)*/0
  , /*decltype(_impl_.daltitude_)*/0
  , /*decltype(_impl_.dheading_)*/0
  , /*decltype(_impl_.dspeed_)*/0
  , /*decltype(_impl_.dverticalspeed_)*/0
  , /*decltype(_impl_.dgpseta_)*/0
  , /*decltype(_impl_.dlatitude_)*/0
  , /*decltype(_impl_.dlongitude_)*/0
  , /*decltype(_impl_.dsimtime_)*/0
  , /*decltype(_impl_.dtemperature_)*/0
  , /*decltype(_impl_.dairpressure_)*/0
  , /*decltype(_impl_.dwindvelocity_)*/0
  , /*decltype(_impl_.dwinddirection_)*/0} {}
struct simDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR simDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~simDataDefaultTypeInternal() {}
  union {
    simData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 simDataDefaultTypeInternal _simData_default_instance_;
}  // namespace simConnect
static ::_pb::Metadata file_level_metadata_simconnectData_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_simconnectData_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_simconnectData_2eproto = nullptr;

const uint32_t TableStruct_simconnectData_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.sztitle_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dabsolutetime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dtime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.usimonground_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.daltitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dheading_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dspeed_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dverticalspeed_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dgpseta_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dlatitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dlongitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dsimtime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dtemperature_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dairpressure_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dwindvelocity_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _impl_.dwinddirection_),
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 22, -1, sizeof(::simConnect::simData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::simConnect::_simData_default_instance_._instance,
};

const char descriptor_table_protodef_simconnectData_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024simconnectData.proto\022\nsimConnect\"\310\002\n\007s"
  "imData\022\017\n\007szTitle\030\001 \002(\t\022\025\n\rdAbsoluteTime"
  "\030\002 \002(\001\022\r\n\005dTime\030\003 \002(\001\022\024\n\014usimOnGround\030\004 "
  "\002(\001\022\021\n\tdAltitude\030\005 \002(\001\022\020\n\010dHeading\030\006 \002(\001"
  "\022\016\n\006dSpeed\030\007 \002(\001\022\026\n\016dVerticalSpeed\030\010 \002(\001"
  "\022\017\n\007dGpsEta\030\t \002(\001\022\021\n\tdLatitude\030\n \002(\001\022\022\n\n"
  "dLongitude\030\013 \002(\001\022\020\n\010dSimTime\030\014 \002(\001\022\024\n\014dT"
  "emperature\030\r \002(\001\022\024\n\014dAirPressure\030\016 \002(\001\022\025"
  "\n\rdWindVelocity\030\017 \002(\001\022\026\n\016dWindDirection\030"
  "\020 \002(\001"
  ;
static ::_pbi::once_flag descriptor_table_simconnectData_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_simconnectData_2eproto = {
    false, false, 365, descriptor_table_protodef_simconnectData_2eproto,
    "simconnectData.proto",
    &descriptor_table_simconnectData_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_simconnectData_2eproto::offsets,
    file_level_metadata_simconnectData_2eproto, file_level_enum_descriptors_simconnectData_2eproto,
    file_level_service_descriptors_simconnectData_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_simconnectData_2eproto_getter() {
  return &descriptor_table_simconnectData_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_simconnectData_2eproto(&descriptor_table_simconnectData_2eproto);
namespace simConnect {

// ===================================================================

class simData::_Internal {
 public:
  using HasBits = decltype(std::declval<simData>()._impl_._has_bits_);
  static void set_has_sztitle(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_dabsolutetime(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_dtime(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_usimonground(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_daltitude(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_dheading(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_dspeed(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_dverticalspeed(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_dgpseta(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_dlatitude(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static void set_has_dlongitude(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
  static void set_has_dsimtime(HasBits* has_bits) {
    (*has_bits)[0] |= 2048u;
  }
  static void set_has_dtemperature(HasBits* has_bits) {
    (*has_bits)[0] |= 4096u;
  }
  static void set_has_dairpressure(HasBits* has_bits) {
    (*has_bits)[0] |= 8192u;
  }
  static void set_has_dwindvelocity(HasBits* has_bits) {
    (*has_bits)[0] |= 16384u;
  }
  static void set_has_dwinddirection(HasBits* has_bits) {
    (*has_bits)[0] |= 32768u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000ffff) ^ 0x0000ffff) != 0;
  }
};

simData::simData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:simConnect.simData)
}
simData::simData(const simData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  simData* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.sztitle_){}
    , decltype(_impl_.dabsolutetime_){}
    , decltype(_impl_.dtime_){}
    , decltype(_impl_.usimonground_){}
    , decltype(_impl_.daltitude_){}
    , decltype(_impl_.dheading_){}
    , decltype(_impl_.dspeed_){}
    , decltype(_impl_.dverticalspeed_){}
    , decltype(_impl_.dgpseta_){}
    , decltype(_impl_.dlatitude_){}
    , decltype(_impl_.dlongitude_){}
    , decltype(_impl_.dsimtime_){}
    , decltype(_impl_.dtemperature_){}
    , decltype(_impl_.dairpressure_){}
    , decltype(_impl_.dwindvelocity_){}
    , decltype(_impl_.dwinddirection_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.sztitle_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sztitle_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_sztitle()) {
    _this->_impl_.sztitle_.Set(from._internal_sztitle(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.dabsolutetime_, &from._impl_.dabsolutetime_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.dwinddirection_) -
    reinterpret_cast<char*>(&_impl_.dabsolutetime_)) + sizeof(_impl_.dwinddirection_));
  // @@protoc_insertion_point(copy_constructor:simConnect.simData)
}

inline void simData::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.sztitle_){}
    , decltype(_impl_.dabsolutetime_){0}
    , decltype(_impl_.dtime_){0}
    , decltype(_impl_.usimonground_){0}
    , decltype(_impl_.daltitude_){0}
    , decltype(_impl_.dheading_){0}
    , decltype(_impl_.dspeed_){0}
    , decltype(_impl_.dverticalspeed_){0}
    , decltype(_impl_.dgpseta_){0}
    , decltype(_impl_.dlatitude_){0}
    , decltype(_impl_.dlongitude_){0}
    , decltype(_impl_.dsimtime_){0}
    , decltype(_impl_.dtemperature_){0}
    , decltype(_impl_.dairpressure_){0}
    , decltype(_impl_.dwindvelocity_){0}
    , decltype(_impl_.dwinddirection_){0}
  };
  _impl_.sztitle_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.sztitle_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

simData::~simData() {
  // @@protoc_insertion_point(destructor:simConnect.simData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void simData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.sztitle_.Destroy();
}

void simData::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void simData::Clear() {
// @@protoc_insertion_point(message_clear_start:simConnect.simData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.sztitle_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x000000feu) {
    ::memset(&_impl_.dabsolutetime_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&_impl_.dverticalspeed_) -
        reinterpret_cast<char*>(&_impl_.dabsolutetime_)) + sizeof(_impl_.dverticalspeed_));
  }
  if (cached_has_bits & 0x0000ff00u) {
    ::memset(&_impl_.dgpseta_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&_impl_.dwinddirection_) -
        reinterpret_cast<char*>(&_impl_.dgpseta_)) + sizeof(_impl_.dwinddirection_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* simData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required string szTitle = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_sztitle();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          #ifndef NDEBUG
          ::_pbi::VerifyUTF8(str, "simConnect.simData.szTitle");
          #endif  // !NDEBUG
        } else
          goto handle_unusual;
        continue;
      // required double dAbsoluteTime = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 17)) {
          _Internal::set_has_dabsolutetime(&has_bits);
          _impl_.dabsolutetime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dTime = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          _Internal::set_has_dtime(&has_bits);
          _impl_.dtime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double usimOnGround = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 33)) {
          _Internal::set_has_usimonground(&has_bits);
          _impl_.usimonground_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dAltitude = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 41)) {
          _Internal::set_has_daltitude(&has_bits);
          _impl_.daltitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dHeading = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 49)) {
          _Internal::set_has_dheading(&has_bits);
          _impl_.dheading_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dSpeed = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 57)) {
          _Internal::set_has_dspeed(&has_bits);
          _impl_.dspeed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dVerticalSpeed = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 65)) {
          _Internal::set_has_dverticalspeed(&has_bits);
          _impl_.dverticalspeed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dGpsEta = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 73)) {
          _Internal::set_has_dgpseta(&has_bits);
          _impl_.dgpseta_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dLatitude = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 81)) {
          _Internal::set_has_dlatitude(&has_bits);
          _impl_.dlatitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dLongitude = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 89)) {
          _Internal::set_has_dlongitude(&has_bits);
          _impl_.dlongitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dSimTime = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 97)) {
          _Internal::set_has_dsimtime(&has_bits);
          _impl_.dsimtime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dTemperature = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 105)) {
          _Internal::set_has_dtemperature(&has_bits);
          _impl_.dtemperature_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dAirPressure = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 113)) {
          _Internal::set_has_dairpressure(&has_bits);
          _impl_.dairpressure_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dWindVelocity = 15;
      case 15:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 121)) {
          _Internal::set_has_dwindvelocity(&has_bits);
          _impl_.dwindvelocity_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // required double dWindDirection = 16;
      case 16:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 129)) {
          _Internal::set_has_dwinddirection(&has_bits);
          _impl_.dwinddirection_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* simData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:simConnect.simData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // required string szTitle = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_sztitle().data(), static_cast<int>(this->_internal_sztitle().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "simConnect.simData.szTitle");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sztitle(), target);
  }

  // required double dAbsoluteTime = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(2, this->_internal_dabsolutetime(), target);
  }

  // required double dTime = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(3, this->_internal_dtime(), target);
  }

  // required double usimOnGround = 4;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(4, this->_internal_usimonground(), target);
  }

  // required double dAltitude = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(5, this->_internal_daltitude(), target);
  }

  // required double dHeading = 6;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(6, this->_internal_dheading(), target);
  }

  // required double dSpeed = 7;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(7, this->_internal_dspeed(), target);
  }

  // required double dVerticalSpeed = 8;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(8, this->_internal_dverticalspeed(), target);
  }

  // required double dGpsEta = 9;
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(9, this->_internal_dgpseta(), target);
  }

  // required double dLatitude = 10;
  if (cached_has_bits & 0x00000200u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(10, this->_internal_dlatitude(), target);
  }

  // required double dLongitude = 11;
  if (cached_has_bits & 0x00000400u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(11, this->_internal_dlongitude(), target);
  }

  // required double dSimTime = 12;
  if (cached_has_bits & 0x00000800u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(12, this->_internal_dsimtime(), target);
  }

  // required double dTemperature = 13;
  if (cached_has_bits & 0x00001000u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(13, this->_internal_dtemperature(), target);
  }

  // required double dAirPressure = 14;
  if (cached_has_bits & 0x00002000u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(14, this->_internal_dairpressure(), target);
  }

  // required double dWindVelocity = 15;
  if (cached_has_bits & 0x00004000u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(15, this->_internal_dwindvelocity(), target);
  }

  // required double dWindDirection = 16;
  if (cached_has_bits & 0x00008000u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(16, this->_internal_dwinddirection(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:simConnect.simData)
  return target;
}

size_t simData::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:simConnect.simData)
  size_t total_size = 0;

  if (_internal_has_sztitle()) {
    // required string szTitle = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sztitle());
  }

  if (_internal_has_dabsolutetime()) {
    // required double dAbsoluteTime = 2;
    total_size += 1 + 8;
  }

  if (_internal_has_dtime()) {
    // required double dTime = 3;
    total_size += 1 + 8;
  }

  if (_internal_has_usimonground()) {
    // required double usimOnGround = 4;
    total_size += 1 + 8;
  }

  if (_internal_has_daltitude()) {
    // required double dAltitude = 5;
    total_size += 1 + 8;
  }

  if (_internal_has_dheading()) {
    // required double dHeading = 6;
    total_size += 1 + 8;
  }

  if (_internal_has_dspeed()) {
    // required double dSpeed = 7;
    total_size += 1 + 8;
  }

  if (_internal_has_dverticalspeed()) {
    // required double dVerticalSpeed = 8;
    total_size += 1 + 8;
  }

  if (_internal_has_dgpseta()) {
    // required double dGpsEta = 9;
    total_size += 1 + 8;
  }

  if (_internal_has_dlatitude()) {
    // required double dLatitude = 10;
    total_size += 1 + 8;
  }

  if (_internal_has_dlongitude()) {
    // required double dLongitude = 11;
    total_size += 1 + 8;
  }

  if (_internal_has_dsimtime()) {
    // required double dSimTime = 12;
    total_size += 1 + 8;
  }

  if (_internal_has_dtemperature()) {
    // required double dTemperature = 13;
    total_size += 1 + 8;
  }

  if (_internal_has_dairpressure()) {
    // required double dAirPressure = 14;
    total_size += 1 + 8;
  }

  if (_internal_has_dwindvelocity()) {
    // required double dWindVelocity = 15;
    total_size += 1 + 8;
  }

  if (_internal_has_dwinddirection()) {
    // required double dWindDirection = 16;
    total_size += 2 + 8;
  }

  return total_size;
}
size_t simData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:simConnect.simData)
  size_t total_size = 0;

  if (((_impl_._has_bits_[0] & 0x0000ffff) ^ 0x0000ffff) == 0) {  // All required fields are present.
    // required string szTitle = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sztitle());

    // required double dAbsoluteTime = 2;
    total_size += 1 + 8;

    // required double dTime = 3;
    total_size += 1 + 8;

    // required double usimOnGround = 4;
    total_size += 1 + 8;

    // required double dAltitude = 5;
    total_size += 1 + 8;

    // required double dHeading = 6;
    total_size += 1 + 8;

    // required double dSpeed = 7;
    total_size += 1 + 8;

    // required double dVerticalSpeed = 8;
    total_size += 1 + 8;

    // required double dGpsEta = 9;
    total_size += 1 + 8;

    // required double dLatitude = 10;
    total_size += 1 + 8;

    // required double dLongitude = 11;
    total_size += 1 + 8;

    // required double dSimTime = 12;
    total_size += 1 + 8;

    // required double dTemperature = 13;
    total_size += 1 + 8;

    // required double dAirPressure = 14;
    total_size += 1 + 8;

    // required double dWindVelocity = 15;
    total_size += 1 + 8;

    // required double dWindDirection = 16;
    total_size += 2 + 8;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData simData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    simData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*simData::GetClassData() const { return &_class_data_; }


void simData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<simData*>(&to_msg);
  auto& from = static_cast<const simData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:simConnect.simData)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_sztitle(from._internal_sztitle());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.dabsolutetime_ = from._impl_.dabsolutetime_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.dtime_ = from._impl_.dtime_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.usimonground_ = from._impl_.usimonground_;
    }
    if (cached_has_bits & 0x00000010u) {
      _this->_impl_.daltitude_ = from._impl_.daltitude_;
    }
    if (cached_has_bits & 0x00000020u) {
      _this->_impl_.dheading_ = from._impl_.dheading_;
    }
    if (cached_has_bits & 0x00000040u) {
      _this->_impl_.dspeed_ = from._impl_.dspeed_;
    }
    if (cached_has_bits & 0x00000080u) {
      _this->_impl_.dverticalspeed_ = from._impl_.dverticalspeed_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x0000ff00u) {
    if (cached_has_bits & 0x00000100u) {
      _this->_impl_.dgpseta_ = from._impl_.dgpseta_;
    }
    if (cached_has_bits & 0x00000200u) {
      _this->_impl_.dlatitude_ = from._impl_.dlatitude_;
    }
    if (cached_has_bits & 0x00000400u) {
      _this->_impl_.dlongitude_ = from._impl_.dlongitude_;
    }
    if (cached_has_bits & 0x00000800u) {
      _this->_impl_.dsimtime_ = from._impl_.dsimtime_;
    }
    if (cached_has_bits & 0x00001000u) {
      _this->_impl_.dtemperature_ = from._impl_.dtemperature_;
    }
    if (cached_has_bits & 0x00002000u) {
      _this->_impl_.dairpressure_ = from._impl_.dairpressure_;
    }
    if (cached_has_bits & 0x00004000u) {
      _this->_impl_.dwindvelocity_ = from._impl_.dwindvelocity_;
    }
    if (cached_has_bits & 0x00008000u) {
      _this->_impl_.dwinddirection_ = from._impl_.dwinddirection_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void simData::CopyFrom(const simData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:simConnect.simData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool simData::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_impl_._has_bits_)) return false;
  return true;
}

void simData::InternalSwap(simData* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.sztitle_, lhs_arena,
      &other->_impl_.sztitle_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(simData, _impl_.dwinddirection_)
      + sizeof(simData::_impl_.dwinddirection_)
      - PROTOBUF_FIELD_OFFSET(simData, _impl_.dabsolutetime_)>(
          reinterpret_cast<char*>(&_impl_.dabsolutetime_),
          reinterpret_cast<char*>(&other->_impl_.dabsolutetime_));
}

::PROTOBUF_NAMESPACE_ID::Metadata simData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_simconnectData_2eproto_getter, &descriptor_table_simconnectData_2eproto_once,
      file_level_metadata_simconnectData_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace simConnect
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::simConnect::simData*
Arena::CreateMaybeMessage< ::simConnect::simData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::simConnect::simData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>