begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / WPS integration  * Copyright (c) 2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPS_HOSTAPD_H
end_ifndef

begin_define
define|#
directive|define
name|WPS_HOSTAPD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_WPS
end_ifdef

begin_function_decl
name|int
name|hostapd_init_wps
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_bss_config
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_deinit_wps
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_wps_add_pin
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|uuid
parameter_list|,
specifier|const
name|char
modifier|*
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_wps_button_pushed
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_wps_probe_req_rx
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_WPS */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_init_wps
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_bss_config
modifier|*
name|conf
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|hostapd_deinit_wps
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|hostapd_wps_probe_req_rx
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_WPS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPS_HOSTAPD_H */
end_comment

end_unit

