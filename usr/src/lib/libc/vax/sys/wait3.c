begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)wait3.c	4.2	(Berkeley)	12/28/82	*/
end_comment

begin_comment
comment|/*  * C library -- wait3  *  * pid = wait3(&status, flags,&rusage);  *  * pid == -1 if error  * status indicates fate of process, if given  * flags may indicate process is not to hang or  * that untraced stopped children are to be reported.  * rusage optionally returns detailed resource usage information  */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SYS_wait3
value|SYS_wait
end_define

begin_macro
name|ENTRY
argument_list|(
argument|wait3
argument_list|)
end_macro

begin_expr_stmt
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

