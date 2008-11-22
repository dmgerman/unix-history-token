begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|IAPP_H
end_ifndef

begin_define
define|#
directive|define
name|IAPP_H
end_define

begin_struct_decl
struct_decl|struct
name|iapp_data
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IAPP
end_ifdef

begin_function_decl
name|void
name|iapp_new_station
parameter_list|(
name|struct
name|iapp_data
modifier|*
name|iapp
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|iapp_data
modifier|*
name|iapp_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iapp_deinit
parameter_list|(
name|struct
name|iapp_data
modifier|*
name|iapp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_IAPP */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|iapp_new_station
parameter_list|(
name|struct
name|iapp_data
modifier|*
name|iapp
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
name|struct
name|iapp_data
modifier|*
name|iapp_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|char
modifier|*
name|iface
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
name|iapp_deinit
parameter_list|(
name|struct
name|iapp_data
modifier|*
name|iapp
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IAPP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IAPP_H */
end_comment

end_unit

