begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2012, 2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdataset.h,v 1.72 2011/06/08 22:13:51 each Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATASET_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATASET_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/rdataset.h  * \brief  * A DNS rdataset is a handle that can be associated with a collection of  * rdata all having a common owner name, class, and type.  *  * The dns_rdataset_t type is like a "virtual class".  To actually use  * rdatasets, an implementation of the method suite (e.g. "slabbed rdata") is  * required.  *  * XXX&lt;more&gt; XXX  *  * MP:  *\li	Clients of this module must impose any required synchronization.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	None.  */
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
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatastruct.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_rdatasetadditional_fromauth
block|,
name|dns_rdatasetadditional_fromcache
block|,
name|dns_rdatasetadditional_fromglue
block|}
name|dns_rdatasetadditional_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_rdatasetmethods
block|{
name|void
function_decl|(
modifier|*
name|disassociate
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|first
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|next
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|current
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clone
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|source
parameter_list|,
name|dns_rdataset_t
modifier|*
name|target
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|count
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|addnoqname
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|getnoqname
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|neg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|negsig
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|addclosest
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|getclosest
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|neg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|negsig
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|getadditional
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|,
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|setadditional
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|,
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|putadditional
function_decl|)
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|settrust
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_trust_t
name|trust
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|expire
function_decl|)
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
block|}
name|dns_rdatasetmethods_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_RDATASET_MAGIC
value|ISC_MAGIC('D','N','S','R')
end_define

begin_define
define|#
directive|define
name|DNS_RDATASET_VALID
parameter_list|(
name|set
parameter_list|)
value|ISC_MAGIC_VALID(set, DNS_RDATASET_MAGIC)
end_define

begin_comment
comment|/*%  * Direct use of this structure by clients is strongly discouraged, except  * for the 'link' field which may be used however the client wishes.  The  * 'private', 'current', and 'index' fields MUST NOT be changed by clients.  * rdataset implementations may change any of the fields.  */
end_comment

begin_struct
struct|struct
name|dns_rdataset
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* XXX ? */
name|dns_rdatasetmethods_t
modifier|*
name|methods
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_rdataset_t
argument_list|)
name|link
expr_stmt|;
comment|/* 	 * XXX do we need these, or should they be retrieved by methods? 	 * Leaning towards the latter, since they are not frequently required 	 * once you have the rdataset. 	 */
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|dns_rdatatype_t
name|type
decl_stmt|;
name|dns_ttl_t
name|ttl
decl_stmt|;
name|dns_trust_t
name|trust
decl_stmt|;
name|dns_rdatatype_t
name|covers
decl_stmt|;
comment|/* 	 * attributes 	 */
name|unsigned
name|int
name|attributes
decl_stmt|;
comment|/*% 	 * the counter provides the starting point in the "cyclic" order. 	 * The value ISC_UINT32_MAX has a special meaning of "picking up a 	 * random value." in order to take care of databases that do not 	 * increment the counter. 	 */
name|isc_uint32_t
name|count
decl_stmt|;
comment|/* 	 * This RRSIG RRset should be re-generated around this time. 	 * Only valid if DNS_RDATASETATTR_RESIGN is set in attributes. 	 */
name|isc_stdtime_t
name|resign
decl_stmt|;
comment|/*@{*/
comment|/*% 	 * These are for use by the rdataset implementation, and MUST NOT 	 * be changed by clients. 	 */
name|void
modifier|*
name|private1
decl_stmt|;
name|void
modifier|*
name|private2
decl_stmt|;
name|void
modifier|*
name|private3
decl_stmt|;
name|unsigned
name|int
name|privateuint4
decl_stmt|;
name|void
modifier|*
name|private5
decl_stmt|;
name|void
modifier|*
name|private6
decl_stmt|;
name|void
modifier|*
name|private7
decl_stmt|;
comment|/*@}*/
block|}
struct|;
end_struct

begin_comment
comment|/*!  * \def DNS_RDATASETATTR_RENDERED  *	Used by message.c to indicate that the rdataset was rendered.  *  * \def DNS_RDATASETATTR_TTLADJUSTED  *	Used by message.c to indicate that the rdataset's rdata had differing  *	TTL values, and the rdataset->ttl holds the smallest.  *  * \def DNS_RDATASETATTR_LOADORDER  *	Output the RRset in load order.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_QUESTION
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_RENDERED
value|0x00000002
end_define

begin_comment
comment|/*%< Used by message.c */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWERED
value|0x00000004
end_define

