begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstCombine.h - InstCombine pass -------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file provides the primary interface to the instcombine pass. This pass
end_comment

begin_comment
comment|/// is suitable for use in the new pass manager. For a pass that works with the
end_comment

begin_comment
comment|/// legacy pass manager, please look for \c createInstructionCombiningPass() in
end_comment

begin_comment
comment|/// Scalar.h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_INSTCOMBINE_INSTCOMBINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_INSTCOMBINE_INSTCOMBINE_H
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

begin_include
include|#
directive|include
file|"llvm/Transforms/InstCombine/InstCombineWorklist.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InstCombinePass
block|{
name|InstCombineWorklist
name|Worklist
decl_stmt|;
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"InstCombinePass"
return|;
block|}
comment|// Explicitly define constructors for MSVC.
name|InstCombinePass
argument_list|()
block|{}
name|InstCombinePass
argument_list|(
name|InstCombinePass
operator|&&
name|Arg
argument_list|)
operator|:
name|Worklist
argument_list|(
argument|std::move(Arg.Worklist)
argument_list|)
block|{}
name|InstCombinePass
operator|&
name|operator
operator|=
operator|(
name|InstCombinePass
operator|&&
name|RHS
operator|)
block|{
name|Worklist
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Worklist
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
operator|>
operator|*
name|AM
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

