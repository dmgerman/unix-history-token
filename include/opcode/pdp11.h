begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PDP-11 opcde list.    Copyright 2001, 2002 Free Software Foundation, Inc.  This file is part of GDB and GAS.  GDB and GAS are free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB and GAS are distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB or GAS; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * PDP-11 opcode types.  */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_NO_OPS
value|0
end_define

begin_define
define|#
directive|define
name|PDP11_OPCODE_REG
value|1
end_define

begin_comment
comment|/* register */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_OP
value|2
end_define

begin_comment
comment|/* generic operand */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_REG_OP
value|3
end_define

begin_comment
comment|/* register and generic operand */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_REG_OP_REV
value|4
end_define

begin_comment
comment|/* register and generic operand, 					   reversed syntax */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_AC_FOP
value|5
end_define

begin_comment
comment|/* fpu accumulator and generic float 					   operand */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_OP_OP
value|6
end_define

begin_comment
comment|/* two generic operands */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_DISPL
value|7
end_define

begin_comment
comment|/* pc-relative displacement */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_REG_DISPL
value|8
end_define

begin_comment
comment|/* redister and pc-relative 					   displacement */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_IMM8
value|9
end_define

begin_comment
comment|/* 8-bit immediate */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_IMM6
value|10
end_define

begin_comment
comment|/* 6-bit immediate */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_IMM3
value|11
end_define

begin_comment
comment|/* 3-bit immediate */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_ILLEGAL
value|12
end_define

begin_comment
comment|/* illegal instruction */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_FOP_AC
value|13
end_define

begin_comment
comment|/* generic float argument, then fpu 					   accumulator */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_FOP
value|14
end_define

begin_comment
comment|/* generic float operand */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_AC_OP
value|15
end_define

begin_comment
comment|/* fpu accumulator and generic int 					   operand */
end_comment

begin_define
define|#
directive|define
name|PDP11_OPCODE_OP_AC
value|16
end_define

begin_comment
comment|/* generic int argument, then fpu 					   accumulator */
end_comment

begin_comment
comment|/*  * PDP-11 instruction set extensions.  *  * Please keep the numbers low, as they are used as indices into  * an array.  */
end_comment

begin_define
define|#
directive|define
name|PDP11_NONE
value|0
end_define

begin_comment
comment|/* not in instruction set */
end_comment

begin_define
define|#
directive|define
name|PDP11_BASIC
value|1
end_define

begin_comment
comment|/* basic instruction set (11/20 etc) */
end_comment

begin_define
define|#
directive|define
name|PDP11_CSM
value|2
end_define

begin_comment
comment|/* commercial instruction set */
end_comment

begin_define
define|#
directive|define
name|PDP11_CIS
value|3
end_define

begin_comment
comment|/* commercial instruction set */
end_comment

begin_define
define|#
directive|define
name|PDP11_EIS
value|4
end_define

begin_comment
comment|/* extended instruction set (11/45 etc) */
end_comment

begin_define
define|#
directive|define
name|PDP11_FIS
value|5
end_define

begin_comment
comment|/* KEV11 floating-point instructions */
end_comment

begin_define
define|#
directive|define
name|PDP11_FPP
value|6
end_define

begin_comment
comment|/* FP-11 floating-point instructions */
end_comment

begin_define
define|#
directive|define
name|PDP11_LEIS
value|7
end_define

begin_comment
comment|/* limited extended instruction set 				   (11/40 etc) */
end_comment

begin_define
define|#
directive|define
name|PDP11_MFPT
value|8
end_define

begin_comment
comment|/* move from processor type */
end_comment

begin_define
define|#
directive|define
name|PDP11_MPROC
value|9
end_define

begin_comment
comment|/* multiprocessor instructions: tstset, 				   wrtlck */
end_comment

begin_define
define|#
directive|define
name|PDP11_MXPS
value|10
end_define

begin_comment
comment|/* move from/to processor status */
end_comment

begin_define
define|#
directive|define
name|PDP11_SPL
value|11
end_define

begin_comment
comment|/* set priority level */
end_comment

begin_define
define|#
directive|define
name|PDP11_UCODE
value|12
end_define

begin_comment
comment|/* microcode instructions: ldub, med, xfc */
end_comment

begin_define
define|#
directive|define
name|PDP11_EXT_NUM
value|13
end_define

begin_comment
comment|/* total number of extension types */
end_comment

begin_struct
struct|struct
name|pdp11_opcode
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|opcode
decl_stmt|;
name|int
name|mask
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|extension
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|pdp11_opcode
name|pdp11_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|pdp11_opcode
name|pdp11_aliases
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|pdp11_num_opcodes
decl_stmt|,
name|pdp11_num_aliases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of pdp11.h */
end_comment

end_unit

