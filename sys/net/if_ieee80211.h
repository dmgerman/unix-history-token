begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_ieee80211.h,v 1.23 2002/10/15 08:51:50 onoe Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_IEEE80211_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_IEEE80211_H_
end_define

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_define
define|#
directive|define
name|IEEE80211_ADDR_LEN
value|ETHER_ADDR_LEN
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_SSID
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_RATES
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_FHPARMS
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_DSPARMS
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_CFPARMS
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_TIM
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_IBSSPARMS
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_ELEMID_CHALLENGE
value|16
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

begin_define
define|#
directive|define
name|IEEE80211_AUTH_OPEN_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_OPEN_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_SHARED_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_SHARED_CHALLENGE
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_SHARED_RESPONSE
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_SHARED_PASS
value|4
end_define

begin_comment
comment|/*  * Reason codes  *  * Unlisted codes are reserved  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_REASON_UNSPECIFIED
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_AUTH_EXPIRE
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_AUTH_LEAVE
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_ASSOC_EXPIRE
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_ASSOC_TOOMANY
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_NOT_AUTHED
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_NOT_ASSOCED
value|7
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_ASSOC_LEAVE
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_REASON_ASSOC_NOT_AUTHED
value|9
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_UNSPECIFIED
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_CAPINFO
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_NOT_ASSOCED
value|11
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_OTHER
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_ALG
value|13
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_SEQUENCE
value|14
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_CHALLENGE
value|15
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_TOOMANY
value|17
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_BASIC_RATE
value|18
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_SP_REQUIRED
value|19
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_PBCC_REQUIRED
value|20
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_CA_REQUIRED
value|21
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_TOO_MANY_STATIONS
value|22
end_define

begin_define
define|#
directive|define
name|IEEE80211_STATUS_RATES
value|23
end_define

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
comment|/*  * ioctls  */
end_comment

begin_comment
comment|/* nwid is pointed at by ifr.ifr_data */
end_comment

