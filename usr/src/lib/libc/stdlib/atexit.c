begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)atexit.c	5.1 (Berkeley) 5/15/90"
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
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"atexit.h"
end_include

begin_comment
comment|/*  * Register a function to be performed at exit.  */
end_comment

begin_function_decl
name|int
name|atexit
function_decl|(
name|fn
function_decl|)
name|void
argument_list|(
argument|*fn
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
specifier|static
name|struct
name|atexit
name|__atexit0
decl_stmt|;
comment|/* one guaranteed table */
specifier|register
name|struct
name|atexit
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|__atexit
operator|)
operator|==
name|NULL
condition|)
name|__atexit
operator|=
name|p
operator|=
operator|&
name|__atexit0
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|ind
operator|>=
name|ATEXIT_SIZE
condition|)
block|{
if|if
condition|(
operator|(
name|p
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|__atexit
operator|->
name|next
operator|=
name|p
expr_stmt|;
name|__atexit
operator|=
name|p
expr_stmt|;
block|}
name|p
operator|->
name|fns
index|[
name|p
operator|->
name|ind
operator|++
index|]
operator|=
name|fn
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

