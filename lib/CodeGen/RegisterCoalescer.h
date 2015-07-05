begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterCoalescer.h - Register Coalescing Interface -----*- C++ -*-===//
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
comment|// This file contains the abstract interface for register coalescers,
end_comment

begin_comment
comment|// allowing them to interact with and query register allocators.
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
name|LLVM_LIB_CODEGEN_REGISTERCOALESCER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_REGISTERCOALESCER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// A helper class for register coalescers. When deciding if
comment|/// two registers can be coalesced, CoalescerPair can determine if a copy
comment|/// instruction would become an identity copy after coalescing.
name|class
name|CoalescerPair
block|{
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
decl_stmt|;
comment|/// The register that will be left after coalescing. It can be a
comment|/// virtual or physical register.
name|unsigned
name|DstReg
decl_stmt|;
comment|/// The virtual register that will be coalesced into dstReg.
name|unsigned
name|SrcReg
decl_stmt|;
comment|/// The sub-register index of the old DstReg in the new coalesced register.
name|unsigned
name|DstIdx
decl_stmt|;
comment|/// The sub-register index of the old SrcReg in the new coalesced register.
name|unsigned
name|SrcIdx
decl_stmt|;
comment|/// True when the original copy was a partial subregister copy.
name|bool
name|Partial
decl_stmt|;
comment|/// True when both regs are virtual and newRC is constrained.
name|bool
name|CrossClass
decl_stmt|;
comment|/// True when DstReg and SrcReg are reversed from the original
comment|/// copy instruction.
name|bool
name|Flipped
decl_stmt|;
comment|/// The register class of the coalesced register, or NULL if DstReg
comment|/// is a physreg. This register class may be a super-register of both
comment|/// SrcReg and DstReg.
specifier|const
name|TargetRegisterClass
modifier|*
name|NewRC
decl_stmt|;
name|public
label|:
name|CoalescerPair
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|tri
argument_list|)
operator|:
name|TRI
argument_list|(
name|tri
argument_list|)
operator|,
name|DstReg
argument_list|(
literal|0
argument_list|)
operator|,
name|SrcReg
argument_list|(
literal|0
argument_list|)
operator|,
name|DstIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|SrcIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|Partial
argument_list|(
name|false
argument_list|)
operator|,
name|CrossClass
argument_list|(
name|false
argument_list|)
operator|,
name|Flipped
argument_list|(
name|false
argument_list|)
operator|,
name|NewRC
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Create a CoalescerPair representing a virtreg-to-physreg copy.
comment|/// No need to call setRegisters().
name|CoalescerPair
argument_list|(
argument|unsigned VirtReg
argument_list|,
argument|unsigned PhysReg
argument_list|,
argument|const TargetRegisterInfo&tri
argument_list|)
operator|:
name|TRI
argument_list|(
name|tri
argument_list|)
operator|,
name|DstReg
argument_list|(
name|PhysReg
argument_list|)
operator|,
name|SrcReg
argument_list|(
name|VirtReg
argument_list|)
operator|,
name|DstIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|SrcIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|Partial
argument_list|(
name|false
argument_list|)
operator|,
name|CrossClass
argument_list|(
name|false
argument_list|)
operator|,
name|Flipped
argument_list|(
name|false
argument_list|)
operator|,
name|NewRC
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Set registers to match the copy instruction MI. Return
comment|/// false if MI is not a coalescable copy instruction.
name|bool
name|setRegisters
argument_list|(
specifier|const
name|MachineInstr
operator|*
argument_list|)
expr_stmt|;
comment|/// Swap SrcReg and DstReg. Return false if swapping is impossible
comment|/// because DstReg is a physical register, or SubIdx is set.
name|bool
name|flip
parameter_list|()
function_decl|;
comment|/// Return true if MI is a copy instruction that will become
comment|/// an identity copy after coalescing.
name|bool
name|isCoalescable
argument_list|(
specifier|const
name|MachineInstr
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if DstReg is a physical register.
name|bool
name|isPhys
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NewRC
return|;
block|}
comment|/// Return true if the original copy instruction did not copy
comment|/// the full register, but was a subreg operation.
name|bool
name|isPartial
argument_list|()
specifier|const
block|{
return|return
name|Partial
return|;
block|}
comment|/// Return true if DstReg is virtual and NewRC is a smaller
comment|/// register class than DstReg's.
name|bool
name|isCrossClass
argument_list|()
specifier|const
block|{
return|return
name|CrossClass
return|;
block|}
comment|/// Return true when getSrcReg is the register being defined by
comment|/// the original copy instruction.
name|bool
name|isFlipped
argument_list|()
specifier|const
block|{
return|return
name|Flipped
return|;
block|}
comment|/// Return the register (virtual or physical) that will remain
comment|/// after coalescing.
name|unsigned
name|getDstReg
argument_list|()
specifier|const
block|{
return|return
name|DstReg
return|;
block|}
comment|/// Return the virtual register that will be coalesced away.
name|unsigned
name|getSrcReg
argument_list|()
specifier|const
block|{
return|return
name|SrcReg
return|;
block|}
comment|/// Return the subregister index that DstReg will be coalesced into, or 0.
name|unsigned
name|getDstIdx
argument_list|()
specifier|const
block|{
return|return
name|DstIdx
return|;
block|}
comment|/// Return the subregister index that SrcReg will be coalesced into, or 0.
name|unsigned
name|getSrcIdx
argument_list|()
specifier|const
block|{
return|return
name|SrcIdx
return|;
block|}
comment|/// Return the register class of the coalesced register.
specifier|const
name|TargetRegisterClass
operator|*
name|getNewRC
argument_list|()
specifier|const
block|{
return|return
name|NewRC
return|;
block|}
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

