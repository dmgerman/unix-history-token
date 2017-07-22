begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AArch64PBQPRegAlloc.h - AArch64 specific PBQP constraints --*- C++ -*-==//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AARCH64_AARCH64PBQPREGALOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64PBQPREGALOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PBQPRAConstraint.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// Add the accumulator chaining constraint to a PBQP graph
name|class
name|A57ChainingConstraint
range|:
name|public
name|PBQPRAConstraint
block|{
name|public
operator|:
comment|// Add A57 specific constraints to the PBQP graph.
name|void
name|apply
argument_list|(
argument|PBQPRAGraph&G
argument_list|)
name|override
block|;
name|private
operator|:
name|SmallSetVector
operator|<
name|unsigned
block|,
literal|32
operator|>
name|Chains
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
comment|// Add the accumulator chaining constraint, inside the chain, i.e. so that
comment|// parity(Rd) == parity(Ra).
comment|// \return true if a constraint was added
name|bool
name|addIntraChainConstraint
argument_list|(
argument|PBQPRAGraph&G
argument_list|,
argument|unsigned Rd
argument_list|,
argument|unsigned Ra
argument_list|)
block|;
comment|// Add constraints between existing chains
name|void
name|addInterChainConstraint
argument_list|(
argument|PBQPRAGraph&G
argument_list|,
argument|unsigned Rd
argument_list|,
argument|unsigned Ra
argument_list|)
block|; }
decl_stmt|;
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
comment|// LLVM_LIB_TARGET_AARCH64_AARCH64PBQPREGALOC_H
end_comment

end_unit

