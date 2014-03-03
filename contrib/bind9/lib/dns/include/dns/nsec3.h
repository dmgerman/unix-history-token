begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008-2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: nsec3.h,v 1.14 2011/10/28 12:20:31 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_NSEC3_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_NSEC3_H
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
file|<isc/iterated_hash.h>
end_include

begin_include
include|#
directive|include
file|<dns/db.h>
end_include

begin_include
include|#
directive|include
file|<dns/diff.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatastruct.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_define
define|#
directive|define
name|DNS_NSEC3_SALTSIZE
value|255
end_define

begin_comment
comment|/*  * hash = 1, flags =1, iterations = 2, salt length = 1, salt = 255 (max)  * hash length = 1, hash = 255 (max), bitmap = 8192 + 512 (max)  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3_BUFFERSIZE
value|(6 + 255 + 255 + 8192 + 512)
end_define

begin_comment
comment|/*  * hash = 1, flags = 1, iterations = 2, salt length = 1, salt = 255 (max)  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3PARAM_BUFFERSIZE
value|(5 + 255)
end_define

begin_comment
comment|/*  * Test "unknown" algorithm.  Is mapped to dns_hash_sha1.  */
end_comment

begin_define
define|#
directive|define
name|DNS_NSEC3_UNKNOWNALG
value|((dns_hash_t)245U)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_nsec3_buildrdata
parameter_list|(
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
name|unsigned
name|int
name|hashalg
parameter_list|,
name|unsigned
name|int
name|optin
parameter_list|,
name|unsigned
name|int
name|iterations
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|salt
parameter_list|,
name|size_t
name|salt_length
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|nexthash
parameter_list|,
name|size_t
name|hash_length
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Build the rdata of a NSEC3 record for the data at 'node'.  * Note: 'node' is not the node where the NSEC3 record will be stored.  *  * Requires:  *	buffer	Points to a temporary buffer of at least  * 		DNS_NSEC_BUFFERSIZE bytes.  *	rdata	Points to an initialized dns_rdata_t.  *  * Ensures:  *      *rdata	Contains a valid NSEC3 rdata.  The 'data' member refers  *		to 'buffer'.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_nsec3_typepresent
parameter_list|(
name|dns_rdata_t
modifier|*
name|nsec
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Determine if a type is marked as present in an NSEC3 record.  *  * Requires:  *	'nsec' points to a valid rdataset of type NSEC3  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_hashname
parameter_list|(
name|dns_fixedname_t
modifier|*
name|result
parameter_list|,
name|unsigned
name|char
name|rethash
index|[
name|NSEC3_MAX_HASH_LENGTH
index|]
parameter_list|,
name|size_t
modifier|*
name|hash_length
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_hash_t
name|hashalg
parameter_list|,
name|unsigned
name|int
name|iterations
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|salt
parameter_list|,
name|size_t
name|saltlength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make a hashed domain name from an unhashed one. If rethash is not NULL  * the raw hash is stored there.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_nsec3_hashlength
parameter_list|(
name|dns_hash_t
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the length of the hash produced by the specified algorithm  * or zero when unknown.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_nsec3_supportedhash
parameter_list|(
name|dns_hash_t
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return whether we support this hash algorithm or not.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_addnsec3
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
specifier|const
name|dns_rdata_nsec3param_t
modifier|*
name|nsec3param
parameter_list|,
name|dns_ttl_t
name|nsecttl
parameter_list|,
name|isc_boolean_t
name|unsecure
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_nsec3_addnsec3s
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_ttl_t
name|nsecttl
parameter_list|,
name|isc_boolean_t
name|unsecure
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_nsec3_addnsec3sx
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_ttl_t
name|nsecttl
parameter_list|,
name|isc_boolean_t
name|unsecure
parameter_list|,
name|dns_rdatatype_t
name|private
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add NSEC3 records for 'name', recording the change in 'diff'.  * Adjust previous NSEC3 records, if any, to reflect the addition.  * The existing NSEC3 records are removed.  *  * dns_nsec3_addnsec3() will only add records to the chain identified by  * 'nsec3param'.  *  * 'unsecure' should be set to reflect if this is a potentially  * unsecure delegation (no DS record).  *  * dns_nsec3_addnsec3s() will examine the NSEC3PARAM RRset to determine which  * chains to be updated.  NSEC3PARAM records with the DNS_NSEC3FLAG_CREATE  * will be preferentially chosen over NSEC3PARAM records without  * DNS_NSEC3FLAG_CREATE set.  NSEC3PARAM records with DNS_NSEC3FLAG_REMOVE  * set will be ignored by dns_nsec3_addnsec3s().  If DNS_NSEC3FLAG_CREATE  * is set then the new NSEC3 will have OPTOUT set to match the that in the  * NSEC3PARAM record otherwise OPTOUT will be inherited from the previous  * record in the chain.  *  * dns_nsec3_addnsec3sx() is similar to dns_nsec3_addnsec3s() but 'private'  * specifies the type of the private rdataset to be checked in addition to  * the nsec3param rdataset at the zone apex.  *  * Requires:  *	'db' to be valid.  *	'version' to be valid or NULL.  *	'name' to be valid.  *	'nsec3param' to be valid.  *	'diff' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_delnsec3
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
specifier|const
name|dns_rdata_nsec3param_t
modifier|*
name|nsec3param
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_nsec3_delnsec3s
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_nsec3_delnsec3sx
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|private
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove NSEC3 records for 'name', recording the change in 'diff'.  * Adjust previous NSEC3 records, if any, to reflect the removal.  *  * dns_nsec3_delnsec3() performs the above for the chain identified by  * 'nsec3param'.  *  * dns_nsec3_delnsec3s() examines the NSEC3PARAM RRset in a similar manner  * to dns_nsec3_addnsec3s().  Unlike dns_nsec3_addnsec3s() updated NSEC3  * records have the OPTOUT flag preserved.  *  * dns_nsec3_delnsec3sx() is similar to dns_nsec3_delnsec3s() but 'private'  * specifies the type of the private rdataset to be checked in addition to  * the nsec3param rdataset at the zone apex.  *  * Requires:  *	'db' to be valid.  *	'version' to be valid or NULL.  *	'name' to be valid.  *	'nsec3param' to be valid.  *	'diff' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_active
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_boolean_t
name|complete
parameter_list|,
name|isc_boolean_t
modifier|*
name|answer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_nsec3_activex
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_boolean_t
name|complete
parameter_list|,
name|dns_rdatatype_t
name|private
parameter_list|,
name|isc_boolean_t
modifier|*
name|answer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check if there are any complete/to be built NSEC3 chains.  * If 'complete' is ISC_TRUE only complete chains will be recognized.  *  * dns_nsec3_activex() is similar to dns_nsec3_active() but 'private'  * specifies the type of the private rdataset to be checked in addition to  * the nsec3param rdataset at the zone apex.  *  * Requires:  *	'db' to be valid.  *	'version' to be valid or NULL.  *	'answer' to be non NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_maxiterations
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
modifier|*
name|iterationsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the maximum permissible number of iterations allowed based on  * the key strength.  *  * Requires:  *	'db' to be valid.  *	'version' to be valid or NULL.  *	'mctx' to be valid.  *	'iterationsp' to be non NULL.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_nsec3param_fromprivate
parameter_list|(
name|dns_rdata_t
modifier|*
name|src
parameter_list|,
name|dns_rdata_t
modifier|*
name|target
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert a private rdata to a nsec3param rdata.  *  * Return ISC_TRUE if 'src' could be successfully converted.  *  * 'buf' should be at least DNS_NSEC3PARAM_BUFFERSIZE in size.  */
end_comment

begin_function_decl
name|void
name|dns_nsec3param_toprivate
parameter_list|(
name|dns_rdata_t
modifier|*
name|src
parameter_list|,
name|dns_rdata_t
modifier|*
name|target
parameter_list|,
name|dns_rdatatype_t
name|privatetype
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert a nsec3param rdata to a private rdata.  *  * 'buf' should be at least src->length + 1 in size.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3param_deletechains
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|nonsec
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Mark NSEC3PARAM for deletion.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_nsec3_noexistnodata
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|nsec3name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nsec3set
parameter_list|,
name|dns_name_t
modifier|*
name|zonename
parameter_list|,
name|isc_boolean_t
modifier|*
name|exists
parameter_list|,
name|isc_boolean_t
modifier|*
name|data
parameter_list|,
name|isc_boolean_t
modifier|*
name|optout
parameter_list|,
name|isc_boolean_t
modifier|*
name|unknown
parameter_list|,
name|isc_boolean_t
modifier|*
name|setclosest
parameter_list|,
name|isc_boolean_t
modifier|*
name|setnearest
parameter_list|,
name|dns_name_t
modifier|*
name|closest
parameter_list|,
name|dns_name_t
modifier|*
name|nearest
parameter_list|,
name|dns_nseclog_t
name|logit
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_NSEC3_H */
end_comment

end_unit

