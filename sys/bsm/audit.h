begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2009 Apple Inc.  * Copyright (c) 2016 Robert N. M. Watson  * All rights reserved.  *  * Portions of this software were developed by BAE Systems, the University of  * Cambridge Computer Laboratory, and Memorial University under DARPA/AFRL  * contract FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent  * Computing (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_H
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|AUDIT_RECORD_MAGIC
value|0x828a0f1b
end_define

begin_define
define|#
directive|define
name|MAX_AUDIT_RECORDS
value|20
end_define

begin_define
define|#
directive|define
name|MAXAUDITDATA
value|(0x8000 - 1)
end_define

begin_define
define|#
directive|define
name|MAX_AUDIT_RECORD_SIZE
value|MAXAUDITDATA
end_define

begin_define
define|#
directive|define
name|MIN_AUDIT_FILE_SIZE
value|(512 * 1024)
end_define

begin_comment
comment|/*  * Minimum noumber of free blocks on the filesystem containing the audit  * log necessary to avoid a hard log rotation. DO NOT SET THIS VALUE TO 0  * as the kernel does an unsigned compare, plus we want to leave a few blocks  * free so userspace can terminate the log, etc.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_HARD_LIMIT_FREE_BLOCKS
value|4
end_define

begin_comment
comment|/*  * Triggers for the audit daemon.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_MIN
value|1
end_define

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_LOW_SPACE
value|1
end_define

begin_comment
comment|/* Below low watermark. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_ROTATE_KERNEL
value|2
end_define

begin_comment
comment|/* Kernel requests rotate. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_READ_FILE
value|3
end_define

begin_comment
comment|/* Re-read config file. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_CLOSE_AND_DIE
value|4
end_define

begin_comment
comment|/* Terminate audit. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_NO_SPACE
value|5
end_define

begin_comment
comment|/* Below min free space. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_ROTATE_USER
value|6
end_define

begin_comment
comment|/* User requests rotate. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_INITIALIZE
value|7
end_define

begin_comment
comment|/* User initialize of auditd. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_EXPIRE_TRAILS
value|8
end_define

begin_comment
comment|/* User expiration of trails. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_MAX
value|8
end_define

begin_comment
comment|/*  * The special device filename (FreeBSD).  */
end_comment

begin_define
define|#
directive|define
name|AUDITDEV_FILENAME
value|"audit"
end_define

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_FILE
value|("/dev/" AUDITDEV_FILENAME)
end_define

begin_comment
comment|/*  * Pre-defined audit IDs  */
end_comment

begin_define
define|#
directive|define
name|AU_DEFAUDITID
value|(uid_t)(-1)
end_define

begin_define
define|#
directive|define
name|AU_DEFAUDITSID
value|0
end_define

begin_define
define|#
directive|define
name|AU_ASSIGN_ASID
value|-1
end_define

begin_comment
comment|/*  * IPC types.  */
end_comment

begin_define
define|#
directive|define
name|AT_IPC_MSG
value|((u_char)1)
end_define

begin_comment
comment|/* Message IPC id. */
end_comment

begin_define
define|#
directive|define
name|AT_IPC_SEM
value|((u_char)2)
end_define

begin_comment
comment|/* Semaphore IPC id. */
end_comment

begin_define
define|#
directive|define
name|AT_IPC_SHM
value|((u_char)3)
end_define

begin_comment
comment|/* Shared mem IPC id. */
end_comment

begin_comment
comment|/*  * Audit conditions.  */
end_comment

begin_define
define|#
directive|define
name|AUC_UNSET
value|0
end_define

begin_define
define|#
directive|define
name|AUC_AUDITING
value|1
end_define

begin_define
define|#
directive|define
name|AUC_NOAUDIT
value|2
end_define

begin_define
define|#
directive|define
name|AUC_DISABLED
value|-1
end_define

begin_comment
comment|/*  * auditon(2) commands.  */
end_comment

begin_define
define|#
directive|define
name|A_OLDGETPOLICY
value|2
end_define

begin_define
define|#
directive|define
name|A_OLDSETPOLICY
value|3
end_define

begin_define
define|#
directive|define
name|A_GETKMASK
value|4
end_define

begin_define
define|#
directive|define
name|A_SETKMASK
value|5
end_define

begin_define
define|#
directive|define
name|A_OLDGETQCTRL
value|6
end_define

begin_define
define|#
directive|define
name|A_OLDSETQCTRL
value|7
end_define

begin_define
define|#
directive|define
name|A_GETCWD
value|8
end_define

begin_define
define|#
directive|define
name|A_GETCAR
value|9
end_define

begin_define
define|#
directive|define
name|A_GETSTAT
value|12
end_define

begin_define
define|#
directive|define
name|A_SETSTAT
value|13
end_define

begin_define
define|#
directive|define
name|A_SETUMASK
value|14
end_define

begin_define
define|#
directive|define
name|A_SETSMASK
value|15
end_define

begin_define
define|#
directive|define
name|A_OLDGETCOND
value|20
end_define

begin_define
define|#
directive|define
name|A_OLDSETCOND
value|21
end_define

begin_define
define|#
directive|define
name|A_GETCLASS
value|22
end_define

begin_define
define|#
directive|define
name|A_SETCLASS
value|23
end_define

begin_define
define|#
directive|define
name|A_GETPINFO
value|24
end_define

begin_define
define|#
directive|define
name|A_SETPMASK
value|25
end_define

begin_define
define|#
directive|define
name|A_SETFSIZE
value|26
end_define

begin_define
define|#
directive|define
name|A_GETFSIZE
value|27
end_define

begin_define
define|#
directive|define
name|A_GETPINFO_ADDR
value|28
end_define

begin_define
define|#
directive|define
name|A_GETKAUDIT
value|29
end_define

begin_define
define|#
directive|define
name|A_SETKAUDIT
value|30
end_define

begin_define
define|#
directive|define
name|A_SENDTRIGGER
value|31
end_define

begin_define
define|#
directive|define
name|A_GETSINFO_ADDR
value|32
end_define

begin_define
define|#
directive|define
name|A_GETPOLICY
value|33
end_define

begin_define
define|#
directive|define
name|A_SETPOLICY
value|34
end_define

begin_define
define|#
directive|define
name|A_GETQCTRL
value|35
end_define

begin_define
define|#
directive|define
name|A_SETQCTRL
value|36
end_define

begin_define
define|#
directive|define
name|A_GETCOND
value|37
end_define

begin_define
define|#
directive|define
name|A_SETCOND
value|38
end_define

begin_define
define|#
directive|define
name|A_GETEVENT
value|39
end_define

begin_comment
comment|/* Get audit event-to-name mapping. */
end_comment

begin_define
define|#
directive|define
name|A_SETEVENT
value|40
end_define

begin_comment
comment|/* Set audit event-to-name mapping. */
end_comment

begin_comment
comment|/*  * Audit policy controls.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_CNT
value|0x0001
end_define

begin_define
define|#
directive|define
name|AUDIT_AHLT
value|0x0002
end_define

begin_define
define|#
directive|define
name|AUDIT_ARGV
value|0x0004
end_define

begin_define
define|#
directive|define
name|AUDIT_ARGE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AUDIT_SEQ
value|0x0010
end_define

begin_define
define|#
directive|define
name|AUDIT_WINDATA
value|0x0020
end_define

begin_define
define|#
directive|define
name|AUDIT_USER
value|0x0040
end_define

begin_define
define|#
directive|define
name|AUDIT_GROUP
value|0x0080
end_define

begin_define
define|#
directive|define
name|AUDIT_TRAIL
value|0x0100
end_define

begin_define
define|#
directive|define
name|AUDIT_PATH
value|0x0200
end_define

begin_define
define|#
directive|define
name|AUDIT_SCNT
value|0x0400
end_define

begin_define
define|#
directive|define
name|AUDIT_PUBLIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|AUDIT_ZONENAME
value|0x1000
end_define

begin_define
define|#
directive|define
name|AUDIT_PERZONE
value|0x2000
end_define

begin_comment
comment|/*  * Default audit queue control parameters.  */
end_comment

begin_define
define|#
directive|define
name|AQ_HIWATER
value|100
end_define

begin_define
define|#
directive|define
name|AQ_MAXHIGH
value|10000
end_define

begin_define
define|#
directive|define
name|AQ_LOWATER
value|10
end_define

begin_define
define|#
directive|define
name|AQ_BUFSZ
value|MAXAUDITDATA
end_define

begin_define
define|#
directive|define
name|AQ_MAXBUFSZ
value|1048576
end_define

begin_comment
comment|/*  * Default minimum percentage free space on file system.  */
end_comment

begin_define
define|#
directive|define
name|AU_FS_MINFREE
value|20
end_define

begin_comment
comment|/*  * Type definitions used indicating the length of variable length addresses  * in tokens containing addresses, such as header fields.  */
end_comment

begin_define
define|#
directive|define
name|AU_IPv4
value|4
end_define

begin_define
define|#
directive|define
name|AU_IPv6
value|16
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
name|uid_t
name|au_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pid_t
name|au_asid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|au_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|au_emod_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|au_class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|au_asflgs_t
name|__attribute__
typedef|((
name|aligned
typedef|(8)));
end_typedef

begin_struct
struct|struct
name|au_tid
block|{
name|u_int32_t
name|port
decl_stmt|;
comment|/* XXX dev_t compatibility */
name|u_int32_t
name|machine
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_tid
name|au_tid_t
typedef|;
end_typedef

begin_struct
struct|struct
name|au_tid_addr
block|{
name|u_int32_t
name|at_port
decl_stmt|;
comment|/* XXX dev_t compatibility */
name|u_int32_t
name|at_type
decl_stmt|;
name|u_int32_t
name|at_addr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_tid_addr
name|au_tid_addr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|au_mask
block|{
name|unsigned
name|int
name|am_success
decl_stmt|;
comment|/* Success bits. */
name|unsigned
name|int
name|am_failure
decl_stmt|;
comment|/* Failure bits. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_mask
name|au_mask_t
typedef|;
end_typedef

begin_struct
struct|struct
name|auditinfo
block|{
name|au_id_t
name|ai_auid
decl_stmt|;
comment|/* Audit user ID. */
name|au_mask_t
name|ai_mask
decl_stmt|;
comment|/* Audit masks. */
name|au_tid_t
name|ai_termid
decl_stmt|;
comment|/* Terminal ID. */
name|au_asid_t
name|ai_asid
decl_stmt|;
comment|/* Audit session ID. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|auditinfo
name|auditinfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|auditinfo_addr
block|{
name|au_id_t
name|ai_auid
decl_stmt|;
comment|/* Audit user ID. */
name|au_mask_t
name|ai_mask
decl_stmt|;
comment|/* Audit masks. */
name|au_tid_addr_t
name|ai_termid
decl_stmt|;
comment|/* Terminal ID. */
name|au_asid_t
name|ai_asid
decl_stmt|;
comment|/* Audit session ID. */
name|au_asflgs_t
name|ai_flags
decl_stmt|;
comment|/* Audit session flags. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|auditinfo_addr
name|auditinfo_addr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|auditpinfo
block|{
name|pid_t
name|ap_pid
decl_stmt|;
comment|/* ID of target process. */
name|au_id_t
name|ap_auid
decl_stmt|;
comment|/* Audit user ID. */
name|au_mask_t
name|ap_mask
decl_stmt|;
comment|/* Audit masks. */
name|au_tid_t
name|ap_termid
decl_stmt|;
comment|/* Terminal ID. */
name|au_asid_t
name|ap_asid
decl_stmt|;
comment|/* Audit session ID. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|auditpinfo
name|auditpinfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|auditpinfo_addr
block|{
name|pid_t
name|ap_pid
decl_stmt|;
comment|/* ID of target process. */
name|au_id_t
name|ap_auid
decl_stmt|;
comment|/* Audit user ID. */
name|au_mask_t
name|ap_mask
decl_stmt|;
comment|/* Audit masks. */
name|au_tid_addr_t
name|ap_termid
decl_stmt|;
comment|/* Terminal ID. */
name|au_asid_t
name|ap_asid
decl_stmt|;
comment|/* Audit session ID. */
name|au_asflgs_t
name|ap_flags
decl_stmt|;
comment|/* Audit session flags. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|auditpinfo_addr
name|auditpinfo_addr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|au_session
block|{
name|auditinfo_addr_t
modifier|*
name|as_aia_p
decl_stmt|;
comment|/* Ptr to full audit info. */
name|au_mask_t
name|as_mask
decl_stmt|;
comment|/* Process Audit Masks. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_session
name|au_session_t
typedef|;
end_typedef

begin_comment
comment|/*  * Contents of token_t are opaque outside of libbsm.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|au_token
name|token_t
typedef|;
end_typedef

begin_comment
comment|/*  * Kernel audit queue control parameters:  * 			Default:		Maximum:  * 	aq_hiwater:	AQ_HIWATER (100)	AQ_MAXHIGH (10000)   * 	aq_lowater:	AQ_LOWATER (10)<aq_hiwater  * 	aq_bufsz:	AQ_BUFSZ (32767)	AQ_MAXBUFSZ (1048576)  * 	aq_delay:	20			20000 (not used)   */
end_comment

begin_struct
struct|struct
name|au_qctrl
block|{
name|int
name|aq_hiwater
decl_stmt|;
comment|/* Max # of audit recs in queue when */
comment|/* threads with new ARs get blocked. */
name|int
name|aq_lowater
decl_stmt|;
comment|/* # of audit recs in queue when */
comment|/* blocked threads get unblocked. */
name|int
name|aq_bufsz
decl_stmt|;
comment|/* Max size of audit record for audit(2). */
name|int
name|aq_delay
decl_stmt|;
comment|/* Queue delay (not used). */
name|int
name|aq_minfree
decl_stmt|;
comment|/* Minimum filesystem percent free space. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_qctrl
name|au_qctrl_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for the audit statistics.  */
end_comment

begin_struct
struct|struct
name|audit_stat
block|{
name|unsigned
name|int
name|as_version
decl_stmt|;
name|unsigned
name|int
name|as_numevent
decl_stmt|;
name|int
name|as_generated
decl_stmt|;
name|int
name|as_nonattrib
decl_stmt|;
name|int
name|as_kernel
decl_stmt|;
name|int
name|as_audit
decl_stmt|;
name|int
name|as_auditctl
decl_stmt|;
name|int
name|as_enqueue
decl_stmt|;
name|int
name|as_written
decl_stmt|;
name|int
name|as_wblocked
decl_stmt|;
name|int
name|as_rblocked
decl_stmt|;
name|int
name|as_dropped
decl_stmt|;
name|int
name|as_totalsize
decl_stmt|;
name|unsigned
name|int
name|as_memused
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|audit_stat
name|au_stat_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for the audit file statistics.  */
end_comment

begin_struct
struct|struct
name|audit_fstat
block|{
name|u_int64_t
name|af_filesz
decl_stmt|;
name|u_int64_t
name|af_currsz
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|audit_fstat
name|au_fstat_t
typedef|;
end_typedef

begin_comment
comment|/*  * Audit to event class mapping.  */
end_comment

begin_struct
struct|struct
name|au_evclass_map
block|{
name|au_event_t
name|ec_number
decl_stmt|;
name|au_class_t
name|ec_class
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_evclass_map
name|au_evclass_map_t
typedef|;
end_typedef

begin_comment
comment|/*  * Event-to-name mapping.  */
end_comment

begin_define
define|#
directive|define
name|EVNAMEMAP_NAME_SIZE
value|64
end_define

begin_struct
struct|struct
name|au_evname_map
block|{
name|au_event_t
name|en_number
decl_stmt|;
name|char
name|en_name
index|[
name|EVNAMEMAP_NAME_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_evname_map
name|au_evname_map_t
typedef|;
end_typedef

begin_comment
comment|/*  * Audit system calls.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_function_decl
name|int
name|audit
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditon
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditctl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getauid
parameter_list|(
name|au_id_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setauid
parameter_list|(
specifier|const
name|au_id_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getaudit
parameter_list|(
name|struct
name|auditinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setaudit
parameter_list|(
specifier|const
name|struct
name|auditinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getaudit_addr
parameter_list|(
name|struct
name|auditinfo_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setaudit_addr
parameter_list|(
specifier|const
name|struct
name|auditinfo_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE_API_PRIVATE
end_ifdef

begin_include
include|#
directive|include
file|<mach/port.h>
end_include

begin_function_decl
name|mach_port_name_t
name|audit_session_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_asid_t
name|audit_session_join
parameter_list|(
name|mach_port_name_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __APPLE_API_PRIVATE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) || defined(KERNEL) */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_H */
end_comment

end_unit

