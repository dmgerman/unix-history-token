begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)raw_cb.h	7.6 (Berkeley) 6/28/90  *	$Id: raw_cb.h,v 1.4 1993/12/19 00:52:05 wollman Exp $  */
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
value|1
end_define

begin_comment
comment|/*  * Raw protocol interface control block.  Used  * to tie a socket to the generic raw interface.  */
end_comment

begin_struct
struct|struct
name|rawcb
block|{
name|struct
name|rawcb
modifier|*
name|rcb_next
decl_stmt|;
comment|/* doubly linked list */
name|struct
name|rawcb
modifier|*
name|rcb_prev
decl_stmt|;
name|struct
name|socket
modifier|*
name|rcb_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sockaddr
modifier|*
name|rcb_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|sockaddr
modifier|*
name|rcb_laddr
decl_stmt|;
comment|/* socket's address */
name|struct
name|sockproto
name|rcb_proto
decl_stmt|;
comment|/* protocol family, protocol */
name|struct
name|mbuf
modifier|*
name|rcb_moptions
decl_stmt|;
comment|/* proto specific multicast options */
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
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|rawcb
name|rawcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list */
end_comment

begin_function_decl
specifier|extern
name|void
name|raw_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
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
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|raw_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|raw_usrreq
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_RAW_CB_H_ */
end_comment

end_unit

