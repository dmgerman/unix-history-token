begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GIC_V3_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_GIC_V3_VAR_H_
end_define

begin_define
define|#
directive|define
name|GIC_V3_DEVSTR
value|"ARM Generic Interrupt Controller v3.0"
end_define

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|gic_v3_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|gic_v3_irqsrc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|redist_lpis
block|{
name|vm_offset_t
name|conf_base
decl_stmt|;
name|vm_offset_t
name|pend_base
index|[
name|MAXCPU
index|]
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gic_redists
block|{
comment|/* 	 * Re-Distributor region description. 	 * We will have few of those depending 	 * on the #redistributor-regions property in FDT. 	 */
name|struct
name|resource
modifier|*
modifier|*
name|regions
decl_stmt|;
comment|/* Number of Re-Distributor regions */
name|u_int
name|nregions
decl_stmt|;
comment|/* Per-CPU Re-Distributor handler */
name|struct
name|resource
modifier|*
name|pcpu
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* LPIs data */
name|struct
name|redist_lpis
name|lpis
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gic_v3_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
modifier|*
name|gic_res
decl_stmt|;
name|struct
name|mtx
name|gic_mtx
decl_stmt|;
comment|/* Distributor */
name|struct
name|resource
modifier|*
name|gic_dist
decl_stmt|;
comment|/* Re-Distributors */
name|struct
name|gic_redists
name|gic_redists
decl_stmt|;
name|uint32_t
name|gic_pidr2
decl_stmt|;
name|u_int
name|gic_bus
decl_stmt|;
name|u_int
name|gic_nirqs
decl_stmt|;
name|u_int
name|gic_idbits
decl_stmt|;
name|boolean_t
name|gic_registered
decl_stmt|;
name|int
name|gic_nchildren
decl_stmt|;
name|device_t
modifier|*
name|gic_children
decl_stmt|;
name|struct
name|intr_pic
modifier|*
name|gic_pic
decl_stmt|;
name|struct
name|gic_v3_irqsrc
modifier|*
name|gic_irqs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gic_v3_devinfo
block|{
name|int
name|gic_domain
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GIC_INTR_ISRC
parameter_list|(
name|sc
parameter_list|,
name|irq
parameter_list|)
value|(&sc->gic_irqs[irq].gi_isrc)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_GIC_V3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ivars */
end_comment

begin_enum
enum|enum
block|{
name|GICV3_IVAR_NIRQS
block|,
name|GICV3_IVAR_REDIST_VADDR
block|, }
enum|;
end_enum

begin_expr_stmt
name|__BUS_ACCESSOR
argument_list|(
name|gicv3
argument_list|,
name|nirqs
argument_list|,
name|GICV3
argument_list|,
name|NIRQS
argument_list|,
name|u_int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__BUS_ACCESSOR
argument_list|(
name|gicv3
argument_list|,
name|redist_vaddr
argument_list|,
name|GICV3
argument_list|,
name|REDIST_VADDR
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Device methods */
end_comment

begin_function_decl
name|int
name|gic_v3_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gic_v3_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_gic_v3_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|gic_r_read_4
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|gic_r_read_8
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gic_r_write_4
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint32_t
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gic_r_write_8
parameter_list|(
name|device_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint64_t
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * GIC Distributor accessors.  * Notice that only GIC sofc can be passed.  */
end_comment

begin_define
define|#
directive|define
name|gic_d_read
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|)
define|\
value|({						\ 	bus_read_##len(sc->gic_dist, reg);	\ })
end_define

begin_define
define|#
directive|define
name|gic_d_write
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|({						\ 	bus_write_##len(sc->gic_dist, reg, val);\ })
end_define

begin_comment
comment|/* GIC Re-Distributor accessors (per-CPU) */
end_comment

begin_define
define|#
directive|define
name|gic_r_read
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|)
define|\
value|({						\ 	u_int cpu = PCPU_GET(cpuid);		\ 						\ 	bus_read_##len(				\ 	    sc->gic_redists.pcpu[cpu],		\ 	    reg);				\ })
end_define

begin_define
define|#
directive|define
name|gic_r_write
parameter_list|(
name|sc
parameter_list|,
name|len
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|({						\ 	u_int cpu = PCPU_GET(cpuid);		\ 						\ 	bus_write_##len(			\ 	    sc->gic_redists.pcpu[cpu],		\ 	    reg, val);				\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GIC_V3_VAR_H_ */
end_comment

end_unit

