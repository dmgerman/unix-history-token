begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Configuration file parser  * Copyright (c) 2003-2009, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FILE_H */
end_comment

end_unit

