begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Configuration file parser  * Copyright (c) 2003-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_FILE_H
end_define

begin_function_decl
name|struct
name|hostapd_config
modifier|*
name|hostapd_config_read
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_set_iface
parameter_list|(
name|struct
name|hostapd_config
modifier|*
name|conf
parameter_list|,
name|struct
name|hostapd_bss_config
modifier|*
name|bss
parameter_list|,
name|char
modifier|*
name|field
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FILE_H */
end_comment

end_unit

