begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for hosting on a Hewlett-Packard 9000/300, running bsd.    Copyright 1986, 1987, 1989, 1991, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Configuration file for HP9000/300 series machine running  * University of Utah's 4.3bsd port.  This is NOT for HP-UX.  * Problems to hpbsd-bugs@cs.utah.edu  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Avoid "INT_MIN redefined" warnings -- by defining it here, exactly    the same as in the system<machine/machtypes.h> file.  */
end_comment

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_define
define|#
directive|define
name|INT_MIN
value|0x80000000
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
comment|/* Get kernel u area address at run-time using BSD style nlist ().  */
end_comment

begin_comment
comment|/* #define KERNEL_U_ADDR_BSD */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|USRSTACK
end_define

begin_comment
comment|/* This is a piece of magic that is given a register number REGNO    and as BLOCKEND the address in the system of the end of the user structure    and stores in ADDR the address in the kernel or core dump    of that register.  */
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
value|{									\   if (regno< PS_REGNUM)						\     addr = (int)&((struct frame *)(blockend))->f_regs[regno];		\   else if (regno == PS_REGNUM)						\     addr = (int)&((struct frame *)(blockend))->f_stackadj;		\   else if (regno == PC_REGNUM)						\     addr = (int)&((struct frame *)(blockend))->f_pc;			\   else if (regno< FPC_REGNUM)						\     addr = (int)							\&((struct user *)0)->u_pcb.pcb_fpregs.fpf_regs[((regno)-FP0_REGNUM)*3];\   else if (regno == FPC_REGNUM)						\     addr = (int)&((struct user *)0)->u_pcb.pcb_fpregs.fpf_fpcr;	\   else if (regno == FPS_REGNUM)						\     addr = (int)&((struct user *)0)->u_pcb.pcb_fpregs.fpf_fpsr;	\   else									\     addr = (int)&((struct user *)0)->u_pcb.pcb_fpregs.fpf_fpiar;	\ }
end_define

begin_comment
comment|/* Kernel is a bit tenacious about sharing text segments, disallowing bpts.  */
end_comment

begin_define
define|#
directive|define
name|ONE_PROCESS_WRITETEXT
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
value|{ asm (".globl end");         \   asm ("movel #end, sp");      \   asm ("movel #0,a6"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("movel a6,sp@-");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl sp@,a6");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clrw -(sp)");	      \   asm ("pea sp@(10)");	      \   asm ("movem #0xfffe,sp@-"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subil #8,sp@(28)");     \   asm ("movem sp@,#0xffff"); \   asm ("rte"); }
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PSIGNAL_IN_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|char*
end_define

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

end_unit

