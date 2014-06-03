begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- BlockFrequency.h - Block Frequency Wrapper --------*- C++ -*-===//
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
comment|// This file implements Block Frequency class.
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
name|LLVM_SUPPORT_BLOCKFREQUENCY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BLOCKFREQUENCY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|BranchProbability
decl_stmt|;
comment|// This class represents Block Frequency as a 64-bit value.
name|class
name|BlockFrequency
block|{
name|uint64_t
name|Frequency
decl_stmt|;
specifier|static
specifier|const
name|int64_t
name|ENTRY_FREQ
init|=
literal|1
operator|<<
literal|14
decl_stmt|;
comment|/// \brief Scale the given BlockFrequency by N/D. Return the remainder from
comment|/// the division by D. Upon overflow, the routine will saturate and
comment|/// additionally will return the remainder set to D.
name|uint32_t
name|scale
parameter_list|(
name|uint32_t
name|N
parameter_list|,
name|uint32_t
name|D
parameter_list|)
function_decl|;
name|public
label|:
name|BlockFrequency
argument_list|(
argument|uint64_t Freq =
literal|0
argument_list|)
block|:
name|Frequency
argument_list|(
argument|Freq
argument_list|)
block|{ }
comment|/// \brief Returns the frequency of the entry block of the function.
specifier|static
name|uint64_t
name|getEntryFrequency
parameter_list|()
block|{
return|return
name|ENTRY_FREQ
return|;
block|}
comment|/// \brief Returns the maximum possible frequency, the saturation value.
specifier|static
name|uint64_t
name|getMaxFrequency
parameter_list|()
block|{
return|return
operator|-
literal|1ULL
return|;
block|}
comment|/// \brief Returns the frequency as a fixpoint number scaled by the entry
comment|/// frequency.
name|uint64_t
name|getFrequency
argument_list|()
specifier|const
block|{
return|return
name|Frequency
return|;
block|}
comment|/// \brief Multiplies with a branch probability. The computation will never
comment|/// overflow.
name|BlockFrequency
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|BranchProbability
operator|&
name|Prob
operator|)
expr_stmt|;
specifier|const
name|BlockFrequency
name|operator
modifier|*
argument_list|(
specifier|const
name|BranchProbability
operator|&
name|Prob
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Divide by a non-zero branch probability using saturating
comment|/// arithmetic.
name|BlockFrequency
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|BranchProbability
operator|&
name|Prob
operator|)
expr_stmt|;
name|BlockFrequency
name|operator
operator|/
operator|(
specifier|const
name|BranchProbability
operator|&
name|Prob
operator|)
specifier|const
expr_stmt|;
comment|/// \brief Adds another block frequency using saturating arithmetic.
name|BlockFrequency
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|BlockFrequency
operator|&
name|Freq
operator|)
expr_stmt|;
specifier|const
name|BlockFrequency
name|operator
operator|+
operator|(
specifier|const
name|BlockFrequency
operator|&
name|Freq
operator|)
specifier|const
expr_stmt|;
comment|/// \brief Scale the given BlockFrequency by N/D. Return the remainder from
comment|/// the division by D. Upon overflow, the routine will saturate.
name|uint32_t
name|scale
parameter_list|(
specifier|const
name|BranchProbability
modifier|&
name|Prob
parameter_list|)
function_decl|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|BlockFrequency
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Frequency
operator|<
name|RHS
operator|.
name|Frequency
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|BlockFrequency
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Frequency
operator|<=
name|RHS
operator|.
name|Frequency
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|BlockFrequency
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Frequency
operator|>
name|RHS
operator|.
name|Frequency
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|BlockFrequency
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Frequency
operator|>=
name|RHS
operator|.
name|Frequency
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|BlockFrequency
operator|&
name|Freq
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

