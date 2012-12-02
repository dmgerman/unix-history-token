begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXISelLowering.h - NVPTX DAG Lowering Interface ------*- C++ -*-===//
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
comment|// This file defines the interfaces that NVPTX uses to lower LLVM code into a
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
name|NVPTXISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTXISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"NVPTX.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
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
name|NVPTXISD
block|{
enum|enum
name|NodeType
block|{
comment|// Start the numbering from where ISD NodeType finishes.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|Wrapper
block|,
name|CALL
block|,
name|RET_FLAG
block|,
name|LOAD_PARAM
block|,
name|NVBuiltin
block|,
name|DeclareParam
block|,
name|DeclareScalarParam
block|,
name|DeclareRetParam
block|,
name|DeclareRet
block|,
name|DeclareScalarRet
block|,
name|LoadParam
block|,
name|StoreParam
block|,
name|StoreParamS32
block|,
comment|// to sext and store a<32bit value, not used currently
name|StoreParamU32
block|,
comment|// to zext and store a<32bit value, not used currently
name|MoveToParam
block|,
name|PrintCall
block|,
name|PrintCallUni
block|,
name|CallArgBegin
block|,
name|CallArg
block|,
name|LastCallArg
block|,
name|CallArgEnd
block|,
name|CallVoid
block|,
name|CallVal
block|,
name|CallSymbol
block|,
name|Prototype
block|,
name|MoveParam
block|,
name|MoveRetval
block|,
name|MoveToRetval
block|,
name|StoreRetval
block|,
name|PseudoUseParam
block|,
name|RETURN
block|,
name|CallSeqBegin
block|,
name|CallSeqEnd
block|,
name|Dummy
block|}
enum|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Implementation
comment|//===--------------------------------------------------------------------===//
name|class
name|NVPTXTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|NVPTXTargetLowering
argument_list|(
name|NVPTXTargetMachine
operator|&
name|TM
argument_list|)
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
name|SDValue
name|LowerGlobalAddress
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
argument|const GlobalValue *GV
argument_list|,
argument|int64_t Offset
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
name|bool
name|isTypeSupportedInIntrinsic
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|;
name|bool
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInfo& Info
argument_list|,
argument|const CallInst&I
argument_list|,
argument|unsigned Intrinsic
argument_list|)
specifier|const
block|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type
comment|/// Used to guide target specific optimizations, like loop strength
comment|/// reduction (LoopStrengthReduce.cpp) and memory optimization for
comment|/// address mode (CodeGenPrepare.cpp)
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
name|EVT
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
name|MVT
operator|::
name|i1
return|;
block|}
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
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
block|;
name|std
operator|::
name|string
name|getPrototype
argument_list|(
argument|Type *
argument_list|,
argument|const ArgListTy&
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&
argument_list|,
argument|unsigned retAlignment
argument_list|)
specifier|const
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|std::string&Constraint
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|NVPTXTargetMachine
operator|*
name|nvTM
block|;
comment|// PTX always uses 32-bit shift amounts
name|virtual
name|MVT
name|getShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
name|private
operator|:
specifier|const
name|NVPTXSubtarget
operator|&
name|nvptxSubtarget
block|;
comment|// cache the subtarget here
name|SDValue
name|getExtSymb
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|const char *name
argument_list|,
argument|int idx
argument_list|,
argument|EVT =                          MVT::i32
argument_list|)
specifier|const
block|;
name|SDValue
name|getParamSymbol
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|int idx
argument_list|,
argument|EVT = MVT::i32
argument_list|)
specifier|const
block|;
name|SDValue
name|getParamHelpSymbol
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|int idx
argument_list|)
block|;
name|SDValue
name|LowerCONCAT_VECTORS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NVPTXISELLOWERING_H
end_comment

end_unit

