begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bio_pk7.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL  * project.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2008 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  */
end_comment

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_include
include|#
directive|include
file|<openssl/pkcs7.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_SYSNAME_NETWARE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_SYSNAME_VXWORKS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Streaming encode support for PKCS#7 */
end_comment

begin_function
name|BIO
modifier|*
name|BIO_new_PKCS7
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|PKCS7
modifier|*
name|p7
parameter_list|)
block|{
return|return
name|BIO_new_NDEF
argument_list|(
name|out
argument_list|,
operator|(
name|ASN1_VALUE
operator|*
operator|)
name|p7
argument_list|,
name|ASN1_ITEM_rptr
argument_list|(
name|PKCS7
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

