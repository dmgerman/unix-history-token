begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Analyze.h - PDB analysis functions -----------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_ANALYSIS_H
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
name|AnalysisStyle
range|:
name|public
name|OutputStyle
block|{
name|public
operator|:
name|explicit
name|AnalysisStyle
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
name|PDBFile
operator|&
name|File
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

