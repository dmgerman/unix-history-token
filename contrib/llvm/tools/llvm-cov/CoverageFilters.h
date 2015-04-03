begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageFilters.h - Function coverage mapping filters --------------===//
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
comment|// These classes provide filtering for function coverage mapping records.
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
name|LLVM_COV_COVERAGEFILTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_COVERAGEFILTERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ProfileData/CoverageMapping.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
comment|/// \brief Matches specific functions that pass the requirement of this filter.
name|class
name|CoverageFilter
block|{
name|public
label|:
name|virtual
operator|~
name|CoverageFilter
argument_list|()
block|{}
comment|/// \brief Return true if the function passes the requirements of this filter.
name|virtual
name|bool
name|matches
argument_list|(
argument|const coverage::FunctionRecord&Function
argument_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Matches functions that contain a specific string in their name.
name|class
name|NameCoverageFilter
range|:
name|public
name|CoverageFilter
block|{
name|StringRef
name|Name
block|;
name|public
operator|:
name|NameCoverageFilter
argument_list|(
argument|StringRef Name
argument_list|)
operator|:
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
name|bool
name|matches
argument_list|(
argument|const coverage::FunctionRecord&Function
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// \brief Matches functions whose name matches a certain regular expression.
name|class
name|NameRegexCoverageFilter
range|:
name|public
name|CoverageFilter
block|{
name|StringRef
name|Regex
block|;
name|public
operator|:
name|NameRegexCoverageFilter
argument_list|(
argument|StringRef Regex
argument_list|)
operator|:
name|Regex
argument_list|(
argument|Regex
argument_list|)
block|{}
name|bool
name|matches
argument_list|(
argument|const coverage::FunctionRecord&Function
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// \brief Matches numbers that pass a certain threshold.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|StatisticThresholdFilter
block|{
name|public
operator|:
expr|enum
name|Operation
block|{
name|LessThan
block|,
name|GreaterThan
block|}
block|;
name|protected
operator|:
name|Operation
name|Op
block|;
name|T
name|Threshold
block|;
name|StatisticThresholdFilter
argument_list|(
argument|Operation Op
argument_list|,
argument|T Threshold
argument_list|)
operator|:
name|Op
argument_list|(
name|Op
argument_list|)
block|,
name|Threshold
argument_list|(
argument|Threshold
argument_list|)
block|{}
comment|/// \brief Return true if the given number is less than
comment|/// or greater than the certain threshold.
name|bool
name|PassesThreshold
argument_list|(
argument|T Value
argument_list|)
specifier|const
block|{
switch|switch
condition|(
name|Op
condition|)
block|{
case|case
name|LessThan
case|:
return|return
name|Value
operator|<
name|Threshold
return|;
case|case
name|GreaterThan
case|:
return|return
name|Value
operator|>
name|Threshold
return|;
block|}
return|return
name|false
return|;
block|}
block|}
expr_stmt|;
comment|/// \brief Matches functions whose region coverage percentage
comment|/// is above/below a certain percentage.
name|class
name|RegionCoverageFilter
range|:
name|public
name|CoverageFilter
decl_stmt|,
name|public
name|StatisticThresholdFilter
decl|<
name|double
decl|>
block|{
name|public
label|:
name|RegionCoverageFilter
argument_list|(
argument|Operation Op
argument_list|,
argument|double Threshold
argument_list|)
block|:
name|StatisticThresholdFilter
argument_list|(
argument|Op
argument_list|,
argument|Threshold
argument_list|)
block|{}
name|bool
name|matches
argument_list|(
specifier|const
name|coverage
operator|::
name|FunctionRecord
operator|&
name|Function
argument_list|)
name|override
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Matches functions whose line coverage percentage
comment|/// is above/below a certain percentage.
name|class
name|LineCoverageFilter
range|:
name|public
name|CoverageFilter
decl_stmt|,
name|public
name|StatisticThresholdFilter
decl|<
name|double
decl|>
block|{
name|public
label|:
name|LineCoverageFilter
argument_list|(
argument|Operation Op
argument_list|,
argument|double Threshold
argument_list|)
block|:
name|StatisticThresholdFilter
argument_list|(
argument|Op
argument_list|,
argument|Threshold
argument_list|)
block|{}
name|bool
name|matches
argument_list|(
specifier|const
name|coverage
operator|::
name|FunctionRecord
operator|&
name|Function
argument_list|)
name|override
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A collection of filters.
comment|/// Matches functions that match any filters contained
comment|/// in an instance of this class.
name|class
name|CoverageFilters
range|:
name|public
name|CoverageFilter
block|{
name|protected
operator|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|CoverageFilter
operator|>>
name|Filters
block|;
name|public
operator|:
comment|/// \brief Append a filter to this collection.
name|void
name|push_back
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|CoverageFilter
operator|>
name|Filter
argument_list|)
block|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Filters
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|matches
argument_list|(
argument|const coverage::FunctionRecord&Function
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// \brief A collection of filters.
comment|/// Matches functions that match all of the filters contained
comment|/// in an instance of this class.
name|class
name|CoverageFiltersMatchAll
range|:
name|public
name|CoverageFilters
block|{
name|public
operator|:
name|bool
name|matches
argument_list|(
argument|const coverage::FunctionRecord&Function
argument_list|)
name|override
block|; }
decl_stmt|;
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
comment|// LLVM_COV_COVERAGEFILTERS_H
end_comment

end_unit

