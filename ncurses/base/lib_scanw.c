begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2009 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_scanw.c ** **	The routines scanw(), wscanw() and friends. ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_scanw.c,v 1.12 2009/10/24 22:35:14 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vwscanw
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
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|wgetnstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
literal|1
argument_list|)
operator|==
name|ERR
condition|)
return|return
operator|(
name|ERR
operator|)
return|;
return|return
operator|(
name|vsscanf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
operator|)
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
name|scanw
argument_list|(
argument|NCURSES_CONST char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|code
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"scanw(\"%s\",...) called"
operator|,
name|fmt
operator|)
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwscanw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|)
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
name|wscanw
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
name|int
name|code
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"wscanw(%p,\"%s\",...) called"
operator|,
operator|(
name|void
operator|*
operator|)
name|win
operator|,
name|fmt
operator|)
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
name|vwscanw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|)
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
name|mvscanw
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
name|int
name|code
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
operator|(
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|OK
operator|)
condition|?
name|vwscanw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
else|:
name|ERR
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|)
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
name|mvwscanw
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
name|int
name|code
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|code
operator|=
operator|(
name|wmove
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|OK
operator|)
condition|?
name|vwscanw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
else|:
name|ERR
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|)
return|;
block|}
end_block

end_unit

