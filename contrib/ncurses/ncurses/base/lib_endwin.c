begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_endwin.c ** **	The routine endwin(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_endwin.c,v 1.17 1999/06/12 23:01:46 tom Exp $"
argument_list|)
end_macro

begin_function
name|int
name|endwin
parameter_list|(
name|void
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"endwin()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SP
condition|)
block|{
name|SP
operator|->
name|_endwin
operator|=
name|TRUE
expr_stmt|;
name|SP
operator|->
name|_mouse_wrap
argument_list|(
name|SP
argument_list|)
expr_stmt|;
name|_nc_screen_wrap
argument_list|()
expr_stmt|;
name|_nc_mvcur_wrap
argument_list|()
expr_stmt|;
comment|/* wrap up cursor addressing */
name|returnCode
argument_list|(
name|reset_shell_mode
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

