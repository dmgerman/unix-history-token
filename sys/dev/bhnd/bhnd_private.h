begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Landon Fuller under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_types.h"
end_include

begin_comment
comment|/*  * Private bhnd(4) driver definitions.  */
end_comment

begin_comment
comment|/**  * A bhnd(4) service registry entry.  */
end_comment

begin_struct
struct|struct
name|bhnd_service_entry
block|{
name|device_t
name|provider
decl_stmt|;
comment|/**< service provider */
name|bhnd_service_t
name|service
decl_stmt|;
comment|/**< service implemented */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< entry flags (see BHND_SPF_*) */
specifier|volatile
name|u_int
name|refs
decl_stmt|;
comment|/**< reference count; updated atomically 					     with only a shared lock held */
name|STAILQ_ENTRY
argument_list|(
argument|bhnd_service_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhnd(4) per-core PMU clkctl quirks.  */
end_comment

begin_enum
enum|enum
block|{
comment|/** On BCM4328-derived chipsets, the CLK_CTL_ST register CCS_HTAVAIL 	 *  and CCS_ALPAVAIL bits are swapped in the ChipCommon and PCMCIA 	 *  cores; the BHND_CCS0_* constants should be used. */
name|BHND_CLKCTL_QUIRK_CCS0
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * Per-core bhnd(4) PMU clkctl registers.  */
end_comment

begin_struct
struct|struct
name|bhnd_core_clkctl
block|{
name|device_t
name|cc_dev
decl_stmt|;
comment|/**< core device */
name|device_t
name|cc_pmu_dev
decl_stmt|;
comment|/**< pmu device */
name|uint32_t
name|cc_quirks
decl_stmt|;
comment|/**< core-specific clkctl quirks */
name|struct
name|bhnd_resource
modifier|*
name|cc_res
decl_stmt|;
comment|/**< resource mapping core's clkctl register */
name|bus_size_t
name|cc_res_offset
decl_stmt|;
comment|/**< offset to clkctl register */
name|u_int
name|cc_max_latency
decl_stmt|;
comment|/**< maximum PMU transition latency, in microseconds */
name|struct
name|mtx
name|cc_mtx
decl_stmt|;
comment|/**< register read/modify/write lock */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_ASSERT_CLKCTL_AVAIL
parameter_list|(
name|_clkctl
parameter_list|)
define|\
value|KASSERT(!bhnd_is_hw_suspended((_clkctl)->cc_dev),	\ 	    ("reading clkctl on suspended core will trigger system livelock"))
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_LOCK_INIT
parameter_list|(
name|_clkctl
parameter_list|)
value|mtx_init(&(_clkctl)->cc_mtx, \     device_get_nameunit((_clkctl)->cc_dev), NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_LOCK
parameter_list|(
name|_clkctl
parameter_list|)
value|mtx_lock(&(_clkctl)->cc_mtx)
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_UNLOCK
parameter_list|(
name|_clkctl
parameter_list|)
value|mtx_unlock(&(_clkctl)->cc_mtx)
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_LOCK_ASSERT
parameter_list|(
name|_clkctl
parameter_list|,
name|what
parameter_list|)
define|\
value|mtx_assert(&(_clkctl)->cc_mtx, what)
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_LOCK_DESTROY
parameter_list|(
name|_clkctl
parameter_list|)
value|mtx_destroy(&(_clkctl->cc_mtx))
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_READ_4
parameter_list|(
name|_clkctl
parameter_list|)
define|\
value|bhnd_bus_read_4((_clkctl)->cc_res, (_clkctl)->cc_res_offset)
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_WRITE_4
parameter_list|(
name|_clkctl
parameter_list|,
name|_val
parameter_list|)
define|\
value|bhnd_bus_write_4((_clkctl)->cc_res, (_clkctl)->cc_res_offset, (_val))
end_define

begin_define
define|#
directive|define
name|BHND_CLKCTL_SET_4
parameter_list|(
name|_clkctl
parameter_list|,
name|_val
parameter_list|,
name|_mask
parameter_list|)
define|\
value|BHND_CLKCTL_WRITE_4((_clkctl),		\ 	    ((_val)& (_mask)) | (BHND_CLKCTL_READ_4(_clkctl)& ~(_mask)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_PRIVATE_H_ */
end_comment

end_unit

