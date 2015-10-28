begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: strndup.c,v 1.1 2010/05/18 22:24:55 tedu Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|char
modifier|*
name|strndup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
block|{
name|char
modifier|*
name|copy
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|len
operator|=
name|strnlen
argument_list|(
name|str
argument_list|,
name|maxlen
argument_list|)
expr_stmt|;
name|copy
operator|=
name|malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|copy
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|memcpy
argument_list|(
name|copy
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|copy
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
return|return
name|copy
return|;
block|}
end_function

end_unit

