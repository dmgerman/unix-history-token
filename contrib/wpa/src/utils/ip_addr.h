begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IP address processing  * Copyright (c) 2003-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_ADDR_H
end_ifndef

begin_define
define|#
directive|define
name|IP_ADDR_H
end_define

begin_struct
struct|struct
name|hostapd_ip_addr
block|{
union|union
block|{
name|struct
name|in_addr
name|v4
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_IPV6
name|struct
name|in6_addr
name|v6
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_IPV6 */
block|}
name|u
union|;
name|int
name|af
decl_stmt|;
comment|/* AF_INET / AF_INET6 */
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|hostapd_ip_txt
parameter_list|(
specifier|const
name|struct
name|hostapd_ip_addr
modifier|*
name|addr
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

begin_function_decl
name|int
name|hostapd_ip_diff
parameter_list|(
name|struct
name|hostapd_ip_addr
modifier|*
name|a
parameter_list|,
name|struct
name|hostapd_ip_addr
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_parse_ip_addr
parameter_list|(
specifier|const
name|char
modifier|*
name|txt
parameter_list|,
name|struct
name|hostapd_ip_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IP_ADDR_H */
end_comment

end_unit

