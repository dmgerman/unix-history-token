begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSUID
end_ifndef

begin_struct_decl
struct_decl|struct
name|utmp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_un
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ID0init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uid_t
name|ID0realuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0ioctl
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0unlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0socket
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|ID0fopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0uu_lock
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0uu_lock_txfr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0uu_unlock
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ID0login
parameter_list|(
name|struct
name|utmp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ID0logout
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0bind_un
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr_un
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0connect_un
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr_un
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ID0kill
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NOKLDLOAD
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|ID0kldload
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

begin_ifndef
ifndef|#
directive|ifndef
name|NONETGRAPH
end_ifndef

begin_function_decl
specifier|extern
name|int
name|ID0NgMkSockNode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NOSUID */
end_comment

begin_define
define|#
directive|define
name|ID0init
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ID0realuid
parameter_list|()
value|(0)
end_define

begin_define
define|#
directive|define
name|ID0ioctl
value|ioctl
end_define

begin_define
define|#
directive|define
name|ID0unlink
value|unlink
end_define

begin_define
define|#
directive|define
name|ID0socket
value|socket
end_define

begin_define
define|#
directive|define
name|ID0fopen
value|fopen
end_define

begin_define
define|#
directive|define
name|ID0open
value|open
end_define

begin_define
define|#
directive|define
name|ID0write
value|write
end_define

begin_define
define|#
directive|define
name|ID0uu_lock
value|uu_lock
end_define

begin_define
define|#
directive|define
name|ID0uu_lock_txfr
value|uu_lock_txfr
end_define

begin_define
define|#
directive|define
name|ID0uu_unlock
value|uu_unlock
end_define

begin_define
define|#
directive|define
name|ID0login
parameter_list|(
name|u
parameter_list|)
define|\
value|do {					\     if (logout((u)->ut_line))		\       logwtmp((u)->ut_line, "", "");	\     login(u);				\   } while (0)
end_define

begin_define
define|#
directive|define
name|ID0logout
parameter_list|(
name|dev
parameter_list|,
name|no
parameter_list|)
define|\
value|do {							\     struct utmp ut;					\     strncpy(ut.ut_line, dev, sizeof ut.ut_line - 1);	\     ut.ut_line[sizeof ut.ut_line - 1] = '\0';		\     if (no || logout(ut.ut_line))			\       logwtmp(ut.ut_line, "", ""); 			\   } while (0)
end_define

begin_define
define|#
directive|define
name|ID0bind_un
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|bind(s, (const struct sockaddr *)(n), sizeof *(n))
end_define

begin_define
define|#
directive|define
name|ID0connect_un
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
define|\
value|connect(s, (const struct sockaddr *)(n), sizeof *(n))
end_define

begin_define
define|#
directive|define
name|ID0kill
value|kill
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NOKLDLOAD
argument_list|)
end_if

begin_define
define|#
directive|define
name|ID0kldload
value|kldload
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NONETGRAPH
end_ifndef

begin_define
define|#
directive|define
name|ID0NgMkSockNode
value|NgMkSockNode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

