begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Message formatting blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SIG_MSG_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SIG_MSG_H
end_define

begin_define
define|#
directive|define
name|UNI_MSG_DISC_Q93B
value|0x09
end_define

begin_define
define|#
directive|define
name|UNI_MSG_MIN_LEN
value|9
end_define

begin_comment
comment|/*  * Values for Q.2931 message type.  */
end_comment

begin_define
define|#
directive|define
name|UNI_MSG_CALP
value|0x02
end_define

begin_define
define|#
directive|define
name|UNI_MSG_CONN
value|0x07
end_define

begin_define
define|#
directive|define
name|UNI_MSG_CACK
value|0x0F
end_define

begin_define
define|#
directive|define
name|UNI_MSG_SETU
value|0x05
end_define

begin_define
define|#
directive|define
name|UNI_MSG_RLSE
value|0x4D
end_define

begin_define
define|#
directive|define
name|UNI_MSG_RLSC
value|0x5A
end_define

begin_define
define|#
directive|define
name|UNI_MSG_RSTR
value|0x46
end_define

begin_define
define|#
directive|define
name|UNI_MSG_RSTA
value|0x4E
end_define

begin_define
define|#
directive|define
name|UNI_MSG_STAT
value|0x7D
end_define

begin_define
define|#
directive|define
name|UNI_MSG_SENQ
value|0x75
end_define

begin_define
define|#
directive|define
name|UNI_MSG_ADDP
value|0x80
end_define

begin_define
define|#
directive|define
name|UNI_MSG_ADPA
value|0x81
end_define

begin_define
define|#
directive|define
name|UNI_MSG_ADPR
value|0x82
end_define

begin_define
define|#
directive|define
name|UNI_MSG_DRPP
value|0x83
end_define

begin_define
define|#
directive|define
name|UNI_MSG_DRPA
value|0x84
end_define

begin_comment
comment|/*  * Values for information element identifier.  */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS
value|0x08
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST
value|0x14
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPRF
value|0x54
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST
value|0x55
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP
value|0x58
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT
value|0x59
end_define

begin_define
define|#
directive|define
name|UNI_IE_CNID
value|0x5A
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP
value|0x5C
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI
value|0x5D
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP
value|0x5E
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI
value|0x5F
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLSH
value|0x60
end_define

begin_define
define|#
directive|define
name|UNI_IE_BNSH
value|0x61
end_define

begin_define
define|#
directive|define
name|UNI_IE_BSDC
value|0x62
end_define

begin_define
define|#
directive|define
name|UNI_IE_BRPI
value|0x63
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD
value|0x6C
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGSA
value|0x6D
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD
value|0x70
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDSA
value|0x71
end_define

begin_define
define|#
directive|define
name|UNI_IE_TRNT
value|0x78
end_define

begin_define
define|#
directive|define
name|UNI_IE_RSTI
value|0x79
end_define

begin_comment
comment|/*  * Masks for information element extension in bit 8  */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_EXT_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|UNI_IE_EXT_MASK
value|0x7F
end_define

begin_comment
comment|/*  * Signalling message in internal format.  */
end_comment

begin_define
define|#
directive|define
name|UNI_MSG_IE_CNT
value|22
end_define

