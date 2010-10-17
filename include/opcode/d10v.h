begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* d10v.h -- Header file for D10V opcode table    Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2003    Free Software Foundation, Inc.    Written by Martin Hunt (hunt@cygnus.com), Cygnus Support  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|D10V_H
end_ifndef

begin_define
define|#
directive|define
name|D10V_H
end_define

begin_comment
comment|/* Format Specifier */
end_comment

begin_define
define|#
directive|define
name|FM00
value|0
end_define

begin_define
define|#
directive|define
name|FM01
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM10
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM11
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|NOP
value|0x5e00
end_define

begin_define
define|#
directive|define
name|OPCODE_DIVS
value|0x14002800
end_define

begin_comment
comment|/* The opcode table is an array of struct d10v_opcode.  */
end_comment

begin_struct
struct|struct
name|d10v_opcode
block|{
comment|/* The opcode name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the opcode format */
name|int
name|format
decl_stmt|;
comment|/* These numbers were picked so we can do if( i& SHORT_OPCODE) */
define|#
directive|define
name|SHORT_OPCODE
value|1
define|#
directive|define
name|LONG_OPCODE
value|8
define|#
directive|define
name|SHORT_2
value|1
comment|/* short with 2 operands */
define|#
directive|define
name|SHORT_B
value|3
comment|/* short with 8-bit branch */
define|#
directive|define
name|LONG_B
value|8
comment|/* long with 16-bit branch */
define|#
directive|define
name|LONG_L
value|10
comment|/* long with 3 operands */
define|#
directive|define
name|LONG_R
value|12
comment|/* reserved */
comment|/* just a placeholder for variable-length instructions */
comment|/* for example, "bra" will be a fake for "bra.s" and bra.l" */
comment|/* which will immediately follow in the opcode table.  */
define|#
directive|define
name|OPCODE_FAKE
value|32
comment|/* the number of cycles */
name|int
name|cycles
decl_stmt|;
comment|/* the execution unit(s) used */
name|int
name|unit
decl_stmt|;
define|#
directive|define
name|EITHER
value|0
define|#
directive|define
name|IU
value|1
define|#
directive|define
name|MU
value|2
define|#
directive|define
name|BOTH
value|3
comment|/* execution type; parallel or sequential */
comment|/* this field is used to decide if two instructions */
comment|/* can be executed in parallel */
name|int
name|exec_type
decl_stmt|;
define|#
directive|define
name|PARONLY
value|1
comment|/* parallel only */
define|#
directive|define
name|SEQ
value|2
comment|/* must be sequential */
define|#
directive|define
name|PAR
value|4
comment|/* may be parallel */
define|#
directive|define
name|BRANCH_LINK
value|8
comment|/* subroutine call.  must be aligned */
define|#
directive|define
name|RMEM
value|16
comment|/* reads memory */
define|#
directive|define
name|WMEM
value|32
comment|/* writes memory */
define|#
directive|define
name|RF0
value|64
comment|/* reads f0 */
define|#
directive|define
name|WF0
value|128
comment|/* modifies f0 */
define|#
directive|define
name|WCAR
value|256
comment|/* write Carry */
define|#
directive|define
name|BRANCH
value|512
comment|/* branch, no link */
define|#
directive|define
name|ALONE
value|1024
comment|/* short but pack with a NOP if on asm line alone */
comment|/* the opcode */
name|long
name|opcode
decl_stmt|;
comment|/* mask.  if( (i& mask) == opcode ) then match */
name|long
name|mask
decl_stmt|;
comment|/* An array of operand codes.  Each code is an index into the      operand table.  They appear in the order which the operands must      appear in assembly code, and are terminated by a zero.  */
name|unsigned
name|char
name|operands
index|[
literal|6
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
name|d10v_opcode
name|d10v_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|d10v_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The operands table is an array of struct d10v_operand.  */
end_comment

begin_struct
struct|struct
name|d10v_operand
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
comment|/* Elements in the table are retrieved by indexing with values from    the operands field of the d10v_opcodes table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|d10v_operand
name|d10v_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values defined for the flags field of a struct d10v_operand.  */
end_comment

begin_comment
comment|/* the operand must be an even number */
end_comment

begin_define
define|#
directive|define
name|OPERAND_EVEN
value|(1)
end_define

begin_comment
comment|/* the operand must be an odd number */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ODD
value|(2)
end_define

begin_comment
comment|/* this is the destination register; it will be modified */
end_comment

begin_comment
comment|/* this is used by the optimizer */
end_comment

begin_define
define|#
directive|define
name|OPERAND_DEST
value|(4)
end_define

begin_comment
comment|/* number or symbol */
end_comment

begin_define
define|#
directive|define
name|OPERAND_NUM
value|(8)
end_define

begin_comment
comment|/* address or label */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ADDR
value|(0x10)
end_define

begin_comment
comment|/* register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_REG
value|(0x20)
end_define

begin_comment
comment|/* postincrement +  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_PLUS
value|(0x40)
end_define

begin_comment
comment|/* postdecrement -  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_MINUS
value|(0x80)
end_define

begin_comment
comment|/* @  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATSIGN
value|(0x100)
end_define

begin_comment
comment|/* @(  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATPAR
value|(0x200)
end_define

begin_comment
comment|/* accumulator 0 */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ACC0
value|(0x400)
end_define

begin_comment
comment|/* accumulator 1 */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ACC1
value|(0x800)
end_define

begin_comment
comment|/* f0 / f1 flag register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_FFLAG
value|(0x1000)
end_define

begin_comment
comment|/* c flag register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_CFLAG
value|(0x2000)
end_define

begin_comment
comment|/* control register  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_CONTROL
value|(0x4000)
end_define

begin_comment
comment|/* predecrement mode '@-sp'  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_ATMINUS
value|(0x8000)
end_define

begin_comment
comment|/* signed number */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SIGNED
value|(0x10000)
end_define

begin_comment
comment|/* special accumulator shifts need a 4-bit number */
end_comment

begin_comment
comment|/* 1<= x<= 16 */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SHIFT
value|(0x20000)
end_define

begin_comment
comment|/* general purpose register */
end_comment

begin_define
define|#
directive|define
name|OPERAND_GPR
value|(0x40000)
end_define

begin_comment
comment|/* special imm3 values with range restricted to -2<= imm3<= 3 */
end_comment

begin_comment
comment|/* needed for rac/rachi */
end_comment

begin_define
define|#
directive|define
name|RESTRICTED_NUM3
value|(0x80000)
end_define

begin_comment
comment|/* Pre-decrement is only supported for SP.  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_SP
value|(0x100000)
end_define

begin_comment
comment|/* Post-decrement is not supported for SP.  Like OPERAND_EVEN, and    unlike OPERAND_SP, this flag doesn't prevent the instruction from    matching, it only fails validation later on.  */
end_comment

begin_define
define|#
directive|define
name|OPERAND_NOSP
value|(0x200000)
end_define

begin_comment
comment|/* Structure to hold information about predefined registers.  */
end_comment

begin_struct
struct|struct
name|pd_reg
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name to recognize */
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* name to print for this register */
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|pd_reg
name|d10v_predefined_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|d10v_reg_name_cnt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* an expressionS only has one register type, so we fake it */
end_comment

begin_comment
comment|/* by setting high bits to indicate type */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MASK
value|0xFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* D10V_H */
end_comment

end_unit

