begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- X86DisassemblerDecoderInternal.h - Disassembler decoder -----*- C -*-==*  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===*  *  * This file is part of the X86 Disassembler.  * It contains the public interface of the instruction decoder.  * Documentation for the disassembler can be found in X86Disassembler.h.  *  *===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X86DISASSEMBLERDECODER_H
end_ifndef

begin_define
define|#
directive|define
name|X86DISASSEMBLERDECODER_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|INSTRUCTION_SPECIFIER_FIELDS
define|\
value|const char*             name;
define|#
directive|define
name|INSTRUCTION_IDS
define|\
value|InstrUID*  instructionIDs;
include|#
directive|include
file|"X86DisassemblerDecoderCommon.h"
undef|#
directive|undef
name|INSTRUCTION_SPECIFIER_FIELDS
undef|#
directive|undef
name|INSTRUCTION_IDS
comment|/*  * Accessor functions for various fields of an Intel instruction  */
define|#
directive|define
name|modFromModRM
parameter_list|(
name|modRM
parameter_list|)
value|((modRM& 0xc0)>> 6)
define|#
directive|define
name|regFromModRM
parameter_list|(
name|modRM
parameter_list|)
value|((modRM& 0x38)>> 3)
define|#
directive|define
name|rmFromModRM
parameter_list|(
name|modRM
parameter_list|)
value|(modRM& 0x7)
define|#
directive|define
name|scaleFromSIB
parameter_list|(
name|sib
parameter_list|)
value|((sib& 0xc0)>> 6)
define|#
directive|define
name|indexFromSIB
parameter_list|(
name|sib
parameter_list|)
value|((sib& 0x38)>> 3)
define|#
directive|define
name|baseFromSIB
parameter_list|(
name|sib
parameter_list|)
value|(sib& 0x7)
define|#
directive|define
name|wFromREX
parameter_list|(
name|rex
parameter_list|)
value|((rex& 0x8)>> 3)
define|#
directive|define
name|rFromREX
parameter_list|(
name|rex
parameter_list|)
value|((rex& 0x4)>> 2)
define|#
directive|define
name|xFromREX
parameter_list|(
name|rex
parameter_list|)
value|((rex& 0x2)>> 1)
define|#
directive|define
name|bFromREX
parameter_list|(
name|rex
parameter_list|)
value|(rex& 0x1)
comment|/*  * These enums represent Intel registers for use by the decoder.  */
define|#
directive|define
name|REGS_8BIT
define|\
value|ENTRY(AL)           \   ENTRY(CL)           \   ENTRY(DL)           \   ENTRY(BL)           \   ENTRY(AH)           \   ENTRY(CH)           \   ENTRY(DH)           \   ENTRY(BH)           \   ENTRY(R8B)          \   ENTRY(R9B)          \   ENTRY(R10B)         \   ENTRY(R11B)         \   ENTRY(R12B)         \   ENTRY(R13B)         \   ENTRY(R14B)         \   ENTRY(R15B)         \   ENTRY(SPL)          \   ENTRY(BPL)          \   ENTRY(SIL)          \   ENTRY(DIL)
define|#
directive|define
name|EA_BASES_16BIT
define|\
value|ENTRY(BX_SI)          \   ENTRY(BX_DI)          \   ENTRY(BP_SI)          \   ENTRY(BP_DI)          \   ENTRY(SI)             \   ENTRY(DI)             \   ENTRY(BP)             \   ENTRY(BX)             \   ENTRY(R8W)            \   ENTRY(R9W)            \   ENTRY(R10W)           \   ENTRY(R11W)           \   ENTRY(R12W)           \   ENTRY(R13W)           \   ENTRY(R14W)           \   ENTRY(R15W)
define|#
directive|define
name|REGS_16BIT
define|\
value|ENTRY(AX)           \   ENTRY(CX)           \   ENTRY(DX)           \   ENTRY(BX)           \   ENTRY(SP)           \   ENTRY(BP)           \   ENTRY(SI)           \   ENTRY(DI)           \   ENTRY(R8W)          \   ENTRY(R9W)          \   ENTRY(R10W)         \   ENTRY(R11W)         \   ENTRY(R12W)         \   ENTRY(R13W)         \   ENTRY(R14W)         \   ENTRY(R15W)
define|#
directive|define
name|EA_BASES_32BIT
define|\
value|ENTRY(EAX)            \   ENTRY(ECX)            \   ENTRY(EDX)            \   ENTRY(EBX)            \   ENTRY(sib)            \   ENTRY(EBP)            \   ENTRY(ESI)            \   ENTRY(EDI)            \   ENTRY(R8D)            \   ENTRY(R9D)            \   ENTRY(R10D)           \   ENTRY(R11D)           \   ENTRY(R12D)           \   ENTRY(R13D)           \   ENTRY(R14D)           \   ENTRY(R15D)
define|#
directive|define
name|REGS_32BIT
define|\
value|ENTRY(EAX)        \   ENTRY(ECX)        \   ENTRY(EDX)        \   ENTRY(EBX)        \   ENTRY(ESP)        \   ENTRY(EBP)        \   ENTRY(ESI)        \   ENTRY(EDI)        \   ENTRY(R8D)        \   ENTRY(R9D)        \   ENTRY(R10D)       \   ENTRY(R11D)       \   ENTRY(R12D)       \   ENTRY(R13D)       \   ENTRY(R14D)       \   ENTRY(R15D)
define|#
directive|define
name|EA_BASES_64BIT
define|\
value|ENTRY(RAX)            \   ENTRY(RCX)            \   ENTRY(RDX)            \   ENTRY(RBX)            \   ENTRY(sib64)          \   ENTRY(RBP)            \   ENTRY(RSI)            \   ENTRY(RDI)            \   ENTRY(R8)             \   ENTRY(R9)             \   ENTRY(R10)            \   ENTRY(R11)            \   ENTRY(R12)            \   ENTRY(R13)            \   ENTRY(R14)            \   ENTRY(R15)
define|#
directive|define
name|REGS_64BIT
define|\
value|ENTRY(RAX)        \   ENTRY(RCX)        \   ENTRY(RDX)        \   ENTRY(RBX)        \   ENTRY(RSP)        \   ENTRY(RBP)        \   ENTRY(RSI)        \   ENTRY(RDI)        \   ENTRY(R8)         \   ENTRY(R9)         \   ENTRY(R10)        \   ENTRY(R11)        \   ENTRY(R12)        \   ENTRY(R13)        \   ENTRY(R14)        \   ENTRY(R15)
define|#
directive|define
name|REGS_MMX
define|\
value|ENTRY(MM0)      \   ENTRY(MM1)      \   ENTRY(MM2)      \   ENTRY(MM3)      \   ENTRY(MM4)      \   ENTRY(MM5)      \   ENTRY(MM6)      \   ENTRY(MM7)
define|#
directive|define
name|REGS_XMM
define|\
value|ENTRY(XMM0)     \   ENTRY(XMM1)     \   ENTRY(XMM2)     \   ENTRY(XMM3)     \   ENTRY(XMM4)     \   ENTRY(XMM5)     \   ENTRY(XMM6)     \   ENTRY(XMM7)     \   ENTRY(XMM8)     \   ENTRY(XMM9)     \   ENTRY(XMM10)    \   ENTRY(XMM11)    \   ENTRY(XMM12)    \   ENTRY(XMM13)    \   ENTRY(XMM14)    \   ENTRY(XMM15)
define|#
directive|define
name|REGS_SEGMENT
define|\
value|ENTRY(ES)          \   ENTRY(CS)          \   ENTRY(SS)          \   ENTRY(DS)          \   ENTRY(FS)          \   ENTRY(GS)
define|#
directive|define
name|REGS_DEBUG
define|\
value|ENTRY(DR0)        \   ENTRY(DR1)        \   ENTRY(DR2)        \   ENTRY(DR3)        \   ENTRY(DR4)        \   ENTRY(DR5)        \   ENTRY(DR6)        \   ENTRY(DR7)
define|#
directive|define
name|REGS_CONTROL_32BIT
define|\
value|ENTRY(ECR0)               \   ENTRY(ECR1)               \   ENTRY(ECR2)               \   ENTRY(ECR3)               \   ENTRY(ECR4)               \   ENTRY(ECR5)               \   ENTRY(ECR6)               \   ENTRY(ECR7)
define|#
directive|define
name|REGS_CONTROL_64BIT
define|\
value|ENTRY(RCR0)               \   ENTRY(RCR1)               \   ENTRY(RCR2)               \   ENTRY(RCR3)               \   ENTRY(RCR4)               \   ENTRY(RCR5)               \   ENTRY(RCR6)               \   ENTRY(RCR7)               \   ENTRY(RCR8)
define|#
directive|define
name|ALL_EA_BASES
define|\
value|EA_BASES_16BIT      \   EA_BASES_32BIT      \   EA_BASES_64BIT
define|#
directive|define
name|ALL_SIB_BASES
define|\
value|REGS_32BIT          \   REGS_64BIT
define|#
directive|define
name|ALL_REGS
define|\
value|REGS_8BIT           \   REGS_16BIT          \   REGS_32BIT          \   REGS_64BIT          \   REGS_MMX            \   REGS_XMM            \   REGS_SEGMENT        \   REGS_DEBUG          \   REGS_CONTROL_32BIT  \   REGS_CONTROL_64BIT  \   ENTRY(RIP)
comment|/*  * EABase - All possible values of the base field for effective-address   *   computations, a.k.a. the Mod and R/M fields of the ModR/M byte.  We  *   distinguish between bases (EA_BASE_*) and registers that just happen to be  *   referred to when Mod == 0b11 (EA_REG_*).  */
typedef|typedef
enum|enum
block|{
name|EA_BASE_NONE
block|,
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|EA_BASE_##x,
name|ALL_EA_BASES
undef|#
directive|undef
name|ENTRY
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|EA_REG_##x,
name|ALL_REGS
undef|#
directive|undef
name|ENTRY
name|EA_max
block|}
name|EABase
typedef|;
comment|/*   * SIBIndex - All possible values of the SIB index field.  *   Borrows entries from ALL_EA_BASES with the special case that  *   sib is synonymous with NONE.  */
typedef|typedef
enum|enum
block|{
name|SIB_INDEX_NONE
block|,
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|SIB_INDEX_##x,
name|ALL_EA_BASES
undef|#
directive|undef
name|ENTRY
name|SIB_INDEX_max
block|}
name|SIBIndex
typedef|;
comment|/*  * SIBBase - All possible values of the SIB base field.  */
typedef|typedef
enum|enum
block|{
name|SIB_BASE_NONE
block|,
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|SIB_BASE_##x,
name|ALL_SIB_BASES
undef|#
directive|undef
name|ENTRY
name|SIB_BASE_max
block|}
name|SIBBase
typedef|;
comment|/*  * EADisplacement - Possible displacement types for effective-address  *   computations.  */
typedef|typedef
enum|enum
block|{
name|EA_DISP_NONE
block|,
name|EA_DISP_8
block|,
name|EA_DISP_16
block|,
name|EA_DISP_32
block|}
name|EADisplacement
typedef|;
comment|/*  * Reg - All possible values of the reg field in the ModR/M byte.  */
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|MODRM_REG_##x,
name|ALL_REGS
undef|#
directive|undef
name|ENTRY
name|MODRM_REG_max
block|}
name|Reg
typedef|;
comment|/*  * SegmentOverride - All possible segment overrides.  */
typedef|typedef
enum|enum
block|{
name|SEG_OVERRIDE_NONE
block|,
name|SEG_OVERRIDE_CS
block|,
name|SEG_OVERRIDE_SS
block|,
name|SEG_OVERRIDE_DS
block|,
name|SEG_OVERRIDE_ES
block|,
name|SEG_OVERRIDE_FS
block|,
name|SEG_OVERRIDE_GS
block|,
name|SEG_OVERRIDE_max
block|}
name|SegmentOverride
typedef|;
typedef|typedef
name|uint8_t
name|BOOL
typedef|;
comment|/*  * byteReader_t - Type for the byte reader that the consumer must provide to  *   the decoder.  Reads a single byte from the instruction's address space.  * @param arg     - A baton that the consumer can associate with any internal  *                  state that it needs.  * @param byte    - A pointer to a single byte in memory that should be set to  *                  contain the value at address.  * @param address - The address in the instruction's address space that should  *                  be read from.  * @return        - -1 if the byte cannot be read for any reason; 0 otherwise.  */
typedef|typedef
name|int
function_decl|(
modifier|*
name|byteReader_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|uint8_t
modifier|*
name|byte
parameter_list|,
name|uint64_t
name|address
parameter_list|)
function_decl|;
comment|/*  * dlog_t - Type for the logging function that the consumer can provide to  *   get debugging output from the decoder.  * @param arg     - A baton that the consumer can associate with any internal  *                  state that it needs.  * @param log     - A string that contains the message.  Will be reused after  *                  the logger returns.  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|dlog_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|log
parameter_list|)
function_decl|;
comment|/*  * The x86 internal instruction, which is produced by the decoder.  */
struct|struct
name|InternalInstruction
block|{
comment|/* Reader interface (C) */
name|byteReader_t
name|reader
decl_stmt|;
comment|/* Opaque value passed to the reader */
name|void
modifier|*
name|readerArg
decl_stmt|;
comment|/* The address of the next byte to read via the reader */
name|uint64_t
name|readerCursor
decl_stmt|;
comment|/* Logger interface (C) */
name|dlog_t
name|dlog
decl_stmt|;
comment|/* Opaque value passed to the logger */
name|void
modifier|*
name|dlogArg
decl_stmt|;
comment|/* General instruction information */
comment|/* The mode to disassemble for (64-bit, protected, real) */
name|DisassemblerMode
name|mode
decl_stmt|;
comment|/* The start of the instruction, usable with the reader */
name|uint64_t
name|startLocation
decl_stmt|;
comment|/* The length of the instruction, in bytes */
name|size_t
name|length
decl_stmt|;
comment|/* Prefix state */
comment|/* 1 if the prefix byte corresponding to the entry is present; 0 if not */
name|uint8_t
name|prefixPresent
index|[
literal|0x100
index|]
decl_stmt|;
comment|/* contains the location (for use with the reader) of the prefix byte */
name|uint64_t
name|prefixLocations
index|[
literal|0x100
index|]
decl_stmt|;
comment|/* The value of the REX prefix, if present */
name|uint8_t
name|rexPrefix
decl_stmt|;
comment|/* The location of the REX prefix */
name|uint64_t
name|rexLocation
decl_stmt|;
comment|/* The location where a mandatory prefix would have to be (i.e., right before      the opcode, or right before the REX prefix if one is present) */
name|uint64_t
name|necessaryPrefixLocation
decl_stmt|;
comment|/* The segment override type */
name|SegmentOverride
name|segmentOverride
decl_stmt|;
comment|/* Sizes of various critical pieces of data */
name|uint8_t
name|registerSize
decl_stmt|;
name|uint8_t
name|addressSize
decl_stmt|;
name|uint8_t
name|displacementSize
decl_stmt|;
name|uint8_t
name|immediateSize
decl_stmt|;
comment|/* opcode state */
comment|/* The value of the two-byte escape prefix (usually 0x0f) */
name|uint8_t
name|twoByteEscape
decl_stmt|;
comment|/* The value of the three-byte escape prefix (usually 0x38 or 0x3a) */
name|uint8_t
name|threeByteEscape
decl_stmt|;
comment|/* The last byte of the opcode, not counting any ModR/M extension */
name|uint8_t
name|opcode
decl_stmt|;
comment|/* The ModR/M byte of the instruction, if it is an opcode extension */
name|uint8_t
name|modRMExtension
decl_stmt|;
comment|/* decode state */
comment|/* The type of opcode, used for indexing into the array of decode tables */
name|OpcodeType
name|opcodeType
decl_stmt|;
comment|/* The instruction ID, extracted from the decode table */
name|uint16_t
name|instructionID
decl_stmt|;
comment|/* The specifier for the instruction, from the instruction info table */
name|struct
name|InstructionSpecifier
modifier|*
name|spec
decl_stmt|;
comment|/* state for additional bytes, consumed during operand decode.  Pattern:      consumed___ indicates that the byte was already consumed and does not      need to be consumed again */
comment|/* The ModR/M byte, which contains most register operands and some portion of      all memory operands */
name|BOOL
name|consumedModRM
decl_stmt|;
name|uint8_t
name|modRM
decl_stmt|;
comment|/* The SIB byte, used for more complex 32- or 64-bit memory operands */
name|BOOL
name|consumedSIB
decl_stmt|;
name|uint8_t
name|sib
decl_stmt|;
comment|/* The displacement, used for memory operands */
name|BOOL
name|consumedDisplacement
decl_stmt|;
name|int32_t
name|displacement
decl_stmt|;
comment|/* Immediates.  There can be two in some cases */
name|uint8_t
name|numImmediatesConsumed
decl_stmt|;
name|uint8_t
name|numImmediatesTranslated
decl_stmt|;
name|uint64_t
name|immediates
index|[
literal|2
index|]
decl_stmt|;
comment|/* A register or immediate operand encoded into the opcode */
name|BOOL
name|consumedOpcodeModifier
decl_stmt|;
name|uint8_t
name|opcodeModifier
decl_stmt|;
name|Reg
name|opcodeRegister
decl_stmt|;
comment|/* Portions of the ModR/M byte */
comment|/* These fields determine the allowable values for the ModR/M fields, which      depend on operand and address widths */
name|EABase
name|eaBaseBase
decl_stmt|;
name|EABase
name|eaRegBase
decl_stmt|;
name|Reg
name|regBase
decl_stmt|;
comment|/* The Mod and R/M fields can encode a base for an effective address, or a      register.  These are separated into two fields here */
name|EABase
name|eaBase
decl_stmt|;
name|EADisplacement
name|eaDisplacement
decl_stmt|;
comment|/* The reg field always encodes a register */
name|Reg
name|reg
decl_stmt|;
comment|/* SIB state */
name|SIBIndex
name|sibIndex
decl_stmt|;
name|uint8_t
name|sibScale
decl_stmt|;
name|SIBBase
name|sibBase
decl_stmt|;
block|}
struct|;
comment|/* decodeInstruction - Decode one instruction and store the decoding results in  *   a buffer provided by the consumer.  * @param insn      - The buffer to store the instruction in.  Allocated by the  *                    consumer.  * @param reader    - The byteReader_t for the bytes to be read.  * @param readerArg - An argument to pass to the reader for storing context  *                    specific to the consumer.  May be NULL.  * @param logger    - The dlog_t to be used in printing status messages from the  *                    disassembler.  May be NULL.  * @param loggerArg - An argument to pass to the logger for storing context  *                    specific to the logger.  May be NULL.  * @param startLoc  - The address (in the reader's address space) of the first  *                    byte in the instruction.  * @param mode      - The mode (16-bit, 32-bit, 64-bit) to decode in.  * @return          - Nonzero if there was an error during decode, 0 otherwise.  */
name|int
name|decodeInstruction
parameter_list|(
name|struct
name|InternalInstruction
modifier|*
name|insn
parameter_list|,
name|byteReader_t
name|reader
parameter_list|,
name|void
modifier|*
name|readerArg
parameter_list|,
name|dlog_t
name|logger
parameter_list|,
name|void
modifier|*
name|loggerArg
parameter_list|,
name|uint64_t
name|startLoc
parameter_list|,
name|DisassemblerMode
name|mode
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

