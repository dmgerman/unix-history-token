begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KDB_H_
end_define

begin_include
include|#
directive|include
file|<machine/setjmp.h>
end_include

begin_typedef
typedef|typedef
name|int
name|dbbe_init_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|dbbe_trace_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|dbbe_trap_f
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|kdb_dbbe
block|{
specifier|const
name|char
modifier|*
name|dbbe_name
decl_stmt|;
name|dbbe_init_f
modifier|*
name|dbbe_init
decl_stmt|;
name|dbbe_trace_f
modifier|*
name|dbbe_trace
decl_stmt|;
name|dbbe_trap_f
modifier|*
name|dbbe_trap
decl_stmt|;
name|int
name|dbbe_active
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KDB_BACKEND
parameter_list|(
name|name
parameter_list|,
name|init
parameter_list|,
name|trace
parameter_list|,
name|trap
parameter_list|)
define|\
value|static struct kdb_dbbe name##_dbbe = {		\ 		.dbbe_name = #name,			\ 		.dbbe_init = init,			\ 		.dbbe_trace = trace,			\ 		.dbbe_trap = trap			\ 	};						\ 	DATA_SET(kdb_dbbe_set, name##_dbbe)
end_define

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|kdb_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero while in debugger. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debugger_on_panic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enter the debugger on panic. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|kdb_dbbe
modifier|*
name|kdb_dbbe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default debugger backend or NULL. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|trapframe
modifier|*
name|kdb_frame
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frame to kdb_trap(). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pcb
modifier|*
name|kdb_thrctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current context. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|thread
modifier|*
name|kdb_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current thread. */
end_comment

begin_function_decl
name|int
name|kdb_alt_break
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdb_backtrace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdb_dbbe_select
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdb_enter
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdb_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|kdb_jmpbuf
parameter_list|(
name|jmp_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdb_reenter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcb
modifier|*
name|kdb_thr_ctx
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|kdb_thr_first
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|kdb_thr_from_pid
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|kdb_thr_lookup
parameter_list|(
name|lwpid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|kdb_thr_next
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdb_thr_select
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdb_trap
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KDB_H_ */
end_comment

end_unit

