begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/t1_lib.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_include
include|#
directive|include
file|"ssl_locl.h"
end_include

begin_decl_stmt
specifier|const
name|char
name|tls1_version_str
index|[]
init|=
literal|"TLSv1"
name|OPENSSL_VERSION_PTEXT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SSL3_ENC_METHOD
name|TLSv1_enc_data
init|=
block|{
name|tls1_enc
block|,
name|tls1_mac
block|,
name|tls1_setup_key_block
block|,
name|tls1_generate_master_secret
block|,
name|tls1_change_cipher_state
block|,
name|tls1_final_finish_mac
block|,
name|TLS1_FINISH_MAC_LENGTH
block|,
name|tls1_cert_verify_mac
block|,
name|TLS_MD_CLIENT_FINISH_CONST
block|,
name|TLS_MD_CLIENT_FINISH_CONST_SIZE
block|,
name|TLS_MD_SERVER_FINISH_CONST
block|,
name|TLS_MD_SERVER_FINISH_CONST_SIZE
block|,
name|tls1_alert_code
block|, 	}
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|tls1_default_timeout
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 2 hours, the 24 hours mentioned in the TLSv1 spec 	 * is way too long for http, the cache would over fill */
return|return
operator|(
literal|60
operator|*
literal|60
operator|*
literal|2
operator|)
return|;
block|}
end_function

begin_macro
name|IMPLEMENT_tls1_meth_func
argument_list|(
argument|tlsv1_base_method
argument_list|,
argument|ssl_undefined_function
argument_list|,
argument|ssl_undefined_function
argument_list|,
argument|ssl_bad_method
argument_list|)
end_macro

begin_function
name|int
name|tls1_new
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ssl3_new
argument_list|(
name|s
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|s
operator|->
name|method
operator|->
name|ssl_clear
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|tls1_free
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
block|{
name|ssl3_free
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|tls1_clear
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
block|{
name|ssl3_clear
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|->
name|version
operator|=
name|TLS1_VERSION
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|long tls1_ctrl(SSL *s, int cmd, long larg, char *parg) 	{ 	return(0); 	}  long tls1_callback_ctrl(SSL *s, int cmd, void *(*fp)()) 	{ 	return(0); 	}
endif|#
directive|endif
end_endif

end_unit

