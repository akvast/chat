// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network.proto

#ifndef PROTOBUF_network_2eproto__INCLUDED
#define PROTOBUF_network_2eproto__INCLUDED

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
#include "network_structs.pb.h"
// @@protoc_insertion_point(includes)
class PAuthMessage;
class PAuthMessageDefaultTypeInternal;
extern PAuthMessageDefaultTypeInternal _PAuthMessage_default_instance_;
class PAuthSucceedMessage;
class PAuthSucceedMessageDefaultTypeInternal;
extern PAuthSucceedMessageDefaultTypeInternal _PAuthSucceedMessage_default_instance_;
class PContactsSearchRequest;
class PContactsSearchRequestDefaultTypeInternal;
extern PContactsSearchRequestDefaultTypeInternal _PContactsSearchRequest_default_instance_;
class PContactsSearchResponse;
class PContactsSearchResponseDefaultTypeInternal;
extern PContactsSearchResponseDefaultTypeInternal _PContactsSearchResponse_default_instance_;
class PErrorMessage;
class PErrorMessageDefaultTypeInternal;
extern PErrorMessageDefaultTypeInternal _PErrorMessage_default_instance_;
class PUser;
class PUserDefaultTypeInternal;
extern PUserDefaultTypeInternal _PUser_default_instance_;

namespace protobuf_network_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_network_2eproto

// ===================================================================

class PAuthMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PAuthMessage) */ {
 public:
  PAuthMessage();
  virtual ~PAuthMessage();

  PAuthMessage(const PAuthMessage& from);

  inline PAuthMessage& operator=(const PAuthMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PAuthMessage& default_instance();

  static inline const PAuthMessage* internal_default_instance() {
    return reinterpret_cast<const PAuthMessage*>(
               &_PAuthMessage_default_instance_);
  }

  void Swap(PAuthMessage* other);

  // implements Message ----------------------------------------------

  inline PAuthMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  PAuthMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PAuthMessage& from);
  void MergeFrom(const PAuthMessage& from);
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
  void InternalSwap(PAuthMessage* other);
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

  // string token = 1;
  void clear_token();
  static const int kTokenFieldNumber = 1;
  const ::std::string& token() const;
  void set_token(const ::std::string& value);
  #if LANG_CXX11
  void set_token(::std::string&& value);
  #endif
  void set_token(const char* value);
  void set_token(const char* value, size_t size);
  ::std::string* mutable_token();
  ::std::string* release_token();
  void set_allocated_token(::std::string* token);

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

  // @@protoc_insertion_point(class_scope:PAuthMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr token_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::internal::ArenaStringPtr avatar_url_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PAuthSucceedMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PAuthSucceedMessage) */ {
 public:
  PAuthSucceedMessage();
  virtual ~PAuthSucceedMessage();

  PAuthSucceedMessage(const PAuthSucceedMessage& from);

  inline PAuthSucceedMessage& operator=(const PAuthSucceedMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PAuthSucceedMessage& default_instance();

  static inline const PAuthSucceedMessage* internal_default_instance() {
    return reinterpret_cast<const PAuthSucceedMessage*>(
               &_PAuthSucceedMessage_default_instance_);
  }

  void Swap(PAuthSucceedMessage* other);

  // implements Message ----------------------------------------------

  inline PAuthSucceedMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  PAuthSucceedMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PAuthSucceedMessage& from);
  void MergeFrom(const PAuthSucceedMessage& from);
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
  void InternalSwap(PAuthSucceedMessage* other);
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

  // int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PAuthSucceedMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 id_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PErrorMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PErrorMessage) */ {
 public:
  PErrorMessage();
  virtual ~PErrorMessage();

  PErrorMessage(const PErrorMessage& from);

