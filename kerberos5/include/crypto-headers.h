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

begin_define
define|#
directive|define
name|OPENSSL_DES_LIBDES_COMPATIBILITY
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __crypto_headers_h__ */
end_comment

end_unit

