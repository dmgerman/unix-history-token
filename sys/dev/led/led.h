begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_LED_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_LED_H
end_define

begin_typedef
typedef|typedef
name|void
name|led_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|cdev
modifier|*
name|led_create_state
parameter_list|(
name|led_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdev
modifier|*
name|led_create
parameter_list|(
name|led_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|led_destroy
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

