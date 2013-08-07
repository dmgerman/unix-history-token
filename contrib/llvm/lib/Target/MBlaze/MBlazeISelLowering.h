begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MBlazeISelLowering.h - MBlaze DAG Lowering Interface ----*- C++ -*-===//
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
comment|// This file defines the interfaces that MBlaze uses to lower LLVM code into a
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
name|MBlazeISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|MBlazeISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MBlaze.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
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
name|MBlazeCC
block|{
enum|enum
name|CC
block|{
name|FIRST
init|=
literal|0
block|,
name|EQ
block|,
name|NE
block|,
name|GT
block|,
name|LT
block|,
name|GE
block|,
name|LE
block|}
enum|;
specifier|inline
specifier|static
name|CC
name|getOppositeCondition
parameter_list|(
name|CC
name|cc
parameter_list|)
block|{
switch|switch
condition|(
name|cc
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
case|case
name|EQ
case|:
return|return
name|NE
return|;
case|case
name|NE
case|:
return|return
name|EQ
return|;
case|case
name|GT
case|:
return|return
name|LE
return|;
case|case
name|LT
case|:
return|return
name|GE
return|;
case|case
name|GE
case|:
return|return
name|LT
return|;
case|case
name|LE
case|:
return|return
name|GE
return|;
block|}
block|}
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|MBlazeCCToString
parameter_list|(
name|CC
name|cc
parameter_list|)
block|{
switch|switch
condition|(
name|cc
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
case|case
name|EQ
case|:
return|return
literal|"eq"
return|;
case|case
name|NE
case|:
return|return
literal|"ne"
return|;
case|case
name|GT
case|:
return|return
literal|"gt"
return|;
case|case
name|LT
case|:
return|return
literal|"lt"
return|;
case|case
name|GE
case|:
return|return
literal|"ge"
return|;
case|case
name|LE
case|:
return|return
literal|"le"
return|;
block|}
block|}
block|}
name|namespace
name|MBlazeISD
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
comment|// Jump and link (call)
name|JmpLink
block|,
comment|// Handle gp_rel (small data/bss sections) relocation.
name|GPRel
block|,
comment|// Select CC Pseudo Instruction
name|Select_CC
block|,
comment|// Wrap up multiple types of instructions
name|Wrap
block|,
comment|// Integer Compare
name|ICmp
block|,
comment|// Return from subroutine
name|Ret
block|,
comment|// Return from interrupt
name|IRet
block|}
enum|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Implementation
comment|//===--------------------------------------------------------------------===//
name|class
name|MBlazeTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|MBlazeTargetLowering
argument_list|(
name|MBlazeTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
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
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|//  DAG node.
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
comment|/// getSetCCResultType - get the ISD::SETCC result ValueType
name|EVT
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// Subtarget Info
specifier|const
name|MBlazeSubtarget
operator|*
name|Subtarget
block|;
comment|// Lower Operand helpers
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
comment|// Lower Operand specifics
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
name|LowerGlobalAddress
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
name|LowerJumpTable
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
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
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
name|MachineBasicBlock
operator|*
name|EmitCustomShift
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitCustomSelect
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitCustomAtomic
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
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
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|// Inline asm support
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
argument_list|)
specifier|const
block|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
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
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will
comment|/// materialize the FP immediate as a load from a constant pool.
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MBlazeISELLOWERING_H
end_comment

end_unit

