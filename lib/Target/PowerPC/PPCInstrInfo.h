begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCInstrInfo.h - PowerPC Instruction Information --------*- C++ -*-===//
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
comment|// This file contains the PowerPC implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_POWERPC_PPCINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"PPCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"PPCGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PPCII - This namespace holds all of the PowerPC target-specific
comment|/// per-instruction flags.  These must match the corresponding definitions in
comment|/// PPC.td and PPCInstrFormats.td.
name|namespace
name|PPCII
block|{
enum|enum
block|{
comment|// PPC970 Instruction Flags.  These flags describe the characteristics of the
comment|// PowerPC 970 (aka G5) dispatch groups and how they are formed out of
comment|// raw machine instructions.
comment|/// PPC970_First - This instruction starts a new dispatch group, so it will
comment|/// always be the first one in the group.
name|PPC970_First
init|=
literal|0x1
block|,
comment|/// PPC970_Single - This instruction starts a new dispatch group and
comment|/// terminates it, so it will be the sole instruction in the group.
name|PPC970_Single
init|=
literal|0x2
block|,
comment|/// PPC970_Cracked - This instruction is cracked into two pieces, requiring
comment|/// two dispatch pipes to be available to issue.
name|PPC970_Cracked
init|=
literal|0x4
block|,
comment|/// PPC970_Mask/Shift - This is a bitmask that selects the pipeline type that
comment|/// an instruction is issued to.
name|PPC970_Shift
init|=
literal|3
block|,
name|PPC970_Mask
init|=
literal|0x07
operator|<<
name|PPC970_Shift
block|}
enum|;
enum|enum
name|PPC970_Unit
block|{
comment|/// These are the various PPC970 execution unit pipelines.  Each instruction
comment|/// is one of these.
name|PPC970_Pseudo
init|=
literal|0
operator|<<
name|PPC970_Shift
block|,
comment|// Pseudo instruction
name|PPC970_FXU
init|=
literal|1
operator|<<
name|PPC970_Shift
block|,
comment|// Fixed Point (aka Integer/ALU) Unit
name|PPC970_LSU
init|=
literal|2
operator|<<
name|PPC970_Shift
block|,
comment|// Load Store Unit
name|PPC970_FPU
init|=
literal|3
operator|<<
name|PPC970_Shift
block|,
comment|// Floating Point Unit
name|PPC970_CRU
init|=
literal|4
operator|<<
name|PPC970_Shift
block|,
comment|// Control Register Unit
name|PPC970_VALU
init|=
literal|5
operator|<<
name|PPC970_Shift
block|,
comment|// Vector ALU
name|PPC970_VPERM
init|=
literal|6
operator|<<
name|PPC970_Shift
block|,
comment|// Vector Permute Unit
name|PPC970_BRU
init|=
literal|7
operator|<<
name|PPC970_Shift
comment|// Branch Unit
block|}
enum|;
enum|enum
block|{
comment|/// Shift count to bypass PPC970 flags
name|NewDef_Shift
init|=
literal|6
block|,
comment|/// The VSX instruction that uses VSX register (vs0-vs63), instead of VMX
comment|/// register (v0-v31).
name|UseVSXReg
init|=
literal|0x1
operator|<<
name|NewDef_Shift
block|}
enum|;
block|}
comment|// end namespace PPCII
name|class
name|PPCSubtarget
decl_stmt|;
name|class
name|PPCInstrInfo
range|:
name|public
name|PPCGenInstrInfo
block|{
name|PPCSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|PPCRegisterInfo
name|RI
block|;
name|bool
name|StoreRegToStackSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|,
argument|bool&NonRI
argument_list|,
argument|bool&SpillsVRS
argument_list|)
specifier|const
block|;
name|bool
name|LoadRegFromStackSlot
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|SmallVectorImpl<MachineInstr *>&NewMIs
argument_list|,
argument|bool&NonRI
argument_list|,
argument|bool&SpillsVRS
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
comment|/// Commutes the operands in the given instruction.
comment|/// The commutable operands are specified by their indices OpIdx1 and OpIdx2.
comment|///
comment|/// Do not call this method for a non-commutable instruction or for
comment|/// non-commutable pair of operand indices OpIdx1 and OpIdx2.
comment|/// Even though the instruction is commutable, the method may still
comment|/// fail to commute the operands, null pointer is returned in such cases.
comment|///
comment|/// For example, we can commute rlwimi instructions, but only if the
comment|/// rotate amt is zero.  We also have to munge the immediates a bit.
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
name|explicit
name|PPCInstrInfo
argument_list|(
name|PPCSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
specifier|const
name|PPCRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
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
block|{
return|return
name|PPCGenInstrInfo
operator|::
name|getOperandLatency
argument_list|(
name|ItinData
argument_list|,
name|DefNode
argument_list|,
name|DefIdx
argument_list|,
name|UseNode
argument_list|,
name|UseIdx
argument_list|)
return|;
block|}
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
block|{
comment|// Machine LICM should hoist all instructions in low-register-pressure
comment|// situations; none are sufficiently free to justify leaving in a loop
comment|// body.
return|return
name|false
return|;
block|}
name|bool
name|useMachineCombiner
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// Return true when there is potentially a faster code sequence
comment|/// for an instruction chain ending in<Root>. All potential patterns are
comment|/// output in the<Pattern> array.
name|bool
name|getMachineCombinerPatterns
argument_list|(
argument|MachineInstr&Root
argument_list|,
argument|SmallVectorImpl<MachineCombinerPattern>&P
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isAssociativeAndCommutative
argument_list|(
argument|const MachineInstr&Inst
argument_list|)
specifier|const
name|override
block|;
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
name|bool
name|findCommutedOpIndices
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned&SrcOpIdx1
argument_list|,
argument|unsigned&SrcOpIdx2
argument_list|)
specifier|const
name|override
block|;
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
argument|bool AllowModify
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
comment|// Select analysis.
name|bool
name|canInsertSelect
argument_list|(
argument|const MachineBasicBlock&
argument_list|,
argument|ArrayRef<MachineOperand> Cond
argument_list|,
argument|unsigned
argument_list|,
argument|unsigned
argument_list|,
argument|int&
argument_list|,
argument|int&
argument_list|,
argument|int&
argument_list|)
specifier|const
name|override
block|;
name|void
name|insertSelect
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const DebugLoc&DL
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
name|override
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
name|reverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
name|override
block|;
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
comment|// If conversion by predication (only supported by some branch instructions).
comment|// All of the profitability checks always return true; it is always
comment|// profitable to use the predicated branches.
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
block|{
return|return
name|true
return|;
block|}
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
name|true
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
block|{
return|return
name|false
return|;
block|}
comment|// Predication support.
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
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
comment|// Comparison optimization.
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
name|bool
name|optimizeCompareInstr
argument_list|(
argument|MachineInstr&CmpInstr
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
name|override
block|;
comment|/// GetInstSize - Return the number of bytes of code the specified
comment|/// instruction may be.  This returns the maximum number of bytes.
comment|///
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
name|void
name|getNoop
argument_list|(
argument|MCInst&NopInst
argument_list|)
specifier|const
name|override
block|;
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
argument|unsigned TF
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
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
name|override
block|;
comment|// Lower pseudo instructions after register allocation.
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|isVFRegister
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
return|return
name|Reg
operator|>=
name|PPC
operator|::
name|VF0
operator|&&
name|Reg
operator|<=
name|PPC
operator|::
name|VF31
return|;
block|}
specifier|static
name|bool
name|isVRRegister
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
return|return
name|Reg
operator|>=
name|PPC
operator|::
name|V0
operator|&&
name|Reg
operator|<=
name|PPC
operator|::
name|V31
return|;
block|}
specifier|const
name|TargetRegisterClass
operator|*
name|updatedRC
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

