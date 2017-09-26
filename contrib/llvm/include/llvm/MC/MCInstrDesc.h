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
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|FeatureBitset
decl_stmt|;
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
comment|/// \brief These are flags set on operands, but should be considered
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
comment|/// \brief Operands are tagged with one of the values of this enum.
enum|enum
name|OperandType
block|{
name|OPERAND_UNKNOWN
init|=
literal|0
block|,
name|OPERAND_IMMEDIATE
init|=
literal|1
block|,
name|OPERAND_REGISTER
init|=
literal|2
block|,
name|OPERAND_MEMORY
init|=
literal|3
block|,
name|OPERAND_PCREL
init|=
literal|4
block|,
name|OPERAND_FIRST_GENERIC
init|=
literal|6
block|,
name|OPERAND_GENERIC_0
init|=
literal|6
block|,
name|OPERAND_GENERIC_1
init|=
literal|7
block|,
name|OPERAND_GENERIC_2
init|=
literal|8
block|,
name|OPERAND_GENERIC_3
init|=
literal|9
block|,
name|OPERAND_GENERIC_4
init|=
literal|10
block|,
name|OPERAND_GENERIC_5
init|=
literal|11
block|,
name|OPERAND_LAST_GENERIC
init|=
literal|11
block|,
name|OPERAND_FIRST_TARGET
init|=
literal|12
block|, }
enum|;
enum|enum
name|GenericOperandType
block|{ }
enum|;
block|}
comment|/// \brief This holds information about one operand of a machine instruction,
comment|/// indicating the register class for register operands, etc.
name|class
name|MCOperandInfo
block|{
name|public
label|:
comment|/// \brief This specifies the register class enumeration of the operand
comment|/// if the operand is a register.  If isLookupPtrRegClass is set, then this is
comment|/// an index that is passed to TargetRegisterInfo::getPointerRegClass(x) to
comment|/// get a dynamic register class.
name|int16_t
name|RegClass
decl_stmt|;
comment|/// \brief These are flags from the MCOI::OperandFlags enum.
name|uint8_t
name|Flags
decl_stmt|;
comment|/// \brief Information about the type of the operand.
name|uint8_t
name|OperandType
decl_stmt|;
comment|/// \brief The lower 16 bits are used to specify which constraints are set.
comment|/// The higher 16 bits are used to specify the value of constraints (4 bits
comment|/// each).
name|uint32_t
name|Constraints
decl_stmt|;
comment|/// \brief Set if this operand is a pointer value and it requires a callback
comment|/// to look up its register class.
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
comment|/// \brief Set if this is one of the operands that made up of the predicate
comment|/// operand that controls an isPredicable() instruction.
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
comment|/// \brief Set if this operand is a optional def.
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
name|bool
name|isGenericType
argument_list|()
specifier|const
block|{
return|return
name|OperandType
operator|>=
name|MCOI
operator|::
name|OPERAND_FIRST_GENERIC
operator|&&
name|OperandType
operator|<=
name|MCOI
operator|::
name|OPERAND_LAST_GENERIC
return|;
block|}
name|unsigned
name|getGenericTypeIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isGenericType
argument_list|()
operator|&&
literal|"non-generic types don't have an index"
argument_list|)
block|;
return|return
name|OperandType
operator|-
name|MCOI
operator|::
name|OPERAND_FIRST_GENERIC
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Machine Instruction Flags and Description
comment|//===----------------------------------------------------------------------===//
name|namespace
name|MCID
block|{
comment|/// \brief These should be considered private to the implementation of the
comment|/// MCInstrDesc class.  Clients should use the predicate methods on MCInstrDesc,
comment|/// not use these directly.  These all correspond to bitfields in the
comment|/// MCInstrDesc::Flags field.
enum|enum
name|Flag
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
block|,
name|RegSequence
block|,
name|ExtractSubreg
block|,
name|InsertSubreg
block|,
name|Convergent
block|,
name|Add
block|}
enum|;
block|}
comment|/// \brief Describe properties that are true of each instruction in the target
comment|/// description file.  This captures information about side effects, register
comment|/// use and many other things.  There is one instance of this struct for each
comment|/// target instruction class, and the MachineInstr class points to this struct
comment|/// directly to describe itself.
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
name|char
name|NumDefs
decl_stmt|;
comment|// Num of args that are definitions
name|unsigned
name|char
name|Size
decl_stmt|;
comment|// Number of bytes in encoding.
name|unsigned
name|short
name|SchedClass
decl_stmt|;
comment|// enum identifying instr sched class
name|uint64_t
name|Flags
decl_stmt|;
comment|// Flags identifying machine instr class
name|uint64_t
name|TSFlags
decl_stmt|;
comment|// Target Specific Flag values
specifier|const
name|MCPhysReg
modifier|*
name|ImplicitUses
decl_stmt|;
comment|// Registers implicitly read by this instr
specifier|const
name|MCPhysReg
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
comment|// Subtarget feature that this is deprecated on, if any
comment|// -1 implies this is not deprecated by any single feature. It may still be
comment|// deprecated due to a "complex" reason, below.
name|int64_t
name|DeprecatedFeature
decl_stmt|;
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
specifier|const
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
specifier|const
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
decl_stmt|;
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
name|using
name|const_opInfo_iterator
init|=
specifier|const
name|MCOperandInfo
operator|*
decl_stmt|;
name|const_opInfo_iterator
name|opInfo_begin
argument_list|()
specifier|const
block|{
return|return
name|OpInfo
return|;
block|}
name|const_opInfo_iterator
name|opInfo_end
argument_list|()
specifier|const
block|{
return|return
name|OpInfo
operator|+
name|NumOperands
return|;
block|}
name|iterator_range
operator|<
name|const_opInfo_iterator
operator|>
name|operands
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|opInfo_begin
argument_list|()
argument_list|,
name|opInfo_end
argument_list|()
argument_list|)
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
name|uint64_t
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
literal|1ULL
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|HasOptionalDef
operator|)
return|;
block|}
comment|/// \brief Return true if this is a pseudo instruction that doesn't
comment|/// correspond to a real machine instruction.
name|bool
name|isPseudo
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|Return
operator|)
return|;
block|}
comment|/// \brief Return true if the instruction is an add instruction.
name|bool
name|isAdd
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|Add
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
decl_stmt|;
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|NotDuplicable
operator|)
return|;
block|}
comment|/// \brief Returns true if the specified instruction has a delay slot which
comment|/// must be filled by the code generator.
name|bool
name|hasDelaySlot
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|DelaySlot
operator|)
return|;
block|}
comment|/// \brief Return true for instructions that can be folded as memory operands
comment|/// in other instructions. The most common use for this is instructions that
comment|/// are simple loads from memory that don't modify the loaded value in any
comment|/// way, but it can also be used for instructions that can be expressed as
comment|/// constant-pool loads, such as V_SETALLONES on x86, to allow them to be
comment|/// folded when it is beneficial.  This should only be set on instructions
comment|/// that return a value in their only virtual register definition.
name|bool
name|canFoldAsLoad
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|FoldableAsLoad
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction behaves
comment|/// the same way as the generic REG_SEQUENCE instructions.
comment|/// E.g., on ARM,
comment|/// dX VMOVDRR rY, rZ
comment|/// is equivalent to
comment|/// dX = REG_SEQUENCE rY, ssub_0, rZ, ssub_1.
comment|///
comment|/// Note that for the optimizers to be able to take advantage of
comment|/// this property, TargetInstrInfo::getRegSequenceLikeInputs has to be
comment|/// override accordingly.
name|bool
name|isRegSequenceLike
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|RegSequence
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction behaves
comment|/// the same way as the generic EXTRACT_SUBREG instructions.
comment|/// E.g., on ARM,
comment|/// rX, rY VMOVRRD dZ
comment|/// is equivalent to two EXTRACT_SUBREG:
comment|/// rX = EXTRACT_SUBREG dZ, ssub_0
comment|/// rY = EXTRACT_SUBREG dZ, ssub_1
comment|///
comment|/// Note that for the optimizers to be able to take advantage of
comment|/// this property, TargetInstrInfo::getExtractSubregLikeInputs has to be
comment|/// override accordingly.
name|bool
name|isExtractSubregLike
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|ExtractSubreg
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction behaves
comment|/// the same way as the generic INSERT_SUBREG instructions.
comment|/// E.g., on ARM,
comment|/// dX = VSETLNi32 dY, rZ, Imm
comment|/// is equivalent to a INSERT_SUBREG:
comment|/// dX = INSERT_SUBREG dY, rZ, translateImmToSubIdx(Imm)
comment|///
comment|/// Note that for the optimizers to be able to take advantage of
comment|/// this property, TargetInstrInfo::getInsertSubregLikeInputs has to be
comment|/// override accordingly.
name|bool
name|isInsertSubregLike
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|InsertSubreg
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction is convergent.
comment|///
comment|/// Convergent instructions may not be made control-dependent on any
comment|/// additional values.
name|bool
name|isConvergent
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|Convergent
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
literal|1ULL
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|MayStore
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction has side
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
name|bool
name|hasUnmodeledSideEffects
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
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
comment|/// \brief Return true if this may be a 2- or 3-address instruction (of the
comment|/// form "X = op Y, Z, ..."), which produces the same result if Y and Z are
comment|/// exchanged.  If this flag is set, then the
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|Commutable
operator|)
return|;
block|}
comment|/// \brief Return true if this is a 2-address instruction which can be changed
comment|/// into a 3-address instruction if needed.  Doing this transformation can be
comment|/// profitable in the register allocator, because it means that the
comment|/// instruction can use a 2-address form if possible, but degrade into a less
comment|/// efficient form if the source and dest register cannot be assigned to the
comment|/// same register.  For example, this allows the x86 backend to turn a "shl
comment|/// reg, 3" instruction into an LEA instruction, which is the same speed as
comment|/// the shift but has bigger code size.
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|ConvertibleTo3Addr
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction requires custom insertion support
comment|/// when the DAG scheduler is inserting it into a machine basic block.  If
comment|/// this is true for the instruction, it basically means that it is a pseudo
comment|/// instruction used at SelectionDAG time that is expanded out into magic code
comment|/// by the target when MachineInstrs are formed.
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
literal|1ULL
operator|<<
name|MCID
operator|::
name|UsesCustomInserter
operator|)
return|;
block|}
comment|/// \brief Return true if this instruction requires *adjustment* after
comment|/// instruction selection by calling a target hook. For example, this can be
comment|/// used to fill in ARM 's' optional operand depending on whether the
comment|/// conditional flag register is used.
name|bool
name|hasPostISelHook
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|HasPostISelHook
operator|)
return|;
block|}
comment|/// \brief Returns true if this instruction is a candidate for remat. This
comment|/// flag is only used in TargetInstrInfo method isTriviallyRematerializable.
comment|///
comment|/// If this flag is set, the isReallyTriviallyReMaterializable()
comment|/// or isReallyTriviallyReMaterializableGeneric methods are called to verify
comment|/// the instruction is really rematable.
name|bool
name|isRematerializable
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|Rematerializable
operator|)
return|;
block|}
comment|/// \brief Returns true if this instruction has the same cost (or less) than a
comment|/// move instruction. This is useful during certain types of optimizations
comment|/// (e.g., remat during two-address conversion or machine licm) where we would
comment|/// like to remat or hoist the instruction, but not if it costs more than
comment|/// moving the instruction into the appropriate register. Note, we are not
comment|/// marking copies from and to the same register class with this flag.
comment|///
comment|/// This method could be called by interface TargetInstrInfo::isAsCheapAsAMove
comment|/// for different subtargets.
name|bool
name|isAsCheapAsAMove
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|CheapAsAMove
operator|)
return|;
block|}
comment|/// \brief Returns true if this instruction source operands have special
comment|/// register allocation requirements that are not captured by the operand
comment|/// register classes. e.g. ARM::STRD's two source registers must be an even /
comment|/// odd pair, ARM::STM registers have to be in ascending order.  Post-register
comment|/// allocation passes should not attempt to change allocations for sources of
comment|/// instructions with this flag.
name|bool
name|hasExtraSrcRegAllocReq
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|ExtraSrcRegAllocReq
operator|)
return|;
block|}
comment|/// \brief Returns true if this instruction def operands have special register
comment|/// allocation requirements that are not captured by the operand register
comment|/// classes. e.g. ARM::LDRD's two def registers must be an even / odd pair,
comment|/// ARM::LDM registers have to be in ascending order.  Post-register
comment|/// allocation passes should not attempt to change allocations for definitions
comment|/// of instructions with this flag.
name|bool
name|hasExtraDefRegAllocReq
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
literal|1ULL
operator|<<
name|MCID
operator|::
name|ExtraDefRegAllocReq
operator|)
return|;
block|}
comment|/// \brief Return a list of registers that are potentially read by any
comment|/// instance of this machine instruction.  For example, on X86, the "adc"
comment|/// instruction adds two register operands and adds the carry bit in from the
comment|/// flags register.  In this case, the instruction is marked as implicitly
comment|/// reading the flags.  Likewise, the variable shift instruction on X86 is
comment|/// marked as implicitly reading the 'CL' register, which it always does.
comment|///
comment|/// This method returns null if the instruction has no implicit uses.
specifier|const
name|MCPhysReg
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
operator|!
name|ImplicitUses
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
comment|/// \brief Return a list of registers that are potentially written by any
comment|/// instance of this machine instruction.  For example, on X86, many
comment|/// instructions implicitly set the flags register.  In this case, they are
comment|/// marked as setting the FLAGS.  Likewise, many instructions always deposit
comment|/// their result in a physical register.  For example, the X86 divide
comment|/// instruction always deposits the quotient and remainder in the EAX/EDX
comment|/// registers.  For that instruction, this will return a list containing the
comment|/// EAX/EDX/EFLAGS registers.
comment|///
comment|/// This method returns null if the instruction has no implicit defs.
specifier|const
name|MCPhysReg
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
operator|!
name|ImplicitDefs
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
name|MCPhysReg
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
name|nullptr
argument_list|)
decl|const
decl_stmt|;
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

begin_comment
unit|}  private:
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
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

