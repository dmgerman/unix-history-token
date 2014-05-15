begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/data/dname.h - domain name routines  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to deal with domain names (dnames).  *  * Some of the functions deal with domain names as a wireformat buffer,  * with a length.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_DATA_DNAME_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_DATA_DNAME_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/** max number of compression ptrs to follow */
end_comment

begin_define
define|#
directive|define
name|MAX_COMPRESS_PTRS
value|256
end_define

begin_comment
comment|/**   * Determine length of dname in buffer, no compression ptrs allowed,   * @param query: the ldns buffer, current position at start of dname.  *	at end, position is at end of the dname.  * @return: 0 on parse failure, or length including ending 0 of dname.   */
end_comment

begin_function_decl
name|size_t
name|query_dname_len
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if dname in memory is correct. no compression ptrs allowed.  * @param dname: where dname starts in memory.  * @param len: dname is not allowed to exceed this length (i.e. of allocation).  * @return length of dname if dname is ok, 0 on a parse error.  */
end_comment

begin_function_decl
name|size_t
name|dname_valid
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** lowercase query dname */
end_comment

begin_function_decl
name|void
name|query_dname_tolower
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * lowercase pkt dname (follows compression pointers)  * @param pkt: the packet, used to follow compression pointers. Position   *	is unchanged.  * @param dname: start of dname in packet.  */
end_comment

begin_function_decl
name|void
name|pkt_dname_tolower
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare query dnames (uncompressed storage). The Dnames passed do not  * have to be lowercased, comparison routine does this.  *  * This routine is special, in that the comparison that it does corresponds  * with the canonical comparison needed when comparing dnames inside rdata  * for RR types that need canonicalization. That means that the first byte  * that is smaller (possibly after lowercasing) makes an RR smaller, or the  * shortest name makes an RR smaller.  *  * This routine does not compute the canonical order needed for NSEC   * processing.  *  * Dnames have to be valid format.  * @param d1: dname to compare  * @param d2: dname to compare  * @return: -1, 0, or +1 depending on comparison results.  * 	Sort order is first difference found. not the canonical ordering.  */
end_comment

begin_function_decl
name|int
name|query_dname_compare
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine correct, compressed, dname present in packet.  * Checks for parse errors.  * @param pkt: packet to read from (from current start position).  * @return: 0 on parse error.  *	At exit the position is right after the (compressed) dname.  *	Compression pointers are followed and checked for loops.  *	The uncompressed wireformat length is returned.  */
end_comment

begin_function_decl
name|size_t
name|pkt_dname_len
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare dnames in packet (compressed). Dnames must be valid.  * routine performs lowercasing, so the packet casing is preserved.  * @param pkt: packet, used to resolve compression pointers.  * @param d1: dname to compare  * @param d2: dname to compare  * @return: -1, 0, or +1 depending on comparison results.  * 	Sort order is first difference found. not the canonical ordering.  */
end_comment

begin_function_decl
name|int
name|dname_pkt_compare
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Hash dname, label by label, lowercasing, into hashvalue.  * Dname in query format (not compressed).  * @param dname: dname to hash.  * @param h: initial hash value.  * @return: result hash value.  */
end_comment

begin_function_decl
name|hashvalue_t
name|dname_query_hash
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|hashvalue_t
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Hash dname, label by label, lowercasing, into hashvalue.  * Dname in pkt format (compressed).  * @param pkt: packet, for resolving compression pointers.  * @param dname: dname to hash, pointer to the pkt buffer.  * 	Must be valid format. No loops, etc.  * @param h: initial hash value.  * @return: result hash value.  * 	Result is the same as dname_query_hash, even if compression is used.  */
end_comment

begin_function_decl
name|hashvalue_t
name|dname_pkt_hash
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
name|hashvalue_t
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy over a valid dname and decompress it.  * @param pkt: packet to resolve compression pointers.  * @param to: buffer of size from pkt_len function to hold result.  * @param dname: pointer into packet where dname starts.  */
end_comment

begin_function_decl
name|void
name|dname_pkt_copy
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|to
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy over a valid dname to a packet.  * @param pkt: packet to copy to.  * @param dname: dname to copy.  * @return: 0 if not enough space in buffer.  */
end_comment

begin_function_decl
name|int
name|dname_buffer_write
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Count the number of labels in an uncompressed dname in memory.  * @param dname: pointer to uncompressed dname.  * @return: count of labels, including root label, "com." has 2 labels.  */
end_comment

begin_function_decl
name|int
name|dname_count_labels
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Count labels and dname length both, for uncompressed dname in memory.  * @param dname: pointer to uncompressed dname.  * @param size: length of dname, including root label.  * @return: count of labels, including root label, "com." has 2 labels.  */
end_comment

begin_function_decl
name|int
name|dname_count_size_labels
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare dnames, sorted not canonical, but by label.  * Such that zone contents follows zone apex.  * @param d1: first dname. pointer to uncompressed wireformat.  * @param labs1: number of labels in first dname.  * @param d2: second dname. pointer to uncompressed wireformat.  * @param labs2: number of labels in second dname.  * @param mlabs: number of labels that matched exactly (the shared topdomain).  * @return: 0 for equal, -1 smaller, or +1 d1 larger than d2.  */
end_comment

