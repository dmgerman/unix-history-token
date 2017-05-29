begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUISelLowering.h - AMDGPU Lowering Interface --------*- C++ -*-===//
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
comment|/// \brief Interface definition of the TargetLowering class that is common
end_comment

begin_comment
comment|/// to all AMD GPUs.
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUMachineFunction
decl_stmt|;
name|class
name|AMDGPUSubtarget
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|AMDGPUTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|private
operator|:
comment|/// \returns AMDGPUISD::FFBH_U32 node if the incoming \p Op may have been
comment|/// legalized from a smaller type VT. Need to match pre-legalized type because
comment|/// the generic legalization inserts the add/sub between the select and
comment|/// compare.
name|SDValue
name|getFFBH_U32
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Op
argument_list|,
argument|const SDLoc&DL
argument_list|)
specifier|const
block|;
name|public
operator|:
specifier|static
name|bool
name|isOrEquivalentToAdd
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Op
argument_list|)
block|;
name|protected
operator|:
specifier|const
name|AMDGPUSubtarget
operator|*
name|Subtarget
block|;
name|AMDGPUAS
name|AMDGPUASI
block|;
name|SDValue
name|LowerEXTRACT_SUBVECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCONCAT_VECTORS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// \brief Split a vector store into multiple scalar stores.
comment|/// \returns The resulting chain.
name|SDValue
name|LowerFREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFCEIL
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFTRUNC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFRINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFNEARBYINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFROUND32_16
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFROUND64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFROUND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFFLOOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCTLZ
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINT_TO_FP32
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
name|LowerINT_TO_FP64
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
name|LowerUINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP64_TO_INT
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
name|LowerFP_TO_FP16
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_UINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_SINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSIGN_EXTEND_INREG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|bool
name|shouldCombineMemoryType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|SDValue
name|performLoadCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performStoreCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performClampCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|splitBinaryBitConstantOpImpl
argument_list|(
argument|DAGCombinerInfo&DCI
argument_list|,
argument|const SDLoc&SL
argument_list|,
argument|unsigned Opc
argument_list|,
argument|SDValue LHS
argument_list|,
argument|uint32_t ValLo
argument_list|,
argument|uint32_t ValHi
argument_list|)
specifier|const
block|;
name|SDValue
name|performShlCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performSraCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performSrlCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performMulCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performMulhsCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performMulhuCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performMulLoHi24Combine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performCtlzCombine
argument_list|(
argument|const SDLoc&SL
argument_list|,
argument|SDValue Cond
argument_list|,
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performSelectCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performFNegCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|performFAbsCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
specifier|static
name|EVT
name|getEquivalentMemType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
block|;
name|virtual
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
block|;
comment|/// Return 64-bit value Op as two 32-bit integers.
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|split64BitValue
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|getLoHalf64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|getHiHalf64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// \brief Split a vector load into 2 loads of half the vector.
name|SDValue
name|SplitVectorLoad
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// \brief Split a vector store into 2 stores of half the vector.
name|SDValue
name|SplitVectorStore
argument_list|(
argument|SDValue Op
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
name|LowerSDIVREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerUDIVREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerDIVREM24
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool sign
argument_list|)
specifier|const
block|;
name|void
name|LowerUDIVREM64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|)
specifier|const
block|;
name|void
name|analyzeFormalArgumentsCompute
argument_list|(
argument|CCState&State
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|)
specifier|const
block|;
name|public
operator|:
name|AMDGPUTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|AMDGPUSubtarget
operator|&
name|STI
argument_list|)
block|;
name|bool
name|mayIgnoreSignedZero
argument_list|(
argument|SDValue Op
argument_list|)
specifier|const
block|{
if|if
condition|(
name|getTargetMachine
argument_list|()
operator|.
name|Options
operator|.
name|NoSignedZerosFPMath
condition|)
return|return
name|true
return|;
specifier|const
name|auto
name|Flags
operator|=
name|Op
operator|.
name|getNode
argument_list|()
operator|->
name|getFlags
argument_list|()
block|;
if|if
condition|(
name|Flags
operator|.
name|isDefined
argument_list|()
condition|)
return|return
name|Flags
operator|.
name|hasNoSignedZeros
argument_list|()
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_function_decl
specifier|static
name|bool
name|allUsesHaveSourceMods
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|CostThreshold
init|=
literal|4
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|isFAbsFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isFNegFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isTruncateFree
argument_list|(
name|EVT
name|Src
argument_list|,
name|EVT
name|Dest
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|Src
argument_list|,
name|Type
operator|*
name|Dest
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
argument_list|(
name|Type
operator|*
name|Src
argument_list|,
name|Type
operator|*
name|Dest
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
argument_list|(
name|EVT
name|Src
argument_list|,
name|EVT
name|Dest
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
argument_list|(
name|SDValue
name|Val
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isNarrowingProfitable
argument_list|(
name|EVT
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MVT
name|getVectorIdxTy
argument_list|(
specifier|const
name|DataLayout
operator|&
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isSelectSupported
argument_list|(
name|SelectSupportKind
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isFPImmLegal
argument_list|(
specifier|const
name|APFloat
operator|&
name|Imm
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ShouldShrinkFPConstant
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|shouldReduceLoadWidth
argument_list|(
name|SDNode
operator|*
name|Load
argument_list|,
name|ISD
operator|::
name|LoadExtType
name|ExtType
argument_list|,
name|EVT
name|ExtVT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isLoadBitCastBeneficial
argument_list|(
name|EVT
argument_list|,
name|EVT
argument_list|)
decl|const
name|final
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|storeOfVectorConstantIsCheap
argument_list|(
name|EVT
name|MemVT
argument_list|,
name|unsigned
name|NumElem
argument_list|,
name|unsigned
name|AS
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|aggressivelyPreferBuildVectorSources
argument_list|(
name|EVT
name|VecVT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|isCheapToSpeculateCttz
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|CCAssignFn
modifier|*
name|CCAssignFnForCall
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|,
name|bool
name|IsVarArg
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|CCAssignFn
modifier|*
name|CCAssignFnForReturn
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|,
name|bool
name|IsVarArg
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerReturn
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SDLoc
operator|&
name|DL
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall
argument_list|(
name|CallLoweringInfo
operator|&
name|CLI
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerDYNAMIC_STACKALLOC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerOperation
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|PerformDAGCombine
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReplaceNodeResults
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|Results
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineFMinMaxLegacy
argument_list|(
specifier|const
name|SDLoc
operator|&
name|DL
argument_list|,
name|EVT
name|VT
argument_list|,
name|SDValue
name|LHS
argument_list|,
name|SDValue
name|RHS
argument_list|,
name|SDValue
name|True
argument_list|,
name|SDValue
name|False
argument_list|,
name|SDValue
name|CC
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getTargetNodeName
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isFsqrtCheap
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
block|{
return|return
name|true
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getSqrtEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|int
name|Enabled
argument_list|,
name|int
operator|&
name|RefinementSteps
argument_list|,
name|bool
operator|&
name|UseOneConstNR
argument_list|,
name|bool
name|Reciprocal
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getRecipEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|int
name|Enabled
argument_list|,
name|int
operator|&
name|RefinementSteps
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|SDNode
modifier|*
name|PostISelFolding
argument_list|(
name|MachineSDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine which of the bits specified in \p Mask are known to be
end_comment

begin_comment
comment|/// either zero or one and return them in the \p KnownZero and \p KnownOne
end_comment

begin_comment
comment|/// bitsets.
end_comment

begin_decl_stmt
name|void
name|computeKnownBitsForTargetNode
argument_list|(
specifier|const
name|SDValue
name|Op
argument_list|,
name|KnownBits
operator|&
name|Known
argument_list|,
specifier|const
name|APInt
operator|&
name|DemandedElts
argument_list|,
specifier|const
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
name|SDValue
name|Op
argument_list|,
specifier|const
name|APInt
operator|&
name|DemandedElts
argument_list|,
specifier|const
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Helper function that adds Reg to the LiveIn list of the DAG's
end_comment

begin_comment
comment|/// MachineFunction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a RegisterSDNode representing Reg.
end_comment

begin_decl_stmt
name|virtual
name|SDValue
name|CreateLiveInRegister
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|ImplicitParameter
block|{
name|FIRST_IMPLICIT
block|,
name|GRID_DIM
init|=
name|FIRST_IMPLICIT
block|,
name|GRID_OFFSET
block|,   }
enum|;
end_enum

begin_comment
comment|/// \brief Helper function that returns the byte offset of the given
end_comment

begin_comment
comment|/// type of implicit parameter.
end_comment

begin_decl_stmt
name|uint32_t
name|getImplicitParameterOffset
argument_list|(
specifier|const
name|AMDGPUMachineFunction
operator|*
name|MFI
argument_list|,
specifier|const
name|ImplicitParameter
name|Param
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|AMDGPUAS
name|getAMDGPUAS
argument_list|()
specifier|const
block|{
return|return
name|AMDGPUASI
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|MVT
name|getFenceOperandTy
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
name|override
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
end_decl_stmt

begin_decl_stmt
unit|};
name|namespace
name|AMDGPUISD
block|{
enum|enum
name|NodeType
enum|:
name|unsigned
block|{
comment|// AMDIL ISD Opcodes
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|UMUL
block|,
comment|// 32bit unsigned multiplication
name|BRANCH_COND
block|,
comment|// End AMDIL ISD Opcodes
comment|// Function call.
name|CALL
block|,
name|TRAP
block|,
comment|// Masked control flow nodes.
name|IF
block|,
name|ELSE
block|,
name|LOOP
block|,
comment|// A uniform kernel return that terminates the wavefront.
name|ENDPGM
block|,
comment|// Return to a shader part's epilog code.
name|RETURN_TO_EPILOG
block|,
comment|// Return with values from a non-entry function.
name|RET_FLAG
block|,
name|DWORDADDR
block|,
name|FRACT
block|,
comment|/// CLAMP value between 0.0 and 1.0. NaN clamped to 0, following clamp output
comment|/// modifier behavior with dx10_enable.
name|CLAMP
block|,
comment|// This is SETCC with the full mask result which is used for a compare with a
comment|// result bit per item in the wavefront.
name|SETCC
block|,
name|SETREG
block|,
comment|// FP ops with input and output chain.
name|FMA_W_CHAIN
block|,
name|FMUL_W_CHAIN
block|,
comment|// SIN_HW, COS_HW - f32 for SI, 1 ULP max error, valid from -100 pi to 100 pi.
comment|// Denormals handled on some parts.
name|COS_HW
block|,
name|SIN_HW
block|,
name|FMAX_LEGACY
block|,
name|FMIN_LEGACY
block|,
name|FMAX3
block|,
name|SMAX3
block|,
name|UMAX3
block|,
name|FMIN3
block|,
name|SMIN3
block|,
name|UMIN3
block|,
name|FMED3
block|,
name|SMED3
block|,
name|UMED3
block|,
name|URECIP
block|,
name|DIV_SCALE
block|,
name|DIV_FMAS
block|,
name|DIV_FIXUP
block|,
comment|// For emitting ISD::FMAD when f32 denormals are enabled because mac/mad is
comment|// treated as an illegal operation.
name|FMAD_FTZ
block|,
name|TRIG_PREOP
block|,
comment|// 1 ULP max error for f64
comment|// RCP, RSQ - For f32, 1 ULP max error, no denormal handling.
comment|//            For f64, max error 2^29 ULP, handles denormals.
name|RCP
block|,
name|RSQ
block|,
name|RCP_LEGACY
block|,
name|RSQ_LEGACY
block|,
name|FMUL_LEGACY
block|,
name|RSQ_CLAMP
block|,
name|LDEXP
block|,
name|FP_CLASS
block|,
name|DOT4
block|,
name|CARRY
block|,
name|BORROW
block|,
name|BFE_U32
block|,
comment|// Extract range of bits with zero extension to 32-bits.
name|BFE_I32
block|,
comment|// Extract range of bits with sign extension to 32-bits.
name|BFI
block|,
comment|// (src0& src1) | (~src0& src2)
name|BFM
block|,
comment|// Insert a range of bits into a 32-bit word.
name|FFBH_U32
block|,
comment|// ctlz with -1 if input is zero.
name|FFBH_I32
block|,
name|MUL_U24
block|,
name|MUL_I24
block|,
name|MULHI_U24
block|,
name|MULHI_I24
block|,
name|MAD_U24
block|,
name|MAD_I24
block|,
name|MUL_LOHI_I24
block|,
name|MUL_LOHI_U24
block|,
name|TEXTURE_FETCH
block|,
name|EXPORT
block|,
comment|// exp on SI+
name|EXPORT_DONE
block|,
comment|// exp on SI+ with done bit set
name|R600_EXPORT
block|,
name|CONST_ADDRESS
block|,
name|REGISTER_LOAD
block|,
name|REGISTER_STORE
block|,
name|SAMPLE
block|,
name|SAMPLEB
block|,
name|SAMPLED
block|,
name|SAMPLEL
block|,
comment|// These cvt_f32_ubyte* nodes need to remain consecutive and in order.
name|CVT_F32_UBYTE0
block|,
name|CVT_F32_UBYTE1
block|,
name|CVT_F32_UBYTE2
block|,
name|CVT_F32_UBYTE3
block|,
comment|// Convert two float 32 numbers into a single register holding two packed f16
comment|// with round to zero.
name|CVT_PKRTZ_F16_F32
block|,
comment|// Same as the standard node, except the high bits of the resulting integer
comment|// are known 0.
name|FP_TO_FP16
block|,
comment|// Wrapper around fp16 results that are known to zero the high bits.
name|FP16_ZEXT
block|,
comment|/// This node is for VLIW targets and it is used to represent a vector
comment|/// that is stored in consecutive registers with the same channel.
comment|/// For example:
comment|///   |X  |Y|Z|W|
comment|/// T0|v.x| | | |
comment|/// T1|v.y| | | |
comment|/// T2|v.z| | | |
comment|/// T3|v.w| | | |
name|BUILD_VERTICAL_VECTOR
block|,
comment|/// Pointer to the start of the shader's constant data.
name|CONST_DATA_PTR
block|,
name|INIT_EXEC
block|,
name|INIT_EXEC_FROM_INPUT
block|,
name|SENDMSG
block|,
name|SENDMSGHALT
block|,
name|INTERP_MOV
block|,
name|INTERP_P1
block|,
name|INTERP_P2
block|,
name|PC_ADD_REL_OFFSET
block|,
name|KILL
block|,
name|DUMMY_CHAIN
block|,
name|FIRST_MEM_OPCODE_NUMBER
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|STORE_MSKOR
block|,
name|LOAD_CONSTANT
block|,
name|TBUFFER_STORE_FORMAT
block|,
name|ATOMIC_CMP_SWAP
block|,
name|ATOMIC_INC
block|,
name|ATOMIC_DEC
block|,
name|BUFFER_LOAD
block|,
name|BUFFER_LOAD_FORMAT
block|,
name|LAST_AMDGPU_ISD_NUMBER
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace AMDGPUISD
end_comment

begin_comment
unit|}
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

