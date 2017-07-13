begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProfileCommon.h - Common profiling APIs. -----------------*- C++ -*-===//
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
comment|// This file contains data structures and functions common to both instrumented
end_comment

begin_comment
comment|// and sample profiling.
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
name|LLVM_PROFILEDATA_PROFILECOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_PROFILECOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ProfileSummary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ProfileData/InstrProf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
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
name|namespace
name|sampleprof
block|{
name|class
name|FunctionSamples
decl_stmt|;
block|}
comment|// end namespace sampleprof
specifier|inline
specifier|const
name|char
modifier|*
name|getHotSectionPrefix
parameter_list|()
block|{
return|return
literal|".hot"
return|;
block|}
specifier|inline
specifier|const
name|char
modifier|*
name|getUnlikelySectionPrefix
parameter_list|()
block|{
return|return
literal|".unlikely"
return|;
block|}
name|class
name|ProfileSummaryBuilder
block|{
name|private
label|:
comment|/// We keep track of the number of times a count (block count or samples)
comment|/// appears in the profile. The map is kept sorted in the descending order of
comment|/// counts.
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|uint32_t
operator|,
name|std
operator|::
name|greater
operator|<
name|uint64_t
operator|>>
name|CountFrequencies
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|DetailedSummaryCutoffs
expr_stmt|;
name|protected
label|:
name|SummaryEntryVector
name|DetailedSummary
decl_stmt|;
name|uint64_t
name|TotalCount
init|=
literal|0
decl_stmt|;
name|uint64_t
name|MaxCount
init|=
literal|0
decl_stmt|;
name|uint64_t
name|MaxFunctionCount
init|=
literal|0
decl_stmt|;
name|uint32_t
name|NumCounts
init|=
literal|0
decl_stmt|;
name|uint32_t
name|NumFunctions
init|=
literal|0
decl_stmt|;
name|ProfileSummaryBuilder
argument_list|(
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Cutoffs
argument_list|)
operator|:
name|DetailedSummaryCutoffs
argument_list|(
argument|std::move(Cutoffs)
argument_list|)
block|{}
operator|~
name|ProfileSummaryBuilder
argument_list|()
operator|=
expr|default
expr_stmt|;
specifier|inline
name|void
name|addCount
parameter_list|(
name|uint64_t
name|Count
parameter_list|)
function_decl|;
name|void
name|computeDetailedSummary
parameter_list|()
function_decl|;
name|public
label|:
comment|/// \brief A vector of useful cutoff values for detailed summary.
specifier|static
specifier|const
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|DefaultCutoffs
expr_stmt|;
block|}
empty_stmt|;
name|class
name|InstrProfSummaryBuilder
name|final
range|:
name|public
name|ProfileSummaryBuilder
block|{
name|uint64_t
name|MaxInternalBlockCount
operator|=
literal|0
block|;
specifier|inline
name|void
name|addEntryCount
argument_list|(
argument|uint64_t Count
argument_list|)
block|;
specifier|inline
name|void
name|addInternalCount
argument_list|(
argument|uint64_t Count
argument_list|)
block|;
name|public
operator|:
name|InstrProfSummaryBuilder
argument_list|(
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Cutoffs
argument_list|)
operator|:
name|ProfileSummaryBuilder
argument_list|(
argument|std::move(Cutoffs)
argument_list|)
block|{}
name|void
name|addRecord
argument_list|(
specifier|const
name|InstrProfRecord
operator|&
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummary
operator|>
name|getSummary
argument_list|()
block|; }
decl_stmt|;
name|class
name|SampleProfileSummaryBuilder
name|final
range|:
name|public
name|ProfileSummaryBuilder
block|{
name|public
operator|:
name|SampleProfileSummaryBuilder
argument_list|(
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Cutoffs
argument_list|)
operator|:
name|ProfileSummaryBuilder
argument_list|(
argument|std::move(Cutoffs)
argument_list|)
block|{}
name|void
name|addRecord
argument_list|(
specifier|const
name|sampleprof
operator|::
name|FunctionSamples
operator|&
name|FS
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummary
operator|>
name|getSummary
argument_list|()
block|; }
decl_stmt|;
comment|/// This is called when a count is seen in the profile.
name|void
name|ProfileSummaryBuilder
operator|::
name|addCount
argument_list|(
argument|uint64_t Count
argument_list|)
block|{
name|TotalCount
operator|+=
name|Count
block|;
if|if
condition|(
name|Count
operator|>
name|MaxCount
condition|)
name|MaxCount
operator|=
name|Count
expr_stmt|;
name|NumCounts
operator|++
expr_stmt|;
name|CountFrequencies
index|[
name|Count
index|]
operator|++
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_PROFILEDATA_PROFILECOMMON_H
end_comment

end_unit

