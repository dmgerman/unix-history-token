begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2009,2010 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
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
literal|"$Id: fld_newftyp.c,v 1.19 2010/01/23 21:14:36 tom Exp $"
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|FIELDTYPE
name|default_fieldtype
init|=
block|{
literal|0
block|,
comment|/* status                                      */
literal|0L
block|,
comment|/* reference count                             */
operator|(
name|FIELDTYPE
operator|*
operator|)
literal|0
block|,
comment|/* pointer to left  operand                    */
operator|(
name|FIELDTYPE
operator|*
operator|)
literal|0
block|,
comment|/* pointer to right operand                    */
name|NULL
block|,
comment|/* makearg function                            */
name|NULL
block|,
comment|/* copyarg function                            */
name|NULL
block|,
comment|/* freearg function                            */
name|INIT_FT_FUNC
argument_list|(
name|NULL
argument_list|)
block|,
comment|/* field validation function                   */
name|INIT_FT_FUNC
argument_list|(
name|NULL
argument_list|)
block|,
comment|/* Character check function                    */
name|INIT_FT_FUNC
argument_list|(
name|NULL
argument_list|)
block|,
comment|/* enumerate next function                     */
name|INIT_FT_FUNC
argument_list|(
name|NULL
argument_list|)
block|,
comment|/* enumerate previous function                 */
if|#
directive|if
name|NCURSES_INTEROP_FUNCS
name|NULL
comment|/* generic callback alternative to makearg     */
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|FIELDTYPE *
argument_list|)
end_macro

begin_expr_stmt
name|_nc_Default_FieldType
operator|=
operator|&
name|default_fieldtype
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform |   Function      :  FIELDTYPE *new_fieldtype( |                       bool (* const field_check)(FIELD *,const void *), |                       bool (* const char_check) (int, const void *) ) | |   Description   :  Create a new fieldtype. The application programmer must |                    write a field_check and a char_check function and give |                    them as input to this call. |                    If an error occurs, errno is set to |                       E_BAD_ARGUMENT  - invalid arguments |                       E_SYSTEM_ERROR  - system error (no memory) | |   Return Values :  Fieldtype pointer or NULL if error occurred +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|FIELDTYPE *
argument_list|)
end_macro

begin_macro
name|new_fieldtype
argument_list|(
argument|bool (*const field_check) (FIELD *, const void *)
argument_list|,
argument|bool (*const char_check) (int, const void *)
argument_list|)
end_macro

begin_block
block|{
name|FIELDTYPE
modifier|*
name|nftyp
init|=
operator|(
name|FIELDTYPE
operator|*
operator|)
literal|0
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"new_fieldtype(%p,%p)"
argument_list|)
operator|,
name|field_check
operator|,
name|char_check
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|field_check
operator|)
operator|||
operator|(
name|char_check
operator|)
condition|)
block|{
name|nftyp
operator|=
name|typeMalloc
argument_list|(
name|FIELDTYPE
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|nftyp
condition|)
block|{
name|T
argument_list|(
operator|(
name|T_CREATE
argument_list|(
literal|"fieldtype %p"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|nftyp
operator|)
argument_list|)
expr_stmt|;
operator|*
name|nftyp
operator|=
name|default_fieldtype
expr_stmt|;
if|#
directive|if
name|NCURSES_INTEROP_FUNCS
name|nftyp
operator|->
name|fieldcheck
operator|.
name|ofcheck
operator|=
name|field_check
expr_stmt|;
name|nftyp
operator|->
name|charcheck
operator|.
name|occheck
operator|=
name|char_check
expr_stmt|;
else|#
directive|else
name|nftyp
operator|->
name|fcheck
operator|=
name|field_check
expr_stmt|;
name|nftyp
operator|->
name|ccheck
operator|=
name|char_check
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|SET_ERROR
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|SET_ERROR
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
block|}
name|returnFieldType
argument_list|(
name|nftyp
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform |   Function      :  int free_fieldtype(FIELDTYPE *typ) | |   Description   :  Release the memory associated with this fieldtype. | |   Return Values :  E_OK            - success |                    E_CONNECTED     - there are fields referencing the type |                    E_BAD_ARGUMENT  - invalid fieldtype pointer +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|free_fieldtype
argument_list|(
argument|FIELDTYPE *typ
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"free_fieldtype(%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|typ
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|typ
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|typ
operator|->
name|ref
operator|!=
literal|0
condition|)
name|RETURN
argument_list|(
name|E_CONNECTED
argument_list|)
expr_stmt|;
if|if
condition|(
name|typ
operator|->
name|status
operator|&
name|_RESIDENT
condition|)
name|RETURN
argument_list|(
name|E_CONNECTED
argument_list|)
expr_stmt|;
if|if
condition|(
name|typ
operator|->
name|status
operator|&
name|_LINKED_TYPE
condition|)
block|{
if|if
condition|(
name|typ
operator|->
name|left
condition|)
name|typ
operator|->
name|left
operator|->
name|ref
operator|--
expr_stmt|;
if|if
condition|(
name|typ
operator|->
name|right
condition|)
name|typ
operator|->
name|right
operator|->
name|ref
operator|--
expr_stmt|;
block|}
name|free
argument_list|(
name|typ
argument_list|)
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_newftyp.c ends here */
end_comment

end_unit

