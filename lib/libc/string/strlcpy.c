begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: strlcpy.c,v 1.12 2015/01/15 03:54:12 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, 2015 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Copy string src to buffer dst of size dsize.  At most dsize-1  * chars will be copied.  Always NUL terminates (unless dsize == 0).  * Returns strlen(src); if retval>= dsize, truncation occurred.  */
end_comment

begin_function
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|dsize
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|osrc
init|=
name|src
decl_stmt|;
name|size_t
name|nleft
init|=
name|dsize
decl_stmt|;
comment|/* Copy as many bytes as will fit. */
if|if
condition|(
name|nleft
operator|!=
literal|0
condition|)
block|{
while|while
condition|(
operator|--
name|nleft
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
operator|)
operator|==
literal|'\0'
condition|)
break|break;
block|}
block|}
comment|/* Not enough room in dst, add NUL and traverse rest of src. */
if|if
condition|(
name|nleft
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|dsize
operator|!=
literal|0
condition|)
operator|*
name|dst
operator|=
literal|'\0'
expr_stmt|;
comment|/* NUL-terminate dst */
while|while
condition|(
operator|*
name|src
operator|++
condition|)
empty_stmt|;
block|}
return|return
operator|(
name|src
operator|-
name|osrc
operator|-
literal|1
operator|)
return|;
comment|/* count does not include NUL */
block|}
end_function

end_unit

