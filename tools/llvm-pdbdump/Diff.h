begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Diff.h - PDB diff utility --------------------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_DIFF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_DIFF_H
end_define

begin_include
include|#
directive|include
file|"OutputStyle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|PDBFile
decl_stmt|;
name|class
name|DiffStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|explicit
name|DiffStyle
argument_list|(
name|PDBFile
operator|&
name|File1
argument_list|,
name|PDBFile
operator|&
name|File2
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
name|diffSuperBlock
argument_list|()
block|;
name|Error
name|diffStreamDirectory
argument_list|()
block|;
name|Error
name|diffStringTable
argument_list|()
block|;
name|Error
name|diffFreePageMap
argument_list|()
block|;
name|Error
name|diffInfoStream
argument_list|()
block|;
name|Error
name|diffDbiStream
argument_list|()
block|;
name|Error
name|diffSectionContribs
argument_list|()
block|;
name|Error
name|diffSectionMap
argument_list|()
block|;
name|Error
name|diffFpoStream
argument_list|()
block|;
name|Error
name|diffTpiStream
argument_list|(
argument|int Index
argument_list|)
block|;
name|Error
name|diffModuleInfoStream
argument_list|(
argument|int Index
argument_list|)
block|;
name|Error
name|diffPublics
argument_list|()
block|;
name|Error
name|diffGlobals
argument_list|()
block|;
name|PDBFile
operator|&
name|File1
block|;
name|PDBFile
operator|&
name|File2
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

