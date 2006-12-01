begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* IEEE 802.11 PLCP header */
end_comment

begin_struct
struct|struct
name|ieee80211_plcp_hdr
block|{
name|u_int16_t
name|i_sfd
decl_stmt|;
name|u_int8_t
name|i_signal
decl_stmt|;
name|u_int8_t
name|i_service
decl_stmt|;
name|u_int16_t
name|i_length
decl_stmt|;
name|u_int16_t
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

begin_comment
comment|/*  * generic definitions for IEEE 802.11 frames  */
end_comment

begin_struct
struct|struct
name|ieee80211_frame
block|{
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr2
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr3
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr4
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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

begin_comment
comment|/* for TYPE_CTL */
end_comment

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
name|IEEE80211_NWID_LEN
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
name|IEEE80211_QOS_ESOP
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ESOP_S
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
name|u_int8_t
name|wme_id
decl_stmt|;
comment|/* IEEE80211_ELEMID_VENDOR */
name|u_int8_t
name|wme_len
decl_stmt|;
comment|/* length in bytes */
name|u_int8_t
name|wme_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x00, 0x50, 0xf2 */
name|u_int8_t
name|wme_type
decl_stmt|;
comment|/* OUI type */
name|u_int8_t
name|wme_subtype
decl_stmt|;
comment|/* OUI subtype */
name|u_int8_t
name|wme_version
decl_stmt|;
comment|/* spec revision */
name|u_int8_t
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
name|u_int8_t
name|ts_id
decl_stmt|;
name|u_int8_t
name|ts_len
decl_stmt|;
name|u_int8_t
name|ts_oui
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|ts_oui_type
decl_stmt|;
name|u_int8_t
name|ts_oui_subtype
decl_stmt|;
name|u_int8_t
name|ts_version
decl_stmt|;
name|u_int8_t
name|ts_tsinfo
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|ts_nom_msdu
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|ts_max_msdu
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|ts_min_svc
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_max_svc
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_inactv_intv
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_susp_intv
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_start_svc
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_min_rate
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_mean_rate
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_max_burst
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_min_phy
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_peak_rate
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_delay
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ts_surplus
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|acp_aci_aifsn
decl_stmt|;
name|u_int8_t
name|acp_logcwminmax
decl_stmt|;
name|u_int16_t
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
value|(      \ 	((_tid)< 1) ? WME_AC_BE : \ 	((_tid)< 3) ? WME_AC_BK : \ 	((_tid)< 6) ? WME_AC_VI : \ 	WME_AC_VO)
end_define

begin_comment
comment|/*  * WME Parameter Element  */
end_comment

begin_struct
struct|struct
name|ieee80211_wme_param
block|{
name|u_int8_t
name|param_id
decl_stmt|;
name|u_int8_t
name|param_len
decl_stmt|;
name|u_int8_t
name|param_oui
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|param_oui_type
decl_stmt|;
name|u_int8_t
name|param_oui_sybtype
decl_stmt|;
name|u_int8_t
name|param_version
decl_stmt|;
name|u_int8_t
name|param_qosInfo
decl_stmt|;
define|#
directive|define
name|WME_QOSINFO_COUNT
value|0x0f
comment|/* Mask for param count field */
name|u_int8_t
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
name|u_int8_t
name|mnf_category
decl_stmt|;
name|u_int8_t
name|mnf_action
decl_stmt|;
name|u_int8_t
name|mnf_dialog
decl_stmt|;
name|u_int8_t
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
comment|/*  * Control frames.  */
end_comment

begin_struct
struct|struct
name|ieee80211_frame_min
block|{
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_addr1
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_aid
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|i_fc
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|i_dur
index|[
literal|2
index|]
decl_stmt|;
comment|/* should be zero */
name|u_int8_t
name|i_ra
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
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

begin_comment
comment|/*  * BEACON management packets  *  *	octet timestamp[8]  *	octet beacon interval[2]  *	octet capability information[2]  *	information element  *		octet elemid  *		octet length  *		octet information[length]  */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
modifier|*
name|ieee80211_mgt_beacon_t
typedef|;
end_typedef

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

begin_comment
comment|/* bits 8-9 are reserved */
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

begin_comment
comment|/*  * 802.11i/WPA information element (maximally sized).  */
end_comment

begin_struct
struct|struct
name|ieee80211_ie_wpa
block|{
name|u_int8_t
name|wpa_id
decl_stmt|;
comment|/* IEEE80211_ELEMID_VENDOR */
name|u_int8_t
name|wpa_len
decl_stmt|;
comment|/* length in bytes */
name|u_int8_t
name|wpa_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x00, 0x50, 0xf2 */
name|u_int8_t
name|wpa_type
decl_stmt|;
comment|/* OUI type */
name|u_int16_t
name|wpa_version
decl_stmt|;
comment|/* spec revision */
name|u_int32_t
name|wpa_mcipher
index|[
literal|1
index|]
decl_stmt|;
comment|/* multicast/group key cipher */
name|u_int16_t
name|wpa_uciphercnt
decl_stmt|;
comment|/* # pairwise key ciphers */
name|u_int32_t
name|wpa_uciphers
index|[
literal|8
index|]
decl_stmt|;
comment|/* ciphers */
name|u_int16_t
name|wpa_authselcnt
decl_stmt|;
comment|/* authentication selector cnt*/
name|u_int32_t
name|wpa_authsels
index|[
literal|8
index|]
decl_stmt|;
comment|/* selectors */
name|u_int16_t
name|wpa_caps
decl_stmt|;
comment|/* 802.11i capabilities */
name|u_int16_t
name|wpa_pmkidcnt
decl_stmt|;
comment|/* 802.11i pmkid count */
name|u_int16_t
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
name|IEEE80211_ELEMID_ERP
init|=
literal|42
block|,
name|IEEE80211_ELEMID_RSN
init|=
literal|48
block|,
name|IEEE80211_ELEMID_XRATES
init|=
literal|50
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
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211_tim_ie
block|{
name|u_int8_t
name|tim_ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_TIM */
name|u_int8_t
name|tim_len
decl_stmt|;
name|u_int8_t
name|tim_count
decl_stmt|;
comment|/* DTIM count */
name|u_int8_t
name|tim_period
decl_stmt|;
comment|/* DTIM period */
name|u_int8_t
name|tim_bitctl
decl_stmt|;
comment|/* bitmap control */
name|u_int8_t
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
name|u_int8_t
name|ie
decl_stmt|;
comment|/* IEEE80211_ELEMID_COUNTRY */
name|u_int8_t
name|len
decl_stmt|;
name|u_int8_t
name|cc
index|[
literal|3
index|]
decl_stmt|;
comment|/* ISO CC+(I)ndoor/(O)utdoor */
struct|struct
block|{
name|u_int8_t
name|schan
decl_stmt|;
comment|/* starting channel */
name|u_int8_t
name|nchan
decl_stmt|;
comment|/* number channels */
name|u_int8_t
name|maxtxpwr
decl_stmt|;
comment|/* tx power cap */
block|}
name|__packed
name|band
index|[
literal|4
index|]
struct|;
comment|/* up to 4 sub bands */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CHALLENGE_LEN
value|128
end_define

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

begin_comment
comment|/* Atheros private advanced capabilities info */
end_comment

begin_define
define|#
directive|define
name|ATHEROS_CAP_TURBO_PRIME
value|0x01
end_define

begin_define
define|#
directive|define
name|ATHEROS_CAP_COMPRESSION
value|0x02
end_define

begin_define
define|#
directive|define
name|ATHEROS_CAP_FAST_FRAME
value|0x04
end_define

begin_comment
comment|/* bits 3-6 reserved */
end_comment

begin_define
define|#
directive|define
name|ATHEROS_CAP_BOOST
value|0x80
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

begin_define
define|#
directive|define
name|ATH_OUI_VERSION
value|0x01
end_define

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
comment|/*  * AUTH management packets  *  *	octet algo[2]  *	octet seq[2]  *	octet status[2]  *	octet chal.id  *	octet chal.length  *	octet chal.text[253]  */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
modifier|*
name|ieee80211_mgt_auth_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IEEE80211_AUTH_ALGORITHM
parameter_list|(
name|auth
parameter_list|)
define|\
value|((auth)[0] | ((auth)[1]<< 8))
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_TRANSACTION
parameter_list|(
name|auth
parameter_list|)
define|\
value|((auth)[2] | ((auth)[3]<< 8))
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_STATUS
parameter_list|(
name|auth
parameter_list|)
define|\
value|((auth)[4] | ((auth)[5]<< 8))
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
comment|/*  * Reason codes  *  * Unlisted codes are reserved  */
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
name|IEEE80211_REASON_RSN_REQUIRED
init|=
literal|11
block|,
name|IEEE80211_REASON_RSN_INCONSISTENT
init|=
literal|12
block|,
name|IEEE80211_REASON_IE_INVALID
init|=
literal|13
block|,
name|IEEE80211_REASON_MIC_FAILURE
init|=
literal|14
block|,
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
name|IEEE80211_STATUS_PBCC_REQUIRED
init|=
literal|20
block|,
name|IEEE80211_STATUS_CA_REQUIRED
init|=
literal|21
block|,
name|IEEE80211_STATUS_TOO_MANY_STATIONS
init|=
literal|22
block|,
name|IEEE80211_STATUS_RATES
init|=
literal|23
block|,
name|IEEE80211_STATUS_SHORTSLOT_REQUIRED
init|=
literal|25
block|,
name|IEEE80211_STATUS_DSSSOFDM_REQUIRED
init|=
literal|26
block|, }
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
comment|/*  * The 802.11 spec says at most 2007 stations may be  * associated at once.  For most AP's this is way more  * than is feasible so we use a default of 128.  This  * number may be overridden by the driver and/or by  * user configuration.  */
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
name|IEEE80211_AID_DEF
value|128
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_H_ */
end_comment

end_unit

