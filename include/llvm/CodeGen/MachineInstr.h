begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineInstr.h - MachineInstr class --------*- C++ -*-===//
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
comment|// This file contains the declaration of the MachineInstr class, which is the
end_comment

begin_comment
comment|// basic representation for all target dependent machine instructions used by
end_comment

begin_comment
comment|// the back end.
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
name|LLVM_CODEGEN_MACHINEINSTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEINSTR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetInstrDesc
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MachineInstr - Representation of each machine instruction.
comment|///
name|class
name|MachineInstr
range|:
name|public
name|ilist_node
operator|<
name|MachineInstr
operator|>
block|{
specifier|const
name|TargetInstrDesc
operator|*
name|TID
block|;
comment|// Instruction descriptor.
name|unsigned
name|short
name|NumImplicitOps
block|;
comment|// Number of implicit operands (which
comment|// are determined at construction time).
name|std
operator|::
name|vector
operator|<
name|MachineOperand
operator|>
name|Operands
block|;
comment|// the operands
name|std
operator|::
name|list
operator|<
name|MachineMemOperand
operator|>
name|MemOperands
block|;
comment|// information on memory references
name|MachineBasicBlock
operator|*
name|Parent
block|;
comment|// Pointer to the owning basic block.
name|DebugLoc
name|debugLoc
block|;
comment|// Source line information.
comment|// OperandComplete - Return true if it's illegal to add a new operand
name|bool
name|OperandsComplete
argument_list|()
specifier|const
block|;
name|MachineInstr
argument_list|(
specifier|const
name|MachineInstr
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|MachineInstr
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
comment|// Intrusive list support
name|friend
expr|struct
name|ilist_traits
operator|<
name|MachineInstr
operator|>
block|;
name|friend
expr|struct
name|ilist_traits
operator|<
name|MachineBasicBlock
operator|>
block|;
name|void
name|setParent
argument_list|(
argument|MachineBasicBlock *P
argument_list|)
block|{
name|Parent
operator|=
name|P
block|; }
comment|/// MachineInstr ctor - This constructor creates a copy of the given
comment|/// MachineInstr in the given MachineFunction.
name|MachineInstr
argument_list|(
name|MachineFunction
operator|&
argument_list|,
specifier|const
name|MachineInstr
operator|&
argument_list|)
block|;
comment|/// MachineInstr ctor - This constructor creates a dummy MachineInstr with
comment|/// TID NULL and no operands.
name|MachineInstr
argument_list|()
block|;
comment|// The next two constructors have DebugLoc and non-DebugLoc versions;
comment|// over time, the non-DebugLoc versions should be phased out and eventually
comment|// removed.
comment|/// MachineInstr ctor - This constructor create a MachineInstr and add the
comment|/// implicit operands.  It reserves space for number of operands specified by
comment|/// TargetInstrDesc.  The version with a DebugLoc should be preferred.
name|explicit
name|MachineInstr
argument_list|(
argument|const TargetInstrDesc&TID
argument_list|,
argument|bool NoImp = false
argument_list|)
block|;
comment|/// MachineInstr ctor - Work exactly the same as the ctor above, except that
comment|/// the MachineInstr is created and added to the end of the specified basic
comment|/// block.  The version with a DebugLoc should be preferred.
comment|///
name|MachineInstr
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
specifier|const
name|TargetInstrDesc
operator|&
name|TID
argument_list|)
block|;
comment|/// MachineInstr ctor - This constructor create a MachineInstr and add the
comment|/// implicit operands.  It reserves space for number of operands specified by
comment|/// TargetInstrDesc.  An explicit DebugLoc is supplied.
name|explicit
name|MachineInstr
argument_list|(
argument|const TargetInstrDesc&TID
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|bool NoImp = false
argument_list|)
block|;
comment|/// MachineInstr ctor - Work exactly the same as the ctor above, except that
comment|/// the MachineInstr is created and added to the end of the specified basic
comment|/// block.
comment|///
name|MachineInstr
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|const TargetInstrDesc&TID
argument_list|)
block|;
operator|~
name|MachineInstr
argument_list|()
block|;
comment|// MachineInstrs are pool-allocated and owned by MachineFunction.
name|friend
name|class
name|MachineFunction
block|;
name|public
operator|:
specifier|const
name|MachineBasicBlock
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
name|MachineBasicBlock
operator|*
name|getParent
argument_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// getDebugLoc - Returns the debug location id of this MachineInstr.
comment|///
specifier|const
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|debugLoc
return|;
block|}
comment|/// getDesc - Returns the target instruction descriptor of this
comment|/// MachineInstr.
specifier|const
name|TargetInstrDesc
operator|&
name|getDesc
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TID
return|;
block|}
comment|/// getOpcode - Returns the opcode of this MachineInstr.
comment|///
name|int
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|TID
operator|->
name|Opcode
return|;
block|}
comment|/// Access to explicit operands of the instruction.
comment|///
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Operands
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|MachineOperand
operator|&
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
name|MachineOperand
operator|&
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
comment|/// getNumExplicitOperands - Returns the number of non-implicit operands.
comment|///
name|unsigned
name|getNumExplicitOperands
argument_list|()
specifier|const
block|;
comment|/// Access to memory operands of the instruction
name|std
operator|::
name|list
operator|<
name|MachineMemOperand
operator|>
operator|::
name|iterator
name|memoperands_begin
argument_list|()
block|{
return|return
name|MemOperands
operator|.
name|begin
argument_list|()
return|;
block|}
name|std
operator|::
name|list
operator|<
name|MachineMemOperand
operator|>
operator|::
name|iterator
name|memoperands_end
argument_list|()
block|{
return|return
name|MemOperands
operator|.
name|end
argument_list|()
return|;
block|}
name|std
operator|::
name|list
operator|<
name|MachineMemOperand
operator|>
operator|::
name|const_iterator
name|memoperands_begin
argument_list|()
specifier|const
block|{
return|return
name|MemOperands
operator|.
name|begin
argument_list|()
return|;
block|}
name|std
operator|::
name|list
operator|<
name|MachineMemOperand
operator|>
operator|::
name|const_iterator
name|memoperands_end
argument_list|()
specifier|const
block|{
return|return
name|MemOperands
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|memoperands_empty
argument_list|()
specifier|const
block|{
return|return
name|MemOperands
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// hasOneMemOperand - Return true if this instruction has exactly one
comment|/// MachineMemOperand.
name|bool
name|hasOneMemOperand
argument_list|()
specifier|const
block|{
return|return
operator|!
name|memoperands_empty
argument_list|()
operator|&&
name|next
argument_list|(
name|memoperands_begin
argument_list|()
argument_list|)
operator|==
name|memoperands_end
argument_list|()
return|;
block|}
comment|/// isIdenticalTo - Return true if this instruction is identical to (same
comment|/// opcode and same operands as) the specified instruction.
name|bool
name|isIdenticalTo
argument_list|(
argument|const MachineInstr *Other
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Other
operator|->
name|getOpcode
argument_list|()
operator|!=
name|getOpcode
argument_list|()
operator|||
name|Other
operator|->
name|getNumOperands
argument_list|()
operator|!=
name|getNumOperands
argument_list|()
condition|)
return|return
name|false
return|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|getOperand
argument_list|(
name|i
argument_list|)
operator|.
name|isIdenticalTo
argument_list|(
name|Other
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// removeFromParent - This method unlinks 'this' from the containing basic
end_comment

begin_comment
comment|/// block, and returns it, but does not delete it.
end_comment

begin_function_decl
name|MachineInstr
modifier|*
name|removeFromParent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// eraseFromParent - This method unlinks 'this' from the containing basic
end_comment

begin_comment
comment|/// block and deletes it.
end_comment

begin_function_decl
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// isLabel - Returns true if the MachineInstr represents a label.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isLabel
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isDebugLabel - Returns true if the MachineInstr represents a debug label.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isDebugLabel
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// readsRegister - Return true if the MachineInstr reads the specified
end_comment

begin_comment
comment|/// register. If TargetRegisterInfo is passed, then it also checks if there
end_comment

begin_comment
comment|/// is a read of a super-register.
end_comment

begin_decl_stmt
name|bool
name|readsRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// killsRegister - Return true if the MachineInstr kills the specified
end_comment

begin_comment
comment|/// register. If TargetRegisterInfo is passed, then it also checks if there is
end_comment

begin_comment
comment|/// a kill of a super-register.
end_comment

begin_decl_stmt
name|bool
name|killsRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|true
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// modifiesRegister - Return true if the MachineInstr modifies the
end_comment

begin_comment
comment|/// specified register. If TargetRegisterInfo is passed, then it also checks
end_comment

begin_comment
comment|/// if there is a def of a super-register.
end_comment

begin_decl_stmt
name|bool
name|modifiesRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// registerDefIsDead - Returns true if the register is dead in this machine
end_comment

begin_comment
comment|/// instruction. If TargetRegisterInfo is passed, then it also checks
end_comment

begin_comment
comment|/// if there is a dead def of a super-register.
end_comment

begin_decl_stmt
name|bool
name|registerDefIsDead
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|true
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// findRegisterUseOperandIdx() - Returns the operand index that is a use of
end_comment

begin_comment
comment|/// the specific register or -1 if it is not found. It further tightening
end_comment

begin_comment
comment|/// the search criteria to a use that kills the register if isKill is true.
end_comment

begin_decl_stmt
name|int
name|findRegisterUseOperandIdx
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|bool
name|isKill
operator|=
name|false
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// findRegisterUseOperand - Wrapper for findRegisterUseOperandIdx, it returns
end_comment

begin_comment
comment|/// a pointer to the MachineOperand rather than an index.
end_comment

begin_function
name|MachineOperand
modifier|*
name|findRegisterUseOperand
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isKill
init|=
name|false
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|NULL
parameter_list|)
block|{
name|int
name|Idx
init|=
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|isKill
argument_list|,
name|TRI
argument_list|)
decl_stmt|;
return|return
operator|(
name|Idx
operator|==
operator|-
literal|1
operator|)
condition|?
name|NULL
else|:
operator|&
name|getOperand
argument_list|(
name|Idx
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// findRegisterDefOperandIdx() - Returns the operand index that is a def of
end_comment

begin_comment
comment|/// the specified register or -1 if it is not found. If isDead is true, defs
end_comment

begin_comment
comment|/// that are not dead are skipped. If TargetRegisterInfo is non-null, then it
end_comment

begin_comment
comment|/// also checks if there is a def of a super-register.
end_comment

begin_decl_stmt
name|int
name|findRegisterDefOperandIdx
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|bool
name|isDead
operator|=
name|false
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// findRegisterDefOperand - Wrapper for findRegisterDefOperandIdx, it returns
end_comment

begin_comment
comment|/// a pointer to the MachineOperand rather than an index.
end_comment

begin_function
name|MachineOperand
modifier|*
name|findRegisterDefOperand
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isDead
init|=
name|false
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|NULL
parameter_list|)
block|{
name|int
name|Idx
init|=
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|isDead
argument_list|,
name|TRI
argument_list|)
decl_stmt|;
return|return
operator|(
name|Idx
operator|==
operator|-
literal|1
operator|)
condition|?
name|NULL
else|:
operator|&
name|getOperand
argument_list|(
name|Idx
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// findFirstPredOperandIdx() - Find the index of the first operand in the
end_comment

begin_comment
comment|/// operand list that is used to represent the predicate. It returns -1 if
end_comment

begin_comment
comment|/// none is found.
end_comment

begin_expr_stmt
name|int
name|findFirstPredOperandIdx
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isRegTiedToUseOperand - Given the index of a register def operand,
end_comment

begin_comment
comment|/// check if the register def is tied to a source operand, due to either
end_comment

begin_comment
comment|/// two-address elimination or inline assembly constraints. Returns the
end_comment

begin_comment
comment|/// first tied use operand index by reference is UseOpIdx is not null.
end_comment

begin_decl_stmt
name|bool
name|isRegTiedToUseOperand
argument_list|(
name|unsigned
name|DefOpIdx
argument_list|,
name|unsigned
operator|*
name|UseOpIdx
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isRegTiedToDefOperand - Return true if the use operand of the specified
end_comment

begin_comment
comment|/// index is tied to an def operand. It also returns the def operand index by
end_comment

begin_comment
comment|/// reference if DefOpIdx is not null.
end_comment

begin_decl_stmt
name|bool
name|isRegTiedToDefOperand
argument_list|(
name|unsigned
name|UseOpIdx
argument_list|,
name|unsigned
operator|*
name|DefOpIdx
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// copyKillDeadInfo - Copies kill / dead operand properties from MI.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|copyKillDeadInfo
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// copyPredicates - Copies predicate operand(s) from MI.
end_comment

begin_function_decl
name|void
name|copyPredicates
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addRegisterKilled - We have determined MI kills a register. Look for the
end_comment

begin_comment
comment|/// operand that uses it and mark it as IsKill. If AddIfNotFound is true,
end_comment

begin_comment
comment|/// add a implicit operand if it's not found. Returns true if the operand
end_comment

begin_comment
comment|/// exists / is added.
end_comment

begin_function_decl
name|bool
name|addRegisterKilled
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addRegisterDead - We have determined MI defined a register without a use.
end_comment

begin_comment
comment|/// Look for the operand that defines it and mark it as IsDead. If
end_comment

begin_comment
comment|/// AddIfNotFound is true, add a implicit operand if it's not found. Returns
end_comment

begin_comment
comment|/// true if the operand exists / is added.
end_comment

begin_function_decl
name|bool
name|addRegisterDead
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isSafeToMove - Return true if it is safe to move this instruction. If
end_comment

begin_comment
comment|/// SawStore is set to true, it means that there is a store (or call) between
end_comment

begin_comment
comment|/// the instruction's location and its intended destination.
end_comment

begin_decl_stmt
name|bool
name|isSafeToMove
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
name|bool
operator|&
name|SawStore
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isSafeToReMat - Return true if it's safe to rematerialize the specified
end_comment

begin_comment
comment|/// instruction which defined the specified register instead of copying it.
end_comment

begin_decl_stmt
name|bool
name|isSafeToReMat
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
name|unsigned
name|DstReg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasVolatileMemoryRef - Return true if this instruction may have a
end_comment

begin_comment
comment|/// volatile memory reference, or if the information describing the
end_comment

begin_comment
comment|/// memory reference is not available. Return false if it is known to
end_comment

begin_comment
comment|/// have no volatile memory references.
end_comment

begin_expr_stmt
name|bool
name|hasVolatileMemoryRef
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Debugging support
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|OS
argument_list|,
specifier|const
name|TargetMachine
operator|*
name|TM
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|,
name|TM
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|OS
argument_list|,
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|OS
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|*
name|OS
argument_list|,
specifier|const
name|TargetMachine
operator|*
name|TM
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|,
name|TM
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|*
name|OS
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Accessors used to build up machine instructions.
end_comment

begin_comment
comment|/// addOperand - Add the specified operand to the instruction.  If it is an
end_comment

begin_comment
comment|/// implicit operand, it is added to the end of the operand list.  If it is
end_comment

begin_comment
comment|/// an explicit operand it is added at the end of the explicit operand list
end_comment

begin_comment
comment|/// (before the first implicit operand).
end_comment

begin_function_decl
name|void
name|addOperand
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setDesc - Replace the instruction descriptor (thus opcode) of
end_comment

begin_comment
comment|/// the current instruction with a new one.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|setDesc
parameter_list|(
specifier|const
name|TargetInstrDesc
modifier|&
name|tid
parameter_list|)
block|{
name|TID
operator|=
operator|&
name|tid
expr_stmt|;
block|}
end_function

begin_comment
comment|/// setDebugLoc - Replace current source information with new such.
end_comment

begin_comment
comment|/// Avoid using this, the constructor argument is preferable.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|setDebugLoc
parameter_list|(
specifier|const
name|DebugLoc
name|dl
parameter_list|)
block|{
name|debugLoc
operator|=
name|dl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// RemoveOperand - Erase an operand  from an instruction, leaving it with one
end_comment

begin_comment
comment|/// fewer operand than it started with.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|RemoveOperand
parameter_list|(
name|unsigned
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addMemOperand - Add a MachineMemOperand to the machine instruction,
end_comment

begin_comment
comment|/// referencing arbitrary storage.
end_comment

begin_function_decl
name|void
name|addMemOperand
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|MachineMemOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// clearMemOperands - Erase all of this MachineInstr's MachineMemOperands.
end_comment

begin_function_decl
name|void
name|clearMemOperands
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// getRegInfo - If this instruction is embedded into a MachineFunction,
end_comment

begin_comment
comment|/// return the MachineRegisterInfo object for the current function, otherwise
end_comment

begin_comment
comment|/// return null.
end_comment

begin_function_decl
name|MachineRegisterInfo
modifier|*
name|getRegInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// addImplicitDefUseOperands - Add all implicit def and use operands to
end_comment

begin_comment
comment|/// this instruction.
end_comment

begin_function_decl
name|void
name|addImplicitDefUseOperands
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// RemoveRegOperandsFromUseLists - Unlink all of the register operands in
end_comment

begin_comment
comment|/// this instruction from their respective use lists.  This requires that the
end_comment

begin_comment
comment|/// operands already be on their use lists.
end_comment

begin_function_decl
name|void
name|RemoveRegOperandsFromUseLists
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// AddRegOperandsToUseLists - Add all of the register operands in
end_comment

begin_comment
comment|/// this instruction from their respective use lists.  This requires that the
end_comment

begin_comment
comment|/// operands not be on their use lists yet.
end_comment

begin_function_decl
name|void
name|AddRegOperandsToUseLists
parameter_list|(
name|MachineRegisterInfo
modifier|&
name|RegInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Debugging Support
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineInstr
operator|&
name|MI
operator|)
block|{
name|MI
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineInstr
operator|&
name|MI
operator|)
block|{
name|MI
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

