// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simconnectData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_simconnectData_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_simconnectData_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_simconnectData_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_simconnectData_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_simconnectData_2eproto;
namespace simConnect {
class simData;
class simDataDefaultTypeInternal;
extern simDataDefaultTypeInternal _simData_default_instance_;
}  // namespace simConnect
PROTOBUF_NAMESPACE_OPEN
template<> ::simConnect::simData* Arena::CreateMaybeMessage<::simConnect::simData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace simConnect {

// ===================================================================

class simData PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:simConnect.simData) */ {
 public:
  inline simData() : simData(nullptr) {}
  virtual ~simData();

  simData(const simData& from);
  simData(simData&& from) noexcept
    : simData() {
    *this = ::std::move(from);
  }

  inline simData& operator=(const simData& from) {
    CopyFrom(from);
    return *this;
  }
  inline simData& operator=(simData&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const simData& default_instance();

  static inline const simData* internal_default_instance() {
    return reinterpret_cast<const simData*>(
               &_simData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(simData& a, simData& b) {
    a.Swap(&b);
  }
  inline void Swap(simData* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(simData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline simData* New() const final {
    return CreateMaybeMessage<simData>(nullptr);
  }

  simData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<simData>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const simData& from);
  void MergeFrom(const simData& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(simData* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "simConnect.simData";
  }
  protected:
  explicit simData(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_simconnectData_2eproto);
    return ::descriptor_table_simconnectData_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSzTitleFieldNumber = 1,
    kDAbsoluteTimeFieldNumber = 2,
    kDTimeFieldNumber = 3,
    kDAltitudeFieldNumber = 5,
    kDHeadingFieldNumber = 6,
    kDSpeedFieldNumber = 7,
    kDVerticalSpeedFieldNumber = 8,
    kDGpsEtaFieldNumber = 9,
    kDLatitudeFieldNumber = 10,
    kDLongitudeFieldNumber = 11,
    kDSimTimeFieldNumber = 12,
    kDTemperatureFieldNumber = 13,
    kDAirPressureFieldNumber = 14,
    kDWindVelocityFieldNumber = 15,
    kDWindDirectionFieldNumber = 16,
    kUsimOnGroundFieldNumber = 4,
  };
  // required string szTitle = 1;
  bool has_sztitle() const;
  private:
  bool _internal_has_sztitle() const;
  public:
  void clear_sztitle();
  const std::string& sztitle() const;
  void set_sztitle(const std::string& value);
  void set_sztitle(std::string&& value);
  void set_sztitle(const char* value);
  void set_sztitle(const char* value, size_t size);
  std::string* mutable_sztitle();
  std::string* release_sztitle();
  void set_allocated_sztitle(std::string* sztitle);
  private:
  const std::string& _internal_sztitle() const;
  void _internal_set_sztitle(const std::string& value);
  std::string* _internal_mutable_sztitle();
  public:

  // required double dAbsoluteTime = 2;
  bool has_dabsolutetime() const;
  private:
  bool _internal_has_dabsolutetime() const;
  public:
  void clear_dabsolutetime();
  double dabsolutetime() const;
  void set_dabsolutetime(double value);
  private:
  double _internal_dabsolutetime() const;
  void _internal_set_dabsolutetime(double value);
  public:

  // required double dTime = 3;
  bool has_dtime() const;
  private:
  bool _internal_has_dtime() const;
  public:
  void clear_dtime();
  double dtime() const;
  void set_dtime(double value);
  private:
  double _internal_dtime() const;
  void _internal_set_dtime(double value);
  public:

  // required double dAltitude = 5;
  bool has_daltitude() const;
  private:
  bool _internal_has_daltitude() const;
  public:
  void clear_daltitude();
  double daltitude() const;
  void set_daltitude(double value);
  private:
  double _internal_daltitude() const;
  void _internal_set_daltitude(double value);
  public:

  // required double dHeading = 6;
  bool has_dheading() const;
  private:
  bool _internal_has_dheading() const;
  public:
  void clear_dheading();
  double dheading() const;
  void set_dheading(double value);
  private:
  double _internal_dheading() const;
  void _internal_set_dheading(double value);
  public:

  // required double dSpeed = 7;
  bool has_dspeed() const;
  private:
  bool _internal_has_dspeed() const;
  public:
  void clear_dspeed();
  double dspeed() const;
  void set_dspeed(double value);
  private:
  double _internal_dspeed() const;
  void _internal_set_dspeed(double value);
  public:

  // required double dVerticalSpeed = 8;
  bool has_dverticalspeed() const;
  private:
  bool _internal_has_dverticalspeed() const;
  public:
  void clear_dverticalspeed();
  double dverticalspeed() const;
  void set_dverticalspeed(double value);
  private:
  double _internal_dverticalspeed() const;
  void _internal_set_dverticalspeed(double value);
  public:

  // required double dGpsEta = 9;
  bool has_dgpseta() const;
  private:
  bool _internal_has_dgpseta() const;
  public:
  void clear_dgpseta();
  double dgpseta() const;
  void set_dgpseta(double value);
  private:
  double _internal_dgpseta() const;
  void _internal_set_dgpseta(double value);
  public:

  // required double dLatitude = 10;
  bool has_dlatitude() const;
  private:
  bool _internal_has_dlatitude() const;
  public:
  void clear_dlatitude();
  double dlatitude() const;
  void set_dlatitude(double value);
  private:
  double _internal_dlatitude() const;
  void _internal_set_dlatitude(double value);
  public:

  // required double dLongitude = 11;
  bool has_dlongitude() const;
  private:
  bool _internal_has_dlongitude() const;
  public:
  void clear_dlongitude();
  double dlongitude() const;
  void set_dlongitude(double value);
  private:
  double _internal_dlongitude() const;
  void _internal_set_dlongitude(double value);
  public:

  // required double dSimTime = 12;
  bool has_dsimtime() const;
  private:
  bool _internal_has_dsimtime() const;
  public:
  void clear_dsimtime();
  double dsimtime() const;
  void set_dsimtime(double value);
  private:
  double _internal_dsimtime() const;
  void _internal_set_dsimtime(double value);
  public:

  // required double dTemperature = 13;
  bool has_dtemperature() const;
  private:
  bool _internal_has_dtemperature() const;
  public:
  void clear_dtemperature();
  double dtemperature() const;
  void set_dtemperature(double value);
  private:
  double _internal_dtemperature() const;
  void _internal_set_dtemperature(double value);
  public:

  // required double dAirPressure = 14;
  bool has_dairpressure() const;
  private:
  bool _internal_has_dairpressure() const;
  public:
  void clear_dairpressure();
  double dairpressure() const;
  void set_dairpressure(double value);
  private:
  double _internal_dairpressure() const;
  void _internal_set_dairpressure(double value);
  public:

  // required double dWindVelocity = 15;
  bool has_dwindvelocity() const;
  private:
  bool _internal_has_dwindvelocity() const;
  public:
  void clear_dwindvelocity();
  double dwindvelocity() const;
  void set_dwindvelocity(double value);
  private:
  double _internal_dwindvelocity() const;
  void _internal_set_dwindvelocity(double value);
  public:

  // required double dWindDirection = 16;
  bool has_dwinddirection() const;
  private:
  bool _internal_has_dwinddirection() const;
  public:
  void clear_dwinddirection();
  double dwinddirection() const;
  void set_dwinddirection(double value);
  private:
  double _internal_dwinddirection() const;
  void _internal_set_dwinddirection(double value);
  public:

  // required int32 usimOnGround = 4;
  bool has_usimonground() const;
  private:
  bool _internal_has_usimonground() const;
  public:
  void clear_usimonground();
  ::PROTOBUF_NAMESPACE_ID::int32 usimonground() const;
  void set_usimonground(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_usimonground() const;
  void _internal_set_usimonground(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:simConnect.simData)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sztitle_;
  double dabsolutetime_;
  double dtime_;
  double daltitude_;
  double dheading_;
  double dspeed_;
  double dverticalspeed_;
  double dgpseta_;
  double dlatitude_;
  double dlongitude_;
  double dsimtime_;
  double dtemperature_;
  double dairpressure_;
  double dwindvelocity_;
  double dwinddirection_;
  ::PROTOBUF_NAMESPACE_ID::int32 usimonground_;
  friend struct ::TableStruct_simconnectData_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// simData

// required string szTitle = 1;
inline bool simData::_internal_has_sztitle() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool simData::has_sztitle() const {
  return _internal_has_sztitle();
}
inline void simData::clear_sztitle() {
  sztitle_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& simData::sztitle() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.szTitle)
  return _internal_sztitle();
}
inline void simData::set_sztitle(const std::string& value) {
  _internal_set_sztitle(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.szTitle)
}
inline std::string* simData::mutable_sztitle() {
  // @@protoc_insertion_point(field_mutable:simConnect.simData.szTitle)
  return _internal_mutable_sztitle();
}
inline const std::string& simData::_internal_sztitle() const {
  return sztitle_.Get();
}
inline void simData::_internal_set_sztitle(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  sztitle_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void simData::set_sztitle(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  sztitle_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:simConnect.simData.szTitle)
}
inline void simData::set_sztitle(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  sztitle_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:simConnect.simData.szTitle)
}
inline void simData::set_sztitle(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  sztitle_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:simConnect.simData.szTitle)
}
inline std::string* simData::_internal_mutable_sztitle() {
  _has_bits_[0] |= 0x00000001u;
  return sztitle_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* simData::release_sztitle() {
  // @@protoc_insertion_point(field_release:simConnect.simData.szTitle)
  if (!_internal_has_sztitle()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return sztitle_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void simData::set_allocated_sztitle(std::string* sztitle) {
  if (sztitle != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  sztitle_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sztitle,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:simConnect.simData.szTitle)
}

// required double dAbsoluteTime = 2;
inline bool simData::_internal_has_dabsolutetime() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool simData::has_dabsolutetime() const {
  return _internal_has_dabsolutetime();
}
inline void simData::clear_dabsolutetime() {
  dabsolutetime_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline double simData::_internal_dabsolutetime() const {
  return dabsolutetime_;
}
inline double simData::dabsolutetime() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dAbsoluteTime)
  return _internal_dabsolutetime();
}
inline void simData::_internal_set_dabsolutetime(double value) {
  _has_bits_[0] |= 0x00000002u;
  dabsolutetime_ = value;
}
inline void simData::set_dabsolutetime(double value) {
  _internal_set_dabsolutetime(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dAbsoluteTime)
}

// required double dTime = 3;
inline bool simData::_internal_has_dtime() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool simData::has_dtime() const {
  return _internal_has_dtime();
}
inline void simData::clear_dtime() {
  dtime_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline double simData::_internal_dtime() const {
  return dtime_;
}
inline double simData::dtime() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dTime)
  return _internal_dtime();
}
inline void simData::_internal_set_dtime(double value) {
  _has_bits_[0] |= 0x00000004u;
  dtime_ = value;
}
inline void simData::set_dtime(double value) {
  _internal_set_dtime(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dTime)
}

// required int32 usimOnGround = 4;
inline bool simData::_internal_has_usimonground() const {
  bool value = (_has_bits_[0] & 0x00008000u) != 0;
  return value;
}
inline bool simData::has_usimonground() const {
  return _internal_has_usimonground();
}
inline void simData::clear_usimonground() {
  usimonground_ = 0;
  _has_bits_[0] &= ~0x00008000u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 simData::_internal_usimonground() const {
  return usimonground_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 simData::usimonground() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.usimOnGround)
  return _internal_usimonground();
}
inline void simData::_internal_set_usimonground(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00008000u;
  usimonground_ = value;
}
inline void simData::set_usimonground(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_usimonground(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.usimOnGround)
}

// required double dAltitude = 5;
inline bool simData::_internal_has_daltitude() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool simData::has_daltitude() const {
  return _internal_has_daltitude();
}
inline void simData::clear_daltitude() {
  daltitude_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline double simData::_internal_daltitude() const {
  return daltitude_;
}
inline double simData::daltitude() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dAltitude)
  return _internal_daltitude();
}
inline void simData::_internal_set_daltitude(double value) {
  _has_bits_[0] |= 0x00000008u;
  daltitude_ = value;
}
inline void simData::set_daltitude(double value) {
  _internal_set_daltitude(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dAltitude)
}

// required double dHeading = 6;
inline bool simData::_internal_has_dheading() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool simData::has_dheading() const {
  return _internal_has_dheading();
}
inline void simData::clear_dheading() {
  dheading_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline double simData::_internal_dheading() const {
  return dheading_;
}
inline double simData::dheading() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dHeading)
  return _internal_dheading();
}
inline void simData::_internal_set_dheading(double value) {
  _has_bits_[0] |= 0x00000010u;
  dheading_ = value;
}
inline void simData::set_dheading(double value) {
  _internal_set_dheading(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dHeading)
}

// required double dSpeed = 7;
inline bool simData::_internal_has_dspeed() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool simData::has_dspeed() const {
  return _internal_has_dspeed();
}
inline void simData::clear_dspeed() {
  dspeed_ = 0;
  _has_bits_[0] &= ~0x00000020u;
}
inline double simData::_internal_dspeed() const {
  return dspeed_;
}
inline double simData::dspeed() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dSpeed)
  return _internal_dspeed();
}
inline void simData::_internal_set_dspeed(double value) {
  _has_bits_[0] |= 0x00000020u;
  dspeed_ = value;
}
inline void simData::set_dspeed(double value) {
  _internal_set_dspeed(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dSpeed)
}

