begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/cache/dns.h - Cache services for DNS using msg and rrset caches.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the DNS cache.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_CACHE_DNS_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_CACHE_DNS_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgreply.h"
end_include

begin_struct_decl
struct_decl|struct
name|module_env
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
name|delegpt
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Region allocated message reply  */
end_comment

begin_struct
struct|struct
name|dns_msg
block|{
comment|/** query info */
name|struct
name|query_info
name|qinfo
decl_stmt|;
comment|/** reply info - ptr to packed repinfo structure */
name|struct
name|reply_info
modifier|*
name|rep
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Allocate a dns_msg with malloc/alloc structure and store in dns cache.  *  * @param env: environment, with alloc structure and dns cache.  * @param qinf: query info, the query for which answer is stored.  * 	this is allocated in a region, and will be copied to malloc area  * 	before insertion.  * @param rep: reply in dns_msg from dns_alloc_msg for example.  * 	this is allocated in a region, and will be copied to malloc area  * 	before insertion.  * @param is_referral: If true, then the given message to be stored is a  *      referral. The cache implementation may use this as a hint.  *      It will store only the RRsets, not the message.  * @param leeway: TTL value, if not 0, other rrsets are considered expired  *	that many seconds before actual TTL expiry.  * @param pside: if true, information came from a server which was fetched  * 	from the parentside of the zonecut.  This means that the type NS  * 	can be updated to full TTL even in prefetch situations.  * @param region: region to allocate better entries from cache into.  *   (used when is_referral is false).  * @return 0 on alloc error (out of memory).  */
end_comment

begin_function_decl
name|int
name|dns_cache_store
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
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
name|int
name|is_referral
parameter_list|,
name|time_t
name|leeway
parameter_list|,
name|int
name|pside
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Store message in the cache. Stores in message cache and rrset cache.  * Both qinfo and rep should be malloced and are put in the cache.  * They should not be used after this call, as they are then in shared cache.  * Does not return errors, they are logged and only lead to less cache.  *  * @param env: module environment with the DNS cache.  * @param qinfo: query info  * @param hash: hash over qinfo.  * @param rep: reply info, together with qinfo makes up the message.  *	Adjusts the reply info TTLs to absolute time.  * @param leeway: TTL value, if not 0, other rrsets are considered expired  *	that many seconds before actual TTL expiry.  * @param pside: if true, information came from a server which was fetched  * 	from the parentside of the zonecut.  This means that the type NS  * 	can be updated to full TTL even in prefetch situations.  * @param qrep: message that can be altered with better rrs from cache.  * @param region: to allocate into for qmsg.  */
end_comment

begin_function_decl
name|void
name|dns_cache_store_msg
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|time_t
name|leeway
parameter_list|,
name|int
name|pside
parameter_list|,
name|struct
name|reply_info
modifier|*
name|qrep
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find a delegation from the cache.  * @param env: module environment with the DNS cache.  * @param qname: query name.  * @param qnamelen: length of qname.  * @param qtype: query type.  * @param qclass: query class.  * @param region: where to allocate result delegation.  * @param msg: if not NULL, delegation message is returned here, synthesized  *	from the cache.  * @param timenow: the time now, for checking if TTL on cache entries is OK.  * @return new delegation or NULL on error or if not found in cache.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|dns_cache_find_delegation
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|dns_msg
modifier|*
modifier|*
name|msg
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Find cached message   * @param env: module environment with the DNS cache.  * @param qname: query name.  * @param qnamelen: length of qname.  * @param qtype: query type.  * @param qclass: query class.  * @param region: where to allocate result.  * @param scratch: where to allocate temporary data.  * @return new response message (alloced in region, rrsets do not have IDs).  * 	or NULL on error or if not found in cache.  *	TTLs are made relative to the current time.  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|dns_cache_lookup
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|regional
modifier|*
name|scratch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * find and add A and AAAA records for missing nameservers in delegpt   * @param env: module environment with rrset cache  * @param qclass: which class to look in.  * @param region: where to store new dp info.  * @param dp: delegation point to fill missing entries.  * @return false on alloc failure.  */
end_comment

begin_function_decl
name|int
name|cache_fill_missing
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Utility, create new, unpacked data structure for cache response.  * QR bit set, no AA. Query set as indicated. Space for number of rrsets.  * @param qname: query section name  * @param qnamelen: len of qname  * @param qtype: query section type  * @param qclass: query section class  * @param region: where to alloc.  * @param capacity: number of rrsets space to create in the array.  * @return new dns_msg struct or NULL on mem fail.  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|dns_msg_create
parameter_list|(
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|size_t
name|capacity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add rrset to authority section in unpacked dns_msg message. Must have enough  * space left, does not grow the array.  * @param msg: msg to put it in.  * @param region: region to alloc in  * @param rrset: to add in authority section  * @param now: now.  * @return true if worked, false on fail  */
end_comment

begin_function_decl
name|int
name|dns_msg_authadd
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
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
comment|/* SERVICES_CACHE_DNS_H */
end_comment

end_unit

