begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: strsep.c,v 1.6 2005/08/08 08:05:37 espie Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/string/strsep.c */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRSEP
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Get next token from string *stringp, where tokens are possibly-empty  * strings separated by characters from delim.    *  * Writes NULs into the string at *stringp to end tokens.  * delim need not remain constant from call to call.  * On return, *stringp points past the last NUL written (if there might  * be further tokens), or is NULL (if there are definitely no more tokens).  *  * If *stringp is NULL, strsep returns NULL.  */
end_comment

begin_function
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
specifier|const
name|char
modifier|*
name|spanp
decl_stmt|;
name|int
name|c
decl_stmt|,
name|sc
decl_stmt|;
name|char
modifier|*
name|tok
decl_stmt|;
if|if
condition|(
operator|(
name|s
operator|=
operator|*
name|stringp
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
for|for
control|(
name|tok
operator|=
name|s
init|;
condition|;
control|)
block|{
name|c
operator|=
operator|*
name|s
operator|++
expr_stmt|;
name|spanp
operator|=
name|delim
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|(
name|sc
operator|=
operator|*
name|spanp
operator|++
operator|)
operator|==
name|c
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|0
condition|)
name|s
operator|=
name|NULL
expr_stmt|;
else|else
name|s
index|[
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
operator|*
name|stringp
operator|=
name|s
expr_stmt|;
return|return
operator|(
name|tok
operator|)
return|;
block|}
block|}
do|while
condition|(
name|sc
operator|!=
literal|0
condition|)
do|;
block|}
comment|/* NOTREACHED */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_STRSEP) */
end_comment

end_unit

