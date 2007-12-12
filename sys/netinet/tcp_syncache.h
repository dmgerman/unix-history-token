begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_var.h	8.4 (Berkeley) 5/24/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_SYNCACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_SYNCACHE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|syncache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_unreach
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_expand
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_add
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_offload_add
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|toe_usrreqs
modifier|*
name|tu
parameter_list|,
name|void
modifier|*
name|toepcb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_chkrst
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_badack
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_pcbcount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_pcblist
parameter_list|(
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|,
name|int
name|max_pcbs
parameter_list|,
name|int
modifier|*
name|pcbs_exported
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _NETINET_TCP_SYNCACHE_H_ */
end_comment

end_unit

