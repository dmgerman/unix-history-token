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
name|AMDGPUISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPUISELLOWERING_H
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
name|void
name|ExtractVectorElements
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&Args
argument_list|,
argument|unsigned Start
argument_list|,
argument|unsigned Count
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
comment|/// \brief Lower vector stores by merging the vector elements into an integer
comment|/// of the same bitwidth.
name|SDValue
name|MergeVectorStore
argument_list|(
argument|const SDValue&Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// \brief Split a vector store into multiple scalar stores.
comment|/// \returns The resulting chain.
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
name|LowerUINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|protected
operator|:
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
block|;
comment|/// \brief Split a vector load into multiple scalar loads.
name|SDValue
name|SplitVectorLoad
argument_list|(
argument|const SDValue&Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
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
comment|/// The SelectionDAGBuilder will automatically promote function arguments
comment|/// with illegal types.  However, this does not work for the AMDGPU targets
comment|/// since the function arguments are stored in memory as these illegal types.
comment|/// In order to handle this properly we need to get the origianl types sizes
comment|/// from the LLVM IR Function and fixup the ISD:InputArg values before
comment|/// passing them to AnalyzeFormalArguments()
name|void
name|getOriginalFunctionArgs
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const Function *F
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SmallVectorImpl<ISD::InputArg>&OrigIns
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
name|public
operator|:
name|AMDGPUTargetLowering
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|bool
name|isFAbsFree
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isFNegFree
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|MVT
name|getVectorIdxTy
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|isLoadBitCastBeneficial
argument_list|(
argument|EVT
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
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
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|{
name|CLI
operator|.
name|Callee
operator|.
name|dump
argument_list|()
block|;
name|llvm_unreachable
argument_list|(
literal|"Undefined function"
argument_list|)
block|;   }
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
name|SDValue
name|LowerIntrinsicIABS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerIntrinsicLRP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerMinMax
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
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
block|{
return|return
name|N
return|;
block|}
comment|// Functions defined in AMDILISelLowering.cpp
name|public
operator|:
comment|/// \brief Determine which of the bits specified in \p Mask are known to be
comment|/// either zero or one and return them in the \p KnownZero and \p KnownOne
comment|/// bitsets.
name|virtual
name|void
name|computeMaskedBitsForTargetNode
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
block|;
name|virtual
name|bool
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInfo&Info
argument_list|,
argument|const CallInst&I
argument_list|,
argument|unsigned Intrinsic
argument_list|)
specifier|const
block|;
comment|/// We want to mark f32/f64 floating point values as legal.
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// We don't want to shrink f64/f32 constants.
name|bool
name|ShouldShrinkFPConstant
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|InitAMDILLowering
argument_list|()
block|;
name|SDValue
name|LowerSREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSREM8
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSREM16
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSREM32
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSREM64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSDIV
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSDIV24
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSDIV32
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSDIV64
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
name|EVT
name|genIntType
argument_list|(
argument|uint32_t size =
literal|32
argument_list|,
argument|uint32_t numEle =
literal|1
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
name|LowerFP_ROUND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|namespace
name|AMDGPUISD
block|{
enum|enum
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
name|DIV_INF
block|,
comment|// Divide with infinity returned on zero divisor
name|RET_FLAG
block|,
name|BRANCH_COND
block|,
comment|// End AMDIL ISD Opcodes
name|DWORDADDR
block|,
name|FRACT
block|,
name|COS_HW
block|,
name|SIN_HW
block|,
name|FMAX
block|,
name|SMAX
block|,
name|UMAX
block|,
name|FMIN
block|,
name|SMIN
block|,
name|UMIN
block|,
name|URECIP
block|,
name|DOT4
block|,
name|TEXTURE_FETCH
block|,
name|EXPORT
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

begin_comment
comment|// AMDGPUISELLOWERING_H
end_comment

end_unit

