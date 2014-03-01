begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2012 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__WIDECHARS_H
end_ifndef

begin_define
define|#
directive|define
name|__WIDECHARS_H
value|1
end_define

begin_include
include|#
directive|include
file|<test.priv.h>
end_include

begin_if
if|#
directive|if
name|USE_WIDEC_SUPPORT
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_comment
comment|/*  * MinGW has wide-character functions, but they do not work correctly.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|_nc_mbtowc
parameter_list|(
name|wchar_t
modifier|*
name|pwc
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__MINGW_NOTHROW
name|_nc_mbtowc
parameter_list|(
name|wchar_t
modifier|*
name|pwc
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mbtowc
parameter_list|(
name|pwc
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|_nc_mbtowc(pwc,s,n)
end_define

begin_function_decl
specifier|extern
name|int
name|__MINGW_NOTHROW
name|_nc_mblen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mblen
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|_nc_mblen(s, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_if
if|#
directive|if
name|HAVE_MBTOWC
operator|&&
name|HAVE_MBLEN
end_if

begin_define
define|#
directive|define
name|reset_mbytes
parameter_list|(
name|state
parameter_list|)
value|IGNORE_RC(mblen(NULL, 0)), IGNORE_RC(mbtowc(NULL, NULL, 0))
end_define

begin_define
define|#
directive|define
name|count_mbytes
parameter_list|(
name|buffer
parameter_list|,
name|length
parameter_list|,
name|state
parameter_list|)
value|mblen(buffer,length)
end_define

begin_define
define|#
directive|define
name|check_mbytes
parameter_list|(
name|wch
parameter_list|,
name|buffer
parameter_list|,
name|length
parameter_list|,
name|state
parameter_list|)
define|\
value|(int) mbtowc(&wch, buffer, length)
end_define

begin_define
define|#
directive|define
name|state_unused
end_define

begin_elif
elif|#
directive|elif
name|HAVE_MBRTOWC
operator|&&
name|HAVE_MBRLEN
end_elif

begin_define
define|#
directive|define
name|reset_mbytes
parameter_list|(
name|state
parameter_list|)
value|init_mb(state)
end_define

begin_define
define|#
directive|define
name|count_mbytes
parameter_list|(
name|buffer
parameter_list|,
name|length
parameter_list|,
name|state
parameter_list|)
value|mbrlen(buffer,length,&state)
end_define

begin_define
define|#
directive|define
name|check_mbytes
parameter_list|(
name|wch
parameter_list|,
name|buffer
parameter_list|,
name|length
parameter_list|,
name|state
parameter_list|)
define|\
value|(int) mbrtowc(&wch, buffer, length,&state)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|make
name|an
name|error
endif|#
directive|endif
else|#
directive|else
endif|#
directive|endif
comment|/* USE_WIDEC_SUPPORT */
specifier|extern
name|void
name|widechars_stub
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __WIDECHARS_H */
end_comment

end_unit

