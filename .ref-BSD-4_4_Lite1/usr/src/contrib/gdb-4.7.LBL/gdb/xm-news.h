begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a Sony/NEWS, for GDB, the GNU debugger.    Copyright 1987, 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* We can't use "isatty" or "fileno" on this machine.  This isn't good,    but it will have to do.  */
end_comment

begin_define
define|#
directive|define
name|ISATTY
parameter_list|(
name|FP
parameter_list|)
value|((FP) == stdin || (FP) == stdout)
end_define

begin_comment
comment|/* THis is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values. */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|UADDR
end_define

begin_comment
comment|/* The offsets in this macro are from /usr/include/machine/reg.h */
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
value|{   static char offsets[] = { \
comment|/*d0-d7:*/
value|1,2,3,4,5,6,7,8, \
comment|/*a0-a6:*/
value|9,10,11,12,13,14,15,
comment|/*sp:*/
value|-4,
comment|/*ps:*/
value|0,
comment|/*pc:*/
value|-1, \
comment|/*fp0-fp7:*/
value|19,22,25,28,31,34,37,40,
comment|/*fpc:*/
value|16,17,18 }; \ 	addr = blockend + 4 * offsets[regno]; \ }
end_define

begin_comment
comment|/* NewsOS 3 apparently dies on large alloca's -- roland@ai.mit.edu.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_escape
end_escape

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* Use GNU assembler instead of standard assembler */
end_comment

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_comment
comment|/* Motorola assembly format */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GAS
end_ifndef

begin_define
define|#
directive|define
name|MOTOROLA
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

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
value|{ asm (".globl end");         \   asm ("move.l $ end, sp");      \   asm ("clr.l fp"); }
end_define

begin_else
else|#
directive|else
end_else

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
value|{ asm (".globl end");         \   asm ("movel $ end, sp");      \   asm ("clrl fp"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("move.l fp, -(sp)");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("movel fp, -(sp)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("move.l (sp), fp");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (sp), fp");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clr.w -(sp)");	      \   asm ("pea (10,sp)");	      \   asm ("movem $ 0xfffe,-(sp)"); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clrw -(sp)");	      \   asm ("pea 10(sp)");	      \   asm ("movem $ 0xfffe,-(sp)"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subi.l $8,28(sp)");     \   asm ("movem (sp),$ 0xffff"); \   asm ("rte"); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subil $8,28(sp)");     \   asm ("movem (sp),$ 0xffff"); \   asm ("rte"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

