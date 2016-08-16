begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LLVMOutputStyle.h -------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_LLVMOUTPUTSTYLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_LLVMOUTPUTSTYLE_H
end_define

begin_include
include|#
directive|include
file|"OutputStyle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDumper.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ScopedPrinter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|LLVMOutputStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|LLVMOutputStyle
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
name|Error
name|dumpFileHeaders
argument_list|()
block|;
name|Error
name|dumpStreamSummary
argument_list|()
block|;
name|Error
name|dumpStreamBlocks
argument_list|()
block|;
name|Error
name|dumpStreamData
argument_list|()
block|;
name|Error
name|dumpInfoStream
argument_list|()
block|;
name|Error
name|dumpNamedStream
argument_list|()
block|;
name|Error
name|dumpTpiStream
argument_list|(
argument|uint32_t StreamIdx
argument_list|)
block|;
name|Error
name|dumpDbiStream
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
name|Error
name|dumpPublicsStream
argument_list|()
block|;
name|Error
name|dumpSectionHeaders
argument_list|()
block|;
name|Error
name|dumpFpoStream
argument_list|()
block|;
name|void
name|flush
argument_list|()
block|;
name|PDBFile
operator|&
name|File
block|;
name|ScopedPrinter
name|P
block|;
name|codeview
operator|::
name|CVTypeDumper
name|TD
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

