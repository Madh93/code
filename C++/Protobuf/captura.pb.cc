// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: captura.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "captura.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Captura_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Captura_reflection_ = NULL;
const ::google::protobuf::Descriptor* Captura_Roi_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Captura_Roi_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_captura_2eproto() {
  protobuf_AddDesc_captura_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "captura.proto");
  GOOGLE_CHECK(file != NULL);
  Captura_descriptor_ = file->message_type(0);
  static const int Captura_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, usuario_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, imagen_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, dispositivo_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, rois_),
  };
  Captura_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Captura_descriptor_,
      Captura::default_instance_,
      Captura_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Captura));
  Captura_Roi_descriptor_ = Captura_descriptor_->nested_type(0);
  static const int Captura_Roi_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, height_),
  };
  Captura_Roi_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Captura_Roi_descriptor_,
      Captura_Roi::default_instance_,
      Captura_Roi_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Captura_Roi, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Captura_Roi));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_captura_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Captura_descriptor_, &Captura::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Captura_Roi_descriptor_, &Captura_Roi::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_captura_2eproto() {
  delete Captura::default_instance_;
  delete Captura_reflection_;
  delete Captura_Roi::default_instance_;
  delete Captura_Roi_reflection_;
}

void protobuf_AddDesc_captura_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rcaptura.proto\"\252\001\n\007Captura\022\017\n\007usuario\030\001"
    " \002(\t\022\021\n\ttimestamp\030\002 \002(\004\022\016\n\006imagen\030\003 \002(\014\022"
    "\023\n\013dispositivo\030\004 \002(\t\022\032\n\004rois\030\005 \003(\0132\014.Cap"
    "tura.Roi\032:\n\003Roi\022\t\n\001x\030\001 \002(\005\022\t\n\001y\030\002 \002(\005\022\r\n"
    "\005width\030\003 \002(\005\022\016\n\006height\030\004 \002(\005", 188);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "captura.proto", &protobuf_RegisterTypes);
  Captura::default_instance_ = new Captura();
  Captura_Roi::default_instance_ = new Captura_Roi();
  Captura::default_instance_->InitAsDefaultInstance();
  Captura_Roi::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_captura_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_captura_2eproto {
  StaticDescriptorInitializer_captura_2eproto() {
    protobuf_AddDesc_captura_2eproto();
  }
} static_descriptor_initializer_captura_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Captura_Roi::kXFieldNumber;
const int Captura_Roi::kYFieldNumber;
const int Captura_Roi::kWidthFieldNumber;
const int Captura_Roi::kHeightFieldNumber;
#endif  // !_MSC_VER

Captura_Roi::Captura_Roi()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Captura_Roi::InitAsDefaultInstance() {
}

Captura_Roi::Captura_Roi(const Captura_Roi& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Captura_Roi::SharedCtor() {
  _cached_size_ = 0;
  x_ = 0;
  y_ = 0;
  width_ = 0;
  height_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Captura_Roi::~Captura_Roi() {
  SharedDtor();
}

void Captura_Roi::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Captura_Roi::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Captura_Roi::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Captura_Roi_descriptor_;
}

const Captura_Roi& Captura_Roi::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_captura_2eproto();
  return *default_instance_;
}

Captura_Roi* Captura_Roi::default_instance_ = NULL;

Captura_Roi* Captura_Roi::New() const {
  return new Captura_Roi;
}

