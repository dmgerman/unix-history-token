begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: msec.c,v 1.11 2014/03/23 11:25:26 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"libmandoc.h"
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
value|if (0 == strcmp(p, x)) return(y);
end_define

begin_function
specifier|const
name|char
modifier|*
name|mandoc_a2msec
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
include|#
directive|include
file|"msec.in"
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

