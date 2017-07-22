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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|ALLOCA
block|,
name|AT_GOT
block|,
comment|// Index in GOT.
name|AT_PCREL
block|,
comment|// Offset relative to PC.
name|CALL
block|,
comment|// Function call.
name|CALLnr
block|,
comment|// Function call that does not return.
name|CALLR
block|,
name|RET_FLAG
block|,
comment|// Return with a flag operand.
name|BARRIER
block|,
comment|// Memory barrier.
name|JT
block|,
comment|// Jump table.
name|CP
block|,
comment|// Constant pool.
name|COMBINE
block|,
name|PACKHL
block|,
name|VSPLAT
block|,
name|VASL
block|,
name|VASR
block|,
name|VLSR
block|,
name|INSERT
block|,
name|INSERTRP
block|,
name|EXTRACTU
block|,
name|EXTRACTURP
block|,
name|VCOMBINE
block|,
name|VPACKE
block|,
name|VPACKO
block|,
name|TC_RETURN
block|,
name|EH_RETURN
block|,
name|DCFETCH
block|,
name|READCYCLE
block|,
name|OP_END
block|}
enum|;
block|}
comment|// end namespace HexagonISD
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
argument|MVT VT
argument_list|,
argument|MVT PromotedLdStVT
argument_list|)
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
comment|/// Return true if an FMA operation is faster than a pair of mul and add
comment|/// instructions. fmuladd intrinsics will be expanded to FMAs when this
comment|/// method returns true (and FMAs are legal), otherwise fmuladd is
comment|/// expanded to mul + add.
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT
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
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
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
name|LowerEXTRACT_SUBVECTOR_HVX
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
name|LowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVECTOR_SHIFT
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
name|LowerPREFETCH
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerREADCYCLECOUNTER
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
argument|const SDLoc&dl
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
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerToTLSGeneralDynamicModel
argument_list|(
argument|GlobalAddressSDNode *GA
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerToTLSInitialExecModel
argument_list|(
argument|GlobalAddressSDNode *GA
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerToTLSLocalExecModel
argument_list|(
argument|GlobalAddressSDNode *GA
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|GetDynamicTLSAddr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Chain
argument_list|,
argument|GlobalAddressSDNode *GA
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|EVT PtrVT
argument_list|,
argument|unsigned ReturnReg
argument_list|,
argument|unsigned char OperandFlags
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGLOBAL_OFFSET_TABLE
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
argument|const SDLoc&dl
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
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|LLVMContext&Context
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
argument|const CallInst *CI
argument_list|)
specifier|const
name|override
block|;
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|Hexagon
operator|::
name|R0
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|Hexagon
operator|::
name|R1
return|;
block|}
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
name|SDValue
name|LowerJumpTable
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
argument|const DataLayout&
argument_list|,
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
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
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
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|StringRef ConstraintCode
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
name|SDValue
name|LowerINTRINSIC_VOID
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
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|unsigned
name|AS
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if folding a constant offset with the given GlobalAddress
comment|/// is legal.  It is frequently not legal in PIC relocation models.
name|bool
name|isOffsetFoldingLegal
argument_list|(
specifier|const
name|GlobalAddressSDNode
operator|*
name|GA
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
name|EVT
name|getOptimalMemOpType
argument_list|(
name|uint64_t
name|Size
argument_list|,
name|unsigned
name|DstAlign
argument_list|,
name|unsigned
name|SrcAlign
argument_list|,
name|bool
name|IsMemset
argument_list|,
name|bool
name|ZeroMemset
argument_list|,
name|bool
name|MemcpyStrSrc
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
name|EVT
name|VT
argument_list|,
name|unsigned
name|AddrSpace
argument_list|,
name|unsigned
name|Align
argument_list|,
name|bool
operator|*
name|Fast
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Returns relocation base for the given PIC jumptable.
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
name|SDValue
name|Table
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
comment|// Handling of atomic RMW instructions.
name|Value
modifier|*
name|emitLoadLinked
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
name|Value
modifier|*
name|emitStoreConditional
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
name|AtomicExpansionKind
name|shouldExpandAtomicLoadInIR
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|shouldExpandAtomicStoreInIR
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|shouldExpandAtomicCmpXchgInIR
argument_list|(
name|AtomicCmpXchgInst
operator|*
name|AI
argument_list|)
decl|const
name|override
decl_stmt|;
name|AtomicExpansionKind
name|shouldExpandAtomicRMWInIR
argument_list|(
name|AtomicRMWInst
operator|*
name|AI
argument_list|)
decl|const
name|override
block|{
return|return
name|AtomicExpansionKind
operator|::
name|LLSC
return|;
block|}
name|protected
label|:
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|uint8_t
operator|>
name|findRepresentativeClass
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
expr_stmt|;
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
comment|// LLVM_LIB_TARGET_HEXAGON_HEXAGONISELLOWERING_H
end_comment

end_unit

