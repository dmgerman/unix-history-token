begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/ieee802_11.h,v 1.9 2003/07/22 17:36:57 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001  *	Fortress Technologies  *      Charlie Lenahan ( clenahan@fortresstech.com )  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

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

begin_comment
comment|/* RESERVED 			0xD  */
end_comment

begin_comment
comment|/* RESERVED 			0xE  */
end_comment

begin_comment
comment|/* RESERVED 			0xF  */
end_comment

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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|da
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|sa
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
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
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|rate
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|challenge_t
block|{
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int16_t
name|dwell_time
decl_stmt|;
name|u_int8_t
name|hop_set
decl_stmt|;
name|u_int8_t
name|hop_pattern
decl_stmt|;
name|u_int8_t
name|hop_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_t
block|{
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|channel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cf_t
block|{
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|count
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|u_int16_t
name|max_duration
decl_stmt|;
name|u_int16_t
name|dur_remaing
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tim_t
block|{
name|u_int8_t
name|element_id
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|count
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|bitmap_control
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|timestamp
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|beacon_interval
decl_stmt|;
name|u_int16_t
name|listen_interval
decl_stmt|;
name|u_int16_t
name|status_code
decl_stmt|;
name|u_int16_t
name|aid
decl_stmt|;
name|u_char
name|ap
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|reason_code
decl_stmt|;
name|u_int16_t
name|auth_alg
decl_stmt|;
name|u_int16_t
name|auth_trans_seq_num
decl_stmt|;
name|struct
name|challenge_t
name|challenge
decl_stmt|;
name|u_int16_t
name|capability_info
decl_stmt|;
name|struct
name|ssid_t
name|ssid
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
name|fh_t
name|fh
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|ta
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|aid
decl_stmt|;
name|u_int8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|ta
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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
name|u_int16_t
name|fc
decl_stmt|;
name|u_int16_t
name|duration
decl_stmt|;
name|u_int8_t
name|ra
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
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

end_unit

