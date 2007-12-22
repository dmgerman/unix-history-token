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
literal|"$Id: fld_just.c,v 1.11 2004/12/11 22:55:48 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_field_just(FIELD *field, int just) |    |   Description   :  Set the fields type of justification. | |   Return Values :  E_OK            - success |                    E_BAD_ARGUMENT  - one of the arguments was incorrect |                    E_SYSTEM_ERROR  - system error +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_field_just
argument_list|(
argument|FIELD *field
argument_list|,
argument|int just
argument_list|)
end_macro

begin_block
block|{
name|int
name|res
init|=
name|E_BAD_ARGUMENT
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_field_just(%p,%d)"
argument_list|)
operator|,
name|field
operator|,
name|just
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|just
operator|==
name|NO_JUSTIFICATION
operator|)
operator|||
operator|(
name|just
operator|==
name|JUSTIFY_LEFT
operator|)
operator|||
operator|(
name|just
operator|==
name|JUSTIFY_CENTER
operator|)
operator|||
operator|(
name|just
operator|==
name|JUSTIFY_RIGHT
operator|)
condition|)
block|{
name|Normalize_Field
argument_list|(
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
name|field
operator|->
name|just
operator|!=
name|just
condition|)
block|{
name|field
operator|->
name|just
operator|=
name|just
expr_stmt|;
name|res
operator|=
name|_nc_Synchronize_Attributes
argument_list|(
name|field
argument_list|)
expr_stmt|;
block|}
else|else
name|res
operator|=
name|E_OK
expr_stmt|;
block|}
name|RETURN
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int field_just( const FIELD *field ) |    |   Description   :  Retrieve the fields type of justification | |   Return Values :  The justification type. +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|field_just
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
literal|"field_just(%p)"
argument_list|)
operator|,
name|field
operator|)
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|Normalize_Field
argument_list|(
name|field
argument_list|)
operator|->
name|just
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_just.c ends here */
end_comment

end_unit

