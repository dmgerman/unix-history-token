begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mandoc_ohash.h,v 1.2 2015/11/07 14:01:16 schwarze Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_OHASH
end_if

begin_include
include|#
directive|include
file|<ohash.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"compat_ohash.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|mandoc_ohash_init
parameter_list|(
name|struct
name|ohash
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|ptrdiff_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