  inline PErrorMessage& operator=(const PErrorMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PErrorMessage& default_instance();

  static inline const PErrorMessage* internal_default_instance() {
    return reinterpret_cast<const PErrorMessage*>(
               &_PErrorMessage_default_instance_);
  }

  void Swap(PErrorMessage* other);

  // implements Message ----------------------------------------------

  inline PErrorMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  PErrorMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PErrorMessage& from);
  void MergeFrom(const PErrorMessage& from);
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
  void InternalSwap(PErrorMessage* other);
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

  // string message = 2;
  void clear_message();
  static const int kMessageFieldNumber = 2;
  const ::std::string& message() const;
  void set_message(const ::std::string& value);
  #if LANG_CXX11
  void set_message(::std::string&& value);
  #endif
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  ::std::string* mutable_message();
  ::std::string* release_message();
  void set_allocated_message(::std::string* message);

  // int32 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PErrorMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr message_;
  ::google::protobuf::int32 code_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PContactsSearchRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PContactsSearchRequest) */ {
 public:
  PContactsSearchRequest();
  virtual ~PContactsSearchRequest();

  PContactsSearchRequest(const PContactsSearchRequest& from);

  inline PContactsSearchRequest& operator=(const PContactsSearchRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PContactsSearchRequest& default_instance();

  static inline const PContactsSearchRequest* internal_default_instance() {
    return reinterpret_cast<const PContactsSearchRequest*>(
               &_PContactsSearchRequest_default_instance_);
  }

  void Swap(PContactsSearchRequest* other);

  // implements Message ----------------------------------------------

  inline PContactsSearchRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  PContactsSearchRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PContactsSearchRequest& from);
  void MergeFrom(const PContactsSearchRequest& from);
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
  void InternalSwap(PContactsSearchRequest* other);
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

  // string query = 2;
  void clear_query();
  static const int kQueryFieldNumber = 2;
  const ::std::string& query() const;
  void set_query(const ::std::string& value);
  #if LANG_CXX11
  void set_query(::std::string&& value);
  #endif
  void set_query(const char* value);
  void set_query(const char* value, size_t size);
  ::std::string* mutable_query();
  ::std::string* release_query();
  void set_allocated_query(::std::string* query);

  // int32 request_id = 1;
  void clear_request_id();
  static const int kRequestIdFieldNumber = 1;
  ::google::protobuf::int32 request_id() const;
  void set_request_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PContactsSearchRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr query_;
  ::google::protobuf::int32 request_id_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PContactsSearchResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PContactsSearchResponse) */ {
 public:
  PContactsSearchResponse();
  virtual ~PContactsSearchResponse();

  PContactsSearchResponse(const PContactsSearchResponse& from);

  inline PContactsSearchResponse& operator=(const PContactsSearchResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PContactsSearchResponse& default_instance();

  static inline const PContactsSearchResponse* internal_default_instance() {
    return reinterpret_cast<const PContactsSearchResponse*>(
               &_PContactsSearchResponse_default_instance_);
  }

  void Swap(PContactsSearchResponse* other);

  // implements Message ----------------------------------------------

  inline PContactsSearchResponse* New() const PROTOBUF_FINAL { return New(NULL); }

  PContactsSearchResponse* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PContactsSearchResponse& from);
  void MergeFrom(const PContactsSearchResponse& from);
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
  void InternalSwap(PContactsSearchResponse* other);
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

  // repeated .PUser users = 2;
  int users_size() const;
  void clear_users();
  static const int kUsersFieldNumber = 2;
  const ::PUser& users(int index) const;
  ::PUser* mutable_users(int index);
  ::PUser* add_users();
  ::google::protobuf::RepeatedPtrField< ::PUser >*
      mutable_users();
  const ::google::protobuf::RepeatedPtrField< ::PUser >&
      users() const;

  // int32 request_id = 1;
  void clear_request_id();
  static const int kRequestIdFieldNumber = 1;
  ::google::protobuf::int32 request_id() const;
  void set_request_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PContactsSearchResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::PUser > users_;
  ::google::protobuf::int32 request_id_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// PAuthMessage

// string token = 1;
inline void PAuthMessage::clear_token() {
  token_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::token() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.token)
  return token_.GetNoArena();
}
inline void PAuthMessage::set_token(const ::std::string& value) {
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.token)
}
#if LANG_CXX11
inline void PAuthMessage::set_token(::std::string&& value) {
  
  token_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.token)
}
#endif
inline void PAuthMessage::set_token(const char* value) {
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.token)
}
inline void PAuthMessage::set_token(const char* value, size_t size) {
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.token)
}
inline ::std::string* PAuthMessage::mutable_token() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.token)
  return token_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_token() {
  // @@protoc_insertion_point(field_release:PAuthMessage.token)
  
  return token_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_token(::std::string* token) {
  if (token != NULL) {
    
  } else {
    
  }
  token_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), token);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.token)
}

