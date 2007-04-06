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
literal|"$Id: fld_type.c,v 1.15 2004/12/25 22:24:10 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_field_type(FIELD *field, FIELDTYPE *type,...) |    |   Description   :  Associate the specified fieldtype with the field. |                    Certain field types take additional arguments. Look |                    at the spec of the field types ! | |   Return Values :  E_OK           - success |                    E_SYSTEM_ERROR - system error +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_field_type
argument_list|(
argument|FIELD *field
argument_list|,
argument|FIELDTYPE *type
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|res
init|=
name|E_SYSTEM_ERROR
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_field_type(%p,%p)"
argument_list|)
operator|,
name|field
operator|,
name|type
operator|)
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|Normalize_Field
argument_list|(
name|field
argument_list|)
expr_stmt|;
name|_nc_Free_Type
argument_list|(
name|field
argument_list|)
expr_stmt|;
name|field
operator|->
name|type
operator|=
name|type
expr_stmt|;
name|field
operator|->
name|arg
operator|=
operator|(
name|void
operator|*
operator|)
name|_nc_Make_Argument
argument_list|(
name|field
operator|->
name|type
argument_list|,
operator|&
name|ap
argument_list|,
operator|&
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|_nc_Free_Argument
argument_list|(
name|field
operator|->
name|type
argument_list|,
operator|(
name|TypeArgument
operator|*
operator|)
operator|(
name|field
operator|->
name|arg
operator|)
argument_list|)
expr_stmt|;
name|field
operator|->
name|type
operator|=
operator|(
name|FIELDTYPE
operator|*
operator|)
literal|0
expr_stmt|;
name|field
operator|->
name|arg
operator|=
operator|(
name|void
operator|*
operator|)
literal|0
expr_stmt|;
block|}
else|else
block|{
name|res
operator|=
name|E_OK
expr_stmt|;
if|if
condition|(
name|field
operator|->
name|type
condition|)
name|field
operator|->
name|type
operator|->
name|ref
operator|++
expr_stmt|;
block|}
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|RETURN
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  FIELDTYPE *field_type(const FIELD *field) |    |   Description   :  Retrieve the associated fieldtype for this field. | |   Return Values :  Pointer to fieldtype of NULL if none is defined. +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|FIELDTYPE *
argument_list|)
end_macro

begin_macro
name|field_type
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
literal|"field_type(%p)"
argument_list|)
operator|,
name|field
operator|)
argument_list|)
expr_stmt|;
name|returnFieldType
argument_list|(
name|Normalize_Field
argument_list|(
name|field
argument_list|)
operator|->
name|type
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_type.c ends here */
end_comment

end_unit

