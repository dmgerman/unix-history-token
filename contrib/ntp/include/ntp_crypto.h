begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_crypto.h - definitions for cryptographic operations  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_include
include|#
directive|include
file|"openssl/evp.h"
end_include

begin_comment
comment|/*  * The following bits are set by the CRYPTO_ASSOC message from  * the server and are not modified by the client.  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_ENAB
value|0x0001
end_define

begin_comment
comment|/* crypto enable */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_TAI
value|0x0002
end_define

begin_comment
comment|/* leapseconds table */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_PRIV
value|0x0010
end_define

begin_comment
comment|/* PC identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_IFF
value|0x0020
end_define

begin_comment
comment|/* IFF identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_GQ
value|0x0040
end_define

begin_comment
comment|/* GQ identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_MV
value|0x0080
end_define

begin_comment
comment|/* MV identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_MASK
value|0x00f0
end_define

begin_comment
comment|/* identity scheme mask */
end_comment

begin_comment
comment|/*  * The following bits are used by the client during the protocol  * exchange.  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_VALID
value|0x0100
end_define

begin_comment
comment|/* public key verified */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_VRFY
value|0x0200
end_define

begin_comment
comment|/* identity verified */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_PROV
value|0x0400
end_define

begin_comment
comment|/* signature verified */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_AGREE
value|0x0800
end_define

begin_comment
comment|/* cookie verifed */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_AUTO
value|0x1000
end_define

begin_comment
comment|/* autokey verified */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_SIGN
value|0x2000
end_define

begin_comment
comment|/* certificate signed */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_FLAG_LEAP
value|0x4000
end_define

begin_comment
comment|/* leapseconds table verified */
end_comment

begin_comment
comment|/*  * Flags used for certificate management  */
end_comment

begin_define
define|#
directive|define
name|CERT_SIGN
value|0x01
end_define

begin_comment
comment|/* certificate is signed */
end_comment

begin_define
define|#
directive|define
name|CERT_TRUST
value|0x02
end_define

begin_comment
comment|/* certificate is trusted */
end_comment

begin_define
define|#
directive|define
name|CERT_PRIV
value|0x04
end_define

begin_comment
comment|/* certificate is private */
end_comment

begin_define
define|#
directive|define
name|CERT_ERROR
value|0x80
end_define

begin_comment
comment|/* certificate has errors */
end_comment

begin_comment
comment|/*  * Extension field definitions  */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_MAXLEN
value|1024
end_define

begin_comment
comment|/* max extension field length */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_VN
value|2
end_define

begin_comment
comment|/* current protocol version number */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CMD
parameter_list|(
name|x
parameter_list|)
value|(((CRYPTO_VN<< 8) | (x))<< 16)
end_define

begin_define
define|#
directive|define
name|CRYPTO_NULL
value|CRYPTO_CMD(0)
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ASSOC
value|CRYPTO_CMD(1)
end_define

begin_comment
comment|/* association */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CERT
value|CRYPTO_CMD(2)
end_define

begin_comment
comment|/* certificate */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_COOK
value|CRYPTO_CMD(3)
end_define

begin_comment
comment|/* cookie value */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_AUTO
value|CRYPTO_CMD(4)
end_define

begin_comment
comment|/* autokey values */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_TAI
value|CRYPTO_CMD(5)
end_define

begin_comment
comment|/* leapseconds table */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_SIGN
value|CRYPTO_CMD(6)
end_define

begin_comment
comment|/* certificate sign */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_IFF
value|CRYPTO_CMD(7)
end_define

begin_comment
comment|/* IFF identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_GQ
value|CRYPTO_CMD(8)
end_define

begin_comment
comment|/* GQ identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_MV
value|CRYPTO_CMD(9)
end_define

begin_comment
comment|/* MV identity scheme */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_RESP
value|0x80000000
end_define

