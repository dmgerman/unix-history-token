begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001  *	Fortress Technologies, Inc.  All rights reserved.  *      Charlie Lenahan (clenahan@fortresstech.com)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"cpack.h"
end_include

begin_comment
comment|/* Lengths of 802.11 header components. */
end_comment

begin_define
define|#
directive|define
name|IEEE802_11_FC_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_DUR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_DA_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE802_11_SA_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE802_11_BSSID_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE802_11_RA_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE802_11_TA_LEN
value|6
end_define

begin_define
define|#
directive|define
name|IEEE802_11_SEQ_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_CTL_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_IV_LEN
value|3
end_define

begin_define
define|#
directive|define
name|IEEE802_11_KID_LEN
value|1
end_define

begin_comment
comment|/* Frame check sequence length. */
end_comment

begin_define
define|#
directive|define
name|IEEE802_11_FCS_LEN
value|4
end_define

begin_comment
comment|/* Lengths of beacon components. */
end_comment

begin_define
define|#
directive|define
name|IEEE802_11_TSTAMP_LEN
value|8
end_define

begin_define
define|#
directive|define
name|IEEE802_11_BCNINT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_CAPINFO_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_LISTENINT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_AID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_STATUS_LEN
value|2
end_define

begin_define
define|#
directive|define
name|IEEE802_11_REASON_LEN
value|2
end_define

begin_comment
comment|/* Length of previous AP in reassocation frame */
end_comment

begin_define
define|#
directive|define
name|IEEE802_11_AP_LEN
value|6
end_define

begin_define
define|#
directive|define
name|T_MGMT
value|0x0
end_define

begin_comment
comment|/* management */
end_comment

begin_define
define|#
directive|define
name|T_CTRL
value|0x1
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|T_DATA
value|0x2
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|T_RESV
value|0x3
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ST_ASSOC_REQUEST
value|0x0
end_define

begin_define
define|#
directive|define
name|ST_ASSOC_RESPONSE
value|0x1
end_define

begin_define
define|#
directive|define
name|ST_REASSOC_REQUEST
value|0x2
end_define

begin_define
define|#
directive|define
name|ST_REASSOC_RESPONSE
value|0x3
end_define

begin_define
define|#
directive|define
name|ST_PROBE_REQUEST
value|0x4
end_define

begin_define
define|#
directive|define
name|ST_PROBE_RESPONSE
value|0x5
end_define

begin_comment
comment|/* RESERVED 			0x6  */
end_comment

begin_comment
comment|/* RESERVED 			0x7  */
end_comment

begin_define
define|#
directive|define
name|ST_BEACON
value|0x8
end_define

begin_define
define|#
directive|define
name|ST_ATIM
value|0x9
end_define

begin_define
define|#
directive|define
name|ST_DISASSOC
value|0xA
end_define

begin_define
define|#
directive|define
name|ST_AUTH
value|0xB
end_define

begin_define
define|#
directive|define
name|ST_DEAUTH
value|0xC
end_define

begin_define
define|#
directive|define
name|ST_ACTION
value|0xD
end_define

begin_comment
comment|/* RESERVED 			0xE  */
end_comment

begin_comment
comment|/* RESERVED 			0xF  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|st_str
index|[]
init|=
block|{
block|{
name|ST_ASSOC_REQUEST
block|,
literal|"Assoc Request"
block|}
block|,
block|{
name|ST_ASSOC_RESPONSE
block|,
literal|"Assoc Response"
block|}
block|,
block|{
name|ST_REASSOC_REQUEST
block|,
literal|"ReAssoc Request"
block|}
block|,
block|{
name|ST_REASSOC_RESPONSE
block|,
literal|"ReAssoc Response"
block|}
block|,
block|{
name|ST_PROBE_REQUEST
block|,
literal|"Probe Request"
block|}
block|,
block|{
name|ST_PROBE_RESPONSE
block|,
literal|"Probe Response"
block|}
block|,
block|{
name|ST_BEACON
block|,
literal|"Beacon"
block|}
block|,
block|{
name|ST_ATIM
block|,
literal|"ATIM"
block|}
block|,
block|{
name|ST_DISASSOC
block|,
literal|"Disassociation"
block|}
block|,
block|{
name|ST_AUTH
block|,
literal|"Authentication"
block|}
block|,
block|{
name|ST_DEAUTH
block|,
literal|"DeAuthentication"
block|}
block|,
block|{
name|ST_ACTION
block|,
literal|"Action"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CTRL_CONTROL_WRAPPER
value|0x7
end_define

begin_define
define|#
directive|define
name|CTRL_BAR
value|0x8
end_define

begin_define
define|#
directive|define
name|CTRL_BA
value|0x9
end_define

begin_define
define|#
directive|define
name|CTRL_PS_POLL
value|0xA
end_define

begin_define
define|#
directive|define
name|CTRL_RTS
value|0xB
end_define

begin_define
define|#
directive|define
name|CTRL_CTS
value|0xC
end_define

begin_define
define|#
directive|define
name|CTRL_ACK
value|0xD
end_define

begin_define
define|#
directive|define
name|CTRL_CF_END
value|0xE
end_define

begin_define
define|#
directive|define
name|CTRL_END_ACK
value|0xF
end_define

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|ctrl_str
index|[]
init|=
block|{
block|{
name|CTRL_CONTROL_WRAPPER
block|,
literal|"Control Wrapper"
block|}
block|,
block|{
name|CTRL_BAR
block|,
literal|"BAR"
block|}
block|,
block|{
name|CTRL_BA
block|,
literal|"BA"
block|}
block|,
block|{
name|CTRL_PS_POLL
block|,
literal|"Power Save-Poll"
block|}
block|,
block|{
name|CTRL_RTS
block|,
literal|"Request-To-Send"
block|}
block|,
block|{
name|CTRL_CTS
block|,
literal|"Clear-To-Send"
block|}
block|,
block|{
name|CTRL_ACK
block|,
literal|"Acknowledgment"
block|}
block|,
block|{
name|CTRL_CF_END
block|,
literal|"CF-End"
block|}
block|,
block|{
name|CTRL_END_ACK
block|,
literal|"CF-End+CF-Ack"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DATA_DATA
value|0x0
end_define

begin_define
define|#
directive|define
name|DATA_DATA_CF_ACK
value|0x1
end_define

begin_define
define|#
directive|define
name|DATA_DATA_CF_POLL
value|0x2
end_define

begin_define
define|#
directive|define
name|DATA_DATA_CF_ACK_POLL
value|0x3
end_define

begin_define
define|#
directive|define
name|DATA_NODATA
value|0x4
end_define

begin_define
define|#
directive|define
name|DATA_NODATA_CF_ACK
value|0x5
end_define

begin_define
define|#
directive|define
name|DATA_NODATA_CF_POLL
value|0x6
end_define

begin_define
define|#
directive|define
name|DATA_NODATA_CF_ACK_POLL
value|0x7
end_define

begin_define
define|#
directive|define
name|DATA_QOS_DATA
value|0x8
end_define

begin_define
define|#
directive|define
name|DATA_QOS_DATA_CF_ACK
value|0x9
end_define

begin_define
define|#
directive|define
name|DATA_QOS_DATA_CF_POLL
value|0xA
end_define

begin_define
define|#
directive|define
name|DATA_QOS_DATA_CF_ACK_POLL
value|0xB
end_define

begin_define
define|#
directive|define
name|DATA_QOS_NODATA
value|0xC
end_define

begin_define
define|#
directive|define
name|DATA_QOS_CF_POLL_NODATA
value|0xE
end_define

begin_define
define|#
directive|define
name|DATA_QOS_CF_ACK_POLL_NODATA
value|0xF
end_define

begin_comment
comment|/*  * The subtype field of a data frame is, in effect, composed of 4 flag  * bits - CF-Ack, CF-Poll, Null (means the frame doesn't actually have  * any data), and QoS.  */
end_comment

begin_define
define|#
directive|define
name|DATA_FRAME_IS_CF_ACK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x01)
end_define

begin_define
define|#
directive|define
name|DATA_FRAME_IS_CF_POLL
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x02)
end_define

begin_define
define|#
directive|define
name|DATA_FRAME_IS_NULL
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x04)
end_define

begin_define
define|#
directive|define
name|DATA_FRAME_IS_QOS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x08)
end_define

begin_comment
comment|/*  * Bits in the frame control field.  */
end_comment

begin_define
define|#
directive|define
name|FC_VERSION
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x3)
end_define

begin_define
define|#
directive|define
name|FC_TYPE
parameter_list|(
name|fc
parameter_list|)
value|(((fc)>> 2)& 0x3)
end_define

begin_define
define|#
directive|define
name|FC_SUBTYPE
parameter_list|(
name|fc
parameter_list|)
value|(((fc)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|FC_TO_DS
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x0100)
end_define

begin_define
define|#
directive|define
name|FC_FROM_DS
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x0200)
end_define

begin_define
define|#
directive|define
name|FC_MORE_FLAG
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x0400)
end_define

begin_define
define|#
directive|define
name|FC_RETRY
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x0800)
end_define

begin_define
define|#
directive|define
name|FC_POWER_MGMT
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x1000)
end_define

begin_define
define|#
directive|define
name|FC_MORE_DATA
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x2000)
end_define

begin_define
define|#
directive|define
name|FC_WEP
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x4000)
end_define

begin_define
define|#
directive|define
name|FC_ORDER
parameter_list|(
name|fc
parameter_list|)
value|((fc)& 0x8000)
end_define

begin_struct
struct|struct
name|mgmt_header_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|da
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|sa
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|seq_ctrl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MGMT_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\ 			 IEEE802_11_DA_LEN+IEEE802_11_SA_LEN+\ 			 IEEE802_11_BSSID_LEN+IEEE802_11_SEQ_LEN)
end_define

begin_define
define|#
directive|define
name|CAPABILITY_ESS
parameter_list|(
name|cap
parameter_list|)
value|((cap)& 0x0001)
end_define

begin_define
define|#
directive|define
name|CAPABILITY_IBSS
parameter_list|(
name|cap
parameter_list|)
value|((cap)& 0x0002)
end_define

begin_define
define|#
directive|define
name|CAPABILITY_CFP
parameter_list|(
name|cap
parameter_list|)
value|((cap)& 0x0004)
end_define

begin_define
define|#
directive|define
name|CAPABILITY_CFP_REQ
parameter_list|(
name|cap
parameter_list|)
value|((cap)& 0x0008)
end_define

begin_define
define|#
directive|define
name|CAPABILITY_PRIVACY
parameter_list|(
name|cap
parameter_list|)
value|((cap)& 0x0010)
end_define

