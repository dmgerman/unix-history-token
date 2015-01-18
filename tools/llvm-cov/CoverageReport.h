begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageReport.h - Code coverage report ---------------------------===//
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
comment|// This class implements rendering of a code coverage report.
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
name|LLVM_COV_COVERAGEREPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_COVERAGEREPORT_H
end_define

begin_include
include|#
directive|include
file|"CoverageSummary.h"
end_include

begin_include
include|#
directive|include
file|"CoverageViewOptions.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Displays the code coverage report.
name|class
name|CoverageReport
block|{
specifier|const
name|CoverageViewOptions
modifier|&
name|Options
decl_stmt|;
name|CoverageSummary
modifier|&
name|Summary
decl_stmt|;
name|void
name|render
parameter_list|(
specifier|const
name|FileCoverageSummary
modifier|&
name|File
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|render
parameter_list|(
specifier|const
name|FunctionCoverageSummary
modifier|&
name|Function
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|public
label|:
name|CoverageReport
argument_list|(
specifier|const
name|CoverageViewOptions
operator|&
name|Options
argument_list|,
name|CoverageSummary
operator|&
name|Summary
argument_list|)
operator|:
name|Options
argument_list|(
name|Options
argument_list|)
operator|,
name|Summary
argument_list|(
argument|Summary
argument_list|)
block|{}
name|void
name|renderFunctionReports
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
name|void
name|renderFileReports
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
comment|// LLVM_COV_COVERAGEREPORT_H
end_comment

end_unit

