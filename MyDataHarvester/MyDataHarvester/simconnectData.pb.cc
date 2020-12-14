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
namespace simConnect {
class simDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<simData> _instance;
} _simData_default_instance_;
}  // namespace simConnect
static void InitDefaultsscc_info_simData_simconnectData_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::simConnect::_simData_default_instance_;
    new (ptr) ::simConnect::simData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_simData_simconnectData_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_simData_simconnectData_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_simconnectData_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_simconnectData_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_simconnectData_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_simconnectData_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, sztitle_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dabsolutetime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dtime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, usimonground_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, daltitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dheading_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dspeed_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dverticalspeed_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dgpseta_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dlatitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dlongitude_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dsimtime_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dtemperature_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dairpressure_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dwindvelocity_),
  PROTOBUF_FIELD_OFFSET(::simConnect::simData, dwinddirection_),
  0,
  1,
  2,
  15,
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
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 21, sizeof(::simConnect::simData)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::simConnect::_simData_default_instance_),
};

const char descriptor_table_protodef_simconnectData_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024simconnectData.proto\022\nsimConnect\"\310\002\n\007s"
  "imData\022\017\n\007szTitle\030\001 \002(\t\022\025\n\rdAbsoluteTime"
  "\030\002 \002(\001\022\r\n\005dTime\030\003 \002(\001\022\024\n\014usimOnGround\030\004 "
  "\002(\005\022\021\n\tdAltitude\030\005 \002(\001\022\020\n\010dHeading\030\006 \002(\001"
  "\022\016\n\006dSpeed\030\007 \002(\001\022\026\n\016dVerticalSpeed\030\010 \002(\001"
  "\022\017\n\007dGpsEta\030\t \002(\001\022\021\n\tdLatitude\030\n \002(\001\022\022\n\n"
  "dLongitude\030\013 \002(\001\022\020\n\010dSimTime\030\014 \002(\001\022\024\n\014dT"
  "emperature\030\r \002(\001\022\024\n\014dAirPressure\030\016 \002(\001\022\025"
  "\n\rdWindVelocity\030\017 \002(\001\022\026\n\016dWindDirection\030"
  "\020 \002(\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_simconnectData_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_simconnectData_2eproto_sccs[1] = {
  &scc_info_simData_simconnectData_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_simconnectData_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_simconnectData_2eproto = {
  false, false, descriptor_table_protodef_simconnectData_2eproto, "simconnectData.proto", 365,
  &descriptor_table_simconnectData_2eproto_once, descriptor_table_simconnectData_2eproto_sccs, descriptor_table_simconnectData_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_simconnectData_2eproto::offsets,
  file_level_metadata_simconnectData_2eproto, 1, file_level_enum_descriptors_simconnectData_2eproto, file_level_service_descriptors_simconnectData_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_simconnectData_2eproto(&descriptor_table_simconnectData_2eproto);
namespace simConnect {

// ===================================================================

class simData::_Internal {
 public:
  using HasBits = decltype(std::declval<simData>()._has_bits_);
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
    (*has_bits)[0] |= 32768u;
  }
  static void set_has_daltitude(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_dheading(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_dspeed(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_dverticalspeed(HasBits* has_bits) {
    (*has_bits)[0] |= 64u;
  }
  static void set_has_dgpseta(HasBits* has_bits) {
    (*has_bits)[0] |= 128u;
  }
  static void set_has_dlatitude(HasBits* has_bits) {
    (*has_bits)[0] |= 256u;
  }
  static void set_has_dlongitude(HasBits* has_bits) {
    (*has_bits)[0] |= 512u;
  }
  static void set_has_dsimtime(HasBits* has_bits) {
    (*has_bits)[0] |= 1024u;
  }
  static void set_has_dtemperature(HasBits* has_bits) {
    (*has_bits)[0] |= 2048u;
  }
  static void set_has_dairpressure(HasBits* has_bits) {
    (*has_bits)[0] |= 4096u;
  }
  static void set_has_dwindvelocity(HasBits* has_bits) {
    (*has_bits)[0] |= 8192u;
  }
  static void set_has_dwinddirection(HasBits* has_bits) {
    (*has_bits)[0] |= 16384u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000ffff) ^ 0x0000ffff) != 0;
  }
};

simData::simData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:simConnect.simData)
}
simData::simData(const simData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  sztitle_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_sztitle()) {
    sztitle_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sztitle(), 
      GetArena());
  }
  ::memcpy(&dabsolutetime_, &from.dabsolutetime_,
    static_cast<size_t>(reinterpret_cast<char*>(&usimonground_) -
    reinterpret_cast<char*>(&dabsolutetime_)) + sizeof(usimonground_));
  // @@protoc_insertion_point(copy_constructor:simConnect.simData)
}

