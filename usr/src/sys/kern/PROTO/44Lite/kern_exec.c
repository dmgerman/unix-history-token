begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	from: @(#)kern_exec.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_comment
comment|/*  * exec system call  */
end_comment

begin_struct
struct|struct
name|execve_args
block|{
name|char
modifier|*
name|fname
decl_stmt|;
name|char
modifier|*
modifier|*
name|argp
decl_stmt|;
name|char
modifier|*
modifier|*
name|envp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|execve
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
name|execve_args
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

end_unit

