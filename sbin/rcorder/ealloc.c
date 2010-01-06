begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD: ealloc.c,v 1.1.1.1 1999/11/19 04:30:56 mrg Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: ealloc.c,v 1.1.1.1 1999/11/19 04:30:56 mrg Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<err.h>
end_include

begin_include
include|#
directive|include
file|"ealloc.h"
end_include

begin_function_decl
specifier|static
name|void
name|enomem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * enomem --  *	die when out of memory.  */
end_comment

begin_function
specifier|static
name|void
name|enomem
parameter_list|(
name|void
parameter_list|)
block|{
name|errx
argument_list|(
literal|2
argument_list|,
literal|"Cannot allocate memory."
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * emalloc --  *	malloc, but die on error.  */
end_comment

begin_function
name|void
modifier|*
name|emalloc
parameter_list|(
name|size_t
name|len
parameter_list|)
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
name|len
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|enomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * estrdup --  *	strdup, but die on error.  */
end_comment

begin_function
name|char
modifier|*
name|estrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|strdup
argument_list|(
name|str
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|enomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * erealloc --  *	realloc, but die on error.  */
end_comment

begin_function
name|void
modifier|*
name|erealloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
if|if
condition|(
operator|(
name|ptr
operator|=
name|realloc
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|enomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * ecalloc --  *	calloc, but die on error.  */
end_comment

begin_function
name|void
modifier|*
name|ecalloc
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|calloc
argument_list|(
name|nmemb
argument_list|,
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|enomem
argument_list|()
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

end_unit

