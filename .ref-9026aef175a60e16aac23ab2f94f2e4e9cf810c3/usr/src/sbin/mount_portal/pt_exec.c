begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)pt_exec.c	8.1 (Berkeley) %G%  *  * $Id: pt_exec.c,v 1.1 1992/05/25 21:43:09 jsp Exp jsp $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|"portald.h"
end_include

begin_function
name|int
name|portal_exec
parameter_list|(
name|pcr
parameter_list|,
name|key
parameter_list|,
name|v
parameter_list|,
name|so
parameter_list|,
name|fdp
parameter_list|)
name|struct
name|portal_cred
modifier|*
name|pcr
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
modifier|*
name|v
decl_stmt|;
name|int
name|so
decl_stmt|;
name|int
modifier|*
name|fdp
decl_stmt|;
block|{
return|return
operator|(
name|ENOEXEC
operator|)
return|;
block|}
end_function

end_unit

