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
name|llvm
block|{
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
name|GraphBase
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
comment|/// \brief Set the selection for a given node.
comment|/// @param nodeId Node id.
comment|/// @param selection Selection for nodeId.
name|void
name|setSelection
argument_list|(
argument|GraphBase::NodeId nodeId
argument_list|,
argument|unsigned selection
argument_list|)
block|{
name|selections
index|[
name|nodeId
index|]
operator|=
name|selection
block|;     }
comment|/// \brief Get a node's selection.
comment|/// @param nodeId Node id.
comment|/// @return The selection for nodeId;
name|unsigned
name|getSelection
argument_list|(
argument|GraphBase::NodeId nodeId
argument_list|)
specifier|const
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
block|;
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
block|;
return|return
name|sItr
operator|->
name|second
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// namespace PBQP
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
comment|// LLVM_CODEGEN_PBQP_SOLUTION_H
end_comment

end_unit

