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
literal|"@(#)fpurge.c	8.1 (Berkeley) %G%"
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

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/*  * fpurge: like fflush, but without writing anything: leave the  * given FILE's buffer empty.  */
end_comment

begin_function
name|int
name|fpurge
parameter_list|(
name|fp
parameter_list|)
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|fp
operator|->
name|_flags
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
name|EOF
operator|)
return|;
block|}
if|if
condition|(
name|HASUB
argument_list|(
name|fp
argument_list|)
condition|)
name|FREEUB
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|fp
operator|->
name|_p
operator|=
name|fp
operator|->
name|_bf
operator|.
name|_base
expr_stmt|;
name|fp
operator|->
name|_r
operator|=
literal|0
expr_stmt|;
name|fp
operator|->
name|_w
operator|=
name|fp
operator|->
name|_flags
operator|&
operator|(
name|__SLBF
operator||
name|__SNBF
operator|)
condition|?
literal|0
else|:
name|fp
operator|->
name|_bf
operator|.
name|_size
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

