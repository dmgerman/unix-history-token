begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Andrew J. Korty  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|SSH_CLIENT_DIR
value|".ssh"
end_define

begin_define
define|#
directive|define
name|MODULE_NAME
value|"pam_ssh"
end_define

begin_define
define|#
directive|define
name|NEED_PASSPHRASE
value|"SSH passphrase: "
end_define

begin_define
define|#
directive|define
name|SSH_AGENT
value|"ssh-agent"
end_define

begin_define
define|#
directive|define
name|ENV_PID_SUFFIX
value|"_AGENT_PID"
end_define

begin_define
define|#
directive|define
name|ENV_SOCKET_SUFFIX
value|"_AUTH_SOCK"
end_define

begin_define
define|#
directive|define
name|DEF_KEYFILES
value|"id_dsa,id_rsa,identity"
end_define

begin_define
define|#
directive|define
name|OPT_KEYFILES
value|"keyfiles"
end_define

begin_define
define|#
directive|define
name|OPT_TRY_FIRST_PASS
value|"try_first_pass"
end_define

begin_define
define|#
directive|define
name|OPT_USE_FIRST_PASS
value|"use_first_pass"
end_define

begin_define
define|#
directive|define
name|SEP_KEYFILES
value|","
end_define

end_unit

