begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.1X-2010 KaY Interface  * Copyright (c) 2013-2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPAS_KAY_H
end_ifndef

begin_define
define|#
directive|define
name|WPAS_KAY_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_MACSEC
end_ifdef

begin_function_decl
name|int
name|ieee802_1x_alloc_kay_sm
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
name|void
modifier|*
name|ieee802_1x_notify_create_actor
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_dealloc_kay_sm
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_MACSEC */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|ieee802_1x_alloc_kay_sm
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
modifier|*
name|ieee802_1x_notify_create_actor
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_addr
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ieee802_1x_dealloc_kay_sm
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_MACSEC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPAS_KAY_H */
end_comment

end_unit

