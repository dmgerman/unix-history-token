begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AddrModeMatcher.h - Addressing mode matching facility ----*- C++ -*-===//
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
comment|// AddressingModeMatcher - This class exposes a single public method, which is
end_comment

begin_comment
comment|// used to construct a "maximal munch" of the addressing mode for the target
end_comment

begin_comment
comment|// specified by TLI for an access to "V" with an access type of AccessTy.  This
end_comment

begin_comment
comment|// returns the addressing mode that is actually matched by value, but also
end_comment

begin_comment
comment|// returns the list of instructions involved in that addressing computation in
end_comment

begin_comment
comment|// AddrModeInsts.
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
name|LLVM_TRANSFORMS_UTILS_ADDRMODEMATCHER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_ADDRMODEMATCHER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|User
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// ExtAddrMode - This is an extended version of TargetLowering::AddrMode
comment|/// which holds actual Value*'s for register values.
name|struct
name|ExtAddrMode
range|:
name|public
name|TargetLowering
operator|::
name|AddrMode
block|{
name|Value
operator|*
name|BaseReg
block|;
name|Value
operator|*
name|ScaledReg
block|;
name|ExtAddrMode
argument_list|()
operator|:
name|BaseReg
argument_list|(
literal|0
argument_list|)
block|,
name|ScaledReg
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|dump
argument_list|()
specifier|const
block|; }
decl_stmt|;
specifier|static
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
name|ExtAddrMode
operator|&
name|AM
operator|)
block|{
name|AM
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
name|class
name|AddressingModeMatcher
block|{
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|AddrModeInsts
expr_stmt|;
specifier|const
name|TargetLowering
modifier|&
name|TLI
decl_stmt|;
comment|/// AccessTy/MemoryInst - This is the type for the access (e.g. double) and
comment|/// the memory instruction that we're computing this address for.
specifier|const
name|Type
modifier|*
name|AccessTy
decl_stmt|;
name|Instruction
modifier|*
name|MemoryInst
decl_stmt|;
comment|/// AddrMode - This is the addressing mode that we're building up.  This is
comment|/// part of the return value of this addressing mode matching stuff.
name|ExtAddrMode
modifier|&
name|AddrMode
decl_stmt|;
comment|/// IgnoreProfitability - This is set to true when we should not do
comment|/// profitability checks.  When true, IsProfitableToFoldIntoAddressingMode
comment|/// always returns true.
name|bool
name|IgnoreProfitability
decl_stmt|;
name|AddressingModeMatcher
argument_list|(
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|AMI
argument_list|,
specifier|const
name|TargetLowering
operator|&
name|T
argument_list|,
specifier|const
name|Type
operator|*
name|AT
argument_list|,
name|Instruction
operator|*
name|MI
argument_list|,
name|ExtAddrMode
operator|&
name|AM
argument_list|)
operator|:
name|AddrModeInsts
argument_list|(
name|AMI
argument_list|)
operator|,
name|TLI
argument_list|(
name|T
argument_list|)
operator|,
name|AccessTy
argument_list|(
name|AT
argument_list|)
operator|,
name|MemoryInst
argument_list|(
name|MI
argument_list|)
operator|,
name|AddrMode
argument_list|(
argument|AM
argument_list|)
block|{
name|IgnoreProfitability
operator|=
name|false
block|;   }
name|public
operator|:
comment|/// Match - Find the maximal addressing mode that a load/store of V can fold,
comment|/// give an access type of AccessTy.  This returns a list of involved
comment|/// instructions in AddrModeInsts.
specifier|static
name|ExtAddrMode
name|Match
argument_list|(
argument|Value *V
argument_list|,
argument|const Type *AccessTy
argument_list|,
argument|Instruction *MemoryInst
argument_list|,
argument|SmallVectorImpl<Instruction*>&AddrModeInsts
argument_list|,
argument|const TargetLowering&TLI
argument_list|)
block|{
name|ExtAddrMode
name|Result
block|;
name|bool
name|Success
operator|=
name|AddressingModeMatcher
argument_list|(
name|AddrModeInsts
argument_list|,
name|TLI
argument_list|,
name|AccessTy
argument_list|,
name|MemoryInst
argument_list|,
name|Result
argument_list|)
operator|.
name|MatchAddr
argument_list|(
name|V
argument_list|,
literal|0
argument_list|)
block|;
name|Success
operator|=
name|Success
block|;
name|assert
argument_list|(
name|Success
operator|&&
literal|"Couldn't select *anything*?"
argument_list|)
block|;
return|return
name|Result
return|;
block|}
name|private
label|:
name|bool
name|MatchScaledValue
parameter_list|(
name|Value
modifier|*
name|ScaleReg
parameter_list|,
name|int64_t
name|Scale
parameter_list|,
name|unsigned
name|Depth
parameter_list|)
function_decl|;
name|bool
name|MatchAddr
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Depth
parameter_list|)
function_decl|;
name|bool
name|MatchOperationAddr
parameter_list|(
name|User
modifier|*
name|Operation
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Depth
parameter_list|)
function_decl|;
name|bool
name|IsProfitableToFoldIntoAddressingMode
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|ExtAddrMode
modifier|&
name|AMBefore
parameter_list|,
name|ExtAddrMode
modifier|&
name|AMAfter
parameter_list|)
function_decl|;
name|bool
name|ValueAlreadyLiveAtInst
parameter_list|(
name|Value
modifier|*
name|Val
parameter_list|,
name|Value
modifier|*
name|KnownLive1
parameter_list|,
name|Value
modifier|*
name|KnownLive2
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

