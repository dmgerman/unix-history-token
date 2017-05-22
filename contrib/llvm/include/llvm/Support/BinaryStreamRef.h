begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStreamRef.h - A copyable reference to a stream -----*- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYSTREAMREF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAMREF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamError.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Common stuff for mutable and immutable StreamRefs.
name|template
operator|<
name|class
name|RefType
operator|,
name|class
name|StreamType
operator|>
name|class
name|BinaryStreamRefBase
block|{
name|protected
operator|:
name|BinaryStreamRefBase
argument_list|()
operator|=
expr|default
block|;
name|BinaryStreamRefBase
argument_list|(
argument|std::shared_ptr<StreamType> SharedImpl
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
operator|:
name|SharedImpl
argument_list|(
name|SharedImpl
argument_list|)
block|,
name|BorrowedImpl
argument_list|(
name|SharedImpl
operator|.
name|get
argument_list|()
argument_list|)
block|,
name|ViewOffset
argument_list|(
name|Offset
argument_list|)
block|,
name|Length
argument_list|(
argument|Length
argument_list|)
block|{}
name|BinaryStreamRefBase
argument_list|(
argument|StreamType&BorrowedImpl
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
operator|:
name|BorrowedImpl
argument_list|(
operator|&
name|BorrowedImpl
argument_list|)
block|,
name|ViewOffset
argument_list|(
name|Offset
argument_list|)
block|,
name|Length
argument_list|(
argument|Length
argument_list|)
block|{}
name|BinaryStreamRefBase
argument_list|(
argument|const BinaryStreamRefBase&Other
argument_list|)
block|{
name|SharedImpl
operator|=
name|Other
operator|.
name|SharedImpl
block|;
name|BorrowedImpl
operator|=
name|Other
operator|.
name|BorrowedImpl
block|;
name|ViewOffset
operator|=
name|Other
operator|.
name|ViewOffset
block|;
name|Length
operator|=
name|Other
operator|.
name|Length
block|;   }
name|public
operator|:
name|llvm
operator|::
name|support
operator|::
name|endianness
name|getEndian
argument_list|()
specifier|const
block|{
return|return
name|BorrowedImpl
operator|->
name|getEndian
argument_list|()
return|;
block|}
name|uint32_t
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|Length
return|;
block|}
comment|/// Return a new BinaryStreamRef with the first \p N elements removed.
name|RefType
name|drop_front
argument_list|(
argument|uint32_t N
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|BorrowedImpl
condition|)
return|return
name|RefType
argument_list|()
return|;
name|N
operator|=
name|std
operator|::
name|min
argument_list|(
name|N
argument_list|,
name|Length
argument_list|)
block|;
name|RefType
name|Result
argument_list|(
name|static_cast
operator|<
specifier|const
name|RefType
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
argument_list|)
block|;
name|Result
operator|.
name|ViewOffset
operator|+=
name|N
block|;
name|Result
operator|.
name|Length
operator|-=
name|N
block|;
return|return
name|Result
return|;
block|}
comment|/// Return a new BinaryStreamRef with the first \p N elements removed.
name|RefType
name|drop_back
argument_list|(
name|uint32_t
name|N
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|BorrowedImpl
condition|)
return|return
name|RefType
argument_list|()
return|;
name|N
operator|=
name|std
operator|::
name|min
argument_list|(
name|N
argument_list|,
name|Length
argument_list|)
expr_stmt|;
name|RefType
name|Result
argument_list|(
name|static_cast
operator|<
specifier|const
name|RefType
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
argument_list|)
decl_stmt|;
name|Result
operator|.
name|Length
operator|-=
name|N
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// Return a new BinaryStreamRef with only the first \p N elements remaining.
name|RefType
name|keep_front
argument_list|(
name|uint32_t
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<=
name|getLength
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|drop_back
argument_list|(
name|getLength
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
comment|/// Return a new BinaryStreamRef with only the last \p N elements remaining.
name|RefType
name|keep_back
argument_list|(
name|uint32_t
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<=
name|getLength
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|drop_front
argument_list|(
name|getLength
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
comment|/// Return a new BinaryStreamRef with the first and last \p N elements
comment|/// removed.
name|RefType
name|drop_symmetric
argument_list|(
name|uint32_t
name|N
argument_list|)
decl|const
block|{
return|return
name|drop_front
argument_list|(
name|N
argument_list|)
operator|.
name|drop_back
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// Return a new BinaryStreamRef with the first \p Offset elements removed,
comment|/// and retaining exactly \p Len elements.
name|RefType
name|slice
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|uint32_t
name|Len
argument_list|)
decl|const
block|{
return|return
name|drop_front
argument_list|(
name|Offset
argument_list|)
operator|.
name|keep_front
argument_list|(
name|Len
argument_list|)
return|;
block|}
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|BorrowedImpl
operator|!=
name|nullptr
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RefType
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|BorrowedImpl
operator|!=
name|Other
operator|.
name|BorrowedImpl
condition|)
return|return
name|false
return|;
if|if
condition|(
name|ViewOffset
operator|!=
name|Other
operator|.
name|ViewOffset
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Length
operator|!=
name|Other
operator|.
name|Length
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|Error
name|checkOffset
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|uint32_t
name|DataSize
argument_list|)
decl|const
block|{
if|if
condition|(
name|Offset
operator|>
name|getLength
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|BinaryStreamError
operator|>
operator|(
name|stream_error_code
operator|::
name|invalid_offset
operator|)
return|;
if|if
condition|(
name|getLength
argument_list|()
operator|<
name|DataSize
operator|+
name|Offset
condition|)
return|return
name|make_error
operator|<
name|BinaryStreamError
operator|>
operator|(
name|stream_error_code
operator|::
name|stream_too_short
operator|)
return|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|StreamType
operator|>
name|SharedImpl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|StreamType
modifier|*
name|BorrowedImpl
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|ViewOffset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|Length
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief BinaryStreamRef is to BinaryStream what ArrayRef is to an Array.  It
end_comment

begin_comment
comment|/// provides copy-semantics and read only access to a "window" of the underlying
end_comment

begin_comment
comment|/// BinaryStream. Note that BinaryStreamRef is *not* a BinaryStream.  That is to
end_comment

begin_comment
comment|/// say, it does not inherit and override the methods of BinaryStream.  In
end_comment

begin_comment
comment|/// general, you should not pass around pointers or references to BinaryStreams
end_comment

begin_comment
comment|/// and use inheritance to achieve polymorphism.  Instead, you should pass
end_comment

begin_comment
comment|/// around BinaryStreamRefs by value and achieve polymorphism that way.
end_comment

begin_decl_stmt
name|class
name|BinaryStreamRef
range|:
name|public
name|BinaryStreamRefBase
operator|<
name|BinaryStreamRef
decl_stmt|,
name|BinaryStream
decl|>
block|{
name|friend
name|BinaryStreamRefBase
operator|<
name|BinaryStreamRef
operator|,
name|BinaryStream
operator|>
expr_stmt|;
name|friend
name|class
name|WritableBinaryStreamRef
decl_stmt|;
name|BinaryStreamRef
argument_list|(
argument|std::shared_ptr<BinaryStream> Impl
argument_list|,
argument|uint32_t ViewOffset
argument_list|,
argument|uint32_t Length
argument_list|)
block|:
name|BinaryStreamRefBase
argument_list|(
argument|Impl
argument_list|,
argument|ViewOffset
argument_list|,
argument|Length
argument_list|)
block|{}
name|public
label|:
name|BinaryStreamRef
argument_list|()
operator|=
expr|default
expr_stmt|;
name|BinaryStreamRef
argument_list|(
name|BinaryStream
operator|&
name|Stream
argument_list|)
expr_stmt|;
name|BinaryStreamRef
argument_list|(
argument|BinaryStream&Stream
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
empty_stmt|;
name|explicit
name|BinaryStreamRef
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|,
name|llvm
operator|::
name|support
operator|::
name|endianness
name|Endian
argument_list|)
decl_stmt|;
name|explicit
name|BinaryStreamRef
argument_list|(
name|StringRef
name|Data
argument_list|,
name|llvm
operator|::
name|support
operator|::
name|endianness
name|Endian
argument_list|)
decl_stmt|;
name|BinaryStreamRef
argument_list|(
specifier|const
name|BinaryStreamRef
operator|&
name|Other
argument_list|)
expr_stmt|;
comment|// Use BinaryStreamRef.slice() instead.
name|BinaryStreamRef
argument_list|(
argument|BinaryStreamRef&S
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Given an Offset into this StreamRef and a Size, return a reference to a
comment|/// buffer owned by the stream.
comment|///
comment|/// \returns a success error code if the entire range of data is within the
comment|/// bounds of this BinaryStreamRef's view and the implementation could read
comment|/// the data, and an appropriate error code otherwise.
name|Error
name|readBytes
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|uint32_t
name|Size
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
decl|const
decl_stmt|;
comment|/// Given an Offset into this BinaryStreamRef, return a reference to the
comment|/// largest buffer the stream could support without necessitating a copy.
comment|///
comment|/// \returns a success error code if implementation could read the data,
comment|/// and an appropriate error code otherwise.
name|Error
name|readLongestContiguousChunk
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|Buffer
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|WritableBinaryStreamRef
range|:
name|public
name|BinaryStreamRefBase
operator|<
name|WritableBinaryStreamRef
decl_stmt|,
name|WritableBinaryStream
decl|>
block|{
name|friend
name|BinaryStreamRefBase
operator|<
name|WritableBinaryStreamRef
operator|,
name|WritableBinaryStream
operator|>
expr_stmt|;
name|WritableBinaryStreamRef
argument_list|(
argument|std::shared_ptr<WritableBinaryStream> Impl
argument_list|,
argument|uint32_t ViewOffset
argument_list|,
argument|uint32_t Length
argument_list|)
block|:
name|BinaryStreamRefBase
argument_list|(
argument|Impl
argument_list|,
argument|ViewOffset
argument_list|,
argument|Length
argument_list|)
block|{}
name|public
label|:
name|WritableBinaryStreamRef
argument_list|()
operator|=
expr|default
expr_stmt|;
name|WritableBinaryStreamRef
argument_list|(
name|WritableBinaryStream
operator|&
name|Stream
argument_list|)
expr_stmt|;
name|WritableBinaryStreamRef
argument_list|(
argument|WritableBinaryStream&Stream
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
empty_stmt|;
name|explicit
name|WritableBinaryStreamRef
argument_list|(
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|,
name|llvm
operator|::
name|support
operator|::
name|endianness
name|Endian
argument_list|)
decl_stmt|;
name|WritableBinaryStreamRef
argument_list|(
specifier|const
name|WritableBinaryStreamRef
operator|&
name|Other
argument_list|)
expr_stmt|;
comment|// Use WritableBinaryStreamRef.slice() instead.
name|WritableBinaryStreamRef
argument_list|(
argument|WritableBinaryStreamRef&S
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|uint32_t Length
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Given an Offset into this WritableBinaryStreamRef and some input data,
comment|/// writes the data to the underlying stream.
comment|///
comment|/// \returns a success error code if the data could fit within the underlying
comment|/// stream at the specified location and the implementation could write the
comment|/// data, and an appropriate error code otherwise.
name|Error
name|writeBytes
argument_list|(
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
decl|const
decl_stmt|;
comment|/// Conver this WritableBinaryStreamRef to a read-only BinaryStreamRef.
name|operator
name|BinaryStreamRef
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief For buffered streams, commits changes to the backing store.
name|Error
name|commit
parameter_list|()
function_decl|;
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
comment|// LLVM_SUPPORT_BINARYSTREAMREF_H
end_comment

end_unit

