begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/data/msgreply.h - store message and reply data.   *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a data structure to store a message and its reply.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_DATA_MSGREPLY_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_DATA_MSGREPLY_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|alloc_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|edns_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msg_parse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_parse
struct_decl|;
end_struct_decl

begin_comment
comment|/** calculate the prefetch TTL as 90% of original. Calculation  * without numerical overflow (uin32_t) */
end_comment

begin_define
define|#
directive|define
name|PREFETCH_TTL_CALC
parameter_list|(
name|ttl
parameter_list|)
value|((ttl) - (ttl)/10)
end_define

begin_comment
comment|/**  * Structure to store query information that makes answers to queries  * different.  */
end_comment

begin_struct
struct|struct
name|query_info
block|{
comment|/**  	 * Salient data on the query: qname, in wireformat.  	 * can be allocated or a pointer to outside buffer. 	 * User has to keep track on the status of this. 	 */
name|uint8_t
modifier|*
name|qname
decl_stmt|;
comment|/** length of qname (including last 0 octet) */
name|size_t
name|qname_len
decl_stmt|;
comment|/** qtype, host byte order */
name|uint16_t
name|qtype
decl_stmt|;
comment|/** qclass, host byte order */
name|uint16_t
name|qclass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Information to reference an rrset  */
end_comment

begin_struct
struct|struct
name|rrset_ref
block|{
comment|/** the key with lock, and ptr to packed data. */
name|struct
name|ub_packed_rrset_key
modifier|*
name|key
decl_stmt|;
comment|/** id needed */
name|rrset_id_t
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Structure to store DNS query and the reply packet.  * To use it, copy over the flags from reply and modify using flags from  * the query (RD,CD if not AA). prepend ID.   *  * Memory layout is:  *	o struct  *	o rrset_ref array  *	o packed_rrset_key* array.  *  * Memory layout is sometimes not packed, when the message is synthesized,  * for easy of the generation. It is allocated packed when it is copied  * from the region allocation to the malloc allocation.  */
end_comment

begin_struct
struct|struct
name|reply_info
block|{
comment|/** the flags for the answer, host byte order. */
name|uint16_t
name|flags
decl_stmt|;
comment|/** 	 * This flag informs unbound the answer is authoritative and  	 * the AA flag should be preserved.  	 */
name|uint8_t
name|authoritative
decl_stmt|;
comment|/** 	 * Number of RRs in the query section. 	 * If qdcount is not 0, then it is 1, and the data that appears 	 * in the reply is the same as the query_info. 	 * Host byte order. 	 */
name|uint8_t
name|qdcount
decl_stmt|;
comment|/** 32 bit padding to pad struct member alignment to 64 bits. */
name|uint32_t
name|padding
decl_stmt|;
comment|/**  	 * TTL of the entire reply (for negative caching). 	 * only for use when there are 0 RRsets in this message. 	 * if there are RRsets, check those instead. 	 */
name|time_t
name|ttl
decl_stmt|;
comment|/** 	 * TTL for prefetch. After it has expired, a prefetch is suitable. 	 * Smaller than the TTL, otherwise the prefetch would not happen. 	 */
name|time_t
name|prefetch_ttl
decl_stmt|;
comment|/** 	 * The security status from DNSSEC validation of this message. 	 */
name|enum
name|sec_status
name|security
decl_stmt|;
comment|/** 	 * Number of RRsets in each section. 	 * The answer section. Add up the RRs in every RRset to calculate 	 * the number of RRs, and the count for the dns packet.  	 * The number of RRs in RRsets can change due to RRset updates. 	 */
name|size_t
name|an_numrrsets
decl_stmt|;
comment|/** Count of authority section RRsets */
name|size_t
name|ns_numrrsets
decl_stmt|;
comment|/** Count of additional section RRsets */
name|size_t
name|ar_numrrsets
decl_stmt|;
comment|/** number of RRsets: an_numrrsets + ns_numrrsets + ar_numrrsets */
name|size_t
name|rrset_count
decl_stmt|;
comment|/**  	 * List of pointers (only) to the rrsets in the order in which  	 * they appear in the reply message.   	 * Number of elements is ancount+nscount+arcount RRsets. 	 * This is a pointer to that array.  	 * Use the accessor function for access. 	 */
name|struct
name|ub_packed_rrset_key
modifier|*
modifier|*
name|rrsets
decl_stmt|;
comment|/**  	 * Packed array of ids (see counts) and pointers to packed_rrset_key. 	 * The number equals ancount+nscount+arcount RRsets.  	 * These are sorted in ascending pointer, the locking order. So 	 * this list can be locked (and id, ttl checked), to see if  	 * all the data is available and recent enough. 	 * 	 * This is defined as an array of size 1, so that the compiler  	 * associates the identifier with this position in the structure. 	 * Array bound overflow on this array then gives access to the further 	 * elements of the array, which are allocated after the main structure. 	 * 	 * It could be more pure to define as array of size 0, ref[0]. 	 * But ref[1] may be less confusing for compilers. 	 * Use the accessor function for access. 	 */
name|struct
name|rrset_ref
name|ref
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Structure to keep hash table entry for message replies.  */
end_comment

begin_struct
struct|struct
name|msgreply_entry
block|{
comment|/** the hash table key */
name|struct
name|query_info
name|key
decl_stmt|;
comment|/** the hash table entry, data is struct reply_info* */
name|struct
name|lruhash_entry
name|entry
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Parse wire query into a queryinfo structure, return 0 on parse error.   * initialises the (prealloced) queryinfo structure as well.  * This query structure contains a pointer back info the buffer!  * This pointer avoids memory allocation. allocqname does memory allocation.  * @param m: the prealloced queryinfo structure to put query into.  *    must be unused, or _clear()ed.  * @param query: the wireformat packet query. starts with ID.  * @return: 0 on format error.  */
end_comment

begin_function_decl
name|int
name|query_info_parse
parameter_list|(
name|struct
name|query_info
modifier|*
name|m
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse query reply.  * Fills in preallocated query_info structure (with ptr into buffer).  * Allocates reply_info and packed_rrsets. These are not yet added to any  * caches or anything, this is only parsing. Returns formerror on qdcount> 1.  * @param pkt: the packet buffer. Must be positioned after the query section.  * @param alloc: creates packed rrset key structures.  * @param rep: allocated reply_info is returned (only on no error).  * @param qinf: query_info is returned (only on no error).  * @param region: where to store temporary data (for parsing).  * @param edns: where to store edns information, does not need to be inited.  * @return: zero is OK, or DNS error code in case of error  *	o FORMERR for parse errors.  *	o SERVFAIL for memory allocation errors.  */
end_comment

begin_function_decl
name|int
name|reply_info_parse
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
modifier|*
name|rep
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate and decompress parsed message and rrsets.  * @param pkt: for name decompression.  * @param msg: parsed message in scratch region.  * @param alloc: alloc cache for special rrset key structures.  *	Not used if region!=NULL, it can be NULL in that case.  * @param qinf: where to store query info.  *	qinf itself is allocated by the caller.  * @param rep: reply info is allocated and returned.  * @param region: if this parameter is NULL then malloc and the alloc is used.  *	otherwise, everything is allocated in this region.  *	In a region, no special rrset key structures are needed (not shared),  *	and no rrset_ref array in the reply is built up.  * @return 0 if allocation failed.  */
end_comment

begin_function_decl
name|int
name|parse_create_msg
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
modifier|*
name|rep
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Sorts the ref array.  * @param rep: reply info. rrsets must be filled in.  */
end_comment

begin_function_decl
name|void
name|reply_info_sortref
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set TTLs inside the replyinfo to absolute values.  * @param rep: reply info. rrsets must be filled in.   *	Also refs must be filled in.  * @param timenow: the current time.  */
end_comment

begin_function_decl
name|void
name|reply_info_set_ttls
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Delete reply_info and packed_rrsets (while they are not yet added to the  * hashtables.). Returns rrsets to the alloc cache.  * @param rep: reply_info to delete.  * @param alloc: where to return rrset structures to.  */
end_comment

begin_function_decl
name|void
name|reply_info_parsedelete
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two queryinfo structures, on query and type, class.   * It is _not_ sorted in canonical ordering.  * @param m1: struct query_info* , void* here to ease use as function pointer.  * @param m2: struct query_info* , void* here to ease use as function pointer.  * @return: 0 = same, -1 m1 is smaller, +1 m1 is larger.  */
end_comment

begin_function_decl
name|int
name|query_info_compare
parameter_list|(
name|void
modifier|*
name|m1
parameter_list|,
name|void
modifier|*
name|m2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** clear out query info structure */
end_comment

begin_function_decl
name|void
name|query_info_clear
parameter_list|(
name|struct
name|query_info
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** calculate size of struct query_info + reply_info */
end_comment

begin_function_decl
name|size_t
name|msgreply_sizefunc
parameter_list|(
name|void
modifier|*
name|k
parameter_list|,
name|void
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** delete msgreply_entry key structure */
end_comment

begin_function_decl
name|void
name|query_entry_delete
parameter_list|(
name|void
modifier|*
name|q
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** delete reply_info data structure */
end_comment

begin_function_decl
name|void
name|reply_info_delete
parameter_list|(
name|void
modifier|*
name|d
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** calculate hash value of query_info, lowercases the qname */
end_comment

begin_function_decl
name|hashvalue_t
name|query_info_hash
parameter_list|(
name|struct
name|query_info
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup query info entry  * @param q: query info to copy. Emptied as if clear is called.  * @param r: reply to init data.  * @param h: hash value.  * @return: newly allocated message reply cache item.  */
end_comment

begin_function_decl
name|struct
name|msgreply_entry
modifier|*
name|query_info_entrysetup
parameter_list|(
name|struct
name|query_info
modifier|*
name|q
parameter_list|,
name|struct
name|reply_info
modifier|*
name|r
parameter_list|,
name|hashvalue_t
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy reply_info and all rrsets in it and allocate.  * @param rep: what to copy, probably inside region, no ref[] array in it.  * @param alloc: how to allocate rrset keys.  *	Not used if region!=NULL, it can be NULL in that case.  * @param region: if this parameter is NULL then malloc and the alloc is used.  *	otherwise, everything is allocated in this region.  *	In a region, no special rrset key structures are needed (not shared),  *	and no rrset_ref array in the reply is built up.  * @return new reply info or NULL on memory error.  */
end_comment

begin_function_decl
name|struct
name|reply_info
modifier|*
name|reply_info_copy
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy a parsed rrset into given key, decompressing and allocating rdata.  * @param pkt: packet for decompression  * @param msg: the parser message (for flags for trust).  * @param pset: the parsed rrset to copy.  * @param region: if NULL - malloc, else data is allocated in this region.  * @param pk: a freshly obtained rrsetkey structure. No dname is set yet,  *	will be set on return.  *	Note that TTL will still be relative on return.  * @return false on alloc failure.  */
end_comment

begin_function_decl
name|int
name|parse_copy_decompress_rrset
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|rrset_parse
modifier|*
name|pset
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|pk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find final cname target in reply, the one matching qinfo. Follows CNAMEs.  * @param qinfo: what to start with.  * @param rep: looks in answer section of this message.  * @return: pointer dname, or NULL if not found.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|reply_find_final_cname_target
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check if cname chain in cached reply is still valid.  * @param rep: reply to check.  * @return: true if valid, false if invalid.  */
end_comment

begin_function_decl
name|int
name|reply_check_cname_chain
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check security status of all RRs in the message.  * @param rep: reply to check  * @return: true if all RRs are secure. False if not.  *    True if there are zero RRs.  */
end_comment

begin_function_decl
name|int
name|reply_all_rrsets_secure
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find answer rrset in reply, the one matching qinfo. Follows CNAMEs, so the  * result may have a different owner name.  * @param qinfo: what to look for.  * @param rep: looks in answer section of this message.  * @return: pointer to rrset, or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|reply_find_answer_rrset
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find rrset in reply, inside the answer section. Does not follow CNAMEs.  * @param rep: looks in answer section of this message.  * @param name: what to look for.  * @param namelen: length of name.  * @param type: looks for (host order).  * @param dclass: looks for (host order).  * @return: pointer to rrset, or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|reply_find_rrset_section_an
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find rrset in reply, inside the authority section. Does not follow CNAMEs.  * @param rep: looks in authority section of this message.  * @param name: what to look for.  * @param namelen: length of name.  * @param type: looks for (host order).  * @param dclass: looks for (host order).  * @return: pointer to rrset, or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|reply_find_rrset_section_ns
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find rrset in reply, inside any section. Does not follow CNAMEs.  * @param rep: looks in answer,authority and additional section of this message.  * @param name: what to look for.  * @param namelen: length of name.  * @param type: looks for (host order).  * @param dclass: looks for (host order).  * @return: pointer to rrset, or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|reply_find_rrset
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Debug send the query info and reply info to the log in readable form.  * @param str: descriptive string printed with packet content.  * @param qinfo: query section.  * @param rep: rest of message.  */
end_comment

begin_function_decl
name|void
name|log_dns_msg
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print string with neat domain name, type, class from query info.  * @param v: at what verbosity level to print this.  * @param str: string of message.  * @param qinf: query info structure with name, type and class.  */
end_comment

begin_function_decl
name|void
name|log_query_info
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
name|query_info
modifier|*
name|qinf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_DATA_MSGREPLY_H */
end_comment

end_unit

