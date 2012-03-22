begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB5_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB5_H__
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_include
include|#
directive|include
file|<asn1_err.h>
end_include

begin_include
include|#
directive|include
file|<krb5_err.h>
end_include

begin_include
include|#
directive|include
file|<heim_err.h>
end_include

begin_include
include|#
directive|include
file|<k524_err.h>
end_include

begin_include
include|#
directive|include
file|<krb5_asn1.h>
end_include

begin_comment
comment|/* name confusion with MIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5KDC_ERR_KEY_EXP
end_ifndef

begin_define
define|#
directive|define
name|KRB5KDC_ERR_KEY_EXP
value|KRB5KDC_ERR_KEY_EXPIRED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|KRB5_CALLCONV
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_CALLCONV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* simple constants */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|krb5_boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|krb5_error_code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|krb5_kvno
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|krb5_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|krb5_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|krb5_const_pointer
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_crypto_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_crypto_data
modifier|*
name|krb5_crypto
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_get_creds_opt_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_get_creds_opt_data
modifier|*
name|krb5_get_creds_opt
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_digest_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_digest_data
modifier|*
name|krb5_digest
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_ntlm_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_ntlm_data
modifier|*
name|krb5_ntlm
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_pac_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_pac_data
modifier|*
name|krb5_pac
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_rd_req_in_ctx_data
modifier|*
name|krb5_rd_req_in_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_rd_req_out_ctx_data
modifier|*
name|krb5_rd_req_out_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CKSUMTYPE
name|krb5_cksumtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Checksum
name|krb5_checksum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ENCTYPE
name|krb5_enctype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_get_init_creds_ctx
modifier|*
name|krb5_init_creds_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|heim_octet_string
name|krb5_data
typedef|;
end_typedef

begin_comment
comment|/* PKINIT related forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|ContentInfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_pk_identity
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_pk_cert
struct_decl|;
end_struct_decl

begin_comment
comment|/* krb5_enc_data is a mit compat structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|krb5_enc_data
block|{
name|krb5_enctype
name|enctype
decl_stmt|;
name|krb5_kvno
name|kvno
decl_stmt|;
name|krb5_data
name|ciphertext
decl_stmt|;
block|}
name|krb5_enc_data
typedef|;
end_typedef

begin_comment
comment|/* alternative names */
end_comment

begin_enum
enum|enum
block|{
name|ENCTYPE_NULL
init|=
name|KRB5_ENCTYPE_NULL
block|,
name|ENCTYPE_DES_CBC_CRC
init|=
name|KRB5_ENCTYPE_DES_CBC_CRC
block|,
name|ENCTYPE_DES_CBC_MD4
init|=
name|KRB5_ENCTYPE_DES_CBC_MD4
block|,
name|ENCTYPE_DES_CBC_MD5
init|=
name|KRB5_ENCTYPE_DES_CBC_MD5
block|,
name|ENCTYPE_DES3_CBC_MD5
init|=
name|KRB5_ENCTYPE_DES3_CBC_MD5
block|,
name|ENCTYPE_OLD_DES3_CBC_SHA1
init|=
name|KRB5_ENCTYPE_OLD_DES3_CBC_SHA1
block|,
name|ENCTYPE_SIGN_DSA_GENERATE
init|=
name|KRB5_ENCTYPE_SIGN_DSA_GENERATE
block|,
name|ENCTYPE_ENCRYPT_RSA_PRIV
init|=
name|KRB5_ENCTYPE_ENCRYPT_RSA_PRIV
block|,
name|ENCTYPE_ENCRYPT_RSA_PUB
init|=
name|KRB5_ENCTYPE_ENCRYPT_RSA_PUB
block|,
name|ENCTYPE_DES3_CBC_SHA1
init|=
name|KRB5_ENCTYPE_DES3_CBC_SHA1
block|,
name|ENCTYPE_AES128_CTS_HMAC_SHA1_96
init|=
name|KRB5_ENCTYPE_AES128_CTS_HMAC_SHA1_96
block|,
name|ENCTYPE_AES256_CTS_HMAC_SHA1_96
init|=
name|KRB5_ENCTYPE_AES256_CTS_HMAC_SHA1_96
block|,
name|ENCTYPE_ARCFOUR_HMAC
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_MD5
block|,
name|ENCTYPE_ARCFOUR_HMAC_MD5
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_MD5
block|,
name|ENCTYPE_ARCFOUR_HMAC_MD5_56
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_MD5_56
block|,
name|ENCTYPE_ENCTYPE_PK_CROSS
init|=
name|KRB5_ENCTYPE_ENCTYPE_PK_CROSS
block|,
name|ENCTYPE_DES_CBC_NONE
init|=
name|KRB5_ENCTYPE_DES_CBC_NONE
block|,
name|ENCTYPE_DES3_CBC_NONE
init|=
name|KRB5_ENCTYPE_DES3_CBC_NONE
block|,
name|ENCTYPE_DES_CFB64_NONE
init|=
name|KRB5_ENCTYPE_DES_CFB64_NONE
block|,
name|ENCTYPE_DES_PCBC_NONE
init|=
name|KRB5_ENCTYPE_DES_PCBC_NONE
block|,
name|ETYPE_NULL
init|=
name|KRB5_ENCTYPE_NULL
block|,
name|ETYPE_DES_CBC_CRC
init|=
name|KRB5_ENCTYPE_DES_CBC_CRC
block|,
name|ETYPE_DES_CBC_MD4
init|=
name|KRB5_ENCTYPE_DES_CBC_MD4
block|,
name|ETYPE_DES_CBC_MD5
init|=
name|KRB5_ENCTYPE_DES_CBC_MD5
block|,
name|ETYPE_DES3_CBC_MD5
init|=
name|KRB5_ENCTYPE_DES3_CBC_MD5
block|,
name|ETYPE_OLD_DES3_CBC_SHA1
init|=
name|KRB5_ENCTYPE_OLD_DES3_CBC_SHA1
block|,
name|ETYPE_SIGN_DSA_GENERATE
init|=
name|KRB5_ENCTYPE_SIGN_DSA_GENERATE
block|,
name|ETYPE_ENCRYPT_RSA_PRIV
init|=
name|KRB5_ENCTYPE_ENCRYPT_RSA_PRIV
block|,
name|ETYPE_ENCRYPT_RSA_PUB
init|=
name|KRB5_ENCTYPE_ENCRYPT_RSA_PUB
block|,
name|ETYPE_DES3_CBC_SHA1
init|=
name|KRB5_ENCTYPE_DES3_CBC_SHA1
block|,
name|ETYPE_AES128_CTS_HMAC_SHA1_96
init|=
name|KRB5_ENCTYPE_AES128_CTS_HMAC_SHA1_96
block|,
name|ETYPE_AES256_CTS_HMAC_SHA1_96
init|=
name|KRB5_ENCTYPE_AES256_CTS_HMAC_SHA1_96
block|,
name|ETYPE_ARCFOUR_HMAC_MD5
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_MD5
block|,
name|ETYPE_ARCFOUR_HMAC_MD5_56
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_MD5_56
block|,
name|ETYPE_ENCTYPE_PK_CROSS
init|=
name|KRB5_ENCTYPE_ENCTYPE_PK_CROSS
block|,
name|ETYPE_ARCFOUR_MD4
init|=
name|KRB5_ENCTYPE_ARCFOUR_MD4
block|,
name|ETYPE_ARCFOUR_HMAC_OLD
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_OLD
block|,
name|ETYPE_ARCFOUR_HMAC_OLD_EXP
init|=
name|KRB5_ENCTYPE_ARCFOUR_HMAC_OLD_EXP
block|,
name|ETYPE_DES_CBC_NONE
init|=
name|KRB5_ENCTYPE_DES_CBC_NONE
block|,
name|ETYPE_DES3_CBC_NONE
init|=
name|KRB5_ENCTYPE_DES3_CBC_NONE
block|,
name|ETYPE_DES_CFB64_NONE
init|=
name|KRB5_ENCTYPE_DES_CFB64_NONE
block|,
name|ETYPE_DES_PCBC_NONE
init|=
name|KRB5_ENCTYPE_DES_PCBC_NONE
block|,
name|ETYPE_DIGEST_MD5_NONE
init|=
name|KRB5_ENCTYPE_DIGEST_MD5_NONE
block|,
name|ETYPE_CRAM_MD5_NONE
init|=
name|KRB5_ENCTYPE_CRAM_MD5_NONE
block|}
enum|;
end_enum

