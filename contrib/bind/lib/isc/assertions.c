begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
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
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: assertions.c,v 8.4 2001/05/29 05:49:22 marka Exp $"
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_comment
comment|/*  * Forward.  */
end_comment

begin_function_decl
specifier|static
name|void
name|default_assertion_failed
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|assertion_type
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Public.  */
end_comment

begin_decl_stmt
name|assertion_failure_callback
name|__assertion_failed
init|=
name|default_assertion_failed
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|set_assertion_failure_callback
parameter_list|(
name|assertion_failure_callback
name|f
parameter_list|)
block|{
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
name|__assertion_failed
operator|=
name|default_assertion_failed
expr_stmt|;
else|else
name|__assertion_failed
operator|=
name|f
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|assertion_type_to_text
parameter_list|(
name|assertion_type
name|type
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|result
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|assert_require
case|:
name|result
operator|=
literal|"REQUIRE"
expr_stmt|;
break|break;
case|case
name|assert_ensure
case|:
name|result
operator|=
literal|"ENSURE"
expr_stmt|;
break|break;
case|case
name|assert_insist
case|:
name|result
operator|=
literal|"INSIST"
expr_stmt|;
break|break;
case|case
name|assert_invariant
case|:
name|result
operator|=
literal|"INVARIANT"
expr_stmt|;
break|break;
default|default:
name|result
operator|=
name|NULL
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Private.  */
end_comment

begin_function
specifier|static
name|void
name|default_assertion_failed
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|assertion_type
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|,
name|int
name|print_errno
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%d: %s(%s)%s%s failed.\n"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|assertion_type_to_text
argument_list|(
name|type
argument_list|)
argument_list|,
name|cond
argument_list|,
operator|(
name|print_errno
operator|)
condition|?
literal|": "
else|:
literal|""
argument_list|,
operator|(
name|print_errno
operator|)
condition|?
name|strerror
argument_list|(
name|errno
argument_list|)
else|:
literal|""
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

