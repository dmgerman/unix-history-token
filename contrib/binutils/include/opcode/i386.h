begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opcode/i386.h -- Intel 80386 opcode macros    Copyright 1989, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler, and GDB, the GNU Debugger.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* The SystemV/386 SVR3.2 assembler, and probably all AT&T derived    ix86 Unix assemblers, generate floating point instructions with    reversed source and destination registers in certain cases.    Unfortunately, gcc and possibly many other programs use this    reversed syntax, so we're stuck with it.     eg. `fsub %st(3),%st' results in st = st - st(3) as expected, but    `fsub %st,%st(3)' results in st(3) = st - st(3), rather than    the expected st(3) = st(3) - st     This happens with all the non-commutative arithmetic floating point    operations with two register operands, where the source register is    %st, and destination register is %st(i).     The affected opcode map is dceX, dcfX, deeX, defX.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV386_COMPAT
end_ifndef

begin_comment
comment|/* Set non-zero for broken, compatible instructions.  Set to zero for    non-broken opcodes at your peril.  gcc generates SystemV/386    compatible instructions.  */
end_comment

begin_define
define|#
directive|define
name|SYSV386_COMPAT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OLDGCC_COMPAT
end_ifndef

begin_comment
comment|/* Set non-zero to cater for old (<= 2.8.1) versions of gcc that could    generate nonsense fsubp, fsubrp, fdivp and fdivrp with operands    reversed.  */
end_comment

begin_define
define|#
directive|define
name|OLDGCC_COMPAT
value|SYSV386_COMPAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MOV_AX_DISP32
value|0xa0
end_define

begin_define
define|#
directive|define
name|POP_SEG_SHORT
value|0x07
end_define

begin_define
define|#
directive|define
name|JUMP_PC_RELATIVE
value|0xeb
end_define

begin_define
define|#
directive|define
name|INT_OPCODE
value|0xcd
end_define

begin_define
define|#
directive|define
name|INT3_OPCODE
value|0xcc
end_define

begin_comment
comment|/* The opcode for the fwait instruction, which disassembler treats as a    prefix when it can.  */
end_comment

begin_define
define|#
directive|define
name|FWAIT_OPCODE
value|0x9b
end_define

begin_define
define|#
directive|define
name|ADDR_PREFIX_OPCODE
value|0x67
end_define

begin_define
define|#
directive|define
name|DATA_PREFIX_OPCODE
value|0x66
end_define

begin_define
define|#
directive|define
name|LOCK_PREFIX_OPCODE
value|0xf0
end_define

begin_define
define|#
directive|define
name|CS_PREFIX_OPCODE
value|0x2e
end_define

begin_define
define|#
directive|define
name|DS_PREFIX_OPCODE
value|0x3e
end_define

begin_define
define|#
directive|define
name|ES_PREFIX_OPCODE
value|0x26
end_define

begin_define
define|#
directive|define
name|FS_PREFIX_OPCODE
value|0x64
end_define

begin_define
define|#
directive|define
name|GS_PREFIX_OPCODE
value|0x65
end_define

begin_define
define|#
directive|define
name|SS_PREFIX_OPCODE
value|0x36
end_define

begin_define
define|#
directive|define
name|REPNE_PREFIX_OPCODE
value|0xf2
end_define

begin_define
define|#
directive|define
name|REPE_PREFIX_OPCODE
value|0xf3
end_define

begin_define
define|#
directive|define
name|TWO_BYTE_OPCODE_ESCAPE
value|0x0f
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE
value|(char) 0x90
end_define

begin_comment
comment|/* register numbers */
end_comment

begin_define
define|#
directive|define
name|EBP_REG_NUM
value|5
end_define

begin_define
define|#
directive|define
name|ESP_REG_NUM
value|4
end_define

begin_comment
comment|/* modrm_byte.regmem for twobyte escape */
end_comment

begin_define
define|#
directive|define
name|ESCAPE_TO_TWO_BYTE_ADDRESSING
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.index for no index register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_INDEX_REGISTER
value|ESP_REG_NUM
end_define

begin_comment
comment|/* index_base_byte.base for no base register addressing */
end_comment

begin_define
define|#
directive|define
name|NO_BASE_REGISTER
value|EBP_REG_NUM
end_define

begin_define
define|#
directive|define
name|NO_BASE_REGISTER_16
value|6
end_define

begin_comment
comment|/* modrm.mode = REGMEM_FIELD_HAS_REG when a register is in there */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_REG
value|0x3
end_define

begin_comment
comment|/* always = 0x3 */
end_comment

begin_define
define|#
directive|define
name|REGMEM_FIELD_HAS_MEM
value|(~REGMEM_FIELD_HAS_REG)
end_define

begin_comment
comment|/* x86-64 extension prefix.  */
end_comment

begin_define
define|#
directive|define
name|REX_OPCODE
value|0x40
end_define

begin_comment
comment|/* Indicates 64 bit operand size.  */
end_comment

begin_define
define|#
directive|define
name|REX_W
value|8
end_define

begin_comment
comment|/* High extension to reg field of modrm byte.  */
end_comment

begin_define
define|#
directive|define
name|REX_R
value|4
end_define

begin_comment
comment|/* High extension to SIB index field.  */
end_comment

begin_define
define|#
directive|define
name|REX_X
value|2
end_define

begin_comment
comment|/* High extension to base field of modrm or SIB, or reg field of opcode.  */
end_comment

begin_define
define|#
directive|define
name|REX_B
value|1
end_define

begin_comment
comment|/* max operands per insn */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|4
end_define

begin_comment
comment|/* max immediates per insn (lcall, ljmp, insertq, extrq) */
end_comment

begin_define
define|#
directive|define
name|MAX_IMMEDIATE_OPERANDS
value|2
end_define

begin_comment
comment|/* max memory refs per insn (string ops) */
end_comment

begin_define
define|#
directive|define
name|MAX_MEMORY_OPERANDS
value|2
end_define

begin_comment
comment|/* max size of insn mnemonics.  */
end_comment

begin_define
define|#
directive|define
name|MAX_MNEM_SIZE
value|16
end_define

begin_comment
comment|/* max size of register name in insn mnemonics.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REG_NAME_SIZE
value|8
end_define

end_unit

