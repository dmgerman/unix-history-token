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
literal|"@(#)htons.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|LIBC_SCCS
comment|/* hostorder = htons(netorder) */
include|#
directive|include
file|"DEFS.h"
name|ENTRY
argument_list|(
argument|htons
argument_list|)
name|rotl
name|$8
operator|,
literal|4
operator|(
name|ap
operator|)
operator|,
name|r0
name|movb
literal|5
operator|(
name|ap
operator|)
operator|,
name|r0
name|movzwl
name|r0
operator|,
name|r0
name|ret
end_expr_stmt

end_unit

