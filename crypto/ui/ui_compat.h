begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ui/ui.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Written by Richard Levitte (richard@levitte.org) for the OpenSSL  * project 2001.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_UI_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_UI_COMPAT_H
end_define

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ui.h>
end_include

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
comment|/* The following functions were previously part of the DES section,    and are provided here for backward compatibility reasons. */
define|#
directive|define
name|des_read_pw_string
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|,
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|_ossl_old_des_read_pw_string((b),(l),(p),(v))
define|#
directive|define
name|des_read_pw
parameter_list|(
name|b
parameter_list|,
name|bf
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|_ossl_old_des_read_pw((b),(bf),(s),(p),(v))
name|int
name|_ossl_old_des_read_pw_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|length
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|verify
parameter_list|)
function_decl|;
name|int
name|_ossl_old_des_read_pw
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|buff
parameter_list|,
name|int
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|verify
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

end_unit

