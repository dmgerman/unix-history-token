begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/data/msgencode.h - encode compressed DNS messages.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains temporary data structures and routines to create  * compressed DNS messages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_DATA_MSGENCODE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_DATA_MSGENCODE_H
end_define

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
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

begin_comment
comment|/**   * Generate answer from reply_info.  * @param qinf: query information that provides query section in packet.  * @param rep: reply to fill in.  * @param id: id word from the query.  * @param qflags: flags word from the query.  * @param dest: buffer to put message into; will truncate if it does not fit.  * @param timenow: time to subtract.  * @param cached: set true if a cached reply (so no AA bit).  *	set false for the first reply.  * @param region: where to allocate temp variables (for compression).  * @param udpsize: size of the answer, 512, from EDNS, or 64k for TCP.  * @param edns: EDNS data included in the answer, NULL for none.  *	or if edns_present = 0, it is not included.  * @param dnssec: if 0 DNSSEC records are omitted from the answer.  * @param secure: if 1, the AD bit is set in the reply.  * @return: 0 on error (server failure).  */
end_comment

begin_function_decl
name|int
name|reply_info_answer_encode
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint16_t
name|id
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|dest
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|int
name|cached
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint16_t
name|udpsize
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|int
name|dnssec
parameter_list|,
name|int
name|secure
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Regenerate the wireformat from the stored msg reply.  * If the buffer is too small then the message is truncated at a whole  * rrset and the TC bit set, or whole rrsets are left out of the additional  * and the TC bit is not set.  * @param qinfo: query info to store.  * @param rep: reply to store.  * @param id: id value to store, network order.  * @param flags: flags value to store, host order.  * @param buffer: buffer to store the packet into.  * @param timenow: time now, to adjust ttl values.  * @param region: to store temporary data in.  * @param udpsize: size of the answer, 512, from EDNS, or 64k for TCP.  * @param dnssec: if 0 DNSSEC records are omitted from the answer.  * @return: nonzero is success, or   *	0 on error: malloc failure (no log_err has been done).  */
end_comment

begin_function_decl
name|int
name|reply_info_encode
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
parameter_list|,
name|uint16_t
name|id
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buffer
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint16_t
name|udpsize
parameter_list|,
name|int
name|dnssec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Encode query packet. Assumes the buffer is large enough.  * @param pkt: where to store the packet.  * @param qinfo: query info.  */
end_comment

begin_function_decl
name|void
name|qinfo_query_encode
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Estimate size of EDNS record in packet. EDNS record will be no larger.  * @param edns: edns data or NULL.  * @return octets to reserve for EDNS.  */
end_comment

begin_function_decl
name|uint16_t
name|calc_edns_field_size
parameter_list|(
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Attach EDNS record to buffer. Buffer has complete packet. There must  * be enough room left for the EDNS record.  * @param pkt: packet added to.  * @param edns: if NULL or present=0, nothing is added to the packet.  */
end_comment

begin_function_decl
name|void
name|attach_edns_record
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
comment|/**   * Encode an error. With QR and RA set.  *  * @param pkt: where to store the packet.  * @param r: RCODE value to encode.  * @param qinfo: if not NULL, the query is included.  * @param qid: query ID to set in packet. network order.  * @param qflags: original query flags (to copy RD and CD bits). host order.  * @param edns: if not NULL, this is the query edns info,  * 	and an edns reply is attached. Only attached if EDNS record fits reply.  */
end_comment

begin_function_decl
name|void
name|error_encode
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|int
name|r
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qid
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_DATA_MSGENCODE_H */
end_comment

end_unit

