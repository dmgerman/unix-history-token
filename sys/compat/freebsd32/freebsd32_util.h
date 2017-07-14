begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-1999 Andrew Gallatin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_FREEBSD32_FREEBSD32_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_FREEBSD32_FREEBSD32_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_struct
struct|struct
name|freebsd32_ps_strings
block|{
name|u_int32_t
name|ps_argvstr
decl_stmt|;
comment|/* first of 0 or more argument strings */
name|int
name|ps_nargvstr
decl_stmt|;
comment|/* the number of argument strings */
name|u_int32_t
name|ps_envstr
decl_stmt|;
comment|/* first of 0 or more environment strings */
name|int
name|ps_nenvstr
decl_stmt|;
comment|/* the number of environment strings */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<compat/ia32/ia32_util.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FREEBSD32_PS_STRINGS
define|\
value|(FREEBSD32_USRSTACK - sizeof(struct freebsd32_ps_strings))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|freebsd32_sysent
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SYSCALL32_MODULE
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
value|static struct syscall_module_data name##_syscall32_mod = {     \        evh, arg, offset, new_sysent, { 0, NULL }               \ };                                                             \                                                                \ static moduledata_t name##32_mod = {                           \        "sys32/" #name,                                         \        syscall32_module_handler,                               \&name##_syscall32_mod                                   \ };                                                             \ DECLARE_MODULE(name##32, name##32_mod, SI_SUB_SYSCALLS, SI_ORDER_MIDDLE)
end_define

begin_define
define|#
directive|define
name|SYSCALL32_MODULE_HELPER
parameter_list|(
name|syscallname
parameter_list|)
define|\
value|static int syscallname##_syscall32 = FREEBSD32_SYS_##syscallname; \ static struct sysent syscallname##_sysent32 = {         \     (sizeof(struct syscallname ## _args )               \      / sizeof(register_t)),                             \     (sy_call_t *)& syscallname                          \ };                                                      \ SYSCALL32_MODULE(syscallname,                           \& syscallname##_syscall32,& syscallname##_sysent32,\     NULL, NULL);
end_define

begin_define
define|#
directive|define
name|SYSCALL32_INIT_HELPER_F
parameter_list|(
name|syscallname
parameter_list|,
name|flags
parameter_list|)
value|{		\     .new_sysent = {						\ 	.sy_narg = (sizeof(struct syscallname ## _args )	\ 	    / sizeof(register_t)),				\ 	.sy_call = (sy_call_t *)& syscallname,			\ 	.sy_flags = (flags)					\     },								\     .syscall_no = FREEBSD32_SYS_##syscallname			\ }
end_define

begin_define
define|#
directive|define
name|SYSCALL32_INIT_HELPER_COMPAT_F
parameter_list|(
name|syscallname
parameter_list|,
name|flags
parameter_list|)
value|{	\     .new_sysent = {						\ 	.sy_narg = (sizeof(struct syscallname ## _args )	\ 	    / sizeof(register_t)),				\ 	.sy_call = (sy_call_t *)& sys_ ## syscallname,		\ 	.sy_flags = (flags)					\     },								\     .syscall_no = FREEBSD32_SYS_##syscallname			\ }
end_define

begin_define
define|#
directive|define
name|SYSCALL32_INIT_HELPER
parameter_list|(
name|syscallname
parameter_list|)
define|\
value|SYSCALL32_INIT_HELPER_F(syscallname, 0)
end_define

begin_define
define|#
directive|define
name|SYSCALL32_INIT_HELPER_COMPAT
parameter_list|(
name|syscallname
parameter_list|)
define|\
value|SYSCALL32_INIT_HELPER_COMPAT_F(syscallname, 0)
end_define

begin_function_decl
name|int
name|syscall32_register
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
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall32_deregister
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
name|syscall32_module_handler
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

begin_function_decl
name|int
name|syscall32_helper_register
parameter_list|(
name|struct
name|syscall_helper_data
modifier|*
name|sd
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall32_helper_unregister
parameter_list|(
name|struct
name|syscall_helper_data
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|iovec32
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rusage32
struct_decl|;
end_struct_decl

begin_function_decl
name|register_t
modifier|*
name|freebsd32_copyout_strings
parameter_list|(
name|struct
name|image_params
modifier|*
name|imgp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd32_copyiniov
parameter_list|(
name|struct
name|iovec32
modifier|*
name|iovp
parameter_list|,
name|u_int
name|iovcnt
parameter_list|,
name|struct
name|iovec
modifier|*
modifier|*
name|iov
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freebsd32_rusage_out
parameter_list|(
specifier|const
name|struct
name|rusage
modifier|*
name|s
parameter_list|,
name|struct
name|rusage32
modifier|*
name|s32
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|image_args
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|freebsd32_exec_copyin_args
parameter_list|(
name|struct
name|image_args
modifier|*
name|args
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|enum
name|uio_seg
name|segflg
parameter_list|,
name|u_int32_t
modifier|*
name|argv
parameter_list|,
name|u_int32_t
modifier|*
name|envv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_FREEBSD32_FREEBSD32_UTIL_H_ */
end_comment

end_unit

