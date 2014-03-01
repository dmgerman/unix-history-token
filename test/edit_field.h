begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2003-2006,2008 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: edit_field.h,v 1.6 2008/12/20 19:23:18 tom Exp $  *  * Interface of edit_field.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EDIT_FORM_H_incl
end_ifndef

begin_define
define|#
directive|define
name|EDIT_FORM_H_incl
value|1
end_define

begin_include
include|#
directive|include
file|<form.h>
end_include

begin_define
define|#
directive|define
name|EDIT_FIELD
parameter_list|(
name|c
parameter_list|)
value|(MAX_FORM_COMMAND + c)
end_define

begin_define
define|#
directive|define
name|MY_HELP
value|EDIT_FIELD('h')
end_define

begin_define
define|#
directive|define
name|MY_QUIT
value|EDIT_FIELD('q')
end_define

begin_define
define|#
directive|define
name|MY_EDT_MODE
value|EDIT_FIELD('e')
end_define

begin_define
define|#
directive|define
name|MY_INS_MODE
value|EDIT_FIELD('t')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|chtype
name|background
decl_stmt|;
block|}
name|FieldAttrs
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|help_edit_field
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|edit_field
parameter_list|(
name|FORM
modifier|*
name|form
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EDIT_FORM_H_incl */
end_comment

end_unit

