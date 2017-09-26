begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProfileSummary.h - Profile summary data structure. -------*- C++ -*-===//
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
comment|// This file defines the profile summary data structure.
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
name|LLVM_IR_PROFILESUMMARY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_PROFILESUMMARY_H
end_define

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
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Metadata
decl_stmt|;
comment|// The profile summary is one or more (Cutoff, MinCount, NumCounts) triplets.
comment|// The semantics of counts depend on the type of profile. For instrumentation
comment|// profile, counts are block counts and for sample profile, counts are
comment|// per-line samples. Given a target counts percentile, we compute the minimum
comment|// number of counts needed to reach this target and the minimum among these
comment|// counts.
struct|struct
name|ProfileSummaryEntry
block|{
name|uint32_t
name|Cutoff
decl_stmt|;
comment|///< The required percentile of counts.
name|uint64_t
name|MinCount
decl_stmt|;
comment|///< The minimum count for this percentile.
name|uint64_t
name|NumCounts
decl_stmt|;
comment|///< Number of counts>= the minimum count.
name|ProfileSummaryEntry
argument_list|(
argument|uint32_t TheCutoff
argument_list|,
argument|uint64_t TheMinCount
argument_list|,
argument|uint64_t TheNumCounts
argument_list|)
block|:
name|Cutoff
argument_list|(
name|TheCutoff
argument_list|)
operator|,
name|MinCount
argument_list|(
name|TheMinCount
argument_list|)
operator|,
name|NumCounts
argument_list|(
argument|TheNumCounts
argument_list|)
block|{}
block|}
struct|;
name|using
name|SummaryEntryVector
init|=
name|std
operator|::
name|vector
operator|<
name|ProfileSummaryEntry
operator|>
decl_stmt|;
name|class
name|ProfileSummary
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|PSK_Instr
block|,
name|PSK_Sample
block|}
enum|;
name|private
label|:
specifier|const
name|Kind
name|PSK
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|KindStr
index|[
literal|2
index|]
decl_stmt|;
name|SummaryEntryVector
name|DetailedSummary
decl_stmt|;
name|uint64_t
name|TotalCount
decl_stmt|,
name|MaxCount
decl_stmt|,
name|MaxInternalCount
decl_stmt|,
name|MaxFunctionCount
decl_stmt|;
name|uint32_t
name|NumCounts
decl_stmt|,
name|NumFunctions
decl_stmt|;
comment|/// \brief Return detailed summary as metadata.
name|Metadata
modifier|*
name|getDetailedSummaryMD
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
name|public
label|:
specifier|static
specifier|const
name|int
name|Scale
init|=
literal|1000000
decl_stmt|;
name|ProfileSummary
argument_list|(
argument|Kind K
argument_list|,
argument|SummaryEntryVector DetailedSummary
argument_list|,
argument|uint64_t TotalCount
argument_list|,
argument|uint64_t MaxCount
argument_list|,
argument|uint64_t MaxInternalCount
argument_list|,
argument|uint64_t MaxFunctionCount
argument_list|,
argument|uint32_t NumCounts
argument_list|,
argument|uint32_t NumFunctions
argument_list|)
block|:
name|PSK
argument_list|(
name|K
argument_list|)
operator|,
name|DetailedSummary
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|DetailedSummary
argument_list|)
argument_list|)
operator|,
name|TotalCount
argument_list|(
name|TotalCount
argument_list|)
operator|,
name|MaxCount
argument_list|(
name|MaxCount
argument_list|)
operator|,
name|MaxInternalCount
argument_list|(
name|MaxInternalCount
argument_list|)
operator|,
name|MaxFunctionCount
argument_list|(
name|MaxFunctionCount
argument_list|)
operator|,
name|NumCounts
argument_list|(
name|NumCounts
argument_list|)
operator|,
name|NumFunctions
argument_list|(
argument|NumFunctions
argument_list|)
block|{}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|PSK
return|;
block|}
comment|/// \brief Return summary information as metadata.
name|Metadata
modifier|*
name|getMD
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// \brief Construct profile summary from metdata.
specifier|static
name|ProfileSummary
modifier|*
name|getFromMD
parameter_list|(
name|Metadata
modifier|*
name|MD
parameter_list|)
function_decl|;
name|SummaryEntryVector
modifier|&
name|getDetailedSummary
parameter_list|()
block|{
return|return
name|DetailedSummary
return|;
block|}
name|uint32_t
name|getNumFunctions
parameter_list|()
block|{
return|return
name|NumFunctions
return|;
block|}
name|uint64_t
name|getMaxFunctionCount
parameter_list|()
block|{
return|return
name|MaxFunctionCount
return|;
block|}
name|uint32_t
name|getNumCounts
parameter_list|()
block|{
return|return
name|NumCounts
return|;
block|}
name|uint64_t
name|getTotalCount
parameter_list|()
block|{
return|return
name|TotalCount
return|;
block|}
name|uint64_t
name|getMaxCount
parameter_list|()
block|{
return|return
name|MaxCount
return|;
block|}
name|uint64_t
name|getMaxInternalCount
parameter_list|()
block|{
return|return
name|MaxInternalCount
return|;
block|}
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
comment|// LLVM_IR_PROFILESUMMARY_H
end_comment

end_unit

