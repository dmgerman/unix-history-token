begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * X.509v3 certificate parsing and processing  * Copyright (c) 2006-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X509V3_H
end_ifndef

begin_define
define|#
directive|define
name|X509V3_H
end_define

begin_include
include|#
directive|include
file|"asn1.h"
end_include

begin_struct
struct|struct
name|x509_algorithm_identifier
block|{
name|struct
name|asn1_oid
name|oid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x509_name_attr
block|{
enum|enum
name|x509_name_attr_type
block|{
name|X509_NAME_ATTR_NOT_USED
block|,
name|X509_NAME_ATTR_DC
block|,
name|X509_NAME_ATTR_CN
block|,
name|X509_NAME_ATTR_C
block|,
name|X509_NAME_ATTR_L
block|,
name|X509_NAME_ATTR_ST
block|,
name|X509_NAME_ATTR_O
block|,
name|X509_NAME_ATTR_OU
block|}
name|type
enum|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|X509_MAX_NAME_ATTRIBUTES
value|20
end_define

begin_struct
struct|struct
name|x509_name
block|{
name|struct
name|x509_name_attr
name|attr
index|[
name|X509_MAX_NAME_ATTRIBUTES
index|]
decl_stmt|;
name|size_t
name|num_attr
decl_stmt|;
name|char
modifier|*
name|email
decl_stmt|;
comment|/* emailAddress */
comment|/* from alternative name extension */
name|char
modifier|*
name|alt_email
decl_stmt|;
comment|/* rfc822Name */
name|char
modifier|*
name|dns
decl_stmt|;
comment|/* dNSName */
name|char
modifier|*
name|uri
decl_stmt|;
comment|/* uniformResourceIdentifier */
name|u8
modifier|*
name|ip
decl_stmt|;
comment|/* iPAddress */
name|size_t
name|ip_len
decl_stmt|;
comment|/* IPv4: 4, IPv6: 16 */
name|struct
name|asn1_oid
name|rid
decl_stmt|;
comment|/* registeredID */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x509_certificate
block|{
name|struct
name|x509_certificate
modifier|*
name|next
decl_stmt|;
enum|enum
block|{
name|X509_CERT_V1
init|=
literal|0
block|,
name|X509_CERT_V2
init|=
literal|1
block|,
name|X509_CERT_V3
init|=
literal|2
block|}
name|version
enum|;
name|unsigned
name|long
name|serial_number
decl_stmt|;
name|struct
name|x509_algorithm_identifier
name|signature
decl_stmt|;
name|struct
name|x509_name
name|issuer
decl_stmt|;
name|struct
name|x509_name
name|subject
decl_stmt|;
name|os_time_t
name|not_before
decl_stmt|;
name|os_time_t
name|not_after
decl_stmt|;
name|struct
name|x509_algorithm_identifier
name|public_key_alg
decl_stmt|;
name|u8
modifier|*
name|public_key
decl_stmt|;
name|size_t
name|public_key_len
decl_stmt|;
name|struct
name|x509_algorithm_identifier
name|signature_alg
decl_stmt|;
name|u8
modifier|*
name|sign_value
decl_stmt|;
name|size_t
name|sign_value_len
decl_stmt|;
comment|/* Extensions */
name|unsigned
name|int
name|extensions_present
decl_stmt|;
define|#
directive|define
name|X509_EXT_BASIC_CONSTRAINTS
value|(1<< 0)
define|#
directive|define
name|X509_EXT_PATH_LEN_CONSTRAINT
value|(1<< 1)
define|#
directive|define
name|X509_EXT_KEY_USAGE
value|(1<< 2)
define|#
directive|define
name|X509_EXT_SUBJECT_ALT_NAME
value|(1<< 3)
define|#
directive|define
name|X509_EXT_ISSUER_ALT_NAME
value|(1<< 4)
comment|/* BasicConstraints */
name|int
name|ca
decl_stmt|;
comment|/* cA */
name|unsigned
name|long
name|path_len_constraint
decl_stmt|;
comment|/* pathLenConstraint */
comment|/* KeyUsage */
name|unsigned
name|long
name|key_usage
decl_stmt|;
define|#
directive|define
name|X509_KEY_USAGE_DIGITAL_SIGNATURE
value|(1<< 0)
define|#
directive|define
name|X509_KEY_USAGE_NON_REPUDIATION
value|(1<< 1)
define|#
directive|define
name|X509_KEY_USAGE_KEY_ENCIPHERMENT
value|(1<< 2)
define|#
directive|define
name|X509_KEY_USAGE_DATA_ENCIPHERMENT
value|(1<< 3)
define|#
directive|define
name|X509_KEY_USAGE_KEY_AGREEMENT
value|(1<< 4)
define|#
directive|define
name|X509_KEY_USAGE_KEY_CERT_SIGN
value|(1<< 5)
define|#
directive|define
name|X509_KEY_USAGE_CRL_SIGN
value|(1<< 6)
define|#
directive|define
name|X509_KEY_USAGE_ENCIPHER_ONLY
value|(1<< 7)
define|#
directive|define
name|X509_KEY_USAGE_DECIPHER_ONLY
value|(1<< 8)
comment|/* 	 * The DER format certificate follows struct x509_certificate. These 	 * pointers point to that buffer. 	 */
specifier|const
name|u8
modifier|*
name|cert_start
decl_stmt|;
name|size_t
name|cert_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|tbs_cert_start
decl_stmt|;
name|size_t
name|tbs_cert_len
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|X509_VALIDATE_OK
block|,
name|X509_VALIDATE_BAD_CERTIFICATE
block|,
name|X509_VALIDATE_UNSUPPORTED_CERTIFICATE
block|,
name|X509_VALIDATE_CERTIFICATE_REVOKED
block|,
name|X509_VALIDATE_CERTIFICATE_EXPIRED
block|,
name|X509_VALIDATE_CERTIFICATE_UNKNOWN
block|,
name|X509_VALIDATE_UNKNOWN_CA
block|}
enum|;
end_enum

begin_function_decl
name|void
name|x509_certificate_free
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|x509_certificate
modifier|*
name|x509_certificate_parse
parameter_list|(
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
name|x509_name_string
parameter_list|(
name|struct
name|x509_name
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x509_name_compare
parameter_list|(
name|struct
name|x509_name
modifier|*
name|a
parameter_list|,
name|struct
name|x509_name
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|x509_certificate_chain_free
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x509_certificate_check_signature
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|issuer
parameter_list|,
name|struct
name|x509_certificate
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x509_certificate_chain_validate
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|trusted
parameter_list|,
name|struct
name|x509_certificate
modifier|*
name|chain
parameter_list|,
name|int
modifier|*
name|reason
parameter_list|,
name|int
name|disable_time_checks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|x509_certificate
modifier|*
name|x509_certificate_get_subject
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|chain
parameter_list|,
name|struct
name|x509_name
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x509_certificate_self_signed
parameter_list|(
name|struct
name|x509_certificate
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* X509V3_H */
end_comment

end_unit

