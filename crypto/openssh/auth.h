begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $OpenBSD: auth.h,v 1.15 2001/04/12 19:15:24 markus Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_H
end_define

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOGIN_CAP
end_ifdef

begin_include
include|#
directive|include
file|<login_cap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_AUTH
end_ifdef

begin_include
include|#
directive|include
file|<bsd_auth.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|Authctxt
name|Authctxt
typedef|;
end_typedef

begin_struct
struct|struct
name|Authctxt
block|{
name|int
name|success
decl_stmt|;
name|int
name|postponed
decl_stmt|;
name|int
name|valid
decl_stmt|;
name|int
name|attempt
decl_stmt|;
name|int
name|failures
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|service
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
name|char
modifier|*
name|style
decl_stmt|;
ifdef|#
directive|ifdef
name|BSD_AUTH
name|auth_session_t
modifier|*
name|as
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tries to authenticate the user using the .rhosts file.  Returns true if  * authentication succeeds.  If ignore_rhosts is non-zero, this will not  * consider .rhosts and .shosts (/etc/hosts.equiv will still be used).  */
end_comment

begin_function_decl
name|int
name|auth_rhosts
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* extended interface similar to auth_rhosts() */
end_comment

begin_function_decl
name|int
name|auth_rhosts2
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|char
modifier|*
name|ipaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to authenticate the user using the .rhosts file and the host using  * its host key.  Returns true if authentication succeeds.  */
end_comment

begin_function_decl
name|int
name|auth_rhosts_rsa
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|,
name|RSA
modifier|*
name|client_host_key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to authenticate the user using password.  Returns true if  * authentication succeeds.  */
end_comment

begin_function_decl
name|int
name|auth_password
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Performs the RSA authentication dialog with the client.  This returns 0 if  * the client could not be authenticated, and 1 if authentication was  * successful.  This may exit if there is a serious protocol violation.  */
end_comment

begin_function_decl
name|int
name|auth_rsa
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|BIGNUM
modifier|*
name|client_n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parses an RSA key (number of bits, e, n) from a string.  Moves the pointer  * over the key.  Skips any whitespace at the beginning and at end.  */
end_comment

begin_function_decl
name|int
name|auth_rsa_read_key
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|,
name|u_int
modifier|*
name|bitsp
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Performs the RSA authentication challenge-response dialog with the client,  * and returns true (non-zero) if the client gave the correct answer to our  * challenge; returns zero if the client gives a wrong answer.  */
end_comment

begin_function_decl
name|int
name|auth_rsa_challenge_dialog
parameter_list|(
name|RSA
modifier|*
name|pk
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_function_decl
name|int
name|auth_krb5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Doplnit prototypy */
end_comment

begin_function_decl
name|int
name|auth_krb5_tgt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb5_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krb5_cleanup_proc
parameter_list|(
name|void
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_krb5_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_comment
comment|/*  * Performs Kerberos v4 mutual authentication with the client. This returns 0  * if the client could not be authenticated, and 1 if authentication was  * successful.  This may exit if there is a serious protocol violation.  */
end_comment

begin_function_decl
name|int
name|auth_krb4
parameter_list|(
specifier|const
name|char
modifier|*
name|server_user
parameter_list|,
name|KTEXT
name|auth
parameter_list|,
name|char
modifier|*
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_init
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krb4_cleanup_proc
parameter_list|(
name|void
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_krb4_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|AFS
end_ifdef

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_comment
comment|/* Accept passed Kerberos v4 ticket-granting ticket and AFS tokens. */
end_comment

begin_function_decl
name|int
name|auth_kerberos_tgt
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_afs_token
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|token_string
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB4 */
end_comment

begin_function_decl
name|void
name|do_authentication
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_authentication2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Authctxt
modifier|*
name|authctxt_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|auth_log
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|int
name|authenticated
parameter_list|,
name|char
modifier|*
name|method
parameter_list|,
name|char
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|userauth_finish
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|int
name|authenticated
parameter_list|,
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_root_allowed
parameter_list|(
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth2_challenge
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|char
modifier|*
name|devs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|allowed_user
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_challenge
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|char
modifier|*
name|devs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify_response
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|char
modifier|*
name|response
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|auth_get_user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AUTH_FAIL_MAX
value|6
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_LOG
value|(AUTH_FAIL_MAX/2)
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_MSG
value|"Too many authentication failures for %.100s"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

