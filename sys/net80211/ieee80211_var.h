begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|IEEE80211_DEBUG
end_define

begin_undef
undef|#
directive|undef
name|IEEE80211_DEBUG_REFCNT
end_undef

begin_comment
comment|/* node refcnt stuff */
end_comment

begin_comment
comment|/* NB: portability glue must go first */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<net80211/ieee80211_netbsd.h>
end_include

begin_elif
elif|#
directive|elif
name|__FreeBSD__
end_elif

begin_include
include|#
directive|include
file|<net80211/ieee80211_freebsd.h>
end_include

begin_elif
elif|#
directive|elif
name|__linux__
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
file|<net80211/ieee80211_crypto.h>
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
file|<net80211/ieee80211_node.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_proto.h>
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
value|-1
end_define

begin_define
define|#
directive|define
name|IEEE80211_MCAST_RATE_DEFAULT
value|(2*1)
end_define

begin_comment
comment|/* default mcast rate (1M) */
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

begin_struct_decl
struct_decl|struct
name|ieee80211_aclator
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee80211com
block|{
name|SLIST_ENTRY
argument_list|(
argument|ieee80211com
argument_list|)
name|ic_next
expr_stmt|;
name|struct
name|ifnet
modifier|*
name|ic_ifp
decl_stmt|;
comment|/* associated device */
name|struct
name|ieee80211_stats
name|ic_stats
decl_stmt|;
comment|/* statistics */
name|struct
name|sysctl_ctx_list
modifier|*
name|ic_sysctl
decl_stmt|;
comment|/* dynamic sysctl context */
name|u_int32_t
name|ic_debug
decl_stmt|;
comment|/* debug msg flags */
name|int
name|ic_vap
decl_stmt|;
comment|/* virtual AP index */
name|ieee80211_beacon_lock_t
name|ic_beaconlock
decl_stmt|;
comment|/* beacon update lock */
name|int
function_decl|(
modifier|*
name|ic_reset
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_send_mgmt
function_decl|)
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
name|int
function_decl|(
modifier|*
name|ic_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
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
name|void
function_decl|(
modifier|*
name|ic_set_tim
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
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
name|u_int8_t
name|ic_myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|ieee80211_rateset
name|ic_sup_rates
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
name|struct
name|ieee80211_channel
name|ic_channels
index|[
name|IEEE80211_CHAN_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|u_int8_t
name|ic_chan_avail
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|u_int8_t
name|ic_chan_active
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|u_int8_t
name|ic_chan_scan
index|[
name|IEEE80211_CHAN_BYTES
index|]
decl_stmt|;
name|struct
name|ieee80211_node_table
name|ic_scan
decl_stmt|;
comment|/* scan candidates */
name|struct
name|ifqueue
name|ic_mgtq
decl_stmt|;
name|u_int32_t
name|ic_flags
decl_stmt|;
comment|/* state flags */
name|u_int32_t
name|ic_flags_ext
decl_stmt|;
comment|/* extended state flags */
name|u_int32_t
name|ic_caps
decl_stmt|;
comment|/* capabilities */
name|u_int16_t
name|ic_modecaps
decl_stmt|;
comment|/* set of mode capabilities */
name|u_int16_t
name|ic_curmode
decl_stmt|;
comment|/* current mode */
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
name|enum
name|ieee80211_state
name|ic_state
decl_stmt|;
comment|/* 802.11 state */
name|enum
name|ieee80211_protmode
name|ic_protmode
decl_stmt|;
comment|/* 802.11g protection mode */
name|enum
name|ieee80211_roamingmode
name|ic_roaming
decl_stmt|;
comment|/* roaming mode */
name|struct
name|ieee80211_node_table
name|ic_sta
decl_stmt|;
comment|/* stations/neighbors */
name|u_int32_t
modifier|*
name|ic_aid_bitmap
decl_stmt|;
comment|/* association id map */
name|u_int16_t
name|ic_max_aid
decl_stmt|;
name|u_int16_t
name|ic_sta_assoc
decl_stmt|;
comment|/* stations associated */
name|u_int16_t
name|ic_ps_sta
decl_stmt|;
comment|/* stations in power save */
name|u_int16_t
name|ic_ps_pending
decl_stmt|;
comment|/* ps sta's w/ pending frames */
name|u_int8_t
modifier|*
name|ic_tim_bitmap
decl_stmt|;
comment|/* power-save stations w/ data*/
name|u_int16_t
name|ic_tim_len
decl_stmt|;
comment|/* ic_tim_bitmap size (bytes) */
name|u_int8_t
name|ic_dtim_period
decl_stmt|;
comment|/* DTIM period */
name|u_int8_t
name|ic_dtim_count
decl_stmt|;
comment|/* DTIM count for last bcn */
name|struct
name|ifmedia
name|ic_media
decl_stmt|;
comment|/* interface media config */
name|struct
name|bpf_if
modifier|*
name|ic_rawbpf
decl_stmt|;
comment|/* packet filter structure */
name|struct
name|ieee80211_node
modifier|*
name|ic_bss
decl_stmt|;
comment|/* information for this node */
name|struct
name|ieee80211_channel
modifier|*
name|ic_ibss_chan
decl_stmt|;
name|struct
name|ieee80211_channel
modifier|*
name|ic_curchan
decl_stmt|;
comment|/* current channel */
name|int
name|ic_fixed_rate
decl_stmt|;
comment|/* index to ic_sup_rates[] */
name|int
name|ic_mcast_rate
decl_stmt|;
comment|/* rate for mcast frames */
name|u_int16_t
name|ic_rtsthreshold
decl_stmt|;
name|u_int16_t
name|ic_fragthreshold
decl_stmt|;
name|u_int8_t
name|ic_bmissthreshold
decl_stmt|;
name|u_int8_t
name|ic_bmiss_count
decl_stmt|;
comment|/* current beacon miss count */
name|int
name|ic_bmiss_max
decl_stmt|;
comment|/* max bmiss before scan */
name|u_int16_t
name|ic_swbmiss_count
decl_stmt|;
comment|/* beacons in last period */
name|u_int16_t
name|ic_swbmiss_period
decl_stmt|;
comment|/* s/w bmiss period */
name|struct
name|callout
name|ic_swbmiss
decl_stmt|;
comment|/* s/w beacon miss timer */
name|struct
name|ieee80211_node
modifier|*
function_decl|(
modifier|*
name|ic_node_alloc
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node_table
modifier|*
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
name|u_int8_t
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
name|u_int16_t
name|ic_lintval
decl_stmt|;
comment|/* listen interval */
name|u_int16_t
name|ic_bintval
decl_stmt|;
comment|/* beacon interval */
name|u_int16_t
name|ic_holdover
decl_stmt|;
comment|/* PM hold over duration */
name|u_int16_t
name|ic_txmin
decl_stmt|;
comment|/* min tx retry count */
name|u_int16_t
name|ic_txmax
decl_stmt|;
comment|/* max tx retry count */
name|u_int16_t
name|ic_txlifetime
decl_stmt|;
comment|/* tx lifetime */
name|u_int16_t
name|ic_txpowlimit
decl_stmt|;
comment|/* global tx power limit */
name|u_int16_t
name|ic_nonerpsta
decl_stmt|;
comment|/* # non-ERP stations */
name|u_int16_t
name|ic_longslotsta
decl_stmt|;
comment|/* # long slot time stations */
name|int
name|ic_mgt_timer
decl_stmt|;
comment|/* mgmt timeout */
name|int
name|ic_inact_timer
decl_stmt|;
comment|/* inactivity timer wait */
name|int
name|ic_des_esslen
decl_stmt|;
name|u_int8_t
name|ic_des_essid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|struct
name|ieee80211_channel
modifier|*
name|ic_des_chan
decl_stmt|;
comment|/* desired channel */
name|u_int8_t
name|ic_des_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|void
modifier|*
name|ic_opt_ie
decl_stmt|;
comment|/* user-specified IE's */
name|u_int16_t
name|ic_opt_ie_len
decl_stmt|;
comment|/* length of ni_opt_ie */
comment|/* 	 * Inactivity timer settings for nodes. 	 */
name|int
name|ic_inact_init
decl_stmt|;
comment|/* initial setting */
name|int
name|ic_inact_auth
decl_stmt|;
comment|/* auth but not assoc setting */
name|int
name|ic_inact_run
decl_stmt|;
comment|/* authorized setting */
name|int
name|ic_inact_probe
decl_stmt|;
comment|/* inactive probe time */
comment|/* 	 * WME/WMM state. 	 */
name|struct
name|ieee80211_wme_state
name|ic_wme
decl_stmt|;
comment|/* 	 * Cipher state/configuration. 	 */
name|struct
name|ieee80211_crypto_state
name|ic_crypto
decl_stmt|;
define|#
directive|define
name|ic_nw_keys
value|ic_crypto.cs_nw_keys
comment|/* XXX compatibility */
define|#
directive|define
name|ic_def_txkey
value|ic_crypto.cs_def_txkey
comment|/* XXX compatibility */
comment|/* 	 * 802.1x glue.  When an authenticator attaches it 	 * fills in this section.  We assume that when ic_ec 	 * is setup that the methods are safe to call. 	 */
specifier|const
name|struct
name|ieee80211_authenticator
modifier|*
name|ic_auth
decl_stmt|;
name|struct
name|eapolcom
modifier|*
name|ic_ec
decl_stmt|;
comment|/* 	 * Access control glue.  When a control agent attaches 	 * it fills in this section.  We assume that when ic_ac 	 * is setup that the methods are safe to call. 	 */
specifier|const
name|struct
name|ieee80211_aclator
modifier|*
name|ic_acl
decl_stmt|;
name|void
modifier|*
name|ic_as
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* ic_flags */
end_comment

begin_comment
comment|/* NB: bits 0x4c available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_FF
value|0x00000001
end_define

begin_comment
comment|/* CONF: ATH FF enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TURBOP
value|0x00000002
end_define

begin_comment
comment|/* CONF: ATH Turbo enabled*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_BURST
value|0x00000004
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
name|IEEE80211_F_TIMUPDATE
value|0x00400000
end_define

begin_comment
comment|/* STATUS: update beacon tim */
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
name|IEEE80211_F_WMEUPDATE
value|0x20000000
end_define

begin_comment
comment|/* STATUS: update beacon wme */
end_comment

begin_comment
comment|/* ic_flags_ext */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_WDS
value|0x00000001
end_define

begin_comment
comment|/* CONF: 4 addr allowed */
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
comment|/* STATUS: enable full bgscan completion */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FEXT_ERPUPDATE
value|0x00000200
end_define

begin_comment
comment|/* STATUS: update ERP element */
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
name|IEEE80211_FEXT_PROBECHAN
value|0x00020000
end_define

begin_comment
comment|/* CONF: probe passive channel*/
end_comment

begin_comment
comment|/* ic_caps */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_WEP
value|0x00000001
end_define

begin_comment
comment|/* CAPABILITY: WEP available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TKIP
value|0x00000002
end_define

begin_comment
comment|/* CAPABILITY: TKIP available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_AES
value|0x00000004
end_define

begin_comment
comment|/* CAPABILITY: AES OCB avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_AES_CCM
value|0x00000008
end_define

begin_comment
comment|/* CAPABILITY: AES CCM avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_CKIP
value|0x00000020
end_define

begin_comment
comment|/* CAPABILITY: CKIP available */
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
name|IEEE80211_C_TKIPMIC
value|0x00020000
end_define

begin_comment
comment|/* CAPABILITY: TKIP MIC avail */
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

begin_comment
comment|/* XXX protection/barker? */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_CRYPTO
value|0x0000002f
end_define

begin_comment
comment|/* CAPABILITY: crypto alg's */
end_comment

begin_function_decl
name|void
name|ieee80211_ifattach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
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
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
name|ieee80211_get_suprates
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
name|ieee80211_media_init
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|ifm_change_cb_t
parameter_list|,
name|ifm_stat_cb_t
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
name|u_int8_t
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
name|ieee80211com
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
name|ieee80211_cfgget
parameter_list|(
name|struct
name|ieee80211com
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
name|ieee80211_cfgset
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_watchdog
parameter_list|(
name|struct
name|ieee80211com
modifier|*
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
name|ieee80211com
modifier|*
name|ic
parameter_list|)
block|{
name|ic
operator|->
name|ic_crypto
operator|.
name|cs_key_update_begin
argument_list|(
name|ic
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
name|ieee80211com
modifier|*
name|ic
parameter_list|)
block|{
name|ic
operator|->
name|ic_crypto
operator|.
name|cs_key_update_end
argument_list|(
name|ic
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
name|u_int32_t
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
name|u_int32_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function

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
name|IEEE80211_MSG_DOT1X
value|0x00020000
end_define

begin_comment
comment|/* 802.1x authenticator */
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
name|IEEE80211_MSG_RADKEYS
value|0x00002000
end_define

begin_comment
comment|/* dump 802.1x keys */
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
name|IEEE80211_MSG_ANY
value|0xffffffff
end_define

begin_comment
comment|/* anything */
end_comment

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
name|_ic
parameter_list|,
name|_m
parameter_list|)
value|((_ic)->ic_debug& (_m))
end_define

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF
parameter_list|(
name|_ic
parameter_list|,
name|_m
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (ieee80211_msg(_ic, _m))					\ 		ieee80211_note(_ic, _fmt, __VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE
parameter_list|(
name|_ic
parameter_list|,
name|_m
parameter_list|,
name|_ni
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (ieee80211_msg(_ic, _m))					\ 		ieee80211_note_mac(_ic, (_ni)->ni_macaddr, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_MAC
parameter_list|(
name|_ic
parameter_list|,
name|_m
parameter_list|,
name|_mac
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if (ieee80211_msg(_ic, _m))					\ 		ieee80211_note_mac(_ic, _mac, _fmt, __VA_ARGS__);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NOTE_FRAME
parameter_list|(
name|_ic
parameter_list|,
name|_m
parameter_list|,
name|_wh
parameter_list|,
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\ 	if (ieee80211_msg(_ic, _m))					\ 		ieee80211_note_frame(_ic, _wh, _fmt, __VA_ARGS__);	\ } while (0)
end_define

begin_function_decl
name|void
name|ieee80211_note
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
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
name|ieee80211_note_mac
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|u_int8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
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
name|ieee80211_note_frame
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
name|wh
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

begin_define
define|#
directive|define
name|ieee80211_msg_debug
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_DEBUG)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumppkts
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_DUMPPKTS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_input
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_INPUT)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_radius
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_RADIUS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumpradius
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_RADDUMP)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_dumpradkeys
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_RADKEYS)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_scan
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_SCAN)
end_define

begin_define
define|#
directive|define
name|ieee80211_msg_assoc
parameter_list|(
name|_ic
parameter_list|)
define|\
value|((_ic)->ic_debug& IEEE80211_MSG_ASSOC)
end_define

begin_comment
comment|/*  * Emit a debug message about discarding a frame or information  * element.  One format is for extracting the mac address from  * the frame header; the other is for when a header is not  * available or otherwise appropriate.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DISCARD
parameter_list|(
name|_ic
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
value|do {		\ 	if ((_ic)->ic_debug& (_m))					\ 		ieee80211_discard_frame(_ic, _wh, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_IE
parameter_list|(
name|_ic
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
value|do {	\ 	if ((_ic)->ic_debug& (_m))					\ 		ieee80211_discard_ie(_ic, _wh, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DISCARD_MAC
parameter_list|(
name|_ic
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
value|do {	\ 	if ((_ic)->ic_debug& (_m))					\ 		ieee80211_discard_mac(_ic, _mac, _type, _fmt, __VA_ARGS__);\ } while (0)
end_define

begin_function_decl
name|void
name|ieee80211_discard_frame
parameter_list|(
name|struct
name|ieee80211com
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
name|ieee80211com
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
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
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
name|_ic
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
name|IEEE80211_NOTE_FRAME
parameter_list|(
name|_ic
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
name|_ic
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
name|_ic
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|ieee80211_msg
parameter_list|(
name|_ic
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
name|_ic
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
name|_ic
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
name|_ic
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

