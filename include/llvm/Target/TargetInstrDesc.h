begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetInstrDesc.h - Instruction Descriptors -*- C++ -*-===//
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
comment|// This file defines the TargetOperandInfo and TargetInstrDesc classes, which
end_comment

begin_comment
comment|// are used to describe target instructions and their operands.
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
name|LLVM_TARGET_TARGETINSTRDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETINSTRDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Machine Operand Flags and Description
comment|//===----------------------------------------------------------------------===//
name|namespace
name|TOI
block|{
comment|// Operand constraints
enum|enum
name|OperandConstraint
block|{
name|TIED_TO
init|=
literal|0
block|,
comment|// Must be allocated the same register as.
name|EARLY_CLOBBER
comment|// Operand is an early clobber register operand
block|}
enum|;
comment|/// OperandFlags - These are flags set on operands, but should be considered
comment|/// private, all access should go through the TargetOperandInfo accessors.
comment|/// See the accessors for a description of what these are.
enum|enum
name|OperandFlags
block|{
name|LookupPtrRegClass
init|=
literal|0
block|,
name|Predicate
block|,
name|OptionalDef
block|}
enum|;
block|}
comment|/// TargetOperandInfo - This holds information about one operand of a machine
comment|/// instruction, indicating the register class for register operands, etc.
comment|///
name|class
name|TargetOperandInfo
block|{
name|public
label|:
comment|/// RegClass - This specifies the register class enumeration of the operand
comment|/// if the operand is a register.  If isLookupPtrRegClass is set, then this is
comment|/// an index that is passed to TargetRegisterInfo::getPointerRegClass(x) to
comment|/// get a dynamic register class.
comment|///
comment|/// NOTE: This member should be considered to be private, all access should go
comment|/// through "getRegClass(TRI)" below.
name|short
name|RegClass
decl_stmt|;
comment|/// Flags - These are flags from the TOI::OperandFlags enum.
name|unsigned
name|short
name|Flags
decl_stmt|;
comment|/// Lower 16 bits are used to specify which constraints are set. The higher 16
comment|/// bits are used to specify the value of constraints (4 bits each).
name|unsigned
name|Constraints
decl_stmt|;
comment|/// Currently no other information.
comment|/// getRegClass - Get the register class for the operand, handling resolution
comment|/// of "symbolic" pointer register classes etc.  If this is not a register
comment|/// operand, this returns null.
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClass
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// isLookupPtrRegClass - Set if this operand is a pointer value and it
comment|/// requires a callback to look up its register class.
name|bool
name|isLookupPtrRegClass
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TOI
operator|::
name|LookupPtrRegClass
operator|)
return|;
block|}
comment|/// isPredicate - Set if this is one of the operands that made up of
comment|/// the predicate operand that controls an isPredicable() instruction.
name|bool
name|isPredicate
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TOI
operator|::
name|Predicate
operator|)
return|;
block|}
comment|/// isOptionalDef - Set if this operand is a optional def.
comment|///
name|bool
name|isOptionalDef
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TOI
operator|::
name|OptionalDef
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Machine Instruction Flags and Description
comment|//===----------------------------------------------------------------------===//
comment|/// TargetInstrDesc flags - These should be considered private to the
comment|/// implementation of the TargetInstrDesc class.  Clients should use the
comment|/// predicate methods on TargetInstrDesc, not use these directly.  These
comment|/// all correspond to bitfields in the TargetInstrDesc::Flags field.
name|namespace
name|TID
block|{
enum|enum
block|{
name|Variadic
init|=
literal|0
block|,
name|HasOptionalDef
block|,
name|Return
block|,
name|Call
block|,
name|Barrier
block|,
name|Terminator
block|,
name|Branch
block|,
name|IndirectBranch
block|,
name|Compare
block|,
name|MoveImm
block|,
name|DelaySlot
block|,
name|FoldableAsLoad
block|,
name|MayLoad
block|,
name|MayStore
block|,
name|Predicable
block|,
name|NotDuplicable
block|,
name|UnmodeledSideEffects
block|,
name|Commutable
block|,
name|ConvertibleTo3Addr
block|,
name|UsesCustomInserter
block|,
name|Rematerializable
block|,
name|CheapAsAMove
block|,
name|ExtraSrcRegAllocReq
block|,
name|ExtraDefRegAllocReq
block|}
enum|;
block|}
comment|/// TargetInstrDesc - Describe properties that are true of each
comment|/// instruction in the target description file.  This captures information about
comment|/// side effects, register use and many other things.  There is one instance of
comment|/// this struct for each target instruction class, and the MachineInstr class
comment|/// points to this struct directly to describe itself.
name|class
name|TargetInstrDesc
block|{
name|public
label|:
name|unsigned
name|short
name|Opcode
decl_stmt|;
comment|// The opcode number
name|unsigned
name|short
name|NumOperands
decl_stmt|;
comment|// Num of args (may be more if variable_ops)
name|unsigned
name|short
name|NumDefs
decl_stmt|;
comment|// Num of args that are definitions
name|unsigned
name|short
name|SchedClass
decl_stmt|;
comment|// enum identifying instr sched class
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Name of the instruction record in td file
name|unsigned
name|Flags
decl_stmt|;
comment|// Flags identifying machine instr class
name|uint64_t
name|TSFlags
decl_stmt|;
comment|// Target Specific Flag values
specifier|const
name|unsigned
modifier|*
name|ImplicitUses
decl_stmt|;
comment|// Registers implicitly read by this instr
specifier|const
name|unsigned
modifier|*
name|ImplicitDefs
decl_stmt|;
comment|// Registers implicitly defined by this instr
specifier|const
name|TargetRegisterClass
modifier|*
modifier|*
name|RCBarriers
decl_stmt|;
comment|// Reg classes completely "clobbered"
specifier|const
name|TargetOperandInfo
modifier|*
name|OpInfo
decl_stmt|;
comment|// 'NumOperands' entries about operands
comment|/// getOperandConstraint - Returns the value of the specific constraint if
comment|/// it is set. Returns -1 if it is not set.
name|int
name|getOperandConstraint
argument_list|(
name|unsigned
name|OpNum
argument_list|,
name|TOI
operator|::
name|OperandConstraint
name|Constraint
argument_list|)
decl|const
block|{
if|if
condition|(
name|OpNum
operator|<
name|NumOperands
operator|&&
operator|(
name|OpInfo
index|[
name|OpNum
index|]
operator|.
name|Constraints
operator|&
operator|(
literal|1
operator|<<
name|Constraint
operator|)
operator|)
condition|)
block|{
name|unsigned
name|Pos
init|=
literal|16
operator|+
name|Constraint
operator|*
literal|4
decl_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
name|OpInfo
index|[
name|OpNum
index|]
operator|.
name|Constraints
operator|>>
name|Pos
argument_list|)
operator|&
literal|0xf
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
comment|/// getRegClass - Returns the register class constraint for OpNum, or NULL.
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClass
argument_list|(
name|unsigned
name|OpNum
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
return|return
name|OpNum
operator|<
name|NumOperands
condition|?
name|OpInfo
index|[
name|OpNum
index|]
operator|.
name|getRegClass
argument_list|(
name|TRI
argument_list|)
else|:
literal|0
return|;
block|}
comment|/// getOpcode - Return the opcode number for this descriptor.
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Opcode
return|;
block|}
comment|/// getName - Return the name of the record in the .td file for this
comment|/// instruction, for example "ADD8ri".
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getNumOperands - Return the number of declared MachineOperands for this
comment|/// MachineInstruction.  Note that variadic (isVariadic() returns true)
comment|/// instructions may have additional operands at the end of the list, and note
comment|/// that the machine instruction may include implicit register def/uses as
comment|/// well.
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
comment|/// getNumDefs - Return the number of MachineOperands that are register
comment|/// definitions.  Register definitions always occur at the start of the
comment|/// machine operand list.  This is the number of "outs" in the .td file,
comment|/// and does not include implicit defs.
name|unsigned
name|getNumDefs
argument_list|()
specifier|const
block|{
return|return
name|NumDefs
return|;
block|}
comment|/// isVariadic - Return true if this instruction can have a variable number of
comment|/// operands.  In this case, the variable operands will be after the normal
comment|/// operands but before the implicit definitions and uses (if any are
comment|/// present).
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Variadic
operator|)
return|;
block|}
comment|/// hasOptionalDef - Set if this instruction has an optional definition, e.g.
comment|/// ARM instructions which can set condition code if 's' bit is set.
name|bool
name|hasOptionalDef
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|HasOptionalDef
operator|)
return|;
block|}
comment|/// getImplicitUses - Return a list of registers that are potentially
comment|/// read by any instance of this machine instruction.  For example, on X86,
comment|/// the "adc" instruction adds two register operands and adds the carry bit in
comment|/// from the flags register.  In this case, the instruction is marked as
comment|/// implicitly reading the flags.  Likewise, the variable shift instruction on
comment|/// X86 is marked as implicitly reading the 'CL' register, which it always
comment|/// does.
comment|///
comment|/// This method returns null if the instruction has no implicit uses.
specifier|const
name|unsigned
operator|*
name|getImplicitUses
argument_list|()
specifier|const
block|{
return|return
name|ImplicitUses
return|;
block|}
comment|/// getNumImplicitUses - Return the number of implicit uses this instruction
comment|/// has.
name|unsigned
name|getNumImplicitUses
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ImplicitUses
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|unsigned
name|i
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
name|ImplicitUses
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
comment|/*empty*/
empty_stmt|;
return|return
name|i
return|;
block|}
comment|/// getImplicitDefs - Return a list of registers that are potentially
comment|/// written by any instance of this machine instruction.  For example, on X86,
comment|/// many instructions implicitly set the flags register.  In this case, they
comment|/// are marked as setting the FLAGS.  Likewise, many instructions always
comment|/// deposit their result in a physical register.  For example, the X86 divide
comment|/// instruction always deposits the quotient and remainder in the EAX/EDX
comment|/// registers.  For that instruction, this will return a list containing the
comment|/// EAX/EDX/EFLAGS registers.
comment|///
comment|/// This method returns null if the instruction has no implicit defs.
specifier|const
name|unsigned
operator|*
name|getImplicitDefs
argument_list|()
specifier|const
block|{
return|return
name|ImplicitDefs
return|;
block|}
comment|/// getNumImplicitDefs - Return the number of implicit defs this instruction
comment|/// has.
name|unsigned
name|getNumImplicitDefs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ImplicitDefs
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|unsigned
name|i
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
name|ImplicitDefs
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
comment|/*empty*/
empty_stmt|;
return|return
name|i
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasImplicitUseOfPhysReg - Return true if this instruction implicitly
end_comment

