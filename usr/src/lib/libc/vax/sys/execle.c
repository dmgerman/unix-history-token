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
literal|"@(#)execle.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
name|ENTRY
argument_list|(
argument|execle
argument_list|)
name|movl
argument_list|(
name|ap
argument_list|)
operator|,
name|r0
name|pushl
argument_list|(
name|ap
argument_list|)
index|[
name|r0
index|]
name|pushab
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
name|execle
argument_list|(
name|file
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
operator|...
argument_list|,
name|env
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