// required double dVerticalSpeed = 8;
inline bool simData::_internal_has_dverticalspeed() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool simData::has_dverticalspeed() const {
  return _internal_has_dverticalspeed();
}
inline void simData::clear_dverticalspeed() {
  dverticalspeed_ = 0;
  _has_bits_[0] &= ~0x00000040u;
}
inline double simData::_internal_dverticalspeed() const {
  return dverticalspeed_;
}
inline double simData::dverticalspeed() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dVerticalSpeed)
  return _internal_dverticalspeed();
}
inline void simData::_internal_set_dverticalspeed(double value) {
  _has_bits_[0] |= 0x00000040u;
  dverticalspeed_ = value;
}
inline void simData::set_dverticalspeed(double value) {
  _internal_set_dverticalspeed(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dVerticalSpeed)
}

// required double dGpsEta = 9;
inline bool simData::_internal_has_dgpseta() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool simData::has_dgpseta() const {
  return _internal_has_dgpseta();
}
inline void simData::clear_dgpseta() {
  dgpseta_ = 0;
  _has_bits_[0] &= ~0x00000080u;
}
inline double simData::_internal_dgpseta() const {
  return dgpseta_;
}
inline double simData::dgpseta() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dGpsEta)
  return _internal_dgpseta();
}
inline void simData::_internal_set_dgpseta(double value) {
  _has_bits_[0] |= 0x00000080u;
  dgpseta_ = value;
}
inline void simData::set_dgpseta(double value) {
  _internal_set_dgpseta(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dGpsEta)
}

