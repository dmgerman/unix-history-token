begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_label
name|_sccsid
label|:
end_label

begin_expr_stmt
operator|.
name|asciz
literal|"11/19/91       ULTRIX  @(#)adjtime.c   6.1"
endif|#
directive|endif
endif|not lint
include|#
directive|include
file|"SYS.h"
name|SYSCALL
argument_list|(
argument|adjtimex
argument_list|)
name|ret
end_expr_stmt

end_unit

