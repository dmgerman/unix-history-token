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
literal|"@(#)puts.c	5.3 (Berkeley) %G%"
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
file|<sys/stdc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"fvwrite.h"
end_include

begin_comment
comment|/*  * Write the given string to stdout, appending a newline.  */
end_comment

begin_macro
name|puts
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
specifier|const
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|size_t
name|c
init|=
name|strlen
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|struct
name|__suio
name|uio
decl_stmt|;
name|struct
name|__siov
name|iov
index|[
literal|2
index|]
decl_stmt|;
name|iov
index|[
literal|0
index|]
operator|.
name|iov_base
operator|=
name|s
expr_stmt|;
name|iov
index|[
literal|0
index|]
operator|.
name|iov_len
operator|=
name|c
expr_stmt|;
name|iov
index|[
literal|1
index|]
operator|.
name|iov_base
operator|=
literal|"\n"
expr_stmt|;
name|iov
index|[
literal|1
index|]
operator|.
name|iov_len
operator|=
literal|1
expr_stmt|;
name|uio
operator|.
name|uio_resid
operator|=
name|c
operator|+
literal|1
expr_stmt|;
name|uio
operator|.
name|uio_iov
operator|=
operator|&
name|iov
index|[
literal|0
index|]
expr_stmt|;
name|uio
operator|.
name|uio_iovcnt
operator|=
literal|2
expr_stmt|;
return|return
operator|(
name|__sfvwrite
argument_list|(
name|stdout
argument_list|,
operator|&
name|uio
argument_list|)
condition|?
name|EOF
else|:
literal|'\n'
operator|)
return|;
block|}
end_block

end_unit