// required double dLatitude = 10;
inline bool simData::_internal_has_dlatitude() const {
  bool value = (_has_bits_[0] & 0x00000100u) != 0;
  return value;
}
inline bool simData::has_dlatitude() const {
  return _internal_has_dlatitude();
}
inline void simData::clear_dlatitude() {
  dlatitude_ = 0;
  _has_bits_[0] &= ~0x00000100u;
}
inline double simData::_internal_dlatitude() const {
  return dlatitude_;
}
inline double simData::dlatitude() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dLatitude)
  return _internal_dlatitude();
}
inline void simData::_internal_set_dlatitude(double value) {
  _has_bits_[0] |= 0x00000100u;
  dlatitude_ = value;
}
inline void simData::set_dlatitude(double value) {
  _internal_set_dlatitude(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dLatitude)
}

// required double dLongitude = 11;
inline bool simData::_internal_has_dlongitude() const {
  bool value = (_has_bits_[0] & 0x00000200u) != 0;
  return value;
}
inline bool simData::has_dlongitude() const {
  return _internal_has_dlongitude();
}
inline void simData::clear_dlongitude() {
  dlongitude_ = 0;
  _has_bits_[0] &= ~0x00000200u;
}
inline double simData::_internal_dlongitude() const {
  return dlongitude_;
}
inline double simData::dlongitude() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dLongitude)
  return _internal_dlongitude();
}
inline void simData::_internal_set_dlongitude(double value) {
  _has_bits_[0] |= 0x00000200u;
  dlongitude_ = value;
}
inline void simData::set_dlongitude(double value) {
  _internal_set_dlongitude(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dLongitude)
}

