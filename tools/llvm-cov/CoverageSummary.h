begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageSummary.h - Code coverage summary --------------------------===//
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
comment|// This class implements data management and rendering for the code coverage
end_comment

begin_comment
comment|// summaries of all files and functions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_COV_COVERAGESUMMARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_COVERAGESUMMARY_H
end_define

begin_include
include|#
directive|include
file|"CoverageSummaryInfo.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Manager for the function and file code coverage summaries.
name|class
name|CoverageSummary
block|{
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Filenames
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|FunctionCoverageSummary
operator|>
name|FunctionSummaries
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>>
name|FunctionSummariesFileIDs
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|FileCoverageSummary
operator|>
name|FileSummaries
expr_stmt|;
name|unsigned
name|getFileID
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
function_decl|;
name|public
label|:
name|void
name|createSummaries
argument_list|(
specifier|const
name|coverage
operator|::
name|CoverageMapping
operator|&
name|Coverage
argument_list|)
decl_stmt|;
name|ArrayRef
operator|<
name|FileCoverageSummary
operator|>
name|getFileSummaries
argument_list|()
block|{
return|return
name|FileSummaries
return|;
block|}
name|FileCoverageSummary
name|getCombinedFileSummaries
parameter_list|()
function_decl|;
name|void
name|render
parameter_list|(
specifier|const
name|FunctionCoverageSummary
modifier|&
name|Summary
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|render
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_COV_COVERAGESUMMARY_H
end_comment

end_unit

