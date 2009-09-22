begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_H_
end_define

begin_comment
comment|/*  * 802.11 protocol definitions.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ADDR_LEN
value|6
end_define

begin_comment
comment|/* size of 802.11 address */
end_comment

begin_comment
comment|/* is 802.11 address multicast/broadcast? */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IS_MULTICAST
parameter_list|(
name|_a
parameter_list|)
value|(*(_a)& 0x01)
end_define

begin_typedef
typedef|typedef
name|uint16_t
name|ieee80211_seq
typedef|;
end_typedef

begin_comment
comment|/* IEEE 802.11 PLCP header */
end_comment

begin_struct
struct|struct
name|ieee80211_plcp_hdr
block|{
name|uint16_t
name|i_sfd
decl_stmt|;
name|uint8_t
name|i_signal
decl_stmt|;
name|uint8_t
name|i_service
decl_stmt|;
name|uint16_t
name|i_length
decl_stmt|;
name|uint16_t
name|i_crc
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SFD
value|0xF3A0
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SERVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SERVICE_LOCKED
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCL_SERVICE_PBCC
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SERVICE_LENEXT5
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SERVICE_LENEXT6
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_PLCP_SERVICE_LENEXT7
value|0x80
end_define

begin_comment
comment|/*  * generic definitions for IEEE 802.11 frames  */
end_comment

begin_struct
struct|struct
name|ieee80211_frame
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
comment|/* possibly followed by addr4[IEEE80211_ADDR_LEN]; */
comment|/* see below */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_qosframe
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_qos
index|[
literal|2
index|]
decl_stmt|;
comment|/* possibly followed by addr4[IEEE80211_ADDR_LEN]; */
comment|/* see below */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_qoscntl
block|{
name|uint8_t
name|i_qos
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_addr4
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr4
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
name|ieee80211_qosframe_addr4
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr4
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_qos
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_0
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_MGT
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_CTL
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_SHIFT
value|4
end_define

begin_comment
comment|/* for TYPE_MGT */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ASSOC_REQ
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ASSOC_RESP
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_REASSOC_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_REASSOC_RESP
value|0x30
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PROBE_REQ
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PROBE_RESP
value|0x50
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_BEACON
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ATIM
value|0x90
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DISASSOC
value|0xa0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_AUTH
value|0xb0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DEAUTH
value|0xc0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ACTION
value|0xd0
end_define

begin_comment
comment|/* for TYPE_CTL */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_BAR
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_BA
value|0x90
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PS_POLL
value|0xa0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_RTS
value|0xb0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CTS
value|0xc0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ACK
value|0xd0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_END
value|0xe0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_END_ACK
value|0xf0
end_define

begin_comment
comment|/* for TYPE_DATA (bit combination) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_POLL
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_ACPL
value|0x30
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_NODATA
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CFACK
value|0x50
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CFPOLL
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_ACK_CF_ACK
value|0x70
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_QOS
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_QOS_NULL
value|0xc0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_NODS
value|0x00
end_define

begin_comment
comment|/* STA->STA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_TODS
value|0x01
end_define

begin_comment
comment|/* STA->AP  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_FROMDS
value|0x02
end_define

begin_comment
comment|/* AP ->STA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_DSTODS
value|0x03
end_define

begin_comment
comment|/* AP ->AP  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_IS_DSTODS
parameter_list|(
name|wh
parameter_list|)
define|\
value|(((wh)->i_fc[1]& IEEE80211_FC1_DIR_MASK) == IEEE80211_FC1_DIR_DSTODS)
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_MORE_FRAG
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_RETRY
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_PWR_MGT
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_MORE_DATA
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_WEP
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_ORDER
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_FRAG_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_FRAG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_SEQ_MASK
value|0xfff0
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_SEQ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_RANGE
value|4096
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_ADD
parameter_list|(
name|seq
parameter_list|,
name|incr
parameter_list|)
define|\
value|(((seq) + (incr))& (IEEE80211_SEQ_RANGE-1))
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_INC
parameter_list|(
name|seq
parameter_list|)
value|IEEE80211_SEQ_ADD(seq,1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_SUB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a) + IEEE80211_SEQ_RANGE - (b))& (IEEE80211_SEQ_RANGE-1))
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_BA_RANGE
value|2048
end_define

begin_comment
comment|/* 2^11 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SEQ_BA_BEFORE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(IEEE80211_SEQ_SUB(b, a+1)< IEEE80211_SEQ_BA_RANGE-1)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NWID_LEN
value|32
end_define

begin_define
define|#
directive|define
name|IEEE80211_MESHID_LEN
value|32
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_TXOP
value|0x00ff
end_define

begin_comment
comment|/* bit 8 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_AMSDU
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_AMSDU_S
value|7
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY_S
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY_NOACK
value|0x20
end_define

begin_comment
comment|/* No ACK required */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY_BA
value|0x60
end_define

begin_comment
comment|/* Block ACK */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_EOSP
value|0x10
end_define

begin_comment
comment|/* EndOfService Period*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_EOSP_S
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_TID
value|0x0f
end_define

begin_comment
comment|/* does frame have QoS sequence control data */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_HAS_SEQ
parameter_list|(
name|wh
parameter_list|)
define|\
value|(((wh)->i_fc[0]& \ 	  (IEEE80211_FC0_TYPE_MASK | IEEE80211_FC0_SUBTYPE_QOS)) == \ 	  (IEEE80211_FC0_TYPE_DATA | IEEE80211_FC0_SUBTYPE_QOS))
end_define

begin_comment
comment|/*  * WME/802.11e information element.  */
end_comment

begin_struct
struct|struct
name|ieee80211_wme_info
block|{
name|uint8_t
name|wme_id
decl_stmt|;
comment|/* IEEE80211_ELEMID_VENDOR */
name|uint8_t
name|wme_len
decl_stmt|;
comment|/* length in bytes */
name|uint8_t
name|wme_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x00, 0x50, 0xf2 */
name|uint8_t
name|wme_type
decl_stmt|;
comment|/* OUI type */
name|uint8_t
name|wme_subtype
decl_stmt|;
comment|/* OUI subtype */
name|uint8_t
name|wme_version
decl_stmt|;
comment|/* spec revision */
name|uint8_t
name|wme_info
decl_stmt|;
comment|/* QoS info */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * WME/802.11e Tspec Element  */
end_comment

begin_struct
struct|struct
name|ieee80211_wme_tspec
block|{
name|uint8_t
name|ts_id
decl_stmt|;
name|uint8_t
name|ts_len
decl_stmt|;
name|uint8_t
name|ts_oui
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|ts_oui_type
decl_stmt|;
name|uint8_t
name|ts_oui_subtype
decl_stmt|;
name|uint8_t
name|ts_version
decl_stmt|;
name|uint8_t
name|ts_tsinfo
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|ts_nom_msdu
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|ts_max_msdu
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|ts_min_svc
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_max_svc
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_inactv_intv
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_susp_intv
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_start_svc
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_min_rate
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_mean_rate
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_max_burst
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_min_phy
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_peak_rate
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_delay
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|ts_surplus
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|ts_medium_time
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * WME AC parameter field  */
end_comment

begin_struct
struct|struct
name|ieee80211_wme_acparams
block|{
name|uint8_t
name|acp_aci_aifsn
decl_stmt|;
name|uint8_t
name|acp_logcwminmax
decl_stmt|;
name|uint16_t
name|acp_txop
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|WME_NUM_AC
value|4
end_define

begin_comment
comment|/* 4 AC categories */
end_comment

begin_define
define|#
directive|define
name|WME_NUM_TID
value|16
end_define

begin_comment
comment|/* 16 tids */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_ACI
value|0x60
end_define

begin_comment
comment|/* Mask for ACI field */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_ACI_S
value|5
end_define

begin_comment
comment|/* Shift for ACI field */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_ACM
value|0x10
end_define

begin_comment
comment|/* Mask for ACM bit */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_ACM_S
value|4
end_define

begin_comment
comment|/* Shift for ACM bit */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_AIFSN
value|0x0f
end_define

begin_comment
comment|/* Mask for aifsn field */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_AIFSN_S
value|0
end_define

begin_comment
comment|/* Shift for aifsn field */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_LOGCWMIN
value|0x0f
end_define

begin_comment
comment|/* Mask for CwMin field (in log) */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_LOGCWMIN_S
value|0
end_define

begin_comment
comment|/* Shift for CwMin field */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_LOGCWMAX
value|0xf0
end_define

begin_comment
comment|/* Mask for CwMax field (in log) */
end_comment

begin_define
define|#
directive|define
name|WME_PARAM_LOGCWMAX_S
value|4
end_define

begin_comment
comment|/* Shift for CwMax field */
end_comment

begin_define
define|#
directive|define
name|WME_AC_TO_TID
parameter_list|(
name|_ac
parameter_list|)
value|(       \ 	((_ac) == WME_AC_VO) ? 6 : \ 	((_ac) == WME_AC_VI) ? 5 : \ 	((_ac) == WME_AC_BK) ? 1 : \ 	0)
end_define

begin_define
define|#
directive|define
name|TID_TO_WME_AC
parameter_list|(
name|_tid
parameter_list|)
value|(      \ 	((_tid) == 0 || (_tid) == 3) ? WME_AC_BE : \ 	((_tid)< 3) ? WME_AC_BK : \ 	((_tid)< 6) ? WME_AC_VI : \ 	WME_AC_VO)
end_define

begin_comment
comment|/*  * WME Parameter Element  */
end_comment

begin_struct
struct|struct
name|ieee80211_wme_param
block|{
name|uint8_t
name|param_id
decl_stmt|;
name|uint8_t
name|param_len
decl_stmt|;
name|uint8_t
name|param_oui
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|param_oui_type
decl_stmt|;
name|uint8_t
name|param_oui_subtype
decl_stmt|;
name|uint8_t
name|param_version
decl_stmt|;
name|uint8_t
name|param_qosInfo
decl_stmt|;
define|#
directive|define
name|WME_QOSINFO_COUNT
value|0x0f
comment|/* Mask for param count field */
name|uint8_t
name|param_reserved
decl_stmt|;
name|struct
name|ieee80211_wme_acparams
name|params_acParams
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Management Notification Frame  */
end_comment

begin_struct
struct|struct
name|ieee80211_mnf
block|{
name|uint8_t
name|mnf_category
decl_stmt|;
name|uint8_t
name|mnf_action
decl_stmt|;
name|uint8_t
name|mnf_dialog
decl_stmt|;
name|uint8_t
name|mnf_status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MNF_SETUP_REQ
value|0
end_define

begin_define
define|#
directive|define
name|MNF_SETUP_RESP
value|1
end_define

begin_define
define|#
directive|define
name|MNF_TEARDOWN
value|2
end_define

begin_comment
comment|/*   * 802.11n Management Action Frames   */
end_comment

begin_comment
comment|/* generic frame format */
end_comment

begin_struct
struct|struct
name|ieee80211_action
block|{
name|uint8_t
name|ia_category
decl_stmt|;
name|uint8_t
name|ia_action
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_SM
value|0
end_define

begin_comment
comment|/* Spectrum Management */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_QOS
value|1
end_define

begin_comment
comment|/* QoS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_DLS
value|2
end_define

begin_comment
comment|/* DLS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_BA
value|3
end_define

begin_comment
comment|/* BA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_HT
value|7
end_define

begin_comment
comment|/* HT */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_CAT_VENDOR
value|127
end_define

begin_comment
comment|/* Vendor Specific */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_HT_TXCHWIDTH
value|0
end_define

begin_comment
comment|/* recommended xmit chan width*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_HT_MIMOPWRSAVE
value|1
end_define

begin_comment
comment|/* MIMO power save */
end_comment

begin_comment
comment|/* HT - recommended transmission channel width */
end_comment

begin_struct
struct|struct
name|ieee80211_action_ht_txchwidth
block|{
name|struct
name|ieee80211_action
name|at_header
decl_stmt|;
name|uint8_t
name|at_chwidth
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_A_HT_TXCHWIDTH_20
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_A_HT_TXCHWIDTH_2040
value|1
end_define

begin_comment
comment|/* HT - MIMO Power Save (NB: D2.04) */
end_comment

begin_struct
struct|struct
name|ieee80211_action_ht_mimopowersave
block|{
name|struct
name|ieee80211_action
name|am_header
decl_stmt|;
name|uint8_t
name|am_control
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_A_HT_MIMOPWRSAVE_ENA
value|0x01
end_define

begin_comment
comment|/* PS enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_A_HT_MIMOPWRSAVE_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_A_HT_MIMOPWRSAVE_MODE_S
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_A_HT_MIMOPWRSAVE_DYNAMIC
value|0x02
end_define

begin_comment
comment|/* Dynamic Mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_A_HT_MIMOPWRSAVE_STATIC
value|0x00
end_define

begin_comment
comment|/* no SM packets */
end_comment

begin_comment
comment|/* bits 2-7 reserved */
end_comment

begin_comment
comment|/* Block Ack actions */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_BA_ADDBA_REQUEST
value|0
end_define

begin_comment
comment|/* ADDBA request */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_BA_ADDBA_RESPONSE
value|1
end_define

begin_comment
comment|/* ADDBA response */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ACTION_BA_DELBA
value|2
end_define

begin_comment
comment|/* DELBA */
end_comment

begin_comment
comment|/* Block Ack Parameter Set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAPS_BUFSIZ
value|0xffc0
end_define

begin_comment
comment|/* buffer size */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAPS_BUFSIZ_S
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_BAPS_TID
value|0x003c
end_define

begin_comment
comment|/* TID */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAPS_TID_S
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_BAPS_POLICY
value|0x0002
end_define

begin_comment
comment|/* block ack policy */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAPS_POLICY_S
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_BAPS_POLICY_DELAYED
value|(0<<IEEE80211_BAPS_POLICY_S)
end_define

begin_define
define|#
directive|define
name|IEEE80211_BAPS_POLICY_IMMEDIATE
value|(1<<IEEE80211_BAPS_POLICY_S)
end_define

begin_comment
comment|/* Block Ack Sequence Control */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BASEQ_START
value|0xfff0
end_define

begin_comment
comment|/* starting seqnum */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BASEQ_START_S
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_BASEQ_FRAG
value|0x000f
end_define

begin_comment
comment|/* fragment number */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BASEQ_FRAG_S
value|0
end_define

begin_comment
comment|/* Delayed Block Ack Parameter Set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DELBAPS_TID
value|0xf000
end_define

begin_comment
comment|/* TID */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DELBAPS_TID_S
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_DELBAPS_INIT
value|0x0800
end_define

begin_comment
comment|/* initiator */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DELBAPS_INIT_S
value|11
end_define

begin_comment
comment|/* BA - ADDBA request */
end_comment

begin_struct
struct|struct
name|ieee80211_action_ba_addbarequest
block|{
name|struct
name|ieee80211_action
name|rq_header
decl_stmt|;
name|uint8_t
name|rq_dialogtoken
decl_stmt|;
name|uint16_t
name|rq_baparamset
decl_stmt|;
name|uint16_t
name|rq_batimeout
decl_stmt|;
comment|/* in TUs */
name|uint16_t
name|rq_baseqctl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* BA - ADDBA response */
end_comment

begin_struct
struct|struct
name|ieee80211_action_ba_addbaresponse
block|{
name|struct
name|ieee80211_action
name|rs_header
decl_stmt|;
name|uint8_t
name|rs_dialogtoken
decl_stmt|;
name|uint16_t
name|rs_statuscode
decl_stmt|;
name|uint16_t
name|rs_baparamset
decl_stmt|;
name|uint16_t
name|rs_batimeout
decl_stmt|;
comment|/* in TUs */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* BA - DELBA */
end_comment

begin_struct
struct|struct
name|ieee80211_action_ba_delba
block|{
name|struct
name|ieee80211_action
name|dl_header
decl_stmt|;
name|uint16_t
name|dl_baparamset
decl_stmt|;
name|uint16_t
name|dl_reasoncode
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* BAR Control */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_TID
value|0xf000
end_define

begin_comment
comment|/* TID */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_TID_S
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_BAR_COMP
value|0x0004
end_define

begin_comment
comment|/* Compressed Bitmap */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_MTID
value|0x0002
end_define

begin_comment
comment|/* Multi-TID */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_NOACK
value|0x0001
end_define

begin_comment
comment|/* No-Ack policy */
end_comment

begin_comment
comment|/* BAR Starting Sequence Control */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_SEQ_START
value|0xfff0
end_define

begin_comment
comment|/* starting seqnum */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BAR_SEQ_START_S
value|4
end_define

begin_struct
struct|struct
name|ieee80211_ba_request
block|{
name|uint16_t
name|rq_barctl
decl_stmt|;
name|uint16_t
name|rq_barseqctl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Control frames.  */
end_comment

begin_struct
struct|struct
name|ieee80211_frame_min
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_rts
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_ta
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_cts
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_ack
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_pspoll
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_aid
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_ta
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_cfend
block|{
comment|/* NB: also CF-End+CF-Ack */
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
comment|/* should be zero */
name|uint8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_frame_bar
block|{
name|uint8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|i_ta
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|i_ctl
decl_stmt|;
name|uint16_t
name|i_seq
decl_stmt|;
comment|/* FCS */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * BEACON management packets  *  *	octet timestamp[8]  *	octet beacon interval[2]  *	octet capability information[2]  *	information element  *		octet elemid  *		octet length  *		octet information[length]  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BEACON_INTERVAL
parameter_list|(
name|beacon
parameter_list|)
define|\
value|((beacon)[8] | ((beacon)[9]<< 8))
end_define

begin_define
define|#
directive|define
name|IEEE80211_BEACON_CAPABILITY
parameter_list|(
name|beacon
parameter_list|)
define|\
value|((beacon)[10] | ((beacon)[11]<< 8))
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_ESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_IBSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_CF_POLLABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_CF_POLLREQ
value|0x0008
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_PRIVACY
value|0x0010
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_SHORT_PREAMBLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_PBCC
value|0x0040
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_CHNL_AGILITY
value|0x0080
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_SPECTRUM_MGMT
value|0x0100
end_define

begin_comment
comment|/* bit 9 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_SHORT_SLOTTIME
value|0x0400
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_RSN
value|0x0800
end_define

begin_comment
comment|/* bit 12 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_DSSSOFDM
value|0x2000
end_define

begin_comment
comment|/* bits 14-15 are reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_BITS
define|\
value|"\20\1ESS\2IBSS\3CF_POLLABLE\4CF_POLLREQ\5PRIVACY\6SHORT_PREAMBLE" \ 	"\7PBCC\10CHNL_AGILITY\11SPECTRUM_MGMT\13SHORT_SLOTTIME\14RSN" \ 	"\16DSSOFDM"
end_define

begin_comment
comment|/*  * 802.11i/WPA information element (maximally sized).  */
end_comment

begin_struct
struct|struct
name|ieee80211_ie_wpa
block|{
name|uint8_t
name|wpa_id
decl_stmt|;
comment|/* IEEE80211_ELEMID_VENDOR */
name|uint8_t
name|wpa_len
decl_stmt|;
comment|/* length in bytes */
name|uint8_t
name|wpa_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x00, 0x50, 0xf2 */
name|uint8_t
name|wpa_type
decl_stmt|;
comment|/* OUI type */
name|uint16_t
name|wpa_version
decl_stmt|;
comment|/* spec revision */
name|uint32_t
name|wpa_mcipher
index|[
literal|1
index|]
decl_stmt|;
comment|/* multicast/group key cipher */
name|uint16_t
name|wpa_uciphercnt
decl_stmt|;
comment|/* # pairwise key ciphers */
name|uint32_t
name|wpa_uciphers
index|[
literal|8
index|]
decl_stmt|;
comment|/* ciphers */
name|uint16_t
name|wpa_authselcnt
decl_stmt|;
comment|/* authentication selector cnt*/
name|uint32_t
name|wpa_authsels
index|[
literal|8
index|]
decl_stmt|;
comment|/* selectors */
name|uint16_t
name|wpa_caps
decl_stmt|;
comment|/* 802.11i capabilities */
name|uint16_t
name|wpa_pmkidcnt
decl_stmt|;
comment|/* 802.11i pmkid count */
name|uint16_t
name|wpa_pmkids
index|[
literal|8
index|]
decl_stmt|;
comment|/* 802.11i pmkids */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * 802.11n HT Capability IE  * NB: these reflect D1.10   */
end_comment

begin_struct
struct|struct
name|ieee80211_ie_htcap
block|{
name|uint8_t
name|hc_id
decl_stmt|;
comment|/* element ID */
name|uint8_t
name|hc_len
decl_stmt|;
comment|/* length in bytes */
name|uint16_t
name|hc_cap
decl_stmt|;
comment|/* HT caps (see below) */
name|uint8_t
name|hc_param
decl_stmt|;
comment|/* HT params (see below) */
name|uint8_t
name|hc_mcsset
index|[
literal|16
index|]
decl_stmt|;
comment|/* supported MCS set */
name|uint16_t
name|hc_extcap
decl_stmt|;
comment|/* extended HT capabilities */
name|uint32_t
name|hc_txbf
decl_stmt|;
comment|/* txbf capabilities */
name|uint8_t
name|hc_antenna
decl_stmt|;
comment|/* antenna capabilities */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* HT capability flags (ht_cap) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_LDPC
value|0x0001
end_define

begin_comment
comment|/* LDPC supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_CHWIDTH40
value|0x0002
end_define

begin_comment
comment|/* 20/40 supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SMPS
value|0x000c
end_define

begin_comment
comment|/* SM Power Save mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SMPS_OFF
value|0x000c
end_define

begin_comment
comment|/* disabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SMPS_DYNAMIC
value|0x0004
end_define

begin_comment
comment|/* send RTS first */
end_comment

begin_comment
comment|/* NB: SMPS value 2 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SMPS_ENA
value|0x0000
end_define

begin_comment
comment|/* enabled (static mode) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_GREENFIELD
value|0x0010
end_define

begin_comment
comment|/* Greenfield supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SHORTGI20
value|0x0020
end_define

begin_comment
comment|/* Short GI in 20MHz */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_SHORTGI40
value|0x0040
end_define

begin_comment
comment|/* Short GI in 40MHz */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_TXSTBC
value|0x0080
end_define

begin_comment
comment|/* STBC tx ok */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RXSTBC
value|0x0300
end_define

begin_comment
comment|/* STBC rx support */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RXSTBC_S
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RXSTBC_1STREAM
value|0x0100
end_define

begin_comment
comment|/* 1 spatial stream */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RXSTBC_2STREAM
value|0x0200
end_define

begin_comment
comment|/* 1-2 spatial streams*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RXSTBC_3STREAM
value|0x0300
end_define

begin_comment
comment|/* 1-3 spatial streams*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_DELBA
value|0x0400
end_define

begin_comment
comment|/* HT DELBA supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXAMSDU
value|0x0800
end_define

begin_comment
comment|/* max A-MSDU length */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXAMSDU_7935
value|0x0800
end_define

begin_comment
comment|/* 7935 octets */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXAMSDU_3839
value|0x0000
end_define

begin_comment
comment|/* 3839 octets */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_DSSSCCK40
value|0x1000
end_define

begin_comment
comment|/* DSSS/CCK in 40MHz */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PSMP
value|0x2000
end_define

begin_comment
comment|/* PSMP supported */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_40INTOLERANT
value|0x4000
end_define

begin_comment
comment|/* 40MHz intolerant */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_LSIGTXOPPROT
value|0x8000
end_define

begin_comment
comment|/* L-SIG TXOP prot */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_BITS
define|\
value|"\20\1LDPC\2CHWIDTH40\5GREENFIELD\6SHORTGI20\7SHORTGI40\10TXSTBC" \ 	"\13DELBA\14AMSDU(7935)\15DSSSCCK40\16PSMP\1740INTOLERANT" \ 	"\20LSIGTXOPPROT"
end_define

begin_comment
comment|/* HT parameters (hc_param) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU
value|0x03
end_define

begin_comment
comment|/* max rx A-MPDU factor */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU_S
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU_8K
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU_16K
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU_32K
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MAXRXAMPDU_64K
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY
value|0x1c
end_define

begin_comment
comment|/* min MPDU start spacing */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_S
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_NA
value|0
end_define

begin_comment
comment|/* no time restriction */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_025
value|1
end_define

begin_comment
comment|/* 1/4 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_05
value|2
end_define

begin_comment
comment|/* 1/2 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_1
value|3
end_define

begin_comment
comment|/* 1 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_2
value|4
end_define

begin_comment
comment|/* 2 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_4
value|5
end_define

begin_comment
comment|/* 4 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_8
value|6
end_define

begin_comment
comment|/* 8 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MPDUDENSITY_16
value|7
end_define

begin_comment
comment|/* 16 us */
end_comment

begin_comment
comment|/* HT extended capabilities (hc_extcap) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCO
value|0x0001
end_define

begin_comment
comment|/* PCO capable */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCOTRANS
value|0x0006
end_define

begin_comment
comment|/* PCO transition time */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCOTRANS_S
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCOTRANS_04
value|0x0002
end_define

begin_comment
comment|/* 400 us */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCOTRANS_15
value|0x0004
end_define

begin_comment
comment|/* 1.5 ms */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_PCOTRANS_5
value|0x0006
end_define

begin_comment
comment|/* 5 ms */
end_comment

begin_comment
comment|/* bits 3-7 reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MCSFBACK
value|0x0300
end_define

begin_comment
comment|/* MCS feedback */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MCSFBACK_S
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MCSFBACK_NONE
value|0x0000
end_define

begin_comment
comment|/* nothing provided */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MCSFBACK_UNSOL
value|0x0200
end_define

begin_comment
comment|/* unsolicited feedback */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_MCSFBACK_MRQ
value|0x0300
end_define

begin_comment
comment|/* " "+respond to MRQ */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_HTC
value|0x0400
end_define

begin_comment
comment|/* +HTC support */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTCAP_RDR
value|0x0800
end_define

begin_comment
comment|/* reverse direction responder*/
end_comment

begin_comment
comment|/* bits 12-15 reserved */
end_comment

begin_comment
comment|/*  * 802.11n HT Information IE  */
end_comment

begin_struct
struct|struct
name|ieee80211_ie_htinfo
block|{
name|uint8_t
name|hi_id
decl_stmt|;
comment|/* element ID */
name|uint8_t
name|hi_len
decl_stmt|;
comment|/* length in bytes */
name|uint8_t
name|hi_ctrlchannel
decl_stmt|;
comment|/* primary channel */
name|uint8_t
name|hi_byte1
decl_stmt|;
comment|/* ht ie byte 1 */
name|uint8_t
name|hi_byte2
decl_stmt|;
comment|/* ht ie byte 2 */
name|uint8_t
name|hi_byte3
decl_stmt|;
comment|/* ht ie byte 3 */
name|uint16_t
name|hi_byte45
decl_stmt|;
comment|/* ht ie bytes 4+5 */
name|uint8_t
name|hi_basicmcsset
index|[
literal|16
index|]
decl_stmt|;
comment|/* basic MCS set */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* byte1 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDCHAN
value|0x03
end_define

begin_comment
comment|/* secondary/ext chan offset */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDCHAN_S
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDCHAN_NONE
value|0x00
end_define

begin_comment
comment|/* no secondary/ext channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDCHAN_ABOVE
value|0x01
end_define

begin_comment
comment|/* above private channel */
end_comment

begin_comment
comment|/* NB: 2 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDCHAN_BELOW
value|0x03
end_define

begin_comment
comment|/* below primary channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_TXWIDTH
value|0x04
end_define

begin_comment
comment|/* tx channel width */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_TXWIDTH_20
value|0x00
end_define

begin_comment
comment|/* 20MHz width */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_TXWIDTH_2040
value|0x04
end_define

begin_comment
comment|/* any supported width */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_RIFSMODE
value|0x08
end_define

begin_comment
comment|/* Reduced IFS (RIFS) use */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_RIFSMODE_PROH
value|0x00
end_define

begin_comment
comment|/* RIFS use prohibited */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_RIFSMODE_PERM
value|0x08
end_define

begin_comment
comment|/* RIFS use permitted */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_PMSPONLY
value|0x10
end_define

begin_comment
comment|/* PSMP required to associate */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_SIGRAN
value|0xe0
end_define

begin_comment
comment|/* shortest Service Interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_SIGRAN_S
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_SIGRAN_5
value|0x00
end_define

begin_comment
comment|/* 5 ms */
end_comment

begin_comment
comment|/* XXX add rest */
end_comment

begin_comment
comment|/* bytes 2+3 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE
value|0x03
end_define

begin_comment
comment|/* operating mode */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE_S
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE_PURE
value|0x00
end_define

begin_comment
comment|/* no protection */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE_PROTOPT
value|0x01
end_define

begin_comment
comment|/* protection optional */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE_HT20PR
value|0x02
end_define

begin_comment
comment|/* protection for HT20 sta's */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_OPMODE_MIXED
value|0x03
end_define

begin_comment
comment|/* protection for legacy sta's*/
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_NONGF_PRESENT
value|0x04
end_define

begin_comment
comment|/* non-GF sta's present */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_TXBL
value|0x08
end_define

begin_comment
comment|/* transmit burst limit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_NONHT_PRESENT
value|0x10
end_define

begin_comment
comment|/* non-HT sta's present */
end_comment

begin_comment
comment|/* bits 5-15 reserved */
end_comment

begin_comment
comment|/* bytes 4+5 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_2NDARYBEACON
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_LSIGTXOPPROT
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_PCO_ACTIVE
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_40MHZPHASE
value|0x08
end_define

begin_comment
comment|/* byte5 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_BASIC_STBCMCS
value|0x7f
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_BASIC_STBCMCS_S
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_HTINFO_DUALPROTECTED
value|0x80
end_define

begin_comment
comment|/*  * Management information element payloads.  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_ELEMID_SSID
init|=
literal|0
block|,
name|IEEE80211_ELEMID_RATES
init|=
literal|1
block|,
name|IEEE80211_ELEMID_FHPARMS
init|=
literal|2
block|,
name|IEEE80211_ELEMID_DSPARMS
init|=
literal|3
block|,
name|IEEE80211_ELEMID_CFPARMS
init|=
literal|4
block|,
name|IEEE80211_ELEMID_TIM
init|=
literal|5
block|,
name|IEEE80211_ELEMID_IBSSPARMS
init|=
literal|6
block|,
name|IEEE80211_ELEMID_COUNTRY
init|=
literal|7
block|,
name|IEEE80211_ELEMID_CHALLENGE
init|=
literal|16
block|,
comment|/* 17-31 reserved for challenge text extension */
name|IEEE80211_ELEMID_PWRCNSTR
init|=
literal|32
block|,
name|IEEE80211_ELEMID_PWRCAP
init|=
literal|33
block|,
name|IEEE80211_ELEMID_TPCREQ
init|=
literal|34
block|,
name|IEEE80211_ELEMID_TPCREP
init|=
literal|35
block|,
name|IEEE80211_ELEMID_SUPPCHAN
init|=
literal|36
block|,
name|IEEE80211_ELEMID_CSA
init|=
literal|37
block|,
name|IEEE80211_ELEMID_MEASREQ
init|=
literal|38
block|,
name|IEEE80211_ELEMID_MEASREP
init|=
literal|39
block|,
name|IEEE80211_ELEMID_QUIET
init|=
literal|40
block|,
name|IEEE80211_ELEMID_IBSSDFS
init|=
literal|41
block|,
name|IEEE80211_ELEMID_ERP
init|=
literal|42
block|,
name|IEEE80211_ELEMID_HTCAP
init|=
literal|45
block|,
name|IEEE80211_ELEMID_RSN
init|=
literal|48
block|,
name|IEEE80211_ELEMID_XRATES
init|=
literal|50
block|,
name|IEEE80211_ELEMID_HTINFO
init|=
literal|61
block|,
name|IEEE80211_ELEMID_TPC
init|=
literal|150
block|,
name|IEEE80211_ELEMID_CCKM
init|=
literal|156
block|,
name|IEEE80211_ELEMID_VENDOR
init|=
literal|221
block|,
comment|/* vendor private */
comment|/* 	 * 802.11s IEs based on D3.03 spec and were not assigned by 	 * ANA. Beware changing them because some of them are being 	 * kept compatible with Linux. 	 */
name|IEEE80211_ELEMID_MESHCONF
init|=
literal|51
block|,
name|IEEE80211_ELEMID_MESHID
init|=
literal|52
block|,
name|IEEE80211_ELEMID_MESHLINK
init|=
literal|35
block|,
name|IEEE80211_ELEMID_MESHCNGST
init|=
literal|36
block|,
name|IEEE80211_ELEMID_MESHPEER
init|=
literal|55
block|,
name|IEEE80211_ELEMID_MESHCSA
init|=
literal|38
block|,
name|IEEE80211_ELEMID_MESHTIM
init|=
literal|39
block|,
name|IEEE80211_ELEMID_MESHAWAKEW
init|=
literal|40
block|,
name|IEEE80211_ELEMID_MESHBEACONT
init|=
literal|41
block|,
name|IEEE80211_ELEMID_MESHPANN
init|=
literal|48
block|,
name|IEEE80211_ELEMID_MESHRANN
init|=
literal|49
block|,
name|IEEE80211_ELEMID_MESHPREQ
init|=
literal|68
block|,
name|IEEE80211_ELEMID_MESHPREP
init|=
literal|69
block|,
name|IEEE80211_ELEMID_MESHPERR
init|=
literal|70
block|,
name|IEEE80211_ELEMID_MESHPXU
init|=
literal|53
block|,
name|IEEE80211_ELEMID_MESHPXUC
init|=
literal|54
block|,
name|IEEE80211_ELEMID_MESHAH
init|=
literal|60
block|,
comment|/* Abbreviated Handshake */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211_tim_ie
block|{
name|uint8_t
name|tim_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_TIM */
name|uint8_t
name|tim_len
decl_stmt|;
name|uint8_t
name|tim_count
decl_stmt|;
comment|/* DTIM count */
name|uint8_t
name|tim_period
decl_stmt|;
comment|/* DTIM period */
name|uint8_t
name|tim_bitctl
decl_stmt|;
comment|/* bitmap control */
name|uint8_t
name|tim_bitmap
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable-length bitmap */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_country_ie
block|{
name|uint8_t
name|ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_COUNTRY */
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|cc
index|[
literal|3
index|]
decl_stmt|;
comment|/* ISO CC+(I)ndoor/(O)utdoor */
struct|struct
block|{
name|uint8_t
name|schan
decl_stmt|;
comment|/* starting channel */
name|uint8_t
name|nchan
decl_stmt|;
comment|/* number channels */
name|uint8_t
name|maxtxpwr
decl_stmt|;
comment|/* tx power cap */
block|}
name|__packed
name|band
index|[
literal|1
index|]
struct|;
comment|/* sub bands (NB: var size) */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_COUNTRY_MAX_BANDS
value|84
end_define

begin_comment
comment|/* max possible bands */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_COUNTRY_MAX_SIZE
define|\
value|(sizeof(struct ieee80211_country_ie) + 3*(IEEE80211_COUNTRY_MAX_BANDS-1))
end_define

begin_comment
comment|/*  * 802.11h Channel Switch Announcement (CSA).  */
end_comment

begin_struct
struct|struct
name|ieee80211_csa_ie
block|{
name|uint8_t
name|csa_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_CHANSWITCHANN */
name|uint8_t
name|csa_len
decl_stmt|;
name|uint8_t
name|csa_mode
decl_stmt|;
comment|/* Channel Switch Mode */
name|uint8_t
name|csa_newchan
decl_stmt|;
comment|/* New Channel Number */
name|uint8_t
name|csa_count
decl_stmt|;
comment|/* Channel Switch Count */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Note the min acceptable CSA count is used to guard against  * malicious CSA injection in station mode.  Defining this value  * as other than 0 violates the 11h spec.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CSA_COUNT_MIN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_CSA_COUNT_MAX
value|255
end_define

begin_comment
comment|/* rate set entries are in .5 Mb/s units, and potentially marked as basic */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RATE_BASIC
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_RATE_VAL
value|0x7f
end_define

begin_comment
comment|/* EPR information element flags */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_ERP_NON_ERP_PRESENT
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_ERP_USE_PROTECTION
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_ERP_LONG_PREAMBLE
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_ERP_BITS
define|\
value|"\20\1NON_ERP_PRESENT\2USE_PROTECTION\3LONG_PREAMBLE"
end_define

begin_define
define|#
directive|define
name|ATH_OUI
value|0x7f0300
end_define

begin_comment
comment|/* Atheros OUI */
end_comment

begin_define
define|#
directive|define
name|ATH_OUI_TYPE
value|0x01
end_define

begin_comment
comment|/* Atheros protocol ie */
end_comment

begin_comment
comment|/* NB: Atheros allocated the OUI for this purpose ~2005 but beware ... */
end_comment

begin_define
define|#
directive|define
name|TDMA_OUI
value|ATH_OUI
end_define

begin_define
define|#
directive|define
name|TDMA_OUI_TYPE
value|0x02
end_define

begin_comment
comment|/* TDMA protocol ie */
end_comment

begin_define
define|#
directive|define
name|BCM_OUI
value|0x4c9000
end_define

begin_comment
comment|/* Broadcom OUI */
end_comment

begin_define
define|#
directive|define
name|BCM_OUI_HTCAP
value|51
end_define

begin_comment
comment|/* pre-draft HTCAP ie */
end_comment

begin_define
define|#
directive|define
name|BCM_OUI_HTINFO
value|52
end_define

begin_comment
comment|/* pre-draft HTINFO ie */
end_comment

begin_define
define|#
directive|define
name|WPA_OUI
value|0xf25000
end_define

begin_define
define|#
directive|define
name|WPA_OUI_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|WPA_VERSION
value|1
end_define

begin_comment
comment|/* current supported version */
end_comment

begin_define
define|#
directive|define
name|WPA_CSE_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|WPA_CSE_WEP40
value|0x01
end_define

begin_define
define|#
directive|define
name|WPA_CSE_TKIP
value|0x02
end_define

begin_define
define|#
directive|define
name|WPA_CSE_CCMP
value|0x04
end_define

begin_define
define|#
directive|define
name|WPA_CSE_WEP104
value|0x05
end_define

begin_define
define|#
directive|define
name|WPA_ASE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|WPA_ASE_8021X_UNSPEC
value|0x01
end_define

begin_define
define|#
directive|define
name|WPA_ASE_8021X_PSK
value|0x02
end_define

begin_define
define|#
directive|define
name|WPS_OUI_TYPE
value|0x04
end_define

begin_define
define|#
directive|define
name|RSN_OUI
value|0xac0f00
end_define

begin_define
define|#
directive|define
name|RSN_VERSION
value|1
end_define

begin_comment
comment|/* current supported version */
end_comment

begin_define
define|#
directive|define
name|RSN_CSE_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|RSN_CSE_WEP40
value|0x01
end_define

begin_define
define|#
directive|define
name|RSN_CSE_TKIP
value|0x02
end_define

begin_define
define|#
directive|define
name|RSN_CSE_WRAP
value|0x03
end_define

begin_define
define|#
directive|define
name|RSN_CSE_CCMP
value|0x04
end_define

begin_define
define|#
directive|define
name|RSN_CSE_WEP104
value|0x05
end_define

begin_define
define|#
directive|define
name|RSN_ASE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RSN_ASE_8021X_UNSPEC
value|0x01
end_define

begin_define
define|#
directive|define
name|RSN_ASE_8021X_PSK
value|0x02
end_define

begin_define
define|#
directive|define
name|RSN_CAP_PREAUTH
value|0x01
end_define

begin_define
define|#
directive|define
name|WME_OUI
value|0xf25000
end_define

begin_define
define|#
directive|define
name|WME_OUI_TYPE
value|0x02
end_define

begin_define
define|#
directive|define
name|WME_INFO_OUI_SUBTYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|WME_PARAM_OUI_SUBTYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|WME_VERSION
value|1
end_define

begin_comment
comment|/* WME stream classes */
end_comment

begin_define
define|#
directive|define
name|WME_AC_BE
value|0
end_define

begin_comment
comment|/* best effort */
end_comment

begin_define
define|#
directive|define
name|WME_AC_BK
value|1
end_define

begin_comment
comment|/* background */
end_comment

begin_define
define|#
directive|define
name|WME_AC_VI
value|2
end_define

begin_comment
comment|/* video */
end_comment

begin_define
define|#
directive|define
name|WME_AC_VO
value|3
end_define

begin_comment
comment|/* voice */
end_comment

begin_comment
comment|/*  * AUTH management packets  *  *	octet algo[2]  *	octet seq[2]  *	octet status[2]  *	octet chal.id  *	octet chal.length  *	octet chal.text[253]		NB: 1-253 bytes  */
end_comment

begin_comment
comment|/* challenge length for shared key auth */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHALLENGE_LEN
value|128
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_ALG_OPEN
value|0x0000
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_ALG_SHARED
value|0x0001
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_ALG_LEAP
value|0x0080
end_define

begin_enum
enum|enum
block|{
name|IEEE80211_AUTH_OPEN_REQUEST
init|=
literal|1
block|,
name|IEEE80211_AUTH_OPEN_RESPONSE
init|=
literal|2
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|IEEE80211_AUTH_SHARED_REQUEST
init|=
literal|1
block|,
name|IEEE80211_AUTH_SHARED_CHALLENGE
init|=
literal|2
block|,
name|IEEE80211_AUTH_SHARED_RESPONSE
init|=
literal|3
block|,
name|IEEE80211_AUTH_SHARED_PASS
init|=
literal|4
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Reason and status codes.  *  * Reason codes are used in management frames to indicate why an  * action took place (e.g. on disassociation).  Status codes are  * used in management frames to indicate the result of an operation.  *  * Unlisted codes are reserved  */
end_comment

begin_enum
enum|enum
block|{
name|IEEE80211_REASON_UNSPECIFIED
init|=
literal|1
block|,
name|IEEE80211_REASON_AUTH_EXPIRE
init|=
literal|2
block|,
name|IEEE80211_REASON_AUTH_LEAVE
init|=
literal|3
block|,
name|IEEE80211_REASON_ASSOC_EXPIRE
init|=
literal|4
block|,
name|IEEE80211_REASON_ASSOC_TOOMANY
init|=
literal|5
block|,
name|IEEE80211_REASON_NOT_AUTHED
init|=
literal|6
block|,
name|IEEE80211_REASON_NOT_ASSOCED
init|=
literal|7
block|,
name|IEEE80211_REASON_ASSOC_LEAVE
init|=
literal|8
block|,
name|IEEE80211_REASON_ASSOC_NOT_AUTHED
init|=
literal|9
block|,
name|IEEE80211_REASON_DISASSOC_PWRCAP_BAD
init|=
literal|10
block|,
comment|/* 11h */
name|IEEE80211_REASON_DISASSOC_SUPCHAN_BAD
init|=
literal|11
block|,
comment|/* 11h */
name|IEEE80211_REASON_IE_INVALID
init|=
literal|13
block|,
comment|/* 11i */
name|IEEE80211_REASON_MIC_FAILURE
init|=
literal|14
block|,
comment|/* 11i */
name|IEEE80211_REASON_4WAY_HANDSHAKE_TIMEOUT
init|=
literal|15
block|,
comment|/* 11i */
name|IEEE80211_REASON_GROUP_KEY_UPDATE_TIMEOUT
init|=
literal|16
block|,
comment|/* 11i */
name|IEEE80211_REASON_IE_IN_4WAY_DIFFERS
init|=
literal|17
block|,
comment|/* 11i */
name|IEEE80211_REASON_GROUP_CIPHER_INVALID
init|=
literal|18
block|,
comment|/* 11i */
name|IEEE80211_REASON_PAIRWISE_CIPHER_INVALID
init|=
literal|19
block|,
comment|/* 11i */
name|IEEE80211_REASON_AKMP_INVALID
init|=
literal|20
block|,
comment|/* 11i */
name|IEEE80211_REASON_UNSUPP_RSN_IE_VERSION
init|=
literal|21
block|,
comment|/* 11i */
name|IEEE80211_REASON_INVALID_RSN_IE_CAP
init|=
literal|22
block|,
comment|/* 11i */
name|IEEE80211_REASON_802_1X_AUTH_FAILED
init|=
literal|23
block|,
comment|/* 11i */
name|IEEE80211_REASON_CIPHER_SUITE_REJECTED
init|=
literal|24
block|,
comment|/* 11i */
name|IEEE80211_REASON_UNSPECIFIED_QOS
init|=
literal|32
block|,
comment|/* 11e */
name|IEEE80211_REASON_INSUFFICIENT_BW
init|=
literal|33
block|,
comment|/* 11e */
name|IEEE80211_REASON_TOOMANY_FRAMES
init|=
literal|34
block|,
comment|/* 11e */
name|IEEE80211_REASON_OUTSIDE_TXOP
init|=
literal|35
block|,
comment|/* 11e */
name|IEEE80211_REASON_LEAVING_QBSS
init|=
literal|36
block|,
comment|/* 11e */
name|IEEE80211_REASON_BAD_MECHANISM
init|=
literal|37
block|,
comment|/* 11e */
name|IEEE80211_REASON_SETUP_NEEDED
init|=
literal|38
block|,
comment|/* 11e */
name|IEEE80211_REASON_TIMEOUT
init|=
literal|39
block|,
comment|/* 11e */
comment|/* values not yet allocated by ANA */
name|IEEE80211_REASON_PEER_LINK_CANCELED
init|=
literal|2
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_MAX_PEERS
init|=
literal|3
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_CPVIOLATION
init|=
literal|4
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_CLOSE_RCVD
init|=
literal|5
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_MAX_RETRIES
init|=
literal|6
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_CONFIRM_TIMEOUT
init|=
literal|7
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_INVALID_GTK
init|=
literal|8
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_INCONS_PARAMS
init|=
literal|9
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_INVALID_SECURITY
init|=
literal|10
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_PERR_UNSPEC
init|=
literal|11
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_PERR_NO_FI
init|=
literal|12
block|,
comment|/* 11s */
name|IEEE80211_REASON_MESH_PERR_DEST_UNREACH
init|=
literal|13
block|,
comment|/* 11s */
name|IEEE80211_STATUS_SUCCESS
init|=
literal|0
block|,
name|IEEE80211_STATUS_UNSPECIFIED
init|=
literal|1
block|,
name|IEEE80211_STATUS_CAPINFO
init|=
literal|10
block|,
name|IEEE80211_STATUS_NOT_ASSOCED
init|=
literal|11
block|,
name|IEEE80211_STATUS_OTHER
init|=
literal|12
block|,
name|IEEE80211_STATUS_ALG
init|=
literal|13
block|,
name|IEEE80211_STATUS_SEQUENCE
init|=
literal|14
block|,
name|IEEE80211_STATUS_CHALLENGE
init|=
literal|15
block|,
name|IEEE80211_STATUS_TIMEOUT
init|=
literal|16
block|,
name|IEEE80211_STATUS_TOOMANY
init|=
literal|17
block|,
name|IEEE80211_STATUS_BASIC_RATE
init|=
literal|18
block|,
name|IEEE80211_STATUS_SP_REQUIRED
init|=
literal|19
block|,
comment|/* 11b */
name|IEEE80211_STATUS_PBCC_REQUIRED
init|=
literal|20
block|,
comment|/* 11b */
name|IEEE80211_STATUS_CA_REQUIRED
init|=
literal|21
block|,
comment|/* 11b */
name|IEEE80211_STATUS_SPECMGMT_REQUIRED
init|=
literal|22
block|,
comment|/* 11h */
name|IEEE80211_STATUS_PWRCAP_REQUIRED
init|=
literal|23
block|,
comment|/* 11h */
name|IEEE80211_STATUS_SUPCHAN_REQUIRED
init|=
literal|24
block|,
comment|/* 11h */
name|IEEE80211_STATUS_SHORTSLOT_REQUIRED
init|=
literal|25
block|,
comment|/* 11g */
name|IEEE80211_STATUS_DSSSOFDM_REQUIRED
init|=
literal|26
block|,
comment|/* 11g */
name|IEEE80211_STATUS_MISSING_HT_CAPS
init|=
literal|27
block|,
comment|/* 11n D3.0 */
name|IEEE80211_STATUS_INVALID_IE
init|=
literal|40
block|,
comment|/* 11i */
name|IEEE80211_STATUS_GROUP_CIPHER_INVALID
init|=
literal|41
block|,
comment|/* 11i */
name|IEEE80211_STATUS_PAIRWISE_CIPHER_INVALID
init|=
literal|42
block|,
comment|/* 11i */
name|IEEE80211_STATUS_AKMP_INVALID
init|=
literal|43
block|,
comment|/* 11i */
name|IEEE80211_STATUS_UNSUPP_RSN_IE_VERSION
init|=
literal|44
block|,
comment|/* 11i */
name|IEEE80211_STATUS_INVALID_RSN_IE_CAP
init|=
literal|45
block|,
comment|/* 11i */
name|IEEE80211_STATUS_CIPHER_SUITE_REJECTED
init|=
literal|46
block|,
comment|/* 11i */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IEEE80211_WEP_KEYLEN
value|5
end_define

begin_comment
comment|/* 40bit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_IVLEN
value|3
end_define

begin_comment
comment|/* 24bit */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_KIDLEN
value|1
end_define

begin_comment
comment|/* 1 octet */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_CRCLEN
value|4
end_define

begin_comment
comment|/* CRC-32 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_TOTLEN
value|(IEEE80211_WEP_IVLEN + \ 					 IEEE80211_WEP_KIDLEN + \ 					 IEEE80211_WEP_CRCLEN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_NKID
value|4
end_define

begin_comment
comment|/* number of key ids */
end_comment

begin_comment
comment|/*  * 802.11i defines an extended IV for use with non-WEP ciphers.  * When the EXTIV bit is set in the key id byte an additional  * 4 bytes immediately follow the IV for TKIP.  For CCMP the  * EXTIV bit is likewise set but the 8 bytes represent the  * CCMP header rather than IV+extended-IV.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_EXTIV
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_EXTIVLEN
value|4
end_define

begin_comment
comment|/* extended IV length */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_WEP_MICLEN
value|8
end_define

begin_comment
comment|/* trailing MIC */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CRC_LEN
value|4
end_define

begin_comment
comment|/*  * Maximum acceptable MTU is:  *	IEEE80211_MAX_LEN - WEP overhead - CRC -  *		QoS overhead - RSN/WPA overhead  * Min is arbitrarily chosen> IEEE80211_MIN_LEN.  The default  * mtu is Ethernet-compatible; it's set by ether_ifattach.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_MTU_MAX
value|2290
end_define

begin_define
define|#
directive|define
name|IEEE80211_MTU_MIN
value|32
end_define

begin_define
define|#
directive|define
name|IEEE80211_MAX_LEN
value|(2300 + IEEE80211_CRC_LEN + \     (IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN + IEEE80211_WEP_CRCLEN))
end_define

begin_define
define|#
directive|define
name|IEEE80211_ACK_LEN
define|\
value|(sizeof(struct ieee80211_frame_ack) + IEEE80211_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_MIN_LEN
define|\
value|(sizeof(struct ieee80211_frame_min) + IEEE80211_CRC_LEN)
end_define

begin_comment
comment|/*  * The 802.11 spec says at most 2007 stations may be  * associated at once.  For most AP's this is way more  * than is feasible so we use a default of IEEE80211_AID_DEF.  * This number may be overridden by the driver and/or by  * user configuration but may not be less than IEEE80211_AID_MIN  * (see _ieee80211.h for implementation-specific settings).  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_AID_MAX
value|2007
end_define

begin_define
define|#
directive|define
name|IEEE80211_AID
parameter_list|(
name|b
parameter_list|)
value|((b)&~ 0xc000)
end_define

begin_comment
comment|/*   * RTS frame length parameters.  The default is specified in  * the 802.11 spec as 512; we treat it as implementation-dependent  * so it's defined in ieee80211_var.h.  The max may be wrong  * for jumbo frames.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RTS_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RTS_MAX
value|2346
end_define

begin_comment
comment|/*   * TX fragmentation parameters.  As above for RTS, we treat  * default as implementation-dependent so define it elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FRAG_MIN
value|256
end_define

begin_define
define|#
directive|define
name|IEEE80211_FRAG_MAX
value|2346
end_define

begin_comment
comment|/*  * Beacon interval (TU's).  Min+max come from WiFi requirements.  * As above, we treat default as implementation-dependent so  * define it elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BINTVAL_MAX
value|1000
end_define

begin_comment
comment|/* max beacon interval (TU's) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_BINTVAL_MIN
value|25
end_define

begin_comment
comment|/* min beacon interval (TU's) */
end_comment

begin_comment
comment|/*  * DTIM period (beacons).  Min+max are not really defined  * by the protocol but we want them publicly visible so  * define them here.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DTIM_MAX
value|15
end_define

begin_comment
comment|/* max DTIM period */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DTIM_MIN
value|1
end_define

begin_comment
comment|/* min DTIM period */
end_comment

begin_comment
comment|/*  * Beacon miss threshold (beacons).  As for DTIM, we define  * them here to be publicly visible.  Note the max may be  * clamped depending on device capabilities.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HWBMISS_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_HWBMISS_MAX
value|255
end_define

begin_comment
comment|/*  * 802.11 frame duration definitions.  */
end_comment

begin_struct
struct|struct
name|ieee80211_duration
block|{
name|uint16_t
name|d_rts_dur
decl_stmt|;
name|uint16_t
name|d_data_dur
decl_stmt|;
name|uint16_t
name|d_plcp_len
decl_stmt|;
name|uint8_t
name|d_residue
decl_stmt|;
comment|/* unused octets in time slot */
block|}
struct|;
end_struct

begin_comment
comment|/* One Time Unit (TU) is 1Kus = 1024 microseconds. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_TU
value|1024
end_define

begin_comment
comment|/* IEEE 802.11b durations for DSSS PHY in microseconds */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_LONG_PREAMBLE
value|144
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SHORT_PREAMBLE
value|72
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SLOW_PLCPHDR
value|48
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_FAST_PLCPHDR
value|24
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SLOW_ACK
value|112
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_FAST_ACK
value|56
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SLOW_CTS
value|112
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_FAST_CTS
value|56
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SLOT
value|20
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_SIFS
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_PIFS
value|(IEEE80211_DUR_DS_SIFS + IEEE80211_DUR_DS_SLOT)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_DIFS
value|(IEEE80211_DUR_DS_SIFS + \ 				 2 * IEEE80211_DUR_DS_SLOT)
end_define

begin_define
define|#
directive|define
name|IEEE80211_DUR_DS_EIFS
value|(IEEE80211_DUR_DS_SIFS + \ 				 IEEE80211_DUR_DS_SLOW_ACK + \ 				 IEEE80211_DUR_DS_LONG_PREAMBLE + \ 				 IEEE80211_DUR_DS_SLOW_PLCPHDR + \ 				 IEEE80211_DUR_DIFS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_H_ */
end_comment

end_unit

