begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1995,1997            *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"form.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: frm_cursor.c,v 1.4 1999/05/16 17:20:19 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int pos_form_cursor(FORM * form) |    |   Description   :  Moves the form window cursor to the location required |                    by the form driver to resume form processing. This may |                    be needed after the application calls a curses library |                    I/O routine that modifies the cursor position. | |   Return Values :  E_OK                      - Success |                    E_SYSTEM_ERROR            - System error. |                    E_BAD_ARGUMENT            - Invalid form pointer |                    E_NOT_POSTED              - Form is not posted +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|pos_form_cursor
parameter_list|(
name|FORM
modifier|*
name|form
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
if|if
condition|(
operator|!
name|form
condition|)
name|res
operator|=
name|E_BAD_ARGUMENT
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|!
operator|(
name|form
operator|->
name|status
operator|&
name|_POSTED
operator|)
condition|)
name|res
operator|=
name|E_NOT_POSTED
expr_stmt|;
else|else
name|res
operator|=
name|_nc_Position_Form_Cursor
argument_list|(
name|form
argument_list|)
expr_stmt|;
block|}
name|RETURN
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* frm_cursor.c ends here */
end_comment

end_unit

