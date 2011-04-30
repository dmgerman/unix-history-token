begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2007,2008 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  * Author: Juergen Pfeifer, 2008-on                                         *   *                                                                          *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: ncurses_mingw.h,v 1.1 2008/12/14 19:22:16 juergen Exp $ */
end_comment

begin_comment
comment|/*  * This is a placholder up to now and describes what needs to be implemented  * to support I/O to external terminals with ncurses on the Windows OS.  */
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

begin_comment
comment|/* c_cc chars */
end_comment

begin_define
define|#
directive|define
name|VINTR
value|0
end_define

begin_define
define|#
directive|define
name|VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|VERASE
value|2
end_define

begin_define
define|#
directive|define
name|VKILL
value|3
end_define

begin_define
define|#
directive|define
name|VEOF
value|4
end_define

begin_define
define|#
directive|define
name|VTIME
value|5
end_define

begin_define
define|#
directive|define
name|VMIN
value|6
end_define

begin_comment
comment|/* c_iflag bits */
end_comment

begin_define
define|#
directive|define
name|ISTRIP
value|0000040
end_define

begin_define
define|#
directive|define
name|INLCR
value|0000100
end_define

begin_define
define|#
directive|define
name|IGNCR
value|0000200
end_define

begin_define
define|#
directive|define
name|ICRNL
value|0000400
end_define

begin_define
define|#
directive|define
name|BRKINT
value|0000002
end_define

begin_define
define|#
directive|define
name|PARMRK
value|0000010
end_define

begin_define
define|#
directive|define
name|IXON
value|0002000
end_define

begin_define
define|#
directive|define
name|IGNBRK
value|0000001
end_define

begin_define
define|#
directive|define
name|IGNPAR
value|0000004
end_define

begin_define
define|#
directive|define
name|INPCK
value|0000020
end_define

begin_define
define|#
directive|define
name|IXOFF
value|0010000
end_define

begin_comment
comment|/* c_oflag bits */
end_comment

begin_define
define|#
directive|define
name|OPOST
value|0000001
end_define

begin_comment
comment|/* c_cflag bit meaning */
end_comment

begin_define
define|#
directive|define
name|CBAUD
value|0010017
end_define

begin_define
define|#
directive|define
name|CSIZE
value|0000060
end_define

begin_define
define|#
directive|define
name|CS8
value|0000060
end_define

begin_define
define|#
directive|define
name|B0
value|0000000
end_define

begin_define
define|#
directive|define
name|B50
value|0000001
end_define

begin_define
define|#
directive|define
name|B75
value|0000002
end_define

begin_define
define|#
directive|define
name|B110
value|0000003
end_define

begin_define
define|#
directive|define
name|B134
value|0000004
end_define

begin_define
define|#
directive|define
name|B150
value|0000005
end_define

begin_define
define|#
directive|define
name|B200
value|0000006
end_define

begin_define
define|#
directive|define
name|B300
value|0000007
end_define

begin_define
define|#
directive|define
name|B600
value|0000010
end_define

begin_define
define|#
directive|define
name|B1200
value|0000011
end_define

begin_define
define|#
directive|define
name|B1800
value|0000012
end_define

begin_define
define|#
directive|define
name|B2400
value|0000013
end_define

begin_define
define|#
directive|define
name|B4800
value|0000014
end_define

begin_define
define|#
directive|define
name|B9600
value|0000015
end_define

begin_define
define|#
directive|define
name|CLOCAL
value|0004000
end_define

begin_define
define|#
directive|define
name|CREAD
value|0000200
end_define

begin_define
define|#
directive|define
name|CSTOPB
value|0000100
end_define

begin_define
define|#
directive|define
name|HUPCL
value|0002000
end_define

begin_define
define|#
directive|define
name|PARENB
value|0000400
end_define

begin_define
define|#
directive|define
name|PARODD
value|0001000
end_define

begin_comment
comment|/* c_lflag bits */
end_comment

begin_define
define|#
directive|define
name|ECHO
value|0000010
end_define

begin_define
define|#
directive|define
name|ECHONL
value|0000100
end_define

begin_define
define|#
directive|define
name|ISIG
value|0000001
end_define

begin_define
define|#
directive|define
name|IEXTEN
value|0100000
end_define

begin_define
define|#
directive|define
name|ICANON
value|0000002
end_define

begin_define
define|#
directive|define
name|NOFLSH
value|0000200
end_define

begin_define
define|#
directive|define
name|ECHOE
value|0000020
end_define

begin_define
define|#
directive|define
name|ECHOK
value|0000040
end_define

begin_comment
comment|/* tcflush() */
end_comment

begin_define
define|#
directive|define
name|TCIFLUSH
value|0
end_define

begin_comment
comment|/* tcsetattr uses these */
end_comment

begin_define
define|#
directive|define
name|TCSADRAIN
value|1
end_define

begin_comment
comment|/* ioctls */
end_comment

begin_define
define|#
directive|define
name|TCGETA
value|0x5405
end_define

begin_define
define|#
directive|define
name|TCFLSH
value|0x540B
end_define

begin_define
define|#
directive|define
name|TIOCGWINSZ
value|0x5413
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|cfgetospeed
end_ifndef

begin_define
define|#
directive|define
name|cfgetospeed
parameter_list|(
name|t
parameter_list|)
value|((t)->c_cflag& CBAUD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tcsetattr
end_ifndef

begin_define
define|#
directive|define
name|tcsetattr
parameter_list|(
name|fd
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
value|_nc_mingw_ioctl(fd, cmd, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tcgetattr
end_ifndef

begin_define
define|#
directive|define
name|tcgetattr
parameter_list|(
name|fd
parameter_list|,
name|arg
parameter_list|)
value|_nc_mingw_ioctl(fd, TCGETA, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tcflush
end_ifndef

begin_define
define|#
directive|define
name|tcflush
parameter_list|(
name|fd
parameter_list|,
name|arg
parameter_list|)
value|_nc_mingw_ioctl(fd, TCFLSH, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ttyname
end_undef

begin_define
define|#
directive|define
name|ttyname
parameter_list|(
name|fd
parameter_list|)
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

