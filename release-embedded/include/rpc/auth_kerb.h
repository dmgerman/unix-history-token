begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * auth_kerb.h, Protocol for Kerberos style authentication for RPC  *  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_AUTH_KERB_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_AUTH_KERB_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERBEROS
end_ifdef

begin_include
include|#
directive|include
file|<kerberos/krb.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/t_kuser.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<rpc/svc.h>
end_include

begin_comment
comment|/*  * There are two kinds of "names": fullnames and nicknames  */
end_comment

begin_enum
enum|enum
name|authkerb_namekind
block|{
name|AKN_FULLNAME
block|,
name|AKN_NICKNAME
block|}
enum|;
end_enum

begin_comment
comment|/*  * A fullname contains the ticket and the window  */
end_comment

begin_struct
struct|struct
name|authkerb_fullname
block|{
name|KTEXT_ST
name|ticket
decl_stmt|;
name|u_long
name|window
decl_stmt|;
comment|/* associated window */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  cooked credential stored in rq_clntcred  */
end_comment

begin_struct
struct|struct
name|authkerb_clnt_cred
block|{
comment|/* start of AUTH_DAT */
name|unsigned
name|char
name|k_flags
decl_stmt|;
comment|/* Flags from ticket */
name|char
name|pname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Principal's name */
name|char
name|pinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* His Instance */
name|char
name|prealm
index|[
name|REALM_SZ
index|]
decl_stmt|;
comment|/* His Realm */
name|unsigned
name|long
name|checksum
decl_stmt|;
comment|/* Data checksum (opt) */
name|C_Block
name|session
decl_stmt|;
comment|/* Session Key */
name|int
name|life
decl_stmt|;
comment|/* Life of ticket */
name|unsigned
name|long
name|time_sec
decl_stmt|;
comment|/* Time ticket issued */
name|unsigned
name|long
name|address
decl_stmt|;
comment|/* Address in ticket */
comment|/* KTEXT_ST reply;	Auth reply (opt) */
comment|/* end of AUTH_DAT */
name|unsigned
name|long
name|expiry
decl_stmt|;
comment|/* time the ticket is expiring */
name|u_long
name|nickname
decl_stmt|;
comment|/* Nickname into cache */
name|u_long
name|window
decl_stmt|;
comment|/* associated window */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|authkerb_clnt_cred
name|authkerb_clnt_cred
typedef|;
end_typedef

begin_comment
comment|/*  * A credential  */
end_comment

begin_struct
struct|struct
name|authkerb_cred
block|{
name|enum
name|authkerb_namekind
name|akc_namekind
decl_stmt|;
name|struct
name|authkerb_fullname
name|akc_fullname
decl_stmt|;
name|u_long
name|akc_nickname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A kerb authentication verifier  */
end_comment

begin_struct
struct|struct
name|authkerb_verf
block|{
union|union
block|{
name|struct
name|timeval
name|akv_ctime
decl_stmt|;
comment|/* clear time */
name|des_block
name|akv_xtime
decl_stmt|;
comment|/* crypt time */
block|}
name|akv_time_u
union|;
name|u_long
name|akv_int_u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * des authentication verifier: client variety  *  * akv_timestamp is the current time.  * akv_winverf is the credential window + 1.  * Both are encrypted using the conversation key.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|akv_timestamp
end_ifndef

begin_define
define|#
directive|define
name|akv_timestamp
value|akv_time_u.akv_ctime
end_define

begin_define
define|#
directive|define
name|akv_xtimestamp
value|akv_time_u.akv_xtime
end_define

begin_define
define|#
directive|define
name|akv_winverf
value|akv_int_u
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * des authentication verifier: server variety  *  * akv_timeverf is the client's timestamp + client's window  * akv_nickname is the server's nickname for the client.  * akv_timeverf is encrypted using the conversation key.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|akv_timeverf
end_ifndef

begin_define
define|#
directive|define
name|akv_timeverf
value|akv_time_u.akv_ctime
end_define

begin_define
define|#
directive|define
name|akv_xtimeverf
value|akv_time_u.akv_xtime
end_define

begin_define
define|#
directive|define
name|akv_nickname
value|akv_int_u
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Register the service name, instance and realm.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|authkerb_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|netbuf
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|dev_t
parameter_list|,
name|int
parameter_list|,
name|AUTH
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_authkerb_cred
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|authkerb_cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_authkerb_verf
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|authkerb_verf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|svc_kerb_reg
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|auth_stat
name|_svcauth_kerb
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERBEROS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_AUTH_KERB_H */
end_comment

end_unit

