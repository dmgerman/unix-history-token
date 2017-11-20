begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1999-2005 Apple Inc.  * Copyright (c) 2016-2017 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by BAE Systems, the University of Cambridge  * Computer Laboratory, and Memorial University under DARPA/AFRL contract  * FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent Computing  * (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|_SECURITY_AUDIT_KERNEL_H_
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
comment|/*  * Audit subsystem condition flags.  The audit_enabled flag is set and  * removed automatically as a result of configuring log files, and can be  * observed but should not be directly manipulated.  The audit suspension  * flag permits audit to be temporarily disabled without reconfiguring the  * audit target.  */
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
comment|/*  * The remaining kernel functions are conditionally compiled in as they are  * wrapped by a macro, and the macro should be the only place in the source  * tree where these functions are referenced.  */
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
name|audit_arg_atfd1
parameter_list|(
name|int
name|atfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_atfd2
parameter_list|(
name|int
name|atfd
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
name|int
name|dirfd
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
name|audit_arg_auditinfo_addr
parameter_list|(
name|struct
name|auditinfo_addr
modifier|*
name|au_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_upath1
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|dirfd
parameter_list|,
name|char
modifier|*
name|upath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_upath1_canon
parameter_list|(
name|char
modifier|*
name|upath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_upath2
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|dirfd
parameter_list|,
name|char
modifier|*
name|upath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_upath2_canon
parameter_list|(
name|char
modifier|*
name|upath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_vnode1
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_vnode2
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
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
name|audit_arg_svipc_which
parameter_list|(
name|int
name|which
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
name|audit_arg_rights
parameter_list|(
name|cap_rights_t
modifier|*
name|rightsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_arg_fcntl_rights
parameter_list|(
name|uint32_t
name|fcntlrights
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
name|audit_cred_copy
parameter_list|(
name|struct
name|ucred
modifier|*
name|src
parameter_list|,
name|struct
name|ucred
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_cred_destroy
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_cred_init
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_cred_kproc0
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_cred_proc1
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_proc_coredump
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|int
name|errcode
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
comment|/*  * Define macros to wrap the audit_arg_* calls by checking the global  * audit_enabled flag before performing the actual call.  */
end_comment

begin_define
define|#
directive|define
name|AUDITING_TD
parameter_list|(
name|td
parameter_list|)
value|((td)->td_pflags& TDP_AUDITREC)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ADDR
parameter_list|(
name|addr
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_addr((addr));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ARGV
parameter_list|(
name|argv
parameter_list|,
name|argc
parameter_list|,
name|length
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_argv((argv), (argc), (length));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ATFD1
parameter_list|(
name|atfd
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_atfd1((atfd));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ATFD2
parameter_list|(
name|atfd
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_atfd2((atfd));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_AUDITON
parameter_list|(
name|udata
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_auditon((udata));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_CMD
parameter_list|(
name|cmd
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_cmd((cmd));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_DEV
parameter_list|(
name|dev
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_dev((dev));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EGID
parameter_list|(
name|egid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_egid((egid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ENVV
parameter_list|(
name|envv
parameter_list|,
name|envc
parameter_list|,
name|length
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_envv((envv), (envc), (length));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EXIT
parameter_list|(
name|status
parameter_list|,
name|retval
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_exit((status), (retval));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EUID
parameter_list|(
name|euid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_euid((euid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FD
parameter_list|(
name|fd
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_fd((fd));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FILE
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_file((p), (fp));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FFLAGS
parameter_list|(
name|fflags
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_fflags((fflags));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_GID
parameter_list|(
name|gid
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_gid((gid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_GROUPSET
parameter_list|(
name|gidset
parameter_list|,
name|gidset_size
parameter_list|)
value|do {			\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_groupset((gidset), (gidset_size));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_LOGIN
parameter_list|(
name|login
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_login((login));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_MODE
parameter_list|(
name|mode
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_mode((mode));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_OWNER
parameter_list|(
name|uid
parameter_list|,
name|gid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_owner((uid), (gid));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_PID
parameter_list|(
name|pid
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_pid((pid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_POSIX_IPC_PERM
parameter_list|(
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|)
value|do {			\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_posix_ipc_perm((uid), (gid), (mod));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_PROCESS
parameter_list|(
name|p
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_process((p));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RGID
parameter_list|(
name|rgid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_rgid((rgid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RIGHTS
parameter_list|(
name|rights
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_rights((rights));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FCNTL_RIGHTS
parameter_list|(
name|fcntlrights
parameter_list|)
value|do {			\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_fcntl_rights((fcntlrights));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RUID
parameter_list|(
name|ruid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_ruid((ruid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SIGNUM
parameter_list|(
name|signum
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_signum((signum));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SGID
parameter_list|(
name|sgid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_sgid((sgid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SOCKET
parameter_list|(
name|sodomain
parameter_list|,
name|sotype
parameter_list|,
name|soprotocol
parameter_list|)
value|do {		\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_socket((sodomain), (sotype), (soprotocol));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SOCKADDR
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|sa
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_sockaddr((td), (dirfd), (sa));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SUID
parameter_list|(
name|suid
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_suid((suid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_CMD
parameter_list|(
name|cmd
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_svipc_cmd((cmd));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_PERM
parameter_list|(
name|perm
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_svipc_perm((perm));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_ID
parameter_list|(
name|id
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_svipc_id((id));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_ADDR
parameter_list|(
name|addr
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_svipc_addr((addr));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_WHICH
parameter_list|(
name|which
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_svipc_which((which));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_TEXT
parameter_list|(
name|text
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_text((text));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UID
parameter_list|(
name|uid
parameter_list|)
value|do {						\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_uid((uid));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH1
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|upath
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_upath1((td), (dirfd), (upath));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH1_CANON
parameter_list|(
name|upath
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_upath1_canon((upath));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH2
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|upath
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_upath2((td), (dirfd), (upath));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH2_CANON
parameter_list|(
name|upath
parameter_list|)
value|do {				\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_upath2_canon((upath));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VALUE
parameter_list|(
name|value
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_value((value));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VNODE1
parameter_list|(
name|vp
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_vnode1((vp));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VNODE2
parameter_list|(
name|vp
parameter_list|)
value|do {					\ 	if (AUDITING_TD(curthread))					\ 		audit_arg_vnode2((vp));					\ } while (0)
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
comment|/*  * Wrap the audit_syscall_exit() function so that it is called only when  * we have a audit record on the thread.  Audit records can persist after  * auditing is disabled, so we don't just check audit_enabled here.  */
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
value|do {				\ 	if (td->td_pflags& TDP_AUDITREC)				\ 		audit_syscall_exit(error, td);				\ } while (0)
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
value|do {					\ 	if (td->td_pflags& TDP_AUDITREC)				\ 		audit_sysclose(td, fd);					\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !AUDIT */
end_comment

begin_define
define|#
directive|define
name|AUDIT_ARG_ADDR
parameter_list|(
name|addr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ARGV
parameter_list|(
name|argv
parameter_list|,
name|argc
parameter_list|,
name|length
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ATFD1
parameter_list|(
name|atfd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ATFD2
parameter_list|(
name|atfd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_AUDITON
parameter_list|(
name|udata
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_CMD
parameter_list|(
name|cmd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_DEV
parameter_list|(
name|dev
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EGID
parameter_list|(
name|egid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_ENVV
parameter_list|(
name|envv
parameter_list|,
name|envc
parameter_list|,
name|length
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EXIT
parameter_list|(
name|status
parameter_list|,
name|retval
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_EUID
parameter_list|(
name|euid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FD
parameter_list|(
name|fd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FILE
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FFLAGS
parameter_list|(
name|fflags
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_GID
parameter_list|(
name|gid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_GROUPSET
parameter_list|(
name|gidset
parameter_list|,
name|gidset_size
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_LOGIN
parameter_list|(
name|login
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_MODE
parameter_list|(
name|mode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_OWNER
parameter_list|(
name|uid
parameter_list|,
name|gid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_PID
parameter_list|(
name|pid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_POSIX_IPC_PERM
parameter_list|(
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_PROCESS
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RGID
parameter_list|(
name|rgid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RIGHTS
parameter_list|(
name|rights
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_FCNTL_RIGHTS
parameter_list|(
name|fcntlrights
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_RUID
parameter_list|(
name|ruid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SIGNUM
parameter_list|(
name|signum
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SGID
parameter_list|(
name|sgid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SOCKET
parameter_list|(
name|sodomain
parameter_list|,
name|sotype
parameter_list|,
name|soprotocol
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SOCKADDR
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|sa
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SUID
parameter_list|(
name|suid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_CMD
parameter_list|(
name|cmd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_PERM
parameter_list|(
name|perm
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_ID
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_ADDR
parameter_list|(
name|addr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_SVIPC_WHICH
parameter_list|(
name|which
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_TEXT
parameter_list|(
name|text
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UID
parameter_list|(
name|uid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH1
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|upath
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH1_CANON
parameter_list|(
name|upath
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH2
parameter_list|(
name|td
parameter_list|,
name|dirfd
parameter_list|,
name|upath
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_UPATH2_CANON
parameter_list|(
name|upath
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VALUE
parameter_list|(
name|value
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VNODE1
parameter_list|(
name|vp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AUDIT_ARG_VNODE2
parameter_list|(
name|vp
parameter_list|)
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

