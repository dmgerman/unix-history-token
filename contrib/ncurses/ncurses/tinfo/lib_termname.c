begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<tic.h>
end_include

begin_comment
comment|/* for MAX_ALIAS */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_termname.c,v 1.2 1999/07/24 21:02:40 tom Exp $"
argument_list|)
end_macro

begin_function
name|char
modifier|*
name|termname
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|name
init|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
decl_stmt|;
specifier|static
name|char
name|ret
index|[
name|MAX_ALIAS
operator|+
literal|1
index|]
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"termname() called"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|!=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|ret
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ret
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|name
operator|=
name|ret
expr_stmt|;
block|}
return|return
name|name
return|;
block|}
end_function

end_unit

