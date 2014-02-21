begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCInstrDesc.h - Instruction Descriptors -*- C++ -*-===//
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
comment|// This file defines the MCOperandInfo and MCInstrDesc classes, which
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
name|LLVM_MC_MCINSTRDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTRDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Machine Operand Flags and Description
comment|//===----------------------------------------------------------------------===//
name|namespace
name|MCOI
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
comment|/// private, all access should go through the MCOperandInfo accessors.
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
comment|/// Operand Type - Operands are tagged with one of the values of this enum.
enum|enum
name|OperandType
block|{
name|OPERAND_UNKNOWN
block|,
name|OPERAND_IMMEDIATE
block|,
name|OPERAND_REGISTER
block|,
name|OPERAND_MEMORY
block|,
name|OPERAND_PCREL
block|}
enum|;
block|}
comment|/// MCOperandInfo - This holds information about one operand of a machine
comment|/// instruction, indicating the register class for register operands, etc.
comment|///
name|class
name|MCOperandInfo
block|{
name|public
label|:
comment|/// RegClass - This specifies the register class enumeration of the operand
comment|/// if the operand is a register.  If isLookupPtrRegClass is set, then this is
comment|/// an index that is passed to TargetRegisterInfo::getPointerRegClass(x) to
comment|/// get a dynamic register class.
name|int16_t
name|RegClass
decl_stmt|;
comment|/// Flags - These are flags from the MCOI::OperandFlags enum.
name|uint8_t
name|Flags
decl_stmt|;
comment|/// OperandType - Information about the type of the operand.
name|uint8_t
name|OperandType
decl_stmt|;
comment|/// Lower 16 bits are used to specify which constraints are set. The higher 16
comment|/// bits are used to specify the value of constraints (4 bits each).
name|uint32_t
name|Constraints
decl_stmt|;
comment|/// Currently no other information.
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
name|MCOI
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
name|MCOI
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
name|MCOI
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
comment|/// MCInstrDesc flags - These should be considered private to the
comment|/// implementation of the MCInstrDesc class.  Clients should use the predicate
comment|/// methods on MCInstrDesc, not use these directly.  These all correspond to
comment|/// bitfields in the MCInstrDesc::Flags field.
name|namespace
name|MCID
block|{
enum|enum
block|{
name|Variadic
init|=
literal|0
block|,
name|HasOptionalDef
block|,
name|Pseudo
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
name|Bitcast
block|,
name|Select
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
name|HasPostISelHook
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
comment|/// MCInstrDesc - Describe properties that are true of each instruction in the
comment|/// target description file.  This captures information about side effects,
comment|/// register use and many other things.  There is one instance of this struct
comment|/// for each target instruction class, and the MachineInstr class points to
comment|/// this struct directly to describe itself.
name|class
name|MCInstrDesc
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
name|unsigned
name|short
name|Size
decl_stmt|;
comment|// Number of bytes in encoding.
name|unsigned
name|Flags
decl_stmt|;
comment|// Flags identifying machine instr class
name|uint64_t
name|TSFlags
decl_stmt|;
comment|// Target Specific Flag values
specifier|const
name|uint16_t
modifier|*
name|ImplicitUses
decl_stmt|;
comment|// Registers implicitly read by this instr
specifier|const
name|uint16_t
modifier|*
name|ImplicitDefs
decl_stmt|;
comment|// Registers implicitly defined by this instr
specifier|const
name|MCOperandInfo
modifier|*
name|OpInfo
decl_stmt|;
comment|// 'NumOperands' entries about operands
name|uint64_t
name|DeprecatedFeatureMask
decl_stmt|;
comment|// Feature bits that this is deprecated on, if any
comment|// A complex method to determine is a certain is deprecated or not, and return
comment|// the reason for deprecation.
name|bool
argument_list|(
operator|*
name|ComplexDeprecationInfo
argument_list|)
argument_list|(
name|MCInst
operator|&
argument_list|,
name|MCSubtargetInfo
operator|&
argument_list|,
name|std
operator|::
name|string
operator|&
argument_list|)
expr_stmt|;
comment|/// \brief Returns the value of the specific constraint if
comment|/// it is set. Returns -1 if it is not set.
name|int
name|getOperandConstraint
argument_list|(
name|unsigned
name|OpNum
argument_list|,
name|MCOI
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
comment|/// \brief Returns true if a certain instruction is deprecated and if so
comment|/// returns the reason in \p Info.
name|bool
name|getDeprecatedInfo
argument_list|(
name|MCInst
operator|&
name|MI
argument_list|,
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|std
operator|::
name|string
operator|&
name|Info
argument_list|)
decl|const
block|{
if|if
condition|(
name|ComplexDeprecationInfo
condition|)
return|return
name|ComplexDeprecationInfo
argument_list|(
name|MI
argument_list|,
name|STI
argument_list|,
name|Info
argument_list|)
return|;
if|if
condition|(
operator|(
name|DeprecatedFeatureMask
operator|&
name|STI
operator|.
name|getFeatureBits
argument_list|()
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// FIXME: it would be nice to include the subtarget feature here.
name|Info
operator|=
literal|"deprecated"
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Return the opcode number for this descriptor.
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Opcode
return|;
block|}
comment|/// \brief Return the number of declared MachineOperands for this
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
comment|/// \brief Return the number of MachineOperands that are register
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
comment|/// \brief Return flags of this instruction.
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// \brief Return true if this instruction can have a variable number of
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
name|MCID
operator|::
name|Variadic
operator|)
return|;
block|}
comment|/// \brief Set if this instruction has an optional definition, e.g.
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
name|MCID
operator|::
name|HasOptionalDef
operator|)
return|;
block|}
comment|/// \brief Return true if this is a pseudo instruction that doesn't
comment|/// correspond to a real machine instruction.
comment|///
name|bool
name|isPseudo
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|MCID
operator|::
name|Pseudo
operator|)
return|;
block|}
comment|/// \brief Return true if the instruction is a return.
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
name|MCID
operator|::
name|Return
operator|)
return|;
block|}
comment|/// \brief  Return true if the instruction is a call.
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
name|MCID
operator|::
name|Call
operator|)
return|;
block|}
comment|/// \brief Returns true if the specified instruction stops control flow
comment|/// from executing the instruction immediately following it.  Examples include
comment|/// unconditional branches and return instructions.
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
name|MCID
operator|::
name|Barrier
operator|)
return|;
block|}
comment|/// \brief Returns true if this instruction part of the terminator for
comment|/// a basic block.  Typically this is things like return and branch
comment|/// instructions.
comment|///
comment|/// Various passes use this to insert code into the bottom of a basic block,
comment|/// but before control flow occurs.
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
name|MCID
operator|::
name|Terminator
operator|)
return|;
block|}
comment|/// \brief Returns true if this is a conditional, unconditional, or
comment|/// indirect branch.  Predicates below can be used to discriminate between
comment|/// these cases, and the TargetInstrInfo::AnalyzeBranch method can be used to
comment|/// get more information.
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
name|MCID
operator|::
name|Branch
operator|)
return|;
block|}
comment|/// \brief Return true if this is an indirect branch, such as a
comment|/// branch through a register.
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
name|MCID
operator|::
name|IndirectBranch
operator|)
return|;
block|}
comment|/// \brief Return true if this is a branch which may fall
comment|/// through to the next instruction or may transfer control flow to some other
comment|/// block.  The TargetInstrInfo::AnalyzeBranch method can be used to get more
comment|/// information about this branch.
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
comment|/// \brief Return true if this is a branch which always
comment|/// transfers control flow to some other block.  The
comment|/// TargetInstrInfo::AnalyzeBranch method can be used to get more information
comment|/// about this branch.
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
comment|/// \brief Return true if this is a branch or an instruction which directly
comment|/// writes to the program counter. Considered 'may' affect rather than
comment|/// 'does' affect as things like predication are not taken into account.
name|bool
name|mayAffectControlFlow
argument_list|(
specifier|const
name|MCInst
operator|&
name|MI
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|RI
argument_list|)
decl|const
block|{
if|if
condition|(
name|isBranch
argument_list|()
operator|||
name|isCall
argument_list|()
operator|||
name|isReturn
argument_list|()
operator|||
name|isIndirectBranch
argument_list|()
condition|)
return|return
name|true
return|;
name|unsigned
name|PC
init|=
name|RI
operator|.
name|getProgramCounter
argument_list|()
decl_stmt|;
if|if
condition|(
name|PC
operator|==
literal|0
condition|)
return|return
name|false
return|;
if|if
condition|(
name|hasDefOfPhysReg
argument_list|(
name|MI
argument_list|,
name|PC
argument_list|,
name|RI
argument_list|)
condition|)
return|return
name|true
return|;
comment|// A variadic instruction may define PC in the variable operand list.
comment|// There's currently no indication of which entries in a variable
comment|// list are defs and which are uses. While that's the case, this function
comment|// needs to assume they're defs in order to be conservatively correct.
for|for
control|(
name|int
name|i
init|=
name|NumOperands
init|,
name|e
init|=
name|MI
operator|.
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
block|{
if|if
condition|(
name|MI
operator|.
name|getOperand
argument_list|(
name|i
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|RI
operator|.
name|isSubRegisterEq
argument_list|(
name|PC
argument_list|,
name|MI
operator|.
name|getOperand
argument_list|(
name|i
argument_list|)
operator|.
name|getReg
argument_list|()
argument_list|)
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Return true if this instruction has a predicate operand
comment|/// that controls execution. It may be set to 'always', or may be set to other
comment|/// values. There are various methods in TargetInstrInfo that can be used to
comment|/// control and modify the predicate in this instruction.
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
name|MCID
operator|::
name|Predicable
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction is a comparison.
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
name|MCID
operator|::
name|Compare
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction is a move immediate
comment|/// (including conditional moves) instruction.
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
name|MCID
operator|::
name|MoveImm
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction is a bitcast instruction.
name|bool
name|isBitcast
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|MCID
operator|::
name|Bitcast
operator|)
return|;
block|}
comment|/// \brief Return true if this is a select instruction.
name|bool
name|isSelect
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|MCID
operator|::
name|Select
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction cannot be safely
comment|/// duplicated.  For example, if the instruction has a unique labels attached
comment|/// to it, duplicating it would cause multiple definition errors.
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
name|MCID
operator|::
name|NotDuplicable
operator|)
return|;
block|}
comment|/// hasDelaySlot - Returns true if the specified instruction has a delay slot
comment|/// which must be filled by the code generator.
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
name|MCID
operator|::
name|DelaySlot
operator|)
return|;
block|}
comment|/// canFoldAsLoad - Return true for instructions that can be folded as
comment|/// memory operands in other instructions. The most common use for this
comment|/// is instructions that are simple loads from memory that don't modify
comment|/// the loaded value in any way, but it can also be used for instructions
comment|/// that can be expressed as constant-pool loads, such as V_SETALLONES
comment|/// on x86, to allow them to be folded when it is beneficial.
comment|/// This should only be set on instructions that return a value in their
comment|/// only virtual register definition.
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
name|MCID
operator|::
name|FoldableAsLoad
operator|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Side Effect Analysis
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return true if this instruction could possibly read memory.
comment|/// Instructions with this flag set are not necessarily simple load
comment|/// instructions, they may load a value and modify it, for example.
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
name|MCID
operator|::
name|MayLoad
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction could possibly modify memory.
comment|/// Instructions with this flag set are not necessarily simple store
comment|/// instructions, they may store a modified value based on their operands, or
comment|/// may not actually modify anything, for example.
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
name|MCID
operator|::
name|MayStore
operator|)
return|;
block|}
comment|/// hasUnmodeledSideEffects - Return true if this instruction has side
comment|/// effects that are not modeled by other flags.  This does not return true
comment|/// for instructions whose effects are captured by:
comment|///
comment|///  1. Their operand list and implicit definition/use list.  Register use/def
comment|///     info is explicit for instructions.
comment|///  2. Memory accesses.  Use mayLoad/mayStore.
comment|///  3. Calling, branching, returning: use isCall/isReturn/isBranch.
comment|///
comment|/// Examples of side effects would be modifying 'invisible' machine state like
comment|/// a control register, flushing a cache, modifying a register invisible to
comment|/// LLVM, etc.
comment|///
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
name|MCID
operator|::
name|UnmodeledSideEffects
operator|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Flags that indicate whether an instruction can be modified by a method.
comment|//===--------------------------------------------------------------------===//
comment|/// isCommutable - Return true if this may be a 2- or 3-address
comment|/// instruction (of the form "X = op Y, Z, ..."), which produces the same
comment|/// result if Y and Z are exchanged.  If this flag is set, then the
comment|/// TargetInstrInfo::commuteInstruction method may be used to hack on the
comment|/// instruction.
comment|///
comment|/// Note that this flag may be set on instructions that are only commutable
comment|/// sometimes.  In these cases, the call to commuteInstruction will fail.
comment|/// Also note that some instructions require non-trivial modification to
comment|/// commute them.
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
name|MCID
operator|::
name|Commutable
operator|)
return|;
block|}
comment|/// isConvertibleTo3Addr - Return true if this is a 2-address instruction
comment|/// which can be changed into a 3-address instruction if needed.  Doing this
comment|/// transformation can be profitable in the register allocator, because it
comment|/// means that the instruction can use a 2-address form if possible, but
comment|/// degrade into a less efficient form if the source and dest register cannot
comment|/// be assigned to the same register.  For example, this allows the x86
comment|/// backend to turn a "shl reg, 3" instruction into an LEA instruction, which
comment|/// is the same speed as the shift but has bigger code size.
comment|///
comment|/// If this returns true, then the target must implement the
comment|/// TargetInstrInfo::convertToThreeAddress method for this instruction, which
comment|/// is allowed to fail if the transformation isn't valid for this specific
comment|/// instruction (e.g. shl reg, 4 on x86).
comment|///
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
name|MCID
operator|::
name|ConvertibleTo3Addr
operator|)
return|;
block|}
comment|/// usesCustomInsertionHook - Return true if this instruction requires
comment|/// custom insertion support when the DAG scheduler is inserting it into a
comment|/// machine basic block.  If this is true for the instruction, it basically
comment|/// means that it is a pseudo instruction used at SelectionDAG time that is
comment|/// expanded out into magic code by the target when MachineInstrs are formed.
comment|///
comment|/// If this is true, the TargetLoweringInfo::InsertAtEndOfBasicBlock method
comment|/// is used to insert this into the MachineBasicBlock.
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
name|MCID
operator|::
name|UsesCustomInserter
operator|)
return|;
block|}
comment|/// hasPostISelHook - Return true if this instruction requires *adjustment*
comment|/// after instruction selection by calling a target hook. For example, this
comment|/// can be used to fill in ARM 's' optional operand depending on whether
comment|/// the conditional flag register is used.
name|bool
name|hasPostISelHook
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1
operator|<<
name|MCID
operator|::
name|HasPostISelHook
operator|)
return|;
block|}
comment|/// isRematerializable - Returns true if this instruction is a candidate for
comment|/// remat.  This flag is deprecated, please don't use it anymore.  If this
comment|/// flag is set, the isReallyTriviallyReMaterializable() method is called to
comment|/// verify the instruction is really rematable.
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
name|MCID
operator|::
name|Rematerializable
operator|)
return|;
block|}
comment|/// isAsCheapAsAMove - Returns true if this instruction has the same cost (or
comment|/// less) than a move instruction. This is useful during certain types of
comment|/// optimizations (e.g., remat during two-address conversion or machine licm)
comment|/// where we would like to remat or hoist the instruction, but not if it costs
comment|/// more than moving the instruction into the appropriate register. Note, we
comment|/// are not marking copies from and to the same register class with this flag.
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
name|MCID
operator|::
name|CheapAsAMove
operator|)
return|;
block|}
comment|/// hasExtraSrcRegAllocReq - Returns true if this instruction source operands
comment|/// have special register allocation requirements that are not captured by the
comment|/// operand register classes. e.g. ARM::STRD's two source registers must be an
comment|/// even / odd pair, ARM::STM registers have to be in ascending order.
comment|/// Post-register allocation passes should not attempt to change allocations
comment|/// for sources of instructions with this flag.
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
name|MCID
operator|::
name|ExtraSrcRegAllocReq
operator|)
return|;
block|}
comment|/// hasExtraDefRegAllocReq - Returns true if this instruction def operands
comment|/// have special register allocation requirements that are not captured by the
comment|/// operand register classes. e.g. ARM::LDRD's two def registers must be an
comment|/// even / odd pair, ARM::LDM registers have to be in ascending order.
comment|/// Post-register allocation passes should not attempt to change allocations
comment|/// for definitions of instructions with this flag.
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
name|MCID
operator|::
name|ExtraDefRegAllocReq
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
name|uint16_t
operator|*
name|getImplicitUses
argument_list|()
specifier|const
block|{
return|return
name|ImplicitUses
return|;
block|}
comment|/// \brief Return the number of implicit uses this instruction has.
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
name|uint16_t
operator|*
name|getImplicitDefs
argument_list|()
specifier|const
block|{
return|return
name|ImplicitDefs
return|;
block|}
comment|/// \brief Return the number of implicit defs this instruct has.
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
comment|/// \brief Return true if this instruction implicitly
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
name|uint16_t
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
comment|/// \brief Return true if this instruction implicitly
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
argument_list|,
specifier|const
name|MCRegisterInfo
operator|*
name|MRI
operator|=
literal|0
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|uint16_t
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
operator|||
operator|(
name|MRI
operator|&&
name|MRI
operator|->
name|isSubRegister
argument_list|(
name|Reg
argument_list|,
operator|*
name|ImpDefs
argument_list|)
operator|)
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
comment|/// \brief Return true if this instruction defines the specified physical
end_comment

