begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BytesOutputStyle.h ------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_BYTESOUTPUTSTYLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_BYTESOUTPUTSTYLE_H
end_define

begin_include
include|#
directive|include
file|"LinePrinter.h"
end_include

begin_include
include|#
directive|include
file|"OutputStyle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|LazyRandomTypeCollection
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|PDBFile
decl_stmt|;
name|class
name|BytesOutputStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|BytesOutputStyle
argument_list|(
name|PDBFile
operator|&
name|File
argument_list|)
block|;
name|Error
name|dump
argument_list|()
name|override
block|;
name|private
operator|:
name|void
name|dumpNameMap
argument_list|()
block|;
name|void
name|dumpBlockRanges
argument_list|(
argument|uint32_t Min
argument_list|,
argument|uint32_t Max
argument_list|)
block|;
name|void
name|dumpByteRanges
argument_list|(
argument|uint32_t Min
argument_list|,
argument|uint32_t Max
argument_list|)
block|;
name|void
name|dumpStreamBytes
argument_list|()
block|;
name|void
name|dumpSectionContributions
argument_list|()
block|;
name|void
name|dumpSectionMap
argument_list|()
block|;
name|void
name|dumpModuleInfos
argument_list|()
block|;
name|void
name|dumpFileInfo
argument_list|()
block|;
name|void
name|dumpTypeServerMap
argument_list|()
block|;
name|void
name|dumpECData
argument_list|()
block|;
name|void
name|dumpModuleSyms
argument_list|()
block|;
name|void
name|dumpModuleC11
argument_list|()
block|;
name|void
name|dumpModuleC13
argument_list|()
block|;
name|void
name|dumpTypeIndex
argument_list|(
argument|uint32_t StreamIdx
argument_list|,
argument|ArrayRef<uint32_t> Indices
argument_list|)
block|;
name|Expected
operator|<
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|&
operator|>
name|initializeTypes
argument_list|(
argument|uint32_t StreamIdx
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|>
name|TpiTypes
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|>
name|IpiTypes
block|;
name|PDBFile
operator|&
name|File
block|;
name|LinePrinter
name|P
block|;
name|ExitOnError
name|Err
block|;
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|8
operator|>
name|StreamPurposes
block|; }
decl_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

