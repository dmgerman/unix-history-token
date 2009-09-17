begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd - Authenticator for IEEE 802.11i RSN pre-authentication  * Copyright (c) 2004-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREAUTH_H
end_ifndef

begin_define
define|#
directive|define
name|PREAUTH_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_RSN_PREAUTH
end_ifdef

begin_function_decl
name|int
name|rsn_preauth_iface_init
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
name|rsn_preauth_iface_deinit
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
name|rsn_preauth_finished
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|int
name|success
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsn_preauth_send
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
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
name|rsn_preauth_free_station
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_RSN_PREAUTH */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|rsn_preauth_iface_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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
name|rsn_preauth_iface_deinit
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
name|rsn_preauth_finished
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|int
name|success
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rsn_preauth_send
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rsn_preauth_free_station
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_RSN_PREAUTH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PREAUTH_H */
end_comment

end_unit

