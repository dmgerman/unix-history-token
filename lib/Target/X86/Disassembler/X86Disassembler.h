begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86Disassembler.h - Disassembler for x86 and x86_64 ------*- C++ -*-===//
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
comment|// The X86 disassembler is a table-driven disassembler for the 16-, 32-, and
end_comment

begin_comment
comment|// 64-bit X86 instruction sets.  The main decode sequence for an assembly
end_comment

begin_comment
comment|// instruction in this disassembler is:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1. Read the prefix bytes and determine the attributes of the instruction.
end_comment

begin_comment
comment|//    These attributes, recorded in enum attributeBits
end_comment

begin_comment
comment|//    (X86DisassemblerDecoderCommon.h), form a bitmask.  The table CONTEXTS_SYM
end_comment

begin_comment
comment|//    provides a mapping from bitmasks to contexts, which are represented by
end_comment

begin_comment
comment|//    enum InstructionContext (ibid.).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 2. Read the opcode, and determine what kind of opcode it is.  The
end_comment

begin_comment
comment|//    disassembler distinguishes four kinds of opcodes, which are enumerated in
end_comment

begin_comment
comment|//    OpcodeType (X86DisassemblerDecoderCommon.h): one-byte (0xnn), two-byte
end_comment

begin_comment
comment|//    (0x0f 0xnn), three-byte-38 (0x0f 0x38 0xnn), or three-byte-3a
end_comment

begin_comment
comment|//    (0x0f 0x3a 0xnn).  Mandatory prefixes are treated as part of the context.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 3. Depending on the opcode type, look in one of four ClassDecision structures
end_comment

begin_comment
comment|//    (X86DisassemblerDecoderCommon.h).  Use the opcode class to determine which
end_comment

begin_comment
comment|//    OpcodeDecision (ibid.) to look the opcode in.  Look up the opcode, to get
end_comment

begin_comment
comment|//    a ModRMDecision (ibid.).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 4. Some instructions, such as escape opcodes or extended opcodes, or even
end_comment

begin_comment
comment|//    instructions that have ModRM*Reg / ModRM*Mem forms in LLVM, need the
end_comment

begin_comment
comment|//    ModR/M byte to complete decode.  The ModRMDecision's type is an entry from
end_comment

begin_comment
comment|//    ModRMDecisionType (X86DisassemblerDecoderCommon.h) that indicates if the
end_comment

begin_comment
comment|//    ModR/M byte is required and how to interpret it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 5. After resolving the ModRMDecision, the disassembler has a unique ID
end_comment

begin_comment
comment|//    of type InstrUID (X86DisassemblerDecoderCommon.h).  Looking this ID up in
end_comment

begin_comment
comment|//    INSTRUCTIONS_SYM yields the name of the instruction and the encodings and
end_comment

begin_comment
comment|//    meanings of its operands.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 6. For each operand, its encoding is an entry from OperandEncoding
end_comment

begin_comment
comment|//    (X86DisassemblerDecoderCommon.h) and its type is an entry from
end_comment

begin_comment
comment|//    OperandType (ibid.).  The encoding indicates how to read it from the
end_comment

begin_comment
comment|//    instruction; the type indicates how to interpret the value once it has
end_comment

begin_comment
comment|//    been read.  For example, a register operand could be stored in the R/M
end_comment

begin_comment
comment|//    field of the ModR/M byte, the REG field of the ModR/M byte, or added to
end_comment

begin_comment
comment|//    the main opcode.  This is orthogonal from its meaning (an GPR or an XMM
end_comment

begin_comment
comment|//    register, for instance).  Given this information, the operands can be
end_comment

begin_comment
comment|//    extracted and interpreted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 7. As the last step, the disassembler translates the instruction information
end_comment

begin_comment
comment|//    and operands into a format understandable by the client - in this case, an
end_comment

begin_comment
comment|//    MCInst for use by the MC infrastructure.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The disassembler is broken broadly into two parts: the table emitter that
end_comment

begin_comment
comment|// emits the instruction decode tables discussed above during compilation, and
end_comment

