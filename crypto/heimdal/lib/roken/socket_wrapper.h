begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) Jelmer Vernooij 2005<jelmer@samba.org>  * Copyright (C) Stefan Metzmacher 2006<metze@samba.org>  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SOCKET_WRAPPER_H__
end_ifndef

begin_define
define|#
directive|define
name|__SOCKET_WRAPPER_H__
end_define

begin_function_decl
name|int
name|swrap_socket
parameter_list|(
name|int
name|family
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|protocol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_accept
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_connect
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|serv_addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_bind
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|myaddr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_listen
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|backlog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_getpeername
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|name
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_getsockname
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|name
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_getsockopt
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|optname
parameter_list|,
name|void
modifier|*
name|optval
parameter_list|,
name|socklen_t
modifier|*
name|optlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_setsockopt
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|optname
parameter_list|,
specifier|const
name|void
modifier|*
name|optval
parameter_list|,
name|socklen_t
name|optlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|swrap_recvfrom
parameter_list|(
name|int
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|from
parameter_list|,
name|socklen_t
modifier|*
name|fromlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|swrap_sendto
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|to
parameter_list|,
name|socklen_t
name|tolen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_ioctl
parameter_list|(
name|int
name|s
parameter_list|,
name|int
name|req
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|swrap_recv
parameter_list|(
name|int
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|swrap_send
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swrap_dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKET_WRAPPER_REPLACE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|accept
end_ifdef

begin_undef
undef|#
directive|undef
name|accept
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|accept
parameter_list|(
name|s
parameter_list|,
name|addr
parameter_list|,
name|addrlen
parameter_list|)
value|swrap_accept(s,addr,addrlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|connect
end_ifdef

begin_undef
undef|#
directive|undef
name|connect
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|connect
parameter_list|(
name|s
parameter_list|,
name|serv_addr
parameter_list|,
name|addrlen
parameter_list|)
value|swrap_connect(s,serv_addr,addrlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|bind
end_ifdef

begin_undef
undef|#
directive|undef
name|bind
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bind
parameter_list|(
name|s
parameter_list|,
name|myaddr
parameter_list|,
name|addrlen
parameter_list|)
value|swrap_bind(s,myaddr,addrlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|listen
end_ifdef

begin_undef
undef|#
directive|undef
name|listen
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|listen
parameter_list|(
name|s
parameter_list|,
name|blog
parameter_list|)
value|swrap_listen(s,blog)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getpeername
end_ifdef

begin_undef
undef|#
directive|undef
name|getpeername
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getpeername
parameter_list|(
name|s
parameter_list|,
name|name
parameter_list|,
name|addrlen
parameter_list|)
value|swrap_getpeername(s,name,addrlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getsockname
end_ifdef

begin_undef
undef|#
directive|undef
name|getsockname
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getsockname
parameter_list|(
name|s
parameter_list|,
name|name
parameter_list|,
name|addrlen
parameter_list|)
value|swrap_getsockname(s,name,addrlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getsockopt
end_ifdef

begin_undef
undef|#
directive|undef
name|getsockopt
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getsockopt
parameter_list|(
name|s
parameter_list|,
name|level
parameter_list|,
name|optname
parameter_list|,
name|optval
parameter_list|,
name|optlen
parameter_list|)
value|swrap_getsockopt(s,level,optname,optval,optlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|setsockopt
end_ifdef

begin_undef
undef|#
directive|undef
name|setsockopt
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|setsockopt
parameter_list|(
name|s
parameter_list|,
name|level
parameter_list|,
name|optname
parameter_list|,
name|optval
parameter_list|,
name|optlen
parameter_list|)
value|swrap_setsockopt(s,level,optname,optval,optlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|recvfrom
end_ifdef

begin_undef
undef|#
directive|undef
name|recvfrom
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|recvfrom
parameter_list|(
name|s
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|,
name|from
parameter_list|,
name|fromlen
parameter_list|)
value|swrap_recvfrom(s,buf,len,flags,from,fromlen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sendto
end_ifdef

begin_undef
undef|#
directive|undef
name|sendto
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sendto
parameter_list|(
name|s
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|,
name|to
parameter_list|,
name|tolen
parameter_list|)
value|swrap_sendto(s,buf,len,flags,to,tolen)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ioctl
end_ifdef

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ioctl
parameter_list|(
name|s
parameter_list|,
name|req
parameter_list|,
name|ptr
parameter_list|)
value|swrap_ioctl(s,req,ptr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|recv
end_ifdef

begin_undef
undef|#
directive|undef
name|recv
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|recv
parameter_list|(
name|s
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
value|swrap_recv(s,buf,len,flags)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|send
end_ifdef

begin_undef
undef|#
directive|undef
name|send
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|send
parameter_list|(
name|s
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
value|swrap_send(s,buf,len,flags)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|socket
end_ifdef

begin_undef
undef|#
directive|undef
name|socket
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|socket
parameter_list|(
name|domain
parameter_list|,
name|type
parameter_list|,
name|protocol
parameter_list|)
value|swrap_socket(domain,type,protocol)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|close
end_ifdef

begin_undef
undef|#
directive|undef
name|close
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|close
parameter_list|(
name|s
parameter_list|)
value|swrap_close(s)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|dup
end_ifdef

begin_undef
undef|#
directive|undef
name|dup
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dup
parameter_list|(
name|oldd
parameter_list|)
value|swrap_dup(oldd)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|dup2
end_ifdef

begin_undef
undef|#
directive|undef
name|dup2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|oldd
parameter_list|,
name|newd
parameter_list|)
value|swrap_dup2(oldd, newd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SOCKET_WRAPPER_H__ */
end_comment

end_unit

