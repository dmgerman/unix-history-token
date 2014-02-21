begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrEmitter.h - Emit MachineInstrs for the SelectionDAG -*- C++ -*--==//
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
comment|// This declares the Emit routines for the SelectionDAG class, which creates
end_comment

begin_comment
comment|// MachineInstrs based on the decisions of the SelectionDAG instruction
end_comment

begin_comment
comment|// selection.
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
name|INSTREMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|INSTREMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstrBuilder
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|SDDbgValue
decl_stmt|;
name|class
name|InstrEmitter
block|{
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
specifier|const
name|TargetMachine
modifier|*
name|TM
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
specifier|const
name|TargetLowering
modifier|*
name|TLI
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|MachineBasicBlock
operator|::
name|iterator
name|InsertPos
expr_stmt|;
comment|/// EmitCopyFromReg - Generate machine code for an CopyFromReg node or an
comment|/// implicit physical register output.
name|void
name|EmitCopyFromReg
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|unsigned
name|ResNo
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|,
name|unsigned
name|SrcReg
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
comment|/// getDstOfCopyToRegUse - If the only use of the specified result number of
comment|/// node is a CopyToReg, return its destination register. Return 0 otherwise.
name|unsigned
name|getDstOfOnlyCopyToRegUse
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|unsigned
name|ResNo
argument_list|)
decl|const
decl_stmt|;
name|void
name|CreateVirtualRegisters
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|MachineInstrBuilder
operator|&
name|MIB
argument_list|,
specifier|const
name|MCInstrDesc
operator|&
name|II
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
comment|/// getVR - Return the virtual register corresponding to the specified result
comment|/// of the specified node.
name|unsigned
name|getVR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
comment|/// AddRegisterOperand - Add the specified register as an operand to the
comment|/// specified machine instr. Insert register copies if the register is
comment|/// not in the required register class.
name|void
name|AddRegisterOperand
argument_list|(
name|MachineInstrBuilder
operator|&
name|MIB
argument_list|,
name|SDValue
name|Op
argument_list|,
name|unsigned
name|IIOpNum
argument_list|,
specifier|const
name|MCInstrDesc
operator|*
name|II
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|,
name|bool
name|IsDebug
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|)
decl_stmt|;
comment|/// AddOperand - Add the specified operand to the specified machine instr.  II
comment|/// specifies the instruction information for the node, and IIOpNum is the
comment|/// operand number (in the II) that we are adding. IIOpNum and II are used for
comment|/// assertions only.
name|void
name|AddOperand
argument_list|(
name|MachineInstrBuilder
operator|&
name|MIB
argument_list|,
name|SDValue
name|Op
argument_list|,
name|unsigned
name|IIOpNum
argument_list|,
specifier|const
name|MCInstrDesc
operator|*
name|II
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|,
name|bool
name|IsDebug
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|)
decl_stmt|;
comment|/// ConstrainForSubReg - Try to constrain VReg to a register class that
comment|/// supports SubIdx sub-registers.  Emit a copy if that isn't possible.
comment|/// Return the virtual register to use.
name|unsigned
name|ConstrainForSubReg
parameter_list|(
name|unsigned
name|VReg
parameter_list|,
name|unsigned
name|SubIdx
parameter_list|,
name|MVT
name|VT
parameter_list|,
name|DebugLoc
name|DL
parameter_list|)
function_decl|;
comment|/// EmitSubregNode - Generate machine code for subreg nodes.
comment|///
name|void
name|EmitSubregNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|)
decl_stmt|;
comment|/// EmitCopyToRegClassNode - Generate machine code for COPY_TO_REGCLASS nodes.
comment|/// COPY_TO_REGCLASS is just a normal copy, except that the destination
comment|/// register is constrained to be in a particular register class.
comment|///
name|void
name|EmitCopyToRegClassNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
comment|/// EmitRegSequence - Generate machine code for REG_SEQUENCE nodes.
comment|///
name|void
name|EmitRegSequence
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// CountResults - The results of target nodes have register or immediate
comment|/// operands first, then an optional chain, and optional flag operands
comment|/// (which do not go into the machine instrs.)
specifier|static
name|unsigned
name|CountResults
parameter_list|(
name|SDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
comment|/// EmitDbgValue - Generate machine instruction for a dbg_value node.
comment|///
name|MachineInstr
modifier|*
name|EmitDbgValue
argument_list|(
name|SDDbgValue
operator|*
name|SD
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
comment|/// EmitNode - Generate machine code for a node and needed dependencies.
comment|///
name|void
name|EmitNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
block|{
if|if
condition|(
name|Node
operator|->
name|isMachineOpcode
argument_list|()
condition|)
name|EmitMachineNode
argument_list|(
name|Node
argument_list|,
name|IsClone
argument_list|,
name|IsCloned
argument_list|,
name|VRBaseMap
argument_list|)
expr_stmt|;
else|else
name|EmitSpecialNode
argument_list|(
name|Node
argument_list|,
name|IsClone
argument_list|,
name|IsCloned
argument_list|,
name|VRBaseMap
argument_list|)
expr_stmt|;
block|}
comment|/// getBlock - Return the current basic block.
name|MachineBasicBlock
modifier|*
name|getBlock
parameter_list|()
block|{
return|return
name|MBB
return|;
block|}
comment|/// getInsertPos - Return the current insertion position.
name|MachineBasicBlock
operator|::
name|iterator
name|getInsertPos
argument_list|()
block|{
return|return
name|InsertPos
return|;
block|}
comment|/// InstrEmitter - Construct an InstrEmitter and set it to start inserting
comment|/// at the given position in the given block.
name|InstrEmitter
argument_list|(
argument|MachineBasicBlock *mbb
argument_list|,
argument|MachineBasicBlock::iterator insertpos
argument_list|)
empty_stmt|;
name|private
label|:
name|void
name|EmitMachineNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
name|void
name|EmitSpecialNode
argument_list|(
name|SDNode
operator|*
name|Node
argument_list|,
name|bool
name|IsClone
argument_list|,
name|bool
name|IsCloned
argument_list|,
name|DenseMap
operator|<
name|SDValue
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