begin_comment
comment|// the disassembler itself.  The table emitter is documented in more detail in
end_comment

begin_comment
comment|// utils/TableGen/X86DisassemblerEmitter.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86Disassembler.h contains the public interface for the disassembler,
end_comment

begin_comment
comment|//   adhering to the MCDisassembler interface.
end_comment

begin_comment
comment|// X86Disassembler.cpp contains the code responsible for step 7, and for
end_comment

begin_comment
comment|//   invoking the decoder to execute steps 1-6.
end_comment

begin_comment
comment|// X86DisassemblerDecoderCommon.h contains the definitions needed by both the
end_comment

begin_comment
comment|//   table emitter and the disassembler.
end_comment

begin_comment
comment|// X86DisassemblerDecoder.h contains the public interface of the decoder,
end_comment

begin_comment
comment|//   factored out into C for possible use by other projects.
end_comment

begin_comment
comment|// X86DisassemblerDecoder.c contains the source code of the decoder, which is
end_comment

begin_comment
comment|//   responsible for steps 1-6.
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
name|X86DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|X86DISASSEMBLER_H
end_define

begin_define
define|#
directive|define
name|INSTRUCTION_SPECIFIER_FIELDS
define|\
value|const char*             name;
end_define

begin_define
define|#
directive|define
name|INSTRUCTION_IDS
define|\
value|InstrUID*  instructionIDs;
end_define

begin_include
include|#
directive|include
file|"X86DisassemblerDecoderCommon.h"
end_include

begin_undef
undef|#
directive|undef
name|INSTRUCTION_SPECIFIER_FIELDS
end_undef

begin_undef
undef|#
directive|undef
name|INSTRUCTION_IDS
end_undef

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler.h"
end_include

begin_struct_decl
struct_decl|struct
name|InternalInstruction
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MemoryObject
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|X86Disassembler
block|{
comment|/// X86GenericDisassembler - Generic disassembler for all X86 platforms.
comment|///   All each platform class should have to do is subclass the constructor, and
comment|///   provide a different disassemblerMode value.
name|class
name|X86GenericDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|protected
operator|:
comment|/// Constructor     - Initializes the disassembler.
comment|///
comment|/// @param mode     - The X86 architecture mode to decode for.
name|X86GenericDisassembler
argument_list|(
argument|DisassemblerMode mode
argument_list|)
block|;
name|public
operator|:
operator|~
name|X86GenericDisassembler
argument_list|()
block|;
comment|/// getInstruction - See MCDisassembler.
name|bool
name|getInstruction
argument_list|(
argument|MCInst&instr
argument_list|,
argument|uint64_t&size
argument_list|,
argument|const MemoryObject&region
argument_list|,
argument|uint64_t address
argument_list|,
argument|raw_ostream&vStream
argument_list|)
specifier|const
block|;
name|private
operator|:
name|DisassemblerMode
name|fMode
block|; }
decl_stmt|;
comment|/// X86_16Disassembler - 16-bit X86 disassembler.
name|class
name|X86_16Disassembler
range|:
name|public
name|X86GenericDisassembler
block|{
name|public
operator|:
name|X86_16Disassembler
argument_list|()
operator|:
name|X86GenericDisassembler
argument_list|(
argument|MODE_16BIT
argument_list|)
block|{   }
block|}
decl_stmt|;
comment|/// X86_16Disassembler - 32-bit X86 disassembler.
name|class
name|X86_32Disassembler
range|:
name|public
name|X86GenericDisassembler
block|{
name|public
operator|:
name|X86_32Disassembler
argument_list|()
operator|:
name|X86GenericDisassembler
argument_list|(
argument|MODE_32BIT
argument_list|)
block|{   }
block|}
decl_stmt|;
comment|/// X86_16Disassembler - 64-bit X86 disassembler.
name|class
name|X86_64Disassembler
range|:
name|public
name|X86GenericDisassembler
block|{
name|public
operator|:
name|X86_64Disassembler
argument_list|()
operator|:
name|X86GenericDisassembler
argument_list|(
argument|MODE_64BIT
argument_list|)
block|{   }
block|}
decl_stmt|;
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

