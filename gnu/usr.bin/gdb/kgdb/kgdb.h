begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KGDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_KGDB_H_
end_define

begin_struct_decl
struct_decl|struct
name|thread_info
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|kvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|kthr
block|{
name|struct
name|kthr
modifier|*
name|next
decl_stmt|;
name|uintptr_t
name|paddr
decl_stmt|;
name|uintptr_t
name|kaddr
decl_stmt|;
name|uintptr_t
name|kstack
decl_stmt|;
name|uintptr_t
name|pcb
decl_stmt|;
name|int
name|tid
decl_stmt|;
name|int
name|pid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|kthr
modifier|*
name|curkthr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|kgdb_target
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kgdb_trgt_fetch_registers
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kgdb_trgt_store_registers
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|frame_unwind_sniffer_ftype
name|kgdb_trgt_trapframe_sniffer
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_first
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_lookup_tid
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_lookup_pid
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_lookup_paddr
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_lookup_taddr
parameter_list|(
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_next
parameter_list|(
name|struct
name|kthr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kthr
modifier|*
name|kgdb_thr_select
parameter_list|(
name|struct
name|kthr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|kgdb_thr_extra_thread_info
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintptr_t
name|kgdb_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|sym
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KGDB_H_ */
end_comment

end_unit

