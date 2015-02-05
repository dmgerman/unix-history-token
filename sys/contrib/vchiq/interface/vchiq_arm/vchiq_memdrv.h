begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_MEMDRV_H
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_MEMDRV_H
end_define

begin_comment
comment|/* ---- Include Files ----------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|"vchiq_if.h"
end_include

begin_comment
comment|/* ---- Constants and Types ---------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|armSharedMemVirt
decl_stmt|;
name|dma_addr_t
name|armSharedMemPhys
decl_stmt|;
name|size_t
name|armSharedMemSize
decl_stmt|;
name|void
modifier|*
name|vcSharedMemVirt
decl_stmt|;
name|dma_addr_t
name|vcSharedMemPhys
decl_stmt|;
name|size_t
name|vcSharedMemSize
decl_stmt|;
block|}
name|VCHIQ_SHARED_MEM_INFO_T
typedef|;
end_typedef

begin_comment
comment|/* ---- Variable Externs ------------------------------------------------- */
end_comment

begin_comment
comment|/* ---- Function Prototypes ---------------------------------------------- */
end_comment

begin_function_decl
name|void
name|vchiq_get_shared_mem_info
parameter_list|(
name|VCHIQ_SHARED_MEM_INFO_T
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VCHIQ_STATUS_T
name|vchiq_memdrv_initialise
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VCHIQ_STATUS_T
name|vchiq_userdrv_create_instance
parameter_list|(
specifier|const
name|VCHIQ_PLATFORM_DATA_T
modifier|*
name|platform_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VCHIQ_STATUS_T
name|vchiq_userdrv_suspend
parameter_list|(
specifier|const
name|VCHIQ_PLATFORM_DATA_T
modifier|*
name|platform_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VCHIQ_STATUS_T
name|vchiq_userdrv_resume
parameter_list|(
specifier|const
name|VCHIQ_PLATFORM_DATA_T
modifier|*
name|platform_data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

