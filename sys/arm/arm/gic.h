begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011,2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Developed by Damjan Marion<damjan.marion@gmail.com>  *  * Based on OMAP4 GIC code by Ben Gray  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_GIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_GIC_H_
end_define

begin_define
define|#
directive|define
name|GIC_FIRST_SGI
value|0
end_define

begin_comment
comment|/* Irqs 0-15 are SGIs/IPIs. */
end_comment

begin_define
define|#
directive|define
name|GIC_LAST_SGI
value|15
end_define

begin_define
define|#
directive|define
name|GIC_FIRST_PPI
value|16
end_define

begin_comment
comment|/* Irqs 16-31 are private (per */
end_comment

begin_define
define|#
directive|define
name|GIC_LAST_PPI
value|31
end_define

begin_comment
comment|/* core) peripheral interrupts. */
end_comment

begin_define
define|#
directive|define
name|GIC_FIRST_SPI
value|32
end_define

begin_comment
comment|/* Irqs 32+ are shared peripherals. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INTRNG
end_ifdef

begin_struct
struct|struct
name|arm_gic_range
block|{
name|uint64_t
name|bus
decl_stmt|;
name|uint64_t
name|host
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|arm_gic_softc
block|{
name|device_t
name|gic_dev
decl_stmt|;
ifdef|#
directive|ifdef
name|INTRNG
name|void
modifier|*
name|gic_intrhand
decl_stmt|;
name|struct
name|gic_irqsrc
modifier|*
name|gic_irqs
decl_stmt|;
endif|#
directive|endif
name|struct
name|resource
modifier|*
name|gic_res
index|[
literal|3
index|]
decl_stmt|;
name|bus_space_tag_t
name|gic_c_bst
decl_stmt|;
name|bus_space_tag_t
name|gic_d_bst
decl_stmt|;
name|bus_space_handle_t
name|gic_c_bsh
decl_stmt|;
name|bus_space_handle_t
name|gic_d_bsh
decl_stmt|;
name|uint8_t
name|ver
decl_stmt|;
name|struct
name|mtx
name|mutex
decl_stmt|;
name|uint32_t
name|nirqs
decl_stmt|;
name|uint32_t
name|typer
decl_stmt|;
name|uint32_t
name|last_irq
index|[
name|MAXCPU
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|INTRNG
name|uint32_t
name|gic_iidr
decl_stmt|;
name|u_int
name|gic_bus
decl_stmt|;
name|int
name|nranges
decl_stmt|;
name|struct
name|arm_gic_range
modifier|*
name|ranges
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|arm_gic_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTRNG
end_ifdef

begin_struct
struct|struct
name|arm_gicv2m_softc
block|{
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
name|struct
name|mtx
name|sc_mutex
decl_stmt|;
name|uintptr_t
name|sc_xref
decl_stmt|;
name|u_int
name|sc_spi_start
decl_stmt|;
name|u_int
name|sc_spi_end
decl_stmt|;
name|u_int
name|sc_spi_count
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|arm_gicv2m_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|arm_gic_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_gic_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_gicv2m_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_gic_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_GIC_H_ */
end_comment

end_unit

