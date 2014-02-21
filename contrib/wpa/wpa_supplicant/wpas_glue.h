begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Glue code to setup EAPOL and RSN modules  * Copyright (c) 2003-2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPAS_GLUE_H
end_ifndef

begin_define
define|#
directive|define
name|WPAS_GLUE_H
end_define

begin_enum_decl
enum_decl|enum
name|wpa_ctrl_req_type
enum_decl|;
end_enum_decl

begin_function_decl
name|int
name|wpa_supplicant_init_eapol
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_supplicant_init_wpa
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
name|wpa_supplicant_rsn_supp_set_config
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|wpa_supplicant_ctrl_req_to_string
parameter_list|(
name|enum
name|wpa_ctrl_req_type
name|field
parameter_list|,
specifier|const
name|char
modifier|*
name|default_txt
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|txt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|wpa_ctrl_req_type
name|wpa_supplicant_ctrl_req_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|field
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPAS_GLUE_H */
end_comment

end_unit

