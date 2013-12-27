begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * TLSv1 common definitions  * Copyright (c) 2006-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TLSV1_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|TLSV1_COMMON_H
end_define

begin_include
include|#
directive|include
file|"crypto/crypto.h"
end_include

begin_define
define|#
directive|define
name|TLS_VERSION_1
value|0x0301
end_define

begin_comment
comment|/* TLSv1 */
end_comment

begin_define
define|#
directive|define
name|TLS_VERSION_1_1
value|0x0302
end_define

begin_comment
comment|/* TLSv1.1 */
end_comment

begin_define
define|#
directive|define
name|TLS_VERSION_1_2
value|0x0303
end_define

begin_comment
comment|/* TLSv1.2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_TLSV12
end_ifdef

begin_define
define|#
directive|define
name|TLS_VERSION
value|TLS_VERSION_1_2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_TLSV12 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_TLSV11
end_ifdef

begin_define
define|#
directive|define
name|TLS_VERSION
value|TLS_VERSION_1_1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_TLSV11 */
end_comment

begin_define
define|#
directive|define
name|TLS_VERSION
value|TLS_VERSION_1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TLSV11 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TLSV12 */
end_comment

begin_define
define|#
directive|define
name|TLS_RANDOM_LEN
value|32
end_define

begin_define
define|#
directive|define
name|TLS_PRE_MASTER_SECRET_LEN
value|48
end_define

begin_define
define|#
directive|define
name|TLS_MASTER_SECRET_LEN
value|48
end_define

begin_define
define|#
directive|define
name|TLS_SESSION_ID_MAX_LEN
value|32
end_define

begin_define
define|#
directive|define
name|TLS_VERIFY_DATA_LEN
value|12
end_define

begin_comment
comment|/* HandshakeType */
end_comment

begin_enum
enum|enum
block|{
name|TLS_HANDSHAKE_TYPE_HELLO_REQUEST
init|=
literal|0
block|,
name|TLS_HANDSHAKE_TYPE_CLIENT_HELLO
init|=
literal|1
block|,
name|TLS_HANDSHAKE_TYPE_SERVER_HELLO
init|=
literal|2
block|,
name|TLS_HANDSHAKE_TYPE_NEW_SESSION_TICKET
init|=
literal|4
comment|/* RFC 4507 */
block|,
name|TLS_HANDSHAKE_TYPE_CERTIFICATE
init|=
literal|11
block|,
name|TLS_HANDSHAKE_TYPE_SERVER_KEY_EXCHANGE
init|=
literal|12
block|,
name|TLS_HANDSHAKE_TYPE_CERTIFICATE_REQUEST
init|=
literal|13
block|,
name|TLS_HANDSHAKE_TYPE_SERVER_HELLO_DONE
init|=
literal|14
block|,
name|TLS_HANDSHAKE_TYPE_CERTIFICATE_VERIFY
init|=
literal|15
block|,
name|TLS_HANDSHAKE_TYPE_CLIENT_KEY_EXCHANGE
init|=
literal|16
block|,
name|TLS_HANDSHAKE_TYPE_FINISHED
init|=
literal|20
block|,
name|TLS_HANDSHAKE_TYPE_CERTIFICATE_URL
init|=
literal|21
comment|/* RFC 4366 */
block|,
name|TLS_HANDSHAKE_TYPE_CERTIFICATE_STATUS
init|=
literal|22
comment|/* RFC 4366 */
block|}
enum|;
end_enum

begin_comment
comment|/* CipherSuite */
end_comment

begin_define
define|#
directive|define
name|TLS_NULL_WITH_NULL_NULL
value|0x0000
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_MD5
value|0x0001
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_SHA
value|0x0002
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_EXPORT_WITH_RC4_40_MD5
value|0x0003
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_RC4_128_MD5
value|0x0004
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_RC4_128_SHA
value|0x0005
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5
value|0x0006
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_IDEA_CBC_SHA
value|0x0007
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_EXPORT_WITH_DES40_CBC_SHA
value|0x0008
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_DES_CBC_SHA
value|0x0009
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_3DES_EDE_CBC_SHA
value|0x000A
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA
value|0x000B
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_DES_CBC_SHA
value|0x000C
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA
value|0x000D
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA
value|0x000E
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_DES_CBC_SHA
value|0x000F
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA
value|0x0010
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA
value|0x0011
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_DES_CBC_SHA
value|0x0012
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA
value|0x0013
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA
value|0x0014
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_DES_CBC_SHA
value|0x0015
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
value|0x0016
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_EXPORT_WITH_RC4_40_MD5
value|0x0017
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_RC4_128_MD5
value|0x0018
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA
value|0x0019
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_DES_CBC_SHA
value|0x001A
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_3DES_EDE_CBC_SHA
value|0x001B
end_define

