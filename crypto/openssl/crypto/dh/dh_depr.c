begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/dh/dh_depr.c */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2002 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* This file contains deprecated functions as wrappers to the new ones */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dh.h>
end_include

begin_decl_stmt
specifier|static
name|void
modifier|*
name|dummy
init|=
operator|&
name|dummy
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DEPRECATED
end_ifndef

begin_function
name|DH
modifier|*
name|DH_generate_parameters
parameter_list|(
name|int
name|prime_len
parameter_list|,
name|int
name|generator
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
block|{
name|BN_GENCB
name|cb
decl_stmt|;
name|DH
modifier|*
name|ret
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|(
name|ret
operator|=
name|DH_new
argument_list|()
operator|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|BN_GENCB_set_old
argument_list|(
operator|&
name|cb
argument_list|,
name|callback
argument_list|,
name|cb_arg
argument_list|)
expr_stmt|;
if|if
condition|(
name|DH_generate_parameters_ex
argument_list|(
name|ret
argument_list|,
name|prime_len
argument_list|,
name|generator
argument_list|,
operator|&
name|cb
argument_list|)
condition|)
return|return
name|ret
return|;
name|DH_free
argument_list|(
name|ret
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

