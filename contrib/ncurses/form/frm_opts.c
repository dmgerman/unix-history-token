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
literal|"$Id: frm_opts.c,v 1.8 1999/05/16 17:38:05 juergen Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int set_form_opts(FORM *form, Form_Options opts) |    |   Description   :  Turns on the named options and turns off all the |                    remaining options for that form. | |   Return Values :  E_OK              - success |                    E_BAD_ARGUMENT    - invalid options +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|set_form_opts
parameter_list|(
name|FORM
modifier|*
name|form
parameter_list|,
name|Form_Options
name|opts
parameter_list|)
block|{
name|opts
operator|&=
name|ALL_FORM_OPTS
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_FORM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
else|else
block|{
name|Normalize_Form
argument_list|(
name|form
argument_list|)
operator|->
name|opts
operator|=
name|opts
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  Form_Options form_opts(const FORM *) |    |   Description   :  Retrieves the current form options. | |   Return Values :  The option flags. +--------------------------------------------------------------------------*/
end_comment

begin_function
name|Form_Options
name|form_opts
parameter_list|(
specifier|const
name|FORM
modifier|*
name|form
parameter_list|)
block|{
return|return
operator|(
name|Normalize_Form
argument_list|(
name|form
argument_list|)
operator|->
name|opts
operator|&
name|ALL_FORM_OPTS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int form_opts_on(FORM *form, Form_Options opts) |    |   Description   :  Turns on the named options; no other options are  |                    changed. | |   Return Values :  E_OK            - success  |                    E_BAD_ARGUMENT  - invalid options +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|form_opts_on
parameter_list|(
name|FORM
modifier|*
name|form
parameter_list|,
name|Form_Options
name|opts
parameter_list|)
block|{
name|opts
operator|&=
name|ALL_FORM_OPTS
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_FORM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
else|else
block|{
name|Normalize_Form
argument_list|(
name|form
argument_list|)
operator|->
name|opts
operator||=
name|opts
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnform   |   Function      :  int form_opts_off(FORM *form, Form_Options opts) |    |   Description   :  Turns off the named options; no other options are  |                    changed. | |   Return Values :  E_OK            - success  |                    E_BAD_ARGUMENT  - invalid options +--------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|form_opts_off
parameter_list|(
name|FORM
modifier|*
name|form
parameter_list|,
name|Form_Options
name|opts
parameter_list|)
block|{
name|opts
operator|&=
name|ALL_FORM_OPTS
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_FORM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
else|else
block|{
name|Normalize_Form
argument_list|(
name|form
argument_list|)
operator|->
name|opts
operator|&=
operator|~
name|opts
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* frm_opts.c ends here */
end_comment

end_unit

