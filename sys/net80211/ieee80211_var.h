begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_VAR_H_
end_define

begin_comment
comment|/*  * Definitions for IEEE 802.11 drivers.  */
end_comment

begin_comment
comment|/* NB: portability glue must go first */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<net80211/ieee80211_netbsd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<net80211/ieee80211_freebsd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<net80211/ieee80211_linux.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"No support for your operating system!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net80211/_ieee80211.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ageq.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_crypto.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_dfs.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ioctl.h>
end_include

begin_comment
comment|/* for ieee80211_stats */
end_comment

begin_include
include|#
directive|include
file|<net80211/ieee80211_phy.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_power.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_node.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_proto.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_scan.h>
end_include

begin_define
define|#
directive|define
name|IEEE80211_TXPOWER_MAX
value|100
end_define

begin_comment
comment|/* .5 dbM (XXX units?) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_TXPOWER_MIN
value|0
end_define

begin_comment
comment|/* kill radio */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DTIM_DEFAULT
value|1
end_define

begin_comment
comment|/* default DTIM period */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BINTVAL_DEFAULT
value|100
end_define

begin_comment
comment|/* default beacon interval (TU's) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BMISS_MAX
value|2
end_define

begin_comment
comment|/* maximum consecutive bmiss allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HWBMISS_DEFAULT
value|7
end_define

begin_comment
comment|/* h/w bmiss threshold (beacons) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BGSCAN_INTVAL_MIN
value|15
end_define

begin_comment
comment|/* min bg scan intvl (secs) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BGSCAN_INTVAL_DEFAULT
value|(5*60)
end_define

begin_comment
comment|/* default bg scan intvl */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BGSCAN_IDLE_MIN
value|100
end_define

begin_comment
comment|/* min idle time (ms) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BGSCAN_IDLE_DEFAULT
value|250
end_define

begin_comment
comment|/* default idle time (ms) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SCAN_VALID_MIN
value|10
end_define

begin_comment
comment|/* min scan valid time (secs) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SCAN_VALID_DEFAULT
value|60
end_define

begin_comment
comment|/* default scan valid time */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_PS_SLEEP
value|0x1
end_define

begin_comment
comment|/* STA is in power saving mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_PS_MAX_QUEUE
value|50
end_define

begin_comment
comment|/* maximum saved packets */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FIXED_RATE_NONE
value|0xff
end_define

begin_define
define|#
directive|define
name|IEEE80211_TXMAX_DEFAULT
value|6
end_define

begin_comment
comment|/* default ucast max retries */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RTS_DEFAULT
value|IEEE80211_RTS_MAX
end_define

begin_define
define|#
directive|define
name|IEEE80211_FRAG_DEFAULT
value|IEEE80211_FRAG_MAX
end_define

begin_define
define|#
directive|define
name|IEEE80211_MS_TO_TU
parameter_list|(
name|x
parameter_list|)
value|(((x) * 1000) / 1024)
end_define

begin_define
define|#
directive|define
name|IEEE80211_TU_TO_MS
parameter_list|(
name|x
parameter_list|)
value|(((x) * 1024) / 1000)
end_define

begin_define
define|#
directive|define
name|IEEE80211_TU_TO_TICKS
parameter_list|(
name|x
parameter_list|)
value|(((x) * 1024 * hz) / (1000 * 1000))
end_define

begin_comment
comment|/*  * 802.11 control state is split into a common portion that maps  * 1-1 to a physical device and one or more "Virtual AP's" (VAP)  * that are bound to an ieee80211com instance and share a single  * underlying device.  Each VAP has a corresponding OS device  * entity through which traffic flows and that applications use  * for issuing ioctls, etc.  */
end_comment

