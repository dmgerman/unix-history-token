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
literal|"@(#)fputs.c	5.5 (Berkeley) %G%"
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
file|<sys/cdefs.h>
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
comment|/*  * Write the given string to the given file.  */
end_comment

begin_macro
name|fputs
argument_list|(
argument|s
argument_list|,
argument|fp
argument_list|)
end_macro

begin_decl_stmt
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|__suio
name|uio
decl_stmt|;
name|struct
name|__siov
name|iov
decl_stmt|;
name|iov
operator|.
name|iov_base
operator|=
operator|(
name|void
operator|*
operator|)
name|s
expr_stmt|;
name|iov
operator|.
name|iov_len
operator|=
name|uio
operator|.
name|uio_resid
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|uio
operator|.
name|uio_iov
operator|=
operator|&
name|iov
expr_stmt|;
name|uio
operator|.
name|uio_iovcnt
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|__sfvwrite
argument_list|(
name|fp
argument_list|,
operator|&
name|uio
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

