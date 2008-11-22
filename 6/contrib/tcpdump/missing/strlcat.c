begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strlcat.c,v 1.5 1999/09/20 04:39:47 lukem Exp $	*/
end_comment

begin_comment
comment|/*	from OpenBSD: strlcat.c,v 1.2 1999/06/17 16:28:58 millert Exp 	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Todd C. Miller<Todd.Miller@courtesan.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/missing/strlcat.c,v 1.5 2003/11/16 09:36:51 guy Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Appends src to string dst of size siz (unlike strncat, siz is the  * full size of dst, not space left).  At most siz-1 characters  * will be copied.  Always NUL terminates (unless siz == 0).  * Returns strlen(src); if retval>= siz, truncation occurred.  */
end_comment

begin_function
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
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
name|size_t
name|dlen
decl_stmt|;
comment|/* Find the end of dst and adjust bytes left but don't go past end */
while|while
condition|(
operator|*
name|d
operator|!=
literal|'\0'
operator|&&
name|n
operator|--
operator|!=
literal|0
condition|)
name|d
operator|++
expr_stmt|;
name|dlen
operator|=
name|d
operator|-
name|dst
expr_stmt|;
name|n
operator|=
name|siz
operator|-
name|dlen
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
operator|(
name|dlen
operator|+
name|strlen
argument_list|(
name|s
argument_list|)
operator|)
return|;
while|while
condition|(
operator|*
name|s
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|n
operator|!=
literal|1
condition|)
block|{
operator|*
name|d
operator|++
operator|=
operator|*
name|s
expr_stmt|;
name|n
operator|--
expr_stmt|;
block|}
name|s
operator|++
expr_stmt|;
block|}
operator|*
name|d
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dlen
operator|+
operator|(
name|s
operator|-
name|src
operator|)
operator|)
return|;
comment|/* count does not include NUL */
block|}
end_function

end_unit

