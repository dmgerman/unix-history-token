begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Basic mesh peer management  * Copyright (c) 2013-2014, cozybit, Inc.  All rights reserved.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MESH_MPM_H
end_ifndef

begin_define
define|#
directive|define
name|MESH_MPM_H
end_define

begin_comment
comment|/* notify MPM of new mesh peer to be inserted in MPM and driver */
end_comment

begin_function_decl
name|void
name|wpa_mesh_new_mesh_peer
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|struct
name|ieee802_11_elems
modifier|*
name|elems
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mesh_mpm_deinit
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|hostapd_iface
modifier|*
name|ifmsh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mesh_mpm_auth_peer
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mesh_mpm_free_sta
parameter_list|(
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_mesh_set_plink_state
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|enum
name|mesh_plink_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_MESH
end_ifdef

begin_function_decl
name|void
name|mesh_mpm_action_rx
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mesh_mpm_mgmt_rx
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|rx_mgmt
modifier|*
name|rx_mgmt
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_MESH */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mesh_mpm_action_rx
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
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
name|mesh_mpm_mgmt_rx
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|rx_mgmt
modifier|*
name|rx_mgmt
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_MESH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MESH_MPM_H */
end_comment

end_unit

