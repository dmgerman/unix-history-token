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
name|LLVM_UTILS_TABLEGEN_X86RECOGNIZABLEINSTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_X86RECOGNIZABLEINSTR_H
end_define

begin_include
include|#
directive|include
file|"CodeGenTarget.h"
end_include

begin_include
include|#
directive|include
file|"X86DisassemblerTables.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/Record.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
define|#
directive|define
name|X86_INSTR_MRM_MAPPING
define|\
value|MAP(C0, 64)                     \   MAP(C1, 65)                     \   MAP(C2, 66)                     \   MAP(C3, 67)                     \   MAP(C4, 68)                     \   MAP(C5, 69)                     \   MAP(C6, 70)                     \   MAP(C7, 71)                     \   MAP(C8, 72)                     \   MAP(C9, 73)                     \   MAP(CA, 74)                     \   MAP(CB, 75)                     \   MAP(CC, 76)                     \   MAP(CD, 77)                     \   MAP(CE, 78)                     \   MAP(CF, 79)                     \   MAP(D0, 80)                     \   MAP(D1, 81)                     \   MAP(D2, 82)                     \   MAP(D3, 83)                     \   MAP(D4, 84)                     \   MAP(D5, 85)                     \   MAP(D6, 86)                     \   MAP(D7, 87)                     \   MAP(D8, 88)                     \   MAP(D9, 89)                     \   MAP(DA, 90)                     \   MAP(DB, 91)                     \   MAP(DC, 92)                     \   MAP(DD, 93)                     \   MAP(DE, 94)                     \   MAP(DF, 95)                     \   MAP(E0, 96)                     \   MAP(E1, 97)                     \   MAP(E2, 98)                     \   MAP(E3, 99)                     \   MAP(E4, 100)                    \   MAP(E5, 101)                    \   MAP(E6, 102)                    \   MAP(E7, 103)                    \   MAP(E8, 104)                    \   MAP(E9, 105)                    \   MAP(EA, 106)                    \   MAP(EB, 107)                    \   MAP(EC, 108)                    \   MAP(ED, 109)                    \   MAP(EE, 110)                    \   MAP(EF, 111)                    \   MAP(F0, 112)                    \   MAP(F1, 113)                    \   MAP(F2, 114)                    \   MAP(F3, 115)                    \   MAP(F4, 116)                    \   MAP(F5, 117)                    \   MAP(F6, 118)                    \   MAP(F7, 119)                    \   MAP(F8, 120)                    \   MAP(F9, 121)                    \   MAP(FA, 122)                    \   MAP(FB, 123)                    \   MAP(FC, 124)                    \   MAP(FD, 125)                    \   MAP(FE, 126)                    \   MAP(FF, 127)
comment|// A clone of X86 since we can't depend on something that is generated.
name|namespace
name|X86Local
block|{
enum|enum
block|{
name|Pseudo
init|=
literal|0
block|,
name|RawFrm
init|=
literal|1
block|,
name|AddRegFrm
init|=
literal|2
block|,
name|RawFrmMemOffs
init|=
literal|3
block|,
name|RawFrmSrc
init|=
literal|4
block|,
name|RawFrmDst
init|=
literal|5
block|,
name|RawFrmDstSrc
init|=
literal|6
block|,
name|RawFrmImm8
init|=
literal|7
block|,
name|RawFrmImm16
init|=
literal|8
block|,
name|MRMDestMem
init|=
literal|32
block|,
name|MRMSrcMem
init|=
literal|33
block|,
name|MRMSrcMem4VOp3
init|=
literal|34
block|,
name|MRMSrcMemOp4
init|=
literal|35
block|,
name|MRMXm
init|=
literal|39
block|,
name|MRM0m
init|=
literal|40
block|,
name|MRM1m
init|=
literal|41
block|,
name|MRM2m
init|=
literal|42
block|,
name|MRM3m
init|=
literal|43
block|,
name|MRM4m
init|=
literal|44
block|,
name|MRM5m
init|=
literal|45
block|,
name|MRM6m
init|=
literal|46
block|,
name|MRM7m
init|=
literal|47
block|,
name|MRMDestReg
init|=
literal|48
block|,
name|MRMSrcReg
init|=
literal|49
block|,
name|MRMSrcReg4VOp3
init|=
literal|50
block|,
name|MRMSrcRegOp4
init|=
literal|51
block|,
name|MRMXr
init|=
literal|55
block|,
name|MRM0r
init|=
literal|56
block|,
name|MRM1r
init|=
literal|57
block|,
name|MRM2r
init|=
literal|58
block|,
name|MRM3r
init|=
literal|59
block|,
name|MRM4r
init|=
literal|60
block|,
name|MRM5r
init|=
literal|61
block|,
name|MRM6r
init|=
literal|62
block|,
name|MRM7r
init|=
literal|63
block|,
define|#
directive|define
name|MAP
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|MRM_##from = to,
name|X86_INSTR_MRM_MAPPING
undef|#
directive|undef
name|MAP
block|}
enum|;
enum|enum
block|{
name|OB
init|=
literal|0
block|,
name|TB
init|=
literal|1
block|,
name|T8
init|=
literal|2
block|,
name|TA
init|=
literal|3
block|,
name|XOP8
init|=
literal|4
block|,
name|XOP9
init|=
literal|5
block|,
name|XOPA
init|=
literal|6
block|}
enum|;
enum|enum
block|{
name|PS
init|=
literal|1
block|,
name|PD
init|=
literal|2
block|,
name|XS
init|=
literal|3
block|,
name|XD
init|=
literal|4
block|}
enum|;
enum|enum
block|{
name|VEX
init|=
literal|1
block|,
name|XOP
init|=
literal|2
block|,
name|EVEX
init|=
literal|3
block|}
enum|;
enum|enum
block|{
name|OpSize16
init|=
literal|1
block|,
name|OpSize32
init|=
literal|2
block|}
enum|;
enum|enum
block|{
name|AdSize16
init|=
literal|1
block|,
name|AdSize32
init|=
literal|2
block|,
name|AdSize64
init|=
literal|3
block|}
enum|;
enum|enum
block|{
name|VEX_W0
init|=
literal|0
block|,
name|VEX_W1
init|=
literal|1
block|,
name|VEX_WIG
init|=
literal|2
block|}
enum|;
block|}
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
comment|/// The OpPrefix field from the record
name|uint8_t
name|OpPrefix
decl_stmt|;
comment|/// The OpMap field from the record
name|uint8_t
name|OpMap
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
comment|// The encoding field from the record
name|uint8_t
name|Encoding
decl_stmt|;
comment|/// The OpSize field from the record
name|uint8_t
name|OpSize
decl_stmt|;
comment|/// The AdSize field from the record
name|uint8_t
name|AdSize
decl_stmt|;
comment|/// The hasREX_WPrefix field from the record
name|bool
name|HasREX_WPrefix
decl_stmt|;
comment|/// The hasVEX_4V field from the record
name|bool
name|HasVEX_4V
decl_stmt|;
comment|/// The VEX_WPrefix field from the record
name|uint8_t
name|VEX_WPrefix
decl_stmt|;
comment|/// Inferred from the operands; indicates whether the L bit in the VEX prefix is set
name|bool
name|HasVEX_LPrefix
decl_stmt|;
comment|/// The ignoreVEX_L field from the record
name|bool
name|IgnoresVEX_L
decl_stmt|;
comment|/// The hasEVEX_L2Prefix field from the record
name|bool
name|HasEVEX_L2Prefix
decl_stmt|;
comment|/// The hasEVEX_K field from the record
name|bool
name|HasEVEX_K
decl_stmt|;
comment|/// The hasEVEX_KZ field from the record
name|bool
name|HasEVEX_KZ
decl_stmt|;
comment|/// The hasEVEX_B field from the record
name|bool
name|HasEVEX_B
decl_stmt|;
comment|/// The isCodeGenOnly field from the record
name|bool
name|IsCodeGenOnly
decl_stmt|;
comment|/// The ForceDisassemble field from the record
name|bool
name|ForceDisassemble
decl_stmt|;
comment|// The CD8_Scale field from the record
name|uint8_t
name|CD8_Scale
decl_stmt|;
comment|// Whether the instruction has the predicate "In64BitMode"
name|bool
name|Is64Bit
decl_stmt|;
comment|// Whether the instruction has the predicate "In32BitMode"
name|bool
name|Is32Bit
decl_stmt|;
comment|/// The instruction name as listed in the tables
name|std
operator|::
name|string
name|Name
expr_stmt|;
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
name|CGIOperandList
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
comment|/// typeFromString - Translates an operand type from the string provided in
comment|///   the LLVM tables to an OperandType for use in the operand specifier.
comment|///
comment|/// @param s              - The string, as extracted by calling Rec->getName()
comment|///                         on a CodeGenInstruction::OperandInfo.
comment|/// @param hasREX_WPrefix - Indicates whether the instruction has a REX.W
comment|///                         prefix.  If it does, 32-bit register operands stay
comment|///                         32-bit regardless of the operand size.
comment|/// @param OpSize           Indicates the operand size of the instruction.
comment|///                         If register size does not match OpSize, then
comment|///                         register sizes keep their size.
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
name|hasREX_WPrefix
argument_list|,
name|uint8_t
name|OpSize
argument_list|)
decl_stmt|;
comment|/// immediateEncodingFromString - Translates an immediate encoding from the
comment|///   string provided in the LLVM tables to an OperandEncoding for use in
comment|///   the operand specifier.
comment|///
comment|/// @param s       - See typeFromString().
comment|/// @param OpSize  - Indicates whether this is an OpSize16 instruction.
comment|///                  If it is not, then 16-bit immediate operands stay 16-bit.
comment|/// @return        - The operand's encoding.
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
name|uint8_t
name|OpSize
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
name|uint8_t
name|OpSize
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
name|uint8_t
name|OpSize
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
name|uint8_t
name|OpSize
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
name|uint8_t
name|OpSize
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
name|uint8_t
name|OpSize
argument_list|)
decl_stmt|;
specifier|static
name|OperandEncoding
name|vvvvRegisterEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|uint8_t
name|OpSize
argument_list|)
decl_stmt|;
specifier|static
name|OperandEncoding
name|writemaskRegisterEncodingFromString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
name|uint8_t
name|OpSize
argument_list|)
decl_stmt|;
comment|/// \brief Adjust the encoding type for an operand based on the instruction.
name|void
name|adjustOperandEncoding
parameter_list|(
name|OperandEncoding
modifier|&
name|encoding
parameter_list|)
function_decl|;
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
name|numPhysicalOperands
argument_list|,
specifier|const
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
name|uint8_t
name|OpSize
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
name|void
name|emitInstructionSpecifier
parameter_list|()
function_decl|;
comment|/// emitDecodePath - Populates the proper fields in the decode tables
comment|///   corresponding to the decode paths for this instruction.
comment|///
comment|/// \param tables The DisassemblerTables to populate with the decode
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
comment|/// \param tables The DisassemblerTables that the specifier will be added to.
comment|/// \param insn   The CodeGenInstruction to extract information from.
comment|/// \param uid    The unique ID of the current instruction.
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
comment|/// \param tables The DiassemblerTables to be populated with decode
comment|///               information.
comment|/// \param insn   The CodeGenInstruction to be used as a source for this
comment|///               information.
comment|/// \param uid    The unique ID of the instruction.
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

