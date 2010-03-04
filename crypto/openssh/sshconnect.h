begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sshconnect.h,v 1.25 2009/05/27 06:38:16 andreas Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Sensitive
name|Sensitive
typedef|;
end_typedef

begin_struct
struct|struct
name|Sensitive
block|{
name|Key
modifier|*
modifier|*
name|keys
decl_stmt|;
name|int
name|nkeys
decl_stmt|;
name|int
name|external_keysign
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ssh_connect
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_login
parameter_list|(
name|Sensitive
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_exchange_identification
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify_host_key
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_kex
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_kex2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_userauth1
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Sensitive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_userauth2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Sensitive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_put_password
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_local_cmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Macros to raise/lower permissions.  */
end_comment

begin_define
define|#
directive|define
name|PRIV_START
value|do {					\ 	int save_errno = errno;				\ 	if (seteuid(original_effective_uid) != 0)	\ 		fatal("PRIV_START: seteuid: %s",	\ 		    strerror(errno));			\ 	errno = save_errno;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PRIV_END
value|do {					\ 	int save_errno = errno;				\ 	if (seteuid(original_real_uid) != 0)		\ 		fatal("PRIV_END: seteuid: %s",		\ 		    strerror(errno));			\ 	errno = save_errno;				\ } while (0)
end_define

end_unit

