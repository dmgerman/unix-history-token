begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2005 Apple Computer, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header includes function prototypes and type definitions that are  * necessary for the kernel as a whole to interact with the audit subsystem.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_AUDIT_KERNEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SEUCRITY_AUDIT_KERNEL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<bsm/audit.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_comment
comment|/*  * Audit subsystem condition flags.  The audit_enabled flag is set and  * removed automatically as a result of configuring log files, and  * can be observed but should not be directly manipulated.  The audit  * suspension flag permits audit to be temporarily disabled without  * reconfiguring the audit target.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|audit_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_suspended
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define the masks for the audited arguments.  *  * XXXRW: These need to remain in audit.h for now because our vnode and name  * lookup audit calls rely on passing in flags to indicate which name or  * vnode is being logged.  These should move to audit_private.h when that is  * fixed.  */
end_comment

begin_define
define|#
directive|define
name|ARG_EUID
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|ARG_RUID
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|ARG_SUID
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|ARG_EGID
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|ARG_RGID
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|ARG_SGID
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|ARG_PID
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|ARG_UID
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|ARG_AUID
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|ARG_GID
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|ARG_FD
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|ARG_POSIX_IPC_PERM
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|ARG_FFLAGS
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|ARG_MODE
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|ARG_DEV
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ADDR
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|ARG_LEN
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|ARG_MASK
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SIGNUM
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|ARG_LOGIN
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SADDRINET
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SADDRINET6
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SADDRUNIX
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|ARG_TERMID_ADDR
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|ARG_UNUSED2
value|0x0000000001000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_UPATH1
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_UPATH2
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_TEXT
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_VNODE1
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_VNODE2
value|0x0000000020000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SVIPC_CMD
value|0x0000000040000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SVIPC_PERM
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SVIPC_ID
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SVIPC_ADDR
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_GROUPSET
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_CMD
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_SOCKINFO
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ASID
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_TERMID
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_AUDITON
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_VALUE
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_AMASK
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_CTLNAME
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_PROCESS
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_MACHPORT1
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_MACHPORT2
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_EXIT
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_IOVECSTR
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ARGV
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ENVV
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_NONE
value|0x0000000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ALL
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_function_decl
name|void
name|audit_syscall_enter
parameter_list|(
name|unsigned
name|short
name|code
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_syscall_exit
parameter_list|(
name|int
name|error
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The remaining kernel functions are conditionally compiled in as they  * are wrapped by a macro, and the macro should be the only place in  * the source tree where these functions are referenced.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIT
end_ifdef

begin_struct_decl
struct_decl|struct
name|ipc_perm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|auditon_udata
union_decl|;
end_union_decl

begin_function_decl
name|void
name|audit_arg_addr
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_exit
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_len
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_fd
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_fflags
parameter_list|(
name|int
name|fflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_gid
parameter_list|(
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_uid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_egid
parameter_list|(
name|gid_t
name|egid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_euid
parameter_list|(
name|uid_t
name|euid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_rgid
parameter_list|(
name|gid_t
name|rgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_ruid
parameter_list|(
name|uid_t
name|ruid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_sgid
parameter_list|(
name|gid_t
name|sgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_suid
parameter_list|(
name|uid_t
name|suid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_groupset
parameter_list|(
name|gid_t
modifier|*
name|gidset
parameter_list|,
name|u_int
name|gidset_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_login
parameter_list|(
name|char
modifier|*
name|login
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_ctlname
parameter_list|(
name|int
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_mask
parameter_list|(
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_mode
parameter_list|(
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_dev
parameter_list|(
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_value
parameter_list|(
name|long
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_owner
parameter_list|(
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_pid
parameter_list|(
name|pid_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_process
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_signum
parameter_list|(
name|u_int
name|signum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_socket
parameter_list|(
name|int
name|sodomain
parameter_list|,
name|int
name|sotype
parameter_list|,
name|int
name|soprotocol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_sockaddr
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_auid
parameter_list|(
name|uid_t
name|auid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_auditinfo
parameter_list|(
name|struct
name|auditinfo
modifier|*
name|au_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_upath
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|upath
parameter_list|,
name|u_int64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_vnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_int64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_text
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_cmd
parameter_list|(
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_svipc_cmd
parameter_list|(
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_svipc_perm
parameter_list|(
name|struct
name|ipc_perm
modifier|*
name|perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_svipc_id
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_svipc_addr
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_posix_ipc_perm
parameter_list|(
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_auditon
parameter_list|(
name|union
name|auditon_udata
modifier|*
name|udata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_file
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_argv
parameter_list|(
name|char
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_envv
parameter_list|(
name|char
modifier|*
name|envv
parameter_list|,
name|int
name|envc
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_sysclose
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_alloc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_kproc0
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_init
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|parent
parameter_list|,
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_free
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_thread_alloc
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_thread_free
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Define a macro to wrap the audit_arg_* calls by checking the global  * audit_enabled flag before performing the actual call.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_ARG
parameter_list|(
name|op
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {					\ 	if (audit_enabled)						\ 		audit_arg_ ## op (args);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_SYSCALL_ENTER
parameter_list|(
name|code
parameter_list|,
name|td
parameter_list|)
value|do {				\ 	if (audit_enabled) {						\ 		audit_syscall_enter(code, td);				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Wrap the audit_syscall_exit() function so that it is called only when  * auditing is enabled, or we have a audit record on the thread. It is  * possible that an audit record was begun before auditing was turned off.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_SYSCALL_EXIT
parameter_list|(
name|error
parameter_list|,
name|td
parameter_list|)
value|do {				\ 	if (audit_enabled | (td->td_ar != NULL))			\ 		audit_syscall_exit(error, td);				\ } while (0)
end_define

begin_comment
comment|/*  * A Macro to wrap the audit_sysclose() function.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_SYSCLOSE
parameter_list|(
name|td
parameter_list|,
name|fd
parameter_list|)
value|do {					\ 	if (audit_enabled)						\ 		audit_sysclose(td, fd);					\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !AUDIT */
end_comment

begin_function_decl
name|void
name|audit_proc_init
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|parent
parameter_list|,
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_free
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AUDIT_ARG
parameter_list|(
name|op
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_SYSCALL_ENTER
parameter_list|(
name|code
parameter_list|,
name|td
parameter_list|)
value|do {				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_SYSCALL_EXIT
parameter_list|(
name|error
parameter_list|,
name|td
parameter_list|)
value|do {				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_SYSCLOSE
parameter_list|(
name|p
parameter_list|,
name|fd
parameter_list|)
value|do {					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUDIT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SECURITY_AUDIT_KERNEL_H_ */
end_comment

end_unit

