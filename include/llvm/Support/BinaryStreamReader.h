begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStreamReader.h - Reads objects from a binary stream *- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYSTREAMREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAMREADER_H
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
file|"llvm/Support/BinaryStreamArray.h"
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
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
comment|/// \brief Provides read only access to a subclass of `BinaryStream`.  Provides
comment|/// bounds checking and helpers for writing certain common data types such as
comment|/// null-terminated strings, integers in various flavors of endianness, etc.
comment|/// Can be subclassed to provide reading of custom datatypes, although no
comment|/// are overridable.
name|class
name|BinaryStreamReader
block|{
name|public
label|:
name|explicit
name|BinaryStreamReader
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|)
function_decl|;
name|virtual
operator|~
name|BinaryStreamReader
argument_list|()
block|{}
comment|/// Read as much as possible from the underlying string at the current offset
comment|/// without invoking a copy, and set \p Buffer to the resulting data slice.
comment|/// Updates the stream's offset to point after the newly read data.
comment|///
comment|/// \returns a success error code if the data was successfully read, otherwise
comment|/// returns an appropriate error code.
name|Error
name|readLongestContiguousChunk
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
expr_stmt|;
comment|/// Read \p Size bytes from the underlying stream at the current offset and
comment|/// and set \p Buffer to the resulting data slice.  Whether a copy occurs
comment|/// depends on the implementation of the underlying stream.  Updates the
comment|/// stream's offset to point after the newly read data.
comment|///
comment|/// \returns a success error code if the data was successfully read, otherwise
comment|/// returns an appropriate error code.
name|Error
name|readBytes
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|,
name|uint32_t
name|Size
argument_list|)
decl_stmt|;
comment|/// Read an integer of the specified endianness into \p Dest and update the
comment|/// stream's offset.  The data is always copied from the stream's underlying
comment|/// buffer into \p Dest. Updates the stream's offset to point after the newly
comment|/// read data.
comment|///
comment|/// \returns a success error code if the data was successfully read, otherwise
comment|/// returns an appropriate error code.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|readInteger
argument_list|(
argument|T&Dest
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
literal|"Cannot call readInteger with non-integral value!"
argument_list|)
block|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|readBytes
argument_list|(
name|Bytes
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
condition|)
return|return
name|EC
return|;
name|Dest
operator|=
name|llvm
operator|::
name|support
operator|::
name|endian
operator|::
name|read
operator|<
name|T
operator|,
name|llvm
operator|::
name|support
operator|::
name|unaligned
operator|>
operator|(
name|Bytes
operator|.
name|data
argument_list|()
operator|,
name|Stream
operator|.
name|getEndian
argument_list|()
operator|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
comment|/// Similar to readInteger.
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|readEnum
argument_list|(
argument|T&Dest
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
literal|"Cannot call readEnum with non-enum value!"
argument_list|)
block|;
name|typename
name|std
operator|::
name|underlying_type
operator|<
name|T
operator|>
operator|::
name|type
name|N
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|readInteger
argument_list|(
name|N
argument_list|)
condition|)
return|return
name|EC
return|;
name|Dest
operator|=
name|static_cast
operator|<
name|T
operator|>
operator|(
name|N
operator|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Read a null terminated string from \p Dest.  Whether a copy occurs depends
end_comment

begin_comment
comment|/// on the implementation of the underlying stream.  Updates the stream's
end_comment

begin_comment
comment|/// offset to point after the newly read data.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_function_decl
name|Error
name|readCString
parameter_list|(
name|StringRef
modifier|&
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Read a \p Length byte string into \p Dest.  Whether a copy occurs depends
end_comment

begin_comment
comment|/// on the implementation of the underlying stream.  Updates the stream's
end_comment

begin_comment
comment|/// offset to point after the newly read data.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_function_decl
name|Error
name|readFixedString
parameter_list|(
name|StringRef
modifier|&
name|Dest
parameter_list|,
name|uint32_t
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Read the entire remainder of the underlying stream into \p Ref.  This is
end_comment

begin_comment
comment|/// equivalent to calling getUnderlyingStream().slice(Offset).  Updates the
end_comment

begin_comment
comment|/// stream's offset to point to the end of the stream.  Never causes a copy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_function_decl
name|Error
name|readStreamRef
parameter_list|(
name|BinaryStreamRef
modifier|&
name|Ref
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Read \p Length bytes from the underlying stream into \p Ref.  This is
end_comment

begin_comment
comment|/// equivalent to calling getUnderlyingStream().slice(Offset, Length).
end_comment

begin_comment
comment|/// Updates the stream's offset to point after the newly read object.  Never
end_comment

begin_comment
comment|/// causes a copy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_function_decl
name|Error
name|readStreamRef
parameter_list|(
name|BinaryStreamRef
modifier|&
name|Ref
parameter_list|,
name|uint32_t
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get a pointer to an object of type T from the underlying stream, as if by
end_comment

begin_comment
comment|/// memcpy, and store the result into \p Dest.  It is up to the caller to
end_comment

begin_comment
comment|/// ensure that objects of type T can be safely treated in this manner.
end_comment

begin_comment
comment|/// Updates the stream's offset to point after the newly read object.  Whether
end_comment

begin_comment
comment|/// a copy occurs depends upon the implementation of the underlying
end_comment

begin_comment
comment|/// stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Error
name|readObject
argument_list|(
argument|const T *&Dest
argument_list|)
block|{
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Buffer
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|readBytes
argument_list|(
name|Buffer
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
condition|)
return|return
name|EC
return|;
name|Dest
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|Buffer
operator|.
name|data
argument_list|()
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Get a reference to a \p NumElements element array of objects of type T
end_comment

begin_comment
comment|/// from the underlying stream as if by memcpy, and store the resulting array
end_comment

begin_comment
comment|/// slice into \p array.  It is up to the caller to ensure that objects of
end_comment

begin_comment
comment|/// type T can be safely treated in this manner.  Updates the stream's offset
end_comment

begin_comment
comment|/// to point after the newly read object.  Whether a copy occurs depends upon
end_comment

begin_comment
comment|/// the implementation of the underlying stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|Error
name|readArray
argument_list|(
argument|ArrayRef<T>&Array
argument_list|,
argument|uint32_t NumElements
argument_list|)
block|{
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
block|;
if|if
condition|(
name|NumElements
operator|==
literal|0
condition|)
block|{
name|Array
operator|=
name|ArrayRef
operator|<
name|T
operator|>
operator|(
operator|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|NumElements
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
end_if

begin_if
if|if
condition|(
name|auto
name|EC
init|=
name|readBytes
argument_list|(
name|Bytes
argument_list|,
name|NumElements
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
condition|)
return|return
name|EC
return|;
end_if

begin_expr_stmt
name|assert
argument_list|(
name|alignmentAdjustment
argument_list|(
name|Bytes
operator|.
name|data
argument_list|()
argument_list|,
name|alignof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|==
literal|0
operator|&&
literal|"Reading at invalid alignment!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Array
operator|=
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|Bytes
operator|.
name|data
argument_list|()
operator|)
operator|,
name|NumElements
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Read a VarStreamArray of size \p Size bytes and store the result into
end_comment

begin_comment
comment|/// \p Array.  Updates the stream's offset to point after the newly read
end_comment

begin_comment
comment|/// array.  Never causes a copy (although iterating the elements of the
end_comment

begin_comment
comment|/// VarStreamArray may, depending upon the implementation of the underlying
end_comment

begin_comment
comment|/// stream).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|Error
name|readArray
argument_list|(
argument|VarStreamArray<T
argument_list|,
argument|U>&Array
argument_list|,
argument|uint32_t Size
argument_list|,
argument|typename VarStreamArray<T
argument_list|,
argument|U>::ContextType *Context = nullptr
argument_list|)
block|{
name|BinaryStreamRef
name|S
block|;
if|if
condition|(
name|auto
name|EC
init|=
name|readStreamRef
argument_list|(
name|S
argument_list|,
name|Size
argument_list|)
condition|)
return|return
name|EC
return|;
name|Array
operator|=
name|VarStreamArray
operator|<
name|T
operator|,
name|U
operator|>
operator|(
name|S
operator|,
name|Context
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Read a FixedStreamArray of \p NumItems elements and store the result into
end_comment

begin_comment
comment|/// \p Array.  Updates the stream's offset to point after the newly read
end_comment

begin_comment
comment|/// array.  Never causes a copy (although iterating the elements of the
end_comment

begin_comment
comment|/// FixedStreamArray may, depending upon the implementation of the underlying
end_comment

begin_comment
comment|/// stream).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if the data was successfully read, otherwise
end_comment

begin_comment
comment|/// returns an appropriate error code.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|Error
name|readArray
argument_list|(
argument|FixedStreamArray<T>&Array
argument_list|,
argument|uint32_t NumItems
argument_list|)
block|{
if|if
condition|(
name|NumItems
operator|==
literal|0
condition|)
block|{
name|Array
operator|=
name|FixedStreamArray
operator|<
name|T
operator|>
operator|(
operator|)
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|NumItems
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
end_if

begin_decl_stmt
name|BinaryStreamRef
name|View
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|auto
name|EC
init|=
name|readStreamRef
argument_list|(
name|View
argument_list|,
name|NumItems
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
condition|)
return|return
name|EC
return|;
end_if

begin_expr_stmt
name|Array
operator|=
name|FixedStreamArray
operator|<
name|T
operator|>
operator|(
name|View
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
end_return

begin_macro
unit|}    bool
name|empty
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|bytesRemaining
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Advance the stream's offset by \p Amount bytes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a success error code if at least \p Amount bytes remain in the
end_comment

begin_comment
comment|/// stream, otherwise returns an appropriate error code.
end_comment

begin_function_decl
name|Error
name|skip
parameter_list|(
name|uint32_t
name|Amount
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Examine the next byte of the underlying stream without advancing the
end_comment

begin_comment
comment|/// stream's offset.  If the stream is empty the behavior is undefined.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the next byte in the stream.
end_comment

begin_expr_stmt
name|uint8_t
name|peek
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|BinaryStreamRef
name|Stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|Offset
decl_stmt|;
end_decl_stmt

begin_comment
unit|}; }
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BINARYSTREAMREADER_H
end_comment

end_unit

