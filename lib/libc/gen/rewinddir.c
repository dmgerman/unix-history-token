begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)rewinddir.c	8.1 (Berkeley) 6/8/93"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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

begin_include
include|#
directive|include
file|"gen-private.h"
end_include

begin_include
include|#
directive|include
file|"telldir.h"
end_include

begin_function
name|void
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
if|if
condition|(
name|__isthreaded
condition|)
name|_pthread_mutex_lock
argument_list|(
operator|&
name|dirp
operator|->
name|dd_lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|dirp
operator|->
name|dd_flags
operator|&
name|__DTF_READALL
condition|)
name|_filldir
argument_list|(
name|dirp
argument_list|,
name|false
argument_list|)
expr_stmt|;
else|else
block|{
operator|(
name|void
operator|)
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_seek
operator|=
literal|0
expr_stmt|;
block|}
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
name|_reclaim_telldir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
if|if
condition|(
name|__isthreaded
condition|)
name|_pthread_mutex_unlock
argument_list|(
operator|&
name|dirp
operator|->
name|dd_lock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

