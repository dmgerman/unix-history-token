begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1997                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Module that "owns" the 'cur_term' variable:  *  *	TERMINAL *set_curterm(TERMINAL *)  *	int del_curterm(TERMINAL *)  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term_entry.h>
end_include

begin_comment
comment|/* TTY, cur_term */
end_comment

begin_include
include|#
directive|include
file|<termcap.h>
end_include

begin_comment
comment|/* ospeed */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_cur_term.c,v 1.9 1999/10/30 23:00:16 tom Exp $"
argument_list|)
end_macro

begin_decl_stmt
name|TERMINAL
modifier|*
name|cur_term
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|TERMINAL
modifier|*
name|set_curterm
parameter_list|(
name|TERMINAL
modifier|*
name|termp
parameter_list|)
block|{
name|TERMINAL
modifier|*
name|oldterm
init|=
name|cur_term
decl_stmt|;
if|if
condition|(
operator|(
name|cur_term
operator|=
name|termp
operator|)
operator|!=
literal|0
condition|)
block|{
name|ospeed
operator|=
name|_nc_ospeed
argument_list|(
name|cur_term
operator|->
name|_baudrate
argument_list|)
expr_stmt|;
name|PC
operator|=
operator|(
name|pad_char
operator|!=
name|NULL
operator|)
condition|?
name|pad_char
index|[
literal|0
index|]
else|:
literal|0
expr_stmt|;
block|}
return|return
name|oldterm
return|;
block|}
end_function

begin_function
name|int
name|del_curterm
parameter_list|(
name|TERMINAL
modifier|*
name|termp
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"del_curterm(%p)"
argument_list|)
operator|,
name|termp
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|termp
operator|!=
literal|0
condition|)
block|{
name|_nc_free_termtype
argument_list|(
operator|&
operator|(
name|termp
operator|->
name|type
operator|)
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|termp
argument_list|)
expr_stmt|;
if|if
condition|(
name|termp
operator|==
name|cur_term
condition|)
name|cur_term
operator|=
literal|0
expr_stmt|;
name|returnCode
argument_list|(
name|OK
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

