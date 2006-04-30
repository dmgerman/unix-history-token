begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ssu.h,v 1.11.206.3 2004/03/08 09:04:39 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_SSU_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_SSU_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
define|#
directive|define
name|DNS_SSUMATCHTYPE_NAME
value|0
define|#
directive|define
name|DNS_SSUMATCHTYPE_SUBDOMAIN
value|1
define|#
directive|define
name|DNS_SSUMATCHTYPE_WILDCARD
value|2
define|#
directive|define
name|DNS_SSUMATCHTYPE_SELF
value|3
name|isc_result_t
name|dns_ssutable_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_ssutable_t
modifier|*
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Creates a table that will be used to store simple-secure-update rules.  *	Note: all locking must be provided by the client.  *  *	Requires:  *		'mctx' is a valid memory context  *		'table' is not NULL, and '*table' is NULL  *  *	Returns:  *		ISC_R_SUCCESS  *		ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_ssutable_attach
parameter_list|(
name|dns_ssutable_t
modifier|*
name|source
parameter_list|,
name|dns_ssutable_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Attach '*targetp' to 'source'.  *  *	Requires:  *		'source' is a valid SSU table  *		'targetp' points to a NULL dns_ssutable_t *.  *  *	Ensures:  *		*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_ssutable_detach
parameter_list|(
name|dns_ssutable_t
modifier|*
modifier|*
name|tablep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Detach '*tablep' from its simple-secure-update rule table.  *  *	Requires:  *		'tablep' points to a valid dns_ssutable_t  *  *	Ensures:  *		*tablep is NULL  *		If '*tablep' is the last reference to the SSU table, all  *			resources used by the table will be freed.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ssutable_addrule
parameter_list|(
name|dns_ssutable_t
modifier|*
name|table
parameter_list|,
name|isc_boolean_t
name|grant
parameter_list|,
name|dns_name_t
modifier|*
name|identity
parameter_list|,
name|unsigned
name|int
name|matchtype
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|ntypes
parameter_list|,
name|dns_rdatatype_t
modifier|*
name|types
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Adds a new rule to a simple-secure-update rule table.  The rule  *	either grants or denies update privileges of an identity (or set of  *	identities) to modify a name (or set of names) or certain types present  *	at that name.  *  *	Notes:  *		If 'matchtype' is SELF, this rule only matches if the name  *		to be updated matches the signing identity.  *  *		If 'ntypes' is 0, this rule applies to all types except  *		NS, SOA, RRSIG, and NSEC.  *  *		If 'types' includes ANY, this rule applies to all types  *		except NSEC.  *  *	Requires:  *		'table' is a valid SSU table  *		'identity' is a valid absolute name  *		'matchtype' must be one of the defined constants.  *		'name' is a valid absolute name  *		If 'ntypes'> 0, 'types' must not be NULL  *  *	Returns:  *		ISC_R_SUCCESS  *		ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_ssutable_checkrules
parameter_list|(
name|dns_ssutable_t
modifier|*
name|table
parameter_list|,
name|dns_name_t
modifier|*
name|signer
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Checks that the attempted update of (name, type) is allowed according  *	to the rules specified in the simple-secure-update rule table.  If  *	no rules are matched, access is denied.  If signer is NULL, access  *	is denied.  *  *	Requires:  *		'table' is a valid SSU table  *		'signer' is NULL or a valid absolute name  *		'name' is a valid absolute name  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_ssurule_isgrant
parameter_list|(
specifier|const
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_name_t
modifier|*
name|dns_ssurule_identity
parameter_list|(
specifier|const
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dns_ssurule_matchtype
parameter_list|(
specifier|const
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_name_t
modifier|*
name|dns_ssurule_name
parameter_list|(
specifier|const
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dns_ssurule_types
parameter_list|(
specifier|const
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|,
name|dns_rdatatype_t
modifier|*
modifier|*
name|types
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Accessor functions to extract rule components  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ssutable_firstrule
parameter_list|(
specifier|const
name|dns_ssutable_t
modifier|*
name|table
parameter_list|,
name|dns_ssurule_t
modifier|*
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initiates a rule iterator.  There is no need to maintain any state.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ssutable_nextrule
parameter_list|(
name|dns_ssurule_t
modifier|*
name|rule
parameter_list|,
name|dns_ssurule_t
modifier|*
modifier|*
name|nextrule
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the next rule in the table.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_SSU_H */
end_comment

end_unit

