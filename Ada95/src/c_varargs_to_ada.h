begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2011 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: c_varargs_to_ada.h,v 1.3 2011/03/19 19:07:41 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__C_VARARGS_TO_ADA_H
end_ifndef

begin_define
define|#
directive|define
name|__C_VARARGS_TO_ADA_H
end_define

begin_include
include|#
directive|include
file|<form.h>
end_include

begin_function_decl
specifier|extern
name|int
name|set_field_type_alnum
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|int
comment|/* minimum_width */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_alpha
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|int
comment|/* minimum_width */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_enum
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* value_list */
parameter_list|,
name|int
comment|/* case_sensitive */
parameter_list|,
name|int
comment|/* unique_match */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_integer
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|int
comment|/* precision */
parameter_list|,
name|long
comment|/* minimum */
parameter_list|,
name|long
comment|/* maximum */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_numeric
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|int
comment|/* precision */
parameter_list|,
name|double
comment|/* minimum */
parameter_list|,
name|double
comment|/* maximum */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_regexp
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|char
modifier|*
comment|/* regular_expression */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_ipv4
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_field_type_user
parameter_list|(
name|FIELD
modifier|*
comment|/* field */
parameter_list|,
name|FIELDTYPE
modifier|*
comment|/* fieldtype */
parameter_list|,
name|void
modifier|*
comment|/* arg */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|void_star_make_arg
parameter_list|(
name|va_list
modifier|*
comment|/* list */
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_traces
parameter_list|(
specifier|const
name|char
modifier|*
comment|/* fmt */
parameter_list|,
name|char
modifier|*
comment|/* arg */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __C_VARARGS_TO_ADA_H */
end_comment

end_unit