begin_comment
comment|/* RFC 2246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_128_CBC_SHA
value|0x002F
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_128_CBC_SHA
value|0x0030
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_128_CBC_SHA
value|0x0031
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_128_CBC_SHA
value|0x0032
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_128_CBC_SHA
value|0x0033
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_AES_128_CBC_SHA
value|0x0034
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_256_CBC_SHA
value|0x0035
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_256_CBC_SHA
value|0x0036
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_256_CBC_SHA
value|0x0037
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_256_CBC_SHA
value|0x0038
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_256_CBC_SHA
value|0x0039
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_AES_256_CBC_SHA
value|0x003A
end_define

begin_comment
comment|/* RFC 3268 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_NULL_SHA256
value|0x003B
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_128_CBC_SHA256
value|0x003C
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_RSA_WITH_AES_256_CBC_SHA256
value|0x003D
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_128_CBC_SHA256
value|0x003E
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_128_CBC_SHA256
value|0x003F
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_128_CBC_SHA256
value|0x0040
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
value|0x0067
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_DSS_WITH_AES_256_CBC_SHA256
value|0x0068
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_RSA_WITH_AES_256_CBC_SHA256
value|0x0069
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_DSS_WITH_AES_256_CBC_SHA256
value|0x006A
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
value|0x006B
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_AES_128_CBC_SHA256
value|0x006C
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_define
define|#
directive|define
name|TLS_DH_anon_WITH_AES_256_CBC_SHA256
value|0x006D
end_define

begin_comment
comment|/* RFC 5246 */
end_comment

begin_comment
comment|/* CompressionMethod */
end_comment

begin_define
define|#
directive|define
name|TLS_COMPRESSION_NULL
value|0
end_define

begin_comment
comment|/* HashAlgorithm */
end_comment

begin_enum
enum|enum
block|{
name|TLS_HASH_ALG_NONE
init|=
literal|0
block|,
name|TLS_HASH_ALG_MD5
init|=
literal|1
block|,
name|TLS_HASH_ALG_SHA1
init|=
literal|2
block|,
name|TLS_HASH_ALG_SHA224
init|=
literal|3
block|,
name|TLS_HASH_ALG_SHA256
init|=
literal|4
block|,
name|TLS_HASH_ALG_SHA384
init|=
literal|5
block|,
name|TLS_HASH_ALG_SHA512
init|=
literal|6
block|}
enum|;
end_enum

begin_comment
comment|/* SignatureAlgorithm */
end_comment

