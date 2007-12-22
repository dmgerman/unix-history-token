begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2005,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * clear.c --  clears the terminal's screen  */
end_comment

begin_include
include|#
directive|include
file|<progs.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: clear.c,v 1.10 2006/05/20 17:47:47 tom Exp $"
argument_list|)
end_macro

begin_function
specifier|static
name|int
name|putch
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|putchar
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
name|GCC_UNUSED
parameter_list|,
name|char
modifier|*
name|argv
index|[]
name|GCC_UNUSED
parameter_list|)
block|{
name|setupterm
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|STDOUT_FILENO
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|ExitProgram
argument_list|(
operator|(
name|tputs
argument_list|(
name|clear_screen
argument_list|,
name|lines
operator|>
literal|0
condition|?
name|lines
else|:
literal|1
argument_list|,
name|putch
argument_list|)
operator|==
name|ERR
operator|)
condition|?
name|EXIT_FAILURE
else|:
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

