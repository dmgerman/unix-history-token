begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mn10200.h -- Header file for Matsushita 10200 opcode table    Copyright 1996, 1997 Free Software Foundation, Inc.    Written by Jeff Law, Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MN10200_H
end_ifndef

begin_define
define|#
directive|define
name|MN10200_H
end_define

begin_comment
comment|/* The opcode table is an array of struct mn10200_opcode.  */
end_comment

begin_struct
struct|struct
name|mn10200_opcode
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
comment|/* The format of this opcode.  */
name|unsigned
name|char
name|format
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|8
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
name|mn10200_opcode
name|mn10200_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|mn10200_num_opcodes
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct mn10200_operand.  */
end_comment

begin_struct
struct|struct
name|mn10200_operand
block|{
comment|/* The number of bits in the operand.  */
name|int
name|bits
decl_stmt|;
comment|/* How far the operand is left shifted in the instruction.  */
name|int
name|shift
decl_stmt|;
comment|/* One bit syntax flags.  */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the mn10200_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mn10200_operand
name|mn10200_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct mn10200_operand.  */
end_comment

begin_define
define|#
directive|define
name|MN10200_OPERAND_DREG
value|0x1
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_AREG
value|0x2
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_PSW
value|0x4
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_MDR
value|0x8
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_SIGNED
value|0x10
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_PROMOTE
value|0x20
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_PAREN
value|0x40
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_REPEATED
value|0x80
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_EXTENDED
value|0x100
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_NOCHECK
value|0x200
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_PCREL
value|0x400
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_MEMADDR
value|0x800
end_define

begin_define
define|#
directive|define
name|MN10200_OPERAND_RELAX
value|0x1000
end_define

begin_define
define|#
directive|define
name|FMT_1
value|1
end_define

begin_define
define|#
directive|define
name|FMT_2
value|2
end_define

begin_define
define|#
directive|define
name|FMT_3
value|3
end_define

begin_define
define|#
directive|define
name|FMT_4
value|4
end_define

begin_define
define|#
directive|define
name|FMT_5
value|5
end_define

begin_define
define|#
directive|define
name|FMT_6
value|6
end_define

begin_define
define|#
directive|define
name|FMT_7
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MN10200_H */
end_comment

end_unit

