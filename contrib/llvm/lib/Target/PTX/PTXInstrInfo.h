begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PTXInstrInfo.h - PTX Instruction Information -------------*- C++ -*-===//
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
comment|// This file contains the PTX implementation of the TargetInstrInfo class.
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
name|PTX_INSTR_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_INSTR_INFO_H
end_define

begin_include
include|#
directive|include
file|"PTXRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PTXTargetMachine
decl_stmt|;
name|class
name|MachineSDNode
decl_stmt|;
name|class
name|SDValue
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|PTXInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
name|private
operator|:
specifier|const
name|PTXRegisterInfo
name|RI
block|;
name|PTXTargetMachine
operator|&
name|TM
block|;
name|public
operator|:
name|explicit
name|PTXInstrInfo
argument_list|(
name|PTXTargetMachine
operator|&
name|_TM
argument_list|)
block|;
name|virtual
specifier|const
name|PTXRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
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
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool KillSrc
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|copyRegToReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|const TargetRegisterClass *DstRC
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isMoveInstr
argument_list|(
argument|const MachineInstr& MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SrcSubIdx
argument_list|,
argument|unsigned&DstSubIdx
argument_list|)
specifier|const
block|;
comment|// predicate support
name|virtual
name|bool
name|isPredicated
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr *MI
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
comment|// PTX is fully-predicable
name|virtual
name|bool
name|isPredicable
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|// branch support
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
comment|// static helper routines
specifier|static
name|MachineSDNode
operator|*
name|GetPTXMachineNode
argument_list|(
argument|SelectionDAG *DAG
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|EVT VT
argument_list|,
argument|SDValue Op1
argument_list|)
block|;
specifier|static
name|MachineSDNode
operator|*
name|GetPTXMachineNode
argument_list|(
argument|SelectionDAG *DAG
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|EVT VT
argument_list|,
argument|SDValue Op1
argument_list|,
argument|SDValue Op2
argument_list|)
block|;
specifier|static
name|void
name|AddDefaultPredicate
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
specifier|static
name|bool
name|IsAnyKindOfBranch
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|inst
argument_list|)
block|;
specifier|static
name|bool
name|IsAnySuccessorAlsoLayoutSuccessor
argument_list|(
specifier|const
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
block|;
specifier|static
name|MachineBasicBlock
operator|*
name|GetBranchTarget
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|inst
argument_list|)
block|; }
decl_stmt|;
comment|// class PTXInstrInfo
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_INSTR_INFO_H
end_comment

end_unit

