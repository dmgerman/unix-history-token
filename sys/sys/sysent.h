begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSENT_H_
end_define

begin_include
include|#
directive|include
file|<bsm/audit.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ksiginfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|sy_call_t
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Used by the machine dependent syscall() code. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|systrace_probe_func_t
function_decl|)
parameter_list|(
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|sysent
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Used by loaded syscalls to convert arguments to a DTrace array  * of 64-bit arguments.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|systrace_args_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int64_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|systrace_probe_func_t
name|systrace_probe_func
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sysent
block|{
comment|/* system call table */
name|int
name|sy_narg
decl_stmt|;
comment|/* number of arguments */
name|sy_call_t
modifier|*
name|sy_call
decl_stmt|;
comment|/* implementing function */
name|au_event_t
name|sy_auevent
decl_stmt|;
comment|/* audit event associated with syscall */
name|systrace_args_func_t
name|sy_systrace_args_func
decl_stmt|;
comment|/* optional argument conversion function. */
name|u_int32_t
name|sy_entry
decl_stmt|;
comment|/* DTrace entry ID for systrace. */
name|u_int32_t
name|sy_return
decl_stmt|;
comment|/* DTrace return ID for systrace. */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|__sigset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sysentvec
block|{
name|int
name|sv_size
decl_stmt|;
comment|/* number of entries */
name|struct
name|sysent
modifier|*
name|sv_table
decl_stmt|;
comment|/* pointer to sysent */
name|u_int
name|sv_mask
decl_stmt|;
comment|/* optional mask to index */
name|int
name|sv_sigsize
decl_stmt|;
comment|/* size of signal translation table */
name|int
modifier|*
name|sv_sigtbl
decl_stmt|;
comment|/* signal translation table */
name|int
name|sv_errsize
decl_stmt|;
comment|/* size of errno translation table */
name|int
modifier|*
name|sv_errtbl
decl_stmt|;
comment|/* errno translation table */
name|int
function_decl|(
modifier|*
name|sv_transtrap
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* translate trap-to-signal mapping */
name|int
function_decl|(
modifier|*
name|sv_fixup
function_decl|)
parameter_list|(
name|register_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
comment|/* stack fixup function */
name|void
function_decl|(
modifier|*
name|sv_sendsig
function_decl|)
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|struct
name|ksiginfo
modifier|*
parameter_list|,
name|struct
name|__sigset
modifier|*
parameter_list|)
function_decl|;
comment|/* send signal */
name|char
modifier|*
name|sv_sigcode
decl_stmt|;
comment|/* start of sigtramp code */
name|int
modifier|*
name|sv_szsigcode
decl_stmt|;
comment|/* size of sigtramp code */
name|void
function_decl|(
modifier|*
name|sv_prepsyscall
function_decl|)
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
name|sv_name
decl_stmt|;
comment|/* name of binary type */
name|int
function_decl|(
modifier|*
name|sv_coredump
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
comment|/* function to dump core, or NULL */
name|int
function_decl|(
modifier|*
name|sv_imgact_try
function_decl|)
parameter_list|(
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
name|int
name|sv_minsigstksz
decl_stmt|;
comment|/* minimum signal stack size */
name|int
name|sv_pagesize
decl_stmt|;
comment|/* pagesize */
name|vm_offset_t
name|sv_minuser
decl_stmt|;
comment|/* VM_MIN_ADDRESS */
name|vm_offset_t
name|sv_maxuser
decl_stmt|;
comment|/* VM_MAXUSER_ADDRESS */
name|vm_offset_t
name|sv_usrstack
decl_stmt|;
comment|/* USRSTACK */
name|vm_offset_t
name|sv_psstrings
decl_stmt|;
comment|/* PS_STRINGS */
name|int
name|sv_stackprot
decl_stmt|;
comment|/* vm protection for stack */
name|register_t
modifier|*
function_decl|(
modifier|*
name|sv_copyout_strings
function_decl|)
parameter_list|(
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sv_setregs
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sv_fixlimits
function_decl|)
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|aout_sysvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|elf_freebsd_sysvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysentvec
name|null_sysvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|sysent
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NO_SYSCALL
value|(-1)
end_define

begin_struct_decl
struct_decl|struct
name|module
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|syscall_module_data
block|{
name|int
function_decl|(
modifier|*
name|chainevh
function_decl|)
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* next handler */
name|void
modifier|*
name|chainarg
decl_stmt|;
comment|/* arg for next event handler */
name|int
modifier|*
name|offset
decl_stmt|;
comment|/* offset into sysent */
name|struct
name|sysent
modifier|*
name|new_sysent
decl_stmt|;
comment|/* new sysent */
name|struct
name|sysent
name|old_sysent
decl_stmt|;
comment|/* old sysent */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYSCALL_MODULE
parameter_list|(
name|name
parameter_list|,
name|offset
parameter_list|,
name|new_sysent
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct syscall_module_data name##_syscall_mod = {       \        evh, arg, offset, new_sysent, { 0, NULL, AUE_NULL }     \ };                                                             \                                                                \ static moduledata_t name##_mod = {                             \        #name,                                                  \        syscall_module_handler,                                 \&name##_syscall_mod                                     \ };                                                             \ DECLARE_MODULE(name, name##_mod, SI_SUB_SYSCALLS, SI_ORDER_MIDDLE)
end_define

begin_define
define|#
directive|define
name|SYSCALL_MODULE_HELPER
parameter_list|(
name|syscallname
parameter_list|)
define|\
value|static int syscallname##_syscall = SYS_##syscallname;   \ static struct sysent syscallname##_sysent = {           \     (sizeof(struct syscallname ## _args )               \      / sizeof(register_t)),                             \     (sy_call_t *)& syscallname,                         \     SYS_AUE_##syscallname                               \ };                                                      \ SYSCALL_MODULE(syscallname,                             \& syscallname##_syscall,& syscallname##_sysent,    \     NULL, NULL);
end_define

begin_define
define|#
directive|define
name|SYSCALL_MODULE_PRESENT
parameter_list|(
name|syscallname
parameter_list|)
define|\
value|(sysent[SYS_##syscallname].sy_call !=		\ 			(sy_call_t *)lkmnosys&&	\ 	sysent[SYS_##syscallname].sy_call !=		\ 			(sy_call_t *)lkmressys)
end_define

begin_function_decl
name|int
name|syscall_register
parameter_list|(
name|int
modifier|*
name|offset
parameter_list|,
name|struct
name|sysent
modifier|*
name|new_sysent
parameter_list|,
name|struct
name|sysent
modifier|*
name|old_sysent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall_deregister
parameter_list|(
name|int
modifier|*
name|offset
parameter_list|,
name|struct
name|sysent
modifier|*
name|old_sysent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall_module_handler
parameter_list|(
name|struct
name|module
modifier|*
name|mod
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSENT_H_ */
end_comment

end_unit

