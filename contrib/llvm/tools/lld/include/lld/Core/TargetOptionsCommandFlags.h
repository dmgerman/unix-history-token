begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TargetOptionsCommandFlags.h ----------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Helper to create TargetOptions from command line flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|llvm
operator|::
name|TargetOptions
name|InitTargetOptionsFromCodeGenFlags
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|CodeModel
operator|::
name|Model
name|GetCodeModelFromCMModel
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

end_unit

