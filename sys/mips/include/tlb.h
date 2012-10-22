begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2010 Juli Mallett<jmallett@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TLB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TLB_H_
end_define

begin_comment
comment|/*  * The first TLB entry that write random hits.  * TLB entry 0 maps the kernel stack of the currently running thread  * TLB entry 1 maps the pcpu area of processor (only for SMP builds)  */
end_comment

begin_define
define|#
directive|define
name|KSTACK_TLB_ENTRY
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|PCPU_TLB_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|VMWIRED_ENTRIES
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VMWIRED_ENTRIES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * The number of process id entries.  */
end_comment

begin_define
define|#
directive|define
name|VMNUM_PIDS
value|256
end_define

begin_decl_stmt
specifier|extern
name|int
name|num_tlbentries
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tlb_insert_wired
parameter_list|(
name|unsigned
parameter_list|,
name|vm_offset_t
parameter_list|,
name|pt_entry_t
parameter_list|,
name|pt_entry_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_invalidate_address
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_invalidate_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_invalidate_all_user
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_invalidate_range
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_save
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tlb_update
parameter_list|(
name|struct
name|pmap
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|pt_entry_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TLB_H_ */
end_comment

end_unit

