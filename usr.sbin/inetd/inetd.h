begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|BUFSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|LINESIZ
value|72
end_define

begin_define
define|#
directive|define
name|NORM_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|MUX_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|MUXPLUS_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|TTCP_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|FAITH_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|ISMUX
parameter_list|(
name|sep
parameter_list|)
value|(((sep)->se_type == MUX_TYPE) || \ 			 ((sep)->se_type == MUXPLUS_TYPE))
end_define

begin_define
define|#
directive|define
name|ISMUXPLUS
parameter_list|(
name|sep
parameter_list|)
value|((sep)->se_type == MUXPLUS_TYPE)
end_define

begin_define
define|#
directive|define
name|ISTTCP
parameter_list|(
name|sep
parameter_list|)
value|((sep)->se_type == TTCP_TYPE)
end_define

begin_struct
struct|struct
name|servtab
block|{
name|char
modifier|*
name|se_service
decl_stmt|;
comment|/* name of service */
name|int
name|se_socktype
decl_stmt|;
comment|/* type of socket to use */
name|int
name|se_family
decl_stmt|;
comment|/* address family */
name|char
modifier|*
name|se_proto
decl_stmt|;
comment|/* protocol used */
name|int
name|se_maxchild
decl_stmt|;
comment|/* max number of children */
name|int
name|se_maxcpm
decl_stmt|;
comment|/* max connects per IP per minute */
name|int
name|se_numchild
decl_stmt|;
comment|/* current number of children */
name|pid_t
modifier|*
name|se_pids
decl_stmt|;
comment|/* array of child pids */
name|char
modifier|*
name|se_user
decl_stmt|;
comment|/* user name to run as */
name|char
modifier|*
name|se_group
decl_stmt|;
comment|/* group name to run as */
ifdef|#
directive|ifdef
name|LOGIN_CAP
name|char
modifier|*
name|se_class
decl_stmt|;
comment|/* login class name to run with */
endif|#
directive|endif
name|struct
name|biltin
modifier|*
name|se_bi
decl_stmt|;
comment|/* if built-in, description */
name|char
modifier|*
name|se_server
decl_stmt|;
comment|/* server program */
name|char
modifier|*
name|se_server_name
decl_stmt|;
comment|/* server program without path */
define|#
directive|define
name|MAXARGV
value|20
name|char
modifier|*
name|se_argv
index|[
name|MAXARGV
operator|+
literal|1
index|]
decl_stmt|;
comment|/* program arguments */
ifdef|#
directive|ifdef
name|IPSEC
name|char
modifier|*
name|se_policy
decl_stmt|;
comment|/* IPsec policy string */
endif|#
directive|endif
name|int
name|se_fd
decl_stmt|;
comment|/* open descriptor */
union|union
block|{
comment|/* bound address */
name|struct
name|sockaddr
name|se_un_ctrladdr
decl_stmt|;
name|struct
name|sockaddr_in
name|se_un_ctrladdr4
decl_stmt|;
name|struct
name|sockaddr_in6
name|se_un_ctrladdr6
decl_stmt|;
name|struct
name|sockaddr_un
name|se_un_ctrladdr_un
decl_stmt|;
block|}
name|se_un
union|;
define|#
directive|define
name|se_ctrladdr
value|se_un.se_un_ctrladdr
define|#
directive|define
name|se_ctrladdr4
value|se_un.se_un_ctrladdr4
define|#
directive|define
name|se_ctrladdr6
value|se_un.se_un_ctrladdr6
define|#
directive|define
name|se_ctrladdr_un
value|se_un.se_un_ctrladdr_un
name|socklen_t
name|se_ctrladdr_size
decl_stmt|;
name|uid_t
name|se_sockuid
decl_stmt|;
comment|/* Owner for unix domain socket */
name|gid_t
name|se_sockgid
decl_stmt|;
comment|/* Group for unix domain socket */
name|mode_t
name|se_sockmode
decl_stmt|;
comment|/* Mode for unix domain socket */
name|u_char
name|se_type
decl_stmt|;
comment|/* type: normal, mux, or mux+ */
name|u_char
name|se_checked
decl_stmt|;
comment|/* looked at during merge */
name|u_char
name|se_accept
decl_stmt|;
comment|/* i.e., wait/nowait mode */
name|u_char
name|se_rpc
decl_stmt|;
comment|/* ==1 if RPC service */
name|int
name|se_rpc_prog
decl_stmt|;
comment|/* RPC program number */
name|u_int
name|se_rpc_lowvers
decl_stmt|;
comment|/* RPC low version */
name|u_int
name|se_rpc_highvers
decl_stmt|;
comment|/* RPC high version */
name|int
name|se_count
decl_stmt|;
comment|/* number started since se_time */
name|struct
name|timeval
name|se_time
decl_stmt|;
comment|/* start of se_count */
name|struct
name|servtab
modifier|*
name|se_next
decl_stmt|;
struct|struct
name|se_flags
block|{
name|u_int
name|se_nomapped
range|:
literal|1
decl_stmt|;
name|u_int
name|se_reset
range|:
literal|1
decl_stmt|;
block|}
name|se_flags
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|se_nomapped
value|se_flags.se_nomapped
end_define

begin_define
define|#
directive|define
name|se_reset
value|se_flags.se_reset
end_define

begin_decl_stmt
name|int
name|check_loop
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
specifier|const
expr|struct
name|servtab
operator|*
name|sep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getvalue
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|newstr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|inetd_setproctitle
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_service
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|servtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sskip
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|skip
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|servtab
modifier|*
name|tcpmux
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|servtab
modifier|*
name|servtab
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|bi_fn_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|servtab
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|biltin
block|{
specifier|const
name|char
modifier|*
name|bi_service
decl_stmt|;
comment|/* internally provided service name */
name|int
name|bi_socktype
decl_stmt|;
comment|/* type of socket supported */
name|short
name|bi_fork
decl_stmt|;
comment|/* 1 if should fork before call */
name|int
name|bi_maxchild
decl_stmt|;
comment|/* max number of children, -1=default */
name|bi_fn_t
modifier|*
name|bi_fn
decl_stmt|;
comment|/* function which performs it */
block|}
struct|;
end_struct

end_unit

