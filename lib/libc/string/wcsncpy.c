begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: wcsncpy.c,v 1.1 2000/12/23 23:14:36 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c)1999 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	citrus Id: wcsncpy.c,v 1.1 1999/12/29 21:47:45 tshiozak Exp  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: wcsncpy.c,v 1.1 2000/12/23 23:14:36 itojun Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|wcsncpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
name|wchar_t
modifier|*
name|s1
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|s2
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
name|wchar_t
modifier|*
name|p
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|q
decl_stmt|;
name|_DIAGASSERT
argument_list|(
name|s1
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|_DIAGASSERT
argument_list|(
name|s2
operator|!=
name|NULL
argument_list|)
expr_stmt|;
operator|*
name|s1
operator|=
literal|'\0'
expr_stmt|;
name|p
operator|=
name|s1
expr_stmt|;
name|q
operator|=
name|s2
expr_stmt|;
while|while
condition|(
name|n
operator|&&
operator|*
name|q
condition|)
block|{
operator|*
name|p
operator|++
operator|=
operator|*
name|q
operator|++
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
return|return
name|s1
return|;
block|}
end_function

end_unit

