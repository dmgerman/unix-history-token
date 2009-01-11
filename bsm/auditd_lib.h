begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Apple Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bsm/auditd_lib.h#3 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDITD_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDITD_LIB_H_
end_define

begin_comment
comment|/*  * Lengths for audit trail file components.  */
end_comment

begin_define
define|#
directive|define
name|NOT_TERMINATED
value|"not_terminated"
end_define

begin_define
define|#
directive|define
name|CRASH_RECOVERY
value|"crash_recovery"
end_define

begin_define
define|#
directive|define
name|POSTFIX_LEN
value|(sizeof("YYYYMMDDhhmmss") - 1)
end_define

begin_define
define|#
directive|define
name|FILENAME_LEN
value|((2 * POSTFIX_LEN) + 2)
end_define

begin_define
define|#
directive|define
name|TIMESTAMP_LEN
value|(POSTFIX_LEN + 1)
end_define

begin_comment
comment|/*  * Macro to generate the timestamp string for trail file.  */
end_comment

begin_define
define|#
directive|define
name|getTSstr
parameter_list|(
name|t
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|)
define|\
value|( (((t) = time(0)) == (time_t)-1 ) ||				\ 	    !strftime((b), (l), "%Y%m%d%H%M%S", gmtime(&(t)) ) ) ? -1 : 0
end_define

begin_comment
comment|/*  * The symbolic link to the currently active audit trail file.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_CURRENT_LINK
value|"/var/audit/current"
end_define

begin_comment
comment|/*  * Path of auditd plist file for launchd.  */
end_comment

begin_define
define|#
directive|define
name|AUDITD_PLIST_FILE
define|\
value|"/System/Library/LaunchDaemons/com.apple.auditd.plist"
end_define

begin_comment
comment|/*  * Error return codes for auditd_lib functions.  */
end_comment

begin_define
define|#
directive|define
name|ADE_NOERR
value|0
end_define

begin_comment
comment|/* No Error or Success. */
end_comment

begin_define
define|#
directive|define
name|ADE_PARSE
value|-1
end_define

begin_comment
comment|/* Error parsing audit_control(5). */
end_comment

begin_define
define|#
directive|define
name|ADE_AUDITON
value|-2
end_define

begin_comment
comment|/* auditon(2) call failed. */
end_comment

begin_define
define|#
directive|define
name|ADE_NOMEM
value|-3
end_define

begin_comment
comment|/* Error allocating memory. */
end_comment

begin_define
define|#
directive|define
name|ADE_SOFTLIM
value|-4
end_define

begin_comment
comment|/* All audit log directories over soft limit. */
end_comment

begin_define
define|#
directive|define
name|ADE_HARDLIM
value|-5
end_define

begin_comment
comment|/* All audit log directories over hard limit. */
end_comment

begin_define
define|#
directive|define
name|ADE_STRERR
value|-6
end_define

begin_comment
comment|/* Error creating file name string. */
end_comment

begin_define
define|#
directive|define
name|ADE_AU_OPEN
value|-7
end_define

begin_comment
comment|/* au_open(3) failed. */
end_comment

begin_define
define|#
directive|define
name|ADE_AU_CLOSE
value|-8
end_define

begin_comment
comment|/* au_close(3) failed. */
end_comment

begin_define
define|#
directive|define
name|ADE_SETAUDIT
value|-9
end_define

begin_comment
comment|/* setaudit(2) or setaudit_addr(2) failed. */
end_comment

begin_define
define|#
directive|define
name|ADE_ACTL
value|-10
end_define

begin_comment
comment|/* "Soft" error with auditctl(2). */
end_comment

begin_define
define|#
directive|define
name|ADE_ACTLERR
value|-11
end_define

begin_comment
comment|/* "Hard" error with auditctl(2). */
end_comment

begin_define
define|#
directive|define
name|ADE_SWAPERR
value|-12
end_define

begin_comment
comment|/* The audit trail file could not be swap. */
end_comment

begin_define
define|#
directive|define
name|ADE_RENAME
value|-13
end_define

begin_comment
comment|/* Error renaming crash recovery file. */
end_comment

begin_define
define|#
directive|define
name|ADE_READLINK
value|-14
end_define

begin_comment
comment|/* Error reading 'current' link. */
end_comment

begin_define
define|#
directive|define
name|ADE_SYMLINK
value|-15
end_define

begin_comment
comment|/* Error creating 'current' link. */
end_comment

begin_define
define|#
directive|define
name|ADE_INVAL
value|-16
end_define

begin_comment
comment|/* Invalid argument. */
end_comment

begin_define
define|#
directive|define
name|ADE_GETADDR
value|-17
end_define

begin_comment
comment|/* Error resolving address from hostname. */
end_comment

begin_define
define|#
directive|define
name|ADE_ADDRFAM
value|-18
end_define

begin_comment
comment|/* Address family not supported. */
end_comment

begin_comment
comment|/*  * auditd_lib functions.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|auditd_strerror
parameter_list|(
name|int
name|errcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_minfree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_read_dirs
parameter_list|(
name|int
function_decl|(
modifier|*
name|warn_soft
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|warn_hard
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auditd_close_dirs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_evcmap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_namask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_policy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_fsize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_set_host
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_swap_trail
parameter_list|(
name|char
modifier|*
name|TS
parameter_list|,
name|char
modifier|*
modifier|*
name|newfile
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|int
function_decl|(
modifier|*
name|warn_getacdir
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_prevent_audit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_gen_record
parameter_list|(
name|int
name|event
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auditd_new_curlink
parameter_list|(
name|char
modifier|*
name|curfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_quick_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_quick_stop
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
comment|/* !_BSM_AUDITD_LIB_H_ */
end_comment

end_unit

