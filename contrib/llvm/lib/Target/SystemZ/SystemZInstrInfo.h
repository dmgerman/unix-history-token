begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZInstrInfo.h - SystemZ instruction information ----*- C++ -*-===//
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
comment|// This file contains the SystemZ implementation of the TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"SystemZ.h"
end_include

begin_include
include|#
directive|include
file|"SystemZRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
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
file|"SystemZGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SystemZSubtarget
decl_stmt|;
name|namespace
name|SystemZII
block|{
enum|enum
block|{
comment|// See comments in SystemZInstrFormats.td.
name|SimpleBDXLoad
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|SimpleBDXStore
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|Has20BitOffset
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|HasIndex
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|Is128Bit
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|AccessSizeMask
init|=
operator|(
literal|31
operator|<<
literal|5
operator|)
block|,
name|AccessSizeShift
init|=
literal|5
block|,
name|CCValuesMask
init|=
operator|(
literal|15
operator|<<
literal|10
operator|)
block|,
name|CCValuesShift
init|=
literal|10
block|,
name|CompareZeroCCMaskMask
init|=
operator|(
literal|15
operator|<<
literal|14
operator|)
block|,
name|CompareZeroCCMaskShift
init|=
literal|14
block|,
name|CCMaskFirst
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
block|,
name|CCMaskLast
init|=
operator|(
literal|1
operator|<<
literal|19
operator|)
block|,
name|IsLogical
init|=
operator|(
literal|1
operator|<<
literal|20
operator|)
block|}
enum|;
specifier|static
specifier|inline
name|unsigned
name|getAccessSize
parameter_list|(
name|unsigned
name|int
name|Flags
parameter_list|)
block|{
return|return
operator|(
name|Flags
operator|&
name|AccessSizeMask
operator|)
operator|>>
name|AccessSizeShift
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getCCValues
parameter_list|(
name|unsigned
name|int
name|Flags
parameter_list|)
block|{
return|return
operator|(
name|Flags
operator|&
name|CCValuesMask
operator|)
operator|>>
name|CCValuesShift
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getCompareZeroCCMask
parameter_list|(
name|unsigned
name|int
name|Flags
parameter_list|)
block|{
return|return
operator|(
name|Flags
operator|&
name|CompareZeroCCMaskMask
operator|)
operator|>>
name|CompareZeroCCMaskShift
return|;
block|}
comment|// SystemZ MachineOperand target flags.
enum|enum
block|{
comment|// Masks out the bits for the access model.
name|MO_SYMBOL_MODIFIER
init|=
operator|(
literal|3
operator|<<
literal|0
operator|)
block|,
comment|// @GOT (aka @GOTENT)
name|MO_GOT
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|// @INDNTPOFF
name|MO_INDNTPOFF
init|=
operator|(
literal|2
operator|<<
literal|0
operator|)
block|}
enum|;
comment|// Classifies a branch.
enum|enum
name|BranchType
block|{
comment|// An instruction that branches on the current value of CC.
name|BranchNormal
block|,
comment|// An instruction that peforms a 32-bit signed comparison and branches
comment|// on the result.
name|BranchC
block|,
comment|// An instruction that peforms a 32-bit unsigned comparison and branches
comment|// on the result.
name|BranchCL
block|,
comment|// An instruction that peforms a 64-bit signed comparison and branches
comment|// on the result.
name|BranchCG
block|,
comment|// An instruction that peforms a 64-bit unsigned comparison and branches
comment|// on the result.
name|BranchCLG
block|,
comment|// An instruction that decrements a 32-bit register and branches if
comment|// the result is nonzero.
name|BranchCT
block|,
comment|// An instruction that decrements a 64-bit register and branches if
comment|// the result is nonzero.
name|BranchCTG
block|}
enum|;
comment|// Information about a branch instruction.
struct|struct
name|Branch
block|{
comment|// The type of the branch.
name|BranchType
name|Type
decl_stmt|;
comment|// CCMASK_<N> is set if CC might be equal to N.
name|unsigned
name|CCValid
decl_stmt|;
comment|// CCMASK_<N> is set if the branch should be taken when CC == N.
name|unsigned
name|CCMask
decl_stmt|;
comment|// The target of the branch.
specifier|const
name|MachineOperand
modifier|*
name|Target
decl_stmt|;
name|Branch
argument_list|(
argument|BranchType type
argument_list|,
argument|unsigned ccValid
argument_list|,
argument|unsigned ccMask
argument_list|,
argument|const MachineOperand *target
argument_list|)
block|:
name|Type
argument_list|(
name|type
argument_list|)
operator|,
name|CCValid
argument_list|(
name|ccValid
argument_list|)
operator|,
name|CCMask
argument_list|(
name|ccMask
argument_list|)
operator|,
name|Target
argument_list|(
argument|target
argument_list|)
block|{}
block|}
struct|;
comment|// Kinds of fused compares in compare-and-* instructions.  Together with type
comment|// of the converted compare, this identifies the compare-and-*
comment|// instruction.
enum|enum
name|FusedCompareType
block|{
comment|// Relative branch - CRJ etc.
name|CompareAndBranch
block|,
comment|// Indirect branch, used for return - CRBReturn etc.
name|CompareAndReturn
block|,
comment|// Indirect branch, used for sibcall - CRBCall etc.
name|CompareAndSibcall
block|,
comment|// Trap
name|CompareAndTrap
block|}
enum|;
block|}
comment|// end namespace SystemZII
name|class
name|SystemZInstrInfo
range|:
name|public
name|SystemZGenInstrInfo
block|{
specifier|const
name|SystemZRegisterInfo
name|RI
block|;
name|SystemZSubtarget
operator|&
name|STI
block|;
name|void
name|splitMove
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned NewOpcode
argument_list|)
specifier|const
block|;
name|void
name|splitAdjDynAlloc
argument_list|(
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
name|void
name|expandRIPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned HighOpcode
argument_list|,
argument|bool ConvertHigh
argument_list|)
specifier|const
block|;
name|void
name|expandRIEPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned LowOpcodeK
argument_list|,
argument|unsigned HighOpcode
argument_list|)
specifier|const
block|;
name|void
name|expandRXYPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned HighOpcode
argument_list|)
specifier|const
block|;
name|void
name|expandLOCPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned HighOpcode
argument_list|)
specifier|const
block|;
name|void
name|expandLOCRPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned HighOpcode
argument_list|)
specifier|const
block|;
name|void
name|expandZExtPseudo
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned LowOpcode
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;
name|void
name|expandLoadStackGuard
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|;
name|MachineInstrBuilder
name|emitGRX32Move
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|const DebugLoc&DL
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned LowLowOpcode
argument_list|,
argument|unsigned Size
argument_list|,
argument|bool KillSrc
argument_list|,
argument|bool UndefSrc
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
comment|/// Commutes the operands in the given instruction by changing the operands
comment|/// order and/or changing the instruction's opcode and/or the immediate value
comment|/// operand.
comment|///
comment|/// The arguments 'CommuteOpIdx1' and 'CommuteOpIdx2' specify the operands
comment|/// to be commuted.
comment|///
comment|/// Do not call this method for a non-commutable instruction or
comment|/// non-commutable operands.
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
argument|unsigned CommuteOpIdx1
argument_list|,
argument|unsigned CommuteOpIdx2
argument_list|)
specifier|const
name|override
block|;
name|public
operator|:
name|explicit
name|SystemZInstrInfo
argument_list|(
name|SystemZSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|// Override TargetInstrInfo.
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
name|isStackSlotCopy
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|int&DestFrameIndex
argument_list|,
argument|int&SrcFrameIndex
argument_list|)
specifier|const
name|override
block|;
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
name|bool
name|isPredicable
argument_list|(
argument|const MachineInstr&MI
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
argument|unsigned NumCyclesT
argument_list|,
argument|unsigned ExtraPredCyclesT
argument_list|,
argument|MachineBasicBlock&FMBB
argument_list|,
argument|unsigned NumCyclesF
argument_list|,
argument|unsigned ExtraPredCyclesF
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
name|void
name|copyPhysReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
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
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
name|override
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
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr&MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|int FrameIndex
argument_list|,
argument|LiveIntervals *LIS = nullptr
argument_list|)
specifier|const
name|override
block|;
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr&MI
argument_list|,
argument|ArrayRef<unsigned> Ops
argument_list|,
argument|MachineBasicBlock::iterator InsertPt
argument_list|,
argument|MachineInstr&LoadMI
argument_list|,
argument|LiveIntervals *LIS = nullptr
argument_list|)
specifier|const
name|override
block|;
name|bool
name|expandPostRAPseudo
argument_list|(
argument|MachineInstr&MBBI
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
comment|// Return the SystemZRegisterInfo, which this class owns.
specifier|const
name|SystemZRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
comment|// Return the size in bytes of MI.
name|unsigned
name|getInstSizeInBytes
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
name|override
block|;
comment|// Return true if MI is a conditional or unconditional branch.
comment|// When returning true, set Cond to the mask of condition-code
comment|// values on which the instruction will branch, and set Target
comment|// to the operand that contains the branch target.  This target
comment|// can be a register or a basic block.
name|SystemZII
operator|::
name|Branch
name|getBranchInfo
argument_list|(
argument|const MachineInstr&MI
argument_list|)
specifier|const
block|;
comment|// Get the load and store opcodes for a given register class.
name|void
name|getLoadStoreOpcodes
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned&LoadOpcode
argument_list|,
argument|unsigned&StoreOpcode
argument_list|)
specifier|const
block|;
comment|// Opcode is the opcode of an instruction that has an address operand,
comment|// and the caller wants to perform that instruction's operation on an
comment|// address that has displacement Offset.  Return the opcode of a suitable
comment|// instruction (which might be Opcode itself) or 0 if no such instruction
comment|// exists.
name|unsigned
name|getOpcodeForOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
block|;
comment|// If Opcode is a load instruction that has a LOAD AND TEST form,
comment|// return the opcode for the testing form, otherwise return 0.
name|unsigned
name|getLoadAndTest
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|// Return true if ROTATE AND ... SELECTED BITS can be used to select bits
comment|// Mask of the R2 operand, given that only the low BitSize bits of Mask are
comment|// significant.  Set Start and End to the I3 and I4 operands if so.
name|bool
name|isRxSBGMask
argument_list|(
argument|uint64_t Mask
argument_list|,
argument|unsigned BitSize
argument_list|,
argument|unsigned&Start
argument_list|,
argument|unsigned&End
argument_list|)
specifier|const
block|;
comment|// If Opcode is a COMPARE opcode for which an associated fused COMPARE AND *
comment|// operation exists, return the opcode for the latter, otherwise return 0.
comment|// MI, if nonnull, is the compare instruction.
name|unsigned
name|getFusedCompare
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|SystemZII::FusedCompareType Type
argument_list|,
argument|const MachineInstr *MI = nullptr
argument_list|)
specifier|const
block|;
comment|// If Opcode is a LOAD opcode for with an associated LOAD AND TRAP
comment|// operation exists, returh the opcode for the latter, otherwise return 0.
name|unsigned
name|getLoadAndTrap
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|// Emit code before MBBI in MI to move immediate value Value into
comment|// physical register Reg.
name|void
name|loadImmediate
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|uint64_t Value
argument_list|)
specifier|const
block|;
comment|// Sometimes, it is possible for the target to tell, even without
comment|// aliasing information, that two MIs access different memory
comment|// addresses. This function returns true if two MIs access different
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
comment|// LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZINSTRINFO_H
end_comment

end_unit

