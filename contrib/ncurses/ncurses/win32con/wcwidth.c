begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2010 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: wcwidth.c,v 1.2 2010/08/07 20:52:43 tom Exp $"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|USE_WIDEC_SUPPORT
end_if

begin_define
define|#
directive|define
name|mk_wcwidth
parameter_list|(
name|ucs
parameter_list|)
value|_nc_wcwidth(ucs)
end_define

begin_define
define|#
directive|define
name|mk_wcswidth
parameter_list|(
name|pwcs
parameter_list|,
name|n
parameter_list|)
value|_nc_wcswidth(pwcs, n)
end_define

begin_define
define|#
directive|define
name|mk_wcwidth_cjk
parameter_list|(
name|ucs
parameter_list|)
value|_nc_wcwidth_cjk(ucs)
end_define

begin_define
define|#
directive|define
name|mk_wcswidth_cjk
parameter_list|(
name|pwcs
parameter_list|,
name|n
parameter_list|)
value|_nc_wcswidth_cjk(pwcs, n)
end_define

begin_function_decl
specifier|extern
name|int
name|mk_wcwidth
parameter_list|(
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mk_wcswidth
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mk_wcwidth_cjk
parameter_list|(
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mk_wcswidth_cjk
parameter_list|(
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<wcwidth.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|_nc_empty_wcwidth
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_nc_empty_wcwidth
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

