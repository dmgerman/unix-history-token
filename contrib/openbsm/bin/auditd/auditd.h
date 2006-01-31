begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Apple Computer, Inc.  * All rights reserved.  *  * @APPLE_BSD_LICENSE_HEADER_START@  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * @APPLE_BSD_LICENSE_HEADER_END@  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/auditd/auditd.h#4 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUDITD_H_
end_ifndef

begin_define
define|#
directive|define
name|_AUDITD_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_define
define|#
directive|define
name|MAX_DIR_SIZE
value|255
end_define

begin_define
define|#
directive|define
name|AUDITD_NAME
value|"auditd"
end_define

begin_define
define|#
directive|define
name|POSTFIX_LEN
value|16
end_define

begin_define
define|#
directive|define
name|NOT_TERMINATED
value|".not_terminated"
end_define

begin_struct
struct|struct
name|dir_ent
block|{
name|char
modifier|*
name|dirname
decl_stmt|;
name|char
name|softlim
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|dir_ent
argument_list|)
name|dirs
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HARDLIM_ALL_WARN
value|"allhard"
end_define

begin_define
define|#
directive|define
name|SOFTLIM_ALL_WARN
value|"allsoft"
end_define

begin_define
define|#
directive|define
name|AUDITOFF_WARN
value|"aditoff"
end_define

begin_define
define|#
directive|define
name|EBUSY_WARN
value|"ebusy"
end_define

begin_define
define|#
directive|define
name|GETACDIR_WARN
value|"getacdir"
end_define

begin_define
define|#
directive|define
name|HARDLIM_WARN
value|"hard"
end_define

begin_define
define|#
directive|define
name|NOSTART_WARN
value|"nostart"
end_define

begin_define
define|#
directive|define
name|POSTSIGTERM_WARN
value|"postsigterm"
end_define

begin_define
define|#
directive|define
name|SOFTLIM_WARN
value|"soft"
end_define

begin_define
define|#
directive|define
name|TMPFILE_WARN
value|"tmpfile"
end_define

begin_define
define|#
directive|define
name|AUDITWARN_SCRIPT
value|"/etc/security/audit_warn"
end_define

begin_define
define|#
directive|define
name|AUDITD_PIDFILE
value|"/var/run/auditd.pid"
end_define

begin_function_decl
name|int
name|audit_warn_allhard
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_allsoft
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_auditoff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_ebusy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_getacdir
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_hard
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_nostart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_postsigterm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_soft
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|audit_warn_tmpfile
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
comment|/* !_AUDITD_H_ */
end_comment

end_unit

