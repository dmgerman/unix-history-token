begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wi-Fi Protected Setup - device attributes  * Copyright (c) 2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPS_DEV_ATTR_H
end_ifndef

begin_define
define|#
directive|define
name|WPS_DEV_ATTR_H
end_define

begin_struct_decl
struct_decl|struct
name|wps_parse_attr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|wps_build_device_attrs
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_build_os_version
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_build_rf_bands
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_build_primary_dev_type
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_process_device_attrs
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
name|struct
name|wps_parse_attr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_process_os_version
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
specifier|const
name|u8
modifier|*
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_process_rf_bands
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
specifier|const
name|u8
modifier|*
name|bands
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_device_data_dup
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dst
parameter_list|,
specifier|const
name|struct
name|wps_device_data
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_device_data_free
parameter_list|(
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPS_DEV_ATTR_H */
end_comment

end_unit

