begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)closedir.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/*  * close a directory.  */
end_comment

begin_function
name|void
name|closedir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
name|close
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_fd
operator|=
operator|-
literal|1
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

