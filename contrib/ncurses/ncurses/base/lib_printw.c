begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1997                        *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_printw.c ** **	The routines printw(), wprintw() and friends. ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_printw.c,v 1.9 2000/12/10 02:43:27 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|printw
argument_list|(
argument|NCURSES_CONST char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|int
name|code
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"printw(%s,...) called"
operator|,
name|_nc_visbuf
argument_list|(
name|fmt
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwprintw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|wprintw
argument_list|(
argument|WINDOW *win
argument_list|,
argument|NCURSES_CONST char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|int
name|code
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"wprintw(%p,%s,...) called"
operator|,
name|win
operator|,
name|_nc_visbuf
argument_list|(
name|fmt
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwprintw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|mvprintw
argument_list|(
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|NCURSES_CONST char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|int
name|code
init|=
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
decl_stmt|;
if|if
condition|(
name|code
operator|!=
name|ERR
condition|)
block|{
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwprintw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
block|}
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|mvwprintw
argument_list|(
argument|WINDOW *win
argument_list|,
argument|int y
argument_list|,
argument|int x
argument_list|,
argument|NCURSES_CONST char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|int
name|code
init|=
name|wmove
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
decl_stmt|;
if|if
condition|(
name|code
operator|!=
name|ERR
condition|)
block|{
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwprintw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
block|}
return|return
name|code
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vwprintw
argument_list|(
argument|WINDOW *win
argument_list|,
argument|NCURSES_CONST char *fmt
argument_list|,
argument|va_list argp
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|buf
init|=
name|_nc_printf_string
argument_list|(
name|fmt
argument_list|,
name|argp
argument_list|)
decl_stmt|;
name|int
name|code
init|=
name|ERR
decl_stmt|;
if|if
condition|(
name|buf
operator|!=
literal|0
condition|)
block|{
name|code
operator|=
name|waddstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|#
directive|if
name|USE_SAFE_SPRINTF
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|code
return|;
block|}
end_block

end_unit

