begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
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
literal|"$Id: fld_stat.c,v 1.7 2000/12/10 02:09:38 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_field_status(FIELD *field, bool status) |    |   Description   :  Set or clear the 'changed' indication flag for that |                    fields primary buffer. | |   Return Values :  E_OK            - success +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_field_status
argument_list|(
argument|FIELD * field
argument_list|,
argument|bool status
argument_list|)
end_macro

begin_block
block|{
name|Normalize_Field
argument_list|(
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
name|field
operator|->
name|status
operator||=
name|_CHANGED
expr_stmt|;
else|else
name|field
operator|->
name|status
operator|&=
operator|~
name|_CHANGED
expr_stmt|;
return|return
operator|(
name|E_OK
operator|)
return|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  bool field_status(const FIELD *field) |    |   Description   :  Retrieve the value of the 'changed' indication flag |                    for that fields primary buffer.  | |   Return Values :  TRUE  - buffer has been changed |                    FALSE - buffer has not been changed +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|field_status
argument_list|(
argument|const FIELD * field
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
operator|(
name|Normalize_Field
argument_list|(
name|field
argument_list|)
operator|->
name|status
operator|&
name|_CHANGED
operator|)
condition|?
name|TRUE
else|:
name|FALSE
operator|)
return|;
block|}
end_block

begin_comment
comment|/* fld_stat.c ends here */
end_comment

end_unit

