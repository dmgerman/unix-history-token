begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_PROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_PROTO_H_
end_define

begin_comment
comment|/*  * 802.11 protocol implementation definitions.  */
end_comment

begin_enum
enum|enum
name|ieee80211_state
block|{
name|IEEE80211_S_INIT
init|=
literal|0
block|,
comment|/* default state */
name|IEEE80211_S_SCAN
init|=
literal|1
block|,
comment|/* scanning */
name|IEEE80211_S_AUTH
init|=
literal|2
block|,
comment|/* try to authenticate */
name|IEEE80211_S_ASSOC
init|=
literal|3
block|,
comment|/* try to assoc */
name|IEEE80211_S_RUN
init|=
literal|4
block|,
comment|/* associated */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_S_MAX
value|(IEEE80211_S_RUN+1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEND_MGMT
parameter_list|(
name|_ic
parameter_list|,
name|_ni
parameter_list|,
name|_type
parameter_list|,
name|_arg
parameter_list|)
define|\
value|((*(_ic)->ic_send_mgmt)(_ic, _ni, _type, _arg))
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ieee80211_mgt_subtype_name
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ieee80211_proto_attach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_proto_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_recv_mgmt
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ieee80211_send_mgmt
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ieee80211_mgmt_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|ieee80211_encap
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|ieee80211_decap
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int8_t
modifier|*
name|ieee80211_add_rates
parameter_list|(
name|u_int8_t
modifier|*
name|frm
parameter_list|,
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ieee80211_new_state
parameter_list|(
name|_ic
parameter_list|,
name|_nstate
parameter_list|,
name|_arg
parameter_list|)
define|\
value|(((_ic)->ic_newstate)((_ic), (_nstate), (_arg)))
end_define

begin_function_decl
specifier|extern
name|u_int8_t
modifier|*
name|ieee80211_add_xrates
parameter_list|(
name|u_int8_t
modifier|*
name|frm
parameter_list|,
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_print_essid
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_dump_pkt
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ieee80211_state_name
index|[
name|IEEE80211_S_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_PROTO_H_ */
end_comment

end_unit