begin_struct
struct|struct
name|ssid_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|u_char
name|ssid
index|[
literal|33
index|]
decl_stmt|;
comment|/* 32 + 1 for null */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rates_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|rate
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|challenge_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|text
index|[
literal|254
index|]
decl_stmt|;
comment|/* 1-253 + 1 for null */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fh_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint16_t
name|dwell_time
decl_stmt|;
name|uint8_t
name|hop_set
decl_stmt|;
name|uint8_t
name|hop_pattern
decl_stmt|;
name|uint8_t
name|hop_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|channel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cf_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|count
decl_stmt|;
name|uint8_t
name|period
decl_stmt|;
name|uint16_t
name|max_duration
decl_stmt|;
name|uint16_t
name|dur_remaing
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tim_t
block|{
name|uint8_t
name|element_id
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|count
decl_stmt|;
name|uint8_t
name|period
decl_stmt|;
name|uint8_t
name|bitmap_control
decl_stmt|;
name|uint8_t
name|bitmap
index|[
literal|251
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E_SSID
value|0
end_define

begin_define
define|#
directive|define
name|E_RATES
value|1
end_define

begin_define
define|#
directive|define
name|E_FH
value|2
end_define

begin_define
define|#
directive|define
name|E_DS
value|3
end_define

begin_define
define|#
directive|define
name|E_CF
value|4
end_define

begin_define
define|#
directive|define
name|E_TIM
value|5
end_define

begin_define
define|#
directive|define
name|E_IBSS
value|6
end_define

begin_comment
comment|/* reserved 		7 */
end_comment

begin_comment
comment|/* reserved 		8 */
end_comment

begin_comment
comment|/* reserved 		9 */
end_comment

begin_comment
comment|/* reserved 		10 */
end_comment

begin_comment
comment|/* reserved 		11 */
end_comment

begin_comment
comment|/* reserved 		12 */
end_comment

begin_comment
comment|/* reserved 		13 */
end_comment

begin_comment
comment|/* reserved 		14 */
end_comment

begin_comment
comment|/* reserved 		15 */
end_comment

begin_comment
comment|/* reserved 		16 */
end_comment

begin_define
define|#
directive|define
name|E_CHALLENGE
value|16
end_define

begin_comment
comment|/* reserved 		17 */
end_comment

begin_comment
comment|/* reserved 		18 */
end_comment

begin_comment
comment|/* reserved 		19 */
end_comment

begin_comment
comment|/* reserved 		16 */
end_comment

begin_comment
comment|/* reserved 		16 */
end_comment

begin_struct
struct|struct
name|mgmt_body_t
block|{
name|uint8_t
name|timestamp
index|[
name|IEEE802_11_TSTAMP_LEN
index|]
decl_stmt|;
name|uint16_t
name|beacon_interval
decl_stmt|;
name|uint16_t
name|listen_interval
decl_stmt|;
name|uint16_t
name|status_code
decl_stmt|;
name|uint16_t
name|aid
decl_stmt|;
name|u_char
name|ap
index|[
name|IEEE802_11_AP_LEN
index|]
decl_stmt|;
name|uint16_t
name|reason_code
decl_stmt|;
name|uint16_t
name|auth_alg
decl_stmt|;
name|uint16_t
name|auth_trans_seq_num
decl_stmt|;
name|int
name|challenge_present
decl_stmt|;
name|struct
name|challenge_t
name|challenge
decl_stmt|;
name|uint16_t
name|capability_info
decl_stmt|;
name|int
name|ssid_present
decl_stmt|;
name|struct
name|ssid_t
name|ssid
decl_stmt|;
name|int
name|rates_present
decl_stmt|;
name|struct
name|rates_t
name|rates
decl_stmt|;
name|int
name|ds_present
decl_stmt|;
name|struct
name|ds_t
name|ds
decl_stmt|;
name|int
name|cf_present
decl_stmt|;
name|struct
name|cf_t
name|cf
decl_stmt|;
name|int
name|fh_present
decl_stmt|;
name|struct
name|fh_t
name|fh
decl_stmt|;
name|int
name|tim_present
decl_stmt|;
name|struct
name|tim_t
name|tim
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctrl_rts_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|ta
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_RTS_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\ 			 IEEE802_11_RA_LEN+IEEE802_11_TA_LEN)
end_define

begin_struct
struct|struct
name|ctrl_cts_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_CTS_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+IEEE802_11_RA_LEN)
end_define

begin_struct
struct|struct
name|ctrl_ack_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_ACK_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+IEEE802_11_RA_LEN)
end_define

begin_struct
struct|struct
name|ctrl_ps_poll_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|aid
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|ta
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_PS_POLL_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_AID_LEN+\ 				 IEEE802_11_BSSID_LEN+IEEE802_11_TA_LEN)
end_define

begin_struct
struct|struct
name|ctrl_end_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_END_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\ 			 IEEE802_11_RA_LEN+IEEE802_11_BSSID_LEN)
end_define

begin_struct
struct|struct
name|ctrl_end_ack_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_END_ACK_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\ 				 IEEE802_11_RA_LEN+IEEE802_11_BSSID_LEN)
end_define

begin_struct
struct|struct
name|ctrl_ba_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_BA_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+IEEE802_11_RA_LEN)
end_define

begin_struct
struct|struct
name|ctrl_bar_t
block|{
name|uint16_t
name|fc
decl_stmt|;
name|uint16_t
name|dur
decl_stmt|;
name|uint8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|ta
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|ctl
decl_stmt|;
name|uint16_t
name|seq
decl_stmt|;
name|uint8_t
name|fcs
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTRL_BAR_HDRLEN
value|(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\ 				 IEEE802_11_RA_LEN+IEEE802_11_TA_LEN+\ 				 IEEE802_11_CTL_LEN+IEEE802_11_SEQ_LEN)
end_define

begin_struct
struct|struct
name|meshcntl_t
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|ttl
decl_stmt|;
name|uint8_t
name|seq
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|addr4
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|addr5
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|addr6
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IV_IV
parameter_list|(
name|iv
parameter_list|)
value|((iv)& 0xFFFFFF)
end_define

begin_define
define|#
directive|define
name|IV_PAD
parameter_list|(
name|iv
parameter_list|)
value|(((iv)>> 24)& 0x3F)
end_define

begin_define
define|#
directive|define
name|IV_KEYID
parameter_list|(
name|iv
parameter_list|)
value|(((iv)>> 30)& 0x03)
end_define

begin_comment
comment|/* $FreeBSD: src/sys/net80211/ieee80211_radiotap.h,v 1.5 2005/01/22 20:12:05 sam Exp $ */
end_comment

begin_comment
comment|/* NetBSD: ieee802_11_radio.h,v 1.2 2006/02/26 03:04:03 dyoung Exp  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003, 2004 David Young.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY DAVID YOUNG ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DAVID  * YOUNG BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* A generic radio capture format is desirable. It must be  * rigidly defined (e.g., units for fields should be given),  * and easily extensible.  *  * The following is an extensible radio capture format. It is  * based on a bitmap indicating which fields are present.  *  * I am trying to describe precisely what the application programmer  * should expect in the following, and for that reason I tell the  * units and origin of each measurement (where it applies), or else I  * use sufficiently weaselly language ("is a monotonically nondecreasing  * function of...") that I cannot set false expectations for lawyerly  * readers.  */
end_comment

begin_comment
comment|/*  * The radio capture header precedes the 802.11 header.  *  * Note well: all radiotap fields are little-endian.  */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_header
block|{
name|uint8_t
name|it_version
decl_stmt|;
comment|/* Version 0. Only increases 					 * for drastic changes, 					 * introduction of compatible 					 * new fields does not count. 					 */
name|uint8_t
name|it_pad
decl_stmt|;
name|uint16_t
name|it_len
decl_stmt|;
comment|/* length of the whole 					 * header in bytes, including 					 * it_version, it_pad, 					 * it_len, and data fields. 					 */
name|uint32_t
name|it_present
decl_stmt|;
comment|/* A bitmap telling which 					 * fields are present. Set bit 31 					 * (0x80000000) to extend the 					 * bitmap by another 32 bits. 					 * Additional extensions are made 					 * by setting bit 31. 					 */
block|}
struct|;
end_struct

begin_comment
comment|/* Name                                 Data type       Units  * ----                                 ---------       -----  *  * IEEE80211_RADIOTAP_TSFT              uint64_t       microseconds  *  *      Value in microseconds of the MAC's 64-bit 802.11 Time  *      Synchronization Function timer when the first bit of the  *      MPDU arrived at the MAC. For received frames, only.  *  * IEEE80211_RADIOTAP_CHANNEL           2 x uint16_t   MHz, bitmap  *  *      Tx/Rx frequency in MHz, followed by flags (see below).  *	Note that IEEE80211_RADIOTAP_XCHANNEL must be used to  *	represent an HT channel as there is not enough room in  *	the flags word.  *  * IEEE80211_RADIOTAP_FHSS              uint16_t       see below  *  *      For frequency-hopping radios, the hop set (first byte)  *      and pattern (second byte).  *  * IEEE80211_RADIOTAP_RATE              uint8_t        500kb/s or index  *  *      Tx/Rx data rate.  If bit 0x80 is set then it represents an  *	an MCS index and not an IEEE rate.  *  * IEEE80211_RADIOTAP_DBM_ANTSIGNAL     int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF signal power at the antenna, decibel difference from  *      one milliwatt.  *  * IEEE80211_RADIOTAP_DBM_ANTNOISE      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      RF noise power at the antenna, decibel difference from one  *      milliwatt.  *  * IEEE80211_RADIOTAP_DB_ANTSIGNAL      uint8_t        decibel (dB)  *  *      RF signal power at the antenna, decibel difference from an  *      arbitrary, fixed reference.  *  * IEEE80211_RADIOTAP_DB_ANTNOISE       uint8_t        decibel (dB)  *  *      RF noise power at the antenna, decibel difference from an  *      arbitrary, fixed reference point.  *  * IEEE80211_RADIOTAP_LOCK_QUALITY      uint16_t       unitless  *  *      Quality of Barker code lock. Unitless. Monotonically  *      nondecreasing with "better" lock strength. Called "Signal  *      Quality" in datasheets.  (Is there a standard way to measure  *      this?)  *  * IEEE80211_RADIOTAP_TX_ATTENUATION    uint16_t       unitless  *  *      Transmit power expressed as unitless distance from max  *      power set at factory calibration.  0 is max power.  *      Monotonically nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DB_TX_ATTENUATION uint16_t       decibels (dB)  *  *      Transmit power expressed as decibel distance from max power  *      set at factory calibration.  0 is max power.  Monotonically  *      nondecreasing with lower power levels.  *  * IEEE80211_RADIOTAP_DBM_TX_POWER      int8_t          decibels from  *                                                      one milliwatt (dBm)  *  *      Transmit power expressed as dBm (decibels from a 1 milliwatt  *      reference). This is the absolute power level measured at  *      the antenna port.  *  * IEEE80211_RADIOTAP_FLAGS             uint8_t        bitmap  *  *      Properties of transmitted and received frames. See flags  *      defined below.  *  * IEEE80211_RADIOTAP_ANTENNA           uint8_t        antenna index  *  *      Unitless indication of the Rx/Tx antenna for this packet.  *      The first antenna is antenna 0.  *  * IEEE80211_RADIOTAP_RX_FLAGS          uint16_t       bitmap  *  *     Properties of received frames. See flags defined below.  *  * IEEE80211_RADIOTAP_XCHANNEL          uint32_t	bitmap  *					uint16_t	MHz  *					uint8_t		channel number  *					uint8_t		.5 dBm  *  *	Extended channel specification: flags (see below) followed by  *	frequency in MHz, the corresponding IEEE channel number, and  *	finally the maximum regulatory transmit power cap in .5 dBm  *	units.  This property supersedes IEEE80211_RADIOTAP_CHANNEL  *	and only one of the two should be present.  *  * IEEE80211_RADIOTAP_MCS		uint8_t		known  *					uint8_t		flags  *					uint8_t		mcs  *  *	Bitset indicating which fields have known values, followed  *	by bitset of flag values, followed by the MCS rate index as  *	in IEEE 802.11n.  *  * IEEE80211_RADIOTAP_VENDOR_NAMESPACE  *					uint8_t  OUI[3]  *                                   uint8_t  subspace  *                                   uint16_t length  *  *     The Vendor Namespace Field contains three sub-fields. The first  *     sub-field is 3 bytes long. It contains the vendor's IEEE 802  *     Organizationally Unique Identifier (OUI). The fourth byte is a  *     vendor-specific "namespace selector."  *  */
end_comment

begin_enum
enum|enum
name|ieee80211_radiotap_type
block|{
name|IEEE80211_RADIOTAP_TSFT
init|=
literal|0
block|,
name|IEEE80211_RADIOTAP_FLAGS
init|=
literal|1
block|,
name|IEEE80211_RADIOTAP_RATE
init|=
literal|2
block|,
name|IEEE80211_RADIOTAP_CHANNEL
init|=
literal|3
block|,
name|IEEE80211_RADIOTAP_FHSS
init|=
literal|4
block|,
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
init|=
literal|5
block|,
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
init|=
literal|6
block|,
name|IEEE80211_RADIOTAP_LOCK_QUALITY
init|=
literal|7
block|,
name|IEEE80211_RADIOTAP_TX_ATTENUATION
init|=
literal|8
block|,
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
init|=
literal|9
block|,
name|IEEE80211_RADIOTAP_DBM_TX_POWER
init|=
literal|10
block|,
name|IEEE80211_RADIOTAP_ANTENNA
init|=
literal|11
block|,
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
init|=
literal|12
block|,
name|IEEE80211_RADIOTAP_DB_ANTNOISE
init|=
literal|13
block|,
name|IEEE80211_RADIOTAP_RX_FLAGS
init|=
literal|14
block|,
comment|/* NB: gap for netbsd definitions */
name|IEEE80211_RADIOTAP_XCHANNEL
init|=
literal|18
block|,
name|IEEE80211_RADIOTAP_MCS
init|=
literal|19
block|,
name|IEEE80211_RADIOTAP_NAMESPACE
init|=
literal|29
block|,
name|IEEE80211_RADIOTAP_VENDOR_NAMESPACE
init|=
literal|30
block|,
name|IEEE80211_RADIOTAP_EXT
init|=
literal|31
block|}
enum|;
end_enum

begin_comment
comment|/* channel attributes */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TURBO
value|0x00010
end_define

begin_comment
comment|/* Turbo channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_CCK
value|0x00020
end_define

begin_comment
comment|/* CCK channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_OFDM
value|0x00040
end_define

begin_comment
comment|/* OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_2GHZ
value|0x00080
end_define

begin_comment
comment|/* 2 GHz spectrum channel. */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_5GHZ
value|0x00100
end_define

begin_comment
comment|/* 5 GHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_PASSIVE
value|0x00200
end_define

begin_comment
comment|/* Only passive scan allowed */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_DYN
value|0x00400
end_define

begin_comment
comment|/* Dynamic CCK-OFDM channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GFSK
value|0x00800
end_define

begin_comment
comment|/* GFSK channel (FHSS PHY) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_GSM
value|0x01000
end_define

begin_comment
comment|/* 900 MHz spectrum channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_STURBO
value|0x02000
end_define

begin_comment
comment|/* 11a static turbo channel only */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HALF
value|0x04000
end_define

begin_comment
comment|/* Half rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_QUARTER
value|0x08000
end_define

begin_comment
comment|/* Quarter rate channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT20
value|0x10000
end_define

begin_comment
comment|/* HT 20 channel */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40U
value|0x20000
end_define

begin_comment
comment|/* HT 40 channel w/ ext above */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CHAN_HT40D
value|0x40000
end_define

begin_comment
comment|/* HT 40 channel w/ ext below */
end_comment

begin_comment
comment|/* Useful combinations of channel characteristics, borrowed from Ethereal */
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
name|IEEE80211_CHAN_G
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TA
define|\
value|(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
end_define

begin_define
define|#
directive|define
name|IEEE80211_CHAN_TG
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN  | IEEE80211_CHAN_TURBO)
end_define

begin_comment
comment|/* For IEEE80211_RADIOTAP_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_CFP
value|0x01
end_define

begin_comment
comment|/* sent/received 						 * during CFP 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_SHORTPRE
value|0x02
end_define

begin_comment
comment|/* sent/received 						 * with short 						 * preamble 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_WEP
value|0x04
end_define

begin_comment
comment|/* sent/received 						 * with WEP encryption 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_FRAG
value|0x08
end_define

begin_comment
comment|/* sent/received 						 * with fragmentation 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_FCS
value|0x10
end_define

begin_comment
comment|/* frame includes FCS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_DATAPAD
value|0x20
end_define

begin_comment
comment|/* frame has padding between 						 * 802.11 header and payload 						 * (to 32-bit boundary) 						 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_BADFCS
value|0x40
end_define

begin_comment
comment|/* does not pass FCS check */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_RX_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_RX_BADFCS
value|0x0001
end_define

begin_comment
comment|/* frame failed crc check */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_F_RX_PLCP_CRC
value|0x0002
end_define

begin_comment
comment|/* frame failed PLCP CRC check */
end_comment

begin_comment
comment|/* For IEEE80211_RADIOTAP_MCS known */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_MCS_INDEX_KNOWN
value|0x02
end_define

begin_comment
comment|/* MCS index field */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HT_FORMAT_KNOWN
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FEC_TYPE_KNOWN
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_KNOWN
value|0x20
end_define

begin_comment
comment|/* For IEEE80211_RADIOTAP_MCS flags */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_40
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20L
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_20U
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
value|0x04
end_define

begin_comment
comment|/* short guard interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_HT_GREENFIELD
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_FEC_LDPC
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_1
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_2
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_3
value|3
end_define

begin_define
define|#
directive|define
name|IEEE80211_RADIOTAP_MCS_STBC_SHIFT
value|5
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
name|tstr
index|[]
init|=
literal|"[|802.11]"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Radiotap state */
end_comment

begin_comment
comment|/*  This is used to save state when parsing/processing parameters */
end_comment

begin_struct
struct|struct
name|radiotap_state
block|{
name|uint32_t
name|present
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRINT_SSID
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.ssid_present) { \ 		ND_PRINT((ndo, " (")); \ 		fn_print(ndo, p.ssid.ssid, NULL); \ 		ND_PRINT((ndo, ")")); \ 	}
end_define

begin_define
define|#
directive|define
name|PRINT_RATE
parameter_list|(
name|_sep
parameter_list|,
name|_r
parameter_list|,
name|_suf
parameter_list|)
define|\
value|ND_PRINT((ndo, "%s%2.1f%s", _sep, (.5 * ((_r)& 0x7f)), _suf))
end_define

begin_define
define|#
directive|define
name|PRINT_RATES
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.rates_present) { \ 		int z; \ 		const char *sep = " ["; \ 		for (z = 0; z< p.rates.length ; z++) { \ 			PRINT_RATE(sep, p.rates.rate[z], \ 				(p.rates.rate[z]& 0x80 ? "*" : "")); \ 			sep = " "; \ 		} \ 		if (p.rates.length != 0) \ 			ND_PRINT((ndo, " Mbit]")); \ 	}
end_define

