begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * pccard driver interface.  * Bruce Evans, November 1995.  * This file is in the public domain.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_DRIVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_DRIVER_H_
end_define

begin_struct_decl
struct_decl|struct
name|pccard_device
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|pccard_add_driver
parameter_list|(
name|struct
name|pccard_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|beepstate
block|{
name|BEEP_OFF
block|,
name|BEEP_ON
block|}
enum|;
end_enum

begin_function_decl
name|void
name|pccard_insert_beep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_remove_beep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_success_beep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_failure_beep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_beep_select
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCCARD_DRIVER_H_ */
end_comment

end_unit

