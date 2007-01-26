begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ixp425var.h,v 1.10 2006/04/10 03:36:03 simonb Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2003  *	Ichiro FUKUHARA<ichiro@ichiro.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ichiro FUKUHARA.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ICHIRO FUKUHARA ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL ICHIRO FUKUHARA OR THE VOICES IN HIS HEAD BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXP425VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXP425VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|ixp425_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_space_handle_t
name|sc_gpio_ioh
decl_stmt|;
name|bus_space_handle_t
name|sc_exp_ioh
decl_stmt|;
name|u_int32_t
name|sc_intrmask
decl_stmt|;
name|struct
name|rman
name|sc_irq_rman
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixppcib_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|u_int
name|sc_bus
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_csr
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
name|struct
name|rman
name|sc_io_rman
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|struct
name|rman
name|sc_irq_rman
decl_stmt|;
name|struct
name|bus_space
name|sc_pci_memt
decl_stmt|;
name|struct
name|bus_space
name|sc_pci_iot
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXP_BUS_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_4(sc->sc_iot, sc->sc_exp_ioh, reg, data)
end_define

begin_define
define|#
directive|define
name|EXP_BUS_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->sc_iot, sc->sc_exp_ioh, reg)
end_define

begin_define
define|#
directive|define
name|GPIO_CONF_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_4(sc->sc_iot, sc->sc_gpio_ioh, reg, data)
end_define

begin_define
define|#
directive|define
name|GPIO_CONF_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->sc_iot, sc->sc_gpio_ioh, reg)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|ixp425_bs_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|ixp425_a4x_bs_tag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ixp425_io_bs_init
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixp425_mem_bs_init
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ixp425_sdram_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixp425_md_route_interrupt
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixp425_md_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXP425VAR_H_ */
end_comment

end_unit

