begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic Snooping for Proxy ARP  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_SNOOP_H
end_ifndef

begin_define
define|#
directive|define
name|X_SNOOP_H
end_define

begin_include
include|#
directive|include
file|"l2_packet/l2_packet.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PROXYARP
end_ifdef

begin_function_decl
name|int
name|x_snoop_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|l2_packet_data
modifier|*
name|x_snoop_get_l2_packet
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
parameter_list|,
name|enum
name|l2_packet_filter_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x_snoop_mcast_to_ucast_convert_send
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
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x_snoop_deinit
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
name|x_snoop_init
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
name|struct
name|l2_packet_data
modifier|*
name|x_snoop_get_l2_packet
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
parameter_list|,
name|enum
name|l2_packet_filter_type
name|type
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|x_snoop_mcast_to_ucast_convert_send
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
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|x_snoop_deinit
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
comment|/* X_SNOOP_H */
end_comment

end_unit

