begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* freebsd.h     System dependencies for FreeBSD... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996, 1998 The Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE INTERNET SOFTWARE CONSORTIUM OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software was written for the Internet Software Consortium by Ted Lemon  * under a contract with Vixie Laboratories.  */
end_comment

begin_define
define|#
directive|define
name|_ANSI_SOURCE
end_define

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
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
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
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
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INADDR_LOOPBACK
argument_list|)
end_if

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|((u_int32_t)0x7f000001)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Varargs stuff... */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_DOTDOTDOT
value|...
end_define

begin_define
define|#
directive|define
name|va_dcl
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
value|va_start (list, last)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCPD_PID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCPD_PID
value|"/var/run/dhcpd.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCPD_DB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCPD_DB
value|"/var/db/dhcpd.leases"
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
value|"/var/run/dhclient.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DHCLIENT_DB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DHCLIENT_DB
value|"/var/db/dhclient.leases"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Time stuff... */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
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
name|HAVE_SA_LEN
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_DEFAULT_NETWORK
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_BPF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

