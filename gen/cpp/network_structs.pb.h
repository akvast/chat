// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network_structs.proto

#ifndef PROTOBUF_network_5fstructs_2eproto__INCLUDED
#define PROTOBUF_network_5fstructs_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
class PUser;
class PUserDefaultTypeInternal;
extern PUserDefaultTypeInternal _PUser_default_instance_;

namespace protobuf_network_5fstructs_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_network_5fstructs_2eproto

// ===================================================================

class PUser : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PUser) */ {
 public:
  PUser();
  virtual ~PUser();

  PUser(const PUser& from);

  inline PUser& operator=(const PUser& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PUser& default_instance();

  static inline const PUser* internal_default_instance() {
    return reinterpret_cast<const PUser*>(
               &_PUser_default_instance_);
  }

  void Swap(PUser* other);

  // implements Message ----------------------------------------------

  inline PUser* New() const PROTOBUF_FINAL { return New(NULL); }

  PUser* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PUser& from);
  void MergeFrom(const PUser& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(PUser* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string email = 3;
  void clear_email();
  static const int kEmailFieldNumber = 3;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // string avatar_url = 4;
  void clear_avatar_url();
  static const int kAvatarUrlFieldNumber = 4;
  const ::std::string& avatar_url() const;
  void set_avatar_url(const ::std::string& value);
  #if LANG_CXX11
  void set_avatar_url(::std::string&& value);
  #endif
  void set_avatar_url(const char* value);
  void set_avatar_url(const char* value, size_t size);
  ::std::string* mutable_avatar_url();
  ::std::string* release_avatar_url();
  void set_allocated_avatar_url(::std::string* avatar_url);

  // int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PUser)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::internal::ArenaStringPtr avatar_url_;
  ::google::protobuf::int64 id_;
  mutable int _cached_size_;
  friend struct  protobuf_network_5fstructs_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// PUser

// int64 id = 1;
inline void PUser::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 PUser::id() const {
  // @@protoc_insertion_point(field_get:PUser.id)
  return id_;
}
inline void PUser::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:PUser.id)
}

// string name = 2;
inline void PUser::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PUser::name() const {
  // @@protoc_insertion_point(field_get:PUser.name)
  return name_.GetNoArena();
}
inline void PUser::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PUser.name)
}
#if LANG_CXX11
inline void PUser::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PUser.name)
}
#endif
inline void PUser::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PUser.name)
}
inline void PUser::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PUser.name)
}
inline ::std::string* PUser::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:PUser.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PUser::release_name() {
  // @@protoc_insertion_point(field_release:PUser.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PUser::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:PUser.name)
}

// string email = 3;
inline void PUser::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PUser::email() const {
  // @@protoc_insertion_point(field_get:PUser.email)
  return email_.GetNoArena();
}
inline void PUser::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PUser.email)
}
#if LANG_CXX11
inline void PUser::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PUser.email)
}
#endif
inline void PUser::set_email(const char* value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PUser.email)
}
inline void PUser::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PUser.email)
}
inline ::std::string* PUser::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:PUser.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PUser::release_email() {
  // @@protoc_insertion_point(field_release:PUser.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PUser::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:PUser.email)
}

// string avatar_url = 4;
inline void PUser::clear_avatar_url() {
  avatar_url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PUser::avatar_url() const {
  // @@protoc_insertion_point(field_get:PUser.avatar_url)
  return avatar_url_.GetNoArena();
}
inline void PUser::set_avatar_url(const ::std::string& value) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PUser.avatar_url)
}
#if LANG_CXX11
inline void PUser::set_avatar_url(::std::string&& value) {
  
  avatar_url_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PUser.avatar_url)
}
#endif
inline void PUser::set_avatar_url(const char* value) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PUser.avatar_url)
}
inline void PUser::set_avatar_url(const char* value, size_t size) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PUser.avatar_url)
}
inline ::std::string* PUser::mutable_avatar_url() {
  
  // @@protoc_insertion_point(field_mutable:PUser.avatar_url)
  return avatar_url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PUser::release_avatar_url() {
  // @@protoc_insertion_point(field_release:PUser.avatar_url)
  
  return avatar_url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PUser::set_allocated_avatar_url(::std::string* avatar_url) {
  if (avatar_url != NULL) {
    
  } else {
    
  }
  avatar_url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), avatar_url);
  // @@protoc_insertion_point(field_set_allocated:PUser.avatar_url)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_network_5fstructs_2eproto__INCLUDED
