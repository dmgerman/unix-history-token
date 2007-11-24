begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdataset.h,v 1.41.2.5.2.10 2006/03/02 00:37:20 marka Exp $ */
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
comment|/*  * DNS Rdataset  *  * A DNS rdataset is a handle that can be associated with a collection of  * rdata all having a common owner name, class, and type.  *  * The dns_rdataset_t type is like a "virtual class".  To actually use  * rdatasets, an implementation of the method suite (e.g. "slabbed rdata") is  * required.  *  * XXX<more> XXX  *  * MP:  *	Clients of this module must impose any required synchronization.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
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
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

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
name|nsec
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsecsig
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
comment|/*  * Direct use of this structure by clients is strongly discouraged, except  * for the 'link' field which may be used however the client wishes.  The  * 'private', 'current', and 'index' fields MUST NOT be changed by clients.  * rdataset implementations may change any of the fields.  */
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
comment|/* 	 * the counter provides the starting point in the "cyclic" order. 	 * The value ISC_UINT32_MAX has a special meaning of "picking up a 	 * random value." in order to take care of databases that do not 	 * increment the counter. 	 */
name|isc_uint32_t
name|count
decl_stmt|;
comment|/* 	 * These are for use by the rdataset implementation, and MUST NOT 	 * be changed by clients. 	 */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * _RENDERED:  *	Used by message.c to indicate that the rdataset was rendered.  *  * _TTLADJUSTED:  *	Used by message.c to indicate that the rdataset's rdata had differing  *	TTL values, and the rdataset->ttl holds the smallest.  */
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
comment|/* Used by message.c */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWERED
value|0x00000004
end_define

begin_comment
comment|/* Used by server. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CACHE
value|0x00000008
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWER
value|0x00000010
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_ANSWERSIG
value|0x00000020
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_EXTERNAL
value|0x00000040
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_NCACHE
value|0x00000080
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_CHAINING
value|0x00000100
end_define

begin_comment
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_TTLADJUSTED
value|0x00000200
end_define

begin_comment
comment|/* Used by message.c */
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
comment|/* Used by resolver. */
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
comment|/* Used by resolver. */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASETATTR_REQUIREDGLUE
value|0x00010000
end_define

