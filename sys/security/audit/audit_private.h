begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2009 Apple Inc.  * Copyright (c) 2016-2017 Robert N. M. Watson  * All rights reserved.  *  * Portions of this software were developed by BAE Systems, the University of  * Cambridge Computer Laboratory, and Memorial University under DARPA/AFRL  * contract FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent  * Computing (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This include file contains function prototypes and type definitions used  * within the audit implementation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_AUDIT_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_AUDIT_PRIVATE_H_
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
file|<sys/caprights.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AUDITBSM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AUDITDATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AUDITPATH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AUDITTEXT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_AUDITGIDSET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Audit control variables that are usually set/read via system calls and  * used to control various aspects of auditing.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|au_qctrl
name|audit_qctrl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|audit_fstat
name|audit_fstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|au_mask
name|audit_nae_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_panic_on_write_fail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_fail_stop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_arge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Success/failure conditions for the conversion of a kernel audit record to  * BSM format.  */
end_comment

begin_define
define|#
directive|define
name|BSM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|BSM_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|BSM_NOAUDIT
value|2
end_define

begin_comment
comment|/*  * Defines for the kernel audit record k_ar_commit field.  Flags are set to  * indicate what sort of record it is, and which preselection mechanism  * selected it.  */
end_comment

begin_define
define|#
directive|define
name|AR_COMMIT_KERNEL
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|AR_COMMIT_USER
value|0x00000010U
end_define

begin_define
define|#
directive|define
name|AR_PRESELECT_TRAIL
value|0x00001000U
end_define

begin_define
define|#
directive|define
name|AR_PRESELECT_PIPE
value|0x00002000U
end_define

begin_define
define|#
directive|define
name|AR_PRESELECT_USER_TRAIL
value|0x00004000U
end_define

begin_define
define|#
directive|define
name|AR_PRESELECT_USER_PIPE
value|0x00008000U
end_define

begin_define
define|#
directive|define
name|AR_PRESELECT_DTRACE
value|0x00010000U
end_define

begin_comment
comment|/*  * Audit data is generated as a stream of struct audit_record structures,  * linked by struct kaudit_record, and contain storage for possible audit so  * that it will not need to be allocated during the processing of a system  * call, both improving efficiency and avoiding sleeping at untimely moments.  * This structure is converted to BSM format before being written to disk.  */
end_comment

begin_struct
struct|struct
name|vnode_au_info
block|{
name|mode_t
name|vn_mode
decl_stmt|;
name|uid_t
name|vn_uid
decl_stmt|;
name|gid_t
name|vn_gid
decl_stmt|;
name|dev_t
name|vn_dev
decl_stmt|;
name|long
name|vn_fsid
decl_stmt|;
name|long
name|vn_fileid
decl_stmt|;
name|long
name|vn_gen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|groupset
block|{
name|gid_t
modifier|*
name|gidset
decl_stmt|;
name|u_int
name|gidset_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|socket_au_info
block|{
name|int
name|so_domain
decl_stmt|;
name|int
name|so_type
decl_stmt|;
name|int
name|so_protocol
decl_stmt|;
name|in_addr_t
name|so_raddr
decl_stmt|;
comment|/* Remote address if INET socket. */
name|in_addr_t
name|so_laddr
decl_stmt|;
comment|/* Local address if INET socket. */
name|u_short
name|so_rport
decl_stmt|;
comment|/* Remote port. */
name|u_short
name|so_lport
decl_stmt|;
comment|/* Local port. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following is used for A_OLDSETQCTRL and AU_OLDGETQCTRL and a 64-bit  * userland.  */
end_comment

begin_struct
struct|struct
name|au_qctrl64
block|{
name|u_int64_t
name|aq64_hiwater
decl_stmt|;
name|u_int64_t
name|aq64_lowater
decl_stmt|;
name|u_int64_t
name|aq64_bufsz
decl_stmt|;
name|u_int64_t
name|aq64_delay
decl_stmt|;
name|u_int64_t
name|aq64_minfree
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_qctrl64
name|au_qctrl64_t
typedef|;
end_typedef

begin_union
union|union
name|auditon_udata
block|{
name|char
modifier|*
name|au_path
decl_stmt|;
name|int
name|au_cond
decl_stmt|;
name|int
name|au_flags
decl_stmt|;
name|int
name|au_policy
decl_stmt|;
name|int
name|au_trigger
decl_stmt|;
name|int64_t
name|au_cond64
decl_stmt|;
name|int64_t
name|au_policy64
decl_stmt|;
name|au_evclass_map_t
name|au_evclass
decl_stmt|;
name|au_mask_t
name|au_mask
decl_stmt|;
name|auditinfo_t
name|au_auinfo
decl_stmt|;
name|auditpinfo_t
name|au_aupinfo
decl_stmt|;
name|auditpinfo_addr_t
name|au_aupinfo_addr
decl_stmt|;
name|au_qctrl_t
name|au_qctrl
decl_stmt|;
name|au_qctrl64_t
name|au_qctrl64
decl_stmt|;
name|au_stat_t
name|au_stat
decl_stmt|;
name|au_fstat_t
name|au_fstat
decl_stmt|;
name|auditinfo_addr_t
name|au_kau_info
decl_stmt|;
name|au_evname_map_t
name|au_evname
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|posix_ipc_perm
block|{
name|uid_t
name|pipc_uid
decl_stmt|;
name|gid_t
name|pipc_gid
decl_stmt|;
name|mode_t
name|pipc_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|audit_record
block|{
comment|/* Audit record header. */
name|u_int32_t
name|ar_magic
decl_stmt|;
name|int
name|ar_event
decl_stmt|;
name|int
name|ar_retval
decl_stmt|;
comment|/* value returned to the process */
name|int
name|ar_errno
decl_stmt|;
comment|/* return status of system call */
name|struct
name|timespec
name|ar_starttime
decl_stmt|;
name|struct
name|timespec
name|ar_endtime
decl_stmt|;
name|u_int64_t
name|ar_valid_arg
decl_stmt|;
comment|/* Bitmask of valid arguments */
comment|/* Audit subject information. */
name|struct
name|xucred
name|ar_subj_cred
decl_stmt|;
name|uid_t
name|ar_subj_ruid
decl_stmt|;
name|gid_t
name|ar_subj_rgid
decl_stmt|;
name|gid_t
name|ar_subj_egid
decl_stmt|;
name|uid_t
name|ar_subj_auid
decl_stmt|;
comment|/* Audit user ID */
name|pid_t
name|ar_subj_asid
decl_stmt|;
comment|/* Audit session ID */
name|pid_t
name|ar_subj_pid
decl_stmt|;
name|struct
name|au_tid
name|ar_subj_term
decl_stmt|;
name|struct
name|au_tid_addr
name|ar_subj_term_addr
decl_stmt|;
name|struct
name|au_mask
name|ar_subj_amask
decl_stmt|;
comment|/* Operation arguments. */
name|uid_t
name|ar_arg_euid
decl_stmt|;
name|uid_t
name|ar_arg_ruid
decl_stmt|;
name|uid_t
name|ar_arg_suid
decl_stmt|;
name|gid_t
name|ar_arg_egid
decl_stmt|;
name|gid_t
name|ar_arg_rgid
decl_stmt|;
name|gid_t
name|ar_arg_sgid
decl_stmt|;
name|pid_t
name|ar_arg_pid
decl_stmt|;
name|pid_t
name|ar_arg_asid
decl_stmt|;
name|struct
name|au_tid
name|ar_arg_termid
decl_stmt|;
name|struct
name|au_tid_addr
name|ar_arg_termid_addr
decl_stmt|;
name|uid_t
name|ar_arg_uid
decl_stmt|;
name|uid_t
name|ar_arg_auid
decl_stmt|;
name|gid_t
name|ar_arg_gid
decl_stmt|;
name|struct
name|groupset
name|ar_arg_groups
decl_stmt|;
name|int
name|ar_arg_fd
decl_stmt|;
name|int
name|ar_arg_atfd1
decl_stmt|;
name|int
name|ar_arg_atfd2
decl_stmt|;
name|int
name|ar_arg_fflags
decl_stmt|;
name|mode_t
name|ar_arg_mode
decl_stmt|;
name|int
name|ar_arg_dev
decl_stmt|;
name|long
name|ar_arg_value
decl_stmt|;
name|void
modifier|*
name|ar_arg_addr
decl_stmt|;
name|int
name|ar_arg_len
decl_stmt|;
name|int
name|ar_arg_mask
decl_stmt|;
name|u_int
name|ar_arg_signum
decl_stmt|;
name|char
name|ar_arg_login
index|[
name|MAXLOGNAME
index|]
decl_stmt|;
name|int
name|ar_arg_ctlname
index|[
name|CTL_MAXNAME
index|]
decl_stmt|;
name|struct
name|socket_au_info
name|ar_arg_sockinfo
decl_stmt|;
name|char
modifier|*
name|ar_arg_upath1
decl_stmt|;
name|char
modifier|*
name|ar_arg_upath2
decl_stmt|;
name|char
modifier|*
name|ar_arg_text
decl_stmt|;
name|struct
name|au_mask
name|ar_arg_amask
decl_stmt|;
name|struct
name|vnode_au_info
name|ar_arg_vnode1
decl_stmt|;
name|struct
name|vnode_au_info
name|ar_arg_vnode2
decl_stmt|;
name|int
name|ar_arg_cmd
decl_stmt|;
name|int
name|ar_arg_svipc_cmd
decl_stmt|;
name|struct
name|ipc_perm
name|ar_arg_svipc_perm
decl_stmt|;
name|int
name|ar_arg_svipc_id
decl_stmt|;
name|void
modifier|*
name|ar_arg_svipc_addr
decl_stmt|;
name|struct
name|posix_ipc_perm
name|ar_arg_pipc_perm
decl_stmt|;
name|union
name|auditon_udata
name|ar_arg_auditon
decl_stmt|;
name|char
modifier|*
name|ar_arg_argv
decl_stmt|;
name|int
name|ar_arg_argc
decl_stmt|;
name|char
modifier|*
name|ar_arg_envv
decl_stmt|;
name|int
name|ar_arg_envc
decl_stmt|;
name|int
name|ar_arg_exitstatus
decl_stmt|;
name|int
name|ar_arg_exitretval
decl_stmt|;
name|struct
name|sockaddr_storage
name|ar_arg_sockaddr
decl_stmt|;
name|cap_rights_t
name|ar_arg_rights
decl_stmt|;
name|uint32_t
name|ar_arg_fcntl_rights
decl_stmt|;
name|char
name|ar_jailname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arguments in the audit record are initially not defined; flags are set to  * indicate if they are present so they can be included in the audit log  * stream only if defined.  */
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
name|ARG_ATFD1
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_ATFD2
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_RIGHTS
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|ARG_FCNTL_RIGHTS
value|0x0020000000000000ULL
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

begin_define
define|#
directive|define
name|ARG_IS_VALID
parameter_list|(
name|kar
parameter_list|,
name|arg
parameter_list|)
value|((kar)->k_ar.ar_valid_arg& (arg))
end_define

begin_define
define|#
directive|define
name|ARG_SET_VALID
parameter_list|(
name|kar
parameter_list|,
name|arg
parameter_list|)
value|do {					\ 	(kar)->k_ar.ar_valid_arg |= (arg);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ARG_CLEAR_VALID
parameter_list|(
name|kar
parameter_list|,
name|arg
parameter_list|)
value|do {					\ 	(kar)->k_ar.ar_valid_arg&= ~(arg);				\ } while (0)
end_define

begin_comment
comment|/*  * In-kernel version of audit record; the basic record plus queue meta-data.  * This record can also have a pointer set to some opaque data that will be  * passed through to the audit writing mechanism.  */
end_comment

begin_struct
struct|struct
name|kaudit_record
block|{
name|struct
name|audit_record
name|k_ar
decl_stmt|;
name|u_int32_t
name|k_ar_commit
decl_stmt|;
name|void
modifier|*
name|k_udata
decl_stmt|;
comment|/* User data. */
name|u_int
name|k_ulen
decl_stmt|;
comment|/* User data length. */
name|struct
name|uthread
modifier|*
name|k_uthread
decl_stmt|;
comment|/* Audited thread. */
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
name|void
modifier|*
name|k_dtaudit_state
decl_stmt|;
endif|#
directive|endif
name|TAILQ_ENTRY
argument_list|(
argument|kaudit_record
argument_list|)
name|k_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|kaudit_queue
argument_list|,
name|kaudit_record
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Functions to manage the allocation, release, and commit of kernel audit  * records.  */
end_comment

begin_function_decl
name|void
name|audit_abort
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_commit
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|ar
parameter_list|,
name|int
name|error
parameter_list|,
name|int
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kaudit_record
modifier|*
name|audit_new
parameter_list|(
name|int
name|event
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to the conversion of internal kernel audit records to  * the BSM file format.  */
end_comment

begin_struct_decl
struct_decl|struct
name|au_record
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|kaudit_to_bsm
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|kar
parameter_list|,
name|struct
name|au_record
modifier|*
modifier|*
name|pau
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsm_rec_verify
parameter_list|(
name|void
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Kernel versions of the libbsm audit record functions.  */
end_comment

begin_function_decl
name|void
name|kau_free
parameter_list|(
name|struct
name|au_record
modifier|*
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kau_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return values for pre-selection and post-selection decisions.  */
end_comment

begin_define
define|#
directive|define
name|AU_PRS_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|AU_PRS_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|AU_PRS_BOTH
value|(AU_PRS_SUCCESS|AU_PRS_FAILURE)
end_define

begin_comment
comment|/*  * Data structures relating to the kernel audit queue.  Ideally, these might  * be abstracted so that only accessor methods are exposed.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|audit_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cv
name|audit_watermark_cv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cv
name|audit_worker_cv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kaudit_queue
name|audit_q
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_q_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_pre_q_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audit_in_failure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Flags to use on audit files when opening and closing.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_OPEN_FLAGS
value|(FWRITE | O_APPEND)
end_define

begin_define
define|#
directive|define
name|AUDIT_CLOSE_FLAGS
value|(FWRITE | O_APPEND)
end_define

begin_comment
comment|/*  * Audit event-to-name mapping structure, maintained in audit_bsm_klib.c.  It  * appears in this header so that the DTrace audit provider can dereference  * instances passed back in the au_evname_foreach() callbacks.  Safe access to  * its fields requires holding ene_lock (after it is visible in the global  * table).  *  * Locking:  * (c) - Constant after inserted in the global table  * (l) - Protected by ene_lock  * (m) - Protected by evnamemap_lock (audit_bsm_klib.c)  * (M) - Writes protected by evnamemap_lock; reads unprotected.  */
end_comment

begin_struct
struct|struct
name|evname_elem
block|{
name|au_event_t
name|ene_event
decl_stmt|;
comment|/* (c) */
name|char
name|ene_name
index|[
name|EVNAMEMAP_NAME_SIZE
index|]
decl_stmt|;
comment|/* (l) */
name|LIST_ENTRY
argument_list|(
argument|evname_elem
argument_list|)
name|ene_entry
expr_stmt|;
comment|/* (m) */
name|struct
name|mtx
name|ene_lock
decl_stmt|;
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
comment|/* DTrace probe IDs; 0 if not yet registered. */
name|uint32_t
name|ene_commit_probe_id
decl_stmt|;
comment|/* (M) */
name|uint32_t
name|ene_bsm_probe_id
decl_stmt|;
comment|/* (M) */
comment|/* Flags indicating if the probes enabled or not. */
name|int
name|ene_commit_probe_enabled
decl_stmt|;
comment|/* (M) */
name|int
name|ene_bsm_probe_enabled
decl_stmt|;
comment|/* (M) */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EVNAME_LOCK
parameter_list|(
name|ene
parameter_list|)
value|mtx_lock(&(ene)->ene_lock)
end_define

begin_define
define|#
directive|define
name|EVNAME_UNLOCK
parameter_list|(
name|ene
parameter_list|)
value|mtx_unlock(&(ene)->ene_lock)
end_define

begin_comment
comment|/*  * Callback function typedef for the same.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|au_evnamemap_callback_t
function_decl|)
parameter_list|(
name|struct
name|evname_elem
modifier|*
name|ene
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * DTrace audit provider (dtaudit) hooks -- to be set non-NULL when the audit  * provider is loaded and ready to be called into.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|dtaudit_hook_preselect
function_decl|)
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|dtaudit_hook_commit
function_decl|)
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|kar
parameter_list|,
name|au_id_t
name|auid
parameter_list|,
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|,
name|int
name|sorf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|dtaudit_hook_bsm
function_decl|)
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|kar
parameter_list|,
name|au_id_t
name|auid
parameter_list|,
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|,
name|int
name|sorf
parameter_list|,
name|void
modifier|*
name|bsm_data
parameter_list|,
name|size_t
name|bsm_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_comment
comment|/*  * Some of the BSM tokenizer functions take different parameters in the  * kernel implementations in order to save the copying of large kernel data  * structures.  The prototypes of these functions are declared here.  */
end_comment

begin_function_decl
name|token_t
modifier|*
name|kau_to_socket
parameter_list|(
name|struct
name|socket_au_info
modifier|*
name|soi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_klib prototypes  */
end_comment

begin_function_decl
name|int
name|au_preselect
parameter_list|(
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|,
name|au_mask_t
modifier|*
name|mask_p
parameter_list|,
name|int
name|sorf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_evclassmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_evclassmap_insert
parameter_list|(
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_class_t
name|au_event_class
parameter_list|(
name|au_event_t
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_evnamemap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_evnamemap_insert
parameter_list|(
name|au_event_t
name|event
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_evnamemap_foreach
parameter_list|(
name|au_evnamemap_callback_t
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_function_decl
name|struct
name|evname_elem
modifier|*
name|au_evnamemap_lookup
parameter_list|(
name|au_event_t
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|au_event_name
parameter_list|(
name|au_event_t
name|event
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|audit_ctlname_to_sysctlevent
parameter_list|(
name|int
name|name
index|[]
parameter_list|,
name|uint64_t
name|valid_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|audit_flags_and_error_to_openevent
parameter_list|(
name|int
name|oflags
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|audit_flags_and_error_to_openatevent
parameter_list|(
name|int
name|oflags
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|audit_msgctl_to_event
parameter_list|(
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|audit_semctl_to_event
parameter_list|(
name|int
name|cmr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_canon_path
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
name|path
parameter_list|,
name|char
modifier|*
name|cpath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
name|auditon_command_event
parameter_list|(
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Audit trigger events notify user space of kernel audit conditions  * asynchronously.  */
end_comment

begin_function_decl
name|void
name|audit_trigger_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_send_trigger
parameter_list|(
name|unsigned
name|int
name|trigger
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Accessor functions to manage global audit state.  */
end_comment

begin_function_decl
name|void
name|audit_set_kinfo
parameter_list|(
name|struct
name|auditinfo_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_get_kinfo
parameter_list|(
name|struct
name|auditinfo_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General audit related functions.  */
end_comment

begin_function_decl
name|struct
name|kaudit_record
modifier|*
name|currecord
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_free
parameter_list|(
name|struct
name|kaudit_record
modifier|*
name|ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_shutdown
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|howto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_rotate_vnode
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_worker_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Audit pipe functions.  */
end_comment

begin_function_decl
name|int
name|audit_pipe_preselect
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|,
name|int
name|sorf
parameter_list|,
name|int
name|trail_select
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_pipe_submit
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|au_event_t
name|event
parameter_list|,
name|au_class_t
name|class
parameter_list|,
name|int
name|sorf
parameter_list|,
name|int
name|trail_select
parameter_list|,
name|void
modifier|*
name|record
parameter_list|,
name|u_int
name|record_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_pipe_submit_user
parameter_list|(
name|void
modifier|*
name|record
parameter_list|,
name|u_int
name|record_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SECURITY_AUDIT_PRIVATE_H_ */
end_comment

end_unit

