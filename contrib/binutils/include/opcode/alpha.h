begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alpha.h -- Header file for Alpha opcode table    Copyright 1996 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@tamu.edu>,    patterned after the PPC opcode table written by Ian Lance Taylor.  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPCODE_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|OPCODE_ALPHA_H
end_define

begin_comment
comment|/* The opcode table is an array of struct alpha_opcode.  */
end_comment

begin_struct
struct|struct
name|alpha_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with      operands are zeroes.  */
name|unsigned
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a      mask containing ones indicating those bits which must match the      opcode field, and zeroes indicating those bits which need not      match (and are presumably filled in by operands).  */
name|unsigned
name|mask
decl_stmt|;
comment|/* One bit flags for the opcode.  These are primarily used to      indicate specific processors and environments support the      instructions.  The defined values are listed below. */
name|unsigned
name|flags
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The table itself is sorted by major opcode number, and is otherwise    in the order in which the disassembler should consider    instructions.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|alpha_opcode
name|alpha_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|alpha_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct alpha_opcode.  */
end_comment

begin_comment
comment|/* CPU Availability */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_BASE
value|0x0001
end_define

begin_comment
comment|/* Base architecture -- all cpus.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_EV4
value|0x0002
end_define

begin_comment
comment|/* EV4 specific PALcode insns.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_EV5
value|0x0004
end_define

begin_comment
comment|/* EV5 specific PALcode insns.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_BWX
value|0x0100
end_define

begin_comment
comment|/* Byte/word extension (amask bit 0).  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_CIX
value|0x0200
end_define

begin_comment
comment|/* "Count" extension (amask bit 1).  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_MAX
value|0x0400
end_define

begin_comment
comment|/* Multimedia extension (amask bit 8).  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPCODE_NOPAL
value|(~(AXP_OPCODE_EV4|AXP_OPCODE_EV5))
end_define

begin_comment
comment|/* A macro to extract the major opcode from an instruction.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OP
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 26)& 0x3F)
end_define

begin_comment
comment|/* The total number of major opcodes. */
end_comment

begin_define
define|#
directive|define
name|AXP_NOPS
value|0x40
end_define

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct alpha_operand.  */
end_comment

