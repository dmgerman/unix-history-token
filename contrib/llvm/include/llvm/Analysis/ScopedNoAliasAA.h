begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScopedNoAliasAA.h - Scoped No-Alias Alias Analysis -------*- C++ -*-===//
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
comment|/// This is the interface for a metadata-based scoped no-alias analysis.
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
name|LLVM_ANALYSIS_SCOPEDNOALIASAA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCOPEDNOALIASAA_H
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
file|"llvm/IR/Module.h"
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
comment|/// A simple AA result which uses scoped-noalias metadata to answer queries.
name|class
name|ScopedNoAliasAAResult
range|:
name|public
name|AAResultBase
operator|<
name|ScopedNoAliasAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|ScopedNoAliasAAResult
operator|>
block|;
name|public
operator|:
name|explicit
name|ScopedNoAliasAAResult
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|)
operator|:
name|AAResultBase
argument_list|(
argument|TLI
argument_list|)
block|{}
name|ScopedNoAliasAAResult
argument_list|(
name|ScopedNoAliasAAResult
operator|&&
name|Arg
argument_list|)
operator|:
name|AAResultBase
argument_list|(
argument|std::move(Arg)
argument_list|)
block|{}
comment|/// Handle invalidation events from the new pass manager.
comment|///
comment|/// By definition, this result is stateless and so remains valid.
name|bool
name|invalidate
argument_list|(
argument|Function&
argument_list|,
argument|const PreservedAnalyses&
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
name|mayAliasInScopes
argument_list|(
argument|const MDNode *Scopes
argument_list|,
argument|const MDNode *NoAlias
argument_list|)
specifier|const
block|;
name|void
name|collectMDInDomain
argument_list|(
argument|const MDNode *List
argument_list|,
argument|const MDNode *Domain
argument_list|,
argument|SmallPtrSetImpl<const MDNode *>&Nodes
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|ScopedNoAliasAA
block|{
name|public
label|:
typedef|typedef
name|ScopedNoAliasAAResult
name|Result
typedef|;
comment|/// \brief Opaque, unique identifier for this analysis pass.
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|ScopedNoAliasAAResult
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
operator|>
operator|*
name|AM
argument_list|)
decl_stmt|;
comment|/// \brief Provide access to a name for this pass for debugging purposes.
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"ScopedNoAliasAA"
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
block|}
empty_stmt|;
comment|/// Legacy wrapper pass to provide the ScopedNoAliasAAResult object.
name|class
name|ScopedNoAliasAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ScopedNoAliasAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ScopedNoAliasAAWrapperPass
argument_list|()
block|;
name|ScopedNoAliasAAResult
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
name|ScopedNoAliasAAResult
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
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createScopedNoAliasAAWrapperPass - This pass implements metadata-based
comment|// scoped noalias analysis.
comment|//
name|ImmutablePass
modifier|*
name|createScopedNoAliasAAWrapperPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

