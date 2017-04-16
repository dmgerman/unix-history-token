begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStreamWriter.h - Writes objects to a BinaryStream ---*- C++-*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_BINARYSTREAMWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAMWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamError.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Provides write only access to a subclass of `WritableBinaryStream`.
comment|/// Provides bounds checking and helpers for writing certain common data types
comment|/// such as null-terminated strings, integers in various flavors of endianness,
comment|/// etc.  Can be subclassed to provide reading and writing of custom datatypes,
comment|/// although no methods are overridable.
name|class
name|BinaryStreamWriter
block|{
name|public
label|:
name|BinaryStreamWriter
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|BinaryStreamWriter
parameter_list|(
name|WritableBinaryStreamRef
name|Stream
parameter_list|)
function_decl|;
name|virtual
operator|~
name|BinaryStreamWriter
argument_list|()
block|{}
comment|/// Write the bytes specified in \p Buffer to the underlying stream.
comment|/// On success, updates the offset so that subsequent writes will occur
comment|/// at the next unwritten position.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|Error
name|writeBytes
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Buffer
argument_list|)
expr_stmt|;
comment|/// Write the the integer \p Value to the underlying stream in the
comment|/// specified endianness.  On success, updates the offset so that
comment|/// subsequent writes occur at the next unwritten position.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|writeInteger
argument_list|(
argument|T Value
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_integral
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"Cannot call writeInteger with non-integral value!"
argument_list|)
block|;
name|uint8_t
name|Buffer
index|[
sizeof|sizeof
argument_list|(
name|T
argument_list|)
index|]
block|;
name|llvm
operator|::
name|support
operator|::
name|endian
operator|::
name|write
operator|<
name|T
block|,
name|llvm
operator|::
name|support
operator|::
name|unaligned
operator|>
operator|(
name|Buffer
operator|,
name|Value
operator|,
name|Stream
operator|.
name|getEndian
argument_list|()
operator|)
block|;
return|return
name|writeBytes
argument_list|(
name|Buffer
argument_list|)
return|;
block|}
comment|/// Similar to writeInteger
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|writeEnum
argument_list|(
argument|T Num
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_enum
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"Cannot call writeEnum with non-Enum type"
argument_list|)
block|;
name|using
name|U
operator|=
name|typename
name|std
operator|::
name|underlying_type
operator|<
name|T
operator|>
operator|::
name|type
block|;
return|return
name|writeInteger
operator|<
name|U
operator|>
operator|(
name|static_cast
operator|<
name|U
operator|>
operator|(
name|Num
operator|)
operator|)
return|;
block|}
comment|/// Write the the string \p Str to the underlying stream followed by a null
comment|/// terminator.  On success, updates the offset so that subsequent writes
comment|/// occur at the next unwritten position.  \p Str need not be null terminated
comment|/// on input.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|Error
name|writeCString
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// Write the the string \p Str to the underlying stream without a null
comment|/// terminator.  On success, updates the offset so that subsequent writes
comment|/// occur at the next unwritten position.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|Error
name|writeFixedString
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// Efficiently reads all data from \p Ref, and writes it to this stream.
comment|/// This operation will not invoke any copies of the source data, regardless
comment|/// of the source stream's implementation.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|Error
name|writeStreamRef
parameter_list|(
name|BinaryStreamRef
name|Ref
parameter_list|)
function_decl|;
comment|/// Efficiently reads \p Size bytes from \p Ref, and writes it to this stream.
comment|/// This operation will not invoke any copies of the source data, regardless
comment|/// of the source stream's implementation.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|Error
name|writeStreamRef
parameter_list|(
name|BinaryStreamRef
name|Ref
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
comment|/// Writes the object \p Obj to the underlying stream, as if by using memcpy.
comment|/// It is up to the caller to ensure that type of \p Obj can be safely copied
comment|/// in this fashion, as no checks are made to ensure that this is safe.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|writeObject
argument_list|(
argument|const T&Obj
argument_list|)
block|{
name|static_assert
argument_list|(
operator|!
name|std
operator|::
name|is_pointer
operator|<
name|T
operator|>
operator|::
name|value
argument_list|,
literal|"writeObject should not be used with pointers, to write "
literal|"the pointed-to value dereference the pointer before calling "
literal|"writeObject"
argument_list|)
block|;
return|return
name|writeBytes
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|uint8_t
operator|*
operator|>
operator|(
operator|&
name|Obj
operator|)
operator|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
argument_list|)
return|;
block|}
comment|/// Writes an array of objects of type T to the underlying stream, as if by
comment|/// using memcpy.  It is up to the caller to ensure that type of \p Obj can
comment|/// be safely copied in this fashion, as no checks are made to ensure that
comment|/// this is safe.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|writeArray
argument_list|(
argument|ArrayRef<T> Array
argument_list|)
block|{
if|if
condition|(
name|Array
operator|.
name|empty
argument_list|()
condition|)
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
if|if
condition|(
name|Array
operator|.
name|size
argument_list|()
operator|>
name|UINT32_MAX
operator|/
sizeof|sizeof
argument_list|(
name|T
argument_list|)
condition|)
return|return
name|make_error
operator|<
name|BinaryStreamError
operator|>
operator|(
name|stream_error_code
operator|::
name|invalid_array_size
operator|)
return|;
return|return
name|writeBytes
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|uint8_t
operator|*
operator|>
operator|(
name|Array
operator|.
name|data
argument_list|()
operator|)
operator|,
name|Array
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
argument_list|)
return|;
block|}
comment|/// Writes all data from the array \p Array to the underlying stream.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|Error
name|writeArray
argument_list|(
argument|VarStreamArray<T
argument_list|,
argument|U> Array
argument_list|)
block|{
return|return
name|writeStreamRef
argument_list|(
name|Array
operator|.
name|getUnderlyingStream
argument_list|()
argument_list|)
return|;
block|}
comment|/// Writes all elements from the array \p Array to the underlying stream.
comment|///
comment|/// \returns a success error code if the data was successfully written,
comment|/// otherwise returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|writeArray
argument_list|(
argument|FixedStreamArray<T> Array
argument_list|)
block|{
return|return
name|writeStreamRef
argument_list|(
name|Array
operator|.
name|getUnderlyingStream
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setOffset
parameter_list|(
name|uint32_t
name|Off
parameter_list|)
block|{
name|Offset
operator|=
name|Off
expr_stmt|;
block|}
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|uint32_t
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|Stream
operator|.
name|getLength
argument_list|()
return|;
block|}
name|uint32_t
name|bytesRemaining
argument_list|()
specifier|const
block|{
return|return
name|getLength
argument_list|()
operator|-
name|getOffset
argument_list|()
return|;
block|}
name|Error
name|padToAlignment
parameter_list|(
name|uint32_t
name|Align
parameter_list|)
function_decl|;
name|protected
label|:
name|WritableBinaryStreamRef
name|Stream
decl_stmt|;
name|uint32_t
name|Offset
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BINARYSTREAMWRITER_H
end_comment

end_unit

