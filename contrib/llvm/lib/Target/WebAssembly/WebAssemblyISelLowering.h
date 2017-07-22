begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//- WebAssemblyISelLowering.h - WebAssembly DAG Lowering Interface -*- C++ -*-//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file defines the interfaces that WebAssembly uses to lower LLVM
end_comment

begin_comment
comment|/// code into a selection DAG.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYISELLOWERING_H
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
name|namespace
name|WebAssemblyISD
block|{
enum|enum
name|NodeType
enum|:
name|unsigned
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
define|#
directive|define
name|HANDLE_NODETYPE
parameter_list|(
name|NODE
parameter_list|)
value|NODE,
include|#
directive|include
file|"WebAssemblyISD.def"
undef|#
directive|undef
name|HANDLE_NODETYPE
block|}
enum|;
block|}
comment|// end namespace WebAssemblyISD
name|class
name|WebAssemblySubtarget
decl_stmt|;
name|class
name|WebAssemblyTargetMachine
decl_stmt|;
name|class
name|WebAssemblyTargetLowering
name|final
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|WebAssemblyTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|WebAssemblySubtarget
operator|&
name|STI
argument_list|)
block|;
name|private
operator|:
comment|/// Keep a pointer to the WebAssemblySubtarget around so that we can make the
comment|/// right decision when generating code for different targets.
specifier|const
name|WebAssemblySubtarget
operator|*
name|Subtarget
block|;
name|FastISel
operator|*
name|createFastISel
argument_list|(
argument|FunctionLoweringInfo&FuncInfo
argument_list|,
argument|const TargetLibraryInfo *LibInfo
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
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|EVT
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
argument|EVT
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool *Fast
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isIntDivCheap
argument_list|(
argument|EVT VT
argument_list|,
argument|AttributeList Attr
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
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
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
comment|// Custom lowering hooks.
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
name|LowerFrameIndex
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
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerExternalSymbol
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
name|LowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
name|LowerCopyToReg
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|; }
decl_stmt|;
name|namespace
name|WebAssembly
block|{
name|FastISel
modifier|*
name|createFastISel
parameter_list|(
name|FunctionLoweringInfo
modifier|&
name|funcInfo
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|libInfo
parameter_list|)
function_decl|;
block|}
comment|// end namespace WebAssembly
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

