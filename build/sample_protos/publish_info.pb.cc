// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: publish_info.proto

#include "publish_info.pb.h"

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
namespace superbai {
namespace sample {
class PublishInfoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PublishInfo> _instance;
} _PublishInfo_default_instance_;
class workDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<work> _instance;
} _work_default_instance_;
class dateDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<date> _instance;
} _date_default_instance_;
}  // namespace sample
}  // namespace superbai
static void InitDefaultsscc_info_PublishInfo_publish_5finfo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::superbai::sample::_PublishInfo_default_instance_;
    new (ptr) ::superbai::sample::PublishInfo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PublishInfo_publish_5finfo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PublishInfo_publish_5finfo_2eproto}, {}};

static void InitDefaultsscc_info_date_publish_5finfo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::superbai::sample::_date_default_instance_;
    new (ptr) ::superbai::sample::date();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_date_publish_5finfo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_date_publish_5finfo_2eproto}, {}};

static void InitDefaultsscc_info_work_publish_5finfo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::superbai::sample::_work_default_instance_;
    new (ptr) ::superbai::sample::work();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_work_publish_5finfo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_work_publish_5finfo_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_publish_5finfo_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_publish_5finfo_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_publish_5finfo_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_publish_5finfo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::PublishInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::PublishInfo, name_),
  PROTOBUF_FIELD_OFFSET(::superbai::sample::PublishInfo, message_type_),
  PROTOBUF_FIELD_OFFSET(::superbai::sample::PublishInfo, publish_msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::work, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::superbai::sample::date, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::superbai::sample::PublishInfo)},
  { 8, -1, sizeof(::superbai::sample::work)},
  { 13, -1, sizeof(::superbai::sample::date)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::superbai::sample::_PublishInfo_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::superbai::sample::_work_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::superbai::sample::_date_default_instance_),
};

const char descriptor_table_protodef_publish_5finfo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022publish_info.proto\022\017superbai.sample\"F\n"
  "\013PublishInfo\022\014\n\004name\030\001 \001(\t\022\024\n\014message_ty"
  "pe\030\002 \001(\t\022\023\n\013publish_msg\030\003 \001(\t\"\006\n\004work\"\006\n"
  "\004dateb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_publish_5finfo_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_publish_5finfo_2eproto_sccs[3] = {
  &scc_info_PublishInfo_publish_5finfo_2eproto.base,
  &scc_info_date_publish_5finfo_2eproto.base,
  &scc_info_work_publish_5finfo_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_publish_5finfo_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_publish_5finfo_2eproto = {
  false, false, descriptor_table_protodef_publish_5finfo_2eproto, "publish_info.proto", 133,
  &descriptor_table_publish_5finfo_2eproto_once, descriptor_table_publish_5finfo_2eproto_sccs, descriptor_table_publish_5finfo_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_publish_5finfo_2eproto::offsets,
  file_level_metadata_publish_5finfo_2eproto, 3, file_level_enum_descriptors_publish_5finfo_2eproto, file_level_service_descriptors_publish_5finfo_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_publish_5finfo_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_publish_5finfo_2eproto)), true);
namespace superbai {
namespace sample {

// ===================================================================

class PublishInfo::_Internal {
 public:
};

PublishInfo::PublishInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:superbai.sample.PublishInfo)
}
PublishInfo::PublishInfo(const PublishInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArena());
  }
  message_type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_message_type().empty()) {
    message_type_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_message_type(), 
      GetArena());
  }
  publish_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_publish_msg().empty()) {
    publish_msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_publish_msg(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:superbai.sample.PublishInfo)
}

void PublishInfo::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_PublishInfo_publish_5finfo_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  message_type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  publish_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

PublishInfo::~PublishInfo() {
  // @@protoc_insertion_point(destructor:superbai.sample.PublishInfo)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PublishInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  message_type_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  publish_msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void PublishInfo::ArenaDtor(void* object) {
  PublishInfo* _this = reinterpret_cast< PublishInfo* >(object);
  (void)_this;
}
void PublishInfo::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PublishInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PublishInfo& PublishInfo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PublishInfo_publish_5finfo_2eproto.base);
  return *internal_default_instance();
}


void PublishInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:superbai.sample.PublishInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  message_type_.ClearToEmpty();
  publish_msg_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PublishInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "superbai.sample.PublishInfo.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string message_type = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_message_type();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "superbai.sample.PublishInfo.message_type"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string publish_msg = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_publish_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "superbai.sample.PublishInfo.publish_msg"));
          CHK_(ptr);
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
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PublishInfo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:superbai.sample.PublishInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "superbai.sample.PublishInfo.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // string message_type = 2;
  if (this->message_type().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message_type().data(), static_cast<int>(this->_internal_message_type().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "superbai.sample.PublishInfo.message_type");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_message_type(), target);
  }

  // string publish_msg = 3;
  if (this->publish_msg().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_publish_msg().data(), static_cast<int>(this->_internal_publish_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "superbai.sample.PublishInfo.publish_msg");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_publish_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:superbai.sample.PublishInfo)
  return target;
}

