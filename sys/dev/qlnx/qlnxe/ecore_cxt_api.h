begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_CXT_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_CXT_API_H__
end_define

begin_struct_decl
struct_decl|struct
name|ecore_hwfn
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ecore_cxt_info
block|{
name|void
modifier|*
name|p_cxt
decl_stmt|;
name|u32
name|iid
decl_stmt|;
name|enum
name|protocol_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_TID_BLOCKS
value|512
end_define

begin_struct
struct|struct
name|ecore_tid_mem
block|{
name|u32
name|tid_size
decl_stmt|;
name|u32
name|num_tids_per_block
decl_stmt|;
name|u32
name|waste
decl_stmt|;
name|u8
modifier|*
name|blocks
index|[
name|MAX_TID_BLOCKS
index|]
decl_stmt|;
comment|/* 4K */
block|}
struct|;
end_struct

begin_comment
comment|/** * @brief ecoreo_cid_get_cxt_info - Returns the context info for a specific cid * * * @param p_hwfn * @param p_info in/out * * @return enum _ecore_status_t */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_get_cid_info
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_cxt_info
modifier|*
name|p_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_cxt_get_tid_mem_info * * @param p_hwfn * @param p_info * * @return enum _ecore_status_t */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_cxt_get_tid_mem_info
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_tid_mem
modifier|*
name|p_info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