begin_comment
comment|/* PDU types */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|krb5_pdu
block|{
name|KRB5_PDU_ERROR
init|=
literal|0
block|,
name|KRB5_PDU_TICKET
init|=
literal|1
block|,
name|KRB5_PDU_AS_REQUEST
init|=
literal|2
block|,
name|KRB5_PDU_AS_REPLY
init|=
literal|3
block|,
name|KRB5_PDU_TGS_REQUEST
init|=
literal|4
block|,
name|KRB5_PDU_TGS_REPLY
init|=
literal|5
block|,
name|KRB5_PDU_AP_REQUEST
init|=
literal|6
block|,
name|KRB5_PDU_AP_REPLY
init|=
literal|7
block|,
name|KRB5_PDU_KRB_SAFE
init|=
literal|8
block|,
name|KRB5_PDU_KRB_PRIV
init|=
literal|9
block|,
name|KRB5_PDU_KRB_CRED
init|=
literal|10
block|,
name|KRB5_PDU_NONE
init|=
literal|11
comment|/* See krb5_get_permitted_enctypes() */
block|}
name|krb5_pdu
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PADATA_TYPE
name|krb5_preauthtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|krb5_key_usage
block|{
name|KRB5_KU_PA_ENC_TIMESTAMP
init|=
literal|1
block|,
comment|/* AS-REQ PA-ENC-TIMESTAMP padata timestamp, encrypted with the        client key (section 5.4.1) */
name|KRB5_KU_TICKET
init|=
literal|2
block|,
comment|/* AS-REP Ticket and TGS-REP Ticket (includes tgs session key or        application session key), encrypted with the service key        (section 5.4.2) */
name|KRB5_KU_AS_REP_ENC_PART
init|=
literal|3
block|,
comment|/* AS-REP encrypted part (includes tgs session key or application        session key), encrypted with the client key (section 5.4.2) */
name|KRB5_KU_TGS_REQ_AUTH_DAT_SESSION
init|=
literal|4
block|,
comment|/* TGS-REQ KDC-REQ-BODY AuthorizationData, encrypted with the tgs        session key (section 5.4.1) */
name|KRB5_KU_TGS_REQ_AUTH_DAT_SUBKEY
init|=
literal|5
block|,
comment|/* TGS-REQ KDC-REQ-BODY AuthorizationData, encrypted with the tgs           authenticator subkey (section 5.4.1) */
name|KRB5_KU_TGS_REQ_AUTH_CKSUM
init|=
literal|6
block|,
comment|/* TGS-REQ PA-TGS-REQ padata AP-REQ Authenticator cksum, keyed        with the tgs session key (sections 5.3.2, 5.4.1) */
name|KRB5_KU_TGS_REQ_AUTH
init|=
literal|7
block|,
comment|/* TGS-REQ PA-TGS-REQ padata AP-REQ Authenticator (includes tgs        authenticator subkey), encrypted with the tgs session key        (section 5.3.2) */
name|KRB5_KU_TGS_REP_ENC_PART_SESSION
init|=
literal|8
block|,
comment|/* TGS-REP encrypted part (includes application session key),        encrypted with the tgs session key (section 5.4.2) */
name|KRB5_KU_TGS_REP_ENC_PART_SUB_KEY
init|=
literal|9
block|,
comment|/* TGS-REP encrypted part (includes application session key),        encrypted with the tgs authenticator subkey (section 5.4.2) */
name|KRB5_KU_AP_REQ_AUTH_CKSUM
init|=
literal|10
block|,
comment|/* AP-REQ Authenticator cksum, keyed with the application session        key (section 5.3.2) */
name|KRB5_KU_AP_REQ_AUTH
init|=
literal|11
block|,
comment|/* AP-REQ Authenticator (includes application authenticator        subkey), encrypted with the application session key (section        5.3.2) */
name|KRB5_KU_AP_REQ_ENC_PART
init|=
literal|12
block|,
comment|/* AP-REP encrypted part (includes application session subkey),        encrypted with the application session key (section 5.5.2) */
name|KRB5_KU_KRB_PRIV
init|=
literal|13
block|,
comment|/* KRB-PRIV encrypted part, encrypted with a key chosen by the        application (section 5.7.1) */
name|KRB5_KU_KRB_CRED
init|=
literal|14
block|,
comment|/* KRB-CRED encrypted part, encrypted with a key chosen by the        application (section 5.8.1) */
name|KRB5_KU_KRB_SAFE_CKSUM
init|=
literal|15
block|,
comment|/* KRB-SAFE cksum, keyed with a key chosen by the application        (section 5.6.1) */
name|KRB5_KU_OTHER_ENCRYPTED
init|=
literal|16
block|,
comment|/* Data which is defined in some specification outside of        Kerberos to be encrypted using an RFC1510 encryption type. */
name|KRB5_KU_OTHER_CKSUM
init|=
literal|17
block|,
comment|/* Data which is defined in some specification outside of        Kerberos to be checksummed using an RFC1510 checksum type. */
name|KRB5_KU_KRB_ERROR
init|=
literal|18
block|,
comment|/* Krb-error checksum */
name|KRB5_KU_AD_KDC_ISSUED
init|=
literal|19
block|,
comment|/* AD-KDCIssued checksum */
name|KRB5_KU_MANDATORY_TICKET_EXTENSION
init|=
literal|20
block|,
comment|/* Checksum for Mandatory Ticket Extensions */
name|KRB5_KU_AUTH_DATA_TICKET_EXTENSION
init|=
literal|21
block|,
comment|/* Checksum in Authorization Data in Ticket Extensions */
name|KRB5_KU_USAGE_SEAL
init|=
literal|22
block|,
comment|/* seal in GSSAPI krb5 mechanism */
name|KRB5_KU_USAGE_SIGN
init|=
literal|23
block|,
comment|/* sign in GSSAPI krb5 mechanism */
name|KRB5_KU_USAGE_SEQ
init|=
literal|24
block|,
comment|/* SEQ in GSSAPI krb5 mechanism */
name|KRB5_KU_USAGE_ACCEPTOR_SEAL
init|=
literal|22
block|,
comment|/* acceptor sign in GSSAPI CFX krb5 mechanism */
name|KRB5_KU_USAGE_ACCEPTOR_SIGN
init|=
literal|23
block|,
comment|/* acceptor seal in GSSAPI CFX krb5 mechanism */
name|KRB5_KU_USAGE_INITIATOR_SEAL
init|=
literal|24
block|,
comment|/* initiator sign in GSSAPI CFX krb5 mechanism */
name|KRB5_KU_USAGE_INITIATOR_SIGN
init|=
literal|25
block|,
comment|/* initiator seal in GSSAPI CFX krb5 mechanism */
name|KRB5_KU_PA_SERVER_REFERRAL_DATA
init|=
literal|22
block|,
comment|/* encrypted server referral data */
name|KRB5_KU_SAM_CHECKSUM
init|=
literal|25
block|,
comment|/* Checksum for the SAM-CHECKSUM field */
name|KRB5_KU_SAM_ENC_TRACK_ID
init|=
literal|26
block|,
comment|/* Encryption of the SAM-TRACK-ID field */
name|KRB5_KU_PA_SERVER_REFERRAL
init|=
literal|26
block|,
comment|/* Keyusage for the server referral in a TGS req */
name|KRB5_KU_SAM_ENC_NONCE_SAD
init|=
literal|27
block|,
comment|/* Encryption of the SAM-NONCE-OR-SAD field */
name|KRB5_KU_PA_PKINIT_KX
init|=
literal|44
block|,
comment|/* Encryption type of the kdc session contribution in pk-init */
name|KRB5_KU_AS_REQ
init|=
literal|56
block|,
comment|/* Checksum of over the AS-REQ send by the KDC in PA-REQ-ENC-PA-REP */
name|KRB5_KU_DIGEST_ENCRYPT
init|=
operator|-
literal|18
block|,
comment|/* Encryption key usage used in the digest encryption field */
name|KRB5_KU_DIGEST_OPAQUE
init|=
operator|-
literal|19
block|,
comment|/* Checksum key usage used in the digest opaque field */
name|KRB5_KU_KRB5SIGNEDPATH
init|=
operator|-
literal|21
block|,
comment|/* Checksum key usage on KRB5SignedPath */
name|KRB5_KU_CANONICALIZED_NAMES
init|=
operator|-
literal|23
comment|/* Checksum key usage on PA-CANONICALIZED */
block|}
name|krb5_key_usage
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_key_usage
name|krb5_keyusage
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|krb5_salttype
block|{
name|KRB5_PW_SALT
init|=
name|KRB5_PADATA_PW_SALT
block|,
name|KRB5_AFS3_SALT
init|=
name|KRB5_PADATA_AFS3_SALT
block|}
name|krb5_salttype
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_salt
block|{
name|krb5_salttype
name|salttype
decl_stmt|;
name|krb5_data
name|saltvalue
decl_stmt|;
block|}
name|krb5_salt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ETYPE_INFO
name|krb5_preauthinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|krb5_preauthtype
name|type
decl_stmt|;
name|krb5_preauthinfo
name|info
decl_stmt|;
comment|/* list of preauthinfo for this type */
block|}
name|krb5_preauthdata_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_preauthdata
block|{
name|unsigned
name|len
decl_stmt|;
name|krb5_preauthdata_entry
modifier|*
name|val
decl_stmt|;
block|}
name|krb5_preauthdata
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|krb5_address_type
block|{
name|KRB5_ADDRESS_INET
init|=
literal|2
block|,
name|KRB5_ADDRESS_NETBIOS
init|=
literal|20
block|,
name|KRB5_ADDRESS_INET6
init|=
literal|24
block|,
name|KRB5_ADDRESS_ADDRPORT
init|=
literal|256
block|,
name|KRB5_ADDRESS_IPPORT
init|=
literal|257
block|}
name|krb5_address_type
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|AP_OPTS_USE_SESSION_KEY
init|=
literal|1
block|,
name|AP_OPTS_MUTUAL_REQUIRED
init|=
literal|2
block|,
name|AP_OPTS_USE_SUBKEY
init|=
literal|4
comment|/* library internal */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|HostAddress
name|krb5_address
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HostAddresses
name|krb5_addresses
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_enctype
name|krb5_keytype
typedef|;
end_typedef

