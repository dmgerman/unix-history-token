begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EEPROM_H__
end_ifndef

begin_define
define|#
directive|define
name|__EEPROM_H__
end_define

begin_function_decl
specifier|extern
name|void
name|load_eeprom_dump
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
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

