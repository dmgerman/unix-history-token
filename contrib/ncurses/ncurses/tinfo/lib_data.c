begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_data.c ** **	Common data that may/may not be allocated, but is referenced globally ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_data.c,v 1.14 1999/01/31 01:34:33 Ilya.Zakharevich Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  * OS/2's native linker complains if we don't initialize public data when  * constructing a dll (reported by J.J.G.Ripoll).  */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|stdscr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|curscr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|newscr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SCREEN
modifier|*
name|_nc_screen_chain
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The variable 'SP' will be defined as a function on systems that cannot link  * data-only modules, since it is used in a lot of places within ncurses and we  * cannot guarantee that any application will use any particular function.  We  * put the WINDOW variables in this module, because it appears that any  * application that uses them will also use 'SP'.  *  * This module intentionally does not reference other ncurses modules, to avoid  * module coupling that increases the size of the executable.  */
end_comment

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_decl_stmt
specifier|static
name|SCREEN
modifier|*
name|my_screen
decl_stmt|;
end_decl_stmt

begin_function
name|SCREEN
modifier|*
name|_nc_screen
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|my_screen
return|;
block|}
end_function

begin_function
name|int
name|_nc_alloc_screen
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|my_screen
operator|=
name|typeCalloc
argument_list|(
name|SCREEN
argument_list|,
literal|1
argument_list|)
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|_nc_set_screen
parameter_list|(
name|SCREEN
modifier|*
name|sp
parameter_list|)
block|{
name|my_screen
operator|=
name|sp
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|SCREEN
modifier|*
name|SP
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some linkers require initialized data... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

