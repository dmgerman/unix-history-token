begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_comment
comment|/*  * Copyright (c) 1998 Todd C. Miller<Todd.Miller@courtesan.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: strlcpy.c,v 1.11 2006/05/05 15:27:38 millert Exp $  * $FreeBSD$  * $DragonFly: src/lib/libc/string/strlcpy.c,v 1.4 2005/09/18 16:32:34 asmodai Exp $  */
end_comment

begin_include
include|#
directive|include
file|"dfcompat.h"
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
comment|/* Copy as many bytes as will fit */
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
while|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
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
literal|'\0'
condition|)
break|break;
block|}
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

begin_comment
comment|/* !HAVE_STRLCPY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REALLOCF
end_ifndef

begin_comment
comment|/*-  * Copyright (c) 1998, M. Warner Losh<imp@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  * $DragonFly: src/lib/libc/stdlib/reallocf.c,v 1.2 2003/06/17 04:26:46 dillon Exp $  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|void
modifier|*
name|reallocf
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|nptr
decl_stmt|;
name|nptr
operator|=
name|realloc
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|nptr
operator|&&
name|ptr
condition|)
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
return|return
operator|(
name|nptr
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_REALLOCF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPROGNAME
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
specifier|const
name|char
modifier|*
name|getprogname
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|program_invocation_short_name
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GLIBC__ */
end_comment

begin_error
error|#
directive|error
literal|"no getprogname implementation available"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GETPROGNAME */
end_comment

end_unit

