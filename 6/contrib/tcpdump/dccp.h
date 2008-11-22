begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/dccp.h,v 1.1.2.2 2005/09/20 06:25:45 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (C) Arnaldo Carvalho de Melo 2004  * Copyright (C) Ian McDonald 2005<iam4@cs.waikato.ac.nz>  * Copyright (C) Yoshifumi Nishida 2005  *  * This software may be distributed either under the terms of the  * BSD-style license that accompanies tcpdump or the GNU GPL version 2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DCCP_HDR__
end_ifndef

begin_define
define|#
directive|define
name|__DCCP_HDR__
end_define

begin_comment
comment|/**  * struct dccp_hdr - generic part of DCCP packet header  *  * @dccph_sport - Relevant port on the endpoint that sent this packet  * @dccph_dport - Relevant port on the other endpoint  * @dccph_doff - Data Offset from the start of the DCCP header, in 32-bit words  * @dccph_ccval - Used by the HC-Sender CCID  * @dccph_cscov - Parts of the packet that are covered by the Checksum field  * @dccph_checksum - Internet checksum, depends on dccph_cscov  * @dccph_x - 0 = 24 bit sequence number, 1 = 48  * @dccph_type - packet type, see DCCP_PKT_ prefixed macros  * @dccph_seq - sequence number high or low order 24 bits, depends on dccph_x  */
end_comment

begin_struct
struct|struct
name|dccp_hdr
block|{
name|u_int16_t
name|dccph_sport
decl_stmt|,
name|dccph_dport
decl_stmt|;
name|u_int8_t
name|dccph_doff
decl_stmt|;
name|u_int8_t
name|dccph_ccval_cscov
decl_stmt|;
name|u_int16_t
name|dccph_checksum
decl_stmt|;
union|union
block|{
name|u_int8_t
name|dccph_xtr
decl_stmt|;
name|u_int32_t
name|dccph_seq
decl_stmt|;
block|}
name|dccph_xtrs
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DCCPH_CCVAL
parameter_list|(
name|dh
parameter_list|)
value|(((dh)->dccph_ccval_cscov)& 0x0F)
end_define

begin_define
define|#
directive|define
name|DCCPH_CSCOV
parameter_list|(
name|dh
parameter_list|)
value|(((dh)->dccph_ccval_cscov>> 4)& 0x0F)
end_define

begin_define
define|#
directive|define
name|DCCPH_X
parameter_list|(
name|dh
parameter_list|)
value|((dh)->dccph_xtrs.dccph_xtr& 1)
end_define

begin_define
define|#
directive|define
name|DCCPH_TYPE
parameter_list|(
name|dh
parameter_list|)
value|(((dh)->dccph_xtrs.dccph_xtr>> 1)& 0xF)
end_define

begin_define
define|#
directive|define
name|DCCPH_SEQ
parameter_list|(
name|dh
parameter_list|)
value|(((dh)->dccph_xtrs.dccph_seq)>> 8)
end_define

begin_comment
comment|/**  * struct dccp_hdr_ext - the low bits of a 48 bit seq packet  *  * @dccph_seq_low - low 24 bits of a 48 bit seq packet  */
end_comment

begin_struct
struct|struct
name|dccp_hdr_ext
block|{
name|u_int32_t
name|dccph_seq_low
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct dccp_hdr_request - Conection initiation request header  *  * @dccph_req_service - Service to which the client app wants to connect  */
end_comment

begin_struct
struct|struct
name|dccp_hdr_request
block|{
name|u_int32_t
name|dccph_req_service
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct dccp_hdr_ack_bits - acknowledgment bits common to most packets  *  * @dccph_resp_ack_nr_high - 48 bit ack number high order bits, contains GSR  * @dccph_resp_ack_nr_low - 48 bit ack number low order bits, contains GSR  */
end_comment

begin_struct
struct|struct
name|dccp_hdr_ack_bits
block|{
name|u_int32_t
name|dccph_ra
decl_stmt|;
name|u_int32_t
name|dccph_ack_nr_low
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DCCPH_ACK
parameter_list|(
name|dh_ack
parameter_list|)
value|((dh_ack)->dccph_ra>> 8)
end_define

begin_comment
comment|/**  * struct dccp_hdr_response - Conection initiation response header  *  * @dccph_resp_ack_nr_high - 48 bit ack number high order bits, contains GSR  * @dccph_resp_ack_nr_low - 48 bit ack number low order bits, contains GSR  * @dccph_resp_service - Echoes the Service Code on a received DCCP-Request  */
end_comment

begin_struct
struct|struct
name|dccp_hdr_response
block|{
name|struct
name|dccp_hdr_ack_bits
name|dccph_resp_ack
decl_stmt|;
name|u_int32_t
name|dccph_resp_service
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|dccp_hdr_data
modifier|*
name|dccp_hdr_data
parameter_list|(
name|struct
name|dccp_hdr
modifier|*
name|hdrg
parameter_list|)
block|{
specifier|const
name|int
name|ext
init|=
name|DCCPH_X
argument_list|(
name|hdrg
argument_list|)
condition|?
sizeof|sizeof
argument_list|(
expr|struct
name|dccp_hdr_ext
argument_list|)
else|:
literal|0
decl_stmt|;
return|return
operator|(
expr|struct
name|dccp_hdr_data
operator|*
operator|)
operator|(
operator|(
operator|(
name|u_char
operator|*
operator|)
name|hdrg
operator|)
operator|+
sizeof|sizeof
argument_list|(
name|hdrg
argument_list|)
operator|+
name|ext
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * struct dccp_hdr_reset - Unconditionally shut down a connection  *  * @dccph_reset_service - Echoes the Service Code on a received DCCP-Request  */
end_comment

begin_struct
struct|struct
name|dccp_hdr_reset
block|{
name|struct
name|dccp_hdr_ack_bits
name|dccph_reset_ack
decl_stmt|;
name|u_int8_t
name|dccph_reset_code
decl_stmt|,
name|dccph_reset_data
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|dccp_pkt_type
block|{
name|DCCP_PKT_REQUEST
init|=
literal|0
block|,
name|DCCP_PKT_RESPONSE
block|,
name|DCCP_PKT_DATA
block|,
name|DCCP_PKT_ACK
block|,
name|DCCP_PKT_DATAACK
block|,
name|DCCP_PKT_CLOSEREQ
block|,
name|DCCP_PKT_CLOSE
block|,
name|DCCP_PKT_RESET
block|,
name|DCCP_PKT_SYNC
block|,
name|DCCP_PKT_SYNCACK
block|,
name|DCCP_PKT_INVALID
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|dccp_reset_codes
block|{
name|DCCP_RESET_CODE_UNSPECIFIED
init|=
literal|0
block|,
name|DCCP_RESET_CODE_CLOSED
block|,
name|DCCP_RESET_CODE_ABORTED
block|,
name|DCCP_RESET_CODE_NO_CONNECTION
block|,
name|DCCP_RESET_CODE_PACKET_ERROR
block|,
name|DCCP_RESET_CODE_OPTION_ERROR
block|,
name|DCCP_RESET_CODE_MANDATORY_ERROR
block|,
name|DCCP_RESET_CODE_CONNECTION_REFUSED
block|,
name|DCCP_RESET_CODE_BAD_SERVICE_CODE
block|,
name|DCCP_RESET_CODE_TOO_BUSY
block|,
name|DCCP_RESET_CODE_BAD_INIT_COOKIE
block|,
name|DCCP_RESET_CODE_AGGRESSION_PENALTY
block|,
name|__DCCP_RESET_CODE_LAST
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DCCP_HDR__ */
end_comment

end_unit

