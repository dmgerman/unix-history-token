begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- YAMLOutputStyle.h -------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLOUTPUTSTYLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLOUTPUTSTYLE_H
end_define

begin_include
include|#
directive|include
file|"OutputStyle.h"
end_include

begin_include
include|#
directive|include
file|"PdbYaml.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ScopedPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|ModuleDebugStreamRef
decl_stmt|;
name|class
name|YAMLOutputStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|YAMLOutputStyle
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
name|Optional
operator|<
name|CodeViewYAML
operator|::
name|SourceFileInfo
operator|>>
name|getFileLineInfo
argument_list|(
specifier|const
name|pdb
operator|::
name|ModuleDebugStreamRef
operator|&
name|ModS
argument_list|)
block|;
name|Error
name|dumpStringTable
argument_list|()
block|;
name|Error
name|dumpFileHeaders
argument_list|()
block|;
name|Error
name|dumpStreamMetadata
argument_list|()
block|;
name|Error
name|dumpStreamDirectory
argument_list|()
block|;
name|Error
name|dumpPDBStream
argument_list|()
block|;
name|Error
name|dumpDbiStream
argument_list|()
block|;
name|Error
name|dumpTpiStream
argument_list|()
block|;
name|Error
name|dumpIpiStream
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
name|llvm
operator|::
name|yaml
operator|::
name|Output
name|Out
block|;
name|yaml
operator|::
name|PdbObject
name|Obj
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

begin_comment
comment|// LLVM_TOOLS_LLVMPDBDUMP_YAMLOUTPUTSTYLE_H
end_comment

end_unit

