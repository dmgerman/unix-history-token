begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/include/md_var.h,v 1.40 2001/07/12  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MD_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MD_VAR_H_
end_define

begin_typedef
typedef|typedef
name|void
name|cpu_block_copy_t
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|cpu_block_zero_t
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
name|tl0_base
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|_end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Maxmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|kstack0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|kstack0_phys
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|md_utrap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|cpu_identify
parameter_list|(
name|u_long
name|vers
parameter_list|,
name|u_int
name|clock
parameter_list|,
name|u_int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_setregs
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_physical_memory
parameter_list|(
name|vm_paddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|md_utrap
modifier|*
name|utrap_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utrap_free
parameter_list|(
name|struct
name|md_utrap
modifier|*
name|ut
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|md_utrap
modifier|*
name|utrap_hold
parameter_list|(
name|struct
name|md_utrap
modifier|*
name|ut
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|cpu_block_copy_t
name|spitfire_block_copy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cpu_block_zero_t
name|spitfire_block_zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpu_block_copy_t
modifier|*
name|cpu_block_copy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpu_block_zero_t
modifier|*
name|cpu_block_zero
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

