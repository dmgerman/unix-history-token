begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Sequent Symmetry under dynix 3.0,    with Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Symmetry version by Jay Vosburgh (uunet!sequent!fubar) */
end_comment

begin_comment
comment|/* This machine doesn't have the siginterrupt call.  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_comment
comment|/* XPT_DEBUG doesn't work yet under Dynix 3.0.12, but UNDEBUG does... */
end_comment

begin_comment
comment|/* #define PTRACE_ATTACH XPT_DEBUG #define PTRACE_DETACH XPT_UNDEBUG #define ATTACH_DETACH  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
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
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* The magic numbers below are offsets into u_ar0 in the user struct.    They live in<machine/reg.h>.  Gdb calls this macro with blockend    holding u.u_ar0 - KERNEL_U_ADDR.  Only the registers listed are    saved in the u area (along with a few others that aren't useful    here.  See<machine/reg.h>).  */
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
value|{ struct user foo;
comment|/* needed for finding fpu regs */
value|\ switch (regno) { \     case 0: \       addr = blockend + EAX * sizeof(int); break; \   case 1: \       addr = blockend + EDX * sizeof(int); break; \   case 2: \       addr = blockend + ECX * sizeof(int); break; \   case 3:
comment|/* st(0) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[0][0] - (int)&foo); \       break; \   case 4:
comment|/* st(1) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[1][0] - (int)&foo); \       break; \   case 5: \       addr = blockend + EBX * sizeof(int); break; \   case 6: \       addr = blockend + ESI * sizeof(int); break; \   case 7: \       addr = blockend + EDI * sizeof(int); break; \   case 8:
comment|/* st(2) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[2][0] - (int)&foo); \       break; \   case 9:
comment|/* st(3) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[3][0] - (int)&foo); \       break; \   case 10:
comment|/* st(4) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[4][0] - (int)&foo); \       break; \   case 11:
comment|/* st(5) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[5][0] - (int)&foo); \       break; \   case 12:
comment|/* st(6) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[6][0] - (int)&foo); \       break; \   case 13:
comment|/* st(7) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[7][0] - (int)&foo); \       break; \   case 14: \       addr = blockend + ESP * sizeof(int); break; \   case 15: \       addr = blockend + EBP * sizeof(int); break; \   case 16: \       addr = blockend + EIP * sizeof(int); break; \   case 17: \       addr = blockend + FLAGS * sizeof(int); break; \   case 18:
comment|/* fp1 */
value|\   case 19:
comment|/* fp2 */
value|\   case 20:
comment|/* fp3 */
value|\   case 21:
comment|/* fp4 */
value|\   case 22:
comment|/* fp5 */
value|\   case 23:
comment|/* fp6 */
value|\   case 24:
comment|/* fp7 */
value|\   case 25:
comment|/* fp8 */
value|\   case 26:
comment|/* fp9 */
value|\   case 27:
comment|/* fp10 */
value|\   case 28:
comment|/* fp11 */
value|\   case 29:
comment|/* fp12 */
value|\   case 30:
comment|/* fp13 */
value|\   case 31:
comment|/* fp14 */
value|\   case 32:
comment|/* fp15 */
value|\   case 33:
comment|/* fp16 */
value|\   case 34:
comment|/* fp17 */
value|\   case 35:
comment|/* fp18 */
value|\   case 36:
comment|/* fp19 */
value|\   case 37:
comment|/* fp20 */
value|\   case 38:
comment|/* fp21 */
value|\   case 39:
comment|/* fp22 */
value|\   case 40:
comment|/* fp23 */
value|\   case 41:
comment|/* fp24 */
value|\   case 42:
comment|/* fp25 */
value|\   case 43:
comment|/* fp26 */
value|\   case 44:
comment|/* fp27 */
value|\   case 45:
comment|/* fp28 */
value|\   case 46:
comment|/* fp29 */
value|\   case 47:
comment|/* fp30 */
value|\   case 48:
comment|/* fp31 */
value|\      addr = blockend - \ 	 ((int)&foo.u_fpasave.fpa_regs[(regno)-18] - (int)&foo); \   } \ }
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* We must fetch all the regs before storing, since we store all at once.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_escape
end_escape

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* This doesn't work... */
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
value|{ 0, SIGKILL, SIGSEGV, 0, 0, 0, 0, 0, \   0, 0, SIGTRAP, SIGTRAP, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0}
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
value|{ asm (".globl end");         \   asm ("movl $ end, %esp");      \   asm ("movl %ebp, $0"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("pushl %ebp");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (%esp), %ebp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm("pushad"); }
end_define

begin_comment
comment|/* { asm("pushl %eax"); \   asm("pushl %edx"); \   asm("pushl %ecx"); \   asm("pushl %st(0)"); \   asm("pushl %st(1)"); \   asm("pushl %ebx"); \   asm("pushl %esi"); \   asm("pushl %edi"); \   asm("pushl %st(2)"); \   asm("pushl %st(3)"); \   asm("pushl %st(4)"); \   asm("pushl %st(5)"); \   asm("pushl %st(6)"); \   asm("pushl %st(7)"); \   asm("pushl %esp"); \   asm("pushl %ebp"); \   asm("pushl %eip"); \   asm("pushl %eflags"); \   asm("pushl %fp1"); \   asm("pushl %fp2"); \   asm("pushl %fp3"); \   asm("pushl %fp4"); \   asm("pushl %fp5"); \   asm("pushl %fp6"); \   asm("pushl %fp7"); \   asm("pushl %fp8"); \    asm("pushl %fp9"); \   asm("pushl %fp10"); \   asm("pushl %fp11"); \   asm("pushl %fp12"); \   asm("pushl %fp13"); \   asm("pushl %fp14"); \   asm("pushl %fp15"); \   asm("pushl %fp16"); \   asm("pushl %fp17"); \   asm("pushl %fp18"); \   asm("pushl %fp19"); \   asm("pushl %fp20"); \   asm("pushl %fp21"); \   asm("pushl %fp22"); \    asm("pushl %fp23"); \   asm("pushl %fp24"); \   asm("pushl %fp25"); \   asm("pushl %fp26"); \   asm("pushl %fp27"); \   asm("pushl %fp28"); \   asm("pushl %fp29"); \   asm("pushl %fp30"); \   asm("pushl %fp31"); \ } */
end_comment

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("popad"); }
end_define

end_unit