begin_function_decl
name|int
name|dname_lab_cmp
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|int
name|labs1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|,
name|int
name|labs2
parameter_list|,
name|int
modifier|*
name|mlabs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if domain name d1 is a strict subdomain of d2.  * That is a subdomain, but not equal.   * @param d1: domain name, uncompressed wireformat  * @param labs1: number of labels in d1, including root label.  * @param d2: domain name, uncompressed wireformat  * @param labs2: number of labels in d2, including root label.  * @return true if d1 is a subdomain of d2, but not equal to d2.  */
end_comment

begin_function_decl
name|int
name|dname_strict_subdomain
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|int
name|labs1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|,
name|int
name|labs2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Like dname_strict_subdomain but counts labels   * @param d1: domain name, uncompressed wireformat  * @param d2: domain name, uncompressed wireformat  * @return true if d1 is a subdomain of d2, but not equal to d2.  */
end_comment

begin_function_decl
name|int
name|dname_strict_subdomain_c
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Counts labels. Tests is d1 is a subdomain of d2.  * @param d1: domain name, uncompressed wireformat  * @param d2: domain name, uncompressed wireformat  * @return true if d1 is a subdomain of d2.  */
end_comment

begin_function_decl
name|int
name|dname_subdomain_c
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Debug helper. Print wireformat dname to output.   * @param out: like stdout or a file.  * @param pkt: if not NULL, the packet for resolving compression ptrs.  * @param dname: pointer to (start of) dname.  */
end_comment

begin_function_decl
name|void
name|dname_print
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Debug helper. Print dname to given string buffer (string buffer must  * be at least 255 chars + 1 for the 0, in printable form.  * This may lose information (? for nonprintable characters, or& if  * the name is too long, # for a bad label length).  * @param dname: uncompressed wireformat.  * @param str: buffer of 255+1 length.  */
end_comment

begin_function_decl
name|void
name|dname_str
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns true if the uncompressed wireformat dname is the root "."  * @param dname: the dname to check  * @return true if ".", false if not.  */
end_comment

begin_function_decl
name|int
name|dname_is_root
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Snip off first label from a dname, returning the parent zone.  * @param dname: from what to strip off. uncompressed wireformat.  * @param len: length, adjusted to become less.  * @return stripped off, or "." if input was ".".  */
end_comment

begin_function_decl
name|void
name|dname_remove_label
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dname
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Snip off first N labels from a dname, returning the parent zone.  * @param dname: from what to strip off. uncompressed wireformat.  * @param len: length, adjusted to become less.  * @param n: number of labels to strip off (from the left).  * 	if 0, nothing happens.  * @return stripped off, or "." if input was ".".  */
end_comment

begin_function_decl
name|void
name|dname_remove_labels
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dname
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Count labels for the RRSIG signature label field.  * Like a normal labelcount, but "*" wildcard and "." root are not counted.  * @param dname: valid uncompressed wireformat.  * @return number of labels like in RRSIG; '*' and '.' are not counted.  */
end_comment

begin_function_decl
name|int
name|dname_signame_label_count
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return true if the label is a wildcard, *.example.com.  * @param dname: valid uncompressed wireformat.  * @return true if wildcard, or false.  */
end_comment

begin_function_decl
name|int
name|dname_is_wild
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare dnames, Canonical in rfc4034 sense, but by label.  * Such that zone contents follows zone apex.  *  * @param d1: first dname. pointer to uncompressed wireformat.  * @param labs1: number of labels in first dname.  * @param d2: second dname. pointer to uncompressed wireformat.  * @param labs2: number of labels in second dname.  * @param mlabs: number of labels that matched exactly (the shared topdomain).  * @return: 0 for equal, -1 smaller, or +1 d1 larger than d2.  */
end_comment

begin_function_decl
name|int
name|dname_canon_lab_cmp
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|int
name|labs1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|,
name|int
name|labs2
parameter_list|,
name|int
modifier|*
name|mlabs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Canonical dname compare. Takes care of counting labels.  * Per rfc 4034 canonical order.  *  * @param d1: first dname. pointer to uncompressed wireformat.  * @param d2: second dname. pointer to uncompressed wireformat.  * @return: 0 for equal, -1 smaller, or +1 d1 larger than d2.  */
end_comment

begin_function_decl
name|int
name|dname_canonical_compare
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the shared topdomain between two names. Root "." or longer.  * @param d1: first dname. pointer to uncompressed wireformat.  * @param d2: second dname. pointer to uncompressed wireformat.  * @return pointer to shared topdomain. Ptr to a part of d1.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|dname_get_shared_topdomain
parameter_list|(
name|uint8_t
modifier|*
name|d1
parameter_list|,
name|uint8_t
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_DATA_DNAME_H */
end_comment

end_unit

