begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: myproposal.h,v 1.22 2007/06/07 19:37:34 pvalchev Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<openssl/opensslv.h>
end_include

begin_comment
comment|/* Old OpenSSL doesn't support what we need for DHGEX-sha256 */
end_comment

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00907000L
end_if

begin_define
define|#
directive|define
name|KEX_DEFAULT_KEX
define|\
value|"diffie-hellman-group-exchange-sha1," \ 	"diffie-hellman-group14-sha1," \ 	"diffie-hellman-group1-sha1"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KEX_DEFAULT_KEX
define|\
value|"diffie-hellman-group-exchange-sha256," \ 	"diffie-hellman-group-exchange-sha1," \ 	"diffie-hellman-group14-sha1," \ 	"diffie-hellman-group1-sha1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KEX_DEFAULT_PK_ALG
value|"ssh-dss,ssh-rsa"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_ENCRYPT
define|\
value|"aes128-cbc,3des-cbc,blowfish-cbc,cast128-cbc," \ 	"arcfour128,arcfour256,arcfour," \ 	"aes192-cbc,aes256-cbc,rijndael-cbc@lysator.liu.se," \ 	"aes128-ctr,aes192-ctr,aes256-ctr"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_MAC
define|\
value|"hmac-md5,hmac-sha1,umac-64@openssh.com,hmac-ripemd160," \ 	"hmac-ripemd160@openssh.com," \ 	"hmac-sha1-96,hmac-md5-96"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_COMP
value|"none,zlib@openssh.com,zlib"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_LANG
value|""
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|myproposal
index|[
name|PROPOSAL_MAX
index|]
init|=
block|{
name|KEX_DEFAULT_KEX
block|,
name|KEX_DEFAULT_PK_ALG
block|,
name|KEX_DEFAULT_ENCRYPT
block|,
name|KEX_DEFAULT_ENCRYPT
block|,
name|KEX_DEFAULT_MAC
block|,
name|KEX_DEFAULT_MAC
block|,
name|KEX_DEFAULT_COMP
block|,
name|KEX_DEFAULT_COMP
block|,
name|KEX_DEFAULT_LANG
block|,
name|KEX_DEFAULT_LANG
block|}
decl_stmt|;
end_decl_stmt

end_unit

