begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OMAP4VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OMAP4VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_function_decl
name|void
name|omap4_mask_all_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omap4_post_filter_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|omap4_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|bus_space_tag_t
name|sc_iotag
decl_stmt|;
comment|/* Handles for the two generic interrupt controller (GIC) register mappings */
name|bus_space_handle_t
name|sc_gic_cpu_ioh
decl_stmt|;
name|bus_space_handle_t
name|sc_gic_dist_ioh
decl_stmt|;
comment|/* Handle for the PL310 L2 cache controller */
name|bus_space_handle_t
name|sc_pl310_ioh
decl_stmt|;
comment|/* Handle for the global and provate timer register set in the Cortex core */
name|bus_space_handle_t
name|sc_prv_timer_ioh
decl_stmt|;
name|bus_space_handle_t
name|sc_gbl_timer_ioh
decl_stmt|;
comment|/* SCM access */
name|struct
name|resource
modifier|*
name|sc_scm_mem
decl_stmt|;
name|int
name|sc_scm_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|omap4_intr_conf
block|{
name|int
name|num
decl_stmt|;
name|unsigned
name|int
name|priority
decl_stmt|;
name|unsigned
name|int
name|target_cpu
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|omap4_setup_intr_controller
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|omap4_intr_conf
modifier|*
name|irqs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|omap4_setup_gic_cpu
parameter_list|(
name|unsigned
name|int
name|prio_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omap4_init_timer
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|omap4_setup_l2cache_controller
parameter_list|(
name|struct
name|omap4_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omap4_smc_call
parameter_list|(
name|uint32_t
name|fn
parameter_list|,
name|uint32_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OMAP4VAR_H_ */
end_comment

end_unit

