begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kx.h,v 1.39 2001/09/17 01:59:41 assar Exp $ */
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
file|<stdarg.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GRP_H
end_ifdef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<X11/X.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xauth.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STREAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STROPTS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined by aix's sys/stream.h and again by arpa/nameser.h */
end_comment

begin_undef
undef|#
directive|undef
name|NOERROR
end_undef

begin_comment
comment|/* as far as we know, this is only used with later versions of Slowlaris */
end_comment

begin_if
if|#
directive|if
name|SunOS
operator|>=
literal|50
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_STROPTS_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_FATTACH
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_PUSH
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAY_HAVE_X11_PIPES
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* This doesn't belong here. */
end_comment

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5.h>
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

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_struct
struct|struct
name|x_socket
block|{
name|char
modifier|*
name|pathname
decl_stmt|;
name|int
name|fd
decl_stmt|;
enum|enum
block|{
name|LISTENP
init|=
literal|0x80
block|,
name|TCP
init|=
name|LISTENP
operator||
literal|1
block|,
name|UNIX_SOCKET
init|=
name|LISTENP
operator||
literal|2
block|,
name|STREAM_PIPE
init|=
literal|3
block|}
name|flags
enum|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|x_socket
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|display_num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|display
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|display_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|xauthfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xauthfile_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|cookie
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|cookie_len
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|get_xsockets
parameter_list|(
name|int
modifier|*
name|number
parameter_list|,
name|struct
name|x_socket
modifier|*
modifier|*
name|sockets
parameter_list|,
name|int
name|tcpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chown_xsockets
parameter_list|(
name|int
name|n
parameter_list|,
name|struct
name|x_socket
modifier|*
name|sockets
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|connect_local_xsocket
parameter_list|(
name|unsigned
name|dnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create_and_write_cookie
parameter_list|(
name|char
modifier|*
name|xauthfile
parameter_list|,
name|size_t
name|size
parameter_list|,
name|u_char
modifier|*
name|cookie
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify_and_remove_cookies
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|sock
parameter_list|,
name|int
name|cookiesp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|replace_cookie
parameter_list|(
name|int
name|xserver
parameter_list|,
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|cookiesp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|suspicious_address
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|sockaddr_in
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KX_PORT
value|2111
end_define

begin_define
define|#
directive|define
name|KX_OLD_VERSION
value|"KXSERV.1"
end_define

begin_define
define|#
directive|define
name|KX_VERSION
value|"KXSERV.2"
end_define

begin_define
define|#
directive|define
name|COOKIE_TYPE
value|"MIT-MAGIC-COOKIE-1"
end_define

begin_enum
enum|enum
block|{
name|INIT
init|=
literal|0
block|,
name|ACK
init|=
literal|1
block|,
name|NEW_CONN
init|=
literal|2
block|,
name|ERROR
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|kx_flags
block|{
name|PASSIVE
init|=
literal|1
block|,
name|KEEP_ALIVE
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|kx_flags
name|kx_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|kx_context
block|{
name|int
function_decl|(
modifier|*
name|authenticate
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|s
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|userok
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|,
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
name|ssize_t
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|ssize_t
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|copy_encrypted
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd1
parameter_list|,
name|int
name|fd2
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|kx_context
modifier|*
name|kc
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|host
decl_stmt|;
specifier|const
name|char
modifier|*
name|user
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|debug_flag
decl_stmt|;
name|int
name|keepalive_flag
decl_stmt|;
name|int
name|tcp_flag
decl_stmt|;
name|struct
name|sockaddr_in
name|thisaddr
decl_stmt|,
name|thataddr
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kx_context
name|kx_context
typedef|;
end_typedef

begin_function_decl
name|void
name|context_set
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|debug_flag
parameter_list|,
name|int
name|keepalive_flag
parameter_list|,
name|int
name|tcp_flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|context_destroy
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|context_authenticate
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|context_userok
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|kx_read
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|kx_write
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_encrypted
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd1
parameter_list|,
name|int
name|fd2
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_function_decl
name|void
name|krb4_make_context
parameter_list|(
name|kx_context
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recv_v4_auth
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|sock
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_function_decl
name|void
name|krb5_make_context
parameter_list|(
name|kx_context
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recv_v5_auth
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|sock
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|fatal
parameter_list|(
name|kx_context
modifier|*
name|kc
parameter_list|,
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|KRB4
end_ifndef

begin_function_decl
name|int
name|krb_get_int
parameter_list|(
name|void
modifier|*
name|f
parameter_list|,
name|u_int32_t
modifier|*
name|to
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|lsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_put_int
parameter_list|(
name|u_int32_t
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
name|size_t
name|rem
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

