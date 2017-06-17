begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RawOutputStyle.h -------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_RAWOUTPUTSTYLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_RAWOUTPUTSTYLE_H
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
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDatabase.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
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
name|RawOutputStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|RawOutputStyle
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
name|Expected
operator|<
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|&
operator|>
name|initializeTypeDatabase
argument_list|(
argument|uint32_t SN
argument_list|)
block|;
name|Error
name|dumpFileSummary
argument_list|()
block|;
name|Error
name|dumpStreamSummary
argument_list|()
block|;
name|Error
name|dumpBlockRanges
argument_list|()
block|;
name|Error
name|dumpStreamBytes
argument_list|()
block|;
name|Error
name|dumpStringTable
argument_list|()
block|;
name|Error
name|dumpLines
argument_list|()
block|;
name|Error
name|dumpInlineeLines
argument_list|()
block|;
name|Error
name|dumpXmi
argument_list|()
block|;
name|Error
name|dumpXme
argument_list|()
block|;
name|Error
name|dumpTpiStream
argument_list|(
argument|uint32_t StreamIdx
argument_list|)
block|;
name|Error
name|dumpModules
argument_list|()
block|;
name|Error
name|dumpModuleFiles
argument_list|()
block|;
name|Error
name|dumpModuleSyms
argument_list|()
block|;
name|Error
name|dumpPublics
argument_list|()
block|;
name|Error
name|dumpSectionContribs
argument_list|()
block|;
name|Error
name|dumpSectionMap
argument_list|()
block|;
name|PDBFile
operator|&
name|File
block|;
name|LinePrinter
name|P
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
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|32
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

