begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LIBC_SCCS
end_ifdef

begin_label
name|_sccsid
label|:
end_label

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)ntohl.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|LIBC_SCCS
comment|/* hostorder = ntohl(netorder) */
include|#
directive|include
file|"DEFS.h"
name|ENTRY
argument_list|(
argument|ntohl
argument_list|)
name|rotl
name|$
operator|-
literal|8
operator|,
literal|4
operator|(
name|ap
operator|)
operator|,
name|r0
name|insv
name|r0
operator|,
name|$16
operator|,
name|$8
operator|,
name|r0
name|movb
literal|7
operator|(
name|ap
operator|)
operator|,
name|r0
name|ret
end_expr_stmt

end_unit

