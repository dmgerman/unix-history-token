begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
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

begin_comment
comment|/*  * BEACON management packets  *  *	octet timestamp[8]  *	octet beacon interval[2]  *	octet capability information[2]  *	information element  *		octet elemid  *		octet length  *		octet information[length]  */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
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

begin_comment
comment|/* bits 11-12 are reserved */
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
comment|/*  * Management information elements  */
end_comment

begin_struct
struct|struct
name|ieee80211_information
block|{
name|char
name|ssid
index|[
name|IEEE80211_NWID_LEN
operator|+
literal|1
index|]
decl_stmt|;
struct|struct
name|rates
block|{
name|u_int8_t
modifier|*
name|p
decl_stmt|;
block|}
name|rates
struct|;
struct|struct
name|fh
block|{
name|u_int16_t
name|dwell
decl_stmt|;
name|u_int8_t
name|set
decl_stmt|;
name|u_int8_t
name|pattern
decl_stmt|;
name|u_int8_t
name|index
decl_stmt|;
block|}
name|fh
struct|;
struct|struct
name|ds
block|{
name|u_int8_t
name|channel
decl_stmt|;
block|}
name|ds
struct|;
struct|struct
name|cf
block|{
name|u_int8_t
name|count
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|maxdur
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|dur
index|[
literal|2
index|]
decl_stmt|;
block|}
name|cf
struct|;
struct|struct
name|tim
block|{
name|u_int8_t
name|count
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|bitctl
decl_stmt|;
comment|/* u_int8_t	pvt[251]; The driver needs to use this. */
block|}
name|tim
struct|;
struct|struct
name|ibss
block|{
name|u_int16_t
name|atim
decl_stmt|;
block|}
name|ibss
struct|;
struct|struct
name|challenge
block|{
name|u_int8_t
modifier|*
name|p
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
block|}
name|challenge
struct|;
struct|struct
name|erp
block|{
name|u_int8_t
name|flags
decl_stmt|;
block|}
name|erp
struct|;
block|}
struct|;
end_struct

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
name|IEEE80211_ELEMID_ERP
init|=
literal|42
block|,
name|IEEE80211_ELEMID_XRATES
init|=
literal|50
block|, }
enum|;
end_enum

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
name|IEEE80211_ERP_BARKER_MODE
value|0x04
end_define

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

begin_define
define|#
directive|define
name|IEEE80211_CRC_LEN
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|IEEE80211_MAX_LEN
value|(2300 + IEEE80211_CRC_LEN + \     (IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN + IEEE80211_WEP_CRCLEN))
end_define

begin_comment
comment|/*   * RTS frame length parameters.  The default is specified in  * the 802.11 spec.  The max may be wrong for jumbo frames.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RTS_DEFAULT
value|512
end_define

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
value|IEEE80211_MAX_LEN
end_define

begin_enum
enum|enum
block|{
name|IEEE80211_AUTH_NONE
init|=
literal|0
block|,
name|IEEE80211_AUTH_OPEN
init|=
literal|1
block|,
name|IEEE80211_AUTH_SHARED
init|=
literal|2
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_H_ */
end_comment

end_unit

