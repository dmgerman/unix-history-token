begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* p5_pbe.c */
end_comment

begin_comment
comment|/*  * Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL project  * 1999.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
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
file|<openssl/asn1t.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_comment
comment|/* PKCS#5 password based encryption structure */
end_comment

begin_expr_stmt
name|ASN1_SEQUENCE
argument_list|(
name|PBEPARAM
argument_list|)
operator|=
block|{
name|ASN1_SIMPLE
argument_list|(
name|PBEPARAM
argument_list|,
name|salt
argument_list|,
name|ASN1_OCTET_STRING
argument_list|)
block|,
name|ASN1_SIMPLE
argument_list|(
argument|PBEPARAM
argument_list|,
argument|iter
argument_list|,
argument|ASN1_INTEGER
argument_list|)
block|}
name|ASN1_SEQUENCE_END
argument_list|(
argument|PBEPARAM
argument_list|)
name|IMPLEMENT_ASN1_FUNCTIONS
argument_list|(
argument|PBEPARAM
argument_list|)
comment|/* Set an algorithm identifier for a PKCS#5 PBE algorithm */
name|int
name|PKCS5_pbe_set0_algor
argument_list|(
argument|X509_ALGOR *algor
argument_list|,
argument|int alg
argument_list|,
argument|int iter
argument_list|,
argument|const unsigned char *salt
argument_list|,
argument|int saltlen
argument_list|)
block|{
name|PBEPARAM
operator|*
name|pbe
operator|=
name|NULL
block|;
name|ASN1_STRING
operator|*
name|pbe_str
operator|=
name|NULL
block|;
name|unsigned
name|char
operator|*
name|sstr
block|;
name|pbe
operator|=
name|PBEPARAM_new
argument_list|()
block|;
if|if
condition|(
operator|!
name|pbe
condition|)
block|{
name|ASN1err
argument_list|(
name|ASN1_F_PKCS5_PBE_SET0_ALGOR
argument_list|,
name|ERR_R_MALLOC_FAILURE
argument_list|)
expr_stmt|;
goto|goto
name|err
goto|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|iter
operator|<=
literal|0
condition|)
name|iter
operator|=
name|PKCS5_DEFAULT_ITER
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|!
name|ASN1_INTEGER_set
argument_list|(
name|pbe
operator|->
name|iter
argument_list|,
name|iter
argument_list|)
condition|)
block|{
name|ASN1err
argument_list|(
name|ASN1_F_PKCS5_PBE_SET0_ALGOR
argument_list|,
name|ERR_R_MALLOC_FAILURE
argument_list|)
expr_stmt|;
goto|goto
name|err
goto|;
block|}
end_if

begin_if
if|if
condition|(
operator|!
name|saltlen
condition|)
name|saltlen
operator|=
name|PKCS5_SALT_LEN
expr_stmt|;
end_if

begin_if
if|if
condition|(
operator|!
name|ASN1_STRING_set
argument_list|(
name|pbe
operator|->
name|salt
argument_list|,
name|NULL
argument_list|,
name|saltlen
argument_list|)
condition|)
block|{
name|ASN1err
argument_list|(
name|ASN1_F_PKCS5_PBE_SET0_ALGOR
argument_list|,
name|ERR_R_MALLOC_FAILURE
argument_list|)
expr_stmt|;
goto|goto
name|err
goto|;
block|}
end_if

begin_expr_stmt
name|sstr
operator|=
name|ASN1_STRING_data
argument_list|(
name|pbe
operator|->
name|salt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|salt
condition|)
name|memcpy
argument_list|(
name|sstr
argument_list|,
name|salt
argument_list|,
name|saltlen
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|RAND_bytes
argument_list|(
name|sstr
argument_list|,
name|saltlen
argument_list|)
operator|<=
literal|0
condition|)
goto|goto
name|err
goto|;
end_if

begin_if
if|if
condition|(
operator|!
name|ASN1_item_pack
argument_list|(
name|pbe
argument_list|,
name|ASN1_ITEM_rptr
argument_list|(
name|PBEPARAM
argument_list|)
argument_list|,
operator|&
name|pbe_str
argument_list|)
condition|)
block|{
name|ASN1err
argument_list|(
name|ASN1_F_PKCS5_PBE_SET0_ALGOR
argument_list|,
name|ERR_R_MALLOC_FAILURE
argument_list|)
expr_stmt|;
goto|goto
name|err
goto|;
block|}
end_if

begin_expr_stmt
name|PBEPARAM_free
argument_list|(
name|pbe
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pbe
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|X509_ALGOR_set0
argument_list|(
name|algor
argument_list|,
name|OBJ_nid2obj
argument_list|(
name|alg
argument_list|)
argument_list|,
name|V_ASN1_SEQUENCE
argument_list|,
name|pbe_str
argument_list|)
condition|)
return|return
literal|1
return|;
end_if

begin_label
name|err
label|:
end_label

begin_if
if|if
condition|(
name|pbe
operator|!=
name|NULL
condition|)
name|PBEPARAM_free
argument_list|(
name|pbe
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|pbe_str
operator|!=
name|NULL
condition|)
name|ASN1_STRING_free
argument_list|(
name|pbe_str
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|/* Return an algorithm identifier for a PKCS#5 PBE algorithm */
end_comment

begin_expr_stmt
unit|X509_ALGOR
operator|*
name|PKCS5_pbe_set
argument_list|(
argument|int alg
argument_list|,
argument|int iter
argument_list|,
argument|const unsigned char *salt
argument_list|,
argument|int saltlen
argument_list|)
block|{
name|X509_ALGOR
operator|*
name|ret
block|;
name|ret
operator|=
name|X509_ALGOR_new
argument_list|()
block|;
if|if
condition|(
operator|!
name|ret
condition|)
block|{
name|ASN1err
argument_list|(
name|ASN1_F_PKCS5_PBE_SET
argument_list|,
name|ERR_R_MALLOC_FAILURE
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|PKCS5_pbe_set0_algor
argument_list|(
name|ret
argument_list|,
name|alg
argument_list|,
name|iter
argument_list|,
name|salt
argument_list|,
name|saltlen
argument_list|)
condition|)
return|return
name|ret
return|;
end_if

begin_expr_stmt
name|X509_ALGOR_free
argument_list|(
name|ret
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|NULL
return|;
end_return

unit|}
end_unit