// string name = 2;
inline void PAuthMessage::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::name() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.name)
  return name_.GetNoArena();
}
inline void PAuthMessage::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.name)
}
#if LANG_CXX11
inline void PAuthMessage::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.name)
}
#endif
inline void PAuthMessage::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.name)
}
inline void PAuthMessage::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.name)
}
inline ::std::string* PAuthMessage::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_name() {
  // @@protoc_insertion_point(field_release:PAuthMessage.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.name)
}

// string email = 3;
inline void PAuthMessage::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::email() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.email)
  return email_.GetNoArena();
}
inline void PAuthMessage::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.email)
}
#if LANG_CXX11
inline void PAuthMessage::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.email)
}
#endif
inline void PAuthMessage::set_email(const char* value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.email)
}
inline void PAuthMessage::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.email)
}
inline ::std::string* PAuthMessage::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_email() {
  // @@protoc_insertion_point(field_release:PAuthMessage.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.email)
}

// string avatar_url = 4;
inline void PAuthMessage::clear_avatar_url() {
  avatar_url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::avatar_url() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.avatar_url)
  return avatar_url_.GetNoArena();
}
inline void PAuthMessage::set_avatar_url(const ::std::string& value) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.avatar_url)
}
#if LANG_CXX11
inline void PAuthMessage::set_avatar_url(::std::string&& value) {
  
  avatar_url_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.avatar_url)
}
#endif
inline void PAuthMessage::set_avatar_url(const char* value) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.avatar_url)
}
inline void PAuthMessage::set_avatar_url(const char* value, size_t size) {
  
  avatar_url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.avatar_url)
}
inline ::std::string* PAuthMessage::mutable_avatar_url() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.avatar_url)
  return avatar_url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_avatar_url() {
  // @@protoc_insertion_point(field_release:PAuthMessage.avatar_url)
  
  return avatar_url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_avatar_url(::std::string* avatar_url) {
  if (avatar_url != NULL) {
    
  } else {
    
  }
  avatar_url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), avatar_url);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.avatar_url)
}

// -------------------------------------------------------------------

// PAuthSucceedMessage

// int64 id = 1;
inline void PAuthSucceedMessage::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 PAuthSucceedMessage::id() const {
  // @@protoc_insertion_point(field_get:PAuthSucceedMessage.id)
  return id_;
}
inline void PAuthSucceedMessage::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:PAuthSucceedMessage.id)
}

// -------------------------------------------------------------------

// PErrorMessage

// int32 code = 1;
inline void PErrorMessage::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 PErrorMessage::code() const {
  // @@protoc_insertion_point(field_get:PErrorMessage.code)
  return code_;
}
inline void PErrorMessage::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:PErrorMessage.code)
}

// string message = 2;
inline void PErrorMessage::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PErrorMessage::message() const {
  // @@protoc_insertion_point(field_get:PErrorMessage.message)
  return message_.GetNoArena();
}
inline void PErrorMessage::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PErrorMessage.message)
}
#if LANG_CXX11
inline void PErrorMessage::set_message(::std::string&& value) {
  
  message_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PErrorMessage.message)
}
#endif
inline void PErrorMessage::set_message(const char* value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PErrorMessage.message)
}
inline void PErrorMessage::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PErrorMessage.message)
}
inline ::std::string* PErrorMessage::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:PErrorMessage.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PErrorMessage::release_message() {
  // @@protoc_insertion_point(field_release:PErrorMessage.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PErrorMessage::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:PErrorMessage.message)
}

