begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TI_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|TI_GPIO_H
end_define

begin_comment
comment|/* The maximum number of banks for any SoC */
end_comment

begin_define
define|#
directive|define
name|MAX_GPIO_BANKS
value|6
end_define

begin_comment
comment|/*  * Maximum GPIOS possible, max of *_MAX_GPIO_BANKS * *_INTR_PER_BANK.  * These are defined in ti_gpio.c  */
end_comment

begin_define
define|#
directive|define
name|MAX_GPIO_INTRS
value|8
end_define

begin_comment
comment|/**  *	Structure that stores the driver context.  *  *	This structure is allocated during driver attach.  */
end_comment

begin_struct
struct|struct
name|ti_gpio_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* 	 * The memory resource(s) for the PRCM register set, when the device is 	 * created the caller can assign up to 6 memory regions depending on 	 * the SoC type. 	 */
name|struct
name|resource
modifier|*
name|sc_mem_res
index|[
name|MAX_GPIO_BANKS
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
index|[
name|MAX_GPIO_INTRS
index|]
decl_stmt|;
comment|/* The handle for the register IRQ handlers. */
name|void
modifier|*
name|sc_irq_hdl
index|[
name|MAX_GPIO_INTRS
index|]
decl_stmt|;
comment|/* 	 * The following describes the H/W revision of each of the GPIO banks. 	 */
name|uint32_t
name|sc_revision
index|[
name|MAX_GPIO_BANKS
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TI_GPIO_H */
end_comment

end_unit

