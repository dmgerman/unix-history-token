begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16ISelLowering.h - PIC16 DAG Lowering Interface ------*- C++ -*-===//
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
comment|// This file defines the interfaces that PIC16 uses to lower LLVM code into a
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
name|PIC16ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"PIC16.h"
end_include

begin_include
include|#
directive|include
file|"PIC16Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGISel.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PIC16ISD
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
name|Lo
block|,
comment|// Low 8-bits of GlobalAddress.
name|Hi
block|,
comment|// High 8-bits of GlobalAddress.
name|PIC16Load
block|,
name|PIC16LdArg
block|,
comment|// This is replica of PIC16Load but used to load function
comment|// arguments and is being used for facilitating for some
comment|// store removal optimizations.
name|PIC16LdWF
block|,
name|PIC16Store
block|,
name|PIC16StWF
block|,
name|Banksel
block|,
name|MTLO
block|,
comment|// Move to low part of FSR
name|MTHI
block|,
comment|// Move to high part of FSR
name|MTPCLATH
block|,
comment|// Move to PCLATCH
name|PIC16Connect
block|,
comment|// General connector for PIC16 nodes
name|BCF
block|,
name|LSLF
block|,
comment|// PIC16 Logical shift left
name|LRLF
block|,
comment|// PIC16 Logical shift right
name|RLF
block|,
comment|// Rotate left through carry
name|RRF
block|,
comment|// Rotate right through carry
name|CALL
block|,
comment|// PIC16 Call instruction
name|CALLW
block|,
comment|// PIC16 CALLW instruction
name|SUBCC
block|,
comment|// Compare for equality or inequality.
name|SELECT_ICC
block|,
comment|// Psuedo to be caught in schedular and expanded to brcond.
name|BRCOND
block|,
comment|// Conditional branch.
name|RET
block|,
comment|// Return.
name|Dummy
block|}
enum|;
comment|// Keep track of different address spaces.
enum|enum
name|AddressSpace
block|{
name|RAM_SPACE
init|=
literal|0
block|,
comment|// RAM address space
name|ROM_SPACE
init|=
literal|1
comment|// ROM address space number is 1
block|}
enum|;
enum|enum
name|PIC16Libcall
block|{
name|MUL_I8
init|=
name|RTLIB
operator|::
name|UNKNOWN_LIBCALL
operator|+
literal|1
block|,
name|SRA_I8
block|,
name|SLL_I8
block|,
name|SRL_I8
block|,
name|PIC16UnknownCall
block|}
enum|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Implementation
comment|//===--------------------------------------------------------------------===//
name|class
name|PIC16TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|PIC16TargetLowering
argument_list|(
name|PIC16TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
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
comment|/// getSetCCResultType - Return the ISD::SETCC ValueType
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getSetCCResultType
argument_list|(
argument|EVT ValType
argument_list|)
specifier|const
block|;
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getCmpLibcallReturnType
argument_list|()
specifier|const
block|;
name|SDValue
name|LowerShift
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerMUL
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerADD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSUB
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerBinOp
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|// Call returns
name|SDValue
name|LowerDirectCallReturn
argument_list|(
argument|SDValue RetLabel
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
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
name|SDValue
name|LowerIndirectCallReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|SDValue DataAddr_Lo
argument_list|,
argument|SDValue DataAddr_Hi
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
comment|// Call arguments
name|SDValue
name|LowerDirectCallArguments
argument_list|(
argument|SDValue ArgLabel
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerIndirectCallArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|SDValue DataAddr_Lo
argument_list|,
argument|SDValue DataAddr_Hi
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|getPIC16Cmp
argument_list|(
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|unsigned OrigCC
argument_list|,
argument|SDValue&CC
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|,
argument|DenseMap<MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*> *EM
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
block|;
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
name|void
name|LowerOperationWrapper
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
block|;
name|SDValue
name|ExpandStore
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|SDValue
name|ExpandLoad
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|SDValue
name|ExpandGlobalAddress
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|SDValue
name|ExpandExternalSymbol
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|SDValue
name|ExpandFrameIndex
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|PerformPIC16LoadCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|SDValue
name|PerformStoreCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
comment|// This function returns the Tmp Offset for FrameIndex. If any TmpOffset
comment|// already exists for the FI then it returns the same else it creates the
comment|// new offset and returns.
name|unsigned
name|GetTmpOffsetForFI
argument_list|(
argument|unsigned FI
argument_list|,
argument|unsigned slot_size
argument_list|)
block|;
name|void
name|ResetTmpOffsetMap
argument_list|()
block|{
name|FiTmpOffsetMap
operator|.
name|clear
argument_list|()
block|;
name|SetTmpSize
argument_list|(
literal|0
argument_list|)
block|; }
name|void
name|InitReservedFrameCount
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;
comment|// Return the size of Tmp variable
name|unsigned
name|GetTmpSize
argument_list|()
block|{
return|return
name|TmpSize
return|;
block|}
name|void
name|SetTmpSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|TmpSize
operator|=
name|Size
block|; }
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
argument|const Function *
argument_list|)
specifier|const
block|{
comment|// FIXME: The function never seems to be aligned.
return|return
literal|1
return|;
block|}
name|private
operator|:
comment|// If the Node is a BUILD_PAIR representing a direct Address,
comment|// then this function will return true.
name|bool
name|isDirectAddress
argument_list|(
specifier|const
name|SDValue
operator|&
name|Op
argument_list|)
block|;
comment|// If the Node is a DirectAddress in ROM_SPACE then this
comment|// function will return true
name|bool
name|isRomAddress
argument_list|(
specifier|const
name|SDValue
operator|&
name|Op
argument_list|)
block|;
comment|// Extract the Lo and Hi component of Op.
name|void
name|GetExpandedParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&Lo
argument_list|,
argument|SDValue&Hi
argument_list|)
block|;
comment|// Load pointer can be a direct or indirect address. In PIC16 direct
comment|// addresses need Banksel and Indirect addresses need to be loaded to
comment|// FSR first. Handle address specific cases here.
name|void
name|LegalizeAddress
argument_list|(
argument|SDValue Ptr
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&Chain
argument_list|,
argument|SDValue&NewPtr
argument_list|,
argument|unsigned&Offset
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
comment|// FrameIndex should be broken down into ExternalSymbol and FrameOffset.
name|void
name|LegalizeFrameIndex
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&ES
argument_list|,
argument|int&Offset
argument_list|)
block|;
comment|// For indirect calls data address of the callee frame need to be
comment|// extracted. This function fills the arguments DataAddr_Lo and
comment|// DataAddr_Hi with the address of the callee frame.
name|void
name|GetDataAddress
argument_list|(
argument|DebugLoc dl
argument_list|,
argument|SDValue Callee
argument_list|,
argument|SDValue&Chain
argument_list|,
argument|SDValue&DataAddr_Lo
argument_list|,
argument|SDValue&DataAddr_Hi
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|// We can not have both operands of a binary operation in W.
comment|// This function is used to put one operand on stack and generate a load.
name|SDValue
name|ConvertToMemOperand
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
comment|// This function checks if we need to put an operand of an operation on
comment|// stack and generate a load or not.
comment|// DAG parameter is required to access DAG information during
comment|// analysis.
name|bool
name|NeedToConvertToMemOp
argument_list|(
argument|SDValue Op
argument_list|,
argument|unsigned&MemOp
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|/// Subtarget - Keep a pointer to the PIC16Subtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|PIC16Subtarget
operator|*
name|Subtarget
block|;
comment|// Extending the LIB Call framework of LLVM
comment|// to hold the names of PIC16Libcalls.
specifier|const
name|char
operator|*
name|PIC16LibcallNames
index|[
name|PIC16ISD
operator|::
name|PIC16UnknownCall
index|]
block|;
comment|// To set and retrieve the lib call names.
name|void
name|setPIC16LibcallName
argument_list|(
argument|PIC16ISD::PIC16Libcall Call
argument_list|,
argument|const char *Name
argument_list|)
block|;
specifier|const
name|char
operator|*
name|getPIC16LibcallName
argument_list|(
argument|PIC16ISD::PIC16Libcall Call
argument_list|)
block|;
comment|// Make PIC16 Libcall.
name|SDValue
name|MakePIC16Libcall
argument_list|(
argument|PIC16ISD::PIC16Libcall Call
argument_list|,
argument|EVT RetVT
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|bool isSigned
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
comment|// Check if operation has a direct load operand.
specifier|inline
name|bool
name|isDirectLoad
argument_list|(
argument|const SDValue Op
argument_list|)
block|;
name|public
operator|:
comment|// Keep a pointer to SelectionDAGISel to access its public
comment|// interface (It is required during legalization)
name|SelectionDAGISel
operator|*
name|ISel
block|;
name|private
operator|:
comment|// The frameindexes generated for spill/reload are stack based.
comment|// This maps maintain zero based indexes for these FIs.
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|FiTmpOffsetMap
block|;
name|unsigned
name|TmpSize
block|;
comment|// These are the frames for return value and argument passing
comment|// These FrameIndices will be expanded to foo.frame external symbol
comment|// and all others will be expanded to foo.tmp external symbol.
name|unsigned
name|ReservedFrameCount
block|;    }
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
comment|// PIC16ISELLOWERING_H
end_comment

end_unit

