begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: att.c,v 1.16 2017/06/24 14:38:32 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
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

begin_include
include|#
directive|include
file|"mandoc.h"
end_include

begin_include
include|#
directive|include
file|"roff.h"
end_include

begin_include
include|#
directive|include
file|"mdoc.h"
end_include

begin_include
include|#
directive|include
file|"libmdoc.h"
end_include

begin_define
define|#
directive|define
name|LINE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|if (0 == strcmp(p, x)) return(y)
end_define

begin_function
specifier|const
name|char
modifier|*
name|mdoc_a2att
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
name|LINE
argument_list|(
literal|"v1"
argument_list|,
literal|"Version\\~1 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v2"
argument_list|,
literal|"Version\\~2 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v3"
argument_list|,
literal|"Version\\~3 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v4"
argument_list|,
literal|"Version\\~4 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v5"
argument_list|,
literal|"Version\\~5 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v6"
argument_list|,
literal|"Version\\~6 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"v7"
argument_list|,
literal|"Version\\~7 AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"32v"
argument_list|,
literal|"Version\\~32V AT&T UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"III"
argument_list|,
literal|"AT&T System\\~III UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"V"
argument_list|,
literal|"AT&T System\\~V UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"V.1"
argument_list|,
literal|"AT&T System\\~V Release\\~1 UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"V.2"
argument_list|,
literal|"AT&T System\\~V Release\\~2 UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"V.3"
argument_list|,
literal|"AT&T System\\~V Release\\~3 UNIX"
argument_list|)
expr_stmt|;
name|LINE
argument_list|(
literal|"V.4"
argument_list|,
literal|"AT&T System\\~V Release\\~4 UNIX"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

end_unit

