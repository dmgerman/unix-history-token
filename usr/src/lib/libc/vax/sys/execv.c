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
literal|"@(#)execv.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
name|ENTRY
argument_list|(
name|execv
argument_list|)
operator|.
name|globl
name|_environ
name|pushl
name|_environ
name|pushl
literal|8
operator|(
name|ap
operator|)
name|pushl
literal|4
operator|(
name|ap
operator|)
name|calls
name|$3
operator|,
name|_execve
name|ret
operator|#
name|execv
argument_list|(
argument|file
argument_list|,
argument|argv
argument_list|)
end_expr_stmt

end_unit

