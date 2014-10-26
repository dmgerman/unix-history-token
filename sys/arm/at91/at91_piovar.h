begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_PIOVAR_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_PIOVAR_H
end_define

begin_function_decl
name|void
name|at91_pio_use_periph_a
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|periph_a_mask
parameter_list|,
name|int
name|use_pullup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_use_periph_b
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|periph_b_mask
parameter_list|,
name|int
name|use_pullup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_use_gpio
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|gpio_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_input
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|input_enable_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_output
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|output_enable_mask
parameter_list|,
name|int
name|use_pullup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_high_z
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|high_z_mask
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_set
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_clear
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|at91_pio_gpio_get
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_set_deglitch
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|,
name|int
name|use_deglitch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_set_interrupt
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|,
name|int
name|enable_interrupt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|at91_pio_gpio_clear_interrupt
parameter_list|(
name|uint32_t
name|pio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_pio_gpio_pullup
parameter_list|(
name|uint32_t
name|pio
parameter_list|,
name|uint32_t
name|data_mask
parameter_list|,
name|int
name|do_pullup
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_PIOVAR_H */
end_comment

end_unit