begin_enum
enum|enum
name|krb5_keytype_old
block|{
name|KEYTYPE_NULL
init|=
name|ETYPE_NULL
block|,
name|KEYTYPE_DES
init|=
name|ETYPE_DES_CBC_CRC
block|,
name|KEYTYPE_DES3
init|=
name|ETYPE_OLD_DES3_CBC_SHA1
block|,
name|KEYTYPE_AES128
init|=
name|ETYPE_AES128_CTS_HMAC_SHA1_96
block|,
name|KEYTYPE_AES256
init|=
name|ETYPE_AES256_CTS_HMAC_SHA1_96
block|,
name|KEYTYPE_ARCFOUR
init|=
name|ETYPE_ARCFOUR_HMAC_MD5
block|,
name|KEYTYPE_ARCFOUR_56
init|=
name|ETYPE_ARCFOUR_HMAC_MD5_56
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|EncryptionKey
name|krb5_keyblock
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|AP_REQ
name|krb5_ap_req
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_cc_ops
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|KRB5_USE_PATH_TOKENS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_USE_PATH_TOKENS
end_ifdef

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCFILE_ROOT
value|"%{TEMP}/krb5cc_"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCFILE_ROOT
value|"/tmp/krb5cc_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB5_DEFAULT_CCROOT
value|"FILE:" KRB5_DEFAULT_CCFILE_ROOT
end_define

begin_define
define|#
directive|define
name|KRB5_ACCEPT_NULL_ADDRESSES
parameter_list|(
name|C
parameter_list|)
define|\
value|krb5_config_get_bool_default((C), NULL, TRUE, 			 \ 				 "libdefaults", "accept_null_addresses", \ 				 NULL)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|krb5_cc_cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_cccol_cursor_data
modifier|*
name|krb5_cccol_cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_ccache_data
block|{
specifier|const
name|struct
name|krb5_cc_ops
modifier|*
name|ops
decl_stmt|;
name|krb5_data
name|data
decl_stmt|;
block|}
name|krb5_ccache_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_ccache_data
modifier|*
name|krb5_ccache
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_context_data
modifier|*
name|krb5_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Realm
name|krb5_realm
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|krb5_const_realm
typedef|;
end_typedef

begin_comment
comment|/* stupid language */
end_comment

begin_define
define|#
directive|define
name|krb5_realm_length
parameter_list|(
name|r
parameter_list|)
value|strlen(r)
end_define

begin_define
define|#
directive|define
name|krb5_realm_data
parameter_list|(
name|r
parameter_list|)
value|(r)
end_define

begin_typedef
typedef|typedef
name|Principal
name|krb5_principal_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Principal
modifier|*
name|krb5_principal
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|Principal
modifier|*
name|krb5_const_principal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Principals
modifier|*
name|krb5_principals
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|time_t
name|krb5_deltat
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|time_t
name|krb5_timestamp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_times
block|{
name|krb5_timestamp
name|authtime
decl_stmt|;
name|krb5_timestamp
name|starttime
decl_stmt|;
name|krb5_timestamp
name|endtime
decl_stmt|;
name|krb5_timestamp
name|renew_till
decl_stmt|;
block|}
name|krb5_times
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|TicketFlags
name|b
decl_stmt|;
name|krb5_flags
name|i
decl_stmt|;
block|}
name|krb5_ticket_flags
typedef|;
end_typedef

