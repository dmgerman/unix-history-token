begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/data/packed_rrset.h - data storage for a set of resource records.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the data storage for RRsets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_DATA_PACKED_RRSET_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_DATA_PACKED_RRSET_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_struct_decl
struct_decl|struct
name|alloc_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_comment
comment|/** type used to uniquely identify rrsets. Cannot be reused without  * clearing the cache. */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|rrset_id_t
typedef|;
end_typedef

begin_comment
comment|/** this rrset is NSEC and is at zone apex (at child side of zonecut) */
end_comment

begin_define
define|#
directive|define
name|PACKED_RRSET_NSEC_AT_APEX
value|0x1
end_define

begin_comment
comment|/** this rrset is A/AAAA and is in-zone-glue (from parent side of zonecut) */
end_comment

begin_define
define|#
directive|define
name|PACKED_RRSET_PARENT_SIDE
value|0x2
end_define

begin_comment
comment|/** this rrset is SOA and has the negative ttl (from nxdomain or nodata),  * this is set on SOA rrsets in the authority section, to keep its TTL separate  * from the SOA in the answer section from a direct SOA query or ANY query. */
end_comment

begin_define
define|#
directive|define
name|PACKED_RRSET_SOA_NEG
value|0x4
end_define

begin_comment
comment|/**  * The identifying information for an RRset.  */
end_comment

