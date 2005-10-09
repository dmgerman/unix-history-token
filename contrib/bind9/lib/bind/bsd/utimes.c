begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1997,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_UTIMES
end_ifndef

begin_decl_stmt
name|int
name|__bind_utimes_unneeded
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|__utimes
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
block|{
name|struct
name|utimbuf
name|utb
decl_stmt|;
name|utb
operator|.
name|actime
operator|=
operator|(
name|time_t
operator|)
name|tvp
index|[
literal|0
index|]
operator|.
name|tv_sec
expr_stmt|;
name|utb
operator|.
name|modtime
operator|=
operator|(
name|time_t
operator|)
name|tvp
index|[
literal|1
index|]
operator|.
name|tv_sec
expr_stmt|;
return|return
operator|(
name|utime
argument_list|(
name|filename
argument_list|,
operator|&
name|utb
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_UTIMES */
end_comment

end_unit

