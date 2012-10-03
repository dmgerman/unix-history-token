begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: dirname.c,v 1.11 2009/11/24 13:34:20 tnozaki Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 2002 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Klaus Klein and Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DIRNAME
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|dirname
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
block|{
specifier|static
name|char
name|result
index|[
name|PATH_MAX
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|lastp
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* 	 * If `path' is a null pointer or points to an empty string, 	 * return a pointer to the string ".". 	 */
if|if
condition|(
operator|(
name|path
operator|==
name|NULL
operator|)
operator|||
operator|(
operator|*
name|path
operator|==
literal|'\0'
operator|)
condition|)
goto|goto
name|singledot
goto|;
comment|/* Strip trailing slashes, if any. */
name|lastp
operator|=
name|path
operator|+
name|strlen
argument_list|(
name|path
argument_list|)
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|lastp
operator|!=
name|path
operator|&&
operator|*
name|lastp
operator|==
literal|'/'
condition|)
name|lastp
operator|--
expr_stmt|;
comment|/* Terminate path at the last occurence of '/'. */
do|do
block|{
if|if
condition|(
operator|*
name|lastp
operator|==
literal|'/'
condition|)
block|{
comment|/* Strip trailing slashes, if any. */
while|while
condition|(
name|lastp
operator|!=
name|path
operator|&&
operator|*
name|lastp
operator|==
literal|'/'
condition|)
name|lastp
operator|--
expr_stmt|;
comment|/* ...and copy the result into the result buffer. */
name|len
operator|=
operator|(
name|lastp
operator|-
name|path
operator|)
operator|+
literal|1
comment|/* last char */
expr_stmt|;
if|if
condition|(
name|len
operator|>
operator|(
name|PATH_MAX
operator|-
literal|1
operator|)
condition|)
name|len
operator|=
name|PATH_MAX
operator|-
literal|1
expr_stmt|;
name|memcpy
argument_list|(
name|result
argument_list|,
name|path
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|result
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
block|}
do|while
condition|(
operator|--
name|lastp
operator|>=
name|path
condition|)
do|;
comment|/* No /'s found, return a pointer to the string ".". */
name|singledot
label|:
name|result
index|[
literal|0
index|]
operator|=
literal|'.'
expr_stmt|;
name|result
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

