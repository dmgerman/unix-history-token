begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/kssl.h -*- mode: C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Written by Vern Staats<staatsvr@asc.hpc.mil> for the OpenSSL project 2000.  * project 2000.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KSSL_LCL_H
end_ifndef

begin_define
define|#
directive|define
name|KSSL_LCL_H
end_define

begin_include
include|#
directive|include
file|<openssl/kssl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_KRB5
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Private (internal to OpenSSL) */
name|void
name|print_krb5_data
parameter_list|(
name|char
modifier|*
name|label
parameter_list|,
name|krb5_data
modifier|*
name|kdata
parameter_list|)
function_decl|;
name|void
name|print_krb5_authdata
parameter_list|(
name|char
modifier|*
name|label
parameter_list|,
name|krb5_authdata
modifier|*
modifier|*
name|adata
parameter_list|)
function_decl|;
name|void
name|print_krb5_keyblock
parameter_list|(
name|char
modifier|*
name|label
parameter_list|,
name|krb5_keyblock
modifier|*
name|keyblk
parameter_list|)
function_decl|;
name|char
modifier|*
name|kstring
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
name|char
modifier|*
name|knumber
parameter_list|(
name|int
name|len
parameter_list|,
name|krb5_octet
modifier|*
name|contents
parameter_list|)
function_decl|;
name|EVP_CIPHER
modifier|*
name|kssl_map_enc
parameter_list|(
name|krb5_enctype
name|enctype
parameter_list|)
function_decl|;
name|int
name|kssl_keytab_is_available
parameter_list|(
name|KSSL_CTX
modifier|*
name|kssl_ctx
parameter_list|)
function_decl|;
name|int
name|kssl_tgt_is_available
parameter_list|(
name|KSSL_CTX
modifier|*
name|kssl_ctx
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_NO_KRB5	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSSL_LCL_H 	*/
end_comment

end_unit

