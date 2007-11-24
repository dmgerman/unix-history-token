begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / EAP-SIM/AKA shared routines  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_SIM_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_SIM_COMMON_H
end_define

begin_define
define|#
directive|define
name|EAP_SIM_NONCE_S_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SIM_NONCE_MT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SIM_MAC_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SIM_MK_LEN
value|20
end_define

begin_define
define|#
directive|define
name|EAP_SIM_K_AUT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SIM_K_ENCR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_SIM_KEYING_DATA_LEN
value|64
end_define

begin_define
define|#
directive|define
name|EAP_SIM_IV_LEN
value|16
end_define

begin_define
define|#
directive|define
name|GSM_RAND_LEN
value|16
end_define

begin_define
define|#
directive|define
name|AKA_RAND_LEN
value|16
end_define

begin_define
define|#
directive|define
name|AKA_AUTN_LEN
value|16
end_define

begin_function_decl
name|void
name|eap_sim_derive_keys
parameter_list|(
specifier|const
name|u8
modifier|*
name|mk
parameter_list|,
name|u8
modifier|*
name|k_encr
parameter_list|,
name|u8
modifier|*
name|k_aut
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sim_derive_keys_reauth
parameter_list|(
name|u16
name|_counter
parameter_list|,
specifier|const
name|u8
modifier|*
name|identity
parameter_list|,
name|size_t
name|identity_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|mk
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sim_verify_mac
parameter_list|(
specifier|const
name|u8
modifier|*
name|k_aut
parameter_list|,
specifier|const
name|u8
modifier|*
name|req
parameter_list|,
name|size_t
name|req_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac
parameter_list|,
specifier|const
name|u8
modifier|*
name|extra
parameter_list|,
name|size_t
name|extra_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sim_add_mac
parameter_list|(
specifier|const
name|u8
modifier|*
name|k_aut
parameter_list|,
name|u8
modifier|*
name|msg
parameter_list|,
name|size_t
name|msg_len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|,
specifier|const
name|u8
modifier|*
name|extra
parameter_list|,
name|size_t
name|extra_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EAP-SIM/AKA Attributes (0..127 non-skippable) */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_RAND
value|1
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_AUTN
value|2
end_define

begin_comment
comment|/* only AKA */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_RES
value|3
end_define

begin_comment
comment|/* only AKA, only send */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_AUTS
value|4
end_define

begin_comment
comment|/* only AKA, only send */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_PADDING
value|6
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_NONCE_MT
value|7
end_define

begin_comment
comment|/* only SIM, only send */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_PERMANENT_ID_REQ
value|10
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_MAC
value|11
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_NOTIFICATION
value|12
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_ANY_ID_REQ
value|13
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_IDENTITY
value|14
end_define

begin_comment
comment|/* only send */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_VERSION_LIST
value|15
end_define

begin_comment
comment|/* only SIM */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_SELECTED_VERSION
value|16
end_define

begin_comment
comment|/* only SIM */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_FULLAUTH_ID_REQ
value|17
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_COUNTER
value|19
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_COUNTER_TOO_SMALL
value|20
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_NONCE_S
value|21
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_CLIENT_ERROR_CODE
value|22
end_define

begin_comment
comment|/* only send */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_IV
value|129
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_ENCR_DATA
value|130
end_define

begin_define
define|#
directive|define
name|EAP_SIM_AT_NEXT_PSEUDONYM
value|132
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_NEXT_REAUTH_ID
value|133
end_define

begin_comment
comment|/* only encrypted */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_CHECKCODE
value|134
end_define

begin_comment
comment|/* only AKA */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_AT_RESULT_IND
value|135
end_define

begin_comment
comment|/* AT_NOTIFICATION notification code values */
end_comment

begin_define
define|#
directive|define
name|EAP_SIM_GENERAL_FAILURE_AFTER_AUTH
value|0
end_define

begin_define
define|#
directive|define
name|EAP_SIM_TEMPORARILY_DENIED
value|1026
end_define

begin_define
define|#
directive|define
name|EAP_SIM_NOT_SUBSCRIBED
value|1031
end_define

begin_define
define|#
directive|define
name|EAP_SIM_GENERAL_FAILURE_BEFORE_AUTH
value|16384
end_define

begin_define
define|#
directive|define
name|EAP_SIM_SUCCESS
value|32768
end_define

begin_enum
enum|enum
name|eap_sim_id_req
block|{
name|NO_ID_REQ
block|,
name|ANY_ID
block|,
name|FULLAUTH_ID
block|,
name|PERMANENT_ID
block|}
enum|;
end_enum

begin_struct
struct|struct
name|eap_sim_attrs
block|{
specifier|const
name|u8
modifier|*
name|rand
decl_stmt|,
modifier|*
name|autn
decl_stmt|,
modifier|*
name|mac
decl_stmt|,
modifier|*
name|iv
decl_stmt|,
modifier|*
name|encr_data
decl_stmt|,
modifier|*
name|version_list
decl_stmt|,
modifier|*
name|nonce_s
decl_stmt|;
specifier|const
name|u8
modifier|*
name|next_pseudonym
decl_stmt|,
modifier|*
name|next_reauth_id
decl_stmt|;
specifier|const
name|u8
modifier|*
name|nonce_mt
decl_stmt|,
modifier|*
name|identity
decl_stmt|;
name|size_t
name|num_chal
decl_stmt|,
name|version_list_len
decl_stmt|,
name|encr_data_len
decl_stmt|;
name|size_t
name|next_pseudonym_len
decl_stmt|,
name|next_reauth_id_len
decl_stmt|,
name|identity_len
decl_stmt|;
name|enum
name|eap_sim_id_req
name|id_req
decl_stmt|;
name|int
name|notification
decl_stmt|,
name|counter
decl_stmt|,
name|selected_version
decl_stmt|,
name|client_error_code
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|eap_sim_parse_attr
parameter_list|(
specifier|const
name|u8
modifier|*
name|start
parameter_list|,
specifier|const
name|u8
modifier|*
name|end
parameter_list|,
name|struct
name|eap_sim_attrs
modifier|*
name|attr
parameter_list|,
name|int
name|aka
parameter_list|,
name|int
name|encr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_sim_parse_encr
parameter_list|(
specifier|const
name|u8
modifier|*
name|k_encr
parameter_list|,
specifier|const
name|u8
modifier|*
name|encr_data
parameter_list|,
name|size_t
name|encr_data_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|iv
parameter_list|,
name|struct
name|eap_sim_attrs
modifier|*
name|attr
parameter_list|,
name|int
name|aka
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|eap_sim_msg
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|eap_sim_msg
modifier|*
name|eap_sim_msg_init
parameter_list|(
name|int
name|code
parameter_list|,
name|int
name|id
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|subtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_sim_msg_finish
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
specifier|const
name|u8
modifier|*
name|k_aut
parameter_list|,
specifier|const
name|u8
modifier|*
name|extra
parameter_list|,
name|size_t
name|extra_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sim_msg_free
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_sim_msg_add_full
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|u8
name|attr
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_sim_msg_add
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|u8
name|attr
parameter_list|,
name|u16
name|value
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_sim_msg_add_mac
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|u8
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sim_msg_add_encr_start
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|u8
name|attr_iv
parameter_list|,
name|u8
name|attr_encr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sim_msg_add_encr_end
parameter_list|(
name|struct
name|eap_sim_msg
modifier|*
name|msg
parameter_list|,
name|u8
modifier|*
name|k_encr
parameter_list|,
name|int
name|attr_pad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sim_report_notification
parameter_list|(
name|void
modifier|*
name|msg_ctx
parameter_list|,
name|int
name|notification
parameter_list|,
name|int
name|aka
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_SIM_COMMON_H */
end_comment

end_unit

