begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600ISelLowering.h - R600 DAG Lowering Interface -*- C++ -*--------===//
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
comment|/// \brief R600 DAG Lowering interface definition
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
name|LLVM_LIB_TARGET_AMDGPU_R600ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_R600ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUISelLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|R600InstrInfo
decl_stmt|;
name|class
name|R600Subtarget
decl_stmt|;
name|class
name|R600TargetLowering
name|final
range|:
name|public
name|AMDGPUTargetLowering
block|{
name|public
operator|:
name|R600TargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|R600Subtarget
operator|&
name|STI
argument_list|)
block|;
specifier|const
name|R600Subtarget
operator|*
name|getSubtarget
argument_list|()
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
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
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode * N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
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
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getSetCCResultType
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|LLVMContext&
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|canMergeStoresTo
argument_list|(
argument|unsigned AS
argument_list|,
argument|EVT MemVT
argument_list|,
argument|const SelectionDAG&DAG
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
name|private
operator|:
name|unsigned
name|Gen
block|;
comment|/// Each OpenCL kernel has nine implicit parameters that are stored in the
comment|/// first nine dwords of a Vertex Buffer.  These implicit parameters are
comment|/// lowered to load instructions which retrieve the values from the Vertex
comment|/// Buffer.
name|SDValue
name|LowerImplicitParameter
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|unsigned DwordOffset
argument_list|)
specifier|const
block|;
name|void
name|lowerImplicitParameter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock&BB
argument_list|,
argument|MachineRegisterInfo& MRI
argument_list|,
argument|unsigned dword_offset
argument_list|)
specifier|const
block|;
name|SDValue
name|OptimizeSwizzle
argument_list|(
argument|SDValue BuildVector
argument_list|,
argument|SDValue Swz[]
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const SDLoc&DL
argument_list|)
specifier|const
block|;
name|SDValue
name|vectorToVerticalVector
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Vector
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFrameIndex
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
argument|SDValue Op
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
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerPrivateTruncStore
argument_list|(
argument|StoreSDNode *Store
argument_list|,
argument|SelectionDAG&DAG
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
name|lowerFP_TO_UINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFP_TO_SINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerPrivateExtLoad
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
name|LowerBRCOND
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
name|LowerSHLParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSRXParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerUADDSUBO
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned mainop
argument_list|,
argument|unsigned ovf
argument_list|)
specifier|const
block|;
name|SDValue
name|stackPtrToRegIndex
argument_list|(
argument|SDValue Ptr
argument_list|,
argument|unsigned StackWidth
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|void
name|getStackAddress
argument_list|(
argument|unsigned StackWidth
argument_list|,
argument|unsigned ElemIdx
argument_list|,
argument|unsigned&Channel
argument_list|,
argument|unsigned&PtrIncr
argument_list|)
specifier|const
block|;
name|bool
name|isZero
argument_list|(
argument|SDValue Op
argument_list|)
specifier|const
block|;
name|bool
name|isHWTrueValue
argument_list|(
argument|SDValue Op
argument_list|)
specifier|const
block|;
name|bool
name|isHWFalseValue
argument_list|(
argument|SDValue Op
argument_list|)
specifier|const
block|;
name|bool
name|FoldOperand
argument_list|(
argument|SDNode *ParentNode
argument_list|,
argument|unsigned SrcIdx
argument_list|,
argument|SDValue&Src
argument_list|,
argument|SDValue&Neg
argument_list|,
argument|SDValue&Abs
argument_list|,
argument|SDValue&Sel
argument_list|,
argument|SDValue&Imm
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
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
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

