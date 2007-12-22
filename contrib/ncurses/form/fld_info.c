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
literal|"$Id: fld_info.c,v 1.10 2004/12/11 22:24:57 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int field_info(const FIELD *field, |                                   int *rows, int *cols, |                                   int *frow, int *fcol, |                                   int *nrow, int *nbuf) |    |   Description   :  Retrieve infos about the fields creation parameters. | |   Return Values :  E_OK           - success |                    E_BAD_ARGUMENT - invalid field pointer +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|field_info
argument_list|(
argument|const FIELD *field
argument_list|,
argument|int *rows
argument_list|,
argument|int *cols
argument_list|,
argument|int *frow
argument_list|,
argument|int *fcol
argument_list|,
argument|int *nrow
argument_list|,
argument|int *nbuf
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"field_info(%p,%p,%p,%p,%p,%p,%p)"
argument_list|)
operator|,
name|field
operator|,
name|rows
operator|,
name|cols
operator|,
name|frow
operator|,
name|fcol
operator|,
name|nrow
operator|,
name|nbuf
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|field
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|rows
condition|)
operator|*
name|rows
operator|=
name|field
operator|->
name|rows
expr_stmt|;
if|if
condition|(
name|cols
condition|)
operator|*
name|cols
operator|=
name|field
operator|->
name|cols
expr_stmt|;
if|if
condition|(
name|frow
condition|)
operator|*
name|frow
operator|=
name|field
operator|->
name|frow
expr_stmt|;
if|if
condition|(
name|fcol
condition|)
operator|*
name|fcol
operator|=
name|field
operator|->
name|fcol
expr_stmt|;
if|if
condition|(
name|nrow
condition|)
operator|*
name|nrow
operator|=
name|field
operator|->
name|nrow
expr_stmt|;
if|if
condition|(
name|nbuf
condition|)
operator|*
name|nbuf
operator|=
name|field
operator|->
name|nbuf
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int dynamic_field_info(const FIELD *field, |                                           int *drows, int *dcols, |                                           int *maxgrow) |    |   Description   :  Retrieve informations about a dynamic fields current |                    dynamic parameters. | |   Return Values :  E_OK           - success |                    E_BAD_ARGUMENT - invalid argument +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|dynamic_field_info
argument_list|(
argument|const FIELD *field
argument_list|,
argument|int *drows
argument_list|,
argument|int *dcols
argument_list|,
argument|int *maxgrow
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"dynamic_field_info(%p,%p,%p,%p)"
argument_list|)
operator|,
name|field
operator|,
name|drows
operator|,
name|dcols
operator|,
name|maxgrow
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|field
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|drows
condition|)
operator|*
name|drows
operator|=
name|field
operator|->
name|drows
expr_stmt|;
if|if
condition|(
name|dcols
condition|)
operator|*
name|dcols
operator|=
name|field
operator|->
name|dcols
expr_stmt|;
if|if
condition|(
name|maxgrow
condition|)
operator|*
name|maxgrow
operator|=
name|field
operator|->
name|maxgrow
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* fld_info.c ends here */
end_comment

end_unit

