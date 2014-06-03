begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- AnalysisBasedWarnings.h - Sema warnings based on libAnalysis -*- C++ -*-=//
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
comment|// This file defines AnalysisBasedWarnings, a worker object used by Sema
end_comment

begin_comment
comment|// that issues warnings based on dataflow-analysis.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_ANALYSIS_WARNINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_ANALYSIS_WARNINGS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|BlockExpr
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|namespace
name|sema
block|{
name|class
name|FunctionScopeInfo
decl_stmt|;
block|}
name|namespace
name|sema
block|{
name|class
name|AnalysisBasedWarnings
block|{
name|public
label|:
name|class
name|Policy
block|{
name|friend
name|class
name|AnalysisBasedWarnings
decl_stmt|;
comment|// The warnings to run.
name|unsigned
name|enableCheckFallThrough
range|:
literal|1
decl_stmt|;
name|unsigned
name|enableCheckUnreachable
range|:
literal|1
decl_stmt|;
name|unsigned
name|enableThreadSafetyAnalysis
range|:
literal|1
decl_stmt|;
name|unsigned
name|enableConsumedAnalysis
range|:
literal|1
decl_stmt|;
name|public
label|:
name|Policy
argument_list|()
expr_stmt|;
name|void
name|disableCheckFallThrough
parameter_list|()
block|{
name|enableCheckFallThrough
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
name|private
label|:
name|Sema
modifier|&
name|S
decl_stmt|;
name|Policy
name|DefaultPolicy
decl_stmt|;
enum|enum
name|VisitFlag
block|{
name|NotVisited
init|=
literal|0
block|,
name|Visited
init|=
literal|1
block|,
name|Pending
init|=
literal|2
block|}
enum|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FunctionDecl
operator|*
operator|,
name|VisitFlag
operator|>
name|VisitedFD
expr_stmt|;
comment|/// \name Statistics
comment|/// @{
comment|/// \brief Number of function CFGs built and analyzed.
name|unsigned
name|NumFunctionsAnalyzed
decl_stmt|;
comment|/// \brief Number of functions for which the CFG could not be successfully
comment|/// built.
name|unsigned
name|NumFunctionsWithBadCFGs
decl_stmt|;
comment|/// \brief Total number of blocks across all CFGs.
name|unsigned
name|NumCFGBlocks
decl_stmt|;
comment|/// \brief Largest number of CFG blocks for a single function analyzed.
name|unsigned
name|MaxCFGBlocksPerFunction
decl_stmt|;
comment|/// \brief Total number of CFGs with variables analyzed for uninitialized
comment|/// uses.
name|unsigned
name|NumUninitAnalysisFunctions
decl_stmt|;
comment|/// \brief Total number of variables analyzed for uninitialized uses.
name|unsigned
name|NumUninitAnalysisVariables
decl_stmt|;
comment|/// \brief Max number of variables analyzed for uninitialized uses in a single
comment|/// function.
name|unsigned
name|MaxUninitAnalysisVariablesPerFunction
decl_stmt|;
comment|/// \brief Total number of block visits during uninitialized use analysis.
name|unsigned
name|NumUninitAnalysisBlockVisits
decl_stmt|;
comment|/// \brief Max number of block visits during uninitialized use analysis of
comment|/// a single function.
name|unsigned
name|MaxUninitAnalysisBlockVisitsPerFunction
decl_stmt|;
comment|/// @}
name|public
label|:
name|AnalysisBasedWarnings
argument_list|(
name|Sema
operator|&
name|s
argument_list|)
expr_stmt|;
name|void
name|IssueWarnings
parameter_list|(
name|Policy
name|P
parameter_list|,
name|FunctionScopeInfo
modifier|*
name|fscope
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
specifier|const
name|BlockExpr
modifier|*
name|blkExpr
parameter_list|)
function_decl|;
name|Policy
name|getDefaultPolicy
parameter_list|()
block|{
return|return
name|DefaultPolicy
return|;
block|}
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::sema
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

