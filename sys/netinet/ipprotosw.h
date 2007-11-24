begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, 1998, and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)protosw.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IPPROTOSW_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IPPROTOSW_H_
end_define

begin_comment
comment|/*  * For pfil_head structure.  */
end_comment

begin_include
include|#
directive|include
file|<net/pfil.h>
end_include

begin_comment
comment|/* Forward declare these structures referenced from prototypes below. */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ipprotosw
block|{
name|short
name|pr_type
decl_stmt|;
comment|/* socket type used for */
name|struct
name|domain
modifier|*
name|pr_domain
decl_stmt|;
comment|/* domain protocol a member of */
name|short
name|pr_protocol
decl_stmt|;
comment|/* protocol number */
name|short
name|pr_flags
decl_stmt|;
comment|/* see below */
comment|/* protocol-protocol hooks */
name|pr_in_input_t
modifier|*
name|pr_input
decl_stmt|;
comment|/* input to protocol (from below) */
name|pr_output_t
modifier|*
name|pr_output
decl_stmt|;
comment|/* output to protocol (from above) */
name|pr_ctlinput_t
modifier|*
name|pr_ctlinput
decl_stmt|;
comment|/* control input (from below) */
name|pr_ctloutput_t
modifier|*
name|pr_ctloutput
decl_stmt|;
comment|/* control output (from above) */
comment|/* user-protocol hook */
name|void
modifier|*
name|pr_ousrreq
decl_stmt|;
comment|/* utility hooks */
name|pr_init_t
modifier|*
name|pr_init
decl_stmt|;
name|pr_fasttimo_t
modifier|*
name|pr_fasttimo
decl_stmt|;
comment|/* fast timeout (200ms) */
name|pr_slowtimo_t
modifier|*
name|pr_slowtimo
decl_stmt|;
comment|/* slow timeout (500ms) */
name|pr_drain_t
modifier|*
name|pr_drain
decl_stmt|;
comment|/* flush any excess space possible */
name|struct
name|pr_usrreqs
modifier|*
name|pr_usrreqs
decl_stmt|;
comment|/* supersedes pr_usrreq() */
name|struct
name|pfil_head
name|pr_pfh
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_IPPROTOSW_H_ */
end_comment

end_unit

