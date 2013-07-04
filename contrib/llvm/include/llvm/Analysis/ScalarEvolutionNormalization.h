begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/ScalarEvolutionNormalization.h - See below -*- C++ -*-===//
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
comment|// This file defines utilities for working with "normalized" ScalarEvolution
end_comment

begin_comment
comment|// expressions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following example illustrates post-increment uses and how normalized
end_comment

begin_comment
comment|// expressions help.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   for (i=0; i!=n; ++i) {
end_comment

begin_comment
comment|//     ...
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//   use(i);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// While the expression for most uses of i inside the loop is {0,+,1}<%L>, the
end_comment

begin_comment
comment|// expression for the use of i outside the loop is {1,+,1}<%L>, since i is
end_comment

begin_comment
comment|// incremented at the end of the loop body. This is inconveient, since it
end_comment

begin_comment
comment|// suggests that we need two different induction variables, one that starts
end_comment

begin_comment
comment|// at 0 and one that starts at 1. We'd prefer to be able to think of these as
end_comment

begin_comment
comment|// the same induction variable, with uses inside the loop using the
end_comment

begin_comment
comment|// "pre-incremented" value, and uses after the loop using the
end_comment

begin_comment
comment|// "post-incremented" value.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Expressions for post-incremented uses are represented as an expression
end_comment

begin_comment
comment|// paired with a set of loops for which the expression is in "post-increment"
end_comment

begin_comment
comment|// mode (there may be multiple loops).
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
name|LLVM_ANALYSIS_SCALAREVOLUTIONNORMALIZATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCALAREVOLUTIONNORMALIZATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Instruction
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// TransformKind - Different types of transformations that
comment|/// TransformForPostIncUse can do.
enum|enum
name|TransformKind
block|{
comment|/// Normalize - Normalize according to the given loops.
name|Normalize
block|,
comment|/// NormalizeAutodetect - Detect post-inc opportunities on new expressions,
comment|/// update the given loop set, and normalize.
name|NormalizeAutodetect
block|,
comment|/// Denormalize - Perform the inverse transform on the expression with the
comment|/// given loop set.
name|Denormalize
block|}
enum|;
comment|/// PostIncLoopSet - A set of loops.
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|Loop
operator|*
operator|,
literal|2
operator|>
name|PostIncLoopSet
expr_stmt|;
comment|/// TransformForPostIncUse - Transform the given expression according to the
comment|/// given transformation kind.
specifier|const
name|SCEV
modifier|*
name|TransformForPostIncUse
parameter_list|(
name|TransformKind
name|Kind
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
name|Instruction
modifier|*
name|User
parameter_list|,
name|Value
modifier|*
name|OperandValToReplace
parameter_list|,
name|PostIncLoopSet
modifier|&
name|Loops
parameter_list|,
name|ScalarEvolution
modifier|&
name|SE
parameter_list|,
name|DominatorTree
modifier|&
name|DT
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

