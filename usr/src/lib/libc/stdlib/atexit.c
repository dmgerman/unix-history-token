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
literal|"@(#)atexit.c	8.2 (Berkeley) %G%"
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

begin_decl_stmt
name|struct
name|atexit
modifier|*
name|__atexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to head of LIFO stack */
end_comment

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
elseif|else
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
name|p
operator|->
name|ind
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|next
operator|=
name|__atexit
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

