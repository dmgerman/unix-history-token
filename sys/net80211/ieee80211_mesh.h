begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-   * Copyright (c) 2009 The FreeBSD Foundation   * All rights reserved.   *   * This software was developed by Rui Paulo under sponsorship from the  * FreeBSD Foundation.   *    * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_MESH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_MESH_H_
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESH_DEFAULT_TTL
value|31
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESH_MAX_NEIGHBORS
value|15
end_define

begin_comment
comment|/*  * NB: all structures are __packed  so sizeof works on arm, et. al.  */
end_comment

begin_comment
comment|/*  * 802.11s Information Elements. */
end_comment

begin_comment
comment|/* Mesh Configuration */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESH_CONF_SZ
value|(7)
end_define

begin_struct
struct|struct
name|ieee80211_meshconf_ie
block|{
name|uint8_t
name|conf_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHCONF */
name|uint8_t
name|conf_len
decl_stmt|;
name|uint8_t
name|conf_pselid
decl_stmt|;
comment|/* Active Path Sel. Proto. ID */
name|uint8_t
name|conf_pmetid
decl_stmt|;
comment|/* Active Metric Identifier */
name|uint8_t
name|conf_ccid
decl_stmt|;
comment|/* Congestion Control Mode ID  */
name|uint8_t
name|conf_syncid
decl_stmt|;
comment|/* Sync. Protocol ID */
name|uint8_t
name|conf_authid
decl_stmt|;
comment|/* Auth. Protocol ID */
name|uint8_t
name|conf_form
decl_stmt|;
comment|/* Formation Information */
name|uint8_t
name|conf_cap
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Hybrid Wireless Mesh Protocol */
end_comment

begin_enum
enum|enum
block|{
comment|/* 0 reserved */
name|IEEE80211_MESHCONF_PATH_HWMP
init|=
literal|1
block|,
comment|/* 2-254 reserved */
name|IEEE80211_MESHCONF_PATH_VENDOR
init|=
literal|255
block|, }
enum|;
end_enum

begin_comment
comment|/* Airtime Link Metric */
end_comment

begin_enum
enum|enum
block|{
comment|/* 0 reserved */
name|IEEE80211_MESHCONF_METRIC_AIRTIME
init|=
literal|1
block|,
comment|/* 2-254 reserved */
name|IEEE80211_MESHCONF_METRIC_VENDOR
init|=
literal|255
block|, }
enum|;
end_enum

begin_comment
comment|/* Congestion Control */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_MESHCONF_CC_DISABLED
init|=
literal|0
block|,
name|IEEE80211_MESHCONF_CC_SIG
init|=
literal|1
block|,
comment|/* 2-254 reserved */
name|IEEE80211_MESHCONF_CC_VENDOR
init|=
literal|255
block|, }
enum|;
end_enum

begin_comment
comment|/* Neighbour Offset */
end_comment

begin_enum
enum|enum
block|{
comment|/* 0 reserved */
name|IEEE80211_MESHCONF_SYNC_NEIGHOFF
init|=
literal|1
block|,
comment|/* 2-254 rserved */
name|IEEE80211_MESHCONF_SYNC_VENDOR
init|=
literal|255
block|, }
enum|;
end_enum

begin_comment
comment|/* Authentication Protocol Identifier */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_MESHCONF_AUTH_DISABLED
init|=
literal|0
block|,
comment|/* Simultaneous Authenticaction of Equals */
name|IEEE80211_MESHCONF_AUTH_SEA
init|=
literal|1
block|,
name|IEEE80211_MESHCONF_AUTH_8021X
init|=
literal|2
block|,
comment|/* IEEE 802.1X */
comment|/* 3-254 reserved */
name|IEEE80211_MESHCONF_AUTH_VENDOR
init|=
literal|255
block|, }
enum|;
end_enum

begin_comment
comment|/* Mesh Formation Info */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_FORM_GATE
value|0x01
end_define

begin_comment
comment|/* Connected to Gate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_FORM_NNEIGH_MASK
value|0x7E
end_define

begin_comment
comment|/* Number of Neighbours */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_FORM_SA
value|0xF0
end_define

begin_comment
comment|/* indicating 802.1X auth */
end_comment

begin_comment
comment|/* Mesh Capability */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_AP
value|0x01
end_define

