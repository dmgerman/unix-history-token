begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_INIT_OPS__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_INIT_OPS__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_comment
comment|/**  * @brief ecore_init_iro_array - init iro_arr.  *  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_init_iro_array
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_run - Run the init-sequence.  *  *  * @param p_hwfn  * @param p_ptt  * @param phase   * @param phase_id   * @param modes  * @return _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_init_run
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|int
name|phase
parameter_list|,
name|int
name|phase_id
parameter_list|,
name|int
name|modes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_hwfn_allocate - Allocate RT array, Store 'values' ptrs.  *  *  * @param p_hwfn  *  * @return _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_init_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_hwfn_deallocate  *  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_init_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_clear_rt_data - Clears the runtime init array.  *  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_init_clear_rt_data
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_init_store_rt_reg - Store a configuration value in the RT array.  *  *  * @param p_hwfn  * @param rt_offset  * @param val  */
end_comment

begin_function_decl
name|void
name|ecore_init_store_rt_reg
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|rt_offset
parameter_list|,
name|u32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STORE_RT_REG
parameter_list|(
name|hwfn
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|ecore_init_store_rt_reg(hwfn, offset, val)
end_define

begin_define
define|#
directive|define
name|OVERWRITE_RT_REG
parameter_list|(
name|hwfn
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|ecore_init_store_rt_reg(hwfn, offset, val)
end_define

begin_comment
comment|/** * @brief * * * @param p_hwfn * @param rt_offset * @param val * @param size */
end_comment

begin_function_decl
name|void
name|ecore_init_store_rt_agg
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|rt_offset
parameter_list|,
name|u32
modifier|*
name|val
parameter_list|,
name|osal_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STORE_RT_REG_AGG
parameter_list|(
name|hwfn
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|ecore_init_store_rt_agg(hwfn, offset, (u32*)&val, sizeof(val))
end_define

begin_comment
comment|/**  * @brief   *      Initialize GTT global windows and set admin window  *      related params of GTT/PTT to default values.   *   * @param p_hwfn   */
end_comment

begin_function_decl
name|void
name|ecore_gtt_init
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_INIT_OPS__ */
end_comment

end_unit

