begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* aix.h */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 The Internet Software Consortium.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|int8_t
value|char
end_define

begin_define
define|#
directive|define
name|int16_t
value|short
end_define

begin_define
define|#
directive|define
name|int32_t
value|long
end_define

begin_define
define|#
directive|define
name|u_int8_t
value|unsigned char
end_define

begin_define
define|#
directive|define
name|u_int16_t
value|unsigned short
end_define

begin_define
define|#
directive|define
name|u_int32_t
value|unsigned long
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCPD_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCPD_PID
value|"/etc/dhcpd.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCLIENT_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCLIENT_PID
value|"/etc/dhclient.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCRELAY_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCRELAY_PID
value|"/etc/dhcrelay.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_DOTDOTDOT
value|va_alist
end_define

begin_define
define|#
directive|define
name|VA_start
parameter_list|(
name|list
parameter_list|,
name|last
parameter_list|)
value|va_start (list)
end_define

begin_define
define|#
directive|define
name|vsnprintf
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|,
name|fmt
parameter_list|,
name|list
parameter_list|)
value|vsprintf (buf, fmt, list)
end_define

begin_define
define|#
directive|define
name|NO_SNPRINTF
end_define

begin_define
define|#
directive|define
name|EOL
value|'\n'
end_define

begin_define
define|#
directive|define
name|VOIDPTR
value|void *
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_define
define|#
directive|define
name|TIME
value|time_t
end_define

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|x
parameter_list|)
value|time ((x))
end_define

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_define
define|#
directive|define
name|USE_SOCKETS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
value|1
end_define

begin_undef
undef|#
directive|undef
name|FDDI
end_undef

end_unit

