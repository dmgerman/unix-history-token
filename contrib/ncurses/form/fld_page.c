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
literal|"$Id: fld_page.c,v 1.9 2004/12/11 21:58:19 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_new_page(FIELD *field, bool new_page_flag) |    |   Description   :  Marks the field as the beginning of a new page of  |                    the form. | |   Return Values :  E_OK         - success |                    E_CONNECTED  - field is connected +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_new_page
argument_list|(
argument|FIELD *field
argument_list|,
argument|bool new_page_flag
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_new_page(%p,%d)"
argument_list|)
operator|,
name|field
operator|,
name|new_page_flag
operator|)
argument_list|)
expr_stmt|;
name|Normalize_Field
argument_list|(
name|field
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
if|if
condition|(
name|new_page_flag
condition|)
name|field
operator|->
name|status
operator||=
name|_NEWPAGE
expr_stmt|;
else|else
name|field
operator|->
name|status
operator|&=
operator|~
name|_NEWPAGE
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  bool new_page(const FIELD *field) |    |   Description   :  Retrieve the info whether or not the field starts a |                    new page on the form. | |   Return Values :  TRUE  - field starts a new page |                    FALSE - field doesn't start a new page +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|new_page
argument_list|(
argument|const FIELD *field
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"new_page(%p)"
argument_list|)
operator|,
name|field
operator|)
argument_list|)
expr_stmt|;
name|returnBool
argument_list|(
operator|(
name|Normalize_Field
argument_list|(
name|field
argument_list|)
operator|->
name|status
operator|&
name|_NEWPAGE
operator|)
condition|?
name|TRUE
else|:
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_page.c ends here */
end_comment

end_unit

