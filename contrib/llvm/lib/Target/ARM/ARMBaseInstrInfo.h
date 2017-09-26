begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMBaseInstrInfo.h - ARM Base Instruction Information ---*- C++ -*-===//
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
comment|// This file contains the Base ARM implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_ARM_ARMBASEINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMBASEINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMBaseInfo.h"
end_include

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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"ARMGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMBaseRegisterInfo
decl_stmt|;
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMBaseInstrInfo
range|:
name|public
name|ARMGenInstrInfo
block|{
specifier|const
name|ARMSubtarget
operator|&
name|Subtarget
block|;
name|protected
operator|:
comment|// Can be only subclassed.
name|explicit
name|ARMBaseInstrInfo
argument_list|(
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|;
name|void
name|expandLoadStackGuardBase
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned LoadImmOpc
argument_list|,
argument|unsigned LoadOpc
argument_list|)
specifier|const
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
comment|/// \pre MI.isRegSequenceLike().
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
name|override
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
comment|/// \pre MI.isExtractSubregLike().
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
name|override
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
comment|/// \pre MI.isInsertSubregLike().
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
name|override
block|;
comment|/// Commutes the operands in the given instruction.
comment|/// The commutable operands are specified by their indices OpIdx1 and OpIdx2.
comment|///
comment|/// Do not call this method for a non-commutable instruction or for
comment|/// non-commutable pair of operand indices OpIdx1 and OpIdx2.
comment|/// Even though the instruction is commutable, the method may still
comment|/// fail to commute the operands, null pointer is returned in such cases.
name|MachineInstr
operator|*
name|commuteInstructionImpl
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|bool NewMI
argument_list|,
argument|unsigned OpIdx1
argument_list|,
argument|unsigned OpIdx2
argument_list|)
specifier|const
name|override
block|;
name|public
operator|:
comment|// Return whether the target has an explicit NOP encoding.
name|bool
name|hasNOP
argument_list|()
specifier|const
block|;
comment|// Return the non-pre/post incrementing version of 'Opc'. Return 0
comment|// if there is not such an opcode.
name|virtual
name|unsigned
name|getUnindexedOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MFI
argument_list|,
argument|MachineInstr&MI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
name|override
block|;
name|virtual
specifier|const
name|ARMBaseRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|const
name|ARMSubtarget
operator|&
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
return|;
block|}
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetHazardRecognizer
argument_list|(
argument|const TargetSubtargetInfo *STI
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
name|override
block|;
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetPostRAHazardRecognizer
argument_list|(
argument|const InstrItineraryData *II
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
name|override
block|;
comment|// Branch analysis.
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
argument|bool AllowModify = false
argument_list|)
specifier|const
name|override
block|;
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
name|bool
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
comment|// Predication support.
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|ARMCC
operator|::
name|CondCodes
name|getPredicate
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|{
name|int
name|PIdx
operator|=
name|MI
operator|.
name|findFirstPredOperandIdx
argument_list|()
block|;
return|return
name|PIdx
operator|!=
operator|-
literal|1
condition|?
operator|(
name|ARMCC
operator|::
name|CondCodes
operator|)
name|MI
operator|.
name|getOperand
argument_list|(
name|PIdx
argument_list|)
operator|.
name|getImm
argument_list|()
else|:
name|ARMCC
operator|::
name|AL
return|;
block|}
name|bool
name|PredicateInstruction
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|ArrayRef<MachineOperand> Pred
argument_list|)
specifier|const
name|override
block|;
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
name|bool
name|isPredicable
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|// CPSR defined in instruction
specifier|static
name|bool
name|isCPSRDefined
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|bool
name|isAddrMode3OpImm
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
name|bool
name|isAddrMode3OpMinusReg
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|// Load, scaled register offset
name|bool
name|isLdstScaledReg
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|// Load, scaled register offset, not plus LSL2
name|bool
name|isLdstScaledRegNotPlusLsl2
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|// Minus reg for ldstso addr mode
name|bool
name|isLdstSoMinusReg
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|// Scaled register offset in address mode 2
name|bool
name|isAm2ScaledReg
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned Op
argument_list|)
specifier|const
block|;
comment|// Load multiple, base reg in list
name|bool
name|isLDMBaseRegInList
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|// get LDM variable defs size
name|unsigned
name|getLDMVariableDefsSize
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|/// GetInstSize - Returns the size of the specified MachineInstr.
comment|///
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
name|unsigned
name|isLoadFromStackSlotPostFE
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|isStoreToStackSlotPostFE
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
name|override
block|;
name|void
name|copyToCPSR
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|,
argument|const ARMSubtarget&Subtarget
argument_list|)
specifier|const
block|;
name|void
name|copyFromCPSR
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|bool KillSrc
argument_list|,
argument|const ARMSubtarget&Subtarget
argument_list|)
specifier|const
block|;
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
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
argument|const MachineInstr&Orig
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
name|override
block|;
name|MachineInstr
operator|*
name|duplicate
argument_list|(
argument|MachineInstr&Orig
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MachineInstrBuilder
operator|&
name|AddDReg
argument_list|(
argument|MachineInstrBuilder&MIB
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|unsigned State
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|;
name|bool
name|produceSameValue
argument_list|(
argument|const MachineInstr&MI0
argument_list|,
argument|const MachineInstr&MI1
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|override
block|;
comment|/// areLoadsFromSameBasePtr - This is used by the pre-regalloc scheduler to
comment|/// determine if two loads are loading from the same base address. It should
comment|/// only return true if the base pointers are the same and the only
comment|/// differences between the two addresses is the offset. It also returns the
comment|/// offsets by reference.
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
name|override
block|;
comment|/// shouldScheduleLoadsNear - This is a used by the pre-regalloc scheduler to
comment|/// determine (in conjunction with areLoadsFromSameBasePtr) if two loads
comment|/// should be scheduled togther. On some targets if two loads are loading from
comment|/// addresses in the same cache line, it's better if they are scheduled
comment|/// together. This function takes two integers that represent the load offsets
comment|/// from the common base address. It returns true if it decides it's desirable
comment|/// to schedule the two loads together. "NumLoads" is the number of loads that
comment|/// have already been scheduled after Load1.
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
name|override
block|;
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
name|bool
name|isProfitableToIfCvt
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|unsigned NumT
argument_list|,
argument|unsigned ExtraT
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|,
argument|unsigned NumF
argument_list|,
argument|unsigned ExtraF
argument_list|,
argument|BranchProbability Probability
argument_list|)
specifier|const
name|override
block|;
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
block|{
return|return
name|NumCycles
operator|==
literal|1
return|;
block|}
name|bool
name|isProfitableToUnpredicate
argument_list|(
argument|MachineBasicBlock&TMBB
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|)
specifier|const
name|override
block|;
comment|/// analyzeCompare - For a comparison instruction, return the source registers
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
argument|int&CmpMask
argument_list|,
argument|int&CmpValue
argument_list|)
specifier|const
name|override
block|;
comment|/// optimizeCompareInstr - Convert the instruction to set the zero flag so
comment|/// that we can remove a "comparison with zero"; Remove a redundant CMP
comment|/// instruction if the flags can be updated in the same way by an earlier
comment|/// instruction such as SUB.
name|bool
name|optimizeCompareInstr
argument_list|(
argument|MachineInstr&CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned SrcReg2
argument_list|,
argument|int CmpMask
argument_list|,
argument|int CmpValue
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|analyzeSelect
argument_list|(
argument|const MachineInstr&MI
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
name|override
block|;
name|MachineInstr
operator|*
name|optimizeSelect
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|SmallPtrSetImpl<MachineInstr *>&SeenMIs
argument_list|,
argument|bool
argument_list|)
specifier|const
name|override
block|;
comment|/// FoldImmediate - 'Reg' is known to be defined by a move immediate
comment|/// instruction, try to fold the immediate into the use instruction.
name|bool
name|FoldImmediate
argument_list|(
argument|MachineInstr&UseMI
argument_list|,
argument|MachineInstr&DefMI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|MachineRegisterInfo *MRI
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getNumMicroOps
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
comment|/// VFP/NEON execution domains.
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
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|void
name|setExecutionDomain
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned Domain
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getPartialRegUpdateClearance
argument_list|(
argument|const MachineInstr&
argument_list|,
argument|unsigned
argument_list|,
argument|const TargetRegisterInfo *
argument_list|)
specifier|const
name|override
block|;
name|void
name|breakPartialRegDependency
argument_list|(
argument|MachineInstr&
argument_list|,
argument|unsigned
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
block|;
comment|/// Get the number of addresses by LDM or VLDM or zero for unknown.
name|unsigned
name|getNumLDMAddresses
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|private
operator|:
name|unsigned
name|getInstBundleLength
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
name|int
name|getVLDMDefCycle
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MCInstrDesc&DefMCID
argument_list|,
argument|unsigned DefClass
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|unsigned DefAlign
argument_list|)
specifier|const
block|;
name|int
name|getLDMDefCycle
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MCInstrDesc&DefMCID
argument_list|,
argument|unsigned DefClass
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|unsigned DefAlign
argument_list|)
specifier|const
block|;
name|int
name|getVSTMUseCycle
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MCInstrDesc&UseMCID
argument_list|,
argument|unsigned UseClass
argument_list|,
argument|unsigned UseIdx
argument_list|,
argument|unsigned UseAlign
argument_list|)
specifier|const
block|;
name|int
name|getSTMUseCycle
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MCInstrDesc&UseMCID
argument_list|,
argument|unsigned UseClass
argument_list|,
argument|unsigned UseIdx
argument_list|,
argument|unsigned UseAlign
argument_list|)
specifier|const
block|;
name|int
name|getOperandLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MCInstrDesc&DefMCID
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|unsigned DefAlign
argument_list|,
argument|const MCInstrDesc&UseMCID
argument_list|,
argument|unsigned UseIdx
argument_list|,
argument|unsigned UseAlign
argument_list|)
specifier|const
block|;
name|int
name|getOperandLatencyImpl
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const MachineInstr&DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|const MCInstrDesc&DefMCID
argument_list|,
argument|unsigned DefAdj
argument_list|,
argument|const MachineOperand&DefMO
argument_list|,
argument|unsigned Reg
argument_list|,
argument|const MachineInstr&UseMI
argument_list|,
argument|unsigned UseIdx
argument_list|,
argument|const MCInstrDesc&UseMCID
argument_list|,
argument|unsigned UseAdj
argument_list|)
specifier|const
block|;
name|unsigned
name|getPredicationCost
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasHighOperandLatency
argument_list|(
argument|const TargetSchedModel&SchedModel
argument_list|,
argument|const MachineRegisterInfo *MRI
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
name|hasLowDefLatency
argument_list|(
argument|const TargetSchedModel&SchedModel
argument_list|,
argument|const MachineInstr&DefMI
argument_list|,
argument|unsigned DefIdx
argument_list|)
specifier|const
name|override
block|;
comment|/// verifyInstruction - Perform target specific instruction verification.
name|bool
name|verifyInstruction
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|StringRef&ErrInfo
argument_list|)
specifier|const
name|override
block|;
name|virtual
name|void
name|expandLoadStackGuard
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|void
name|expandMEMCPY
argument_list|(
argument|MachineBasicBlock::iterator
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// Modeling special VFP / NEON fp MLA / MLS hazards.
comment|/// MLxEntryMap - Map fp MLA / MLS to the corresponding entry in the internal
comment|/// MLx table.
name|DenseMap
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|MLxEntryMap
block|;
comment|/// MLxHazardOpcodes - Set of add / sub and multiply opcodes that would cause
comment|/// stalls when scheduled together with fp MLA / MLS opcodes.
name|SmallSet
operator|<
name|unsigned
block|,
literal|16
operator|>
name|MLxHazardOpcodes
block|;
name|public
operator|:
comment|/// isFpMLxInstruction - Return true if the specified opcode is a fp MLA / MLS
comment|/// instruction.
name|bool
name|isFpMLxInstruction
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|{
return|return
name|MLxEntryMap
operator|.
name|count
argument_list|(
name|Opcode
argument_list|)
return|;
block|}
comment|/// isFpMLxInstruction - This version also returns the multiply opcode and the
comment|/// addition / subtraction opcode to expand to. Return true for 'HasLane' for
comment|/// the MLX instructions with an extra lane operand.
name|bool
name|isFpMLxInstruction
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned&MulOpc
argument_list|,
argument|unsigned&AddSubOpc
argument_list|,
argument|bool&NegAcc
argument_list|,
argument|bool&HasLane
argument_list|)
specifier|const
block|;
comment|/// canCauseFpMLxStall - Return true if an instruction of the specified opcode
comment|/// will cause stalls when scheduled after (within 4-cycle window) a fp
comment|/// MLA / MLS instruction.
name|bool
name|canCauseFpMLxStall
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|{
return|return
name|MLxHazardOpcodes
operator|.
name|count
argument_list|(
name|Opcode
argument_list|)
return|;
block|}
comment|/// Returns true if the instruction has a shift by immediate that can be
comment|/// executed in one cycle less.
name|bool
name|isSwiftFastImmShift
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// Returns predicate register associated with the given frame instruction.
name|unsigned
name|getFramePred
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isFrameInstr
argument_list|(
name|MI
argument_list|)
argument_list|)
block|;
comment|// Operands of ADJCALLSTACKDOWN/ADJCALLSTACKUP:
comment|// - argument declared in the pattern:
comment|// 0 - frame size
comment|// 1 - arg of CALLSEQ_START/CALLSEQ_END
comment|// 2 - predicate code (like ARMCC::AL)
comment|// - added by predOps:
comment|// 3 - predicate reg
return|return
name|MI
operator|.
name|getOperand
argument_list|(
literal|3
argument_list|)
operator|.
name|getReg
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// Get the operands corresponding to the given \p Pred value. By default, the
comment|/// predicate register is assumed to be 0 (no register), but you can pass in a
comment|/// \p PredReg if that is not the case.
specifier|static
specifier|inline
name|std
operator|::
name|array
operator|<
name|MachineOperand
block|,
literal|2
operator|>
name|predOps
argument_list|(
argument|ARMCC::CondCodes Pred
argument_list|,
argument|unsigned PredReg =
literal|0
argument_list|)
block|{
return|return
block|{
block|{
name|MachineOperand
operator|::
name|CreateImm
argument_list|(
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|Pred
operator|)
argument_list|)
block|,
name|MachineOperand
operator|::
name|CreateReg
argument_list|(
argument|PredReg
argument_list|,
argument|false
argument_list|)
block|}
block|}
return|;
block|}
comment|/// Get the operand corresponding to the conditional code result. By default,
comment|/// this is 0 (no register).
specifier|static
specifier|inline
name|MachineOperand
name|condCodeOp
argument_list|(
argument|unsigned CCReg =
literal|0
argument_list|)
block|{
return|return
name|MachineOperand
operator|::
name|CreateReg
argument_list|(
name|CCReg
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|/// Get the operand corresponding to the conditional code result for Thumb1.
comment|/// This operand will always refer to CPSR and it will have the Define flag set.
comment|/// You can optionally set the Dead flag by means of \p isDead.
specifier|static
specifier|inline
name|MachineOperand
name|t1CondCodeOp
argument_list|(
argument|bool isDead = false
argument_list|)
block|{
return|return
name|MachineOperand
operator|::
name|CreateReg
argument_list|(
name|ARM
operator|::
name|CPSR
argument_list|,
comment|/*Define*/
name|true
argument_list|,
comment|/*Implicit*/
name|false
argument_list|,
comment|/*Kill*/
name|false
argument_list|,
name|isDead
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isUncondBranchOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|B
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|tB
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2B
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isCondBranchOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|Bcc
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|tBcc
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2Bcc
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isJumpTableBranchOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|BR_JTr
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|BR_JTm
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|BR_JTadd
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|tBR_JTr
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2BR_JT
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isIndirectBranchOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|BX
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|MOVPCRX
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|tBRIND
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPopOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|tPOP_RET
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|LDMIA_RET
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2LDMIA_RET
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|tPOP
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|LDMIA_UPD
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2LDMIA_UPD
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|VLDMDIA_UPD
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPushOpcode
argument_list|(
argument|int Opc
argument_list|)
block|{
return|return
name|Opc
operator|==
name|ARM
operator|::
name|tPUSH
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|t2STMDB_UPD
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|STMDB_UPD
operator|||
name|Opc
operator|==
name|ARM
operator|::
name|VSTMDDB_UPD
return|;
block|}
comment|/// getInstrPredicate - If instruction is predicated, returns its predicate
comment|/// condition, otherwise returns AL. It also returns the condition code
comment|/// register by reference.
name|ARMCC
operator|::
name|CondCodes
name|getInstrPredicate
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
name|unsigned
operator|&
name|PredReg
argument_list|)
block|;
name|unsigned
name|getMatchingCondBranchOpcode
argument_list|(
argument|unsigned Opc
argument_list|)
block|;
comment|/// Determine if MI can be folded into an ARM MOVCC instruction, and return the
comment|/// opcode of the SSA instruction representing the conditional MI.
name|unsigned
name|canFoldARMInstrIntoMOVCC
argument_list|(
argument|unsigned Reg
argument_list|,
argument|MachineInstr *&MI
argument_list|,
argument|const MachineRegisterInfo&MRI
argument_list|)
block|;
comment|/// Map pseudo instructions that imply an 'S' bit onto real opcodes. Whether
comment|/// the instruction is encoded with an 'S' bit is determined by the optional
comment|/// CPSR def operand.
name|unsigned
name|convertAddSubFlagsOpcode
argument_list|(
argument|unsigned OldOpc
argument_list|)
block|;
comment|/// emitARMRegPlusImmediate / emitT2RegPlusImmediate - Emits a series of
comment|/// instructions to materializea destreg = basereg + immediate in ARM / Thumb2
comment|/// code.
name|void
name|emitARMRegPlusImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|const DebugLoc&dl
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int NumBytes
argument_list|,
argument|ARMCC::CondCodes Pred
argument_list|,
argument|unsigned PredReg
argument_list|,
argument|const ARMBaseInstrInfo&TII
argument_list|,
argument|unsigned MIFlags =
literal|0
argument_list|)
block|;
name|void
name|emitT2RegPlusImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|const DebugLoc&dl
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int NumBytes
argument_list|,
argument|ARMCC::CondCodes Pred
argument_list|,
argument|unsigned PredReg
argument_list|,
argument|const ARMBaseInstrInfo&TII
argument_list|,
argument|unsigned MIFlags =
literal|0
argument_list|)
block|;
name|void
name|emitThumbRegPlusImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|const DebugLoc&dl
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int NumBytes
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|const ARMBaseRegisterInfo&MRI
argument_list|,
argument|unsigned MIFlags =
literal|0
argument_list|)
block|;
comment|/// Tries to add registers to the reglist of a given base-updating
comment|/// push/pop instruction to adjust the stack by an additional
comment|/// NumBytes. This can save a few bytes per function in code-size, but
comment|/// obviously generates more memory traffic. As such, it only takes
comment|/// effect in functions being optimised for size.
name|bool
name|tryFoldSPUpdateIntoPushPop
argument_list|(
argument|const ARMSubtarget&Subtarget
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|unsigned NumBytes
argument_list|)
block|;
comment|/// rewriteARMFrameIndex / rewriteT2FrameIndex -
comment|/// Rewrite MI to access 'Offset' bytes from the FP. Return false if the
comment|/// offset could not be handled directly in MI, and return the left-over
comment|/// portion by reference.
name|bool
name|rewriteARMFrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned FrameRegIdx
argument_list|,
argument|unsigned FrameReg
argument_list|,
argument|int&Offset
argument_list|,
argument|const ARMBaseInstrInfo&TII
argument_list|)
block|;
name|bool
name|rewriteT2FrameIndex
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned FrameRegIdx
argument_list|,
argument|unsigned FrameReg
argument_list|,
argument|int&Offset
argument_list|,
argument|const ARMBaseInstrInfo&TII
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARMBASEINSTRINFO_H
end_comment

end_unit

