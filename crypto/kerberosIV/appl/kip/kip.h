begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kip.h,v 1.18.2.1 2000/06/23 02:55:01 assar Exp $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_TCP_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_VAR_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_TUN_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if_tun.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_include
include|#
directive|include
file|<socks.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_define
define|#
directive|define
name|TUNDEV
value|"tun"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TUNMTU
end_ifndef

begin_define
define|#
directive|define
name|TUNMTU
value|1500
end_define

begin_comment
comment|/* everything is ethernet :) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KIPPORT
value|2112
end_define

begin_define
define|#
directive|define
name|KIP_VERSION
value|"KIPSRV.0"
end_define

begin_function_decl
name|int
name|copy_packets
parameter_list|(
name|int
name|tundev
parameter_list|,
name|int
name|netdev
parameter_list|,
name|int
name|mtu
parameter_list|,
name|des_cblock
modifier|*
name|iv
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RETSIGTYPE
name|childhandler
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|disconnect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isserver
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|tunnel_open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|des_key_schedule
name|schedule
parameter_list|,
name|des_cblock
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kip_exec
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

