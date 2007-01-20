begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: SigAction.h,v 1.8 2005/08/06 20:05:32 tom Exp $  *  * This file exists to handle non-POSIX systems which don't have<unistd.h>,  * and usually no sigaction() nor<termios.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGACTION_H
end_ifndef

begin_define
define|#
directive|define
name|_SIGACTION_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SIGACTION
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SIGVEC
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SIGACTION
end_if

begin_if
if|#
directive|if
operator|!
name|HAVE_TYPE_SIGACTION
end_if

begin_typedef
typedef|typedef
name|struct
name|sigaction
name|sigaction_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_SIGACTION */
end_comment

begin_if
if|#
directive|if
name|HAVE_SIGVEC
end_if

begin_undef
undef|#
directive|undef
name|SIG_BLOCK
end_undef

begin_define
define|#
directive|define
name|SIG_BLOCK
value|00
end_define

begin_undef
undef|#
directive|undef
name|SIG_UNBLOCK
end_undef

begin_define
define|#
directive|define
name|SIG_UNBLOCK
value|01
end_define

begin_undef
undef|#
directive|undef
name|SIG_SETMASK
end_undef

begin_define
define|#
directive|define
name|SIG_SETMASK
value|02
end_define

begin_comment
comment|/* 	 *<bsd/signal.h> is in the Linux 1.2.8 + gcc 2.7.0 configuration, 	 * and is useful for testing this header file. 	 */
end_comment

begin_if
if|#
directive|if
name|HAVE_BSD_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<bsd/signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|sigvec
name|sigaction_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sigset_t
value|_nc_sigset_t
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|sigset_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|sa_mask
end_undef

begin_define
define|#
directive|define
name|sa_mask
value|sv_mask
end_define

begin_undef
undef|#
directive|undef
name|sa_handler
end_undef

begin_define
define|#
directive|define
name|sa_handler
value|sv_handler
end_define

begin_undef
undef|#
directive|undef
name|sa_flags
end_undef

begin_define
define|#
directive|define
name|sa_flags
value|sv_flags
end_define

begin_undef
undef|#
directive|undef
name|sigaction
end_undef

begin_define
define|#
directive|define
name|sigaction
value|_nc_sigaction
end_define

begin_undef
undef|#
directive|undef
name|sigprocmask
end_undef

begin_define
define|#
directive|define
name|sigprocmask
value|_nc_sigprocmask
end_define

begin_undef
undef|#
directive|undef
name|sigemptyset
end_undef

begin_define
define|#
directive|define
name|sigemptyset
value|_nc_sigemptyset
end_define

begin_undef
undef|#
directive|undef
name|sigsuspend
end_undef

begin_define
define|#
directive|define
name|sigsuspend
value|_nc_sigsuspend
end_define

begin_undef
undef|#
directive|undef
name|sigdelset
end_undef

begin_define
define|#
directive|define
name|sigdelset
value|_nc_sigdelset
end_define

begin_undef
undef|#
directive|undef
name|sigaddset
end_undef

begin_define
define|#
directive|define
name|sigaddset
value|_nc_sigaddset
end_define

begin_comment
comment|/* tty/lib_tstp.c is the only user */
end_comment

begin_include
include|#
directive|include
file|<base/sigaction.c>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGVEC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGACTION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_SIGACTION_H) */
end_comment

end_unit

