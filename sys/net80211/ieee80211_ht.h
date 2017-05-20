begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|IEEE80211_AGGR_BAWMAX
value|64
end_define

begin_comment
comment|/* max block ack window size */
end_comment

begin_comment
comment|/* threshold for aging overlapping non-HT bss */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NONHT_PRESENT_AGE
value|msecs_to_ticks(60*1000)
end_define

begin_struct
struct|struct
name|ieee80211_tx_ampdu
block|{
name|struct
name|ieee80211_node
modifier|*
name|txa_ni
decl_stmt|;
comment|/* back pointer */
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
define|#
directive|define
name|IEEE80211_AGGR_NAK
value|0x0010
comment|/* peer NAK'd ADDBA request */
define|#
directive|define
name|IEEE80211_AGGR_BARPEND
value|0x0020
comment|/* BAR response pending */
define|#
directive|define
name|IEEE80211_AGGR_WAITRX
value|0x0040
comment|/* Wait for first RX frame to define BAW */
name|uint8_t
name|txa_tid
decl_stmt|;
name|uint8_t
name|txa_token
decl_stmt|;
comment|/* dialog token */
name|int
name|txa_lastsample
decl_stmt|;
comment|/* ticks @ last traffic sample */
name|int
name|txa_pkts
decl_stmt|;
comment|/* packets over last sample interval */
name|int
name|txa_avgpps
decl_stmt|;
comment|/* filtered traffic over window */
name|int
name|txa_qbytes
decl_stmt|;
comment|/* data queued (bytes) */
name|short
name|txa_qframes
decl_stmt|;
comment|/* data queued (frames) */
name|ieee80211_seq
name|txa_start
decl_stmt|;
comment|/* BA window left edge */
name|ieee80211_seq
name|txa_seqpending
decl_stmt|;
comment|/* new txa_start pending BAR response */
name|uint16_t
name|txa_wnd
decl_stmt|;
comment|/* BA window size */
name|uint8_t
name|txa_attempts
decl_stmt|;
comment|/* # ADDBA/BAR requests w/o a response*/
name|int
name|txa_nextrequest
decl_stmt|;
comment|/* soonest to make next request */
name|struct
name|callout
name|txa_timer
decl_stmt|;
name|void
modifier|*
name|txa_private
decl_stmt|;
comment|/* driver-private storage */
name|uint64_t
name|txa_pad
index|[
literal|4
index|]
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
comment|/* return non-zero if AMPDU tx for the TID was NACKed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AMPDU_NACKED
parameter_list|(
name|tap
parameter_list|)
define|\
value|(!! ((tap)->txa_flags& IEEE80211_AGGR_NAK))
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
value|(((tap)->txa_flags& \ 	 (IEEE80211_AGGR_RUNNING|IEEE80211_AGGR_XCHGPEND|IEEE80211_AGGR_NAK)) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_AGGR_BITS
define|\
value|"\20\1IMMEDIATE\2XCHGPEND\3RUNNING\4SETUP\5NAK"
end_define

begin_comment
comment|/*  * Traffic estimator support.  We estimate packets/sec for  * each AC that is setup for AMPDU or will potentially be  * setup for AMPDU.  The traffic rate can be used to decide  * when AMPDU should be setup (according to a threshold)  * and is available for drivers to do things like cache  * eviction when only a limited number of BA streams are  * available and more streams are requested than available.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_txampdu_init_pps
parameter_list|(
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|tap
parameter_list|)
block|{
comment|/* 	 * Reset packet estimate. 	 */
name|tap
operator|->
name|txa_lastsample
operator|=
name|ticks
expr_stmt|;
name|tap
operator|->
name|txa_avgpps
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_txampdu_update_pps
parameter_list|(
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|tap
parameter_list|)
block|{
comment|/* NB: scale factor of 2 was picked heuristically */
name|tap
operator|->
name|txa_avgpps
operator|=
operator|(
operator|(
name|tap
operator|->
name|txa_avgpps
operator|<<
literal|2
operator|)
operator|-
name|tap
operator|->
name|txa_avgpps
operator|+
name|tap
operator|->
name|txa_pkts
operator|)
operator|>>
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Count a packet towards the pps estimate.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_txampdu_count_packet
parameter_list|(
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|tap
parameter_list|)
block|{
comment|/* XXX bound loop/do more crude estimate? */
while|while
condition|(
name|ticks
operator|-
name|tap
operator|->
name|txa_lastsample
operator|>=
name|hz
condition|)
block|{
name|ieee80211_txampdu_update_pps
argument_list|(
name|tap
argument_list|)
expr_stmt|;
comment|/* reset to start new sample interval */
name|tap
operator|->
name|txa_pkts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tap
operator|->
name|txa_avgpps
operator|==
literal|0
condition|)
block|{
name|tap
operator|->
name|txa_lastsample
operator|=
name|ticks
expr_stmt|;
break|break;
block|}
name|tap
operator|->
name|txa_lastsample
operator|+=
name|hz
expr_stmt|;
block|}
name|tap
operator|->
name|txa_pkts
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get the current pps estimate.  If the average is out of  * date due to lack of traffic then we decay the estimate  * to account for the idle time.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_txampdu_getpps
parameter_list|(
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|tap
parameter_list|)
block|{
comment|/* XXX bound loop/do more crude estimate? */
while|while
condition|(
name|ticks
operator|-
name|tap
operator|->
name|txa_lastsample
operator|>=
name|hz
condition|)
block|{
name|ieee80211_txampdu_update_pps
argument_list|(
name|tap
argument_list|)
expr_stmt|;
name|tap
operator|->
name|txa_pkts
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tap
operator|->
name|txa_avgpps
operator|==
literal|0
condition|)
block|{
name|tap
operator|->
name|txa_lastsample
operator|=
name|ticks
expr_stmt|;
break|break;
block|}
name|tap
operator|->
name|txa_lastsample
operator|+=
name|hz
expr_stmt|;
block|}
return|return
name|tap
operator|->
name|txa_avgpps
return|;
block|}
end_function

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
name|uint16_t
name|rxa_wnd
decl_stmt|;
comment|/* BA window size */
name|int
name|rxa_age
decl_stmt|;
comment|/* age of oldest frame in window */
name|int
name|rxa_nframes
decl_stmt|;
comment|/* frames since ADDBA */
name|struct
name|mbuf
modifier|*
name|rxa_m
index|[
name|IEEE80211_AGGR_BAWMAX
index|]
decl_stmt|;
name|void
modifier|*
name|rxa_private
decl_stmt|;
name|uint64_t
name|rxa_pad
index|[
literal|3
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
name|ieee80211_ht_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_vdetach
parameter_list|(
name|struct
name|ieee80211vap
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

begin_struct
struct|struct
name|ieee80211_mcs_rates
block|{
name|uint16_t
name|ht20_rate_800ns
decl_stmt|;
name|uint16_t
name|ht20_rate_400ns
decl_stmt|;
name|uint16_t
name|ht40_rate_800ns
decl_stmt|;
name|uint16_t
name|ht40_rate_400ns
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ieee80211_mcs_rates
name|ieee80211_htrates
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ieee80211_init_suphtrates
parameter_list|(
name|struct
name|ieee80211com
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
parameter_list|,
specifier|const
name|struct
name|ieee80211_rx_stats
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
name|ieee80211_ht_node_age
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_channel
modifier|*
name|ieee80211_ht_adjust_channel
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_wds_init
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_node_join
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_node_leave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_htprot_update
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|protmode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ht_timeout
parameter_list|(
name|struct
name|ieee80211com
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
name|ieee80211_ht_updateparams
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
name|ieee80211_ht_updateparams_final
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
name|void
name|ieee80211_ht_updatehtcap
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
name|ieee80211_ht_updatehtcap_final
parameter_list|(
name|struct
name|ieee80211_node
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
name|void
name|ieee80211_ampdu_stop
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|,
name|int
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
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|,
name|ieee80211_seq
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
name|ieee80211_add_htcap_ch
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
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
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_beacon_offsets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ampdu_rx_start_ext
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
name|tid
parameter_list|,
name|int
name|seq
parameter_list|,
name|int
name|baw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ampdu_rx_stop_ext
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ampdu_tx_request_ext
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ampdu_tx_request_active_ext
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
name|tid
parameter_list|,
name|int
name|status
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

