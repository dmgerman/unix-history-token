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
file|"llvm/Target/TargetInstrDesc.h"
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
block|{
specifier|const
name|TargetInstrDesc
modifier|*
name|Descriptors
decl_stmt|;
comment|// Raw array to allow static init'n
name|unsigned
name|NumOpcodes
decl_stmt|;
comment|// Number of entries in the desc array
name|TargetInstrInfo
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetInstrInfo
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|TargetInstrInfo
argument_list|(
argument|const TargetInstrDesc *desc
argument_list|,
argument|unsigned NumOpcodes
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|TargetInstrInfo
argument_list|()
expr_stmt|;
name|unsigned
name|getNumOpcodes
argument_list|()
specifier|const
block|{
return|return
name|NumOpcodes
return|;
block|}
comment|/// get - Return the machine instruction descriptor that corresponds to the
comment|/// specified instruction opcode.
comment|///
specifier|const
name|TargetInstrDesc
modifier|&
name|get
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Opcode
operator|<
name|NumOpcodes
operator|&&
literal|"Invalid opcode!"
argument_list|)
expr_stmt|;
return|return
name|Descriptors
index|[
name|Opcode
index|]
return|;
block|}
comment|/// isTriviallyReMaterializable - Return true if the instruction is trivially
comment|/// rematerializable, meaning it has no side effects and requires no operands
comment|/// that aren't always available.
name|bool
name|isTriviallyReMaterializable
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|AliasAnalysis
operator|*
name|AA
operator|=
literal|0
argument_list|)
decl|const
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
label|:
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|private
label|:
comment|/// isReallyTriviallyReMaterializableGeneric - For instructions with opcodes
comment|/// for which the M_REMATERIALIZABLE flag is set and the target hook
comment|/// isReallyTriviallyReMaterializable returns false, this function does
comment|/// target-independent tests to determine if the instruction is really
comment|/// trivially rematerializable.
name|bool
name|isReallyTriviallyReMaterializableGeneric
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
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
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
name|unsigned
operator|&
name|SrcReg
argument_list|,
name|unsigned
operator|&
name|DstReg
argument_list|,
name|unsigned
operator|&
name|SubIdx
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MachineMemOperand
operator|*
operator|&
name|MMO
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MachineMemOperand
operator|*
operator|&
name|MMO
argument_list|,
name|int
operator|&
name|FrameIndex
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|unsigned
name|DestReg
argument_list|,
name|unsigned
name|SubIdx
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|Orig
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// scheduleTwoAddrSource - Schedule the copy / re-mat of the source of the
comment|/// two-addrss instruction inserted by two-address pass.
name|virtual
name|void
name|scheduleTwoAddrSource
argument_list|(
name|MachineInstr
operator|*
name|SrcMI
argument_list|,
name|MachineInstr
operator|*
name|UseMI
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
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
modifier|*
name|duplicate
argument_list|(
name|MachineInstr
operator|*
name|Orig
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
modifier|*
name|convertToThreeAddress
argument_list|(
name|MachineFunction
operator|::
name|iterator
operator|&
name|MFI
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|MBBI
argument_list|,
name|LiveVariables
operator|*
name|LV
argument_list|)
decl|const
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
modifier|*
name|commuteInstruction
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|bool
name|NewMI
operator|=
name|false
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// findCommutedOpIndices - If specified MI is commutable, return the two
comment|/// operand indices that would swap value. Return false if the instruction
comment|/// is not in a form which this routine understands.
name|virtual
name|bool
name|findCommutedOpIndices
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
operator|&
name|SrcOpIdx1
argument_list|,
name|unsigned
operator|&
name|SrcOpIdx2
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// produceSameValue - Return true if two machine instructions would produce
comment|/// identical values. By default, this is only true when the two instructions
comment|/// are deemed identical except for defs. If this function is called when the
comment|/// IR is still in SSA form, the caller can pass the MachineRegisterInfo for
comment|/// aggressive checks.
name|virtual
name|bool
name|produceSameValue
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI0
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI1
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|*
operator|&
name|TBB
argument_list|,
name|MachineBasicBlock
operator|*
operator|&
name|FBB
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Cond
argument_list|,
name|bool
name|AllowModify
operator|=
name|false
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::RemoveBranch!"
argument_list|)
expr_stmt|;
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|*
name|TBB
argument_list|,
name|MachineBasicBlock
operator|*
name|FBB
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Cond
argument_list|,
name|DebugLoc
name|DL
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::InsertBranch!"
argument_list|)
expr_stmt|;
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
name|MachineBasicBlock
operator|::
name|iterator
name|Tail
argument_list|,
name|MachineBasicBlock
operator|*
name|NewDest
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// isLegalToSplitMBBAt - Return true if it's legal to split the given basic
comment|/// block at the specified instruction (i.e. instruction would be the start
comment|/// of a new basic block).
name|virtual
name|bool
name|isLegalToSplitMBBAt
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MBBI
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|unsigned
name|NumCyles
argument_list|,
name|unsigned
name|ExtraPredCycles
argument_list|,
name|float
name|Probability
argument_list|,
name|float
name|Confidence
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|TMBB
argument_list|,
name|unsigned
name|NumTCycles
argument_list|,
name|unsigned
name|ExtraTCycles
argument_list|,
name|MachineBasicBlock
operator|&
name|FMBB
argument_list|,
name|unsigned
name|NumFCycles
argument_list|,
name|unsigned
name|ExtraFCycles
argument_list|,
name|float
name|Probability
argument_list|,
name|float
name|Confidence
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|unsigned
name|NumCyles
argument_list|,
name|float
name|Probability
argument_list|,
name|float
name|Confidence
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|DebugLoc
name|DL
argument_list|,
name|unsigned
name|DestReg
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|bool
name|KillSrc
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::copyPhysReg!"
argument_list|)
expr_stmt|;
block|}
comment|/// storeRegToStackSlot - Store the specified register of the given register
comment|/// class to the specified stack frame index. The store instruction is to be
comment|/// added to the given machine basic block before the specified machine
comment|/// instruction. If isKill is true, the register operand is the last use and
comment|/// must be marked kill.
name|virtual
name|void
name|storeRegToStackSlot
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|bool
name|isKill
argument_list|,
name|int
name|FrameIndex
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::storeRegToStackSlot!"
argument_list|)
expr_stmt|;
block|}
comment|/// loadRegFromStackSlot - Load the specified register of the given register
comment|/// class from the specified stack frame index. The load instruction is to be
comment|/// added to the given machine basic block before the specified machine
comment|/// instruction.
name|virtual
name|void
name|loadRegFromStackSlot
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|unsigned
name|DestReg
argument_list|,
name|int
name|FrameIndex
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::loadRegFromStackSlot!"
argument_list|)
expr_stmt|;
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
modifier|*
name|emitFrameIndexDebugValue
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|int
name|FrameIx
argument_list|,
name|uint64_t
name|Offset
argument_list|,
specifier|const
name|MDNode
operator|*
name|MDPtr
argument_list|,
name|DebugLoc
name|dl
argument_list|)
decl|const
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
modifier|*
name|foldMemoryOperand
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|,
name|int
name|FrameIndex
argument_list|)
decl|const
decl_stmt|;
comment|/// foldMemoryOperand - Same as the previous version except it allows folding
comment|/// of any load and store from / to any address, not just from a specific
comment|/// stack slot.
name|MachineInstr
modifier|*
name|foldMemoryOperand
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|,
name|MachineInstr
operator|*
name|LoadMI
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|/// foldMemoryOperandImpl - Target-dependent implementation for
comment|/// foldMemoryOperand. Target-independent code in foldMemoryOperand will
comment|/// take care of adding a MachineMemOperand to the newly created instruction.
name|virtual
name|MachineInstr
modifier|*
name|foldMemoryOperandImpl
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|,
name|int
name|FrameIndex
argument_list|)
decl|const
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
modifier|*
name|foldMemoryOperandImpl
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|,
name|MachineInstr
operator|*
name|LoadMI
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
name|public
label|:
comment|/// canFoldMemoryOperand - Returns true for the specified load / store if
comment|/// folding is possible.
name|virtual
name|bool
name|canFoldMemoryOperand
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// unfoldMemoryOperand - Separate a single instruction which folded a load or
comment|/// a store or a load and a store into two or more instruction. If this is
comment|/// possible, returns true as well as the new instructions by reference.
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|bool
name|UnfoldLoad
argument_list|,
name|bool
name|UnfoldStore
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|&
name|NewMIs
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDNode
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SDNode
operator|*
operator|>
operator|&
name|NewNodes
argument_list|)
decl|const
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
name|unsigned
name|Opc
argument_list|,
name|bool
name|UnfoldLoad
argument_list|,
name|bool
name|UnfoldStore
argument_list|,
name|unsigned
operator|*
name|LoadRegIndex
operator|=
literal|0
argument_list|)
decl|const
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
name|SDNode
operator|*
name|Load1
argument_list|,
name|SDNode
operator|*
name|Load2
argument_list|,
name|int64_t
operator|&
name|Offset1
argument_list|,
name|int64_t
operator|&
name|Offset2
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// shouldScheduleLoadsNear - This is a used by the pre-regalloc scheduler to
comment|/// determine (in conjuction with areLoadsFromSameBasePtr) if two loads should
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
name|SDNode
operator|*
name|Load1
argument_list|,
name|SDNode
operator|*
name|Load2
argument_list|,
name|int64_t
name|Offset1
argument_list|,
name|int64_t
name|Offset2
argument_list|,
name|unsigned
name|NumLoads
argument_list|)
decl|const
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
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Cond
argument_list|)
decl|const
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
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// getNoopForMachoTarget - Return the noop instruction to use for a noop.
name|virtual
name|void
name|getNoopForMachoTarget
argument_list|(
name|MCInst
operator|&
name|NopInst
argument_list|)
decl|const
block|{
comment|// Default to just using 'nop' string.
block|}
comment|/// isPredicated - Returns true if the instruction is already predicated.
comment|///
name|virtual
name|bool
name|isPredicated
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// PredicateInstruction - Convert the instruction into a predicated
comment|/// instruction. It returns true if the operation was successful.
name|virtual
name|bool
name|PredicateInstruction
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Pred
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// SubsumesPredicate - Returns true if the first specified predicate
comment|/// subsumes the second, e.g. GE subsumes GT.
name|virtual
name|bool
name|SubsumesPredicate
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Pred1
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|MachineOperand
operator|>
operator|&
name|Pred2
argument_list|)
decl|const
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
name|MachineInstr
operator|*
name|MI
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MachineOperand
operator|>
operator|&
name|Pred
argument_list|)
decl|const
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
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
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
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Measure the specified inline asm to determine an approximation of its
comment|/// length.
name|virtual
name|unsigned
name|getInlineAsmLength
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|,
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|)
decl|const
decl_stmt|;
comment|/// CreateTargetHazardRecognizer - Allocate and return a hazard recognizer to
comment|/// use for this target when scheduling the machine instructions before
comment|/// register allocation.
name|virtual
name|ScheduleHazardRecognizer
modifier|*
name|CreateTargetHazardRecognizer
argument_list|(
specifier|const
name|TargetMachine
operator|*
name|TM
argument_list|,
specifier|const
name|ScheduleDAG
operator|*
name|DAG
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// CreateTargetPostRAHazardRecognizer - Allocate and return a hazard
comment|/// recognizer to use for this target when scheduling the machine instructions
comment|/// after register allocation.
name|virtual
name|ScheduleHazardRecognizer
modifier|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
argument_list|,
specifier|const
name|ScheduleDAG
operator|*
name|DAG
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// AnalyzeCompare - For a comparison instruction, return the source register
comment|/// in SrcReg and the value it compares against in CmpValue. Return true if
comment|/// the comparison instruction can be analyzed.
name|virtual
name|bool
name|AnalyzeCompare
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
operator|&
name|SrcReg
argument_list|,
name|int
operator|&
name|Mask
argument_list|,
name|int
operator|&
name|Value
argument_list|)
decl|const
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
name|MachineInstr
operator|*
name|CmpInstr
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|int
name|Mask
argument_list|,
name|int
name|Value
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|)
decl|const
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
name|MachineInstr
operator|*
name|UseMI
argument_list|,
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|)
decl|const
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
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// isZeroCost - Return true for pseudo instructions that don't consume any
comment|/// machine resources in their current form. These are common cases that the
comment|/// scheduler should consider free, rather than conservatively handling them
comment|/// as instructions with no itinerary.
name|bool
name|isZeroCost
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
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
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|UseMI
argument_list|,
name|unsigned
name|UseIdx
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|int
name|getOperandLatency
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
name|SDNode
operator|*
name|DefNode
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
name|SDNode
operator|*
name|UseNode
argument_list|,
name|unsigned
name|UseIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// getInstrLatency - Compute the instruction latency of a given instruction.
comment|/// If the instruction has higher cost when predicated, it's returned via
comment|/// PredCost.
name|virtual
name|int
name|getInstrLatency
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|unsigned
operator|*
name|PredCost
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|int
name|getInstrLatency
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
name|SDNode
operator|*
name|Node
argument_list|)
decl|const
decl_stmt|;
comment|/// hasHighOperandLatency - Compute operand latency between a def of 'Reg'
comment|/// and an use in the current loop, return true if the target considered
comment|/// it 'high'. This is used by optimization passes such as machine LICM to
comment|/// determine whether it makes sense to hoist an instruction out even in
comment|/// high register pressure situation.
name|virtual
name|bool
name|hasHighOperandLatency
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefIdx
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|UseMI
argument_list|,
name|unsigned
name|UseIdx
argument_list|)
decl|const
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
specifier|const
name|InstrItineraryData
operator|*
name|ItinData
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|DefMI
argument_list|,
name|unsigned
name|DefIdx
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
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
argument|const TargetInstrDesc *desc
argument_list|,
argument|unsigned NumOpcodes
argument_list|)
operator|:
name|TargetInstrInfo
argument_list|(
argument|desc
argument_list|,
argument|NumOpcodes
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

