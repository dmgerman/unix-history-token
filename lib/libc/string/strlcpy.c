begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: strlcpy.c,v 1.4 1999/05/01 18:56:41 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Todd C. Miller<Todd.Miller@courtesan.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char *rcsid = "$OpenBSD: strlcpy.c,v 1.4 1999/05/01 18:56:41 millert Exp $";
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Copy src to string dst of size siz.  At most siz-1 characters  * will be copied.  Always NUL terminates (unless siz == 0).  * Returns strlen(src); if retval>= siz, truncation occurred.  */
end_comment

begin_function
name|size_t
name|strlcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|siz
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
name|siz
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|d
init|=
name|dst
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|s
init|=
name|src
decl_stmt|;
specifier|register
name|size_t
name|n
init|=
name|siz
decl_stmt|;
comment|/* Copy as many bytes as will fit */
if|if
condition|(
name|n
operator|!=
literal|0
operator|&&
operator|--
name|n
operator|!=
literal|0
condition|)
block|{
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
block|}
comment|/* Not enough room in dst, add NUL and traverse rest of src */
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|siz
operator|!=
literal|0
condition|)
operator|*
name|d
operator|=
literal|'\0'
expr_stmt|;
comment|/* NUL-terminate dst */
while|while
condition|(
operator|*
name|s
operator|++
condition|)
empty_stmt|;
block|}
return|return
operator|(
name|s
operator|-
name|src
operator|-
literal|1
operator|)
return|;
comment|/* count does not include NUL */
block|}
end_function

end_unit

