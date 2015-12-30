begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ADCE.h - Aggressive dead code elimination --------------------------===//
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
comment|// This file provides the interface for the Aggressive Dead Code Elimination
end_comment

begin_comment
comment|// pass. This pass optimistically assumes that all instructions are dead until
end_comment

begin_comment
comment|// proven otherwise, allowing it to eliminate dead computations that other DCE
end_comment

begin_comment
comment|// passes do not catch, particularly involving loop computations.
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
name|LLVM_TRANSFORMS_SCALAR_ADCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_ADCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A DCE pass that assumes instructions are dead until proven otherwise.
comment|///
comment|/// This pass eliminates dead code by optimistically assuming that all
comment|/// instructions are dead until proven otherwise. This allows it to eliminate
comment|/// dead computations that other DCE passes do not catch, particularly involving
comment|/// loop computations.
name|class
name|ADCEPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"ADCEPass"
return|;
block|}
name|PreservedAnalyses
name|run
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_ADCE_H
end_comment

end_unit

