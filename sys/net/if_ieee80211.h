begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_ieee80211.h,v 1.5 2000/07/21 04:47:40 onoe Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr2
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_addr3
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|i_seq
index|[
literal|2
index|]
decl_stmt|;
comment|/* possibly followed by addr4[ETHER_ADDR_LEN]; */
block|}
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
name|IEEE80211_FC0_SUBTYPE_NODATA
value|0x40
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

begin_comment
comment|/*  * Management Frames  */
end_comment

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
name|IEEE80211_CAPINFO_ESS
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_IBSS
value|0x02
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_CF_POLLABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_CF_POLLREQ
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAPINFO_PRIVACY
value|0x10
end_define

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
name|IEEE80211_NWID_LEN
value|32
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_IEEE80211_H_ */
end_comment

end_unit

