begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Transforms/Utils/SimplifyIndVar.h - Indvar Utils ---*- C++ -*-===//
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
comment|// This file defines in interface for induction variable simplification. It does
end_comment

begin_comment
comment|// not define any actual pass or policy, but provides a single function to
end_comment

begin_comment
comment|// simplify a loop's induction variables based on ScalarEvolution.
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
name|LLVM_TRANSFORMS_UTILS_SIMPLIFYINDVAR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SIMPLIFYINDVAR_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CastInst
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
comment|/// Interface for visiting interesting IV users that are recognized but not
comment|/// simplified by this utility.
name|class
name|IVVisitor
block|{
name|protected
label|:
specifier|const
name|DominatorTree
modifier|*
name|DT
init|=
name|nullptr
decl_stmt|;
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|IVVisitor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|IVVisitor
argument_list|()
operator|=
expr|default
expr_stmt|;
specifier|const
name|DominatorTree
operator|*
name|getDomTree
argument_list|()
specifier|const
block|{
return|return
name|DT
return|;
block|}
name|virtual
name|void
name|visitCast
parameter_list|(
name|CastInst
modifier|*
name|Cast
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// simplifyUsersOfIV - Simplify instructions that use this induction variable
comment|/// by using ScalarEvolution to analyze the IV's recurrence.
name|bool
name|simplifyUsersOfIV
argument_list|(
name|PHINode
operator|*
name|CurrIV
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|,
name|SmallVectorImpl
operator|<
name|WeakVH
operator|>
operator|&
name|Dead
argument_list|,
name|IVVisitor
operator|*
name|V
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// SimplifyLoopIVs - Simplify users of induction variables within this
comment|/// loop. This does not actually change or add IVs.
name|bool
name|simplifyLoopIVs
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|,
name|SmallVectorImpl
operator|<
name|WeakVH
operator|>
operator|&
name|Dead
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_SIMPLIFYINDVAR_H
end_comment

end_unit

