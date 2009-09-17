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
name|int
name|vlan_reconfig
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|hostapd_config
modifier|*
name|oldconf
parameter_list|,
name|struct
name|hostapd_bss_config
modifier|*
name|oldbss
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VLAN_INIT_H */
end_comment

end_unit

