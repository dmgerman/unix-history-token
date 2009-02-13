begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
unit|static char sccsid[] = "@(#)strncmp.c	8.1 (Berkeley) 6/4/93"; __RCSID("$NetBSD: wcsncmp.c,v 1.3 2001/01/05 12:13:13 itojun Exp $");
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
file|<wchar.h>
end_include

begin_function
name|int
name|wcsncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
specifier|const
name|wchar_t
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_decl_stmt
name|size_t
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
do|do
block|{
if|if
condition|(
operator|*
name|s1
operator|!=
operator|*
name|s2
operator|++
condition|)
block|{
comment|/* XXX assumes wchar_t = int */
return|return
operator|(
operator|*
operator|(
specifier|const
name|unsigned
name|int
operator|*
operator|)
name|s1
operator|-
operator|*
operator|(
specifier|const
name|unsigned
name|int
operator|*
operator|)
operator|--
name|s2
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|s1
operator|++
operator|==
literal|0
condition|)
break|break;
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