begin_comment
comment|/* options for krb5_get_in_tkt() */
end_comment

begin_define
define|#
directive|define
name|KDC_OPT_FORWARDABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_FORWARDED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_PROXIABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_PROXY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_ALLOW_POSTDATE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_POSTDATED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_RENEWABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_REQUEST_ANONYMOUS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_DISABLE_TRANSITED_CHECK
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_RENEWABLE_OK
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_ENC_TKT_IN_SKEY
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_RENEW
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|KDC_OPT_VALIDATE
value|(1<< 31)
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|KDCOptions
name|b
decl_stmt|;
name|krb5_flags
name|i
decl_stmt|;
block|}
name|krb5_kdc_flags
typedef|;
end_typedef

begin_comment
comment|/* flags for krb5_verify_ap_req */
end_comment

begin_define
define|#
directive|define
name|KRB5_VERIFY_AP_REQ_IGNORE_INVALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_CACHED
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_USER_USER
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_EXPIRED_OK
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_NO_STORE
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_FORWARDABLE
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_NO_TRANSIT_CHECK
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_CONSTRAINED_DELEGATION
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|KRB5_GC_CANONICALIZE
value|(1U<< 7)
end_define

begin_comment
comment|/* constants for compare_creds (and cc_retrieve_cred) */
end_comment

