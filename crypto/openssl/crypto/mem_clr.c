begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/mem_clr.c -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Written by Geoff Thorpe (geoff@geoffthorpe.net) for the OpenSSL  * project 2002.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_decl_stmt
name|unsigned
name|char
name|cleanse_ctr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|OPENSSL_cleanse
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
name|ptr
decl_stmt|;
name|size_t
name|loop
init|=
name|len
decl_stmt|;
while|while
condition|(
name|loop
operator|--
condition|)
block|{
operator|*
operator|(
name|p
operator|++
operator|)
operator|=
name|cleanse_ctr
expr_stmt|;
name|cleanse_ctr
operator|+=
operator|(
literal|17
operator|+
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|(
name|int
operator|)
name|p
operator|&
literal|0xF
argument_list|)
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|memchr
argument_list|(
name|ptr
argument_list|,
name|cleanse_ctr
argument_list|,
name|len
argument_list|)
condition|)
name|cleanse_ctr
operator|+=
literal|63
expr_stmt|;
block|}
end_function

end_unit

