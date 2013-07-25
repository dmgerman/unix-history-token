begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|IEEE80211_S_CAC
init|=
literal|4
block|,
comment|/* doing channel availability check */
name|IEEE80211_S_RUN
init|=
literal|5
block|,
comment|/* operational (e.g. associated) */
name|IEEE80211_S_CSA
init|=
literal|6
block|,
comment|/* channel switch announce pending */
name|IEEE80211_S_SLEEP
init|=
literal|7
block|,
comment|/* power save */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_S_MAX
value|(IEEE80211_S_SLEEP+1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEND_MGMT
parameter_list|(
name|_ni
parameter_list|,
name|_type
parameter_list|,
name|_arg
parameter_list|)
define|\
value|((*(_ni)->ni_ic->ic_send_mgmt)(_ni, _type, _arg))
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ieee80211_phymode_name
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|ieee80211_opcap
index|[
name|IEEE80211_OPMODE_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ieee80211_proto_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_proto_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_proto_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_proto_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_syncifflag_locked
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_syncflag
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_syncflag_ht
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_syncflag_ext
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE80211_R_NF
value|0x0000001
end_define

begin_comment
comment|/* global NF value valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_RSSI
value|0x0000002
end_define

begin_comment
comment|/* global RSSI value valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_C_CHAIN
value|0x0000004
end_define

begin_comment
comment|/* RX chain count valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_C_NF
value|0x0000008
end_define

begin_comment
comment|/* per-chain NF value valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_C_RSSI
value|0x0000010
end_define

begin_comment
comment|/* per-chain RSSI value valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_C_EVM
value|0x0000020
end_define

begin_comment
comment|/* per-chain EVM valid */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_R_C_HT40
value|0x0000040
end_define

begin_comment
comment|/* RX'ed packet is 40mhz, pilots 4,5 valid */
end_comment

begin_struct
struct|struct
name|ieee80211_rx_stats
block|{
name|uint32_t
name|r_flags
decl_stmt|;
comment|/* IEEE80211_R_* flags */
name|uint8_t
name|c_chain
decl_stmt|;
comment|/* number of RX chains involved */
name|int16_t
name|c_nf_ctl
index|[
name|IEEE80211_MAX_CHAINS
index|]
decl_stmt|;
comment|/* per-chain NF */
name|int16_t
name|c_nf_ext
index|[
name|IEEE80211_MAX_CHAINS
index|]
decl_stmt|;
comment|/* per-chain NF */
name|int16_t
name|c_rssi_ctl
index|[
name|IEEE80211_MAX_CHAINS
index|]
decl_stmt|;
comment|/* per-chain RSSI */
name|int16_t
name|c_rssi_ext
index|[
name|IEEE80211_MAX_CHAINS
index|]
decl_stmt|;
comment|/* per-chain RSSI */
name|uint8_t
name|nf
decl_stmt|;
comment|/* global NF */
name|uint8_t
name|rssi
decl_stmt|;
comment|/* global RSSI */
name|uint8_t
name|evm
index|[
name|IEEE80211_MAX_CHAINS
index|]
index|[
name|IEEE80211_MAX_EVM_PILOTS
index|]
decl_stmt|;
comment|/* per-chain, per-pilot EVM values */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ieee80211_input
parameter_list|(
name|ni
parameter_list|,
name|m
parameter_list|,
name|rssi
parameter_list|,
name|nf
parameter_list|)
define|\
value|((ni)->ni_vap->iv_input(ni, m, rssi, nf))
end_define

begin_function_decl
name|int
name|ieee80211_input_all
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_input_mimo
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ieee80211_rx_stats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_input_mimo_all
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
name|ieee80211_rx_stats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_bpf_params
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_mgmt_output
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
name|struct
name|ieee80211_bpf_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_raw_xmit
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
end_function_decl

begin_function_decl
name|int
name|ieee80211_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_raw_output
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
parameter_list|,
specifier|const
name|struct
name|ieee80211_bpf_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_send_setup
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
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_start
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_send_nulldata
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_classify
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_mbuf_adjust
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ieee80211_key
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_encap
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
end_function_decl

begin_function_decl
name|int
name|ieee80211_send_mgmt
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
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_appie
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee80211_send_probereq
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
specifier|const
name|uint8_t
name|sa
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|uint8_t
name|da
index|[
name|IEEE80211_ADDR_LEN
index|]
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
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssidlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The formation of ProbeResponse frames requires guidance to  * deal with legacy clients.  When the client is identified as  * "legacy 11b" ieee80211_send_proberesp is passed this token.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SEND_LEGACY_11B
value|0x1
end_define

begin_comment
comment|/* legacy 11b client */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SEND_LEGACY_11
value|0x2
end_define

begin_comment
comment|/* other legacy client */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SEND_LEGACY
value|0x3
end_define

begin_comment
comment|/* any legacy client */
end_comment

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_alloc_proberesp
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
name|ieee80211_send_proberesp
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|da
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_alloc_rts
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_alloc_cts
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_rates
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_xrates
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_wpa
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_rsn
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_qos
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|ieee80211_getcapinfo
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
name|ieee80211_reset_erp
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_set_shortslottime
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_iserp_rateset
parameter_list|(
specifier|const
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_setbasicrates
parameter_list|(
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|,
name|enum
name|ieee80211_phymode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_addbasicrates
parameter_list|(
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|,
name|enum
name|ieee80211_phymode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the size of the 802.11 header for a management or data frame.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_hdrsize
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
specifier|const
name|struct
name|ieee80211_frame
modifier|*
name|wh
init|=
name|data
decl_stmt|;
name|int
name|size
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|ieee80211_frame
argument_list|)
decl_stmt|;
comment|/* NB: we don't handle control frames */
name|KASSERT
argument_list|(
operator|(
name|wh
operator|->
name|i_fc
index|[
literal|0
index|]
operator|&
name|IEEE80211_FC0_TYPE_MASK
operator|)
operator|!=
name|IEEE80211_FC0_TYPE_CTL
argument_list|,
operator|(
literal|"%s: control frame"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|IEEE80211_IS_DSTODS
argument_list|(
name|wh
argument_list|)
condition|)
name|size
operator|+=
name|IEEE80211_ADDR_LEN
expr_stmt|;
if|if
condition|(
name|IEEE80211_QOS_HAS_SEQ
argument_list|(
name|wh
argument_list|)
condition|)
name|size
operator|+=
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function

begin_comment
comment|/*  * Like ieee80211_hdrsize, but handles any type of frame.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_anyhdrsize
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
specifier|const
name|struct
name|ieee80211_frame
modifier|*
name|wh
init|=
name|data
decl_stmt|;
if|if
condition|(
operator|(
name|wh
operator|->
name|i_fc
index|[
literal|0
index|]
operator|&
name|IEEE80211_FC0_TYPE_MASK
operator|)
operator|==
name|IEEE80211_FC0_TYPE_CTL
condition|)
block|{
switch|switch
condition|(
name|wh
operator|->
name|i_fc
index|[
literal|0
index|]
operator|&
name|IEEE80211_FC0_SUBTYPE_MASK
condition|)
block|{
case|case
name|IEEE80211_FC0_SUBTYPE_CTS
case|:
case|case
name|IEEE80211_FC0_SUBTYPE_ACK
case|:
return|return
sizeof|sizeof
argument_list|(
expr|struct
name|ieee80211_frame_ack
argument_list|)
return|;
case|case
name|IEEE80211_FC0_SUBTYPE_BAR
case|:
return|return
sizeof|sizeof
argument_list|(
expr|struct
name|ieee80211_frame_bar
argument_list|)
return|;
block|}
return|return
sizeof|sizeof
argument_list|(
expr|struct
name|ieee80211_frame_min
argument_list|)
return|;
block|}
else|else
return|return
name|ieee80211_hdrsize
argument_list|(
name|data
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Template for an in-kernel authenticator.  Authenticators  * register with the protocol code and are typically loaded  * as separate modules as needed.  One special authenticator  * is xauth; it intercepts requests so that protocols like  * WPA can be handled in user space.  */
end_comment

begin_struct
struct|struct
name|ieee80211_authenticator
block|{
specifier|const
name|char
modifier|*
name|ia_name
decl_stmt|;
comment|/* printable name */
name|int
function_decl|(
modifier|*
name|ia_attach
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
name|ia_detach
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
name|ia_node_join
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
name|ia_node_leave
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_authenticator_register
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|struct
name|ieee80211_authenticator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_authenticator_unregister
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ieee80211_authenticator
modifier|*
name|ieee80211_authenticator_get
parameter_list|(
name|int
name|auth
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211req
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Template for an MAC ACL policy module.  Such modules  * register with the protocol code and are passed the sender's  * address of each received auth frame for validation.  */
end_comment

begin_struct
struct|struct
name|ieee80211_aclator
block|{
specifier|const
name|char
modifier|*
name|iac_name
decl_stmt|;
comment|/* printable name */
name|int
function_decl|(
modifier|*
name|iac_attach
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
name|iac_detach
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_check
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_add
function_decl|)
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
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_remove
function_decl|)
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
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_flush
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_setpolicy
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
name|iac_getpolicy
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_setioctl
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211req
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|iac_getioctl
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211req
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_aclator_register
parameter_list|(
specifier|const
name|struct
name|ieee80211_aclator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_aclator_unregister
parameter_list|(
specifier|const
name|struct
name|ieee80211_aclator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ieee80211_aclator
modifier|*
name|ieee80211_aclator_get
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* use fixed legacy rate */
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

begin_define
define|#
directive|define
name|IEEE80211_F_DOBRS
value|0x00000010
end_define

begin_comment
comment|/* check basic rate set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_JOIN
value|0x00000020
end_define

begin_comment
comment|/* sta joining our bss */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_DOFMCS
value|0x00000040
end_define

begin_comment
comment|/* use fixed HT rate */
end_comment

begin_function_decl
name|int
name|ieee80211_fix_rate
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_rateset
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * WME/WMM support.  */
end_comment

begin_struct
struct|struct
name|wmeParams
block|{
name|uint8_t
name|wmep_acm
decl_stmt|;
name|uint8_t
name|wmep_aifsn
decl_stmt|;
name|uint8_t
name|wmep_logcwmin
decl_stmt|;
comment|/* log2(cwmin) */
name|uint8_t
name|wmep_logcwmax
decl_stmt|;
comment|/* log2(cwmax) */
name|uint8_t
name|wmep_txopLimit
decl_stmt|;
name|uint8_t
name|wmep_noackPolicy
decl_stmt|;
comment|/* 0 (ack), 1 (no ack) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_TXOP_TO_US
parameter_list|(
name|_txop
parameter_list|)
value|((_txop)<<5)
end_define

begin_define
define|#
directive|define
name|IEEE80211_US_TO_TXOP
parameter_list|(
name|_us
parameter_list|)
value|((_us)>>5)
end_define

begin_struct
struct|struct
name|chanAccParams
block|{
name|uint8_t
name|cap_info
decl_stmt|;
comment|/* version of the current set */
name|struct
name|wmeParams
name|cap_wmeParams
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_wme_state
block|{
name|u_int
name|wme_flags
decl_stmt|;
define|#
directive|define
name|WME_F_AGGRMODE
value|0x00000001
comment|/* STATUS: WME agressive mode */
name|u_int
name|wme_hipri_traffic
decl_stmt|;
comment|/* VI/VO frames in beacon interval */
name|u_int
name|wme_hipri_switch_thresh
decl_stmt|;
comment|/* agressive mode switch thresh */
name|u_int
name|wme_hipri_switch_hysteresis
decl_stmt|;
comment|/* agressive mode switch hysteresis */
name|struct
name|wmeParams
name|wme_params
index|[
literal|4
index|]
decl_stmt|;
comment|/* from assoc resp for each AC*/
name|struct
name|chanAccParams
name|wme_wmeChanParams
decl_stmt|;
comment|/* WME params applied to self */
name|struct
name|chanAccParams
name|wme_wmeBssChanParams
decl_stmt|;
comment|/* WME params bcast to stations */
name|struct
name|chanAccParams
name|wme_chanParams
decl_stmt|;
comment|/* params applied to self */
name|struct
name|chanAccParams
name|wme_bssChanParams
decl_stmt|;
comment|/* params bcast to stations */
name|int
function_decl|(
modifier|*
name|wme_update
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_wme_initparams
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_wme_updateparams
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_wme_updateparams_locked
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the WME TID from a QoS frame.  If no TID  * is present return the index for the "non-QoS" entry.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint8_t
name|ieee80211_gettid
parameter_list|(
specifier|const
name|struct
name|ieee80211_frame
modifier|*
name|wh
parameter_list|)
block|{
name|uint8_t
name|tid
decl_stmt|;
if|if
condition|(
name|IEEE80211_QOS_HAS_SEQ
argument_list|(
name|wh
argument_list|)
condition|)
block|{
if|if
condition|(
name|IEEE80211_IS_DSTODS
argument_list|(
name|wh
argument_list|)
condition|)
name|tid
operator|=
operator|(
operator|(
specifier|const
expr|struct
name|ieee80211_qosframe_addr4
operator|*
operator|)
name|wh
operator|)
operator|->
name|i_qos
index|[
literal|0
index|]
expr_stmt|;
else|else
name|tid
operator|=
operator|(
operator|(
specifier|const
expr|struct
name|ieee80211_qosframe
operator|*
operator|)
name|wh
operator|)
operator|->
name|i_qos
index|[
literal|0
index|]
expr_stmt|;
name|tid
operator|&=
name|IEEE80211_QOS_TID
expr_stmt|;
block|}
else|else
name|tid
operator|=
name|IEEE80211_NONQOS_TID
expr_stmt|;
return|return
name|tid
return|;
block|}
end_function

begin_function_decl
name|void
name|ieee80211_waitfor_parent
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_start_locked
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_start_all
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_stop_locked
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_stop
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_stop_all
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_suspend_all
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_resume_all
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_dturbo_switch
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|newflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_swbmiss
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_beacon_miss
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_new_state
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
end_function_decl

begin_function_decl
name|void
name|ieee80211_print_essid
parameter_list|(
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
name|ieee80211_dump_pkt
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|uint8_t
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
name|ieee80211_opmode_name
index|[]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ieee80211_wme_acnames
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Beacon frames constructed by ieee80211_beacon_alloc  * have the following structure filled in so drivers  * can update the frame later w/ minimal overhead.  */
end_comment

begin_struct
struct|struct
name|ieee80211_beacon_offsets
block|{
name|uint8_t
name|bo_flags
index|[
literal|4
index|]
decl_stmt|;
comment|/* update/state flags */
name|uint16_t
modifier|*
name|bo_caps
decl_stmt|;
comment|/* capabilities */
name|uint8_t
modifier|*
name|bo_cfp
decl_stmt|;
comment|/* start of CFParms element */
name|uint8_t
modifier|*
name|bo_tim
decl_stmt|;
comment|/* start of atim/dtim */
name|uint8_t
modifier|*
name|bo_wme
decl_stmt|;
comment|/* start of WME parameters */
name|uint8_t
modifier|*
name|bo_tdma
decl_stmt|;
comment|/* start of TDMA parameters */
name|uint8_t
modifier|*
name|bo_tim_trailer
decl_stmt|;
comment|/* start of fixed-size trailer */
name|uint16_t
name|bo_tim_len
decl_stmt|;
comment|/* atim/dtim length in bytes */
name|uint16_t
name|bo_tim_trailer_len
decl_stmt|;
comment|/* tim trailer length in bytes */
name|uint8_t
modifier|*
name|bo_erp
decl_stmt|;
comment|/* start of ERP element */
name|uint8_t
modifier|*
name|bo_htinfo
decl_stmt|;
comment|/* start of HT info element */
name|uint8_t
modifier|*
name|bo_ath
decl_stmt|;
comment|/* start of ATH parameters */
name|uint8_t
modifier|*
name|bo_appie
decl_stmt|;
comment|/* start of AppIE element */
name|uint16_t
name|bo_appie_len
decl_stmt|;
comment|/* AppIE length in bytes */
name|uint16_t
name|bo_csa_trailer_len
decl_stmt|;
name|uint8_t
modifier|*
name|bo_csa
decl_stmt|;
comment|/* start of CSA element */
name|uint8_t
modifier|*
name|bo_quiet
decl_stmt|;
comment|/* start of Quiet element */
name|uint8_t
modifier|*
name|bo_meshconf
decl_stmt|;
comment|/* start of MESHCONF element */
name|uint8_t
modifier|*
name|bo_spare
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_beacon_alloc
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_beacon_offsets
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Beacon frame updates are signaled through calls to iv_update_beacon  * with one of the IEEE80211_BEACON_* tokens defined below.  For devices  * that construct beacon frames on the host this can trigger a rebuild  * or defer the processing.  For devices that offload beacon frame  * handling this callback can be used to signal a rebuild.  The bo_flags  * array in the ieee80211_beacon_offsets structure is intended to record  * deferred processing requirements; ieee80211_beacon_update uses the  * state to optimize work.  Since this structure is owned by the driver  * and not visible to the 802.11 layer drivers must supply an iv_update_beacon  * callback that marks the flag bits and schedules (as necessary) an update.  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_BEACON_CAPS
init|=
literal|0
block|,
comment|/* capabilities */
name|IEEE80211_BEACON_TIM
init|=
literal|1
block|,
comment|/* DTIM/ATIM */
name|IEEE80211_BEACON_WME
init|=
literal|2
block|,
name|IEEE80211_BEACON_ERP
init|=
literal|3
block|,
comment|/* Extended Rate Phy */
name|IEEE80211_BEACON_HTINFO
init|=
literal|4
block|,
comment|/* HT Information */
name|IEEE80211_BEACON_APPIE
init|=
literal|5
block|,
comment|/* Application IE's */
name|IEEE80211_BEACON_CFP
init|=
literal|6
block|,
comment|/* CFParms */
name|IEEE80211_BEACON_CSA
init|=
literal|7
block|,
comment|/* Channel Switch Announcement */
name|IEEE80211_BEACON_TDMA
init|=
literal|9
block|,
comment|/* TDMA Info */
name|IEEE80211_BEACON_ATH
init|=
literal|10
block|,
comment|/* ATH parameters */
name|IEEE80211_BEACON_MESHCONF
init|=
literal|11
block|,
comment|/* Mesh Configuration */
block|}
enum|;
end_enum

begin_function_decl
name|int
name|ieee80211_beacon_update
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_beacon_offsets
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
name|mcast
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_csa_startswitch
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
name|mode
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_csa_completeswitch
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_csa_cancelswitch
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_cac_completeswitch
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Notification methods called from the 802.11 state machine.  * Note that while these are defined here, their implementation  * is OS-specific.  */
end_comment

begin_function_decl
name|void
name|ieee80211_notify_node_join
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
name|newassoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_node_leave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_scan_done
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_wds_discover
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_csa
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_radar
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

begin_enum
enum|enum
name|ieee80211_notify_cac_event
block|{
name|IEEE80211_NOTIFY_CAC_START
init|=
literal|0
block|,
comment|/* CAC timer started */
name|IEEE80211_NOTIFY_CAC_STOP
init|=
literal|1
block|,
comment|/* CAC intentionally stopped */
name|IEEE80211_NOTIFY_CAC_RADAR
init|=
literal|2
block|,
comment|/* CAC stopped due to radar detectio */
name|IEEE80211_NOTIFY_CAC_EXPIRE
init|=
literal|3
block|,
comment|/* CAC expired w/o radar */
block|}
enum|;
end_enum

begin_function_decl
name|void
name|ieee80211_notify_cac
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|enum
name|ieee80211_notify_cac_event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_node_deauth
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_node_auth
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_country
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|,
specifier|const
name|uint8_t
name|cc
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_notify_radio
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_PROTO_H_ */
end_comment

end_unit

