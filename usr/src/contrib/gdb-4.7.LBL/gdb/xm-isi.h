begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an ISI Optimum V (3.05) under 4.3bsd.    Copyright 1987, 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* This has not been tested on ISI's running BSD 4.2, but it will probably    work.  */
end_comment

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_comment
comment|/*#define KERNEL_U_ADDR 0x10800000*/
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0
end_define

begin_comment
comment|/* expects blockend to be u.u_ar0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rloc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in isi-dep.c */
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|{       blockend&= UPAGES*NBPG - 1;                            \ 	if (regno< 18) addr = (int)blockend + rloc[regno]*4;  	\         else if (regno< 26) addr = (int)&((struct user *)0)->u_68881_regs \             + (regno - 18) * 12;                                \         else if (regno< 29) addr = (int)&((struct user *)0)->u_68881_regs \             + 8 * 12 + (regno - 26) * 4;                        \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* Map machine fault codes into signal numbers.    First subtract 0, divide by 4, then index in a table.    Faults for which the entry in this table is 0    are not handled by KDB; the program's own trap handler    gets to handle then.  */
end_comment

begin_define
define|#
directive|define
name|FAULT_CODE_ORIGIN
value|0
end_define

begin_define
define|#
directive|define
name|FAULT_CODE_UNITS
value|4
end_define

begin_define
define|#
directive|define
name|FAULT_TABLE
define|\
value|{ 0, 0, 0, 0, SIGTRAP, 0, 0, 0, \   0, SIGTRAP, 0, 0, 0, 0, 0, SIGKILL, \   0, 0, 0, 0, 0, 0, 0, 0, \   SIGILL }
end_define

begin_comment
comment|/* Start running with a stack stretching from BEG to END.    BEG and END should be symbols meaningful to the assembler.    This is used only for kdb.  */
end_comment

begin_define
define|#
directive|define
name|INIT_STACK
parameter_list|(
name|beg
parameter_list|,
name|end
parameter_list|)
define|\
value|{ asm (".globl end");         \   asm ("movl $ end, sp");      \   asm ("clrl fp"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("movel fp, -(sp)");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (sp), fp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clrw -(sp)");	      \   asm ("pea 10(sp)");	      \   asm ("movem $ 0xfffe,-(sp)"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subil $8,28(sp)");     \   asm ("movem (sp),$ 0xffff"); \   asm ("rte"); }
end_define

end_unit

