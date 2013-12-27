begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__9287_H__
end_ifndef

begin_define
define|#
directive|define
name|__9287_H__
end_define

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_base_print
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_custdata_print
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_modal_print
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_calfreqpiers_print
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_ctl_print
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_print_targets
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_print_edges
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|eeprom_9287_print_other
parameter_list|(
name|uint16_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

