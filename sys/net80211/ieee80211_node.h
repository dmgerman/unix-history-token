begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_NODE_H_
end_define

begin_include
include|#
directive|include
file|<net80211/ieee80211_ioctl.h>
end_include

begin_comment
comment|/* for ieee80211_nodestats */
end_comment

begin_include
include|#
directive|include
file|<net80211/ieee80211_ht.h>
end_include

begin_comment
comment|/* for aggregation state */
end_comment

begin_comment
comment|/*  * Each ieee80211com instance has a single timer that fires every  * IEEE80211_INACT_WAIT seconds to handle "inactivity processing".  * This is used to do node inactivity processing when operating  * as an AP or in adhoc mode.  For inactivity processing each node  * has a timeout set in it's ni_inact field that is decremented  * on each timeout and the node is reclaimed when the counter goes  * to zero.  We use different inactivity timeout values depending  * on whether the node is associated and authorized (either by  * 802.1x or open/shared key authentication) or associated but yet  * to be authorized.  The latter timeout is shorter to more aggressively  * reclaim nodes that leave part way through the 802.1x exchange.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_WAIT
value|15
end_define

begin_comment
comment|/* inactivity interval (secs) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_INIT
value|(30/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/* initial */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_AUTH
value|(180/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/* associated but not authorized */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_RUN
value|(300/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/* authorized */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_PROBE
value|(30/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/* probe */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_SCAN
value|(300/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/* scanned */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_TRANS_WAIT
value|2
end_define

begin_comment
comment|/* mgt frame tx timer (secs) */
end_comment

begin_comment
comment|/* threshold for aging overlapping non-ERP bss */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NONERP_PRESENT_AGE
value|msecs_to_ticks(60*1000)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_HASHSIZE
value|32
end_define

begin_comment
comment|/* simple hash is enough for variation of macaddr */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NODE_HASH
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((const uint8_t *)(addr))[IEEE80211_ADDR_LEN - 1] % \ 		IEEE80211_NODE_HASHSIZE)
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_node_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Information element ``blob''.  We use this structure  * to capture management frame payloads that need to be  * retained.  Information elements within the payload that  * we need to consult have references recorded.  */
end_comment

begin_struct
struct|struct
name|ieee80211_ies
block|{
comment|/* the following are either NULL or point within data */
name|uint8_t
modifier|*
name|wpa_ie
decl_stmt|;
comment|/* captured WPA ie */
name|uint8_t
modifier|*
name|rsn_ie
decl_stmt|;
comment|/* captured RSN ie */
name|uint8_t
modifier|*
name|wme_ie
decl_stmt|;
comment|/* captured WME ie */
name|uint8_t
modifier|*
name|ath_ie
decl_stmt|;
comment|/* captured Atheros ie */
name|uint8_t
modifier|*
name|htcap_ie
decl_stmt|;
comment|/* captured HTCAP ie */
name|uint8_t
modifier|*
name|htinfo_ie
decl_stmt|;
comment|/* captured HTINFO ie */
name|uint8_t
modifier|*
name|tdma_ie
decl_stmt|;
comment|/* captured TDMA ie */
comment|/* NB: these must be the last members of this structure */
name|uint8_t
modifier|*
name|data
decl_stmt|;
comment|/* frame data> 802.11 header */
name|int
name|len
decl_stmt|;
comment|/* data size in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Node specific information.  Note that drivers are expected  * to derive from this structure to add device-specific per-node  * state.  This is done by overriding the ic_node_* methods in  * the ieee80211com structure.  */
end_comment

begin_struct
struct|struct
name|ieee80211_node
block|{
name|struct
name|ieee80211vap
modifier|*
name|ni_vap
decl_stmt|;
comment|/* associated vap */
name|struct
name|ieee80211com
modifier|*
name|ni_ic
decl_stmt|;
comment|/* copy from vap to save deref*/
name|struct
name|ieee80211_node_table
modifier|*
name|ni_table
decl_stmt|;
comment|/* NB: may be NULL */
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_list
expr_stmt|;
comment|/* list of all nodes */
name|LIST_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_hash
expr_stmt|;
comment|/* hash collision list */
name|u_int
name|ni_refcnt
decl_stmt|;
comment|/* count of held references */
name|u_int
name|ni_scangen
decl_stmt|;
comment|/* gen# for timeout scan */
name|u_int
name|ni_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_NODE_AUTH
value|0x000001
comment|/* authorized for data */
define|#
directive|define
name|IEEE80211_NODE_QOS
value|0x000002
comment|/* QoS enabled */
define|#
directive|define
name|IEEE80211_NODE_ERP
value|0x000004
comment|/* ERP enabled */
comment|/* NB: this must have the same value as IEEE80211_FC1_PWR_MGT */
define|#
directive|define
name|IEEE80211_NODE_PWR_MGT
value|0x000010
comment|/* power save mode enabled */
define|#
directive|define
name|IEEE80211_NODE_AREF
value|0x000020
comment|/* authentication ref held */
define|#
directive|define
name|IEEE80211_NODE_HT
value|0x000040
comment|/* HT enabled */
define|#
directive|define
name|IEEE80211_NODE_HTCOMPAT
value|0x000080
comment|/* HT setup w/ vendor OUI's */
define|#
directive|define
name|IEEE80211_NODE_WPS
value|0x000100
comment|/* WPS association */
define|#
directive|define
name|IEEE80211_NODE_TSN
value|0x000200
comment|/* TSN association */
define|#
directive|define
name|IEEE80211_NODE_AMPDU_RX
value|0x000400
comment|/* AMPDU rx enabled */
define|#
directive|define
name|IEEE80211_NODE_AMPDU_TX
value|0x000800
comment|/* AMPDU tx enabled */
define|#
directive|define
name|IEEE80211_NODE_MIMO_PS
value|0x001000
comment|/* MIMO power save enabled */
define|#
directive|define
name|IEEE80211_NODE_MIMO_RTS
value|0x002000
comment|/* send RTS in MIMO PS */
define|#
directive|define
name|IEEE80211_NODE_RIFS
value|0x004000
comment|/* RIFS enabled */
define|#
directive|define
name|IEEE80211_NODE_SGI20
value|0x008000
comment|/* Short GI in HT20 enabled */
define|#
directive|define
name|IEEE80211_NODE_SGI40
value|0x010000
comment|/* Short GI in HT40 enabled */
define|#
directive|define
name|IEEE80211_NODE_ASSOCID
value|0x020000
comment|/* xmit requires associd */
name|uint16_t
name|ni_associd
decl_stmt|;
comment|/* association ID */
name|uint16_t
name|ni_vlan
decl_stmt|;
comment|/* vlan tag */
name|uint16_t
name|ni_txpower
decl_stmt|;
comment|/* current transmit power */
name|uint8_t
name|ni_authmode
decl_stmt|;
comment|/* authentication algorithm */
name|uint8_t
name|ni_ath_flags
decl_stmt|;
comment|/* Atheros feature flags */
comment|/* NB: These must have the same values as IEEE80211_ATHC_* */
define|#
directive|define
name|IEEE80211_NODE_TURBOP
value|0x0001
comment|/* Turbo prime enable */
define|#
directive|define
name|IEEE80211_NODE_COMP
value|0x0002
comment|/* Compresssion enable */
define|#
directive|define
name|IEEE80211_NODE_FF
value|0x0004
comment|/* Fast Frame capable */
define|#
directive|define
name|IEEE80211_NODE_XR
value|0x0008
comment|/* Atheros WME enable */
define|#
directive|define
name|IEEE80211_NODE_AR
value|0x0010
comment|/* AR capable */
define|#
directive|define
name|IEEE80211_NODE_BOOST
value|0x0080
comment|/* Dynamic Turbo boosted */
name|uint16_t
name|ni_ath_defkeyix
decl_stmt|;
comment|/* Atheros def key index */
specifier|const
name|struct
name|ieee80211_txparam
modifier|*
name|ni_txparms
decl_stmt|;
name|uint32_t
name|ni_jointime
decl_stmt|;
comment|/* time of join (secs) */
name|uint32_t
modifier|*
name|ni_challenge
decl_stmt|;
comment|/* shared-key challenge */
name|struct
name|ieee80211_ies
name|ni_ies
decl_stmt|;
comment|/* captured ie's */
comment|/* tx seq per-tid */
name|uint16_t
name|ni_txseqs
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
comment|/* rx seq previous per-tid*/
name|uint16_t
name|ni_rxseqs
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
name|uint32_t
name|ni_rxfragstamp
decl_stmt|;
comment|/* time stamp of last rx frag */
name|struct
name|mbuf
modifier|*
name|ni_rxfrag
index|[
literal|3
index|]
decl_stmt|;
comment|/* rx frag reassembly */
name|struct
name|ieee80211_key
name|ni_ucastkey
decl_stmt|;
comment|/* unicast key */
comment|/* hardware */
name|uint32_t
name|ni_rstamp
decl_stmt|;
comment|/* recv timestamp */
name|uint32_t
name|ni_avgrssi
decl_stmt|;
comment|/* recv ssi state */
name|int8_t
name|ni_noise
decl_stmt|;
comment|/* noise floor */
comment|/* header */
name|uint8_t
name|ni_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|ni_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* beacon, probe response */
union|union
block|{
name|uint8_t
name|data
index|[
literal|8
index|]
decl_stmt|;
name|u_int64_t
name|tsf
decl_stmt|;
block|}
name|ni_tstamp
union|;
comment|/* from last rcv'd beacon */
name|uint16_t
name|ni_intval
decl_stmt|;
comment|/* beacon interval */
name|uint16_t
name|ni_capinfo
decl_stmt|;
comment|/* capabilities */
name|uint8_t
name|ni_esslen
decl_stmt|;
name|uint8_t
name|ni_essid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|struct
name|ieee80211_rateset
name|ni_rates
decl_stmt|;
comment|/* negotiated rate set */
name|struct
name|ieee80211_channel
modifier|*
name|ni_chan
decl_stmt|;
name|uint16_t
name|ni_fhdwell
decl_stmt|;
comment|/* FH only */
name|uint8_t
name|ni_fhindex
decl_stmt|;
comment|/* FH only */
name|uint16_t
name|ni_erp
decl_stmt|;
comment|/* ERP from beacon/probe resp */
name|uint16_t
name|ni_timoff
decl_stmt|;
comment|/* byte offset to TIM ie */
name|uint8_t
name|ni_dtim_period
decl_stmt|;
comment|/* DTIM period */
name|uint8_t
name|ni_dtim_count
decl_stmt|;
comment|/* DTIM count for last bcn */
comment|/* 11n state */
name|uint16_t
name|ni_htcap
decl_stmt|;
comment|/* HT capabilities */
name|uint8_t
name|ni_htparam
decl_stmt|;
comment|/* HT params */
name|uint8_t
name|ni_htctlchan
decl_stmt|;
comment|/* HT control channel */
name|uint8_t
name|ni_ht2ndchan
decl_stmt|;
comment|/* HT 2nd channel */
name|uint8_t
name|ni_htopmode
decl_stmt|;
comment|/* HT operating mode */
name|uint8_t
name|ni_htstbc
decl_stmt|;
comment|/* HT */
name|uint8_t
name|ni_chw
decl_stmt|;
comment|/* negotiated channel width */
name|struct
name|ieee80211_htrateset
name|ni_htrates
decl_stmt|;
comment|/* negotiated ht rate set */
name|struct
name|ieee80211_tx_ampdu
name|ni_tx_ampdu
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|struct
name|ieee80211_rx_ampdu
name|ni_rx_ampdu
index|[
name|WME_NUM_TID
index|]
decl_stmt|;
comment|/* others */
name|short
name|ni_inact
decl_stmt|;
comment|/* inactivity mark count */
name|short
name|ni_inact_reload
decl_stmt|;
comment|/* inactivity reload value */
name|int
name|ni_txrate
decl_stmt|;
comment|/* legacy rate/MCS */
name|struct
name|ieee80211_psq
name|ni_psq
decl_stmt|;
comment|/* power save queue */
name|struct
name|ieee80211_nodestats
name|ni_stats
decl_stmt|;
comment|/* per-node statistics */
name|struct
name|ieee80211vap
modifier|*
name|ni_wdsvap
decl_stmt|;
comment|/* associated WDS vap */
comment|/* XXX move to vap? */
name|struct
name|ifqueue
name|ni_wdsq
decl_stmt|;
comment|/* wds pending queue */
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_NODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_NODE_IE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IEEE80211_NODE_ATH
value|(IEEE80211_NODE_FF | IEEE80211_NODE_TURBOP)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_AMPDU
define|\
value|(IEEE80211_NODE_AMPDU_RX | IEEE80211_NODE_AMPDU_TX)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_HT_ALL
define|\
value|(IEEE80211_NODE_HT | IEEE80211_NODE_HTCOMPAT | \ 	 IEEE80211_NODE_AMPDU | IEEE80211_NODE_MIMO_PS | \ 	 IEEE80211_NODE_MIMO_RTS | IEEE80211_NODE_RIFS | \ 	 IEEE80211_NODE_SGI20 | IEEE80211_NODE_SGI40)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_BITS
define|\
value|"\20\1AUTH\2QOS\3ERP\5PWR_MGT\6AREF\7HT\10HTCOMPAT\11WPS\12TSN" \ 	"\13AMPDU_RX\14AMPDU_TX\15MIMO_PS\16MIMO_RTS\17RIFS\20SGI20\21SGI40" \ 	"\22ASSOCID"
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_AID
parameter_list|(
name|ni
parameter_list|)
value|IEEE80211_AID(ni->ni_associd)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_STAT
parameter_list|(
name|ni
parameter_list|,
name|stat
parameter_list|)
value|(ni->ni_stats.ns_##stat++)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_STAT_ADD
parameter_list|(
name|ni
parameter_list|,
name|stat
parameter_list|,
name|v
parameter_list|)
value|(ni->ni_stats.ns_##stat += v)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_STAT_SET
parameter_list|(
name|ni
parameter_list|,
name|stat
parameter_list|,
name|v
parameter_list|)
value|(ni->ni_stats.ns_##stat = v)
end_define

begin_comment
comment|/*  * Filtered rssi calculation support.  The receive rssi is maintained  * as an average over the last 10 frames received using a low pass filter  * (all frames for now, possibly need to be more selective).  Calculations  * are designed such that a good compiler can optimize them.  The avg  * rssi state should be initialized to IEEE80211_RSSI_DUMMY_MARKER and  * each sample incorporated with IEEE80211_RSSI_LPF.  Use IEEE80211_RSSI_GET  * to extract the current value.  *  * Note that we assume rssi data are in the range [-127..127] and we  * discard values<-20.  This is consistent with assumptions throughout  * net80211 that signal strength data are in .5 dBm units relative to  * the current noise floor (linear, not log).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RSSI_LPF_LEN
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSI_DUMMY_MARKER
value|127
end_define

begin_comment
comment|/* NB: pow2 to optimize out * and / */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RSSI_EP_MULTIPLIER
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSI_IN
parameter_list|(
name|x
parameter_list|)
value|((x) * IEEE80211_RSSI_EP_MULTIPLIER)
end_define

begin_define
define|#
directive|define
name|_IEEE80211_RSSI_LPF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|len
parameter_list|)
define|\
value|(((x) != IEEE80211_RSSI_DUMMY_MARKER) ? (((x) * ((len) - 1) + (y)) / (len)) : (y))
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSI_LPF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {					\     if ((y)>= -20) {							\     	x = _IEEE80211_RSSI_LPF((x), IEEE80211_RSSI_IN((y)), 		\ 		IEEE80211_RSSI_LPF_LEN);				\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSI_EP_RND
parameter_list|(
name|x
parameter_list|,
name|mul
parameter_list|)
define|\
value|((((x) % (mul))>= ((mul)/2)) ? ((x) + ((mul) - 1)) / (mul) : (x)/(mul))
end_define

begin_define
define|#
directive|define
name|IEEE80211_RSSI_GET
parameter_list|(
name|x
parameter_list|)
define|\
value|IEEE80211_RSSI_EP_RND(x, IEEE80211_RSSI_EP_MULTIPLIER)
end_define

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ieee80211_node
operator|*
name|ieee80211_ref_node
argument_list|(
argument|struct ieee80211_node *ni
argument_list|)
block|{
name|ieee80211_node_incref
argument_list|(
name|ni
argument_list|)
block|;
return|return
name|ni
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_unref_node
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
modifier|*
name|ni
parameter_list|)
block|{
name|ieee80211_node_decref
argument_list|(
operator|*
name|ni
argument_list|)
expr_stmt|;
operator|*
name|ni
operator|=
name|NULL
expr_stmt|;
comment|/* guard against use */
block|}
end_function

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_node_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_lateattach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_latevattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_node_is_authorized
parameter_list|(
specifier|const
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
block|{
return|return
operator|(
name|ni
operator|->
name|ni_flags
operator|&
name|IEEE80211_NODE_AUTH
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|ieee80211_node_authorize
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_unauthorize
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_set_chan
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_create_ibss
parameter_list|(
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
name|void
name|ieee80211_reset_bss
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sync_curchan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_setcurchan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ibss_merge
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_scan_entry
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_sta_join
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scan_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sta_leave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_deauth
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ies_init
parameter_list|(
name|struct
name|ieee80211_ies
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ies_cleanup
parameter_list|(
name|struct
name|ieee80211_ies
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ies_expand
parameter_list|(
name|struct
name|ieee80211_ies
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ieee80211_ies_setie
parameter_list|(
name|_ies
parameter_list|,
name|_ie
parameter_list|,
name|_off
parameter_list|)
value|do {		\ 	(_ies)._ie = (_ies).data + (_off);			\ } while (0)
end_define

begin_comment
comment|/*  * Table of ieee80211_node instances.  Each ieee80211com  * has one that holds association stations (when operating  * as an ap) or neighbors (in ibss mode).  *  * XXX embed this in ieee80211com instead of indirect?  */
end_comment

begin_struct
struct|struct
name|ieee80211_node_table
block|{
name|struct
name|ieee80211com
modifier|*
name|nt_ic
decl_stmt|;
comment|/* back reference */
name|ieee80211_node_lock_t
name|nt_nodelock
decl_stmt|;
comment|/* on node table */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ieee80211_node
argument_list|)
name|nt_node
expr_stmt|;
comment|/* information of all nodes */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ieee80211_node
argument_list|)
name|nt_hash
index|[
name|IEEE80211_NODE_HASHSIZE
index|]
expr_stmt|;
name|struct
name|ieee80211_node
modifier|*
modifier|*
name|nt_keyixmap
decl_stmt|;
comment|/* key ix -> node map */
name|int
name|nt_keyixmax
decl_stmt|;
comment|/* keyixmap size */
specifier|const
name|char
modifier|*
name|nt_name
decl_stmt|;
comment|/* table name for debug msgs */
name|ieee80211_scan_lock_t
name|nt_scanlock
decl_stmt|;
comment|/* on nt_scangen */
name|u_int
name|nt_scangen
decl_stmt|;
comment|/* gen# for iterators */
name|int
name|nt_inact_init
decl_stmt|;
comment|/* initial node inact setting */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_alloc_node
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_tmp_node
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_dup_bss
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_node_create_wds
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_DEBUG_REFCNT
end_ifdef

begin_function_decl
name|void
name|ieee80211_free_node_debug
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_node_locked_debug
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_node_debug
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_vap_node_locked_debug
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_vap_node_debug
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_rxnode_debug
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame_min
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_rxnode_withkey_debug
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame_min
modifier|*
parameter_list|,
name|uint16_t
name|keyix
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_txnode_debug
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ieee80211_free_node
parameter_list|(
name|ni
parameter_list|)
define|\
value|ieee80211_free_node_debug(ni, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_node_locked
parameter_list|(
name|nt
parameter_list|,
name|mac
parameter_list|)
define|\
value|ieee80211_find_node_locked_debug(nt, mac, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_node
parameter_list|(
name|nt
parameter_list|,
name|mac
parameter_list|)
define|\
value|ieee80211_find_node_debug(nt, mac, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_vap_node_locked
parameter_list|(
name|nt
parameter_list|,
name|vap
parameter_list|,
name|mac
parameter_list|)
define|\
value|ieee80211_find_vap_node_locked_debug(nt, vap, mac, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_vap_node
parameter_list|(
name|nt
parameter_list|,
name|vap
parameter_list|,
name|mac
parameter_list|)
define|\
value|ieee80211_find_vap_node_debug(nt, vap, mac, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_rxnode
parameter_list|(
name|ic
parameter_list|,
name|wh
parameter_list|)
define|\
value|ieee80211_find_rxnode_debug(ic, wh, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_rxnode_withkey
parameter_list|(
name|ic
parameter_list|,
name|wh
parameter_list|,
name|keyix
parameter_list|)
define|\
value|ieee80211_find_rxnode_withkey_debug(ic, wh, keyix, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ieee80211_find_txnode
parameter_list|(
name|vap
parameter_list|,
name|mac
parameter_list|)
define|\
value|ieee80211_find_txnode_debug(vap, mac, __func__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|ieee80211_free_node
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_node_locked
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_node
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_vap_node_locked
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_vap_node
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_rxnode
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame_min
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_rxnode_withkey
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame_min
modifier|*
parameter_list|,
name|uint16_t
name|keyix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_txnode
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ieee80211_node_delucastkey
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_timeout
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|ieee80211_iter_func
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|ieee80211_iterate_nodes
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
name|ieee80211_iter_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_erp
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_dump_node
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_dump_nodes
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_fakeup_adhoc_node
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_scanparams
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_init_neighbor
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanparams
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_add_neighbor
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanparams
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_join
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_leave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int8_t
name|ieee80211_getrssi
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_getsignal
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_NODE_H_ */
end_comment

end_unit