begin_enum
enum|enum
block|{
name|TLS_SIGN_ALG_ANONYMOUS
init|=
literal|0
block|,
name|TLS_SIGN_ALG_RSA
init|=
literal|1
block|,
name|TLS_SIGN_ALG_DSA
init|=
literal|2
block|,
name|TLS_SIGN_ALG_ECDSA
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/* AlertLevel */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_LEVEL_WARNING
value|1
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_LEVEL_FATAL
value|2
end_define

begin_comment
comment|/* AlertDescription */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_CLOSE_NOTIFY
value|0
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_UNEXPECTED_MESSAGE
value|10
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_BAD_RECORD_MAC
value|20
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_DECRYPTION_FAILED
value|21
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_RECORD_OVERFLOW
value|22
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_DECOMPRESSION_FAILURE
value|30
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_HANDSHAKE_FAILURE
value|40
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_BAD_CERTIFICATE
value|42
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_UNSUPPORTED_CERTIFICATE
value|43
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_CERTIFICATE_REVOKED
value|44
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_CERTIFICATE_EXPIRED
value|45
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_CERTIFICATE_UNKNOWN
value|46
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_ILLEGAL_PARAMETER
value|47
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_UNKNOWN_CA
value|48
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_ACCESS_DENIED
value|49
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_DECODE_ERROR
value|50
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_DECRYPT_ERROR
value|51
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_EXPORT_RESTRICTION
value|60
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_PROTOCOL_VERSION
value|70
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_INSUFFICIENT_SECURITY
value|71
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_INTERNAL_ERROR
value|80
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_USER_CANCELED
value|90
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_NO_RENEGOTIATION
value|100
end_define

begin_define
define|#
directive|define
name|TLS_ALERT_UNSUPPORTED_EXTENSION
value|110
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_CERTIFICATE_UNOBTAINABLE
value|111
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_UNRECOGNIZED_NAME
value|112
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_BAD_CERTIFICATE_STATUS_RESPONSE
value|113
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_ALERT_BAD_CERTIFICATE_HASH_VALUE
value|114
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_comment
comment|/* ChangeCipherSpec */
end_comment

begin_enum
enum|enum
block|{
name|TLS_CHANGE_CIPHER_SPEC
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* TLS Extensions */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_SERVER_NAME
value|0
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_MAX_FRAGMENT_LENGTH
value|1
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_CLIENT_CERTIFICATE_URL
value|2
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_TRUSTED_CA_KEYS
value|3
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_TRUNCATED_HMAC
value|4
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_STATUS_REQUEST
value|5
end_define

begin_comment
comment|/* RFC 4366 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_SESSION_TICKET
value|35
end_define

begin_comment
comment|/* RFC 4507 */
end_comment

begin_define
define|#
directive|define
name|TLS_EXT_PAC_OPAQUE
value|TLS_EXT_SESSION_TICKET
end_define

begin_comment
comment|/* EAP-FAST terminology */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TLS_KEY_X_NULL
block|,
name|TLS_KEY_X_RSA
block|,
name|TLS_KEY_X_RSA_EXPORT
block|,
name|TLS_KEY_X_DH_DSS_EXPORT
block|,
name|TLS_KEY_X_DH_DSS
block|,
name|TLS_KEY_X_DH_RSA_EXPORT
block|,
name|TLS_KEY_X_DH_RSA
block|,
name|TLS_KEY_X_DHE_DSS_EXPORT
block|,
name|TLS_KEY_X_DHE_DSS
block|,
name|TLS_KEY_X_DHE_RSA_EXPORT
block|,
name|TLS_KEY_X_DHE_RSA
block|,
name|TLS_KEY_X_DH_anon_EXPORT
block|,
name|TLS_KEY_X_DH_anon
block|}
name|tls_key_exchange
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TLS_CIPHER_NULL
block|,
name|TLS_CIPHER_RC4_40
block|,
name|TLS_CIPHER_RC4_128
block|,
name|TLS_CIPHER_RC2_CBC_40
block|,
name|TLS_CIPHER_IDEA_CBC
block|,
name|TLS_CIPHER_DES40_CBC
block|,
name|TLS_CIPHER_DES_CBC
block|,
name|TLS_CIPHER_3DES_EDE_CBC
block|,
name|TLS_CIPHER_AES_128_CBC
block|,
name|TLS_CIPHER_AES_256_CBC
block|}
name|tls_cipher
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TLS_HASH_NULL
block|,
name|TLS_HASH_MD5
block|,
name|TLS_HASH_SHA
block|,
name|TLS_HASH_SHA256
block|}
name|tls_hash
typedef|;
end_typedef

begin_struct
struct|struct
name|tls_cipher_suite
block|{
name|u16
name|suite
decl_stmt|;
name|tls_key_exchange
name|key_exchange
decl_stmt|;
name|tls_cipher
name|cipher
decl_stmt|;
name|tls_hash
name|hash
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|TLS_CIPHER_STREAM
block|,
name|TLS_CIPHER_BLOCK
block|}
name|tls_cipher_type
typedef|;
end_typedef

begin_struct
struct|struct
name|tls_cipher_data
block|{
name|tls_cipher
name|cipher
decl_stmt|;
name|tls_cipher_type
name|type
decl_stmt|;
name|size_t
name|key_material
decl_stmt|;
name|size_t
name|expanded_key_material
decl_stmt|;
name|size_t
name|block_size
decl_stmt|;
comment|/* also iv_size */
name|enum
name|crypto_cipher_alg
name|alg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tls_verify_hash
block|{
name|struct
name|crypto_hash
modifier|*
name|md5_client
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha1_client
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha256_client
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|md5_server
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha1_server
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha256_server
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|md5_cert
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha1_cert
decl_stmt|;
name|struct
name|crypto_hash
modifier|*
name|sha256_cert
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|tls_cipher_suite
modifier|*
name|tls_get_cipher_suite
parameter_list|(
name|u16
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|tls_cipher_data
modifier|*
name|tls_get_cipher_data
parameter_list|(
name|tls_cipher
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_server_key_exchange_allowed
parameter_list|(
name|tls_cipher
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_parse_cert
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|struct
name|crypto_public_key
modifier|*
modifier|*
name|pk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_verify_hash_init
parameter_list|(
name|struct
name|tls_verify_hash
modifier|*
name|verify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls_verify_hash_add
parameter_list|(
name|struct
name|tls_verify_hash
modifier|*
name|verify
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls_verify_hash_free
parameter_list|(
name|struct
name|tls_verify_hash
modifier|*
name|verify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_version_ok
parameter_list|(
name|u16
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|tls_version_str
parameter_list|(
name|u16
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_prf
parameter_list|(
name|u16
name|ver
parameter_list|,
specifier|const
name|u8
modifier|*
name|secret
parameter_list|,
name|size_t
name|secret_len
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
specifier|const
name|u8
modifier|*
name|seed
parameter_list|,
name|size_t
name|seed_len
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLSV1_COMMON_H */
end_comment

end_unit

