begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"login_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: stty_default.c,v 1.8 1999/12/02 17:04:56 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* HP-UX 9.0 termios doesn't define these */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLUSHO
end_ifndef

begin_define
define|#
directive|define
name|FLUSHO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XTABS
end_ifndef

begin_define
define|#
directive|define
name|XTABS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OXTABS
end_ifndef

begin_define
define|#
directive|define
name|OXTABS
value|XTABS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Ultrix... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ECHOPRT
end_ifndef

begin_define
define|#
directive|define
name|ECHOPRT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECHOCTL
end_ifndef

begin_define
define|#
directive|define
name|ECHOCTL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ECHOKE
end_ifndef

begin_define
define|#
directive|define
name|ECHOKE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IMAXBEL
end_ifndef

begin_define
define|#
directive|define
name|IMAXBEL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|x
parameter_list|)
value|((x) ^ 0100)
end_define

begin_function
name|void
name|stty_default
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|termios
name|termios
decl_stmt|;
comment|/*      * Finalize the terminal settings. Some systems default to 8 bits,      * others to 7, so we should leave that alone.      */
name|tcgetattr
argument_list|(
literal|0
argument_list|,
operator|&
name|termios
argument_list|)
expr_stmt|;
name|termios
operator|.
name|c_iflag
operator||=
operator|(
name|BRKINT
operator||
name|IGNPAR
operator||
name|ICRNL
operator||
name|IXON
operator||
name|IMAXBEL
operator|)
expr_stmt|;
name|termios
operator|.
name|c_iflag
operator|&=
operator|~
name|IXANY
expr_stmt|;
name|termios
operator|.
name|c_lflag
operator||=
operator|(
name|ISIG
operator||
name|IEXTEN
operator||
name|ICANON
operator||
name|ECHO
operator||
name|ECHOE
operator||
name|ECHOK
operator||
name|ECHOCTL
operator||
name|ECHOKE
operator|)
expr_stmt|;
name|termios
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ECHOPRT
operator||
name|TOSTOP
operator||
name|FLUSHO
operator|)
expr_stmt|;
name|termios
operator|.
name|c_oflag
operator||=
operator|(
name|OPOST
operator||
name|ONLCR
operator|)
expr_stmt|;
name|termios
operator|.
name|c_oflag
operator|&=
operator|~
name|OXTABS
expr_stmt|;
name|termios
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
name|Ctl
argument_list|(
literal|'C'
argument_list|)
expr_stmt|;
name|termios
operator|.
name|c_cc
index|[
name|VERASE
index|]
operator|=
name|Ctl
argument_list|(
literal|'H'
argument_list|)
expr_stmt|;
name|termios
operator|.
name|c_cc
index|[
name|VKILL
index|]
operator|=
name|Ctl
argument_list|(
literal|'U'
argument_list|)
expr_stmt|;
name|termios
operator|.
name|c_cc
index|[
name|VEOF
index|]
operator|=
name|Ctl
argument_list|(
literal|'D'
argument_list|)
expr_stmt|;
name|termios
operator|.
name|c_cc
index|[
name|VSUSP
index|]
operator|=
name|Ctl
argument_list|(
literal|'Z'
argument_list|)
expr_stmt|;
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSANOW
argument_list|,
operator|&
name|termios
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

