begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLIBC_SCCS
end_ifdef

begin_label
name|_sccsid
label|:
end_label

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)sigreturn.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
comment|/*  * We must preserve the state of the registers as the user has set them up.  */
ifdef|#
directive|ifdef
name|PROF
undef|#
directive|undef
name|ENTRY
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl _
comment|/**/
value|x; .align 2; _
comment|/**/
value|x: .word 0; pushr $0x3f; \ 	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount; popr $0x3f
endif|#
directive|endif
endif|PROF
name|SYSCALL
argument_list|(
argument|sigreturn
argument_list|)
name|ret
end_expr_stmt

end_unit

