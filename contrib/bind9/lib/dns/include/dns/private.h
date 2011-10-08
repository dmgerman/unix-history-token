begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: private.h,v 1.3 2009-10-09 23:48:09 tbox Exp $ */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/db.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_PRIVATE_H
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_private_chains
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|,
name|dns_rdatatype_t
name|privatetype
parameter_list|,
name|isc_boolean_t
modifier|*
name|build_nsec
parameter_list|,
name|isc_boolean_t
modifier|*
name|build_nsec3
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Examine the NSEC, NSEC3PARAM and privatetype RRsets at the apex of the  * database to determine which of NSEC or NSEC3 chains we are currently  * maintaining.  In normal operations only one of NSEC or NSEC3 is being  * maintained but when we are transitiong between NSEC and NSEC3 we need  * to update both sets of chains.  If 'privatetype' is zero then the  * privatetype RRset will not be examined.  *  * Requires:  * \li	'db' is valid.  * \li	'version' is valid or NULL.  * \li	'build_nsec' is a pointer to a isc_boolean_t or NULL.  * \li	'build_nsec3' is a pointer to a isc_boolean_t or NULL.  *  * Returns:  * \li 	ISC_R_SUCCESS, 'build_nsec' and 'build_nsec3' will be valid.  * \li	other on error  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

