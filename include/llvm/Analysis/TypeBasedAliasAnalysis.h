begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeBasedAliasAnalysis.h - Type-Based Alias Analysis -----*- C++ -*-===//
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
comment|/// This is the interface for a metadata-based TBAA. See the source file for
end_comment

begin_comment
comment|/// details on the algorithm.
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
name|LLVM_ANALYSIS_TYPEBASEDALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_TYPEBASEDALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A simple AA result that uses TBAA metadata to answer queries.
name|class
name|TypeBasedAAResult
range|:
name|public
name|AAResultBase
operator|<
name|TypeBasedAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|TypeBasedAAResult
operator|>
block|;
name|public
operator|:
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
name|AliasResult
name|alias
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
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
block|;
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
block|;
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
block|;
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS1
argument_list|,
argument|ImmutableCallSite CS2
argument_list|)
block|;
name|private
operator|:
name|bool
name|Aliases
argument_list|(
argument|const MDNode *A
argument_list|,
argument|const MDNode *B
argument_list|)
specifier|const
block|;
name|bool
name|PathAliases
argument_list|(
argument|const MDNode *A
argument_list|,
argument|const MDNode *B
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|TypeBasedAA
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|TypeBasedAA
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|TypeBasedAA
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|TypeBasedAAResult
name|Result
typedef|;
name|TypeBasedAAResult
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
comment|/// Legacy wrapper pass to provide the TypeBasedAAResult object.
end_comment

begin_decl_stmt
name|class
name|TypeBasedAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|TypeBasedAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|TypeBasedAAWrapperPass
argument_list|()
block|;
name|TypeBasedAAResult
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
name|TypeBasedAAResult
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
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
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
comment|// createTypeBasedAAWrapperPass - This pass implements metadata-based
end_comment

begin_comment
comment|// type-based alias analysis.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|ImmutablePass
modifier|*
name|createTypeBasedAAWrapperPass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

