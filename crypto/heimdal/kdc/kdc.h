begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2003 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   *  * Copyright (c) 2005 Andrew Bartlett<abartlet@samba.org>  *   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/*   * $Id: kdc.h 21287 2007-06-25 14:09:03Z lha $   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KDC_H__
end_ifndef

begin_define
define|#
directive|define
name|__KDC_H__
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_enum
enum|enum
name|krb5_kdc_trpolicy
block|{
name|TRPOLICY_ALWAYS_CHECK
block|,
name|TRPOLICY_ALLOW_PER_PRINCIPAL
block|,
name|TRPOLICY_ALWAYS_HONOUR_REQUEST
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|krb5_kdc_configuration
block|{
name|krb5_boolean
name|require_preauth
decl_stmt|;
comment|/* require preauth for all principals */
name|time_t
name|kdc_warn_pwexpire
decl_stmt|;
comment|/* time before expiration to print a warning */
name|struct
name|HDB
modifier|*
modifier|*
name|db
decl_stmt|;
name|int
name|num_db
decl_stmt|;
name|krb5_boolean
name|encode_as_rep_as_tgs_rep
decl_stmt|;
comment|/* bug compatibility */
name|krb5_boolean
name|check_ticket_addresses
decl_stmt|;
name|krb5_boolean
name|allow_null_ticket_addresses
decl_stmt|;
name|krb5_boolean
name|allow_anonymous
decl_stmt|;
name|enum
name|krb5_kdc_trpolicy
name|trpolicy
decl_stmt|;
name|char
modifier|*
name|v4_realm
decl_stmt|;
name|krb5_boolean
name|enable_v4
decl_stmt|;
name|krb5_boolean
name|enable_v4_cross_realm
decl_stmt|;
name|krb5_boolean
name|enable_v4_per_principal
decl_stmt|;
name|krb5_boolean
name|enable_kaserver
decl_stmt|;
name|krb5_boolean
name|enable_524
decl_stmt|;
name|krb5_boolean
name|enable_pkinit
decl_stmt|;
name|krb5_boolean
name|pkinit_princ_in_cert
decl_stmt|;
name|char
modifier|*
name|pkinit_kdc_ocsp_file
decl_stmt|;
name|int
name|pkinit_dh_min_bits
decl_stmt|;
name|int
name|pkinit_require_binding
decl_stmt|;
name|krb5_log_facility
modifier|*
name|logf
decl_stmt|;
name|int
name|enable_digest
decl_stmt|;
name|int
name|digests_allowed
decl_stmt|;
name|size_t
name|max_datagram_reply_length
decl_stmt|;
name|int
name|enable_kx509
decl_stmt|;
specifier|const
name|char
modifier|*
name|kx509_template
decl_stmt|;
specifier|const
name|char
modifier|*
name|kx509_ca
decl_stmt|;
block|}
name|krb5_kdc_configuration
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<kdc-protos.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

