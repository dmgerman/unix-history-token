begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: portlist.h,v 1.2.84.2 2004/03/06 08:13:58 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
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

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_portlist_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_portlist_t
modifier|*
modifier|*
name|portlistp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a port list.  *   * Requires:  *	'mctx' to be valid.  *	'portlistp' to be non NULL and '*portlistp' to be NULL;  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_portlist_add
parameter_list|(
name|dns_portlist_t
modifier|*
name|portlist
parameter_list|,
name|int
name|af
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add the given<port,af> tuple to the portlist.  *  * Requires:  *	'portlist' to be valid.  *	'af' to be AF_INET or AF_INET6  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_portlist_remove
parameter_list|(
name|dns_portlist_t
modifier|*
name|portlist
parameter_list|,
name|int
name|af
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Remove the given<port,af> tuple to the portlist.  *  * Requires:  *	'portlist' to be valid.  *	'af' to be AF_INET or AF_INET6  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_portlist_match
parameter_list|(
name|dns_portlist_t
modifier|*
name|portlist
parameter_list|,
name|int
name|af
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the given<port,af> tuple to the portlist.  *  * Requires:  *	'portlist' to be valid.  *	'af' to be AF_INET or AF_INET6  *  * Returns  * 	ISC_TRUE if the tuple is found, ISC_FALSE otherwise.  */
end_comment

begin_function_decl
name|void
name|dns_portlist_attach
parameter_list|(
name|dns_portlist_t
modifier|*
name|portlist
parameter_list|,
name|dns_portlist_t
modifier|*
modifier|*
name|portlistp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to a port list.  *  * Requires:  *	'portlist' to be valid.  *	'portlistp' to be non NULL and '*portlistp' to be NULL;  */
end_comment

begin_function_decl
name|void
name|dns_portlist_detach
parameter_list|(
name|dns_portlist_t
modifier|*
modifier|*
name|portlistp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from a port list.  *  * Requires:  *	'*portlistp' to be valid.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

end_unit

