begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_nsec3.h - validator NSEC3 denial of existance functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  * The functions help with NSEC3 checking, the different NSEC3 proofs  * for denial of existance, and proofs for presence of types.  *  * NSEC3  *                      1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3  *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |   Hash Alg.   |     Flags     |          Iterations           |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |  Salt Length  |                     Salt                      /  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |  Hash Length  |             Next Hashed Owner Name            /  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * /                         Type Bit Maps                         /  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  * NSEC3PARAM  *                      1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3  *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |   Hash Alg.   |     Flags     |          Iterations           |  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  * |  Salt Length  |                     Salt                      /  * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_NSEC3_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_NSEC3_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|val_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_entry_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  *     0 1 2 3 4 5 6 7  *    +-+-+-+-+-+-+-+-+  *    |             |O|  *    +-+-+-+-+-+-+-+-+  * The OPT-OUT bit in the NSEC3 flags field.  * If enabled, there can be zero or more unsigned delegations in the span.  * If disabled, there are zero unsigned delegations in the span.  */
end_comment

begin_define
define|#
directive|define
name|NSEC3_OPTOUT
value|0x01
end_define

begin_comment
comment|/**  * The unknown flags in the NSEC3 flags field.  * They must be zero, or the NSEC3 is ignored.  */
end_comment

begin_define
define|#
directive|define
name|NSEC3_UNKNOWN_FLAGS
value|0xFE
end_define

begin_comment
comment|/** The SHA1 hash algorithm for NSEC3 */
end_comment

begin_define
define|#
directive|define
name|NSEC3_HASH_SHA1
value|0x01
end_define

begin_comment
comment|/**  * Determine if the set of NSEC3 records provided with a response prove NAME  * ERROR. This means that the NSEC3s prove a) the closest encloser exists,  * b) the direct child of the closest encloser towards qname doesn't exist,  * and c) *.closest encloser does not exist.  *  * @param env: module environment with temporary region and buffer.  * @param ve: validator environment, with iteration count settings.  * @param list: array of RRsets, some of which are NSEC3s.  * @param num: number of RRsets in the array to examine.  * @param qinfo: query that is verified for.  * @param kkey: key entry that signed the NSEC3s.  * @return:  * 	sec_status SECURE of the Name Error is proven by the NSEC3 RRs,   * 	BOGUS if not, INSECURE if all of the NSEC3s could be validly ignored.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|nsec3_prove_nameerror
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|list
parameter_list|,
name|size_t
name|num
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if the NSEC3s provided in a response prove the NOERROR/NODATA  * status. There are a number of different variants to this:  *   * 1) Normal NODATA -- qname is matched to an NSEC3 record, type is not  * present.  *   * 2) ENT NODATA -- because there must be NSEC3 record for  * empty-non-terminals, this is the same as #1.  *   * 3) NSEC3 ownername NODATA -- qname matched an existing, lone NSEC3  * ownername, but qtype was not NSEC3. NOTE: as of nsec-05, this case no  * longer exists.  *   * 4) Wildcard NODATA -- A wildcard matched the name, but not the type.  *   * 5) Opt-In DS NODATA -- the qname is covered by an opt-in span and qtype ==  * DS. (or maybe some future record with the same parent-side-only property)  *  * @param env: module environment with temporary region and buffer.  * @param ve: validator environment, with iteration count settings.  * @param list: array of RRsets, some of which are NSEC3s.  * @param num: number of RRsets in the array to examine.  * @param qinfo: query that is verified for.  * @param kkey: key entry that signed the NSEC3s.  * @return:  * 	sec_status SECURE of the proposition is proven by the NSEC3 RRs,   * 	BOGUS if not, INSECURE if all of the NSEC3s could be validly ignored.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|nsec3_prove_nodata
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|list
parameter_list|,
name|size_t
name|num
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prove that a positive wildcard match was appropriate (no direct match  * RRset).  *  * @param env: module environment with temporary region and buffer.  * @param ve: validator environment, with iteration count settings.  * @param list: array of RRsets, some of which are NSEC3s.  * @param num: number of RRsets in the array to examine.  * @param qinfo: query that is verified for.  * @param kkey: key entry that signed the NSEC3s.  * @param wc: The purported wildcard that matched. This is the wildcard name  * 	as *.wildcard.name., with the *. label already removed.  * @return:  * 	sec_status SECURE of the proposition is proven by the NSEC3 RRs,   * 	BOGUS if not, INSECURE if all of the NSEC3s could be validly ignored.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|nsec3_prove_wildcard
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|list
parameter_list|,
name|size_t
name|num
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|uint8_t
modifier|*
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prove that a DS response either had no DS, or wasn't a delegation point.  *  * Fundamentally there are two cases here: normal NODATA and Opt-In NODATA.  *  * @param env: module environment with temporary region and buffer.  * @param ve: validator environment, with iteration count settings.  * @param list: array of RRsets, some of which are NSEC3s.  * @param num: number of RRsets in the array to examine.  * @param qinfo: query that is verified for.  * @param kkey: key entry that signed the NSEC3s.  * @param reason: string for bogus result.  * @return:  * 	sec_status SECURE of the proposition is proven by the NSEC3 RRs,   * 	BOGUS if not, INSECURE if all of the NSEC3s could be validly ignored.  * 	or if there was no DS in an insecure (i.e., opt-in) way,  * 	INDETERMINATE if it was clear that this wasn't a delegation point.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|nsec3_prove_nods
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|list
parameter_list|,
name|size_t
name|num
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prove NXDOMAIN or NODATA.  *  * @param env: module environment with temporary region and buffer.  * @param ve: validator environment, with iteration count settings.  * @param list: array of RRsets, some of which are NSEC3s.  * @param num: number of RRsets in the array to examine.  * @param qinfo: query that is verified for.  * @param kkey: key entry that signed the NSEC3s.  * @param nodata: if return value is secure, this indicates if nodata or  * 	nxdomain was proven.  * @return:  * 	sec_status SECURE of the proposition is proven by the NSEC3 RRs,   * 	BOGUS if not, INSECURE if all of the NSEC3s could be validly ignored.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|nsec3_prove_nxornodata
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|list
parameter_list|,
name|size_t
name|num
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|int
modifier|*
name|nodata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * The NSEC3 hash result storage.  * Consists of an rbtree, with these nodes in it.  * The nodes detail how a set of parameters (from nsec3 rr) plus  * a dname result in a hash.  */
end_comment