// required double dSimTime = 12;
inline bool simData::_internal_has_dsimtime() const {
  bool value = (_has_bits_[0] & 0x00000400u) != 0;
  return value;
}
inline bool simData::has_dsimtime() const {
  return _internal_has_dsimtime();
}
inline void simData::clear_dsimtime() {
  dsimtime_ = 0;
  _has_bits_[0] &= ~0x00000400u;
}
inline double simData::_internal_dsimtime() const {
  return dsimtime_;
}
inline double simData::dsimtime() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dSimTime)
  return _internal_dsimtime();
}
inline void simData::_internal_set_dsimtime(double value) {
  _has_bits_[0] |= 0x00000400u;
  dsimtime_ = value;
}
inline void simData::set_dsimtime(double value) {
  _internal_set_dsimtime(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dSimTime)
}

// required double dTemperature = 13;
inline bool simData::_internal_has_dtemperature() const {
  bool value = (_has_bits_[0] & 0x00000800u) != 0;
  return value;
}
inline bool simData::has_dtemperature() const {
  return _internal_has_dtemperature();
}
inline void simData::clear_dtemperature() {
  dtemperature_ = 0;
  _has_bits_[0] &= ~0x00000800u;
}
inline double simData::_internal_dtemperature() const {
  return dtemperature_;
}
inline double simData::dtemperature() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dTemperature)
  return _internal_dtemperature();
}
inline void simData::_internal_set_dtemperature(double value) {
  _has_bits_[0] |= 0x00000800u;
  dtemperature_ = value;
}
inline void simData::set_dtemperature(double value) {
  _internal_set_dtemperature(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dTemperature)
}