begin_struct
struct|struct
name|alpha_operand
block|{
comment|/* The number of bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction.  */
name|int
name|shift
decl_stmt|;
comment|/* The default relocation type for this operand.  */
name|int
name|default_reloc
decl_stmt|;
comment|/* One bit syntax flags.  */
name|unsigned
name|flags
decl_stmt|;
comment|/* Insertion function.  This is used by the assembler.  To insert an      operand value into an instruction, check this field.       If it is NULL, execute          i |= (op& ((1<< o->bits) - 1))<< o->shift;      (i is the instruction which we are filling in, o is a pointer to      this structure, and op is the opcode value; this assumes twos      complement arithmetic).       If this field is not NULL, then simply call it with the      instruction and the operand value.  It will return the new value      of the instruction.  If the ERRMSG argument is not NULL, then if      the operand value is illegal, *ERRMSG will be set to a warning      string (the operand will be inserted in any case).  If the      operand value is legal, *ERRMSG will be unchanged (most operands      can accept any value).  */
name|unsigned
argument_list|(
argument|*insert
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|instruction
operator|,
name|int
name|op
operator|,
specifier|const
name|char
operator|*
operator|*
name|errmsg
operator|)
argument_list|)
expr_stmt|;
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if ((o->flags& AXP_OPERAND_SIGNED) != 0&& (op& (1<< (o->bits - 1))) != 0) 	   op -= 1<< o->bits;      (i is the instruction, o is a pointer to this structure, and op      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.  */
name|int
argument_list|(
argument|*extract
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|instruction
operator|,
name|int
operator|*
name|invalid
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the alpha_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|alpha_operand
name|alpha_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|alpha_num_operands
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct alpha_operand.  */
end_comment

begin_comment
comment|/* Mask for selecting the type for typecheck purposes */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_TYPECHECK_MASK
define|\
value|(AXP_OPERAND_PARENS | AXP_OPERAND_COMMA | AXP_OPERAND_IR |		\    AXP_OPERAND_FPR | AXP_OPERAND_RELATIVE | AXP_OPERAND_SIGNED | 	\    AXP_OPERAND_UNSIGNED)
end_define

begin_comment
comment|/* This operand does not actually exist in the assembler input.  This    is used to support extended mnemonics, for which two operands fields    are identical.  The assembler should call the insert function with    any op value.  The disassembler should call the extract function,    ignore the return value, and check the value placed in the invalid    argument.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_FAKE
value|01
end_define

begin_comment
comment|/* The operand should be wrapped in parentheses rather than separated    from the previous by a comma.  This is used for the load and store    instructions which want their operands to look like "Ra,disp(Rb)".  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_PARENS
value|02
end_define

begin_comment
comment|/* Used in combination with PARENS, this supresses the supression of    the comma.  This is used for "jmp Ra,(Rb),hint".  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_COMMA
value|04
end_define

begin_comment
comment|/* This operand names an integer register.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_IR
value|010
end_define

begin_comment
comment|/* This operand names a floating point register.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_FPR
value|020
end_define

begin_comment
comment|/* This operand is a relative branch displacement.  The disassembler    prints these symbolically if possible.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_RELATIVE
value|040
end_define

begin_comment
comment|/* This operand takes signed values.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_SIGNED
value|0100
end_define

begin_comment
comment|/* This operand takes unsigned values.  This exists primarily so that    a flags value of 0 can be treated as end-of-arguments.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_UNSIGNED
value|0200
end_define

begin_comment
comment|/* Supress overflow detection on this field.  This is used for hints. */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_NOOVERFLOW
value|0400
end_define

begin_comment
comment|/* Mask for optional argument default value.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_OPTIONAL_MASK
value|07000
end_define

begin_comment
comment|/* This operand defaults to zero.  This is used for jump hints.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_DEFAULT_ZERO
value|01000
end_define

begin_comment
comment|/* This operand should default to the first (real) operand and is used    in conjunction with AXP_OPERAND_OPTIONAL.  This allows    "and $0,3,$0" to be written as "and $0,3", etc.  I don't like    it, but it's what DEC does.  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_DEFAULT_FIRST
value|02000
end_define

begin_comment
comment|/* Similarly, this operand should default to the second (real) operand.    This allows "negl $0" instead of "negl $0,$0".  */
end_comment

begin_define
define|#
directive|define
name|AXP_OPERAND_DEFAULT_SECOND
value|04000
end_define

begin_escape
end_escape

begin_comment
comment|/* Register common names */
end_comment

begin_define
define|#
directive|define
name|AXP_REG_V0
value|0
end_define

begin_define
define|#
directive|define
name|AXP_REG_T0
value|1
end_define

begin_define
define|#
directive|define
name|AXP_REG_T1
value|2
end_define

begin_define
define|#
directive|define
name|AXP_REG_T2
value|3
end_define

begin_define
define|#
directive|define
name|AXP_REG_T3
value|4
end_define

begin_define
define|#
directive|define
name|AXP_REG_T4
value|5
end_define

begin_define
define|#
directive|define
name|AXP_REG_T5
value|6
end_define

begin_define
define|#
directive|define
name|AXP_REG_T6
value|7
end_define

begin_define
define|#
directive|define
name|AXP_REG_T7
value|8
end_define

begin_define
define|#
directive|define
name|AXP_REG_S0
value|9
end_define

begin_define
define|#
directive|define
name|AXP_REG_S1
value|10
end_define

begin_define
define|#
directive|define
name|AXP_REG_S2
value|11
end_define

begin_define
define|#
directive|define
name|AXP_REG_S3
value|12
end_define

begin_define
define|#
directive|define
name|AXP_REG_S4
value|13
end_define

begin_define
define|#
directive|define
name|AXP_REG_S5
value|14
end_define

begin_define
define|#
directive|define
name|AXP_REG_FP
value|15
end_define

begin_define
define|#
directive|define
name|AXP_REG_A0
value|16
end_define

begin_define
define|#
directive|define
name|AXP_REG_A1
value|17
end_define

begin_define
define|#
directive|define
name|AXP_REG_A2
value|18
end_define

begin_define
define|#
directive|define
name|AXP_REG_A3
value|19
end_define

begin_define
define|#
directive|define
name|AXP_REG_A4
value|20
end_define

begin_define
define|#
directive|define
name|AXP_REG_A5
value|21
end_define

begin_define
define|#
directive|define
name|AXP_REG_T8
value|22
end_define

begin_define
define|#
directive|define
name|AXP_REG_T9
value|23
end_define

begin_define
define|#
directive|define
name|AXP_REG_T10
value|24
end_define

begin_define
define|#
directive|define
name|AXP_REG_T11
value|25
end_define

begin_define
define|#
directive|define
name|AXP_REG_RA
value|26
end_define

begin_define
define|#
directive|define
name|AXP_REG_PV
value|27
end_define

begin_define
define|#
directive|define
name|AXP_REG_T12
value|27
end_define

begin_define
define|#
directive|define
name|AXP_REG_AT
value|28
end_define

begin_define
define|#
directive|define
name|AXP_REG_GP
value|29
end_define

begin_define
define|#
directive|define
name|AXP_REG_SP
value|30
end_define

begin_define
define|#
directive|define
name|AXP_REG_ZERO
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPCODE_ALPHA_H */
end_comment

end_unit

