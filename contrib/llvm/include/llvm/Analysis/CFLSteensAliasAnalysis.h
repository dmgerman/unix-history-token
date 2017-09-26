begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- CFLSteensAliasAnalysis.h - Unification-based Alias Analysis ---*- C++-*-=//
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
comment|/// This is the interface for LLVM's unification-based alias analysis
end_comment

begin_comment
comment|/// implemented with CFL graph reachability.
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
name|LLVM_ANALYSIS_CFLSTEENSALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CFLSTEENSALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CFLAliasAnalysisUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<forward_list>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetLibraryInfo
decl_stmt|;
name|namespace
name|cflaa
block|{
struct_decl|struct
name|AliasSummary
struct_decl|;
block|}
name|class
name|CFLSteensAAResult
range|:
name|public
name|AAResultBase
operator|<
name|CFLSteensAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|CFLSteensAAResult
operator|>
block|;
name|class
name|FunctionInfo
block|;
name|public
operator|:
name|explicit
name|CFLSteensAAResult
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
argument_list|)
block|;
name|CFLSteensAAResult
argument_list|(
name|CFLSteensAAResult
operator|&&
name|Arg
argument_list|)
block|;
operator|~
name|CFLSteensAAResult
argument_list|()
block|;
comment|/// Handle invalidation events from the new pass manager.
comment|///
comment|/// By definition, this result is stateless and so remains valid.
name|bool
name|invalidate
argument_list|(
argument|Function&
argument_list|,
argument|const PreservedAnalyses&
argument_list|,
argument|FunctionAnalysisManager::Invalidator&
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Inserts the given Function into the cache.
name|void
name|scan
argument_list|(
name|Function
operator|*
name|Fn
argument_list|)
block|;
name|void
name|evict
argument_list|(
name|Function
operator|*
name|Fn
argument_list|)
block|;
comment|/// \brief Ensures that the given function is available in the cache.
comment|/// Returns the appropriate entry from the cache.
specifier|const
name|Optional
operator|<
name|FunctionInfo
operator|>
operator|&
name|ensureCached
argument_list|(
name|Function
operator|*
name|Fn
argument_list|)
block|;
comment|/// \brief Get the alias summary for the given function
comment|/// Return nullptr if the summary is not found or not available
specifier|const
name|cflaa
operator|::
name|AliasSummary
operator|*
name|getAliasSummary
argument_list|(
name|Function
operator|&
name|Fn
argument_list|)
block|;
name|AliasResult
name|query
argument_list|(
specifier|const
name|MemoryLocation
operator|&
name|LocA
argument_list|,
specifier|const
name|MemoryLocation
operator|&
name|LocB
argument_list|)
block|;
name|AliasResult
name|alias
argument_list|(
argument|const MemoryLocation&LocA
argument_list|,
argument|const MemoryLocation&LocB
argument_list|)
block|{
if|if
condition|(
name|LocA
operator|.
name|Ptr
operator|==
name|LocB
operator|.
name|Ptr
condition|)
return|return
name|LocA
operator|.
name|Size
operator|==
name|LocB
operator|.
name|Size
operator|?
name|MustAlias
operator|:
name|PartialAlias
return|;
comment|// Comparisons between global variables and other constants should be
comment|// handled by BasicAA.
comment|// CFLSteensAA may report NoAlias when comparing a GlobalValue and
comment|// ConstantExpr, but every query needs to have at least one Value tied to a
comment|// Function, and neither GlobalValues nor ConstantExprs are.
if|if
condition|(
name|isa
operator|<
name|Constant
operator|>
operator|(
name|LocA
operator|.
name|Ptr
operator|)
operator|&&
name|isa
operator|<
name|Constant
operator|>
operator|(
name|LocB
operator|.
name|Ptr
operator|)
condition|)
return|return
name|AAResultBase
operator|::
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
return|;
name|AliasResult
name|QueryResult
operator|=
name|query
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
decl_stmt|;
if|if
condition|(
name|QueryResult
operator|==
name|MayAlias
condition|)
return|return
name|AAResultBase
operator|::
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
return|;
return|return
name|QueryResult
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|TargetLibraryInfo
modifier|&
name|TLI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Cached mapping of Functions to their StratifiedSets.
end_comment

begin_comment
comment|/// If a function's sets are currently being built, it is marked
end_comment

begin_comment
comment|/// in the cache as an Optional without a value. This way, if we
end_comment

begin_comment
comment|/// have any kind of recursion, it is discernable from a function
end_comment

begin_comment
comment|/// that simply has empty sets.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
name|Function
operator|*
operator|,
name|Optional
operator|<
name|FunctionInfo
operator|>>
name|Cache
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|forward_list
operator|<
name|cflaa
operator|::
name|FunctionHandle
operator|<
name|CFLSteensAAResult
operator|>>
name|Handles
expr_stmt|;
end_expr_stmt

begin_function_decl
name|FunctionInfo
name|buildSetsFrom
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// Analysis pass providing a never-invalidated alias analysis result.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We really should refactor CFL to use the analysis more heavily, and
end_comment

begin_comment
comment|/// in particular to leverage invalidation to trigger re-computation of sets.
end_comment

begin_decl_stmt
name|class
name|CFLSteensAA
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|CFLSteensAA
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|CFLSteensAA
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|CFLSteensAAResult
name|Result
typedef|;
name|CFLSteensAAResult
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
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Legacy wrapper pass to provide the CFLSteensAAResult object.
end_comment

begin_decl_stmt
name|class
name|CFLSteensAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|CFLSteensAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|CFLSteensAAWrapperPass
argument_list|()
block|;
name|CFLSteensAAResult
operator|&
name|getResult
argument_list|()
block|{
return|return
operator|*
name|Result
return|;
block|}
specifier|const
name|CFLSteensAAResult
operator|&
name|getResult
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Result
return|;
block|}
name|void
name|initializePass
argument_list|()
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// createCFLSteensAAWrapperPass - This pass implements a set-based approach to
end_comment

begin_comment
comment|// alias analysis.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|ImmutablePass
modifier|*
name|createCFLSteensAAWrapperPass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

