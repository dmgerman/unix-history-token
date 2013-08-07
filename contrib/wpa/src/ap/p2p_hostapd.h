begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / P2P integration  * Copyright (c) 2009-2010, Atheros Communications  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P2P_HOSTAPD_H
end_ifndef

begin_define
define|#
directive|define
name|P2P_HOSTAPD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_P2P
end_ifdef

begin_function_decl
name|int
name|hostapd_p2p_get_mib_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
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
name|hostapd_p2p_set_noa
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
name|count
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_p2p_non_p2p_sta_connected
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
name|hostapd_p2p_non_p2p_sta_disconnected
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
comment|/* CONFIG_P2P */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_p2p_get_mib_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
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
comment|/* CONFIG_P2P */
end_comment

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_p2p_manage
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* P2P_HOSTAPD_H */
end_comment

end_unit

