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
name|MCAsmInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|LiveVariables
decl_stmt|;
name|class
name|CalleeSavedInfo
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|MachineMemOperand
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
comment|// Invariant opcodes: All instruction sets have these as their low opcodes.
enum|enum
block|{
name|PHI
init|=
literal|0
block|,
name|INLINEASM
init|=
literal|1
block|,
name|DBG_LABEL
init|=
literal|2
block|,
name|EH_LABEL
init|=
literal|3
block|,
name|GC_LABEL
init|=
literal|4
block|,
comment|/// KILL - This instruction is a noop that is used only to adjust the liveness
comment|/// of registers. This can be useful when dealing with sub-registers.
name|KILL
init|=
literal|5
block|,
comment|/// EXTRACT_SUBREG - This instruction takes two operands: a register
comment|/// that has subregisters, and a subregister index. It returns the
comment|/// extracted subregister value. This is commonly used to implement
comment|/// truncation operations on target architectures which support it.
name|EXTRACT_SUBREG
init|=
literal|6
block|,
comment|/// INSERT_SUBREG - This instruction takes three operands: a register
comment|/// that has subregisters, a register providing an insert value, and a
comment|/// subregister index. It returns the value of the first register with
comment|/// the value of the second register inserted. The first register is
comment|/// often defined by an IMPLICIT_DEF, as is commonly used to implement
comment|/// anyext operations on target architectures which support it.
name|INSERT_SUBREG
init|=
literal|7
block|,
comment|/// IMPLICIT_DEF - This is the MachineInstr-level equivalent of undef.
name|IMPLICIT_DEF
init|=
literal|8
block|,
comment|/// SUBREG_TO_REG - This instruction is similar to INSERT_SUBREG except
comment|/// that the first operand is an immediate integer constant. This constant
comment|/// is often zero, as is commonly used to implement zext operations on
comment|/// target architectures which support it, such as with x86-64 (with
comment|/// zext from i32 to i64 via implicit zero-extension).
name|SUBREG_TO_REG
init|=
literal|9
block|,
comment|/// COPY_TO_REGCLASS - This instruction is a placeholder for a plain
comment|/// register-to-register copy into a specific register class. This is only
comment|/// used between instruction selection and MachineInstr creation, before
comment|/// virtual registers have been created for all the instructions, and it's
comment|/// only needed in cases where the register classes implied by the
comment|/// instructions are insufficient. The actual MachineInstrs to perform
comment|/// the copy are emitted with the TargetInstrInfo::copyRegToReg hook.
name|COPY_TO_REGCLASS
init|=
literal|10
block|,
comment|// DEBUG_VALUE - a mapping of the llvm.dbg.value intrinsic
name|DEBUG_VALUE
init|=
literal|11
block|}
enum|;
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
comment|/// isMoveInstr - Return true if the instruction is a register to register
comment|/// move and return the source and dest operands and their sub-register
comment|/// indices by reference.
name|virtual
name|bool
name|isMoveInstr
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
name|SrcSubIdx
argument_list|,
name|unsigned
operator|&
name|DstSubIdx
argument_list|)
decl|const
block|{
return|return
name|false
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
comment|/// isIdentityCopy - Return true if the instruction is a copy (or
comment|/// extract_subreg, insert_subreg, subreg_to_reg) where the source and
comment|/// destination registers are the same.
name|bool
name|isIdentityCopy
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
block|{
name|unsigned
name|SrcReg
decl_stmt|,
name|DstReg
decl_stmt|,
name|SrcSubIdx
decl_stmt|,
name|DstSubIdx
decl_stmt|;
if|if
condition|(
name|isMoveInstr
argument_list|(
name|MI
argument_list|,
name|SrcReg
argument_list|,
name|DstReg
argument_list|,
name|SrcSubIdx
argument_list|,
name|DstSubIdx
argument_list|)
operator|&&
name|SrcReg
operator|==
name|DstReg
condition|)
return|return
name|true
return|;
if|if
condition|(
name|MI
operator|.
name|getOpcode
argument_list|()
operator|==
name|TargetInstrInfo
operator|::
name|EXTRACT_SUBREG
operator|&&
name|MI
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getReg
argument_list|()
operator|==
name|MI
operator|.
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getReg
argument_list|()
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|(
name|MI
operator|.
name|getOpcode
argument_list|()
operator|==
name|TargetInstrInfo
operator|::
name|INSERT_SUBREG
operator|||
name|MI
operator|.
name|getOpcode
argument_list|()
operator|==
name|TargetInstrInfo
operator|::
name|SUBREG_TO_REG
operator|)
operator|&&
name|MI
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getReg
argument_list|()
operator|==
name|MI
operator|.
name|getOperand
argument_list|(
literal|2
argument_list|)
operator|.
name|getReg
argument_list|()
condition|)
return|return
name|true
return|;
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
comment|/// this returns true for any instructions that loads from the
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
operator|*
name|TRI
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
comment|/// commuteInstruction - If a target has any instructions that are commutable,
comment|/// but require converting to a different instruction or making non-trivial
comment|/// changes to commute them, this method can overloaded to do this.  The
comment|/// default implementation of this method simply swaps the first two operands
comment|/// of MI and returns it.
comment|///
comment|/// If a target wants to make more aggressive changes, they can construct and
comment|/// return a new machine instruction.  If an instruction cannot commute, it
comment|/// can also return null.
comment|///
comment|/// If NewMI is true, then a new machine instruction must be created.
comment|///
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
comment|/// operand indices that would swap value. Return true if the instruction
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
comment|/// isIdentical - Return true if two instructions are identical. This differs
comment|/// from MachineInstr::isIdenticalTo() in that it does not require the
comment|/// virtual destination registers to be the same. This is used by MachineLICM
comment|/// and other MI passes to perform CSE.
name|virtual
name|bool
name|isIdentical
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|Other
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|*
name|MRI
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
comment|/// copyRegToReg - Emit instructions to copy between a pair of registers. It
comment|/// returns false if the target does not how to copy between the specified
comment|/// registers.
name|virtual
name|bool
name|copyRegToReg
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
name|SrcReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|DestRC
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|SrcRC
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::copyRegToReg!"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
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
comment|/// spillCalleeSavedRegisters - Issues instruction(s) to spill all callee
comment|/// saved registers and returns true if it isn't possible / profitable to do
comment|/// so by issuing a series of store instructions via
comment|/// storeRegToStackSlot(). Returns false otherwise.
name|virtual
name|bool
name|spillCalleeSavedRegisters
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
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|CSI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// restoreCalleeSavedRegisters - Issues instruction(s) to restore all callee
comment|/// saved registers and returns true if it isn't possible / profitable to do
comment|/// so by issuing a series of load instructions via loadRegToStackSlot().
comment|/// Returns false otherwise.
name|virtual
name|bool
name|restoreCalleeSavedRegisters
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
specifier|const
name|std
operator|::
name|vector
operator|<
name|CalleeSavedInfo
operator|>
operator|&
name|CSI
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// foldMemoryOperand - Attempt to fold a load or store of the specified stack
comment|/// slot into the specified machine instruction for the specified operand(s).
comment|/// If this is possible, a new instruction is returned with the specified
comment|/// operand folded, otherwise NULL is returned. The client is responsible for
comment|/// removing the old instruction and adding the new one in the instruction
comment|/// stream.
name|MachineInstr
modifier|*
name|foldMemoryOperand
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
decl_stmt|;
comment|/// foldMemoryOperand - Same as the previous version except it allows folding
comment|/// of any load and store from / to any address, not just from a specific
comment|/// stack slot.
name|MachineInstr
modifier|*
name|foldMemoryOperand
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
block|{
return|return
name|false
return|;
block|}
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
comment|/// GetInstSize - Returns the size of the specified Instruction.
comment|///
name|virtual
name|unsigned
name|GetInstSizeInBytes
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Target didn't implement TargetInstrInfo::GetInstSize!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/// GetFunctionSizeInBytes - Returns the size of the specified
comment|/// MachineFunction.
comment|///
name|virtual
name|unsigned
name|GetFunctionSizeInBytes
argument_list|(
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
argument|const TargetRegisterInfo *TRI
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
name|isIdentical
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|const MachineInstr *Other
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|GetFunctionSizeInBytes
argument_list|(
argument|const MachineFunction&MF
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