begin_comment
comment|/* Accepting Peers */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_MCCAS
value|0x02
end_define

begin_comment
comment|/* MCCA supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_MCCAE
value|0x04
end_define

begin_comment
comment|/* MCCA enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_FWRD
value|0x08
end_define

begin_comment
comment|/* forwarding enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_BTR
value|0x10
end_define

begin_comment
comment|/* Beacon Timing Report Enab */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_TBTT
value|0x20
end_define

begin_comment
comment|/* TBTT Adjusting  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHCONF_CAP_PSL
value|0x40
end_define

begin_comment
comment|/* Power Save Level */
end_comment

begin_comment
comment|/* 0x80 reserved */
end_comment

begin_comment
comment|/* Mesh Identifier */
end_comment

begin_struct
struct|struct
name|ieee80211_meshid_ie
block|{
name|uint8_t
name|id_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHID */
name|uint8_t
name|id_len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Link Metric Report */
end_comment

begin_struct
struct|struct
name|ieee80211_meshlmetric_ie
block|{
name|uint8_t
name|lm_ie
decl_stmt|;
comment|/* IEEE80211_ACTION_MESH_LMETRIC */
name|uint8_t
name|lm_len
decl_stmt|;
name|uint8_t
name|lm_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESH_LMETRIC_FLAGS_REQ
value|0x01
comment|/* Request */
comment|/* 	 * XXX: this field should be variable in size and depend on 	 * the active active path selection metric identifier 	 */
name|uint32_t
name|lm_metric
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHLMETRIC_INITIALVAL
value|0
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Congestion Notification */
end_comment

begin_struct
struct|struct
name|ieee80211_meshcngst_ie
block|{
name|uint8_t
name|cngst_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHCNGST */
name|uint8_t
name|cngst_len
decl_stmt|;
name|uint16_t
name|cngst_timer
index|[
literal|4
index|]
decl_stmt|;
comment|/* Expiration Timers: AC_BK, 					   AC_BE, AC_VI, AC_VO */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Peer Link Management */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MPM_BASE_SZ
value|(4)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MPM_MAX_SZ
value|(8)
end_define

begin_struct
struct|struct
name|ieee80211_meshpeer_ie
block|{
name|uint8_t
name|peer_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPEER */
name|uint8_t
name|peer_len
decl_stmt|;
name|uint16_t
name|peer_proto
decl_stmt|;
comment|/* Peer Management Protocol */
name|uint16_t
name|peer_llinkid
decl_stmt|;
comment|/* Local Link ID */
name|uint16_t
name|peer_linkid
decl_stmt|;
comment|/* Peer Link ID */
name|uint16_t
name|peer_rcode
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Peering Protocol Identifier field value */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_MPPID_MPM
init|=
literal|0
block|,
comment|/* Mesh peering management */
name|IEEE80211_MPPID_AUTH_MPM
init|=
literal|1
block|,
comment|/* Auth. mesh peering exchange */
comment|/* 2-65535 reserved */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* Mesh Channel Switch Annoucement */
end_comment

begin_struct
struct|struct
name|ieee80211_meshcsa_ie
block|{
name|uint8_t
name|csa_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHCSA */
name|uint8_t
name|csa_len
decl_stmt|;
name|uint8_t
name|csa_mode
decl_stmt|;
name|uint8_t
name|csa_newclass
decl_stmt|;
comment|/* New Regulatory Class */
name|uint8_t
name|csa_newchan
decl_stmt|;
name|uint8_t
name|csa_precvalue
decl_stmt|;
comment|/* Precedence Value */
name|uint8_t
name|csa_count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh TIM */
end_comment

begin_comment
comment|/* Equal to the non Mesh version */
end_comment

begin_comment
comment|/* Mesh Awake Window */
end_comment

begin_struct
struct|struct
name|ieee80211_meshawakew_ie
block|{
name|uint8_t
name|awakew_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHAWAKEW */
name|uint8_t
name|awakew_len
decl_stmt|;
name|uint8_t
name|awakew_windowlen
decl_stmt|;
comment|/* in TUs */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Beacon Timing */
end_comment

begin_struct
struct|struct
name|ieee80211_meshbeacont_ie
block|{
name|uint8_t
name|beacont_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHBEACONT */
name|uint8_t
name|beacont_len
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|mp_aid
decl_stmt|;
comment|/* Least Octet of AID */
name|uint16_t
name|mp_btime
decl_stmt|;
comment|/* Beacon Time */
name|uint16_t
name|mp_bint
decl_stmt|;
comment|/* Beacon Interval */
block|}
name|__packed
name|mp
index|[
literal|1
index|]
struct|;
comment|/* NB: variable size */
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Gate (GANN) Annoucement */
end_comment

begin_comment
comment|/*  * NB: these macros used for the length in the IEs does not include 2 bytes  * for _ie and _len fields as is defined by the standard.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHGANN_BASE_SZ
value|(15)
end_define

begin_struct
struct|struct
name|ieee80211_meshgann_ie
block|{
name|uint8_t
name|gann_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHGANN */
name|uint8_t
name|gann_len
decl_stmt|;
name|uint8_t
name|gann_flags
decl_stmt|;
name|uint8_t
name|gann_hopcount
decl_stmt|;
name|uint8_t
name|gann_ttl
decl_stmt|;
name|uint8_t
name|gann_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|gann_seq
decl_stmt|;
comment|/* GANN Sequence Number */
name|uint16_t
name|gann_interval
decl_stmt|;
comment|/* GANN Interval */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Root (MP) Annoucement */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHRANN_BASE_SZ
value|(21)
end_define

begin_struct
struct|struct
name|ieee80211_meshrann_ie
block|{
name|uint8_t
name|rann_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHRANN */
name|uint8_t
name|rann_len
decl_stmt|;
name|uint8_t
name|rann_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHRANN_FLAGS_GATE
value|0x01
comment|/* Mesh Gate */
name|uint8_t
name|rann_hopcount
decl_stmt|;
name|uint8_t
name|rann_ttl
decl_stmt|;
name|uint8_t
name|rann_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|rann_seq
decl_stmt|;
comment|/* HWMP Sequence Number */
name|uint32_t
name|rann_interval
decl_stmt|;
name|uint32_t
name|rann_metric
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Path Request */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHPREQ_BASE_SZ
value|(26)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPREQ_BASE_SZ_AE
value|(32)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPREQ_TRGT_SZ
value|(11)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPREQ_TCNT_OFFSET
value|(27)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPREQ_TCNT_OFFSET_AE
value|(33)
end_define

begin_struct
struct|struct
name|ieee80211_meshpreq_ie
block|{
name|uint8_t
name|preq_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPREQ */
name|uint8_t
name|preq_len
decl_stmt|;
name|uint8_t
name|preq_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHPREQ_FLAGS_GATE
value|0x01
comment|/* Mesh Gate */
define|#
directive|define
name|IEEE80211_MESHPREQ_FLAGS_AM
value|0x02
comment|/* 0 = bcast / 1 = ucast */
define|#
directive|define
name|IEEE80211_MESHPREQ_FLAGS_PP
value|0x04
comment|/* Proactive PREP */
define|#
directive|define
name|IEEE80211_MESHPREQ_FLAGS_AE
value|0x40
comment|/* Address Extension */
name|uint8_t
name|preq_hopcount
decl_stmt|;
name|uint8_t
name|preq_ttl
decl_stmt|;
name|uint32_t
name|preq_id
decl_stmt|;
name|uint8_t
name|preq_origaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|preq_origseq
decl_stmt|;
comment|/* HWMP Sequence Number */
comment|/* NB: may have Originator External Address */
name|uint8_t
name|preq_orig_ext_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|preq_lifetime
decl_stmt|;
name|uint32_t
name|preq_metric
decl_stmt|;
name|uint8_t
name|preq_tcount
decl_stmt|;
comment|/* target count */
struct|struct
block|{
name|uint8_t
name|target_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHPREQ_TFLAGS_TO
value|0x01
comment|/* Target Only */
define|#
directive|define
name|IEEE80211_MESHPREQ_TFLAGS_USN
value|0x04
comment|/* Unknown HWMP seq number */
name|uint8_t
name|target_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|target_seq
decl_stmt|;
comment|/* HWMP Sequence Number */
block|}
name|__packed
name|preq_targets
index|[
literal|1
index|]
struct|;
comment|/* NB: variable size */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Path Reply */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHPREP_BASE_SZ
value|(31)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPREP_BASE_SZ_AE
value|(37)
end_define

begin_struct
struct|struct
name|ieee80211_meshprep_ie
block|{
name|uint8_t
name|prep_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPREP */
name|uint8_t
name|prep_len
decl_stmt|;
name|uint8_t
name|prep_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHPREP_FLAGS_AE
value|0x40
comment|/* Address Extension */
name|uint8_t
name|prep_hopcount
decl_stmt|;
name|uint8_t
name|prep_ttl
decl_stmt|;
name|uint8_t
name|prep_targetaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|prep_targetseq
decl_stmt|;
comment|/* NB: May have Target External Address */
name|uint8_t
name|prep_target_ext_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|prep_lifetime
decl_stmt|;
name|uint32_t
name|prep_metric
decl_stmt|;
name|uint8_t
name|prep_origaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|prep_origseq
decl_stmt|;
comment|/* HWMP Sequence Number */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Path Error */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MESHPERR_MAXDEST
value|(19)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPERR_NDEST_OFFSET
value|(3)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPERR_BASE_SZ
value|(2)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPERR_DEST_SZ
value|(13)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHPERR_DEST_SZ_AE
value|(19)
end_define

begin_struct
struct|struct
name|ieee80211_meshperr_ie
block|{
name|uint8_t
name|perr_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPERR */
name|uint8_t
name|perr_len
decl_stmt|;
name|uint8_t
name|perr_ttl
decl_stmt|;
name|uint8_t
name|perr_ndests
decl_stmt|;
comment|/* Number of Destinations */
struct|struct
block|{
name|uint8_t
name|dest_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHPERR_DFLAGS_USN
value|0x01
comment|/* XXX: not part of standard */
define|#
directive|define
name|IEEE80211_MESHPERR_DFLAGS_RC
value|0x02
comment|/* XXX: not part of standard */
define|#
directive|define
name|IEEE80211_MESHPERR_FLAGS_AE
value|0x40
comment|/* Address Extension */
name|uint8_t
name|dest_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|dest_seq
decl_stmt|;
comment|/* HWMP Sequence Number */
comment|/* NB: May have Destination External Address */
name|uint8_t
name|dest_ext_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|dest_rcode
decl_stmt|;
block|}
name|__packed
name|perr_dests
index|[
literal|1
index|]
struct|;
comment|/* NB: variable size */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* Mesh Proxy Update */
end_comment

begin_struct
struct|struct
name|ieee80211_meshpu_ie
block|{
name|uint8_t
name|pu_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPU */
name|uint8_t
name|pu_len
decl_stmt|;
name|uint8_t
name|pu_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHPU_FLAGS_MASK
value|0x1
define|#
directive|define
name|IEEE80211_MESHPU_FLAGS_DEL
value|0x0
define|#
directive|define
name|IEEE80211_MESHPU_FLAGS_ADD
value|0x1
name|uint8_t
name|pu_seq
decl_stmt|;
comment|/* PU Sequence Number */
name|uint8_t
name|pu_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|pu_naddr
decl_stmt|;
comment|/* Number of Proxied Addresses */
comment|/* NB: proxied address follows */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Mesh Proxy Update Confirmation */
end_comment

begin_struct
struct|struct
name|ieee80211_meshpuc_ie
block|{
name|uint8_t
name|puc_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_MESHPUC */
name|uint8_t
name|puc_len
decl_stmt|;
name|uint8_t
name|puc_flags
decl_stmt|;
name|uint8_t
name|puc_seq
decl_stmt|;
comment|/* PU Sequence Number */
name|uint8_t
name|puc_daddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 802.11s Action Frames  * XXX: these are wrong, and some of them should be  * under MESH category while PROXY is under MULTIHOP category.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_INTERWORK
value|15
end_define

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_RESOURCE
value|16
end_define

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_PROXY
value|17
end_define

begin_comment
comment|/*  * Mesh Peering Action codes.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* 0 reserved */
name|IEEE80211_ACTION_MESHPEERING_OPEN
init|=
literal|1
block|,
name|IEEE80211_ACTION_MESHPEERING_CONFIRM
init|=
literal|2
block|,
name|IEEE80211_ACTION_MESHPEERING_CLOSE
init|=
literal|3
block|,
comment|/* 4-255 reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Mesh Action code.  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_ACTION_MESH_LMETRIC
init|=
literal|0
block|,
comment|/* Mesh Link Metric Report */
name|IEEE80211_ACTION_MESH_HWMP
init|=
literal|1
block|,
comment|/* HWMP Mesh Path Selection */
name|IEEE80211_ACTION_MESH_GANN
init|=
literal|2
block|,
comment|/* Gate Announcement */
name|IEEE80211_ACTION_MESH_CC
init|=
literal|3
block|,
comment|/* Congestion Control */
name|IEEE80211_ACTION_MESH_MCCA_SREQ
init|=
literal|4
block|,
comment|/* MCCA Setup Request */
name|IEEE80211_ACTION_MESH_MCCA_SREP
init|=
literal|5
block|,
comment|/* MCCA Setup Reply */
name|IEEE80211_ACTION_MESH_MCCA_AREQ
init|=
literal|6
block|,
comment|/* MCCA Advertisement Req. */
name|IEEE80211_ACTION_MESH_MCCA_ADVER
init|=
literal|7
block|,
comment|/* MCCA Advertisement */
name|IEEE80211_ACTION_MESH_MCCA_TRDOWN
init|=
literal|8
block|,
comment|/* MCCA Teardown */
name|IEEE80211_ACTION_MESH_TBTT_REQ
init|=
literal|9
block|,
comment|/* TBTT Adjustment Request */
name|IEEE80211_ACTION_MESH_TBTT_RES
init|=
literal|10
block|,
comment|/* TBTT Adjustment Response */
comment|/* 11-255 reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Different mesh control structures based on the AE  * (Address Extension) bits.  */
end_comment

begin_struct
struct|struct
name|ieee80211_meshcntl
block|{
name|uint8_t
name|mc_flags
decl_stmt|;
comment|/* Address Extension 00 */
name|uint8_t
name|mc_ttl
decl_stmt|;
comment|/* TTL */
name|uint8_t
name|mc_seq
index|[
literal|4
index|]
decl_stmt|;
comment|/* Sequence No. */
comment|/* NB: more addresses may follow */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_meshcntl_ae01
block|{
name|uint8_t
name|mc_flags
decl_stmt|;
comment|/* Address Extension 01 */
name|uint8_t
name|mc_ttl
decl_stmt|;
comment|/* TTL */
name|uint8_t
name|mc_seq
index|[
literal|4
index|]
decl_stmt|;
comment|/* Sequence No. */
name|uint8_t
name|mc_addr4
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_meshcntl_ae10
block|{
name|uint8_t
name|mc_flags
decl_stmt|;
comment|/* Address Extension 10 */
name|uint8_t
name|mc_ttl
decl_stmt|;
comment|/* TTL */
name|uint8_t
name|mc_seq
index|[
literal|4
index|]
decl_stmt|;
comment|/* Sequence No. */
name|uint8_t
name|mc_addr5
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|mc_addr6
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_MESH_AE_MASK
value|0x03
end_define

begin_enum
enum|enum
block|{
name|IEEE80211_MESH_AE_00
init|=
literal|0
block|,
comment|/* MC has no AE subfield */
name|IEEE80211_MESH_AE_01
init|=
literal|1
block|,
comment|/* MC contain addr4 */
name|IEEE80211_MESH_AE_10
init|=
literal|2
block|,
comment|/* MC contain addr5& addr6 */
name|IEEE80211_MESH_AE_11
init|=
literal|3
block|,
comment|/* RESERVED */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_MESH_PREQ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_MESH_PREP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_MESH_PERR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_MESH_RT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_MESH_GT_RT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Basic forwarding information:  * o Destination MAC  * o Next-hop MAC  * o Precursor list (not implemented yet)  * o Path timeout  * The rest is part of the active Mesh path selection protocol.  * XXX: to be moved out later.  */
end_comment

begin_struct
struct|struct
name|ieee80211_mesh_route
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211_mesh_route
argument_list|)
name|rt_next
expr_stmt|;
name|struct
name|ieee80211vap
modifier|*
name|rt_vap
decl_stmt|;
name|struct
name|mtx
name|rt_lock
decl_stmt|;
comment|/* fine grained route lock */
name|struct
name|callout
name|rt_discovery
decl_stmt|;
comment|/* discovery timeout */
name|int
name|rt_updtime
decl_stmt|;
comment|/* last update time */
name|uint8_t
name|rt_dest
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|rt_mesh_gate
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* meshDA */
name|uint8_t
name|rt_nexthop
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|rt_metric
decl_stmt|;
comment|/* path metric */
name|uint16_t
name|rt_nhops
decl_stmt|;
comment|/* number of hops */
name|uint16_t
name|rt_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_DISCOVER
value|0x01
comment|/* path discovery */
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_VALID
value|0x02
comment|/* path discovery complete */
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_PROXY
value|0x04
comment|/* proxy entry */
define|#
directive|define
name|IEEE80211_MESHRT_FLAGS_GATE
value|0x08
comment|/* mesh gate entry */
name|uint32_t
name|rt_lifetime
decl_stmt|;
comment|/* route timeout */
name|uint32_t
name|rt_lastmseq
decl_stmt|;
comment|/* last seq# seen dest */
name|uint32_t
name|rt_ext_seq
decl_stmt|;
comment|/* proxy seq number */
name|void
modifier|*
name|rt_priv
decl_stmt|;
comment|/* private data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_MESH_ROUTE_PRIV
parameter_list|(
name|rt
parameter_list|,
name|cast
parameter_list|)
value|((cast *)rt->rt_priv)
end_define

begin_comment
comment|/*  * Stored information about known mesh gates.  */
end_comment

begin_struct
struct|struct
name|ieee80211_mesh_gate_route
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211_mesh_gate_route
argument_list|)
name|gr_next
expr_stmt|;
name|uint8_t
name|gr_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|gr_lastseq
decl_stmt|;
name|struct
name|ieee80211_mesh_route
modifier|*
name|gr_route
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_MESH_PROTO_DSZ
value|12
end_define

begin_comment
comment|/* description size */
end_comment

begin_comment
comment|/*  * Mesh Path Selection Protocol.  */
end_comment

begin_enum_decl
enum_decl|enum
name|ieee80211_state
enum_decl|;
end_enum_decl

begin_struct
struct|struct
name|ieee80211_mesh_proto_path
block|{
name|uint8_t
name|mpp_active
decl_stmt|;
name|char
name|mpp_descr
index|[
name|IEEE80211_MESH_PROTO_DSZ
index|]
decl_stmt|;
name|uint8_t
name|mpp_ie
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
function_decl|(
modifier|*
name|mpp_discover
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
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mpp_peerdown
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
name|mpp_senderror
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
parameter_list|,
name|struct
name|ieee80211_mesh_route
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mpp_vattach
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
name|mpp_vdetach
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
name|mpp_newstate
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
specifier|const
name|size_t
name|mpp_privlen
decl_stmt|;
comment|/* size required in the routing table 					   for private data */
name|int
name|mpp_inact
decl_stmt|;
comment|/* inact. timeout for invalid routes 					   (ticks) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mesh Link Metric Report Protocol.  */
end_comment

begin_struct
struct|struct
name|ieee80211_mesh_proto_metric
block|{
name|uint8_t
name|mpm_active
decl_stmt|;
name|char
name|mpm_descr
index|[
name|IEEE80211_MESH_PROTO_DSZ
index|]
decl_stmt|;
name|uint8_t
name|mpm_ie
decl_stmt|;
name|uint32_t
function_decl|(
modifier|*
name|mpm_metric
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

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/*  * Mesh Authentication Protocol.  */
end_comment

begin_struct
struct|struct
name|ieee80211_mesh_proto_auth
block|{
name|uint8_t
name|mpa_ie
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_mesh_proto_congestion
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_mesh_proto_sync
block|{ }
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint32_t
name|ieee80211_mesh_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_MESH_SEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int32_t)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESH_SEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int32_t)((a)-(b))>= 0)
end_define

begin_struct
struct|struct
name|ieee80211_mesh_state
block|{
name|int
name|ms_idlen
decl_stmt|;
name|uint8_t
name|ms_id
index|[
name|IEEE80211_MESHID_LEN
index|]
decl_stmt|;
name|ieee80211_mesh_seq
name|ms_seq
decl_stmt|;
comment|/* seq no for meshcntl */
name|uint16_t
name|ms_neighbors
decl_stmt|;
name|uint8_t
name|ms_ttl
decl_stmt|;
comment|/* mesh ttl set in packets */
define|#
directive|define
name|IEEE80211_MESHFLAGS_AP
value|0x01
comment|/* accept peers */
define|#
directive|define
name|IEEE80211_MESHFLAGS_GATE
value|0x02
comment|/* mesh gate role */
define|#
directive|define
name|IEEE80211_MESHFLAGS_FWD
value|0x04
comment|/* forward packets */
define|#
directive|define
name|IEEE80211_MESHFLAGS_ROOT
value|0x08
comment|/* configured as root */
name|uint8_t
name|ms_flags
decl_stmt|;
name|struct
name|mtx
name|ms_rt_lock
decl_stmt|;
name|struct
name|callout
name|ms_cleantimer
decl_stmt|;
name|struct
name|callout
name|ms_gatetimer
decl_stmt|;
name|ieee80211_mesh_seq
name|ms_gateseq
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ieee80211_mesh_gate_route
argument_list|)
name|ms_known_gates
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ieee80211_mesh_route
argument_list|)
name|ms_routes
expr_stmt|;
name|struct
name|ieee80211_mesh_proto_metric
modifier|*
name|ms_pmetric
decl_stmt|;
name|struct
name|ieee80211_mesh_proto_path
modifier|*
name|ms_ppath
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_mesh_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_mesh_route
modifier|*
name|ieee80211_mesh_rt_find
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
end_function_decl

begin_function_decl
name|struct
name|ieee80211_mesh_route
modifier|*
name|ieee80211_mesh_rt_add
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
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_rt_del
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
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_rt_flush
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_rt_flush_peer
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
end_function_decl

begin_function_decl
name|int
name|ieee80211_mesh_rt_update
parameter_list|(
name|struct
name|ieee80211_mesh_route
modifier|*
name|rt
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_proxy_check
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
end_function_decl

begin_function_decl
name|int
name|ieee80211_mesh_register_proto_path
parameter_list|(
specifier|const
name|struct
name|ieee80211_mesh_proto_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_mesh_register_proto_metric
parameter_list|(
specifier|const
name|struct
name|ieee80211_mesh_proto_metric
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_meshid
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_meshconf
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_meshpeer
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_meshlmetric
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_meshgate
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_meshgann_ie
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_node_init
parameter_list|(
name|struct
name|ieee80211vap
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
name|ieee80211_mesh_node_cleanup
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_parse_meshid
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

begin_struct_decl
struct_decl|struct
name|ieee80211_scanparams
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_mesh_init_neighbor
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
name|void
name|ieee80211_mesh_update_beacon
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
name|struct
name|ieee80211_mesh_gate_route
modifier|*
name|ieee80211_mesh_mark_gate
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|ieee80211_mesh_route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_mesh_forward_to_gates
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|struct
name|ieee80211_mesh_route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_mesh_find_txnode
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
end_function_decl

begin_comment
comment|/*  * Return non-zero if proxy operation is enabled.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ieee80211_mesh_isproxyena
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{
name|struct
name|ieee80211_mesh_state
modifier|*
name|ms
init|=
name|vap
operator|->
name|iv_mesh
decl_stmt|;
return|return
operator|(
name|ms
operator|->
name|ms_flags
operator|&
operator|(
name|IEEE80211_MESHFLAGS_AP
operator||
name|IEEE80211_MESHFLAGS_GATE
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Process an outbound frame: if a path is known to the  * destination then return a reference to the next hop  * for immediate transmission.  Otherwise initiate path  * discovery and, if possible queue the packet to be  * sent when path discovery completes.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ieee80211_node
operator|*
name|ieee80211_mesh_discover
argument_list|(
argument|struct ieee80211vap *vap
argument_list|,
argument|const uint8_t dest[IEEE80211_ADDR_LEN]
argument_list|,
argument|struct mbuf *m
argument_list|)
block|{ 	struct
name|ieee80211_mesh_state
operator|*
name|ms
operator|=
name|vap
operator|->
name|iv_mesh
block|;
return|return
name|ms
operator|->
name|ms_ppath
operator|->
name|mpp_discover
argument_list|(
name|vap
argument_list|,
name|dest
argument_list|,
name|m
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET80211_IEEE80211_MESH_H_ */
end_comment

end_unit

