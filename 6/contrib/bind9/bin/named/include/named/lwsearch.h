begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lwsearch.h,v 1.4.208.1 2004/03/06 10:21:25 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_LWSEARCH_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_LWSEARCH_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
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
file|<named/types.h>
end_include

begin_comment
comment|/*  * Lightweight resolver search list types and routines.  *  * An ns_lwsearchlist_t holds a list of search path elements.  *  * An ns_lwsearchctx stores the state of search list during a lookup  * operation.  */
end_comment

begin_struct
struct|struct
name|ns_lwsearchlist
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|unsigned
name|int
name|refs
decl_stmt|;
name|dns_namelist_t
name|names
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ns_lwsearchctx
block|{
name|dns_name_t
modifier|*
name|relname
decl_stmt|;
name|dns_name_t
modifier|*
name|searchname
decl_stmt|;
name|unsigned
name|int
name|ndots
decl_stmt|;
name|ns_lwsearchlist_t
modifier|*
name|list
decl_stmt|;
name|isc_boolean_t
name|doneexact
decl_stmt|;
name|isc_boolean_t
name|exactfirst
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|isc_result_t
name|ns_lwsearchlist_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|ns_lwsearchlist_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an empty search list object.  */
end_comment

begin_function_decl
name|void
name|ns_lwsearchlist_attach
parameter_list|(
name|ns_lwsearchlist_t
modifier|*
name|source
parameter_list|,
name|ns_lwsearchlist_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to a search list object.  */
end_comment

begin_function_decl
name|void
name|ns_lwsearchlist_detach
parameter_list|(
name|ns_lwsearchlist_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from a search list object.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_lwsearchlist_append
parameter_list|(
name|ns_lwsearchlist_t
modifier|*
name|list
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append an element to a search list.  This creates a copy of the name.  */
end_comment

begin_function_decl
name|void
name|ns_lwsearchctx_init
parameter_list|(
name|ns_lwsearchctx_t
modifier|*
name|sctx
parameter_list|,
name|ns_lwsearchlist_t
modifier|*
name|list
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|ndots
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates a search list context structure.  */
end_comment

begin_function_decl
name|void
name|ns_lwsearchctx_first
parameter_list|(
name|ns_lwsearchctx_t
modifier|*
name|sctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Moves the search list context iterator to the first element, which  * is usually the exact name.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_lwsearchctx_next
parameter_list|(
name|ns_lwsearchctx_t
modifier|*
name|sctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Moves the search list context iterator to the next element.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_lwsearchctx_current
parameter_list|(
name|ns_lwsearchctx_t
modifier|*
name|sctx
parameter_list|,
name|dns_name_t
modifier|*
name|absname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Obtains the current name to be looked up.  This involves either  * concatenating the name with a search path element, making an  * exact name absolute, or doing nothing.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_LWSEARCH_H */
end_comment

end_unit

