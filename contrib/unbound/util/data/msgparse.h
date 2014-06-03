begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/data/msgparse.h - parse wireformat DNS messages.  *   * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * Contains message parsing data structures.  * These point back into the packet buffer.  *  * During parsing RRSIGS are put together with the rrsets they (claim to) sign.  * This process works as follows:  *	o if RRSIG follows the data rrset, it is added to the rrset rrsig list.  *	o if no matching data rrset is found, the RRSIG becomes a new rrset.  *	o If the data rrset later follows the RRSIG  *		o See if the RRSIG rrset contains multiple types, and needs to  *		  have the rrsig(s) for that data type split off.  *		o Put the data rr as data type in the rrset and rrsig in list.  *	o RRSIGs are allowed to move to a different section. The section of  *	  the data item is used for the final rrset.  *	o multiple signatures over an RRset are possible.  *  * For queries of qtype=RRSIG, some special handling is needed, to avoid  * splitting the RRSIG in the answer section.  *	o duplicate, not split, RRSIGs from the answer section, if qtype=RRSIG.  *	o check for doubles in the rrsig list when adding an RRSIG to data,  *	  so that a data rrset is signed by RRSIGs with different rdata.  *	  when qtype=RRSIG.  * This will move the RRSIG from the answer section to sign the data further  * in the packet (if possible). If then after that, more RRSIGs are found  * that sign the data as well, doubles are removed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_DATA_MSGPARSE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_DATA_MSGPARSE_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"ldns/pkthdr.h"
end_include

begin_include
include|#
directive|include
file|"ldns/rrdef.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_parse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rr_parse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_comment
comment|/** number of buckets in parse rrset hash table. Must be power of 2. */
end_comment

begin_define
define|#
directive|define
name|PARSE_TABLE_SIZE
value|32
end_define

begin_comment
comment|/** Maximum TTL that is allowed. */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|MAX_TTL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** Minimum TTL that is allowed. */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|MIN_TTL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** Negative cache time (for entries without any RRs.) */
end_comment

begin_define
define|#
directive|define
name|NORR_TTL
value|5
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/**  * Data stored in scratch pad memory during parsing.  * Stores the data that will enter into the msgreply and packet result.  */
end_comment