begin_comment
comment|/// uses the specified physical register.
end_comment

begin_decl_stmt
name|bool
name|hasImplicitUseOfPhysReg
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|unsigned
modifier|*
name|ImpUses
init|=
name|ImplicitUses
condition|)
for|for
control|(
init|;
operator|*
name|ImpUses
condition|;
operator|++
name|ImpUses
control|)
if|if
condition|(
operator|*
name|ImpUses
operator|==
name|Reg
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasImplicitDefOfPhysReg - Return true if this instruction implicitly
end_comment

begin_comment
comment|/// defines the specified physical register.
end_comment

begin_decl_stmt
name|bool
name|hasImplicitDefOfPhysReg
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|unsigned
modifier|*
name|ImpDefs
init|=
name|ImplicitDefs
condition|)
for|for
control|(
init|;
operator|*
name|ImpDefs
condition|;
operator|++
name|ImpDefs
control|)
if|if
condition|(
operator|*
name|ImpDefs
operator|==
name|Reg
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getRegClassBarriers - Return a list of register classes that are
end_comment

begin_comment
comment|/// completely clobbered by this machine instruction. For example, on X86
end_comment

begin_comment
comment|/// the call instructions will completely clobber all the registers in the
end_comment

begin_comment
comment|/// fp stack and XMM classes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method returns null if the instruction doesn't completely clobber
end_comment

begin_comment
comment|/// any register class.
end_comment

begin_expr_stmt
specifier|const
name|TargetRegisterClass
operator|*
operator|*
name|getRegClassBarriers
argument_list|()
specifier|const
block|{
return|return
name|RCBarriers
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getSchedClass - Return the scheduling class for this instruction.  The
end_comment

begin_comment
comment|/// scheduling class is an index into the InstrItineraryData table.  This
end_comment

begin_comment
comment|/// returns zero if there is no known scheduling information for the
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getSchedClass
argument_list|()
specifier|const
block|{
return|return
name|SchedClass
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isReturn
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Return
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isCall
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Call
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isBarrier - Returns true if the specified instruction stops control flow
end_comment

begin_comment
comment|/// from executing the instruction immediately following it.  Examples include
end_comment

begin_comment
comment|/// unconditional branches and return instructions.
end_comment

begin_expr_stmt
name|bool
name|isBarrier
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Barrier
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isTerminator - Returns true if this instruction part of the terminator for
end_comment

begin_comment
comment|/// a basic block.  Typically this is things like return and branch
end_comment

begin_comment
comment|/// instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Various passes use this to insert code into the bottom of a basic block,
end_comment

begin_comment
comment|/// but before control flow occurs.
end_comment

begin_expr_stmt
name|bool
name|isTerminator
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Terminator
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isBranch - Returns true if this is a conditional, unconditional, or
end_comment

begin_comment
comment|/// indirect branch.  Predicates below can be used to discriminate between
end_comment

begin_comment
comment|/// these cases, and the TargetInstrInfo::AnalyzeBranch method can be used to
end_comment

begin_comment
comment|/// get more information.
end_comment

begin_expr_stmt
name|bool
name|isBranch
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Branch
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isIndirectBranch - Return true if this is an indirect branch, such as a
end_comment

begin_comment
comment|/// branch through a register.
end_comment

begin_expr_stmt
name|bool
name|isIndirectBranch
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|IndirectBranch
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isConditionalBranch - Return true if this is a branch which may fall
end_comment

begin_comment
comment|/// through to the next instruction or may transfer control flow to some other
end_comment

begin_comment
comment|/// block.  The TargetInstrInfo::AnalyzeBranch method can be used to get more
end_comment

begin_comment
comment|/// information about this branch.
end_comment

begin_expr_stmt
name|bool
name|isConditionalBranch
argument_list|()
specifier|const
block|{
return|return
name|isBranch
argument_list|()
operator|&
operator|!
name|isBarrier
argument_list|()
operator|&
operator|!
name|isIndirectBranch
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isUnconditionalBranch - Return true if this is a branch which always
end_comment

begin_comment
comment|/// transfers control flow to some other block.  The
end_comment

begin_comment
comment|/// TargetInstrInfo::AnalyzeBranch method can be used to get more information
end_comment

begin_comment
comment|/// about this branch.
end_comment

begin_expr_stmt
name|bool
name|isUnconditionalBranch
argument_list|()
specifier|const
block|{
return|return
name|isBranch
argument_list|()
operator|&
name|isBarrier
argument_list|()
operator|&
operator|!
name|isIndirectBranch
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// isPredicable - Return true if this instruction has a predicate operand that
end_comment

begin_comment
comment|// controls execution.  It may be set to 'always', or may be set to other
end_comment

begin_comment
comment|/// values.   There are various methods in TargetInstrInfo that can be used to
end_comment

begin_comment
comment|/// control and modify the predicate in this instruction.
end_comment

begin_expr_stmt
name|bool
name|isPredicable
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Predicable
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isCompare - Return true if this instruction is a comparison.
end_comment

begin_expr_stmt
name|bool
name|isCompare
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Compare
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isMoveImmediate - Return true if this instruction is a move immediate
end_comment

begin_comment
comment|/// (including conditional moves) instruction.
end_comment

begin_expr_stmt
name|bool
name|isMoveImmediate
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|MoveImm
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isNotDuplicable - Return true if this instruction cannot be safely
end_comment

begin_comment
comment|/// duplicated.  For example, if the instruction has a unique labels attached
end_comment

begin_comment
comment|/// to it, duplicating it would cause multiple definition errors.
end_comment

begin_expr_stmt
name|bool
name|isNotDuplicable
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|NotDuplicable
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasDelaySlot - Returns true if the specified instruction has a delay slot
end_comment

begin_comment
comment|/// which must be filled by the code generator.
end_comment

begin_expr_stmt
name|bool
name|hasDelaySlot
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|DelaySlot
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// canFoldAsLoad - Return true for instructions that can be folded as
end_comment

begin_comment
comment|/// memory operands in other instructions. The most common use for this
end_comment

begin_comment
comment|/// is instructions that are simple loads from memory that don't modify
end_comment

begin_comment
comment|/// the loaded value in any way, but it can also be used for instructions
end_comment

begin_comment
comment|/// that can be expressed as constant-pool loads, such as V_SETALLONES
end_comment

begin_comment
comment|/// on x86, to allow them to be folded when it is beneficial.
end_comment

begin_comment
comment|/// This should only be set on instructions that return a value in their
end_comment

begin_comment
comment|/// only virtual register definition.
end_comment

begin_expr_stmt
name|bool
name|canFoldAsLoad
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|FoldableAsLoad
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Side Effect Analysis
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// mayLoad - Return true if this instruction could possibly read memory.
end_comment

begin_comment
comment|/// Instructions with this flag set are not necessarily simple load
end_comment

begin_comment
comment|/// instructions, they may load a value and modify it, for example.
end_comment

begin_expr_stmt
name|bool
name|mayLoad
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|MayLoad
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// mayStore - Return true if this instruction could possibly modify memory.
end_comment

begin_comment
comment|/// Instructions with this flag set are not necessarily simple store
end_comment

begin_comment
comment|/// instructions, they may store a modified value based on their operands, or
end_comment

begin_comment
comment|/// may not actually modify anything, for example.
end_comment

begin_expr_stmt
name|bool
name|mayStore
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|MayStore
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasUnmodeledSideEffects - Return true if this instruction has side
end_comment

begin_comment
comment|/// effects that are not modeled by other flags.  This does not return true
end_comment

begin_comment
comment|/// for instructions whose effects are captured by:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  1. Their operand list and implicit definition/use list.  Register use/def
end_comment

begin_comment
comment|///     info is explicit for instructions.
end_comment

begin_comment
comment|///  2. Memory accesses.  Use mayLoad/mayStore.
end_comment

begin_comment
comment|///  3. Calling, branching, returning: use isCall/isReturn/isBranch.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Examples of side effects would be modifying 'invisible' machine state like
end_comment

begin_comment
comment|/// a control register, flushing a cache, modifying a register invisible to
end_comment

begin_comment
comment|/// LLVM, etc.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|hasUnmodeledSideEffects
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|UnmodeledSideEffects
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Flags that indicate whether an instruction can be modified by a method.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// isCommutable - Return true if this may be a 2- or 3-address
end_comment

begin_comment
comment|/// instruction (of the form "X = op Y, Z, ..."), which produces the same
end_comment

begin_comment
comment|/// result if Y and Z are exchanged.  If this flag is set, then the
end_comment

begin_comment
comment|/// TargetInstrInfo::commuteInstruction method may be used to hack on the
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this flag may be set on instructions that are only commutable
end_comment

begin_comment
comment|/// sometimes.  In these cases, the call to commuteInstruction will fail.
end_comment

begin_comment
comment|/// Also note that some instructions require non-trivial modification to
end_comment

begin_comment
comment|/// commute them.
end_comment

begin_expr_stmt
name|bool
name|isCommutable
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Commutable
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isConvertibleTo3Addr - Return true if this is a 2-address instruction
end_comment

begin_comment
comment|/// which can be changed into a 3-address instruction if needed.  Doing this
end_comment

begin_comment
comment|/// transformation can be profitable in the register allocator, because it
end_comment

begin_comment
comment|/// means that the instruction can use a 2-address form if possible, but
end_comment

begin_comment
comment|/// degrade into a less efficient form if the source and dest register cannot
end_comment

begin_comment
comment|/// be assigned to the same register.  For example, this allows the x86
end_comment

begin_comment
comment|/// backend to turn a "shl reg, 3" instruction into an LEA instruction, which
end_comment

begin_comment
comment|/// is the same speed as the shift but has bigger code size.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns true, then the target must implement the
end_comment

begin_comment
comment|/// TargetInstrInfo::convertToThreeAddress method for this instruction, which
end_comment

begin_comment
comment|/// is allowed to fail if the transformation isn't valid for this specific
end_comment

begin_comment
comment|/// instruction (e.g. shl reg, 4 on x86).
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isConvertibleTo3Addr
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|ConvertibleTo3Addr
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// usesCustomInsertionHook - Return true if this instruction requires
end_comment

begin_comment
comment|/// custom insertion support when the DAG scheduler is inserting it into a
end_comment

begin_comment
comment|/// machine basic block.  If this is true for the instruction, it basically
end_comment

begin_comment
comment|/// means that it is a pseudo instruction used at SelectionDAG time that is
end_comment

begin_comment
comment|/// expanded out into magic code by the target when MachineInstrs are formed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this is true, the TargetLoweringInfo::InsertAtEndOfBasicBlock method
end_comment

begin_comment
comment|/// is used to insert this into the MachineBasicBlock.
end_comment

begin_expr_stmt
name|bool
name|usesCustomInsertionHook
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|UsesCustomInserter
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isRematerializable - Returns true if this instruction is a candidate for
end_comment

begin_comment
comment|/// remat.  This flag is deprecated, please don't use it anymore.  If this
end_comment

begin_comment
comment|/// flag is set, the isReallyTriviallyReMaterializable() method is called to
end_comment

begin_comment
comment|/// verify the instruction is really rematable.
end_comment

begin_expr_stmt
name|bool
name|isRematerializable
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|Rematerializable
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isAsCheapAsAMove - Returns true if this instruction has the same cost (or
end_comment

begin_comment
comment|/// less) than a move instruction. This is useful during certain types of
end_comment

begin_comment
comment|/// optimizations (e.g., remat during two-address conversion or machine licm)
end_comment

begin_comment
comment|/// where we would like to remat or hoist the instruction, but not if it costs
end_comment

begin_comment
comment|/// more than moving the instruction into the appropriate register. Note, we
end_comment

begin_comment
comment|/// are not marking copies from and to the same register class with this flag.
end_comment

begin_expr_stmt
name|bool
name|isAsCheapAsAMove
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|CheapAsAMove
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasExtraSrcRegAllocReq - Returns true if this instruction source operands
end_comment

begin_comment
comment|/// have special register allocation requirements that are not captured by the
end_comment

begin_comment
comment|/// operand register classes. e.g. ARM::STRD's two source registers must be an
end_comment

begin_comment
comment|/// even / odd pair, ARM::STM registers have to be in ascending order.
end_comment

begin_comment
comment|/// Post-register allocation passes should not attempt to change allocations
end_comment

begin_comment
comment|/// for sources of instructions with this flag.
end_comment

begin_expr_stmt
name|bool
name|hasExtraSrcRegAllocReq
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|ExtraSrcRegAllocReq
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasExtraDefRegAllocReq - Returns true if this instruction def operands
end_comment

begin_comment
comment|/// have special register allocation requirements that are not captured by the
end_comment

begin_comment
comment|/// operand register classes. e.g. ARM::LDRD's two def registers must be an
end_comment

begin_comment
comment|/// even / odd pair, ARM::LDM registers have to be in ascending order.
end_comment

begin_comment
comment|/// Post-register allocation passes should not attempt to change allocations
end_comment

begin_comment
comment|/// for definitions of instructions with this flag.
end_comment

begin_expr_stmt
name|bool
name|hasExtraDefRegAllocReq
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|TID
operator|::
name|ExtraDefRegAllocReq
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

