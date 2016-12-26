begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==------ UpdateCompilerUsed.h - LLVM Link Time Optimizer Utility --------===//
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
comment|// This file declares a helper class to update llvm.compiler_used metadata.
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
name|LLVM_LTO_UPDATE_COMPILER_USED_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_UPDATE_COMPILER_USED_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// Find all globals in \p TheModule that are referenced in
comment|/// \p AsmUndefinedRefs, as well as the user-supplied functions definitions that
comment|/// are also libcalls, and create or update the magic "llvm.compiler_used"
comment|/// global in \p TheModule.
name|void
name|updateCompilerUsed
argument_list|(
name|Module
operator|&
name|TheModule
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|StringSet
operator|<
operator|>
operator|&
name|AsmUndefinedRefs
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LTO_UPDATE_COMPILER_USED_H
end_comment

end_unit

