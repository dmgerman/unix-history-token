begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)rewind.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

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

begin_function
name|void
name|rewind
parameter_list|(
name|fp
parameter_list|)
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fseek
argument_list|(
name|fp
argument_list|,
literal|0L
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|clearerr
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* not required, but seems reasonable */
block|}
end_function

end_unit

