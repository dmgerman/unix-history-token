begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1998                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	home_terminfo.c -- return the $HOME/.terminfo string, expanded  */
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

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: home_terminfo.c,v 1.2 1999/02/27 19:58:46 tom Exp $"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|my_length
value|(strlen(home) + sizeof(PRIVATE_INFO))
end_define

begin_comment
comment|/* ncurses extension...fall back on user's private directory */
end_comment

begin_function
name|char
modifier|*
name|_nc_home_terminfo
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|home
decl_stmt|;
specifier|static
name|char
modifier|*
name|temp
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|temp
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|home
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
operator|!=
literal|0
operator|&&
name|my_length
operator|<=
name|PATH_MAX
condition|)
block|{
name|temp
operator|=
name|typeMalloc
argument_list|(
name|char
argument_list|,
name|my_length
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|==
literal|0
condition|)
name|_nc_err_abort
argument_list|(
literal|"Out of memory"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|temp
argument_list|,
name|PRIVATE_INFO
argument_list|,
name|home
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|temp
return|;
block|}
end_function

end_unit

