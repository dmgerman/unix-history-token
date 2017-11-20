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
name|VXGE_HAL_SRPCIM_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_SRPCIM_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*  * __hal_srpcim_vpath_t  *  * HAL srpcim vpath messaging state.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_srpcim_vpath_t
block|{
name|u32
name|registered
decl_stmt|;
name|u32
name|srpcim_id
decl_stmt|;
block|}
name|__hal_srpcim_vpath_t
typedef|;
end_typedef

begin_comment
comment|/*  * __hal_srpcim_t  *  * HAL srpcim object. Represents privileged mode srpcim device.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_srpcim_t
block|{
name|__hal_srpcim_vpath_t
name|vpath_state
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
block|}
name|__hal_srpcim_t
typedef|;
end_typedef

begin_function_decl
name|vxge_hal_status_e
name|__hal_srpcim_alarm_process
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|srpcim_id
parameter_list|,
name|u32
name|skip_alarms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_srpcim_intr_enable
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|srpcim_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_srpcim_intr_disable
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|,
name|u32
name|srpcim_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_srpcim_initialize
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_srpcim_terminate
parameter_list|(
name|__hal_device_t
modifier|*
name|hldev
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_SRPCIM_H */
end_comment

end_unit

