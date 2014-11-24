begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGen/MachineInstBundle.h - MI bundle utilities -------*- C++ -*-===//
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
comment|// This file provide utility functions to manipulate machine instruction
end_comment

begin_comment
comment|// bundles.
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
name|LLVM_CODEGEN_MACHINEINSTRBUNDLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEINSTRBUNDLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// finalizeBundle - Finalize a machine instruction bundle which includes
comment|/// a sequence of instructions starting from FirstMI to LastMI (exclusive).
comment|/// This routine adds a BUNDLE instruction to represent the bundle, it adds
comment|/// IsInternalRead markers to MachineOperands which are defined inside the
comment|/// bundle, and it copies externally visible defs and uses to the BUNDLE
comment|/// instruction.
name|void
name|finalizeBundle
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|instr_iterator
name|FirstMI
argument_list|,
name|MachineBasicBlock
operator|::
name|instr_iterator
name|LastMI
argument_list|)
decl_stmt|;
comment|/// finalizeBundle - Same functionality as the previous finalizeBundle except
comment|/// the last instruction in the bundle is not provided as an input. This is
comment|/// used in cases where bundles are pre-determined by marking instructions
comment|/// with 'InsideBundle' marker. It returns the MBB instruction iterator that
comment|/// points to the end of the bundle.
name|MachineBasicBlock
operator|::
name|instr_iterator
name|finalizeBundle
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::instr_iterator FirstMI
argument_list|)
expr_stmt|;
comment|/// finalizeBundles - Finalize instruction bundles in the specified
comment|/// MachineFunction. Return true if any bundles are finalized.
name|bool
name|finalizeBundles
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// getBundleStart - Returns the first instruction in the bundle containing MI.
comment|///
specifier|inline
name|MachineInstr
modifier|*
name|getBundleStart
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|MachineBasicBlock
operator|::
name|instr_iterator
name|I
operator|=
name|MI
expr_stmt|;
while|while
condition|(
name|I
operator|->
name|isBundledWithPred
argument_list|()
condition|)
operator|--
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
specifier|inline
specifier|const
name|MachineInstr
modifier|*
name|getBundleStart
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|MachineBasicBlock
operator|::
name|const_instr_iterator
name|I
operator|=
name|MI
expr_stmt|;
while|while
condition|(
name|I
operator|->
name|isBundledWithPred
argument_list|()
condition|)
operator|--
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
comment|/// Return an iterator pointing beyond the bundle containing MI.
specifier|inline
name|MachineBasicBlock
operator|::
name|instr_iterator
name|getBundleEnd
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
name|MachineBasicBlock
operator|::
name|instr_iterator
name|I
operator|=
name|MI
block|;
while|while
condition|(
name|I
operator|->
name|isBundledWithSucc
argument_list|()
condition|)
operator|++
name|I
expr_stmt|;
return|return
operator|++
name|I
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return an iterator pointing beyond the bundle containing MI.
end_comment