begin_comment
comment|/// register, either explicitly or implicitly.
end_comment

begin_decl_stmt
name|bool
name|hasDefOfPhysReg
argument_list|(
specifier|const
name|MCInst
operator|&
name|MI
argument_list|,
name|unsigned
name|Reg
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|RI
argument_list|)
decl|const
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|e
init|=
name|NumDefs
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
name|MI
operator|.
name|getOperand
argument_list|(
name|i
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|RI
operator|.
name|isSubRegisterEq
argument_list|(
name|Reg
argument_list|,
name|MI
operator|.
name|getOperand
argument_list|(
name|i
argument_list|)
operator|.
name|getReg
argument_list|()
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|hasImplicitDefOfPhysReg
argument_list|(
name|Reg
argument_list|,
operator|&
name|RI
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the scheduling class for this instruction.  The
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

begin_comment
comment|/// \brief Return the number of bytes in the encoding of this instruction,
end_comment

begin_comment
comment|/// or zero if the encoding size cannot be known from the opcode.
end_comment

begin_expr_stmt
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Find the index of the first operand in the
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
block|{
if|if
condition|(
name|isPredicable
argument_list|()
condition|)
block|{
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
name|OpInfo
index|[
name|i
index|]
operator|.
name|isPredicate
argument_list|()
condition|)
return|return
name|i
return|;
block|}
end_expr_stmt

begin_return
return|return
operator|-
literal|1
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

