begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)raw_cb.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_RAW_CB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_RAW_CB_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Raw protocol interface control block.  Used to tie a socket to the generic  * raw interface.  */
end_comment

begin_struct
struct|struct
name|rawcb
block|{
name|LIST_ENTRY
argument_list|(
argument|rawcb
argument_list|)
name|list
expr_stmt|;
name|struct
name|socket
modifier|*
name|rcb_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sockproto
name|rcb_proto
decl_stmt|;
comment|/* protocol family, protocol */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotorawcb
parameter_list|(
name|so
parameter_list|)
value|((struct rawcb *)(so)->so_pcb)
end_define

begin_comment
comment|/*  * Nominal space allocated to a raw socket.  */
end_comment

begin_define
define|#
directive|define
name|RAWSNDQ
value|8192
end_define

begin_define
define|#
directive|define
name|RAWRCVQ
value|8192
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|LIST_HEAD
argument_list|(
name|rawcb_list_head
argument_list|,
name|rawcb
argument_list|)
argument_list|,
name|rawcb_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_rawcb_list
value|VNET(rawcb_list)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|rawcb_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Generic protosw entries for raw socket protocols.  */
end_comment

begin_decl_stmt
name|pr_ctlinput_t
name|raw_ctlinput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pr_init_t
name|raw_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Library routines for raw socket usrreq functions; will always be wrapped  * so that protocol-specific functions can be handled.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|raw_input_cb_fn
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockproto
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rawcb
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|raw_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raw_detach
parameter_list|(
name|struct
name|rawcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raw_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockproto
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raw_input_ext
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockproto
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|raw_input_cb_fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generic pr_usrreqs entries for raw socket protocols, usually wrapped so  * that protocol-specific functions can be handled.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|raw_usrreqs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

