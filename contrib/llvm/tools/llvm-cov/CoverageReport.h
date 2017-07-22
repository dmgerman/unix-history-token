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
file|"CoverageSummaryInfo.h"
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
specifier|const
name|coverage
operator|::
name|CoverageMapping
operator|&
name|Coverage
expr_stmt|;
name|void
name|render
argument_list|(
specifier|const
name|FileCoverageSummary
operator|&
name|File
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|render
argument_list|(
specifier|const
name|FunctionCoverageSummary
operator|&
name|Function
argument_list|,
specifier|const
name|DemangleCache
operator|&
name|DC
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|CoverageReport
argument_list|(
specifier|const
name|CoverageViewOptions
operator|&
name|Options
argument_list|,
specifier|const
name|coverage
operator|::
name|CoverageMapping
operator|&
name|Coverage
argument_list|)
operator|:
name|Options
argument_list|(
name|Options
argument_list|)
operator|,
name|Coverage
argument_list|(
argument|Coverage
argument_list|)
block|{}
name|void
name|renderFunctionReports
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|Files
argument_list|,
specifier|const
name|DemangleCache
operator|&
name|DC
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
comment|/// Prepare file reports for the files specified in \p Files.
specifier|static
name|std
operator|::
name|vector
operator|<
name|FileCoverageSummary
operator|>
name|prepareFileReports
argument_list|(
specifier|const
name|coverage
operator|::
name|CoverageMapping
operator|&
name|Coverage
argument_list|,
name|FileCoverageSummary
operator|&
name|Totals
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|Files
argument_list|)
expr_stmt|;
comment|/// Render file reports for every unique file in the coverage mapping.
name|void
name|renderFileReports
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Render file reports for the files specified in \p Files.
name|void
name|renderFileReports
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|Files
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_COV_COVERAGEREPORT_H
end_comment

end_unit

