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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONISELLOWERING_H
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
comment|// Return true when the given node fits in a positive half word.
name|bool
name|isPositiveHalfWord
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|namespace
name|HexagonISD
block|{
enum|enum
name|NodeType
enum|:
name|unsigned
block|{
name|OP_BEGIN
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|CONST32
init|=
name|OP_BEGIN
block|,
name|CONST32_GP
block|,
comment|// For marking data present in GP.
name|FCONST32
block|,
name|ALLOCA
block|,
name|ARGEXTEND
block|,
name|PIC_ADD
block|,
name|AT_GOT
block|,
name|AT_PCREL
block|,
name|CALLv3
block|,
comment|// A V3+ call instruction.
name|CALLv3nr
block|,
comment|// A V3+ call instruction that doesn't return.
name|CALLR
block|,
name|RET_FLAG
block|,
comment|// Return with a flag operand.
name|BR_JT
block|,
comment|// Branch through jump table.
name|BARRIER
block|,
comment|// Memory barrier.
name|JT
block|,
comment|// Jump table.
name|CP
block|,
comment|// Constant pool.
name|POPCOUNT
block|,
name|COMBINE
block|,
name|PACKHL
block|,
name|VSPLATB
block|,
name|VSPLATH
block|,
name|SHUFFEB
block|,
name|SHUFFEH
block|,
name|SHUFFOB
block|,
name|SHUFFOH
block|,
name|VSXTBH
block|,
name|VSXTBW
block|,
name|VSRAW
block|,
name|VSRAH
block|,
name|VSRLW
block|,
name|VSRLH
block|,
name|VSHLW
block|,
name|VSHLH
block|,
name|VCMPBEQ
block|,
name|VCMPBGT
block|,
name|VCMPBGTU
block|,
name|VCMPHEQ
block|,
name|VCMPHGT
block|,
name|VCMPHGTU
block|,
name|VCMPWEQ
block|,
name|VCMPWGT
block|,
name|VCMPWGTU
block|,
name|INSERT
block|,
name|INSERTRP
block|,
name|EXTRACTU
block|,
name|EXTRACTURP
block|,
name|TC_RETURN
block|,
name|EH_RETURN
block|,
name|DCFETCH
block|,
name|OP_END
block|}
enum|;
block|}
name|class
name|HexagonSubtarget
decl_stmt|;
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
name|void
name|promoteLdStType
argument_list|(
argument|EVT VT
argument_list|,
argument|EVT PromotedLdStVT
argument_list|)
block|;
specifier|const
name|HexagonTargetMachine
operator|&
name|HTM
block|;
specifier|const
name|HexagonSubtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|HexagonTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|HexagonSubtarget
operator|&
name|ST
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
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|allowTruncateForTailCall
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
comment|// Should we expand the build vector with shuffles?
name|bool
name|shouldExpandBuildVectorWithShuffles
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned DefinedValues
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
name|LowerEXTRACT_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINSERT_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
name|override
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
name|override
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
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCTPOP
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
name|LowerLOAD
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
name|override
block|;
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
name|override
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
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
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
name|override
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
argument|const std::string&Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|const std::string&ConstraintCode
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|ConstraintCode
operator|==
literal|"o"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_o
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"v"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_v
return|;
return|return
name|TargetLowering
operator|::
name|getInlineAsmMemConstraint
argument_list|(
name|ConstraintCode
argument_list|)
return|;
block|}
comment|// Intrinsics
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
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
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
name|override
decl_stmt|;
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
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can
comment|/// compare a register against the immediate without having to materialize
comment|/// the immediate into a register.
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

