begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)misc.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_function
name|void
name|get
parameter_list|(
name|fd
parameter_list|,
name|off
parameter_list|,
name|p
parameter_list|,
name|len
parameter_list|)
name|int
name|fd
decl_stmt|;
name|off_t
name|off
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|{
name|int
name|rbytes
decl_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
name|off
argument_list|,
name|SEEK_SET
argument_list|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
name|special
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|rbytes
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|p
argument_list|,
name|len
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
name|special
argument_list|)
expr_stmt|;
if|if
condition|(
name|rbytes
operator|!=
name|len
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"%s: short read (%d, not %d)"
argument_list|,
name|special
argument_list|,
name|rbytes
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

