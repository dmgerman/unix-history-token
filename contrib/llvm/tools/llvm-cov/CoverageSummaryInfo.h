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
file|"llvm/ProfileData/Coverage/CoverageMapping.h"
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
argument_list|()
operator|:
name|Covered
argument_list|(
literal|0
argument_list|)
operator|,
name|NotCovered
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRegions
argument_list|(
literal|0
argument_list|)
block|{}
name|RegionCoverageInfo
argument_list|(
argument|size_t Covered
argument_list|,
argument|size_t NumRegions
argument_list|)
operator|:
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
name|RegionCoverageInfo
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|RegionCoverageInfo
operator|&
name|RHS
operator|)
block|{
name|Covered
operator|+=
name|RHS
operator|.
name|Covered
block|;
name|NotCovered
operator|+=
name|RHS
operator|.
name|NotCovered
block|;
name|NumRegions
operator|+=
name|RHS
operator|.
name|NumRegions
block|;
return|return
operator|*
name|this
return|;
block|}
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
if|if
condition|(
name|NumRegions
operator|==
literal|0
condition|)
return|return
literal|0.0
return|;
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Provides information about line coverage for a function/file.
end_comment

begin_struct
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
comment|/// \brief The total number of lines in a function/file.
name|size_t
name|NumLines
decl_stmt|;
name|LineCoverageInfo
argument_list|()
operator|:
name|Covered
argument_list|(
literal|0
argument_list|)
operator|,
name|NotCovered
argument_list|(
literal|0
argument_list|)
operator|,
name|NumLines
argument_list|(
literal|0
argument_list|)
block|{}
name|LineCoverageInfo
argument_list|(
argument|size_t Covered
argument_list|,
argument|size_t NumLines
argument_list|)
operator|:
name|Covered
argument_list|(
name|Covered
argument_list|)
operator|,
name|NotCovered
argument_list|(
name|NumLines
operator|-
name|Covered
argument_list|)
operator|,
name|NumLines
argument_list|(
argument|NumLines
argument_list|)
block|{}
name|LineCoverageInfo
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|LineCoverageInfo
operator|&
name|RHS
operator|)
block|{
name|Covered
operator|+=
name|RHS
operator|.
name|Covered
block|;
name|NotCovered
operator|+=
name|RHS
operator|.
name|NotCovered
block|;
name|NumLines
operator|+=
name|RHS
operator|.
name|NumLines
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|isFullyCovered
argument_list|()
specifier|const
block|{
return|return
name|Covered
operator|==
name|NumLines
return|;
block|}
name|double
name|getPercentCovered
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NumLines
operator|==
literal|0
condition|)
return|return
literal|0.0
return|;
return|return
name|double
argument_list|(
name|Covered
argument_list|)
operator|/
name|double
argument_list|(
name|NumLines
argument_list|)
operator|*
literal|100.0
return|;
block|}
end_struct

begin_comment
unit|};
comment|/// \brief Provides information about function coverage for a file.
end_comment

begin_struct
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
argument_list|()
operator|:
name|Executed
argument_list|(
literal|0
argument_list|)
operator|,
name|NumFunctions
argument_list|(
literal|0
argument_list|)
block|{}
name|FunctionCoverageInfo
argument_list|(
argument|size_t Executed
argument_list|,
argument|size_t NumFunctions
argument_list|)
operator|:
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
name|void
name|addFunction
argument_list|(
argument|bool Covered
argument_list|)
block|{
if|if
condition|(
name|Covered
condition|)
operator|++
name|Executed
expr_stmt|;
operator|++
name|NumFunctions
expr_stmt|;
block|}
name|bool
name|isFullyCovered
argument_list|()
decl|const
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
decl|const
block|{
if|if
condition|(
name|NumFunctions
operator|==
literal|0
condition|)
return|return
literal|0.0
return|;
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
end_struct

begin_comment
unit|};
comment|/// \brief A summary of function's code coverage.
end_comment

begin_struct
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
argument_list|)
block|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|ExecutionCount
argument_list|(
literal|0
argument_list|)
block|{}
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
operator|:
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
comment|/// \brief Update the summary with information from another instantiation
comment|/// of this function.
name|void
name|update
parameter_list|(
specifier|const
name|FunctionCoverageSummary
modifier|&
name|Summary
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief A summary of file's code coverage.
end_comment

begin_struct
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
name|FunctionCoverageInfo
name|InstantiationCoverage
decl_stmt|;
name|FileCoverageSummary
argument_list|(
argument|StringRef Name
argument_list|)
block|:
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
name|void
name|addFunction
parameter_list|(
specifier|const
name|FunctionCoverageSummary
modifier|&
name|Function
parameter_list|)
block|{
name|RegionCoverage
operator|+=
name|Function
operator|.
name|RegionCoverage
expr_stmt|;
name|LineCoverage
operator|+=
name|Function
operator|.
name|LineCoverage
expr_stmt|;
name|FunctionCoverage
operator|.
name|addFunction
argument_list|(
comment|/*Covered=*/
name|Function
operator|.
name|ExecutionCount
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
name|void
name|addInstantiation
parameter_list|(
specifier|const
name|FunctionCoverageSummary
modifier|&
name|Function
parameter_list|)
block|{
name|InstantiationCoverage
operator|.
name|addFunction
argument_list|(
comment|/*Covered=*/
name|Function
operator|.
name|ExecutionCount
operator|>
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// \brief A cache for demangled symbols.
end_comment

begin_struct
struct|struct
name|DemangleCache
block|{
name|StringMap
operator|<
name|std
operator|::
name|string
operator|>
name|DemangledNames
expr_stmt|;
comment|/// \brief Demangle \p Sym if possible. Otherwise, just return \p Sym.
name|StringRef
name|demangle
argument_list|(
name|StringRef
name|Sym
argument_list|)
decl|const
block|{
specifier|const
specifier|auto
name|DemangledName
init|=
name|DemangledNames
operator|.
name|find
argument_list|(
name|Sym
argument_list|)
decl_stmt|;
if|if
condition|(
name|DemangledName
operator|==
name|DemangledNames
operator|.
name|end
argument_list|()
condition|)
return|return
name|Sym
return|;
return|return
name|DemangledName
operator|->
name|getValue
argument_list|()
return|;
block|}
block|}
struct|;
end_struct

begin_comment
unit|}
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

