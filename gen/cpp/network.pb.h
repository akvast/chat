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
// @@protoc_insertion_point(includes)
class PAuthMessage;
class PAuthMessageDefaultTypeInternal;
extern PAuthMessageDefaultTypeInternal _PAuthMessage_default_instance_;
class PAuthSucceedMessage;
class PAuthSucceedMessageDefaultTypeInternal;
extern PAuthSucceedMessageDefaultTypeInternal _PAuthSucceedMessage_default_instance_;
class PErrorMessage;
class PErrorMessageDefaultTypeInternal;
extern PErrorMessageDefaultTypeInternal _PErrorMessage_default_instance_;
class PRegisterMessage;
class PRegisterMessageDefaultTypeInternal;
extern PRegisterMessageDefaultTypeInternal _PRegisterMessage_default_instance_;

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

  // string login = 1;
  void clear_login();
  static const int kLoginFieldNumber = 1;
  const ::std::string& login() const;
  void set_login(const ::std::string& value);
  #if LANG_CXX11
  void set_login(::std::string&& value);
  #endif
  void set_login(const char* value);
  void set_login(const char* value, size_t size);
  ::std::string* mutable_login();
  ::std::string* release_login();
  void set_allocated_login(::std::string* login);

  // string password = 2;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:PAuthMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr login_;
  ::google::protobuf::internal::ArenaStringPtr password_;
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

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
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

  // @@protoc_insertion_point(class_scope:PAuthSucceedMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable int _cached_size_;
  friend struct  protobuf_network_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PRegisterMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PRegisterMessage) */ {
 public:
  PRegisterMessage();
  virtual ~PRegisterMessage();

  PRegisterMessage(const PRegisterMessage& from);

  inline PRegisterMessage& operator=(const PRegisterMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PRegisterMessage& default_instance();

  static inline const PRegisterMessage* internal_default_instance() {
    return reinterpret_cast<const PRegisterMessage*>(
               &_PRegisterMessage_default_instance_);
  }

  void Swap(PRegisterMessage* other);

  // implements Message ----------------------------------------------

  inline PRegisterMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  PRegisterMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PRegisterMessage& from);
  void MergeFrom(const PRegisterMessage& from);
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
  void InternalSwap(PRegisterMessage* other);
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

  // string email = 1;
  void clear_email();
  static const int kEmailFieldNumber = 1;
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

  // string password = 2;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:PRegisterMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::internal::ArenaStringPtr password_;
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
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// PAuthMessage

// string login = 1;
inline void PAuthMessage::clear_login() {
  login_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::login() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.login)
  return login_.GetNoArena();
}
inline void PAuthMessage::set_login(const ::std::string& value) {
  
  login_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.login)
}
#if LANG_CXX11
inline void PAuthMessage::set_login(::std::string&& value) {
  
  login_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.login)
}
#endif
inline void PAuthMessage::set_login(const char* value) {
  
  login_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.login)
}
inline void PAuthMessage::set_login(const char* value, size_t size) {
  
  login_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.login)
}
inline ::std::string* PAuthMessage::mutable_login() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.login)
  return login_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_login() {
  // @@protoc_insertion_point(field_release:PAuthMessage.login)
  
  return login_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_login(::std::string* login) {
  if (login != NULL) {
    
  } else {
    
  }
  login_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), login);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.login)
}

// string password = 2;
inline void PAuthMessage::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthMessage::password() const {
  // @@protoc_insertion_point(field_get:PAuthMessage.password)
  return password_.GetNoArena();
}
inline void PAuthMessage::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthMessage.password)
}
#if LANG_CXX11
inline void PAuthMessage::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthMessage.password)
}
#endif
inline void PAuthMessage::set_password(const char* value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthMessage.password)
}
inline void PAuthMessage::set_password(const char* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthMessage.password)
}
inline ::std::string* PAuthMessage::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:PAuthMessage.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthMessage::release_password() {
  // @@protoc_insertion_point(field_release:PAuthMessage.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthMessage::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:PAuthMessage.password)
}

// -------------------------------------------------------------------

// PAuthSucceedMessage

// string name = 1;
inline void PAuthSucceedMessage::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PAuthSucceedMessage::name() const {
  // @@protoc_insertion_point(field_get:PAuthSucceedMessage.name)
  return name_.GetNoArena();
}
inline void PAuthSucceedMessage::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PAuthSucceedMessage.name)
}
#if LANG_CXX11
inline void PAuthSucceedMessage::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PAuthSucceedMessage.name)
}
#endif
inline void PAuthSucceedMessage::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PAuthSucceedMessage.name)
}
inline void PAuthSucceedMessage::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PAuthSucceedMessage.name)
}
inline ::std::string* PAuthSucceedMessage::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:PAuthSucceedMessage.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PAuthSucceedMessage::release_name() {
  // @@protoc_insertion_point(field_release:PAuthSucceedMessage.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PAuthSucceedMessage::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:PAuthSucceedMessage.name)
}

// -------------------------------------------------------------------

// PRegisterMessage

// string email = 1;
inline void PRegisterMessage::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PRegisterMessage::email() const {
  // @@protoc_insertion_point(field_get:PRegisterMessage.email)
  return email_.GetNoArena();
}
inline void PRegisterMessage::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PRegisterMessage.email)
}
#if LANG_CXX11
inline void PRegisterMessage::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PRegisterMessage.email)
}
#endif
inline void PRegisterMessage::set_email(const char* value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PRegisterMessage.email)
}
inline void PRegisterMessage::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PRegisterMessage.email)
}
inline ::std::string* PRegisterMessage::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:PRegisterMessage.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PRegisterMessage::release_email() {
  // @@protoc_insertion_point(field_release:PRegisterMessage.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PRegisterMessage::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:PRegisterMessage.email)
}

// string password = 2;
inline void PRegisterMessage::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& PRegisterMessage::password() const {
  // @@protoc_insertion_point(field_get:PRegisterMessage.password)
  return password_.GetNoArena();
}
inline void PRegisterMessage::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PRegisterMessage.password)
}
#if LANG_CXX11
inline void PRegisterMessage::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PRegisterMessage.password)
}
#endif
inline void PRegisterMessage::set_password(const char* value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PRegisterMessage.password)
}
inline void PRegisterMessage::set_password(const char* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PRegisterMessage.password)
}
inline ::std::string* PRegisterMessage::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:PRegisterMessage.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PRegisterMessage::release_password() {
  // @@protoc_insertion_point(field_release:PRegisterMessage.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PRegisterMessage::set_allocated_password(::std::string* password) {
  if (password != NULL) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:PRegisterMessage.password)
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

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_network_2eproto__INCLUDED
