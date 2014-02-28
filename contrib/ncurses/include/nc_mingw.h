begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2008-2009,2010 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  * Author: Thomas Dickey, 2008-on                                           *   *                                                                          *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: nc_mingw.h,v 1.3 2010/09/25 22:16:12 juergen Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NC_MINGW_H
end_ifndef

begin_define
define|#
directive|define
name|NC_MINGW_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WINVER
end_ifdef

begin_if
if|#
directive|if
name|WINVER
operator|<
literal|0x0501
end_if

begin_error
error|#
directive|error
error|WINVER must at least be 0x0501
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WINVER
value|0x0501
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_undef
undef|#
directive|undef
name|sleep
end_undef

begin_define
define|#
directive|define
name|sleep
parameter_list|(
name|n
parameter_list|)
value|Sleep((n) * 1000)
end_define

begin_undef
undef|#
directive|undef
name|gettimeofday
end_undef

begin_define
define|#
directive|define
name|gettimeofday
parameter_list|(
name|tv
parameter_list|,
name|tz
parameter_list|)
value|_nc_gettimeofday(tv,tz)
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* for struct timeval */
end_comment

begin_function_decl
specifier|extern
name|int
name|_nc_gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|HAVE_GETTIMEOFDAY
end_undef

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|getlogin
parameter_list|()
value|"username"
end_define

begin_undef
undef|#
directive|undef
name|wcwidth
end_undef

begin_define
define|#
directive|define
name|wcwidth
parameter_list|(
name|ucs
parameter_list|)
value|_nc_wcwidth(ucs)
end_define

begin_function_decl
specifier|extern
name|int
name|_nc_wcwidth
parameter_list|(
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NC_MINGW_H */
end_comment

end_unit

