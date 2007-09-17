begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_HT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_HT_H_
end_define

begin_comment
comment|/*  * 802.11n protocol implementation definitions.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SEND_ACTION
parameter_list|(
name|_ni
parameter_list|,
name|_cat
parameter_list|,
name|_act
parameter_list|,
name|_args
parameter_list|)
define|\
value|((*(_ic)->ic_send_action)(_ni, _cat, _act, _args))
end_define

begin_define
define|#
directive|define
name|IEEE80211_AGGR_BAWMAX
value|64
end_define

begin_comment
comment|/* max block ack window size */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|ieee80211_seq
typedef|;
end_typedef

begin_struct
struct|struct
name|ieee80211_tx_ampdu
block|{
name|u_short
name|txa_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_AGGR_IMMEDIATE
value|0x0001
comment|/* BA policy */
define|#
directive|define
name|IEEE80211_AGGR_XCHGPEND
value|0x0002
comment|/* ADDBA response pending */
define|#
directive|define
name|IEEE80211_AGGR_RUNNING
value|0x0004
comment|/* ADDBA response received */
define|#
directive|define
name|IEEE80211_AGGR_SETUP
value|0x0008
comment|/* deferred state setup */
name|uint8_t
name|txa_ac
decl_stmt|;
name|uint8_t
name|txa_token
decl_stmt|;
comment|/* dialog token */
name|int
name|txa_qbytes
decl_stmt|;
comment|/* data queued (bytes) */
name|short
name|txa_qframes
decl_stmt|;
comment|/* data queued (frames) */
name|ieee80211_seq
name|txa_seqstart
decl_stmt|;
name|ieee80211_seq
name|txa_start
decl_stmt|;
name|uint16_t
name|txa_wnd
decl_stmt|;
comment|/* BA window size */
name|uint8_t
name|txa_attempts
decl_stmt|;
comment|/* # setup attempts */
name|int
name|txa_lastrequest
decl_stmt|;
comment|/* time of last ADDBA request */
name|struct
name|ifqueue
name|txa_q
decl_stmt|;
comment|/* packet queue */
name|struct
name|callout
name|txa_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* return non-zero if AMPDU tx for the TID is running */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AMPDU_RUNNING
parameter_list|(
name|tap
parameter_list|)
define|\
value|(((tap)->txa_flags& IEEE80211_AGGR_RUNNING) != 0)
end_define

begin_comment
comment|/* return non-zero if AMPDU tx for the TID is running or started */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AMPDU_REQUESTED
parameter_list|(
name|tap
parameter_list|)
define|\
value|(((tap)->txa_flags& \ 	 (IEEE80211_AGGR_RUNNING|IEEE80211_AGGR_XCHGPEND)) != 0)
end_define

begin_struct
struct|struct
name|ieee80211_rx_ampdu
block|{
name|int
name|rxa_flags
decl_stmt|;
name|int
name|rxa_qbytes
decl_stmt|;
comment|/* data queued (bytes) */
name|short
name|rxa_qframes
decl_stmt|;
comment|/* data queued (frames) */
name|ieee80211_seq
name|rxa_seqstart
decl_stmt|;
name|ieee80211_seq
name|rxa_start
decl_stmt|;
comment|/* start of current BA window */
name|ieee80211_seq
name|rxa_nxt
decl_stmt|;
comment|/* next seq# in BA window */
name|uint16_t
name|rxa_wnd
decl_stmt|;
comment|/* BA window size */
name|struct
name|mbuf
modifier|*
name|rxa_m
index|[
name|IEEE80211_AGGR_BAWMAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_ht_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_announce
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|ieee80211_htrates
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|struct
name|ieee80211_htrateset
modifier|*
name|ieee80211_get_suphtrates
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_node
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_setup_htrates
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|htcap
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_setup_basic_htrates
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|htinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_decap_amsdu
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ampdu_reorder
parameter_list|(
name|struct
name|ieee80211_node
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
name|ieee80211_recv_bar
parameter_list|(
name|struct
name|ieee80211_node
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
name|ieee80211_ht_node_init
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_node_cleanup
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_parse_htcap
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_parse_htinfo
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_recv_action
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ampdu_request
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_send_bar
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_send_action
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint16_t
index|[
literal|4
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_htcap
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_htcap_vendor
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_htinfo
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_htinfo_vendor
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_beacon_offsets
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_ht_update_beacon
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_beacon_offsets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_HT_H_ */
end_comment

end_unit

