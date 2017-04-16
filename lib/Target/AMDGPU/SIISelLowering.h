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
name|LLVM_LIB_TARGET_AMDGPU_SIISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_SIISELLOWERING_H
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
name|final
range|:
name|public
name|AMDGPUTargetLowering
block|{
name|SDValue
name|lowerKernArgParameterPtr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|uint64_t Offset
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerKernargMemParameter
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|EVT MemVT
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|bool Signed
argument_list|,
argument|const ISD::InputArg *Arg = nullptr
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
name|lowerImplicitZextParam
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Op
argument_list|,
argument|MVT VT
argument_list|,
argument|unsigned Offset
argument_list|)
specifier|const
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
name|LowerINTRINSIC_W_CHAIN
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
name|lowerFastUnsafeFDIV
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFDIV_FAST
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFDIV16
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
name|LowerATOMIC_CMP_SWAP
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
comment|/// \brief Converts \p Op, which must be of floating point type, to the
comment|/// floating point type \p VT, by either extending or truncating it.
name|SDValue
name|getFPExtOrFPTrunc
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Op
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|SDValue
name|convertArgType
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT VT
argument_list|,
argument|EVT MemVT
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|SDValue Val
argument_list|,
argument|bool Signed
argument_list|,
argument|const ISD::InputArg *Arg = nullptr
argument_list|)
specifier|const
block|;
comment|/// \brief Custom lowering for ISD::FP_ROUND for MVT::f16.
name|SDValue
name|lowerFP_ROUND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|getSegmentAperture
argument_list|(
argument|unsigned AS
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerADDRSPACECAST
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerINSERT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerTRAP
argument_list|(
argument|SDValue Op
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
name|performMemSDNodeCombine
argument_list|(
argument|MemSDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|splitBinaryBitConstantOp
argument_list|(
argument|DAGCombinerInfo&DCI
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|unsigned Opc
argument_list|,
argument|SDValue LHS
argument_list|,
argument|const ConstantSDNode *CRHS
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
name|performXorCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performZeroExtendCombine
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
name|performFCanonicalizeCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performFPMed3ImmCombine
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|SDValue Op0
argument_list|,
argument|SDValue Op1
argument_list|)
specifier|const
block|;
name|SDValue
name|performIntMed3ImmCombine
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|SDValue Op0
argument_list|,
argument|SDValue Op1
argument_list|,
argument|bool Signed
argument_list|)
specifier|const
block|;
name|SDValue
name|performMinMaxCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performFMed3Combine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performCvtPkRTZCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|unsigned
name|getFusedOpcode
argument_list|(
argument|const SelectionDAG&DAG
argument_list|,
argument|const SDNode *N0
argument_list|,
argument|const SDNode *N1
argument_list|)
specifier|const
block|;
name|SDValue
name|performFAddCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performFSubCombine
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
name|SDValue
name|performCvtF32UByteNCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|bool
name|isLegalFlatAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|)
specifier|const
block|;
name|bool
name|isLegalMUBUFAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|)
specifier|const
block|;
name|unsigned
name|isCFIntrinsic
argument_list|(
argument|const SDNode *Intr
argument_list|)
specifier|const
block|;
name|void
name|createDebuggerPrologueStackObjects
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \returns True if fixup needs to be emitted for given global value \p GV,
comment|/// false otherwise.
name|bool
name|shouldEmitFixup
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
comment|/// \returns True if GOT relocation needs to be emitted for given global value
comment|/// \p GV, false otherwise.
name|bool
name|shouldEmitGOTReloc
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
comment|/// \returns True if PC-relative relocation needs to be emitted for given
comment|/// global value \p GV, false otherwise.
name|bool
name|shouldEmitPCReloc
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
name|public
operator|:
name|SITargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|tm
argument_list|,
specifier|const
name|SISubtarget
operator|&
name|STI
argument_list|)
block|;
specifier|const
name|SISubtarget
operator|*
name|getSubtarget
argument_list|()
specifier|const
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
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInfo&
argument_list|,
argument|const CallInst&
argument_list|,
argument|unsigned IntrinsicID
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getAddrModeArguments
argument_list|(
argument|IntrinsicInst *
comment|/*I*/
argument_list|,
argument|SmallVectorImpl<Value*>&
comment|/*Ops*/
argument_list|,
argument|Type *&
comment|/*AccessTy*/
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|,
argument|unsigned AS
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
name|bool
name|isMemOpUniform
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|;
name|bool
name|isMemOpHasNoClobberedMemOperand
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
block|;
name|bool
name|isNoopAddrSpaceCast
argument_list|(
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCheapAddrSpaceCast
argument_list|(
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
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
name|bool
name|isTypeDesirableForOp
argument_list|(
argument|unsigned Op
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
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
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegisterByName
argument_list|(
argument|const char* RegName
argument_list|,
argument|EVT VT
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|splitKillBlock
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
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
name|bool
name|enableAggressiveFMAFusion
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getSetCCResultType
argument_list|(
argument|const DataLayout&DL
argument_list|,
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
argument|const DataLayout&
argument_list|,
argument|EVT
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
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
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
argument|MachineInstr&MI
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
name|override
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
name|SDNode
operator|*
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
argument|const SDLoc&DL
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
argument|const SDLoc&DL
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|uint32_t RsrcDword1
argument_list|,
argument|uint64_t RsrcDword2And3
argument_list|)
specifier|const
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|copyToM0
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Chain
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SDValue V
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

