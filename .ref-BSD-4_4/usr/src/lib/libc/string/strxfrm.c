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
literal|"@(#)strxfrm.c	8.1 (Berkeley) 6/4/93"
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
comment|/*  * Transform src, storing the result in dst, such that  * strcmp() on transformed strings returns what strcoll()  * on the original untransformed strings would return.  */
end_comment

begin_function
name|size_t
name|strxfrm
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
specifier|register
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
specifier|register
name|size_t
name|srclen
decl_stmt|,
name|copysize
decl_stmt|;
comment|/* 	 * Since locales are unimplemented, this is just a copy. 	 */
name|srclen
operator|=
name|strlen
argument_list|(
name|src
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|copysize
operator|=
name|srclen
operator|<
name|n
condition|?
name|srclen
else|:
name|n
operator|-
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|copysize
argument_list|)
expr_stmt|;
name|dst
index|[
name|copysize
index|]
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|srclen
operator|)
return|;
block|}
end_function

end_unit