// required double dAirPressure = 14;
inline bool simData::_internal_has_dairpressure() const {
  bool value = (_has_bits_[0] & 0x00001000u) != 0;
  return value;
}
inline bool simData::has_dairpressure() const {
  return _internal_has_dairpressure();
}
inline void simData::clear_dairpressure() {
  dairpressure_ = 0;
  _has_bits_[0] &= ~0x00001000u;
}
inline double simData::_internal_dairpressure() const {
  return dairpressure_;
}
inline double simData::dairpressure() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dAirPressure)
  return _internal_dairpressure();
}
inline void simData::_internal_set_dairpressure(double value) {
  _has_bits_[0] |= 0x00001000u;
  dairpressure_ = value;
}
inline void simData::set_dairpressure(double value) {
  _internal_set_dairpressure(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dAirPressure)
}

// required double dWindVelocity = 15;
inline bool simData::_internal_has_dwindvelocity() const {
  bool value = (_has_bits_[0] & 0x00002000u) != 0;
  return value;
}
inline bool simData::has_dwindvelocity() const {
  return _internal_has_dwindvelocity();
}
inline void simData::clear_dwindvelocity() {
  dwindvelocity_ = 0;
  _has_bits_[0] &= ~0x00002000u;
}
inline double simData::_internal_dwindvelocity() const {
  return dwindvelocity_;
}
inline double simData::dwindvelocity() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dWindVelocity)
  return _internal_dwindvelocity();
}
inline void simData::_internal_set_dwindvelocity(double value) {
  _has_bits_[0] |= 0x00002000u;
  dwindvelocity_ = value;
}
inline void simData::set_dwindvelocity(double value) {
  _internal_set_dwindvelocity(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dWindVelocity)
}

// required double dWindDirection = 16;
inline bool simData::_internal_has_dwinddirection() const {
  bool value = (_has_bits_[0] & 0x00004000u) != 0;
  return value;
}
inline bool simData::has_dwinddirection() const {
  return _internal_has_dwinddirection();
}
inline void simData::clear_dwinddirection() {
  dwinddirection_ = 0;
  _has_bits_[0] &= ~0x00004000u;
}
inline double simData::_internal_dwinddirection() const {
  return dwinddirection_;
}
inline double simData::dwinddirection() const {
  // @@protoc_insertion_point(field_get:simConnect.simData.dWindDirection)
  return _internal_dwinddirection();
}
inline void simData::_internal_set_dwinddirection(double value) {
  _has_bits_[0] |= 0x00004000u;
  dwinddirection_ = value;
}
inline void simData::set_dwinddirection(double value) {
  _internal_set_dwinddirection(value);
  // @@protoc_insertion_point(field_set:simConnect.simData.dWindDirection)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace simConnect

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_simconnectData_2eproto