begin_comment
comment|/* response */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_ERROR
value|0x40000000
end_define

begin_comment
comment|/* error */
end_comment

begin_comment
comment|/*  * Autokey event codes  */
end_comment

begin_define
define|#
directive|define
name|XEVNT_CMD
parameter_list|(
name|x
parameter_list|)
value|(CRPT_EVENT | (x))
end_define

begin_define
define|#
directive|define
name|XEVNT_OK
value|XEVNT_CMD(0)
end_define

begin_comment
comment|/* success */
end_comment

begin_define
define|#
directive|define
name|XEVNT_LEN
value|XEVNT_CMD(1)
end_define

begin_comment
comment|/* bad field format or length */
end_comment

begin_define
define|#
directive|define
name|XEVNT_TSP
value|XEVNT_CMD(2)
end_define

begin_comment
comment|/* bad timestamp */
end_comment

begin_define
define|#
directive|define
name|XEVNT_FSP
value|XEVNT_CMD(3)
end_define

begin_comment
comment|/* bad filestamp */
end_comment

begin_define
define|#
directive|define
name|XEVNT_PUB
value|XEVNT_CMD(4)
end_define

begin_comment
comment|/* bad procedure or data */
end_comment

begin_define
define|#
directive|define
name|XEVNT_MD
value|XEVNT_CMD(5)
end_define

begin_comment
comment|/* unsupported digest type */
end_comment

begin_define
define|#
directive|define
name|XEVNT_KEY
value|XEVNT_CMD(6)
end_define

begin_comment
comment|/* unsupported identity type */
end_comment

begin_define
define|#
directive|define
name|XEVNT_SGL
value|XEVNT_CMD(7)
end_define

begin_comment
comment|/* bad signature length */
end_comment

begin_define
define|#
directive|define
name|XEVNT_SIG
value|XEVNT_CMD(8)
end_define

begin_comment
comment|/* signature not verified */
end_comment

begin_define
define|#
directive|define
name|XEVNT_VFY
value|XEVNT_CMD(9)
end_define

begin_comment
comment|/* certificate not verified */
end_comment

begin_define
define|#
directive|define
name|XEVNT_PER
value|XEVNT_CMD(10)
end_define

begin_comment
comment|/* certificate expired */
end_comment

begin_define
define|#
directive|define
name|XEVNT_CKY
value|XEVNT_CMD(11)
end_define

begin_comment
comment|/* bad or missing cookie */
end_comment

begin_define
define|#
directive|define
name|XEVNT_DAT
value|XEVNT_CMD(12)
end_define

begin_comment
comment|/* bad or missing leapseconds table */
end_comment

begin_define
define|#
directive|define
name|XEVNT_CRT
value|XEVNT_CMD(13)
end_define

begin_comment
comment|/* bad or missing certificate */
end_comment

begin_define
define|#
directive|define
name|XEVNT_ID
value|XEVNT_CMD(14)
end_define

begin_comment
comment|/* bad or missing identification */
end_comment

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
name|CRYPTO_CONF_PRIV
value|1
end_define

begin_comment
comment|/* host keys file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_SIGN
value|2
end_define

begin_comment
comment|/* signature keys file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_LEAP
value|3
end_define

begin_comment
comment|/* leapseconds table file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_KEYS
value|4
end_define

begin_comment
comment|/* keys directory path */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_CERT
value|5
end_define

begin_comment
comment|/* certificate file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_RAND
value|6
end_define

begin_comment
comment|/* random seed file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_TRST
value|7
end_define

begin_comment
comment|/* specify trust */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_IFFPAR
value|8
end_define

begin_comment
comment|/* IFF parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_GQPAR
value|9
end_define

begin_comment
comment|/* GQ parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_MVPAR
value|10
end_define

begin_comment
comment|/* GQ parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_PW
value|11
end_define

begin_comment
comment|/* private key password */
end_comment

