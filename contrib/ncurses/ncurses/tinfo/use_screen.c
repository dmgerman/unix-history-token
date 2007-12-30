begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2007 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *     Author: Thomas E. Dickey                        2007                 *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: use_screen.c,v 1.2 2007/09/08 21:46:48 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|use_screen
argument_list|(
argument|SCREEN *screen
argument_list|,
argument|NCURSES_CALLBACK func
argument_list|,
argument|void *data
argument_list|)
end_macro

begin_block
block|{
name|SCREEN
modifier|*
name|save_SP
decl_stmt|;
name|int
name|code
init|=
name|OK
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"use_screen(%p,%p,%p)"
argument_list|)
operator|,
name|screen
operator|,
name|func
operator|,
name|data
operator|)
argument_list|)
expr_stmt|;
comment|/*      * FIXME - add a flag so a given thread can check if _it_ has already      * recurred through this point, return an error if so.      */
name|_nc_lock_global
argument_list|(
name|use_screen
argument_list|)
expr_stmt|;
name|save_SP
operator|=
name|SP
expr_stmt|;
name|set_term
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|code
operator|=
name|func
argument_list|(
name|screen
operator|->
name|_stdscr
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|set_term
argument_list|(
name|save_SP
argument_list|)
expr_stmt|;
name|_nc_unlock_global
argument_list|(
name|use_screen
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|code
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

