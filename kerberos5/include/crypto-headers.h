begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__crypto_headers_h__
end_ifndef

begin_define
define|#
directive|define
name|__crypto_headers_h__
end_define

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rc4.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rc2.h>
end_include

begin_include
include|#
directive|include
file|<openssl/md4.h>
end_include

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ui.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_include
include|#
directive|include
file|<openssl/pkcs12.h>
end_include

begin_include
include|#
directive|include
file|<openssl/pem.h>
end_include

begin_include
include|#
directive|include
file|<openssl/hmac.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ec.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ecdsa.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ecdh.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BN_is_negative
end_ifndef

begin_define
define|#
directive|define
name|BN_set_negative
parameter_list|(
name|bn
parameter_list|,
name|flag
parameter_list|)
value|((bn)->neg=(flag)?1:0)
end_define

begin_define
define|#
directive|define
name|BN_is_negative
parameter_list|(
name|bn
parameter_list|)
value|((bn)->neg != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __crypto_headers_h__ */
end_comment

end_unit

