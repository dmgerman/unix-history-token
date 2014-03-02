begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2008,2011 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  * Author: Juergen Pfeifer, 2008-on                                         *   *                                                                          *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: ncurses_mingw.h,v 1.2 2011/06/25 20:51:00 tom Exp $ */
end_comment

begin_comment
comment|/*  * This is a placeholder up to now and describes what needs to be implemented  * to support I/O to external terminals with ncurses on the Windows OS.  */
end_comment

begin_if
if|#
directive|if
name|__MINGW32__
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_NC_MINGWH
end_ifndef

begin_define
define|#
directive|define
name|_NC_MINGWH
end_define

begin_define
define|#
directive|define
name|USE_CONSOLE_DRIVER
value|1
end_define

begin_undef
undef|#
directive|undef
name|TERMIOS
end_undef

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_define
define|#
directive|define
name|InvalidHandle
value|((TERM_HANDLE)-1)
end_define

begin_define
define|#
directive|define
name|InvalidConsoleHandle
parameter_list|(
name|s
parameter_list|)
value|((s)==InvalidHandle)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|tcflag_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NCCS
value|32
end_define

begin_struct
struct|struct
name|termios
block|{
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|/* input mode         */
name|tcflag_t
name|c_oflag
decl_stmt|;
comment|/* output mode        */
name|tcflag_t
name|c_cflag
decl_stmt|;
comment|/* control mode       */
name|tcflag_t
name|c_lflag
decl_stmt|;
comment|/* local mode         */
name|cc_t
name|c_line
decl_stmt|;
comment|/* line discipline    */
name|cc_t
name|c_cc
index|[
name|NCCS
index|]
decl_stmt|;
comment|/* control characters */
name|speed_t
name|c_ispeed
decl_stmt|;
comment|/* input speed        */
name|speed_t
name|c_ospeed
decl_stmt|;
comment|/* c_ospeed           */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|_nc_mingw_ioctl
parameter_list|(
name|int
name|fd
parameter_list|,
name|long
name|int
name|request
parameter_list|,
name|struct
name|termios
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_set_term_driver
parameter_list|(
name|void
modifier|*
name|term
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NC_MINGWH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

end_unit

