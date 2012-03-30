begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 - 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_HX509_H
end_ifndef

begin_define
define|#
directive|define
name|HEIMDAL_HX509_H
value|1
end_define

begin_include
include|#
directive|include
file|<rfc2459_asn1.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|hx509_cert_attribute_data
modifier|*
name|hx509_cert_attribute
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_cert_data
modifier|*
name|hx509_cert
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_certs_data
modifier|*
name|hx509_certs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_context_data
modifier|*
name|hx509_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_crypto_data
modifier|*
name|hx509_crypto
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_lock_data
modifier|*
name|hx509_lock
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_name_data
modifier|*
name|hx509_name
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_private_key
modifier|*
name|hx509_private_key
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_private_key_ops
name|hx509_private_key_ops
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_validate_ctx_data
modifier|*
name|hx509_validate_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_verify_ctx_data
modifier|*
name|hx509_verify_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_revoke_ctx_data
modifier|*
name|hx509_revoke_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_query_data
name|hx509_query
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|hx509_cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_request_data
modifier|*
name|hx509_request
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_error_data
modifier|*
name|hx509_error
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_peer_info
modifier|*
name|hx509_peer_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_ca_tbs
modifier|*
name|hx509_ca_tbs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_env_data
modifier|*
name|hx509_env
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hx509_crl
modifier|*
name|hx509_crl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hx509_vprint_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
block|{
name|HX509_VHN_F_ALLOW_NO_MATCH
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HX509_VALIDATE_F_VALIDATE
init|=
literal|1
block|,
name|HX509_VALIDATE_F_VERBOSE
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HX509_CRYPTO_PADDING_PKCS7
init|=
literal|0
block|,
name|HX509_CRYPTO_PADDING_NONE
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HX509_KEY_FORMAT_GUESS
init|=
literal|0
block|,
name|HX509_KEY_FORMAT_DER
init|=
literal|1
block|,
name|HX509_KEY_FORMAT_WIN_BACKUPKEY
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|uint32_t
name|hx509_key_format_t
typedef|;
end_typedef

begin_struct
struct|struct
name|hx509_cert_attribute_data
block|{
name|heim_oid
name|oid
decl_stmt|;
name|heim_octet_string
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|HX509_PROMPT_TYPE_PASSWORD
init|=
literal|0x1
block|,
comment|/* password, hidden */
name|HX509_PROMPT_TYPE_QUESTION
init|=
literal|0x2
block|,
comment|/* question, not hidden */
name|HX509_PROMPT_TYPE_INFO
init|=
literal|0x4
comment|/* infomation, reply doesn't matter */
block|}
name|hx509_prompt_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hx509_prompt
block|{
specifier|const
name|char
modifier|*
name|prompt
decl_stmt|;
name|hx509_prompt_type
name|type
decl_stmt|;
name|heim_octet_string
name|reply
decl_stmt|;
block|}
name|hx509_prompt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hx509_prompter_fct
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|hx509_prompt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hx509_octet_string_list
block|{
name|size_t
name|len
decl_stmt|;
name|heim_octet_string
modifier|*
name|val
decl_stmt|;
block|}
name|hx509_octet_string_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hx509_pem_header
block|{
name|struct
name|hx509_pem_header
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|header
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|hx509_pem_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hx509_pem_read_func
function_decl|)
parameter_list|(
name|hx509_context
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|hx509_pem_header
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Options passed to hx509_query_match_option.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HX509_QUERY_OPTION_PRIVATE_KEY
init|=
literal|1
block|,
name|HX509_QUERY_OPTION_KU_ENCIPHERMENT
init|=
literal|2
block|,
name|HX509_QUERY_OPTION_KU_DIGITALSIGNATURE
init|=
literal|3
block|,
name|HX509_QUERY_OPTION_KU_KEYCERTSIGN
init|=
literal|4
block|,
name|HX509_QUERY_OPTION_END
init|=
literal|0xffff
block|}
name|hx509_query_option
typedef|;
end_typedef

begin_comment
comment|/* flags to hx509_certs_init */
end_comment

begin_define
define|#
directive|define
name|HX509_CERTS_CREATE
value|0x01
end_define

begin_define
define|#
directive|define
name|HX509_CERTS_UNPROTECT_ALL
value|0x02
end_define

begin_comment
comment|/* flags to hx509_set_error_string */
end_comment

begin_define
define|#
directive|define
name|HX509_ERROR_APPEND
value|0x01
end_define

begin_comment
comment|/* flags to hx509_cms_unenvelope */
end_comment

begin_define
define|#
directive|define
name|HX509_CMS_UE_DONT_REQUIRE_KU_ENCIPHERMENT
value|0x01
end_define

begin_define
define|#
directive|define
name|HX509_CMS_UE_ALLOW_WEAK
value|0x02
end_define

begin_comment
comment|/* flags to hx509_cms_envelope_1 */
end_comment

begin_define
define|#
directive|define
name|HX509_CMS_EV_NO_KU_CHECK
value|0x01
end_define

begin_define
define|#
directive|define
name|HX509_CMS_EV_ALLOW_WEAK
value|0x02
end_define

begin_define
define|#
directive|define
name|HX509_CMS_EV_ID_NAME
value|0x04
end_define

begin_comment
comment|/* flags to hx509_cms_verify_signed */
end_comment

begin_define
define|#
directive|define
name|HX509_CMS_VS_ALLOW_DATA_OID_MISMATCH
value|0x01
end_define

begin_define
define|#
directive|define
name|HX509_CMS_VS_NO_KU_CHECK
value|0x02
end_define

begin_define
define|#
directive|define
name|HX509_CMS_VS_ALLOW_ZERO_SIGNER
value|0x04
end_define

begin_define
define|#
directive|define
name|HX509_CMS_VS_NO_VALIDATE
value|0x08
end_define

begin_comment
comment|/* selectors passed to hx509_crypto_select and hx509_crypto_available */
end_comment

begin_define
define|#
directive|define
name|HX509_SELECT_ALL
value|0
end_define

begin_define
define|#
directive|define
name|HX509_SELECT_DIGEST
value|1
end_define

begin_define
define|#
directive|define
name|HX509_SELECT_PUBLIC_SIG
value|2
end_define

begin_define
define|#
directive|define
name|HX509_SELECT_PUBLIC_ENC
value|3
end_define

begin_define
define|#
directive|define
name|HX509_SELECT_SECRET_ENC
value|4
end_define

begin_comment
comment|/* flags to hx509_ca_tbs_set_template */
end_comment

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_SUBJECT
value|1
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_SERIAL
value|2
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_NOTBEFORE
value|4
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_NOTAFTER
value|8
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_SPKI
value|16
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_KU
value|32
end_define

begin_define
define|#
directive|define
name|HX509_CA_TEMPLATE_EKU
value|64
end_define

begin_comment
comment|/* flags hx509_cms_create_signed* */
end_comment

begin_define
define|#
directive|define
name|HX509_CMS_SIGNATURE_DETACHED
value|0x01
end_define

begin_define
define|#
directive|define
name|HX509_CMS_SIGNATURE_ID_NAME
value|0x02
end_define

begin_define
define|#
directive|define
name|HX509_CMS_SIGNATURE_NO_SIGNER
value|0x04
end_define

begin_define
define|#
directive|define
name|HX509_CMS_SIGNATURE_LEAF_ONLY
value|0x08
end_define

begin_define
define|#
directive|define
name|HX509_CMS_SIGNATURE_NO_CERTS
value|0x10
end_define

begin_comment
comment|/* hx509_verify_hostname nametype */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HX509_HN_HOSTNAME
init|=
literal|0
block|,
name|HX509_HN_DNSSRV
block|}
name|hx509_hostname_type
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<hx509-protos.h>
end_include

begin_include
include|#
directive|include
file|<hx509_err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_HX509_H */
end_comment

end_unit

