begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: order.h,v 1.2.202.3 2004/03/08 09:04:37 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ORDER_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ORDER_H
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
name|dns_order_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_order_t
modifier|*
modifier|*
name|orderp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a order object.  *  * Requires:  * 	'orderp' to be non NULL and '*orderp == NULL'.  *	'mctx' to be valid.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_order_add
parameter_list|(
name|dns_order_t
modifier|*
name|order
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|rdtype
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|unsigned
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a entry to the end of the order list.  *  * Requires:  * 	'order' to be valid.  *	'name' to be valid.  *	'mode' to be one of DNS_RDATASERATTR_RANDOMIZE,  *		DNS_RDATASERATTR_RANDOMIZE or zero (DNS_RDATASERATTR_CYCLIC).  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_order_find
parameter_list|(
name|dns_order_t
modifier|*
name|order
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|rdtype
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the first matching entry on the list.  *  * Requires:  *	'order' to be valid.  *	'name' to be valid.  *  * Returns the mode set by dns_order_add() or zero.  */
end_comment

begin_function_decl
name|void
name|dns_order_attach
parameter_list|(
name|dns_order_t
modifier|*
name|source
parameter_list|,
name|dns_order_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to the 'source' object.  *  * Requires:  * 	'source' to be valid.  *	'target' to be non NULL and '*target == NULL'.  */
end_comment

begin_function_decl
name|void
name|dns_order_detach
parameter_list|(
name|dns_order_t
modifier|*
modifier|*
name|orderp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach from the object.  Clean up if last this was the last  * reference.  *  * Requires:  *	'*orderp' to be valid.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ORDER_H */
end_comment

end_unit

