begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBGPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBGPIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/gpio.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_define
define|#
directive|define
name|GPIO_INVALID_HANDLE
value|-1
end_define

begin_typedef
typedef|typedef
name|int
name|gpio_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|gpio_pin_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure describing a GPIO pin configuration.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|gpio_pin_t
name|g_pin
decl_stmt|;
name|char
name|g_name
index|[
name|GPIOMAXNAME
index|]
decl_stmt|;
name|uint32_t
name|g_caps
decl_stmt|;
name|uint32_t
name|g_flags
decl_stmt|;
block|}
name|gpio_config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|GPIO_VALUE_INVALID
init|=
operator|-
literal|1
block|,
name|GPIO_VALUE_LOW
init|=
name|GPIO_PIN_LOW
block|,
name|GPIO_VALUE_HIGH
init|=
name|GPIO_PIN_HIGH
block|}
name|gpio_value_t
typedef|;
end_typedef

begin_comment
comment|/*  * Open /dev/gpiocN or a specific device.  */
end_comment

begin_function_decl
name|gpio_handle_t
name|gpio_open
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gpio_handle_t
name|gpio_open_device
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gpio_close
parameter_list|(
name|gpio_handle_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get a list of all the GPIO pins.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_list
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_config_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * GPIO pin configuration.  *  * Retrieve the configuration of a specific GPIO pin.  The pin number is  * passed through the gpio_config_t structure.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_config
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_config_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets the GPIO flags on a specific GPIO pin.  The pin number and the flags  * to be set are passed through the gpio_config_t structure.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_set_flags
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_config_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * GPIO pin values.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_get
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_set
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_toggle
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Helper functions to set pin states.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_low
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_high
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Helper functions to configure pins.  */
end_comment

begin_function_decl
name|int
name|gpio_pin_input
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_output
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_opendrain
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_pushpull
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_tristate
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_pullup
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_pulldown
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_invin
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_invout
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_pulsate
parameter_list|(
name|gpio_handle_t
parameter_list|,
name|gpio_pin_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBGPIO_H_ */
end_comment

end_unit

