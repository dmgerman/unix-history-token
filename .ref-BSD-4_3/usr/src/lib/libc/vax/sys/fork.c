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
literal|"@(#)fork.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
name|SYSCALL
argument_list|(
argument|fork
argument_list|)
name|jlbc
name|r1
operator|,
literal|1f
operator|#
name|parent
operator|,
name|since
name|r1
operator|==
literal|0
name|in
name|parent
operator|,
literal|1
name|in
name|child
name|clrl
name|r0
literal|1
operator|:
name|ret
operator|#
name|pid
operator|=
name|fork
argument_list|()
end_expr_stmt

end_unit

