begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * Copyright (c) 2013 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCM2835_BSCVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_BCM2835_BSCVAR_H
end_define

begin_struct
struct|struct
block|{
name|uint32_t
name|sda
decl_stmt|;
name|uint32_t
name|scl
decl_stmt|;
name|unsigned
name|long
name|start
decl_stmt|;
block|}
name|bcm_bsc_pins
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|1
block|,
literal|0x20205000
block|}
block|,
comment|/* BSC0 GPIO pins and base address. */
block|{
literal|2
block|,
literal|3
block|,
literal|0x20804000
block|}
comment|/* BSC1 GPIO pins and base address. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bcm_bsc_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|bus_space_tag_t
name|sc_bst
decl_stmt|;
name|bus_space_handle_t
name|sc_bsh
decl_stmt|;
name|uint16_t
name|sc_resid
decl_stmt|;
name|uint8_t
modifier|*
name|sc_data
decl_stmt|;
name|uint8_t
name|sc_flags
decl_stmt|;
name|void
modifier|*
name|sc_intrhand
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BCM_I2C_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|BCM_I2C_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|BCM_I2C_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|BCM_BSC_WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_off
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4(_sc->sc_bst, _sc->sc_bsh, _off, _val)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_READ
parameter_list|(
name|_sc
parameter_list|,
name|_off
parameter_list|)
define|\
value|bus_space_read_4(_sc->sc_bst, _sc->sc_bsh, _off)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_LOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCM2835_BSCVAR_H_ */
end_comment

end_unit

