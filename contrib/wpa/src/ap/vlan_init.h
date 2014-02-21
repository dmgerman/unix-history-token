begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / VLAN initialization  * Copyright 2003, Instant802 Networks, Inc.  * Copyright 2005, Devicescape Software, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VLAN_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|VLAN_INIT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NO_VLAN
end_ifndef

begin_function_decl
name|int
name|vlan_init
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
name|vlan_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostapd_vlan
modifier|*
name|vlan_add_dynamic
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_vlan
modifier|*
name|vlan
parameter_list|,
name|int
name|vlan_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlan_remove_dynamic
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
name|vlan_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vlan_setup_encryption_dyn
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_ssid
modifier|*
name|mssid
parameter_list|,
specifier|const
name|char
modifier|*
name|dyn_vlan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_VLAN */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|vlan_init
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
name|vlan_deinit
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
name|struct
name|hostapd_vlan
modifier|*
name|vlan_add_dynamic
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_vlan
modifier|*
name|vlan
parameter_list|,
name|int
name|vlan_id
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
name|int
name|vlan_remove_dynamic
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
name|vlan_id
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|vlan_setup_encryption_dyn
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_ssid
modifier|*
name|mssid
parameter_list|,
specifier|const
name|char
modifier|*
name|dyn_vlan
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_VLAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VLAN_INIT_H */
end_comment

end_unit

