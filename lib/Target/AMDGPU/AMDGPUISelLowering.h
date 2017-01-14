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
name|protected
operator|:
specifier|const
name|AMDGPUSubtarget
operator|*
name|Subtarget
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
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
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
name|LowerFROUND32
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
name|void
name|AnalyzeFormalArguments
argument_list|(
argument|CCState&State
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|)
specifier|const
block|;
name|void
name|AnalyzeReturn
argument_list|(
argument|CCState&State
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
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
name|isFAbsFree
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFNegFree
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|EVT Src
argument_list|,
argument|EVT Dest
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Src
argument_list|,
argument|Type *Dest
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|Type *Src
argument_list|,
argument|Type *Dest
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|EVT Src
argument_list|,
argument|EVT Dest
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|SDValue Val
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isNarrowingProfitable
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|MVT
name|getVectorIdxTy
argument_list|(
argument|const DataLayout&
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSelectSupported
argument_list|(
argument|SelectSupportKind
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|ShouldShrinkFPConstant
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldReduceLoadWidth
argument_list|(
argument|SDNode *Load
argument_list|,
argument|ISD::LoadExtType ExtType
argument_list|,
argument|EVT ExtVT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLoadBitCastBeneficial
argument_list|(
argument|EVT
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|final
block|;
name|bool
name|storeOfVectorConstantIsCheap
argument_list|(
argument|EVT MemVT
argument_list|,
argument|unsigned NumElem
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
name|override
block|;
name|bool
name|aggressivelyPreferBuildVectorSources
argument_list|(
argument|EVT VecVT
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCheapToSpeculateCttz
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
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
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerDYNAMIC_STACKALLOC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
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
name|CombineFMinMaxLegacy
argument_list|(
argument|const SDLoc&DL
argument_list|,
argument|EVT VT
argument_list|,
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|SDValue True
argument_list|,
argument|SDValue False
argument_list|,
argument|SDValue CC
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFsqrtCheap
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|SDValue
name|getSqrtEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&RefinementSteps
argument_list|,
argument|bool&UseOneConstNR
argument_list|,
argument|bool Reciprocal
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|getRecipEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&RefinementSteps
argument_list|)
specifier|const
name|override
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
operator|=
literal|0
block|;
comment|/// \brief Determine which of the bits specified in \p Mask are known to be
comment|/// either zero or one and return them in the \p KnownZero and \p KnownOne
comment|/// bitsets.
name|void
name|computeKnownBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
argument|SDValue Op
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Helper function that adds Reg to the LiveIn list of the DAG's
comment|/// MachineFunction.
comment|///
comment|/// \returns a RegisterSDNode representing Reg.
name|virtual
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
block|;    enum
name|ImplicitParameter
block|{
name|FIRST_IMPLICIT
block|,
name|GRID_DIM
operator|=
name|FIRST_IMPLICIT
block|,
name|GRID_OFFSET
block|,   }
block|;
comment|/// \brief Helper function that returns the byte offset of the given
comment|/// type of implicit parameter.
name|uint32_t
name|getImplicitParameterOffset
argument_list|(
argument|const AMDGPUMachineFunction *MFI
argument_list|,
argument|const ImplicitParameter Param
argument_list|)
specifier|const
block|; }
decl_stmt|;
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
name|CALL
block|,
comment|// Function call based on a single integer
name|UMUL
block|,
comment|// 32bit unsigned multiplication
name|BRANCH_COND
block|,
comment|// End AMDIL ISD Opcodes
name|ENDPGM
block|,
name|RETURN
block|,
name|DWORDADDR
block|,
name|FRACT
block|,
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
name|LOAD_INPUT
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
comment|// End namespace AMDGPUISD
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

