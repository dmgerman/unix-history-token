begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)un.h	8.3 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UN_H_
end_define

begin_comment
comment|/*  * Definitions for UNIX IPC domain.  */
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|u_char
name|sun_len
decl_stmt|;
comment|/* sockaddr len including null */
name|u_char
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|104
index|]
decl_stmt|;
comment|/* path name (gag) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|uipc_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|req
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_connect2
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|socket
operator|*
name|so2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_dispose
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_externalize
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|rights
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unp_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|uipc_usrreqs
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/* actual length of an initialized sockaddr_un */
end_comment

begin_define
define|#
directive|define
name|SUN_LEN
parameter_list|(
name|su
parameter_list|)
define|\
value|(sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UN_H_ */
end_comment

end_unit

