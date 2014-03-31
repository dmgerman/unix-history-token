begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: myproposal.h,v 1.35 2013/12/06 13:39:49 markus Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
comment|/* conditional algorithm support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAS_ECC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAS_NISTP521
end_ifdef

begin_define
define|#
directive|define
name|KEX_ECDH_METHODS
define|\
value|"ecdh-sha2-nistp256," \ 	"ecdh-sha2-nistp384," \ 	"ecdh-sha2-nistp521,"
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_CERT_METHODS
define|\
value|"ecdsa-sha2-nistp256-cert-v01@openssh.com," \ 	"ecdsa-sha2-nistp384-cert-v01@openssh.com," \ 	"ecdsa-sha2-nistp521-cert-v01@openssh.com,"
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_METHODS
define|\
value|"ecdsa-sha2-nistp256," \ 	"ecdsa-sha2-nistp384," \ 	"ecdsa-sha2-nistp521,"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KEX_ECDH_METHODS
define|\
value|"ecdh-sha2-nistp256," \ 	"ecdh-sha2-nistp384,"
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_CERT_METHODS
define|\
value|"ecdsa-sha2-nistp256-cert-v01@openssh.com," \ 	"ecdsa-sha2-nistp384-cert-v01@openssh.com,"
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_METHODS
define|\
value|"ecdsa-sha2-nistp256," \ 	"ecdsa-sha2-nistp384,"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KEX_ECDH_METHODS
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_CERT_METHODS
end_define

begin_define
define|#
directive|define
name|HOSTKEY_ECDSA_METHODS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAVE_EVPGCM
end_ifdef

begin_define
define|#
directive|define
name|AESGCM_CIPHER_MODES
define|\
value|"aes128-gcm@openssh.com,aes256-gcm@openssh.com,"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AESGCM_CIPHER_MODES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_EVP_SHA256
end_ifdef

begin_define
define|#
directive|define
name|KEX_SHA256_METHODS
define|\
value|"diffie-hellman-group-exchange-sha256,"
end_define

begin_define
define|#
directive|define
name|KEX_CURVE25519_METHODS
define|\
value|"curve25519-sha256@libssh.org,"
end_define

begin_define
define|#
directive|define
name|SHA2_HMAC_MODES
define|\
value|"hmac-sha2-256," \ 	"hmac-sha2-512,"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KEX_SHA256_METHODS
end_define

begin_define
define|#
directive|define
name|KEX_CURVE25519_METHODS
end_define

begin_define
define|#
directive|define
name|SHA2_HMAC_MODES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KEX_DEFAULT_KEX
define|\
value|KEX_CURVE25519_METHODS \ 	KEX_ECDH_METHODS \ 	KEX_SHA256_METHODS \ 	"diffie-hellman-group-exchange-sha1," \ 	"diffie-hellman-group14-sha1," \ 	"diffie-hellman-group1-sha1"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_PK_ALG
define|\
value|HOSTKEY_ECDSA_CERT_METHODS \ 	"ssh-rsa-cert-v01@openssh.com," \ 	"ssh-dss-cert-v01@openssh.com," \ 	"ssh-rsa-cert-v00@openssh.com," \ 	"ssh-dss-cert-v00@openssh.com," \ 	HOSTKEY_ECDSA_METHODS \ 	"ssh-rsa," \ 	"ssh-dss," \ 	"ssh-ed25519-cert-v01@openssh.com," \ 	"ssh-ed25519"
end_define

begin_comment
comment|/* the actual algorithms */
end_comment

begin_define
define|#
directive|define
name|KEX_DEFAULT_ENCRYPT
define|\
value|"aes128-ctr,aes192-ctr,aes256-ctr," \ 	"arcfour256,arcfour128," \ 	AESGCM_CIPHER_MODES \ 	"chacha20-poly1305@openssh.com," \ 	"aes128-cbc,3des-cbc,blowfish-cbc,cast128-cbc," \ 	"aes192-cbc,aes256-cbc,arcfour,rijndael-cbc@lysator.liu.se"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NONE_CIPHER_ENABLED
end_ifdef

begin_define
define|#
directive|define
name|KEX_ENCRYPT_INCLUDE_NONE
value|KEX_DEFAULT_ENCRYPT \ 	",none"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KEX_DEFAULT_MAC
define|\
value|"hmac-md5-etm@openssh.com," \ 	"hmac-sha1-etm@openssh.com," \ 	"umac-64-etm@openssh.com," \ 	"umac-128-etm@openssh.com," \ 	"hmac-sha2-256-etm@openssh.com," \ 	"hmac-sha2-512-etm@openssh.com," \ 	"hmac-ripemd160-etm@openssh.com," \ 	"hmac-sha1-96-etm@openssh.com," \ 	"hmac-md5-96-etm@openssh.com," \ 	"hmac-md5," \ 	"hmac-sha1," \ 	"umac-64@openssh.com," \ 	"umac-128@openssh.com," \ 	SHA2_HMAC_MODES \ 	"hmac-ripemd160," \ 	"hmac-ripemd160@openssh.com," \ 	"hmac-sha1-96," \ 	"hmac-md5-96"
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

