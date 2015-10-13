begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file x509.h  *  *  Based on XySSL: Copyright (C) 2006-2008  Christophe Devine  *  *  Copyright (C) 2009  Paul Bakker<polarssl_maintainer at polarssl dot org>  *  *  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *    * Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    * Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *    * Neither the names of PolarSSL or XySSL nor the names of its contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_X509_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_X509_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<apr_time.h>
end_include

begin_include
include|#
directive|include
file|"svn_x509.h"
end_include

begin_comment
comment|/*  * DER constants  */
end_comment

begin_define
define|#
directive|define
name|ASN1_BOOLEAN
value|0x01
end_define

begin_define
define|#
directive|define
name|ASN1_INTEGER
value|0x02
end_define

begin_define
define|#
directive|define
name|ASN1_BIT_STRING
value|0x03
end_define

begin_define
define|#
directive|define
name|ASN1_OCTET_STRING
value|0x04
end_define

begin_define
define|#
directive|define
name|ASN1_NULL
value|0x05
end_define

begin_define
define|#
directive|define
name|ASN1_OID
value|0x06
end_define

begin_define
define|#
directive|define
name|ASN1_UTF8_STRING
value|0x0C
end_define

begin_define
define|#
directive|define
name|ASN1_SEQUENCE
value|0x10
end_define

begin_define
define|#
directive|define
name|ASN1_SET
value|0x11
end_define

begin_define
define|#
directive|define
name|ASN1_PRINTABLE_STRING
value|0x13
end_define

begin_define
define|#
directive|define
name|ASN1_T61_STRING
value|0x14
end_define

begin_define
define|#
directive|define
name|ASN1_IA5_STRING
value|0x16
end_define

begin_define
define|#
directive|define
name|ASN1_UTC_TIME
value|0x17
end_define

begin_define
define|#
directive|define
name|ASN1_GENERALIZED_TIME
value|0x18
end_define

begin_define
define|#
directive|define
name|ASN1_UNIVERSAL_STRING
value|0x1C
end_define

begin_define
define|#
directive|define
name|ASN1_BMP_STRING
value|0x1E
end_define

begin_define
define|#
directive|define
name|ASN1_PRIMITIVE
value|0x00
end_define

begin_define
define|#
directive|define
name|ASN1_CONSTRUCTED
value|0x20
end_define

begin_define
define|#
directive|define
name|ASN1_CONTEXT_SPECIFIC
value|0x80
end_define

begin_comment
comment|/*  * various object identifiers  */
end_comment

begin_define
define|#
directive|define
name|OID_SUBJECT_ALT_NAME
value|"\x55\x1D\x11"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/*  * Structures for parsing X.509 certificates  */
typedef|typedef
struct|struct
name|_x509_buf
block|{
name|int
name|tag
decl_stmt|;
name|ptrdiff_t
name|len
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|p
decl_stmt|;
block|}
name|x509_buf
typedef|;
typedef|typedef
struct|struct
name|_x509_name
block|{
name|x509_buf
name|oid
decl_stmt|;
name|x509_buf
name|val
decl_stmt|;
name|struct
name|_x509_name
modifier|*
name|next
decl_stmt|;
block|}
name|x509_name
typedef|;
typedef|typedef
struct|struct
name|_x509_cert
block|{
name|int
name|version
decl_stmt|;
name|x509_buf
name|serial
decl_stmt|;
name|x509_buf
name|sig_oid1
decl_stmt|;
name|x509_name
name|issuer
decl_stmt|;
name|x509_name
name|subject
decl_stmt|;
name|apr_time_t
name|valid_from
decl_stmt|;
name|apr_time_t
name|valid_to
decl_stmt|;
name|x509_buf
name|issuer_id
decl_stmt|;
name|x509_buf
name|subject_id
decl_stmt|;
name|apr_array_header_t
modifier|*
name|dnsnames
decl_stmt|;
name|x509_buf
name|sig_oid2
decl_stmt|;
name|x509_buf
name|sig
decl_stmt|;
block|}
name|x509_cert
typedef|;
struct|struct
name|svn_x509_name_attr_t
block|{
name|unsigned
name|char
modifier|*
name|oid
decl_stmt|;
name|apr_size_t
name|oid_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|utf8_value
decl_stmt|;
block|}
struct|;
comment|/*  * Certificate info, returned from the parser  */
struct|struct
name|svn_x509_certinfo_t
block|{
name|apr_array_header_t
modifier|*
name|issuer
decl_stmt|;
name|apr_array_header_t
modifier|*
name|subject
decl_stmt|;
name|apr_time_t
name|valid_from
decl_stmt|;
name|apr_time_t
name|valid_to
decl_stmt|;
name|svn_checksum_t
modifier|*
name|digest
decl_stmt|;
name|apr_array_header_t
modifier|*
name|hostnames
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_SUBR_X509_H */
end_comment

end_unit

