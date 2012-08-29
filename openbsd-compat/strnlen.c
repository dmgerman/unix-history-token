begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: strnlen.c,v 1.3 2010/06/02 12:58:12 millert Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/string/strnlen.c */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRNLEN
end_ifndef

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

begin_function
name|size_t
name|strnlen
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
specifier|const
name|char
modifier|*
name|cp
decl_stmt|;
for|for
control|(
name|cp
operator|=
name|str
init|;
name|maxlen
operator|!=
literal|0
operator|&&
operator|*
name|cp
operator|!=
literal|'\0'
condition|;
name|cp
operator|++
operator|,
name|maxlen
operator|--
control|)
empty_stmt|;
return|return
call|(
name|size_t
call|)
argument_list|(
name|cp
operator|-
name|str
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