begin_define
define|#
directive|define
name|PRINT_DS_CHANNEL
parameter_list|(
name|p
parameter_list|)
define|\
value|if (p.ds_present) \ 		ND_PRINT((ndo, " CH: %u", p.ds.channel)); \ 	ND_PRINT((ndo, "%s", \ 	    CAPABILITY_PRIVACY(p.capability_info) ? ", PRIVACY" : ""));
end_define

begin_define
define|#
directive|define
name|MAX_MCS_INDEX
value|76
end_define

begin_comment
comment|/*  * Indices are:  *  *	the MCS index (0-76);  *  *	0 for 20 MHz, 1 for 40 MHz;  *  *	0 for a long guard interval, 1 for a short guard interval.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|ieee80211_float_htrates
index|[
name|MAX_MCS_INDEX
operator|+
literal|1
index|]
index|[
literal|2
index|]
index|[
literal|2
index|]
init|=
block|{
comment|/* MCS  0  */
block|{
comment|/* 20 Mhz */
block|{
literal|6.5
block|,
comment|/* SGI */
literal|7.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|13.5
block|,
comment|/* SGI */
literal|15.0
block|, }
block|, 	}
block|,
comment|/* MCS  1  */
block|{
comment|/* 20 Mhz */
block|{
literal|13.0
block|,
comment|/* SGI */
literal|14.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|27.0
block|,
comment|/* SGI */
literal|30.0
block|, }
block|, 	}
block|,
comment|/* MCS  2  */
block|{
comment|/* 20 Mhz */
block|{
literal|19.5
block|,
comment|/* SGI */
literal|21.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|40.5
block|,
comment|/* SGI */
literal|45.0
block|, }
block|, 	}
block|,
comment|/* MCS  3  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS  4  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS  5  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS  6  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS  7  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS  8  */
block|{
comment|/* 20 Mhz */
block|{
literal|13.0
block|,
comment|/* SGI */
literal|14.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|27.0
block|,
comment|/* SGI */
literal|30.0
block|, }
block|, 	}
block|,
comment|/* MCS  9  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS 10  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 11  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 12  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 13  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 14  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 15  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 16  */
block|{
comment|/* 20 Mhz */
block|{
literal|19.5
block|,
comment|/* SGI */
literal|21.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|40.5
block|,
comment|/* SGI */
literal|45.0
block|, }
block|, 	}
block|,
comment|/* MCS 17  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 18  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS 19  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 20  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 21  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 22  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 23  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 24  */
block|{
comment|/* 20 Mhz */
block|{
literal|26.0
block|,
comment|/* SGI */
literal|28.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|54.0
block|,
comment|/* SGI */
literal|60.0
block|, }
block|, 	}
block|,
comment|/* MCS 25  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 26  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 27  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 28  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 29  */
block|{
comment|/* 20 Mhz */
block|{
literal|208.0
block|,
comment|/* SGI */
literal|231.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|432.0
block|,
comment|/* SGI */
literal|480.0
block|, }
block|, 	}
block|,
comment|/* MCS 30  */
block|{
comment|/* 20 Mhz */
block|{
literal|234.0
block|,
comment|/* SGI */
literal|260.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|486.0
block|,
comment|/* SGI */
literal|540.0
block|, }
block|, 	}
block|,
comment|/* MCS 31  */
block|{
comment|/* 20 Mhz */
block|{
literal|260.0
block|,
comment|/* SGI */
literal|288.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|540.0
block|,
comment|/* SGI */
literal|600.0
block|, }
block|, 	}
block|,
comment|/* MCS 32  */
block|{
comment|/* 20 Mhz */
block|{
literal|0.0
block|,
comment|/* SGI */
literal|0.0
block|, }
block|,
comment|/* not valid */
comment|/* 40 Mhz */
block|{
literal|6.0
block|,
comment|/* SGI */
literal|6.7
block|, }
block|, 	}
block|,
comment|/* MCS 33  */
block|{
comment|/* 20 Mhz */
block|{
literal|39.0
block|,
comment|/* SGI */
literal|43.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|81.0
block|,
comment|/* SGI */
literal|90.0
block|, }
block|, 	}
block|,
comment|/* MCS 34  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 35  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 36  */
block|{
comment|/* 20 Mhz */
block|{
literal|58.5
block|,
comment|/* SGI */
literal|65.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|121.5
block|,
comment|/* SGI */
literal|135.0
block|, }
block|, 	}
block|,
comment|/* MCS 37  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 38  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 39  */
block|{
comment|/* 20 Mhz */
block|{
literal|52.0
block|,
comment|/* SGI */
literal|57.8
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|108.0
block|,
comment|/* SGI */
literal|120.0
block|, }
block|, 	}
block|,
comment|/* MCS 40  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 41  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 42  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 43  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 44  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 45  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 46  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 47  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 48  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 49  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 50  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 51  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 52  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 53  */
block|{
comment|/* 20 Mhz */
block|{
literal|65.0
block|,
comment|/* SGI */
literal|72.2
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|135.0
block|,
comment|/* SGI */
literal|150.0
block|, }
block|, 	}
block|,
comment|/* MCS 54  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 55  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 56  */
block|{
comment|/* 20 Mhz */
block|{
literal|78.0
block|,
comment|/* SGI */
literal|86.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|162.0
block|,
comment|/* SGI */
literal|180.0
block|, }
block|, 	}
block|,
comment|/* MCS 57  */
block|{
comment|/* 20 Mhz */
block|{
literal|91.0
block|,
comment|/* SGI */
literal|101.1
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|189.0
block|,
comment|/* SGI */
literal|210.0
block|, }
block|, 	}
block|,
comment|/* MCS 58  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 59  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 60  */
block|{
comment|/* 20 Mhz */
block|{
literal|104.0
block|,
comment|/* SGI */
literal|115.6
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|216.0
block|,
comment|/* SGI */
literal|240.0
block|, }
block|, 	}
block|,
comment|/* MCS 61  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 62  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 63  */
block|{
comment|/* 20 Mhz */
block|{
literal|130.0
block|,
comment|/* SGI */
literal|144.4
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|270.0
block|,
comment|/* SGI */
literal|300.0
block|, }
block|, 	}
block|,
comment|/* MCS 64  */
block|{
comment|/* 20 Mhz */
block|{
literal|143.0
block|,
comment|/* SGI */
literal|158.9
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|297.0
block|,
comment|/* SGI */
literal|330.0
block|, }
block|, 	}
block|,
comment|/* MCS 65  */
block|{
comment|/* 20 Mhz */
block|{
literal|97.5
block|,
comment|/* SGI */
literal|108.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|202.5
block|,
comment|/* SGI */
literal|225.0
block|, }
block|, 	}
block|,
comment|/* MCS 66  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 67  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 68  */
block|{
comment|/* 20 Mhz */
block|{
literal|117.0
block|,
comment|/* SGI */
literal|130.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|243.0
block|,
comment|/* SGI */
literal|270.0
block|, }
block|, 	}
block|,
comment|/* MCS 69  */
block|{
comment|/* 20 Mhz */
block|{
literal|136.5
block|,
comment|/* SGI */
literal|151.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|283.5
block|,
comment|/* SGI */
literal|315.0
block|, }
block|, 	}
block|,
comment|/* MCS 70  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 71  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 72  */
block|{
comment|/* 20 Mhz */
block|{
literal|156.0
block|,
comment|/* SGI */
literal|173.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|324.0
block|,
comment|/* SGI */
literal|360.0
block|, }
block|, 	}
block|,
comment|/* MCS 73  */
block|{
comment|/* 20 Mhz */
block|{
literal|175.5
block|,
comment|/* SGI */
literal|195.0
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|364.5
block|,
comment|/* SGI */
literal|405.0
block|, }
block|, 	}
block|,
comment|/* MCS 74  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 75  */
block|{
comment|/* 20 Mhz */
block|{
literal|195.0
block|,
comment|/* SGI */
literal|216.7
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|405.0
block|,
comment|/* SGI */
literal|450.0
block|, }
block|, 	}
block|,
comment|/* MCS 76  */
block|{
comment|/* 20 Mhz */
block|{
literal|214.5
block|,
comment|/* SGI */
literal|238.3
block|, }
block|,
comment|/* 40 Mhz */
block|{
literal|445.5
block|,
comment|/* SGI */
literal|495.0
block|, }
block|, 	}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|auth_alg_text
index|[]
init|=
block|{
literal|"Open System"
block|,
literal|"Shared Key"
block|,
literal|"EAP"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_AUTH_ALGS
value|(sizeof auth_alg_text / sizeof auth_alg_text[0])
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|status_text
index|[]
init|=
block|{
literal|"Successful"
block|,
comment|/*  0 */
literal|"Unspecified failure"
block|,
comment|/*  1 */
literal|"Reserved"
block|,
comment|/*  2 */
literal|"Reserved"
block|,
comment|/*  3 */
literal|"Reserved"
block|,
comment|/*  4 */
literal|"Reserved"
block|,
comment|/*  5 */
literal|"Reserved"
block|,
comment|/*  6 */
literal|"Reserved"
block|,
comment|/*  7 */
literal|"Reserved"
block|,
comment|/*  8 */
literal|"Reserved"
block|,
comment|/*  9 */
literal|"Cannot Support all requested capabilities in the Capability "
literal|"Information field"
block|,
comment|/* 10 */
literal|"Reassociation denied due to inability to confirm that association "
literal|"exists"
block|,
comment|/* 11 */
literal|"Association denied due to reason outside the scope of the "
literal|"standard"
block|,
comment|/* 12 */
literal|"Responding station does not support the specified authentication "
literal|"algorithm "
block|,
comment|/* 13 */
literal|"Received an Authentication frame with authentication transaction "
literal|"sequence number out of expected sequence"
block|,
comment|/* 14 */
literal|"Authentication rejected because of challenge failure"
block|,
comment|/* 15 */
literal|"Authentication rejected due to timeout waiting for next frame in "
literal|"sequence"
block|,
comment|/* 16 */
literal|"Association denied because AP is unable to handle additional"
literal|"associated stations"
block|,
comment|/* 17 */
literal|"Association denied due to requesting station not supporting all of "
literal|"the data rates in BSSBasicRateSet parameter"
block|,
comment|/* 18 */
literal|"Association denied due to requesting station not supporting "
literal|"short preamble operation"
block|,
comment|/* 19 */
literal|"Association denied due to requesting station not supporting "
literal|"PBCC encoding"
block|,
comment|/* 20 */
literal|"Association denied due to requesting station not supporting "
literal|"channel agility"
block|,
comment|/* 21 */
literal|"Association request rejected because Spectrum Management "
literal|"capability is required"
block|,
comment|/* 22 */
literal|"Association request rejected because the information in the "
literal|"Power Capability element is unacceptable"
block|,
comment|/* 23 */
literal|"Association request rejected because the information in the "
literal|"Supported Channels element is unacceptable"
block|,
comment|/* 24 */
literal|"Association denied due to requesting station not supporting "
literal|"short slot operation"
block|,
comment|/* 25 */
literal|"Association denied due to requesting station not supporting "
literal|"DSSS-OFDM operation"
block|,
comment|/* 26 */
literal|"Association denied because the requested STA does not support HT "
literal|"features"
block|,
comment|/* 27 */
literal|"Reserved"
block|,
comment|/* 28 */
literal|"Association denied because the requested STA does not support "
literal|"the PCO transition time required by the AP"
block|,
comment|/* 29 */
literal|"Reserved"
block|,
comment|/* 30 */
literal|"Reserved"
block|,
comment|/* 31 */
literal|"Unspecified, QoS-related failure"
block|,
comment|/* 32 */
literal|"Association denied due to QAP having insufficient bandwidth "
literal|"to handle another QSTA"
block|,
comment|/* 33 */
literal|"Association denied due to excessive frame loss rates and/or "
literal|"poor conditions on current operating channel"
block|,
comment|/* 34 */
literal|"Association (with QBSS) denied due to requesting station not "
literal|"supporting the QoS facility"
block|,
comment|/* 35 */
literal|"Association denied due to requesting station not supporting "
literal|"Block Ack"
block|,
comment|/* 36 */
literal|"The request has been declined"
block|,
comment|/* 37 */
literal|"The request has not been successful as one or more parameters "
literal|"have invalid values"
block|,
comment|/* 38 */
literal|"The TS has not been created because the request cannot be honored. "
literal|"Try again with the suggested changes to the TSPEC"
block|,
comment|/* 39 */
literal|"Invalid Information Element"
block|,
comment|/* 40 */
literal|"Group Cipher is not valid"
block|,
comment|/* 41 */
literal|"Pairwise Cipher is not valid"
block|,
comment|/* 42 */
literal|"AKMP is not valid"
block|,
comment|/* 43 */
literal|"Unsupported RSN IE version"
block|,
comment|/* 44 */
literal|"Invalid RSN IE Capabilities"
block|,
comment|/* 45 */
literal|"Cipher suite is rejected per security policy"
block|,
comment|/* 46 */
literal|"The TS has not been created. However, the HC may be capable of "
literal|"creating a TS, in response to a request, after the time indicated "
literal|"in the TS Delay element"
block|,
comment|/* 47 */
literal|"Direct Link is not allowed in the BSS by policy"
block|,
comment|/* 48 */
literal|"Destination STA is not present within this QBSS."
block|,
comment|/* 49 */
literal|"The Destination STA is not a QSTA."
block|,
comment|/* 50 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_STATUSES
value|(sizeof status_text / sizeof status_text[0])
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|reason_text
index|[]
init|=
block|{
literal|"Reserved"
block|,
comment|/* 0 */
literal|"Unspecified reason"
block|,
comment|/* 1 */
literal|"Previous authentication no longer valid"
block|,
comment|/* 2 */
literal|"Deauthenticated because sending station is leaving (or has left) "
literal|"IBSS or ESS"
block|,
comment|/* 3 */
literal|"Disassociated due to inactivity"
block|,
comment|/* 4 */
literal|"Disassociated because AP is unable to handle all currently "
literal|" associated stations"
block|,
comment|/* 5 */
literal|"Class 2 frame received from nonauthenticated station"
block|,
comment|/* 6 */
literal|"Class 3 frame received from nonassociated station"
block|,
comment|/* 7 */
literal|"Disassociated because sending station is leaving "
literal|"(or has left) BSS"
block|,
comment|/* 8 */
literal|"Station requesting (re)association is not authenticated with "
literal|"responding station"
block|,
comment|/* 9 */
literal|"Disassociated because the information in the Power Capability "
literal|"element is unacceptable"
block|,
comment|/* 10 */
literal|"Disassociated because the information in the SupportedChannels "
literal|"element is unacceptable"
block|,
comment|/* 11 */
literal|"Invalid Information Element"
block|,
comment|/* 12 */
literal|"Reserved"
block|,
comment|/* 13 */
literal|"Michael MIC failure"
block|,
comment|/* 14 */
literal|"4-Way Handshake timeout"
block|,
comment|/* 15 */
literal|"Group key update timeout"
block|,
comment|/* 16 */
literal|"Information element in 4-Way Handshake different from (Re)Association"
literal|"Request/Probe Response/Beacon"
block|,
comment|/* 17 */
literal|"Group Cipher is not valid"
block|,
comment|/* 18 */
literal|"AKMP is not valid"
block|,
comment|/* 20 */
literal|"Unsupported RSN IE version"
block|,
comment|/* 21 */
literal|"Invalid RSN IE Capabilities"
block|,
comment|/* 22 */
literal|"IEEE 802.1X Authentication failed"
block|,
comment|/* 23 */
literal|"Cipher suite is rejected per security policy"
block|,
comment|/* 24 */
literal|"Reserved"
block|,
comment|/* 25 */
literal|"Reserved"
block|,
comment|/* 26 */
literal|"Reserved"
block|,
comment|/* 27 */
literal|"Reserved"
block|,
comment|/* 28 */
literal|"Reserved"
block|,
comment|/* 29 */
literal|"Reserved"
block|,
comment|/* 30 */
literal|"TS deleted because QoS AP lacks sufficient bandwidth for this "
literal|"QoS STA due to a change in BSS service characteristics or "
literal|"operational mode (e.g. an HT BSS change from 40 MHz channel "
literal|"to 20 MHz channel)"
block|,
comment|/* 31 */
literal|"Disassociated for unspecified, QoS-related reason"
block|,
comment|/* 32 */
literal|"Disassociated because QoS AP lacks sufficient bandwidth for this "
literal|"QoS STA"
block|,
comment|/* 33 */
literal|"Disassociated because of excessive number of frames that need to be "
literal|"acknowledged, but are not acknowledged for AP transmissions "
literal|"and/or poor channel conditions"
block|,
comment|/* 34 */
literal|"Disassociated because STA is transmitting outside the limits "
literal|"of its TXOPs"
block|,
comment|/* 35 */
literal|"Requested from peer STA as the STA is leaving the BSS "
literal|"(or resetting)"
block|,
comment|/* 36 */
literal|"Requested from peer STA as it does not want to use the "
literal|"mechanism"
block|,
comment|/* 37 */
literal|"Requested from peer STA as the STA received frames using the "
literal|"mechanism for which a set up is required"
block|,
comment|/* 38 */
literal|"Requested from peer STA due to time out"
block|,
comment|/* 39 */
literal|"Reserved"
block|,
comment|/* 40 */
literal|"Reserved"
block|,
comment|/* 41 */
literal|"Reserved"
block|,
comment|/* 42 */
literal|"Reserved"
block|,
comment|/* 43 */
literal|"Reserved"
block|,
comment|/* 44 */
literal|"Peer STA does not support the requested cipher suite"
block|,
comment|/* 45 */
literal|"Association denied due to requesting STA not supporting HT "
literal|"features"
block|,
comment|/* 46 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_REASONS
value|(sizeof reason_text / sizeof reason_text[0])
end_define

begin_function
specifier|static
name|int
name|wep_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|iv
decl_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_IV_LEN
operator|+
name|IEEE802_11_KID_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
name|iv
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Data IV:%3x Pad %x KeyID %x"
operator|,
name|IV_IV
argument_list|(
name|iv
argument_list|)
operator|,
name|IV_PAD
argument_list|(
name|iv
argument_list|)
operator|,
name|IV_KEYID
argument_list|(
name|iv
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|parse_elements
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|struct
name|mgmt_body_t
modifier|*
name|pbody
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|int
name|offset
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|u_int
name|elementlen
decl_stmt|;
name|struct
name|ssid_t
name|ssid
decl_stmt|;
name|struct
name|challenge_t
name|challenge
decl_stmt|;
name|struct
name|rates_t
name|rates
decl_stmt|;
name|struct
name|ds_t
name|ds
decl_stmt|;
name|struct
name|cf_t
name|cf
decl_stmt|;
name|struct
name|tim_t
name|tim
decl_stmt|;
comment|/* 	 * We haven't seen any elements yet. 	 */
name|pbody
operator|->
name|challenge_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|ssid_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|rates_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|ds_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|cf_present
operator|=
literal|0
expr_stmt|;
name|pbody
operator|->
name|tim_present
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|length
operator|!=
literal|0
condition|)
block|{
comment|/* Make sure we at least have the element ID and length. */
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
name|elementlen
operator|=
operator|*
operator|(
name|p
operator|+
name|offset
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* Make sure we have the entire element. */
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|+
literal|2
operator|)
argument_list|,
name|elementlen
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|elementlen
operator|+
literal|2
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
condition|)
block|{
case|case
name|E_SSID
case|:
name|memcpy
argument_list|(
operator|&
name|ssid
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|ssid
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|ssid
operator|.
name|length
operator|>
sizeof|sizeof
argument_list|(
name|ssid
operator|.
name|ssid
argument_list|)
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|ssid
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|ssid
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|ssid
operator|.
name|ssid
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|ssid
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|ssid
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|ssid
operator|.
name|length
expr_stmt|;
block|}
name|ssid
operator|.
name|ssid
index|[
name|ssid
operator|.
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen an SSID IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|ssid_present
condition|)
block|{
name|pbody
operator|->
name|ssid
operator|=
name|ssid
expr_stmt|;
name|pbody
operator|->
name|ssid_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_CHALLENGE
case|:
name|memcpy
argument_list|(
operator|&
name|challenge
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|challenge
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|challenge
operator|.
name|length
operator|>
sizeof|sizeof
argument_list|(
name|challenge
operator|.
name|text
argument_list|)
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|challenge
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|challenge
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|challenge
operator|.
name|text
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|challenge
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|challenge
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|challenge
operator|.
name|length
expr_stmt|;
block|}
name|challenge
operator|.
name|text
index|[
name|challenge
operator|.
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a challenge IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|challenge_present
condition|)
block|{
name|pbody
operator|->
name|challenge
operator|=
name|challenge
expr_stmt|;
name|pbody
operator|->
name|challenge_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_RATES
case|:
name|memcpy
argument_list|(
operator|&
name|rates
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|rates
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|rates
operator|.
name|length
operator|>
sizeof|sizeof
name|rates
operator|.
name|rate
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
argument_list|,
name|rates
operator|.
name|length
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|rates
operator|.
name|length
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|rates
operator|.
name|rate
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|rates
operator|.
name|length
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|rates
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|rates
operator|.
name|length
expr_stmt|;
block|}
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a rates IE, 			 * copy this one if it's not zero-length, 			 * otherwise ignore this one, so we later 			 * report the first one we saw. 			 * 			 * We ignore zero-length rates IEs as some 			 * devices seem to put a zero-length rates 			 * IE, followed by an SSID IE, followed by 			 * a non-zero-length rates IE into frames, 			 * even though IEEE Std 802.11-2007 doesn't 			 * seem to indicate that a zero-length rates 			 * IE is valid. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|rates_present
operator|&&
name|rates
operator|.
name|length
operator|!=
literal|0
condition|)
block|{
name|pbody
operator|->
name|rates
operator|=
name|rates
expr_stmt|;
name|pbody
operator|->
name|rates_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_DS
case|:
name|memcpy
argument_list|(
operator|&
name|ds
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|ds
operator|.
name|length
operator|!=
literal|1
condition|)
block|{
name|offset
operator|+=
name|ds
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|ds
operator|.
name|length
expr_stmt|;
break|break;
block|}
name|ds
operator|.
name|channel
operator|=
operator|*
operator|(
name|p
operator|+
name|offset
operator|)
expr_stmt|;
name|offset
operator|+=
literal|1
expr_stmt|;
name|length
operator|-=
literal|1
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a DS IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|ds_present
condition|)
block|{
name|pbody
operator|->
name|ds
operator|=
name|ds
expr_stmt|;
name|pbody
operator|->
name|ds_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_CF
case|:
name|memcpy
argument_list|(
operator|&
name|cf
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|cf
operator|.
name|length
operator|!=
literal|6
condition|)
block|{
name|offset
operator|+=
name|cf
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|cf
operator|.
name|length
expr_stmt|;
break|break;
block|}
name|memcpy
argument_list|(
operator|&
name|cf
operator|.
name|count
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|6
expr_stmt|;
name|length
operator|-=
literal|6
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a CF IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|cf_present
condition|)
block|{
name|pbody
operator|->
name|cf
operator|=
name|cf
expr_stmt|;
name|pbody
operator|->
name|cf_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
name|E_TIM
case|:
name|memcpy
argument_list|(
operator|&
name|tim
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|tim
operator|.
name|length
operator|<=
literal|3
condition|)
block|{
name|offset
operator|+=
name|tim
operator|.
name|length
expr_stmt|;
name|length
operator|-=
name|tim
operator|.
name|length
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|>
operator|(
name|int
operator|)
sizeof|sizeof
name|tim
operator|.
name|bitmap
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|tim
operator|.
name|count
argument_list|,
name|p
operator|+
name|offset
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|3
expr_stmt|;
name|length
operator|-=
literal|3
expr_stmt|;
name|memcpy
argument_list|(
name|tim
operator|.
name|bitmap
argument_list|,
name|p
operator|+
operator|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|)
argument_list|,
operator|(
name|tim
operator|.
name|length
operator|-
literal|3
operator|)
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|tim
operator|.
name|length
operator|-
literal|3
expr_stmt|;
name|length
operator|-=
name|tim
operator|.
name|length
operator|-
literal|3
expr_stmt|;
comment|/* 			 * Present and not truncated. 			 * 			 * If we haven't already seen a TIM IE, 			 * copy this one, otherwise ignore this one, 			 * so we later report the first one we saw. 			 */
if|if
condition|(
operator|!
name|pbody
operator|->
name|tim_present
condition|)
block|{
name|pbody
operator|->
name|tim
operator|=
name|tim
expr_stmt|;
name|pbody
operator|->
name|tim_present
operator|=
literal|1
expr_stmt|;
block|}
break|break;
default|default:
if|#
directive|if
literal|0
block|ND_PRINT((ndo, "(1) unhandled element_id (%d)  ", 			    *(p + offset)));
endif|#
directive|endif
name|offset
operator|+=
literal|2
operator|+
name|elementlen
expr_stmt|;
name|length
operator|-=
literal|2
operator|+
name|elementlen
expr_stmt|;
break|break;
block|}
block|}
comment|/* No problems found. */
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Print Handle functions for the management frame types  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|handle_beacon
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|timestamp
argument_list|,
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|pbody
operator|.
name|beacon_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" %s"
operator|,
name|CAPABILITY_ESS
argument_list|(
name|pbody
operator|.
name|capability_info
argument_list|)
condition|?
literal|"ESS"
else|:
literal|"IBSS"
operator|)
argument_list|)
expr_stmt|;
name|PRINT_DS_CHANNEL
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_assoc_request
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|listen_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_assoc_response
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_STATUS_LEN
operator|+
name|IEEE802_11_AID_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_STATUS_LEN
operator|+
name|IEEE802_11_AID_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|status_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_STATUS_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_STATUS_LEN
expr_stmt|;
name|pbody
operator|.
name|aid
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_AID_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_AID_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" AID(%x) :%s: %s"
operator|,
operator|(
call|(
name|uint16_t
call|)
argument_list|(
name|pbody
operator|.
name|aid
operator|<<
literal|2
argument_list|)
operator|)
operator|>>
literal|2
operator|,
name|CAPABILITY_PRIVACY
argument_list|(
name|pbody
operator|.
name|capability_info
argument_list|)
condition|?
literal|" PRIVACY "
else|:
literal|""
operator|,
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_reassoc_request
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
operator|+
name|IEEE802_11_AP_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_CAPINFO_LEN
operator|+
name|IEEE802_11_LISTENINT_LEN
operator|+
name|IEEE802_11_AP_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|pbody
operator|.
name|listen_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_LISTENINT_LEN
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|ap
argument_list|,
name|p
operator|+
name|offset
argument_list|,
name|IEEE802_11_AP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_AP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_AP_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" AP : %s"
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|pbody
operator|.
name|ap
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_reassoc_response
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
comment|/* Same as a Association Reponse */
return|return
name|handle_assoc_response
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_probe_request
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_probe_response
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_TSTAMP_LEN
operator|+
name|IEEE802_11_BCNINT_LEN
operator|+
name|IEEE802_11_CAPINFO_LEN
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
operator|&
name|pbody
operator|.
name|timestamp
argument_list|,
name|p
argument_list|,
name|IEEE802_11_TSTAMP_LEN
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_TSTAMP_LEN
expr_stmt|;
name|pbody
operator|.
name|beacon_interval
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_BCNINT_LEN
expr_stmt|;
name|pbody
operator|.
name|capability_info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|length
operator|-=
name|IEEE802_11_CAPINFO_LEN
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|PRINT_SSID
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_RATES
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
name|PRINT_DS_CHANNEL
argument_list|(
name|pbody
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_atim
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* the frame body for ATIM is null. */
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_disassoc
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_REASON_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_REASON_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|reason_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|": %s"
operator|,
operator|(
name|pbody
operator|.
name|reason_code
operator|<
name|NUM_REASONS
operator|)
condition|?
name|reason_text
index|[
name|pbody
operator|.
name|reason_code
index|]
else|:
literal|"Reserved"
operator|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_auth
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
name|int
name|offset
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|6
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|6
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|auth_alg
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|pbody
operator|.
name|auth_trans_seq_num
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|pbody
operator|.
name|status_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
operator|+
name|offset
argument_list|)
expr_stmt|;
name|offset
operator|+=
literal|2
expr_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|ret
operator|=
name|parse_elements
argument_list|(
name|ndo
argument_list|,
operator|&
name|pbody
argument_list|,
name|p
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pbody
operator|.
name|auth_alg
operator|==
literal|1
operator|)
operator|&&
operator|(
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|==
literal|2
operator|)
operator|||
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|==
literal|3
operator|)
operator|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" (%s)-%x [Challenge Text] %s"
operator|,
operator|(
name|pbody
operator|.
name|auth_alg
operator|<
name|NUM_AUTH_ALGS
operator|)
condition|?
name|auth_alg_text
index|[
name|pbody
operator|.
name|auth_alg
index|]
else|:
literal|"Reserved"
operator|,
name|pbody
operator|.
name|auth_trans_seq_num
operator|,
operator|(
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|%
literal|2
operator|)
condition|?
operator|(
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
operator|)
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
else|:
literal|""
operator|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" (%s)-%x: %s"
operator|,
operator|(
name|pbody
operator|.
name|auth_alg
operator|<
name|NUM_AUTH_ALGS
operator|)
condition|?
name|auth_alg_text
index|[
name|pbody
operator|.
name|auth_alg
index|]
else|:
literal|"Reserved"
operator|,
name|pbody
operator|.
name|auth_trans_seq_num
operator|,
operator|(
name|pbody
operator|.
name|auth_trans_seq_num
operator|%
literal|2
operator|)
condition|?
operator|(
operator|(
name|pbody
operator|.
name|status_code
operator|<
name|NUM_STATUSES
operator|)
condition|?
name|status_text
index|[
name|pbody
operator|.
name|status_code
index|]
else|:
literal|"n/a"
operator|)
else|:
literal|""
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|handle_deauth
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|struct
name|mgmt_body_t
name|pbody
decl_stmt|;
specifier|const
name|char
modifier|*
name|reason
init|=
name|NULL
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pbody
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pbody
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|IEEE802_11_REASON_LEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
name|IEEE802_11_REASON_LEN
condition|)
return|return
literal|0
return|;
name|pbody
operator|.
name|reason_code
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|reason
operator|=
operator|(
name|pbody
operator|.
name|reason_code
operator|<
name|NUM_REASONS
operator|)
condition|?
name|reason_text
index|[
name|pbody
operator|.
name|reason_code
index|]
else|:
literal|"Reserved"
expr_stmt|;
if|if
condition|(
name|ndo
operator|->
name|ndo_eflag
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|": %s"
operator|,
name|reason
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" (%s): %s"
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|pmh
operator|->
name|sa
argument_list|)
operator|,
name|reason
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PRINT_HT_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "TxChWidth")) : \ 	(v) == 1 ? ND_PRINT((ndo, "MIMOPwrSave")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_BA_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "ADDBA Request")) : \ 	(v) == 1 ? ND_PRINT((ndo, "ADDBA Response")) : \ 	(v) == 2 ? ND_PRINT((ndo, "DELBA")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHLINK_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "Request")) : \ 	(v) == 1 ? ND_PRINT((ndo, "Report")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHPEERING_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "Open")) : \ 	(v) == 1 ? ND_PRINT((ndo, "Confirm")) : \ 	(v) == 2 ? ND_PRINT((ndo, "Close")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESHPATH_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "Request")) : \ 	(v) == 1 ? ND_PRINT((ndo, "Report")) : \ 	(v) == 2 ? ND_PRINT((ndo, "Error")) : \ 	(v) == 3 ? ND_PRINT((ndo, "RootAnnouncement")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MESH_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "MeshLink")) : \ 	(v) == 1 ? ND_PRINT((ndo, "HWMP")) : \ 	(v) == 2 ? ND_PRINT((ndo, "Gate Announcement")) : \ 	(v) == 3 ? ND_PRINT((ndo, "Congestion Control")) : \ 	(v) == 4 ? ND_PRINT((ndo, "MCCA Setup Request")) : \ 	(v) == 5 ? ND_PRINT((ndo, "MCCA Setup Reply")) : \ 	(v) == 6 ? ND_PRINT((ndo, "MCCA Advertisement Request")) : \ 	(v) == 7 ? ND_PRINT((ndo, "MCCA Advertisement")) : \ 	(v) == 8 ? ND_PRINT((ndo, "MCCA Teardown")) : \ 	(v) == 9 ? ND_PRINT((ndo, "TBTT Adjustment Request")) : \ 	(v) == 10 ? ND_PRINT((ndo, "TBTT Adjustment Response")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_MULTIHOP_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 0 ? ND_PRINT((ndo, "Proxy Update")) : \ 	(v) == 1 ? ND_PRINT((ndo, "Proxy Update Confirmation")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_define
define|#
directive|define
name|PRINT_SELFPROT_ACTION
parameter_list|(
name|v
parameter_list|)
value|(\ 	(v) == 1 ? ND_PRINT((ndo, "Peering Open")) : \ 	(v) == 2 ? ND_PRINT((ndo, "Peering Confirm")) : \ 	(v) == 3 ? ND_PRINT((ndo, "Peering Close")) : \ 	(v) == 4 ? ND_PRINT((ndo, "Group Key Inform")) : \ 	(v) == 5 ? ND_PRINT((ndo, "Group Key Acknowledge")) : \ 		   ND_PRINT((ndo, "Act#%d", (v))) \ )
end_define

begin_function
specifier|static
name|int
name|handle_action
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|length
operator|<
literal|2
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|ndo
operator|->
name|ndo_eflag
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|": "
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" (%s): "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|pmh
operator|->
name|sa
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|p
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|0
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Spectrum Management Act#%d"
operator|,
name|p
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"QoS Act#%d"
operator|,
name|p
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"DLS Act#%d"
operator|,
name|p
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"BA "
operator|)
argument_list|)
expr_stmt|;
name|PRINT_BA_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|7
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"HT "
operator|)
argument_list|)
expr_stmt|;
name|PRINT_HT_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|13
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MeshAction "
operator|)
argument_list|)
expr_stmt|;
name|PRINT_MESH_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|14
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MultiohopAction "
operator|)
argument_list|)
expr_stmt|;
name|PRINT_MULTIHOP_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|15
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"SelfprotectAction "
operator|)
argument_list|)
expr_stmt|;
name|PRINT_SELFPROT_ACTION
argument_list|(
name|p
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
literal|127
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Vendor Act#%d"
operator|,
name|p
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Reserved(%d) Act#%d"
operator|,
name|p
index|[
literal|0
index|]
operator|,
name|p
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Print Body funcs  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|mgmt_body_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|,
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|pmh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tok2str
argument_list|(
name|st_str
argument_list|,
literal|"Unhandled Management subtype(%x)"
argument_list|,
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|ST_ASSOC_REQUEST
case|:
return|return
name|handle_assoc_request
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_ASSOC_RESPONSE
case|:
return|return
name|handle_assoc_response
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_REASSOC_REQUEST
case|:
return|return
name|handle_reassoc_request
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_REASSOC_RESPONSE
case|:
return|return
name|handle_reassoc_response
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_PROBE_REQUEST
case|:
return|return
name|handle_probe_request
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_PROBE_RESPONSE
case|:
return|return
name|handle_probe_response
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_BEACON
case|:
return|return
name|handle_beacon
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_ATIM
case|:
return|return
name|handle_atim
argument_list|()
return|;
case|case
name|ST_DISASSOC
case|:
return|return
name|handle_disassoc
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_AUTH
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|p
index|[
literal|0
index|]
operator|==
literal|0
operator|)
operator|&&
operator|(
name|p
index|[
literal|1
index|]
operator|==
literal|0
operator|)
operator|&&
operator|(
name|p
index|[
literal|2
index|]
operator|==
literal|0
operator|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Authentication (Shared-Key)-3 "
operator|)
argument_list|)
expr_stmt|;
return|return
name|wep_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|)
return|;
block|}
return|return
name|handle_auth
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_DEAUTH
case|:
return|return
name|handle_deauth
argument_list|(
name|ndo
argument_list|,
name|pmh
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
case|case
name|ST_ACTION
case|:
return|return
name|handle_action
argument_list|(
name|ndo
argument_list|,
name|pmh
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
return|;
default|default:
return|return
literal|1
return|;
block|}
block|}
end_function

