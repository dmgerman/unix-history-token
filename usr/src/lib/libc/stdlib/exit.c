begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)exit.c	8.1 (Berkeley) %G%"
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"atexit.h"
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|__cleanup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Exit, flushing stdio buffers if necessary.  */
end_comment

begin_function
name|void
name|exit
parameter_list|(
name|status
parameter_list|)
name|int
name|status
decl_stmt|;
block|{
specifier|register
name|struct
name|atexit
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
for|for
control|(
name|p
operator|=
name|__atexit
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
for|for
control|(
name|n
operator|=
name|p
operator|->
name|ind
init|;
operator|--
name|n
operator|>=
literal|0
condition|;
control|)
call|(
modifier|*
name|p
operator|->
name|fns
index|[
name|n
index|]
call|)
argument_list|()
expr_stmt|;
if|if
condition|(
name|__cleanup
condition|)
call|(
modifier|*
name|__cleanup
call|)
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

