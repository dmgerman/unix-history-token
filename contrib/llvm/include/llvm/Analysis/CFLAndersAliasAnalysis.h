begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- CFLAndersAliasAnalysis.h - Unification-based Alias Analysis ---*- C++-*-=//
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
comment|/// This is the interface for LLVM's inclusion-based alias analysis
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
name|LLVM_ANALYSIS_CFLANDERSALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CFLANDERSALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|CFLAndersAAResult
range|:
name|public
name|AAResultBase
operator|<
name|CFLAndersAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|CFLAndersAAResult
operator|>
block|;
name|class
name|FunctionInfo
block|;
name|public
operator|:
name|explicit
name|CFLAndersAAResult
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
argument_list|)
block|;
name|CFLAndersAAResult
argument_list|(
name|CFLAndersAAResult
operator|&&
argument_list|)
block|;
operator|~
name|CFLAndersAAResult
argument_list|()
block|;
comment|/// Handle invalidation events from the new pass manager.
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
comment|/// Evict the given function from cache
name|void
name|evict
argument_list|(
specifier|const
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
specifier|const
name|Function
operator|&
argument_list|)
block|;
name|AliasResult
name|query
argument_list|(
specifier|const
name|MemoryLocation
operator|&
argument_list|,
specifier|const
name|MemoryLocation
operator|&
argument_list|)
block|;
name|AliasResult
name|alias
argument_list|(
specifier|const
name|MemoryLocation
operator|&
argument_list|,
specifier|const
name|MemoryLocation
operator|&
argument_list|)
block|;
name|private
operator|:
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
specifier|const
name|Function
operator|&
argument_list|)
block|;
comment|/// \brief Inserts the given Function into the cache.
name|void
name|scan
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
block|;
comment|/// \brief Build summary for a given function
name|FunctionInfo
name|buildInfoFrom
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
block|;
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
block|;
comment|/// \brief Cached mapping of Functions to their StratifiedSets.
comment|/// If a function's sets are currently being built, it is marked
comment|/// in the cache as an Optional without a value. This way, if we
comment|/// have any kind of recursion, it is discernable from a function
comment|/// that simply has empty sets.
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
block|,
name|Optional
operator|<
name|FunctionInfo
operator|>>
name|Cache
block|;
name|std
operator|::
name|forward_list
operator|<
name|cflaa
operator|::
name|FunctionHandle
operator|<
name|CFLAndersAAResult
operator|>>
name|Handles
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
comment|///
comment|/// FIXME: We really should refactor CFL to use the analysis more heavily, and
comment|/// in particular to leverage invalidation to trigger re-computation.
name|class
name|CFLAndersAA
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|CFLAndersAA
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|CFLAndersAA
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|CFLAndersAAResult
name|Result
typedef|;
name|CFLAndersAAResult
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Legacy wrapper pass to provide the CFLAndersAAResult object.
end_comment

begin_decl_stmt
name|class
name|CFLAndersAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|CFLAndersAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|CFLAndersAAWrapperPass
argument_list|()
block|;
name|CFLAndersAAResult
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
name|CFLAndersAAResult
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
comment|// createCFLAndersAAWrapperPass - This pass implements a set-based approach to
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
name|createCFLAndersAAWrapperPass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