begin_comment
comment|/*********************************************************************************  * Handles printing all the control frame types  *********************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ctrl_body_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tok2str
argument_list|(
name|ctrl_str
argument_list|,
literal|"Unknown Ctrl Subtype"
argument_list|,
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_CONTROL_WRAPPER
case|:
comment|/* XXX - requires special handling */
break|break;
case|case
name|CTRL_BAR
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_BAR_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s TA:%s CTL(%x) SEQ(%u) "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ctl
operator|)
argument_list|)
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|seq
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_BA
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_BA_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ba_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_PS_POLL
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_PS_POLL_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" AID(%x)"
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|aid
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_RTS
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_RTS_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" TA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CTS
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_CTS_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_cts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_ACK
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_ACK_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CF_END
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_END_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_END_ACK
case|:
if|if
condition|(
operator|!
name|ND_TTEST2
argument_list|(
operator|*
name|p
argument_list|,
name|CTRL_END_ACK_HDRLEN
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Print Header funcs  */
end_comment

begin_comment
comment|/*  *  Data Frame - Address field contents  *  *  To Ds  | From DS | Addr 1 | Addr 2 | Addr 3 | Addr 4  *    0    |  0      |  DA    | SA     | BSSID  | n/a  *    0    |  1      |  DA    | BSSID  | SA     | n/a  *    1    |  0      |  BSSID | SA     | DA     | n/a  *    1    |  1      |  RA    | TA     | DA     | SA  */
end_comment

begin_function
specifier|static
name|void
name|data_header_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
name|u_int
name|subtype
init|=
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
decl_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_CF_ACK
argument_list|(
name|subtype
argument_list|)
operator|||
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
operator|||
name|DATA_FRAME_IS_QOS
argument_list|(
name|subtype
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"CF "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_CF_ACK
argument_list|(
name|subtype
argument_list|)
condition|)
block|{
if|if
condition|(
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Ack/Poll"
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Ack"
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|DATA_FRAME_IS_CF_POLL
argument_list|(
name|subtype
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Poll"
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|DATA_FRAME_IS_QOS
argument_list|(
name|subtype
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"+QoS"
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" "
operator|)
argument_list|)
expr_stmt|;
block|}
define|#
directive|define
name|ADDR1
value|(p + 4)
define|#
directive|define
name|ADDR2
value|(p + 10)
define|#
directive|define
name|ADDR3
value|(p + 16)
define|#
directive|define
name|ADDR4
value|(p + 24)
if|if
condition|(
operator|!
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
operator|!
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR2
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR1
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"DA:%s SA:%s BSSID:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR1
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR2
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR1
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"DA:%s BSSID:%s SA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR1
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR2
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
operator|!
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR2
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"BSSID:%s SA:%s DA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR1
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR2
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|ADDR4
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|ADDR3
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s TA:%s DA:%s SA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR1
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR2
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR3
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|ADDR4
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
undef|#
directive|undef
name|ADDR1
undef|#
directive|undef
name|ADDR2
undef|#
directive|undef
name|ADDR3
undef|#
directive|undef
name|ADDR4
block|}
end_function

begin_function
specifier|static
name|void
name|mgmt_header_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
specifier|const
name|struct
name|mgmt_header_t
modifier|*
name|hp
init|=
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
name|p
decl_stmt|;
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|hp
operator|->
name|sa
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|hp
operator|->
name|da
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"BSSID:%s DA:%s SA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
name|hp
operator|)
operator|->
name|bssid
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
name|hp
operator|)
operator|->
name|da
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
name|hp
operator|)
operator|->
name|sa
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ctrl_header_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
if|if
condition|(
name|srcp
operator|!=
name|NULL
condition|)
operator|*
name|srcp
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|dstp
operator|!=
name|NULL
condition|)
operator|*
name|dstp
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
return|return;
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_BAR
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" RA:%s TA:%s CTL(%x) SEQ(%u) "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ctl
operator|)
argument_list|)
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_bar_t
operator|*
operator|)
name|p
operator|)
operator|->
name|seq
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_BA
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ba_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_PS_POLL
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"BSSID:%s TA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ps_poll_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_RTS
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s TA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_rts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ta
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CTS
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_cts_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_ACK
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_CF_END
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s BSSID:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|CTRL_END_ACK
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RA:%s BSSID:%s "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|ra
argument_list|)
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
operator|(
operator|(
specifier|const
expr|struct
name|ctrl_end_ack_t
operator|*
operator|)
name|p
operator|)
operator|->
name|bssid
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(H) Unknown Ctrl Subtype"
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|extract_header_length
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|)
block|{
name|int
name|len
decl_stmt|;
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
return|return
name|MGMT_HDRLEN
return|;
case|case
name|T_CTRL
case|:
switch|switch
condition|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|CTRL_BAR
case|:
return|return
name|CTRL_BAR_HDRLEN
return|;
case|case
name|CTRL_PS_POLL
case|:
return|return
name|CTRL_PS_POLL_HDRLEN
return|;
case|case
name|CTRL_RTS
case|:
return|return
name|CTRL_RTS_HDRLEN
return|;
case|case
name|CTRL_CTS
case|:
return|return
name|CTRL_CTS_HDRLEN
return|;
case|case
name|CTRL_ACK
case|:
return|return
name|CTRL_ACK_HDRLEN
return|;
case|case
name|CTRL_CF_END
case|:
return|return
name|CTRL_END_HDRLEN
return|;
case|case
name|CTRL_END_ACK
case|:
return|return
name|CTRL_END_ACK_HDRLEN
return|;
default|default:
return|return
literal|0
return|;
block|}
case|case
name|T_DATA
case|:
name|len
operator|=
operator|(
name|FC_TO_DS
argument_list|(
name|fc
argument_list|)
operator|&&
name|FC_FROM_DS
argument_list|(
name|fc
argument_list|)
operator|)
condition|?
literal|30
else|:
literal|24
expr_stmt|;
if|if
condition|(
name|DATA_FRAME_IS_QOS
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
name|len
operator|+=
literal|2
expr_stmt|;
return|return
name|len
return|;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"unknown IEEE802.11 frame type (%d)"
operator|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|extract_mesh_header_length
parameter_list|(
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|p
index|[
literal|0
index|]
operator|&
operator|~
literal|3
operator|)
condition|?
literal|0
else|:
literal|6
operator|*
operator|(
literal|1
operator|+
operator|(
name|p
index|[
literal|0
index|]
operator|&
literal|3
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Print the 802.11 MAC header if eflag is set, and set "*srcp" and "*dstp"  * to point to the source and destination MAC addresses in any case if  * "srcp" and "dstp" aren't null.  */
end_comment

begin_function
specifier|static
name|void
name|ieee_802_11_hdr_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint16_t
name|fc
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|hdrlen
parameter_list|,
name|u_int
name|meshdrlen
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|srcp
parameter_list|,
specifier|const
name|uint8_t
modifier|*
modifier|*
name|dstp
parameter_list|)
block|{
if|if
condition|(
name|ndo
operator|->
name|ndo_vflag
condition|)
block|{
if|if
condition|(
name|FC_MORE_DATA
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"More Data "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_MORE_FLAG
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"More Fragments "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_POWER_MGMT
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Pwr Mgmt "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_RETRY
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Retry "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_ORDER
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"Strictly Ordered "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_WEP
argument_list|(
name|fc
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"WEP Encrypted "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|!=
name|T_CTRL
operator|||
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
operator|!=
name|CTRL_PS_POLL
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%dus "
operator|,
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
operator|(
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
name|p
operator|)
operator|->
name|duration
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|meshdrlen
operator|!=
literal|0
condition|)
block|{
specifier|const
name|struct
name|meshcntl_t
modifier|*
name|mc
init|=
operator|(
specifier|const
expr|struct
name|meshcntl_t
operator|*
operator|)
operator|&
name|p
index|[
name|hdrlen
operator|-
name|meshdrlen
index|]
decl_stmt|;
name|int
name|ae
init|=
name|mc
operator|->
name|flags
operator|&
literal|3
decl_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MeshData (AE %d TTL %u seq %u"
operator|,
name|ae
operator|,
name|mc
operator|->
name|ttl
operator|,
name|EXTRACT_LE_32BITS
argument_list|(
name|mc
operator|->
name|seq
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|0
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" A4:%s"
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|mc
operator|->
name|addr4
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|1
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" A5:%s"
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|mc
operator|->
name|addr5
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ae
operator|>
literal|2
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" A6:%s"
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|mc
operator|->
name|addr6
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|") "
operator|)
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
name|mgmt_header_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_CTRL
case|:
name|ctrl_header_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_DATA
case|:
name|data_header_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
name|p
argument_list|,
name|srcp
argument_list|,
name|dstp
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(header) unknown IEEE802.11 frame type (%d)"
operator|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|)
argument_list|)
expr_stmt|;
operator|*
name|srcp
operator|=
name|NULL
expr_stmt|;
operator|*
name|dstp
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|roundup2
end_ifndef

begin_define
define|#
directive|define
name|roundup2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))&(~((y)-1)))
end_define

begin_comment
comment|/* if y is powers of two */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|u_int
name|ieee802_11_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|orig_caplen
parameter_list|,
name|int
name|pad
parameter_list|,
name|u_int
name|fcslen
parameter_list|)
block|{
name|uint16_t
name|fc
decl_stmt|;
name|u_int
name|caplen
decl_stmt|,
name|hdrlen
decl_stmt|,
name|meshdrlen
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|src
decl_stmt|,
modifier|*
name|dst
decl_stmt|;
name|u_short
name|extracted_ethertype
decl_stmt|;
name|caplen
operator|=
name|orig_caplen
expr_stmt|;
comment|/* Remove FCS, if present */
if|if
condition|(
name|length
operator|<
name|fcslen
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|length
operator|-=
name|fcslen
expr_stmt|;
if|if
condition|(
name|caplen
operator|>
name|length
condition|)
block|{
comment|/* Amount of FCS in actual packet data, if any */
name|fcslen
operator|=
name|caplen
operator|-
name|length
expr_stmt|;
name|caplen
operator|-=
name|fcslen
expr_stmt|;
name|ndo
operator|->
name|ndo_snapend
operator|-=
name|fcslen
expr_stmt|;
block|}
if|if
condition|(
name|caplen
operator|<
name|IEEE802_11_FC_LEN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|orig_caplen
return|;
block|}
name|fc
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|hdrlen
operator|=
name|extract_header_length
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|)
expr_stmt|;
if|if
condition|(
name|pad
condition|)
name|hdrlen
operator|=
name|roundup2
argument_list|(
name|hdrlen
argument_list|,
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|ndo
operator|->
name|ndo_Hflag
operator|&&
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|==
name|T_DATA
operator|&&
name|DATA_FRAME_IS_QOS
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
block|{
name|meshdrlen
operator|=
name|extract_mesh_header_length
argument_list|(
name|p
operator|+
name|hdrlen
argument_list|)
expr_stmt|;
name|hdrlen
operator|+=
name|meshdrlen
expr_stmt|;
block|}
else|else
name|meshdrlen
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
name|hdrlen
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
name|ieee_802_11_hdr_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
name|p
argument_list|,
name|hdrlen
argument_list|,
name|meshdrlen
argument_list|,
operator|&
name|src
argument_list|,
operator|&
name|dst
argument_list|)
expr_stmt|;
comment|/* 	 * Go past the 802.11 header. 	 */
name|length
operator|-=
name|hdrlen
expr_stmt|;
name|caplen
operator|-=
name|hdrlen
expr_stmt|;
name|p
operator|+=
name|hdrlen
expr_stmt|;
switch|switch
condition|(
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
condition|)
block|{
case|case
name|T_MGMT
case|:
if|if
condition|(
operator|!
name|mgmt_body_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
operator|(
specifier|const
expr|struct
name|mgmt_header_t
operator|*
operator|)
operator|(
name|p
operator|-
name|hdrlen
operator|)
argument_list|,
name|p
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
break|break;
case|case
name|T_CTRL
case|:
if|if
condition|(
operator|!
name|ctrl_body_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
name|p
operator|-
name|hdrlen
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
break|break;
case|case
name|T_DATA
case|:
if|if
condition|(
name|DATA_FRAME_IS_NULL
argument_list|(
name|FC_SUBTYPE
argument_list|(
name|fc
argument_list|)
argument_list|)
condition|)
return|return
name|hdrlen
return|;
comment|/* no-data frame */
comment|/* There may be a problem w/ AP not having this bit set */
if|if
condition|(
name|FC_WEP
argument_list|(
name|fc
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|wep_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|hdrlen
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|llc_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|,
name|dst
argument_list|,
name|src
argument_list|,
operator|&
name|extracted_ethertype
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* 			 * Some kinds of LLC packet we cannot 			 * handle intelligently 			 */
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ieee_802_11_hdr_print
argument_list|(
name|ndo
argument_list|,
name|fc
argument_list|,
name|p
operator|-
name|hdrlen
argument_list|,
name|hdrlen
argument_list|,
name|meshdrlen
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|extracted_ethertype
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(LLC %s) "
operator|,
name|etherproto_string
argument_list|(
name|htons
argument_list|(
name|extracted_ethertype
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_suppress_default_print
condition|)
name|ND_DEFAULTPRINT
argument_list|(
name|p
argument_list|,
name|caplen
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"unknown 802.11 frame type (%d)"
operator|,
name|FC_TYPE
argument_list|(
name|fc
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|hdrlen
return|;
block|}
end_function

begin_comment
comment|/*  * This is the top level routine of the printer.  'p' points  * to the 802.11 header of the packet, 'h->ts' is the timestamp,  * 'h->len' is the length of the packet off the wire, and 'h->caplen'  * is the number of bytes actually captured.  */
end_comment

begin_function
name|u_int
name|ieee802_11_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IEEE80211_CHAN_FHSS
define|\
value|(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_GFSK)
end_define

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
name|IS_CHAN_FHSS
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_FHSS) == IEEE80211_CHAN_FHSS)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_A
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_B
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_PUREG
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_G
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
end_define

begin_define
define|#
directive|define
name|IS_CHAN_ANYG
parameter_list|(
name|flags
parameter_list|)
define|\
value|(IS_CHAN_PUREG(flags) || IS_CHAN_G(flags))
end_define

begin_function
specifier|static
name|void
name|print_chaninfo
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|int
name|freq
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%u MHz"
operator|,
name|freq
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|IS_CHAN_FHSS
argument_list|(
name|flags
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" FHSS"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|IS_CHAN_A
argument_list|(
name|flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HALF
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11a/10Mhz"
operator|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_QUARTER
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11a/5Mhz"
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11a"
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|IS_CHAN_ANYG
argument_list|(
name|flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HALF
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11g/10Mhz"
operator|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_QUARTER
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11g/5Mhz"
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11g"
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IS_CHAN_B
argument_list|(
name|flags
argument_list|)
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" 11b"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_TURBO
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" Turbo"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT20
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" ht/20"
operator|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT40D
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" ht/40-"
operator|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|IEEE80211_CHAN_HT40U
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" ht/40+"
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" "
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_radiotap_field
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|struct
name|cpack_state
modifier|*
name|s
parameter_list|,
name|uint32_t
name|bit
parameter_list|,
name|uint8_t
modifier|*
name|flags
parameter_list|,
name|struct
name|radiotap_state
modifier|*
name|state
parameter_list|,
name|uint32_t
name|presentflags
parameter_list|)
block|{
union|union
block|{
name|int8_t
name|i8
decl_stmt|;
name|uint8_t
name|u8
decl_stmt|;
name|int16_t
name|i16
decl_stmt|;
name|uint16_t
name|u16
decl_stmt|;
name|uint32_t
name|u32
decl_stmt|;
name|uint64_t
name|u64
decl_stmt|;
block|}
name|u
union|,
name|u2
union|,
name|u3
union|,
name|u4
union|;
name|int
name|rc
decl_stmt|;
switch|switch
condition|(
name|bit
condition|)
block|{
case|case
name|IEEE80211_RADIOTAP_FLAGS
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
operator|*
name|flags
operator|=
name|u
operator|.
name|u8
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RATE
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
comment|/* Save state rate */
name|state
operator|->
name|rate
operator|=
name|u
operator|.
name|u8
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
case|:
case|case
name|IEEE80211_RADIOTAP_DB_ANTNOISE
case|:
case|case
name|IEEE80211_RADIOTAP_ANTENNA
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
case|:
case|case
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
case|:
name|rc
operator|=
name|cpack_int8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_CHANNEL
case|:
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FHSS
case|:
case|case
name|IEEE80211_RADIOTAP_LOCK_QUALITY
case|:
case|case
name|IEEE80211_RADIOTAP_TX_ATTENUATION
case|:
case|case
name|IEEE80211_RADIOTAP_RX_FLAGS
case|:
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_TX_POWER
case|:
name|rc
operator|=
name|cpack_int8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|i8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TSFT
case|:
name|rc
operator|=
name|cpack_uint64
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u64
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_XCHANNEL
case|:
name|rc
operator|=
name|cpack_uint32
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u32
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u4
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_MCS
case|:
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u2
operator|.
name|u8
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|u3
operator|.
name|u8
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_VENDOR_NAMESPACE
case|:
block|{
name|uint8_t
name|vns
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|subspace
decl_stmt|;
if|if
condition|(
operator|(
name|cpack_align_and_reserve
argument_list|(
name|s
argument_list|,
literal|2
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|rc
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|vns
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint8
argument_list|(
name|s
argument_list|,
operator|&
name|subspace
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
name|rc
operator|=
name|cpack_uint16
argument_list|(
name|s
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
break|break;
comment|/* Skip up to length */
name|s
operator|->
name|c_next
operator|+=
name|length
expr_stmt|;
break|break;
block|}
default|default:
comment|/* this bit indicates a field whose 		 * size we do not know, so we cannot 		 * proceed.  Just print the bit number. 		 */
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[bit %u] "
operator|,
name|bit
operator|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|rc
operator|!=
literal|0
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|rc
return|;
block|}
comment|/* Preserve the state present flags */
name|state
operator|->
name|present
operator|=
name|presentflags
expr_stmt|;
switch|switch
condition|(
name|bit
condition|)
block|{
case|case
name|IEEE80211_RADIOTAP_CHANNEL
case|:
comment|/* 		 * If CHANNEL and XCHANNEL are both present, skip 		 * CHANNEL. 		 */
if|if
condition|(
name|presentflags
operator|&
operator|(
literal|1
operator|<<
name|IEEE80211_RADIOTAP_XCHANNEL
operator|)
condition|)
break|break;
name|print_chaninfo
argument_list|(
name|ndo
argument_list|,
name|u
operator|.
name|u16
argument_list|,
name|u2
operator|.
name|u16
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FHSS
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"fhset %d fhpat %d "
operator|,
name|u
operator|.
name|u16
operator|&
literal|0xff
operator|,
operator|(
name|u
operator|.
name|u16
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RATE
case|:
comment|/* 		 * XXX On FreeBSD rate& 0x80 means we have an MCS. On 		 * Linux and AirPcap it does not.  (What about 		 * Mac OS X, NetBSD, OpenBSD, and DragonFly BSD?) 		 * 		 * This is an issue either for proprietary extensions 		 * to 11a or 11g, which do exist, or for 11n 		 * implementations that stuff a rate value into 		 * this field, which also appear to exist. 		 * 		 * We currently handle that by assuming that 		 * if the 0x80 bit is set *and* the remaining 		 * bits have a value between 0 and 15 it's 		 * an MCS value, otherwise it's a rate.  If 		 * there are cases where systems that use 		 * "0x80 + MCS index" for MCS indices> 15, 		 * or stuff a rate value here between 64 and 		 * 71.5 Mb/s in here, we'll need a preference 		 * setting.  Such rates do exist, e.g. 11n 		 * MCS 7 at 20 MHz with a long guard interval. 		 */
if|if
condition|(
name|u
operator|.
name|u8
operator|>=
literal|0x80
operator|&&
name|u
operator|.
name|u8
operator|<=
literal|0x8f
condition|)
block|{
comment|/* 			 * XXX - we don't know the channel width 			 * or guard interval length, so we can't 			 * convert this to a data rate. 			 * 			 * If you want us to show a data rate, 			 * use the MCS field, not the Rate field; 			 * the MCS field includes not only the 			 * MCS index, it also includes bandwidth 			 * and guard interval information. 			 * 			 * XXX - can we get the channel width 			 * from XChannel and the guard interval 			 * information from Flags, at least on 			 * FreeBSD? 			 */
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MCS %u "
operator|,
name|u
operator|.
name|u8
operator|&
literal|0x7f
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%2.1f Mb/s "
operator|,
literal|.5
operator|*
name|u
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTSIGNAL
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddB signal "
operator|,
name|u
operator|.
name|i8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_ANTNOISE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddB noise "
operator|,
name|u
operator|.
name|i8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTSIGNAL
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddB signal "
operator|,
name|u
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_ANTNOISE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddB noise "
operator|,
name|u
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_LOCK_QUALITY
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%u sq "
operator|,
name|u
operator|.
name|u16
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TX_ATTENUATION
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%d tx power "
operator|,
operator|-
operator|(
name|int
operator|)
name|u
operator|.
name|u16
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DB_TX_ATTENUATION
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddB tx power "
operator|,
operator|-
operator|(
name|int
operator|)
name|u
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_DBM_TX_POWER
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ddBm tx power "
operator|,
name|u
operator|.
name|i8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_FLAGS
case|:
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_CFP
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"cfp "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_SHORTPRE
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"short preamble "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_WEP
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"wep "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_FRAG
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"fragmented "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_F_BADFCS
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"bad-fcs "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_ANTENNA
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"antenna %d "
operator|,
name|u
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_TSFT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%"
name|PRIu64
literal|"us tsft "
operator|,
name|u
operator|.
name|u64
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_RX_FLAGS
case|:
comment|/* Do nothing for now */
break|break;
case|case
name|IEEE80211_RADIOTAP_XCHANNEL
case|:
name|print_chaninfo
argument_list|(
name|ndo
argument_list|,
name|u2
operator|.
name|u16
argument_list|,
name|u
operator|.
name|u32
argument_list|)
expr_stmt|;
break|break;
case|case
name|IEEE80211_RADIOTAP_MCS
case|:
block|{
specifier|static
specifier|const
name|char
modifier|*
name|bandwidth
index|[
literal|4
index|]
init|=
block|{
literal|"20 MHz"
block|,
literal|"40 MHz"
block|,
literal|"20 MHz (L)"
block|,
literal|"20 MHz (U)"
block|}
decl_stmt|;
name|float
name|htrate
decl_stmt|;
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_MCS_INDEX_KNOWN
condition|)
block|{
comment|/* 			 * We know the MCS index. 			 */
if|if
condition|(
name|u3
operator|.
name|u8
operator|<=
name|MAX_MCS_INDEX
condition|)
block|{
comment|/* 				 * And it's in-range. 				 */
if|if
condition|(
name|u
operator|.
name|u8
operator|&
operator|(
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
operator||
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
operator|)
condition|)
block|{
comment|/* 					 * And we know both the bandwidth and 					 * the guard interval, so we can look 					 * up the rate. 					 */
name|htrate
operator|=
name|ieee80211_float_htrates
name|\
index|[
name|u3
operator|.
name|u8
index|]
name|\
index|[
operator|(
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
operator|)
operator|==
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_40
condition|?
literal|1
else|:
literal|0
operator|)
index|]
name|\
index|[
operator|(
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
index|]
expr_stmt|;
block|}
else|else
block|{
comment|/* 					 * We don't know both the bandwidth 					 * and the guard interval, so we can 					 * only report the MCS index. 					 */
name|htrate
operator|=
literal|0.0
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 				 * The MCS value is out of range. 				 */
name|htrate
operator|=
literal|0.0
expr_stmt|;
block|}
if|if
condition|(
name|htrate
operator|!=
literal|0.0
condition|)
block|{
comment|/* 				 * We have the rate. 				 * Print it. 				 */
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%.1f Mb/s MCS %u "
operator|,
name|htrate
operator|,
name|u3
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 				 * We at least have the MCS index. 				 * Print it. 				 */
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MCS %u "
operator|,
name|u3
operator|.
name|u8
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_KNOWN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s "
operator|,
name|bandwidth
index|[
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_BANDWIDTH_MASK
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_GUARD_INTERVAL_KNOWN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s GI "
operator|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_SHORT_GI
operator|)
condition|?
literal|"short"
else|:
literal|"lon"
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_HT_FORMAT_KNOWN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s "
operator|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_HT_GREENFIELD
operator|)
condition|?
literal|"greenfield"
else|:
literal|"mixed"
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_FEC_TYPE_KNOWN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s FEC "
operator|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_FEC_LDPC
operator|)
condition|?
literal|"LDPC"
else|:
literal|"BCC"
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|u
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_STBC_KNOWN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RX-STBC%u "
operator|,
operator|(
name|u2
operator|.
name|u8
operator|&
name|IEEE80211_RADIOTAP_MCS_STBC_MASK
operator|)
operator|>>
name|IEEE80211_RADIOTAP_MCS_STBC_SHIFT
operator|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|u_int
name|ieee802_11_radio_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
define|#
directive|define
name|BITNO_32
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16) ? 16 + BITNO_16((x)>> 16) : BITNO_16((x)))
define|#
directive|define
name|BITNO_16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8) ? 8 + BITNO_8((x)>> 8) : BITNO_8((x)))
define|#
directive|define
name|BITNO_8
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4) ? 4 + BITNO_4((x)>> 4) : BITNO_4((x)))
define|#
directive|define
name|BITNO_4
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2) ? 2 + BITNO_2((x)>> 2) : BITNO_2((x)))
define|#
directive|define
name|BITNO_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 2) ? 1 : 0)
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1U<< n)
define|#
directive|define
name|IS_EXTENDED
parameter_list|(
name|__p
parameter_list|)
define|\
value|(EXTRACT_LE_32BITS(__p)& BIT(IEEE80211_RADIOTAP_EXT)) != 0
name|struct
name|cpack_state
name|cpacker
decl_stmt|;
name|struct
name|ieee80211_radiotap_header
modifier|*
name|hdr
decl_stmt|;
name|uint32_t
name|present
decl_stmt|,
name|next_present
decl_stmt|;
name|uint32_t
name|presentflags
init|=
literal|0
decl_stmt|;
name|uint32_t
modifier|*
name|presentp
decl_stmt|,
modifier|*
name|last_presentp
decl_stmt|;
name|enum
name|ieee80211_radiotap_type
name|bit
decl_stmt|;
name|int
name|bit0
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|int
name|pad
decl_stmt|;
name|u_int
name|fcslen
decl_stmt|;
name|struct
name|radiotap_state
name|state
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
sizeof|sizeof
argument_list|(
operator|*
name|hdr
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|hdr
operator|=
operator|(
expr|struct
name|ieee80211_radiotap_header
operator|*
operator|)
name|p
expr_stmt|;
name|len
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
operator|&
name|hdr
operator|->
name|it_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|caplen
operator|<
name|len
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|cpack_init
argument_list|(
operator|&
name|cpacker
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
name|hdr
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* align against header start */
name|cpack_advance
argument_list|(
operator|&
name|cpacker
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|hdr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* includes the 1st bitmap */
for|for
control|(
name|last_presentp
operator|=
operator|&
name|hdr
operator|->
name|it_present
init|;
name|IS_EXTENDED
argument_list|(
name|last_presentp
argument_list|)
operator|&&
operator|(
name|u_char
operator|*
operator|)
operator|(
name|last_presentp
operator|+
literal|1
operator|)
operator|<=
name|p
operator|+
name|len
condition|;
name|last_presentp
operator|++
control|)
name|cpack_advance
argument_list|(
operator|&
name|cpacker
argument_list|,
sizeof|sizeof
argument_list|(
name|hdr
operator|->
name|it_present
argument_list|)
argument_list|)
expr_stmt|;
comment|/* more bitmaps */
comment|/* are there more bitmap extensions than bytes in header? */
if|if
condition|(
name|IS_EXTENDED
argument_list|(
name|last_presentp
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
comment|/* Assume no flags */
name|flags
operator|=
literal|0
expr_stmt|;
comment|/* Assume no Atheros padding between 802.11 header and body */
name|pad
operator|=
literal|0
expr_stmt|;
comment|/* Assume no FCS at end of frame */
name|fcslen
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|bit0
operator|=
literal|0
operator|,
name|presentp
operator|=
operator|&
name|hdr
operator|->
name|it_present
init|;
name|presentp
operator|<=
name|last_presentp
condition|;
name|presentp
operator|++
operator|,
name|bit0
operator|+=
literal|32
control|)
block|{
name|presentflags
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|presentp
argument_list|)
expr_stmt|;
comment|/* Clear state. */
name|memset
argument_list|(
operator|&
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|present
operator|=
name|EXTRACT_LE_32BITS
argument_list|(
name|presentp
argument_list|)
init|;
name|present
condition|;
name|present
operator|=
name|next_present
control|)
block|{
comment|/* clear the least significant bit that is set */
name|next_present
operator|=
name|present
operator|&
operator|(
name|present
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* extract the least significant bit that is set */
name|bit
operator|=
operator|(
expr|enum
name|ieee80211_radiotap_type
operator|)
operator|(
name|bit0
operator|+
name|BITNO_32
argument_list|(
name|present
operator|^
name|next_present
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|print_radiotap_field
argument_list|(
name|ndo
argument_list|,
operator|&
name|cpacker
argument_list|,
name|bit
argument_list|,
operator|&
name|flags
argument_list|,
operator|&
name|state
argument_list|,
name|presentflags
argument_list|)
operator|!=
literal|0
condition|)
goto|goto
name|out
goto|;
block|}
block|}
name|out
label|:
if|if
condition|(
name|flags
operator|&
name|IEEE80211_RADIOTAP_F_DATAPAD
condition|)
name|pad
operator|=
literal|1
expr_stmt|;
comment|/* Atheros padding */
if|if
condition|(
name|flags
operator|&
name|IEEE80211_RADIOTAP_F_FCS
condition|)
name|fcslen
operator|=
literal|4
expr_stmt|;
comment|/* FCS at end of packet */
return|return
name|len
operator|+
name|ieee802_11_print
argument_list|(
name|ndo
argument_list|,
name|p
operator|+
name|len
argument_list|,
name|length
operator|-
name|len
argument_list|,
name|caplen
operator|-
name|len
argument_list|,
name|pad
argument_list|,
name|fcslen
argument_list|)
return|;
undef|#
directive|undef
name|BITNO_32
undef|#
directive|undef
name|BITNO_16
undef|#
directive|undef
name|BITNO_8
undef|#
directive|undef
name|BITNO_4
undef|#
directive|undef
name|BITNO_2
undef|#
directive|undef
name|BIT
block|}
end_function

begin_function
specifier|static
name|u_int
name|ieee802_11_avs_radio_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
name|uint32_t
name|caphdr_len
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
literal|8
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|caphdr_len
operator|=
name|EXTRACT_32BITS
argument_list|(
name|p
operator|+
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|caphdr_len
operator|<
literal|8
condition|)
block|{
comment|/* 		 * Yow!  The capture header length is claimed not 		 * to be large enough to include even the version 		 * cookie or capture header length! 		 */
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
if|if
condition|(
name|caplen
operator|<
name|caphdr_len
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
return|return
name|caphdr_len
operator|+
name|ieee802_11_print
argument_list|(
name|ndo
argument_list|,
name|p
operator|+
name|caphdr_len
argument_list|,
name|length
operator|-
name|caphdr_len
argument_list|,
name|caplen
operator|-
name|caphdr_len
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PRISM_HDR_LEN
value|144
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_BASE
value|0x80211000
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_V1
value|0x80211001
end_define

begin_define
define|#
directive|define
name|WLANCAP_MAGIC_COOKIE_V2
value|0x80211002
end_define

begin_comment
comment|/*  * For DLT_PRISM_HEADER; like DLT_IEEE802_11, but with an extra header,  * containing information such as radio information, which we  * currently ignore.  *  * If, however, the packet begins with WLANCAP_MAGIC_COOKIE_V1 or  * WLANCAP_MAGIC_COOKIE_V2, it's really DLT_IEEE802_11_RADIO_AVS  * (currently, on Linux, there's no ARPHRD_ type for  * DLT_IEEE802_11_RADIO_AVS, as there is a ARPHRD_IEEE80211_PRISM  * for DLT_PRISM_HEADER, so ARPHRD_IEEE80211_PRISM is used for  * the AVS header, and the first 4 bytes of the header are used to  * indicate whether it's a Prism header or an AVS header).  */
end_comment

begin_function
name|u_int
name|prism_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
name|u_int
name|caplen
init|=
name|h
operator|->
name|caplen
decl_stmt|;
name|u_int
name|length
init|=
name|h
operator|->
name|len
decl_stmt|;
name|uint32_t
name|msgcode
decl_stmt|;
if|if
condition|(
name|caplen
operator|<
literal|4
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
name|msgcode
operator|=
name|EXTRACT_32BITS
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|msgcode
operator|==
name|WLANCAP_MAGIC_COOKIE_V1
operator|||
name|msgcode
operator|==
name|WLANCAP_MAGIC_COOKIE_V2
condition|)
return|return
name|ieee802_11_avs_radio_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|)
return|;
if|if
condition|(
name|caplen
operator|<
name|PRISM_HDR_LEN
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return
name|caplen
return|;
block|}
return|return
name|PRISM_HDR_LEN
operator|+
name|ieee802_11_print
argument_list|(
name|ndo
argument_list|,
name|p
operator|+
name|PRISM_HDR_LEN
argument_list|,
name|length
operator|-
name|PRISM_HDR_LEN
argument_list|,
name|caplen
operator|-
name|PRISM_HDR_LEN
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * For DLT_IEEE802_11_RADIO; like DLT_IEEE802_11, but with an extra  * header, containing information such as radio information.  */
end_comment

begin_function
name|u_int
name|ieee802_11_radio_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_radio_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * For DLT_IEEE802_11_RADIO_AVS; like DLT_IEEE802_11, but with an  * extra header, containing information such as radio information,  * which we currently ignore.  */
end_comment

begin_function
name|u_int
name|ieee802_11_radio_avs_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
return|return
name|ieee802_11_avs_radio_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|,
name|h
operator|->
name|caplen
argument_list|)
return|;
block|}
end_function

end_unit

