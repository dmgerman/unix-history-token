begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_crypto.h - definitions for cryptographic operations  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_CRYPTO_H
end_define

begin_comment
comment|/*  * Configuration codes (also needed for parser without AUTOKEY)  */
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
comment|/* host name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_IDENT
value|2
end_define

begin_comment
comment|/* group name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_CERT
value|3
end_define

begin_comment
comment|/* certificate file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_RAND
value|4
end_define

begin_comment
comment|/* random seed file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_IFFPAR
value|5
end_define

begin_comment
comment|/* IFF parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_GQPAR
value|6
end_define

begin_comment
comment|/* GQ parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_MVPAR
value|7
end_define

begin_comment
comment|/* MV parameters file name */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_PW
value|8
end_define

begin_comment
comment|/* private key password */
end_comment

begin_define
define|#
directive|define
name|CRYPTO_CONF_NID
value|9
end_define

begin_comment
comment|/* specify digest name */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOKEY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL
end_ifndef

begin_error
error|#
directive|error
error|AUTOKEY should be defined only if OPENSSL is.
end_error

begin_label
name|invalidsyntax
label|:
end_label

begin_expr_stmt
name|AUTOKEY
name|should
name|be
name|defined
name|only
end_expr_stmt

begin_if
if|if OPENSSL is.
endif|#
directive|endif
include|#
directive|include
file|"openssl/evp.h"
include|#
directive|include
file|"ntp_calendar.h"
comment|/* for fields in the cert_info structure */
comment|/*  * The following bits are set by the CRYPTO_ASSOC message from  * the server and are not modified by the client.  */
define|#
directive|define
name|CRYPTO_FLAG_ENAB
value|0x0001
comment|/* crypto enable */
define|#
directive|define
name|CRYPTO_FLAG_TAI
value|0x0002
comment|/* leapseconds table */
define|#
directive|define
name|CRYPTO_FLAG_PRIV
value|0x0010
comment|/* PC identity scheme */
define|#
directive|define
name|CRYPTO_FLAG_IFF
value|0x0020
comment|/* IFF identity scheme */
define|#
directive|define
name|CRYPTO_FLAG_GQ
value|0x0040
comment|/* GQ identity scheme */
define|#
directive|define
name|CRYPTO_FLAG_MV
value|0x0080
comment|/* MV identity scheme */
define|#
directive|define
name|CRYPTO_FLAG_MASK
value|0x00f0
comment|/* identity scheme mask */
comment|/*  * The following bits are used by the client during the protocol  * exchange.  */
define|#
directive|define
name|CRYPTO_FLAG_CERT
value|0x0100
comment|/* public key verified */
define|#
directive|define
name|CRYPTO_FLAG_VRFY
value|0x0200
comment|/* identity verified */
define|#
directive|define
name|CRYPTO_FLAG_PROV
value|0x0400
comment|/* signature verified */
define|#
directive|define
name|CRYPTO_FLAG_COOK
value|0x0800
comment|/* cookie verifed */
define|#
directive|define
name|CRYPTO_FLAG_AUTO
value|0x1000
comment|/* autokey verified */
define|#
directive|define
name|CRYPTO_FLAG_SIGN
value|0x2000
comment|/* certificate signed */
define|#
directive|define
name|CRYPTO_FLAG_LEAP
value|0x4000
comment|/* leapsecond values verified */
define|#
directive|define
name|CRYPTO_FLAG_ALL
value|0x7f00
comment|/* all mask */
comment|/*  * Flags used for certificate management  */
define|#
directive|define
name|CERT_TRUST
value|0x01
comment|/* certificate is trusted */
define|#
directive|define
name|CERT_SIGN
value|0x02
comment|/* certificate is signed */
define|#
directive|define
name|CERT_VALID
value|0x04
comment|/* certificate is valid */
define|#
directive|define
name|CERT_PRIV
value|0x08
comment|/* certificate is private */
define|#
directive|define
name|CERT_ERROR
value|0x80
comment|/* certificate has errors */
comment|/*  * Extension field definitions  */
define|#
directive|define
name|CRYPTO_MAXLEN
value|1024
comment|/* max extension field length */
define|#
directive|define
name|CRYPTO_VN
value|2
comment|/* current protocol version number */
define|#
directive|define
name|CRYPTO_CMD
parameter_list|(
name|x
parameter_list|)
value|(((CRYPTO_VN<< 8) | (x))<< 16)
define|#
directive|define
name|CRYPTO_NULL
value|CRYPTO_CMD(0)
comment|/* no operation */
define|#
directive|define
name|CRYPTO_ASSOC
value|CRYPTO_CMD(1)
comment|/* association */
define|#
directive|define
name|CRYPTO_CERT
value|CRYPTO_CMD(2)
comment|/* certificate */
define|#
directive|define
name|CRYPTO_COOK
value|CRYPTO_CMD(3)
comment|/* cookie value */
define|#
directive|define
name|CRYPTO_AUTO
value|CRYPTO_CMD(4)
comment|/* autokey values */
define|#
directive|define
name|CRYPTO_LEAP
value|CRYPTO_CMD(5)
comment|/* leapsecond values */
define|#
directive|define
name|CRYPTO_SIGN
value|CRYPTO_CMD(6)
comment|/* certificate sign */
define|#
directive|define
name|CRYPTO_IFF
value|CRYPTO_CMD(7)
comment|/* IFF identity scheme */
define|#
directive|define
name|CRYPTO_GQ
value|CRYPTO_CMD(8)
comment|/* GQ identity scheme */
define|#
directive|define
name|CRYPTO_MV
value|CRYPTO_CMD(9)
comment|/* MV identity scheme */
define|#
directive|define
name|CRYPTO_RESP
value|0x80000000
comment|/* response */
define|#
directive|define
name|CRYPTO_ERROR
value|0x40000000
comment|/* error */
comment|/*  * Autokey event codes  */
define|#
directive|define
name|XEVNT_CMD
parameter_list|(
name|x
parameter_list|)
value|(CRPT_EVENT | (x))
define|#
directive|define
name|XEVNT_OK
value|XEVNT_CMD(0)
comment|/* success */
define|#
directive|define
name|XEVNT_LEN
value|XEVNT_CMD(1)
comment|/* bad field format or length */
define|#
directive|define
name|XEVNT_TSP
value|XEVNT_CMD(2)
comment|/* bad timestamp */
define|#
directive|define
name|XEVNT_FSP
value|XEVNT_CMD(3)
comment|/* bad filestamp */
define|#
directive|define
name|XEVNT_PUB
value|XEVNT_CMD(4)
comment|/* bad or missing public key */
define|#
directive|define
name|XEVNT_MD
value|XEVNT_CMD(5)
comment|/* unsupported digest type */
define|#
directive|define
name|XEVNT_KEY
value|XEVNT_CMD(6)
comment|/* unsupported identity type */
define|#
directive|define
name|XEVNT_SGL
value|XEVNT_CMD(7)
comment|/* bad signature length */
define|#
directive|define
name|XEVNT_SIG
value|XEVNT_CMD(8)
comment|/* signature not verified */
define|#
directive|define
name|XEVNT_VFY
value|XEVNT_CMD(9)
comment|/* certificate not verified */
define|#
directive|define
name|XEVNT_PER
value|XEVNT_CMD(10)
comment|/* host certificate expired */
define|#
directive|define
name|XEVNT_CKY
value|XEVNT_CMD(11)
comment|/* bad or missing cookie */
define|#
directive|define
name|XEVNT_DAT
value|XEVNT_CMD(12)
comment|/* bad or missing leapseconds */
define|#
directive|define
name|XEVNT_CRT
value|XEVNT_CMD(13)
comment|/* bad or missing certificate */
define|#
directive|define
name|XEVNT_ID
value|XEVNT_CMD(14)
comment|/* bad or missing group key */
define|#
directive|define
name|XEVNT_ERR
value|XEVNT_CMD(15)
comment|/* protocol error */
comment|/*  * Miscellaneous crypto stuff  */
define|#
directive|define
name|NTP_MAXSESSION
value|100
comment|/* maximum session key list entries */
define|#
directive|define
name|NTP_MAXEXTEN
value|2048
comment|/* maximum extension field size */
define|#
directive|define
name|NTP_AUTOMAX
value|12
comment|/* default key list timeout (log2 s) */
define|#
directive|define
name|KEY_REVOKE
value|17
comment|/* default key revoke timeout (log2 s) */
define|#
directive|define
name|NTP_REFRESH
value|19
comment|/* default restart timeout (log2 s) */
define|#
directive|define
name|NTP_MAXKEY
value|65535
comment|/* maximum symmetric key ID */
comment|/*  * The autokey structure holds the values used to authenticate key IDs.  */
if|struct autokey
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
end_if

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|void
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
name|struct
name|calendar
name|first
decl_stmt|;
comment|/* not valid before */
name|struct
name|calendar
name|last
decl_stmt|;
comment|/* not valid after */
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
name|BIGNUM
modifier|*
name|grpkey
decl_stmt|;
comment|/* GQ group key */
name|struct
name|value
name|cert
decl_stmt|;
comment|/* certificate/value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The keys info/value structure  */
end_comment

begin_struct
struct|struct
name|pkey_info
block|{
name|struct
name|pkey_info
modifier|*
name|link
decl_stmt|;
comment|/* forward link */
name|EVP_PKEY
modifier|*
name|pkey
decl_stmt|;
comment|/* generic key */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* file name */
name|tstamp_t
name|fstamp
decl_stmt|;
comment|/* filestamp */
block|}
struct|;
end_struct

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

begin_decl_stmt
specifier|extern
name|int
name|crypto_nid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* digest nid */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOKEY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_CRYPTO_H */
end_comment

end_unit

