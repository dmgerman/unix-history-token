begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2007,2008 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
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
literal|"$Id: use_window.c,v 1.7 2008/05/03 14:09:38 tom Exp $"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PTHREADS
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_lock_window
argument_list|(
argument|const WINDOW *win
argument_list|)
end_macro

begin_block
block|{
name|WINDOWLIST
modifier|*
name|p
decl_stmt|;
name|_nc_lock_global
argument_list|(
name|windowlist
argument_list|)
expr_stmt|;
for|for
control|(
name|each_window
argument_list|(
name|p
argument_list|)
control|)
block|{
if|if
condition|(
operator|&
operator|(
name|p
operator|->
name|win
operator|)
operator|==
name|win
condition|)
block|{
name|_nc_mutex_lock
argument_list|(
operator|&
operator|(
name|p
operator|->
name|mutex_use_window
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_unlock_window
argument_list|(
argument|const WINDOW *win
argument_list|)
end_macro

begin_block
block|{
name|WINDOWLIST
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|each_window
argument_list|(
name|p
argument_list|)
control|)
block|{
if|if
condition|(
operator|&
operator|(
name|p
operator|->
name|win
operator|)
operator|==
name|win
condition|)
block|{
name|_nc_mutex_unlock
argument_list|(
operator|&
operator|(
name|p
operator|->
name|mutex_use_window
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|_nc_unlock_global
argument_list|(
name|windowlist
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|use_window
argument_list|(
argument|WINDOW *win
argument_list|,
argument|NCURSES_WINDOW_CB func
argument_list|,
argument|void *data
argument_list|)
end_macro

begin_block
block|{
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
literal|"use_window(%p,%p,%p)"
argument_list|)
operator|,
name|win
operator|,
name|func
operator|,
name|data
operator|)
argument_list|)
expr_stmt|;
name|_nc_lock_window
argument_list|(
name|win
argument_list|)
expr_stmt|;
name|code
operator|=
name|func
argument_list|(
name|win
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|_nc_unlock_window
argument_list|(
name|win
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

