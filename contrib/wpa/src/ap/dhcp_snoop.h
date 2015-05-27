begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * DHCP snooping for Proxy ARP  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DHCP_SNOOP_H
end_ifndef

begin_define
define|#
directive|define
name|DHCP_SNOOP_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PROXYARP
end_ifdef

begin_function_decl
name|int
name|dhcp_snoop_init
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
name|dhcp_snoop_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_PROXYARP */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|dhcp_snoop_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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
name|dhcp_snoop_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_PROXYARP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DHCP_SNOOP_H */
end_comment

end_unit

