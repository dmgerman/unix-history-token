begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScalarEvolutionAliasAnalysis.h - SCEV-based AA -----------*- C++ -*-===//
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
comment|/// This is the interface for a SCEV-based alias analysis.
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
name|LLVM_ANALYSIS_SCALAREVOLUTIONALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCALAREVOLUTIONALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionExpressions.h"
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
comment|/// A simple alias analysis implementation that uses ScalarEvolution to answer
comment|/// queries.
name|class
name|SCEVAAResult
range|:
name|public
name|AAResultBase
operator|<
name|SCEVAAResult
operator|>
block|{
name|ScalarEvolution
operator|&
name|SE
block|;
name|public
operator|:
name|explicit
name|SCEVAAResult
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|)
operator|:
name|AAResultBase
argument_list|(
name|TLI
argument_list|)
block|,
name|SE
argument_list|(
argument|SE
argument_list|)
block|{}
name|SCEVAAResult
argument_list|(
name|SCEVAAResult
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
name|SE
argument_list|(
argument|Arg.SE
argument_list|)
block|{}
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
name|private
operator|:
name|Value
operator|*
name|GetBaseValue
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|; }
decl_stmt|;
comment|/// Analysis pass providing a never-invalidated alias analysis result.
name|class
name|SCEVAA
block|{
name|public
label|:
typedef|typedef
name|SCEVAAResult
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
name|SCEVAAResult
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
literal|"SCEVAA"
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
comment|/// Legacy wrapper pass to provide the SCEVAAResult object.
name|class
name|SCEVAAWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|SCEVAAResult
operator|>
name|Result
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|SCEVAAWrapperPass
argument_list|()
block|;
name|SCEVAAResult
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
name|SCEVAAResult
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
name|runOnFunction
argument_list|(
argument|Function&F
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
comment|/// Creates an instance of \c SCEVAAWrapperPass.
name|FunctionPass
modifier|*
name|createSCEVAAWrapperPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

