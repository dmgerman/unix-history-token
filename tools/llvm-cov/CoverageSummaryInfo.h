begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageSummaryInfo.h - Coverage summary for function/file ---------===//
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
comment|// These structures are used to represent code coverage metrics
end_comment

begin_comment
comment|// for functions/files.
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
name|LLVM_COV_COVERAGESUMMARYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_COVERAGESUMMARYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ProfileData/CoverageMapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Provides information about region coverage for a function/file.
struct|struct
name|RegionCoverageInfo
block|{
comment|/// \brief The number of regions that were executed at least once.
name|size_t
name|Covered
decl_stmt|;
comment|/// \brief The number of regions that weren't executed.
name|size_t
name|NotCovered
decl_stmt|;
comment|/// \brief The total number of regions in a function/file.
name|size_t
name|NumRegions
decl_stmt|;
name|RegionCoverageInfo
argument_list|(
argument|size_t Covered
argument_list|,
argument|size_t NumRegions
argument_list|)
block|:
name|Covered
argument_list|(
name|Covered
argument_list|)
operator|,
name|NotCovered
argument_list|(
name|NumRegions
operator|-
name|Covered
argument_list|)
operator|,
name|NumRegions
argument_list|(
argument|NumRegions
argument_list|)
block|{}
name|bool
name|isFullyCovered
argument_list|()
specifier|const
block|{
return|return
name|Covered
operator|==
name|NumRegions
return|;
block|}
name|double
name|getPercentCovered
argument_list|()
specifier|const
block|{
return|return
name|double
argument_list|(
name|Covered
argument_list|)
operator|/
name|double
argument_list|(
name|NumRegions
argument_list|)
operator|*
literal|100.0
return|;
block|}
block|}
struct|;
comment|/// \brief Provides information about line coverage for a function/file.
struct|struct
name|LineCoverageInfo
block|{
comment|/// \brief The number of lines that were executed at least once.
name|size_t
name|Covered
decl_stmt|;
comment|/// \brief The number of lines that weren't executed.
name|size_t
name|NotCovered
decl_stmt|;
comment|/// \brief The number of lines that aren't code.
name|size_t
name|NonCodeLines
decl_stmt|;
comment|/// \brief The total number of lines in a function/file.
name|size_t
name|NumLines
decl_stmt|;
name|LineCoverageInfo
argument_list|(
argument|size_t Covered
argument_list|,
argument|size_t NumNonCodeLines
argument_list|,
argument|size_t NumLines
argument_list|)
block|:
name|Covered
argument_list|(
name|Covered
argument_list|)
operator|,
name|NotCovered
argument_list|(
name|NumLines
operator|-
name|NumNonCodeLines
operator|-
name|Covered
argument_list|)
operator|,
name|NonCodeLines
argument_list|(
name|NumNonCodeLines
argument_list|)
operator|,
name|NumLines
argument_list|(
argument|NumLines
argument_list|)
block|{}
name|bool
name|isFullyCovered
argument_list|()
specifier|const
block|{
return|return
name|Covered
operator|==
operator|(
name|NumLines
operator|-
name|NonCodeLines
operator|)
return|;
block|}
name|double
name|getPercentCovered
argument_list|()
specifier|const
block|{
return|return
name|double
argument_list|(
name|Covered
argument_list|)
operator|/
name|double
argument_list|(
name|NumLines
operator|-
name|NonCodeLines
argument_list|)
operator|*
literal|100.0
return|;
block|}
block|}
struct|;
comment|/// \brief Provides information about function coverage for a file.
struct|struct
name|FunctionCoverageInfo
block|{
comment|/// \brief The number of functions that were executed.
name|size_t
name|Executed
decl_stmt|;
comment|/// \brief The total number of functions in this file.
name|size_t
name|NumFunctions
decl_stmt|;
name|FunctionCoverageInfo
argument_list|(
argument|size_t Executed
argument_list|,
argument|size_t NumFunctions
argument_list|)
block|:
name|Executed
argument_list|(
name|Executed
argument_list|)
operator|,
name|NumFunctions
argument_list|(
argument|NumFunctions
argument_list|)
block|{}
name|bool
name|isFullyCovered
argument_list|()
specifier|const
block|{
return|return
name|Executed
operator|==
name|NumFunctions
return|;
block|}
name|double
name|getPercentCovered
argument_list|()
specifier|const
block|{
return|return
name|double
argument_list|(
name|Executed
argument_list|)
operator|/
name|double
argument_list|(
name|NumFunctions
argument_list|)
operator|*
literal|100.0
return|;
block|}
block|}
struct|;
comment|/// \brief A summary of function's code coverage.
struct|struct
name|FunctionCoverageSummary
block|{
name|StringRef
name|Name
decl_stmt|;
name|uint64_t
name|ExecutionCount
decl_stmt|;
name|RegionCoverageInfo
name|RegionCoverage
decl_stmt|;
name|LineCoverageInfo
name|LineCoverage
decl_stmt|;
name|FunctionCoverageSummary
argument_list|(
argument|StringRef Name
argument_list|,
argument|uint64_t ExecutionCount
argument_list|,
argument|const RegionCoverageInfo&RegionCoverage
argument_list|,
argument|const LineCoverageInfo&LineCoverage
argument_list|)
block|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|ExecutionCount
argument_list|(
name|ExecutionCount
argument_list|)
operator|,
name|RegionCoverage
argument_list|(
name|RegionCoverage
argument_list|)
operator|,
name|LineCoverage
argument_list|(
argument|LineCoverage
argument_list|)
block|{   }
comment|/// \brief Compute the code coverage summary for the given function coverage
comment|/// mapping record.
specifier|static
name|FunctionCoverageSummary
name|get
argument_list|(
specifier|const
name|coverage
operator|::
name|FunctionRecord
operator|&
name|Function
argument_list|)
expr_stmt|;
block|}
struct|;
comment|/// \brief A summary of file's code coverage.
struct|struct
name|FileCoverageSummary
block|{
name|StringRef
name|Name
decl_stmt|;
name|RegionCoverageInfo
name|RegionCoverage
decl_stmt|;
name|LineCoverageInfo
name|LineCoverage
decl_stmt|;
name|FunctionCoverageInfo
name|FunctionCoverage
decl_stmt|;
comment|/// \brief The summary of every function
comment|/// in this file.
name|ArrayRef
operator|<
name|FunctionCoverageSummary
operator|>
name|FunctionSummaries
expr_stmt|;
name|FileCoverageSummary
argument_list|(
argument|StringRef Name
argument_list|,
argument|const RegionCoverageInfo&RegionCoverage
argument_list|,
argument|const LineCoverageInfo&LineCoverage
argument_list|,
argument|const FunctionCoverageInfo&FunctionCoverage
argument_list|,
argument|ArrayRef<FunctionCoverageSummary> FunctionSummaries
argument_list|)
block|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|RegionCoverage
argument_list|(
name|RegionCoverage
argument_list|)
operator|,
name|LineCoverage
argument_list|(
name|LineCoverage
argument_list|)
operator|,
name|FunctionCoverage
argument_list|(
name|FunctionCoverage
argument_list|)
operator|,
name|FunctionSummaries
argument_list|(
argument|FunctionSummaries
argument_list|)
block|{}
comment|/// \brief Compute the code coverage summary for a file.
specifier|static
name|FileCoverageSummary
name|get
argument_list|(
argument|StringRef Name
argument_list|,
argument|ArrayRef<FunctionCoverageSummary> FunctionSummaries
argument_list|)
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_COV_COVERAGESUMMARYINFO_H
end_comment

end_unit

