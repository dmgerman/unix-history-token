begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dso_null.c */
end_comment

begin_comment
comment|/* Written by Geoff Thorpe (geoff@geoffthorpe.net) for the OpenSSL  * project 2000.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* This "NULL" method is provided as the fallback for systems that have  * no appropriate support for "shared-libraries". */
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
file|<openssl/dso.h>
end_include

begin_decl_stmt
specifier|static
name|DSO_METHOD
name|dso_meth_null
init|=
block|{
literal|"NULL shared library method"
block|,
name|NULL
block|,
comment|/* load */
name|NULL
block|,
comment|/* unload */
name|NULL
block|,
comment|/* bind_var */
name|NULL
block|,
comment|/* bind_func */
comment|/* For now, "unbind" doesn't exist */
if|#
directive|if
literal|0
block|NULL,
comment|/* unbind_var */
block|NULL,
comment|/* unbind_func */
endif|#
directive|endif
name|NULL
block|,
comment|/* ctrl */
name|NULL
block|,
comment|/* init */
name|NULL
comment|/* finish */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|DSO_METHOD
modifier|*
name|DSO_METHOD_null
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|&
name|dso_meth_null
operator|)
return|;
block|}
end_function

end_unit

