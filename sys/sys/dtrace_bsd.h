begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * This file contains BSD shims for Sun's DTrace code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DTRACE_BSD_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DTRACE_BSD_H
end_define

begin_comment
comment|/* Forward definitions: */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devstat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Cyclic clock function type definition used to hook the cyclic  * subsystem into the appropriate timer interrupt.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cyclic_clock_func_t
function_decl|)
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|cyclic_clock_func_t
name|cyclic_clock_func
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|clocksource_cyc_set
parameter_list|(
specifier|const
name|struct
name|bintime
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The dtrace module handles traps that occur during a DTrace probe.  * This type definition is used in the trap handler to provide a  * hook for the dtrace module to register it's handler with.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dtrace_trap_func_t
function_decl|)
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|dtrace_trap
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|dtrace_trap_func_t
name|dtrace_trap_func
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A hook which removes active FBT probes before executing the double fault  * handler. We want to ensure that DTrace doesn't trigger another trap, which  * would result in a reset.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dtrace_invop_func_t
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_doubletrap_func_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_invop_func_t
name|dtrace_invop_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_doubletrap_func_t
name|dtrace_doubletrap_func
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pid provider hooks */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dtrace_pid_probe_ptr_t
function_decl|)
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_pid_probe_ptr_t
name|dtrace_pid_probe_ptr
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dtrace_return_probe_ptr_t
function_decl|)
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_return_probe_ptr_t
name|dtrace_return_probe_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Virtual time hook function type. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_vtime_switch_func_t
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|dtrace_vtime_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_vtime_switch_func_t
name|dtrace_vtime_switch_func
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The fasttrap module hooks into the fork, exit and exit. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_fork_func_t
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_execexit_func_t
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Global variable in kern_fork.c */
end_comment

begin_decl_stmt
specifier|extern
name|dtrace_fork_func_t
name|dtrace_fasttrap_fork
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global variable in kern_exec.c */
end_comment

begin_decl_stmt
specifier|extern
name|dtrace_execexit_func_t
name|dtrace_fasttrap_exec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global variable in kern_exit.c */
end_comment

begin_decl_stmt
specifier|extern
name|dtrace_execexit_func_t
name|dtrace_fasttrap_exit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The dtmalloc provider hooks into malloc. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_malloc_probe_func_t
function_decl|)
parameter_list|(
name|u_int32_t
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_malloc_probe_func_t
name|dtrace_malloc_probe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dtnfsclient NFSv[34] access cache provider hooks. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_accesscache_flush_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_flush_probe_func_t
name|dtrace_nfsclient_accesscache_flush_done_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_flush_probe_func_t
name|dtrace_nfscl_accesscache_flush_done_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_accesscache_get_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_get_probe_func_t
name|dtrace_nfsclient_accesscache_get_hit_probe
decl_stmt|,
name|dtrace_nfsclient_accesscache_get_miss_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_get_probe_func_t
name|dtrace_nfscl_accesscache_get_hit_probe
decl_stmt|,
name|dtrace_nfscl_accesscache_get_miss_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_accesscache_load_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_load_probe_func_t
name|dtrace_nfsclient_accesscache_load_done_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_accesscache_load_probe_func_t
name|dtrace_nfscl_accesscache_load_done_probe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dtnfsclient NFSv[234] attribute cache provider hooks. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_attrcache_flush_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_flush_probe_func_t
name|dtrace_nfsclient_attrcache_flush_done_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_flush_probe_func_t
name|dtrace_nfscl_attrcache_flush_done_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_attrcache_get_hit_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_get_hit_probe_func_t
name|dtrace_nfsclient_attrcache_get_hit_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_get_hit_probe_func_t
name|dtrace_nfscl_attrcache_get_hit_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_attrcache_get_miss_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_get_miss_probe_func_t
name|dtrace_nfsclient_attrcache_get_miss_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_get_miss_probe_func_t
name|dtrace_nfscl_attrcache_get_miss_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_attrcache_load_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_load_probe_func_t
name|dtrace_nfsclient_attrcache_load_done_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_attrcache_load_probe_func_t
name|dtrace_nfscl_attrcache_load_done_probe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dtnfsclient NFSv[234] RPC provider hooks. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_nfs23_start_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_nfs23_start_probe_func_t
name|dtrace_nfsclient_nfs23_start_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_nfs23_start_probe_func_t
name|dtrace_nfscl_nfs234_start_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_nfsclient_nfs23_done_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_nfs23_done_probe_func_t
name|dtrace_nfsclient_nfs23_done_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dtrace_nfsclient_nfs23_done_probe_func_t
name|dtrace_nfscl_nfs234_done_probe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IO Provider hooks, really hook into devstat */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_io_start_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|bio
modifier|*
parameter_list|,
name|struct
name|devstat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_io_start_probe_func_t
name|dtrace_io_start_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_io_done_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|struct
name|bio
modifier|*
parameter_list|,
name|struct
name|devstat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_io_done_probe_func_t
name|dtrace_io_done_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_io_wait_start_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|,
name|struct
name|devstat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_io_wait_start_probe_func_t
name|dtrace_io_wait_start_probe
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dtrace_io_wait_done_probe_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|,
name|struct
name|devstat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|dtrace_io_wait_done_probe_func_t
name|dtrace_io_wait_done_probe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions which allow the dtrace module to check that the kernel   * hooks have been compiled with sufficient space for it's private  * structures.  */
end_comment

begin_function_decl
name|size_t
name|kdtrace_proc_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|kdtrace_thread_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * OpenSolaris compatible time functions returning nanoseconds.  * On OpenSolaris these return hrtime_t which we define as uint64_t.  */
end_comment

begin_function_decl
name|uint64_t
name|dtrace_gethrtime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|dtrace_gethrestime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DTRACE_BSD_H */
end_comment

end_unit

