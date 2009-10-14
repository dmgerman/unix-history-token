begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Solution.h ------- PBQP Solution -----------------------*- C++ --*-===//
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
comment|// Annotated PBQP Graph class. This class is used internally by the PBQP solver
end_comment

begin_comment
comment|// to cache information to speed up reduction.
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
name|LLVM_CODEGEN_PBQP_SOLUTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PBQP_SOLUTION_H
end_define

begin_include
include|#
directive|include
file|"PBQPMath.h"
end_include

begin_decl_stmt
name|namespace
name|PBQP
block|{
name|class
name|Solution
block|{
name|friend
name|class
name|SolverImplementation
decl_stmt|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|selections
expr_stmt|;
name|PBQPNum
name|solutionCost
decl_stmt|;
name|bool
name|provedOptimal
decl_stmt|;
name|unsigned
name|r0Reductions
decl_stmt|,
name|r1Reductions
decl_stmt|,
name|r2Reductions
decl_stmt|,
name|rNReductions
decl_stmt|;
name|public
label|:
name|Solution
argument_list|()
operator|:
name|solutionCost
argument_list|(
literal|0.0
argument_list|)
operator|,
name|provedOptimal
argument_list|(
name|false
argument_list|)
operator|,
name|r0Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|r1Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|r2Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|rNReductions
argument_list|(
literal|0
argument_list|)
block|{}
name|Solution
argument_list|(
argument|unsigned length
argument_list|,
argument|bool assumeOptimal
argument_list|)
operator|:
name|selections
argument_list|(
name|length
argument_list|)
operator|,
name|solutionCost
argument_list|(
literal|0.0
argument_list|)
operator|,
name|provedOptimal
argument_list|(
name|assumeOptimal
argument_list|)
operator|,
name|r0Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|r1Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|r2Reductions
argument_list|(
literal|0
argument_list|)
operator|,
name|rNReductions
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setProvedOptimal
argument_list|(
argument|bool provedOptimal
argument_list|)
block|{
name|this
operator|->
name|provedOptimal
operator|=
name|provedOptimal
block|;   }
name|void
name|setSelection
argument_list|(
argument|unsigned nodeID
argument_list|,
argument|unsigned selection
argument_list|)
block|{
name|selections
index|[
name|nodeID
index|]
operator|=
name|selection
block|;   }
name|void
name|setSolutionCost
argument_list|(
argument|PBQPNum solutionCost
argument_list|)
block|{
name|this
operator|->
name|solutionCost
operator|=
name|solutionCost
block|;   }
name|void
name|incR0Reductions
argument_list|()
block|{
operator|++
name|r0Reductions
block|; }
name|void
name|incR1Reductions
argument_list|()
block|{
operator|++
name|r1Reductions
block|; }
name|void
name|incR2Reductions
argument_list|()
block|{
operator|++
name|r2Reductions
block|; }
name|void
name|incRNReductions
argument_list|()
block|{
operator|++
name|rNReductions
block|; }
name|unsigned
name|numNodes
argument_list|()
specifier|const
block|{
return|return
name|selections
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|getSelection
argument_list|(
name|unsigned
name|nodeID
argument_list|)
decl|const
block|{
return|return
name|selections
index|[
name|nodeID
index|]
return|;
block|}
name|PBQPNum
name|getCost
argument_list|()
specifier|const
block|{
return|return
name|solutionCost
return|;
block|}
name|bool
name|isProvedOptimal
argument_list|()
specifier|const
block|{
return|return
name|provedOptimal
return|;
block|}
name|unsigned
name|getR0Reductions
argument_list|()
specifier|const
block|{
return|return
name|r0Reductions
return|;
block|}
name|unsigned
name|getR1Reductions
argument_list|()
specifier|const
block|{
return|return
name|r1Reductions
return|;
block|}
name|unsigned
name|getR2Reductions
argument_list|()
specifier|const
block|{
return|return
name|r2Reductions
return|;
block|}
name|unsigned
name|getRNReductions
argument_list|()
specifier|const
block|{
return|return
name|rNReductions
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Solution
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|(
name|selections
operator|==
name|other
operator|.
name|selections
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Solution
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_PBQP_SOLUTION_H
end_comment

end_unit

