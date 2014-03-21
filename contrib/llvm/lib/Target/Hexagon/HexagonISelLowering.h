begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonISelLowering.h - Hexagon DAG Lowering Interface --*- C++ -*-===//
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
comment|// This file defines the interfaces that Hexagon uses to lower LLVM code into a
end_comment

begin_comment
comment|// selection DAG.
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
name|Hexagon_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|Hexagon_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"Hexagon.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
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
name|namespace
name|HexagonISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|CONST32
block|,
name|CONST32_GP
block|,
comment|// For marking data present in GP.
name|CONST32_Int_Real
block|,
name|FCONST32
block|,
name|SETCC
block|,
name|ADJDYNALLOC
block|,
name|ARGEXTEND
block|,
name|CMPICC
block|,
comment|// Compare two GPR operands, set icc.
name|CMPFCC
block|,
comment|// Compare two FP operands, set fcc.
name|BRICC
block|,
comment|// Branch to dest on icc condition
name|BRFCC
block|,
comment|// Branch to dest on fcc condition
name|SELECT_ICC
block|,
comment|// Select between two values using the current ICC flags.
name|SELECT_FCC
block|,
comment|// Select between two values using the current FCC flags.
name|Hi
block|,
name|Lo
block|,
comment|// Hi/Lo operations, typically on a global address.
name|FTOI
block|,
comment|// FP to Int within a FP register.
name|ITOF
block|,
comment|// Int to FP within a FP register.
name|CALL
block|,
comment|// A call instruction.
name|RET_FLAG
block|,
comment|// Return with a flag operand.
name|BR_JT
block|,
comment|// Jump table.
name|BARRIER
block|,
comment|// Memory barrier.
name|WrapperJT
block|,
name|WrapperCP
block|,
name|WrapperCombineII
block|,
name|WrapperCombineRR
block|,
name|WrapperCombineRI_V4
block|,
name|WrapperCombineIR_V4
block|,
name|WrapperPackhl
block|,
name|WrapperSplatB
block|,
name|WrapperSplatH
block|,
name|WrapperShuffEB
block|,
name|WrapperShuffEH
block|,
name|WrapperShuffOB
block|,
name|WrapperShuffOH
block|,
name|TC_RETURN
block|,
name|EH_RETURN
block|}
enum|;
block|}
name|class
name|HexagonTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|int
name|VarArgsFrameOffset
block|;
comment|// Frame offset to start of varargs area.
name|bool
name|CanReturnSmallStruct
argument_list|(
argument|const Function* CalleeFn
argument_list|,
argument|unsigned& RetSize
argument_list|)
specifier|const
block|;
name|public
operator|:
name|HexagonTargetMachine
operator|&
name|TM
block|;
name|explicit
name|HexagonTargetLowering
argument_list|(
name|HexagonTargetMachine
operator|&
name|targetmachine
argument_list|)
block|;
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization. Targets which want to do tail call
comment|/// optimization should implement this function.
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CalleeCC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isCalleeStructRet
argument_list|,
argument|bool isCallerStructRet
argument_list|,
argument|const                                       SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|allowTruncateForTailCall
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
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
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBR_JT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
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
name|LowerINLINEASM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEH_LABEL
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEH_RETURN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
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
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGLOBALADDRESS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBlockAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCallResult
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDValue Callee
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
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerATOMIC_FENCE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
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
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|VT
operator|.
name|isVector
argument_list|()
condition|)
return|return
name|MVT
operator|::
name|i1
return|;
else|else
return|return
name|EVT
operator|::
name|getVectorVT
argument_list|(
name|C
argument_list|,
name|MVT
operator|::
name|i1
argument_list|,
name|VT
operator|.
name|getVectorNumElements
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|bool
name|getPostIndexedAddressParts
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDNode *Op
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|,
argument|ISD::MemIndexedMode&AM
argument_list|,
argument|SelectionDAG&DAG
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
argument|MVT VT
argument_list|)
specifier|const
block|;
comment|// Intrinsics
name|virtual
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can
comment|/// compare a register against the immediate without having to materialize
comment|/// the immediate into a register.
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Hexagon_ISELLOWERING_H
end_comment

end_unit

