begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: if_pfsync.h,v 1.2 2002/12/11 18:31:26 mickey Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Michael Shalayeff  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_PFSYNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_PFSYNC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|pfsync_softc
block|{
name|struct
name|ifnet
name|sc_if
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|callout
name|sc_tmo
decl_stmt|;
else|#
directive|else
name|struct
name|timeout
name|sc_tmo
decl_stmt|;
endif|#
directive|endif
name|struct
name|mbuf
modifier|*
name|sc_mbuf
decl_stmt|;
comment|/* current cummulative mbuf */
name|struct
name|pf_state
modifier|*
name|sc_ptr
decl_stmt|;
comment|/* current ongoing state */
name|int
name|sc_count
decl_stmt|;
comment|/* number of states in one mtu */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|LIST_ENTRY
argument_list|(
argument|pfsync_softc
argument_list|)
name|sc_next
expr_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pfsync_header
block|{
name|u_int8_t
name|version
decl_stmt|;
define|#
directive|define
name|PFSYNC_VERSION
value|1
name|u_int8_t
name|af
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
define|#
directive|define
name|PFSYNC_ACT_CLR
value|0
define|#
directive|define
name|PFSYNC_ACT_INS
value|1
define|#
directive|define
name|PFSYNC_ACT_UPD
value|2
define|#
directive|define
name|PFSYNC_ACT_DEL
value|3
define|#
directive|define
name|PFSYNC_ACT_MAX
value|4
name|u_int8_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSYNC_HDRLEN
value|sizeof(struct pfsync_header)
end_define

begin_define
define|#
directive|define
name|PFSYNC_ACTIONS
define|\
value|"CLR ST", "INS ST", "UPD ST", "DEL ST"
end_define

begin_define
define|#
directive|define
name|pf_state_peer_hton
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {		\ 	(d)->seqlo = htonl((s)->seqlo);		\ 	(d)->seqhi = htonl((s)->seqhi);		\ 	(d)->seqdiff = htonl((s)->seqdiff);	\ 	(d)->max_win = htons((s)->max_win);	\ 	(d)->state = (s)->state;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|pf_state_peer_ntoh
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {		\ 	(d)->seqlo = ntohl((s)->seqlo);		\ 	(d)->seqhi = ntohl((s)->seqhi);		\ 	(d)->seqdiff = ntohl((s)->seqdiff);	\ 	(d)->max_win = ntohs((s)->max_win);	\ 	(d)->state = (s)->state;		\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|pfsync_clear_state
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfsync_pack_state
parameter_list|(
name|u_int8_t
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pfsync_insert_state
parameter_list|(
name|st
parameter_list|)
value|pfsync_pack_state(PFSYNC_ACT_INS, (st))
end_define

begin_define
define|#
directive|define
name|pfsync_update_state
parameter_list|(
name|st
parameter_list|)
value|pfsync_pack_state(PFSYNC_ACT_UPD, (st))
end_define

begin_define
define|#
directive|define
name|pfsync_delete_state
parameter_list|(
name|st
parameter_list|)
value|pfsync_pack_state(PFSYNC_ACT_DEL, (st))
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
comment|/* _NET_IF_PFSYNC_H_ */
end_comment

end_unit

