begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: acl.h,v 1.20.52.5 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ACL_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ACL_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Address match list handling.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_aclelementtype_ipprefix
block|,
name|dns_aclelementtype_keyname
block|,
name|dns_aclelementtype_nestedacl
block|,
name|dns_aclelementtype_localhost
block|,
name|dns_aclelementtype_localnets
block|,
name|dns_aclelementtype_any
block|}
name|dns_aclelemettype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_aclipprefix
name|dns_aclipprefix_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_aclipprefix
block|{
name|isc_netaddr_t
name|address
decl_stmt|;
comment|/* IP4/IP6 */
name|unsigned
name|int
name|prefixlen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_aclelement
block|{
name|dns_aclelemettype_t
name|type
decl_stmt|;
name|isc_boolean_t
name|negative
decl_stmt|;
union|union
block|{
name|dns_aclipprefix_t
name|ip_prefix
decl_stmt|;
name|dns_name_t
name|keyname
decl_stmt|;
name|dns_acl_t
modifier|*
name|nestedacl
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_acl
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_refcount_t
name|refcount
decl_stmt|;
name|dns_aclelement_t
modifier|*
name|elements
decl_stmt|;
name|unsigned
name|int
name|alloc
decl_stmt|;
comment|/* Elements allocated */
name|unsigned
name|int
name|length
decl_stmt|;
comment|/* Elements initialized */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Temporary use only */
name|ISC_LINK
argument_list|(
argument|dns_acl_t
argument_list|)
name|nextincache
expr_stmt|;
comment|/* Ditto */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_aclenv
block|{
name|dns_acl_t
modifier|*
name|localhost
decl_stmt|;
name|dns_acl_t
modifier|*
name|localnets
decl_stmt|;
name|isc_boolean_t
name|match_mapped
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_ACL_MAGIC
value|ISC_MAGIC('D','a','c','l')
end_define

begin_define
define|#
directive|define
name|DNS_ACL_VALID
parameter_list|(
name|a
parameter_list|)
value|ISC_MAGIC_VALID(a, DNS_ACL_MAGIC)
end_define

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_acl_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|int
name|n
parameter_list|,
name|dns_acl_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new ACL with room for 'n' elements.  * The elements are uninitialized and the length is 0.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acl_appendelement
parameter_list|(
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
name|elt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append an element to an existing ACL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acl_any
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_acl_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new ACL that matches everything.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acl_none
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_acl_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new ACL that matches nothing.  */
end_comment

begin_function_decl
name|void
name|dns_acl_attach
parameter_list|(
name|dns_acl_t
modifier|*
name|source
parameter_list|,
name|dns_acl_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_acl_detach
parameter_list|(
name|dns_acl_t
modifier|*
modifier|*
name|aclp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dns_aclelement_equal
parameter_list|(
specifier|const
name|dns_aclelement_t
modifier|*
name|ea
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
name|eb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dns_acl_equal
parameter_list|(
specifier|const
name|dns_acl_t
modifier|*
name|a
parameter_list|,
specifier|const
name|dns_acl_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dns_acl_isinsecure
parameter_list|(
specifier|const
name|dns_acl_t
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return ISC_TRUE iff the acl 'a' is considered insecure, that is,  * if it contains IP addresses other than those of the local host.  * This is intended for applications such as printing warning   * messages for suspect ACLs; it is not intended for making access  * control decisions.  We make no guarantee that an ACL for which  * this function returns ISC_FALSE is safe.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_aclenv_init
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_aclenv_t
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_aclenv_copy
parameter_list|(
name|dns_aclenv_t
modifier|*
name|t
parameter_list|,
name|dns_aclenv_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_aclenv_destroy
parameter_list|(
name|dns_aclenv_t
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_acl_match
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|reqaddr
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|reqsigner
parameter_list|,
specifier|const
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
specifier|const
name|dns_aclenv_t
modifier|*
name|env
parameter_list|,
name|int
modifier|*
name|match
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
modifier|*
name|matchelt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * General, low-level ACL matching.  This is expected to  * be useful even for weird stuff like the topology and sortlist statements.  *  * Match the address 'reqaddr', and optionally the key name 'reqsigner',  * against 'acl'.  'reqsigner' may be NULL.  *  * If there is a positive match, '*match' will be set to a positive value  * indicating the distance from the beginning of the list.  *  * If there is a negative match, '*match' will be set to a negative value  * whose absolute value indicates the distance from the beginning of  * the list.  *  * If there is a match (either positive or negative) and 'matchelt' is  * non-NULL, *matchelt will be attached to the primitive  * (non-indirect) address match list element that matched.  *  * If there is no match, *match will be set to zero.  *  * Returns:  *	ISC_R_SUCCESS		Always succeeds.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_aclelement_match
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|reqaddr
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|reqsigner
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
name|e
parameter_list|,
specifier|const
name|dns_aclenv_t
modifier|*
name|env
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
modifier|*
name|matchelt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like dns_acl_match, but matches against the single ACL element 'e'  * rather than a complete list and returns ISC_TRUE iff it matched.  * To determine whether the match was prositive or negative, the   * caller should examine e->negative.  Since the element 'e' may be  * a reference to a named ACL or a nested ACL, the matching element  * returned through 'matchelt' is not necessarily 'e' itself.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acl_elementmatch
parameter_list|(
specifier|const
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
name|elt
parameter_list|,
specifier|const
name|dns_aclelement_t
modifier|*
modifier|*
name|matchelt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for an ACL element in 'acl' which is exactly the same as 'elt'.  * If there is one, and 'matchelt' is non NULL, then '*matchelt' will point  * to the entry.  *  * This function is intended to be used for avoiding duplicated ACL entries  * before adding an entry.  *  * Returns:  *	ISC_R_SUCCESS		Match succeeds.  *	ISC_R_NOTFOUND		Match fails.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ACL_H */
end_comment

end_unit