begin_comment
comment|/*  * Data common to one or more virtual AP's.  State shared by  * the underlying device and the net80211 layer is exposed here;  * e.g. device-specific callbacks.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ieee80211vap_attach
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ieee80211_appie
block|{
name|uint16_t
name|ie_len
decl_stmt|;
comment|/* size of ie_data */
name|uint8_t
name|ie_data
index|[]
decl_stmt|;
comment|/* user-specified IE's */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ieee80211_tdma_param
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_rate_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_tx_ampdu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_rx_ampdu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_superg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_frame
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee80211com
block|{
name|struct
name|ifnet
modifier|*
name|ic_ifp
decl_stmt|;
comment|/* associated device */
name|ieee80211_com_lock_t
name|ic_comlock
decl_stmt|;
comment|/* state update lock */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ieee80211vap
argument_list|)
name|ic_vaps
expr_stmt|;
comment|/* list of vap instances */
name|int
name|ic_headroom
decl_stmt|;
comment|/* driver tx headroom needs */
name|enum
name|ieee80211_phytype
name|ic_phytype
decl_stmt|;
comment|/* XXX wrong for multi-mode */
name|enum
name|ieee80211_opmode
name|ic_opmode
decl_stmt|;
comment|/* operation mode */
name|struct
name|ifmedia
name|ic_media
decl_stmt|;
comment|/* interface media config */
name|struct
name|callout
name|ic_inact
decl_stmt|;
comment|/* inactivity processing */
name|struct
name|taskqueue
modifier|*
name|ic_tq
decl_stmt|;
comment|/* deferred state thread */
name|struct
name|task
name|ic_parent_task
decl_stmt|;
comment|/* deferred parent processing */
name|struct
name|task
name|ic_promisc_task
decl_stmt|;
comment|/* deferred promisc update */
name|struct
name|task
name|ic_mcast_task
decl_stmt|;
comment|/* deferred mcast update */
name|struct
name|task
name|ic_chan_task
decl_stmt|;
comment|/* deferred channel change */
name|struct
name|task
name|ic_bmiss_task
decl_stmt|;
comment|/* deferred beacon miss hndlr */
name|uint32_t
name|ic_flags
decl_stmt|;
comment|/* state flags */
name|uint32_t
name|ic_flags_ext
decl_stmt|;
comment|/* extended state flags */
name|uint32_t
name|ic_flags_ht
decl_stmt|;
comment|/* HT state flags */
name|uint32_t
name|ic_flags_ven
decl_stmt|;
comment|/* vendor state flags */
name|uint32_t
name|ic_caps
decl_stmt|;
comment|/* capabilities */
name|uint32_t
name|ic_htcaps
decl_stmt|;
comment|/* HT capabilities */
name|uint32_t
name|ic_cryptocaps
decl_stmt|;
comment|/* crypto capabilities */
name|uint8_t
name|ic_modecaps
index|[
literal|2
index|]
decl_stmt|;
comment|/* set of mode capabilities */
name|uint8_t
name|ic_promisc
decl_stmt|;
comment|/* vap's needing promisc mode */
name|uint8_t
name|ic_allmulti
decl_stmt|;
comment|/* vap's needing all multicast*/
name|uint8_t
name|ic_nrunning
decl_stmt|;
comment|/* vap's marked running */
name|uint8_t
name|ic_curmode
decl_stmt|;
comment|/* current mode */
name|uint16_t
name|ic_bintval
decl_stmt|;
comment|/* beacon interval */
name|uint16_t
name|ic_lintval
decl_stmt|;
comment|/* listen interval */
name|uint16_t
name|ic_holdover
decl_stmt|;
comment|/* PM hold over duration */
name|uint16_t
name|ic_txpowlimit
decl_stmt|;
comment|/* global tx power limit */
name|struct
name|ieee80211_rateset
name|ic_sup_rates
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
comment|/* 	 * Channel state: 	 * 	 * ic_channels is the set of available channels for the device; 	 *    it is setup by the driver 	 * ic_nchans is the number of valid entries in ic_channels 	 * ic_chan_avail is a bit vector of these channels used to check 	 *    whether a channel is available w/o searching the channel table. 	 * ic_chan_active is a (potentially) constrained subset of 	 *    ic_chan_avail that reflects any mode setting or user-specified 	 *    limit on the set of channels to use/scan 	 * ic_curchan is the current channel the device is set to; it may 	 *    be different from ic_bsschan when we are off-channel scanning 	 *    or otherwise doing background work 	 * ic_bsschan is the channel selected for operation; it may 	 *    be undefined (IEEE80211_CHAN_ANYC) 	 * ic_prevchan is a cached ``previous channel'' used to optimize 	 *    lookups when switching back+forth between two channels 	 *    (e.g. for dynamic turbo) 	 */
name|int
name|ic_nchans
decl_stmt|;
comment|/* # entries in ic_channels */
name|struct
name|ieee80211_channel
name|ic_channels
index|[
name|IEEE80211_CHAN_MAX
index|]
decl_stmt|;
name|uint8_t
name|ic_chan_avail
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|uint8_t
name|ic_chan_active
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|uint8_t
name|ic_chan_scan
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|struct
name|ieee80211_channel
modifier|*
name|ic_curchan
decl_stmt|;
comment|/* current channel */
specifier|const
name|struct
name|ieee80211_rate_table
modifier|*
name|ic_rt
decl_stmt|;
comment|/* table for ic_curchan */
name|struct
name|ieee80211_channel
modifier|*
name|ic_bsschan
decl_stmt|;
comment|/* bss channel */
name|struct
name|ieee80211_channel
modifier|*
name|ic_prevchan
decl_stmt|;
comment|/* previous channel */
name|struct
name|ieee80211_regdomain
name|ic_regdomain
decl_stmt|;
comment|/* regulatory data */
name|struct
name|ieee80211_appie
modifier|*
name|ic_countryie
decl_stmt|;
comment|/* calculated country ie */
name|struct
name|ieee80211_channel
modifier|*
name|ic_countryie_chan
decl_stmt|;
comment|/* 802.11h/DFS state */
name|struct
name|ieee80211_channel
modifier|*
name|ic_csa_newchan
decl_stmt|;
comment|/* channel for doing CSA */
name|short
name|ic_csa_mode
decl_stmt|;
comment|/* mode for doing CSA */
name|short
name|ic_csa_count
decl_stmt|;
comment|/* count for doing CSA */
name|struct
name|ieee80211_dfs_state
name|ic_dfs
decl_stmt|;
comment|/* DFS state */
name|struct
name|ieee80211_scan_state
modifier|*
name|ic_scan
decl_stmt|;
comment|/* scan state */
name|int
name|ic_lastdata
decl_stmt|;
comment|/* time of last data frame */
name|int
name|ic_lastscan
decl_stmt|;
comment|/* time last scan completed */
comment|/* NB: this is the union of all vap stations/neighbors */
name|int
name|ic_max_keyix
decl_stmt|;
comment|/* max h/w key index */
name|struct
name|ieee80211_node_table
name|ic_sta
decl_stmt|;
comment|/* stations/neighbors */
name|struct
name|ieee80211_ageq
name|ic_stageq
decl_stmt|;
comment|/* frame staging queue */
name|uint32_t
name|ic_hash_key
decl_stmt|;
comment|/* random key for mac hash */
comment|/* XXX multi-bss: split out common/vap parts */
name|struct
name|ieee80211_wme_state
name|ic_wme
decl_stmt|;
comment|/* WME/WMM state */
comment|/* XXX multi-bss: can per-vap be done/make sense? */
name|enum
name|ieee80211_protmode
name|ic_protmode
decl_stmt|;
comment|/* 802.11g protection mode */
name|uint16_t
name|ic_nonerpsta
decl_stmt|;
comment|/* # non-ERP stations */
name|uint16_t
name|ic_longslotsta
decl_stmt|;
comment|/* # long slot time stations */
name|uint16_t
name|ic_sta_assoc
decl_stmt|;
comment|/* stations associated */
name|uint16_t
name|ic_ht_sta_assoc
decl_stmt|;
comment|/* HT stations associated */
name|uint16_t
name|ic_ht40_sta_assoc
decl_stmt|;
comment|/* HT40 stations associated */
name|uint8_t
name|ic_curhtprotmode
decl_stmt|;
comment|/* HTINFO bss state */
name|enum
name|ieee80211_protmode
name|ic_htprotmode
decl_stmt|;
comment|/* HT protection mode */
name|int
name|ic_lastnonerp
decl_stmt|;
comment|/* last time non-ERP sta noted*/
name|int
name|ic_lastnonht
decl_stmt|;
comment|/* last time non-HT sta noted */
comment|/* optional state for Atheros SuperG protocol extensions */
name|struct
name|ieee80211_superg
modifier|*
name|ic_superg
decl_stmt|;
comment|/* radiotap handling */
name|struct
name|ieee80211_radiotap_header
modifier|*
name|ic_th
decl_stmt|;
comment|/* tx radiotap headers */
name|void
modifier|*
name|ic_txchan
decl_stmt|;
comment|/* channel state in ic_th */
name|struct
name|ieee80211_radiotap_header
modifier|*
name|ic_rh
decl_stmt|;
comment|/* rx radiotap headers */
name|void
modifier|*
name|ic_rxchan
decl_stmt|;
comment|/* channel state in ic_rh */
name|int
name|ic_montaps
decl_stmt|;
comment|/* active monitor mode taps */
comment|/* virtual ap create/delete */
name|struct
name|ieee80211vap
modifier|*
function_decl|(
modifier|*
name|ic_vap_create
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|char
name|name
index|[
name|IFNAMSIZ
index|]
parameter_list|,
name|int
name|unit
parameter_list|,
name|int
name|opmode
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_vap_delete
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
comment|/* operating mode attachment */
name|ieee80211vap_attach
name|ic_vattach
index|[
name|IEEE80211_OPMODE_MAX
index|]
decl_stmt|;
comment|/* return hardware/radio capabilities */
name|void
function_decl|(
modifier|*
name|ic_getradiocaps
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
type|[]
parameter_list|)
function_decl|;
comment|/* check and/or prepare regdomain state change */
name|int
function_decl|(
modifier|*
name|ic_setregdomain
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_regdomain
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ieee80211_channel
type|[]
parameter_list|)
function_decl|;
comment|/* send/recv 802.11 management frame */
name|int
function_decl|(
modifier|*
name|ic_send_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* send raw 802.11 frame */
name|int
function_decl|(
modifier|*
name|ic_raw_xmit
function_decl|)
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
name|ieee80211_bpf_params
modifier|*
parameter_list|)
function_decl|;
comment|/* update device state for 802.11 slot time change */
name|void
function_decl|(
modifier|*
name|ic_updateslot
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* handle multicast state changes */
name|void
function_decl|(
modifier|*
name|ic_update_mcast
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* handle promiscuous mode changes */
name|void
function_decl|(
modifier|*
name|ic_update_promisc
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
comment|/* new station association callback/notification */
name|void
function_decl|(
modifier|*
name|ic_newassoc
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* TDMA update notification */
name|void
function_decl|(
modifier|*
name|ic_tdma_update
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_tdma_param
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* node state management */
name|struct
name|ieee80211_node
modifier|*
function_decl|(
modifier|*
name|ic_node_alloc
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_free
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_cleanup
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_age
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_drain
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|int8_t
function_decl|(
modifier|*
name|ic_node_getrssi
function_decl|)
parameter_list|(
specifier|const
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_getsignal
function_decl|)
parameter_list|(
specifier|const
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|,
name|int8_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_getmimoinfo
function_decl|)
parameter_list|(
specifier|const
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_mimo_info
modifier|*
parameter_list|)
function_decl|;
comment|/* scanning support */
name|void
function_decl|(
modifier|*
name|ic_scan_start
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_scan_end
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_set_channel
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_scan_curchan
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_scan_mindwell
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
comment|/* 	 * 802.11n ADDBA support.  A simple/generic implementation 	 * of A-MPDU tx aggregation is provided; the driver may 	 * override these methods to provide their own support. 	 * A-MPDU rx re-ordering happens automatically if the 	 * driver passes out-of-order frames to ieee80211_input 	 * from an assocated HT station. 	 */
name|int
function_decl|(
modifier|*
name|ic_recv_action
function_decl|)
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
name|uint8_t
modifier|*
name|frm
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|efrm
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_send_action
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
name|category
parameter_list|,
name|int
name|action
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* check if A-MPDU should be enabled this station+ac */
name|int
function_decl|(
modifier|*
name|ic_ampdu_enable
function_decl|)
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
comment|/* start/stop doing A-MPDU tx aggregation for a station */
name|int
function_decl|(
modifier|*
name|ic_addba_request
function_decl|)
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
name|dialogtoken
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_addba_response
function_decl|)
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
name|status
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_addba_stop
function_decl|)
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
comment|/* BAR response received */
name|void
function_decl|(
modifier|*
name|ic_bar_response
function_decl|)
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
name|status
parameter_list|)
function_decl|;
comment|/* start/stop doing A-MPDU rx processing for a station */
name|int
function_decl|(
modifier|*
name|ic_ampdu_rx_start
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_rx_ampdu
modifier|*
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|,
name|int
name|baseqctl
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_ampdu_rx_stop
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_rx_ampdu
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
name|ic_spare
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ieee80211_aclator
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_tdma_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_mesh_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_hwmp_state
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee80211vap
block|{
name|struct
name|ifmedia
name|iv_media
decl_stmt|;
comment|/* interface media config */
name|struct
name|ifnet
modifier|*
name|iv_ifp
decl_stmt|;
comment|/* associated device */
name|struct
name|bpf_if
modifier|*
name|iv_rawbpf
decl_stmt|;
comment|/* packet filter structure */
name|struct
name|sysctl_ctx_list
modifier|*
name|iv_sysctl
decl_stmt|;
comment|/* dynamic sysctl context */
name|struct
name|sysctl_oid
modifier|*
name|iv_oid
decl_stmt|;
comment|/* net.wlan.X sysctl oid */
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211vap
argument_list|)
name|iv_next
expr_stmt|;
comment|/* list of vap instances */
name|struct
name|ieee80211com
modifier|*
name|iv_ic
decl_stmt|;
comment|/* back ptr to common state */
name|uint32_t
name|iv_debug
decl_stmt|;
comment|/* debug msg flags */
name|struct
name|ieee80211_stats
name|iv_stats
decl_stmt|;
comment|/* statistics */
name|uint8_t
name|iv_myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|iv_flags
decl_stmt|;
comment|/* state flags */
name|uint32_t
name|iv_flags_ext
decl_stmt|;
comment|/* extended state flags */
name|uint32_t
name|iv_flags_ht
decl_stmt|;
comment|/* HT state flags */
name|uint32_t
name|iv_flags_ven
decl_stmt|;
comment|/* vendor state flags */
name|uint32_t
name|iv_caps
decl_stmt|;
comment|/* capabilities */
name|uint32_t
name|iv_htcaps
decl_stmt|;
comment|/* HT capabilities */
name|enum
name|ieee80211_opmode
name|iv_opmode
decl_stmt|;
comment|/* operation mode */
name|enum
name|ieee80211_state
name|iv_state
decl_stmt|;
comment|/* state machine state */
name|enum
name|ieee80211_state
name|iv_nstate
decl_stmt|;
comment|/* pending state */
name|int
name|iv_nstate_arg
decl_stmt|;
comment|/* pending state arg */
name|struct
name|task
name|iv_nstate_task
decl_stmt|;
comment|/* deferred state processing */
name|struct
name|task
name|iv_swbmiss_task
decl_stmt|;
comment|/* deferred iv_bmiss call */
name|struct
name|callout
name|iv_mgtsend
decl_stmt|;
comment|/* mgmt frame response timer */
comment|/* inactivity timer settings */
name|int
name|iv_inact_init
decl_stmt|;
comment|/* setting for new station */
name|int
name|iv_inact_auth
decl_stmt|;
comment|/* auth but not assoc setting */
name|int
name|iv_inact_run
decl_stmt|;
comment|/* authorized setting */
name|int
name|iv_inact_probe
decl_stmt|;
comment|/* inactive probe time */
name|int
name|iv_des_nssid
decl_stmt|;
comment|/* # desired ssids */
name|struct
name|ieee80211_scan_ssid
name|iv_des_ssid
index|[
literal|1
index|]
decl_stmt|;
comment|/* desired ssid table */
name|uint8_t
name|iv_des_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|ieee80211_channel
modifier|*
name|iv_des_chan
decl_stmt|;
comment|/* desired channel */
name|uint16_t
name|iv_des_mode
decl_stmt|;
comment|/* desired mode */
name|int
name|iv_nicknamelen
decl_stmt|;
comment|/* XXX junk */
name|uint8_t
name|iv_nickname
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|u_int
name|iv_bgscanidle
decl_stmt|;
comment|/* bg scan idle threshold */
name|u_int
name|iv_bgscanintvl
decl_stmt|;
comment|/* bg scan min interval */
name|u_int
name|iv_scanvalid
decl_stmt|;
comment|/* scan cache valid threshold */
name|u_int
name|iv_scanreq_duration
decl_stmt|;
name|u_int
name|iv_scanreq_mindwell
decl_stmt|;
name|u_int
name|iv_scanreq_maxdwell
decl_stmt|;
name|uint16_t
name|iv_scanreq_flags
decl_stmt|;
comment|/* held scan request params */
name|uint8_t
name|iv_scanreq_nssid
decl_stmt|;
name|struct
name|ieee80211_scan_ssid
name|iv_scanreq_ssid
index|[
name|IEEE80211_SCAN_MAX_SSID
index|]
decl_stmt|;
comment|/* sta-mode roaming state */
name|enum
name|ieee80211_roamingmode
name|iv_roaming
decl_stmt|;
comment|/* roaming mode */
name|struct
name|ieee80211_roamparam
name|iv_roamparms
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
name|uint8_t
name|iv_bmissthreshold
decl_stmt|;
name|uint8_t
name|iv_bmiss_count
decl_stmt|;
comment|/* current beacon miss count */
name|int
name|iv_bmiss_max
decl_stmt|;
comment|/* max bmiss before scan */
name|uint16_t
name|iv_swbmiss_count
decl_stmt|;
comment|/* beacons in last period */
name|uint16_t
name|iv_swbmiss_period
decl_stmt|;
comment|/* s/w bmiss period */
name|struct
name|callout
name|iv_swbmiss
decl_stmt|;
comment|/* s/w beacon miss timer */
name|int
name|iv_ampdu_rxmax
decl_stmt|;
comment|/* A-MPDU rx limit (bytes) */
name|int
name|iv_ampdu_density
decl_stmt|;
comment|/* A-MPDU density */
name|int
name|iv_ampdu_limit
decl_stmt|;
comment|/* A-MPDU tx limit (bytes) */
name|int
name|iv_amsdu_limit
decl_stmt|;
comment|/* A-MSDU tx limit (bytes) */
name|u_int
name|iv_ampdu_mintraffic
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|uint32_t
modifier|*
name|iv_aid_bitmap
decl_stmt|;
comment|/* association id map */
name|uint16_t
name|iv_max_aid
decl_stmt|;
name|uint16_t
name|iv_sta_assoc
decl_stmt|;
comment|/* stations associated */
name|uint16_t
name|iv_ps_sta
decl_stmt|;
comment|/* stations in power save */
name|uint16_t
name|iv_ps_pending
decl_stmt|;
comment|/* ps sta's w/ pending frames */
name|uint16_t
name|iv_txseq
decl_stmt|;
comment|/* mcast xmit seq# space */
name|uint16_t
name|iv_tim_len
decl_stmt|;
comment|/* ic_tim_bitmap size (bytes) */
name|uint8_t
modifier|*
name|iv_tim_bitmap
decl_stmt|;
comment|/* power-save stations w/ data*/
name|uint8_t
name|iv_dtim_period
decl_stmt|;
comment|/* DTIM period */
name|uint8_t
name|iv_dtim_count
decl_stmt|;
comment|/* DTIM count from last bcn */
comment|/* set/unset aid pwrsav state */
name|int
name|iv_csa_count
decl_stmt|;
comment|/* count for doing CSA */
name|struct
name|ieee80211_node
modifier|*
name|iv_bss
decl_stmt|;
comment|/* information for this node */
name|struct
name|ieee80211_txparam
name|iv_txparms
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
name|uint16_t
name|iv_rtsthreshold
decl_stmt|;
name|uint16_t
name|iv_fragthreshold
decl_stmt|;
name|int
name|iv_inact_timer
decl_stmt|;
comment|/* inactivity timer wait */
comment|/* application-specified IE's to attach to mgt frames */
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_beacon
decl_stmt|;
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_probereq
decl_stmt|;
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_proberesp
decl_stmt|;
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_assocreq
decl_stmt|;
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_assocresp
decl_stmt|;
name|struct
name|ieee80211_appie
modifier|*
name|iv_appie_wpa
decl_stmt|;
name|uint8_t
modifier|*
name|iv_wpa_ie
decl_stmt|;
name|uint8_t
modifier|*
name|iv_rsn_ie
decl_stmt|;
name|uint16_t
name|iv_max_keyix
decl_stmt|;
comment|/* max h/w key index */
name|ieee80211_keyix
name|iv_def_txkey
decl_stmt|;
comment|/* default/group tx key index */
name|struct
name|ieee80211_key
name|iv_nw_keys
index|[
name|IEEE80211_WEP_NKID
index|]
decl_stmt|;
name|int
function_decl|(
modifier|*
name|iv_key_alloc
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|ieee80211_keyix
modifier|*
parameter_list|,
name|ieee80211_keyix
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iv_key_delete
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_key
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iv_key_set
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iv_key_update_begin
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iv_key_update_end
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|struct
name|ieee80211_authenticator
modifier|*
name|iv_auth
decl_stmt|;
comment|/* authenticator glue */
name|void
modifier|*
name|iv_ec
decl_stmt|;
comment|/* private auth state */
specifier|const
name|struct
name|ieee80211_aclator
modifier|*
name|iv_acl
decl_stmt|;
comment|/* acl glue */
name|void
modifier|*
name|iv_as
decl_stmt|;
comment|/* private aclator state */
name|struct
name|ieee80211_tdma_state
modifier|*
name|iv_tdma
decl_stmt|;
comment|/* tdma state */
name|struct
name|ieee80211_mesh_state
modifier|*
name|iv_mesh
decl_stmt|;
comment|/* MBSS state */
name|struct
name|ieee80211_hwmp_state
modifier|*
name|iv_hwmp
decl_stmt|;
comment|/* HWMP state */
comment|/* operate-mode detach hook */
name|void
function_decl|(
modifier|*
name|iv_opdetach
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
comment|/* receive processing */
name|int
function_decl|(
modifier|*
name|iv_input
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iv_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
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
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iv_recv_ctl
function_decl|)
parameter_list|(
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
name|void
function_decl|(
modifier|*
name|iv_deliver_data
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
comment|/* send processing */
block|int			(*iv_send_mgmt)(struct ieee80211_node *, 				     int, int);
endif|#
directive|endif
comment|/* beacon miss processing */
name|void
function_decl|(
modifier|*
name|iv_bmiss
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
comment|/* reset device state after 802.11 parameter/state change */
name|int
function_decl|(
modifier|*
name|iv_reset
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
comment|/* [schedule] beacon frame update */
name|void
function_decl|(
modifier|*
name|iv_update_beacon
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* power save handling */
name|void
function_decl|(
modifier|*
name|iv_update_ps
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iv_set_tim
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* state machine processing */
name|int
function_decl|(
modifier|*
name|iv_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* 802.3 output method for raw frame xmit */
name|int
function_decl|(
modifier|*
name|iv_output
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
name|iv_spare
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_VAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IEEE80211_ADDR_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|(memcmp(a1,a2,IEEE80211_ADDR_LEN) == 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_ADDR_COPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|memcpy(dst,src,IEEE80211_ADDR_LEN)
end_define

begin_comment
comment|/* ic_flags/iv_flags */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TURBOP
value|0x00000001
end_define

begin_comment
comment|/* CONF: ATH Turbo enabled*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_COMP
value|0x00000002
end_define

begin_comment
comment|/* CONF: ATH comp enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_FF
value|0x00000004
end_define

begin_comment
comment|/* CONF: ATH FF enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_BURST
value|0x00000008
end_define

begin_comment
comment|/* CONF: bursting enabled */
end_comment

begin_comment
comment|/* NB: this is intentionally setup to be IEEE80211_CAPINFO_PRIVACY */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_PRIVACY
value|0x00000010
end_define

begin_comment
comment|/* CONF: privacy enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_PUREG
value|0x00000020
end_define

begin_comment
comment|/* CONF: 11g w/o 11b sta's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SCAN
value|0x00000080
end_define

begin_comment
comment|/* STATUS: scanning */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_ASCAN
value|0x00000100
end_define

begin_comment
comment|/* STATUS: active scan */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SIBSS
value|0x00000200
end_define

begin_comment
comment|/* STATUS: start IBSS */
end_comment

begin_comment
comment|/* NB: this is intentionally setup to be IEEE80211_CAPINFO_SHORT_SLOTTIME */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SHSLOT
value|0x00000400
end_define

begin_comment
comment|/* STATUS: use short slot time*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_PMGTON
value|0x00000800
end_define

begin_comment
comment|/* CONF: Power mgmt enable */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DESBSSID
value|0x00001000
end_define

begin_comment
comment|/* CONF: des_bssid is set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_WME
value|0x00002000
end_define

begin_comment
comment|/* CONF: enable WME use */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_BGSCAN
value|0x00004000
end_define

begin_comment
comment|/* CONF: bg scan enabled (???)*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SWRETRY
value|0x00008000
end_define

begin_comment
comment|/* CONF: sw tx retry enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TXPOW_FIXED
value|0x00010000
end_define

begin_comment
comment|/* TX Power: fixed rate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_IBSSON
value|0x00020000
end_define

begin_comment
comment|/* CONF: IBSS creation enable */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SHPREAMBLE
value|0x00040000
end_define

begin_comment
comment|/* STATUS: use short preamble */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DATAPAD
value|0x00080000
end_define

begin_comment
comment|/* CONF: do alignment pad */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_USEPROT
value|0x00100000
end_define

begin_comment
comment|/* STATUS: protection enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_USEBARKER
value|0x00200000
end_define

begin_comment
comment|/* STATUS: use barker preamble*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_CSAPENDING
value|0x00400000
end_define

begin_comment
comment|/* STATUS: chan switch pending*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_WPA1
value|0x00800000
end_define

begin_comment
comment|/* CONF: WPA enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_WPA2
value|0x01000000
end_define

begin_comment
comment|/* CONF: WPA2 enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_WPA
value|0x01800000
end_define

begin_comment
comment|/* CONF: WPA/WPA2 enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DROPUNENC
value|0x02000000
end_define

begin_comment
comment|/* CONF: drop unencrypted */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_COUNTERM
value|0x04000000
end_define

begin_comment
comment|/* CONF: TKIP countermeasures */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_HIDESSID
value|0x08000000
end_define

begin_comment
comment|/* CONF: hide SSID in beacon */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_NOBRIDGE
value|0x10000000
end_define

begin_comment
comment|/* CONF: dis. internal bridge */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_PCF
value|0x20000000
end_define

begin_comment
comment|/* CONF: PCF enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DOTH
value|0x40000000
end_define

begin_comment
comment|/* CONF: 11h enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DWDS
value|0x80000000
end_define

begin_comment
comment|/* CONF: Dynamic WDS enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_BITS
define|\
value|"\20\1TURBOP\2COMP\3FF\4BURST\5PRIVACY\6PUREG\10SCAN\11ASCAN\12SIBSS" \ 	"\13SHSLOT\14PMGTON\15DESBSSID\16WME\17BGSCAN\20SWRETRY\21TXPOW_FIXED" \ 	"\22IBSSON\23SHPREAMBLE\24DATAPAD\25USEPROT\26USERBARKER\27CSAPENDING" \ 	"\30WPA1\31WPA2\32DROPUNENC\33COUNTERM\34HIDESSID\35NOBRIDG\36PCF" \ 	"\37DOTH\40DWDS"
end_define

begin_comment
comment|/* Atheros protocol-specific flags */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_ATHEROS
define|\
value|(IEEE80211_F_FF | IEEE80211_F_COMP | IEEE80211_F_TURBOP)
end_define

begin_comment
comment|/* Check if an Atheros capability was negotiated for use */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ATH_CAP
parameter_list|(
name|vap
parameter_list|,
name|ni
parameter_list|,
name|bit
parameter_list|)
define|\
value|((vap)->iv_flags& (ni)->ni_ath_flags& (bit))
end_define

begin_comment
comment|/* ic_flags_ext/iv_flags_ext */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_INACT
value|0x00000002
end_define

begin_comment
comment|/* CONF: sta inact handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_SCANWAIT
value|0x00000004
end_define

begin_comment
comment|/* STATUS: awaiting scan */
end_comment

begin_comment
comment|/* 0x00000006 reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_BGSCAN
value|0x00000008
end_define

begin_comment
comment|/* STATUS: complete bgscan */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_WPS
value|0x00000010
end_define

begin_comment
comment|/* CONF: WPS enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_TSN
value|0x00000020
end_define

begin_comment
comment|/* CONF: TSN enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_SCANREQ
value|0x00000040
end_define

begin_comment
comment|/* STATUS: scan req params */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_RESUME
value|0x00000080
end_define

begin_comment
comment|/* STATUS: start on resume */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_4ADDR
value|0x00000100
end_define

begin_comment
comment|/* CONF: apply 4-addr encap */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_NONERP_PR
value|0x00000200
end_define

begin_comment
comment|/* STATUS: non-ERP sta present*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_SWBMISS
value|0x00000400
end_define

begin_comment
comment|/* CONF: do bmiss in s/w */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_DFS
value|0x00000800
end_define

begin_comment
comment|/* CONF: DFS enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_DOTD
value|0x00001000
end_define

begin_comment
comment|/* CONF: 11d enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_STATEWAIT
value|0x00002000
end_define

begin_comment
comment|/* STATUS: awaiting state chg */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_REINIT
value|0x00004000
end_define

begin_comment
comment|/* STATUS: INIT state first */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_BPF
value|0x00008000
end_define

begin_comment
comment|/* STATUS: BPF tap present */
end_comment

begin_comment
comment|/* NB: immutable: should be set only when creating a vap */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_WDSLEGACY
value|0x00010000
end_define

begin_comment
comment|/* CONF: legacy WDS operation */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_PROBECHAN
value|0x00020000
end_define

begin_comment
comment|/* CONF: probe passive channel*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_BITS
define|\
value|"\20\2INACT\3SCANWAIT\4BGSCAN\5WPS\6TSN\7SCANREQ\10RESUME" \ 	"\0114ADDR\12NONEPR_PR\13SWBMISS\14DFS\15DOTD\16STATEWAIT\17REINIT" \ 	"\20BPF\21WDSLEGACY\22PROBECHAN"
end_define

begin_comment
comment|/* ic_flags_ht/iv_flags_ht */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_NONHT_PR
value|0x00000001
end_define

begin_comment
comment|/* STATUS: non-HT sta present */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_GF
value|0x00040000
end_define

begin_comment
comment|/* CONF: Greenfield enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_HT
value|0x00080000
end_define

begin_comment
comment|/* CONF: HT supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_AMPDU_TX
value|0x00100000
end_define

begin_comment
comment|/* CONF: A-MPDU tx supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_AMPDU_RX
value|0x00200000
end_define

begin_comment
comment|/* CONF: A-MPDU rx supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_AMSDU_TX
value|0x00400000
end_define

begin_comment
comment|/* CONF: A-MSDU tx supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_AMSDU_RX
value|0x00800000
end_define

begin_comment
comment|/* CONF: A-MSDU rx supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_USEHT40
value|0x01000000
end_define

begin_comment
comment|/* CONF: 20/40 use enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_PUREN
value|0x02000000
end_define

begin_comment
comment|/* CONF: 11n w/o legacy sta's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_SHORTGI20
value|0x04000000
end_define

begin_comment
comment|/* CONF: short GI in HT20 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_SHORTGI40
value|0x08000000
end_define

begin_comment
comment|/* CONF: short GI in HT40 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_HTCOMPAT
value|0x10000000
end_define

begin_comment
comment|/* CONF: HT vendor OUI's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_RIFS
value|0x20000000
end_define

begin_comment
comment|/* CONF: RIFS enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_STBC_TX
value|0x40000000
end_define

begin_comment
comment|/* CONF: STBC tx enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_STBC_RX
value|0x80000000
end_define

begin_comment
comment|/* CONF: STBC rx enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FHT_BITS
define|\
value|"\20\1NONHT_PR" \ 	"\23GF\24HT\25AMDPU_TX\26AMPDU_TX" \ 	"\27AMSDU_TX\30AMSDU_RX\31USEHT40\32PUREN\33SHORTGI20\34SHORTGI40" \ 	"\35HTCOMPAT\36RIFS\37STBC_TX\40STBC_RX"
end_define

begin_define
define|#
directive|define
name|IEEE80211_FVEN_BITS
value|"\20"
end_define

begin_comment
comment|/* ic_caps/iv_caps: device driver capabilities */
end_comment

begin_comment
comment|/* 0x2e available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_STA
value|0x00000001
end_define

begin_comment
comment|/* CAPABILITY: STA available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_8023ENCAP
value|0x00000002
end_define

begin_comment
comment|/* CAPABILITY: 802.3 encap */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_FF
value|0x00000040
end_define

begin_comment
comment|/* CAPABILITY: ATH FF avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TURBOP
value|0x00000080
end_define

begin_comment
comment|/* CAPABILITY: ATH Turbo avail*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_IBSS
value|0x00000100
end_define

begin_comment
comment|/* CAPABILITY: IBSS available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_PMGT
value|0x00000200
end_define

begin_comment
comment|/* CAPABILITY: Power mgmt */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_HOSTAP
value|0x00000400
end_define

begin_comment
comment|/* CAPABILITY: HOSTAP avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_AHDEMO
value|0x00000800
end_define

begin_comment
comment|/* CAPABILITY: Old Adhoc Demo */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SWRETRY
value|0x00001000
end_define

begin_comment
comment|/* CAPABILITY: sw tx retry */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TXPMGT
value|0x00002000
end_define

begin_comment
comment|/* CAPABILITY: tx power mgmt */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SHSLOT
value|0x00004000
end_define

begin_comment
comment|/* CAPABILITY: short slottime */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SHPREAMBLE
value|0x00008000
end_define

begin_comment
comment|/* CAPABILITY: short preamble */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_MONITOR
value|0x00010000
end_define

begin_comment
comment|/* CAPABILITY: monitor mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_DFS
value|0x00020000
end_define

begin_comment
comment|/* CAPABILITY: DFS/radar avail*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_MBSS
value|0x00040000
end_define

begin_comment
comment|/* CAPABILITY: MBSS available */
end_comment

begin_comment
comment|/* 0x7c0000 available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WPA1
value|0x00800000
end_define

begin_comment
comment|/* CAPABILITY: WPA1 avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WPA2
value|0x01000000
end_define

begin_comment
comment|/* CAPABILITY: WPA2 avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WPA
value|0x01800000
end_define

begin_comment
comment|/* CAPABILITY: WPA1+WPA2 avail*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_BURST
value|0x02000000
end_define

begin_comment
comment|/* CAPABILITY: frame bursting */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WME
value|0x04000000
end_define

begin_comment
comment|/* CAPABILITY: WME avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WDS
value|0x08000000
end_define

begin_comment
comment|/* CAPABILITY: 4-addr support */
end_comment

begin_comment
comment|/* 0x10000000 reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_BGSCAN
value|0x20000000
end_define

begin_comment
comment|/* CAPABILITY: bg scanning */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TXFRAG
value|0x40000000
end_define

begin_comment
comment|/* CAPABILITY: tx fragments */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TDMA
value|0x80000000
end_define

begin_comment
comment|/* CAPABILITY: TDMA avail */
end_comment

begin_comment
comment|/* XXX protection/barker? */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_OPMODE
define|\
value|(IEEE80211_C_STA | IEEE80211_C_IBSS | IEEE80211_C_HOSTAP | \ 	 IEEE80211_C_AHDEMO | IEEE80211_C_MONITOR | IEEE80211_C_WDS | \ 	 IEEE80211_C_TDMA | IEEE80211_C_MBSS)
end_define

begin_define
define|#
directive|define
name|IEEE80211_C_BITS
define|\
value|"\20\1STA\002803ENCAP\7FF\10TURBOP\11IBSS\12PMGT" \ 	"\13HOSTAP\14AHDEMO\15SWRETRY\16TXPMGT\17SHSLOT\20SHPREAMBLE" \ 	"\21MONITOR\22DFS\23MBSS\30WPA1\31WPA2\32BURST\33WME\34WDS\36BGSCAN" \ 	"\37TXFRAG\40TDMA"
end_define

begin_comment
comment|/*  * ic_htcaps/iv_htcaps: HT-specific device/driver capabilities  *  * NB: the low 16-bits are the 802.11 definitions, the upper  *     16-bits are used to define s/w/driver capabilities.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTC_AMPDU
value|0x00010000
end_define

begin_comment
comment|/* CAPABILITY: A-MPDU tx */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTC_AMSDU
value|0x00020000
end_define

begin_comment
comment|/* CAPABILITY: A-MSDU tx */
end_comment

begin_comment
comment|/* NB: HT40 is implied by IEEE80211_HTCAP_CHWIDTH40 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTC_HT
value|0x00040000
end_define

begin_comment
comment|/* CAPABILITY: HT operation */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTC_SMPS
value|0x00080000
end_define

begin_comment
comment|/* CAPABILITY: MIMO power save*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTC_RIFS
value|0x00100000
end_define

begin_comment
comment|/* CAPABILITY: RIFS support */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_HTCAP_BITS
define|\
value|"\20\1LDPC\2CHWIDTH40\5GREENFIELD\6SHORTGI20\7SHORTGI40\10TXSTBC" \ 	"\21AMPDU\22AMSDU\23HT\24SMPS\25RIFS"
end_define

begin_function_decl
name|void
name|ieee80211_ifattach
parameter_list|(
name|struct
name|ieee80211com
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
name|void
name|ieee80211_ifdetach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_vap_setup
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|char
name|name
index|[
name|IFNAMSIZ
index|]
parameter_list|,
name|int
name|unit
parameter_list|,
name|int
name|opmode
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
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
name|int
name|ieee80211_vap_attach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|ifm_change_cb_t
parameter_list|,
name|ifm_stat_cb_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_vap_detach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
name|ieee80211_get_suprates
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_announce
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_announce_channels
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_drain
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_media_init
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211com
modifier|*
name|ieee80211_find_vap
parameter_list|(
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_media_change
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_media_status
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_rate2media
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|ieee80211_phymode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_media2rate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_mhz2ieee
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_chan2ieee
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

begin_function_decl
name|u_int
name|ieee80211_ieee2mhz
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_channel
modifier|*
name|ieee80211_find_channel
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|freq
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_channel
modifier|*
name|ieee80211_find_channel_byieee
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|ieee
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_setmode
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ieee80211_phymode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|ieee80211_phymode
name|ieee80211_chan2mode
parameter_list|(
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ieee80211_mac_hash
parameter_list|(
specifier|const
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|addr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_radiotap_header
modifier|*
name|th
parameter_list|,
name|int
name|tlen
parameter_list|,
name|uint32_t
name|tx_radiotap
parameter_list|,
name|struct
name|ieee80211_radiotap_header
modifier|*
name|rh
parameter_list|,
name|int
name|rlen
parameter_list|,
name|uint32_t
name|rx_radiotap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_chan_change
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_radiotap_tx
parameter_list|(
name|struct
name|ieee80211vap
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
name|ieee80211_radiotap_rx
parameter_list|(
name|struct
name|ieee80211vap
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
name|ieee80211_radiotap_rx_all
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_radiotap_active
parameter_list|(
specifier|const
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|)
block|{
return|return
operator|(
name|ic
operator|->
name|ic_flags_ext
operator|&
name|IEEE80211_FEXT_BPF
operator|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_radiotap_active_vap
parameter_list|(
specifier|const
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{
return|return
operator|(
name|vap
operator|->
name|iv_flags_ext
operator|&
name|IEEE80211_FEXT_BPF
operator|)
operator|||
name|vap
operator|->
name|iv_ic
operator|->
name|ic_montaps
operator|!=
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Enqueue a task on the state thread.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_runtask
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
block|{
name|taskqueue_enqueue
argument_list|(
name|ic
operator|->
name|ic_tq
argument_list|,
name|task
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Wait for a queued task to complete.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_draintask
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
block|{
name|taskqueue_drain
argument_list|(
name|ic
operator|->
name|ic_tq
argument_list|,
name|task
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   * Key update synchronization methods.  XXX should not be visible.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_key_update_begin
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{
name|vap
operator|->
name|iv_key_update_begin
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_key_update_end
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{
name|vap
operator|->
name|iv_key_update_end
argument_list|(
name|vap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * XXX these need to be here for IEEE80211_F_DATAPAD  */
end_comment

begin_comment
comment|/*  * Return the space occupied by the 802.11 header and any  * padding required by the driver.  This works for a  * management or data frame.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_hdrspace
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
name|int
name|size
init|=
name|ieee80211_hdrsize
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|ic
operator|->
name|ic_flags
operator|&
name|IEEE80211_F_DATAPAD
condition|)
name|size
operator|=
name|roundup
argument_list|(
name|size
argument_list|,
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function

begin_comment
comment|/*  * Like ieee80211_hdrspace, but handles any type of frame.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_anyhdrspace
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
name|int
name|size
init|=
name|ieee80211_anyhdrsize
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|ic
operator|->
name|ic_flags
operator|&
name|IEEE80211_F_DATAPAD
condition|)
name|size
operator|=
name|roundup
argument_list|(
name|size
argument_list|,
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function

begin_comment
comment|/*  * Notify a vap that beacon state has been updated.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_beacon_notify
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|int
name|what
parameter_list|)
block|{
if|if
condition|(
name|vap
operator|->
name|iv_state
operator|==
name|IEEE80211_S_RUN
condition|)
name|vap
operator|->
name|iv_update_beacon
argument_list|(
name|vap
argument_list|,
name|what
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Calculate HT channel promotion flags for a channel.  * XXX belongs in ieee80211_ht.h but needs IEEE80211_FHT_*  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_htchanflags
parameter_list|(
specifier|const
name|struct
name|ieee80211_channel
modifier|*
name|c
parameter_list|)
block|{
return|return
name|IEEE80211_IS_CHAN_HT40
argument_list|(
name|c
argument_list|)
condition|?
name|IEEE80211_FHT_HT
operator||
name|IEEE80211_FHT_USEHT40
else|:
name|IEEE80211_IS_CHAN_HT
argument_list|(
name|c
argument_list|)
condition|?
name|IEEE80211_FHT_HT
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Debugging facilities compiled in when IEEE80211_DEBUG is defined.  *  * The intent is that any problem in the net80211 layer can be  * diagnosed by inspecting the statistics (dumped by the wlanstats  * program) and/or the msgs generated by net80211.  Messages are  * broken into functional classes and can be controlled with the  * wlandebug program.  Certain of these msg groups are for facilities  * that are no longer part of net80211 (e.g. IEEE80211_MSG_DOT1XSM).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_11N
value|0x80000000
end_define

begin_comment
comment|/* 11n mode debug */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_DEBUG
value|0x40000000
end_define

begin_comment
comment|/* IFF_DEBUG equivalent */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_DUMPPKTS
value|0x20000000
end_define

begin_comment
comment|/* IFF_LINK2 equivalant */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_CRYPTO
value|0x10000000
end_define

begin_comment
comment|/* crypto work */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_INPUT
value|0x08000000
end_define

begin_comment
comment|/* input handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_XRATE
value|0x04000000
end_define

begin_comment
comment|/* rate set handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ELEMID
value|0x02000000
end_define

begin_comment
comment|/* element id parsing */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_NODE
value|0x01000000
end_define

begin_comment
comment|/* node handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ASSOC
value|0x00800000
end_define

begin_comment
comment|/* association handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_AUTH
value|0x00400000
end_define

begin_comment
comment|/* authentication handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_SCAN
value|0x00200000
end_define

begin_comment
comment|/* scanning */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_OUTPUT
value|0x00100000
end_define

begin_comment
comment|/* output handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_STATE
value|0x00080000
end_define

begin_comment
comment|/* state machine */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_POWER
value|0x00040000
end_define

begin_comment
comment|/* power save handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_HWMP
value|0x00020000
end_define

begin_comment
comment|/* hybrid mesh protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_DOT1XSM
value|0x00010000
end_define

begin_comment
comment|/* 802.1x state machine */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_RADIUS
value|0x00008000
end_define

begin_comment
comment|/* 802.1x radius client */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_RADDUMP
value|0x00004000
end_define

begin_comment
comment|/* dump 802.1x radius packets */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_MESH
value|0x00002000
end_define

begin_comment
comment|/* mesh networking */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_WPA
value|0x00001000
end_define

begin_comment
comment|/* WPA/RSN protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ACL
value|0x00000800
end_define

begin_comment
comment|/* ACL handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_WME
value|0x00000400
end_define

begin_comment
comment|/* WME protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_SUPERG
value|0x00000200
end_define

begin_comment
comment|/* Atheros SuperG protocol */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_DOTH
value|0x00000100
end_define

begin_comment
comment|/* 802.11h support */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_INACT
value|0x00000080
end_define

begin_comment
comment|/* inactivity handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ROAM
value|0x00000040
end_define

begin_comment
comment|/* sta-mode roaming */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_RATECTL
value|0x00000020
end_define

begin_comment
comment|/* tx rate control */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ACTION
value|0x00000010
end_define

begin_comment
comment|/* action frame handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_WDS
value|0x00000008
end_define

begin_comment
comment|/* WDS handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_IOCTL
value|0x00000004
end_define

begin_comment
comment|/* ioctl handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_TDMA
value|0x00000002
end_define

begin_comment
comment|/* TDMA handling */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_ANY
value|0xffffffff
end_define

begin_comment
comment|/* anything */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MSG_BITS
define|\
value|"\20\2TDMA\3IOCTL\4WDS\5ACTION\6RATECTL\7ROAM\10INACT\11DOTH\12SUPERG" \ 	"\13WME\14ACL\15WPA\16RADKEYS\17RADDUMP\20RADIUS\21DOT1XSM\22HWMP" \ 	"\23POWER\24STATE\25OUTPUT\26SCAN\27AUTH\30ASSOC\31NODE\32ELEMID" \ 	"\33XRATE\34INPUT\35CRYPTO\36DUPMPKTS\37DEBUG\04011N"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ieee80211_msg
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|)
value|((_vap)->iv_debug& (_m))
end_define

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (ieee80211_msg(_vap, _m))					\ 		ieee80211_note(_vap, _fmt, __VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_ni
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (ieee80211_msg(_vap, _m))					\ 		ieee80211_note_mac(_vap, (_ni)->ni_macaddr, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_MAC
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_mac
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if (ieee80211_msg(_vap, _m))					\ 		ieee80211_note_mac(_vap, _mac, _fmt, __VA_ARGS__);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_FRAME
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if (ieee80211_msg(_vap, _m))					\ 		ieee80211_note_frame(_vap, _wh, _fmt, __VA_ARGS__);	\ } while (0)
end_define

begin_function_decl
name|void
name|ieee80211_note
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_note_mac
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_note_frame
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
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ieee80211_msg_debug
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_DEBUG)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumppkts
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_DUMPPKTS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_input
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_INPUT)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_radius
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_RADIUS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumpradius
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_RADDUMP)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumpradkeys
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_RADKEYS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_scan
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_SCAN)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_assoc
parameter_list|(
name|_vap
parameter_list|)
define|\
value|((_vap)->iv_debug& IEEE80211_MSG_ASSOC)
end_define

begin_comment
comment|/*  * Emit a debug message about discarding a frame or information  * element.  One format is for extracting the mac address from  * the frame header; the other is for when a header is not  * available or otherwise appropriate.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DISCARD
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if ((_vap)->iv_debug& (_m))					\ 		ieee80211_discard_frame(_vap, _wh, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_IE
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {	\ 	if ((_vap)->iv_debug& (_m))					\ 		ieee80211_discard_ie(_vap, _wh, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_MAC
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_mac
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {	\ 	if ((_vap)->iv_debug& (_m))					\ 		ieee80211_discard_mac(_vap, _mac, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_function_decl
name|void
name|ieee80211_discard_frame
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
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_discard_ie
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
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_discard_mac
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_ni
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_FRAME
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_MAC
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_mac
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumppkts
parameter_list|(
name|_vap
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ieee80211_msg
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_IE
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_MAC
parameter_list|(
name|_vap
parameter_list|,
name|_m
parameter_list|,
name|_mac
parameter_list|,
name|_type
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
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
comment|/* _NET80211_IEEE80211_VAR_H_ */
end_comment

end_unit

