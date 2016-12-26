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
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlockFrequencyInfo
decl_stmt|;
comment|/// Class to build a module summary index for the given Module, possibly from
comment|/// a Pass.
name|class
name|ModuleSummaryIndexBuilder
block|{
comment|/// The index being built
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>
name|Index
expr_stmt|;
comment|/// The module for which we are building an index
specifier|const
name|Module
modifier|*
name|M
decl_stmt|;
name|public
label|:
comment|/// Default constructor
name|ModuleSummaryIndexBuilder
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Constructor that builds an index for the given Module. An optional
comment|/// callback can be supplied to obtain the frequency info for a function.
name|ModuleSummaryIndexBuilder
argument_list|(
specifier|const
name|Module
operator|*
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
name|Ftor
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// Get a reference to the index owned by builder
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
comment|/// Take ownership of the built index
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>
name|takeIndex
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Index
argument_list|)
return|;
block|}
name|private
label|:
comment|/// Compute summary for given function with optional frequency information
name|void
name|computeFunctionSummary
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|BlockFrequencyInfo
modifier|*
name|BFI
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Compute summary for given variable with optional frequency information
name|void
name|computeVariableSummary
parameter_list|(
specifier|const
name|GlobalVariable
modifier|&
name|V
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Legacy wrapper pass to provide the ModuleSummaryIndex object.
name|class
name|ModuleSummaryIndexWrapperPass
range|:
name|public
name|ModulePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndexBuilder
operator|>
name|IndexBuilder
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
name|IndexBuilder
operator|->
name|getIndex
argument_list|()
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
name|IndexBuilder
operator|->
name|getIndex
argument_list|()
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
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createModuleSummaryIndexWrapperPass - This pass builds a ModuleSummaryIndex
comment|// object for the module, to be written to bitcode or LLVM assembly.
comment|//
name|ModulePass
modifier|*
name|createModuleSummaryIndexWrapperPass
parameter_list|()
function_decl|;
comment|/// Returns true if \p M is eligible for ThinLTO promotion.
comment|///
comment|/// Currently we check if it has any any InlineASM that uses an internal symbol.
name|bool
name|moduleCanBeRenamedForThinLTO
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

