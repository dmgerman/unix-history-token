begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleSummaryAnalysis.h - Module summary index builder ---*- C++ -*-===//
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
comment|/// This is the interface to build a ModuleSummaryIndex for a module.
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
name|LLVM_ANALYSIS_MODULESUMMARYANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MODULESUMMARYANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
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
name|class
name|BlockFrequencyInfo
decl_stmt|;
name|class
name|ProfileSummaryInfo
decl_stmt|;
comment|/// Direct function to compute a \c ModuleSummaryIndex from a given module.
comment|///
comment|/// If operating within a pass manager which has defined ways to compute the \c
comment|/// BlockFrequencyInfo for a given function, that can be provided via
comment|/// a std::function callback. Otherwise, this routine will manually construct
comment|/// that information.
name|ModuleSummaryIndex
name|buildModuleSummaryIndex
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
name|std
operator|::
name|function
operator|<
name|BlockFrequencyInfo
operator|*
operator|(
specifier|const
name|Function
operator|&
name|F
operator|)
operator|>
name|GetBFICallback
argument_list|,
name|ProfileSummaryInfo
operator|*
name|PSI
argument_list|)
decl_stmt|;
comment|/// Analysis pass to provide the ModuleSummaryIndex object.
name|class
name|ModuleSummaryIndexAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|ModuleSummaryIndexAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|ModuleSummaryIndexAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|ModuleSummaryIndex
name|Result
typedef|;
name|Result
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
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
comment|/// Legacy wrapper pass to provide the ModuleSummaryIndex object.
end_comment

begin_decl_stmt
name|class
name|ModuleSummaryIndexWrapperPass
range|:
name|public
name|ModulePass
block|{
name|Optional
operator|<
name|ModuleSummaryIndex
operator|>
name|Index
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ModuleSummaryIndexWrapperPass
argument_list|()
block|;
comment|/// Get the index built by pass
name|ModuleSummaryIndex
operator|&
name|getIndex
argument_list|()
block|{
return|return
operator|*
name|Index
return|;
block|}
specifier|const
name|ModuleSummaryIndex
operator|&
name|getIndex
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Index
return|;
block|}
name|bool
name|runOnModule
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
comment|// createModuleSummaryIndexWrapperPass - This pass builds a ModuleSummaryIndex
end_comment

begin_comment
comment|// object for the module, to be written to bitcode or LLVM assembly.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|ModulePass
modifier|*
name|createModuleSummaryIndexWrapperPass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

