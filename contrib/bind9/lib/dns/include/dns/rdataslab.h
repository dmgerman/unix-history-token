begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdataslab.h,v 1.20.2.2.2.4 2004/03/08 09:04:39 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATASLAB_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATASLAB_H
value|1
end_define

begin_comment
comment|/*  * DNS Rdata Slab  *  * Implements storage of rdatasets into slabs of memory.  *  * MP:  *	Clients of this module must impose any required synchronization.  *  * Reliability:  *	This module deals with low-level byte streams.  Errors in any of  *	the functions are likely to crash the server or corrupt memory.  *  *	If the caller passes invalid memory references, these functions are  *	likely to crash the server or corrupt memory.  *  * Resources:  *	None.  *  * Security:  *	None.  *  * Standards:  *	None.  */
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
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
define|#
directive|define
name|DNS_RDATASLAB_FORCE
value|0x1
define|#
directive|define
name|DNS_RDATASLAB_EXACT
value|0x2
comment|/***  *** Functions  ***/
name|isc_result_t
name|dns_rdataslab_fromrdataset
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Slabify a rdataset.  The slab area will be allocated and returned  * in 'region'.  *  * Requires:  *	'rdataset' is valid.  *  * Ensures:  *	'region' will have base pointing to the start of allocated memory,  *	with the slabified region beginning at region->base + reservelen.  *	region->length contains the total length allocated.  *  * Returns:  *	ISC_R_SUCCESS		- successful completion  *	ISC_R_NOMEMORY		- no memory.  *<XXX others>  */
end_comment

begin_function_decl
name|void
name|dns_rdataslab_tordataset
parameter_list|(
name|unsigned
name|char
modifier|*
name|slab
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|rdtype
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct an rdataset from a slab.  *  * Requires:  *	'slab' points to a slab.  *	'rdataset' is disassociated.  *  * Ensures:  *	'rdataset' is associated and points to a valid rdataest.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_rdataslab_size
parameter_list|(
name|unsigned
name|char
modifier|*
name|slab
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the total size of an rdataslab.  *  * Requires:  *	'slab' points to a slab.  *  * Returns:  *	The number of bytes in the slab, including the reservelen.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataslab_merge
parameter_list|(
name|unsigned
name|char
modifier|*
name|oslab
parameter_list|,
name|unsigned
name|char
modifier|*
name|nslab
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|tslabp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Merge 'oslab' and 'nslab'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataslab_subtract
parameter_list|(
name|unsigned
name|char
modifier|*
name|mslab
parameter_list|,
name|unsigned
name|char
modifier|*
name|sslab
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|tslabp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Subtract 'sslab' from 'mslab'.  If 'exact' is true then all elements  * of 'sslab' must exist in 'mslab'.  *  * XXX  * valid flags are DNS_RDATASLAB_EXACT  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdataslab_equal
parameter_list|(
name|unsigned
name|char
modifier|*
name|slab1
parameter_list|,
name|unsigned
name|char
modifier|*
name|slab2
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compare two rdataslabs for equality.  This does _not_ do a full  * DNSSEC comparison.  *  * Requires:  *	'slab1' and 'slab2' point to slabs.  *  * Returns:  *	ISC_TRUE if the slabs are equal, ISC_FALSE otherwise.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdataslab_equalx
parameter_list|(
name|unsigned
name|char
modifier|*
name|slab1
parameter_list|,
name|unsigned
name|char
modifier|*
name|slab2
parameter_list|,
name|unsigned
name|int
name|reservelen
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compare two rdataslabs for DNSSEC equality.   *  * Requires:  *	'slab1' and 'slab2' point to slabs.  *  * Returns:  *	ISC_TRUE if the slabs are equal, ISC_FALSE otherwise.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATASLAB_H */
end_comment

end_unit

