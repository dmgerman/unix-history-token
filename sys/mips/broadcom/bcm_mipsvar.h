begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Landon Fuller under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BCM_MIPSVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BCM_MIPSVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/intr.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bcm_mips_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bcm_mips_irqsrc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bcm_mips_softc
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|BCM_MIPS_NINTR
value|32
end_define

begin_comment
comment|/**< maximum number of addressable backplane interrupt vectors */
end_comment

begin_define
define|#
directive|define
name|BCM_MIPS_IRQ_SHARED
value|0
end_define

begin_comment
comment|/**< MIPS CPU IRQ reserved for shared interrupt handling */
end_comment

begin_define
define|#
directive|define
name|INTR_MAP_DATA_BCM_MIPS
value|INTR_MAP_DATA_PLAT_2
end_define

begin_comment
comment|/**< Broadcom MIPS PIC interrupt map data type */
end_comment

begin_function_decl
name|int
name|bcm_mips_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|num_cpuirqs
parameter_list|,
name|u_int
name|timer_irq
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_mips_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Broadcom MIPS PIC interrupt map data.  */
end_comment

begin_struct
struct|struct
name|bcm_mips_intr_map_data
block|{
name|struct
name|intr_map_data
name|mdata
decl_stmt|;
name|u_int
name|ivec
decl_stmt|;
comment|/**< bus interrupt vector */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Nested MIPS CPU interrupt handler state.  */
end_comment

begin_struct
struct|struct
name|bcm_mips_cpuirq
block|{
name|struct
name|bcm_mips_softc
modifier|*
name|sc
decl_stmt|;
comment|/**< driver instance state, or NULL if uninitialized. */
name|u_int
name|mips_irq
decl_stmt|;
comment|/**< mips hardware interrupt number (relative to NSOFT_IRQ) */
name|int
name|irq_rid
decl_stmt|;
comment|/**< mips IRQ resource id, or -1 if this entry is unavailable */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/**< mips interrupt resource */
name|void
modifier|*
name|irq_cookie
decl_stmt|;
comment|/**< mips interrupt handler cookie, or NULL */
name|struct
name|bcm_mips_irqsrc
modifier|*
name|isrc_solo
decl_stmt|;
comment|/**< solo isrc assigned to this interrupt, or NULL */
name|u_int
name|refs
decl_stmt|;
comment|/**< isrc consumer refcount */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Broadcom MIPS PIC interrupt source definition.  */
end_comment

begin_struct
struct|struct
name|bcm_mips_irqsrc
block|{
name|struct
name|intr_irqsrc
name|isrc
decl_stmt|;
name|u_int
name|ivec
decl_stmt|;
comment|/**< bus interrupt vector */
name|u_int
name|refs
decl_stmt|;
comment|/**< active reference count */
name|struct
name|bcm_mips_cpuirq
modifier|*
name|cpuirq
decl_stmt|;
comment|/**< assigned MIPS HW IRQ, or NULL if no assignment */
block|}
struct|;
end_struct

begin_comment
comment|/**  * bcm_mips driver instance state. Must be first member of all subclass  * softc structures.  */
end_comment

begin_struct
struct|struct
name|bcm_mips_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|bcm_mips_cpuirq
name|cpuirqs
index|[
name|NREAL_IRQS
index|]
decl_stmt|;
comment|/**< nested CPU IRQ handlers */
name|u_int
name|num_cpuirqs
decl_stmt|;
comment|/**< number of nested CPU IRQ handlers */
name|u_int
name|timer_irq
decl_stmt|;
comment|/**< CPU timer IRQ */
name|struct
name|bcm_mips_irqsrc
name|isrcs
index|[
name|BCM_MIPS_NINTR
index|]
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BCM_MIPS_IVEC_MASK
parameter_list|(
name|_isrc
parameter_list|)
value|(1<< ((_isrc)->ivec))
end_define

begin_define
define|#
directive|define
name|BCM_MIPS_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "bhnd mips driver lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BCM_MIPS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BCM_MIPS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BCM_MIPS_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|BCM_MIPS_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BCM_MIPSVAR_H_ */
end_comment

end_unit

