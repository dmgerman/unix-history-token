begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)termios.h	8.3 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TERMIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_TERMIOS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|OXTABS
value|TAB3
end_define

begin_define
define|#
directive|define
name|MDMBUF
value|CCAR_OFLOW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|CCEQ
parameter_list|(
name|val
parameter_list|,
name|c
parameter_list|)
value|((c) == (val)&& (val) != _POSIX_VDISABLE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Commands passed to tcsetattr() for setting the termios structure.  */
end_comment

begin_define
define|#
directive|define
name|TCSANOW
value|0
end_define

begin_comment
comment|/* make change immediate */
end_comment

begin_define
define|#
directive|define
name|TCSADRAIN
value|1
end_define

begin_comment
comment|/* drain output, then change */
end_comment

begin_define
define|#
directive|define
name|TCSAFLUSH
value|2
end_define

begin_comment
comment|/* drain output, flush input */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|TCSASOFT
value|0x10
end_define

begin_comment
comment|/* flag - don't alter h.w. state */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCIFLUSH
value|1
end_define

begin_define
define|#
directive|define
name|TCOFLUSH
value|2
end_define

begin_define
define|#
directive|define
name|TCIOFLUSH
value|3
end_define

begin_define
define|#
directive|define
name|TCOOFF
value|1
end_define

begin_define
define|#
directive|define
name|TCOON
value|2
end_define

begin_define
define|#
directive|define
name|TCIOFF
value|3
end_define

begin_define
define|#
directive|define
name|TCION
value|4
end_define

begin_function_decl
name|__BEGIN_DECLS
name|speed_t
name|cfgetispeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|speed_t
name|cfgetospeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetispeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetospeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcgetattr
parameter_list|(
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetattr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcdrain
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcflow
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcflush
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsendbreak
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|pid_t
name|tcgetsid
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|tcsetsid
parameter_list|(
name|int
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfmakeraw
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfmakesane
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetspeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TERMIOS_H_ */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttydefaults.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

