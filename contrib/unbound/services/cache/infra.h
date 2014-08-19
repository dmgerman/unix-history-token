begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/cache/infra.h - infrastructure cache, server rtt and capabilities  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the infrastructure cache.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_CACHE_INFRA_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_CACHE_INFRA_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/rtt.h"
end_include

begin_struct_decl
struct_decl|struct
name|slabhash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Host information kept for every server, per zone.  */
end_comment

begin_struct
struct|struct
name|infra_key
block|{
comment|/** the host address. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr. */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** zone name in wireformat */
name|uint8_t
modifier|*
name|zonename
decl_stmt|;
comment|/** length of zonename */
name|size_t
name|namelen
decl_stmt|;
comment|/** hash table entry, data of type infra_data. */
name|struct
name|lruhash_entry
name|entry
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Host information encompasses host capabilities and retransmission timeouts.  * And lameness information (notAuthoritative, noEDNS, Recursive)  */
end_comment

begin_struct
struct|struct
name|infra_data
block|{
comment|/** TTL value for this entry. absolute time. */
name|time_t
name|ttl
decl_stmt|;
comment|/** time in seconds (absolute) when probing re-commences, 0 disabled */
name|time_t
name|probedelay
decl_stmt|;
comment|/** round trip times for timeout calculation */
name|struct
name|rtt_info
name|rtt
decl_stmt|;
comment|/** edns version that the host supports, -1 means no EDNS */
name|int
name|edns_version
decl_stmt|;
comment|/** if the EDNS lameness is already known or not. 	 * EDNS lame is when EDNS queries or replies are dropped,  	 * and cause a timeout */
name|uint8_t
name|edns_lame_known
decl_stmt|;
comment|/** is the host lame (does not serve the zone authoritatively), 	 * or is the host dnssec lame (does not serve DNSSEC data) */
name|uint8_t
name|isdnsseclame
decl_stmt|;
comment|/** is the host recursion lame (not AA, but RA) */
name|uint8_t
name|rec_lame
decl_stmt|;
comment|/** the host is lame (not authoritative) for A records */
name|uint8_t
name|lame_type_A
decl_stmt|;
comment|/** the host is lame (not authoritative) for other query types */
name|uint8_t
name|lame_other
decl_stmt|;
comment|/** timeouts counter for type A */
name|uint8_t
name|timeout_A
decl_stmt|;
comment|/** timeouts counter for type AAAA */
name|uint8_t
name|timeout_AAAA
decl_stmt|;
comment|/** timeouts counter for others */
name|uint8_t
name|timeout_other
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Infra cache   */
end_comment

begin_struct
struct|struct
name|infra_cache
block|{
comment|/** The hash table with hosts */
name|struct
name|slabhash
modifier|*
name|hosts
decl_stmt|;
comment|/** TTL value for host information, in seconds */
name|int
name|host_ttl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** infra host cache default hash lookup size */
end_comment

begin_define
define|#
directive|define
name|INFRA_HOST_STARTSIZE
value|32
end_define

begin_comment
comment|/** bytes per zonename reserved in the hostcache, dnamelen(zonename.com.) */
end_comment

begin_define
define|#
directive|define
name|INFRA_BYTES_NAME
value|14
end_define

begin_comment
comment|/**  * Create infra cache.  * @param cfg: config parameters or NULL for defaults.  * @return: new infra cache, or NULL.  */
end_comment

begin_function_decl
name|struct
name|infra_cache
modifier|*
name|infra_create
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete infra cache.  * @param infra: infrastructure cache to delete.  */
end_comment

begin_function_decl
name|void
name|infra_delete
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Adjust infra cache to use updated configuration settings.  * This may clean the cache. Operates a bit like realloc.  * There may be no threading or use by other threads.  * @param infra: existing cache. If NULL a new infra cache is returned.  * @param cfg: config options.  * @return the new infra cache pointer or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|infra_cache
modifier|*
name|infra_adjust
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Plain find infra data function (used by the the other functions)  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: domain name of zone.  * @param namelen: length of domain name.  * @param wr: if true, writelock, else readlock.  * @return the entry, could be expired (this is not checked) or NULL.  */
end_comment

begin_function_decl
name|struct
name|lruhash_entry
modifier|*
name|infra_lookup_nottl
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|int
name|wr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find host information to send a packet. Creates new entry if not found.  * Lameness is empty. EDNS is 0 (try with first), and rtt is returned for   * the first message to it.  * Use this to send a packet only, because it also locks out others when  * probing is restricted.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: domain name of zone.  * @param namelen: length of domain name.  * @param timenow: what time it is now.  * @param edns_vs: edns version it supports, is returned.  * @param edns_lame_known: if EDNS lame (EDNS is dropped in transit) has  * 	already been probed, is returned.  * @param to: timeout to use, is returned.  * @return: 0 on error.  */
end_comment

begin_function_decl
name|int
name|infra_host
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|int
modifier|*
name|edns_vs
parameter_list|,
name|uint8_t
modifier|*
name|edns_lame_known
parameter_list|,
name|int
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set a host to be lame for the given zone.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: domain name of zone apex.  * @param namelen: length of domain name.  * @param timenow: what time it is now.  * @param dnsseclame: if true the host is set dnssec lame.  *	if false, the host is marked lame (not serving the zone).  * @param reclame: if true host is a recursor not AA server.  *      if false, dnsseclame or marked lame.  * @param qtype: the query type for which it is lame.  * @return: 0 on error.  */
end_comment

begin_function_decl
name|int
name|infra_set_lame
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|int
name|dnsseclame
parameter_list|,
name|int
name|reclame
parameter_list|,
name|uint16_t
name|qtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update rtt information for the host.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: zone name  * @param namelen: zone name length  * @param qtype: query type.  * @param roundtrip: estimate of roundtrip time in milliseconds or -1 for   * 	timeout.  * @param orig_rtt: original rtt for the query that timed out (roundtrip==-1).  * 	ignored if roundtrip != -1.  * @param timenow: what time it is now.  * @return: 0 on error. new rto otherwise.  */
end_comment

begin_function_decl
name|int
name|infra_rtt_update
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|int
name|qtype
parameter_list|,
name|int
name|roundtrip
parameter_list|,
name|int
name|orig_rtt
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update information for the host, store that a TCP transaction works.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: name of zone  * @param namelen: length of name  */
end_comment

begin_function_decl
name|void
name|infra_update_tcp_works
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update edns information for the host.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: name of zone  * @param namelen: length of name  * @param edns_version: the version that it publishes.  * 	If it is known to support EDNS then no-EDNS is not stored over it.  * @param timenow: what time it is now.  * @return: 0 on error.  */
end_comment

begin_function_decl
name|int
name|infra_edns_update
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|int
name|edns_version
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get Lameness information and average RTT if host is in the cache.  * This information is to be used for server selection.  * @param infra: infrastructure cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: zone name.  * @param namelen: zone name length.  * @param qtype: the query to be made.  * @param lame: if function returns true, this returns lameness of the zone.  * @param dnsseclame: if function returns true, this returns if the zone  *	is dnssec-lame.  * @param reclame: if function returns true, this is if it is recursion lame.  * @param rtt: if function returns true, this returns avg rtt of the server.  * 	The rtt value is unclamped and reflects recent timeouts.  * @param timenow: what time it is now.  * @return if found in cache, or false if not (or TTL bad).  */
end_comment

begin_function_decl
name|int
name|infra_get_lame_rtt
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|int
modifier|*
name|lame
parameter_list|,
name|int
modifier|*
name|dnsseclame
parameter_list|,
name|int
modifier|*
name|reclame
parameter_list|,
name|int
modifier|*
name|rtt
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get additional (debug) info on timing.  * @param infra: infra cache.  * @param addr: host address.  * @param addrlen: length of addr.  * @param name: zone name  * @param namelen: zone name length  * @param rtt: the rtt_info is copied into here (caller alloced return struct).  * @param delay: probe delay (if any).  * @param timenow: what time it is now.  * @param tA: timeout counter on type A.  * @param tAAAA: timeout counter on type AAAA.  * @param tother: timeout counter on type other.  * @return TTL the infra host element is valid for. If -1: not found in cache.  *	TTL -2: found but expired.  */
end_comment

begin_function_decl
name|long
name|long
name|infra_get_host_rto
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
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
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|struct
name|rtt_info
modifier|*
name|rtt
parameter_list|,
name|int
modifier|*
name|delay
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|int
modifier|*
name|tA
parameter_list|,
name|int
modifier|*
name|tAAAA
parameter_list|,
name|int
modifier|*
name|tother
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory used by the infra cache.  * @param infra: infrastructure cache.  * @return memory in use in bytes.  */
end_comment

begin_function_decl
name|size_t
name|infra_get_mem
parameter_list|(
name|struct
name|infra_cache
modifier|*
name|infra
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** calculate size for the hashtable, does not count size of lameness,  * so the hashtable is a fixed number of items */
end_comment

begin_function_decl
name|size_t
name|infra_sizefunc
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
comment|/** compare two addresses, returns -1, 0, or +1 */
end_comment

begin_function_decl
name|int
name|infra_compfunc
parameter_list|(
name|void
modifier|*
name|key1
parameter_list|,
name|void
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** delete key, and destroy the lock */
end_comment

begin_function_decl
name|void
name|infra_delkeyfunc
parameter_list|(
name|void
modifier|*
name|k
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** delete data and destroy the lameness hashtable */
end_comment

begin_function_decl
name|void
name|infra_deldatafunc
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_CACHE_INFRA_H */
end_comment

end_unit

