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
literal|"$Id: fld_arg.c,v 1.4 1999/05/16 17:16:04 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_fieldtype_arg( |                            FIELDTYPE *typ, |                            void * (* const make_arg)(va_list *), |                            void * (* const copy_arg)(const void *), |                            void   (* const free_arg)(void *) ) |    |   Description   :  Connects to the type additional arguments necessary |                    for a set_field_type call. The various function pointer |                    arguments are: |                       make_arg : allocates a structure for the field |                                  specific parameters. |                       copy_arg : duplicate the structure created by |                                  make_arg |                       free_arg : Release the memory allocated by make_arg |                                  or copy_arg | |                    At least make_arg must be non-NULL. |                    You may pass NULL for copy_arg and free_arg if your |                    make_arg function doesn't allocate memory and your |                    arg fits into the storage for a (void*). | |   Return Values :  E_OK           - success |                    E_BAD_ARGUMENT - invalid argument +--------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
name|int
name|set_fieldtype_arg
argument_list|(
name|FIELDTYPE
operator|*
name|typ
argument_list|,
name|void
operator|*
operator|(
operator|*
specifier|const
name|make_arg
operator|)
operator|(
name|va_list
operator|*
operator|)
argument_list|,
name|void
operator|*
operator|(
operator|*
specifier|const
name|copy_arg
operator|)
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|,
name|void
argument_list|(
operator|*
specifier|const
name|free_arg
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
block|{
if|if
condition|(
operator|!
name|typ
operator|||
operator|!
name|make_arg
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
name|_HAS_ARGS
expr_stmt|;
name|typ
operator|->
name|makearg
operator|=
name|make_arg
expr_stmt|;
name|typ
operator|->
name|copyarg
operator|=
name|copy_arg
expr_stmt|;
name|typ
operator|->
name|freearg
operator|=
name|free_arg
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  void *field_arg(const FIELD *field) |    |   Description   :  Retrieve pointer to the fields argument structure. | |   Return Values :  Pointer to structure or NULL if none is defined. +--------------------------------------------------------------------------*/
end_comment

begin_function
name|void
modifier|*
name|field_arg
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
name|arg
return|;
block|}
end_function

begin_comment
comment|/* fld_arg.c ends here */
end_comment

end_unit

