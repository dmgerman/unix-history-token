begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / WMM (Wi-Fi Multimedia)  * Copyright 2002-2003, Instant802 Networks, Inc.  * Copyright 2005-2006, Devicescape Software, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WME_H
end_ifndef

begin_define
define|#
directive|define
name|WME_H
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_mgmt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wmm_tspec_element
struct_decl|;
end_struct_decl

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_wmm
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_eid_wmm_valid
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|eid
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_wmm_action
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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
name|int
name|wmm_process_tspec
parameter_list|(
name|struct
name|wmm_tspec_element
modifier|*
name|tspec
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WME_H */
end_comment

end_unit

