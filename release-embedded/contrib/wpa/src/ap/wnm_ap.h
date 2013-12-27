begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.11v WNM related functions and structures  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WNM_AP_H
end_ifndef

begin_define
define|#
directive|define
name|WNM_AP_H
end_define

begin_struct_decl
struct_decl|struct
name|rx_action
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ieee802_11_rx_wnm_action_ap
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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
comment|/* WNM_AP_H */
end_comment

end_unit

