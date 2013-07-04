begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.11v WNM related functions and structures  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WNM_STA_H
end_ifndef

begin_define
define|#
directive|define
name|WNM_STA_H
end_define

begin_struct_decl
struct_decl|struct
name|rx_action
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee802_11_send_wnmsleep_req
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|action
parameter_list|,
name|u16
name|intval
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|tfs_req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_11_rx_wnm_action
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|rx_action
modifier|*
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WNM_STA_H */
end_comment

end_unit

