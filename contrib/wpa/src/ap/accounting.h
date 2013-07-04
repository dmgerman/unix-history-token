begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / RADIUS Accounting  * Copyright (c) 2002-2005, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACCOUNTING_H
end_ifndef

begin_define
define|#
directive|define
name|ACCOUNTING_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_ACCOUNTING
end_ifdef

begin_function
specifier|static
specifier|inline
name|void
name|accounting_sta_get_id
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
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|accounting_sta_start
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
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|accounting_sta_stop
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
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|accounting_init
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
name|accounting_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_ACCOUNTING */
end_comment

begin_function_decl
name|void
name|accounting_sta_get_id
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|accounting_sta_start
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|accounting_sta_stop
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|accounting_init
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
name|accounting_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_ACCOUNTING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACCOUNTING_H */
end_comment

end_unit

