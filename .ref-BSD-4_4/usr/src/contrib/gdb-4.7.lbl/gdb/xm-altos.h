begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an Altos 3068 (m68k running SVR2)    Copyright (C) 1987,1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* The altos support would make a good base for a port to other USGR2 systems    (like the 3b1 and the Convergent miniframe).  */
end_comment

begin_comment
comment|/* This is only needed in one file, but it's cleaner to put it here than    putting in more #ifdef's.  */
end_comment

begin_include
include|#
directive|include
file|<sys/page.h>
end_include

begin_include
include|#
directive|include
file|<sys/net.h>
end_include

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_define
define|#
directive|define
name|CBREAK
value|XTABS
end_define

begin_comment
comment|/* It takes all kinds... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get sys/wait.h ie. from a Sun and edit it a little (mc68000 to m68k) */
end_comment

begin_comment
comment|/* Why bother?  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values. */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x1fbf000
end_define

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
value|{	if (regno<= SP_REGNUM) \ 	  addr = blockend + regno * 4; \ 	else if (regno == PS_REGNUM) \ 	  addr = blockend + regno * 4 + 4; \ 	else if (regno == PC_REGNUM) \ 	  addr = blockend + regno * 4 + 2; \ }
end_define

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
value|(((regno)< PS_REGNUM)						\    ? (&((struct exception_stack *) (u_ar0))->e_regs[(regno + R0)])	\    : (((regno) == PS_REGNUM)						\       ? ((int *) (&((struct exception_stack *) (u_ar0))->e_PS))		\       : (&((struct exception_stack *) (u_ar0))->e_PC)))
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_undef
undef|#
directive|undef
name|USE_GAS
end_undef

begin_define
define|#
directive|define
name|ALTOS_AS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Motorola assembly format */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USE_GAS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ALTOS
argument_list|)
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_AS
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
value|{ asm ("global end");         \   asm ("mov.l&end,%sp");      \   asm ("clr.l %fp"); }
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

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_AS
end_ifdef

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("mov.l %fp, -(%sp)");
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

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_AS
end_ifdef

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("mov.l (%sp), %fp");
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

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_AS
end_ifdef

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clr.w -(%sp)");	      \   asm ("pea (10,%sp)");	      \   asm ("movm.l&0xfffe,-(%sp)"); }
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

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_AS
end_ifdef

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("sub.l&8,28(%sp)");     \   asm ("movem (%sp),&0xffff"); \   asm ("rte"); }
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

