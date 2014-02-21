begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Control interface for shared AP commands  * Copyright (c) 2004-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL_IFACE_AP_H
end_ifndef

begin_define
define|#
directive|define
name|CTRL_IFACE_AP_H
end_define

begin_function_decl
name|int
name|hostapd_ctrl_iface_sta_first
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_ctrl_iface_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|txtaddr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_ctrl_iface_sta_next
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|txtaddr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_ctrl_iface_deauthenticate
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|txtaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_ctrl_iface_disassociate
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|txtaddr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_AP_H */
end_comment

end_unit

