begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2011 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                        2011                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: nc_termios.h,v 1.2 2011/06/25 20:44:05 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NC_TERMIOS_included
end_ifndef

begin_define
define|#
directive|define
name|NC_TERMIOS_included
value|1
end_define

begin_if
if|#
directive|if
name|HAVE_TERMIOS_H
operator|&&
name|HAVE_TCGETATTR
end_if

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_TERMIOS_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_TERMIO_H
end_if

begin_comment
comment|/* Add definitions to make termio look like termios.  * But ifdef it, since there are some implementations  * that try to do this for us in a fake<termio.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCSADRAIN
end_ifndef

begin_define
define|#
directive|define
name|TCSADRAIN
value|TCSETAW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCSAFLUSH
end_ifndef

begin_define
define|#
directive|define
name|TCSAFLUSH
value|TCSETAF
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
value|ioctl(fd, cmd, arg)
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
value|ioctl(fd, TCGETA, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|TCIFLUSH
end_ifndef

begin_define
define|#
directive|define
name|TCIFLUSH
value|0
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
value|ioctl(fd, TCFLSH, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_TERMIO_H */
end_comment

begin_if
if|#
directive|if
name|__MINGW32__
end_if

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

begin_else
else|#
directive|else
end_else

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MINGW32__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TERMIO_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TERMIOS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NC_TERMIOS_included */
end_comment

end_unit

