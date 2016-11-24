begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ByteStream.h - Reads stream data from a byte sequence ----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_BYTESTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_BYTESTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/StreamInterface.h"
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
file|<memory>
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
name|namespace
name|codeview
block|{
name|class
name|StreamReader
decl_stmt|;
name|template
operator|<
name|bool
name|Writable
operator|=
name|false
operator|>
name|class
name|ByteStream
operator|:
name|public
name|StreamInterface
block|{
typedef|typedef
name|typename
name|std
operator|::
name|conditional
operator|<
name|Writable
operator|,
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|,
name|ArrayRef
operator|<
name|uint8_t
operator|>>
operator|::
name|type
name|ArrayType
expr_stmt|;
name|public
operator|:
name|ByteStream
argument_list|()
block|{}
name|explicit
name|ByteStream
argument_list|(
argument|ArrayType Data
argument_list|)
operator|:
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
operator|~
name|ByteStream
argument_list|()
name|override
block|{}
name|Error
name|readBytes
argument_list|(
argument|uint32_t Offset
argument_list|,
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint8_t>&Buffer
argument_list|)
specifier|const
name|override
expr_stmt|;
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
name|override
decl_stmt|;
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
name|Buffer
argument_list|)
decl|const
name|override
decl_stmt|;
name|uint32_t
name|getLength
argument_list|()
specifier|const
name|override
expr_stmt|;
name|Error
name|commit
argument_list|()
specifier|const
name|override
expr_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|StringRef
name|str
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|ArrayType
name|Data
decl_stmt|;
block|}
empty_stmt|;
extern|extern template class ByteStream<true>;
extern|extern template class ByteStream<false>;
block|}
end_decl_stmt

begin_comment
comment|// end namespace pdb
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_BYTESTREAM_H
end_comment

end_unit

