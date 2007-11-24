begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: listenlist.h,v 1.10.208.1 2004/03/06 10:21:24 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_LISTENLIST_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_LISTENLIST_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * "Listen lists", as in the "listen-on" configuration statement.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/net.h>
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
name|struct
name|ns_listenelt
name|ns_listenelt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_listenlist
name|ns_listenlist_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ns_listenelt
block|{
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|in_port_t
name|port
decl_stmt|;
name|dns_acl_t
modifier|*
name|acl
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|ns_listenelt_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ns_listenlist
block|{
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|int
name|refcount
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|ns_listenelt_t
argument_list|)
name|elts
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|isc_result_t
name|ns_listenelt_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|in_port_t
name|port
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
name|ns_listenelt_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a listen-on list element.  */
end_comment

begin_function_decl
name|void
name|ns_listenelt_destroy
parameter_list|(
name|ns_listenelt_t
modifier|*
name|elt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a listen-on list element.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_listenlist_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|ns_listenlist_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new, empty listen-on list.  */
end_comment

begin_function_decl
name|void
name|ns_listenlist_attach
parameter_list|(
name|ns_listenlist_t
modifier|*
name|source
parameter_list|,
name|ns_listenlist_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach '*target' to '*source'.  */
end_comment

begin_function_decl
name|void
name|ns_listenlist_detach
parameter_list|(
name|ns_listenlist_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach 'listp'.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_listenlist_default
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|in_port_t
name|port
parameter_list|,
name|isc_boolean_t
name|enabled
parameter_list|,
name|ns_listenlist_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a listen-on list with default contents, matching  * all addresses with port 'port' (if 'enabled' is ISC_TRUE),  * or no addresses (if 'enabled' is ISC_FALSE).  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_LISTENLIST_H */
end_comment

end_unit

