begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vax-inst.h - GNU - Part of vax.c    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This is part of vax-ins-parse.c& friends.  * We want to parse a vax instruction text into a tree defined here.  */
end_comment

begin_define
define|#
directive|define
name|VIT_MAX_OPERANDS
value|(6)
end_define

begin_comment
comment|/* maximum number of operands in one       */
end_comment

begin_comment
comment|/* single vax instruction */
end_comment

begin_struct
struct|struct
name|vop
comment|/* vax instruction operand                 */
block|{
name|short
name|int
name|vop_ndx
decl_stmt|;
comment|/* -1, or index register. eg 7=[R7]	   */
name|short
name|int
name|vop_reg
decl_stmt|;
comment|/* -1, or register number. eg @I^#=0xF     */
comment|/* Helps distinguish "abs" from "abs(PC)". */
name|short
name|int
name|vop_mode
decl_stmt|;
comment|/* addressing mode 4 bits. eg I^#=0x9	   */
name|char
name|vop_short
decl_stmt|;
comment|/* operand displacement length as written  */
comment|/* ' '=none, "bilsw"=B^I^L^S^W^.           */
name|char
name|vop_access
decl_stmt|;
comment|/* 'b'branch ' 'no-instruction 'amrvw'norm */
name|char
name|vop_width
decl_stmt|;
comment|/* Operand width, one of "bdfghloqw"	   */
name|char
modifier|*
name|vop_warn
decl_stmt|;
comment|/* warning message of this operand, if any */
name|char
modifier|*
name|vop_error
decl_stmt|;
comment|/* say if operand is inappropriate         */
name|char
modifier|*
name|vop_expr_begin
decl_stmt|;
comment|/* Unparsed expression, 1st char ...	   */
name|char
modifier|*
name|vop_expr_end
decl_stmt|;
comment|/* ... last char.			   */
name|unsigned
name|char
name|vop_nbytes
decl_stmt|;
comment|/* number of bytes in datum		   */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|long
name|vax_opcodeT
typedef|;
end_typedef

begin_comment
comment|/* For initialising array of opcodes	   */
end_comment

begin_comment
comment|/* Some synthetic opcodes> 16 bits!       */
end_comment

begin_define
define|#
directive|define
name|VIT_OPCODE_SYNTHETIC
value|0x80000000
end_define

begin_comment
comment|/* Not real hardware instruction.  */
end_comment

begin_define
define|#
directive|define
name|VIT_OPCODE_SPECIAL
value|0x40000000
end_define

begin_comment
comment|/* Not normal branch optimising.   */
end_comment

begin_comment
comment|/* Never set without ..._SYNTHETIC */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDTH_UNCONDITIONAL_JUMP
value|'-'
end_define

begin_comment
comment|/* These are encoded into         */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDTH_CONDITIONAL_JUMP
value|'?'
end_define

begin_comment
comment|/* vop_width when vop_access == 'b' */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDTH_WORD_JUMP
value|'!'
end_define

begin_comment
comment|/* and VIT_OPCODE_SYNTHETIC set.  */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDTH_BYTE_JUMP
value|':'
end_define

begin_comment
comment|/*                                */
end_comment

begin_define
define|#
directive|define
name|VAX_JMP
value|(0x17)
end_define

begin_comment
comment|/* Useful for branch optimising. Jump instr*/
end_comment

begin_define
define|#
directive|define
name|VAX_PC_RELATIVE_MODE
value|(0xef)
end_define

begin_comment
comment|/* Use it after VAX_JMP		   */
end_comment

begin_define
define|#
directive|define
name|VAX_ABSOLUTE_MODE
value|(0x9F)
end_define

begin_comment
comment|/* Use as @#...			   */
end_comment

begin_define
define|#
directive|define
name|VAX_BRB
value|(0x11)
end_define

begin_comment
comment|/* Canonical branch.			   */
end_comment

begin_define
define|#
directive|define
name|VAX_BRW
value|(0x31)
end_define

begin_comment
comment|/* Another canonical branch		   */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDEN_WORD
value|(0x20)
end_define

begin_comment
comment|/* Add this to byte branch to get word br. */
end_comment

begin_define
define|#
directive|define
name|VAX_WIDEN_LONG
value|(0x6)
end_define

begin_comment
comment|/* Add this to byte branch to get long jmp.*/
end_comment

begin_comment
comment|/* Needs VAX_PC_RELATIVE_MODE byte after it*/
end_comment

begin_struct
struct|struct
name|vit
comment|/* vax instruction tree                    */
block|{
comment|/* vit_opcode is char[] for portability.   */
name|char
name|vit_opcode
index|[
sizeof|sizeof
argument_list|(
name|vax_opcodeT
argument_list|)
index|]
decl_stmt|;
name|unsigned
name|char
name|vit_opcode_nbytes
decl_stmt|;
comment|/* How long is _opcode? (chars)	   */
name|unsigned
name|char
name|vit_operands
decl_stmt|;
comment|/*					   */
name|struct
name|vop
name|vit_operand
index|[
name|VIT_MAX_OPERANDS
index|]
decl_stmt|;
comment|/* operands             */
name|char
modifier|*
name|vit_error
decl_stmt|;
comment|/* "" or error text */
block|}
struct|;
end_struct

begin_comment
comment|/* end of vax-inst.h */
end_comment

end_unit

