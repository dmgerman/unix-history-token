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
literal|"@(#)getppid.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
include|#
directive|include
file|"SYS.h"
name|PSEUDO
argument_list|(
argument|getppid
argument_list|,
argument|getpid
argument_list|)
name|movl
name|r1
operator|,
name|r0
name|ret
operator|#
name|ppid
operator|=
name|getppid
argument_list|()
expr_stmt|;
end_expr_stmt

end_unit

