begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_md5.h: deal with md5.h headers  *  * Use the system MD5 if available, otherwise libisc's.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_MD5_H
operator|&&
name|defined
name|HAVE_MD5INIT
end_if

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"isc/md5.h"
end_include

begin_typedef
typedef|typedef
name|isc_md5_t
name|MD5_CTX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MD5Init
parameter_list|(
name|c
parameter_list|)
value|isc_md5_init(c)
end_define

begin_define
define|#
directive|define
name|MD5Update
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|isc_md5_update(c, p, s)
end_define

begin_define
define|#
directive|define
name|MD5Final
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
value|isc_md5_final((c), (d))
end_define

begin_comment
comment|/* swapped */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Provide OpenSSL-alike MD5 API if we're not using OpenSSL  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL
end_ifndef

begin_typedef
typedef|typedef
name|MD5_CTX
name|EVP_MD_CTX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EVP_get_digestbynid
parameter_list|(
name|t
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|EVP_DigestInit
parameter_list|(
name|c
parameter_list|,
name|dt
parameter_list|)
value|MD5Init(c)
end_define

begin_define
define|#
directive|define
name|EVP_DigestUpdate
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|MD5Update(c, p, s)
end_define

begin_define
define|#
directive|define
name|EVP_DigestFinal
parameter_list|(
name|c
parameter_list|,
name|d
parameter_list|,
name|pdl
parameter_list|)
define|\
value|do {				\ 		MD5Final((d), (c));	\ 		*(pdl) = 16;		\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

