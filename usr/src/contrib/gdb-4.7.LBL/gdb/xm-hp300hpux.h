begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on an HP 9000 model 320, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* HP/UX is USG, but it does have<ptrace.h>  */
end_comment

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Define this to indicate problems with traps after continuing.  */
end_comment

begin_define
define|#
directive|define
name|HP_OS_BUG
end_define

begin_comment
comment|/* fetch_inferior_registers is in hp300hpux-dep.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Set flag to indicate whether HP's assembler is in use. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__HPUX_ASM__
end_ifdef

begin_define
define|#
directive|define
name|HPUX_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not GNU C.  */
end_comment

begin_define
define|#
directive|define
name|HPUX_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GNU C.  */
end_comment

begin_comment
comment|/* Define this for versions of hp-ux older than 6.0 */
end_comment

begin_comment
comment|/* #define HPUX_VERSION_5 */
end_comment

begin_comment
comment|/* define USG if you are using sys5 /usr/include's */
end_comment

begin_undef
undef|#
directive|undef
name|USG
end_undef

begin_comment
comment|/* In case it was defined in the Makefile for cplus-dem.c */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* The mem functions are in<string.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|MEM_FNS_DECLARED
end_undef

begin_define
define|#
directive|define
name|MEM_FNS_DECLARED
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_comment
comment|/* The hp9k320.h doesn't seem to have this feature.  */
end_comment

begin_comment
comment|/* #define SET_STACK_LIMIT_HUGE */
end_comment

begin_comment
comment|/* So we'll just have to avoid big alloca's.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_VERSION_5
end_ifdef

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x00979000
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not HPUX version 5.  */
end_comment

begin_comment
comment|/* Use HPUX-style nlist() to get kernel_u_addr.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR_HPUX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not HPUX version 5.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_ADDR
parameter_list|(
name|u_ar0
parameter_list|,
name|regno
parameter_list|)
define|\
value|(unsigned int)							\   (((regno)< PS_REGNUM)						\    ? (&((struct exception_stack *) (u_ar0))->e_regs[(regno + R0)])	\    : (((regno) == PS_REGNUM)						\       ? ((int *) (&((struct exception_stack *) (u_ar0))->e_PS))		\       : (&((struct exception_stack *) (u_ar0))->e_PC)))
end_define

begin_define
define|#
directive|define
name|FP_REGISTER_ADDR
parameter_list|(
name|u
parameter_list|,
name|regno
parameter_list|)
define|\
value|(((char *)								\     (((regno)< FPC_REGNUM)						\      ? (&u.u_pcb.pcb_mc68881[FMC68881_R0 + (((regno) - FP0_REGNUM) * 3)]) \      : (&u.u_pcb.pcb_mc68881[FMC68881_C + ((regno) - FPC_REGNUM)])))	\    - ((char *) (& u)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Do implement the attach and detach commands.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
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

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX_ASM
end_ifndef

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
value|{ asm (".globl end");         \   asm ("movel $ end, sp");      \   asm ("clrl fp"); }
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HPUX_ASM */
end_comment

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
value|{ asm ("global end");							\   asm ("mov.l&end,%sp");						\   asm ("clr.l %a6"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("mov.l %fp,-(%sp)");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("mov.l (%sp),%fp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clr.w -(%sp)");							\   asm ("pea 10(%sp)");							\   asm ("movm.l&0xfffe,-(%sp)"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subi.l&8,28(%sp)");						\   asm ("mov.m (%sp),&0xffff");						\   asm ("rte"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX_ASM */
end_comment

end_unit