begin_comment
comment|/*%< Used by server. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CACHE
value|0x00000008
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWER
value|0x00000010
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWERSIG
value|0x00000020
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_EXTERNAL
value|0x00000040
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_NCACHE
value|0x00000080
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CHAINING
value|0x00000100
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_TTLADJUSTED
value|0x00000200
end_define

begin_comment
comment|/*%< Used by message.c */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_FIXEDORDER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_RANDOMIZE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CHASE
value|0x00001000
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_NXDOMAIN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_NOQNAME
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CHECKNAMES
value|0x00008000
end_define

begin_comment
comment|/*%< Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_REQUIRED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_REQUIREDGLUE
value|DNS_RDATASETATTR_REQUIRED
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_LOADORDER
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_RESIGN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CLOSEST
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_OPTOUT
value|0x00100000
end_define

begin_comment
comment|/*%< OPTOUT proof */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_NEGATIVE
value|0x00200000
end_define

begin_comment
comment|/*%  * _OMITDNSSEC:  * 	Omit DNSSEC records when rendering ncache records.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETTOWIRE_OMITDNSSEC
value|0x0001
end_define

begin_function_decl
name|void
name|dns_rdataset_init
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdataset' a valid, disassociated rdataset.  *  * Requires:  *\li	'rdataset' is not NULL.  *  * Ensures:  *\li	'rdataset' is a valid, disassociated rdataset.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_invalidate
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Invalidate 'rdataset'.  *  * Requires:  *\li	'rdataset' is a valid, disassociated rdataset.  *  * Ensures:  *\li	If assertion checking is enabled, future attempts to use 'rdataset'  *	without initializing it will cause an assertion failure.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_disassociate
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Disassociate 'rdataset' from its rdata, allowing it to be reused.  *  * Notes:  *\li	The client must ensure it has no references to rdata in the rdataset  *	before disassociating.  *  * Requires:  *\li	'rdataset' is a valid, associated rdataset.  *  * Ensures:  *\li	'rdataset' is a valid, disassociated rdataset.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdataset_isassociated
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Is 'rdataset' associated?  *  * Requires:  *\li	'rdataset' is a valid rdataset.  *  * Returns:  *\li	#ISC_TRUE			'rdataset' is associated.  *\li	#ISC_FALSE			'rdataset' is not associated.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_makequestion
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
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
comment|/*%<  * Make 'rdataset' a valid, associated, question rdataset, with a  * question class of 'rdclass' and type 'type'.  *  * Notes:  *\li	Question rdatasets have a class and type, but no rdata.  *  * Requires:  *\li	'rdataset' is a valid, disassociated rdataset.  *  * Ensures:  *\li	'rdataset' is a valid, associated, question rdataset.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_clone
parameter_list|(
name|dns_rdataset_t
modifier|*
name|source
parameter_list|,
name|dns_rdataset_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'target' refer to the same rdataset as 'source'.  *  * Requires:  *\li	'source' is a valid, associated rdataset.  *  *\li	'target' is a valid, dissociated rdataset.  *  * Ensures:  *\li	'target' references the same rdataset as 'source'.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_rdataset_count
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the number of records in 'rdataset'.  *  * Requires:  *\li	'rdataset' is a valid, associated rdataset.  *  * Returns:  *\li	The number of records in 'rdataset'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_first
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Move the rdata cursor to the first rdata in the rdataset (if any).  *  * Requires:  *\li	'rdataset' is a valid, associated rdataset.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			There are no rdata in the set.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_next
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Move the rdata cursor to the next rdata in the rdataset (if any).  *  * Requires:  *\li	'rdataset' is a valid, associated rdataset.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMORE			There are no more rdata in the set.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_current
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdata' refer to the current rdata.  *  * Notes:  *  *\li	The data returned in 'rdata' is valid for the life of the  *	rdataset; in particular, subsequent changes in the cursor position  *	do not invalidate 'rdata'.  *  * Requires:  *\li	'rdataset' is a valid, associated rdataset.  *  *\li	The rdata cursor of 'rdataset' is at a valid location (i.e. the  *	result of last call to a cursor movement command was ISC_R_SUCCESS).  *  * Ensures:  *\li	'rdata' refers to the rdata at the rdata cursor location of  *\li	'rdataset'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_totext
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|isc_boolean_t
name|omit_final_dot
parameter_list|,
name|isc_boolean_t
name|question
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert 'rdataset' to text format, storing the result in 'target'.  *  * Notes:  *\li	The rdata cursor position will be changed.  *  *\li	The 'question' flag should normally be #ISC_FALSE.  If it is  *	#ISC_TRUE, the TTL and rdata fields are not printed.  This is  *	for use when printing an rdata representing a question section.  *  *\li	This interface is deprecated; use dns_master_rdatasettottext()  * 	and/or dns_master_questiontotext() instead.  *  * Requires:  *\li	'rdataset' is a valid rdataset.  *  *\li	'rdataset' is not empty.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_towire
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|owner_name
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
comment|/*%<  * Convert 'rdataset' to wire format, compressing names as specified  * in 'cctx', and storing the result in 'target'.  *  * Notes:  *\li	The rdata cursor position will be changed.  *  *\li	The number of RRs added to target will be added to *countp.  *  * Requires:  *\li	'rdataset' is a valid rdataset.  *  *\li	'rdataset' is not empty.  *  *\li	'countp' is a valid pointer.  *  * Ensures:  *\li	On a return of ISC_R_SUCCESS, 'target' contains a wire format  *	for the data contained in 'rdataset'.  Any error return leaves  *	the buffer unchanged.  *  *\li	*countp has been incremented by the number of RRs added to  *	target.  *  * Returns:  *\li	#ISC_R_SUCCESS		- all ok  *\li	#ISC_R_NOSPACE		- 'target' doesn't have enough room  *  *\li	Any error returned by dns_rdata_towire(), dns_rdataset_next(),  *	dns_name_towire().  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_towiresorted
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|,
name|dns_rdatasetorderfunc_t
name|order
parameter_list|,
specifier|const
name|void
modifier|*
name|order_arg
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
comment|/*%<  * Like dns_rdataset_towire(), but sorting the rdatasets according to  * the integer value returned by 'order' when called with the rdataset  * and 'order_arg' as arguments.  *  * Requires:  *\li	All the requirements of dns_rdataset_towire(), and  *	that order_arg is NULL if and only if order is NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_towirepartial
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|,
name|dns_rdatasetorderfunc_t
name|order
parameter_list|,
specifier|const
name|void
modifier|*
name|order_arg
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|unsigned
name|int
modifier|*
name|countp
parameter_list|,
name|void
modifier|*
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Like dns_rdataset_towiresorted() except that a partial rdataset  * may be written.  *  * Requires:  *\li	All the requirements of dns_rdataset_towiresorted().  *	If 'state' is non NULL then the current position in the  *	rdataset will be remembered if the rdataset in not  *	completely written and should be passed on on subsequent  *	calls (NOT CURRENTLY IMPLEMENTED).  *  * Returns:  *\li	#ISC_R_SUCCESS if all of the records were written.  *\li	#ISC_R_NOSPACE if unable to fit in all of the records. *countp  *		      will be updated to reflect the number of records  *		      written.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_additionaldata
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_additionaldatafunc_t
name|add
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * For each rdata in rdataset, call 'add' for each name and type in the  * rdata which is subject to additional section processing.  *  * Requires:  *  *\li	'rdataset' is a valid, non-question rdataset.  *  *\li	'add' is a valid dns_additionaldatafunc_t  *  * Ensures:  *  *\li	If successful, dns_rdata_additionaldata() will have been called for  *	each rdata in 'rdataset'.  *  *\li	If a call to dns_rdata_additionaldata() is not successful, the  *	result returned will be the result of dns_rdataset_additionaldata().  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *  *\li	Any error that dns_rdata_additionaldata() can return.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_getnoqname
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|neg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|negsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the noqname proof for this record.  *  * Requires:  *\li	'rdataset' to be valid and #DNS_RDATASETATTR_NOQNAME to be set.  *\li	'name' to be valid.  *\li	'neg' and 'negsig' to be valid and not associated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_addnoqname
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a noqname proof with this record.  * Sets #DNS_RDATASETATTR_NOQNAME if successful.  * Adjusts the 'rdataset->ttl' to minimum of the 'rdataset->ttl' and  * the 'nsec'/'nsec3' and 'rrsig(nsec)'/'rrsig(nsec3)' ttl.  *  * Requires:  *\li	'rdataset' to be valid and #DNS_RDATASETATTR_NOQNAME to be set.  *\li	'name' to be valid and have NSEC or NSEC3 and associated RRSIG  *	 rdatasets.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_getclosest
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsec
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsecsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the closest encloser for this record.  *  * Requires:  *\li	'rdataset' to be valid and #DNS_RDATASETATTR_CLOSEST to be set.  *\li	'name' to be valid.  *\li	'nsec' and 'nsecsig' to be valid and not associated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_addclosest
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a closest encloset proof with this record.  * Sets #DNS_RDATASETATTR_CLOSEST if successful.  * Adjusts the 'rdataset->ttl' to minimum of the 'rdataset->ttl' and  * the 'nsec' and 'rrsig(nsec)' ttl.  *  * Requires:  *\li	'rdataset' to be valid and #DNS_RDATASETATTR_CLOSEST to be set.  *\li	'name' to be valid and have NSEC3 and RRSIG(NSEC3) rdatasets.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_getadditional
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|,
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get cached additional information from the DB node for a particular  * 'rdataset.'  'type' is one of dns_rdatasetadditional_fromauth,  * dns_rdatasetadditional_fromcache, and dns_rdatasetadditional_fromglue,  * which specifies the origin of the information.  'qtype' is intended to  * be used for specifying a particular rdata type in the cached information.  *  * Requires:  * \li	'rdataset' is a valid rdataset.  * \li	'acache' can be NULL, in which case this function will simply return  * 	ISC_R_FAILURE.  * \li	For the other pointers, see dns_acache_getentry().  *  * Ensures:  * \li	See dns_acache_getentry().  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_FAILURE	- additional information caching is not supported.  * \li	#ISC_R_NOTFOUND	- the corresponding DB node has not cached additional  *			  information for 'rdataset.'  * \li	Any error that dns_acache_getentry() can return.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_setadditional
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|,
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set cached additional information to the DB node for a particular  * 'rdataset.'  See dns_rdataset_getadditional for the semantics of 'type'  * and 'qtype'.  *  * Requires:  * \li	'rdataset' is a valid rdataset.  * \li	'acache' can be NULL, in which case this function will simply return  *	ISC_R_FAILURE.  * \li	For the other pointers, see dns_acache_setentry().  *  * Ensures:  * \li	See dns_acache_setentry().  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_FAILURE	- additional information caching is not supported.  * \li	#ISC_R_NOMEMORY  * \li	Any error that dns_acache_setentry() can return.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdataset_putadditional
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdatasetadditional_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Discard cached additional information stored in the DB node for a particular  * 'rdataset.'  See dns_rdataset_getadditional for the semantics of 'type'  * and 'qtype'.  *  * Requires:  * \li	'rdataset' is a valid rdataset.  * \li	'acache' can be NULL, in which case this function will simply return  *	ISC_R_FAILURE.  *  * Ensures:  * \li	See dns_acache_cancelentry().  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_FAILURE	- additional information caching is not supported.  * \li	#ISC_R_NOTFOUND	- the corresponding DB node has not cached additional  *			  information for 'rdataset.'  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_settrust
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_trust_t
name|trust
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the trust of the 'rdataset' to trust in any in the backing database.  * The local trust level of 'rdataset' is also set.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_expire
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Mark the rdataset to be expired in the backing database.  */
end_comment

begin_function_decl
name|void
name|dns_rdataset_trimttl
parameter_list|(
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|,
name|dns_rdata_rrsig_t
modifier|*
name|rrsig
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|isc_boolean_t
name|acceptexpired
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Trim the ttl of 'rdataset' and 'sigrdataset' so that they will expire  * at or before 'rrsig->expiretime'.  If 'acceptexpired' is true and the  * signature has expired or will expire in the next 120 seconds, limit  * the ttl to be no more than 120 seconds.  *  * The ttl is further limited by the original ttl as stored in 'rrsig'  * and the original ttl values of 'rdataset' and 'sigrdataset'.  *  * Requires:  * \li	'rdataset' is a valid rdataset.  * \li	'sigrdataset' is a valid rdataset.  * \li	'rrsig' is non NULL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_trust_totext
parameter_list|(
name|dns_trust_t
name|trust
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Display trust in textual form.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATASET_H */
end_comment

end_unit

