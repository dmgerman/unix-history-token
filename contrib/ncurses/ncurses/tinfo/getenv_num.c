begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1998                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	getenv_num.c -- obtain a number from the environment  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: getenv_num.c,v 1.1 1998/09/19 21:30:23 tom Exp $"
argument_list|)
end_macro

begin_function
name|int
name|_nc_getenv_num
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|char
modifier|*
name|dst
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|src
init|=
name|getenv
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|long
name|value
decl_stmt|;
if|if
condition|(
operator|(
name|src
operator|==
literal|0
operator|)
operator|||
operator|(
name|value
operator|=
name|strtol
argument_list|(
name|src
argument_list|,
operator|&
name|dst
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
operator|||
operator|(
name|dst
operator|==
name|src
operator|)
operator|||
operator|(
operator|*
name|dst
operator|!=
literal|'\0'
operator|)
operator|||
operator|(
name|int
operator|)
name|value
operator|<
name|value
condition|)
name|value
operator|=
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|int
operator|)
name|value
return|;
block|}
end_function

end_unit

