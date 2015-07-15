begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008, 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: portset.h,v 1.6 2009/06/25 05:28:34 marka Exp $ */
end_comment

begin_comment
comment|/*! \file isc/portset.h  * \brief Transport Protocol Port Manipulation Module  *  * This module provides simple utilities to handle a set of transport protocol  * (UDP or TCP) port numbers, e.g., for creating an ACL list.  An isc_portset_t  * object is an opaque instance of a port set, for which the user can add or  * remove a specific port or a range of consecutive ports.  This object is  * expected to be used as a temporary work space only, and does not protect  * simultaneous access from multiple threads.  Therefore it must not be stored  * in a place that can be accessed from multiple threads.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PORTSET_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PORTSET_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_portset_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_portset_t
modifier|*
modifier|*
name|portsetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a port set and initialize it as an empty set.  *  * Requires:  *\li	'mctx' to be valid.  *\li	'portsetp' to be non NULL and '*portsetp' to be NULL;  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|isc_portset_destroy
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_portset_t
modifier|*
modifier|*
name|portsetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a port set.  *  * Requires:  *\li	'mctx' to be valid and must be the same context given when the port set  *       was created.  *\li	'*portsetp' to be a valid set.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_portset_isset
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Test whether the given port is stored in the portset.  *  * Requires:  *\li	'portset' to be a valid set.  *  * Returns  * \li	#ISC_TRUE if the port is found, ISC_FALSE otherwise.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_portset_nports
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Provides the number of ports stored in the given portset.  *  * Requires:  *\li	'portset' to be a valid set.  *  * Returns  * \li	the number of ports stored in portset.  */
end_comment

begin_function_decl
name|void
name|isc_portset_add
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add the given port to the portset.  The port may or may not be stored in  * the portset.  *  * Requires:  *\li	'portlist' to be valid.  */
end_comment

begin_function_decl
name|void
name|isc_portset_remove
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove the given port to the portset.  The port may or may not be stored in  * the portset.  *  * Requires:  *\li	'portlist' to be valid.  */
end_comment

begin_function_decl
name|void
name|isc_portset_addrange
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|,
name|in_port_t
name|port_lo
parameter_list|,
name|in_port_t
name|port_hi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add a subset of [port_lo, port_hi] (inclusive) to the portset.  Ports in the  * subset may or may not be stored in portset.  *  * Requires:  *\li	'portlist' to be valid.  *\li	port_lo<= port_hi  */
end_comment

begin_function_decl
name|void
name|isc_portset_removerange
parameter_list|(
name|isc_portset_t
modifier|*
name|portset
parameter_list|,
name|in_port_t
name|port_lo
parameter_list|,
name|in_port_t
name|port_hi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Subtract a subset of [port_lo, port_hi] (inclusive) from the portset.  Ports  * in the subset may or may not be stored in portset.  *  * Requires:  *\li	'portlist' to be valid.  *\li	port_lo<= port_hi  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PORTSET_H */
end_comment

end_unit

