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
literal|"$Id: fld_pad.c,v 1.4 1999/05/16 17:38:58 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_field_pad(FIELD *field, int ch) |    |   Description   :  Set the pad character used to fill the field. This must |                    be a printable character. | |   Return Values :  E_OK           - success |                    E_BAD_ARGUMENT - invalid field pointer or pad character |                    E_SYSTEM_ERROR - system error +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|set_field_pad
parameter_list|(
name|FIELD
modifier|*
name|field
parameter_list|,
name|int
name|ch
parameter_list|)
block|{
name|int
name|res
init|=
name|E_BAD_ARGUMENT
decl_stmt|;
name|Normalize_Field
argument_list|(
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
name|isprint
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|ch
argument_list|)
condition|)
block|{
if|if
condition|(
name|field
operator|->
name|pad
operator|!=
name|ch
condition|)
block|{
name|field
operator|->
name|pad
operator|=
name|ch
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
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int field_pad(const FIELD *field) |    |   Description   :  Retrieve the fields pad character. | |   Return Values :  The pad character. +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|field_pad
parameter_list|(
specifier|const
name|FIELD
modifier|*
name|field
parameter_list|)
block|{
return|return
name|Normalize_Field
argument_list|(
name|field
argument_list|)
operator|->
name|pad
return|;
block|}
end_function

begin_comment
comment|/* fld_pad.c ends here */
end_comment

end_unit

