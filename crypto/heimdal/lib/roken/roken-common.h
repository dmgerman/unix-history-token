begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: roken-common.h,v 1.42 2001/01/29 02:09:09 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ROKEN_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__ROKEN_COMMON_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|ROKEN_CPP_START
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|ROKEN_CPP_END
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROKEN_CPP_START
end_define

begin_define
define|#
directive|define
name|ROKEN_CPP_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_NONE
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|0x7f000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SOMAXCONN
end_ifndef

begin_define
define|#
directive|define
name|SOMAXCONN
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|openlog
parameter_list|(
name|id
parameter_list|,
name|option
parameter_list|,
name|facility
parameter_list|)
value|openlog((id),(option))
end_define

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_ODELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_ODELAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_NDELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_NDELAY
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_CONS
end_ifndef

begin_define
define|#
directive|define
name|LOG_CONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUTH
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUTH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_AUTHPRIV
end_ifndef

begin_define
define|#
directive|define
name|LOG_AUTHPRIV
value|LOG_AUTH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HEQUIV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HEQUIV
value|"/etc/hosts.equiv"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VARRUN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VARRUN
value|"/var/run/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|(1024+4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_ERR
end_ifndef

begin_define
define|#
directive|define
name|SIG_ERR
value|((RETSIGTYPE (*)(int))-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * error code for getipnodeby{name,addr}  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_NOT_FOUND
end_ifndef

begin_define
define|#
directive|define
name|HOST_NOT_FOUND
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRY_AGAIN
end_ifndef

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RECOVERY
end_ifndef

begin_define
define|#
directive|define
name|NO_RECOVERY
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DATA
end_ifndef

begin_define
define|#
directive|define
name|NO_DATA
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|NO_ADDRESS
value|NO_DATA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * error code for getaddrinfo  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_NOERROR
end_ifndef

begin_define
define|#
directive|define
name|EAI_NOERROR
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_ADDRFAMILY
end_ifndef

begin_define
define|#
directive|define
name|EAI_ADDRFAMILY
value|1
end_define

begin_comment
comment|/* address family for nodename not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_AGAIN
value|2
end_define

begin_comment
comment|/* temporary failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_BADFLAGS
value|3
end_define

begin_comment
comment|/* invalid value for ai_flags */
end_comment

begin_define
define|#
directive|define
name|EAI_FAIL
value|4
end_define

begin_comment
comment|/* non-recoverable failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_FAMILY
value|5
end_define

begin_comment
comment|/* ai_family not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_MEMORY
value|6
end_define

begin_comment
comment|/* memory allocation failure */
end_comment

begin_define
define|#
directive|define
name|EAI_NODATA
value|7
end_define

begin_comment
comment|/* no address associated with nodename */
end_comment

begin_define
define|#
directive|define
name|EAI_NONAME
value|8
end_define

begin_comment
comment|/* nodename nor servname provided, or not known */
end_comment

begin_define
define|#
directive|define
name|EAI_SERVICE
value|9
end_define

begin_comment
comment|/* servname not supported for ai_socktype */
end_comment

begin_define
define|#
directive|define
name|EAI_SOCKTYPE
value|10
end_define

begin_comment
comment|/* ai_socktype not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|11
end_define

begin_comment
comment|/* system error returned in errno */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAI_ADDRFAMILY */
end_comment

begin_comment
comment|/* flags for getaddrinfo() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AI_PASSIVE
end_ifndef

begin_define
define|#
directive|define
name|AI_PASSIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x02
end_define

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AI_PASSIVE */
end_comment

begin_comment
comment|/* flags for getnameinfo() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_DGRAM
end_ifndef

begin_define
define|#
directive|define
name|NI_DGRAM
value|0x01
end_define

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|0x02
end_define

begin_define
define|#
directive|define
name|NI_NOFQDN
value|0x04
end_define

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|0x08
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * constants for getnameinfo  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_MAXHOST
end_ifndef

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * constants for inet_ntop  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INET_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET_ADDRSTRLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * for shutdown(2)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHUT_RD
end_ifndef

begin_define
define|#
directive|define
name|SHUT_RD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHUT_WR
end_ifndef

begin_define
define|#
directive|define
name|SHUT_WR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHUT_RDWR
end_ifndef

begin_define
define|#
directive|define
name|SHUT_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ROKEN_CPP_START
end_macro

begin_if
if|#
directive|if
name|IRIX
operator|!=
literal|4
end_if

begin_comment
comment|/* fix for compiler bug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RETSIGTYPE
end_ifdef

begin_typedef
typedef|typedef
name|RETSIGTYPE
function_decl|(
modifier|*
name|SigAction
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|SigAction
name|signal
parameter_list|(
name|int
name|iSig
parameter_list|,
name|SigAction
name|pAction
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BSD compatible */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|simple_execve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|simple_execvp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|simple_execlp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|simple_execle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ROKEN_LIB_FUNCTION
name|simple_execl
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ROKEN_LIB_FUNCTION
name|print_version
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ROKEN_LIB_FUNCTION
name|emalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ROKEN_LIB_FUNCTION
name|erealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ROKEN_LIB_FUNCTION
name|estrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|ROKEN_LIB_FUNCTION
name|eread
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|ROKEN_LIB_FUNCTION
name|ewrite
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|esetenv
parameter_list|(
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|,
name|int
name|rewrite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_address_and_port
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|socket_addr_size
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_any
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|socket_sockaddr_size
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|socket_get_address
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|socket_get_port
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_port
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_debug
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_tos
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|tos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socket_set_reuseaddr
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|vstrcollect
parameter_list|(
name|va_list
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|strcollect
parameter_list|(
name|char
modifier|*
name|first
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timevalfix
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timevaladd
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timevalsub
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pid_file_write
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pid_file_delete
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_environment
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warnerr
parameter_list|(
name|int
name|doerrno
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_macro
name|ROKEN_CPP_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ROKEN_COMMON_H__ */
end_comment

end_unit

