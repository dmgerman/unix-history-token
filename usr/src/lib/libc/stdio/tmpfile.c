begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)tmpfile.c	5.1 (Berkeley) %G%"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|FILE
modifier|*
name|tmpfile
parameter_list|()
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|e
decl_stmt|;
name|char
modifier|*
name|f
decl_stmt|,
name|buf
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|=
name|tmpnam
argument_list|(
name|buf
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|fp
operator|=
name|fopen
argument_list|(
name|f
argument_list|,
literal|"w+"
argument_list|)
expr_stmt|;
name|e
operator|=
name|errno
expr_stmt|;
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|errno
operator|=
name|e
expr_stmt|;
return|return
operator|(
name|fp
operator|)
return|;
block|}
end_function

end_unit

