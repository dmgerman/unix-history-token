begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_crypto.h - definitions for cryptographic operations  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOKEY
end_ifdef

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"md5.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSAREF
end_ifdef

begin_include
include|#
directive|include
file|"rsaref.h"
end_include

begin_include
include|#
directive|include
file|"rsa.h"
end_include

begin_define
define|#
directive|define
name|EVP_SignInit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|R_SignInit(a, b)
end_define

begin_define
define|#
directive|define
name|EVP_SignUpdate
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|R_SignUpdate(a, b, c);
end_define

begin_define
define|#
directive|define
name|EVP_SignFinal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|R_SignFinal(a, b, c, d);
end_define

begin_define
define|#
directive|define
name|EVP_VerifyInit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|R_VerifyInit(a, b)
end_define

begin_define
define|#
directive|define
name|EVP_VerifyUpdate
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|R_VerifyUpdate(a, b, c);
end_define

begin_define
define|#
directive|define
name|EVP_VerifyFinal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|R_VerifyFinal(a, b, c, d);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSAREF */
end_comment

begin_comment
comment|/*  * Cryptostatus word  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_ENAB
value|0x01
end_define

begin_comment
comment|/* crypto enable */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_RSA
value|0x02
end_define

begin_comment
comment|/* public/private keys */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_CERT
value|0x04
end_define

begin_comment
comment|/* certificate */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_DH
value|0x08
end_define

begin_comment
comment|/* agreement parameters */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_TAI
value|0x10
end_define

begin_comment
comment|/* leapseconds table */
end_comment

begin_comment
comment|/*  * Extension field definitions  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_VN
value|1
end_define

begin_comment
comment|/* current protocol version number */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_NULL
value|((CRYPTO_VN<< 8) | 0)
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_STAT
value|((CRYPTO_VN<< 8) | 1)
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ASSOC
value|((CRYPTO_VN<< 8) | 2)
end_define

begin_comment
comment|/* association ID */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_AUTO
value|((CRYPTO_VN<< 8) | 3)
end_define

begin_comment
comment|/* autokey values */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_PRIV
value|((CRYPTO_VN<< 8) | 4)
end_define

begin_comment
comment|/* cookie value */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_DHPAR
value|((CRYPTO_VN<< 8) | 5)
end_define

begin_comment
comment|/* agreement params */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_DH
value|((CRYPTO_VN<< 8) | 6)
end_define

begin_comment
comment|/* public value */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_NAME
value|((CRYPTO_VN<< 8) | 7)
end_define

begin_comment
comment|/* host name/pub key */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CERT
value|((CRYPTO_VN<< 8) | 8)
end_define

begin_comment
comment|/* PKI certificate */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_TAI
value|((CRYPTO_VN<< 8) | 9)
end_define

begin_comment
comment|/* leapseconds table */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_RESP
value|0x8000
end_define

begin_comment
comment|/* response */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ERROR
value|0x4000
end_define

begin_comment
comment|/* error */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_comment
comment|/*  * Configuration codes  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_NONE
value|0
end_define

begin_comment
comment|/* nothing doing */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_FLAGS
value|1
end_define

begin_comment
comment|/* initialize flags */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_PRIV
value|2
end_define

begin_comment
comment|/* load private key from file */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_PUBL
value|3
end_define

begin_comment
comment|/* load public key from file */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_DH
value|4
end_define

begin_comment
comment|/* load Diffie_Hellman pars from file */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_LEAP
value|5
end_define

begin_comment
comment|/* load leapsecond table */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_KEYS
value|6
end_define

begin_comment
comment|/* set keys directory path */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_CERT
value|7
end_define

begin_comment
comment|/* load PKI certificate from file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|crypto_recv
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crypto_xmit
name|P
argument_list|(
operator|(
name|u_int32
operator|*
operator|,
name|int
operator|,
name|u_int
operator|,
name|keyid_t
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|keyid_t
name|session_key
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|keyid_t
operator|,
name|keyid_t
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|make_keylist
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_expire
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|crypto_agree
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|crypto_config
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|crypto_setup
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crypto_public
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_comment
comment|/*  * Cryptographic values  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|crypto_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status word */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUBKEY
end_ifdef

begin_decl_stmt
specifier|extern
name|R_DH_PARAMS
name|dh_params
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|value
name|host
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name/public key */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|value
name|certif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* certificate */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|value
name|dhparam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* agreement parameters */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|value
name|dhpub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* public value */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|value
name|tai_leap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leapseconds table */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|crypto_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status word */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|sys_tai
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current UTC offset from TAI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUBKEY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOKEY */
end_comment

end_unit

