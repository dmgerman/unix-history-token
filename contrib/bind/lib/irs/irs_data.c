begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CODECENTER
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: irs_data.c,v 1.7 1997/12/04 04:57:54 halley Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<irs.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_include
include|#
directive|include
file|"irs_data.h"
end_include

begin_decl_stmt
name|struct
name|net_data
name|net_data
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|net_data_init
parameter_list|()
block|{
if|if
condition|(
operator|!
name|net_data
operator|.
name|irs
condition|)
name|net_data
operator|.
name|irs
operator|=
name|irs_gen_acc
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return
operator|(
name|net_data
operator|.
name|irs
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

end_unit

