begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopUnrollAnalyzer.h - Loop Unroll Analyzer-*- C++ -*-===//
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
comment|// This file implements UnrolledInstAnalyzer class. It's used for predicting
end_comment

begin_comment
comment|// potential effects that loop unrolling might have, such as enabling constant
end_comment

begin_comment
comment|// propagation and other optimizations.
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
name|LLVM_ANALYSIS_LOOPUNROLLANALYZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPUNROLLANALYZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/InstructionSimplify.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionExpressions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstVisitor.h"
end_include

begin_comment
comment|// This class is used to get an estimate of the optimization effects that we
end_comment

begin_comment
comment|// could get from complete loop unrolling. It comes from the fact that some
end_comment

begin_comment
comment|// loads might be replaced with concrete constant values and that could trigger
end_comment

begin_comment
comment|// a chain of instruction simplifications.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// E.g. we might have:
end_comment

begin_comment
comment|//   int a[] = {0, 1, 0};
end_comment

begin_comment
comment|//   v = 0;
end_comment

begin_comment
comment|//   for (i = 0; i< 3; i ++)
end_comment

begin_comment
comment|//     v += b[i]*a[i];
end_comment

begin_comment
comment|// If we completely unroll the loop, we would get:
end_comment

begin_comment
comment|//   v = b[0]*a[0] + b[1]*a[1] + b[2]*a[2]
end_comment

begin_comment
comment|// Which then will be simplified to:
end_comment

begin_comment
comment|//   v = b[0]* 0 + b[1]* 1 + b[2]* 0
end_comment

begin_comment
comment|// And finally:
end_comment

begin_comment
comment|//   v = b[1]
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|UnrolledInstAnalyzer
range|:
name|private
name|InstVisitor
operator|<
name|UnrolledInstAnalyzer
decl_stmt|,
name|bool
decl|>
block|{
typedef|typedef
name|InstVisitor
operator|<
name|UnrolledInstAnalyzer
operator|,
name|bool
operator|>
name|Base
expr_stmt|;
name|friend
name|class
name|InstVisitor
operator|<
name|UnrolledInstAnalyzer
operator|,
name|bool
operator|>
expr_stmt|;
struct|struct
name|SimplifiedAddress
block|{
name|Value
modifier|*
name|Base
init|=
name|nullptr
decl_stmt|;
name|ConstantInt
modifier|*
name|Offset
init|=
name|nullptr
decl_stmt|;
block|}
struct|;
name|public
label|:
name|UnrolledInstAnalyzer
argument_list|(
argument|unsigned Iteration
argument_list|,
argument|DenseMap<Value *
argument_list|,
argument|Constant *>&SimplifiedValues
argument_list|,
argument|ScalarEvolution&SE
argument_list|,
argument|const Loop *L
argument_list|)
block|:
name|SimplifiedValues
argument_list|(
name|SimplifiedValues
argument_list|)
operator|,
name|SE
argument_list|(
name|SE
argument_list|)
operator|,
name|L
argument_list|(
argument|L
argument_list|)
block|{
name|IterationNumber
operator|=
name|SE
operator|.
name|getConstant
argument_list|(
name|APInt
argument_list|(
literal|64
argument_list|,
name|Iteration
argument_list|)
argument_list|)
block|;   }
comment|// Allow access to the initial visit method.
name|using
name|Base
operator|::
name|visit
expr_stmt|;
name|private
label|:
comment|/// \brief A cache of pointer bases and constant-folded offsets corresponding
comment|/// to GEP (or derived from GEP) instructions.
comment|///
comment|/// In order to find the base pointer one needs to perform non-trivial
comment|/// traversal of the corresponding SCEV expression, so it's good to have the
comment|/// results saved.
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|SimplifiedAddress
operator|>
name|SimplifiedAddresses
expr_stmt|;
comment|/// \brief SCEV expression corresponding to number of currently simulated
comment|/// iteration.
specifier|const
name|SCEV
modifier|*
name|IterationNumber
decl_stmt|;
comment|/// \brief A Value->Constant map for keeping values that we managed to
comment|/// constant-fold on the given iteration.
comment|///
comment|/// While we walk the loop instructions, we build up and maintain a mapping
comment|/// of simplified values specific to this iteration.  The idea is to propagate
comment|/// any special information we have about loads that can be replaced with
comment|/// constants after complete unrolling, and account for likely simplifications
comment|/// post-unrolling.
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|Constant
operator|*
operator|>
operator|&
name|SimplifiedValues
expr_stmt|;
name|ScalarEvolution
modifier|&
name|SE
decl_stmt|;
specifier|const
name|Loop
modifier|*
name|L
decl_stmt|;
name|bool
name|simplifyInstWithSCEV
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|visitInstruction
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|)
block|{
return|return
name|simplifyInstWithSCEV
argument_list|(
operator|&
name|I
argument_list|)
return|;
block|}
name|bool
name|visitBinaryOperator
parameter_list|(
name|BinaryOperator
modifier|&
name|I
parameter_list|)
function_decl|;
name|bool
name|visitLoad
parameter_list|(
name|LoadInst
modifier|&
name|I
parameter_list|)
function_decl|;
name|bool
name|visitCastInst
parameter_list|(
name|CastInst
modifier|&
name|I
parameter_list|)
function_decl|;
name|bool
name|visitCmpInst
parameter_list|(
name|CmpInst
modifier|&
name|I
parameter_list|)
function_decl|;
name|bool
name|visitPHINode
parameter_list|(
name|PHINode
modifier|&
name|PN
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

end_unit

