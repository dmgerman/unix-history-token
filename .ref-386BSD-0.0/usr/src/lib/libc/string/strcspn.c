begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)strcspn.c	5.6 (Berkeley) 1/26/91"
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Span the complement of string s2.  */
end_comment

begin_function
name|size_t
name|strcspn
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|const
name|char
modifier|*
name|s1
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|s2
decl_stmt|;
block|{
specifier|register
specifier|const
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|spanp
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|,
name|sc
decl_stmt|;
comment|/* 	 * Stop as soon as we find any character from s2.  Note that there 	 * must be a NUL in s2; it suffices to stop when we find that, too. 	 */
for|for
control|(
name|p
operator|=
name|s1
init|;
condition|;
control|)
block|{
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|spanp
operator|=
name|s2
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
return|return
operator|(
name|p
operator|-
literal|1
operator|-
name|s1
operator|)
return|;
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

end_unit

