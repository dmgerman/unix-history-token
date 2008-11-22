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
name|void
name|hostapd_ctrl_iface_send
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_H */
end_comment

end_unit

