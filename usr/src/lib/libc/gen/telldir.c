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
literal|"@(#)telldir.c	5.2 (Berkeley) 3/9/86"
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
comment|/*  * return a pointer into a directory  */
end_comment

begin_function
name|long
name|telldir
parameter_list|(
name|dirp
parameter_list|)
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
return|return
operator|(
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
literal|0L
argument_list|,
literal|1
argument_list|)
operator|-
name|dirp
operator|->
name|dd_size
operator|+
name|dirp
operator|->
name|dd_loc
operator|)
return|;
block|}
end_function

end_unit

