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
literal|"@(#)wait3.c	5.3 (Berkeley) 3/9/86"
endif|#
directive|endif
endif|SYSLIBC_SCCS
comment|/*	@(#)wait3.c	5.3	(Berkeley)	3/9/86	*/
comment|/*  * C library -- wait3  *  * pid = wait3(&status, flags,&rusage);  *  * pid == -1 if error  * status indicates fate of process, if given  * flags may indicate process is not to hang or  * that untraced stopped children are to be reported.  * rusage optionally returns detailed resource usage information  */
include|#
directive|include
file|"SYS.h"
define|#
directive|define
name|SYS_wait3
value|SYS_wait
name|ENTRY
argument_list|(
argument|wait3
argument_list|)
name|movl
literal|8
operator|(
name|ap
operator|)
operator|,
name|r0
comment|/* make it easy for system to get */
name|movl
literal|12
operator|(
name|ap
operator|)
operator|,
name|r1
comment|/* these extra arguments */
name|bispsw
name|$0xf
comment|/* flags wait3() */
name|chmk
name|$SYS_wait3
name|bcc
name|noerror
name|movl
name|r0
operator|,
name|_errno
name|mnegl
name|$1
operator|,
name|r0
name|ret
name|noerror
operator|:
name|tstl
literal|4
operator|(
name|ap
operator|)
comment|/* status desired? */
name|beql
name|nostatus
comment|/* no */
name|movl
name|r1
operator|,
operator|*
literal|4
operator|(
name|ap
operator|)
comment|/* store child's status */
name|nostatus
operator|:
name|ret
end_expr_stmt

end_unit

