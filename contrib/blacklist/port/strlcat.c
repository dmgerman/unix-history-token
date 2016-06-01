begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strlcat.c,v 1.2 2015/01/22 03:48:07 christos Exp $	*/
end_comment

begin_comment
comment|/*	$OpenBSD: strlcat.c,v 1.10 2003/04/12 21:56:39 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND TODD C. MILLER DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL TODD C. MILLER BE LIABLE  * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
literal|"$NetBSD: strlcat.c,v 1.2 2015/01/22 03:48:07 christos Exp $"
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

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|"namespace.h"
end_include

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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__weak_alias
end_ifdef

begin_macro
name|__weak_alias
argument_list|(
argument|strlcat
argument_list|,
argument|_strlcat
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<lib/libkern/libkern.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL&& !_STANDALONE */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRLCAT
end_if

begin_comment
comment|/*  * Appends src to string dst of size siz (unlike strncat, siz is the  * full size of dst, not space left).  At most siz-1 characters  * will be copied.  Always NUL terminates (unless siz<= strlen(dst)).  * Returns strlen(src) + MIN(siz, strlen(initial dst)).  * If retval>= siz, truncation occurred.  */
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
if|#
directive|if
literal|1
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
name|size_t
name|dlen
decl_stmt|;
comment|/* Find the end of dst and adjust bytes left but don't go past end */
while|while
condition|(
name|n
operator|--
operator|!=
literal|0
operator|&&
operator|*
name|d
operator|!=
literal|'\0'
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
else|#
directive|else
comment|/* 	 * Find length of string in dst (maxing out at siz). 	 */
name|size_t
name|dlen
init|=
name|strnlen
argument_list|(
name|dst
argument_list|,
name|siz
argument_list|)
decl_stmt|;
comment|/* 	 * Copy src into any remaining space in dst (truncating if needed). 	 * Note strlcpy(dst, src, 0) returns strlen(src). 	 */
return|return
name|dlen
operator|+
name|strlcpy
argument_list|(
name|dst
operator|+
name|dlen
argument_list|,
name|src
argument_list|,
name|siz
operator|-
name|dlen
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

