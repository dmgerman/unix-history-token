begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_ALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_ALLOC_H_
end_define

begin_struct_decl
struct_decl|struct
name|i40e_hw
struct_decl|;
end_struct_decl

begin_comment
comment|/* Memory allocation types */
end_comment

begin_enum
enum|enum
name|i40e_memory_type
block|{
name|i40e_mem_arq_buf
init|=
literal|0
block|,
comment|/* ARQ indirect command buffer */
name|i40e_mem_asq_buf
init|=
literal|1
block|,
name|i40e_mem_atq_buf
init|=
literal|2
block|,
comment|/* ATQ indirect command buffer */
name|i40e_mem_arq_ring
init|=
literal|3
block|,
comment|/* ARQ descriptor ring */
name|i40e_mem_atq_ring
init|=
literal|4
block|,
comment|/* ATQ descriptor ring */
name|i40e_mem_pd
init|=
literal|5
block|,
comment|/* Page Descriptor */
name|i40e_mem_bp
init|=
literal|6
block|,
comment|/* Backing Page - 4KB */
name|i40e_mem_bp_jumbo
init|=
literal|7
block|,
comment|/* Backing Page -> 4KB */
name|i40e_mem_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* prototype for functions used for dynamic memory allocation */
end_comment

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_allocate_dma
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_dma_mem
modifier|*
name|mem
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|u32
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_free_dma
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_dma_mem
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_allocate_virt
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_virt_mem
modifier|*
name|mem
parameter_list|,
name|u32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|i40e_status_code
name|i40e_free_virt
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|i40e_virt_mem
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_ALLOC_H_ */
end_comment

end_unit