begin_struct
struct|struct
name|msg_parse
block|{
comment|/** id from message, network format. */
name|uint16_t
name|id
decl_stmt|;
comment|/** flags from message, host format. */
name|uint16_t
name|flags
decl_stmt|;
comment|/** count of RRs, host format */
name|uint16_t
name|qdcount
decl_stmt|;
comment|/** count of RRs, host format */
name|uint16_t
name|ancount
decl_stmt|;
comment|/** count of RRs, host format */
name|uint16_t
name|nscount
decl_stmt|;
comment|/** count of RRs, host format */
name|uint16_t
name|arcount
decl_stmt|;
comment|/** count of RRsets per section. */
name|size_t
name|an_rrsets
decl_stmt|;
comment|/** count of RRsets per section. */
name|size_t
name|ns_rrsets
decl_stmt|;
comment|/** count of RRsets per section. */
name|size_t
name|ar_rrsets
decl_stmt|;
comment|/** total number of rrsets found. */
name|size_t
name|rrset_count
decl_stmt|;
comment|/** query dname (pointer to start location in packet, NULL if none */
name|uint8_t
modifier|*
name|qname
decl_stmt|;
comment|/** length of query dname in octets, 0 if none */
name|size_t
name|qname_len
decl_stmt|;
comment|/** query type, host order. 0 if qdcount=0 */
name|uint16_t
name|qtype
decl_stmt|;
comment|/** query class, host order. 0 if qdcount=0 */
name|uint16_t
name|qclass
decl_stmt|;
comment|/** 	 * Hash table array used during parsing to lookup rrset types. 	 * Based on name, type, class.  Same hash value as in rrset cache. 	 */
name|struct
name|rrset_parse
modifier|*
name|hashtable
index|[
name|PARSE_TABLE_SIZE
index|]
decl_stmt|;
comment|/** linked list of rrsets that have been found (in order). */
name|struct
name|rrset_parse
modifier|*
name|rrset_first
decl_stmt|;
comment|/** last element of rrset list. */
name|struct
name|rrset_parse
modifier|*
name|rrset_last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Data stored for an rrset during parsing.  */
end_comment

begin_struct
struct|struct
name|rrset_parse
block|{
comment|/** next in hash bucket */
name|struct
name|rrset_parse
modifier|*
name|rrset_bucket_next
decl_stmt|;
comment|/** next in list of all rrsets */
name|struct
name|rrset_parse
modifier|*
name|rrset_all_next
decl_stmt|;
comment|/** hash value of rrset */
name|hashvalue_t
name|hash
decl_stmt|;
comment|/** which section was it found in: one of 	 * LDNS_SECTION_ANSWER, LDNS_SECTION_AUTHORITY, LDNS_SECTION_ADDITIONAL 	 */
name|sldns_pkt_section
name|section
decl_stmt|;
comment|/** start of (possibly compressed) dname in packet */
name|uint8_t
modifier|*
name|dname
decl_stmt|;
comment|/** length of the dname uncompressed wireformat */
name|size_t
name|dname_len
decl_stmt|;
comment|/** type, host order. */
name|uint16_t
name|type
decl_stmt|;
comment|/** class, network order. var name so that it is not a c++ keyword. */
name|uint16_t
name|rrset_class
decl_stmt|;
comment|/** the flags for the rrset, like for packedrrset */
name|uint32_t
name|flags
decl_stmt|;
comment|/** number of RRs in the rr list */
name|size_t
name|rr_count
decl_stmt|;
comment|/** sum of RR rdata sizes */
name|size_t
name|size
decl_stmt|;
comment|/** linked list of RRs in this rrset. */
name|struct
name|rr_parse
modifier|*
name|rr_first
decl_stmt|;
comment|/** last in list of RRs in this rrset. */
name|struct
name|rr_parse
modifier|*
name|rr_last
decl_stmt|;
comment|/** number of RRSIGs over this rrset. */
name|size_t
name|rrsig_count
decl_stmt|;
comment|/** linked list of RRsig RRs over this rrset. */
name|struct
name|rr_parse
modifier|*
name|rrsig_first
decl_stmt|;
comment|/** last in list of RRSIG RRs over this rrset. */
name|struct
name|rr_parse
modifier|*
name|rrsig_last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Data stored for an RR during parsing.  */
end_comment

begin_struct
struct|struct
name|rr_parse
block|{
comment|/**  	 * Pointer to the RR. Points to start of TTL value in the packet. 	 * Rdata length and rdata follow it. 	 * its dname, type and class are the same and stored for the rrset. 	 */
name|uint8_t
modifier|*
name|ttl_data
decl_stmt|;
comment|/** true if ttl_data is not part of the packet, but elsewhere in mem. 	 * Set for generated CNAMEs for DNAMEs. */
name|int
name|outside_packet
decl_stmt|;
comment|/** the length of the rdata if allocated (with no dname compression)*/
name|size_t
name|size
decl_stmt|;
comment|/** next in list of RRs. */
name|struct
name|rr_parse
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Check if label length is first octet of a compression pointer, pass u8. */
end_comment

begin_define
define|#
directive|define
name|LABEL_IS_PTR
parameter_list|(
name|x
parameter_list|)
value|( ((x)&0xc0) == 0xc0 )
end_define

begin_comment
comment|/** Calculate destination offset of a compression pointer. pass first and  * second octets of the compression pointer. */
end_comment

begin_define
define|#
directive|define
name|PTR_OFFSET
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( ((x)&0x3f)<<8 | (y) )
end_define

begin_comment
comment|/** create a compression pointer to the given offset. */
end_comment

begin_define
define|#
directive|define
name|PTR_CREATE
parameter_list|(
name|offset
parameter_list|)
value|((uint16_t)(0xc000 | (offset)))
end_define

begin_comment
comment|/** error codes, extended with EDNS, so> 15. */
end_comment

begin_define
define|#
directive|define
name|EDNS_RCODE_BADVERS
value|16
end_define

begin_comment
comment|/** bad EDNS version */
end_comment

begin_comment
comment|/** largest valid compression offset */
end_comment

begin_define
define|#
directive|define
name|PTR_MAX_OFFSET
value|0x3fff
end_define

begin_comment
comment|/**  * EDNS data storage  * EDNS rdata is ignored.  */
end_comment

begin_struct
struct|struct
name|edns_data
block|{
comment|/** if EDNS OPT record was present */
name|int
name|edns_present
decl_stmt|;
comment|/** Extended RCODE */
name|uint8_t
name|ext_rcode
decl_stmt|;
comment|/** The EDNS version number */
name|uint8_t
name|edns_version
decl_stmt|;
comment|/** the EDNS bits field from ttl (host order): Z */
name|uint16_t
name|bits
decl_stmt|;
comment|/** UDP reassembly size. */
name|uint16_t
name|udp_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Obtain size in the packet of an rr type, that is before dname type.  * Do TYPE_DNAME, and type STR, yourself. Gives size for most regular types.  * @param rdf: the rdf type from the descriptor.  * @return: size in octets. 0 on failure.  */
end_comment

begin_function_decl
name|size_t
name|get_rdf_size
parameter_list|(
name|sldns_rdf_type
name|rdf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the packet.  * @param pkt: packet, position at call must be at start of packet.  *	at end position is after packet.  * @param msg: where to store results.  * @param region: how to alloc results.  * @return: 0 if OK, or rcode on error.  */
end_comment

begin_function_decl
name|int
name|parse_packet
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
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * After parsing the packet, extract EDNS data from packet.  * If not present this is noted in the data structure.  * If a parse error happens, an error code is returned.  *  * Quirks:  *	o ignores OPT rdata.  *	o ignores OPT owner name.  *	o ignores extra OPT records, except the last one in the packet.  *  * @param msg: parsed message structure. Modified on exit, if EDNS was present  * 	it is removed from the additional section.  * @param edns: the edns data is stored here. Does not have to be initialised.  * @return: 0 on success. or an RCODE on an error.  *	RCODE formerr if OPT in wrong section, and so on.  */
end_comment

begin_function_decl
name|int
name|parse_extract_edns
parameter_list|(
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * If EDNS data follows a query section, extract it and initialize edns struct.  * @param pkt: the packet. position at start must be right after the query  *	section. At end, right after EDNS data or no movement if failed.  * @param edns: the edns data allocated by the caller. Does not have to be  *	initialised.  * @return: 0 on success, or an RCODE on error.  *	RCODE formerr if OPT is badly formatted and so on.  */
end_comment

begin_function_decl
name|int
name|parse_edns_from_pkt
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Calculate hash value for rrset in packet.  * @param pkt: the packet.  * @param dname: pointer to uncompressed dname, or compressed dname in packet.  * @param type: rrset type in host order.  * @param dclass: rrset class in network order.  * @param rrset_flags: rrset flags (same as packed_rrset flags).  * @return hash value  */
end_comment

begin_function_decl
name|hashvalue_t
name|pkt_hash_rrset
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|uint32_t
name|rrset_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup in msg hashtable to find a rrset.  * @param msg: with the hashtable.  * @param pkt: packet for compressed names.  * @param h: hash value  * @param rrset_flags: flags of rrset sought for.  * @param dname: name of rrset sought for.  * @param dnamelen: len of dname.  * @param type: rrset type, host order.  * @param dclass: rrset class, network order.  * @return NULL or the rrset_parse if found.  */
end_comment

begin_function_decl
name|struct
name|rrset_parse
modifier|*
name|msgparse_hashtable_lookup
parameter_list|(
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|hashvalue_t
name|h
parameter_list|,
name|uint32_t
name|rrset_flags
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
name|dnamelen
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
comment|/**  * Remove rrset from hash table.  * @param msg: with hashtable.  * @param rrset: with hash value and id info.  */
end_comment

begin_function_decl
name|void
name|msgparse_bucket_remove
parameter_list|(
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|rrset_parse
modifier|*
name|rrset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_DATA_MSGPARSE_H */
end_comment

end_unit

