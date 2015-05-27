begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BranchProbability.h - Branch Probability Wrapper ---------*- C++ -*-===//
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
comment|// Definition of BranchProbability shared by IR and Machine Instructions.
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
name|LLVM_SUPPORT_BRANCHPROBABILITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BRANCHPROBABILITY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|// This class represents Branch Probability as a non-negative fraction.
name|class
name|BranchProbability
block|{
comment|// Numerator
name|uint32_t
name|N
decl_stmt|;
comment|// Denominator
name|uint32_t
name|D
decl_stmt|;
name|public
label|:
name|BranchProbability
argument_list|(
argument|uint32_t n
argument_list|,
argument|uint32_t d
argument_list|)
block|:
name|N
argument_list|(
name|n
argument_list|)
operator|,
name|D
argument_list|(
argument|d
argument_list|)
block|{
name|assert
argument_list|(
name|d
operator|>
literal|0
operator|&&
literal|"Denomiator cannot be 0!"
argument_list|)
block|;
name|assert
argument_list|(
name|n
operator|<=
name|d
operator|&&
literal|"Probability cannot be bigger than 1!"
argument_list|)
block|;   }
specifier|static
name|BranchProbability
name|getZero
argument_list|()
block|{
return|return
name|BranchProbability
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
return|;
block|}
specifier|static
name|BranchProbability
name|getOne
parameter_list|()
block|{
return|return
name|BranchProbability
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|uint32_t
name|getNumerator
argument_list|()
specifier|const
block|{
return|return
name|N
return|;
block|}
name|uint32_t
name|getDenominator
argument_list|()
specifier|const
block|{
return|return
name|D
return|;
block|}
comment|// Return (1 - Probability).
name|BranchProbability
name|getCompl
argument_list|()
specifier|const
block|{
return|return
name|BranchProbability
argument_list|(
name|D
operator|-
name|N
argument_list|,
name|D
argument_list|)
return|;
block|}
name|raw_ostream
modifier|&
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Scale a large integer.
comment|///
comment|/// Scales \c Num.  Guarantees full precision.  Returns the floor of the
comment|/// result.
comment|///
comment|/// \return \c Num times \c this.
name|uint64_t
name|scale
argument_list|(
name|uint64_t
name|Num
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Scale a large integer by the inverse.
comment|///
comment|/// Scales \c Num by the inverse of \c this.  Guarantees full precision.
comment|/// Returns the floor of the result.
comment|///
comment|/// \return \c Num divided by \c this.
name|uint64_t
name|scaleByInverse
argument_list|(
name|uint64_t
name|Num
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|N
operator|*
name|RHS
operator|.
name|D
operator|==
operator|(
name|uint64_t
operator|)
name|D
operator|*
name|RHS
operator|.
name|N
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|N
operator|*
name|RHS
operator|.
name|D
operator|<
operator|(
name|uint64_t
operator|)
name|D
operator|*
name|RHS
operator|.
name|N
return|;
block|}
name|bool
name|operator
operator|>
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|RHS
operator|<
operator|*
name|this
operator|)
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
name|BranchProbability
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|<
name|RHS
operator|)
return|;
block|}
block|}
empty_stmt|;
specifier|inline
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
name|BranchProbability
operator|&
name|Prob
operator|)
block|{
return|return
name|Prob
operator|.
name|print
argument_list|(
name|OS
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