begin_struct
struct|struct
name|unisig_msg
block|{
name|u_int
name|msg_call_ref
decl_stmt|;
name|u_char
name|msg_type
decl_stmt|;
name|u_char
name|msg_type_flag
decl_stmt|;
name|u_char
name|msg_type_action
decl_stmt|;
name|int
name|msg_length
decl_stmt|;
name|struct
name|ie_generic
modifier|*
name|msg_ie_vec
index|[
name|UNI_MSG_IE_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_MSG_CALL_REF_RMT
value|0x800000
end_define

begin_define
define|#
directive|define
name|UNI_MSG_CALL_REF_MASK
value|0x7FFFFF
end_define

begin_define
define|#
directive|define
name|UNI_MSG_CALL_REF_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_MSG_CALL_REF_DUMMY
value|0x7FFFFF
end_define

begin_define
define|#
directive|define
name|EXTRACT_CREF
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& UNI_MSG_CALL_REF_RMT ? (x)& UNI_MSG_CALL_REF_MASK : (x) | UNI_MSG_CALL_REF_RMT)
end_define

begin_define
define|#
directive|define
name|GLOBAL_CREF
parameter_list|(
name|x
parameter_list|)
value|(((x)& UNI_MSG_CALL_REF_MASK) == UNI_MSG_CALL_REF_GLOBAL)
end_define

begin_define
define|#
directive|define
name|DUMMY_CREF
parameter_list|(
name|x
parameter_list|)
value|(((x)& UNI_MSG_CALL_REF_MASK) == UNI_MSG_CALL_REF_DUMMY)
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_FLAG_MASK
value|1
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_FLAG_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_ACT_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_ACT_DISC
value|1
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_ACT_RPRT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_ACT_RSVD
value|3
end_define

begin_define
define|#
directive|define
name|UNI_MSG_TYPE_ACT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_AALP
value|0
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CLRT
value|1
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BBCP
value|2
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BHLI
value|3
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BLLI
value|4
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CLST
value|5
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CDAD
value|6
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CDSA
value|7
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CGAD
value|8
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CGSA
value|9
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CAUS
value|10
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_CNID
value|11
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_QOSP
value|12
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BRPI
value|13
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_RSTI
value|14
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BLSH
value|15
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BNSH
value|16
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_BSDC
value|17
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_TRNT
value|18
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_EPRF
value|19
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_EPST
value|20
end_define

begin_define
define|#
directive|define
name|UNI_MSG_IE_ERR
value|21
end_define

begin_define
define|#
directive|define
name|msg_ie_aalp
value|msg_ie_vec[UNI_MSG_IE_AALP]
end_define

begin_define
define|#
directive|define
name|msg_ie_clrt
value|msg_ie_vec[UNI_MSG_IE_CLRT]
end_define

begin_define
define|#
directive|define
name|msg_ie_bbcp
value|msg_ie_vec[UNI_MSG_IE_BBCP]
end_define

begin_define
define|#
directive|define
name|msg_ie_bhli
value|msg_ie_vec[UNI_MSG_IE_BHLI]
end_define

begin_define
define|#
directive|define
name|msg_ie_blli
value|msg_ie_vec[UNI_MSG_IE_BLLI]
end_define

begin_define
define|#
directive|define
name|msg_ie_clst
value|msg_ie_vec[UNI_MSG_IE_CLST]
end_define

begin_define
define|#
directive|define
name|msg_ie_cdad
value|msg_ie_vec[UNI_MSG_IE_CDAD]
end_define

begin_define
define|#
directive|define
name|msg_ie_cdsa
value|msg_ie_vec[UNI_MSG_IE_CDSA]
end_define

begin_define
define|#
directive|define
name|msg_ie_cgad
value|msg_ie_vec[UNI_MSG_IE_CGAD]
end_define

begin_define
define|#
directive|define
name|msg_ie_cgsa
value|msg_ie_vec[UNI_MSG_IE_CGSA]
end_define

begin_define
define|#
directive|define
name|msg_ie_caus
value|msg_ie_vec[UNI_MSG_IE_CAUS]
end_define

begin_define
define|#
directive|define
name|msg_ie_cnid
value|msg_ie_vec[UNI_MSG_IE_CNID]
end_define

begin_define
define|#
directive|define
name|msg_ie_qosp
value|msg_ie_vec[UNI_MSG_IE_QOSP]
end_define

begin_define
define|#
directive|define
name|msg_ie_brpi
value|msg_ie_vec[UNI_MSG_IE_BRPI]
end_define

begin_define
define|#
directive|define
name|msg_ie_rsti
value|msg_ie_vec[UNI_MSG_IE_RSTI]
end_define

begin_define
define|#
directive|define
name|msg_ie_blsh
value|msg_ie_vec[UNI_MSG_IE_BLSH]
end_define

begin_define
define|#
directive|define
name|msg_ie_bnsh
value|msg_ie_vec[UNI_MSG_IE_BNSH]
end_define

begin_define
define|#
directive|define
name|msg_ie_bsdc
value|msg_ie_vec[UNI_MSG_IE_BSDC]
end_define

begin_define
define|#
directive|define
name|msg_ie_trnt
value|msg_ie_vec[UNI_MSG_IE_TRNT]
end_define

begin_define
define|#
directive|define
name|msg_ie_eprf
value|msg_ie_vec[UNI_MSG_IE_EPRF]
end_define

begin_define
define|#
directive|define
name|msg_ie_epst
value|msg_ie_vec[UNI_MSG_IE_EPST]
end_define

begin_define
define|#
directive|define
name|msg_ie_err
value|msg_ie_vec[UNI_MSG_IE_ERR]
end_define

begin_comment
comment|/*  * Information element header.  */
end_comment

begin_struct
struct|struct
name|ie_hdr
block|{
name|u_char
name|ie_hdr_ident
decl_stmt|;
name|u_char
name|ie_hdr_coding
decl_stmt|;
name|u_char
name|ie_hdr_flag
decl_stmt|;
name|u_char
name|ie_hdr_action
decl_stmt|;
name|int
name|ie_hdr_length
decl_stmt|;
name|int
name|ie_hdr_err_cause
decl_stmt|;
name|struct
name|ie_generic
modifier|*
name|ie_hdr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_HDR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_CODE_CCITT
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CODE_STD
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CODE_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_FLAG_MASK
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_FLAG_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_DIS
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_RPRT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_DMSGIGN
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_DMSGRPRT
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_ACT_MASK
value|7
end_define

begin_comment
comment|/*  * ATM AAL parameters information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_aalp
block|{
name|int8_t
name|ie_aal_type
decl_stmt|;
union|union
block|{
struct|struct
name|aal_type_1_parm
block|{
name|u_char
name|subtype
decl_stmt|;
name|u_char
name|cbr_rate
decl_stmt|;
name|u_short
name|multiplier
decl_stmt|;
name|u_char
name|clock_recovery
decl_stmt|;
name|u_char
name|error_correction
decl_stmt|;
name|u_char
name|struct_data_tran
decl_stmt|;
name|u_char
name|partial_cells
decl_stmt|;
block|}
name|type_1
struct|;
struct|struct
name|aal_type_4_parm
block|{
name|int32_t
name|fwd_max_sdu
decl_stmt|;
name|int32_t
name|bkwd_max_sdu
decl_stmt|;
name|int32_t
name|mid_range
decl_stmt|;
name|u_char
name|mode
decl_stmt|;
name|u_char
name|sscs_type
decl_stmt|;
block|}
name|type_4
struct|;
struct|struct
name|aal_type_5_parm
block|{
name|int32_t
name|fwd_max_sdu
decl_stmt|;
name|int32_t
name|bkwd_max_sdu
decl_stmt|;
name|u_char
name|mode
decl_stmt|;
name|u_char
name|sscs_type
decl_stmt|;
block|}
name|type_5
struct|;
struct|struct
name|user_aal_type
block|{
name|u_char
name|aal_info
index|[
literal|4
index|]
decl_stmt|;
block|}
name|type_user
struct|;
block|}
name|aal_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_AALP_AT_AAL1
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_AT_AAL3
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_AT_AAL5
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_AT_AALU
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_VCE
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_SCE
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_ACE
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_HQA
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_ST_VID
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_64
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_DS1
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_DS2
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_32064
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_DS3
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_97728
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_E1
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_E2
value|17
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_E3
value|18
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_139264
value|19
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CB_N64
value|64
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CR_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CR_SRTS
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_CR_ACR
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_EC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_EC_FEC
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_SD_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A1_SD_SDT
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A3_R_MASK
value|1023
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A3_R_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_M_MSG
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_M_STR
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_ST_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_ST_AO
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_ST_NAO
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_AALP_A5_ST_FR
value|4
end_define

begin_comment
comment|/*  * ATM user cell rate information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_clrt
block|{
name|int32_t
name|ie_fwd_peak
decl_stmt|;
name|int32_t
name|ie_bkwd_peak
decl_stmt|;
name|int32_t
name|ie_fwd_peak_01
decl_stmt|;
name|int32_t
name|ie_bkwd_peak_01
decl_stmt|;
name|int32_t
name|ie_fwd_sust
decl_stmt|;
name|int32_t
name|ie_bkwd_sust
decl_stmt|;
name|int32_t
name|ie_fwd_sust_01
decl_stmt|;
name|int32_t
name|ie_bkwd_sust_01
decl_stmt|;
name|int32_t
name|ie_fwd_burst
decl_stmt|;
name|int32_t
name|ie_bkwd_burst
decl_stmt|;
name|int32_t
name|ie_fwd_burst_01
decl_stmt|;
name|int32_t
name|ie_bkwd_burst_01
decl_stmt|;
name|int8_t
name|ie_best_effort
decl_stmt|;
name|int8_t
name|ie_tm_options
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_PEAK_ID
value|130
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_PEAK_ID
value|131
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_PEAK_01_ID
value|132
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_PEAK_01_ID
value|133
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_SUST_ID
value|136
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_SUST_ID
value|137
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_SUST_01_ID
value|144
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_SUST_01_ID
value|145
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_BURST_ID
value|160
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_BURST_ID
value|161
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_FWD_BURST_01_ID
value|176
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BKWD_BURST_01_ID
value|177
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_BEST_EFFORT_ID
value|190
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_TM_OPTIONS_ID
value|191
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_TM_FWD_TAG
value|0x01
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLRT_TM_BKWD_TAG
value|0x02
end_define

begin_comment
comment|/*  * Broadband bearer capability information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_bbcp
block|{
name|int8_t
name|ie_bearer_class
decl_stmt|;
name|int8_t
name|ie_traffic_type
decl_stmt|;
name|int8_t
name|ie_timing_req
decl_stmt|;
name|int8_t
name|ie_clipping
decl_stmt|;
name|int8_t
name|ie_conn_config
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_BBCP_BC_BCOB_A
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_BC_BCOB_C
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_BC_BCOB_X
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_BC_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TT_NIND
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TT_CBR
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TT_VBR
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TR_NIND
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TR_EER
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TR_EENR
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TR_RSVD
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_TR_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_SC_NSUS
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_SC_SUS
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_SC_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_SC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_CC_PP
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_CC_PM
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BBCP_CC_MASK
value|3
end_define

begin_comment
comment|/*  * Broadband high layer information information element in internal  * format.  */
end_comment

begin_struct
struct|struct
name|ie_bhli
block|{
name|int8_t
name|ie_type
decl_stmt|;
name|u_char
name|ie_info
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_BHLI_TYPE_ISO
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI_TYPE_USER
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI_TYPE_HLP
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI_TYPE_VSA
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI_HLP_LEN
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_BHLI_VSA_LEN
value|7
end_define

begin_comment
comment|/*  * Broadband low-layer information information element in internal  * format.  */
end_comment

begin_struct
struct|struct
name|ie_blli
block|{
name|int8_t
name|ie_l1_id
decl_stmt|;
name|int8_t
name|ie_l2_id
decl_stmt|;
name|int8_t
name|ie_l2_mode
decl_stmt|;
name|int8_t
name|ie_l2_q933_use
decl_stmt|;
name|int8_t
name|ie_l2_window
decl_stmt|;
name|int8_t
name|ie_l2_user_proto
decl_stmt|;
name|int8_t
name|ie_l3_id
decl_stmt|;
name|int8_t
name|ie_l3_mode
decl_stmt|;
name|int8_t
name|ie_l3_packet_size
decl_stmt|;
name|int8_t
name|ie_l3_window
decl_stmt|;
name|int8_t
name|ie_l3_user_proto
decl_stmt|;
name|int16_t
name|ie_l3_ipi
decl_stmt|;
name|int8_t
name|ie_l3_snap_id
decl_stmt|;
name|u_char
name|ie_l3_oui
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|ie_l3_pid
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L1_ID
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2_ID
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3_ID
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_LID_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_LID_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_LP_MASK
value|31
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_ISO1745
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_Q921
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_X25L
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_X25M
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_LAPB
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_HDLC1
value|9
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_HDLC2
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_HDLC3
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_LLC
value|12
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_X75
value|13
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_Q922
value|14
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_USER
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2P_ISO7776
value|17
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2MODE_NORM
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2MODE_EXT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L2MODE_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_Q933_ALT
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_X25
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_ISO8208
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_ISO8878
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_ISO8473
value|9
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_T70
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_ISO9577
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3P_USER
value|16
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3MODE_NORM
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3MODE_EXT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3MODE_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_16
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_32
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_64
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_128
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_256
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_512
value|9
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_1024
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_2048
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_4096
value|12
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3PS_MASK
value|15
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3IPI_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_BLLI_L3IPI_SNAP
value|0x80
end_define

begin_comment
comment|/*  * Call state information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_clst
block|{
name|int8_t
name|ie_state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U0
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U1
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U3
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U6
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U8
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U9
value|9
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U10
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U11
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_U12
value|12
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N0
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N1
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N3
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N6
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N8
value|8
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N9
value|9
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N10
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N11
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_N12
value|12
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_GLBL_REST0
value|0x00
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_GLBL_REST1
value|0x3d
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_GLBL_REST2
value|0x3e
end_define

begin_define
define|#
directive|define
name|UNI_IE_CLST_STATE_MASK
value|0x3f
end_define

begin_comment
comment|/*  * Called party number information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_cdad
block|{
name|int8_t
name|ie_type
decl_stmt|;
name|int8_t
name|ie_plan
decl_stmt|;
name|Atm_addr
name|ie_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CDAD_TYPE_UNK
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_TYPE_INTL
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_TYPE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_PLAN_E164
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_PLAN_NSAP
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDAD_PLAN_MASK
value|15
end_define

begin_comment
comment|/*  * Called party subaddress information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_cdsa
block|{
name|Atm_addr
name|ie_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CDSA_TYPE_NSAP
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDSA_TYPE_AESA
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDSA_TYPE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CDSA_TYPE_SHIFT
value|4
end_define

begin_comment
comment|/*  * Calling party number information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_cgad
block|{
name|int8_t
name|ie_type
decl_stmt|;
name|int8_t
name|ie_plan
decl_stmt|;
name|int8_t
name|ie_pres_ind
decl_stmt|;
name|int8_t
name|ie_screen_ind
decl_stmt|;
name|Atm_addr
name|ie_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CGAD_TYPE_UNK
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_TYPE_INTL
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_TYPE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PLAN_E164
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PLAN_NSAP
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PLAN_MASK
value|15
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_ALLOW
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_RSTR
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_NNA
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_RSVD
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_PRES_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_SCR_UNS
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_SCR_UVP
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_SCR_UVF
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_SCR_NET
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGAD_SCR_MASK
value|3
end_define

begin_comment
comment|/*  * Calling party subaddress information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_cgsa
block|{
name|Atm_addr
name|ie_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CGSA_TYPE_NSAP
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGSA_TYPE_AESA
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGSA_TYPE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CGSA_TYPE_SHIFT
value|4
end_define

begin_comment
comment|/*  * Cause information element in internal format.  */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_MAX_ID
value|24
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_MAX_QOS_SUB
value|24
end_define

begin_struct
struct|struct
name|ie_caus
block|{
name|int8_t
name|ie_loc
decl_stmt|;
name|int8_t
name|ie_cause
decl_stmt|;
name|int8_t
name|ie_diag_len
decl_stmt|;
name|u_int8_t
name|ie_diagnostic
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_USER
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_PRI_LCL
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_PUB_LCL
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_TRANSIT
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_PUB_RMT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_PRI_RMT
value|5
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_INTL
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_BEYOND
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LOC_MASK
value|15
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UN_NS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UN_NS_MASK
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UN_NA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UN_NA_MASK
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UN_CAU_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RR_USER
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RR_IE
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RR_INSUFF
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RR_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RR_MASK
value|31
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RC_UNK
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RC_PERM
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RC_TRANS
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_CAUS_RC_MASK
value|3
end_define

begin_comment
comment|/*  * Cause codes from UNI 3.0, section 5.4.5.15  */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UNO
value|1
end_define

begin_comment
comment|/* Unallocated number */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NOTROUTE
value|2
end_define

begin_comment
comment|/* No route to transit net */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NODROUTE
value|3
end_define

begin_comment
comment|/* No route to destination */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_BAD_VCC
value|10
end_define

begin_comment
comment|/* VPI/VCI unacceptable */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NORM
value|16
end_define

begin_comment
comment|/* Normal call clearing */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_BUSY
value|17
end_define

begin_comment
comment|/* User busy */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NORSP
value|18
end_define

begin_comment
comment|/* No user responding */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_REJECT
value|21
end_define

begin_comment
comment|/* Call rejected */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_CHANGED
value|22
end_define

begin_comment
comment|/* Number changed */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_CLIR
value|23
end_define

begin_comment
comment|/* User rejects CLIR */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_DORDER
value|27
end_define

begin_comment
comment|/* Dest out of order */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_INVNO
value|28
end_define

begin_comment
comment|/* Invalid number format */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_SENQ
value|30
end_define

begin_comment
comment|/* Rsp to Status Enquiry */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NORM_UNSP
value|31
end_define

begin_comment
comment|/* Normal, unspecified */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NA_VCC
value|35
end_define

begin_comment
comment|/* VCC not available */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_ASSIGN_VCC
value|36
end_define

begin_comment
comment|/* VPCI/VCI assignment failure */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NORDER
value|38
end_define

begin_comment
comment|/* Network out of order */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_TEMP
value|41
end_define

begin_comment
comment|/* Temporary failure */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_DISCARD
value|43
end_define

begin_comment
comment|/* Access info discarded */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NO_VCC
value|45
end_define

begin_comment
comment|/* No VPI/VCI available */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UNAVAIL
value|47
end_define

begin_comment
comment|/* Resource unavailable */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NO_QOS
value|49
end_define

begin_comment
comment|/* QoS unavailable */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NO_CR
value|51
end_define

begin_comment
comment|/* User cell rate not avail */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NO_BC
value|57
end_define

begin_comment
comment|/* Bearer capability not auth */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NA_BC
value|58
end_define

begin_comment
comment|/* Bearer capability n/a */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_SERVICE
value|63
end_define

begin_comment
comment|/* Service or opt not avail */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_NI_BC
value|65
end_define

begin_comment
comment|/* Bearer cap not implemented */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_COMB
value|73
end_define

begin_comment
comment|/* Unsupported combination */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_CREF
value|81
end_define

begin_comment
comment|/* Invalid call reference */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_CEXIST
value|82
end_define

begin_comment
comment|/* Channel does not exist */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_IDEST
value|88
end_define

begin_comment
comment|/* Incompatible destination */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_ENDPT
value|89
end_define

begin_comment
comment|/* Invalid endpoint reference */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_TRNET
value|91
end_define

begin_comment
comment|/* Invalid transit net */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_APPEND
value|92
end_define

begin_comment
comment|/* Too many pending add party */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_UAAL
value|93
end_define

begin_comment
comment|/* AAL parms can't be supp */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_MISSING
value|96
end_define

begin_comment
comment|/* Mandatory IE missing */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_MTEXIST
value|97
end_define

begin_comment
comment|/* Message type nonexistent */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_IEEXIST
value|99
end_define

begin_comment
comment|/* IE type nonexistent */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_IECONTENT
value|100
end_define

begin_comment
comment|/* IE content invalid */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_STATE
value|101
end_define

begin_comment
comment|/* Message incomp with state */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_TIMER
value|102
end_define

begin_comment
comment|/* Recovery on timer expire */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_LEN
value|104
end_define

begin_comment
comment|/* Incorrect message length */
end_comment

begin_define
define|#
directive|define
name|UNI_IE_CAUS_PROTO
value|111
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_comment
comment|/*  * Connection identifier information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_cnid
block|{
name|int8_t
name|ie_vp_sig
decl_stmt|;
name|int8_t
name|ie_pref_excl
decl_stmt|;
name|u_short
name|ie_vpci
decl_stmt|;
name|u_short
name|ie_vci
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_CNID_VPSIG_MASK
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CNID_VPSIG_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_CNID_PREX_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_CNID_MIN_VCI
value|32
end_define

begin_comment
comment|/*  * Quality of service parameter information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_qosp
block|{
name|int8_t
name|ie_fwd_class
decl_stmt|;
name|int8_t
name|ie_bkwd_class
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_QOSP_FWD_CLASS_0
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_FWD_CLASS_1
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_FWD_CLASS_2
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_FWD_CLASS_3
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_FWD_CLASS_4
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_BKWD_CLASS_0
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_BKWD_CLASS_1
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_BKWD_CLASS_2
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_BKWD_CLASS_3
value|3
end_define

begin_define
define|#
directive|define
name|UNI_IE_QOSP_BKWD_CLASS_4
value|4
end_define

begin_comment
comment|/*  * Broadband repeat indicator information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_brpi
block|{
name|int8_t
name|ie_ind
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_BRPI_PRI_LIST
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_BRPI_IND_MASK
value|15
end_define

begin_comment
comment|/*  * Restart indicator information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_rsti
block|{
name|int8_t
name|ie_class
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_RSTI_IND_VC
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_RSTI_ALL_VC
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_RSTI_CLASS_MASK
value|3
end_define

begin_comment
comment|/*  * Broadband locking shift information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_blsh
block|{
name|int8_t
name|ie_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Broadband non-locking shift information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_bnsh
block|{
name|int8_t
name|ie_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Broadband sending complete information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_bsdc
block|{
name|int8_t
name|ie_ind
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_BSDC_IND
value|0x21
end_define

begin_comment
comment|/*  * Transit net selection information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_trnt
block|{
name|int8_t
name|ie_id_type
decl_stmt|;
name|int8_t
name|ie_id_plan
decl_stmt|;
name|u_char
name|ie_id_len
decl_stmt|;
name|u_char
name|ie_id
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
name|UNI_IE_TRNT_IDT_MASK
value|7
end_define

begin_define
define|#
directive|define
name|UNI_IE_TRNT_IDT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UNI_IE_TRNT_IDP_MASK
value|15
end_define

begin_define
define|#
directive|define
name|UNI_IE_TRNT_IDT_NATL
value|2
end_define

begin_define
define|#
directive|define
name|UNI_IE_TRNT_IDP_CIC
value|1
end_define

begin_comment
comment|/*  * Endpoint reference information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_eprf
block|{
name|int8_t
name|ie_type
decl_stmt|;
name|int16_t
name|ie_id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_EPRF_LDI
value|0
end_define

begin_comment
comment|/*  * Endpoint state information element in internal format.  */
end_comment

begin_struct
struct|struct
name|ie_epst
block|{
name|int8_t
name|ie_state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNI_IE_EPST_NULL
value|0
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_API
value|1
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_APR
value|6
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_DPI
value|11
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_DPR
value|12
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_ACTIVE
value|10
end_define

begin_define
define|#
directive|define
name|UNI_IE_EPST_STATE_MASK
value|0x3F
end_define

begin_comment
comment|/*  * Generic information element  */
end_comment

begin_struct
struct|struct
name|ie_generic
block|{
name|struct
name|ie_hdr
name|ie_hdr
decl_stmt|;
union|union
block|{
name|struct
name|ie_aalp
name|ie_aalp
decl_stmt|;
name|struct
name|ie_clrt
name|ie_clrt
decl_stmt|;
name|struct
name|ie_bbcp
name|ie_bbcp
decl_stmt|;
name|struct
name|ie_bhli
name|ie_bhli
decl_stmt|;
name|struct
name|ie_blli
name|ie_blli
decl_stmt|;
name|struct
name|ie_clst
name|ie_clst
decl_stmt|;
name|struct
name|ie_cdad
name|ie_cdad
decl_stmt|;
name|struct
name|ie_cdsa
name|ie_cdsa
decl_stmt|;
name|struct
name|ie_cgad
name|ie_cgad
decl_stmt|;
name|struct
name|ie_cgsa
name|ie_cgsa
decl_stmt|;
name|struct
name|ie_caus
name|ie_caus
decl_stmt|;
name|struct
name|ie_cnid
name|ie_cnid
decl_stmt|;
name|struct
name|ie_qosp
name|ie_qosp
decl_stmt|;
name|struct
name|ie_brpi
name|ie_brpi
decl_stmt|;
name|struct
name|ie_rsti
name|ie_rsti
decl_stmt|;
name|struct
name|ie_blsh
name|ie_blsh
decl_stmt|;
name|struct
name|ie_bnsh
name|ie_bnsh
decl_stmt|;
name|struct
name|ie_bsdc
name|ie_bsdc
decl_stmt|;
name|struct
name|ie_trnt
name|ie_trnt
decl_stmt|;
name|struct
name|ie_eprf
name|ie_eprf
decl_stmt|;
name|struct
name|ie_epst
name|ie_epst
decl_stmt|;
block|}
name|ie_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ie_ident
value|ie_hdr.ie_hdr_ident
end_define

begin_define
define|#
directive|define
name|ie_coding
value|ie_hdr.ie_hdr_coding
end_define

begin_define
define|#
directive|define
name|ie_flag
value|ie_hdr.ie_hdr_flag
end_define

begin_define
define|#
directive|define
name|ie_action
value|ie_hdr.ie_hdr_action
end_define

begin_define
define|#
directive|define
name|ie_length
value|ie_hdr.ie_hdr_length
end_define

begin_define
define|#
directive|define
name|ie_err_cause
value|ie_hdr.ie_hdr_err_cause
end_define

begin_define
define|#
directive|define
name|ie_next
value|ie_hdr.ie_hdr_next
end_define

begin_define
define|#
directive|define
name|ie_aalp_aal_type
value|ie_u.ie_aalp.ie_aal_type
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_subtype
value|ie_u.ie_aalp.aal_u.type_1.subtype
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_cbr_rate
value|ie_u.ie_aalp.aal_u.type_1.cbr_rate
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_multiplier
value|ie_u.ie_aalp.aal_u.type_1.multiplier
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_clock_recovery
value|ie_u.ie_aalp.aal_u.type_1.clock_recovery
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_error_correction
value|ie_u.ie_aalp.aal_u.type_1.error_correction
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_struct_data_tran
value|ie_u.ie_aalp.aal_u.type_1.struct_data_tran
end_define

begin_define
define|#
directive|define
name|ie_aalp_1_partial_cells
value|ie_u.ie_aalp.aal_u.type_1.partial_cells
end_define

begin_define
define|#
directive|define
name|ie_aalp_4_fwd_max_sdu
value|ie_u.ie_aalp.aal_u.type_4.fwd_max_sdu
end_define

begin_define
define|#
directive|define
name|ie_aalp_4_bkwd_max_sdu
value|ie_u.ie_aalp.aal_u.type_4.bkwd_max_sdu
end_define

begin_define
define|#
directive|define
name|ie_aalp_4_mid_range
value|ie_u.ie_aalp.aal_u.type_4.mid_range
end_define

begin_define
define|#
directive|define
name|ie_aalp_4_mode
value|ie_u.ie_aalp.aal_u.type_4.mode
end_define

begin_define
define|#
directive|define
name|ie_aalp_4_sscs_type
value|ie_u.ie_aalp.aal_u.type_4.sscs_type
end_define

begin_define
define|#
directive|define
name|ie_aalp_5_fwd_max_sdu
value|ie_u.ie_aalp.aal_u.type_5.fwd_max_sdu
end_define

begin_define
define|#
directive|define
name|ie_aalp_5_bkwd_max_sdu
value|ie_u.ie_aalp.aal_u.type_5.bkwd_max_sdu
end_define

begin_define
define|#
directive|define
name|ie_aalp_5_mode
value|ie_u.ie_aalp.aal_u.type_5.mode
end_define

begin_define
define|#
directive|define
name|ie_aalp_5_sscs_type
value|ie_u.ie_aalp.aal_u.type_5.sscs_type
end_define

begin_define
define|#
directive|define
name|ie_aalp_user_info
value|ie_u.ie_aalp.aal_u.type_user.aal_info
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_peak
value|ie_u.ie_clrt.ie_fwd_peak
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_peak
value|ie_u.ie_clrt.ie_bkwd_peak
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_peak_01
value|ie_u.ie_clrt.ie_fwd_peak_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_peak_01
value|ie_u.ie_clrt.ie_bkwd_peak_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_sust
value|ie_u.ie_clrt.ie_fwd_sust
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_sust
value|ie_u.ie_clrt.ie_bkwd_sust
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_sust_01
value|ie_u.ie_clrt.ie_fwd_sust_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_sust_01
value|ie_u.ie_clrt.ie_bkwd_sust_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_burst
value|ie_u.ie_clrt.ie_fwd_burst
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_burst
value|ie_u.ie_clrt.ie_bkwd_burst
end_define

begin_define
define|#
directive|define
name|ie_clrt_fwd_burst_01
value|ie_u.ie_clrt.ie_fwd_burst_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_bkwd_burst_01
value|ie_u.ie_clrt.ie_bkwd_burst_01
end_define

begin_define
define|#
directive|define
name|ie_clrt_best_effort
value|ie_u.ie_clrt.ie_best_effort
end_define

begin_define
define|#
directive|define
name|ie_clrt_tm_options
value|ie_u.ie_clrt.ie_tm_options
end_define

begin_define
define|#
directive|define
name|ie_bbcp_bearer_class
value|ie_u.ie_bbcp.ie_bearer_class
end_define

begin_define
define|#
directive|define
name|ie_bbcp_traffic_type
value|ie_u.ie_bbcp.ie_traffic_type
end_define

begin_define
define|#
directive|define
name|ie_bbcp_timing_req
value|ie_u.ie_bbcp.ie_timing_req
end_define

begin_define
define|#
directive|define
name|ie_bbcp_clipping
value|ie_u.ie_bbcp.ie_clipping
end_define

begin_define
define|#
directive|define
name|ie_bbcp_conn_config
value|ie_u.ie_bbcp.ie_conn_config
end_define

begin_define
define|#
directive|define
name|ie_bhli_type
value|ie_u.ie_bhli.ie_type
end_define

begin_define
define|#
directive|define
name|ie_bhli_info
value|ie_u.ie_bhli.ie_info
end_define

begin_define
define|#
directive|define
name|ie_blli_l1_id
value|ie_u.ie_blli.ie_l1_id
end_define

begin_define
define|#
directive|define
name|ie_blli_l2_id
value|ie_u.ie_blli.ie_l2_id
end_define

begin_define
define|#
directive|define
name|ie_blli_l2_mode
value|ie_u.ie_blli.ie_l2_mode
end_define

begin_define
define|#
directive|define
name|ie_blli_l2_q933_use
value|ie_u.ie_blli.ie_l2_q933_use
end_define

begin_define
define|#
directive|define
name|ie_blli_l2_window
value|ie_u.ie_blli.ie_l2_window
end_define

begin_define
define|#
directive|define
name|ie_blli_l2_user_proto
value|ie_u.ie_blli.ie_l2_user_proto
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_id
value|ie_u.ie_blli.ie_l3_id
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_mode
value|ie_u.ie_blli.ie_l3_mode
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_packet_size
value|ie_u.ie_blli.ie_l3_packet_size
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_window
value|ie_u.ie_blli.ie_l3_window
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_user_proto
value|ie_u.ie_blli.ie_l3_user_proto
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_ipi
value|ie_u.ie_blli.ie_l3_ipi
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_snap_id
value|ie_u.ie_blli.ie_l3_snap_id
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_oui
value|ie_u.ie_blli.ie_l3_oui
end_define

begin_define
define|#
directive|define
name|ie_blli_l3_pid
value|ie_u.ie_blli.ie_l3_pid
end_define

begin_define
define|#
directive|define
name|ie_clst_state
value|ie_u.ie_clst.ie_state
end_define

begin_define
define|#
directive|define
name|ie_cdad_type
value|ie_u.ie_cdad.ie_type
end_define

begin_define
define|#
directive|define
name|ie_cdad_plan
value|ie_u.ie_cdad.ie_plan
end_define

begin_define
define|#
directive|define
name|ie_cdad_addr
value|ie_u.ie_cdad.ie_addr
end_define

begin_define
define|#
directive|define
name|ie_cdsa_addr
value|ie_u.ie_cdsa.ie_addr
end_define

begin_define
define|#
directive|define
name|ie_cgad_type
value|ie_u.ie_cgad.ie_type
end_define

begin_define
define|#
directive|define
name|ie_cgad_plan
value|ie_u.ie_cgad.ie_plan
end_define

begin_define
define|#
directive|define
name|ie_cgad_pres_ind
value|ie_u.ie_cgad.ie_pres_ind
end_define

begin_define
define|#
directive|define
name|ie_cgad_screen_ind
value|ie_u.ie_cgad.ie_screen_ind
end_define

begin_define
define|#
directive|define
name|ie_cgad_addr
value|ie_u.ie_cgad.ie_addr
end_define

begin_define
define|#
directive|define
name|ie_cgsa_addr
value|ie_u.ie_cgsa.ie_addr
end_define

begin_define
define|#
directive|define
name|ie_caus_loc
value|ie_u.ie_caus.ie_loc
end_define

begin_define
define|#
directive|define
name|ie_caus_cause
value|ie_u.ie_caus.ie_cause
end_define

begin_define
define|#
directive|define
name|ie_caus_diag_len
value|ie_u.ie_caus.ie_diag_len
end_define

begin_define
define|#
directive|define
name|ie_caus_diagnostic
value|ie_u.ie_caus.ie_diagnostic
end_define

begin_define
define|#
directive|define
name|ie_cnid_vp_sig
value|ie_u.ie_cnid.ie_vp_sig
end_define

begin_define
define|#
directive|define
name|ie_cnid_pref_excl
value|ie_u.ie_cnid.ie_pref_excl
end_define

begin_define
define|#
directive|define
name|ie_cnid_vpci
value|ie_u.ie_cnid.ie_vpci
end_define

begin_define
define|#
directive|define
name|ie_cnid_vci
value|ie_u.ie_cnid.ie_vci
end_define

begin_define
define|#
directive|define
name|ie_qosp_fwd_class
value|ie_u.ie_qosp.ie_fwd_class
end_define

begin_define
define|#
directive|define
name|ie_qosp_bkwd_class
value|ie_u.ie_qosp.ie_bkwd_class
end_define

begin_define
define|#
directive|define
name|ie_brpi_ind
value|ie_u.ie_brpi.ie_ind
end_define

begin_define
define|#
directive|define
name|ie_rsti_class
value|ie_u.ie_rsti.ie_class
end_define

begin_define
define|#
directive|define
name|ie_bsdc_ind
value|ie_u.ie_bsdc.ie_ind
end_define

begin_define
define|#
directive|define
name|ie_trnt_id_type
value|ie_u.ie_trnt.ie_id_type
end_define

begin_define
define|#
directive|define
name|ie_trnt_id_plan
value|ie_u.ie_trnt.ie_id_plan
end_define

begin_define
define|#
directive|define
name|ie_trnt_id_len
value|ie_u.ie_trnt.ie_id_len
end_define

begin_define
define|#
directive|define
name|ie_trnt_id
value|ie_u.ie_trnt.ie_id
end_define

begin_define
define|#
directive|define
name|ie_eprf_type
value|ie_u.ie_eprf.ie_type
end_define

begin_define
define|#
directive|define
name|ie_eprf_id
value|ie_u.ie_eprf.ie_id
end_define

begin_define
define|#
directive|define
name|ie_epst_state
value|ie_u.ie_epst.ie_state
end_define

begin_comment
comment|/*  * Macro to add an IE to the end of a list of IEs  */
end_comment

begin_define
define|#
directive|define
name|MSG_IE_ADD
parameter_list|(
name|m
parameter_list|,
name|i
parameter_list|,
name|ind
parameter_list|)
define|\
value|if (m->msg_ie_vec[ind]) {				\ 		struct ie_generic *_iep = msg->msg_ie_vec[ind];	\ 		while (_iep->ie_next) {				\ 			_iep = _iep->ie_next;			\ 		}						\ 		_iep->ie_next = i;				\ 	} else {						\ 		m->msg_ie_vec[ind] = i;				\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SIG_MSG_H */
end_comment

end_unit

