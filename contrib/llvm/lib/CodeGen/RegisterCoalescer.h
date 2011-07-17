begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterCoalescer.h - Register Coalescing Interface ------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"RegisterClassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/IncludeFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_REGISTER_COALESCER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_REGISTER_COALESCER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegallocQuery
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
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
name|class
name|LiveDebugVariables
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|CoalescerPair
decl_stmt|;
comment|/// An abstract interface for register coalescers.  Coalescers must
comment|/// implement this interface to be part of the coalescer analysis
comment|/// group.
name|class
name|RegisterCoalescer
range|:
name|public
name|MachineFunctionPass
block|{
name|MachineFunction
operator|*
name|mf_
block|;
name|MachineRegisterInfo
operator|*
name|mri_
block|;
specifier|const
name|TargetMachine
operator|*
name|tm_
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|tri_
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|tii_
block|;
name|LiveIntervals
operator|*
name|li_
block|;
name|LiveDebugVariables
operator|*
name|ldv_
block|;
specifier|const
name|MachineLoopInfo
operator|*
name|loopInfo
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|RegisterClassInfo
name|RegClassInfo
block|;
comment|/// JoinedCopies - Keep track of copies eliminated due to coalescing.
comment|///
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
block|,
literal|32
operator|>
name|JoinedCopies
block|;
comment|/// ReMatCopies - Keep track of copies eliminated due to remat.
comment|///
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
block|,
literal|32
operator|>
name|ReMatCopies
block|;
comment|/// ReMatDefs - Keep track of definition instructions which have
comment|/// been remat'ed.
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
block|,
literal|8
operator|>
name|ReMatDefs
block|;
comment|/// joinIntervals - join compatible live intervals
name|void
name|joinIntervals
argument_list|()
block|;
comment|/// CopyCoalesceInMBB - Coalesce copies in the specified MBB, putting
comment|/// copies that cannot yet be coalesced into the "TryAgain" list.
name|void
name|CopyCoalesceInMBB
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
operator|&
name|TryAgain
argument_list|)
block|;
comment|/// JoinCopy - Attempt to join intervals corresponding to SrcReg/DstReg,
comment|/// which are the src/dst of the copy instruction CopyMI.  This returns true
comment|/// if the copy was successfully coalesced away. If it is not currently
comment|/// possible to coalesce this interval, but it may be possible if other
comment|/// things get coalesced, then it returns true by reference in 'Again'.
name|bool
name|JoinCopy
argument_list|(
name|MachineInstr
operator|*
name|TheCopy
argument_list|,
name|bool
operator|&
name|Again
argument_list|)
block|;
comment|/// JoinIntervals - Attempt to join these two intervals.  On failure, this
comment|/// returns false.  The output "SrcInt" will not have been modified, so we can
comment|/// use this information below to update aliases.
name|bool
name|JoinIntervals
argument_list|(
name|CoalescerPair
operator|&
name|CP
argument_list|)
block|;
comment|/// AdjustCopiesBackFrom - We found a non-trivially-coalescable copy. If
comment|/// the source value number is defined by a copy from the destination reg
comment|/// see if we can merge these two destination reg valno# into a single
comment|/// value number, eliminating a copy.
name|bool
name|AdjustCopiesBackFrom
argument_list|(
specifier|const
name|CoalescerPair
operator|&
name|CP
argument_list|,
name|MachineInstr
operator|*
name|CopyMI
argument_list|)
block|;
comment|/// HasOtherReachingDefs - Return true if there are definitions of IntB
comment|/// other than BValNo val# that can reach uses of AValno val# of IntA.
name|bool
name|HasOtherReachingDefs
argument_list|(
name|LiveInterval
operator|&
name|IntA
argument_list|,
name|LiveInterval
operator|&
name|IntB
argument_list|,
name|VNInfo
operator|*
name|AValNo
argument_list|,
name|VNInfo
operator|*
name|BValNo
argument_list|)
block|;
comment|/// RemoveCopyByCommutingDef - We found a non-trivially-coalescable copy.
comment|/// If the source value number is defined by a commutable instruction and
comment|/// its other operand is coalesced to the copy dest register, see if we
comment|/// can transform the copy into a noop by commuting the definition.
name|bool
name|RemoveCopyByCommutingDef
argument_list|(
specifier|const
name|CoalescerPair
operator|&
name|CP
argument_list|,
name|MachineInstr
operator|*
name|CopyMI
argument_list|)
block|;
comment|/// ReMaterializeTrivialDef - If the source of a copy is defined by a trivial
comment|/// computation, replace the copy by rematerialize the definition.
comment|/// If PreserveSrcInt is true, make sure SrcInt is valid after the call.
name|bool
name|ReMaterializeTrivialDef
argument_list|(
argument|LiveInterval&SrcInt
argument_list|,
argument|bool PreserveSrcInt
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned DstSubIdx
argument_list|,
argument|MachineInstr *CopyMI
argument_list|)
block|;
comment|/// shouldJoinPhys - Return true if a physreg copy should be joined.
name|bool
name|shouldJoinPhys
argument_list|(
name|CoalescerPair
operator|&
name|CP
argument_list|)
block|;
comment|/// isWinToJoinCrossClass - Return true if it's profitable to coalesce
comment|/// two virtual registers from different register classes.
name|bool
name|isWinToJoinCrossClass
argument_list|(
argument|unsigned SrcReg
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|,
argument|const TargetRegisterClass *DstRC
argument_list|,
argument|const TargetRegisterClass *NewRC
argument_list|)
block|;
comment|/// UpdateRegDefsUses - Replace all defs and uses of SrcReg to DstReg and
comment|/// update the subregister number if it is not zero. If DstReg is a
comment|/// physical register and the existing subregister number of the def / use
comment|/// being updated is not zero, make sure to set it to the correct physical
comment|/// subregister.
name|void
name|UpdateRegDefsUses
argument_list|(
specifier|const
name|CoalescerPair
operator|&
name|CP
argument_list|)
block|;
comment|/// RemoveDeadDef - If a def of a live interval is now determined dead,
comment|/// remove the val# it defines. If the live interval becomes empty, remove
comment|/// it as well.
name|bool
name|RemoveDeadDef
argument_list|(
name|LiveInterval
operator|&
name|li
argument_list|,
name|MachineInstr
operator|*
name|DefMI
argument_list|)
block|;
comment|/// RemoveCopyFlag - If DstReg is no longer defined by CopyMI, clear the
comment|/// VNInfo copy flag for DstReg and all aliases.
name|void
name|RemoveCopyFlag
argument_list|(
argument|unsigned DstReg
argument_list|,
argument|const MachineInstr *CopyMI
argument_list|)
block|;
comment|/// markAsJoined - Remember that CopyMI has already been joined.
name|void
name|markAsJoined
argument_list|(
name|MachineInstr
operator|*
name|CopyMI
argument_list|)
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|RegisterCoalescer
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeRegisterCoalescerPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
comment|/// Register allocators must call this from their own
comment|/// getAnalysisUsage to cover the case where the coalescer is not
comment|/// a Pass in the proper sense and isn't managed by PassManager.
comment|/// PassManager needs to know which analyses to make available and
comment|/// which to invalidate when running the register allocator or any
comment|/// pass that might call coalescing.  The long-term solution is to
comment|/// allow hierarchies of PassManagers.
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
comment|/// runOnMachineFunction - pass entry point
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
comment|/// print - Implement the dump method.
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|/// CoalescerPair - A helper class for register coalescers. When deciding if
comment|/// two registers can be coalesced, CoalescerPair can determine if a copy
comment|/// instruction would become an identity copy after coalescing.
name|class
name|CoalescerPair
block|{
specifier|const
name|TargetInstrInfo
modifier|&
name|tii_
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|&
name|tri_
decl_stmt|;
comment|/// dstReg_ - The register that will be left after coalescing. It can be a
comment|/// virtual or physical register.
name|unsigned
name|dstReg_
decl_stmt|;
comment|/// srcReg_ - the virtual register that will be coalesced into dstReg.
name|unsigned
name|srcReg_
decl_stmt|;
comment|/// subReg_ - The subregister index of srcReg in dstReg_. It is possible the
comment|/// coalesce srcReg_ into a subreg of the larger dstReg_ when dstReg_ is a
comment|/// virtual register.
name|unsigned
name|subIdx_
decl_stmt|;
comment|/// partial_ - True when the original copy was a partial subregister copy.
name|bool
name|partial_
decl_stmt|;
comment|/// crossClass_ - True when both regs are virtual, and newRC is constrained.
name|bool
name|crossClass_
decl_stmt|;
comment|/// flipped_ - True when DstReg and SrcReg are reversed from the oriignal copy
comment|/// instruction.
name|bool
name|flipped_
decl_stmt|;
comment|/// newRC_ - The register class of the coalesced register, or NULL if dstReg_
comment|/// is a physreg.
specifier|const
name|TargetRegisterClass
modifier|*
name|newRC_
decl_stmt|;
name|public
label|:
name|CoalescerPair
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|tri
argument_list|)
operator|:
name|tii_
argument_list|(
name|tii
argument_list|)
operator|,
name|tri_
argument_list|(
name|tri
argument_list|)
operator|,
name|dstReg_
argument_list|(
literal|0
argument_list|)
operator|,
name|srcReg_
argument_list|(
literal|0
argument_list|)
operator|,
name|subIdx_
argument_list|(
literal|0
argument_list|)
operator|,
name|partial_
argument_list|(
name|false
argument_list|)
operator|,
name|crossClass_
argument_list|(
name|false
argument_list|)
operator|,
name|flipped_
argument_list|(
name|false
argument_list|)
operator|,
name|newRC_
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// setRegisters - set registers to match the copy instruction MI. Return
comment|/// false if MI is not a coalescable copy instruction.
name|bool
name|setRegisters
argument_list|(
specifier|const
name|MachineInstr
operator|*
argument_list|)
expr_stmt|;
comment|/// flip - Swap srcReg_ and dstReg_. Return false if swapping is impossible
comment|/// because dstReg_ is a physical register, or subIdx_ is set.
name|bool
name|flip
parameter_list|()
function_decl|;
comment|/// isCoalescable - Return true if MI is a copy instruction that will become
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
comment|/// isPhys - Return true if DstReg is a physical register.
name|bool
name|isPhys
argument_list|()
specifier|const
block|{
return|return
operator|!
name|newRC_
return|;
block|}
comment|/// isPartial - Return true if the original copy instruction did not copy the
comment|/// full register, but was a subreg operation.
name|bool
name|isPartial
argument_list|()
specifier|const
block|{
return|return
name|partial_
return|;
block|}
comment|/// isCrossClass - Return true if DstReg is virtual and NewRC is a smaller register class than DstReg's.
name|bool
name|isCrossClass
argument_list|()
specifier|const
block|{
return|return
name|crossClass_
return|;
block|}
comment|/// isFlipped - Return true when getSrcReg is the register being defined by
comment|/// the original copy instruction.
name|bool
name|isFlipped
argument_list|()
specifier|const
block|{
return|return
name|flipped_
return|;
block|}
comment|/// getDstReg - Return the register (virtual or physical) that will remain
comment|/// after coalescing.
name|unsigned
name|getDstReg
argument_list|()
specifier|const
block|{
return|return
name|dstReg_
return|;
block|}
comment|/// getSrcReg - Return the virtual register that will be coalesced away.
name|unsigned
name|getSrcReg
argument_list|()
specifier|const
block|{
return|return
name|srcReg_
return|;
block|}
comment|/// getSubIdx - Return the subregister index in DstReg that SrcReg will be
comment|/// coalesced into, or 0.
name|unsigned
name|getSubIdx
argument_list|()
specifier|const
block|{
return|return
name|subIdx_
return|;
block|}
comment|/// getNewRC - Return the register class of the coalesced register.
specifier|const
name|TargetRegisterClass
operator|*
name|getNewRC
argument_list|()
specifier|const
block|{
return|return
name|newRC_
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