void simData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_simData_simconnectData_2eproto.base);
  sztitle_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&dabsolutetime_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&usimonground_) -
      reinterpret_cast<char*>(&dabsolutetime_)) + sizeof(usimonground_));
}

simData::~simData() {
  // @@protoc_insertion_point(destructor:simConnect.simData)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void simData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  sztitle_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void simData::ArenaDtor(void* object) {
  simData* _this = reinterpret_cast< simData* >(object);
  (void)_this;
}
void simData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void simData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const simData& simData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_simData_simconnectData_2eproto.base);
  return *internal_default_instance();
}


void simData::Clear() {
// @@protoc_insertion_point(message_clear_start:simConnect.simData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    sztitle_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x000000feu) {
    ::memset(&dabsolutetime_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&dgpseta_) -
        reinterpret_cast<char*>(&dabsolutetime_)) + sizeof(dgpseta_));
  }
  if (cached_has_bits & 0x0000ff00u) {
    ::memset(&dlatitude_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&usimonground_) -
        reinterpret_cast<char*>(&dlatitude_)) + sizeof(usimonground_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* simData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string szTitle = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_sztitle();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "simConnect.simData.szTitle");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required double dAbsoluteTime = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          _Internal::set_has_dabsolutetime(&has_bits);
          dabsolutetime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dTime = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          _Internal::set_has_dtime(&has_bits);
          dtime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required int32 usimOnGround = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_usimonground(&has_bits);
          usimonground_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required double dAltitude = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          _Internal::set_has_daltitude(&has_bits);
          daltitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dHeading = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 49)) {
          _Internal::set_has_dheading(&has_bits);
          dheading_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dSpeed = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 57)) {
          _Internal::set_has_dspeed(&has_bits);
          dspeed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dVerticalSpeed = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 65)) {
          _Internal::set_has_dverticalspeed(&has_bits);
          dverticalspeed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dGpsEta = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 73)) {
          _Internal::set_has_dgpseta(&has_bits);
          dgpseta_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dLatitude = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 81)) {
          _Internal::set_has_dlatitude(&has_bits);
          dlatitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dLongitude = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 89)) {
          _Internal::set_has_dlongitude(&has_bits);
          dlongitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dSimTime = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 97)) {
          _Internal::set_has_dsimtime(&has_bits);
          dsimtime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dTemperature = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 105)) {
          _Internal::set_has_dtemperature(&has_bits);
          dtemperature_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dAirPressure = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 113)) {
          _Internal::set_has_dairpressure(&has_bits);
          dairpressure_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dWindVelocity = 15;
      case 15:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 121)) {
          _Internal::set_has_dwindvelocity(&has_bits);
          dwindvelocity_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // required double dWindDirection = 16;
      case 16:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 129)) {
          _Internal::set_has_dwinddirection(&has_bits);
          dwinddirection_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* simData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:simConnect.simData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
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
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_dabsolutetime(), target);
  }

  // required double dTime = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_dtime(), target);
  }

  // required int32 usimOnGround = 4;
  if (cached_has_bits & 0x00008000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_usimonground(), target);
  }

  // required double dAltitude = 5;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(5, this->_internal_daltitude(), target);
  }

  // required double dHeading = 6;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(6, this->_internal_dheading(), target);
  }

  // required double dSpeed = 7;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(7, this->_internal_dspeed(), target);
  }

  // required double dVerticalSpeed = 8;
  if (cached_has_bits & 0x00000040u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(8, this->_internal_dverticalspeed(), target);
  }

  // required double dGpsEta = 9;
  if (cached_has_bits & 0x00000080u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(9, this->_internal_dgpseta(), target);
  }

  // required double dLatitude = 10;
  if (cached_has_bits & 0x00000100u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(10, this->_internal_dlatitude(), target);
  }

  // required double dLongitude = 11;
  if (cached_has_bits & 0x00000200u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(11, this->_internal_dlongitude(), target);
  }

  // required double dSimTime = 12;
  if (cached_has_bits & 0x00000400u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(12, this->_internal_dsimtime(), target);
  }

  // required double dTemperature = 13;
  if (cached_has_bits & 0x00000800u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(13, this->_internal_dtemperature(), target);
  }

  // required double dAirPressure = 14;
  if (cached_has_bits & 0x00001000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(14, this->_internal_dairpressure(), target);
  }

  // required double dWindVelocity = 15;
  if (cached_has_bits & 0x00002000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(15, this->_internal_dwindvelocity(), target);
  }

  // required double dWindDirection = 16;
  if (cached_has_bits & 0x00004000u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(16, this->_internal_dwinddirection(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
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

  if (_internal_has_usimonground()) {
    // required int32 usimOnGround = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_usimonground());
  }

  return total_size;
}
size_t simData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:simConnect.simData)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000ffff) ^ 0x0000ffff) == 0) {  // All required fields are present.
    // required string szTitle = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sztitle());

    // required double dAbsoluteTime = 2;
    total_size += 1 + 8;

    // required double dTime = 3;
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

    // required int32 usimOnGround = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_usimonground());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void simData::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:simConnect.simData)
  GOOGLE_DCHECK_NE(&from, this);
  const simData* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<simData>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:simConnect.simData)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:simConnect.simData)
    MergeFrom(*source);
  }
}