begin_expr_stmt
specifier|inline
name|MachineBasicBlock
operator|::
name|const_instr_iterator
name|getBundleEnd
argument_list|(
argument|const MachineInstr *MI
argument_list|)
block|{
name|MachineBasicBlock
operator|::
name|const_instr_iterator
name|I
operator|=
name|MI
block|;
while|while
condition|(
name|I
operator|->
name|isBundledWithSucc
argument_list|()
condition|)
operator|++
name|I
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|++
name|I
return|;
end_return

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// MachineOperand iterator
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// MachineOperandIteratorBase - Iterator that can visit all operands on a
end_comment

begin_comment
comment|/// MachineInstr, or all operands on a bundle of MachineInstrs.  This class is
end_comment

begin_comment
comment|/// not intended to be used directly, use one of the sub-classes instead.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Intended use:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   for (MIBundleOperands MIO(MI); MIO.isValid(); ++MIO) {
end_comment

begin_comment
comment|///     if (!MIO->isReg())
end_comment

begin_comment
comment|///       continue;
end_comment

begin_comment
comment|///     ...
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_macro
unit|class
name|MachineOperandIteratorBase
end_macro

begin_block
block|{
name|MachineBasicBlock
operator|::
name|instr_iterator
name|InstrI
operator|,
name|InstrE
expr_stmt|;
name|MachineInstr
operator|::
name|mop_iterator
name|OpI
operator|,
name|OpE
expr_stmt|;
comment|// If the operands on InstrI are exhausted, advance InstrI to the next
comment|// bundled instruction with operands.
name|void
name|advance
parameter_list|()
block|{
while|while
condition|(
name|OpI
operator|==
name|OpE
condition|)
block|{
comment|// Don't advance off the basic block, or into a new bundle.
if|if
condition|(
operator|++
name|InstrI
operator|==
name|InstrE
operator|||
operator|!
name|InstrI
operator|->
name|isInsideBundle
argument_list|()
condition|)
break|break;
name|OpI
operator|=
name|InstrI
operator|->
name|operands_begin
argument_list|()
expr_stmt|;
name|OpE
operator|=
name|InstrI
operator|->
name|operands_end
argument_list|()
expr_stmt|;
block|}
block|}
name|protected
label|:
comment|/// MachineOperandIteratorBase - Create an iterator that visits all operands
comment|/// on MI, or all operands on every instruction in the bundle containing MI.
comment|///
comment|/// @param MI The instruction to examine.
comment|/// @param WholeBundle When true, visit all operands on the entire bundle.
comment|///
name|explicit
name|MachineOperandIteratorBase
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|bool
name|WholeBundle
parameter_list|)
block|{
if|if
condition|(
name|WholeBundle
condition|)
block|{
name|InstrI
operator|=
name|getBundleStart
argument_list|(
name|MI
argument_list|)
expr_stmt|;
name|InstrE
operator|=
name|MI
operator|->
name|getParent
argument_list|()
operator|->
name|instr_end
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|InstrI
operator|=
name|InstrE
operator|=
name|MI
expr_stmt|;
operator|++
name|InstrE
expr_stmt|;
block|}
name|OpI
operator|=
name|InstrI
operator|->
name|operands_begin
argument_list|()
expr_stmt|;
name|OpE
operator|=
name|InstrI
operator|->
name|operands_end
argument_list|()
expr_stmt|;
if|if
condition|(
name|WholeBundle
condition|)
name|advance
argument_list|()
expr_stmt|;
block|}
name|MachineOperand
operator|&
name|deref
argument_list|()
specifier|const
block|{
return|return
operator|*
name|OpI
return|;
block|}
name|public
label|:
comment|/// isValid - Returns true until all the operands have been visited.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|OpI
operator|!=
name|OpE
return|;
block|}
comment|/// Preincrement.  Move to the next operand.
name|void
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"Cannot advance MIOperands beyond the last operand"
argument_list|)
block|;
operator|++
name|OpI
block|;
name|advance
argument_list|()
block|;   }
comment|/// getOperandNo - Returns the number of the current operand relative to its
comment|/// instruction.
comment|///
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
block|{
return|return
name|OpI
operator|-
name|InstrI
operator|->
name|operands_begin
argument_list|()
return|;
block|}
comment|/// VirtRegInfo - Information about a virtual register used by a set of operands.
comment|///
struct|struct
name|VirtRegInfo
block|{
comment|/// Reads - One of the operands read the virtual register.  This does not
comment|/// include<undef> or<internal> use operands, see MO::readsReg().
name|bool
name|Reads
decl_stmt|;
comment|/// Writes - One of the operands writes the virtual register.
name|bool
name|Writes
decl_stmt|;
comment|/// Tied - Uses and defs must use the same register. This can be because of
comment|/// a two-address constraint, or there may be a partial redefinition of a
comment|/// sub-register.
name|bool
name|Tied
decl_stmt|;
block|}
struct|;
comment|/// PhysRegInfo - Information about a physical register used by a set of
comment|/// operands.
struct|struct
name|PhysRegInfo
block|{
comment|/// Clobbers - Reg or an overlapping register is defined, or a regmask
comment|/// clobbers Reg.
name|bool
name|Clobbers
decl_stmt|;
comment|/// Defines - Reg or a super-register is defined.
name|bool
name|Defines
decl_stmt|;
comment|/// Reads - Read or a super-register is read.
name|bool
name|Reads
decl_stmt|;
comment|/// ReadsOverlap - Reg or an overlapping register is read.
name|bool
name|ReadsOverlap
decl_stmt|;
comment|/// DefinesDead - All defs of a Reg or a super-register are dead.
name|bool
name|DefinesDead
decl_stmt|;
comment|/// There is a kill of Reg or a super-register.
name|bool
name|Kills
decl_stmt|;
block|}
struct|;
comment|/// analyzeVirtReg - Analyze how the current instruction or bundle uses a
comment|/// virtual register.  This function should not be called after operator++(),
comment|/// it expects a fresh iterator.
comment|///
comment|/// @param Reg The virtual register to analyze.
comment|/// @param Ops When set, this vector will receive an (MI, OpNum) entry for
comment|///            each operand referring to Reg.
comment|/// @returns A filled-in RegInfo struct.
name|VirtRegInfo
name|analyzeVirtReg
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
argument_list|,
name|unsigned
operator|>
expr|>
operator|*
name|Ops
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// analyzePhysReg - Analyze how the current instruction or bundle uses a
comment|/// physical register.  This function should not be called after operator++(),
comment|/// it expects a fresh iterator.
comment|///
comment|/// @param Reg The physical register to analyze.
comment|/// @returns A filled-in PhysRegInfo struct.
name|PhysRegInfo
name|analyzePhysReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
function_decl|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MIOperands - Iterate over operands of a single instruction.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MIOperands
range|:
name|public
name|MachineOperandIteratorBase
block|{
name|public
operator|:
name|MIOperands
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
operator|:
name|MachineOperandIteratorBase
argument_list|(
argument|MI
argument_list|,
argument|false
argument_list|)
block|{}
name|MachineOperand
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|deref
argument_list|()
return|;
block|}
name|MachineOperand
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|&
name|deref
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ConstMIOperands - Iterate over operands of a single const instruction.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ConstMIOperands
range|:
name|public
name|MachineOperandIteratorBase
block|{
name|public
operator|:
name|ConstMIOperands
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
operator|:
name|MachineOperandIteratorBase
argument_list|(
argument|const_cast<MachineInstr*>(MI)
argument_list|,
argument|false
argument_list|)
block|{}
specifier|const
name|MachineOperand
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|deref
argument_list|()
return|;
block|}
specifier|const
name|MachineOperand
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|&
name|deref
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MIBundleOperands - Iterate over all operands in a bundle of machine
end_comment

begin_comment
comment|/// instructions.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MIBundleOperands
range|:
name|public
name|MachineOperandIteratorBase
block|{
name|public
operator|:
name|MIBundleOperands
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
operator|:
name|MachineOperandIteratorBase
argument_list|(
argument|MI
argument_list|,
argument|true
argument_list|)
block|{}
name|MachineOperand
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|deref
argument_list|()
return|;
block|}
name|MachineOperand
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|&
name|deref
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ConstMIBundleOperands - Iterate over all operands in a const bundle of
end_comment

begin_comment
comment|/// machine instructions.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ConstMIBundleOperands
range|:
name|public
name|MachineOperandIteratorBase
block|{
name|public
operator|:
name|ConstMIBundleOperands
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
operator|:
name|MachineOperandIteratorBase
argument_list|(
argument|const_cast<MachineInstr*>(MI)
argument_list|,
argument|true
argument_list|)
block|{}
specifier|const
name|MachineOperand
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|deref
argument_list|()
return|;
block|}
specifier|const
name|MachineOperand
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|&
name|deref
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

