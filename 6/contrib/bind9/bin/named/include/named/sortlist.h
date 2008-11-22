begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sortlist.h,v 1.4.208.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_SORTLIST_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_SORTLIST_H
value|1
end_define

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

begin_comment
comment|/*  * Type for callback functions that rank addresses.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dns_addressorderfunc_t
function_decl|)
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|address
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Return value type for setup_sortlist.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NS_SORTLISTTYPE_NONE
block|,
name|NS_SORTLISTTYPE_1ELEMENT
block|,
name|NS_SORTLISTTYPE_2ELEMENT
block|}
name|ns_sortlisttype_t
typedef|;
end_typedef

begin_function_decl
name|ns_sortlisttype_t
name|ns_sortlist_setup
parameter_list|(
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
name|isc_netaddr_t
modifier|*
name|clientaddr
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the sortlist statement in 'acl' that applies to 'clientaddr', if any.  *  * If a 1-element sortlist item applies, return NS_SORTLISTTYPE_1ELEMENT and  * make '*argp' point to the matching subelement.  *  * If a 2-element sortlist item applies, return NS_SORTLISTTYPE_2ELEMENT and  * make '*argp' point to ACL that forms the second element.  *  * If no sortlist item applies, return NS_SORTLISTTYPE_NONE and set '*argp'  * to NULL.  */
end_comment

begin_function_decl
name|int
name|ns_sortlist_addrorder1
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|addr
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the sort order of 'addr' in 'arg', the matching element  * of a 1-element top-level sortlist statement.  */
end_comment

begin_function_decl
name|int
name|ns_sortlist_addrorder2
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|addr
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the sort order of 'addr' in 'arg', a topology-like  * ACL forming the second element in a 2-element top-level  * sortlist statement.  */
end_comment

begin_function_decl
name|void
name|ns_sortlist_byaddrsetup
parameter_list|(
name|dns_acl_t
modifier|*
name|sortlist_acl
parameter_list|,
name|isc_netaddr_t
modifier|*
name|client_addr
parameter_list|,
name|dns_addressorderfunc_t
modifier|*
name|orderp
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the sortlist statement in 'acl' that applies to 'clientaddr', if any.  * If a sortlist statement applies, return in '*orderp' a pointer to a function  * for ranking network addresses based on that sortlist statement, and in  * '*argp' an argument to pass to said function.  If no sortlist statement  * applies, set '*orderp' and '*argp' to NULL.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_SORTLIST_H */
end_comment

end_unit