begin_define
define|#
directive|define
name|KRB5_TC_DONT_MATCH_REALM
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_KEYTYPE
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_KTYPE
value|KRB5_TC_MATCH_KEYTYPE
end_define

begin_comment
comment|/* MIT name */
end_comment

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_SRV_NAMEONLY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_FLAGS_EXACT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_FLAGS
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_TIMES_EXACT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_TIMES
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_AUTHDATA
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_2ND_TKT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|KRB5_TC_MATCH_IS_SKEY
value|(1<< 22)
end_define

begin_comment
comment|/* constants for get_flags and set_flags */
end_comment

begin_define
define|#
directive|define
name|KRB5_TC_OPENCLOSE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KRB5_TC_NOTICKET
value|0x00000002
end_define

begin_typedef
typedef|typedef
name|AuthorizationData
name|krb5_authdata
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|KRB_ERROR
name|krb5_error
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_creds
block|{
name|krb5_principal
name|client
decl_stmt|;
name|krb5_principal
name|server
decl_stmt|;
name|krb5_keyblock
name|session
decl_stmt|;
name|krb5_times
name|times
decl_stmt|;
name|krb5_data
name|ticket
decl_stmt|;
name|krb5_data
name|second_ticket
decl_stmt|;
name|krb5_authdata
name|authdata
decl_stmt|;
name|krb5_addresses
name|addresses
decl_stmt|;
name|krb5_ticket_flags
name|flags
decl_stmt|;
block|}
name|krb5_creds
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|krb5_cc_cache_cursor_data
modifier|*
name|krb5_cc_cache_cursor
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_CC_OPS_VERSION
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|krb5_cc_ops
block|{
name|int
name|version
decl_stmt|;
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
specifier|const
name|char
modifier|*
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_name
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|resolve
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|gen_new
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|init
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_principal
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|close
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|store
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_creds
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|retrieve
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_flags
parameter_list|,
specifier|const
name|krb5_creds
modifier|*
parameter_list|,
name|krb5_creds
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_princ
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_principal
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_first
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_cc_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_next
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_cc_cursor
modifier|*
parameter_list|,
name|krb5_creds
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|end_get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_cc_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|remove_cred
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_flags
parameter_list|,
name|krb5_creds
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|set_flags
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_flags
parameter_list|)
function_decl|;
name|int
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_version
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_cache_first
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_cc_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_cache_next
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_cc_cursor
parameter_list|,
name|krb5_ccache
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|end_cache_get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_cc_cursor
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|move
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_default_name
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|set_default
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|lastchange
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_timestamp
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|set_kdc_offset
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_deltat
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_kdc_offset
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_ccache
parameter_list|,
name|krb5_deltat
modifier|*
parameter_list|)
function_decl|;
block|}
name|krb5_cc_ops
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_log_facility
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|krb5_config_binding
block|{
enum|enum
block|{
name|krb5_config_string
block|,
name|krb5_config_list
block|}
name|type
enum|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|krb5_config_binding
modifier|*
name|next
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|struct
name|krb5_config_binding
modifier|*
name|list
decl_stmt|;
name|void
modifier|*
name|generic
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|krb5_config_binding
name|krb5_config_binding
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_config_binding
name|krb5_config_section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_ticket
block|{
name|EncTicketPart
name|ticket
decl_stmt|;
name|krb5_principal
name|client
decl_stmt|;
name|krb5_principal
name|server
decl_stmt|;
block|}
name|krb5_ticket
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Authenticator
name|krb5_authenticator_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_authenticator_data
modifier|*
name|krb5_authenticator
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_rcache_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_rcache_data
modifier|*
name|krb5_rcache
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Authenticator
name|krb5_donot_replay
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_STORAGE_HOST_BYTEORDER
value|0x01
end_define

begin_comment
comment|/* old */
end_comment

begin_define
define|#
directive|define
name|KRB5_STORAGE_PRINCIPAL_WRONG_NUM_COMPONENTS
value|0x02
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_PRINCIPAL_NO_NAME_TYPE
value|0x04
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_KEYBLOCK_KEYTYPE_TWICE
value|0x08
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_BYTEORDER_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_BYTEORDER_BE
value|0x00
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|KRB5_STORAGE_BYTEORDER_LE
value|0x20
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_BYTEORDER_HOST
value|0x40
end_define

begin_define
define|#
directive|define
name|KRB5_STORAGE_CREDS_FLAGS_WRONG_BITORDER
value|0x80
end_define

begin_struct_decl
struct_decl|struct
name|krb5_storage_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_storage_data
name|krb5_storage
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_keytab_entry
block|{
name|krb5_principal
name|principal
decl_stmt|;
name|krb5_kvno
name|vno
decl_stmt|;
name|krb5_keyblock
name|keyblock
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|krb5_principals
name|aliases
decl_stmt|;
block|}
name|krb5_keytab_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_kt_cursor
block|{
name|int
name|fd
decl_stmt|;
name|krb5_storage
modifier|*
name|sp
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|krb5_kt_cursor
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_keytab_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_keytab_data
modifier|*
name|krb5_keytab
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_KT_PREFIX_MAX_LEN
value|30
end_define

begin_struct
struct|struct
name|krb5_keytab_data
block|{
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|resolve
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_keytab
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get_name
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|close
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_const_principal
parameter_list|,
name|krb5_kvno
parameter_list|,
name|krb5_enctype
parameter_list|,
name|krb5_keytab_entry
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|start_seq_get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_kt_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|next_entry
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_keytab_entry
modifier|*
parameter_list|,
name|krb5_kt_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|end_seq_get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_kt_cursor
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|add
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_keytab_entry
modifier|*
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|remove
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|krb5_keytab_entry
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
decl_stmt|;
name|int32_t
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|krb5_keytab_data
name|krb5_kt_ops
typedef|;
end_typedef

begin_struct
struct|struct
name|krb5_keytab_key_proc_args
block|{
name|krb5_keytab
name|keytab
decl_stmt|;
name|krb5_principal
name|principal
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|krb5_keytab_key_proc_args
name|krb5_keytab_key_proc_args
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_replay_data
block|{
name|krb5_timestamp
name|timestamp
decl_stmt|;
name|int32_t
name|usec
decl_stmt|;
name|uint32_t
name|seq
decl_stmt|;
block|}
name|krb5_replay_data
typedef|;
end_typedef

begin_comment
comment|/* flags for krb5_auth_con_setflags */
end_comment

begin_enum
enum|enum
block|{
name|KRB5_AUTH_CONTEXT_DO_TIME
init|=
literal|1
block|,
name|KRB5_AUTH_CONTEXT_RET_TIME
init|=
literal|2
block|,
name|KRB5_AUTH_CONTEXT_DO_SEQUENCE
init|=
literal|4
block|,
name|KRB5_AUTH_CONTEXT_RET_SEQUENCE
init|=
literal|8
block|,
name|KRB5_AUTH_CONTEXT_PERMIT_ALL
init|=
literal|16
block|,
name|KRB5_AUTH_CONTEXT_USE_SUBKEY
init|=
literal|32
block|,
name|KRB5_AUTH_CONTEXT_CLEAR_FORWARDED_CRED
init|=
literal|64
block|}
enum|;
end_enum

begin_comment
comment|/* flags for krb5_auth_con_genaddrs */
end_comment

begin_enum
enum|enum
block|{
name|KRB5_AUTH_CONTEXT_GENERATE_LOCAL_ADDR
init|=
literal|1
block|,
name|KRB5_AUTH_CONTEXT_GENERATE_LOCAL_FULL_ADDR
init|=
literal|3
block|,
name|KRB5_AUTH_CONTEXT_GENERATE_REMOTE_ADDR
init|=
literal|4
block|,
name|KRB5_AUTH_CONTEXT_GENERATE_REMOTE_FULL_ADDR
init|=
literal|12
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|krb5_auth_context_data
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|krb5_address
modifier|*
name|local_address
decl_stmt|;
name|krb5_address
modifier|*
name|remote_address
decl_stmt|;
name|int16_t
name|local_port
decl_stmt|;
name|int16_t
name|remote_port
decl_stmt|;
name|krb5_keyblock
modifier|*
name|keyblock
decl_stmt|;
name|krb5_keyblock
modifier|*
name|local_subkey
decl_stmt|;
name|krb5_keyblock
modifier|*
name|remote_subkey
decl_stmt|;
name|uint32_t
name|local_seqnumber
decl_stmt|;
name|uint32_t
name|remote_seqnumber
decl_stmt|;
name|krb5_authenticator
name|authenticator
decl_stmt|;
name|krb5_pointer
name|i_vector
decl_stmt|;
name|krb5_rcache
name|rcache
decl_stmt|;
name|krb5_keytype
name|keytype
decl_stmt|;
comment|/* Â¿requested key type ? */
name|krb5_cksumtype
name|cksumtype
decl_stmt|;
comment|/* Â¡requested checksum type! */
block|}
name|krb5_auth_context_data
operator|,
typedef|*
name|krb5_auth_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|KDC_REP
name|kdc_rep
decl_stmt|;
name|EncKDCRepPart
name|enc_part
decl_stmt|;
name|KRB_ERROR
name|error
decl_stmt|;
block|}
name|krb5_kdc_rep
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|heimdal_version
decl_stmt|,
modifier|*
name|heimdal_long_version
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_log_log_func_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_log_close_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5_log_facility
block|{
name|char
modifier|*
name|program
decl_stmt|;
name|int
name|len
decl_stmt|;
name|struct
name|facility
modifier|*
name|val
decl_stmt|;
block|}
name|krb5_log_facility
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EncAPRepPart
name|krb5_ap_rep_enc_part
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_RECVAUTH_IGNORE_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_SENDAUTH_VERSION
value|"KRB5_SENDAUTH_V1.0"
end_define

begin_define
define|#
directive|define
name|KRB5_TGS_NAME_SIZE
value|(6)
end_define

begin_define
define|#
directive|define
name|KRB5_TGS_NAME
value|("krbtgt")
end_define

begin_define
define|#
directive|define
name|KRB5_WELLKNOWN_NAME
value|("WELLKNOWN")
end_define

begin_define
define|#
directive|define
name|KRB5_ANON_NAME
value|("ANONYMOUS")
end_define

begin_define
define|#
directive|define
name|KRB5_DIGEST_NAME
value|("digest")
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|KRB5_PROMPT_TYPE_PASSWORD
init|=
literal|0x1
block|,
name|KRB5_PROMPT_TYPE_NEW_PASSWORD
init|=
literal|0x2
block|,
name|KRB5_PROMPT_TYPE_NEW_PASSWORD_AGAIN
init|=
literal|0x3
block|,
name|KRB5_PROMPT_TYPE_PREAUTH
init|=
literal|0x4
block|,
name|KRB5_PROMPT_TYPE_INFO
init|=
literal|0x5
block|}
name|krb5_prompt_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_prompt
block|{
specifier|const
name|char
modifier|*
name|prompt
decl_stmt|;
name|int
name|hidden
decl_stmt|;
name|krb5_data
modifier|*
name|reply
decl_stmt|;
name|krb5_prompt_type
name|type
decl_stmt|;
block|}
name|krb5_prompt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_prompter_fct
function_decl|)
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|void
modifier|*
comment|/*data*/
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*name*/
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*banner*/
parameter_list|,
name|int
comment|/*num_prompts*/
parameter_list|,
name|krb5_prompt
comment|/*prompts*/
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_key_proc
function_decl|)
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|krb5_enctype
comment|/*type*/
parameter_list|,
name|krb5_salt
comment|/*salt*/
parameter_list|,
name|krb5_const_pointer
comment|/*keyseed*/
parameter_list|,
name|krb5_keyblock
modifier|*
modifier|*
comment|/*key*/
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_decrypt_proc
function_decl|)
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|krb5_keyblock
modifier|*
comment|/*key*/
parameter_list|,
name|krb5_key_usage
comment|/*usage*/
parameter_list|,
name|krb5_const_pointer
comment|/*decrypt_arg*/
parameter_list|,
name|krb5_kdc_rep
modifier|*
comment|/*dec_rep*/
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_s2k_proc
function_decl|)
parameter_list|(
name|krb5_context
comment|/*context*/
parameter_list|,
name|krb5_enctype
comment|/*type*/
parameter_list|,
name|krb5_const_pointer
comment|/*keyseed*/
parameter_list|,
name|krb5_salt
comment|/*salt*/
parameter_list|,
name|krb5_data
modifier|*
comment|/*s2kparms*/
parameter_list|,
name|krb5_keyblock
modifier|*
modifier|*
comment|/*key*/
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|_krb5_get_init_creds_opt_private
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|_krb5_get_init_creds_opt
block|{
name|krb5_flags
name|flags
decl_stmt|;
name|krb5_deltat
name|tkt_life
decl_stmt|;
name|krb5_deltat
name|renew_life
decl_stmt|;
name|int
name|forwardable
decl_stmt|;
name|int
name|proxiable
decl_stmt|;
name|int
name|anonymous
decl_stmt|;
name|krb5_enctype
modifier|*
name|etype_list
decl_stmt|;
name|int
name|etype_list_length
decl_stmt|;
name|krb5_addresses
modifier|*
name|address_list
decl_stmt|;
comment|/* XXX the next three should not be used, as they may be        removed later */
name|krb5_preauthtype
modifier|*
name|preauth_list
decl_stmt|;
name|int
name|preauth_list_length
decl_stmt|;
name|krb5_data
modifier|*
name|salt
decl_stmt|;
name|struct
name|_krb5_get_init_creds_opt_private
modifier|*
name|opt_private
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_krb5_get_init_creds_opt
name|krb5_get_init_creds_opt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_TKT_LIFE
value|0x0001
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_RENEW_LIFE
value|0x0002
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_FORWARDABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_PROXIABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_ETYPE_LIST
value|0x0010
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_ADDRESS_LIST
value|0x0020
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_PREAUTH_LIST
value|0x0040
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_SALT
value|0x0080
end_define

begin_comment
comment|/* no supported */
end_comment

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_ANONYMOUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|KRB5_GET_INIT_CREDS_OPT_DISABLE_TRANSITED_CHECK
value|0x0200
end_define

begin_comment
comment|/* krb5_init_creds_step flags argument */
end_comment

begin_define
define|#
directive|define
name|KRB5_INIT_CREDS_STEP_FLAG_CONTINUE
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
name|_krb5_verify_init_creds_opt
block|{
name|krb5_flags
name|flags
decl_stmt|;
name|int
name|ap_req_nofail
decl_stmt|;
block|}
name|krb5_verify_init_creds_opt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_VERIFY_INIT_CREDS_OPT_AP_REQ_NOFAIL
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
name|krb5_verify_opt
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|krb5_ccache
name|ccache
decl_stmt|;
name|krb5_keytab
name|keytab
decl_stmt|;
name|krb5_boolean
name|secure
decl_stmt|;
specifier|const
name|char
modifier|*
name|service
decl_stmt|;
block|}
name|krb5_verify_opt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_VERIFY_LREALMS
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_VERIFY_NO_ADDRESSES
value|2
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_VERS_CHANGEPW
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_VERS_SETPW
value|0xff80
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_MALFORMED
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_HARDERROR
value|2
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_AUTHERROR
value|3
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_SOFTERROR
value|4
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_ACCESSDENIED
value|5
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_BAD_VERSION
value|6
end_define

begin_define
define|#
directive|define
name|KRB5_KPASSWD_INITIAL_FLAG_NEEDED
value|7
end_define

begin_define
define|#
directive|define
name|KPASSWD_PORT
value|464
end_define

begin_comment
comment|/* types for the new krbhst interface */
end_comment

begin_struct_decl
struct_decl|struct
name|krb5_krbhst_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|krb5_krbhst_data
modifier|*
name|krb5_krbhst_handle
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_KRBHST_KDC
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_KRBHST_ADMIN
value|2
end_define

begin_define
define|#
directive|define
name|KRB5_KRBHST_CHANGEPW
value|3
end_define

begin_define
define|#
directive|define
name|KRB5_KRBHST_KRB524
value|4
end_define

begin_define
define|#
directive|define
name|KRB5_KRBHST_KCA
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|krb5_krbhst_info
block|{
enum|enum
block|{
name|KRB5_KRBHST_UDP
block|,
name|KRB5_KRBHST_TCP
block|,
name|KRB5_KRBHST_HTTP
block|}
name|proto
enum|;
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|short
name|def_port
decl_stmt|;
name|struct
name|addrinfo
modifier|*
name|ai
decl_stmt|;
name|struct
name|krb5_krbhst_info
modifier|*
name|next
decl_stmt|;
name|char
name|hostname
index|[
literal|1
index|]
decl_stmt|;
comment|/* has to come last */
block|}
name|krb5_krbhst_info
typedef|;
end_typedef

begin_comment
comment|/* flags for krb5_krbhst_init_flags (and krb5_send_to_kdc_flags) */
end_comment

begin_enum
enum|enum
block|{
name|KRB5_KRBHST_FLAGS_MASTER
init|=
literal|1
block|,
name|KRB5_KRBHST_FLAGS_LARGE_MSG
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_send_to_kdc_func
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|void
modifier|*
parameter_list|,
name|krb5_krbhst_info
modifier|*
parameter_list|,
name|time_t
parameter_list|,
specifier|const
name|krb5_data
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** flags for krb5_parse_name_flags */
end_comment

begin_enum
enum|enum
block|{
name|KRB5_PRINCIPAL_PARSE_NO_REALM
init|=
literal|1
block|,
comment|/**< Require that there are no realm */
name|KRB5_PRINCIPAL_PARSE_REQUIRE_REALM
init|=
literal|2
block|,
comment|/**< Require a realm present */
name|KRB5_PRINCIPAL_PARSE_ENTERPRISE
init|=
literal|4
comment|/**< Parse as a NT-ENTERPRISE name */
block|}
enum|;
end_enum

begin_comment
comment|/** flags for krb5_unparse_name_flags */
end_comment

begin_enum
enum|enum
block|{
name|KRB5_PRINCIPAL_UNPARSE_SHORT
init|=
literal|1
block|,
comment|/**< No realm if it is the default realm */
name|KRB5_PRINCIPAL_UNPARSE_NO_REALM
init|=
literal|2
block|,
comment|/**< No realm */
name|KRB5_PRINCIPAL_UNPARSE_DISPLAY
init|=
literal|4
comment|/**< No quoting */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|struct
name|krb5_sendto_ctx_data
modifier|*
name|krb5_sendto_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_SENDTO_DONE
value|0
end_define

begin_define
define|#
directive|define
name|KRB5_SENDTO_RESTART
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_SENDTO_CONTINUE
value|2
end_define

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_sendto_ctx_func
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_sendto_ctx
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|krb5_data
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|krb5_plugin
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|krb5_plugin_type
block|{
name|PLUGIN_TYPE_DATA
init|=
literal|1
block|,
name|PLUGIN_TYPE_FUNC
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|credentials
struct_decl|;
end_struct_decl

begin_comment
comment|/* this is to keep the compiler happy */
end_comment

begin_struct_decl
struct_decl|struct
name|getargs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Semi private, not stable yet  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|krb5_crypto_iov
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* ignored */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_EMPTY
value|0
comment|/* OUT krb5_crypto_length(KRB5_CRYPTO_TYPE_HEADER) */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_HEADER
value|1
comment|/* IN and OUT */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_DATA
value|2
comment|/* IN */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_SIGN_ONLY
value|3
comment|/* (only for encryption) OUT krb5_crypto_length(KRB5_CRYPTO_TYPE_TRAILER) */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_PADDING
value|4
comment|/* OUT krb5_crypto_length(KRB5_CRYPTO_TYPE_TRAILER) */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_TRAILER
value|5
comment|/* OUT krb5_crypto_length(KRB5_CRYPTO_TYPE_CHECKSUM) */
define|#
directive|define
name|KRB5_CRYPTO_TYPE_CHECKSUM
value|6
name|krb5_data
name|data
decl_stmt|;
block|}
name|krb5_crypto_iov
typedef|;
end_typedef

begin_comment
comment|/* Glue for MIT */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|lr_type
decl_stmt|;
name|krb5_timestamp
name|value
decl_stmt|;
block|}
name|krb5_last_req_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|krb5_gic_process_last_req
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_last_req_entry
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|hx509_certs_data
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<krb5-protos.h>
end_include

begin_comment
comment|/* variables */
end_comment

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_config_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_defkeyname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_acc_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_fcc_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_mcc_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_kcm_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_akcm_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_cc_ops
name|krb5_scc_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_fkt_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_wrfkt_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_javakt_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_mkt_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_akf_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|krb5_kt_ops
name|krb5_any_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_api
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_memory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_kcm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_scc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KRB5_H__ */
end_comment

end_unit

