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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineCombinerPattern.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BranchProbability.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
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
struct_decl|struct
name|MCSchedModel
struct_decl|;
name|class
name|MCSymbolRefExpr
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
name|TargetSubtargetInfo
decl_stmt|;
name|class
name|TargetSchedModel
decl_stmt|;
name|class
name|DFAPacketizer
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
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetInstrInfo
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
name|TargetInstrInfo
argument_list|(
argument|unsigned CFSetupOpcode = ~
literal|0u
argument_list|,
argument|unsigned CFDestroyOpcode = ~
literal|0u
argument_list|,
argument|unsigned CatchRetOpcode = ~
literal|0u
argument_list|)
operator|:
name|CallFrameSetupOpcode
argument_list|(
name|CFSetupOpcode
argument_list|)
block|,
name|CallFrameDestroyOpcode
argument_list|(
name|CFDestroyOpcode
argument_list|)
block|,
name|CatchRetOpcode
argument_list|(
argument|CatchRetOpcode
argument_list|)
block|{}
name|virtual
operator|~
name|TargetInstrInfo
argument_list|()
block|;
specifier|static
name|bool
name|isGenericOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
block|{
return|return
name|Opc
operator|<=
name|TargetOpcode
operator|::
name|GENERIC_OP_END
return|;
block|}
comment|/// Given a machine instruction descriptor, returns the register
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
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Return true if the instruction is trivially rematerializable, meaning it
comment|/// has no side effects and requires no operands that aren't always available.
comment|/// This means the only allowed uses are constants and unallocatable physical
comment|/// registers so that the instructions result is independent of the place
comment|/// in the function.
name|bool
name|isTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA = nullptr
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
comment|/// For instructions with opcodes for which the M_REMATERIALIZABLE flag is
comment|/// set, this hook lets the target specify whether the instruction is actually
comment|/// trivially rematerializable, taking into consideration its operands. This
comment|/// predicate must return false if the instruction has any side effects other
comment|/// than producing a value, or if it requres any address registers that are
comment|/// not always available.
comment|/// Requirements must be check as stated in isTriviallyReMaterializable() .
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
comment|/// This method commutes the operands of the given machine instruction MI.
comment|/// The operands to be commuted are specified by their indices OpIdx1 and
comment|/// OpIdx2.
comment|///
comment|/// If a target has any instructions that are commutable but require
comment|/// converting to different instructions or making non-trivial changes
comment|/// to commute them, this method can be overloaded to do that.
comment|/// The default implementation simply swaps the commutable operands.
comment|///
comment|/// If NewMI is false, MI is modified in place and returned; otherwise, a
comment|/// new machine instruction is created and returned.
comment|///
comment|/// Do not call this method for a non-commutable instruction.
comment|/// Even though the instruction is commutable, the method may still
comment|/// fail to commute the operands, null pointer is returned in such cases.
name|virtual
name|MachineInstr
operator|*
name|commuteInstructionImpl
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI
argument_list|,
argument|unsigned OpIdx1
argument_list|,
argument|unsigned OpIdx2
argument_list|)
specifier|const
block|;
comment|/// Assigns the (CommutableOpIdx1, CommutableOpIdx2) pair of commutable
comment|/// operand indices to (ResultIdx1, ResultIdx2).
comment|/// One or both input values of the pair: (ResultIdx1, ResultIdx2) may be
comment|/// predefined to some indices or be undefined (designated by the special
comment|/// value 'CommuteAnyOperandIndex').
comment|/// The predefined result indices cannot be re-defined.
comment|/// The function returns true iff after the result pair redefinition
comment|/// the fixed result pair is equal to or equivalent to the source pair of
comment|/// indices: (CommutableOpIdx1, CommutableOpIdx2). It is assumed here that
comment|/// the pairs (x,y) and (y,x) are equivalent.
specifier|static
name|bool
name|fixCommutedOpIndices
argument_list|(
argument|unsigned&ResultIdx1
argument_list|,
argument|unsigned&ResultIdx2
argument_list|,
argument|unsigned CommutableOpIdx1
argument_list|,
argument|unsigned CommutableOpIdx2
argument_list|)
block|;
name|private
operator|:
comment|/// For instructions with opcodes for which the M_REMATERIALIZABLE flag is
comment|/// set and the target hook isReallyTriviallyReMaterializable returns false,
comment|/// this function does target-independent tests to determine if the
comment|/// instruction is really trivially rematerializable.
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
comment|/// These methods return the opcode of the frame setup/destroy instructions
comment|/// if they exist (-1 otherwise).  Some targets use pseudo instructions in
comment|/// order to abstract away the difference between operating with a frame
comment|/// pointer and operating without, through the use of these two instructions.
comment|///
name|unsigned
name|getCallFrameSetupOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameSetupOpcode
return|;
block|}
name|unsigned
name|getCallFrameDestroyOpcode
argument_list|()
specifier|const
block|{
return|return
name|CallFrameDestroyOpcode
return|;
block|}
name|unsigned
name|getCatchReturnOpcode
argument_list|()
specifier|const
block|{
return|return
name|CatchRetOpcode
return|;
block|}
comment|/// Returns the actual stack pointer adjustment made by an instruction
comment|/// as part of a call sequence. By default, only call frame setup/destroy
comment|/// instructions adjust the stack, but targets may want to override this
comment|/// to enable more fine-grained adjustment, or adjust by a different value.
name|virtual
name|int
name|getSPAdjust
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Return true if the instruction is a "coalescable" extension instruction.
comment|/// That is, it's like a copy where it's legal for the source to overlap the
comment|/// destination. e.g. X86::MOVSX64rr32. If this returns true, then it's
comment|/// expected the pre-extension value is available as a subreg of the result
comment|/// register. This also returns the sub-register index in SubIdx.
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
comment|/// If the specified machine instruction is a direct
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
comment|/// Check for post-frame ptr elimination stack locations as well.
comment|/// This uses a heuristic so it isn't reliable for correctness.
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
comment|/// If the specified machine instruction has a load from a stack slot,
comment|/// return true along with the FrameIndex of the loaded stack slot and the
comment|/// machine mem operand containing the reference.
comment|/// If not, return false.  Unlike isLoadFromStackSlot, this returns true for
comment|/// any instructions that loads from the stack.  This is just a hint, as some
comment|/// cases may be missed.
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
comment|/// If the specified machine instruction is a direct
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
comment|/// Check for post-frame ptr elimination stack locations as well.
comment|/// This uses a heuristic, so it isn't reliable for correctness.
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
comment|/// If the specified machine instruction has a store to a stack slot,
comment|/// return true along with the FrameIndex of the loaded stack slot and the
comment|/// machine mem operand containing the reference.
comment|/// If not, return false.  Unlike isStoreToStackSlot,
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
block|;
comment|/// Return true if the specified machine instruction
comment|/// is a copy of one stack slot to another and has no other effect.
comment|/// Provide the identity of the two frame indices.
name|virtual
name|bool
name|isStackSlotCopy
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&DestFrameIndex
argument_list|,
argument|int&SrcFrameIndex
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Compute the size in bytes and offset within a stack slot of a spilled
comment|/// register or subregister.
comment|///
comment|/// \param [out] Size in bytes of the spilled value.
comment|/// \param [out] Offset in bytes within the stack slot.
comment|/// \returns true if both Size and Offset are successfully computed.
comment|///
comment|/// Not all subregisters have computable spill slots. For example,
comment|/// subregisters registers may not be byte-sized, and a pair of discontiguous
comment|/// subregisters has no single offset.
comment|///
comment|/// Targets with nontrivial bigendian implementations may need to override
comment|/// this, particularly to support spilled vector registers.
name|virtual
name|bool
name|getStackSlotRange
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|unsigned&Size
argument_list|,
argument|unsigned&Offset
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// Return true if the instruction is as cheap as a move instruction.
comment|///
comment|/// Targets for different archs need to override this, and different
comment|/// micro-architectures can also be finely tuned inside.
name|virtual
name|bool
name|isAsCheapAsAMove
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|MI
operator|->
name|isAsCheapAsAMove
argument_list|()
return|;
block|}
comment|/// Re-issue the specified 'original' instruction at the
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
block|;
comment|/// Create a duplicate of the Orig instruction in MF. This is like
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
block|;
comment|/// This method must be implemented by targets that
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
name|nullptr
return|;
block|}
comment|// This constant can be used as an input value of operand index passed to
comment|// the method findCommutedOpIndices() to tell the method that the
comment|// corresponding operand index is not pre-defined and that the method
comment|// can pick any commutable operand.
specifier|static
specifier|const
name|unsigned
name|CommuteAnyOperandIndex
operator|=
operator|~
literal|0U
block|;
comment|/// This method commutes the operands of the given machine instruction MI.
comment|///
comment|/// The operands to be commuted are specified by their indices OpIdx1 and
comment|/// OpIdx2. OpIdx1 and OpIdx2 arguments may be set to a special value
comment|/// 'CommuteAnyOperandIndex', which means that the method is free to choose
comment|/// any arbitrarily chosen commutable operand. If both arguments are set to
comment|/// 'CommuteAnyOperandIndex' then the method looks for 2 different commutable
comment|/// operands; then commutes them if such operands could be found.
comment|///
comment|/// If NewMI is false, MI is modified in place and returned; otherwise, a
comment|/// new machine instruction is created and returned.
comment|///
comment|/// Do not call this method for a non-commutable instruction or
comment|/// for non-commuable operands.
comment|/// Even though the instruction is commutable, the method may still
comment|/// fail to commute the operands, null pointer is returned in such cases.
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI = false
argument_list|,
argument|unsigned OpIdx1 = CommuteAnyOperandIndex
argument_list|,
argument|unsigned OpIdx2 = CommuteAnyOperandIndex
argument_list|)
specifier|const
block|;
comment|/// Returns true iff the routine could find two commutable operands in the
comment|/// given machine instruction.
comment|/// The 'SrcOpIdx1' and 'SrcOpIdx2' are INPUT and OUTPUT arguments.
comment|/// If any of the INPUT values is set to the special value
comment|/// 'CommuteAnyOperandIndex' then the method arbitrarily picks a commutable
comment|/// operand, then returns its index in the corresponding argument.
comment|/// If both of INPUT values are set to 'CommuteAnyOperandIndex' then method
comment|/// looks for 2 commutable operands.
comment|/// If INPUT values refer to some operands of MI, then the method simply
comment|/// returns true if the corresponding operands are commutable and returns
comment|/// false otherwise.
comment|///
comment|/// For example, calling this method this way:
comment|///     unsigned Op1 = 1, Op2 = CommuteAnyOperandIndex;
comment|///     findCommutedOpIndices(MI, Op1, Op2);
comment|/// can be interpreted as a query asking to find an operand that would be
comment|/// commutable with the operand#1.
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
comment|/// A pair composed of a register and a sub-register index.
comment|/// Used to give some type checking when modeling Reg:SubReg.
block|struct
name|RegSubRegPair
block|{
name|unsigned
name|Reg
block|;
name|unsigned
name|SubReg
block|;
name|RegSubRegPair
argument_list|(
argument|unsigned Reg =
literal|0
argument_list|,
argument|unsigned SubReg =
literal|0
argument_list|)
operator|:
name|Reg
argument_list|(
name|Reg
argument_list|)
block|,
name|SubReg
argument_list|(
argument|SubReg
argument_list|)
block|{}
block|}
block|;
comment|/// A pair composed of a pair of a register and a sub-register index,
comment|/// and another sub-register index.
comment|/// Used to give some type checking when modeling Reg:SubReg1, SubReg2.
block|struct
name|RegSubRegPairAndIdx
operator|:
name|RegSubRegPair
block|{
name|unsigned
name|SubIdx
block|;
name|RegSubRegPairAndIdx
argument_list|(
argument|unsigned Reg =
literal|0
argument_list|,
argument|unsigned SubReg =
literal|0
argument_list|,
argument|unsigned SubIdx =
literal|0
argument_list|)
operator|:
name|RegSubRegPair
argument_list|(
name|Reg
argument_list|,
name|SubReg
argument_list|)
block|,
name|SubIdx
argument_list|(
argument|SubIdx
argument_list|)
block|{}
block|}
block|;
comment|/// Build the equivalent inputs of a REG_SEQUENCE for the given \p MI
comment|/// and \p DefIdx.
comment|/// \p [out] InputRegs of the equivalent REG_SEQUENCE. Each element of
comment|/// the list is modeled as<Reg:SubReg, SubIdx>.
comment|/// E.g., REG_SEQUENCE vreg1:sub1, sub0, vreg2, sub1 would produce
comment|/// two elements:
comment|/// - vreg1:sub1, sub0
comment|/// - vreg2<:0>, sub1
comment|///
comment|/// \returns true if it is possible to build such an input sequence
comment|/// with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isRegSequence() or MI.isRegSequenceLike().
comment|///
comment|/// \note The generic implementation does not provide any support for
comment|/// MI.isRegSequenceLike(). In other words, one has to override
comment|/// getRegSequenceLikeInputs for target specific instructions.
name|bool
name|getRegSequenceInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|SmallVectorImpl<RegSubRegPairAndIdx>&InputRegs
argument_list|)
specifier|const
block|;
comment|/// Build the equivalent inputs of a EXTRACT_SUBREG for the given \p MI
comment|/// and \p DefIdx.
comment|/// \p [out] InputReg of the equivalent EXTRACT_SUBREG.
comment|/// E.g., EXTRACT_SUBREG vreg1:sub1, sub0, sub1 would produce:
comment|/// - vreg1:sub1, sub0
comment|///
comment|/// \returns true if it is possible to build such an input sequence
comment|/// with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isExtractSubreg() or MI.isExtractSubregLike().
comment|///
comment|/// \note The generic implementation does not provide any support for
comment|/// MI.isExtractSubregLike(). In other words, one has to override
comment|/// getExtractSubregLikeInputs for target specific instructions.
name|bool
name|getExtractSubregInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|RegSubRegPairAndIdx&InputReg
argument_list|)
specifier|const
block|;
comment|/// Build the equivalent inputs of a INSERT_SUBREG for the given \p MI
comment|/// and \p DefIdx.
comment|/// \p [out] BaseReg and \p [out] InsertedReg contain
comment|/// the equivalent inputs of INSERT_SUBREG.
comment|/// E.g., INSERT_SUBREG vreg0:sub0, vreg1:sub1, sub3 would produce:
comment|/// - BaseReg: vreg0:sub0
comment|/// - InsertedReg: vreg1:sub1, sub3
comment|///
comment|/// \returns true if it is possible to build such an input sequence
comment|/// with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isInsertSubreg() or MI.isInsertSubregLike().
comment|///
comment|/// \note The generic implementation does not provide any support for
comment|/// MI.isInsertSubregLike(). In other words, one has to override
comment|/// getInsertSubregLikeInputs for target specific instructions.
name|bool
name|getInsertSubregInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|RegSubRegPair&BaseReg
argument_list|,
argument|RegSubRegPairAndIdx&InsertedReg
argument_list|)
specifier|const
block|;
comment|/// Return true if two machine instructions would produce identical values.
comment|/// By default, this is only true when the two instructions
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
argument|const MachineRegisterInfo *MRI = nullptr
argument_list|)
specifier|const
block|;
comment|/// Analyze the branching code at the end of MBB, returning
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
comment|/// Represents a predicate at the MachineFunction level.  The control flow a
comment|/// MachineBranchPredicate represents is:
comment|///
comment|///  Reg<def>= LHS `Predicate` RHS         == ConditionDef
comment|///  if Reg then goto TrueDest else goto FalseDest
comment|///
expr|struct
name|MachineBranchPredicate
block|{     enum
name|ComparePredicate
block|{
name|PRED_EQ
block|,
comment|// True if two values are equal
name|PRED_NE
block|,
comment|// True if two values are not equal
name|PRED_INVALID
comment|// Sentinel value
block|}
block|;
name|ComparePredicate
name|Predicate
block|;
name|MachineOperand
name|LHS
block|;
name|MachineOperand
name|RHS
block|;
name|MachineBasicBlock
operator|*
name|TrueDest
block|;
name|MachineBasicBlock
operator|*
name|FalseDest
block|;
name|MachineInstr
operator|*
name|ConditionDef
block|;
comment|/// SingleUseCondition is true if ConditionDef is dead except for the
comment|/// branch(es) at the end of the basic block.
comment|///
name|bool
name|SingleUseCondition
block|;
name|explicit
name|MachineBranchPredicate
argument_list|()
operator|:
name|Predicate
argument_list|(
name|PRED_INVALID
argument_list|)
block|,
name|LHS
argument_list|(
name|MachineOperand
operator|::
name|CreateImm
argument_list|(
literal|0
argument_list|)
argument_list|)
block|,
name|RHS
argument_list|(
name|MachineOperand
operator|::
name|CreateImm
argument_list|(
literal|0
argument_list|)
argument_list|)
block|,
name|TrueDest
argument_list|(
name|nullptr
argument_list|)
block|,
name|FalseDest
argument_list|(
name|nullptr
argument_list|)
block|,
name|ConditionDef
argument_list|(
name|nullptr
argument_list|)
block|,
name|SingleUseCondition
argument_list|(
argument|false
argument_list|)
block|{     }
block|}
block|;
comment|/// Analyze the branching code at the end of MBB and parse it into the
comment|/// MachineBranchPredicate structure if possible.  Returns false on success
comment|/// and true on failure.
comment|///
comment|/// If AllowModify is true, then this routine is allowed to modify the basic
comment|/// block (e.g. delete instructions after the unconditional branch).
comment|///
name|virtual
name|bool
name|AnalyzeBranchPredicate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBranchPredicate&MBP
argument_list|,
argument|bool AllowModify = false
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Remove the branching code at the end of the specific MBB.
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
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement TargetInstrInfo::RemoveBranch!"
argument_list|)
block|;   }
comment|/// Insert branch code into the end of the specified MachineBasicBlock.
comment|/// The operands to this method are the same as those
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
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement TargetInstrInfo::InsertBranch!"
argument_list|)
block|;   }
comment|/// Delete the instruction OldInst and everything after it, replacing it with
comment|/// an unconditional branch to NewDest. This is used by the tail merging pass.
name|virtual
name|void
name|ReplaceTailWithBranchTo
argument_list|(
argument|MachineBasicBlock::iterator Tail
argument_list|,
argument|MachineBasicBlock *NewDest
argument_list|)
specifier|const
block|;
comment|/// Get an instruction that performs an unconditional branch to the given
comment|/// symbol.
name|virtual
name|void
name|getUnconditionalBranch
argument_list|(
argument|MCInst&MI
argument_list|,
argument|const MCSymbolRefExpr *BranchTarget
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement "
literal|"TargetInstrInfo::getUnconditionalBranch!"
argument_list|)
block|;   }
comment|/// Get a machine trap instruction.
name|virtual
name|void
name|getTrap
argument_list|(
argument|MCInst&MI
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement TargetInstrInfo::getTrap!"
argument_list|)
block|;   }
comment|/// Get a number of bytes that suffices to hold
comment|/// either the instruction returned by getUnconditionalBranch or the
comment|/// instruction returned by getTrap. This only makes sense because
comment|/// getUnconditionalBranch returns a single, specific instruction. This
comment|/// information is needed by the jumptable construction code, since it must
comment|/// decide how many bytes to use for a jumptable entry so it can generate the
comment|/// right mask.
comment|///
comment|/// Note that if the jumptable instruction requires alignment, then that
comment|/// alignment should be factored into this required bound so that the
comment|/// resulting bound gives the right alignment for the instruction.
name|virtual
name|unsigned
name|getJumpInstrTableEntryBound
argument_list|()
specifier|const
block|{
comment|// This method gets called by LLVMTargetMachine always, so it can't fail
comment|// just because there happens to be no implementation for this target.
comment|// Any code that tries to use a jumptable annotation without defining
comment|// getUnconditionalBranch on the appropriate Target will fail anyway, and
comment|// the value returned here won't matter in that case.
return|return
literal|0
return|;
block|}
comment|/// Return true if it's legal to split the given basic
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
comment|/// Return true if it's profitable to predicate
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
argument|unsigned NumCycles
argument_list|,
argument|unsigned ExtraPredCycles
argument_list|,
argument|BranchProbability Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Second variant of isProfitableToIfCvt. This one
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
argument|BranchProbability Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it's profitable for if-converter to duplicate instructions
comment|/// of specified accumulated instruction latencies in the specified MBB to
comment|/// enable if-conversion.
comment|/// The probability of the instructions being executed is given by
comment|/// Probability, and Confidence is a measure of our confidence that it
comment|/// will be properly predicted.
name|virtual
name|bool
name|isProfitableToDupForIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCycles
argument_list|,
argument|BranchProbability Probability
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it's profitable to unpredicate
comment|/// one side of a 'diamond', i.e. two sides of if-else predicated on mutually
comment|/// exclusive predicates.
comment|/// e.g.
comment|///   subeq  r0, r1, #1
comment|///   addne  r0, r1, #1
comment|/// =>
comment|///   sub    r0, r1, #1
comment|///   addne  r0, r1, #1
comment|///
comment|/// This may be profitable is conditional instructions are always executed.
name|virtual
name|bool
name|isProfitableToUnpredicate
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true if it is possible to insert a select
comment|/// instruction that chooses between TrueReg and FalseReg based on the
comment|/// condition code in Cond.
comment|///
comment|/// When successful, also return the latency in cycles from TrueReg,
comment|/// FalseReg, and Cond to the destination register. In most cases, a select
comment|/// instruction will be 1 cycle, so CondCycles = TrueCycles = FalseCycles = 1
comment|///
comment|/// Some x86 implementations have 2-cycle cmov instructions.
comment|///
comment|/// @param MBB         Block where select instruction would be inserted.
comment|/// @param Cond        Condition returned by AnalyzeBranch.
comment|/// @param TrueReg     Virtual register to select when Cond is true.
comment|/// @param FalseReg    Virtual register to select when Cond is false.
comment|/// @param CondCycles  Latency from Cond+Branch to select output.
comment|/// @param TrueCycles  Latency from TrueReg to select output.
comment|/// @param FalseCycles Latency from FalseReg to select output.
name|virtual
name|bool
name|canInsertSelect
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|unsigned TrueReg
argument_list|,
argument|unsigned FalseReg
argument_list|,
argument|int&CondCycles
argument_list|,
argument|int&TrueCycles
argument_list|,
argument|int&FalseCycles
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Insert a select instruction into MBB before I that will copy TrueReg to
comment|/// DstReg when Cond is true, and FalseReg to DstReg when Cond is false.
comment|///
comment|/// This function can only be called after canInsertSelect() returned true.
comment|/// The condition in Cond comes from AnalyzeBranch, and it can be assumed
comment|/// that the same flags or registers required by Cond are available at the
comment|/// insertion point.
comment|///
comment|/// @param MBB      Block where select instruction should be inserted.
comment|/// @param I        Insertion point.
comment|/// @param DL       Source location for debugging.
comment|/// @param DstReg   Virtual register to be defined by select instruction.
comment|/// @param Cond     Condition as computed by AnalyzeBranch.
comment|/// @param TrueReg  Virtual register to copy when Cond is true.
comment|/// @param FalseReg Virtual register to copy when Cons is false.
name|virtual
name|void
name|insertSelect
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|unsigned TrueReg
argument_list|,
argument|unsigned FalseReg
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement TargetInstrInfo::insertSelect!"
argument_list|)
block|;   }
comment|/// Analyze the given select instruction, returning true if
comment|/// it cannot be understood. It is assumed that MI->isSelect() is true.
comment|///
comment|/// When successful, return the controlling condition and the operands that
comment|/// determine the true and false result values.
comment|///
comment|///   Result = SELECT Cond, TrueOp, FalseOp
comment|///
comment|/// Some targets can optimize select instructions, for example by predicating
comment|/// the instruction defining one of the operands. Such targets should set
comment|/// Optimizable.
comment|///
comment|/// @param         MI Select instruction to analyze.
comment|/// @param Cond    Condition controlling the select.
comment|/// @param TrueOp  Operand number of the value selected when Cond is true.
comment|/// @param FalseOp Operand number of the value selected when Cond is false.
comment|/// @param Optimizable Returned as true if MI is optimizable.
comment|/// @returns False on success.
name|virtual
name|bool
name|analyzeSelect
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|unsigned&TrueOp
argument_list|,
argument|unsigned&FalseOp
argument_list|,
argument|bool&Optimizable
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|MI
operator|&&
name|MI
operator|->
name|getDesc
argument_list|()
operator|.
name|isSelect
argument_list|()
operator|&&
literal|"MI must be a select instruction"
argument_list|)
block|;
return|return
name|true
return|;
block|}
comment|/// Given a select instruction that was understood by
comment|/// analyzeSelect and returned Optimizable = true, attempt to optimize MI by
comment|/// merging it with one of its operands. Returns NULL on failure.
comment|///
comment|/// When successful, returns the new select instruction. The client is
comment|/// responsible for deleting MI.
comment|///
comment|/// If both sides of the select can be optimized, PreferFalse is used to pick
comment|/// a side.
comment|///
comment|/// @param MI          Optimizable select instruction.
comment|/// @param NewMIs     Set that record all MIs in the basic block up to \p
comment|/// MI. Has to be updated with any newly created MI or deleted ones.
comment|/// @param PreferFalse Try to optimize FalseOp instead of TrueOp.
comment|/// @returns Optimized instruction or NULL.
name|virtual
name|MachineInstr
operator|*
name|optimizeSelect
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|SmallPtrSetImpl<MachineInstr *>&NewMIs
argument_list|,
argument|bool PreferFalse = false
argument_list|)
specifier|const
block|{
comment|// This function must be implemented if Optimizable is ever set.
name|llvm_unreachable
argument_list|(
literal|"Target must implement TargetInstrInfo::optimizeSelect!"
argument_list|)
block|;   }
comment|/// Emit instructions to copy a pair of physical registers.
comment|///
comment|/// This function should support copies within any legal register class as
comment|/// well as any cross-class copies created during instruction selection.
comment|///
comment|/// The source and destination registers may overlap, which may require a
comment|/// careful implementation when multiple copy instructions are required for
comment|/// large registers. See for example the ARM target.
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
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement TargetInstrInfo::copyPhysReg!"
argument_list|)
block|;   }
comment|/// Store the specified register of the given register class to the specified
comment|/// stack frame index. The store instruction is to be added to the given
comment|/// machine basic block before the specified machine instruction. If isKill
comment|/// is true, the register operand is the last use and must be marked kill.
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
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement "
literal|"TargetInstrInfo::storeRegToStackSlot!"
argument_list|)
block|;   }
comment|/// Load the specified register of the given register class from the specified
comment|/// stack frame index. The load instruction is to be added to the given
comment|/// machine basic block before the specified machine instruction.
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
name|llvm_unreachable
argument_list|(
literal|"Target didn't implement "
literal|"TargetInstrInfo::loadRegFromStackSlot!"
argument_list|)
block|;   }
comment|/// This function is called for all pseudo instructions
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
comment|/// Attempt to fold a load or store of the specified stack
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
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|;
comment|/// Same as the previous version except it allows folding of any load and
comment|/// store from / to any address, not just from a specific stack slot.
name|MachineInstr
operator|*
name|foldMemoryOperand
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineInstr *LoadMI
argument_list|)
specifier|const
block|;
comment|/// Return true when there is potentially a faster code sequence
comment|/// for an instruction chain ending in \p Root. All potential patterns are
comment|/// returned in the \p Pattern vector. Pattern should be sorted in priority
comment|/// order since the pattern evaluator stops checking as soon as it finds a
comment|/// faster sequence.
comment|/// \param Root - Instruction that could be combined with one of its operands
comment|/// \param Patterns - Vector of possible combination patterns
name|virtual
name|bool
name|getMachineCombinerPatterns
argument_list|(
argument|MachineInstr&Root
argument_list|,
argument|SmallVectorImpl<MachineCombinerPattern>&Patterns
argument_list|)
specifier|const
block|;
comment|/// Return true if the input \P Inst is part of a chain of dependent ops
comment|/// that are suitable for reassociation, otherwise return false.
comment|/// If the instruction's operands must be commuted to have a previous
comment|/// instruction of the same type define the first source operand, \P Commuted
comment|/// will be set to true.
name|bool
name|isReassociationCandidate
argument_list|(
argument|const MachineInstr&Inst
argument_list|,
argument|bool&Commuted
argument_list|)
specifier|const
block|;
comment|/// Return true when \P Inst is both associative and commutative.
name|virtual
name|bool
name|isAssociativeAndCommutative
argument_list|(
argument|const MachineInstr&Inst
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Return true when \P Inst has reassociable operands in the same \P MBB.
name|virtual
name|bool
name|hasReassociableOperands
argument_list|(
argument|const MachineInstr&Inst
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// Return true when \P Inst has reassociable sibling.
name|bool
name|hasReassociableSibling
argument_list|(
argument|const MachineInstr&Inst
argument_list|,
argument|bool&Commuted
argument_list|)
specifier|const
block|;
comment|/// When getMachineCombinerPatterns() finds patterns, this function generates
comment|/// the instructions that could replace the original code sequence. The client
comment|/// has to decide whether the actual replacement is beneficial or not.
comment|/// \param Root - Instruction that could be combined with one of its operands
comment|/// \param Pattern - Combination pattern for Root
comment|/// \param InsInstrs - Vector of new instructions that implement P
comment|/// \param DelInstrs - Old instructions, including Root, that could be
comment|/// replaced by InsInstr
comment|/// \param InstrIdxForVirtReg - map of virtual register to instruction in
comment|/// InsInstr that defines it
name|virtual
name|void
name|genAlternativeCodeSequence
argument_list|(
argument|MachineInstr&Root
argument_list|,
argument|MachineCombinerPattern Pattern
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&InsInstrs
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&DelInstrs
argument_list|,
argument|DenseMap<unsigned
argument_list|,
argument|unsigned>&InstrIdxForVirtReg
argument_list|)
specifier|const
block|;
comment|/// Attempt to reassociate \P Root and \P Prev according to \P Pattern to
comment|/// reduce critical path length.
name|void
name|reassociateOps
argument_list|(
argument|MachineInstr&Root
argument_list|,
argument|MachineInstr&Prev
argument_list|,
argument|MachineCombinerPattern Pattern
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&InsInstrs
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&DelInstrs
argument_list|,
argument|DenseMap<unsigned
argument_list|,
argument|unsigned>&InstrIdxForVirtReg
argument_list|)
specifier|const
block|;
comment|/// This is an architecture-specific helper function of reassociateOps.
comment|/// Set special operand attributes for new instructions after reassociation.
name|virtual
name|void
name|setSpecialOperandAttr
argument_list|(
argument|MachineInstr&OldMI1
argument_list|,
argument|MachineInstr&OldMI2
argument_list|,
argument|MachineInstr&NewMI1
argument_list|,
argument|MachineInstr&NewMI2
argument_list|)
specifier|const
block|{
return|return;
block|}
block|;
comment|/// Return true when a target supports MachineCombiner.
name|virtual
name|bool
name|useMachineCombiner
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|protected
operator|:
comment|/// Target-dependent implementation for foldMemoryOperand.
comment|/// Target-independent code in foldMemoryOperand will
comment|/// take care of adding a MachineMemOperand to the newly created instruction.
comment|/// The instruction and any auxiliary instructions necessary will be inserted
comment|/// at InsertPt.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Target-dependent implementation for foldMemoryOperand.
comment|/// Target-independent code in foldMemoryOperand will
comment|/// take care of adding a MachineMemOperand to the newly created instruction.
comment|/// The instruction and any auxiliary instructions necessary will be inserted
comment|/// at InsertPt.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|MachineInstr *LoadMI
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// \brief Target-dependent implementation of getRegSequenceInputs.
comment|///
comment|/// \returns true if it is possible to build the equivalent
comment|/// REG_SEQUENCE inputs with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isRegSequenceLike().
comment|///
comment|/// \see TargetInstrInfo::getRegSequenceInputs.
name|virtual
name|bool
name|getRegSequenceLikeInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|SmallVectorImpl<RegSubRegPairAndIdx>&InputRegs
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Target-dependent implementation of getExtractSubregInputs.
comment|///
comment|/// \returns true if it is possible to build the equivalent
comment|/// EXTRACT_SUBREG inputs with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isExtractSubregLike().
comment|///
comment|/// \see TargetInstrInfo::getExtractSubregInputs.
name|virtual
name|bool
name|getExtractSubregLikeInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|RegSubRegPairAndIdx&InputReg
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Target-dependent implementation of getInsertSubregInputs.
comment|///
comment|/// \returns true if it is possible to build the equivalent
comment|/// INSERT_SUBREG inputs with the pair \p MI, \p DefIdx. False otherwise.
comment|///
comment|/// \pre MI.isInsertSubregLike().
comment|///
comment|/// \see TargetInstrInfo::getInsertSubregInputs.
name|virtual
name|bool
name|getInsertSubregLikeInputs
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|RegSubRegPair&BaseReg
argument_list|,
argument|RegSubRegPairAndIdx&InsertedReg
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|public
operator|:
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
comment|/// Returns the opcode of the would be new
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
argument|unsigned *LoadRegIndex = nullptr
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// This is used by the pre-regalloc scheduler to determine if two loads are
comment|/// loading from the same base address. It should only return true if the base
comment|/// pointers are the same and the only differences between the two addresses
comment|/// are the offset. It also returns the offsets by reference.
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
comment|/// This is a used by the pre-regalloc scheduler to determine (in conjunction
comment|/// with areLoadsFromSameBasePtr) if two loads should be scheduled together.
comment|/// On some targets if two loads are loading from
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
comment|/// Get the base register and byte offset of an instruction that reads/writes
comment|/// memory.
name|virtual
name|bool
name|getMemOpBaseRegImmOfs
argument_list|(
argument|MachineInstr *MemOp
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|unsigned&Offset
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|enableClusterLoads
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|shouldClusterLoads
argument_list|(
argument|MachineInstr *FirstLdSt
argument_list|,
argument|MachineInstr *SecondLdSt
argument_list|,
argument|unsigned NumLoads
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Can this target fuse the given instructions if they are scheduled
comment|/// adjacent.
name|virtual
name|bool
name|shouldScheduleAdjacent
argument_list|(
argument|MachineInstr* First
argument_list|,
argument|MachineInstr *Second
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Reverses the branch condition of the specified condition list,
comment|/// returning false on success and true if it cannot be reversed.
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
comment|/// Insert a noop into the instruction stream at the specified point.
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
comment|/// Return the noop instruction to use for a noop.
name|virtual
name|void
name|getNoopForMachoTarget
argument_list|(
argument|MCInst&NopInst
argument_list|)
specifier|const
block|;
comment|/// Returns true if the instruction is already predicated.
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
comment|/// Returns true if the instruction is a
comment|/// terminator instruction that has not been predicated.
name|virtual
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Convert the instruction into a predicated instruction.
comment|/// It returns true if the operation was successful.
name|virtual
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|ArrayRef<MachineOperand> Pred
argument_list|)
specifier|const
block|;
comment|/// Returns true if the first specified predicate
comment|/// subsumes the second, e.g. GE subsumes GT.
name|virtual
name|bool
name|SubsumesPredicate
argument_list|(
argument|ArrayRef<MachineOperand> Pred1
argument_list|,
argument|ArrayRef<MachineOperand> Pred2
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// If the specified instruction defines any predicate
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
comment|/// Return true if the specified instruction can be predicated.
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
comment|/// Return true if it's safe to move a machine
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
comment|/// Test if the given instruction should be considered a scheduling boundary.
comment|/// This primarily includes labels and terminators.
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
comment|/// Allocate and return a hazard recognizer to use for this target when
comment|/// scheduling the machine instructions before register allocation.
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetHazardRecognizer
argument_list|(
argument|const TargetSubtargetInfo *STI
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
block|;
comment|/// Allocate and return a hazard recognizer to use for this target when
comment|/// scheduling the machine instructions before register allocation.
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetMIHazardRecognizer
argument_list|(
argument|const InstrItineraryData*
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
block|;
comment|/// Allocate and return a hazard recognizer to use for this target when
comment|/// scheduling the machine instructions after register allocation.
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
block|;
comment|/// Provide a global flag for disabling the PreRA hazard recognizer that
comment|/// targets may choose to honor.
name|bool
name|usePreRAHazardRecognizer
argument_list|()
specifier|const
block|;
comment|/// For a comparison instruction, return the source registers
comment|/// in SrcReg and SrcReg2 if having two register operands, and the value it
comment|/// compares against in CmpValue. Return true if the comparison instruction
comment|/// can be analyzed.
name|virtual
name|bool
name|analyzeCompare
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&SrcReg2
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
comment|/// See if the comparison instruction can be converted
comment|/// into something more efficient. E.g., on ARM most instructions can set the
comment|/// flags register, obviating the need for a separate CMP.
name|virtual
name|bool
name|optimizeCompareInstr
argument_list|(
argument|MachineInstr *CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned SrcReg2
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
name|virtual
name|bool
name|optimizeCondBranch
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Try to remove the load by folding it to a register operand at the use.
comment|/// We fold the load instructions if and only if the
comment|/// def and use are in the same BB. We only look at one load and see
comment|/// whether it can be folded into MI. FoldAsLoadDefReg is the virtual register
comment|/// defined by the load we are trying to fold. DefMI returns the machine
comment|/// instruction that defines FoldAsLoadDefReg, and the function returns
comment|/// the machine instruction generated due to folding.
name|virtual
name|MachineInstr
operator|*
name|optimizeLoadInstr
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|,
argument|unsigned&FoldAsLoadDefReg
argument_list|,
argument|MachineInstr *&DefMI
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// 'Reg' is known to be defined by a move immediate instruction,
comment|/// try to fold the immediate into the use instruction.
comment|/// If MRI->hasOneNonDBGUse(Reg) is true, and this function returns true,
comment|/// then the caller may assume that DefMI has been erased from its parent
comment|/// block. The caller may assume that it will not be erased by this
comment|/// function otherwise.
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
comment|/// Return the number of u-operations the given machine
comment|/// instruction will be decoded to on the target cpu. The itinerary's
comment|/// IssueWidth is the number of microops that can be dispatched each
comment|/// cycle. An instruction with zero microops takes no dispatch resources.
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
comment|/// Return true for pseudo instructions that don't consume any
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
comment|/// Compute and return the use operand latency of a given pair of def and use.
comment|/// In most cases, the static scheduling itinerary was enough to determine the
comment|/// operand latency. But it may not be possible for instructions with variable
comment|/// number of defs / uses.
comment|///
comment|/// This is a raw interface to the itinerary that may be directly overridden
comment|/// by a target. Use computeOperandLatency to get the best estimate of
comment|/// latency.
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
comment|/// Compute and return the latency of the given data
comment|/// dependent def and use when the operand indices are already known.
name|unsigned
name|computeOperandLatency
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
comment|/// Compute the instruction latency of a given instruction.
comment|/// If the instruction has higher cost when predicated, it's returned via
comment|/// PredCost.
name|virtual
name|unsigned
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *MI
argument_list|,
argument|unsigned *PredCost = nullptr
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getPredicationCost
argument_list|(
argument|const MachineInstr *MI
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
comment|/// Return the default expected latency for a def based on it's opcode.
name|unsigned
name|defaultDefLatency
argument_list|(
argument|const MCSchedModel&SchedModel
argument_list|,
argument|const MachineInstr *DefMI
argument_list|)
specifier|const
block|;
name|int
name|computeDefOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr *DefMI
argument_list|)
specifier|const
block|;
comment|/// Return true if this opcode has high latency to its result.
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
comment|/// Compute operand latency between a def of 'Reg'
comment|/// and a use in the current loop. Return true if the target considered
comment|/// it 'high'. This is used by optimization passes such as machine LICM to
comment|/// determine whether it makes sense to hoist an instruction out even in a
comment|/// high register pressure situation.
name|virtual
name|bool
name|hasHighOperandLatency
argument_list|(
argument|const TargetSchedModel&SchedModel
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
comment|/// Compute operand latency of a def of 'Reg'. Return true
comment|/// if the target considered it 'low'.
name|virtual
name|bool
name|hasLowDefLatency
argument_list|(
argument|const TargetSchedModel&SchedModel
argument_list|,
argument|const MachineInstr *DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|)
specifier|const
block|;
comment|/// Perform target-specific instruction verification.
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
comment|/// Return the current execution domain and bit mask of
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
comment|/// Change the opcode of MI to execute in Domain.
comment|///
comment|/// The bit (1<< Domain) must be set in the mask returned from
comment|/// getExecutionDomain(MI).
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
comment|/// Returns the preferred minimum clearance
comment|/// before an instruction with an unwanted partial register update.
comment|///
comment|/// Some instructions only write part of a register, and implicitly need to
comment|/// read the other parts of the register.  This may cause unwanted stalls
comment|/// preventing otherwise unrelated instructions from executing in parallel in
comment|/// an out-of-order CPU.
comment|///
comment|/// For example, the x86 instruction cvtsi2ss writes its result to bits
comment|/// [31:0] of the destination xmm register. Bits [127:32] are unaffected, so
comment|/// the instruction needs to wait for the old value of the register to become
comment|/// available:
comment|///
comment|///   addps %xmm1, %xmm0
comment|///   movaps %xmm0, (%rax)
comment|///   cvtsi2ss %rbx, %xmm0
comment|///
comment|/// In the code above, the cvtsi2ss instruction needs to wait for the addps
comment|/// instruction before it can issue, even though the high bits of %xmm0
comment|/// probably aren't needed.
comment|///
comment|/// This hook returns the preferred clearance before MI, measured in
comment|/// instructions.  Other defs of MI's operand OpNum are avoided in the last N
comment|/// instructions before MI.  It should only return a positive value for
comment|/// unwanted dependencies.  If the old bits of the defined register have
comment|/// useful values, or if MI is determined to otherwise read the dependency,
comment|/// the hook should return 0.
comment|///
comment|/// The unwanted dependency may be handled by:
comment|///
comment|/// 1. Allocating the same register for an MI def and use.  That makes the
comment|///    unwanted dependency identical to a required dependency.
comment|///
comment|/// 2. Allocating a register for the def that has no defs in the previous N
comment|///    instructions.
comment|///
comment|/// 3. Calling breakPartialRegDependency() with the same arguments.  This
comment|///    allows the target to insert a dependency breaking instruction.
comment|///
name|virtual
name|unsigned
name|getPartialRegUpdateClearance
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
comment|// The default implementation returns 0 for no partial register dependency.
return|return
literal|0
return|;
block|}
comment|/// \brief Return the minimum clearance before an instruction that reads an
comment|/// unused register.
comment|///
comment|/// For example, AVX instructions may copy part of a register operand into
comment|/// the unused high bits of the destination register.
comment|///
comment|/// vcvtsi2sdq %rax, %xmm0<undef>, %xmm14
comment|///
comment|/// In the code above, vcvtsi2sdq copies %xmm0[127:64] into %xmm14 creating a
comment|/// false dependence on any previous write to %xmm0.
comment|///
comment|/// This hook works similarly to getPartialRegUpdateClearance, except that it
comment|/// does not take an operand index. Instead sets \p OpNum to the index of the
comment|/// unused register.
name|virtual
name|unsigned
name|getUndefRegClearance
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned&OpNum
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
comment|// The default implementation returns 0 for no undef register dependency.
return|return
literal|0
return|;
block|}
comment|/// Insert a dependency-breaking instruction
comment|/// before MI to eliminate an unwanted dependency on OpNum.
comment|///
comment|/// If it wasn't possible to avoid a def in the last N instructions before MI
comment|/// (see getPartialRegUpdateClearance), this hook will be called to break the
comment|/// unwanted dependency.
comment|///
comment|/// On x86, an xorps instruction can be used as a dependency breaker:
comment|///
comment|///   addps %xmm1, %xmm0
comment|///   movaps %xmm0, (%rax)
comment|///   xorps %xmm0, %xmm0
comment|///   cvtsi2ss %rbx, %xmm0
comment|///
comment|/// An<imp-kill> operand should be added to MI if an instruction was
comment|/// inserted.  This ties the instructions together in the post-ra scheduler.
comment|///
name|virtual
name|void
name|breakPartialRegDependency
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{}
comment|/// Create machine specific model for scheduling.
name|virtual
name|DFAPacketizer
operator|*
name|CreateTargetScheduleState
argument_list|(
argument|const TargetSubtargetInfo&
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|// Sometimes, it is possible for the target
comment|// to tell, even without aliasing information, that two MIs access different
comment|// memory addresses. This function returns true if two MIs access different
comment|// memory addresses and false otherwise.
name|virtual
name|bool
name|areMemAccessesTriviallyDisjoint
argument_list|(
argument|MachineInstr *MIa
argument_list|,
argument|MachineInstr *MIb
argument_list|,
argument|AliasAnalysis *AA = nullptr
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|MIa
operator|&&
operator|(
name|MIa
operator|->
name|mayLoad
argument_list|()
operator|||
name|MIa
operator|->
name|mayStore
argument_list|()
operator|)
operator|&&
literal|"MIa must load from or modify a memory location"
argument_list|)
block|;
name|assert
argument_list|(
name|MIb
operator|&&
operator|(
name|MIb
operator|->
name|mayLoad
argument_list|()
operator|||
name|MIb
operator|->
name|mayStore
argument_list|()
operator|)
operator|&&
literal|"MIb must load from or modify a memory location"
argument_list|)
block|;
return|return
name|false
return|;
block|}
comment|/// \brief Return the value to use for the MachineCSE's LookAheadLimit,
comment|/// which is a heuristic used for CSE'ing phys reg defs.
name|virtual
name|unsigned
name|getMachineCSELookAheadLimit
argument_list|()
specifier|const
block|{
comment|// The default lookahead is small to prevent unprofitable quadratic
comment|// behavior.
return|return
literal|5
return|;
block|}
comment|/// Return an array that contains the ids of the target indices (used for the
comment|/// TargetIndex machine operand) and their names.
comment|///
comment|/// MIR Serialization is able to serialize only the target indices that are
comment|/// defined by this method.
name|virtual
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|int
block|,
specifier|const
name|char
operator|*
operator|>>
name|getSerializableTargetIndices
argument_list|()
specifier|const
block|{
return|return
name|None
return|;
block|}
comment|/// Decompose the machine operand's target flags into two values - the direct
comment|/// target flag value and any of bit flags that are applied.
name|virtual
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|decomposeMachineOperandsTargetFlags
argument_list|(
argument|unsigned
comment|/*TF*/
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
literal|0u
argument_list|,
literal|0u
argument_list|)
return|;
block|}
comment|/// Return an array that contains the direct target flag values and their
comment|/// names.
comment|///
comment|/// MIR Serialization is able to serialize only the target flags that are
comment|/// defined by this method.
name|virtual
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|char
operator|*
operator|>>
name|getSerializableDirectMachineOperandTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|None
return|;
block|}
comment|/// Return an array that contains the bitmask target flag values and their
comment|/// names.
comment|///
comment|/// MIR Serialization is able to serialize only the target flags that are
comment|/// defined by this method.
name|virtual
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|char
operator|*
operator|>>
name|getSerializableBitmaskMachineOperandTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|None
return|;
block|}
name|private
operator|:
name|unsigned
name|CallFrameSetupOpcode
block|,
name|CallFrameDestroyOpcode
block|;
name|unsigned
name|CatchRetOpcode
block|; }
decl_stmt|;
comment|/// \brief Provide DenseMapInfo for TargetInstrInfo::RegSubRegPair.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|TargetInstrInfo
operator|::
name|RegSubRegPair
operator|>
block|{
typedef|typedef
name|DenseMapInfo
operator|<
name|unsigned
operator|>
name|RegInfo
expr_stmt|;
specifier|static
specifier|inline
name|TargetInstrInfo
operator|::
name|RegSubRegPair
name|getEmptyKey
argument_list|()
block|{
return|return
name|TargetInstrInfo
operator|::
name|RegSubRegPair
argument_list|(
name|RegInfo
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|RegInfo
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|TargetInstrInfo
operator|::
name|RegSubRegPair
name|getTombstoneKey
argument_list|()
block|{
return|return
name|TargetInstrInfo
operator|::
name|RegSubRegPair
argument_list|(
name|RegInfo
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|RegInfo
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Reuse getHashValue implementation from
comment|/// std::pair<unsigned, unsigned>.
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const TargetInstrInfo::RegSubRegPair&Val
argument_list|)
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|PairVal
operator|=
name|std
operator|::
name|make_pair
argument_list|(
name|Val
operator|.
name|Reg
argument_list|,
name|Val
operator|.
name|SubReg
argument_list|)
block|;
return|return
name|DenseMapInfo
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>>
operator|::
name|getHashValue
argument_list|(
name|PairVal
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const TargetInstrInfo::RegSubRegPair&LHS
argument_list|,
argument|const TargetInstrInfo::RegSubRegPair&RHS
argument_list|)
block|{
return|return
name|RegInfo
operator|::
name|isEqual
argument_list|(
name|LHS
operator|.
name|Reg
argument_list|,
name|RHS
operator|.
name|Reg
argument_list|)
operator|&&
name|RegInfo
operator|::
name|isEqual
argument_list|(
name|LHS
operator|.
name|SubReg
argument_list|,
name|RHS
operator|.
name|SubReg
argument_list|)
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

