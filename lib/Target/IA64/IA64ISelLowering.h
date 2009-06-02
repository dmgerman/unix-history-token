begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IA64ISelLowering.h - IA64 DAG Lowering Interface --------*- C++ -*-===//
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
comment|// This file defines the interfaces that IA64 uses to lower LLVM code into a
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
name|LLVM_TARGET_IA64_IA64ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_IA64_IA64ISELLOWERING_H
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
file|"IA64.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|IA64ISD
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
comment|/// GETFD - the getf.d instruction takes a floating point operand and
comment|/// returns its 64-bit memory representation as an i64
name|GETFD
block|,
comment|// TODO: explain this hack
name|BRCALL
block|,
comment|// RET_FLAG - Return with a flag operand
name|RET_FLAG
block|}
enum|;
block|}
name|class
name|IA64TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|int
name|VarArgsFrameIndex
block|;
comment|// FrameIndex for start of varargs area.
comment|//int ReturnAddrIndex;              // FrameIndex for return slot.
name|unsigned
name|GP
block|,
name|SP
block|,
name|RP
block|;
comment|// FIXME - clean this mess up
name|public
operator|:
name|explicit
name|IA64TargetLowering
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|unsigned
name|VirtGPR
block|;
comment|// this is public so it can be accessed in the selector
comment|// for ISD::RET. add an accessor instead? FIXME
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|/// getSetCCResultType: return ISD::SETCC's result type.
name|virtual
name|MVT
name|getSetCCResultType
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|;
comment|/// LowerArguments - This hook must be implemented to indicate how we should
comment|/// lower the arguments for the specified function, into the specified DAG.
name|virtual
name|void
name|LowerArguments
argument_list|(
argument|Function&F
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&ArgValues
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
comment|/// LowerCallTo - This hook lowers an abstract call to a function into an
comment|/// actual call.
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|LowerCallTo
argument_list|(
argument|SDValue Chain
argument_list|,
argument|const Type *RetTy
argument_list|,
argument|bool RetSExt
argument_list|,
argument|bool RetZExt
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isInreg
argument_list|,
argument|unsigned CC
argument_list|,
argument|bool isTailCall
argument_list|,
argument|SDValue Callee
argument_list|,
argument|ArgListTy&Args
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
comment|/// LowerOperation - for custom lowering specific ops
comment|/// (currently, only "ret void")
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;        }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_IA64_IA64ISELLOWERING_H
end_comment

end_unit

