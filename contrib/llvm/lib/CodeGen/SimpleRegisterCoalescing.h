begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SimpleRegisterCoalescing.h - Register Coalescing --------*- C++ -*-===//
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
comment|// This file implements a simple register copy coalescing phase.
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
name|LLVM_CODEGEN_SIMPLE_REGISTER_COALESCING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SIMPLE_REGISTER_COALESCING_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveIntervalAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterCoalescer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SimpleRegisterCoalescing
decl_stmt|;
name|class
name|LiveDebugVariables
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
comment|/// CopyRec - Representation for copy instructions in coalescer queue.
comment|///
struct|struct
name|CopyRec
block|{
name|MachineInstr
modifier|*
name|MI
decl_stmt|;
name|unsigned
name|LoopDepth
decl_stmt|;
name|CopyRec
argument_list|(
argument|MachineInstr *mi
argument_list|,
argument|unsigned depth
argument_list|)
block|:
name|MI
argument_list|(
name|mi
argument_list|)
operator|,
name|LoopDepth
argument_list|(
argument|depth
argument_list|)
block|{}
block|}
struct|;
name|class
name|SimpleRegisterCoalescing
range|:
name|public
name|MachineFunctionPass
decl_stmt|,
name|public
name|RegisterCoalescer
block|{
name|MachineFunction
modifier|*
name|mf_
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|mri_
decl_stmt|;
specifier|const
name|TargetMachine
modifier|*
name|tm_
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|tri_
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|tii_
decl_stmt|;
name|LiveIntervals
modifier|*
name|li_
decl_stmt|;
name|LiveDebugVariables
modifier|*
name|ldv_
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|*
name|loopInfo
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|DenseMap
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|BitVector
operator|>
name|allocatableRCRegs_
expr_stmt|;
comment|/// JoinedCopies - Keep track of copies eliminated due to coalescing.
comment|///
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
operator|,
literal|32
operator|>
name|JoinedCopies
expr_stmt|;
comment|/// ReMatCopies - Keep track of copies eliminated due to remat.
comment|///
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
operator|,
literal|32
operator|>
name|ReMatCopies
expr_stmt|;
comment|/// ReMatDefs - Keep track of definition instructions which have
comment|/// been remat'ed.
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
operator|,
literal|8
operator|>
name|ReMatDefs
expr_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identifcation, replacement for typeid
name|SimpleRegisterCoalescing
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeSimpleRegisterCoalescingPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|/// runOnMachineFunction - pass entry point
name|virtual
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
name|bool
name|coalesceFunction
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|,
name|RegallocQuery
modifier|&
parameter_list|)
block|{
comment|// This runs as an independent pass, so don't do anything.
return|return
name|false
return|;
block|}
comment|/// print - Implement the dump method.
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|Module
operator|*
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// joinIntervals - join compatible live intervals
name|void
name|joinIntervals
parameter_list|()
function_decl|;
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
name|CopyRec
operator|>
operator|&
name|TryAgain
argument_list|)
decl_stmt|;
comment|/// JoinCopy - Attempt to join intervals corresponding to SrcReg/DstReg,
comment|/// which are the src/dst of the copy instruction CopyMI.  This returns true
comment|/// if the copy was successfully coalesced away. If it is not currently
comment|/// possible to coalesce this interval, but it may be possible if other
comment|/// things get coalesced, then it returns true by reference in 'Again'.
name|bool
name|JoinCopy
parameter_list|(
name|CopyRec
modifier|&
name|TheCopy
parameter_list|,
name|bool
modifier|&
name|Again
parameter_list|)
function_decl|;
comment|/// JoinIntervals - Attempt to join these two intervals.  On failure, this
comment|/// returns false.  The output "SrcInt" will not have been modified, so we can
comment|/// use this information below to update aliases.
name|bool
name|JoinIntervals
parameter_list|(
name|CoalescerPair
modifier|&
name|CP
parameter_list|)
function_decl|;
comment|/// Return true if the two specified registers belong to different register
comment|/// classes.  The registers may be either phys or virt regs.
name|bool
name|differingRegisterClasses
argument_list|(
name|unsigned
name|RegA
argument_list|,
name|unsigned
name|RegB
argument_list|)
decl|const
decl_stmt|;
comment|/// AdjustCopiesBackFrom - We found a non-trivially-coalescable copy. If
comment|/// the source value number is defined by a copy from the destination reg
comment|/// see if we can merge these two destination reg valno# into a single
comment|/// value number, eliminating a copy.
name|bool
name|AdjustCopiesBackFrom
parameter_list|(
specifier|const
name|CoalescerPair
modifier|&
name|CP
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// HasOtherReachingDefs - Return true if there are definitions of IntB
comment|/// other than BValNo val# that can reach uses of AValno val# of IntA.
name|bool
name|HasOtherReachingDefs
parameter_list|(
name|LiveInterval
modifier|&
name|IntA
parameter_list|,
name|LiveInterval
modifier|&
name|IntB
parameter_list|,
name|VNInfo
modifier|*
name|AValNo
parameter_list|,
name|VNInfo
modifier|*
name|BValNo
parameter_list|)
function_decl|;
comment|/// RemoveCopyByCommutingDef - We found a non-trivially-coalescable copy.
comment|/// If the source value number is defined by a commutable instruction and
comment|/// its other operand is coalesced to the copy dest register, see if we
comment|/// can transform the copy into a noop by commuting the definition.
name|bool
name|RemoveCopyByCommutingDef
parameter_list|(
specifier|const
name|CoalescerPair
modifier|&
name|CP
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// TrimLiveIntervalToLastUse - If there is a last use in the same basic
comment|/// block as the copy instruction, trim the ive interval to the last use
comment|/// and return true.
name|bool
name|TrimLiveIntervalToLastUse
parameter_list|(
name|SlotIndex
name|CopyIdx
parameter_list|,
name|MachineBasicBlock
modifier|*
name|CopyMBB
parameter_list|,
name|LiveInterval
modifier|&
name|li
parameter_list|,
specifier|const
name|LiveRange
modifier|*
name|LR
parameter_list|)
function_decl|;
comment|/// ReMaterializeTrivialDef - If the source of a copy is defined by a trivial
comment|/// computation, replace the copy by rematerialize the definition.
comment|/// If PreserveSrcInt is true, make sure SrcInt is valid after the call.
name|bool
name|ReMaterializeTrivialDef
parameter_list|(
name|LiveInterval
modifier|&
name|SrcInt
parameter_list|,
name|bool
name|PreserveSrcInt
parameter_list|,
name|unsigned
name|DstReg
parameter_list|,
name|unsigned
name|DstSubIdx
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// shouldJoinPhys - Return true if a physreg copy should be joined.
name|bool
name|shouldJoinPhys
parameter_list|(
name|CoalescerPair
modifier|&
name|CP
parameter_list|)
function_decl|;
comment|/// isWinToJoinCrossClass - Return true if it's profitable to coalesce
comment|/// two virtual registers from different register classes.
name|bool
name|isWinToJoinCrossClass
parameter_list|(
name|unsigned
name|SrcReg
parameter_list|,
name|unsigned
name|DstReg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|SrcRC
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|DstRC
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|NewRC
parameter_list|)
function_decl|;
comment|/// UpdateRegDefsUses - Replace all defs and uses of SrcReg to DstReg and
comment|/// update the subregister number if it is not zero. If DstReg is a
comment|/// physical register and the existing subregister number of the def / use
comment|/// being updated is not zero, make sure to set it to the correct physical
comment|/// subregister.
name|void
name|UpdateRegDefsUses
parameter_list|(
specifier|const
name|CoalescerPair
modifier|&
name|CP
parameter_list|)
function_decl|;
comment|/// ShortenDeadCopyLiveRange - Shorten a live range defined by a dead copy.
comment|/// Return true if live interval is removed.
name|bool
name|ShortenDeadCopyLiveRange
parameter_list|(
name|LiveInterval
modifier|&
name|li
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// ShortenDeadCopyLiveRange - Shorten a live range as it's artificially
comment|/// extended by a dead copy. Mark the last use (if any) of the val# as kill
comment|/// as ends the live range there. If there isn't another use, then this
comment|/// live range is dead. Return true if live interval is removed.
name|bool
name|ShortenDeadCopySrcLiveRange
parameter_list|(
name|LiveInterval
modifier|&
name|li
parameter_list|,
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// RemoveDeadDef - If a def of a live interval is now determined dead,
comment|/// remove the val# it defines. If the live interval becomes empty, remove
comment|/// it as well.
name|bool
name|RemoveDeadDef
parameter_list|(
name|LiveInterval
modifier|&
name|li
parameter_list|,
name|MachineInstr
modifier|*
name|DefMI
parameter_list|)
function_decl|;
comment|/// RemoveCopyFlag - If DstReg is no longer defined by CopyMI, clear the
comment|/// VNInfo copy flag for DstReg and all aliases.
name|void
name|RemoveCopyFlag
parameter_list|(
name|unsigned
name|DstReg
parameter_list|,
specifier|const
name|MachineInstr
modifier|*
name|CopyMI
parameter_list|)
function_decl|;
comment|/// lastRegisterUse - Returns the last use of the specific register between
comment|/// cycles Start and End or NULL if there are no uses.
name|MachineOperand
modifier|*
name|lastRegisterUse
argument_list|(
name|SlotIndex
name|Start
argument_list|,
name|SlotIndex
name|End
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|SlotIndex
operator|&
name|LastUseIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// markAsJoined - Remember that CopyMI has already been joined.
name|void
name|markAsJoined
parameter_list|(
name|MachineInstr
modifier|*
name|CopyMI
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

