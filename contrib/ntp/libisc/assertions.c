begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: assertions.c,v 1.16 2001/07/16 03:52:05 mayer Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
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
file|<isc/assertions.h>
end_include

begin_include
include|#
directive|include
file|<isc/msgs.h>
end_include

begin_comment
comment|/*  * Forward.  */
end_comment

begin_function_decl
specifier|static
name|void
name|default_callback
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|isc_assertiontype_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Public.  */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|isc_assertioncallback_t
name|isc_assertion_failed
init|=
name|default_callback
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|isc_assertion_setcallback
parameter_list|(
name|isc_assertioncallback_t
name|cb
parameter_list|)
block|{
if|if
condition|(
name|cb
operator|==
name|NULL
condition|)
name|isc_assertion_failed
operator|=
name|default_callback
expr_stmt|;
else|else
name|isc_assertion_failed
operator|=
name|cb
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|isc_assertion_typetotext
parameter_list|(
name|isc_assertiontype_t
name|type
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|result
decl_stmt|;
comment|/* 	 * These strings have purposefully not been internationalized 	 * because they are considered to essentially be keywords of 	 * the ISC development environment. 	 */
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|isc_assertiontype_require
case|:
name|result
operator|=
literal|"REQUIRE"
expr_stmt|;
break|break;
case|case
name|isc_assertiontype_ensure
case|:
name|result
operator|=
literal|"ENSURE"
expr_stmt|;
break|break;
case|case
name|isc_assertiontype_insist
case|:
name|result
operator|=
literal|"INSIST"
expr_stmt|;
break|break;
case|case
name|isc_assertiontype_invariant
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
name|default_callback
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|isc_assertiontype_t
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%d: %s(%s) %s.\n"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|isc_assertion_typetotext
argument_list|(
name|type
argument_list|)
argument_list|,
name|cond
argument_list|,
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_MSGSET_GENERAL
argument_list|,
name|ISC_MSG_FAILED
argument_list|,
literal|"failed"
argument_list|)
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

