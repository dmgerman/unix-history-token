begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_delegpt.h - delegation point with NS and address information.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file implements the Delegation Point. It contains a list of name servers  * and their addresses if known.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_DELEGPT_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_DELEGPT_H
end_define

begin_include
include|#
directive|include
file|"util/log.h"
end_include

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt_ns
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dns_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msgreply_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Delegation Point.  * For a domain name, the NS rrset, and the A and AAAA records for those.  */
end_comment

begin_struct
struct|struct
name|delegpt
block|{
comment|/** the domain name of the delegation point. */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of the delegation point name */
name|size_t
name|namelen
decl_stmt|;
comment|/** number of labels in delegation point */
name|int
name|namelabs
decl_stmt|;
comment|/** the nameservers, names from the NS RRset rdata. */
name|struct
name|delegpt_ns
modifier|*
name|nslist
decl_stmt|;
comment|/** the target addresses for delegation */
name|struct
name|delegpt_addr
modifier|*
name|target_list
decl_stmt|;
comment|/** the list of usable targets; subset of target_list  	 * the items in this list are not part of the result list.  */
name|struct
name|delegpt_addr
modifier|*
name|usable_list
decl_stmt|;
comment|/** the list of returned targets; subset of target_list */
name|struct
name|delegpt_addr
modifier|*
name|result_list
decl_stmt|;
comment|/** if true, the NS RRset was bogus. All info is bad. */
name|int
name|bogus
decl_stmt|;
comment|/** if true, the parent-side NS record has been applied: 	 * its names have been added and their addresses can follow later. 	 * Also true if the delegationpoint was created from a delegation 	 * message and thus contains the parent-side-info already. */
name|uint8_t
name|has_parent_side_NS
decl_stmt|;
comment|/** for assertions on type of delegpt */
name|uint8_t
name|dp_type_mlc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Nameservers for a delegation point.  */
end_comment

begin_struct
struct|struct
name|delegpt_ns
block|{
comment|/** next in list */
name|struct
name|delegpt_ns
modifier|*
name|next
decl_stmt|;
comment|/** name of nameserver */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|namelen
decl_stmt|;
comment|/**  	 * If the name has been resolved. false if not queried for yet. 	 * true if the A, AAAA queries have been generated. 	 * marked true if those queries fail. 	 * and marked true if got4 and got6 are both true. 	 */
name|int
name|resolved
decl_stmt|;
comment|/** if the ipv4 address is in the delegpt */
name|uint8_t
name|got4
decl_stmt|;
comment|/** if the ipv6 address is in the delegpt */
name|uint8_t
name|got6
decl_stmt|;
comment|/** 	 * If the name is parent-side only and thus dispreferred. 	 * Its addresses become dispreferred as well 	 */
name|uint8_t
name|lame
decl_stmt|;
comment|/** if the parent-side ipv4 address has been looked up (last resort). 	 * Also enabled if a parent-side cache entry exists, or a parent-side 	 * negative-cache entry exists. */
name|uint8_t
name|done_pside4
decl_stmt|;
comment|/** if the parent-side ipv6 address has been looked up (last resort). 	 * Also enabled if a parent-side cache entry exists, or a parent-side 	 * negative-cache entry exists. */
name|uint8_t
name|done_pside6
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Address of target nameserver in delegation point.  */
end_comment

begin_struct
struct|struct
name|delegpt_addr
block|{
comment|/** next delegation point in results */
name|struct
name|delegpt_addr
modifier|*
name|next_result
decl_stmt|;
comment|/** next delegation point in usable list */
name|struct
name|delegpt_addr
modifier|*
name|next_usable
decl_stmt|;
comment|/** next delegation point in all targets list */
name|struct
name|delegpt_addr
modifier|*
name|next_target
decl_stmt|;
comment|/** delegation point address */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** number of attempts for this addr */
name|int
name|attempts
decl_stmt|;
comment|/** rtt stored here in the selection algorithm */
name|int
name|sel_rtt
decl_stmt|;
comment|/** if true, the A or AAAA RR was bogus, so this address is bad. 	 * Also check the dp->bogus to see if everything is bogus. */
name|uint8_t
name|bogus
decl_stmt|;
comment|/** if true, this address is dispreferred: it is a lame IP address */
name|uint8_t
name|lame
decl_stmt|;
comment|/** if the address is dnsseclame, but this cannot be cached, this 	 * option is useful to mark the address dnsseclame. 	 * This value is not copied in addr-copy and dp-copy. */
name|uint8_t
name|dnsseclame
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create new delegation point.  * @param regional: where to allocate it.  * @return new delegation point or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|delegpt_create
parameter_list|(
name|struct
name|regional
modifier|*
name|regional
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a copy of a delegation point.  * @param dp: delegation point to copy.  * @param regional: where to allocate it.  * @return new delegation point or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|delegpt_copy
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set name of delegation point.  * @param dp: delegation point.  * @param regional: where to allocate the name copy.  * @param name: name to use.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_set_name
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add a name to the delegation point.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param name: domain name in wire format.  * @param lame: name is lame, disprefer it.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_ns
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add NS rrset; calls add_ns repeatedly.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param ns_rrset: NS rrset.  * @param lame: rrset is lame, disprefer it.  * @return 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|delegpt_rrset_add_ns
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ns_rrset
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add target address to the delegation point.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param name: name for which target was found (must be in nslist).  *	This name is marked resolved.  * @param namelen: length of name.  * @param addr: the address.  * @param addrlen: the length of addr.  * @param bogus: security status for the address, pass true if bogus.  * @param lame: address is lame.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_target
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
name|bogus
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add A RRset to delegpt.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param rrset: RRset A to add.  * @param lame: rrset is lame, disprefer it.  * @return 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_rrset_A
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add AAAA RRset to delegpt.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param rrset: RRset AAAA to add.  * @param lame: rrset is lame, disprefer it.  * @return 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_rrset_AAAA
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add any RRset to delegpt.  * Does not check for duplicates added.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param rrset: RRset to add, NS, A, AAAA.  * @param lame: rrset is lame, disprefer it.  * @return 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_rrset
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add address to the delegation point. No servername is associated or checked.  * @param dp: delegation point.  * @param regional: where to allocate the info.  * @param addr: the address.  * @param addrlen: the length of addr.  * @param bogus: if address is bogus.  * @param lame: if address is lame.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_addr
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
name|bogus
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Find NS record in name list of delegation point.  * @param dp: delegation point.  * @param name: name of nameserver to look for, uncompressed wireformat.  * @param namelen: length of name.  * @return the ns structure or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|delegpt_ns
modifier|*
name|delegpt_find_ns
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Find address record in total list of delegation point.  * @param dp: delegation point.  * @param addr: address  * @param addrlen: length of addr  * @return the addr structure or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|delegpt_addr
modifier|*
name|delegpt_find_addr
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print the delegation point to the log. For debugging.  * @param v: verbosity value that is needed to emit to log.  * @param dp: delegation point.  */
end_comment

begin_function_decl
name|void
name|delegpt_log
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** count NS and number missing for logging */
end_comment

begin_function_decl
name|void
name|delegpt_count_ns
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|size_t
modifier|*
name|numns
parameter_list|,
name|size_t
modifier|*
name|missing
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** count addresses, and number in result and available lists, for logging */
end_comment

begin_function_decl
name|void
name|delegpt_count_addr
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|size_t
modifier|*
name|numaddr
parameter_list|,
name|size_t
modifier|*
name|numres
parameter_list|,
name|size_t
modifier|*
name|numavail
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add all usable targets to the result list.  * @param dp: delegation point.  */
end_comment

begin_function_decl
name|void
name|delegpt_add_unused_targets
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Count number of missing targets. These are ns names with no resolved flag.  * @param dp: delegation point.  * @return number of missing targets (or 0).  */
end_comment

begin_function_decl
name|size_t
name|delegpt_count_missing_targets
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** count total number of targets in dp */
end_comment

begin_function_decl
name|size_t
name|delegpt_count_targets
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create new delegation point from a dns message  *  * Note that this method does not actually test to see if the message is an  * actual referral. It really is just checking to see if it can construct a  * delegation point, so the message could be of some other type (some ANSWER  * messages, some CNAME messages, generally.) Note that the resulting  * DelegationPoint will contain targets for all "relevant" glue (i.e.,  * address records whose ownernames match the target of one of the NS  * records), so if policy dictates that some glue should be discarded beyond  * that, discard it before calling this method. Note that this method will  * find "glue" in either the ADDITIONAL section or the ANSWER section.  *  * @param msg: the dns message, referral.  * @param regional: where to allocate delegation point.  * @return new delegation point or NULL on alloc error, or if the  *         message was not appropriate.  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|delegpt_from_message
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add negative message to delegation point.  * @param dp: delegation point.  * @param msg: the message added, marks off A or AAAA from an NS entry.  */
end_comment

begin_function_decl
name|void
name|delegpt_add_neg_msg
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|msgreply_entry
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Register the fact that there is no ipv6 and thus AAAAs are not going   * to be queried for or be useful.  * @param dp: the delegation point. Updated to reflect no ipv6.  */
end_comment

begin_function_decl
name|void
name|delegpt_no_ipv6
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Register the fact that there is no ipv4 and thus As are not going   * to be queried for or be useful.  * @param dp: the delegation point. Updated to reflect no ipv4.  */
end_comment

begin_function_decl
name|void
name|delegpt_no_ipv4
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * create malloced delegation point, with the given name   * @param name: uncompressed wireformat of degegpt name.  * @return NULL on alloc failure  */
end_comment

begin_function_decl
name|struct
name|delegpt
modifier|*
name|delegpt_create_mlc
parameter_list|(
name|uint8_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * free malloced delegation point.  * @param dp: must have been created with delegpt_create_mlc, free'd.   */
end_comment

begin_function_decl
name|void
name|delegpt_free_mlc
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set name of delegation point.  * @param dp: delegation point. malloced.  * @param name: name to use.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_set_name_mlc
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * add a name to malloced delegation point.  * @param dp: must have been created with delegpt_create_mlc.   * @param name: the name to add.  * @param lame: the name is lame, disprefer.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_ns_mlc
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * add an address to a malloced delegation point.  * @param dp: must have been created with delegpt_create_mlc.   * @param addr: the address.  * @param addrlen: the length of addr.  * @param bogus: if address is bogus.  * @param lame: if address is lame.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_addr_mlc
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
name|bogus
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add target address to the delegation point.  * @param dp: must have been created with delegpt_create_mlc.   * @param name: name for which target was found (must be in nslist).  *	This name is marked resolved.  * @param namelen: length of name.  * @param addr: the address.  * @param addrlen: the length of addr.  * @param bogus: security status for the address, pass true if bogus.  * @param lame: address is lame.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|delegpt_add_target_mlc
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
name|bogus
parameter_list|,
name|uint8_t
name|lame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** get memory in use by dp */
end_comment

begin_function_decl
name|size_t
name|delegpt_get_mem
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITER_DELEGPT_H */
end_comment

end_unit

