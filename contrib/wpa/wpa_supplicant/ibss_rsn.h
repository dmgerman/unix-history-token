begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - IBSS RSN  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IBSS_RSN_H
end_ifndef

begin_define
define|#
directive|define
name|IBSS_RSN_H
end_define

begin_struct_decl
struct_decl|struct
name|ibss_rsn
struct_decl|;
end_struct_decl

begin_comment
comment|/* not authenticated */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_AUTH_NOT_AUTHENTICATED
value|0x00
end_define

begin_comment
comment|/* remote peer sent an EAPOL message */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_AUTH_EAPOL_BY_PEER
value|0x01
end_define

begin_comment
comment|/* we sent an AUTH message with seq 1 */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_AUTH_BY_US
value|0x02
end_define

begin_comment
comment|/* we sent an EAPOL message */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_AUTH_EAPOL_BY_US
value|0x04
end_define

begin_comment
comment|/* PTK derived as supplicant */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_SET_PTK_SUPP
value|0x08
end_define

begin_comment
comment|/* PTK derived as authenticator */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_SET_PTK_AUTH
value|0x10
end_define

begin_comment
comment|/* PTK completion reported */
end_comment

begin_define
define|#
directive|define
name|IBSS_RSN_REPORTED_PTK
value|0x20
end_define

begin_struct
struct|struct
name|ibss_rsn_peer
block|{
name|struct
name|ibss_rsn_peer
modifier|*
name|next
decl_stmt|;
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
decl_stmt|;
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|struct
name|wpa_sm
modifier|*
name|supp
decl_stmt|;
name|enum
name|wpa_states
name|supp_state
decl_stmt|;
name|u8
name|supp_ie
index|[
literal|80
index|]
decl_stmt|;
name|size_t
name|supp_ie_len
decl_stmt|;
name|struct
name|wpa_state_machine
modifier|*
name|auth
decl_stmt|;
name|int
name|authentication_status
decl_stmt|;
name|struct
name|os_reltime
name|own_auth_tx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibss_rsn
block|{
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
decl_stmt|;
name|struct
name|wpa_authenticator
modifier|*
name|auth_group
decl_stmt|;
name|struct
name|ibss_rsn_peer
modifier|*
name|peers
decl_stmt|;
name|u8
name|psk
index|[
name|PMK_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibss_rsn_deinit
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibss_rsn_start
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibss_rsn_stop
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|,
specifier|const
name|u8
modifier|*
name|peermac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ibss_rsn_rx_eapol
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|,
specifier|const
name|u8
modifier|*
name|src_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibss_rsn_set_psk
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|,
specifier|const
name|u8
modifier|*
name|psk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibss_rsn_handle_auth
parameter_list|(
name|struct
name|ibss_rsn
modifier|*
name|ibss_rsn
parameter_list|,
specifier|const
name|u8
modifier|*
name|auth_frame
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IBSS_RSN_H */
end_comment

end_unit

