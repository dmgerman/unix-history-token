begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strlcpy.c,v 1.3 2007/06/04 18:19:27 christos Exp $	*/
end_comment

begin_comment
comment|/*	$OpenBSD: strlcpy.c,v 1.7 2003/04/12 21:56:39 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND TODD C. MILLER DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL TODD C. MILLER BE LIABLE  * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
name|HAVE_STRLCPY
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
name|size_t
name|n
init|=
name|siz
decl_stmt|;
if|if
condition|(
operator|!
name|dst
operator|||
operator|!
name|src
condition|)
return|return
literal|0
return|;
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