begin_comment
comment|/*  * _OMITDNSSEC:  * 	Omit DNSSEC records when rendering ncache records.  */
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
comment|/*  * Make 'rdataset' a valid, disassociated rdataset.  *  * Requires:  *	'rdataset' is not NULL.  *  * Ensures:  *	'rdataset' is a valid, disassociated rdataset.  */
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
comment|/*  * Invalidate 'rdataset'.  *  * Requires:  *	'rdataset' is a valid, disassociated rdataset.  *  * Ensures:  *	If assertion checking is enabled, future attempts to use 'rdataset'  *	without initializing it will cause an assertion failure.  */
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
comment|/*  * Disassociate 'rdataset' from its rdata, allowing it to be reused.  *  * Notes:  *	The client must ensure it has no references to rdata in the rdataset  *	before disassociating.  *  * Requires:  *	'rdataset' is a valid, associated rdataset.  *  * Ensures:  *	'rdataset' is a valid, disassociated rdataset.  */
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
comment|/*  * Is 'rdataset' associated?  *  * Requires:  *	'rdataset' is a valid rdataset.  *  * Returns:  *	ISC_TRUE			'rdataset' is associated.  *	ISC_FALSE			'rdataset' is not associated.  */
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
comment|/*  * Make 'rdataset' a valid, associated, question rdataset, with a  * question class of 'rdclass' and type 'type'.  *  * Notes:  *	Question rdatasets have a class and type, but no rdata.  *  * Requires:  *	'rdataset' is a valid, disassociated rdataset.  *  * Ensures:  *	'rdataset' is a valid, associated, question rdataset.  */
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
comment|/*  * Make 'target' refer to the same rdataset as 'source'.  *  * Requires:  *	'source' is a valid, associated rdataset.  *  *	'target' is a valid, dissociated rdataset.  *  * Ensures:  *	'target' references the same rdataset as 'source'.  */
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
comment|/*  * Return the number of records in 'rdataset'.  *  * Requires:  *	'rdataset' is a valid, associated rdataset.  *  * Returns:  *	The number of records in 'rdataset'.  */
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
comment|/*  * Move the rdata cursor to the first rdata in the rdataset (if any).  *  * Requires:  *	'rdataset' is a valid, associated rdataset.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no rdata in the set.  */
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
comment|/*  * Move the rdata cursor to the next rdata in the rdataset (if any).  *  * Requires:  *	'rdataset' is a valid, associated rdataset.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMORE			There are no more rdata in the set.  */
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
comment|/*  * Make 'rdata' refer to the current rdata.  *  * Notes:  *  *	The data returned in 'rdata' is valid for the life of the  *	rdataset; in particular, subsequent changes in the cursor position  *	do not invalidate 'rdata'.  *  * Requires:  *	'rdataset' is a valid, associated rdataset.  *  *	The rdata cursor of 'rdataset' is at a valid location (i.e. the  *	result of last call to a cursor movement command was ISC_R_SUCCESS).  *  * Ensures:  *	'rdata' refers to the rdata at the rdata cursor location of  *	'rdataset'.  */
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
comment|/*  * Convert 'rdataset' to text format, storing the result in 'target'.  *  * Notes:  *	The rdata cursor position will be changed.  *  *	The 'question' flag should normally be ISC_FALSE.  If it is   *	ISC_TRUE, the TTL and rdata fields are not printed.  This is   *	for use when printing an rdata representing a question section.  *  *	This interface is deprecated; use dns_master_rdatasettottext()  * 	and/or dns_master_questiontotext() instead.  *  * Requires:  *	'rdataset' is a valid rdataset.  *  *	'rdataset' is not empty.  */
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
comment|/*  * Convert 'rdataset' to wire format, compressing names as specified  * in 'cctx', and storing the result in 'target'.  *  * Notes:  *	The rdata cursor position will be changed.  *  *	The number of RRs added to target will be added to *countp.  *  * Requires:  *	'rdataset' is a valid rdataset.  *  *	'rdataset' is not empty.  *  *	'countp' is a valid pointer.  *  * Ensures:  *	On a return of ISC_R_SUCCESS, 'target' contains a wire format  *	for the data contained in 'rdataset'.  Any error return leaves  *	the buffer unchanged.  *  *	*countp has been incremented by the number of RRs added to  *	target.  *  * Returns:  *	ISC_R_SUCCESS		- all ok  *	ISC_R_NOSPACE		- 'target' doesn't have enough room  *  *	Any error returned by dns_rdata_towire(), dns_rdataset_next(),  *	dns_name_towire().  */
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
comment|/*  * Like dns_rdataset_towire(), but sorting the rdatasets according to  * the integer value returned by 'order' when called witih the rdataset  * and 'order_arg' as arguments.  *  * Requires:  *	All the requirements of dns_rdataset_towire(), and  *	that order_arg is NULL if and only if order is NULL.  */
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
comment|/*  * Like dns_rdataset_towiresorted() except that a partial rdataset  * may be written.  *  * Requires:  *	All the requirements of dns_rdataset_towiresorted().  *	If 'state' is non NULL then the current position in the  *	rdataset will be remembered if the rdataset in not  *	completely written and should be passed on on subsequent  *	calls (NOT CURRENTLY IMPLEMENTED).  *  * Returns:  *	ISC_R_SUCCESS if all of the records were written.  *	ISC_R_NOSPACE if unable to fit in all of the records. *countp  *		      will be updated to reflect the number of records  *		      written.  */
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
comment|/*  * For each rdata in rdataset, call 'add' for each name and type in the  * rdata which is subject to additional section processing.  *  * Requires:  *  *	'rdataset' is a valid, non-question rdataset.  *  *	'add' is a valid dns_additionaldatafunc_t  *  * Ensures:  *  *	If successful, dns_rdata_additionaldata() will have been called for  *	each rdata in 'rdataset'.  *  *	If a call to dns_rdata_additionaldata() is not successful, the  *	result returned will be the result of dns_rdataset_additionaldata().  *  * Returns:  *  *	ISC_R_SUCCESS  *  *	Any error that dns_rdata_additionaldata() can return.  */
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
name|nsec
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsecsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the noqname proof for this record.  *  * Requires:  *	'rdataset' to be valid and DNS_RDATASETATTR_NOQNAME to be set.  *	'name' to be valid.  *	'nsec' and 'nsecsig' to be valid and not associated.  */
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
comment|/*  * Associate a noqname proof with this record.  * Sets DNS_RDATASETATTR_NOQNAME if successful.  * Adjusts the 'rdataset->ttl' to minimum of the 'rdataset->ttl' and  * the 'nsec' and 'rrsig(nsec)' ttl.  *  * Requires:  *	'rdataset' to be valid and DNS_RDATASETATTR_NOQNAME to be set.  *	'name' to be valid and have NSEC and RRSIG(NSEC) rdatasets.  */
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

