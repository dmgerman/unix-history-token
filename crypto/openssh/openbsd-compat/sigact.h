begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: SigAction.h,v 1.3 2001/01/22 18:01:32 millert Exp $	*/
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $From: SigAction.h,v 1.6 2000/12/10 02:36:10 tom Exp $  *  * This file exists to handle non-POSIX systems which don't have<unistd.h>,  * and usually no sigaction() nor<termios.h>  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: lib/libcurses/SigAction.h */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SIGACTION
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SIGVEC
argument_list|)
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
comment|/*  *<bsd/signal.h> is in the Linux 1.2.8 + gcc 2.7.0 configuration,  * and is useful for testing this header file.  */
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

begin_struct
struct|struct
name|sigaction
block|{
name|struct
name|sigvec
name|sv
decl_stmt|;
block|}
struct|;
end_struct

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
value|sv.sv_mask
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
value|sv.sv_handler
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
value|sv.sv_flags
end_define

begin_function_decl
name|int
name|sigaction
parameter_list|(
name|int
name|sig
parameter_list|,
name|struct
name|sigaction
modifier|*
name|sigact
parameter_list|,
name|struct
name|sigaction
modifier|*
name|osigact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigprocmask
parameter_list|(
name|int
name|how
parameter_list|,
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|sigset_t
modifier|*
name|omask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigemptyset
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsuspend
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigdelset
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaddset
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SIGACTION)&& defined(HAVE_SIGVEC) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_SIGACTION_H) */
end_comment

end_unit

