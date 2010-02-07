begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2008  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ncache.h,v 1.25.142.1 2009/12/31 20:29:21 each Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_NCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_NCACHE_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/ncache.h  *\brief  * DNS Ncache  *  * XXX TBS XXX  *  * MP:  *\li	The caller must ensure any required synchronization.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	RFC2308  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*%  * _OMITDNSSEC:  *      Omit DNSSEC records when rendering.  */
define|#
directive|define
name|DNS_NCACHETOWIRE_OMITDNSSEC
value|0x0001
name|isc_result_t
name|dns_ncache_add
parameter_list|(
name|dns_message_t
modifier|*
name|message
parameter_list|,
name|dns_db_t
modifier|*
name|cache
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_ttl_t
name|maxttl
parameter_list|,
name|dns_rdataset_t
modifier|*
name|addedrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_ncache_addoptout
parameter_list|(
name|dns_message_t
modifier|*
name|message
parameter_list|,
name|dns_db_t
modifier|*
name|cache
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_ttl_t
name|maxttl
parameter_list|,
name|isc_boolean_t
name|optout
parameter_list|,
name|dns_rdataset_t
modifier|*
name|addedrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the authority data from 'message' into a negative cache  * rdataset, and store it in 'cache' at 'node' with a TTL limited to  * 'maxttl'.  *  * The 'covers' argument is the RR type whose nonexistence we are caching,  * or dns_rdatatype_any when caching a NXDOMAIN response.  *  * 'optout' indicates a DNS_RDATASETATTR_OPTOUT should be set.  *  * Note:  *\li	If 'addedrdataset' is not NULL, then it will be attached to the added  *	rdataset.  See dns_db_addrdataset() for more details.  *  * Requires:  *\li	'message' is a valid message with a properly formatting negative cache  *	authority section.  *  *\li	The requirements of dns_db_addrdataset() apply to 'cache', 'node',  *	'now', and 'addedrdataset'.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOSPACE  *  *\li	Any result code of dns_db_addrdataset() is a possible result code  *	of dns_ncache_add().  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ncache_towire
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|unsigned
name|int
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the negative caching rdataset 'rdataset' to wire format,  * compressing names as specified in 'cctx', and storing the result in  * 'target'.  If 'omit_dnssec' is set, DNSSEC records will not  * be added to 'target'.  *  * Notes:  *\li	The number of RRs added to target will be added to *countp.  *  * Requires:  *\li	'rdataset' is a valid negative caching rdataset.  *  *\li	'rdataset' is not empty.  *  *\li	'countp' is a valid pointer.  *  * Ensures:  *\li	On a return of ISC_R_SUCCESS, 'target' contains a wire format  *	for the data contained in 'rdataset'.  Any error return leaves  *	the buffer unchanged.  *  *\li	*countp has been incremented by the number of RRs added to  *	target.  *  * Returns:  *\li	#ISC_R_SUCCESS		- all ok  *\li	#ISC_R_NOSPACE		- 'target' doesn't have enough room  *  *\li	Any error returned by dns_rdata_towire(), dns_rdataset_next(),  *	dns_name_towire().  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_ncache_getrdataset
parameter_list|(
name|dns_rdataset_t
modifier|*
name|ncacherdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search the negative caching rdataset for an rdataset with the  * specified name and type.  *  * Requires:  *\li	'ncacherdataset' is a valid negative caching rdataset.  *  *\li	'ncacherdataset' is not empty.  *  *\li	'name' is a valid name.  *  *\li	'type' is not SIG, or a meta-RR type.  *  *\li	'rdataset' is a valid disassociated rdataset.  *  * Ensures:  *\li	On a return of ISC_R_SUCCESS, 'rdataset' is bound to the found  *	rdataset.  *  * Returns:  *\li	#ISC_R_SUCCESS		- the rdataset was found.  *\li	#ISC_R_NOTFOUND		- the rdataset was not found.  *  */
end_comment

begin_function_decl
name|void
name|dns_ncache_current
parameter_list|(
name|dns_rdataset_t
modifier|*
name|ncacherdataset
parameter_list|,
name|dns_name_t
modifier|*
name|found
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Extract the current rdataset and name from a ncache entry.  *  * Requires:  * \li	'ncacherdataset' to be valid and to be a negative cache entry  * \li	'found' to be valid.  * \li	'rdataset' to be unassociated.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_NCACHE_H */
end_comment

end_unit

