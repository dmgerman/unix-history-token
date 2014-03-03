begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009, 2014  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: resconf.h,v 1.3 2009/09/02 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IRS_RESCONF_H
end_ifndef

begin_define
define|#
directive|define
name|IRS_RESCONF_H
value|1
end_define

begin_comment
comment|/*! \file  *  * \brief  * The IRS resconf module parses the legacy "/etc/resolv.conf" file and  * creates the corresponding configuration objects for the DNS library  * modules.  */
end_comment

begin_include
include|#
directive|include
file|<irs/types.h>
end_include

begin_comment
comment|/*%  * A DNS search list specified in the 'domain' or 'search' statements  * in the "resolv.conf" file.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|irs_resconf_search
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|struct irs_resconf_search
argument_list|)
name|link
expr_stmt|;
block|}
name|irs_resconf_search_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|irs_resconf_search_t
argument_list|)
name|irs_resconf_searchlist_t
expr_stmt|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|irs_resconf_load
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
name|irs_resconf_t
modifier|*
modifier|*
name|confp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Load the resolver configuration file 'filename' in the "resolv.conf" format,  * and create a new irs_resconf_t object from the configuration.  If the file  * is not found ISC_R_FILENOTFOUND is returned with the structure initialized  * as if file contained only:  *  *	nameserver ::1  *	nameserver 127.0.0.1  *  * Notes:  *  *\li	Currently, only the following options are supported:  *	nameserver, domain, search, sortlist, ndots, and options.  *	In addition, 'sortlist' is not actually effective; it's parsed, but  *	the application cannot use the configuration.  *  * Returns:  * \li	ISC_R_SUCCESS on success  * \li  ISC_R_FILENOTFOUND if the file was not found. *confp will be valid.  * \li  other on error.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'filename' != NULL  *  *\li	'confp' != NULL&& '*confp' == NULL  */
end_comment

begin_function_decl
name|void
name|irs_resconf_destroy
parameter_list|(
name|irs_resconf_t
modifier|*
modifier|*
name|confp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy the resconf object.  *  * Requires:  *  *\li	'*confp' is a valid resconf object.  *  * Ensures:  *  *\li	*confp == NULL  */
end_comment

begin_function_decl
name|isc_sockaddrlist_t
modifier|*
name|irs_resconf_getnameservers
parameter_list|(
name|irs_resconf_t
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return a list of name server addresses stored in 'conf'.  *  * Requires:  *  *\li	'conf' is a valid resconf object.  */
end_comment

begin_function_decl
name|irs_resconf_searchlist_t
modifier|*
name|irs_resconf_getsearchlist
parameter_list|(
name|irs_resconf_t
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the search list stored in 'conf'.  *  * Requires:  *  *\li	'conf' is a valid resconf object.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|irs_resconf_getndots
parameter_list|(
name|irs_resconf_t
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the 'ndots' value stored in 'conf'.  *  * Requires:  *  *\li	'conf' is a valid resconf object.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRS_RESCONF_H */
end_comment

end_unit

