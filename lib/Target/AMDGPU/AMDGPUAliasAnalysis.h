begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPUAliasAnalysis ---------------------------------------*- C++ -*-==//
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
comment|/// This is the AMGPU address space based alias analysis pass.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_AMDGPUALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_AMDGPUALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

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
comment|/// A simple AA result that uses TBAA metadata to answer queries.
name|class
name|AMDGPUAAResult
range|:
name|public
name|AAResultBase
operator|<
name|AMDGPUAAResult
operator|>
block|{
name|friend
name|AAResultBase
operator|<
name|AMDGPUAAResult
operator|>
block|;
specifier|const
name|DataLayout
operator|&
name|DL
block|;
name|AMDGPUAS
name|AS
block|;
name|public
operator|:
name|explicit
name|AMDGPUAAResult
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|Triple T
argument_list|)
operator|:
name|AAResultBase
argument_list|()
block|,
name|DL
argument_list|(
name|DL
argument_list|)
block|,
name|AS
argument_list|(
name|AMDGPU
operator|::
name|getAMDGPUAS
argument_list|(
name|T
argument_list|)
argument_list|)
block|,
name|ASAliasRules
argument_list|(
argument|AS
argument_list|,
argument|T.getArch()
argument_list|)
block|{}
name|AMDGPUAAResult
argument_list|(
name|AMDGPUAAResult
operator|&&
name|Arg
argument_list|)
operator|:
name|AAResultBase
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
argument_list|)
argument_list|)
block|,
name|DL
argument_list|(
name|Arg
operator|.
name|DL
argument_list|)
block|,
name|AS
argument_list|(
name|Arg
operator|.
name|AS
argument_list|)
block|,
name|ASAliasRules
argument_list|(
argument|Arg.ASAliasRules
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
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
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
block|;
name|class
name|ASAliasRulesTy
block|{
name|public
operator|:
name|ASAliasRulesTy
argument_list|(
argument|AMDGPUAS AS_
argument_list|,
argument|Triple::ArchType Arch_
argument_list|)
block|;
name|AliasResult
name|getAliasResult
argument_list|(
argument|unsigned AS1
argument_list|,
argument|unsigned AS2
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Triple
operator|::
name|ArchType
name|Arch
block|;
name|AMDGPUAS
name|AS
block|;
specifier|const
name|AliasResult
argument_list|(
operator|*
name|ASAliasRules
argument_list|)
index|[
literal|6
index|]
index|[
literal|6
index|]
block|;   }
name|ASAliasRules
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|AMDGPUAA
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|AMDGPUAA
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|AMDGPUAA
operator|>
block|;
specifier|static
name|char
name|PassID
block|;
name|public
operator|:
typedef|typedef
name|AMDGPUAAResult
name|Result
typedef|;
name|AMDGPUAAResult
name|run
argument_list|(
argument|Function&F
argument_list|,
argument|AnalysisManager<Function>&AM
argument_list|)
block|{
return|return
name|AMDGPUAAResult
argument_list|(
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getDataLayout
argument_list|()
argument_list|,
name|Triple
argument_list|(
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getTargetTriple
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Legacy wrapper pass to provide the AMDGPUAAResult object.
name|class
name|AMDGPUAAWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|AMDGPUAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|AMDGPUAAWrapperPass
argument_list|()
operator|:
name|ImmutablePass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeAMDGPUAAWrapperPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|AMDGPUAAResult
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
name|AMDGPUAAResult
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
block|{
name|Result
operator|.
name|reset
argument_list|(
argument|new AMDGPUAAResult(M.getDataLayout(),         Triple(M.getTargetTriple()))
argument_list|)
block|;
return|return
name|false
return|;
block|}
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|{
name|Result
operator|.
name|reset
argument_list|()
block|;
return|return
name|false
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_AMDGPUALIASANALYSIS_H
end_comment

end_unit

