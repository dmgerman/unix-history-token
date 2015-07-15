begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: once.c,v 1.12 2007/06/18 23:47:49 tbox Exp $ */
end_comment

begin_comment
comment|/* Principal Authors: DCL */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_function
name|isc_result_t
name|isc_once_do
parameter_list|(
name|isc_once_t
modifier|*
name|controller
parameter_list|,
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|REQUIRE
argument_list|(
name|controller
operator|!=
name|NULL
operator|&&
name|function
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|controller
operator|->
name|status
operator|==
name|ISC_ONCE_INIT_NEEDED
condition|)
block|{
if|if
condition|(
name|InterlockedDecrement
argument_list|(
operator|&
name|controller
operator|->
name|counter
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|controller
operator|->
name|status
operator|==
name|ISC_ONCE_INIT_NEEDED
condition|)
block|{
name|function
argument_list|()
expr_stmt|;
name|controller
operator|->
name|status
operator|=
name|ISC_ONCE_INIT_DONE
expr_stmt|;
block|}
block|}
else|else
block|{
while|while
condition|(
name|controller
operator|->
name|status
operator|==
name|ISC_ONCE_INIT_NEEDED
condition|)
block|{
comment|/* 				 * Sleep(0) indicates that this thread  				 * should be suspended to allow other  				 * waiting threads to execute. 				 */
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
operator|(
name|ISC_R_SUCCESS
operator|)
return|;
block|}
end_function

end_unit

