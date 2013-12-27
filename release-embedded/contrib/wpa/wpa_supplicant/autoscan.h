begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - auto scan  * Copyright (c) 2012, Intel Corporation. All rights reserved.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOSCAN_H
end_ifndef

begin_define
define|#
directive|define
name|AUTOSCAN_H
end_define

begin_struct_decl
struct_decl|struct
name|wpa_supplicant
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|autoscan_ops
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
parameter_list|,
name|struct
name|wpa_scan_results
modifier|*
name|scan_res
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_AUTOSCAN
end_ifdef

begin_function_decl
name|int
name|autoscan_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|req_scan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|autoscan_deinit
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
name|autoscan_notify_scan
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_scan_results
modifier|*
name|scan_res
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_AUTOSCAN */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|autoscan_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|req_scan
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
name|autoscan_deinit
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
name|autoscan_notify_scan
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_scan_results
modifier|*
name|scan_res
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_AUTOSCAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOSCAN_H */
end_comment

end_unit

