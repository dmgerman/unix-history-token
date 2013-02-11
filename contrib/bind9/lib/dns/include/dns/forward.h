begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: forward.h,v 1.13 2009/09/02 23:48:02 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_FORWARD_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_FORWARD_H
value|1
end_define

begin_comment
comment|/*! \file dns/forward.h */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|dns_forwarders
block|{
name|isc_sockaddrlist_t
name|addrs
decl_stmt|;
name|dns_fwdpolicy_t
name|fwdpolicy
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|isc_result_t
name|dns_fwdtable_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_fwdtable_t
modifier|*
modifier|*
name|fwdtablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Creates a new forwarding table.  *  * Requires:  * \li 	mctx is a valid memory context.  * \li	fwdtablep != NULL&& *fwdtablep == NULL  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_fwdtable_add
parameter_list|(
name|dns_fwdtable_t
modifier|*
name|fwdtable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_sockaddrlist_t
modifier|*
name|addrs
parameter_list|,
name|dns_fwdpolicy_t
name|policy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Adds an entry to the forwarding table.  The entry associates  * a domain with a list of forwarders and a forwarding policy.  The  * addrs list is copied if not empty, so the caller should free its copy.  *  * Requires:  * \li	fwdtable is a valid forwarding table.  * \li	name is a valid name  * \li	addrs is a valid list of sockaddrs, which may be empty.  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_fwdtable_delete
parameter_list|(
name|dns_fwdtable_t
modifier|*
name|fwdtable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Removes an entry for 'name' from the forwarding table.  If an entry  * that exactly matches 'name' does not exist, ISC_R_NOTFOUND will be returned.  *  * Requires:  * \li	fwdtable is a valid forwarding table.  * \li	name is a valid name  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_fwdtable_find
parameter_list|(
name|dns_fwdtable_t
modifier|*
name|fwdtable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_forwarders_t
modifier|*
modifier|*
name|forwardersp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Finds a domain in the forwarding table.  The closest matching parent  * domain is returned.  *  * Requires:  * \li	fwdtable is a valid forwarding table.  * \li	name is a valid name  * \li	forwardersp != NULL&& *forwardersp == NULL  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_fwdtable_find2
parameter_list|(
name|dns_fwdtable_t
modifier|*
name|fwdtable
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_forwarders_t
modifier|*
modifier|*
name|forwardersp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Finds a domain in the forwarding table.  The closest matching parent  * domain is returned.  *  * Requires:  * \li	fwdtable is a valid forwarding table.  * \li	name is a valid name  * \li	forwardersp != NULL&& *forwardersp == NULL  * \li	foundname to be NULL or a valid name with buffer.  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|void
name|dns_fwdtable_destroy
parameter_list|(
name|dns_fwdtable_t
modifier|*
modifier|*
name|fwdtablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroys a forwarding table.  *  * Requires:  * \li	fwtablep != NULL&& *fwtablep != NULL  *  * Ensures:  * \li	all memory associated with the forwarding table is freed.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_FORWARD_H */
end_comment

end_unit

