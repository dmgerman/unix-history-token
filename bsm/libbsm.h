begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Apple Computer, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bsm/libbsm.h#33 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBBSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBBSM_H_
end_define

begin_comment
comment|/*  * NB: definitions, etc., marked with "OpenSSH compatibility" were introduced  * solely to allow OpenSSH to compile; Darwin/Apple code should not use them.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* Required for audit.h. */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* Required for clock_t on Linux. */
end_comment

begin_include
include|#
directive|include
file|<bsm/audit.h>
end_include

begin_include
include|#
directive|include
file|<bsm/audit_record.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_comment
comment|/* audit_token_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Size parsed token vectors for execve(2) arguments and environmental  * variables.  Note: changing these sizes affects the ABI of the token  * structure, and as the token structure is often placed in the caller stack,  * this is undesirable.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_MAX_ARGS
value|128
end_define

begin_define
define|#
directive|define
name|AUDIT_MAX_ENV
value|128
end_define

begin_comment
comment|/*  * Arguments to au_preselect(3).  */
end_comment

begin_define
define|#
directive|define
name|AU_PRS_USECACHE
value|0
end_define

begin_define
define|#
directive|define
name|AU_PRS_REREAD
value|1
end_define

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

begin_define
define|#
directive|define
name|AUDIT_EVENT_FILE
value|"/etc/security/audit_event"
end_define

begin_define
define|#
directive|define
name|AUDIT_CLASS_FILE
value|"/etc/security/audit_class"
end_define

begin_define
define|#
directive|define
name|AUDIT_CONTROL_FILE
value|"/etc/security/audit_control"
end_define

begin_define
define|#
directive|define
name|AUDIT_USER_FILE
value|"/etc/security/audit_user"
end_define

begin_define
define|#
directive|define
name|DIR_CONTROL_ENTRY
value|"dir"
end_define

begin_define
define|#
directive|define
name|MINFREE_CONTROL_ENTRY
value|"minfree"
end_define

begin_define
define|#
directive|define
name|FILESZ_CONTROL_ENTRY
value|"filesz"
end_define

begin_define
define|#
directive|define
name|FLAGS_CONTROL_ENTRY
value|"flags"
end_define

begin_define
define|#
directive|define
name|NA_CONTROL_ENTRY
value|"naflags"
end_define

begin_define
define|#
directive|define
name|POLICY_CONTROL_ENTRY
value|"policy"
end_define

begin_define
define|#
directive|define
name|AU_CLASS_NAME_MAX
value|8
end_define

begin_define
define|#
directive|define
name|AU_CLASS_DESC_MAX
value|72
end_define

begin_define
define|#
directive|define
name|AU_EVENT_NAME_MAX
value|30
end_define

begin_define
define|#
directive|define
name|AU_EVENT_DESC_MAX
value|50
end_define

begin_define
define|#
directive|define
name|AU_USER_NAME_MAX
value|50
end_define

begin_define
define|#
directive|define
name|AU_LINE_MAX
value|256
end_define

begin_define
define|#
directive|define
name|MAX_AUDITSTRING_LEN
value|256
end_define

begin_define
define|#
directive|define
name|BSM_TEXTBUFSZ
value|MAX_AUDITSTRING_LEN
end_define

begin_comment
comment|/* OpenSSH compatibility */
end_comment

begin_comment
comment|/*  * Arguments to au_close(3).  */
end_comment

begin_define
define|#
directive|define
name|AU_TO_NO_WRITE
value|0
end_define

begin_comment
comment|/* Abandon audit record. */
end_comment

begin_define
define|#
directive|define
name|AU_TO_WRITE
value|1
end_define