begin_struct
struct|struct
name|ieee80211_nwid
block|{
name|u_int8_t
name|i_len
decl_stmt|;
name|u_int8_t
name|i_nwid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCS80211NWID
value|_IOWR('i', 230, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCG80211NWID
value|_IOWR('i', 231, struct ifreq)
end_define

begin_comment
comment|/* the first member must be matched with struct ifreq */
end_comment

begin_struct
struct|struct
name|ieee80211_nwkey
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|int
name|i_wepon
decl_stmt|;
comment|/* wep enabled flag */
name|int
name|i_defkid
decl_stmt|;
comment|/* default encrypt key id */
struct|struct
block|{
name|int
name|i_keylen
decl_stmt|;
name|u_int8_t
modifier|*
name|i_keydat
decl_stmt|;
block|}
name|i_key
index|[
name|IEEE80211_WEP_NKID
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCS80211NWKEY
value|_IOW('i', 232, struct ieee80211_nwkey)
end_define

begin_define
define|#
directive|define
name|SIOCG80211NWKEY
value|_IOWR('i', 233, struct ieee80211_nwkey)
end_define

begin_comment
comment|/* i_wepon */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NWKEY_OPEN
value|0
end_define

begin_comment
comment|/* No privacy */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NWKEY_WEP
value|1
end_define

begin_comment
comment|/* WEP enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NWKEY_EAP
value|2
end_define

begin_comment
comment|/* EAP enabled */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NWKEY_PERSIST
value|0x100
end_define

begin_comment
comment|/* designate persist keyset */
end_comment

begin_comment
comment|/* power management parameters */
end_comment

begin_struct
struct|struct
name|ieee80211_power
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|int
name|i_enabled
decl_stmt|;
comment|/* 1 == on, 0 == off */
name|int
name|i_maxsleep
decl_stmt|;
comment|/* max sleep in ms */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|SIOCS80211POWER
value|_IOW('i', 234, struct ieee80211_power)
end_define

begin_define
define|#
directive|define
name|SIOCG80211POWER
value|_IOWR('i', 235, struct ieee80211_power)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCS80211POWER
value|_IOW('i', 242, struct ieee80211_power)
end_define

begin_define
define|#
directive|define
name|SIOCG80211POWER
value|_IOWR('i', 243, struct ieee80211_power)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ieee80211_auth
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|int
name|i_authtype
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_AUTH_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_AUTH_SHARED
value|2
end_define

begin_define
define|#
directive|define
name|SIOCS80211AUTH
value|_IOW('i', 236, struct ieee80211_auth)
end_define

begin_define
define|#
directive|define
name|SIOCG80211AUTH
value|_IOWR('i', 237, struct ieee80211_auth)
end_define

begin_struct
struct|struct
name|ieee80211_channel
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|u_int16_t
name|i_channel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_CHAN_ANY
value|0xffff
end_define

begin_define
define|#
directive|define
name|SIOCS80211CHANNEL
value|_IOW('i', 238, struct ieee80211_channel)
end_define

begin_define
define|#
directive|define
name|SIOCG80211CHANNEL
value|_IOWR('i', 239, struct ieee80211_channel)
end_define

begin_struct
struct|struct
name|ieee80211_bssid
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|u_int8_t
name|i_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCS80211BSSID
value|_IOW('i', 240, struct ieee80211_bssid)
end_define

begin_define
define|#
directive|define
name|SIOCG80211BSSID
value|_IOWR('i', 241, struct ieee80211_bssid)
end_define

begin_comment
comment|/*  * FreeBSD-style ioctls.  */
end_comment

begin_comment
comment|/* the first member must be matched with struct ifreq */
end_comment

begin_struct
struct|struct
name|ieee80211req
block|{
name|char
name|i_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if_name, e.g. "wi0" */
name|u_int16_t
name|i_type
decl_stmt|;
comment|/* req type */
name|int16_t
name|i_val
decl_stmt|;
comment|/* Index or simple value */
name|int16_t
name|i_len
decl_stmt|;
comment|/* Index or simple value */
name|void
modifier|*
name|i_data
decl_stmt|;
comment|/* Extra data */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|SIOCS80211
value|_IOW('i', 234, struct ieee80211req)
end_define

begin_define
define|#
directive|define
name|SIOCG80211
value|_IOWR('i', 235, struct ieee80211req)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCS80211
value|_IOW('i', 242, struct ieee80211req)
end_define

begin_define
define|#
directive|define
name|SIOCG80211
value|_IOWR('i', 243, struct ieee80211req)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IEEE80211_IOC_SSID
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_NUMSSIDS
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEP
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_NOSUP
value|-1
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_OFF
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_ON
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_WEP_MIXED
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEPKEY
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_NUMWEPKEYS
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_WEPTXKEY
value|6
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_AUTHMODE
value|7
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_STATIONNAME
value|8
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_CHANNEL
value|9
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_POWERSAVE
value|10
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_NOSUP
value|-1
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_CAM
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_PSP
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_PSP_CAM
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_POWERSAVE_ON
value|IEEE80211_POWERSAVE_CAM
end_define

begin_define
define|#
directive|define
name|IEEE80211_IOC_POWERSAVESLEEP
value|11
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IEEE80211_ASCAN_WAIT
value|2
end_define

begin_comment
comment|/* active scan wait */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_PSCAN_WAIT
value|5
end_define

begin_comment
comment|/* passive scan wait */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_TRANS_WAIT
value|5
end_define

begin_comment
comment|/* transition wait */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_WAIT
value|5
end_define

begin_comment
comment|/* inactivity timer interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_MAX
value|(300/IEEE80211_INACT_WAIT)
end_define

begin_comment
comment|/*  * Structure for IEEE 802.11 drivers.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IEEE80211_RATE_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|IEEE80211_KEYBUF_SIZE
value|16
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
value|(((u_int8_t *)(addr))[IEEE80211_ADDR_LEN - 1] % IEEE80211_NODE_HASHSIZE)
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
name|IEEE80211_T_HRDS
comment|/* high rate DS */
block|}
enum|;
end_enum

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
comment|/* Software Access Point */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ieee80211_state
block|{
name|IEEE80211_S_INIT
block|,
comment|/* default state */
name|IEEE80211_S_SCAN
block|,
comment|/* scanning */
name|IEEE80211_S_AUTH
block|,
comment|/* try to authenticate */
name|IEEE80211_S_ASSOC
block|,
comment|/* try to assoc */
name|IEEE80211_S_RUN
comment|/* associated */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Node specific information.  */
end_comment

begin_struct
struct|struct
name|ieee80211_node
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_hash
expr_stmt|;
comment|/* hardware */
name|u_int8_t
name|ni_rssi
decl_stmt|;
name|u_int32_t
name|ni_rstamp
decl_stmt|;
comment|/* header */
name|u_int8_t
name|ni_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ni_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* beacon, probe response */
name|u_int8_t
name|ni_tstamp
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|ni_intval
decl_stmt|;
name|u_int16_t
name|ni_capinfo
decl_stmt|;
name|u_int8_t
name|ni_esslen
decl_stmt|;
name|u_int8_t
name|ni_essid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|int
name|ni_nrate
decl_stmt|;
name|u_int8_t
name|ni_rates
index|[
name|IEEE80211_RATE_SIZE
index|]
decl_stmt|;
name|u_int8_t
name|ni_chan
decl_stmt|;
name|u_int16_t
name|ni_fhdwell
decl_stmt|;
comment|/* FH only */
name|u_int8_t
name|ni_fhindex
decl_stmt|;
comment|/* FH only */
comment|/* DTIM and contention free period (CFP) */
name|u_int8_t
name|ni_dtimperiod
decl_stmt|;
name|u_int8_t
name|ni_cfpperiod
decl_stmt|;
comment|/* # of DTIMs between CFPs */
name|u_int16_t
name|ni_cfpmaxduration
decl_stmt|;
comment|/* max CFP duration in TU */
name|u_int16_t
name|ni_cfpduremain
decl_stmt|;
comment|/* remaining duration */
name|u_int16_t
name|ni_timoffset
decl_stmt|;
comment|/* others */
name|u_int16_t
name|ni_associd
decl_stmt|;
comment|/* assoc response */
name|u_int16_t
name|ni_txseq
decl_stmt|;
comment|/* seq to be transmitted */
name|u_int16_t
name|ni_rxseq
decl_stmt|;
comment|/* seq previous received */
name|int
name|ni_fails
decl_stmt|;
comment|/* failure count to associate */
name|int
name|ni_inact
decl_stmt|;
comment|/* inactivity mark count */
name|int
name|ni_txrate
decl_stmt|;
comment|/* index to ni_rates[] */
name|void
modifier|*
name|ni_private
decl_stmt|;
comment|/* driver private */
block|}
struct|;
end_struct

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
name|ieee80211_wepkey
block|{
name|int
name|wk_len
decl_stmt|;
name|u_int8_t
name|wk_key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211com
block|{
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|ethercom
name|ic_ec
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|arpcom
name|ic_ac
decl_stmt|;
name|struct
name|mtx
name|ic_mtx
decl_stmt|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|ic_recv_mgmt
index|[
literal|16
index|]
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
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_send_mgmt
index|[
literal|16
index|]
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
name|void
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ic_chancheck
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
name|u_int8_t
name|ic_myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ic_sup_rates
index|[
name|IEEE80211_RATE_SIZE
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
name|struct
name|ifqueue
name|ic_mgtq
decl_stmt|;
name|int
name|ic_flags
decl_stmt|;
name|enum
name|ieee80211_phytype
name|ic_phytype
decl_stmt|;
name|enum
name|ieee80211_opmode
name|ic_opmode
decl_stmt|;
name|enum
name|ieee80211_state
name|ic_state
decl_stmt|;
name|struct
name|bpf_if
modifier|*
name|ic_rawbpf
decl_stmt|;
comment|/* packet filter structure */
name|struct
name|ieee80211_node
name|ic_bss
decl_stmt|;
comment|/* information for this node */
name|int
name|ic_node_privlen
decl_stmt|;
comment|/* size for ni_private */
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
comment|/* callback */
name|u_int8_t
name|ic_ibss_chan
decl_stmt|;
name|int
name|ic_fixed_rate
decl_stmt|;
comment|/* index to ic_sup_rates[] */
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
name|int
name|ic_mgt_timer
decl_stmt|;
comment|/* mgmt timeout */
name|int
name|ic_scan_timer
decl_stmt|;
comment|/* scant wait */
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
name|int
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

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|ic_if
value|ic_ec.ec_if
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK
parameter_list|(
name|_ic
parameter_list|)
value|do { s = splnet(); } while (0)
end_define

begin_define
define|#
directive|define
name|IEEE80211_UNLOCK
parameter_list|(
name|_ic
parameter_list|)
value|splx(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|ic_if
value|ic_ac.ac_if
end_define

begin_define
define|#
directive|define
name|IEEE80211_LOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_lock(&(_ic)->ic_mtx)
end_define

begin_define
define|#
directive|define
name|IEEE80211_UNLOCK
parameter_list|(
name|_ic
parameter_list|)
value|mtx_unlock(&(_ic)->ic_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ic_softc
value|ic_if.if_softc
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEND_MGMT
parameter_list|(
name|ic
parameter_list|,
name|ni
parameter_list|,
name|type
parameter_list|,
name|arg
parameter_list|)
value|do {			      \ 	if ((ic)->ic_send_mgmt[(type)>>IEEE80211_FC0_SUBTYPE_SHIFT] != NULL)  \ 		(*(ic)->ic_send_mgmt[(type)>>IEEE80211_FC0_SUBTYPE_SHIFT])    \ 		    (ic,ni,type,arg);					      \ } while (0)
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

begin_define
define|#
directive|define
name|IEEE80211_IS_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|ETHER_IS_MULTICAST(a)
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
name|IEEE80211_F_HASWEP
value|0x00010000
end_define

begin_comment
comment|/* CAPABILITY: WEP available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_HASIBSS
value|0x00020000
end_define

begin_comment
comment|/* CAPABILITY: IBSS available */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_HASPMGT
value|0x00040000
end_define

begin_comment
comment|/* CAPABILITY: Power mgmt */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_HASHOSTAP
value|0x00080000
end_define

begin_comment
comment|/* CAPABILITY: HOSTAP avail */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_F_HASAHDEMO
value|0x00100000
end_define

begin_comment
comment|/* CAPABILITY: Old Adhoc Demo */
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
name|ieee80211_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_mgmt_output
parameter_list|(
name|struct
name|ifnet
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
name|int
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
name|ifnet
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
name|ieee80211_decap
parameter_list|(
name|struct
name|ifnet
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
name|void
name|ieee80211_print_essid
parameter_list|(
name|u_int8_t
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
name|u_int8_t
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
name|void
name|ieee80211_next_scan
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_end_scan
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_alloc_node
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|int
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
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_free_node
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
end_function_decl

begin_function_decl
name|void
name|ieee80211_free_allnodes
parameter_list|(
name|struct
name|ieee80211com
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
name|ieee80211_new_state
parameter_list|(
name|struct
name|ifnet
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
name|struct
name|mbuf
modifier|*
name|ieee80211_wep_crypt
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
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
name|int
parameter_list|,
name|enum
name|ieee80211_phytype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_media2rate
parameter_list|(
name|int
parameter_list|,
name|enum
name|ieee80211_phytype
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
comment|/* _NET_IF_IEEE80211_H_ */
end_comment

end_unit

