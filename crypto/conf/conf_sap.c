begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* conf_sap.c */
end_comment

begin_comment
comment|/* Written by Stephen Henson (shenson@bigfoot.com) for the OpenSSL  * project 2001.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/conf.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dso.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the automatic configuration loader: it is called automatically by  * OpenSSL when any of a number of standard initialisation functions are called,  * unless this is overridden by calling OPENSSL_no_config()  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|openssl_configured
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|OPENSSL_config
parameter_list|(
specifier|const
name|char
modifier|*
name|config_name
parameter_list|)
block|{
if|if
condition|(
name|openssl_configured
condition|)
return|return;
name|OPENSSL_load_builtin_modules
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
comment|/* Need to load ENGINEs */
name|ENGINE_load_builtin_engines
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* Add others here? */
name|ERR_clear_error
argument_list|()
expr_stmt|;
if|if
condition|(
name|CONF_modules_load_file
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|CONF_MFLAGS_IGNORE_MISSING_FILE
argument_list|)
operator|<=
literal|0
condition|)
block|{
name|BIO
modifier|*
name|bio_err
decl_stmt|;
name|ERR_load_crypto_strings
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|bio_err
operator|=
name|BIO_new_fp
argument_list|(
name|stderr
argument_list|,
name|BIO_NOCLOSE
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|BIO_printf
argument_list|(
name|bio_err
argument_list|,
literal|"Auto configuration failed\n"
argument_list|)
expr_stmt|;
name|ERR_print_errors
argument_list|(
name|bio_err
argument_list|)
expr_stmt|;
name|BIO_free
argument_list|(
name|bio_err
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
name|void
name|OPENSSL_no_config
parameter_list|()
block|{
name|openssl_configured
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

