begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AliasAnalysisEvaluator.h - Alias Analysis Accuracy Evaluator -------===//
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
comment|/// This file implements a simple N^2 alias analysis accuracy evaluator. The
end_comment

begin_comment
comment|/// analysis result is a set of statistics of how many times the AA
end_comment

begin_comment
comment|/// infrastructure provides each kind of alias result and mod/ref result when
end_comment

begin_comment
comment|/// queried with all pairs of pointers in the function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It can be used to evaluate a change in an alias analysis implementation,
end_comment

begin_comment
comment|/// algorithm, or the AA pipeline infrastructure itself. It acts like a stable
end_comment

begin_comment
comment|/// and easily tested consumer of all AA information exposed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is inspired and adapted from code by: Naveen Neelakantam, Francesco
end_comment

begin_comment
comment|/// Spadini, and Wojciech Stryjewski.
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
name|LLVM_ANALYSIS_ALIASANALYSISEVALUATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ALIASANALYSISEVALUATOR_H
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
name|class
name|AAResults
decl_stmt|;
name|class
name|AAEvaluator
range|:
name|public
name|PassInfoMixin
operator|<
name|AAEvaluator
operator|>
block|{
name|int64_t
name|FunctionCount
block|;
name|int64_t
name|NoAliasCount
block|,
name|MayAliasCount
block|,
name|PartialAliasCount
block|,
name|MustAliasCount
block|;
name|int64_t
name|NoModRefCount
block|,
name|ModCount
block|,
name|RefCount
block|,
name|ModRefCount
block|;
name|public
operator|:
name|AAEvaluator
argument_list|()
operator|:
name|FunctionCount
argument_list|()
block|,
name|NoAliasCount
argument_list|()
block|,
name|MayAliasCount
argument_list|()
block|,
name|PartialAliasCount
argument_list|()
block|,
name|MustAliasCount
argument_list|()
block|,
name|NoModRefCount
argument_list|()
block|,
name|ModCount
argument_list|()
block|,
name|RefCount
argument_list|()
block|,
name|ModRefCount
argument_list|()
block|{}
name|AAEvaluator
argument_list|(
name|AAEvaluator
operator|&&
name|Arg
argument_list|)
operator|:
name|FunctionCount
argument_list|(
name|Arg
operator|.
name|FunctionCount
argument_list|)
block|,
name|NoAliasCount
argument_list|(
name|Arg
operator|.
name|NoAliasCount
argument_list|)
block|,
name|MayAliasCount
argument_list|(
name|Arg
operator|.
name|MayAliasCount
argument_list|)
block|,
name|PartialAliasCount
argument_list|(
name|Arg
operator|.
name|PartialAliasCount
argument_list|)
block|,
name|MustAliasCount
argument_list|(
name|Arg
operator|.
name|MustAliasCount
argument_list|)
block|,
name|NoModRefCount
argument_list|(
name|Arg
operator|.
name|NoModRefCount
argument_list|)
block|,
name|ModCount
argument_list|(
name|Arg
operator|.
name|ModCount
argument_list|)
block|,
name|RefCount
argument_list|(
name|Arg
operator|.
name|RefCount
argument_list|)
block|,
name|ModRefCount
argument_list|(
argument|Arg.ModRefCount
argument_list|)
block|{
name|Arg
operator|.
name|FunctionCount
operator|=
literal|0
block|;   }
operator|~
name|AAEvaluator
argument_list|()
block|;
comment|/// \brief Run the pass over the function.
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|private
operator|:
comment|// Allow the legacy pass to run this using an internal API.
name|friend
name|class
name|AAEvalLegacyPass
block|;
name|void
name|runInternal
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AAResults
operator|&
name|AA
argument_list|)
block|; }
decl_stmt|;
comment|/// Create a wrapper of the above for the legacy pass manager.
name|FunctionPass
modifier|*
name|createAAEvalPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

