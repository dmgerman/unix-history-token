begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _ ## x; .even; _ ## x:; .data; PROF ## x:; \ 			.long 0; .text; link a6,\#0; lea PROF ## x,a0; \ 			jbsr mcount; unlk a6
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _ ## x; .even; _ ## x:; .data; PROF ## x:; \ 			.long 0; .text; link a6,#0; lea PROF ## x,a0; \ 			jbsr mcount; unlk a6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _ ## x; .even; _ ## x:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|movl \#SYS_ ## x,d0; trap \#0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|movl #SYS_ ## x,d0; trap #0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:; .data; PROF
comment|/**/
value|x:; \ 			.long 0; .text; link a6,#0; lea PROF
comment|/**/
value|x,a0; \ 			jbsr mcount; unlk a6
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSTRAP
parameter_list|(
name|x
parameter_list|)
value|movl #SYS_
comment|/**/
value|x,d0; trap #0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
value|.even; err: jmp cerror; ENTRY(x); SYSTRAP(x); jcs err
end_define

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
value|SYSCALL(x); rts
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|ENTRY(x); SYSTRAP(y); rts
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

begin_expr_stmt
operator|.
name|globl
name|cerror
end_expr_stmt

end_unit

