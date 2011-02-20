begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMBaseInstrInfo.h - ARM Base Instruction Information ----*- C++ -*-===//
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
name|ARMBASEINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMBASEINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMBaseRegisterInfo
decl_stmt|;
comment|/// ARMII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|ARMII
block|{
enum|enum
block|{
comment|//===------------------------------------------------------------------===//
comment|// Instruction Flags.
comment|//===------------------------------------------------------------------===//
comment|// This four-bit field describes the addressing mode used.
name|AddrModeMask
init|=
literal|0x1f
block|,
name|AddrModeNone
init|=
literal|0
block|,
name|AddrMode1
init|=
literal|1
block|,
name|AddrMode2
init|=
literal|2
block|,
name|AddrMode3
init|=
literal|3
block|,
name|AddrMode4
init|=
literal|4
block|,
name|AddrMode5
init|=
literal|5
block|,
name|AddrMode6
init|=
literal|6
block|,
name|AddrModeT1_1
init|=
literal|7
block|,
name|AddrModeT1_2
init|=
literal|8
block|,
name|AddrModeT1_4
init|=
literal|9
block|,
name|AddrModeT1_s
init|=
literal|10
block|,
comment|// i8 * 4 for pc and sp relative data
name|AddrModeT2_i12
init|=
literal|11
block|,
name|AddrModeT2_i8
init|=
literal|12
block|,
name|AddrModeT2_so
init|=
literal|13
block|,
name|AddrModeT2_pc
init|=
literal|14
block|,
comment|// +/- i12 for pc relative data
name|AddrModeT2_i8s4
init|=
literal|15
block|,
comment|// i8 * 4
name|AddrMode_i12
init|=
literal|16
block|,
comment|// Size* - Flags to keep track of the size of an instruction.
name|SizeShift
init|=
literal|5
block|,
name|SizeMask
init|=
literal|7
operator|<<
name|SizeShift
block|,
name|SizeSpecial
init|=
literal|1
block|,
comment|// 0 byte pseudo or special case.
name|Size8Bytes
init|=
literal|2
block|,
name|Size4Bytes
init|=
literal|3
block|,
name|Size2Bytes
init|=
literal|4
block|,
comment|// IndexMode - Unindex, pre-indexed, or post-indexed are valid for load
comment|// and store ops only.  Generic "updating" flag is used for ld/st multiple.
name|IndexModeShift
init|=
literal|8
block|,
name|IndexModeMask
init|=
literal|3
operator|<<
name|IndexModeShift
block|,
name|IndexModePre
init|=
literal|1
block|,
name|IndexModePost
init|=
literal|2
block|,
name|IndexModeUpd
init|=
literal|3
block|,
comment|//===------------------------------------------------------------------===//
comment|// Instruction encoding formats.
comment|//
name|FormShift
init|=
literal|10
block|,
name|FormMask
init|=
literal|0x3f
operator|<<
name|FormShift
block|,
comment|// Pseudo instructions
name|Pseudo
init|=
literal|0
operator|<<
name|FormShift
block|,
comment|// Multiply instructions
name|MulFrm
init|=
literal|1
operator|<<
name|FormShift
block|,
comment|// Branch instructions
name|BrFrm
init|=
literal|2
operator|<<
name|FormShift
block|,
name|BrMiscFrm
init|=
literal|3
operator|<<
name|FormShift
block|,
comment|// Data Processing instructions
name|DPFrm
init|=
literal|4
operator|<<
name|FormShift
block|,
name|DPSoRegFrm
init|=
literal|5
operator|<<
name|FormShift
block|,
comment|// Load and Store
name|LdFrm
init|=
literal|6
operator|<<
name|FormShift
block|,
name|StFrm
init|=
literal|7
operator|<<
name|FormShift
block|,
name|LdMiscFrm
init|=
literal|8
operator|<<
name|FormShift
block|,
name|StMiscFrm
init|=
literal|9
operator|<<
name|FormShift
block|,
name|LdStMulFrm
init|=
literal|10
operator|<<
name|FormShift
block|,
name|LdStExFrm
init|=
literal|11
operator|<<
name|FormShift
block|,
comment|// Miscellaneous arithmetic instructions
name|ArithMiscFrm
init|=
literal|12
operator|<<
name|FormShift
block|,
name|SatFrm
init|=
literal|13
operator|<<
name|FormShift
block|,
comment|// Extend instructions
name|ExtFrm
init|=
literal|14
operator|<<
name|FormShift
block|,
comment|// VFP formats
name|VFPUnaryFrm
init|=
literal|15
operator|<<
name|FormShift
block|,
name|VFPBinaryFrm
init|=
literal|16
operator|<<
name|FormShift
block|,
name|VFPConv1Frm
init|=
literal|17
operator|<<
name|FormShift
block|,
name|VFPConv2Frm
init|=
literal|18
operator|<<
name|FormShift
block|,
name|VFPConv3Frm
init|=
literal|19
operator|<<
name|FormShift
block|,
name|VFPConv4Frm
init|=
literal|20
operator|<<
name|FormShift
block|,
name|VFPConv5Frm
init|=
literal|21
operator|<<
name|FormShift
block|,
name|VFPLdStFrm
init|=
literal|22
operator|<<
name|FormShift
block|,
name|VFPLdStMulFrm
init|=
literal|23
operator|<<
name|FormShift
block|,
name|VFPMiscFrm
init|=
literal|24
operator|<<
name|FormShift
block|,
comment|// Thumb format
name|ThumbFrm
init|=
literal|25
operator|<<
name|FormShift
block|,
comment|// Miscelleaneous format
name|MiscFrm
init|=
literal|26
operator|<<
name|FormShift
block|,
comment|// NEON formats
name|NGetLnFrm
init|=
literal|27
operator|<<
name|FormShift
block|,
name|NSetLnFrm
init|=
literal|28
operator|<<
name|FormShift
block|,
name|NDupFrm
init|=
literal|29
operator|<<
name|FormShift
block|,
name|NLdStFrm
init|=
literal|30
operator|<<
name|FormShift
block|,
name|N1RegModImmFrm
init|=
literal|31
operator|<<
name|FormShift
block|,
name|N2RegFrm
init|=
literal|32
operator|<<
name|FormShift
block|,
name|NVCVTFrm
init|=
literal|33
operator|<<
name|FormShift
block|,
name|NVDupLnFrm
init|=
literal|34
operator|<<
name|FormShift
block|,
name|N2RegVShLFrm
init|=
literal|35
operator|<<
name|FormShift
block|,
name|N2RegVShRFrm
init|=
literal|36
operator|<<
name|FormShift
block|,
name|N3RegFrm
init|=
literal|37
operator|<<
name|FormShift
block|,
name|N3RegVShFrm
init|=
literal|38
operator|<<
name|FormShift
block|,
name|NVExtFrm
init|=
literal|39
operator|<<
name|FormShift
block|,
name|NVMulSLFrm
init|=
literal|40
operator|<<
name|FormShift
block|,
name|NVTBLFrm
init|=
literal|41
operator|<<
name|FormShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// Misc flags.
comment|// UnaryDP - Indicates this is a unary data processing instruction, i.e.
comment|// it doesn't have a Rn operand.
name|UnaryDP
init|=
literal|1
operator|<<
literal|16
block|,
comment|// Xform16Bit - Indicates this Thumb2 instruction may be transformed into
comment|// a 16-bit Thumb instruction if certain conditions are met.
name|Xform16Bit
init|=
literal|1
operator|<<
literal|17
block|,
comment|//===------------------------------------------------------------------===//
comment|// Code domain.
name|DomainShift
init|=
literal|18
block|,
name|DomainMask
init|=
literal|3
operator|<<
name|DomainShift
block|,
name|DomainGeneral
init|=
literal|0
operator|<<
name|DomainShift
block|,
name|DomainVFP
init|=
literal|1
operator|<<
name|DomainShift
block|,
name|DomainNEON
init|=
literal|2
operator|<<
name|DomainShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// Field shifts - such shifts are used to set field while generating
comment|// machine instructions.
comment|//
comment|// FIXME: This list will need adjusting/fixing as the MC code emitter
comment|// takes shape and the ARMCodeEmitter.cpp bits go away.
name|ShiftTypeShift
init|=
literal|4
block|,
name|M_BitShift
init|=
literal|5
block|,
name|ShiftImmShift
init|=
literal|5
block|,
name|ShiftShift
init|=
literal|7
block|,
name|N_BitShift
init|=
literal|7
block|,
name|ImmHiShift
init|=
literal|8
block|,
name|SoRotImmShift
init|=
literal|8
block|,
name|RegRsShift
init|=
literal|8
block|,
name|ExtRotImmShift
init|=
literal|10
block|,
name|RegRdLoShift
init|=
literal|12
block|,
name|RegRdShift
init|=
literal|12
block|,
name|RegRdHiShift
init|=
literal|16
block|,
name|RegRnShift
init|=
literal|16
block|,
name|S_BitShift
init|=
literal|20
block|,
name|W_BitShift
init|=
literal|21
block|,
name|AM3_I_BitShift
init|=
literal|22
block|,
name|D_BitShift
init|=
literal|22
block|,
name|U_BitShift
init|=
literal|23
block|,
name|P_BitShift
init|=
literal|24
block|,
name|I_BitShift
init|=
literal|25
block|,
name|CondShift
init|=
literal|28
block|}
enum|;
block|}
name|class
name|ARMBaseInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
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
name|public
operator|:
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
argument|const TargetMachine *TM
argument_list|,
argument|const ScheduleDAG *DAG
argument_list|)
specifier|const
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
block|;
comment|// Branch analysis.
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
block|;
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
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
block|;
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
comment|// Predication support.
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
name|int
name|PIdx
operator|=
name|MI
operator|->
name|findFirstPredOperandIdx
argument_list|()
block|;
return|return
name|PIdx
operator|!=
operator|-
literal|1
operator|&&
name|MI
operator|->
name|getOperand
argument_list|(
name|PIdx
argument_list|)
operator|.
name|getImm
argument_list|()
operator|!=
name|ARMCC
operator|::
name|AL
return|;
block|}
name|ARMCC
operator|::
name|CondCodes
name|getPredicate
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|{
name|int
name|PIdx
operator|=
name|MI
operator|->
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
operator|->
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
name|bool
name|SubsumesPredicate
argument_list|(
argument|const SmallVectorImpl<MachineOperand>&Pred1
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Pred2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|DefinesPredicate
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|std::vector<MachineOperand>&Pred
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isPredicable
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// GetInstSize - Returns the size of the specified MachineInstr.
comment|///
name|virtual
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr* MI
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
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
block|;
name|virtual
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
block|;
name|virtual
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
block|;
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
argument|DebugLoc DL
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
argument|unsigned SubIdx
argument_list|,
argument|const MachineInstr *Orig
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|)
specifier|const
block|;
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
comment|/// areLoadsFromSameBasePtr - This is used by the pre-regalloc scheduler to
comment|/// determine if two loads are loading from the same base address. It should
comment|/// only return true if the base pointers are the same and the only
comment|/// differences between the two addresses is the offset. It also returns the
comment|/// offsets by reference.
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
block|;
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
argument|float Prob
argument_list|,
argument|float Confidence
argument_list|)
specifier|const
block|;
name|virtual
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
argument|float Probability
argument_list|,
argument|float Confidence
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isProfitableToDupForIfCvt
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|unsigned NumCyles
argument_list|,
argument|float Probability
argument_list|,
argument|float Confidence
argument_list|)
specifier|const
block|{
return|return
name|NumCyles
operator|==
literal|1
return|;
block|}
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
argument|int&CmpMask
argument_list|,
argument|int&CmpValue
argument_list|)
specifier|const
block|;
comment|/// OptimizeCompareInstr - Convert the instruction to set the zero flag so
comment|/// that we can remove a "comparison with zero".
name|virtual
name|bool
name|OptimizeCompareInstr
argument_list|(
argument|MachineInstr *CmpInstr
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|int CmpMask
argument_list|,
argument|int CmpValue
argument_list|,
argument|const MachineRegisterInfo *MRI
argument_list|)
specifier|const
block|;
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
block|;
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
name|private
operator|:
name|int
name|getVLDMDefCycle
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|const TargetInstrDesc&DefTID
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
argument|const TargetInstrDesc&DefTID
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
argument|const TargetInstrDesc&UseTID
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
argument|const TargetInstrDesc&UseTID
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
argument|const TargetInstrDesc&DefTID
argument_list|,
argument|unsigned DefIdx
argument_list|,
argument|unsigned DefAlign
argument_list|,
argument|const TargetInstrDesc&UseTID
argument_list|,
argument|unsigned UseIdx
argument_list|,
argument|unsigned UseAlign
argument_list|)
specifier|const
block|;
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
name|int
name|getInstrLatency
argument_list|(
argument|const InstrItineraryData *ItinData
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
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
block|;
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
expr|}
block|;
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
operator|&
name|AddDefaultPred
argument_list|(
argument|const MachineInstrBuilder&MIB
argument_list|)
block|{
return|return
name|MIB
operator|.
name|addImm
argument_list|(
operator|(
name|int64_t
operator|)
name|ARMCC
operator|::
name|AL
argument_list|)
operator|.
name|addReg
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
operator|&
name|AddDefaultCC
argument_list|(
argument|const MachineInstrBuilder&MIB
argument_list|)
block|{
return|return
name|MIB
operator|.
name|addReg
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
operator|&
name|AddDefaultT1CC
argument_list|(
argument|const MachineInstrBuilder&MIB
argument_list|,
argument|bool isDead = false
argument_list|)
block|{
return|return
name|MIB
operator|.
name|addReg
argument_list|(
name|ARM
operator|::
name|CPSR
argument_list|,
name|getDefRegState
argument_list|(
name|true
argument_list|)
operator||
name|getDeadRegState
argument_list|(
name|isDead
argument_list|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
operator|&
name|AddNoT1CC
argument_list|(
argument|const MachineInstrBuilder&MIB
argument_list|)
block|{
return|return
name|MIB
operator|.
name|addReg
argument_list|(
literal|0
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
operator|*
name|MI
argument_list|,
name|unsigned
operator|&
name|PredReg
argument_list|)
block|;
name|int
name|getMatchingCondBranchOpcode
argument_list|(
argument|int Opc
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
argument|DebugLoc dl
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
argument_list|)
block|;
name|void
name|emitT2RegPlusImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|DebugLoc dl
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
argument_list|)
block|;
name|void
name|emitThumbRegPlusImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int NumBytes
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|const ARMBaseRegisterInfo& MRI
argument_list|,
argument|DebugLoc dl
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

