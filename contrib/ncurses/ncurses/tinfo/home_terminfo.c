begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2010,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                                                *  ****************************************************************************/
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
literal|"$Id: home_terminfo.c,v 1.15 2012/10/27 21:49:14 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/* ncurses extension...fall back on user's private directory */
end_comment

begin_define
define|#
directive|define
name|MyBuffer
value|_nc_globals.home_terminfo
end_define

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|_nc_home_terminfo
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|USE_HOME_TERMINFO
name|char
modifier|*
name|home
decl_stmt|;
if|if
condition|(
name|use_terminfo_vars
argument_list|()
condition|)
block|{
if|if
condition|(
name|MyBuffer
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
condition|)
block|{
name|size_t
name|want
init|=
operator|(
name|strlen
argument_list|(
name|home
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|PRIVATE_INFO
argument_list|)
operator|)
decl_stmt|;
name|TYPE_MALLOC
argument_list|(
name|char
argument_list|,
name|want
argument_list|,
name|MyBuffer
argument_list|)
expr_stmt|;
name|_nc_SPRINTF
argument_list|(
name|MyBuffer
argument_list|,
name|_nc_SLIMIT
argument_list|(
argument|want
argument_list|)
name|PRIVATE_INFO
argument_list|,
name|home
argument_list|)
expr_stmt|;
block|}
block|}
name|result
operator|=
name|MyBuffer
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|result
return|;
block|}
end_block

end_unit

