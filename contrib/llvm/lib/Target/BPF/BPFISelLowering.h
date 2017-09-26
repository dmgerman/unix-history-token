begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BPFISelLowering.h - BPF DAG Lowering Interface ----------*- C++ -*-===//
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
comment|// This file defines the interfaces that BPF uses to lower LLVM code into a
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
name|LLVM_LIB_TARGET_BPF_BPFISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_BPF_BPFISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"BPF.h"
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
name|class
name|BPFSubtarget
decl_stmt|;
name|namespace
name|BPFISD
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
name|RET_FLAG
block|,
name|CALL
block|,
name|SELECT_CC
block|,
name|BR_CC
block|,
name|Wrapper
block|}
enum|;
block|}
name|class
name|BPFTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|BPFTargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|BPFSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|// Provide custom lowering hooks for some operations.
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
comment|// This method returns the name of a target specific DAG node.
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
comment|// This method decides whether folding a constant offset
comment|// with the given GlobalAddress is legal.
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|SDValue
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Lower the result values of a call, copying them out of physregs into vregs
name|SDValue
name|LowerCallResult
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
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
block|;
comment|// Maximum number of arguments to a call
specifier|static
specifier|const
name|unsigned
name|MaxArgs
block|;
comment|// Lower a call into CALLSEQ_START - BPFISD:CALL - CALLSEQ_END chain
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
comment|// Lower incoming arguments, copy physregs into vregs
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
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
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
name|EVT
name|getOptimalMemOpType
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned DstAlign
argument_list|,
argument|unsigned SrcAlign
argument_list|,
argument|bool IsMemset
argument_list|,
argument|bool ZeroMemset
argument_list|,
argument|bool MemcpyStrSrc
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|Size
operator|>=
literal|8
operator|?
name|MVT
operator|::
name|i64
operator|:
name|MVT
operator|::
name|i32
return|;
block|}
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

