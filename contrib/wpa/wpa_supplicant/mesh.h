begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Basic mesh mode routines  * Copyright (c) 2013-2014, cozybit, Inc.  All rights reserved.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MESH_H
end_ifndef

begin_define
define|#
directive|define
name|MESH_H
end_define

begin_function_decl
name|int
name|wpa_supplicant_join_mesh
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
name|int
name|wpa_supplicant_leave_mesh
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
name|wpa_supplicant_mesh_iface_deinit
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
name|int
name|wpas_mesh_scan_result_text
parameter_list|(
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpas_mesh_add_interface
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|char
modifier|*
name|ifname
parameter_list|,
name|size_t
name|len
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
name|wpa_mesh_notify_peer
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
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_supplicant_mesh_add_scan_ie
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|extra_ie
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
name|wpa_mesh_notify_peer
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
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ie_len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_mesh_add_scan_ie
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|extra_ie
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
comment|/* MESH_H */
end_comment

end_unit

