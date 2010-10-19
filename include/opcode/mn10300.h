begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mn10300.h -- Header file for Matsushita 10300 opcode table    Copyright 1996, 1997, 1998, 1999, 2003 Free Software Foundation, Inc.    Written by Jeff Law, Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MN10300_H
end_ifndef

begin_define
define|#
directive|define
name|MN10300_H
end_define

begin_comment
comment|/* The opcode table is an array of struct mn10300_opcode.  */
end_comment

begin_define
define|#
directive|define
name|MN10300_MAX_OPERANDS
value|8
end_define

begin_struct
struct|struct
name|mn10300_opcode
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
comment|/* A bitmask.  For each operand, nonzero if it must not have the same      register specification as all other operands with a nonzero bit in      this flag.  ie 0x81 would indicate that operands 7 and 0 must not      match.  Note that we count operands from left to right as they appear      in the operands specification below.  */
name|unsigned
name|int
name|no_match_operands
decl_stmt|;
comment|/* The format of this opcode.  */
name|unsigned
name|char
name|format
decl_stmt|;
comment|/* Bitmask indicating what cpu variants this opcode is available on.      We assume mn10300 base opcodes are available everywhere, so we only      have to note opcodes which are available on other variants.  */
name|unsigned
name|int
name|machine
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
name|MN10300_MAX_OPERANDS
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
name|mn10300_opcode
name|mn10300_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|mn10300_num_opcodes
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The operands table is an array of struct mn10300_operand.  */
end_comment

begin_struct
struct|struct
name|mn10300_operand
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
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the mn10300_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mn10300_operand
name|mn10300_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct mn10300_operand.  */
end_comment

begin_define
define|#
directive|define
name|MN10300_OPERAND_DREG
value|0x1
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_AREG
value|0x2
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_SP
value|0x4
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PSW
value|0x8
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_MDR
value|0x10
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_SIGNED
value|0x20
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PROMOTE
value|0x40
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PAREN
value|0x80
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_REPEATED
value|0x100
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_EXTENDED
value|0x200
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_SPLIT
value|0x400
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_REG_LIST
value|0x800
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PCREL
value|0x1000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_MEMADDR
value|0x2000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_RELAX
value|0x4000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_USP
value|0x8000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_SSP
value|0x10000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_MSP
value|0x20000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PC
value|0x40000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_EPSW
value|0x80000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_RREG
value|0x100000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_XRREG
value|0x200000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_PLUS
value|0x400000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_24BIT
value|0x800000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_FSREG
value|0x1000000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_FDREG
value|0x2000000
end_define

begin_define
define|#
directive|define
name|MN10300_OPERAND_FPCR
value|0x4000000
end_define

begin_comment
comment|/* Opcode Formats.  */
end_comment

begin_define
define|#
directive|define
name|FMT_S0
value|1
end_define

begin_define
define|#
directive|define
name|FMT_S1
value|2
end_define

begin_define
define|#
directive|define
name|FMT_S2
value|3
end_define

begin_define
define|#
directive|define
name|FMT_S4
value|4
end_define

begin_define
define|#
directive|define
name|FMT_S6
value|5
end_define

begin_define
define|#
directive|define
name|FMT_D0
value|6
end_define

begin_define
define|#
directive|define
name|FMT_D1
value|7
end_define

begin_define
define|#
directive|define
name|FMT_D2
value|8
end_define

begin_define
define|#
directive|define
name|FMT_D4
value|9
end_define

begin_define
define|#
directive|define
name|FMT_D5
value|10
end_define

begin_define
define|#
directive|define
name|FMT_D6
value|11
end_define

begin_define
define|#
directive|define
name|FMT_D7
value|12
end_define

begin_define
define|#
directive|define
name|FMT_D8
value|13
end_define

begin_define
define|#
directive|define
name|FMT_D9
value|14
end_define

begin_define
define|#
directive|define
name|FMT_D10
value|15
end_define

begin_define
define|#
directive|define
name|FMT_D3
value|16
end_define

begin_comment
comment|/* Variants of the mn10300 which have additional opcodes.  */
end_comment

begin_define
define|#
directive|define
name|MN103
value|300
end_define

begin_define
define|#
directive|define
name|AM30
value|300
end_define

begin_define
define|#
directive|define
name|AM33
value|330
end_define

begin_define
define|#
directive|define
name|AM33_2
value|332
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MN10300_H */
end_comment

end_unit

