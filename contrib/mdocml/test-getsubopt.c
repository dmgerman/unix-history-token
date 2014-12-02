begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: test-getsubopt.c,v 1.3 2014/08/17 20:53:50 schwarze Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* getsubopt() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|buf
index|[]
init|=
literal|"k=v"
decl_stmt|;
name|char
modifier|*
name|options
init|=
name|buf
decl_stmt|;
name|char
name|token0
index|[]
init|=
literal|"k"
decl_stmt|;
name|char
modifier|*
specifier|const
name|tokens
index|[]
init|=
block|{
name|token0
block|,
name|NULL
block|}
decl_stmt|;
name|char
modifier|*
name|value
init|=
name|NULL
decl_stmt|;
return|return
operator|(
operator|!
operator|(
literal|0
operator|==
name|getsubopt
argument_list|(
operator|&
name|options
argument_list|,
name|tokens
argument_list|,
operator|&
name|value
argument_list|)
operator|&&
name|value
operator|==
name|buf
operator|+
literal|2
operator|&&
name|options
operator|==
name|buf
operator|+
literal|3
operator|)
operator|)
return|;
block|}
end_function

end_unit