// -------------------------------------------------------------------

// PContactsSearchRequest

// int32 request_id = 1;
inline void PContactsSearchRequest::clear_request_id() {
  request_id_ = 0;
}
inline ::google::protobuf::int32 PContactsSearchRequest::request_id() const {
  // @@protoc_insertion_point(field_get:PContactsSearchRequest.request_id)
  return request_id_;
}
inline void PContactsSearchRequest::set_request_id(::google::protobuf::int32 value) {
  
  request_id_ = value;
  // @@protoc_insertion_point(field_set:PContactsSearchRequest.request_id)
}

// string query = 2;
inline void PContactsSearchRequest::clear_query() {
  query_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PContactsSearchRequest::query() const {
  // @@protoc_insertion_point(field_get:PContactsSearchRequest.query)
  return query_.GetNoArena();
}
inline void PContactsSearchRequest::set_query(const ::std::string& value) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PContactsSearchRequest.query)
}
#if LANG_CXX11
inline void PContactsSearchRequest::set_query(::std::string&& value) {
  
  query_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PContactsSearchRequest.query)
}
#endif
inline void PContactsSearchRequest::set_query(const char* value) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PContactsSearchRequest.query)
}
inline void PContactsSearchRequest::set_query(const char* value, size_t size) {
  
  query_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PContactsSearchRequest.query)
}
inline ::std::string* PContactsSearchRequest::mutable_query() {
  
  // @@protoc_insertion_point(field_mutable:PContactsSearchRequest.query)
  return query_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PContactsSearchRequest::release_query() {
  // @@protoc_insertion_point(field_release:PContactsSearchRequest.query)
  
  return query_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PContactsSearchRequest::set_allocated_query(::std::string* query) {
  if (query != NULL) {
    
  } else {
    
  }
  query_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), query);
  // @@protoc_insertion_point(field_set_allocated:PContactsSearchRequest.query)
}

// -------------------------------------------------------------------

// PContactsSearchResponse

// int32 request_id = 1;
inline void PContactsSearchResponse::clear_request_id() {
  request_id_ = 0;
}
inline ::google::protobuf::int32 PContactsSearchResponse::request_id() const {
  // @@protoc_insertion_point(field_get:PContactsSearchResponse.request_id)
  return request_id_;
}
inline void PContactsSearchResponse::set_request_id(::google::protobuf::int32 value) {
  
  request_id_ = value;
  // @@protoc_insertion_point(field_set:PContactsSearchResponse.request_id)
}

// repeated .PUser users = 2;
inline int PContactsSearchResponse::users_size() const {
  return users_.size();
}
inline void PContactsSearchResponse::clear_users() {
  users_.Clear();
}
inline const ::PUser& PContactsSearchResponse::users(int index) const {
  // @@protoc_insertion_point(field_get:PContactsSearchResponse.users)
  return users_.Get(index);
}
inline ::PUser* PContactsSearchResponse::mutable_users(int index) {
  // @@protoc_insertion_point(field_mutable:PContactsSearchResponse.users)
  return users_.Mutable(index);
}
inline ::PUser* PContactsSearchResponse::add_users() {
  // @@protoc_insertion_point(field_add:PContactsSearchResponse.users)
  return users_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::PUser >*
PContactsSearchResponse::mutable_users() {
  // @@protoc_insertion_point(field_mutable_list:PContactsSearchResponse.users)
  return &users_;
}
inline const ::google::protobuf::RepeatedPtrField< ::PUser >&
PContactsSearchResponse::users() const {
  // @@protoc_insertion_point(field_list:PContactsSearchResponse.users)
  return users_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_network_2eproto__INCLUDED
