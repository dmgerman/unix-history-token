begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_CTRL_IFACE
end_ifdef

begin_function_decl
name|int
name|wpa_supplicant_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_supplicant_ctrl_iface_deinit
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_supplicant_ctrl_iface_send
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|wpa_supplicant_ctrl_iface_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
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
name|wpa_supplicant_ctrl_iface_deinit
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|wpa_supplicant_ctrl_iface_send
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|level
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_CTRL_IFACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_H */
end_comment

end_unit

