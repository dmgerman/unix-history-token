begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)fork.c	8.1 (Berkeley) %G%"
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|"SYS.h"
operator|.
name|globl
name|mypid
operator|,
name|myppid
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
name|movl
name|r0
operator|,
name|myppid
name|clrl
name|mypid
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

