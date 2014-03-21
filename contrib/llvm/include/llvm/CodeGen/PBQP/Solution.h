begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Solution.h ------- PBQP Solution ------------------------*- C++ -*-===//
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
comment|// PBQP Solution class.
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
file|"Graph.h"
end_include

begin_include
include|#
directive|include
file|"Math.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|PBQP
block|{
comment|/// \brief Represents a solution to a PBQP problem.
comment|///
comment|/// To get the selection for each node in the problem use the getSelection method.
name|class
name|Solution
block|{
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Graph
operator|::
name|NodeId
operator|,
name|unsigned
operator|>
name|SelectionsMap
expr_stmt|;
name|SelectionsMap
name|selections
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
comment|/// \brief Initialise an empty solution.
name|Solution
argument_list|()
operator|:
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
comment|/// \brief Number of nodes for which selections have been made.
comment|/// @return Number of nodes for which selections have been made.
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
comment|/// \brief Records a reduction via the R0 rule. Should be called from the
comment|///        solver only.
name|void
name|recordR0
parameter_list|()
block|{
operator|++
name|r0Reductions
expr_stmt|;
block|}
comment|/// \brief Returns the number of R0 reductions applied to solve the problem.
name|unsigned
name|numR0Reductions
argument_list|()
specifier|const
block|{
return|return
name|r0Reductions
return|;
block|}
comment|/// \brief Records a reduction via the R1 rule. Should be called from the
comment|///        solver only.
name|void
name|recordR1
parameter_list|()
block|{
operator|++
name|r1Reductions
expr_stmt|;
block|}
comment|/// \brief Returns the number of R1 reductions applied to solve the problem.
name|unsigned
name|numR1Reductions
argument_list|()
specifier|const
block|{
return|return
name|r1Reductions
return|;
block|}
comment|/// \brief Records a reduction via the R2 rule. Should be called from the
comment|///        solver only.
name|void
name|recordR2
parameter_list|()
block|{
operator|++
name|r2Reductions
expr_stmt|;
block|}
comment|/// \brief Returns the number of R2 reductions applied to solve the problem.
name|unsigned
name|numR2Reductions
argument_list|()
specifier|const
block|{
return|return
name|r2Reductions
return|;
block|}
comment|/// \brief Records a reduction via the RN rule. Should be called from the
comment|///        solver only.
name|void
name|recordRN
parameter_list|()
block|{
operator|++
name|rNReductions
expr_stmt|;
block|}
comment|/// \brief Returns the number of RN reductions applied to solve the problem.
name|unsigned
name|numRNReductions
argument_list|()
specifier|const
block|{
return|return
name|rNReductions
return|;
block|}
comment|/// \brief Set the selection for a given node.
comment|/// @param nodeId Node id.
comment|/// @param selection Selection for nodeId.
name|void
name|setSelection
argument_list|(
name|Graph
operator|::
name|NodeId
name|nodeId
argument_list|,
name|unsigned
name|selection
argument_list|)
block|{
name|selections
index|[
name|nodeId
index|]
operator|=
name|selection
expr_stmt|;
block|}
comment|/// \brief Get a node's selection.
comment|/// @param nodeId Node id.
comment|/// @return The selection for nodeId;
name|unsigned
name|getSelection
argument_list|(
name|Graph
operator|::
name|NodeId
name|nodeId
argument_list|)
decl|const
block|{
name|SelectionsMap
operator|::
name|const_iterator
name|sItr
operator|=
name|selections
operator|.
name|find
argument_list|(
name|nodeId
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|sItr
operator|!=
name|selections
operator|.
name|end
argument_list|()
operator|&&
literal|"No selection for node."
argument_list|)
expr_stmt|;
return|return
name|sItr
operator|->
name|second
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

