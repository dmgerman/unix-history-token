begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / UNIX domain socket -based control interface  * Copyright (c) 2004, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTRL_IFACE_H
end_ifndef

begin_define
define|#
directive|define
name|CTRL_IFACE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NO_CTRL_IFACE
end_ifndef

begin_function_decl
name|int
name|hostapd_ctrl_iface_init
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
name|hostapd_ctrl_iface_deinit
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
name|hostapd_global_ctrl_iface_init
parameter_list|(
name|struct
name|hapd_interfaces
modifier|*
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_global_ctrl_iface_deinit
parameter_list|(
name|struct
name|hapd_interfaces
modifier|*
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_CTRL_IFACE */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_ctrl_iface_init
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
name|hostapd_ctrl_iface_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_global_ctrl_iface_init
parameter_list|(
name|struct
name|hapd_interfaces
modifier|*
name|interface
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
name|hostapd_global_ctrl_iface_deinit
parameter_list|(
name|struct
name|hapd_interfaces
modifier|*
name|interface
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_CTRL_IFACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_H */
end_comment

end_unit

