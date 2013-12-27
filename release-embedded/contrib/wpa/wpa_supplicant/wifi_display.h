begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - Wi-Fi Display  * Copyright (c) 2011, Atheros Communications, Inc.  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFI_DISPLAY_H
end_ifndef

begin_define
define|#
directive|define
name|WIFI_DISPLAY_H
end_define

begin_function_decl
name|int
name|wifi_display_init
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wifi_display_deinit
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wifi_display_enable
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wifi_display_subelem_set
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wifi_display_subelem_get
parameter_list|(
name|struct
name|wpa_global
modifier|*
name|global
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIFI_DISPLAY_H */
end_comment

end_unit

