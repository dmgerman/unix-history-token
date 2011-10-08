begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dnsconf.h,v 1.3 2009-09-02 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IRS_DNSCONF_H
end_ifndef

begin_define
define|#
directive|define
name|IRS_DNSCONF_H
value|1
end_define

begin_comment
comment|/*! \file  *  * \brief  * The IRS dnsconf module parses an "advanced" configuration file related to  * the DNS library, such as trusted keys for DNSSEC validation, and creates  * the corresponding configuration objects for the DNS library modules.  *  * Notes:  * This module is very experimental and the configuration syntax or library  * interfaces may change in future versions.  Currently, only the  * 'trusted-keys' statement is supported, whose syntax is the same as the  * same name of statement for named.conf.  */
end_comment

begin_include
include|#
directive|include
file|<irs/types.h>
end_include

begin_comment
comment|/*%  * A compound structure storing DNS key information mainly for DNSSEC  * validation.  A dns_key_t object will be created using the 'keyname' and  * 'keydatabuf' members with the dst_key_fromdns() function.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|irs_dnsconf_dnskey
block|{
name|dns_name_t
modifier|*
name|keyname
decl_stmt|;
name|isc_buffer_t
modifier|*
name|keydatabuf
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|struct irs_dnsconf_dnskey
argument_list|)
name|link
expr_stmt|;
block|}
name|irs_dnsconf_dnskey_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|irs_dnsconf_dnskey_t
argument_list|)
name|irs_dnsconf_dnskeylist_t
expr_stmt|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|irs_dnsconf_load
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|irs_dnsconf_t
modifier|*
modifier|*
name|confp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Load the "advanced" DNS configuration file 'filename' in the "dns.conf"  * format, and create a new irs_dnsconf_t object from the configuration.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'filename' != NULL  *  *\li	'confp' != NULL&& '*confp' == NULL  */
end_comment

begin_function_decl
name|void
name|irs_dnsconf_destroy
parameter_list|(
name|irs_dnsconf_t
modifier|*
modifier|*
name|confp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy the dnsconf object.  *  * Requires:  *  *\li	'*confp' is a valid dnsconf object.  *  * Ensures:  *  *\li	*confp == NULL  */
end_comment

begin_function_decl
name|irs_dnsconf_dnskeylist_t
modifier|*
name|irs_dnsconf_gettrustedkeys
parameter_list|(
name|irs_dnsconf_t
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return a list of key information stored in 'conf'.  *  * Requires:  *  *\li	'conf' is a valid dnsconf object.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRS_DNSCONF_H */
end_comment

end_unit

