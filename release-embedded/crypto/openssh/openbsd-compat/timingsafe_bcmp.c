begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: timingsafe_bcmp.c,v 1.1 2010/09/24 13:33:00 matthew Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Damien Miller.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/string/timingsafe_bcmp.c */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TIMINGSAFE_BCMP
end_ifndef

begin_function
name|int
name|timingsafe_bcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|b1
parameter_list|,
specifier|const
name|void
modifier|*
name|b2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|p1
init|=
name|b1
decl_stmt|,
modifier|*
name|p2
init|=
name|b2
decl_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|n
operator|>
literal|0
condition|;
name|n
operator|--
control|)
name|ret
operator||=
operator|*
name|p1
operator|++
operator|^
operator|*
name|p2
operator|++
expr_stmt|;
return|return
operator|(
name|ret
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMINGSAFE_BCMP */
end_comment

end_unit

