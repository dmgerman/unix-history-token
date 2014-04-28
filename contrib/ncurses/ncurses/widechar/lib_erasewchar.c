begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2002-2010,2014 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey 2002                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_erasewchar.c,v 1.3 2014/02/23 01:21:08 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  *	erasewchar()  *  *	Return erase character as given in cur_term->Ottyb.  *  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|erasewchar
argument_list|(
argument|wchar_t *wch
argument_list|)
end_macro

begin_block
block|{
name|int
name|value
decl_stmt|;
name|int
name|result
init|=
name|ERR
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"erasewchar()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|value
operator|=
name|erasechar
argument_list|()
operator|)
operator|!=
name|ERR
condition|)
block|{
operator|*
name|wch
operator|=
operator|(
name|wchar_t
operator|)
name|value
expr_stmt|;
name|result
operator|=
name|OK
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	killwchar()  *  *	Return kill character as given in cur_term->Ottyb.  *  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|killwchar
argument_list|(
argument|wchar_t *wch
argument_list|)
end_macro

begin_block
block|{
name|int
name|value
decl_stmt|;
name|int
name|result
init|=
name|ERR
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"killwchar()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|value
operator|=
name|killchar
argument_list|()
operator|)
operator|!=
name|ERR
condition|)
block|{
operator|*
name|wch
operator|=
operator|(
name|wchar_t
operator|)
name|value
expr_stmt|;
name|result
operator|=
name|OK
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

