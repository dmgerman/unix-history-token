begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|HAVE_REALLOCARRAY
end_if

begin_decl_stmt
name|int
name|dummy
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*	$Id: compat_reallocarray.c,v 1.4 2014/12/11 09:05:01 schwarze Exp $	*/
end_comment

begin_comment
comment|/*	$OpenBSD: reallocarray.c,v 1.2 2014/12/08 03:45:00 bcook Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 Otto Moerbeek<otto@drijf.net>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/*  * This is sqrt(SIZE_MAX+1), as s1*s2<= SIZE_MAX  * if both s1< MUL_NO_OVERFLOW and s2< MUL_NO_OVERFLOW  */
end_comment

begin_define
define|#
directive|define
name|MUL_NO_OVERFLOW
value|((size_t)1<< (sizeof(size_t) * 4))
end_define

begin_function
name|void
modifier|*
name|reallocarray
parameter_list|(
name|void
modifier|*
name|optr
parameter_list|,
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
if|if
condition|(
operator|(
name|nmemb
operator|>=
name|MUL_NO_OVERFLOW
operator|||
name|size
operator|>=
name|MUL_NO_OVERFLOW
operator|)
operator|&&
name|nmemb
operator|>
literal|0
operator|&&
name|SIZE_MAX
operator|/
name|nmemb
operator|<
name|size
condition|)
block|{
name|errno
operator|=
name|ENOMEM
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|realloc
argument_list|(
name|optr
argument_list|,
name|size
operator|*
name|nmemb
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!HAVE_REALLOCARRAY*/
end_comment

end_unit

