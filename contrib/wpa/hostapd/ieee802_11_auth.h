begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / IEEE 802.11 authentication (ACL)  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_11_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_11_AUTH_H
end_define

begin_enum
enum|enum
block|{
name|HOSTAPD_ACL_REJECT
init|=
literal|0
block|,
name|HOSTAPD_ACL_ACCEPT
init|=
literal|1
block|,
name|HOSTAPD_ACL_PENDING
init|=
literal|2
block|,
name|HOSTAPD_ACL_ACCEPT_TIMEOUT
init|=
literal|3
block|}
enum|;
end_enum

begin_function_decl
name|int
name|hostapd_allowed_address
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u32
modifier|*
name|session_timeout
parameter_list|,
name|u32
modifier|*
name|acct_interim_interval
parameter_list|,
name|int
modifier|*
name|vlan_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_acl_init
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
name|hostapd_acl_deinit
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
name|hostapd_acl_reconfig
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
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11_AUTH_H */
end_comment

end_unit

