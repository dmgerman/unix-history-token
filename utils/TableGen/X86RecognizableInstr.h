begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86RecognizableInstr.h - Disassembler instruction spec ----*- C++ -*-===//
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
comment|// This file is part of the X86 Disassembler Emitter.
end_comment

begin_comment
comment|// It contains the interface of a single recognizable instruction.
end_comment

begin_comment
comment|// Documentation for the disassembler emitter in general can be found in
end_comment

begin_comment
comment|//  X86DisasemblerEmitter.h.
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
name|X86RECOGNIZABLEINSTR_H
end_ifndef

begin_define
define|#
directive|define
name|X86RECOGNIZABLEINSTR_H
end_define

begin_include
include|#
directive|include
file|"X86DisassemblerTables.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTarget.h"
end_include

begin_include
include|#
directive|include
file|"Record.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86Disassembler
block|{
comment|/// RecognizableInstr - Encapsulates all information required to decode a single
comment|///   instruction, as extracted from the LLVM instruction tables.  Has methods
comment|///   to interpret the information available in the LLVM tables, and to emit the
comment|///   instruction into DisassemblerTables.
name|class
name|RecognizableInstr
block|{
name|private
label|:
comment|/// The opcode of the instruction, as used in an MCInst
name|InstrUID
name|UID
decl_stmt|;
comment|/// The record from the .td files corresponding to this instruction
specifier|const
name|Record
modifier|*
name|Rec
decl_stmt|;
comment|/// The prefix field from the record
name|uint8_t
name|Prefix
decl_stmt|;
comment|/// The opcode field from the record; this is the opcode used in the Intel
comment|/// encoding and therefore distinct from the UID
name|uint8_t
name|Opcode
decl_stmt|;
comment|/// The form field from the record
name|uint8_t
name|Form
decl_stmt|;
comment|/// The segment override field from the record
name|uint8_t
name|SegOvr
decl_stmt|;
comment|/// The hasOpSizePrefix field from the record
name|bool
name|HasOpSizePrefix
decl_stmt|;
comment|/// The hasREX_WPrefix field from the record
name|bool
name|HasREX_WPrefix
decl_stmt|;
comment|/// The hasLockPrefix field from the record
name|bool
name|HasLockPrefix
decl_stmt|;
comment|/// The isCodeGenOnly filed from the record
name|bool
name|IsCodeGenOnly
decl_stmt|;
comment|/// The instruction name as listed in the tables
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// The AT&T AsmString for the instruction
name|std
operator|::
name|string
name|AsmString
expr_stmt|;
comment|/// Indicates whether the instruction is SSE
name|bool
name|IsSSE
decl_stmt|;
comment|/// Indicates whether the instruction has FR operands - MOVs with FR operands
comment|/// are typically ignored
name|bool
name|HasFROperands
decl_stmt|;
comment|/// Indicates whether the instruction should be emitted into the decode
comment|/// tables; regardless, it will be emitted into the instruction info table
name|bool
name|ShouldBeEmitted
decl_stmt|;
comment|/// The operands of the instruction, as listed in the CodeGenInstruction.
comment|/// They are not one-to-one with operands listed in the MCInst; for example,
comment|/// memory operands expand to 5 operands in the MCInst
specifier|const
name|std
operator|::
name|vector
operator|<
name|CodeGenInstruction
operator|::
name|OperandInfo
operator|>
operator|*
name|Operands
expr_stmt|;
comment|/// The description of the instruction that is emitted into the instruction
comment|/// info table
name|InstructionSpecifier
modifier|*
name|Spec
decl_stmt|;
comment|/// insnContext - Returns the primary context in which the instruction is
comment|///   valid.
comment|///
comment|/// @return - The context in which the instruction is valid.
name|InstructionContext
name|insnContext
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|filter_ret
block|{
name|FILTER_STRONG
block|,
comment|// instruction has no place in the instruction tables
name|FILTER_WEAK
block|,
comment|// instruction may conflict, and should be eliminated if
comment|// it does
name|FILTER_NORMAL
comment|// instruction should have high priority and generate an
comment|// error if it conflcits with any other FILTER_NORMAL
comment|// instruction
block|}
enum|;
comment|/// filter - Determines whether the instruction should be decodable.  Some
comment|///   instructions are pure intrinsics and use unencodable operands; many
comment|///   synthetic instructions are duplicates of other instructions; other
comment|///   instructions only differ in the logical way in which they are used, and
comment|///   have the same decoding.  Because these would cause decode conflicts,
comment|///   they must be filtered out.
comment|///
comment|/// @return - The degree of filtering to be applied (see filter_ret).
name|filter_ret
name|filter
argument_list|()
specifier|const
expr_stmt|;
comment|/// typeFromString - Translates an operand type from the string provided in
comment|///   the LLVM tables to an OperandType for use in the operand specifier.
comment|///
comment|/// @param s              - The string, as extracted by calling Rec->getName()
comment|///                         on a CodeGenInstruction::OperandInfo.
comment|/// @param isSSE          - Indicates whether the instruction is an SSE
comment|///                         instruction.  For SSE instructions, immediates are
comment|///                         fixed-size rather than being affected by the
comment|///                         mandatory OpSize prefix.
comment|/// @param hasREX_WPrefix - Indicates whether the instruction has a REX.W
comment|///                         prefix.  If it does, 32-bit register operands stay
comment|///                         32-bit regardless of the operand size.
comment|/// @param hasOpSizePrefix- Indicates whether the instruction has an OpSize
comment|///                         prefix.  If it does not, then 16-bit register
comment|///                         operands stay 16-bit.
comment|/// @return               - The operand's type.
specifier|static
name|OperandType
name|typeFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|isSSE
argument_list|,
name|bool
name|hasREX_WPrefix
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
comment|/// immediateEncodingFromString - Translates an immediate encoding from the
comment|///   string provided in the LLVM tables to an OperandEncoding for use in
comment|///   the operand specifier.
comment|///
comment|/// @param s                - See typeFromString().
comment|/// @param hasOpSizePrefix  - Indicates whether the instruction has an OpSize
comment|///                           prefix.  If it does not, then 16-bit immediate
comment|///                           operands stay 16-bit.
comment|/// @return                 - The operand's encoding.
specifier|static
name|OperandEncoding
name|immediateEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
comment|/// rmRegisterEncodingFromString - Like immediateEncodingFromString, but
comment|///   handles operands that are in the REG field of the ModR/M byte.
specifier|static
name|OperandEncoding
name|rmRegisterEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
comment|/// rmRegisterEncodingFromString - Like immediateEncodingFromString, but
comment|///   handles operands that are in the REG field of the ModR/M byte.
specifier|static
name|OperandEncoding
name|roRegisterEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
specifier|static
name|OperandEncoding
name|memoryEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
specifier|static
name|OperandEncoding
name|relocationEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
specifier|static
name|OperandEncoding
name|opcodeModifierEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|bool
name|hasOpSizePrefix
argument_list|)
decl_stmt|;
comment|/// handleOperand - Converts a single operand from the LLVM table format to
comment|///   the emitted table format, handling any duplicate operands it encounters
comment|///   and then one non-duplicate.
comment|///
comment|/// @param optional             - Determines whether to assert that the
comment|///                               operand exists.
comment|/// @param operandIndex         - The index into the generated operand table.
comment|///                               Incremented by this function one or more
comment|///                               times to reflect possible duplicate
comment|///                               operands).
comment|/// @param physicalOperandIndex - The index of the current operand into the
comment|///                               set of non-duplicate ('physical') operands.
comment|///                               Incremented by this function once.
comment|/// @param numPhysicalOperands  - The number of non-duplicate operands in the
comment|///                               instructions.
comment|/// @param operandMapping       - The operand mapping, which has an entry for
comment|///                               each operand that indicates whether it is a
comment|///                               duplicate, and of what.
name|void
name|handleOperand
argument_list|(
name|bool
name|optional
argument_list|,
name|unsigned
operator|&
name|operandIndex
argument_list|,
name|unsigned
operator|&
name|physicalOperandIndex
argument_list|,
name|unsigned
operator|&
name|numPhysicalOperands
argument_list|,
name|unsigned
operator|*
name|operandMapping
argument_list|,
name|OperandEncoding
argument_list|(
argument|*encodingFromString
argument_list|)
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
operator|,
name|bool
name|hasOpSizePrefix
operator|)
argument_list|)
decl_stmt|;
comment|/// shouldBeEmitted - Returns the shouldBeEmitted field.  Although filter()
comment|///   filters out many instructions, at various points in decoding we
comment|///   determine that the instruction should not actually be decodable.  In
comment|///   particular, MMX MOV instructions aren't emitted, but they're only
comment|///   identified during operand parsing.
comment|///
comment|/// @return - true if at this point we believe the instruction should be
comment|///   emitted; false if not.  This will return false if filter() returns false
comment|///   once emitInstructionSpecifier() has been called.
name|bool
name|shouldBeEmitted
argument_list|()
specifier|const
block|{
return|return
name|ShouldBeEmitted
return|;
block|}
comment|/// emitInstructionSpecifier - Loads the instruction specifier for the current
comment|///   instruction into a DisassemblerTables.
comment|///
comment|/// @arg tables - The DisassemblerTables to populate with the specifier for
comment|///               the current instruction.
name|void
name|emitInstructionSpecifier
parameter_list|(
name|DisassemblerTables
modifier|&
name|tables
parameter_list|)
function_decl|;
comment|/// emitDecodePath - Populates the proper fields in the decode tables
comment|///   corresponding to the decode paths for this instruction.
comment|///
comment|/// @arg tables - The DisassemblerTables to populate with the decode
comment|///               decode information for the current instruction.
name|void
name|emitDecodePath
parameter_list|(
name|DisassemblerTables
modifier|&
name|tables
parameter_list|)
function_decl|const;
comment|/// Constructor - Initializes a RecognizableInstr with the appropriate fields
comment|///   from a CodeGenInstruction.
comment|///
comment|/// @arg tables - The DisassemblerTables that the specifier will be added to.
comment|/// @arg insn   - The CodeGenInstruction to extract information from.
comment|/// @arg uid    - The unique ID of the current instruction.
name|RecognizableInstr
argument_list|(
argument|DisassemblerTables&tables
argument_list|,
argument|const CodeGenInstruction&insn
argument_list|,
argument|InstrUID uid
argument_list|)
empty_stmt|;
name|public
label|:
comment|/// processInstr - Accepts a CodeGenInstruction and loads decode information
comment|///   for it into a DisassemblerTables if appropriate.
comment|///
comment|/// @arg tables - The DiassemblerTables to be populated with decode
comment|///               information.
comment|/// @arg insn   - The CodeGenInstruction to be used as a source for this
comment|///               information.
comment|/// @uid        - The unique ID of the instruction.
specifier|static
name|void
name|processInstr
parameter_list|(
name|DisassemblerTables
modifier|&
name|tables
parameter_list|,
specifier|const
name|CodeGenInstruction
modifier|&
name|insn
parameter_list|,
name|InstrUID
name|uid
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace X86Disassembler
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

