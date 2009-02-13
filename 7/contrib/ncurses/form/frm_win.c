begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"form.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: frm_win.c,v 1.13 2004/12/11 22:15:27 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_form_win(FORM *form,WINDOW *win) |    |   Description   :  Set the window of the form to win.  | |   Return Values :  E_OK       - success |                    E_POSTED   - form is posted +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_form_win
argument_list|(
argument|FORM *form
argument_list|,
argument|WINDOW *win
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_form_win(%p,%p)"
argument_list|)
operator|,
name|form
operator|,
name|win
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|form
operator|&&
operator|(
name|form
operator|->
name|status
operator|&
name|_POSTED
operator|)
condition|)
name|RETURN
argument_list|(
name|E_POSTED
argument_list|)
expr_stmt|;
name|Normalize_Form
argument_list|(
name|form
argument_list|)
operator|->
name|win
operator|=
name|win
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  WINDOW *form_win(const FORM *) |    |   Description   :  Retrieve the window of the form. | |   Return Values :  The pointer to the Window or stdscr if there is none. +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_macro
name|form_win
argument_list|(
argument|const FORM *form
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|FORM
modifier|*
name|f
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"form_win(%p)"
argument_list|)
operator|,
name|form
operator|)
argument_list|)
expr_stmt|;
name|f
operator|=
name|Normalize_Form
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|returnWin
argument_list|(
name|f
operator|->
name|win
condition|?
name|f
operator|->
name|win
else|:
name|stdscr
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* frm_win.c ends here */
end_comment

end_unit

