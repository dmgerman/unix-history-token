begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Diomidis Spinellis.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Diomidis Spinellis of Imperial College, University of London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)misc.c	8.1 (Berkeley) 6/6/93";
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
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * malloc with result test  */
end_comment

begin_function
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size
parameter_list|)
name|u_int
name|size
decl_stmt|;
block|{
name|void
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"malloc"
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * realloc with result test  */
end_comment

begin_function
name|void
modifier|*
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|)
name|void
modifier|*
name|p
decl_stmt|;
name|u_int
name|size
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
comment|/* Compatibility hack. */
return|return
operator|(
name|xmalloc
argument_list|(
name|size
argument_list|)
operator|)
return|;
if|if
condition|(
operator|(
name|p
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"realloc"
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return a string for a regular expression error passed.  This is a overkill,  * because of the silly semantics of regerror (we can never know the size of  * the buffer).  */
end_comment

begin_function
name|char
modifier|*
name|strregerror
parameter_list|(
name|errcode
parameter_list|,
name|preg
parameter_list|)
name|int
name|errcode
decl_stmt|;
name|regex_t
modifier|*
name|preg
decl_stmt|;
block|{
specifier|static
name|char
modifier|*
name|oe
decl_stmt|;
name|size_t
name|s
decl_stmt|;
if|if
condition|(
name|oe
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|oe
argument_list|)
expr_stmt|;
name|s
operator|=
name|regerror
argument_list|(
name|errcode
argument_list|,
name|preg
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|oe
operator|=
name|xmalloc
argument_list|(
name|s
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|regerror
argument_list|(
name|errcode
argument_list|,
name|preg
argument_list|,
name|oe
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|oe
operator|)
return|;
block|}
end_function

end_unit

