begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HexagonInstrInfo.h - Hexagon Instruction Information -----*- C++ -*-===//
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
comment|// This file contains the Hexagon implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"HexagonRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBranchProbabilityInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"HexagonGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|EVT
struct_decl|;
name|class
name|HexagonSubtarget
decl_stmt|;
name|class
name|HexagonInstrInfo
range|:
name|public
name|HexagonGenInstrInfo
block|{
specifier|const
name|HexagonRegisterInfo
name|RI
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|explicit
name|HexagonInstrInfo
argument_list|(
name|HexagonSubtarget
operator|&
name|ST
argument_list|)
block|;
comment|/// TargetInstrInfo overrides.
comment|///
comment|/// If the specified machine instruction is a direct
comment|/// load from a stack slot, return the virtual or physical register number of
comment|/// the destination along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than loading from the stack slot.
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
comment|/// If the specified machine instruction is a direct
comment|/// store to a stack slot, return the virtual or physical register number of
comment|/// the source reg along with the FrameIndex of the loaded stack slot.  If
comment|/// not, return 0.  This predicate must return 0 if the instruction has
comment|/// any side effects other than storing to the stack slot.
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
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
comment|/// Note that removeBranch and insertBranch must be implemented to support
comment|/// cases where this method returns success.
comment|///
comment|/// If AllowModify is true, then this routine is allowed to modify the basic
comment|/// block (e.g. delete instructions after the unconditional branch).
comment|///
name|bool
name|analyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
name|override
block|;
comment|/// Remove the branching code at the end of the specific MBB.
comment|/// This is only invoked in cases where AnalyzeBranch returns success. It
comment|/// returns the number of instructions that were removed.
name|unsigned
name|removeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|int *BytesRemoved = nullptr
argument_list|)
specifier|const
name|override
block|;
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
name|unsigned
name|insertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|int *BytesAdded = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// Analyze the loop code, return true if it cannot be understood. Upon
comment|/// success, this function returns false and returns information about the
comment|/// induction variable and compare instruction used at the end.
name|bool
name|analyzeLoop
argument_list|(
argument|MachineLoop&L
argument_list|,
argument|MachineInstr *&IndVarInst
argument_list|,
argument|MachineInstr *&CmpInst
argument_list|)
specifier|const
name|override
block|;
comment|/// Generate code to reduce the loop iteration by one and check if the loop is
comment|/// finished.  Return the value/register of the the new loop count.  We need
comment|/// this function when peeling off one or more iterations of a loop. This
comment|/// function assumes the nth iteration is peeled first.
name|unsigned
name|reduceLoopCount
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineInstr *IndVar
argument_list|,
argument|MachineInstr&Cmp
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&PrevInsts
argument_list|,
argument|unsigned Iter
argument_list|,
argument|unsigned MaxIter
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if it's profitable to predicate
comment|/// instructions with accumulated instruction latency of "NumCycles"
comment|/// of the specified basic block, where the probability of the instructions
comment|/// being executed is given by Probability, and Confidence is a measure
comment|/// of our confidence that it will be properly predicted.
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
name|override
block|;
comment|/// Second variant of isProfitableToIfCvt. This one
comment|/// checks for the case where two basic blocks from true and false path
comment|/// of a if-then-else (diamond) are predicated on mutally exclusive
comment|/// predicates, where the probability of the true path being taken is given
comment|/// by Probability, and Confidence is a measure of our confidence that it
comment|/// will be properly predicted.
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
name|override
block|;
comment|/// Return true if it's profitable for if-converter to duplicate instructions
comment|/// of specified accumulated instruction latencies in the specified MBB to
comment|/// enable if-conversion.
comment|/// The probability of the instructions being executed is given by
comment|/// Probability, and Confidence is a measure of our confidence that it
comment|/// will be properly predicted.
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
name|override
block|;
comment|/// Emit instructions to copy a pair of physical registers.
comment|///
comment|/// This function should support copies within any legal register class as
comment|/// well as any cross-class copies created during instruction selection.
comment|///
comment|/// The source and destination registers may overlap, which may require a
comment|/// careful implementation when multiple copy instructions are required for
comment|/// large registers. See for example the ARM target.
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
name|override
block|;
comment|/// Store the specified register of the given register class to the specified
comment|/// stack frame index. The store instruction is to be added to the given
comment|/// machine basic block before the specified machine instruction. If isKill
comment|/// is true, the register operand is the last use and must be marked kill.
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
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
name|override
block|;
comment|/// Load the specified register of the given register class from the specified
comment|/// stack frame index. The load instruction is to be added to the given
comment|/// machine basic block before the specified machine instruction.
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
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
name|override
block|;
comment|/// This function is called for all pseudo instructions
comment|/// that remain after register allocation. Many pseudo instructions are
comment|/// created to help register allocation. This is the place to convert them
comment|/// into real instructions. The target can edit MI in place, or it can insert
comment|/// new instructions and erase MI. The function should return true if
comment|/// anything was changed.
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Get the base register and byte offset of a load/store instr.
name|bool
name|getMemOpBaseRegImmOfs
argument_list|(
argument|MachineInstr&LdSt
argument_list|,
argument|unsigned&BaseReg
argument_list|,
argument|int64_t&Offset
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
comment|/// Reverses the branch condition of the specified condition list,
comment|/// returning false on success and true if it cannot be reversed.
name|bool
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
comment|/// Insert a noop into the instruction stream at the specified point.
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if the instruction is already predicated.
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true for post-incremented instructions.
name|bool
name|isPostIncrement
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|/// Convert the instruction into a predicated instruction.
comment|/// It returns true if the operation was successful.
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if the first specified predicate
comment|/// subsumes the second, e.g. GE subsumes GT.
name|bool
name|SubsumesPredicate
argument_list|(
argument|ArrayRef<MachineOperand> Pred1
argument_list|,
argument|ArrayRef<MachineOperand> Pred2
argument_list|)
specifier|const
name|override
block|;
comment|/// If the specified instruction defines any predicate
comment|/// or condition code register(s) used for predication, returns true as well
comment|/// as the definition predicate(s) by reference.
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if the specified instruction can be predicated.
comment|/// By default, this returns true for every instruction with a
comment|/// PredicateOperand.
name|bool
name|isPredicable
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|/// Test if the given instruction should be considered a scheduling boundary.
comment|/// This primarily includes labels and terminators.
name|bool
name|isSchedulingBoundary
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|,
argument|const MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|/// Measure the specified inline asm to determine an approximation of its
comment|/// length.
name|unsigned
name|getInlineAsmLength
argument_list|(
argument|const char *Str
argument_list|,
argument|const MCAsmInfo&MAI
argument_list|)
specifier|const
name|override
block|;
comment|/// Allocate and return a hazard recognizer to use for this target when
comment|/// scheduling the machine instructions after register allocation.
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
argument|const InstrItineraryData*
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
name|override
block|;
comment|/// For a comparison instruction, return the source registers
comment|/// in SrcReg and SrcReg2 if having two register operands, and the value it
comment|/// compares against in CmpValue. Return true if the comparison instruction
comment|/// can be analyzed.
name|bool
name|analyzeCompare
argument_list|(
argument|const MachineInstr&MI
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
name|override
block|;
comment|/// Compute the instruction latency of a given instruction.
comment|/// If the instruction has higher cost when predicated, it's returned via
comment|/// PredCost.
name|unsigned
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr&MI
argument_list|,
argument|unsigned *PredCost = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// Create machine specific model for scheduling.
name|DFAPacketizer
operator|*
name|CreateTargetScheduleState
argument_list|(
argument|const TargetSubtargetInfo&STI
argument_list|)
specifier|const
name|override
block|;
comment|// Sometimes, it is possible for the target
comment|// to tell, even without aliasing information, that two MIs access different
comment|// memory addresses. This function returns true if two MIs access different
comment|// memory addresses and false otherwise.
name|bool
name|areMemAccessesTriviallyDisjoint
argument_list|(
argument|MachineInstr&MIa
argument_list|,
argument|MachineInstr&MIb
argument_list|,
argument|AliasAnalysis *AA = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// For instructions with a base and offset, return the position of the
comment|/// base register and offset operands.
name|bool
name|getBaseAndOffsetPosition
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&BasePos
argument_list|,
argument|unsigned&OffsetPos
argument_list|)
specifier|const
name|override
block|;
comment|/// If the instruction is an increment of a constant value, return the amount.
name|bool
name|getIncrementValue
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&Value
argument_list|)
specifier|const
name|override
block|;
comment|/// getOperandLatency - Compute and return the use operand latency of a given
comment|/// pair of def and use.
comment|/// In most cases, the static scheduling itinerary was enough to determine the
comment|/// operand latency. But it may not be possible for instructions with variable
comment|/// number of defs / uses.
comment|///
comment|/// This is a raw interface to the itinerary that may be directly overriden by
comment|/// a target. Use computeOperandLatency to get the best estimate of latency.
name|int
name|getOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr&DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|const MachineInstr&UseMI
argument_list|,
argument|unsigned UseIdx
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTailCall
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|/// HexagonInstrInfo specifics.
comment|///
specifier|const
name|HexagonRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|unsigned
name|createVR
argument_list|(
argument|MachineFunction* MF
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
block|;
name|bool
name|isAbsoluteSet
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isAccumulator
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isComplex
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isCompoundBranchInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isConstExtended
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isDeallocRet
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isDependent
argument_list|(
argument|const MachineInstr&ProdMI
argument_list|,
argument|const MachineInstr&ConsMI
argument_list|)
specifier|const
block|;
name|bool
name|isDotCurInst
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isDotNewInst
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isDuplexPair
argument_list|(
argument|const MachineInstr&MIa
argument_list|,
argument|const MachineInstr&MIb
argument_list|)
specifier|const
block|;
name|bool
name|isEarlySourceInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isEndLoopN
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isExpr
argument_list|(
argument|unsigned OpType
argument_list|)
specifier|const
block|;
name|bool
name|isExtendable
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isExtended
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isFloat
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isHVXMemWithAIndirect
argument_list|(
argument|const MachineInstr&I
argument_list|,
argument|const MachineInstr&J
argument_list|)
specifier|const
block|;
name|bool
name|isIndirectCall
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isIndirectL4Return
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isJumpR
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isJumpWithinBranchRange
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned offset
argument_list|)
specifier|const
block|;
name|bool
name|isLateInstrFeedsEarlyInstr
argument_list|(
argument|const MachineInstr&LRMI
argument_list|,
argument|const MachineInstr&ESMI
argument_list|)
specifier|const
block|;
name|bool
name|isLateResultInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isLateSourceInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isLoopN
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isMemOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isNewValue
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isNewValue
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isNewValueInst
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isNewValueJump
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isNewValueJump
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isNewValueStore
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isNewValueStore
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isOperandExtended
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned OperandNum
argument_list|)
specifier|const
block|;
name|bool
name|isPredicatedNew
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isPredicatedNew
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isPredicatedTrue
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isPredicatedTrue
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isPredicated
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isPredicateLate
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isPredictedTaken
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|isSaveCalleeSavedRegsCall
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isSignExtendingLoad
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isSolo
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isSpillPredRegOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isTC1
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isTC2
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isTC2Early
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isTC4x
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isToBeScheduledASAP
argument_list|(
argument|const MachineInstr&MI1
argument_list|,
argument|const MachineInstr&MI2
argument_list|)
specifier|const
block|;
name|bool
name|isHVXVec
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isValidAutoIncImm
argument_list|(
argument|const EVT VT
argument_list|,
argument|const int Offset
argument_list|)
specifier|const
block|;
name|bool
name|isValidOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|int Offset
argument_list|,
argument|bool Extend = true
argument_list|)
specifier|const
block|;
name|bool
name|isVecAcc
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isVecALU
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|isVecUsableNextPacket
argument_list|(
argument|const MachineInstr&ProdMI
argument_list|,
argument|const MachineInstr&ConsMI
argument_list|)
specifier|const
block|;
name|bool
name|isZeroExtendingLoad
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|addLatencyToSchedule
argument_list|(
argument|const MachineInstr&MI1
argument_list|,
argument|const MachineInstr&MI2
argument_list|)
specifier|const
block|;
name|bool
name|canExecuteInBundle
argument_list|(
argument|const MachineInstr&First
argument_list|,
argument|const MachineInstr&Second
argument_list|)
specifier|const
block|;
name|bool
name|doesNotReturn
argument_list|(
argument|const MachineInstr&CallMI
argument_list|)
specifier|const
block|;
name|bool
name|hasEHLabel
argument_list|(
argument|const MachineBasicBlock *B
argument_list|)
specifier|const
block|;
name|bool
name|hasNonExtEquivalent
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|hasPseudoInstrPair
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|hasUncondBranch
argument_list|(
argument|const MachineBasicBlock *B
argument_list|)
specifier|const
block|;
name|bool
name|mayBeCurLoad
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|mayBeNewStore
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|producesStall
argument_list|(
argument|const MachineInstr&ProdMI
argument_list|,
argument|const MachineInstr&ConsMI
argument_list|)
specifier|const
block|;
name|bool
name|producesStall
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|MachineBasicBlock::const_instr_iterator MII
argument_list|)
specifier|const
block|;
name|bool
name|predCanBeUsedAsDotNew
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned PredReg
argument_list|)
specifier|const
block|;
name|bool
name|PredOpcodeHasJMP_c
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|predOpcodeHasNot
argument_list|(
argument|ArrayRef<MachineOperand> Cond
argument_list|)
specifier|const
block|;
name|short
name|getAbsoluteForm
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getAddrMode
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getBaseAndOffset
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&Offset
argument_list|,
argument|unsigned&AccessSize
argument_list|)
specifier|const
block|;
name|short
name|getBaseWithLongOffset
argument_list|(
argument|short Opcode
argument_list|)
specifier|const
block|;
name|short
name|getBaseWithLongOffset
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|short
name|getBaseWithRegOffset
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|SmallVector
operator|<
name|MachineInstr
operator|*
block|,
literal|2
operator|>
name|getBranchingInstrs
argument_list|(
argument|MachineBasicBlock& MBB
argument_list|)
specifier|const
block|;
name|unsigned
name|getCExtOpNum
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|HexagonII
operator|::
name|CompoundGroup
name|getCompoundCandidateGroup
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getCompoundOpcode
argument_list|(
argument|const MachineInstr&GA
argument_list|,
argument|const MachineInstr&GB
argument_list|)
specifier|const
block|;
name|int
name|getCondOpcode
argument_list|(
argument|int Opc
argument_list|,
argument|bool sense
argument_list|)
specifier|const
block|;
name|int
name|getDotCurOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|int
name|getNonDotCurOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|int
name|getDotNewOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|int
name|getDotNewPredJumpOp
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineBranchProbabilityInfo *MBPI
argument_list|)
specifier|const
block|;
name|int
name|getDotNewPredOp
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineBranchProbabilityInfo *MBPI
argument_list|)
specifier|const
block|;
name|int
name|getDotOldOp
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|HexagonII
operator|::
name|SubInstructionGroup
name|getDuplexCandidateGroup
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|short
name|getEquivalentHWInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|MachineInstr
operator|*
name|getFirstNonDbgInst
argument_list|(
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|unsigned
name|getInstrTimingClassLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|getInvertedPredSense
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|unsigned
name|getInvertedPredicatedOpcode
argument_list|(
argument|const int Opc
argument_list|)
specifier|const
block|;
name|int
name|getMaxValue
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getMemAccessSize
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|int
name|getMinValue
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|short
name|getNonExtOpcode
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|getPredReg
argument_list|(
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|unsigned&PredReg
argument_list|,
argument|unsigned&PredRegPos
argument_list|,
argument|unsigned&PredRegFlags
argument_list|)
specifier|const
block|;
name|short
name|getPseudoInstrPair
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|short
name|getRegForm
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getSize
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|uint64_t
name|getType
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|getUnits
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|/// getInstrTimingClassLatency - Compute the instruction latency of a given
comment|/// instruction using Timing Class information, if available.
name|unsigned
name|nonDbgBBSize
argument_list|(
argument|const MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|unsigned
name|nonDbgBundleSize
argument_list|(
argument|MachineBasicBlock::const_iterator BundleHead
argument_list|)
specifier|const
block|;
name|void
name|immediateExtend
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
block|;
name|bool
name|invertAndChangeJumpTarget
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock* NewTarget
argument_list|)
specifier|const
block|;
name|void
name|genAllInsnTimingClasses
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|bool
name|reversePredSense
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
block|;
name|unsigned
name|reversePrediction
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|bool
name|validateBranchCond
argument_list|(
argument|const ArrayRef<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|short
name|xformRegToImmOffset
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
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
comment|// LLVM_LIB_TARGET_HEXAGON_HEXAGONINSTRINFO_H
end_comment

end_unit

