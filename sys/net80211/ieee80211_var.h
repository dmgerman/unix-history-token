begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|IEEE80211_CHAN_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANY
value|0xffff
end_define

begin_comment
comment|/* token for ``any channel'' */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANYC
define|\
value|((struct ieee80211_channel *) IEEE80211_CHAN_ANY)
end_define

begin_enum
enum|enum
name|ieee80211_phytype
block|{
name|IEEE80211_T_DS
block|,
comment|/* direct sequence spread spectrum */
name|IEEE80211_T_FH
block|,
comment|/* frequency hopping */
name|IEEE80211_T_OFDM
block|,
comment|/* frequency division multiplexing */
name|IEEE80211_T_TURBO
block|,
comment|/* high rate OFDM, aka turbo mode */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_T_CCK
value|IEEE80211_T_DS
end_define

begin_comment
comment|/* more common nomenclature */
end_comment

begin_comment
comment|/* XXX not really a mode; there are really multiple PHY's */
end_comment

begin_enum
enum|enum
name|ieee80211_phymode
block|{
name|IEEE80211_MODE_AUTO
init|=
literal|0
block|,
comment|/* autoselect */
name|IEEE80211_MODE_11A
init|=
literal|1
block|,
comment|/* 5GHz, OFDM */
name|IEEE80211_MODE_11B
init|=
literal|2
block|,
comment|/* 2GHz, CCK */
name|IEEE80211_MODE_11G
init|=
literal|3
block|,
comment|/* 2GHz, OFDM */
name|IEEE80211_MODE_TURBO
init|=
literal|4
block|,
comment|/* 5GHz, OFDM, 2x clock */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_MODE_MAX
value|(IEEE80211_MODE_TURBO+1)
end_define

begin_enum
enum|enum
name|ieee80211_opmode
block|{
name|IEEE80211_M_STA
init|=
literal|1
block|,
comment|/* infrastructure station */
name|IEEE80211_M_IBSS
init|=
literal|0
block|,
comment|/* IBSS (adhoc) station */
name|IEEE80211_M_AHDEMO
init|=
literal|3
block|,
comment|/* Old lucent compatible adhoc demo */
name|IEEE80211_M_HOSTAP
init|=
literal|6
block|,
comment|/* Software Access Point */
name|IEEE80211_M_MONITOR
init|=
literal|8
comment|/* Monitor mode */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Channels are specified by frequency and attributes.  */
end_comment

begin_struct
struct|struct
name|ieee80211_channel
block|{
name|u_int16_t
name|ic_freq
decl_stmt|;
comment|/* setting in Mhz */
name|u_int16_t
name|ic_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_comment
comment|/* bits 0-3 are for private use by drivers */
end_comment

begin_comment
comment|/* channel attributes */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TURBO
value|0x0010
end_define

begin_comment
comment|/* Turbo channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_CCK
value|0x0020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_OFDM
value|0x0040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_2GHZ
value|0x0080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_5GHZ
value|0x0100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PASSIVE
value|0x0200
end_define

begin_comment
comment|/* Only passive scan allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DYN
value|0x0400
end_define

begin_comment
comment|/* Dynamic CCK-OFDM channel */
end_comment

begin_comment
comment|/*  * Useful combinations of channel characteristics.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_A
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_B
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_CCK)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PUREG
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_G
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_T
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_A
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_B
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_PUREG
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_G
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_T
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_T) == IEEE80211_CHAN_T)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_2GHZ
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_2GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_5GHZ
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_5GHZ) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_OFDM
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_OFDM) != 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_IS_CHAN_CCK
parameter_list|(
name|_c
parameter_list|)
define|\
value|(((_c)->ic_flags& IEEE80211_CHAN_CCK) != 0)
end_define

begin_comment
comment|/* ni_chan encoding for FH phy */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANMOD
value|80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHAN
parameter_list|(
name|set
parameter_list|,
name|pat
parameter_list|)
value|(((set)-1)*IEEE80211_FH_CHANMOD+(pat))
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANSET
parameter_list|(
name|chan
parameter_list|)
value|((chan)/IEEE80211_FH_CHANMOD+1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_FH_CHANPAT
parameter_list|(
name|chan
parameter_list|)
value|((chan)%IEEE80211_FH_CHANMOD)
end_define

begin_struct
struct|struct
name|ieee80211com
block|{
name|struct
name|arpcom
name|ic_ac
decl_stmt|;
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
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
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
name|u_char
name|ic_chan_avail
index|[
name|roundup
argument_list|(
name|IEEE80211_CHAN_MAX
argument_list|,
name|NBBY
argument_list|)
index|]
decl_stmt|;
name|u_char
name|ic_chan_active
index|[
name|roundup
argument_list|(
name|IEEE80211_CHAN_MAX
argument_list|,
name|NBBY
argument_list|)
index|]
decl_stmt|;
name|u_char
name|ic_chan_scan
index|[
name|roundup
argument_list|(
name|IEEE80211_CHAN_MAX
argument_list|,
name|NBBY
argument_list|)
index|]
decl_stmt|;
name|struct
name|ifqueue
name|ic_mgtq
decl_stmt|;
name|u_int32_t
name|ic_flags
decl_stmt|;
comment|/* state flags */
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
name|int
name|ic_fixed_rate
decl_stmt|;
comment|/* index to ic_sup_rates[] */
name|u_int16_t
name|ic_rtsthreshold
decl_stmt|;
name|u_int16_t
name|ic_fragthreshold
decl_stmt|;
name|struct
name|mtx
name|ic_nodelock
decl_stmt|;
comment|/* on node table */
name|struct
name|ieee80211_node
modifier|*
function_decl|(
modifier|*
name|ic_node_alloc
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
name|ic_node_free
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ic_node_copy
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
specifier|const
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ieee80211_node
argument_list|)
name|ic_node
expr_stmt|;
comment|/* information of all nodes */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ieee80211_node
argument_list|)
name|ic_hash
index|[
name|IEEE80211_NODE_HASHSIZE
index|]
expr_stmt|;
name|u_int16_t
name|ic_lintval
decl_stmt|;
comment|/* listen interval */
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
name|ic_txpower
decl_stmt|;
comment|/* tx power setting (dbM) */
name|u_int16_t
name|ic_bmisstimeout
decl_stmt|;
comment|/* beacon miss threshold (ms) */
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
name|struct
name|ieee80211_wepkey
name|ic_nw_keys
index|[
name|IEEE80211_WEP_NKID
index|]
decl_stmt|;
name|int
name|ic_wep_txkey
decl_stmt|;
comment|/* default tx key index */
name|void
modifier|*
name|ic_wep_ctx
decl_stmt|;
comment|/* wep crypt context */
name|u_int32_t
name|ic_iv
decl_stmt|;
comment|/* initial vector for wep */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ic_if
value|ic_ac.ac_if
end_define

begin_define
define|#
directive|define
name|ic_softc
value|ic_if.if_softc
end_define

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

begin_define
define|#
directive|define
name|IEEE80211_F_ASCAN
value|0x00000001
end_define

begin_comment
comment|/* STATUS: active scan */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SIBSS
value|0x00000002
end_define

begin_comment
comment|/* STATUS: start IBSS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_WEPON
value|0x00000100
end_define

begin_comment
comment|/* CONF: WEP enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_IBSSON
value|0x00000200
end_define

begin_comment
comment|/* CONF: IBSS creation enable */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_PMGTON
value|0x00000400
end_define

begin_comment
comment|/* CONF: Power mgmt enable */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DESBSSID
value|0x00000800
end_define

begin_comment
comment|/* CONF: des_bssid is set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SCANAP
value|0x00001000
end_define

begin_comment
comment|/* CONF: Scanning AP */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_ROAMING
value|0x00002000
end_define

begin_comment
comment|/* CONF: roaming enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SWRETRY
value|0x00004000
end_define

begin_comment
comment|/* CONF: sw tx retry enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TXPMGT
value|0x00018000
end_define

begin_comment
comment|/* STATUS: tx power */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TXPOW_OFF
value|0x00000000
end_define

begin_comment
comment|/* TX Power: radio disabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TXPOW_FIXED
value|0x00008000
end_define

begin_comment
comment|/* TX Power: fixed rate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_TXPOW_AUTO
value|0x00010000
end_define

begin_comment
comment|/* TX Power: undefined */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SHSLOT
value|0x00020000
end_define

begin_comment
comment|/* CONF: short slot time */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_SHPREAMBLE
value|0x00040000
end_define

begin_comment
comment|/* CONF: short preamble */
end_comment

begin_comment
comment|/* ic_capabilities */
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
name|IEEE80211_C_IBSS
value|0x00000002
end_define

begin_comment
comment|/* CAPABILITY: IBSS available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_PMGT
value|0x00000004
end_define

begin_comment
comment|/* CAPABILITY: Power mgmt */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_HOSTAP
value|0x00000008
end_define

begin_comment
comment|/* CAPABILITY: HOSTAP avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_AHDEMO
value|0x00000010
end_define

begin_comment
comment|/* CAPABILITY: Old Adhoc Demo */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SWRETRY
value|0x00000020
end_define

begin_comment
comment|/* CAPABILITY: sw tx retry */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_TXPMGT
value|0x00000040
end_define

begin_comment
comment|/* CAPABILITY: tx power mgmt */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SHSLOT
value|0x00000080
end_define

begin_comment
comment|/* CAPABILITY: short slottime */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_SHPREAMBLE
value|0x00000100
end_define

begin_comment
comment|/* CAPABILITY: short preamble */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_C_MONITOR
value|0x00000200
end_define

begin_comment
comment|/* CAPABILITY: monitor mode */
end_comment

begin_comment
comment|/* flags for ieee80211_fix_rate() */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DOSORT
value|0x00000001
end_define

begin_comment
comment|/* sort rate list */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DOFRATE
value|0x00000002
end_define

begin_comment
comment|/* use fixed rate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DONEGO
value|0x00000004
end_define

begin_comment
comment|/* calc negotiated rate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DODEL
value|0x00000008
end_define

begin_comment
comment|/* delete ignore rate */
end_comment

begin_function_decl
name|void
name|ieee80211_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_media_init
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|ifm_change_cb_t
parameter_list|,
name|ifm_stat_cb_t
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
name|ieee80211_cfgget
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
name|ieee80211_cfgset
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
name|void
name|ieee80211_watchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_fix_rate
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
name|u_int
name|ieee80211_mhz2ieee
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ieee80211_chan2ieee
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
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE80211_DEBUG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE80211_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ieee80211_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF
parameter_list|(
name|X
parameter_list|)
value|if (ieee80211_debug) printf X
end_define

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF2
parameter_list|(
name|X
parameter_list|)
value|if (ieee80211_debug>1) printf X
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DPRINTF2
parameter_list|(
name|X
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

