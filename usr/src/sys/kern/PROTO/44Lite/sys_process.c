begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	from: @(#)sys_process.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_comment
comment|/*  * Process debugging system call.  */
end_comment

begin_struct
struct|struct
name|ptrace_args
block|{
name|int
name|req
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|caddr_t
name|addr
decl_stmt|;
name|int
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|ptrace
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ptrace_args
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|a3
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_macro
name|trace_req
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

