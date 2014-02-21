begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)auth_des.h	2.2 88/07/29 4.0 RPCSRC; from 1.3 88/02/08 SMI */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   *	from: @(#)auth_des.h 2.2 88/07/29 4.0 RPCSRC  *	from: @(#)auth_des.h 1.14    94/04/25 SMI  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * auth_des.h, Protocol for DES style authentication for RPC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUTH_DES_
end_ifndef

begin_define
define|#
directive|define
name|_AUTH_DES_
end_define

begin_comment
comment|/*  * There are two kinds of "names": fullnames and nicknames  */
end_comment

begin_enum
enum|enum
name|authdes_namekind
block|{
name|ADN_FULLNAME
block|,
name|ADN_NICKNAME
block|}
enum|;
end_enum

begin_comment
comment|/*  * A fullname contains the network name of the client,   * a conversation key and the window  */
end_comment

begin_struct
struct|struct
name|authdes_fullname
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* network name of client, up to MAXNETNAMELEN */
name|des_block
name|key
decl_stmt|;
comment|/* conversation key */
name|u_long
name|window
decl_stmt|;
comment|/* associated window */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A credential   */
end_comment

begin_struct
struct|struct
name|authdes_cred
block|{
name|enum
name|authdes_namekind
name|adc_namekind
decl_stmt|;
name|struct
name|authdes_fullname
name|adc_fullname
decl_stmt|;
name|u_long
name|adc_nickname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A des authentication verifier   */
end_comment

begin_struct
struct|struct
name|authdes_verf
block|{
union|union
block|{
name|struct
name|timeval
name|adv_ctime
decl_stmt|;
comment|/* clear time */
name|des_block
name|adv_xtime
decl_stmt|;
comment|/* crypt time */
block|}
name|adv_time_u
union|;
name|u_long
name|adv_int_u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * des authentication verifier: client variety  *  * adv_timestamp is the current time.  * adv_winverf is the credential window + 1.  * Both are encrypted using the conversation key.  */
end_comment

begin_define
define|#
directive|define
name|adv_timestamp
value|adv_time_u.adv_ctime
end_define

begin_define
define|#
directive|define
name|adv_xtimestamp
value|adv_time_u.adv_xtime
end_define

begin_define
define|#
directive|define
name|adv_winverf
value|adv_int_u
end_define

begin_comment
comment|/*  * des authentication verifier: server variety  *  * adv_timeverf is the client's timestamp + client's window  * adv_nickname is the server's nickname for the client.  * adv_timeverf is encrypted using the conversation key.  */
end_comment

begin_define
define|#
directive|define
name|adv_timeverf
value|adv_time_u.adv_ctime
end_define

begin_define
define|#
directive|define
name|adv_xtimeverf
value|adv_time_u.adv_xtime
end_define

begin_define
define|#
directive|define
name|adv_nickname
value|adv_int_u
end_define

begin_comment
comment|/*  * Map a des credential into a unix cred.  *  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|authdes_getucred
parameter_list|(
name|struct
name|authdes_cred
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_authdes_cred
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|authdes_cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_authdes_verf
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|authdes_verf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtime
parameter_list|(
name|dev_t
parameter_list|,
name|struct
name|netbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kgetnetname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|auth_stat
name|_svcauth_des
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _AUTH_DES_ */
end_comment

end_unit

