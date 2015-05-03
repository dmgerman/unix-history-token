begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ACS - Automatic Channel Selection module  * Copyright (c) 2011, Atheros Communications  * Copyright (c) 2013, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_H
end_ifndef

begin_define
define|#
directive|define
name|ACS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ACS
end_ifdef

begin_function_decl
name|enum
name|hostapd_chan_status
name|acs_init
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_ACS */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|hostapd_chan_status
name|acs_init
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{
name|wpa_printf
argument_list|(
name|MSG_ERROR
argument_list|,
literal|"ACS was disabled on your build, rebuild hostapd with CONFIG_ACS=y or set channel"
argument_list|)
expr_stmt|;
return|return
name|HOSTAPD_CHAN_INVALID
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_ACS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACS_H */
end_comment

end_unit

