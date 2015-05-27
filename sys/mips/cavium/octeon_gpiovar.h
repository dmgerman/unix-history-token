begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_GPIOVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_GPIOVAR_H__
end_define

begin_define
define|#
directive|define
name|GPIO_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->gpio_mtx)
end_define

begin_define
define|#
directive|define
name|GPIO_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->gpio_mtx)
end_define

begin_define
define|#
directive|define
name|GPIO_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->gpio_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|OCTEON_GPIO_IRQ_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|OCTEON_GPIO_IRQ_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|OCTEON_GPIO_PINS
value|24
end_define

begin_define
define|#
directive|define
name|OCTEON_GPIO_IRQS
value|16
end_define

begin_struct
struct|struct
name|octeon_gpio_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|busdev
decl_stmt|;
name|struct
name|mtx
name|gpio_mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|gpio_irq_res
index|[
name|OCTEON_GPIO_IRQS
index|]
decl_stmt|;
name|int
name|gpio_irq_rid
index|[
name|OCTEON_GPIO_IRQS
index|]
decl_stmt|;
name|void
modifier|*
name|gpio_ih
index|[
name|OCTEON_GPIO_IRQS
index|]
decl_stmt|;
name|void
modifier|*
name|gpio_intr_cookies
index|[
name|OCTEON_GPIO_IRQS
index|]
decl_stmt|;
name|int
name|gpio_npins
decl_stmt|;
name|struct
name|gpio_pin
name|gpio_pins
index|[
name|OCTEON_GPIO_PINS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OCTEON_GPIOVAR_H__ */
end_comment

end_unit

