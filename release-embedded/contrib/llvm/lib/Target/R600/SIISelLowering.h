begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIISelLowering.h - SI DAG Lowering Interface ------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief SI DAG Lowering interface definition
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
name|SIISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|SIISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SIInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SITargetLowering
range|:
name|public
name|AMDGPUTargetLowering
block|{
specifier|const
name|SIInstrInfo
operator|*
name|TII
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
name|SDValue
name|LowerSTORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBRCOND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|foldImm
argument_list|(
argument|SDValue&Operand
argument_list|,
argument|int32_t&Immediate
argument_list|,
argument|bool&ScalarSlotUsed
argument_list|)
specifier|const
block|;
name|bool
name|fitsRegClass
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&Op
argument_list|,
argument|unsigned RegClass
argument_list|)
specifier|const
block|;
name|void
name|ensureSRegLimit
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&Operand
argument_list|,
argument|unsigned RegClass
argument_list|,
argument|bool&ScalarSlotUsed
argument_list|)
specifier|const
block|;
name|SDNode
operator|*
name|foldOperands
argument_list|(
argument|MachineSDNode *N
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|void
name|adjustWritemask
argument_list|(
argument|MachineSDNode *&N
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|public
operator|:
name|SITargetLowering
argument_list|(
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr * MI
argument_list|,
argument|MachineBasicBlock * BB
argument_list|)
specifier|const
block|;
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|virtual
name|SDNode
operator|*
name|PostISelFolding
argument_list|(
argument|MachineSDNode *N
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|AdjustInstrPostInstrSelection
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
name|int32_t
name|analyzeImmediate
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//SIISELLOWERING_H
end_comment

end_unit

