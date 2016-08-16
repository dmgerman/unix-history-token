begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBStreamData.h - Base interface for PDB Stream Data ----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_IPDBSTREAMDATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_IPDBSTREAMDATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
comment|/// IPDBStream abstracts the notion of PDB stream data.  Although we already
comment|/// have another stream abstraction (namely in the form of StreamInterface
comment|/// and MappedBlockStream), they assume that the stream data is referenced
comment|/// the same way.  Namely, by looking in the directory to get the list of
comment|/// stream blocks, and by looking in the array of stream lengths to get the
comment|/// length.  This breaks down for the directory itself, however, since its
comment|/// length and list of blocks are stored elsewhere.  By abstracting the
comment|/// notion of stream data further, we can use a MappedBlockStream to read
comment|/// from the directory itself, or from an indexed stream which references
comment|/// the directory.
name|class
name|IPDBStreamData
block|{
name|public
label|:
name|virtual
operator|~
name|IPDBStreamData
argument_list|()
block|{}
name|virtual
name|uint32_t
name|getLength
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|ArrayRef
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|getStreamBlocks
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

