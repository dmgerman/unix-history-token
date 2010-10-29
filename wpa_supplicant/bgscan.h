begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - background scan and roaming interface  * Copyright (c) 2009-2010, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BGSCAN_H
end_ifndef

begin_define
define|#
directive|define
name|BGSCAN_H
end_define

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_ssid
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bgscan_ops
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|char
modifier|*
name|params
parameter_list|,
specifier|const
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|notify_scan
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|notify_beacon_loss
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|notify_signal_change
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|above
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_BGSCAN
end_ifdef

begin_function_decl
name|int
name|bgscan_init
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
name|bgscan_deinit
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
name|bgscan_notify_scan
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
name|bgscan_notify_beacon_loss
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
name|bgscan_notify_signal_change
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|above
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_BGSCAN */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bgscan_init
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
name|bgscan_deinit
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|bgscan_notify_scan
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
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
name|bgscan_notify_beacon_loss
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|bgscan_notify_signal_change
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|above
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_BGSCAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BGSCAN_H */
end_comment

end_unit

