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
literal|"@(#)strncpy.c	8.1 (Berkeley) 6/4/93"
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
file|<string.h>
end_include

begin_comment
comment|/*  * Copy src to dst, truncating or null-padding to always copy n bytes.  * Return dst.  */
end_comment

begin_function
name|char
modifier|*
name|strncpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|dst
decl_stmt|;
specifier|const
name|char
modifier|*
name|src
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|char
modifier|*
name|d
init|=
name|dst
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
init|=
name|src
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* NUL pad the remaining n-1 bytes */
while|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
block|}
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

end_unit