void Captura_Roi::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    x_ = 0;
    y_ = 0;
    width_ = 0;
    height_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Captura_Roi::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 x = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_y;
        break;
      }

      // required int32 y = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_width;
        break;
      }

      // required int32 width = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &width_)));
          set_has_width();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_height;
        break;
      }

      // required int32 height = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &height_)));
          set_has_height();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Captura_Roi::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 x = 1;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->x(), output);
  }

  // required int32 y = 2;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->y(), output);
  }

  // required int32 width = 3;
  if (has_width()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->width(), output);
  }

  // required int32 height = 4;
  if (has_height()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->height(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Captura_Roi::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 x = 1;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->x(), target);
  }

  // required int32 y = 2;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->y(), target);
  }

  // required int32 width = 3;
  if (has_width()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->width(), target);
  }

  // required int32 height = 4;
  if (has_height()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->height(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Captura_Roi::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 x = 1;
    if (has_x()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->x());
    }

    // required int32 y = 2;
    if (has_y()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->y());
    }

    // required int32 width = 3;
    if (has_width()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->width());
    }

    // required int32 height = 4;
    if (has_height()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->height());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Captura_Roi::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Captura_Roi* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Captura_Roi*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Captura_Roi::MergeFrom(const Captura_Roi& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_width()) {
      set_width(from.width());
    }
    if (from.has_height()) {
      set_height(from.height());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Captura_Roi::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Captura_Roi::CopyFrom(const Captura_Roi& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Captura_Roi::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void Captura_Roi::Swap(Captura_Roi* other) {
  if (other != this) {
    std::swap(x_, other->x_);
    std::swap(y_, other->y_);
    std::swap(width_, other->width_);
    std::swap(height_, other->height_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Captura_Roi::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Captura_Roi_descriptor_;
  metadata.reflection = Captura_Roi_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int Captura::kUsuarioFieldNumber;
const int Captura::kTimestampFieldNumber;
const int Captura::kImagenFieldNumber;
const int Captura::kDispositivoFieldNumber;
const int Captura::kRoisFieldNumber;
#endif  // !_MSC_VER

Captura::Captura()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Captura::InitAsDefaultInstance() {
}

Captura::Captura(const Captura& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Captura::SharedCtor() {
  _cached_size_ = 0;
  usuario_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  timestamp_ = GOOGLE_ULONGLONG(0);
  imagen_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  dispositivo_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Captura::~Captura() {
  SharedDtor();
}

void Captura::SharedDtor() {
  if (usuario_ != &::google::protobuf::internal::kEmptyString) {
    delete usuario_;
  }
  if (imagen_ != &::google::protobuf::internal::kEmptyString) {
    delete imagen_;
  }
  if (dispositivo_ != &::google::protobuf::internal::kEmptyString) {
    delete dispositivo_;
  }
  if (this != default_instance_) {
  }
}

void Captura::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Captura::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Captura_descriptor_;
}

const Captura& Captura::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_captura_2eproto();
  return *default_instance_;
}

Captura* Captura::default_instance_ = NULL;

Captura* Captura::New() const {
  return new Captura;
}

void Captura::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_usuario()) {
      if (usuario_ != &::google::protobuf::internal::kEmptyString) {
        usuario_->clear();
      }
    }
    timestamp_ = GOOGLE_ULONGLONG(0);
    if (has_imagen()) {
      if (imagen_ != &::google::protobuf::internal::kEmptyString) {
        imagen_->clear();
      }
    }
    if (has_dispositivo()) {
      if (dispositivo_ != &::google::protobuf::internal::kEmptyString) {
        dispositivo_->clear();
      }
    }
  }
  rois_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Captura::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string usuario = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_usuario()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->usuario().data(), this->usuario().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_timestamp;
        break;
      }

      // required uint64 timestamp = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_imagen;
        break;
      }

      // required bytes imagen = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_imagen:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_imagen()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_dispositivo;
        break;
      }

      // required string dispositivo = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_dispositivo:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_dispositivo()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->dispositivo().data(), this->dispositivo().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_rois;
        break;
      }

      // repeated .Captura.Roi rois = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_rois:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_rois()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_rois;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Captura::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string usuario = 1;
  if (has_usuario()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->usuario().data(), this->usuario().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->usuario(), output);
  }

  // required uint64 timestamp = 2;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->timestamp(), output);
  }

  // required bytes imagen = 3;
  if (has_imagen()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->imagen(), output);
  }

  // required string dispositivo = 4;
  if (has_dispositivo()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dispositivo().data(), this->dispositivo().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->dispositivo(), output);
  }

  // repeated .Captura.Roi rois = 5;
  for (int i = 0; i < this->rois_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->rois(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Captura::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string usuario = 1;
  if (has_usuario()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->usuario().data(), this->usuario().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->usuario(), target);
  }

  // required uint64 timestamp = 2;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->timestamp(), target);
  }

  // required bytes imagen = 3;
  if (has_imagen()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->imagen(), target);
  }

  // required string dispositivo = 4;
  if (has_dispositivo()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dispositivo().data(), this->dispositivo().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->dispositivo(), target);
  }

  // repeated .Captura.Roi rois = 5;
  for (int i = 0; i < this->rois_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->rois(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Captura::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string usuario = 1;
    if (has_usuario()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->usuario());
    }

    // required uint64 timestamp = 2;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->timestamp());
    }

    // required bytes imagen = 3;
    if (has_imagen()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->imagen());
    }

    // required string dispositivo = 4;
    if (has_dispositivo()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->dispositivo());
    }

  }
  // repeated .Captura.Roi rois = 5;
  total_size += 1 * this->rois_size();
  for (int i = 0; i < this->rois_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->rois(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Captura::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Captura* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Captura*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Captura::MergeFrom(const Captura& from) {
  GOOGLE_CHECK_NE(&from, this);
  rois_.MergeFrom(from.rois_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_usuario()) {
      set_usuario(from.usuario());
    }
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_imagen()) {
      set_imagen(from.imagen());
    }
    if (from.has_dispositivo()) {
      set_dispositivo(from.dispositivo());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Captura::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Captura::CopyFrom(const Captura& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Captura::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  for (int i = 0; i < rois_size(); i++) {
    if (!this->rois(i).IsInitialized()) return false;
  }
  return true;
}

void Captura::Swap(Captura* other) {
  if (other != this) {
    std::swap(usuario_, other->usuario_);
    std::swap(timestamp_, other->timestamp_);
    std::swap(imagen_, other->imagen_);
    std::swap(dispositivo_, other->dispositivo_);
    rois_.Swap(&other->rois_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Captura::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Captura_descriptor_;
  metadata.reflection = Captura_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
