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
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
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
block|{
name|SDValue
name|pred_reg
operator|=
name|DAG
operator|->
name|getRegister
argument_list|(
literal|0
argument_list|,
name|MVT
operator|::
name|i1
argument_list|)
block|;
name|SDValue
name|pred_imm
operator|=
name|DAG
operator|->
name|getTargetConstant
argument_list|(
literal|0
argument_list|,
name|MVT
operator|::
name|i32
argument_list|)
block|;
name|SDValue
name|ops
index|[]
operator|=
block|{
name|Op1
block|,
name|pred_reg
block|,
name|pred_imm
block|}
block|;
return|return
name|DAG
operator|->
name|getMachineNode
argument_list|(
name|Opcode
argument_list|,
name|dl
argument_list|,
name|VT
argument_list|,
name|ops
argument_list|,
name|array_lengthof
argument_list|(
name|ops
argument_list|)
argument_list|)
return|;
block|}
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
block|{
name|SDValue
name|pred_reg
operator|=
name|DAG
operator|->
name|getRegister
argument_list|(
literal|0
argument_list|,
name|MVT
operator|::
name|i1
argument_list|)
block|;
name|SDValue
name|pred_imm
operator|=
name|DAG
operator|->
name|getTargetConstant
argument_list|(
literal|0
argument_list|,
name|MVT
operator|::
name|i32
argument_list|)
block|;
name|SDValue
name|ops
index|[]
operator|=
block|{
name|Op1
block|,
name|Op2
block|,
name|pred_reg
block|,
name|pred_imm
block|}
block|;
return|return
name|DAG
operator|->
name|getMachineNode
argument_list|(
name|Opcode
argument_list|,
name|dl
argument_list|,
name|VT
argument_list|,
name|ops
argument_list|,
name|array_lengthof
argument_list|(
name|ops
argument_list|)
argument_list|)
return|;
block|}
expr|}
block|;
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