begin_struct
struct|struct
name|packed_rrset_key
block|{
comment|/** 	 * The domain name. If not null (for id=0) it is allocated, and 	 * contains the wireformat domain name. 	 * This dname is not canonicalized. 	 */
name|uint8_t
modifier|*
name|dname
decl_stmt|;
comment|/**  	 * Length of the domain name, including last 0 root octet.  	 */
name|size_t
name|dname_len
decl_stmt|;
comment|/** 	 * Flags. 32bit to be easy for hashing: 	 * 	o PACKED_RRSET_NSEC_AT_APEX 	 * 	o PACKED_RRSET_PARENT_SIDE 	 * 	o PACKED_RRSET_SOA_NEG 	 */
name|uint32_t
name|flags
decl_stmt|;
comment|/** the rrset type in network format */
name|uint16_t
name|type
decl_stmt|;
comment|/** the rrset class in network format */
name|uint16_t
name|rrset_class
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * This structure contains an RRset. A set of resource records that  * share the same domain name, type and class.  *  * Due to memory management and threading, the key structure cannot be  * deleted, although the data can be. The id can be set to 0 to store and the  * structure can be recycled with a new id.  */
end_comment

begin_struct
struct|struct
name|ub_packed_rrset_key
block|{
comment|/**  	 * entry into hashtable. Note the lock is never destroyed, 	 *  even when this key is retired to the cache.  	 * the data pointer (if not null) points to a struct packed_rrset. 	 */
name|struct
name|lruhash_entry
name|entry
decl_stmt|;
comment|/**  	 * the ID of this rrset. unique, based on threadid + sequenceno.  	 * ids are not reused, except after flushing the cache. 	 * zero is an unused entry, and never a valid id. 	 * Check this value after getting entry.lock. 	 * The other values in this struct may only be altered after changing 	 * the id (which needs a writelock on entry.lock). 	 */
name|rrset_id_t
name|id
decl_stmt|;
comment|/** key data: dname, type and class */
name|struct
name|packed_rrset_key
name|rk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * RRset trustworthiness. Bigger value is more trust. RFC 2181.  * The rrset_trust_add_noAA, rrset_trust_auth_noAA, rrset_trust_add_AA,  * are mentioned as the same trustworthiness in 2181, but split up here  * for ease of processing.  *  * rrset_trust_nonauth_ans_AA, rrset_trust_ans_noAA  * are also mentioned as the same trustworthiness in 2181, but split up here  * for ease of processing.  *  * Added trust_none for a sane initial value, smaller than anything else.  * Added validated and ultimate trust for keys and rrsig validated content.  */
end_comment

begin_enum
enum|enum
name|rrset_trust
block|{
comment|/** initial value for trust */
name|rrset_trust_none
init|=
literal|0
block|,
comment|/** Additional information from non-authoritative answers */
name|rrset_trust_add_noAA
block|,
comment|/** Data from the authority section of a non-authoritative answer */
name|rrset_trust_auth_noAA
block|,
comment|/** Additional information from an authoritative answer */
name|rrset_trust_add_AA
block|,
comment|/** non-authoritative data from the answer section of authoritative 	 * answers */
name|rrset_trust_nonauth_ans_AA
block|,
comment|/** Data from the answer section of a non-authoritative answer */
name|rrset_trust_ans_noAA
block|,
comment|/** Glue from a primary zone, or glue from a zone transfer */
name|rrset_trust_glue
block|,
comment|/** Data from the authority section of an authoritative answer */
name|rrset_trust_auth_AA
block|,
comment|/** The authoritative data included in the answer section of an 	 *  authoritative reply */
name|rrset_trust_ans_AA
block|,
comment|/** Data from a zone transfer, other than glue */
name|rrset_trust_sec_noglue
block|,
comment|/** Data from a primary zone file, other than glue data */
name|rrset_trust_prim_noglue
block|,
comment|/** DNSSEC(rfc4034) validated with trusted keys */
name|rrset_trust_validated
block|,
comment|/** ultimately trusted, no more trust is possible;  	 * trusted keys from the unbound configuration setup. */
name|rrset_trust_ultimate
block|}
enum|;
end_enum

begin_comment
comment|/**  * Security status from validation for data.  * The order is significant; more secure, more proven later.  */
end_comment

begin_enum
enum|enum
name|sec_status
block|{
comment|/** UNCHECKED means that object has yet to be validated. */
name|sec_status_unchecked
init|=
literal|0
block|,
comment|/** BOGUS means that the object (RRset or message) failed to validate 	 *  (according to local policy), but should have validated. */
name|sec_status_bogus
block|,
comment|/** INDETERMINATE means that the object is insecure, but not  	 * authoritatively so. Generally this means that the RRset is not  	 * below a configured trust anchor. */
name|sec_status_indeterminate
block|,
comment|/** INSECURE means that the object is authoritatively known to be  	 * insecure. Generally this means that this RRset is below a trust  	 * anchor, but also below a verified, insecure delegation. */
name|sec_status_insecure
block|,
comment|/** SECURE means that the object (RRset or message) validated  	 * according to local policy. */
name|sec_status_secure
block|}
enum|;
end_enum

begin_comment
comment|/**  * RRset data.  *  * The data is packed, stored contiguously in memory.  * memory layout:  *	o base struct  *	o rr_len size_t array  *	o rr_data uint8_t* array  *	o rr_ttl uint32_t array (after size_t and ptrs because those may be  *		64bit and this array before those would make them unaligned).  *		Since the stuff before is 32/64bit, rr_ttl is 32 bit aligned.  *	o rr_data rdata wireformats  *	o rrsig_data rdata wireformat(s)  *  * Rdata is stored in wireformat. The dname is stored in wireformat.  * TTLs are stored as absolute values (and could be expired).  *  * RRSIGs are stored in the arrays after the regular rrs.  *  * You need the packed_rrset_key to know dname, type, class of the  * resource records in this RRset. (if signed the rrsig gives the type too).  *  * On the wire an RR is:  *	name, type, class, ttl, rdlength, rdata.  * So we need to send the following per RR:  *	key.dname, ttl, rr_data[i].  *	since key.dname ends with type and class.  *	and rr_data starts with the rdlength.  *	the ttl value to send changes due to time.  */
end_comment

begin_struct
struct|struct
name|packed_rrset_data
block|{
comment|/** TTL (in seconds like time()) of the rrset. 	 * Same for all RRs see rfc2181(5.2).  */
name|time_t
name|ttl
decl_stmt|;
comment|/** number of rrs. */
name|size_t
name|count
decl_stmt|;
comment|/** number of rrsigs, if 0 no rrsigs */
name|size_t
name|rrsig_count
decl_stmt|;
comment|/** the trustworthiness of the rrset data */
name|enum
name|rrset_trust
name|trust
decl_stmt|;
comment|/** security status of the rrset data */
name|enum
name|sec_status
name|security
decl_stmt|;
comment|/** length of every rr's rdata, rr_len[i] is size of rr_data[i]. */
name|size_t
modifier|*
name|rr_len
decl_stmt|;
comment|/** ttl of every rr. rr_ttl[i] ttl of rr i. */
name|time_t
modifier|*
name|rr_ttl
decl_stmt|;
comment|/**  	 * Array of pointers to every rr's rdata.  	 * The rr_data[i] rdata is stored in uncompressed wireformat.  	 * The first uint16_t of rr_data[i] is network format rdlength. 	 * 	 * rr_data[count] to rr_data[count+rrsig_count] contain the rrsig data. 	 */
name|uint8_t
modifier|*
modifier|*
name|rr_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * An RRset can be represented using both key and data together.  * Split into key and data structures to simplify implementation of  * caching schemes.  */
end_comment

begin_struct
struct|struct
name|packed_rrset
block|{
comment|/** domain name, type and class */
name|struct
name|packed_rrset_key
modifier|*
name|k
decl_stmt|;
comment|/** ttl, count and rdatas (and rrsig) */
name|struct
name|packed_rrset_data
modifier|*
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * list of packed rrsets  */
end_comment

begin_struct
struct|struct
name|packed_rrset_list
block|{
comment|/** next in list */
name|struct
name|packed_rrset_list
modifier|*
name|next
decl_stmt|;
comment|/** rrset key and data */
name|struct
name|packed_rrset
name|rrset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Delete packed rrset key and data, not entered in hashtables yet.  * Used during parsing.  * @param pkey: rrset key structure with locks, key and data pointers.  * @param alloc: where to return the unfree-able key structure.  */
end_comment

begin_function_decl
name|void
name|ub_packed_rrset_parsedelete
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|pkey
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Memory size of rrset data. RRset data must be filled in correctly.  * @param data: data to examine.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|packed_rrset_sizeof
parameter_list|(
name|struct
name|packed_rrset_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get TTL of rrset. RRset data must be filled in correctly.  * @param key: rrset key, with data to examine.  * @return ttl value.  */
end_comment

begin_function_decl
name|time_t
name|ub_packed_rrset_ttl
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Calculate memory size of rrset entry. For hash table usage.  * @param key: struct ub_packed_rrset_key*.  * @param data: struct packed_rrset_data*.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|ub_rrset_sizefunc
parameter_list|(
name|void
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * compares two rrset keys.  * @param k1: struct ub_packed_rrset_key*.  * @param k2: struct ub_packed_rrset_key*.  * @return 0 if equal.  */
end_comment

begin_function_decl
name|int
name|ub_rrset_compare
parameter_list|(
name|void
modifier|*
name|k1
parameter_list|,
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * compare two rrset data structures.  * Compared rdata and rrsigdata, not the trust or ttl value.  * @param d1: data to compare.  * @param d2: data to compare.  * @return 1 if equal.  */
end_comment

begin_function_decl
name|int
name|rrsetdata_equal
parameter_list|(
name|struct
name|packed_rrset_data
modifier|*
name|d1
parameter_list|,
name|struct
name|packed_rrset_data
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Old key to be deleted. RRset keys are recycled via alloc.  * The id is set to 0. So that other threads, after acquiring a lock always  * get the correct value, in this case the 0 deleted-special value.  * @param key: struct ub_packed_rrset_key*.  * @param userdata: alloc structure to use for recycling.  */
end_comment

begin_function_decl
name|void
name|ub_rrset_key_delete
parameter_list|(
name|void
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Old data to be deleted.  * @param data: what to delete.  * @param userdata: user data ptr.  */
end_comment

begin_function_decl
name|void
name|rrset_data_delete
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Calculate hash value for a packed rrset key.  * @param key: the rrset key with name, type, class, flags.  * @return hash value.  */
end_comment

begin_function_decl
name|hashvalue_t
name|rrset_key_hash
parameter_list|(
name|struct
name|packed_rrset_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Fixup pointers in fixed data packed_rrset_data blob.  * After a memcpy of the data for example. Will set internal pointers right.  * @param data: rrset data structure. Otherwise correctly filled in.  */
end_comment

begin_function_decl
name|void
name|packed_rrset_ptr_fixup
parameter_list|(
name|struct
name|packed_rrset_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Fixup TTLs in fixed data packed_rrset_data blob.  * @param data: rrset data structure. Otherwise correctly filled in.  * @param add: how many seconds to add, pass time(0) for example.  */
end_comment

begin_function_decl
name|void
name|packed_rrset_ttl_add
parameter_list|(
name|struct
name|packed_rrset_data
modifier|*
name|data
parameter_list|,
name|time_t
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Utility procedure to extract CNAME target name from its rdata.  * Failsafes; it will change passed dname to a valid dname or do nothing.  * @param rrset: the rrset structure. Must be a CNAME.   *	Only first RR is used (multiple RRs are technically illegal anyway).  * 	Also works on type DNAME. Returns target name.  * @param dname: this pointer is updated to point into the cname rdata.  *	If a failsafe fails, nothing happens to the pointer (such as the  *	rdata was not a valid dname, not a CNAME, ...).  * @param dname_len: length of dname is returned.  */
end_comment

begin_function_decl
name|void
name|get_cname_target
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|dname
parameter_list|,
name|size_t
modifier|*
name|dname_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a printable string for a rrset trust value   * @param s: rrset trust value  * @return printable string.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|rrset_trust_to_string
parameter_list|(
name|enum
name|rrset_trust
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a printable string for a security status value   * @param s: security status  * @return printable string.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|sec_status_to_string
parameter_list|(
name|enum
name|sec_status
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print string with neat domain name, type, class from rrset.  * @param v: at what verbosity level to print this.  * @param str: string of message.  * @param rrset: structure with name, type and class.  */
end_comment

begin_function_decl
name|void
name|log_rrset_key
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert RR from RRset to string.  * @param rrset: structure with data.  * @param i: index of rr or RRSIG.  * @param now: time that is subtracted from ttl before printout. Can be 0.  * @param dest: destination string buffer. Must be nonNULL.  * @param dest_len: length of dest buffer (>0).  * @return false on failure.  */
end_comment

begin_function_decl
name|int
name|packed_rr_to_string
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|size_t
name|i
parameter_list|,
name|time_t
name|now
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|size_t
name|dest_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print the string with prefix, one rr per line.  * @param v: at what verbosity level to print this.  * @param str: string of message.  * @param rrset: with name, and rdata, and rrsigs.  */
end_comment

begin_function_decl
name|void
name|log_packed_rrset
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Allocate rrset in region - no more locks needed   * @param key: a (just from rrset cache looked up) rrset key + valid,  * 	packed data record.  * @param region: where to alloc the copy  * @param now: adjust the TTLs to be relative (subtract from all TTLs).  * @return new region-alloced rrset key or NULL on alloc failure.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|packed_rrset_copy_region
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|key
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Allocate rrset with malloc (from region or you are holding the lock).  * @param key: key with data entry.  * @param alloc: alloc_cache to create rrset_keys  * @param now: adjust the TTLs to be absolute (add to all TTLs).  * @return new region-alloced rrset key or NULL on alloc failure.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|packed_rrset_copy_alloc
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|key
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_DATA_PACKED_RRSET_H */
end_comment

end_unit

