begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__crypto_header__
end_ifndef

begin_define
define|#
directive|define
name|__crypto_header__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PACKAGE_NAME
end_ifndef

begin_error
error|#
directive|error
literal|"need config.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|OPENSSL_DES_LIBDES_COMPATIBILITY
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<hcrypto/evp.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/des.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/md4.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/md5.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/sha.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/rc4.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/rc2.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/ui.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/rand.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/engine.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/pkcs12.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/hmac.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/ec.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/ecdsa.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/ecdh.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_OPENSSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __crypto_header__ */
end_comment

end_unit

