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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)fputs.c	8.1 (Berkeley) 6/4/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Write the given string to the given file.  */
end_comment

begin_function
name|int
name|fputs
parameter_list|(
name|s
parameter_list|,
name|fp
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|retval
decl_stmt|;
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
ifdef|#
directive|ifdef
name|_THREAD_SAFE
name|_thread_flockfile
argument_list|(
name|fp
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|retval
operator|=
name|__sfvwrite
argument_list|(
name|fp
argument_list|,
operator|&
name|uio
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_THREAD_SAFE
name|_thread_funlockfile
argument_list|(
name|fp
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

end_unit

