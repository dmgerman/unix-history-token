begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 by Internet Software Consortium, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<port_before.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/misc.h>
end_include

begin_include
include|#
directive|include
file|<port_after.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MOVEFILE
end_ifndef

begin_comment
comment|/*  * rename() is lame (can't overwrite an existing file) on some systems.  * use movefile() instead, and let lame OS ports do what they need to.  */
end_comment

begin_function
name|int
name|isc_movefile
parameter_list|(
specifier|const
name|char
modifier|*
name|oldname
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
block|{
return|return
operator|(
name|rename
argument_list|(
name|oldname
argument_list|,
name|newname
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|int
name|os_port_has_isc_movefile
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

