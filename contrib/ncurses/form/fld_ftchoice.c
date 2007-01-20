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
literal|"$Id: fld_ftchoice.c,v 1.9 2004/12/11 21:44:57 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_fieldtype_choice( |                          FIELDTYPE *typ, |                          bool (* const next_choice)(FIELD *,const void *), |                          bool (* const prev_choice)(FIELD *,const void *)) | |   Description   :  Define implementation of enumeration requests. | |   Return Values :  E_OK           - success |                    E_BAD_ARGUMENT - invalid arguments +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_fieldtype_choice
argument_list|(
argument|FIELDTYPE *typ
argument_list|,
argument|bool (*const next_choice) (FIELD *, const void *)
argument_list|,
argument|bool (*const prev_choice) (FIELD *, const void *)
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_fieldtype_choice(%p,%p,%p)"
argument_list|)
operator|,
name|typ
operator|,
name|next_choice
operator|,
name|prev_choice
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|typ
operator|||
operator|!
name|next_choice
operator|||
operator|!
name|prev_choice
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
name|typ
operator|->
name|status
operator||=
name|_HAS_CHOICE
expr_stmt|;
name|typ
operator|->
name|next
operator|=
name|next_choice
expr_stmt|;
name|typ
operator|->
name|prev
operator|=
name|prev_choice
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_ftchoice.c ends here */
end_comment

end_unit

