begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)atexit.c	8.2 (Berkeley) 7/3/94"
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

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
end_include

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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"atexit.h"
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_decl_stmt
specifier|static
name|pthread_mutex_t
name|atexit_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_MUTEX_LOCK
parameter_list|(
name|x
parameter_list|)
value|if (__isthreaded) _pthread_mutex_lock(x)
end_define

begin_define
define|#
directive|define
name|_MUTEX_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|if (__isthreaded) _pthread_mutex_unlock(x)
end_define

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
name|struct
name|atexit
modifier|*
name|p
decl_stmt|;
name|_MUTEX_LOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
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
else|else
while|while
condition|(
name|p
operator|->
name|ind
operator|>=
name|ATEXIT_SIZE
condition|)
block|{
name|struct
name|atexit
modifier|*
name|old__atexit
decl_stmt|;
name|old__atexit
operator|=
name|__atexit
expr_stmt|;
name|_MUTEX_UNLOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
operator|(
expr|struct
name|atexit
operator|*
operator|)
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
name|_MUTEX_LOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
if|if
condition|(
name|old__atexit
operator|!=
name|__atexit
condition|)
block|{
comment|/* Lost race, retry operation */
name|_MUTEX_UNLOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|_MUTEX_LOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
name|p
operator|=
name|__atexit
expr_stmt|;
continue|continue;
block|}
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
name|_MUTEX_UNLOCK
argument_list|(
operator|&
name|atexit_mutex
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

