begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	5.6 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

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
value|x; .align 2; _
comment|/**/
value|x: .word 0; \ 			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
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
value|x; .align 2; _
comment|/**/
value|x: .word 0
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
value|err: jmp cerror; ENTRY(x); chmk $SYS_
comment|/**/
value|x; jcs err
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
value|ENTRY(x); chmk $SYS_
comment|/**/
value|y
end_define

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|calls $x, _
comment|/**/
value|y
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

