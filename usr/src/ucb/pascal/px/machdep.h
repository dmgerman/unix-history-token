begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.h	5.2 (Berkeley) 11/12/86  */
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
value|push4
end_define

begin_define
define|#
directive|define
name|popaddr
value|(char *)pop4
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
value|push2
end_define

begin_define
define|#
directive|define
name|popaddr
value|(char *)pop2
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
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

end_unit