size_t PublishInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:superbai.sample.PublishInfo)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string message_type = 2;
  if (this->message_type().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message_type());
  }

  // string publish_msg = 3;
  if (this->publish_msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_publish_msg());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PublishInfo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:superbai.sample.PublishInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const PublishInfo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PublishInfo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:superbai.sample.PublishInfo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:superbai.sample.PublishInfo)
    MergeFrom(*source);
  }
}

void PublishInfo::MergeFrom(const PublishInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:superbai.sample.PublishInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.message_type().size() > 0) {
    _internal_set_message_type(from._internal_message_type());
  }
  if (from.publish_msg().size() > 0) {
    _internal_set_publish_msg(from._internal_publish_msg());
  }
}

void PublishInfo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:superbai.sample.PublishInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PublishInfo::CopyFrom(const PublishInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:superbai.sample.PublishInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PublishInfo::IsInitialized() const {
  return true;
}

void PublishInfo::InternalSwap(PublishInfo* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  message_type_.Swap(&other->message_type_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  publish_msg_.Swap(&other->publish_msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata PublishInfo::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class work::_Internal {
 public:
};

work::work(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:superbai.sample.work)
}
work::work(const work& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:superbai.sample.work)
}

void work::SharedCtor() {
}

work::~work() {
  // @@protoc_insertion_point(destructor:superbai.sample.work)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void work::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void work::ArenaDtor(void* object) {
  work* _this = reinterpret_cast< work* >(object);
  (void)_this;
}
void work::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void work::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const work& work::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_work_publish_5finfo_2eproto.base);
  return *internal_default_instance();
}


void work::Clear() {
// @@protoc_insertion_point(message_clear_start:superbai.sample.work)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* work::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* work::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:superbai.sample.work)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:superbai.sample.work)
  return target;
}

size_t work::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:superbai.sample.work)
  size_t total_size = 0;

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

void work::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:superbai.sample.work)
  GOOGLE_DCHECK_NE(&from, this);
  const work* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<work>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:superbai.sample.work)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:superbai.sample.work)
    MergeFrom(*source);
  }
}

void work::MergeFrom(const work& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:superbai.sample.work)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void work::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:superbai.sample.work)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void work::CopyFrom(const work& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:superbai.sample.work)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool work::IsInitialized() const {
  return true;
}

void work::InternalSwap(work* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata work::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class date::_Internal {
 public:
};

date::date(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:superbai.sample.date)
}
date::date(const date& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:superbai.sample.date)
}

void date::SharedCtor() {
}

date::~date() {
  // @@protoc_insertion_point(destructor:superbai.sample.date)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void date::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void date::ArenaDtor(void* object) {
  date* _this = reinterpret_cast< date* >(object);
  (void)_this;
}
void date::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void date::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const date& date::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_date_publish_5finfo_2eproto.base);
  return *internal_default_instance();
}


void date::Clear() {
// @@protoc_insertion_point(message_clear_start:superbai.sample.date)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* date::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* date::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:superbai.sample.date)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:superbai.sample.date)
  return target;
}

size_t date::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:superbai.sample.date)
  size_t total_size = 0;

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

void date::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:superbai.sample.date)
  GOOGLE_DCHECK_NE(&from, this);
  const date* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<date>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:superbai.sample.date)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:superbai.sample.date)
    MergeFrom(*source);
  }
}

void date::MergeFrom(const date& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:superbai.sample.date)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void date::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:superbai.sample.date)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void date::CopyFrom(const date& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:superbai.sample.date)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool date::IsInitialized() const {
  return true;
}

void date::InternalSwap(date* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata date::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sample
}  // namespace superbai
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::superbai::sample::PublishInfo* Arena::CreateMaybeMessage< ::superbai::sample::PublishInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::superbai::sample::PublishInfo >(arena);
}
template<> PROTOBUF_NOINLINE ::superbai::sample::work* Arena::CreateMaybeMessage< ::superbai::sample::work >(Arena* arena) {
  return Arena::CreateMessageInternal< ::superbai::sample::work >(arena);
}
template<> PROTOBUF_NOINLINE ::superbai::sample::date* Arena::CreateMaybeMessage< ::superbai::sample::date >(Arena* arena) {
  return Arena::CreateMessageInternal< ::superbai::sample::date >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