void simData::MergeFrom(const simData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:simConnect.simData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_sztitle(from._internal_sztitle());
    }
    if (cached_has_bits & 0x00000002u) {
      dabsolutetime_ = from.dabsolutetime_;
    }
    if (cached_has_bits & 0x00000004u) {
      dtime_ = from.dtime_;
    }
    if (cached_has_bits & 0x00000008u) {
      daltitude_ = from.daltitude_;
    }
    if (cached_has_bits & 0x00000010u) {
      dheading_ = from.dheading_;
    }
    if (cached_has_bits & 0x00000020u) {
      dspeed_ = from.dspeed_;
    }
    if (cached_has_bits & 0x00000040u) {
      dverticalspeed_ = from.dverticalspeed_;
    }
    if (cached_has_bits & 0x00000080u) {
      dgpseta_ = from.dgpseta_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 0x0000ff00u) {
    if (cached_has_bits & 0x00000100u) {
      dlatitude_ = from.dlatitude_;
    }
    if (cached_has_bits & 0x00000200u) {
      dlongitude_ = from.dlongitude_;
    }
    if (cached_has_bits & 0x00000400u) {
      dsimtime_ = from.dsimtime_;
    }
    if (cached_has_bits & 0x00000800u) {
      dtemperature_ = from.dtemperature_;
    }
    if (cached_has_bits & 0x00001000u) {
      dairpressure_ = from.dairpressure_;
    }
    if (cached_has_bits & 0x00002000u) {
      dwindvelocity_ = from.dwindvelocity_;
    }
    if (cached_has_bits & 0x00004000u) {
      dwinddirection_ = from.dwinddirection_;
    }
    if (cached_has_bits & 0x00008000u) {
      usimonground_ = from.usimonground_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void simData::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:simConnect.simData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void simData::CopyFrom(const simData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:simConnect.simData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool simData::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void simData::InternalSwap(simData* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  sztitle_.Swap(&other->sztitle_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(simData, usimonground_)
      + sizeof(simData::usimonground_)
      - PROTOBUF_FIELD_OFFSET(simData, dabsolutetime_)>(
          reinterpret_cast<char*>(&dabsolutetime_),
          reinterpret_cast<char*>(&other->dabsolutetime_));
}

::PROTOBUF_NAMESPACE_ID::Metadata simData::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace simConnect
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::simConnect::simData* Arena::CreateMaybeMessage< ::simConnect::simData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::simConnect::simData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
