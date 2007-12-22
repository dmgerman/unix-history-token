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
literal|"$Id: fld_move.c,v 1.9 2004/12/11 21:52:44 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int move_field(FIELD *field,int frow, int fcol) |    |   Description   :  Moves the disconnected field to the new location in |                    the forms subwindow. | |   Return Values :  E_OK            - success |                    E_BAD_ARGUMENT  - invalid argument passed |                    E_CONNECTED     - field is connected +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|move_field
argument_list|(
argument|FIELD *field
argument_list|,
argument|int frow
argument_list|,
argument|int fcol
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"move_field(%p,%d,%d)"
argument_list|)
operator|,
name|field
operator|,
name|frow
operator|,
name|fcol
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|field
operator|||
operator|(
name|frow
operator|<
literal|0
operator|)
operator|||
operator|(
name|fcol
operator|<
literal|0
operator|)
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|field
operator|->
name|form
condition|)
name|RETURN
argument_list|(
name|E_CONNECTED
argument_list|)
expr_stmt|;
name|field
operator|->
name|frow
operator|=
name|frow
expr_stmt|;
name|field
operator|->
name|fcol
operator|=
name|fcol
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_move.c ends here */
end_comment

end_unit

