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
name|LLVM_LIB_TARGET_R600_SIISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_SIISELLOWERING_H
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
name|SDValue
name|LowerParameter
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|unsigned Offset
argument_list|,
argument|bool Signed
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSampleIntrinsic
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|const SDValue&Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|AMDGPUMachineFunction *MFI
argument_list|,
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINTRINSIC_VOID
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFrameIndex
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerLOAD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFastFDIV
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFDIV32
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFDIV64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFDIV
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool Signed
argument_list|)
specifier|const
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
name|LowerTrig
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
specifier|const
name|TargetRegisterClass
operator|*
name|getRegClassForNode
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const SDValue&Op
argument_list|)
specifier|const
block|;
name|bool
name|fitsRegClass
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const SDValue&Op
argument_list|,
argument|unsigned RegClass
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
name|MachineSDNode
operator|*
name|AdjustRegClass
argument_list|(
argument|MachineSDNode *N
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|performUCharToFloatCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performSHLPtrCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|unsigned AS
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performAndCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performOrCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performClassCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performMin3Max3Combine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performSetCCCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
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
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&
comment|/*Mask*/
argument_list|,
argument|EVT
comment|/*VT*/
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AS
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool *IsFast
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getOptimalMemOpType
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned DstAlign
argument_list|,
argument|unsigned SrcAlign
argument_list|,
argument|bool IsMemset
argument_list|,
argument|bool ZeroMemset
argument_list|,
argument|bool MemcpyStrSrc
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
name|TargetLoweringBase
operator|::
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
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
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr * MI
argument_list|,
argument|MachineBasicBlock * BB
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
name|override
block|;
name|SDNode
operator|*
name|PostISelFolding
argument_list|(
argument|MachineSDNode *N
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|void
name|AdjustInstrPostInstrSelection
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
name|override
block|;
name|int32_t
name|analyzeImmediate
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|;
name|SDValue
name|CreateLiveInRegister
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|unsigned Reg
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|void
name|legalizeTargetIndependentNode
argument_list|(
argument|SDNode *Node
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|MachineSDNode
operator|*
name|wrapAddr64Rsrc
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Ptr
argument_list|)
specifier|const
block|;
name|MachineSDNode
operator|*
name|buildRSRC
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|uint32_t RsrcDword1
argument_list|,
argument|uint64_t RsrcDword2And3
argument_list|)
specifier|const
block|;
name|MachineSDNode
operator|*
name|buildScratchRSRC
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Ptr
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

end_unit

