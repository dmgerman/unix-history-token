begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|ia64_unwind_table
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ia64_unwind_table
modifier|*
name|ia64_add_unwind_table
parameter_list|(
name|u_int64_t
modifier|*
name|base
parameter_list|,
name|u_int64_t
modifier|*
name|start
parameter_list|,
name|u_int64_t
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_free_unwind_table
parameter_list|(
name|struct
name|ia64_unwind_table
modifier|*
name|ut
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ia64_unwind_state
modifier|*
name|ia64_create_unwind_state
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_free_unwind_state
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|ia64_unwind_state_get_ip
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|ia64_unwind_state_get_sp
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|ia64_unwind_state_get_cfm
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
modifier|*
name|ia64_unwind_state_get_bsp
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_unwind_state_previous_frame
parameter_list|(
name|struct
name|ia64_unwind_state
modifier|*
name|us
parameter_list|)
function_decl|;
end_function_decl

end_unit

