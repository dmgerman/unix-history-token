begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* v850.h -- Header file for NEC V850 opcode table    Copyright 1996, 1997, 2001 Free Software Foundation, Inc.    Written by J.T. Conklin, Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|V850_H
end_ifndef

begin_define
define|#
directive|define
name|V850_H
end_define

begin_comment
comment|/* The opcode table is an array of struct v850_opcode.  */
end_comment

begin_struct
struct|struct
name|v850_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The opcode itself.  Those bits which will be filled in with      operands are zeroes.  */
name|unsigned
name|long
name|opcode
decl_stmt|;
comment|/* The opcode mask.  This is used by the disassembler.  This is a      mask containing ones indicating those bits which must match the      opcode field, and zeroes indicating those bits which need not      match (and are presumably filled in by operands).  */
name|unsigned
name|long
name|mask
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|8
index|]
decl_stmt|;
comment|/* Which (if any) operand is a memory operand.  */
name|unsigned
name|int
name|memop
decl_stmt|;
comment|/* Target processor(s).  A bit field of processors which support      this instruction.  Note a bit field is used as some instructions      are available on multiple, different processor types, whereas      other instructions are only available on one specific type.  */
name|unsigned
name|int
name|processors
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Values for the processors field in the v850_opcode structure.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_V850
value|(1<< 0)
end_define

begin_comment
comment|/* Just the V850.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_ALL
value|-1
end_define

begin_comment
comment|/* Any processor.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_V850E
value|(1<< 1)
end_define

begin_comment
comment|/* Just the V850E. */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_NOT_V850
value|(~ PROCESSOR_V850)
end_define

begin_comment
comment|/* Any processor except the V850.  */
end_comment

begin_define
define|#
directive|define
name|PROCESSOR_V850EA
value|(1<< 2)
end_define

begin_comment
comment|/* Just the V850EA. */
end_comment

begin_comment
comment|/* The table itself is sorted by major opcode number, and is otherwise    in the order in which the disassembler should consider    instructions.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|v850_opcode
name|v850_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|v850_num_opcodes
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct v850_operand.  */
end_comment

begin_struct
struct|struct
name|v850_operand
block|{
comment|/* The number of bits in the operand.  */
comment|/* If this value is -1 then the operand's bits are in a discontinous distribution in the instruction. */
name|int
name|bits
decl_stmt|;
comment|/* (bits>= 0):  How far the operand is left shifted in the instruction.  */
comment|/* (bits == -1): Bit mask of the bits in the operand.  */
name|int
name|shift
decl_stmt|;
comment|/* Insertion function.  This is used by the assembler.  To insert an      operand value into an instruction, check this field.       If it is NULL, execute          i |= (op& ((1<< o->bits) - 1))<< o->shift;      (i is the instruction which we are filling in, o is a pointer to      this structure, and op is the opcode value; this assumes twos      complement arithmetic).       If this field is not NULL, then simply call it with the      instruction and the operand value.  It will return the new value      of the instruction.  If the ERRMSG argument is not NULL, then if      the operand value is illegal, *ERRMSG will be set to a warning      string (the operand will be inserted in any case).  If the      operand value is legal, *ERRMSG will be unchanged (most operands      can accept any value).  */
name|unsigned
name|long
argument_list|(
operator|*
name|insert
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
name|instruction
operator|,
name|long
name|op
operator|,
specifier|const
name|char
operator|*
operator|*
name|errmsg
operator|)
argument_list|)
decl_stmt|;
comment|/* Extraction function.  This is used by the disassembler.  To      extract this operand type from an instruction, check this field.       If it is NULL, compute          op = o->bits == -1 ? ((i)& o->shift) : ((i)>> o->shift)& ((1<< o->bits) - 1); 	 if (o->flags& V850_OPERAND_SIGNED) 	     op = (op<< (32 - o->bits))>> (32 - o->bits);      (i is the instruction, o is a pointer to this structure, and op      is the result; this assumes twos complement arithmetic).       If this field is not NULL, then simply call it with the      instruction value.  It will return the value of the operand.  If      the INVALID argument is not NULL, *INVALID will be set to      non-zero if this operand type can not actually be extracted from      this operand (i.e., the instruction does not match).  If the      operand is valid, *INVALID will not be changed.  */
name|unsigned
name|long
argument_list|(
operator|*
name|extract
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
name|instruction
operator|,
name|int
operator|*
name|invalid
operator|)
argument_list|)
decl_stmt|;
comment|/* One bit syntax flags.  */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the v850_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|v850_operand
name|v850_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct v850_operand.  */
end_comment

begin_comment
comment|/* This operand names a general purpose register */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_REG
value|0x01
end_define

begin_comment
comment|/* This operand names a system register */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_SRG
value|0x02
end_define

begin_comment
comment|/* This operand names a condition code used in the setf instruction */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_CC
value|0x04
end_define

begin_comment
comment|/* This operand takes signed values */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_SIGNED
value|0x08
end_define

begin_comment
comment|/* This operand is the ep register.  */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_EP
value|0x10
end_define

begin_comment
comment|/* This operand is a PC displacement */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_DISP
value|0x20
end_define

begin_comment
comment|/* This is a relaxable operand.   Only used for D9->D22 branch relaxing    right now.  We may need others in the future (or maybe handle them like    promoted operands on the mn10300?)  */
end_comment

begin_define
define|#
directive|define
name|V850_OPERAND_RELAX
value|0x40
end_define

begin_comment
comment|/* The register specified must not be r0 */
end_comment

begin_define
define|#
directive|define
name|V850_NOT_R0
value|0x80
end_define

begin_comment
comment|/* push/pop type instruction, V850E specific.  */
end_comment

begin_define
define|#
directive|define
name|V850E_PUSH_POP
value|0x100
end_define

begin_comment
comment|/* 16 bit immediate follows instruction, V850E specific.  */
end_comment

begin_define
define|#
directive|define
name|V850E_IMMEDIATE16
value|0x200
end_define

begin_comment
comment|/* 32 bit immediate follows instruction, V850E specific.  */
end_comment

begin_define
define|#
directive|define
name|V850E_IMMEDIATE32
value|0x400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V850_H */
end_comment

end_unit

