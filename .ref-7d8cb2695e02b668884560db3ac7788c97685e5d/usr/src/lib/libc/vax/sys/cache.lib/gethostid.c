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
literal|"@(#)gethostid.c	8.1 (Berkeley) %G%"
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|"SYS.h"
operator|.
name|data
name|hostid
operator|:
operator|.
name|long
literal|0
operator|.
name|text
name|ENTRY
argument_list|(
argument|gethostid
argument_list|)
name|movl
name|hostid
operator|,
name|r0
operator|#
name|check
name|cache
name|beql
name|doit
name|ret
name|doit
operator|:
name|chmk
name|$SYS_gethostid
name|jcs
name|err
name|movl
name|r0
operator|,
name|hostid
operator|#
name|set
name|cache
name|ret
operator|#
name|hostid
operator|=
name|gethostid
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|err
label|:
end_label

begin_decl_stmt
name|jmp
name|cerror
decl_stmt|;
end_decl_stmt

end_unit