begin_comment
comment|/*  * Miscellaneous crypto stuff  */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXSESSION
value|100
end_define

begin_comment
comment|/* maximum session key list entries */
end_comment

begin_define
define|#
directive|define
name|NTP_AUTOMAX
value|13
end_define

begin_comment
comment|/* log2 default max session key life */
end_comment

begin_define
define|#
directive|define
name|KEY_REVOKE
value|16
end_define

begin_comment
comment|/* log2 default key revoke timeout */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXEXTEN
value|1024
end_define

begin_comment
comment|/* maximum extension field size */
end_comment

begin_comment
comment|/*  * The autokey structure holds the values used to authenticate key IDs.  */
end_comment

begin_struct
struct|struct
name|autokey
block|{
comment|/* network byte order */
name|keyid_t
name|key
decl_stmt|;
comment|/* key ID */
name|int32
name|seq
decl_stmt|;
comment|/* key number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The value structure holds variable length data such as public  * key, agreement parameters, public valule and leapsecond table.  * They are in network byte order.  */
end_comment

begin_struct
struct|struct
name|value
block|{
comment|/* network byte order */
name|tstamp_t
name|tstamp
decl_stmt|;
comment|/* timestamp */
name|tstamp_t
name|fstamp
decl_stmt|;
comment|/* filestamp */
name|u_int32
name|vallen
decl_stmt|;
comment|/* value length */
name|u_char
modifier|*
name|ptr
decl_stmt|;
comment|/* data pointer (various) */
name|u_int32
name|siglen
decl_stmt|;
comment|/* signature length */
name|u_char
modifier|*
name|sig
decl_stmt|;
comment|/* signature */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The packet extension field structures are used to hold values  * and signatures in network byte order.  */
end_comment

begin_struct
struct|struct
name|exten
block|{
name|u_int32
name|opcode
decl_stmt|;
comment|/* opcode */
name|u_int32
name|associd
decl_stmt|;
comment|/* association ID */
name|u_int32
name|tstamp
decl_stmt|;
comment|/* timestamp */
name|u_int32
name|fstamp
decl_stmt|;
comment|/* filestamp */
name|u_int32
name|vallen
decl_stmt|;
comment|/* value length */
name|u_int32
name|pkt
index|[
literal|1
index|]
decl_stmt|;
comment|/* start of value field */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The certificate info/value structure  */
end_comment

begin_struct
struct|struct
name|cert_info
block|{
name|struct
name|cert_info
modifier|*
name|link
decl_stmt|;
comment|/* forward link */
name|u_int
name|flags
decl_stmt|;
comment|/* flags that wave */
name|EVP_PKEY
modifier|*
name|pkey
decl_stmt|;
comment|/* generic key */
name|long
name|version
decl_stmt|;
comment|/* X509 version */
name|int
name|nid
decl_stmt|;
comment|/* signature/digest ID */
specifier|const
name|EVP_MD
modifier|*
name|digest
decl_stmt|;
comment|/* message digest algorithm */
name|u_long
name|serial
decl_stmt|;
comment|/* serial number */
name|tstamp_t
name|first
decl_stmt|;
comment|/* valid not before */
name|tstamp_t
name|last
decl_stmt|;
comment|/* valid not after */
name|char
modifier|*
name|subject
decl_stmt|;
comment|/* subject common name */
name|char
modifier|*
name|issuer
decl_stmt|;
comment|/* issuer common name */
name|u_char
modifier|*
name|grpkey
decl_stmt|;
comment|/* GQ group key */
name|u_int
name|grplen
decl_stmt|;
comment|/* GQ group key length */
name|struct
name|value
name|cert
decl_stmt|;
comment|/* certificate/value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cryptographic values  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|keysdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* crypto keys directory */
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
name|struct
name|value
name|hostval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name/value */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cert_info
modifier|*
name|cinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host certificate information */
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
comment|/* OPENSSL */
end_comment

end_unit

