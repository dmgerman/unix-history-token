begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * Copyright (c) 2009, Luiz Otavio O Souza.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR71XX_GPIOVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR71XX_GPIOVAR_H__
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

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|GPIO_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|do {	\ 		bus_write_4(sc->gpio_mem_res, (reg), (val)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GPIO_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4(sc->gpio_mem_res, (reg))
end_define

begin_define
define|#
directive|define
name|GPIO_SET_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|GPIO_WRITE(sc, reg, GPIO_READ(sc, (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|GPIO_CLEAR_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|GPIO_WRITE(sc, reg, GPIO_READ(sc, (reg))& ~(bits))
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_PINS
value|12
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_PINS
value|18
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_PINS
value|22
end_define

begin_struct
struct|struct
name|ar71xx_gpio_softc
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
name|gpio_mem_res
decl_stmt|;
name|int
name|gpio_mem_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|gpio_irq_res
decl_stmt|;
name|int
name|gpio_irq_rid
decl_stmt|;
name|void
modifier|*
name|gpio_ih
decl_stmt|;
name|int
name|gpio_npins
decl_stmt|;
name|struct
name|gpio_pin
modifier|*
name|gpio_pins
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR71XX_GPIOVAR_H__ */
end_comment

end_unit

