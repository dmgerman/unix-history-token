begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_DRIVER_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/* maximum number of events consumed in a syncle poll() cycle */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_DRIVER_QUEUE_CONSUME_MAX
value|5
end_define

begin_comment
comment|/*  * struct __hal_driver_t - Represents HAL object for driver.  * @config: HAL configuration.  * @devices: List of all PCI-enumerated X3100 devices in the system.  * A single vxge_hal_driver_t instance contains zero or more  * X3100 devices.  * @devices_lock: Lock to protect %devices when inserting/removing.  * @is_initialized: True if HAL is initialized; false otherwise.  * @uld_callbacks: Upper-layer driver callbacks. See vxge_hal_uld_cbs_t {}.  * @debug_module_mask: 32bit mask that defines which components of the  * driver are to be traced. The trace-able components are listed in  * xgehal_debug.h:  * @debug_level: See vxge_debug_level_e {}.  *  * HAL (driver) object. There is a single instance of this structure per HAL.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_driver_t
block|{
name|vxge_hal_driver_config_t
name|config
decl_stmt|;
name|int
name|is_initialized
decl_stmt|;
name|vxge_hal_uld_cbs_t
name|uld_callbacks
decl_stmt|;
name|u32
name|debug_level
decl_stmt|;
block|}
name|__hal_driver_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|__hal_driver_t
modifier|*
name|g_vxge_hal_driver
decl_stmt|;
end_decl_stmt

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_DRIVER_H */
end_comment

end_unit

