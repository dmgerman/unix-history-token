begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)1999 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	citrus Id: wcsrchr.c,v 1.2 2000/12/21 05:07:25 itojun Exp  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
unit|__RCSID("$NetBSD: wcsrchr.c,v 1.1 2000/12/23 23:14:37 itojun Exp $");
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_function
name|wchar_t
modifier|*
name|wcsrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|const
name|wchar_t
modifier|*
name|s
decl_stmt|;
name|wchar_t
name|c
decl_stmt|;
block|{
specifier|const
name|wchar_t
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|s
expr_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
name|p
operator|++
expr_stmt|;
while|while
condition|(
name|s
operator|<=
name|p
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|c
condition|)
block|{
comment|/* LINTED interface specification */
return|return
operator|(
name|wchar_t
operator|*
operator|)
name|p
return|;
block|}
name|p
operator|--
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

end_unit

