begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SBI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SBI_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|base
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint64_t
name|node_id
decl_stmt|;
block|}
name|memory_block_info
typedef|;
end_typedef

begin_function_decl
name|uint64_t
name|sbi_query_memory
parameter_list|(
name|uint64_t
name|id
parameter_list|,
name|memory_block_info
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_hart_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_num_harts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_timebase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_set_timer
parameter_list|(
name|uint64_t
name|stime_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_send_ipi
parameter_list|(
name|uint64_t
name|hart_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_clear_ipi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_console_putchar
parameter_list|(
name|unsigned
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbi_console_getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_remote_sfence_vm
parameter_list|(
name|uint64_t
name|hart_mask_ptr
parameter_list|,
name|uint64_t
name|asid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_remote_sfence_vm_range
parameter_list|(
name|uint64_t
name|hart_mask_ptr
parameter_list|,
name|uint64_t
name|asid
parameter_list|,
name|uint64_t
name|start
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbi_remote_fence_i
parameter_list|(
name|uint64_t
name|hart_mask_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_mask_interrupt
parameter_list|(
name|uint64_t
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|sbi_unmask_interrupt
parameter_list|(
name|uint64_t
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SBI_H_ */
end_comment

end_unit

