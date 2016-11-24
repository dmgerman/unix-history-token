begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StreamInterface.h - Base interface for a stream of data --*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_STREAMINTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_STREAMINTERFACE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
comment|/// StreamInterface abstracts the notion of a data stream.  This way, an
comment|/// implementation could implement trivial reading from a contiguous memory
comment|/// buffer or, as in the case of PDB files, reading from a set of possibly
comment|/// discontiguous blocks.  The implementation is required to return references
comment|/// to stable memory, so if this is not possible (for example in the case of
comment|/// a PDB file with discontiguous blocks, it must keep its own pool of temp
comment|/// storage.
name|class
name|StreamInterface
block|{
name|public
label|:
name|virtual
operator|~
name|StreamInterface
argument_list|()
block|{}
comment|// Given an offset into the stream and a number of bytes, attempt to read
comment|// the bytes and set the output ArrayRef to point to a reference into the
comment|// stream, without copying any data.
name|virtual
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
operator|=
literal|0
expr_stmt|;
comment|// Given an offset into the stream, read as much as possible without copying
comment|// any data.
name|virtual
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
init|=
literal|0
decl_stmt|;
comment|// Attempt to write the given bytes into the stream at the desired offset.
comment|// This will always necessitate a copy.  Cannot shrink or grow the stream,
comment|// only writes into existing allocated space.
name|virtual
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
init|=
literal|0
decl_stmt|;
name|virtual
name|uint32_t
name|getLength
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|Error
name|commit
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_STREAMINTERFACE_H
end_comment

end_unit

