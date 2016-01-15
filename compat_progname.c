begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|HAVE_PROGNAME
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
comment|/*	$Id: compat_progname.c,v 1.1 2015/11/06 16:30:33 schwarze Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2015 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|setprogname
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|progname
operator|=
name|name
expr_stmt|;
block|}
end_function

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
name|progname
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