begin_struct
struct|struct
name|nsec3_cached_hash
block|{
comment|/** rbtree node, key is this structure */
name|rbnode_t
name|node
decl_stmt|;
comment|/** where are the parameters for conversion, in this rrset data */
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec3
decl_stmt|;
comment|/** where are the parameters for conversion, this RR number in data */
name|int
name|rr
decl_stmt|;
comment|/** the name to convert */
name|uint8_t
modifier|*
name|dname
decl_stmt|;
comment|/** length of the dname */
name|size_t
name|dname_len
decl_stmt|;
comment|/** the hash result (not base32 encoded) */
name|uint8_t
modifier|*
name|hash
decl_stmt|;
comment|/** length of hash in bytes */
name|size_t
name|hash_len
decl_stmt|;
comment|/** the hash result in base32 encoding */
name|uint8_t
modifier|*
name|b32
decl_stmt|;
comment|/** length of base32 encoding (as a label) */
name|size_t
name|b32_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Rbtree for hash cache comparison function.  * @param c1: key 1.  * @param c2: key 2.  * @return: comparison code, -1, 0, 1, of the keys.  */
end_comment

begin_function_decl
name|int
name|nsec3_hash_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|c1
parameter_list|,
specifier|const
name|void
modifier|*
name|c2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain the hash of an owner name.  * Used internally by the nsec3 proof functions in this file.  * published to enable unit testing of hash algorithms and cache.  *  * @param table: the cache table. Must be inited at start.  * @param region: scratch region to use for allocation.  * 	This region holds the tree, if you wipe the region, reinit the tree.  * @param buf: temporary buffer.  * @param nsec3: the rrset with parameters  * @param rr: rr number from d that has the NSEC3 parameters to hash to.  * @param dname: name to hash  * 	This pointer is used inside the tree, assumed region-alloced.  * @param dname_len: the length of the name.  * @param hash: the hash node is returned on success.  * @return:  * 	1 on success, either from cache or newly hashed hash is returned.  * 	0 on a malloc failure.  * 	-1 if the NSEC3 rr was badly formatted (i.e. formerr).  */
end_comment

begin_function_decl
name|int
name|nsec3_hash_name
parameter_list|(
name|rbtree_t
modifier|*
name|table
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec3
parameter_list|,
name|int
name|rr
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
name|dname_len
parameter_list|,
name|struct
name|nsec3_cached_hash
modifier|*
modifier|*
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get next owner name, converted to base32 encoding and with the  * zone name (taken from the nsec3 owner name) appended.  * @param rrset: the NSEC3 rrset.  * @param r: the rr num of the nsec3 in the rrset.  * @param buf: buffer to store name in  * @param max: size of buffer.  * @return length of name on success. 0 on failure (buffer too short or  *	bad format nsec3 record).  */
end_comment

begin_function_decl
name|size_t
name|nsec3_get_nextowner_b32
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|r
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert hash into base32 encoding and with the  * zone name appended.  * @param hash: hashed buffer  * @param hashlen: length of hash  * @param zone: name of zone  * @param zonelen: length of zonename.  * @param buf: buffer to store name in  * @param max: size of buffer.  * @return length of name on success. 0 on failure (buffer too short or  *	bad format nsec3 record).  */
end_comment

begin_function_decl
name|size_t
name|nsec3_hash_to_b32
parameter_list|(
name|uint8_t
modifier|*
name|hash
parameter_list|,
name|size_t
name|hashlen
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|size_t
name|zonelen
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Get NSEC3 parameters out of rr.  * @param rrset: the NSEC3 rrset.  * @param r: the rr num of the nsec3 in the rrset.  * @param algo: nsec3 hash algo.  * @param iter: iteration count.  * @param salt: ptr to salt inside rdata.  * @param saltlen: length of salt.  * @return 0 if bad formatted, unknown nsec3 hash algo, or unknown flags set.  */
end_comment

begin_function_decl
name|int
name|nsec3_get_params
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|r
parameter_list|,
name|int
modifier|*
name|algo
parameter_list|,
name|size_t
modifier|*
name|iter
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|salt
parameter_list|,
name|size_t
modifier|*
name|saltlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get NSEC3 hashed in a buffer  * @param buf: buffer for temp use.  * @param nm: name to hash  * @param nmlen: length of nm.  * @param algo: algo to use, must be known.  * @param iter: iterations  * @param salt: salt for nsec3  * @param saltlen: length of salt.  * @param res: result of hash stored here.  * @param max: maximum space for result.  * @return 0 on failure, otherwise bytelength stored.  */
end_comment

begin_function_decl
name|size_t
name|nsec3_get_hashed
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|nmlen
parameter_list|,
name|int
name|algo
parameter_list|,
name|size_t
name|iter
parameter_list|,
name|uint8_t
modifier|*
name|salt
parameter_list|,
name|size_t
name|saltlen
parameter_list|,
name|uint8_t
modifier|*
name|res
parameter_list|,
name|size_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * see if NSEC3 RR contains given type  * @param rrset: NSEC3 rrset  * @param r: RR in rrset  * @param type: in host order to check bit for.  * @return true if bit set, false if not or error.  */
end_comment

begin_function_decl
name|int
name|nsec3_has_type
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|r
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * return if nsec3 RR has the optout flag   * @param rrset: NSEC3 rrset  * @param r: RR in rrset  * @return true if optout, false on error or not optout  */
end_comment

begin_function_decl
name|int
name|nsec3_has_optout
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Return nsec3 RR next hashed owner name   * @param rrset: NSEC3 rrset  * @param r: RR in rrset  * @param next: ptr into rdata to next owner hash  * @param nextlen: length of hash.  * @return false on malformed  */
end_comment

begin_function_decl
name|int
name|nsec3_get_nextowner
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|r
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|next
parameter_list|,
name|size_t
modifier|*
name|nextlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * nsec3Covers  * Given a hash and a candidate NSEC3Record, determine if that NSEC3Record  * covers the hash. Covers specifically means that the hash is in between  * the owner and next hashes and does not equal either.  *  * @param zone: the zone name.  * @param hash: the hash of the name  * @param rrset: the rrset of the NSEC3.  * @param rr: which rr in the rrset.  * @param buf: temporary buffer.  * @return true if covers, false if not.  */
end_comment

begin_function_decl
name|int
name|nsec3_covers
parameter_list|(
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|struct
name|nsec3_cached_hash
modifier|*
name|hash
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|int
name|rr
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_NSEC3_H */
end_comment

end_unit

