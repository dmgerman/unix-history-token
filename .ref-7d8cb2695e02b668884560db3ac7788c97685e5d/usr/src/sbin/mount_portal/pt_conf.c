begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)pt_conf.c	8.1 (Berkeley) %G%  *  * $Id: pt_conf.c,v 1.2 1992/05/27 07:09:27 jsp Exp jsp $  */
end_comment

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
file|"portald.h"
end_include

begin_decl_stmt
name|provider
name|providers
index|[]
init|=
block|{
block|{
literal|"exec"
block|,
name|portal_exec
block|}
block|,
block|{
literal|"file"
block|,
name|portal_file
block|}
block|,
block|{
literal|"tcp"
block|,
name|portal_tcp
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

