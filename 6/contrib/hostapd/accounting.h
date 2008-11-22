begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_function_decl
name|void
name|accounting_sta_start
parameter_list|(
name|hostapd
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
name|accounting_sta_interim
parameter_list|(
name|hostapd
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
name|hostapd
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
name|int
name|accounting_init
parameter_list|(
name|hostapd
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|accounting_deinit
parameter_list|(
name|hostapd
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
comment|/* ACCOUNTING_H */
end_comment

end_unit

