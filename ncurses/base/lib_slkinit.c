begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2008,2009 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  *     and: Juergen Pfeifer                         2009                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_slkinit.c  *	Soft key routines.  *      Initialize soft labels.  Called by the user before initscr().  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_slkinit.c,v 1.13 2009/10/31 00:10:46 tom Exp $"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SP_RIPOFF
end_ifdef

begin_define
define|#
directive|define
name|SoftkeyFormat
value|SP_PARM->slk_format
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SoftkeyFormat
value|_nc_globals.slk_format
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|NCURSES_EXPORT
function|(
name|int
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|slk_init
argument_list|)
parameter_list|(
name|NCURSES_SP_DCLx
name|int
name|format
parameter_list|)
block|{
name|int
name|code
init|=
name|ERR
decl_stmt|;
name|START_TRACE
argument_list|()
expr_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"slk_init(%p,%d)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|SP_PARM
operator|,
name|format
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|>=
literal|0
operator|&&
name|format
operator|<=
literal|3
ifdef|#
directive|ifdef
name|USE_SP_RIPOFF
operator|&&
name|SP_PARM
operator|&&
name|SP_PARM
operator|->
name|_prescreen
endif|#
directive|endif
operator|&&
operator|!
name|SoftkeyFormat
condition|)
block|{
name|SoftkeyFormat
operator|=
literal|1
operator|+
name|format
expr_stmt|;
name|code
operator|=
name|NCURSES_SP_NAME
argument_list|(
name|_nc_ripoffline
argument_list|)
argument_list|(
name|NCURSES_SP_ARGx
operator|-
name|SLK_LINES
argument_list|(
name|SoftkeyFormat
argument_list|)
argument_list|,
name|_nc_slk_initialize
argument_list|)
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|slk_init
argument_list|(
argument|int format
argument_list|)
end_macro

begin_block
block|{
return|return
name|NCURSES_SP_NAME
argument_list|(
name|slk_init
argument_list|)
argument_list|(
name|CURRENT_SCREEN_PRE
argument_list|,
name|format
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

