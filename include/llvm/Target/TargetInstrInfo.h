begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetInstrInfo.h - Instruction Info --------*- C++ -*-===//
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
comment|// This file describes the target machine instruction set to the code generator.
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
name|LLVM_TARGET_TARGETINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|InstrItineraryData
decl_stmt|;
name|class
name|LiveVariables
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MachineMemOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|ScheduleHazardRecognizer
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|BranchProbability
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|//---------------------------------------------------------------------------
comment|///
comment|/// TargetInstrInfo - Interface to description of machine instruction set
comment|///
name|class
name|TargetInstrInfo
range|:
name|public
name|MCInstrInfo
block|{
name|TargetInstrInfo
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetInstrInfo
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|public
operator|:
name|TargetInstrInfo
argument_list|(
argument|int CFSetupOpcode = -
literal|1
argument_list|,
argument|int CFDestroyOpcode = -
literal|1
argument_list|)
operator|:
name|CallFrameSetupOpcode
argument_list|(
name|CFSetupOpcode
argument_list|)
block|,
name|CallFrameDestroyOpcode
argument_list|(
argument|CFDestroyOpcode
argument_list|)
block|{   }
name|virtual
operator|~
name|TargetInstrInfo
argument_list|()
block|;
comment|/// getRegClass - Givem a machine instruction descriptor, returns the register
comment|/// class constraint for OpNum, or NULL.
specifier|const
name|TargetRegisterClass
operator|*
name|getRegClass
argument_list|(
argument|const MCInstrDesc&TID
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
comment|/// isTriviallyReMaterializable - Return true if the instruction is trivially
comment|/// rematerializable, meaning it has no side effects and requires no operands
comment|/// that aren't always available.
name|bool
name|isTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|MI
operator|->
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|IMPLICIT_DEF
operator|||
operator|(
name|MI
operator|->
name|getDesc
argument_list|()
operator|.
name|isRematerializable
argument_list|()
operator|&&
operator|(
name|isReallyTriviallyReMaterializable
argument_list|(
name|MI
argument_list|,
name|AA
argument_list|)
operator|||
name|isReallyTriviallyReMaterializableGeneric
argument_list|(
name|MI
argument_list|,
name|AA
argument_list|)
operator|)
operator|)
return|;
block|}
name|protected
operator|:
comment|/// isReallyTriviallyReMaterializable - For instructions with opcodes for
comment|/// which the M_REMATERIALIZABLE flag is set, this hook lets the target
comment|/// specify whether the instruction is actually trivially rematerializable,
comment|/// taking into consideration its operands. This predicate must return false
comment|/// if the instruction has any side effects other than producing a value, or
comment|/// if it requres any address registers that are not always available.
name|virtual
name|bool
name|isReallyTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|private
operator|:
comment|/// isReallyTriviallyReMaterializableGeneric - For instructions with opcodes
comment|/// for which the M_REMATERIALIZABLE flag is set and the target hook
comment|/// isReallyTriviallyReMaterializable returns false, this function does
comment|/// target-independent tests to determine if the instruction is really
comment|/// trivially rematerializable.
name|bool
name|isReallyTriviallyReMaterializableGeneric
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|/// getCallFrameSetup/DestroyOpcode - These methods return the opcode of the
comment|/// frame setup/destroy instructions if they exist (-1 otherwise).  Some
comment|/// targets use pseudo instructions in order to abstract away the difference
comment|/// between operating with a frame pointer and operating without, through the
comment|/// use of these two instructions.
comment|///
name|int
name|getCallFrameSetupOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameSetupOpcode
return|;
block|}
name|int
name|getCallFrameDestroyOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameDestroyOpcode
return|;
block|}
comment|/// isCoalescableExtInstr - Return true if the instruction is a "coalescable"
comment|/// extension instruction. That is, it's like a copy where it's legal for the
comment|/// source to overlap the destination. e.g. X86::MOVSX64rr32. If this returns
comment|/// true, then it's expected the pre-extension value is available as a subreg
comment|/// of the result register. This also returns the sub-register index in
comment|/// SubIdx.
name|virtual
name|bool
name|isCoalescableExtInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SubIdx
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isLoadFromStackSlot - If the specified machine instruction is a direct
comment|/// load from a stack slot, return the virtual or physical register number of
comment|/// the destination along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than loading from the stack slot.
name|virtual
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// isLoadFromStackSlotPostFE - Check for post-frame ptr elimination
comment|/// stack locations as well.  This uses a heuristic so it isn't
comment|/// reliable for correctness.
name|virtual
name|unsigned
name|isLoadFromStackSlotPostFE
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// hasLoadFromStackSlot - If the specified machine instruction has
comment|/// a load from a stack slot, return true along with the FrameIndex
comment|/// of the loaded stack slot and the machine mem operand containing
comment|/// the reference.  If not, return false.  Unlike
comment|/// isLoadFromStackSlot, this returns true for any instructions that
comment|/// loads from the stack.  This is just a hint, as some cases may be
comment|/// missed.
name|virtual
name|bool
name|hasLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// isStoreToStackSlot - If the specified machine instruction is a direct
comment|/// store to a stack slot, return the virtual or physical register number of
comment|/// the source reg along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than storing to the stack slot.
name|virtual
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// isStoreToStackSlotPostFE - Check for post-frame ptr elimination
comment|/// stack locations as well.  This uses a heuristic so it isn't
comment|/// reliable for correctness.
name|virtual
name|unsigned
name|isStoreToStackSlotPostFE
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// hasStoreToStackSlot - If the specified machine instruction has a
comment|/// store to a stack slot, return true along with the FrameIndex of
comment|/// the loaded stack slot and the machine mem operand containing the
comment|/// reference.  If not, return false.  Unlike isStoreToStackSlot,
comment|/// this returns true for any instructions that stores to the
comment|/// stack.  This is just a hint, as some cases may be missed.
name|virtual
name|bool
name|hasStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// reMaterialize - Re-issue the specified 'original' instruction at the
comment|/// specific location targeting a new destination register.
comment|/// The register in Orig->getOperand(0).getReg() will be substituted by
comment|/// DestReg:SubIdx. Any existing subreg index is preserved or composed with
comment|/// SubIdx.
name|virtual
name|void
name|reMaterialize
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|const MachineInstr *Orig
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// scheduleTwoAddrSource - Schedule the copy / re-mat of the source of the
comment|/// two-addrss instruction inserted by two-address pass.
name|virtual
name|void
name|scheduleTwoAddrSource
argument_list|(
argument|MachineInstr *SrcMI
argument_list|,
argument|MachineInstr *UseMI
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
block|{
comment|// Do nothing.
block|}
comment|/// duplicate - Create a duplicate of the Orig instruction in MF. This is like
comment|/// MachineFunction::CloneMachineInstr(), but the target may update operands
comment|/// that are required to be unique.
comment|///
comment|/// The instruction must be duplicable as indicated by isNotDuplicable().
name|virtual
name|MachineInstr
operator|*
name|duplicate
argument_list|(
argument|MachineInstr *Orig
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// convertToThreeAddress - This method must be implemented by targets that
comment|/// set the M_CONVERTIBLE_TO_3_ADDR flag.  When this flag is set, the target
comment|/// may be able to convert a two-address instruction into one or more true
comment|/// three-address instructions on demand.  This allows the X86 target (for
comment|/// example) to convert ADD and SHL instructions into LEA instructions if they
comment|/// would require register copies due to two-addressness.
comment|///
comment|/// This method returns a null pointer if the transformation cannot be
comment|/// performed, otherwise it returns the last new instruction.
comment|///
name|virtual
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MFI
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// commuteInstruction - If a target has any instructions that are
comment|/// commutable but require converting to different instructions or making
comment|/// non-trivial changes to commute them, this method can overloaded to do
comment|/// that.  The default implementation simply swaps the commutable operands.
comment|/// If NewMI is false, MI is modified in place and returned; otherwise, a
comment|/// new machine instruction is created and returned.  Do not call this
comment|/// method for a non-commutable instruction, but there may be some cases
comment|/// where this method fails and returns null.
name|virtual
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI = false
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// findCommutedOpIndices - If specified MI is commutable, return the two
comment|/// operand indices that would swap value. Return false if the instruction
comment|/// is not in a form which this routine understands.
name|virtual
name|bool
name|findCommutedOpIndices
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned&SrcOpIdx1
argument_list|,
argument|unsigned&SrcOpIdx2
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// produceSameValue - Return true if two machine instructions would produce
comment|/// identical values. By default, this is only true when the two instructions
comment|/// are deemed identical except for defs. If this function is called when the
comment|/// IR is still in SSA form, the caller can pass the MachineRegisterInfo for
comment|/// aggressive checks.
name|virtual
name|bool
name|produceSameValue
argument_list|(
argument|const MachineInstr *MI0
argument_list|,
argument|const MachineInstr *MI1
argument_list|,
argument|const MachineRegisterInfo *MRI =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// AnalyzeBranch - Analyze the branching code at the end of MBB, returning
comment|/// true if it cannot be understood (e.g. it's a switch dispatch or isn't
comment|/// implemented for a target).  Upon success, this returns false and returns
comment|/// with the following information in various cases:
comment|///
comment|/// 1. If this block ends with no branches (it just falls through to its succ)
comment|///    just return false, leaving TBB/FBB null.
comment|/// 2. If this block ends with only an unconditional branch, it sets TBB to be
comment|///    the destination block.
comment|/// 3. If this block ends with a conditional branch and it falls through to a
comment|///    successor block, it sets TBB to be the branch destination block and a
comment|///    list of operands that evaluate the condition. These operands can be
comment|///    passed to other TargetInstrInfo methods to create new branches.
comment|/// 4. If this block ends with a conditional branch followed by an
comment|///    unconditional branch, it returns the 'true' destination in TBB, the
comment|///    'false' destination in FBB, and a list of operands that evaluate the
comment|///    condition.  These operands can be passed to other TargetInstrInfo
comment|///    methods to create new branches.
comment|///
comment|/// Note that RemoveBranch and InsertBranch must be implemented to support
comment|/// cases where this method returns success.
comment|///
comment|/// If AllowModify is true, then this routine is allowed to modify the basic
comment|/// block (e.g. delete instructions after the unconditional branch).
comment|///
name|virtual
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify = false
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// RemoveBranch - Remove the branching code at the end of the specific MBB.
comment|/// This is only invoked in cases where AnalyzeBranch returns success. It
comment|/// returns the number of instructions that were removed.
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::RemoveBranch!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
comment|/// InsertBranch - Insert branch code into the end of the specified
comment|/// MachineBasicBlock.  The operands to this method are the same as those
comment|/// returned by AnalyzeBranch.  This is only invoked in cases where
comment|/// AnalyzeBranch returns success. It returns the number of instructions
comment|/// inserted.
comment|///
comment|/// It is also invoked by tail merging to add unconditional branches in
comment|/// cases where AnalyzeBranch doesn't apply because there was no original
comment|/// branch to analyze.  At least this much must be implemented, else tail
comment|/// merging needs to be disabled.
name|virtual
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::InsertBranch!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
comment|/// ReplaceTailWithBranchTo - Delete the instruction OldInst and everything
comment|/// after it, replacing it with an unconditional branch to NewDest. This is
comment|/// used by the tail merging pass.
name|virtual
name|void
name|ReplaceTailWithBranchTo
argument_list|(
argument|MachineBasicBlock::iterator Tail
argument_list|,
argument|MachineBasicBlock *NewDest
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// isLegalToSplitMBBAt - Return true if it's legal to split the given basic
comment|/// block at the specified instruction (i.e. instruction would be the start
comment|/// of a new basic block).
name|virtual
name|bool
name|isLegalToSplitMBBAt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// isProfitableToIfCvt - Return true if it's profitable to predicate
comment|/// instructions with accumulated instruction latency of "NumCycles"
comment|/// of the specified basic block, where the probability of the instructions
comment|/// being executed is given by Probability, and Confidence is a measure
comment|/// of our confidence that it will be properly predicted.
name|virtual
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCyles
argument_list|,
argument|unsigned ExtraPredCycles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isProfitableToIfCvt - Second variant of isProfitableToIfCvt, this one
comment|/// checks for the case where two basic blocks from true and false path
comment|/// of a if-then-else (diamond) are predicated on mutally exclusive
comment|/// predicates, where the probability of the true path being taken is given
comment|/// by Probability, and Confidence is a measure of our confidence that it
comment|/// will be properly predicted.
name|virtual
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|unsigned NumTCycles
argument_list|,
argument|unsigned ExtraTCycles
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|,
argument|unsigned NumFCycles
argument_list|,
argument|unsigned ExtraFCycles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isProfitableToDupForIfCvt - Return true if it's profitable for
comment|/// if-converter to duplicate instructions of specified accumulated
comment|/// instruction latencies in the specified MBB to enable if-conversion.
comment|/// The probability of the instructions being executed is given by
comment|/// Probability, and Confidence is a measure of our confidence that it
comment|/// will be properly predicted.
name|virtual
name|bool
name|isProfitableToDupForIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCyles
argument_list|,
argument|const BranchProbability&Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// copyPhysReg - Emit instructions to copy a pair of physical registers.
name|virtual
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::copyPhysReg!"
argument_list|)
block|;   }
comment|/// storeRegToStackSlot - Store the specified register of the given register
comment|/// class to the specified stack frame index. The store instruction is to be
comment|/// added to the given machine basic block before the specified machine
comment|/// instruction. If isKill is true, the register operand is the last use and
comment|/// must be marked kill.
name|virtual
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::storeRegToStackSlot!"
argument_list|)
block|;   }
comment|/// loadRegFromStackSlot - Load the specified register of the given register
comment|/// class from the specified stack frame index. The load instruction is to be
comment|/// added to the given machine basic block before the specified machine
comment|/// instruction.
name|virtual
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::loadRegFromStackSlot!"
argument_list|)
block|;   }
comment|/// expandPostRAPseudo - This function is called for all pseudo instructions
comment|/// that remain after register allocation. Many pseudo instructions are
comment|/// created to help register allocation. This is the place to convert them
comment|/// into real instructions. The target can edit MI in place, or it can insert
comment|/// new instructions and erase MI. The function should return true if
comment|/// anything was changed.
name|virtual
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// emitFrameIndexDebugValue - Emit a target-dependent form of
comment|/// DBG_VALUE encoding the address of a frame index.  Addresses would
comment|/// normally be lowered the same way as other addresses on the target,
comment|/// e.g. in load instructions.  For targets that do not support this
comment|/// the debug info is simply lost.
comment|/// If you add this for a target you should handle this DBG_VALUE in the
comment|/// target-specific AsmPrinter code as well; you will probably get invalid
comment|/// assembly output if you don't.
name|virtual
name|MachineInstr
operator|*
name|emitFrameIndexDebugValue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FrameIx
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|const MDNode *MDPtr
argument_list|,
argument|DebugLoc dl
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// foldMemoryOperand - Attempt to fold a load or store of the specified stack
comment|/// slot into the specified machine instruction for the specified operand(s).
comment|/// If this is possible, a new instruction is returned with the specified
comment|/// operand folded, otherwise NULL is returned.
comment|/// The new instruction is inserted before MI, and the client is responsible
comment|/// for removing the old instruction.
name|MachineInstr
operator|*
name|foldMemoryOperand
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|;
comment|/// foldMemoryOperand - Same as the previous version except it allows folding
comment|/// of any load and store from / to any address, not just from a specific
comment|/// stack slot.
name|MachineInstr
operator|*
name|foldMemoryOperand
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|MachineInstr* LoadMI
argument_list|)
specifier|const
block|;
name|protected
operator|:
comment|/// foldMemoryOperandImpl - Target-dependent implementation for
comment|/// foldMemoryOperand. Target-independent code in foldMemoryOperand will
comment|/// take care of adding a MachineMemOperand to the newly created instruction.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// foldMemoryOperandImpl - Target-dependent implementation for
comment|/// foldMemoryOperand. Target-independent code in foldMemoryOperand will
comment|/// take care of adding a MachineMemOperand to the newly created instruction.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|MachineInstr* LoadMI
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|public
operator|:
comment|/// canFoldMemoryOperand - Returns true for the specified load / store if
comment|/// folding is possible.
name|virtual
name|bool
name|canFoldMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// unfoldMemoryOperand - Separate a single instruction which folded a load or
comment|/// a store or a load and a store into two or more instruction. If this is
comment|/// possible, returns true as well as the new instructions by reference.
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDNode*>&NewNodes
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getOpcodeAfterMemoryUnfold - Returns the opcode of the would be new
comment|/// instruction after load / store are unfolded from an instruction of the
comment|/// specified opcode. It returns zero if the specified unfolding is not
comment|/// possible. If LoadRegIndex is non-null, it is filled in with the operand
comment|/// index of the operand which will hold the register holding the loaded
comment|/// value.
name|virtual
name|unsigned
name|getOpcodeAfterMemoryUnfold
argument_list|(
argument|unsigned Opc
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|,
argument|unsigned *LoadRegIndex =
literal|0
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// areLoadsFromSameBasePtr - This is used by the pre-regalloc scheduler
comment|/// to determine if two loads are loading from the same base address. It
comment|/// should only return true if the base pointers are the same and the
comment|/// only differences between the two addresses are the offset. It also returns
comment|/// the offsets by reference.
name|virtual
name|bool
name|areLoadsFromSameBasePtr
argument_list|(
argument|SDNode *Load1
argument_list|,
argument|SDNode *Load2
argument_list|,
argument|int64_t&Offset1
argument_list|,
argument|int64_t&Offset2
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// shouldScheduleLoadsNear - This is a used by the pre-regalloc scheduler to
comment|/// determine (in conjunction with areLoadsFromSameBasePtr) if two loads should
comment|/// be scheduled togther. On some targets if two loads are loading from
comment|/// addresses in the same cache line, it's better if they are scheduled
comment|/// together. This function takes two integers that represent the load offsets
comment|/// from the common base address. It returns true if it decides it's desirable
comment|/// to schedule the two loads together. "NumLoads" is the number of loads that
comment|/// have already been scheduled after Load1.
name|virtual
name|bool
name|shouldScheduleLoadsNear
argument_list|(
argument|SDNode *Load1
argument_list|,
argument|SDNode *Load2
argument_list|,
argument|int64_t Offset1
argument_list|,
argument|int64_t Offset2
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// ReverseBranchCondition - Reverses the branch condition of the specified
comment|/// condition list, returning false on success and true if it cannot be
comment|/// reversed.
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// insertNoop - Insert a noop into the instruction stream at the specified
comment|/// point.
name|virtual
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
comment|/// getNoopForMachoTarget - Return the noop instruction to use for a noop.
name|virtual
name|void
name|getNoopForMachoTarget
argument_list|(
argument|MCInst&NopInst
argument_list|)
specifier|const
block|{
comment|// Default to just using 'nop' string.
block|}
comment|/// isPredicated - Returns true if the instruction is already predicated.
comment|///
name|virtual
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isUnpredicatedTerminator - Returns true if the instruction is a
comment|/// terminator instruction that has not been predicated.
name|virtual
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// PredicateInstruction - Convert the instruction into a predicated
comment|/// instruction. It returns true if the operation was successful.
name|virtual
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// SubsumesPredicate - Returns true if the first specified predicate
comment|/// subsumes the second, e.g. GE subsumes GT.
name|virtual
name|bool
name|SubsumesPredicate
argument_list|(
argument|const SmallVectorImpl<MachineOperand>&Pred1
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred2
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// DefinesPredicate - If the specified instruction defines any predicate
comment|/// or condition code register(s) used for predication, returns true as well
comment|/// as the definition predicate(s) by reference.
name|virtual
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isPredicable - Return true if the specified instruction can be predicated.
comment|/// By default, this returns true for every instruction with a
comment|/// PredicateOperand.
name|virtual
name|bool
name|isPredicable
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|MI
operator|->
name|getDesc
argument_list|()
operator|.
name|isPredicable
argument_list|()
return|;
block|}
comment|/// isSafeToMoveRegClassDefs - Return true if it's safe to move a machine
comment|/// instruction that defines the specified register class.
name|virtual
name|bool
name|isSafeToMoveRegClassDefs
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// isSchedulingBoundary - Test if the given instruction should be
comment|/// considered a scheduling boundary. This primarily includes labels and
comment|/// terminators.
name|virtual
name|bool
name|isSchedulingBoundary
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// Measure the specified inline asm to determine an approximation of its
comment|/// length.
name|virtual
name|unsigned
name|getInlineAsmLength
argument_list|(
argument|const char *Str
argument_list|,
argument|const MCAsmInfo&MAI
argument_list|)
specifier|const
block|;
comment|/// CreateTargetHazardRecognizer - Allocate and return a hazard recognizer to
comment|/// use for this target when scheduling the machine instructions before
comment|/// register allocation.
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetHazardRecognizer
argument_list|(
argument|const TargetMachine *TM
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// CreateTargetPostRAHazardRecognizer - Allocate and return a hazard
comment|/// recognizer to use for this target when scheduling the machine instructions
comment|/// after register allocation.
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
argument|const InstrItineraryData*
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// AnalyzeCompare - For a comparison instruction, return the source register
comment|/// in SrcReg and the value it compares against in CmpValue. Return true if
comment|/// the comparison instruction can be analyzed.
name|virtual
name|bool
name|AnalyzeCompare
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|int&Mask
argument_list|,
argument|int&Value
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// OptimizeCompareInstr - See if the comparison instruction can be converted
comment|/// into something more efficient. E.g., on ARM most instructions can set the
comment|/// flags register, obviating the need for a separate CMP.
name|virtual
name|bool
name|OptimizeCompareInstr
argument_list|(
argument|MachineInstr *CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|int Mask
argument_list|,
argument|int Value
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// FoldImmediate - 'Reg' is known to be defined by a move immediate
comment|/// instruction, try to fold the immediate into the use instruction.
name|virtual
name|bool
name|FoldImmediate
argument_list|(
argument|MachineInstr *UseMI
argument_list|,
argument|MachineInstr *DefMI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|MachineRegisterInfo *MRI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getNumMicroOps - Return the number of u-operations the given machine
comment|/// instruction will be decoded to on the target cpu.
name|virtual
name|unsigned
name|getNumMicroOps
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// isZeroCost - Return true for pseudo instructions that don't consume any
comment|/// machine resources in their current form. These are common cases that the
comment|/// scheduler should consider free, rather than conservatively handling them
comment|/// as instructions with no itinerary.
name|bool
name|isZeroCost
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|{
return|return
name|Opcode
operator|<=
name|TargetOpcode
operator|::
name|COPY
return|;
block|}
comment|/// getOperandLatency - Compute and return the use operand latency of a given
comment|/// pair of def and use.
comment|/// In most cases, the static scheduling itinerary was enough to determine the
comment|/// operand latency. But it may not be possible for instructions with variable
comment|/// number of defs / uses.
name|virtual
name|int
name|getOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|const MachineInstr *UseMI
argument_list|,
argument|unsigned UseIdx
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|SDNode *DefNode
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|SDNode *UseNode
argument_list|,
argument|unsigned UseIdx
argument_list|)
specifier|const
block|;
comment|/// getInstrLatency - Compute the instruction latency of a given instruction.
comment|/// If the instruction has higher cost when predicated, it's returned via
comment|/// PredCost.
name|virtual
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *MI
argument_list|,
argument|unsigned *PredCost =
literal|0
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
comment|/// isHighLatencyDef - Return true if this opcode has high latency to its
comment|/// result.
name|virtual
name|bool
name|isHighLatencyDef
argument_list|(
argument|int opc
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// hasHighOperandLatency - Compute operand latency between a def of 'Reg'
comment|/// and an use in the current loop, return true if the target considered
comment|/// it 'high'. This is used by optimization passes such as machine LICM to
comment|/// determine whether it makes sense to hoist an instruction out even in
comment|/// high register pressure situation.
name|virtual
name|bool
name|hasHighOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|,
argument|const MachineInstr *DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|const MachineInstr *UseMI
argument_list|,
argument|unsigned UseIdx
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// hasLowDefLatency - Compute operand latency of a def of 'Reg', return true
comment|/// if the target considered it 'low'.
name|virtual
name|bool
name|hasLowDefLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|)
specifier|const
block|;
comment|/// verifyInstruction - Perform target specific instruction verification.
name|virtual
name|bool
name|verifyInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|StringRef&ErrInfo
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// getExecutionDomain - Return the current execution domain and bit mask of
comment|/// possible domains for instruction.
comment|///
comment|/// Some micro-architectures have multiple execution domains, and multiple
comment|/// opcodes that perform the same operation in different domains.  For
comment|/// example, the x86 architecture provides the por, orps, and orpd
comment|/// instructions that all do the same thing.  There is a latency penalty if a
comment|/// register is written in one domain and read in another.
comment|///
comment|/// This function returns a pair (domain, mask) containing the execution
comment|/// domain of MI, and a bit mask of possible domains.  The setExecutionDomain
comment|/// function can be used to change the opcode to one of the domains in the
comment|/// bit mask.  Instructions whose execution domain can't be changed should
comment|/// return a 0 mask.
comment|///
comment|/// The execution domain numbers don't have any special meaning except domain
comment|/// 0 is used for instructions that are not associated with any interesting
comment|/// execution domain.
comment|///
name|virtual
name|std
operator|::
name|pair
operator|<
name|uint16_t
block|,
name|uint16_t
operator|>
name|getExecutionDomain
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// setExecutionDomain - Change the opcode of MI to execute in Domain.
comment|///
comment|/// The bit (1<< Domain) must be set in the mask returned from
comment|/// getExecutionDomain(MI).
comment|///
name|virtual
name|void
name|setExecutionDomain
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Domain
argument_list|)
specifier|const
block|{}
name|private
operator|:
name|int
name|CallFrameSetupOpcode
block|,
name|CallFrameDestroyOpcode
block|; }
decl_stmt|;
comment|/// TargetInstrInfoImpl - This is the default implementation of
comment|/// TargetInstrInfo, which just provides a couple of default implementations
comment|/// for various methods.  This separated out because it is implemented in
comment|/// libcodegen, not in libtarget.
name|class
name|TargetInstrInfoImpl
range|:
name|public
name|TargetInstrInfo
block|{
name|protected
operator|:
name|TargetInstrInfoImpl
argument_list|(
argument|int CallFrameSetupOpcode = -
literal|1
argument_list|,
argument|int CallFrameDestroyOpcode = -
literal|1
argument_list|)
operator|:
name|TargetInstrInfo
argument_list|(
argument|CallFrameSetupOpcode
argument_list|,
argument|CallFrameDestroyOpcode
argument_list|)
block|{}
name|public
operator|:
name|virtual
name|void
name|ReplaceTailWithBranchTo
argument_list|(
argument|MachineBasicBlock::iterator OldInst
argument_list|,
argument|MachineBasicBlock *NewDest
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI = false
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|findCommutedOpIndices
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned&SrcOpIdx1
argument_list|,
argument|unsigned&SrcOpIdx2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|canFoldMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|hasStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineMemOperand *&MMO
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|reMaterialize
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubReg
argument_list|,
argument|const MachineInstr *Orig
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineInstr
operator|*
name|duplicate
argument_list|(
argument|MachineInstr *Orig
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|produceSameValue
argument_list|(
argument|const MachineInstr *MI0
argument_list|,
argument|const MachineInstr *MI1
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isSchedulingBoundary
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|usePreRAHazardRecognizer
argument_list|()
specifier|const
block|;
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetHazardRecognizer
argument_list|(
argument|const TargetMachine*
argument_list|,
argument|const ScheduleDAG*
argument_list|)
specifier|const
block|;
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
argument|const InstrItineraryData*
argument_list|,
argument|const ScheduleDAG*
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