begin_comment
comment|/* Commit audit record. */
end_comment

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct
struct|struct
name|au_event_ent
block|{
name|au_event_t
name|ae_number
decl_stmt|;
name|char
modifier|*
name|ae_name
decl_stmt|;
name|char
modifier|*
name|ae_desc
decl_stmt|;
name|au_class_t
name|ae_class
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_event_ent
name|au_event_ent_t
typedef|;
end_typedef

begin_struct
struct|struct
name|au_class_ent
block|{
name|char
modifier|*
name|ac_name
decl_stmt|;
name|au_class_t
name|ac_class
decl_stmt|;
name|char
modifier|*
name|ac_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_class_ent
name|au_class_ent_t
typedef|;
end_typedef

begin_struct
struct|struct
name|au_user_ent
block|{
name|char
modifier|*
name|au_name
decl_stmt|;
name|au_mask_t
name|au_always
decl_stmt|;
name|au_mask_t
name|au_never
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_user_ent
name|au_user_ent_t
typedef|;
end_typedef

begin_expr_stmt
name|__END_DECLS
define|#
directive|define
name|ADD_TO_MASK
parameter_list|(
name|m
parameter_list|,
name|c
parameter_list|,
name|sel
parameter_list|)
value|do {					\ 	if (sel& AU_PRS_SUCCESS)					\ 		(m)->am_success |= c;					\ 	if (sel& AU_PRS_FAILURE)					\ 		(m)->am_failure |= c;					\ } while (0)
define|#
directive|define
name|SUB_FROM_MASK
parameter_list|(
name|m
parameter_list|,
name|c
parameter_list|,
name|sel
parameter_list|)
value|do {					\ 	if (sel& AU_PRS_SUCCESS)					\ 		(m)->am_success&= ((m)->am_success ^ c);		\ 	if (sel& AU_PRS_FAILURE)					\ 		(m)->am_failure&= ((m)->am_failure ^ c);		\ } while (0)
define|#
directive|define
name|ADDMASK
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|do {						\ 	(m)->am_success |= (v)->am_success;				\ 	(m)->am_failure |= (v)->am_failure;				\ } while(0)
define|#
directive|define
name|SUBMASK
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|)
value|do {						\ 	(m)->am_success&= ((m)->am_success ^ (v)->am_success);		\ 	(m)->am_failure&= ((m)->am_failure ^ (v)->am_failure);		\ } while(0)
name|__BEGIN_DECLS
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|au_tid32
block|{
name|u_int32_t
name|port
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
name|au_tid32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|au_tid64
block|{
name|u_int64_t
name|port
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
name|au_tid64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|au_tidaddr32
block|{
name|u_int32_t
name|port
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|au_tidaddr32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|au_tidaddr64
block|{
name|u_int64_t
name|port
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|au_tidaddr64_t
typedef|;
end_typedef

begin_comment
comment|/*  * argument #              1 byte  * argument value          4 bytes/8 bytes (32-bit/64-bit value)  * text length             2 bytes  * text                    N bytes + 1 terminating NULL byte  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|no
decl_stmt|;
name|u_int32_t
name|val
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
name|au_arg32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|no
decl_stmt|;
name|u_int64_t
name|val
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
name|au_arg64_t
typedef|;
end_typedef

begin_comment
comment|/*  * how to print            1 byte  * basic unit              1 byte  * unit count              1 byte  * data items              (depends on basic unit)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|howtopr
decl_stmt|;
name|u_char
name|bu
decl_stmt|;
name|u_char
name|uc
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
block|}
name|au_arb_t
typedef|;
end_typedef

begin_comment
comment|/*  * file access mode        4 bytes  * owner user ID           4 bytes  * owner group ID          4 bytes  * file system ID          4 bytes  * node ID                 8 bytes  * device                  4 bytes/8 bytes (32-bit/64-bit)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|mode
decl_stmt|;
name|u_int32_t
name|uid
decl_stmt|;
name|u_int32_t
name|gid
decl_stmt|;
name|u_int32_t
name|fsid
decl_stmt|;
name|u_int64_t
name|nid
decl_stmt|;
name|u_int32_t
name|dev
decl_stmt|;
block|}
name|au_attr32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|mode
decl_stmt|;
name|u_int32_t
name|uid
decl_stmt|;
name|u_int32_t
name|gid
decl_stmt|;
name|u_int32_t
name|fsid
decl_stmt|;
name|u_int64_t
name|nid
decl_stmt|;
name|u_int64_t
name|dev
decl_stmt|;
block|}
name|au_attr64_t
typedef|;
end_typedef

begin_comment
comment|/*  * count                   4 bytes  * text                    count null-terminated string(s)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|count
decl_stmt|;
name|char
modifier|*
name|text
index|[
name|AUDIT_MAX_ARGS
index|]
decl_stmt|;
block|}
name|au_execarg_t
typedef|;
end_typedef

begin_comment
comment|/*  * count                   4 bytes  * text                    count null-terminated string(s)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|count
decl_stmt|;
name|char
modifier|*
name|text
index|[
name|AUDIT_MAX_ENV
index|]
decl_stmt|;
block|}
name|au_execenv_t
typedef|;
end_typedef

begin_comment
comment|/*  * status                  4 bytes  * return value            4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|status
decl_stmt|;
name|u_int32_t
name|ret
decl_stmt|;
block|}
name|au_exit_t
typedef|;
end_typedef

begin_comment
comment|/*  * seconds of time         4 bytes  * milliseconds of time    4 bytes  * file name length        2 bytes  * file pathname           N bytes + 1 terminating NULL byte  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|s
decl_stmt|;
name|u_int32_t
name|ms
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|au_file_t
typedef|;
end_typedef

begin_comment
comment|/*  * number groups           2 bytes  * group list              N * 4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|no
decl_stmt|;
name|u_int32_t
name|list
index|[
name|AUDIT_MAX_GROUPS
index|]
decl_stmt|;
block|}
name|au_groups_t
typedef|;
end_typedef

begin_comment
comment|/*  * record byte count       4 bytes  * version #               1 byte    [2]  * event type              2 bytes  * event modifier          2 bytes  * seconds of time         4 bytes/8 bytes (32-bit/64-bit value)  * milliseconds of time    4 bytes/8 bytes (32-bit/64-bit value)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_int16_t
name|e_type
decl_stmt|;
name|u_int16_t
name|e_mod
decl_stmt|;
name|u_int32_t
name|s
decl_stmt|;
name|u_int32_t
name|ms
decl_stmt|;
block|}
name|au_header32_t
typedef|;
end_typedef

begin_comment
comment|/*  * record byte count       4 bytes  * version #               1 byte     [2]  * event type              2 bytes  * event modifier          2 bytes  * address type/length     1 byte (XXX: actually, 4 bytes)  * machine address         4 bytes/16 bytes (IPv4/IPv6 address)  * seconds of time         4 bytes/8 bytes  (32/64-bits)  * nanoseconds of time     4 bytes/8 bytes  (32/64-bits)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_int16_t
name|e_type
decl_stmt|;
name|u_int16_t
name|e_mod
decl_stmt|;
name|u_int32_t
name|ad_type
decl_stmt|;
name|u_int32_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|s
decl_stmt|;
name|u_int32_t
name|ms
decl_stmt|;
block|}
name|au_header32_ex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_int16_t
name|e_type
decl_stmt|;
name|u_int16_t
name|e_mod
decl_stmt|;
name|u_int64_t
name|s
decl_stmt|;
name|u_int64_t
name|ms
decl_stmt|;
block|}
name|au_header64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_char
name|version
decl_stmt|;
name|u_int16_t
name|e_type
decl_stmt|;
name|u_int16_t
name|e_mod
decl_stmt|;
name|u_int32_t
name|ad_type
decl_stmt|;
name|u_int32_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
name|u_int64_t
name|s
decl_stmt|;
name|u_int64_t
name|ms
decl_stmt|;
block|}
name|au_header64_ex_t
typedef|;
end_typedef

begin_comment
comment|/*  * internet address        4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|addr
decl_stmt|;
block|}
name|au_inaddr_t
typedef|;
end_typedef

begin_comment
comment|/*  * type                 4 bytes  * internet address     16 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|au_inaddr_ex_t
typedef|;
end_typedef

begin_comment
comment|/*  * version and ihl         1 byte  * type of service         1 byte  * length                  2 bytes  * id                      2 bytes  * offset                  2 bytes  * ttl                     1 byte  * protocol                1 byte  * checksum                2 bytes  * source address          4 bytes  * destination address     4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|version
decl_stmt|;
name|u_char
name|tos
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|u_int16_t
name|id
decl_stmt|;
name|u_int16_t
name|offset
decl_stmt|;
name|u_char
name|ttl
decl_stmt|;
name|u_char
name|prot
decl_stmt|;
name|u_int16_t
name|chksm
decl_stmt|;
name|u_int32_t
name|src
decl_stmt|;
name|u_int32_t
name|dest
decl_stmt|;
block|}
name|au_ip_t
typedef|;
end_typedef

begin_comment
comment|/*  * object ID type          1 byte  * object ID               4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|type
decl_stmt|;
name|u_int32_t
name|id
decl_stmt|;
block|}
name|au_ipc_t
typedef|;
end_typedef

begin_comment
comment|/*  * owner user ID           4 bytes  * owner group ID          4 bytes  * creator user ID         4 bytes  * creator group ID        4 bytes  * access mode             4 bytes  * slot sequence #         4 bytes  * key                     4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|uid
decl_stmt|;
name|u_int32_t
name|gid
decl_stmt|;
name|u_int32_t
name|puid
decl_stmt|;
name|u_int32_t
name|pgid
decl_stmt|;
name|u_int32_t
name|mode
decl_stmt|;
name|u_int32_t
name|seq
decl_stmt|;
name|u_int32_t
name|key
decl_stmt|;
block|}
name|au_ipcperm_t
typedef|;
end_typedef

begin_comment
comment|/*  * port IP address         2 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|port
decl_stmt|;
block|}
name|au_iport_t
typedef|;
end_typedef

begin_comment
comment|/*  * length		2 bytes  * data			length bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|size
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|au_opaque_t
typedef|;
end_typedef

begin_comment
comment|/*  * path length             2 bytes  * path                    N bytes + 1 terminating NULL byte  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
block|}
name|au_path_t
typedef|;
end_typedef

begin_comment
comment|/*  * audit ID                4 bytes  * effective user ID       4 bytes  * effective group ID      4 bytes  * real user ID            4 bytes  * real group ID           4 bytes  * process ID              4 bytes  * session ID              4 bytes  * terminal ID  * port ID               4 bytes/8 bytes (32-bit/64-bit value)  * machine address       4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tid32_t
name|tid
decl_stmt|;
block|}
name|au_proc32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tid64_t
name|tid
decl_stmt|;
block|}
name|au_proc64_t
typedef|;
end_typedef

begin_comment
comment|/*  * audit ID                4 bytes  * effective user ID       4 bytes  * effective group ID      4 bytes  * real user ID            4 bytes  * real group ID           4 bytes  * process ID              4 bytes  * session ID              4 bytes  * terminal ID  * port ID               4 bytes/8 bytes (32-bit/64-bit value)  * type                  4 bytes  * machine address       16 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tidaddr32_t
name|tid
decl_stmt|;
block|}
name|au_proc32ex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tidaddr64_t
name|tid
decl_stmt|;
block|}
name|au_proc64ex_t
typedef|;
end_typedef

begin_comment
comment|/*  * error status            1 byte  * return value            4 bytes/8 bytes (32-bit/64-bit value)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|status
decl_stmt|;
name|u_int32_t
name|ret
decl_stmt|;
block|}
name|au_ret32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|err
decl_stmt|;
name|u_int64_t
name|val
decl_stmt|;
block|}
name|au_ret64_t
typedef|;
end_typedef

begin_comment
comment|/*  * sequence number         4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|seqno
decl_stmt|;
block|}
name|au_seq_t
typedef|;
end_typedef

begin_comment
comment|/*  * socket type             2 bytes  * local port              2 bytes  * local Internet address  4 bytes  * remote port             2 bytes  * remote Internet address 4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|l_port
decl_stmt|;
name|u_int32_t
name|l_addr
decl_stmt|;
name|u_int16_t
name|r_port
decl_stmt|;
name|u_int32_t
name|r_addr
decl_stmt|;
block|}
name|au_socket_t
typedef|;
end_typedef

begin_comment
comment|/*  * socket type             2 bytes  * local port              2 bytes  * address type/length     4 bytes  * local Internet address  4 bytes/16 bytes (IPv4/IPv6 address)  * remote port             4 bytes  * address type/length     4 bytes  * remote Internet address 4 bytes/16 bytes (IPv4/IPv6 address)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|l_port
decl_stmt|;
name|u_int32_t
name|l_ad_type
decl_stmt|;
name|u_int32_t
name|l_addr
decl_stmt|;
name|u_int32_t
name|r_port
decl_stmt|;
name|u_int32_t
name|r_ad_type
decl_stmt|;
name|u_int32_t
name|r_addr
decl_stmt|;
block|}
name|au_socket_ex32_t
typedef|;
end_typedef

begin_comment
comment|/*  * socket family           2 bytes  * local port              2 bytes  * socket address          4 bytes/16 bytes (IPv4/IPv6 address)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|family
decl_stmt|;
name|u_int16_t
name|port
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
name|au_socketinet32_t
typedef|;
end_typedef

begin_comment
comment|/*  * socket family           2 bytes  * path                    104 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|family
decl_stmt|;
name|char
name|path
index|[
literal|104
index|]
decl_stmt|;
block|}
name|au_socketunix_t
typedef|;
end_typedef

begin_comment
comment|/*  * audit ID                4 bytes  * effective user ID       4 bytes  * effective group ID      4 bytes  * real user ID            4 bytes  * real group ID           4 bytes  * process ID              4 bytes  * session ID              4 bytes  * terminal ID  * 	port ID               4 bytes/8 bytes (32-bit/64-bit value)  * 	machine address       4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tid32_t
name|tid
decl_stmt|;
block|}
name|au_subject32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tid64_t
name|tid
decl_stmt|;
block|}
name|au_subject64_t
typedef|;
end_typedef

begin_comment
comment|/*  * audit ID                4 bytes  * effective user ID       4 bytes  * effective group ID      4 bytes  * real user ID            4 bytes  * real group ID           4 bytes  * process ID              4 bytes  * session ID              4 bytes  * terminal ID  * port ID               4 bytes/8 bytes (32-bit/64-bit value)  * type                  4 bytes  * machine address       16 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tidaddr32_t
name|tid
decl_stmt|;
block|}
name|au_subject32ex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|auid
decl_stmt|;
name|u_int32_t
name|euid
decl_stmt|;
name|u_int32_t
name|egid
decl_stmt|;
name|u_int32_t
name|ruid
decl_stmt|;
name|u_int32_t
name|rgid
decl_stmt|;
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|sid
decl_stmt|;
name|au_tidaddr64_t
name|tid
decl_stmt|;
block|}
name|au_subject64ex_t
typedef|;
end_typedef

begin_comment
comment|/*  * text length             2 bytes  * text                    N bytes + 1 terminating NULL byte  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
name|au_text_t
typedef|;
end_typedef

begin_comment
comment|/*  * zonename length	2 bytes  * zonename text	N bytes + 1 NULL terminator  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|len
decl_stmt|;
name|char
modifier|*
name|zonename
decl_stmt|;
block|}
name|au_zonename_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|ident
decl_stmt|;
name|u_int16_t
name|filter
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
name|u_int32_t
name|fflags
decl_stmt|;
name|u_int32_t
name|data
decl_stmt|;
block|}
name|au_kevent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|au_invalid_t
typedef|;
end_typedef

begin_comment
comment|/*  * trailer magic number    2 bytes  * record byte count       4 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|magic
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
block|}
name|au_trailer_t
typedef|;
end_typedef

begin_struct
struct|struct
name|tokenstr
block|{
name|u_char
name|id
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
name|size_t
name|len
decl_stmt|;
union|union
block|{
name|au_arg32_t
name|arg32
decl_stmt|;
name|au_arg64_t
name|arg64
decl_stmt|;
name|au_arb_t
name|arb
decl_stmt|;
name|au_attr32_t
name|attr32
decl_stmt|;
name|au_attr64_t
name|attr64
decl_stmt|;
name|au_execarg_t
name|execarg
decl_stmt|;
name|au_execenv_t
name|execenv
decl_stmt|;
name|au_exit_t
name|exit
decl_stmt|;
name|au_file_t
name|file
decl_stmt|;
name|au_groups_t
name|grps
decl_stmt|;
name|au_header32_t
name|hdr32
decl_stmt|;
name|au_header32_ex_t
name|hdr32_ex
decl_stmt|;
name|au_header64_t
name|hdr64
decl_stmt|;
name|au_header64_ex_t
name|hdr64_ex
decl_stmt|;
name|au_inaddr_t
name|inaddr
decl_stmt|;
name|au_inaddr_ex_t
name|inaddr_ex
decl_stmt|;
name|au_ip_t
name|ip
decl_stmt|;
name|au_ipc_t
name|ipc
decl_stmt|;
name|au_ipcperm_t
name|ipcperm
decl_stmt|;
name|au_iport_t
name|iport
decl_stmt|;
name|au_opaque_t
name|opaque
decl_stmt|;
name|au_path_t
name|path
decl_stmt|;
name|au_proc32_t
name|proc32
decl_stmt|;
name|au_proc32ex_t
name|proc32_ex
decl_stmt|;
name|au_proc64_t
name|proc64
decl_stmt|;
name|au_proc64ex_t
name|proc64_ex
decl_stmt|;
name|au_ret32_t
name|ret32
decl_stmt|;
name|au_ret64_t
name|ret64
decl_stmt|;
name|au_seq_t
name|seq
decl_stmt|;
name|au_socket_t
name|socket
decl_stmt|;
name|au_socket_ex32_t
name|socket_ex32
decl_stmt|;
name|au_socketinet32_t
name|sockinet32
decl_stmt|;
name|au_socketunix_t
name|sockunix
decl_stmt|;
name|au_subject32_t
name|subj32
decl_stmt|;
name|au_subject32ex_t
name|subj32_ex
decl_stmt|;
name|au_subject64_t
name|subj64
decl_stmt|;
name|au_subject64ex_t
name|subj64_ex
decl_stmt|;
name|au_text_t
name|text
decl_stmt|;
name|au_kevent_t
name|kevent
decl_stmt|;
name|au_invalid_t
name|invalid
decl_stmt|;
name|au_trailer_t
name|trail
decl_stmt|;
name|au_zonename_t
name|zonename
decl_stmt|;
block|}
name|tt
union|;
comment|/* The token is one of the above types */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tokenstr
name|tokenstr_t
typedef|;
end_typedef

begin_function_decl
name|int
name|audit_submit
parameter_list|(
name|short
name|au_event
parameter_list|,
name|au_id_t
name|auid
parameter_list|,
name|char
name|status
parameter_list|,
name|int
name|reterr
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to querying audit class information.  */
end_comment

begin_function_decl
name|void
name|setauclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endauclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassent_r
parameter_list|(
name|au_class_ent_t
modifier|*
name|class_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassnam
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassnam_r
parameter_list|(
name|au_class_ent_t
modifier|*
name|class_int
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassnum
parameter_list|(
name|au_class_t
name|class_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_class_ent
modifier|*
name|getauclassnum_r
parameter_list|(
name|au_class_ent_t
modifier|*
name|class_int
parameter_list|,
name|au_class_t
name|class_number
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to querying audit control information.  */
end_comment

begin_function_decl
name|void
name|setac
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endac
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacdir
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacmin
parameter_list|(
name|int
modifier|*
name|min_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacfilesz
parameter_list|(
name|size_t
modifier|*
name|size_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacflg
parameter_list|(
name|char
modifier|*
name|auditstr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacna
parameter_list|(
name|char
modifier|*
name|auditstr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getacpol
parameter_list|(
name|char
modifier|*
name|auditstr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getauditflagsbin
parameter_list|(
name|char
modifier|*
name|auditstr
parameter_list|,
name|au_mask_t
modifier|*
name|masks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getauditflagschar
parameter_list|(
name|char
modifier|*
name|auditstr
parameter_list|,
name|au_mask_t
modifier|*
name|masks
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_preselect
parameter_list|(
name|au_event_t
name|event
parameter_list|,
name|au_mask_t
modifier|*
name|mask_p
parameter_list|,
name|int
name|sorf
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|au_poltostr
parameter_list|(
name|long
name|policy
parameter_list|,
name|size_t
name|maxsize
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_strtopol
parameter_list|(
specifier|const
name|char
modifier|*
name|polstr
parameter_list|,
name|long
modifier|*
name|policy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to querying audit event information.  */
end_comment

begin_function_decl
name|void
name|setauevent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endauevent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevent_r
parameter_list|(
name|struct
name|au_event_ent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevnam
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevnam_r
parameter_list|(
name|struct
name|au_event_ent
modifier|*
name|e
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevnum
parameter_list|(
name|au_event_t
name|event_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_event_ent
modifier|*
name|getauevnum_r
parameter_list|(
name|struct
name|au_event_ent
modifier|*
name|e
parameter_list|,
name|au_event_t
name|event_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
modifier|*
name|getauevnonam
parameter_list|(
specifier|const
name|char
modifier|*
name|event_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|au_event_t
modifier|*
name|getauevnonam_r
parameter_list|(
name|au_event_t
modifier|*
name|ev
parameter_list|,
specifier|const
name|char
modifier|*
name|event_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions relating to querying audit user information.  */
end_comment

begin_function_decl
name|void
name|setauuser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endauuser
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_user_ent
modifier|*
name|getauuserent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_user_ent
modifier|*
name|getauuserent_r
parameter_list|(
name|struct
name|au_user_ent
modifier|*
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_user_ent
modifier|*
name|getauusernam
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|au_user_ent
modifier|*
name|getauusernam_r
parameter_list|(
name|struct
name|au_user_ent
modifier|*
name|u
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_user_mask
parameter_list|(
name|char
modifier|*
name|username
parameter_list|,
name|au_mask_t
modifier|*
name|mask_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getfauditflags
parameter_list|(
name|au_mask_t
modifier|*
name|usremask
parameter_list|,
name|au_mask_t
modifier|*
name|usrdmask
parameter_list|,
name|au_mask_t
modifier|*
name|lastmask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions for reading and printing records and tokens from audit trails.  */
end_comment

begin_function_decl
name|int
name|au_read_rec
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|u_char
modifier|*
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_fetch_tok
parameter_list|(
name|tokenstr_t
modifier|*
name|tok
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//XXX The following interface has different prototype from BSM
end_comment

begin_function_decl
name|void
name|au_print_tok
parameter_list|(
name|FILE
modifier|*
name|outfp
parameter_list|,
name|tokenstr_t
modifier|*
name|tok
parameter_list|,
name|char
modifier|*
name|del
parameter_list|,
name|char
name|raw
parameter_list|,
name|char
name|sfrm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_print_tok_xml
parameter_list|(
name|FILE
modifier|*
name|outfp
parameter_list|,
name|tokenstr_t
modifier|*
name|tok
parameter_list|,
name|char
modifier|*
name|del
parameter_list|,
name|char
name|raw
parameter_list|,
name|char
name|sfrm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * Functions relating to XML output.  */
end_comment

begin_function_decl
name|void
name|au_print_xml_header
parameter_list|(
name|FILE
modifier|*
name|outfp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|au_print_xml_footer
parameter_list|(
name|FILE
modifier|*
name|outfp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__END_DECLS
comment|/*  * The remaining APIs are associated with Apple's BSM implementation, in  * particular as relates to Mach IPC auditing and triggers passed via Mach  * IPC.  */
ifdef|#
directive|ifdef
name|__APPLE__
include|#
directive|include
file|<sys/appleapiopts.h>
comment|/**************************************************************************  **************************************************************************  ** The following definitions, functions, etc., are NOT officially  ** supported: they may be changed or removed in the future.  Do not use  ** them unless you are prepared to cope with that eventuality.  **************************************************************************  **************************************************************************/
ifdef|#
directive|ifdef
name|__APPLE_API_PRIVATE
define|#
directive|define
name|__BSM_INTERNAL_NOTIFY_KEY
value|"com.apple.audit.change"
endif|#
directive|endif
comment|/* __APPLE_API_PRIVATE */
comment|/*  * au_get_state() return values  * XXX  use AUC_* values directly instead (<bsm/audit.h>); AUDIT_OFF and  * AUDIT_ON are deprecated and WILL be removed.  */
ifdef|#
directive|ifdef
name|__APPLE_API_PRIVATE
define|#
directive|define
name|AUDIT_OFF
value|AUC_NOAUDIT
define|#
directive|define
name|AUDIT_ON
value|AUC_AUDITING
endif|#
directive|endif
comment|/* __APPLE_API_PRIVATE */
endif|#
directive|endif
comment|/* !__APPLE__ */
comment|/*  * Error return codes for audit_set_terminal_id(), audit_write() and its  * brethren.  We have 255 (not including kAUNoErr) to play with.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
name|enum
type|{
name|kAUNoErr
init|=
literal|0
decl_stmt|,
name|kAUBadParamErr
init|=
operator|-
literal|66049
decl_stmt|,
name|kAUStatErr
decl_stmt|,
name|kAUSysctlErr
decl_stmt|,
name|kAUOpenErr
decl_stmt|,
name|kAUMakeSubjectTokErr
decl_stmt|,
name|kAUWriteSubjectTokErr
decl_stmt|,
name|kAUWriteCallerTokErr
decl_stmt|,
name|kAUMakeReturnTokErr
decl_stmt|,
name|kAUWriteReturnTokErr
decl_stmt|,
name|kAUCloseErr
decl_stmt|,
name|kAUMakeTextTokErr
decl_stmt|,
name|kAULastErr
end_decl_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_comment
comment|/*  * Error return codes for au_get_state() and/or its private support  * functions.  These codes are designed to be compatible with the  * NOTIFY_STATUS_* codes defined in<notify.h> but non-overlapping.  * Any changes to notify(3) may cause these values to change in future.  *  * AU_UNIMPL should never happen unless you've changed your system software  * without rebooting.  Shame on you.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE_API_PRIVATE
end_ifdef

begin_define
define|#
directive|define
name|AU_UNIMPL
value|NOTIFY_STATUS_FAILED + 1
end_define

begin_comment
comment|/* audit unimplemented */
end_comment

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
comment|/* !__APPLE__ */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * XXX  This prototype should be in audit_record.h  *  * au_free_token()  *  * @summary - au_free_token() deallocates a token_t created by any of  * the au_to_*() BSM API functions.  *  * The BSM API generally manages deallocation of token_t objects.  However,  * if au_write() is passed a bad audit descriptor, the token_t * parameter  * will be left untouched.  In that case, the caller can deallocate the  * token_t using au_free_token() if desired.  This is, in fact, what  * audit_write() does, in keeping with the existing memory management model  * of the BSM API.  *  * @param tok - A token_t * generated by one of the au_to_*() BSM API  * calls.  For convenience, tok may be NULL, in which case  * au_free_token() returns immediately.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
name|void
name|au_free_token
parameter_list|(
name|token_t
modifier|*
name|tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lightweight check to determine if auditing is enabled.  If a client  * wants to use this to govern whether an entire series of audit calls  * should be made--as in the common case of a caller building a set of  * tokens, then writing them--it should cache the audit status in a local  * variable.  This call always returns the current state of auditing.  *  * @return - AUC_AUDITING or AUC_NOAUDIT if no error occurred.  * Otherwise the function can return any of the errno values defined for  * setaudit(2), or AU_UNIMPL if audit does not appear to be supported by  * the system.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|au_get_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/* OpenSSH compatibility */
name|int
name|cannot_audit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * audit_set_terminal_id()  *  * @summary - audit_set_terminal_id() fills in an au_tid_t struct, which is  * used in audit session initialization by processes like /usr/bin/login.  *  * @param tid - A pointer to an au_tid_t struct.  *  * @return - kAUNoErr on success; kAUBadParamErr if tid is NULL, kAUStatErr  * or kAUSysctlErr if one of the underlying system calls fails (a message  * is sent to the system log in those cases).  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
name|int
name|audit_set_terminal_id
parameter_list|(
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * BEGIN au_write() WRAPPERS  *  * The following calls all wrap the existing BSM API.  They use the  * provided subject information, if any, to construct the subject token  * required for every log message.  They use the provided return/error  * value(s), if any, to construct the success/failure indication required  * for every log message.  They only permit one "miscellaneous" token,  * which should contain the event-specific logging information mandated by  * CAPP.  *  * All these calls assume the caller has previously determined that  * auditing is enabled by calling au_get_state().  */
end_comment

begin_comment
comment|/*  * audit_write()  *  * @summary - audit_write() is the basis for the other audit_write_*()  * calls.  Performs a basic write of an audit record (subject, additional  * info, success/failure).  Note that this call only permits logging one  * caller-specified token; clients needing to log more flexibly must use  * the existing BSM API (au_open(), et al.) directly.  *  * Note on memory management: audit_write() guarantees that the token_t *s  * passed to it will be deallocated whether or not the underlying write to  * the audit log succeeded.  This addresses an inconsistency in the  * underlying BSM API in which token_t *s are usually but not always  * deallocated.  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param subject - A token_t * generated by au_to_subject(),  * au_to_subject32(), au_to_subject64(), or au_to_me().  If no subject is  * required, subject should be NULL.  *  * @param misctok - A token_t * generated by one of the au_to_*() BSM API  * calls.  This should correspond to the additional information required by  * CAPP for the event being audited.  If no additional information is  * required, misctok should be NULL.  *  * @param retval - The return value to be logged for this event.  This  * should be 0 (zero) for success, otherwise the value is event-specific.  *  * @param errcode - Any error code associated with the return value (e.g.,  * errno or h_errno).  If there was no error, errcode should be 0 (zero).  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write
parameter_list|(
name|short
name|event_code
parameter_list|,
name|token_t
modifier|*
name|subject
parameter_list|,
name|token_t
modifier|*
name|misctok
parameter_list|,
name|char
name|retval
parameter_list|,
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_write_success()  *  * @summary - audit_write_success() records an auditable event that did not  * encounter an error.  The interface is designed to require as little  * direct use of the au_to_*() API as possible.  It builds a subject token  * from the information passed in and uses that to invoke audit_write().  * A subject, as defined by CAPP, is a process acting on the user's behalf.  *  * If the subject information is the same as the current process, use  * au_write_success_self().  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param misctok - A token_t * generated by one of the au_to_*() BSM API  * calls.  This should correspond to the additional information required by  * CAPP for the event being audited.  If no additional information is  * required, misctok should be NULL.  *  * @param auid - The subject's audit ID.  *  * @param euid - The subject's effective user ID.  *  * @param egid - The subject's effective group ID.  *  * @param ruid - The subject's real user ID.  *  * @param rgid - The subject's real group ID.  *  * @param pid - The subject's process ID.  *  * @param sid - The subject's session ID.  *  * @param tid - The subject's terminal ID.  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write_success
parameter_list|(
name|short
name|event_code
parameter_list|,
name|token_t
modifier|*
name|misctok
parameter_list|,
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_write_success_self()  *  * @summary - Similar to audit_write_success(), but used when the subject  * (process) is owned and operated by the auditable user him/herself.  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param misctok - A token_t * generated by one of the au_to_*() BSM API  * calls.  This should correspond to the additional information required by  * CAPP for the event being audited.  If no additional information is  * required, misctok should be NULL.  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write_success_self
parameter_list|(
name|short
name|event_code
parameter_list|,
name|token_t
modifier|*
name|misctok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_write_failure()  *  * @summary - audit_write_failure() records an auditable event that  * encountered an error.  The interface is designed to require as little  * direct use of the au_to_*() API as possible.  It builds a subject token  * from the information passed in and uses that to invoke audit_write().  * A subject, as defined by CAPP, is a process acting on the user's behalf.  *  * If the subject information is the same as the current process, use  * au_write_failure_self().  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param errmsg - A text message providing additional information about  * the event being audited.  *  * @param errret - A numerical value providing additional information about  * the error.  This is intended to store the value of errno or h_errno if  * it's relevant.  This can be 0 (zero) if no additional information is  * available.  *  * @param auid - The subject's audit ID.  *  * @param euid - The subject's effective user ID.  *  * @param egid - The subject's effective group ID.  *  * @param ruid - The subject's real user ID.  *  * @param rgid - The subject's real group ID.  *  * @param pid - The subject's process ID.  *  * @param sid - The subject's session ID.  *  * @param tid - The subject's terminal ID.  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write_failure
parameter_list|(
name|short
name|event_code
parameter_list|,
name|char
modifier|*
name|errmsg
parameter_list|,
name|int
name|errret
parameter_list|,
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_write_failure_self()  *  * @summary - Similar to audit_write_failure(), but used when the subject  * (process) is owned and operated by the auditable user him/herself.  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param errmsg - A text message providing additional information about  * the event being audited.  *  * @param errret - A numerical value providing additional information about  * the error.  This is intended to store the value of errno or h_errno if  * it's relevant.  This can be 0 (zero) if no additional information is  * available.  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write_failure_self
parameter_list|(
name|short
name|event_code
parameter_list|,
name|char
modifier|*
name|errmsg
parameter_list|,
name|int
name|errret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * audit_write_failure_na()  *  * @summary - audit_write_failure_na() records errors during login.  Such  * errors are implicitly non-attributable (i.e., not ascribable to any user).  *  * @param event_code - The code for the event being logged.  This should  * be one of the AUE_ values in /usr/include/bsm/audit_uevents.h.  *  * @param errmsg - A text message providing additional information about  * the event being audited.  *  * @param errret - A numerical value providing additional information about  * the error.  This is intended to store the value of errno or h_errno if  * it's relevant.  This can be 0 (zero) if no additional information is  * available.  *  * @param euid - The subject's effective user ID.  *  * @param egid - The subject's effective group ID.  *  * @param pid - The subject's process ID.  *  * @param tid - The subject's terminal ID.  *  * @return - The status of the call: 0 (zero) on success, else one of the  * kAU*Err values defined above.  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|int
name|audit_write_failure_na
parameter_list|(
name|short
name|event_code
parameter_list|,
name|char
modifier|*
name|errmsg
parameter_list|,
name|int
name|errret
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* END au_write() WRAPPERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_comment
comment|/*  * audit_token_to_au32()  *  * @summary - Extract information from an audit_token_t, used to identify  * Mach tasks and senders of Mach messages as subjects to the audit system.  * audit_tokent_to_au32() is the only method that should be used to parse  * an audit_token_t, since its internal representation may change over  * time.  A pointer parameter may be NULL if that information is not  * needed.  *  * @param atoken - the audit token containing the desired information  *  * @param auidp - Pointer to a uid_t; on return will be set to the task or  * sender's audit user ID  *  * @param euidp - Pointer to a uid_t; on return will be set to the task or  * sender's effective user ID  *  * @param egidp - Pointer to a gid_t; on return will be set to the task or  * sender's effective group ID  *  * @param ruidp - Pointer to a uid_t; on return will be set to the task or  * sender's real user ID  *  * @param rgidp - Pointer to a gid_t; on return will be set to the task or  * sender's real group ID  *  * @param pidp - Pointer to a pid_t; on return will be set to the task or  * sender's process ID  *  * @param asidp - Pointer to an au_asid_t; on return will be set to the  * task or sender's audit session ID  *  * @param tidp - Pointer to an au_tid_t; on return will be set to the task  * or sender's terminal ID  *  * XXXRW: In Apple's bsm-8, these are marked __APPLE_API_PRIVATE.  */
end_comment

begin_function_decl
name|void
name|audit_token_to_au32
parameter_list|(
name|audit_token_t
name|atoken
parameter_list|,
name|uid_t
modifier|*
name|auidp
parameter_list|,
name|uid_t
modifier|*
name|euidp
parameter_list|,
name|gid_t
modifier|*
name|egidp
parameter_list|,
name|uid_t
modifier|*
name|ruidp
parameter_list|,
name|gid_t
modifier|*
name|rgidp
parameter_list|,
name|pid_t
modifier|*
name|pidp
parameter_list|,
name|au_asid_t
modifier|*
name|asidp
parameter_list|,
name|au_tid_t
modifier|*
name|tidp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__APPLE__ */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBBSM_H_ */
end_comment

end_unit

