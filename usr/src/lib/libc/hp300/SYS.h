begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_comment
comment|/* vax/tahoe compat */
end_comment

begin_define
define|#
directive|define
name|ret
value|rts
end_define

begin_define
define|#
directive|define
name|r0
value|d0
end_define

begin_define
define|#
directive|define
name|r1
value|d1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
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
value|x:; .data; PROF
comment|/**/
value|x:; \ 			.long 0; .text; lea PROF
comment|/**/
value|x,a0; jbsr mcount
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
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:
end_define

begin_endif
endif|#
directive|endif
endif|PROF
end_endif

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
value|err: jmp cerror; ENTRY(x); movl #SYS_
comment|/**/
value|x,d0; \ 			trap #0; jcs err
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
value|ENTRY(x); movl #SYS_
comment|/**/
value|y,d0; trap #0;
end_define

begin_expr_stmt
operator|.
name|globl
name|cerror
end_expr_stmt

end_unit

