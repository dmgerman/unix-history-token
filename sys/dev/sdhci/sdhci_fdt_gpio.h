begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Support routines usable by any SoC sdhci bridge driver that uses gpio pins  * for card detect and/or write protect, and uses FDT data to describe those  * pins.  A bridge driver need only supply a couple 2-line forwarding functions  * to connect the get_present and get_readonly accessors to the corresponding  * driver interface functions, and add setup/teardown calls to its attach and  * detach functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDHCI_FDT_GPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDHCI_FDT_GPIO_H_
end_define

begin_struct_decl
struct_decl|struct
name|sdhci_slot
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sdhci_fdt_gpio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * sdhci_fdt_gpio_setup()  * sdhci_fdt_gpio_teardown()  *  * Process FDT properties that use gpio pins and set up interrupt handling (if  * supported by hardware) and accessor functions to read the pins.  *  * Setup cannot fail.  If the properties are not present, the accessors will  * return the values from standard sdhci registers.  If the gpio controller  * can't trigger interrupts on both edges, it configures the slot to use polling  * for card presence detection.  If it can't access the gpio pin at all it sets  * up the get_present() accessor to always return true.  Likewise the  * get_readonly() accessor always returns false if its pin can't be accessed.  */
end_comment

begin_function_decl
name|struct
name|sdhci_fdt_gpio
modifier|*
name|sdhci_fdt_gpio_setup
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|sdhci_slot
modifier|*
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdhci_fdt_gpio_teardown
parameter_list|(
name|struct
name|sdhci_fdt_gpio
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * sdhci_fdt_gpio_get_present()  * sdhci_fdt_gpio_get_readonly()  *  * Gpio pin state accessor functions.  */
end_comment

begin_function_decl
name|bool
name|sdhci_fdt_gpio_get_present
parameter_list|(
name|struct
name|sdhci_fdt_gpio
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdhci_fdt_gpio_get_readonly
parameter_list|(
name|struct
name|sdhci_fdt_gpio
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

