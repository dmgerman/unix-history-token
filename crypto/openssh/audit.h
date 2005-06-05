begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: audit.h,v 1.2 2005/02/08 10:52:48 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, 2005 Darren Tucker.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"auth.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SSH_AUDIT_H
end_ifndef

begin_define
define|#
directive|define
name|_SSH_AUDIT_H
end_define

begin_enum
enum|enum
name|ssh_audit_event_type
block|{
name|SSH_LOGIN_EXCEED_MAXTRIES
block|,
name|SSH_LOGIN_ROOT_DENIED
block|,
name|SSH_AUTH_SUCCESS
block|,
name|SSH_AUTH_FAIL_NONE
block|,
name|SSH_AUTH_FAIL_PASSWD
block|,
name|SSH_AUTH_FAIL_KBDINT
block|,
comment|/* keyboard-interactive or challenge-response */
name|SSH_AUTH_FAIL_PUBKEY
block|,
comment|/* ssh2 pubkey or ssh1 rsa */
name|SSH_AUTH_FAIL_HOSTBASED
block|,
comment|/* ssh2 hostbased or ssh1 rhostsrsa */
name|SSH_AUTH_FAIL_GSSAPI
block|,
name|SSH_INVALID_USER
block|,
name|SSH_NOLOGIN
block|,
comment|/* denied by /etc/nologin, not implemented */
name|SSH_CONNECTION_CLOSE
block|,
comment|/* closed after attempting auth or session */
name|SSH_CONNECTION_ABANDON
block|,
comment|/* closed without completing auth */
name|SSH_AUDIT_UNKNOWN
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ssh_audit_event_type
name|ssh_audit_event_t
typedef|;
end_typedef

begin_function_decl
name|void
name|audit_connection_from
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_event
parameter_list|(
name|ssh_audit_event_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_session_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_session_close
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|audit_run_command
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssh_audit_event_t
name|audit_classify_auth
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSH_AUDIT_H */
end_comment

end_unit

