begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TSB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TSB_H_
end_define

begin_define
define|#
directive|define
name|MAX_TSB_INFO
value|2
end_define

begin_comment
comment|/*  * Values for "tsb_ttesz_mask" bitmask.  */
end_comment

begin_define
define|#
directive|define
name|TSB8K
value|(1<< TTE8K)
end_define

begin_define
define|#
directive|define
name|TSB64K
value|(1<< TTE64K)
end_define

begin_define
define|#
directive|define
name|TSB512K
value|(1<< TTE512K)
end_define

begin_define
define|#
directive|define
name|TSB4M
value|(1<< TTE4M)
end_define

begin_define
define|#
directive|define
name|TSB32M
value|(1<< TTE32M)
end_define

begin_define
define|#
directive|define
name|TSB256M
value|(1<< TTE256M)
end_define

begin_comment
comment|/*  * Kernel TSBs  */
end_comment

begin_define
define|#
directive|define
name|TSB8K_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TSB4M_INDEX
value|1
end_define

begin_decl_stmt
specifier|extern
name|hv_tsb_info_t
name|kernel_td
index|[
name|MAX_TSB_INFO
index|]
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|hv_tsb_info
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|TSB_INIT_SHIFT
value|3
end_define

begin_function_decl
name|void
name|tsb_init
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|uint64_t
modifier|*
name|scratchval
parameter_list|,
name|uint64_t
name|page_shift
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_deinit
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_assert_invalid
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_set_tte
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|tte_t
name|tte_data
parameter_list|,
name|uint64_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_set_tte_real
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|tte_t
name|tte_data
parameter_list|,
name|uint64_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tsb_get_tte
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tte_t
name|tsb_lookup_tte
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_clear
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_clear_tte
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsb_clear_range
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|,
name|vm_offset_t
name|sva
parameter_list|,
name|vm_offset_t
name|eva
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|tsb_set_scratchpad_kernel
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|tsb_set_scratchpad_user
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsb_size
parameter_list|(
name|struct
name|hv_tsb_info
modifier|*
name|tsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsb_page_shift
parameter_list|(
name|pmap_t
name|pmap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TSB_H_ */
end_comment

end_unit

