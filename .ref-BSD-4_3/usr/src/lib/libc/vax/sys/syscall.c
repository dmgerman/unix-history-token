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
literal|"@(#)syscall.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
name|ENTRY
argument_list|(
argument|syscall
argument_list|)
name|movl
literal|4
operator|(
name|ap
operator|)
operator|,
name|r0
operator|#
name|syscall
name|number
name|subl3
name|$1
operator|,
operator|(
name|ap
operator|)
operator|+
operator|,
operator|(
name|ap
operator|)
operator|#
name|one
name|fewer
name|arguments
name|chmk
name|r0
name|jcs
literal|1f
name|ret
literal|1
operator|:
name|jmp
name|cerror
end_expr_stmt

end_unit

