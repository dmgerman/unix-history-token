begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUISelLowering.h - Cell SPU DAG Lowering Interface -----*- C++ -*-===//
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
comment|// This file defines the interfaces that Cell SPU uses to lower LLVM code into
end_comment

begin_comment
comment|// a selection DAG.
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
name|SPU_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|SPU_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"SPU.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|SPUISD
block|{
enum|enum
name|NodeType
block|{
comment|// Start the numbering where the builting ops and target ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// Pseudo instructions:
name|RET_FLAG
block|,
comment|///< Return with flag, matched by bi instruction
name|Hi
block|,
comment|///< High address component (upper 16)
name|Lo
block|,
comment|///< Low address component (lower 16)
name|PCRelAddr
block|,
comment|///< Program counter relative address
name|AFormAddr
block|,
comment|///< A-form address (local store)
name|IndirectAddr
block|,
comment|///< D-Form "imm($r)" and X-form "$r($r)"
name|LDRESULT
block|,
comment|///< Load result (value, chain)
name|CALL
block|,
comment|///< CALL instruction
name|SHUFB
block|,
comment|///< Vector shuffle (permute)
name|SHUFFLE_MASK
block|,
comment|///< Shuffle mask
name|CNTB
block|,
comment|///< Count leading ones in bytes
name|PREFSLOT2VEC
block|,
comment|///< Promote scalar->vector
name|VEC2PREFSLOT
block|,
comment|///< Extract element 0
name|SHLQUAD_L_BITS
block|,
comment|///< Rotate quad left, by bits
name|SHLQUAD_L_BYTES
block|,
comment|///< Rotate quad left, by bytes
name|VEC_ROTL
block|,
comment|///< Vector rotate left
name|VEC_ROTR
block|,
comment|///< Vector rotate right
name|ROTBYTES_LEFT
block|,
comment|///< Rotate bytes (loads -> ROTQBYI)
name|ROTBYTES_LEFT_BITS
block|,
comment|///< Rotate bytes left by bit shift count
name|SELECT_MASK
block|,
comment|///< Select Mask (FSM, FSMB, FSMH, FSMBI)
name|SELB
block|,
comment|///< Select bits -> (b& mask) | (a& ~mask)
comment|// Markers: These aren't used to generate target-dependent nodes, but
comment|// are used during instruction selection.
name|ADD64_MARKER
block|,
comment|///< i64 addition marker
name|SUB64_MARKER
block|,
comment|///< i64 subtraction marker
name|MUL64_MARKER
block|,
comment|///< i64 multiply marker
name|LAST_SPUISD
comment|///< Last user-defined instruction
block|}
enum|;
block|}
comment|//! Utility functions specific to CellSPU:
name|namespace
name|SPU
block|{
name|SDValue
name|get_vec_u18imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|EVT
name|ValueType
parameter_list|)
function_decl|;
name|SDValue
name|get_vec_i16imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|EVT
name|ValueType
parameter_list|)
function_decl|;
name|SDValue
name|get_vec_i10imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|EVT
name|ValueType
parameter_list|)
function_decl|;
name|SDValue
name|get_vec_i8imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|EVT
name|ValueType
parameter_list|)
function_decl|;
name|SDValue
name|get_ILHUvec_imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|EVT
name|ValueType
parameter_list|)
function_decl|;
name|SDValue
name|get_v4i32_imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
name|SDValue
name|get_v2i64_imm
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
name|SDValue
name|LowerConstantPool
parameter_list|(
name|SDValue
name|Op
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
specifier|const
name|SPUTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|//! Simplify a EVT::v2i64 constant splat to CellSPU-ready form
name|SDValue
name|LowerV2I64Splat
parameter_list|(
name|EVT
name|OpVT
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|uint64_t
name|splat
parameter_list|,
name|DebugLoc
name|dl
parameter_list|)
function_decl|;
block|}
name|class
name|SPUTargetMachine
decl_stmt|;
comment|// forward dec'l.
name|class
name|SPUTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|int
name|VarArgsFrameIndex
block|;
comment|// FrameIndex for start of varargs area.
name|SPUTargetMachine
operator|&
name|SPUTM
block|;
name|public
operator|:
comment|//! The venerable constructor
comment|/*!      This is where the CellSPU backend sets operation handling (i.e., legal,      custom, expand or promote.)      */
name|SPUTargetLowering
argument_list|(
name|SPUTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|//! Get the target machine
name|SPUTargetMachine
operator|&
name|getSPUTargetMachine
argument_list|()
block|{
return|return
name|SPUTM
return|;
block|}
comment|/// getTargetNodeName() - This method returns the name of a target specific
comment|/// DAG node.
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
comment|/// getSetCCResultType - Return the ValueType for ISD::SETCC
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|//! Custom lowering hooks
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|//! Custom lowering hook for nodes with illegal result types.
name|virtual
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
name|void
name|computeMaskedBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|const APInt&Mask
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
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&ConstraintLetter
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
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|char ConstraintLetter
argument_list|,
argument|bool hasMemory
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// isLegalAddressImmediate - Return true if the integer value can be used
comment|/// as the offset of the target addressing mode.
name|virtual
name|bool
name|isLegalAddressImmediate
argument_list|(
argument|int64_t V
argument_list|,
argument|const Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isLegalAddressImmediate
argument_list|(
argument|GlobalValue *
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
argument|const Function *F
argument_list|)
specifier|const
block|;
name|virtual
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isTailCall
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

