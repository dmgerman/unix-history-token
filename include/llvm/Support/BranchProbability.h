begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BranchProbability.h - Branch Probability Analysis --------*- C++ -*-===//
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
comment|// This class represents Branch Probability as a non-negative fraction.
name|class
name|BranchProbability
block|{
name|friend
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|friend
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|friend
name|class
name|MachineBasicBlock
decl_stmt|;
comment|// Numerator
name|uint32_t
name|N
decl_stmt|;
comment|// Denominator
name|uint32_t
name|D
decl_stmt|;
name|BranchProbability
argument_list|(
argument|uint32_t n
argument_list|,
argument|uint32_t d
argument_list|)
empty_stmt|;
name|public
label|:
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
name|BranchProbability
operator|&
name|Prob
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

