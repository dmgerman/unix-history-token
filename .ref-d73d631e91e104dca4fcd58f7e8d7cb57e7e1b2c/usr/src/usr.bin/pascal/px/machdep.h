begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.h	5.3 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|pushaddr
parameter_list|(
name|x
parameter_list|)
value|push4((long)(x))
end_define

begin_define
define|#
directive|define
name|popaddr
parameter_list|()
value|(char *)pop4()
end_define

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|pushaddr
parameter_list|(
name|x
parameter_list|)
value|push2((short)(x))
end_define

begin_define
define|#
directive|define
name|popaddr
parameter_list|()
value|(char *)pop2()
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_define
define|#
directive|define
name|popfile
parameter_list|()
value|(FILE *)(popaddr())
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pdp11
argument_list|)
end_if

begin_define
define|#
directive|define
name|popint
value|pop2
end_define

begin_define
define|#
directive|define
name|pushint
value|push2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|popint
value|pop4
end_define

begin_define
define|#
directive|define
name|pushint
value|push4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Machine specific macros for reading quantities from the  * interpreter instruction stream. Operands in the instruction  * stream are aligned to short, but not long boundries. Blockmarks  * are always long aligned. Stack alignment indicates whether the  * stack is short or long aligned. Stack alignment is assumed to  * be no more than long aligned for ADDR32 machines, short aligned  * for ADDR16 machines.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|pdp11
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCLONGVAL
parameter_list|(
name|target
parameter_list|)
value|target = *pc.lp++
end_define

begin_define
define|#
directive|define
name|GETLONGVAL
parameter_list|(
name|target
parameter_list|,
name|srcptr
parameter_list|)
value|target = *(long *)(srcptr)
end_define

begin_define
define|#
directive|define
name|STACKALIGN
parameter_list|(
name|target
parameter_list|,
name|value
parameter_list|)
value|target = ((value) + 1)&~ 1
end_define

begin_endif
endif|#
directive|endif
endif|vax || mc68000 || pdp11
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|PCLONGVAL
parameter_list|(
name|target
parameter_list|)
value|target = *pc.sp++<< 16, target += *pc.usp++
end_define

begin_define
define|#
directive|define
name|GETLONGVAL
parameter_list|(
name|target
parameter_list|,
name|srcptr
parameter_list|)
define|\
value|tsp = (short *)(srcptr), \ 	target = *tsp++<< 16, target += *(unsigned short *)tsp
end_define

begin_define
define|#
directive|define
name|STACKALIGN
parameter_list|(
name|target
parameter_list|,
name|value
parameter_list|)
value|target = ((value) + 3)&~ 3
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_comment
comment|/*  * The following macros implement all accesses to the interpreter stack.  *  * They used to be hard-coded assembler stuff massaged into the compiler  * output by sed scripts, but things are cleaner now.  *  * The STACKSIZE is an arbitrary value.  I picked 100K since it was unlikely  * that anybody's program would run out of stack.  Automatic allocation  * would be nice, maybe procedure call should check for enough space + slop  * and expand it if necessary.  Expanding the stack will require  * pointer relocation if it moves, though.  Probably better would be a  * command line option to set the stack size.  */
end_comment

begin_define
define|#
directive|define
name|STACKSIZE
value|100000
end_define

begin_define
define|#
directive|define
name|setup
parameter_list|()
value|{ \ 	extern char *malloc(); \ 	stack.cp = STACKSIZE + malloc((unsigned)STACKSIZE); \ 	}
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|tahoe
end_ifndef

begin_define
define|#
directive|define
name|push2
parameter_list|(
name|x
parameter_list|)
value|(*--stack.sp) = (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|push2
parameter_list|(
name|x
parameter_list|)
value|(*--stack.lp) = (x)<< 16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|push4
parameter_list|(
name|x
parameter_list|)
value|(*--stack.lp)  = (x)
end_define

begin_define
define|#
directive|define
name|push8
parameter_list|(
name|x
parameter_list|)
value|(*--stack.dbp) = (x)
end_define

begin_define
define|#
directive|define
name|pushsze8
parameter_list|(
name|x
parameter_list|)
value|(*--stack.s8p) = (x)
end_define

begin_define
define|#
directive|define
name|pushsp
parameter_list|(
name|x
parameter_list|)
value|(stack.cp -= (x))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|tahoe
end_ifndef

begin_define
define|#
directive|define
name|pop2
parameter_list|()
value|(*stack.sp++)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pop2
parameter_list|()
value|(*stack.lp++)>> 16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pop4
parameter_list|()
value|(*stack.lp++)
end_define

begin_define
define|#
directive|define
name|pop8
parameter_list|()
value|(*stack.dbp++)
end_define

begin_define
define|#
directive|define
name|popsze8
parameter_list|()
value|(*stack.s8p++)
end_define

begin_define
define|#
directive|define
name|popsp
parameter_list|(
name|x
parameter_list|)
value|(void)(stack.cp += (x))
end_define

begin_define
define|#
directive|define
name|enableovrflo
parameter_list|()
end_define

begin_comment
comment|/*nop*/
end_comment

begin_define
define|#
directive|define
name|disableovrflo
parameter_list|()
end_define

begin_comment
comment|/*nop*/
end_comment

end_unit

