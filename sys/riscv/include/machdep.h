begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2017 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MACHDEP_H_
end_define

begin_struct
struct|struct
name|riscv_bootparams
block|{
name|vm_offset_t
name|kern_l1pt
decl_stmt|;
comment|/* Kernel L1 base */
name|vm_offset_t
name|kern_phys
decl_stmt|;
comment|/* Kernel base (physical) addr */
name|vm_offset_t
name|kern_stack
decl_stmt|;
name|vm_offset_t
name|dtbp_virt
decl_stmt|;
comment|/* Device tree blob virtual addr */
name|vm_offset_t
name|dtbp_phys
decl_stmt|;
comment|/* Device tree blob physical addr */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|physmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|physmap_idx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|vm_offset_t
name|fake_preload_metadata
parameter_list|(
name|struct
name|riscv_bootparams
modifier|*
name|rbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initriscv
parameter_list|(
name|struct
name|riscv_bootparams
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MACHDEP_H_ */
end_comment

end_unit

