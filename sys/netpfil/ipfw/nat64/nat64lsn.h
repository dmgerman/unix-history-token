begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Yandex LLC  * Copyright (c) 2015 Alexander V. Chernikov<melifaro@FreeBSD.org>  * Copyright (c) 2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_FW_NAT64LSN_H_
end_ifndef

begin_define
define|#
directive|define
name|_IP_FW_NAT64LSN_H_
end_define

begin_define
define|#
directive|define
name|NAT64_CHUNK_SIZE_BITS
value|6
end_define

begin_comment
comment|/* 64 ports */
end_comment

begin_define
define|#
directive|define
name|NAT64_CHUNK_SIZE
value|(1<< NAT64_CHUNK_SIZE_BITS)
end_define

begin_define
define|#
directive|define
name|NAT64_MIN_PORT
value|1024
end_define

begin_define
define|#
directive|define
name|NAT64_MIN_CHUNK
value|(NAT64_MIN_PORT>> NAT64_CHUNK_SIZE_BITS)
end_define

begin_struct
struct|struct
name|st_ptr
block|{
name|uint8_t
name|idx
decl_stmt|;
comment|/* index in nh->pg_ptr array. 					 * NOTE: it starts from 1. 					 */
name|uint8_t
name|off
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAT64LSN_MAXPGPTR
value|((1<< (sizeof(uint8_t) * NBBY)) - 1)
end_define

begin_define
define|#
directive|define
name|NAT64LSN_PGPTRMASKBITS
value|(sizeof(uint64_t) * NBBY)
end_define

begin_define
define|#
directive|define
name|NAT64LSN_PGPTRNMASK
value|(roundup(NAT64LSN_MAXPGPTR,	\     NAT64LSN_PGPTRMASKBITS) / NAT64LSN_PGPTRMASKBITS)
end_define

begin_struct_decl
struct_decl|struct
name|nat64lsn_portgroup
struct_decl|;
end_struct_decl

begin_comment
comment|/* sizeof(struct nat64lsn_host) = 64 + 64x2 + 8x8 = 256 bytes */
end_comment

begin_struct
struct|struct
name|nat64lsn_host
block|{
name|struct
name|rwlock
name|h_lock
decl_stmt|;
comment|/* Host states lock */
name|struct
name|in6_addr
name|addr
decl_stmt|;
name|struct
name|nat64lsn_host
modifier|*
name|next
decl_stmt|;
name|uint16_t
name|timestamp
decl_stmt|;
comment|/* Last altered */
name|uint16_t
name|hsize
decl_stmt|;
comment|/* ports hash size */
name|uint16_t
name|pg_used
decl_stmt|;
comment|/* Number of portgroups used */
define|#
directive|define
name|NAT64LSN_REMAININGPG
value|8
comment|/* Number of remaining PG before 					 * requesting of new chunk of indexes. 					 */
name|uint16_t
name|pg_allocated
decl_stmt|;
comment|/* Number of portgroups indexes 					 * allocated. 					 */
define|#
directive|define
name|NAT64LSN_HSIZE
value|64
name|struct
name|st_ptr
name|phash
index|[
name|NAT64LSN_HSIZE
index|]
decl_stmt|;
comment|/* XXX: hardcoded size */
comment|/* 	 * PG indexes are stored in chunks with 32 elements. 	 * The maximum count is limited to 255 due to st_ptr->idx is uint8_t. 	 */
define|#
directive|define
name|NAT64LSN_PGIDX_CHUNK
value|32
define|#
directive|define
name|NAT64LSN_PGNIDX
value|(roundup(NAT64LSN_MAXPGPTR, \     NAT64LSN_PGIDX_CHUNK) / NAT64LSN_PGIDX_CHUNK)
name|struct
name|nat64lsn_portgroup
modifier|*
modifier|*
name|pg_ptr
index|[
name|NAT64LSN_PGNIDX
index|]
decl_stmt|;
comment|/* PG indexes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAT64_RLOCK_ASSERT
parameter_list|(
name|h
parameter_list|)
value|rw_assert(&(h)->h_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|NAT64_WLOCK_ASSERT
parameter_list|(
name|h
parameter_list|)
value|rw_assert(&(h)->h_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|NAT64_RLOCK
parameter_list|(
name|h
parameter_list|)
value|rw_rlock(&(h)->h_lock)
end_define

begin_define
define|#
directive|define
name|NAT64_RUNLOCK
parameter_list|(
name|h
parameter_list|)
value|rw_runlock(&(h)->h_lock)
end_define

begin_define
define|#
directive|define
name|NAT64_WLOCK
parameter_list|(
name|h
parameter_list|)
value|rw_wlock(&(h)->h_lock)
end_define

begin_define
define|#
directive|define
name|NAT64_WUNLOCK
parameter_list|(
name|h
parameter_list|)
value|rw_wunlock(&(h)->h_lock)
end_define

begin_define
define|#
directive|define
name|NAT64_LOCK
parameter_list|(
name|h
parameter_list|)
value|NAT64_WLOCK(h)
end_define

begin_define
define|#
directive|define
name|NAT64_UNLOCK
parameter_list|(
name|h
parameter_list|)
value|NAT64_WUNLOCK(h)
end_define

begin_define
define|#
directive|define
name|NAT64_LOCK_INIT
parameter_list|(
name|h
parameter_list|)
value|do {			\ 	rw_init(&(h)->h_lock, "NAT64 host lock");	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NAT64_LOCK_DESTROY
parameter_list|(
name|h
parameter_list|)
value|do {			\ 	rw_destroy(&(h)->h_lock);			\ 	} while (0)
end_define

begin_comment
comment|/* Internal proto index */
end_comment

begin_define
define|#
directive|define
name|NAT_PROTO_TCP
value|1
end_define

begin_define
define|#
directive|define
name|NAT_PROTO_UDP
value|2
end_define

begin_define
define|#
directive|define
name|NAT_PROTO_ICMP
value|3
end_define

begin_define
define|#
directive|define
name|NAT_MAX_PROTO
value|4
end_define

begin_decl_stmt
specifier|extern
name|uint8_t
name|nat64lsn_rproto_map
index|[
name|NAT_MAX_PROTO
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|uint16_t
argument_list|,
name|nat64lsn_eid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_nat64lsn_eid
value|VNET(nat64lsn_eid)
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_NAT64LSN_NAME
value|IPFW_TLV_EACTION_NAME(V_nat64lsn_eid)
end_define

begin_comment
comment|/* Timestamp macro */
end_comment

begin_define
define|#
directive|define
name|_CT
value|((int)time_uptime % 65536)
end_define

begin_define
define|#
directive|define
name|SET_AGE
parameter_list|(
name|x
parameter_list|)
value|(x) = _CT
end_define

begin_define
define|#
directive|define
name|GET_AGE
parameter_list|(
name|x
parameter_list|)
value|((_CT>= (x)) ? _CT - (x) :	\ 	(int)65536 + _CT - (x))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_comment
comment|/* ffsl() is capable of checking 64-bit ints */
end_comment

begin_define
define|#
directive|define
name|_FFS64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 16 bytes */
end_comment

begin_struct
struct|struct
name|nat64lsn_state
block|{
union|union
block|{
struct|struct
block|{
name|in_addr_t
name|faddr
decl_stmt|;
comment|/* Remote IPv4 address */
name|uint16_t
name|fport
decl_stmt|;
comment|/* Remote IPv4 port */
name|uint16_t
name|lport
decl_stmt|;
comment|/* Local IPv6 port */
block|}
name|s
struct|;
name|uint64_t
name|hkey
decl_stmt|;
block|}
name|u
union|;
name|uint8_t
name|nat_proto
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|timestamp
decl_stmt|;
name|struct
name|st_ptr
name|cur
decl_stmt|;
comment|/* Index of portgroup in nat64lsn_host */
name|struct
name|st_ptr
name|next
decl_stmt|;
comment|/* Next entry index */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 1024+32 bytes per 64 states, used to store state  * AND for outside-in state lookup   */
end_comment

begin_struct
struct|struct
name|nat64lsn_portgroup
block|{
name|struct
name|nat64lsn_host
modifier|*
name|host
decl_stmt|;
comment|/* IPv6 source host info */
name|in_addr_t
name|aaddr
decl_stmt|;
comment|/* Alias addr, network format */
name|uint16_t
name|aport
decl_stmt|;
comment|/* Base port */
name|uint16_t
name|timestamp
decl_stmt|;
name|uint8_t
name|nat_proto
decl_stmt|;
name|uint8_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|idx
decl_stmt|;
ifdef|#
directive|ifdef
name|_FFS64
name|uint64_t
name|freemask
decl_stmt|;
comment|/* Mask of free entries */
else|#
directive|else
name|uint32_t
name|freemask
index|[
literal|2
index|]
decl_stmt|;
comment|/* Mask of free entries */
endif|#
directive|endif
name|struct
name|nat64lsn_state
name|states
index|[
name|NAT64_CHUNK_SIZE
index|]
decl_stmt|;
comment|/* State storage */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_FFS64
end_ifdef

begin_define
define|#
directive|define
name|PG_MARK_BUSY_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
value|(_pg)->freemask&= ~((uint64_t)1<<(_idx))
end_define

begin_define
define|#
directive|define
name|PG_MARK_FREE_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
value|(_pg)->freemask |= ((uint64_t)1<<(_idx))
end_define

begin_define
define|#
directive|define
name|PG_IS_FREE_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
value|((_pg)->freemask& ((uint64_t)1<<(_idx)))
end_define

begin_define
define|#
directive|define
name|PG_IS_BUSY_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
value|(PG_IS_FREE_IDX(_pg, _idx) == 0)
end_define

begin_define
define|#
directive|define
name|PG_GET_FREE_IDX
parameter_list|(
name|_pg
parameter_list|)
value|(ffsll((_pg)->freemask))
end_define

begin_define
define|#
directive|define
name|PG_IS_EMPTY
parameter_list|(
name|_pg
parameter_list|)
value|(((_pg)->freemask + 1) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PG_MARK_BUSY_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
define|\
value|(_pg)->freemask[(_idx) / 32]&= ~((u_long)1<<((_idx) % 32))
end_define

begin_define
define|#
directive|define
name|PG_MARK_FREE_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
define|\
value|(_pg)->freemask[(_idx) / 32] |= ((u_long)1<<((_idx)  % 32))
end_define

begin_define
define|#
directive|define
name|PG_IS_FREE_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
define|\
value|((_pg)->freemask[(_idx) / 32]& ((u_long)1<<((_idx) % 32)))
end_define

begin_define
define|#
directive|define
name|PG_IS_BUSY_IDX
parameter_list|(
name|_pg
parameter_list|,
name|_idx
parameter_list|)
value|(PG_IS_FREE_IDX(_pg, _idx) == 0)
end_define

begin_define
define|#
directive|define
name|PG_GET_FREE_IDX
parameter_list|(
name|_pg
parameter_list|)
value|_pg_get_free_idx(_pg)
end_define

begin_define
define|#
directive|define
name|PG_IS_EMPTY
parameter_list|(
name|_pg
parameter_list|)
define|\
value|((((_pg)->freemask[0] + 1) == 0&& ((_pg)->freemask[1] + 1) == 0))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|_pg_get_free_idx
parameter_list|(
specifier|const
name|struct
name|nat64lsn_portgroup
modifier|*
name|pg
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
name|ffsl
argument_list|(
name|pg
operator|->
name|freemask
index|[
literal|0
index|]
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|i
operator|)
return|;
if|if
condition|(
operator|(
name|i
operator|=
name|ffsl
argument_list|(
name|pg
operator|->
name|freemask
index|[
literal|1
index|]
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|i
operator|+
literal|32
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nat64lsn_job_head
argument_list|,
name|nat64lsn_job_item
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NAT64LSN_FLAGSMASK
value|(NAT64_LOG)
end_define

begin_struct
struct|struct
name|nat64lsn_cfg
block|{
name|struct
name|named_object
name|no
decl_stmt|;
comment|//struct nat64_exthost	*ex;	/* Pointer to external addr array */
name|struct
name|nat64lsn_portgroup
modifier|*
modifier|*
name|pg
decl_stmt|;
comment|/* XXX: array of pointers */
name|struct
name|nat64lsn_host
modifier|*
modifier|*
name|ih
decl_stmt|;
comment|/* Host hash */
name|uint32_t
name|prefix4
decl_stmt|;
comment|/* IPv4 prefix */
name|uint32_t
name|pmask4
decl_stmt|;
comment|/* IPv4 prefix mask */
name|uint32_t
name|ihsize
decl_stmt|;
comment|/* IPv6 host hash size */
name|uint8_t
name|plen4
decl_stmt|;
name|uint8_t
name|plen6
decl_stmt|;
name|uint8_t
name|nomatch_verdict
decl_stmt|;
comment|/* What to return to ipfw on no-match */
name|uint8_t
name|nomatch_final
decl_stmt|;
comment|/* Exit outer loop? */
name|struct
name|in6_addr
name|prefix6
decl_stmt|;
comment|/* IPv6 prefix to embed IPv4 hosts */
name|uint32_t
name|ihcount
decl_stmt|;
comment|/* Number of items in host hash */
name|int
name|max_chunks
decl_stmt|;
comment|/* Max chunks per client */
name|int
name|agg_prefix_len
decl_stmt|;
comment|/* Prefix length to count */
name|int
name|agg_prefix_max
decl_stmt|;
comment|/* Max hosts per agg prefix */
name|uint32_t
name|jmaxlen
decl_stmt|;
comment|/* Max jobqueue length */
name|uint32_t
name|flags
decl_stmt|;
name|uint16_t
name|min_chunk
decl_stmt|;
comment|/* Min port group # to use */
name|uint16_t
name|max_chunk
decl_stmt|;
comment|/* Max port group # to use */
name|uint16_t
name|nh_delete_delay
decl_stmt|;
comment|/* Stale host delete delay */
name|uint16_t
name|pg_delete_delay
decl_stmt|;
comment|/* Stale portgroup del delay */
name|uint16_t
name|st_syn_ttl
decl_stmt|;
comment|/* TCP syn expire */
name|uint16_t
name|st_close_ttl
decl_stmt|;
comment|/* TCP fin expire */
name|uint16_t
name|st_estab_ttl
decl_stmt|;
comment|/* TCP established expire */
name|uint16_t
name|st_udp_ttl
decl_stmt|;
comment|/* UDP expire */
name|uint16_t
name|st_icmp_ttl
decl_stmt|;
comment|/* ICMP expire */
name|uint32_t
name|protochunks
index|[
name|NAT_MAX_PROTO
index|]
decl_stmt|;
comment|/* Number of chunks used */
name|struct
name|callout
name|periodic
decl_stmt|;
name|struct
name|callout
name|jcallout
decl_stmt|;
name|struct
name|ip_fw_chain
modifier|*
name|ch
decl_stmt|;
name|struct
name|vnet
modifier|*
name|vp
decl_stmt|;
name|struct
name|nat64lsn_job_head
name|jhead
decl_stmt|;
name|int
name|jlen
decl_stmt|;
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* Nat instance name */
name|nat64_stats_block
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|nat64lsn_cfg
modifier|*
name|nat64lsn_init_instance
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|size_t
name|numaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_destroy_instance
parameter_list|(
name|struct
name|nat64lsn_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_start_instance
parameter_list|(
name|struct
name|nat64lsn_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_init_internal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_uninit_internal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_nat64lsn
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_dump_state
parameter_list|(
specifier|const
name|struct
name|nat64lsn_cfg
modifier|*
name|cfg
parameter_list|,
specifier|const
name|struct
name|nat64lsn_portgroup
modifier|*
name|pg
parameter_list|,
specifier|const
name|struct
name|nat64lsn_state
modifier|*
name|st
parameter_list|,
specifier|const
name|char
modifier|*
name|px
parameter_list|,
name|int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Portgroup layout  * addr x nat_proto x port_off  *  */
end_comment

begin_define
define|#
directive|define
name|_ADDR_PG_PROTO_COUNT
value|(65536>> NAT64_CHUNK_SIZE_BITS)
end_define

begin_define
define|#
directive|define
name|_ADDR_PG_COUNT
value|(_ADDR_PG_PROTO_COUNT * NAT_MAX_PROTO)
end_define

begin_define
define|#
directive|define
name|GET_ADDR_IDX
parameter_list|(
name|_cfg
parameter_list|,
name|_addr
parameter_list|)
value|((_addr) - ((_cfg)->prefix4))
end_define

begin_define
define|#
directive|define
name|__GET_PORTGROUP_IDX
parameter_list|(
name|_proto
parameter_list|,
name|_port
parameter_list|)
define|\
value|((_proto - 1) * _ADDR_PG_PROTO_COUNT +	\ 	((_port)>> NAT64_CHUNK_SIZE_BITS))
end_define

begin_define
define|#
directive|define
name|_GET_PORTGROUP_IDX
parameter_list|(
name|_cfg
parameter_list|,
name|_addr
parameter_list|,
name|_proto
parameter_list|,
name|_port
parameter_list|)
define|\
value|GET_ADDR_IDX(_cfg, _addr) * _ADDR_PG_COUNT +	\ 	__GET_PORTGROUP_IDX(_proto, _port)
end_define

begin_define
define|#
directive|define
name|GET_PORTGROUP
parameter_list|(
name|_cfg
parameter_list|,
name|_addr
parameter_list|,
name|_proto
parameter_list|,
name|_port
parameter_list|)
define|\
value|((_cfg)->pg[_GET_PORTGROUP_IDX(_cfg, _addr, _proto, _port)])
end_define

begin_define
define|#
directive|define
name|PORTGROUP_CHUNK
parameter_list|(
name|_nh
parameter_list|,
name|_idx
parameter_list|)
define|\
value|((_nh)->pg_ptr[(_idx)])
end_define

begin_define
define|#
directive|define
name|PORTGROUP_BYSIDX
parameter_list|(
name|_cfg
parameter_list|,
name|_nh
parameter_list|,
name|_idx
parameter_list|)
define|\
value|(PORTGROUP_CHUNK(_nh, (_idx - 1) / NAT64LSN_PGIDX_CHUNK) \ 	[((_idx) - 1) % NAT64LSN_PGIDX_CHUNK])
end_define

begin_comment
comment|/* Chained hash table */
end_comment

begin_define
define|#
directive|define
name|CHT_FIND
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_PX
parameter_list|,
name|_x
parameter_list|,
name|_key
parameter_list|)
value|do {			\ 	unsigned int _buck = _PX##hash(_key)& (_hsize - 1);		\ 	_PX##lock(_ph, _buck);						\ 	_x = _PX##first(_ph, _buck);					\ 	for ( ; _x != NULL; _x = _PX##next(_x)) {			\ 		if (_PX##cmp(_key, _PX##val(_x)))			\ 			break;						\ 	}								\ 	if (_x == NULL)							\ 		_PX##unlock(_ph, _buck);				\ } while(0)
end_define

begin_define
define|#
directive|define
name|CHT_UNLOCK_BUCK
parameter_list|(
name|_ph
parameter_list|,
name|_PX
parameter_list|,
name|_buck
parameter_list|)
define|\
value|_PX##unlock(_ph, _buck);
end_define

begin_define
define|#
directive|define
name|CHT_UNLOCK_KEY
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_PX
parameter_list|,
name|_key
parameter_list|)
value|do {			\ 	unsigned int _buck = _PX##hash(_key)& (_hsize - 1);		\ 	_PX##unlock(_ph, _buck);					\ } while(0)
end_define

begin_define
define|#
directive|define
name|CHT_INSERT_HEAD
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_PX
parameter_list|,
name|_i
parameter_list|)
value|do {			\ 	unsigned int _buck = _PX##hash(_PX##val(_i))& (_hsize - 1);	\ 	_PX##lock(_ph, _buck);						\ 	_PX##next(_i) = _PX##first(_ph, _buck);				\ 	_PX##first(_ph, _buck) = _i;					\ 	_PX##unlock(_ph, _buck);					\ } while(0)
end_define

begin_define
define|#
directive|define
name|CHT_REMOVE
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_PX
parameter_list|,
name|_x
parameter_list|,
name|_tmp
parameter_list|,
name|_key
parameter_list|)
value|do {		\ 	unsigned int _buck = _PX##hash(_key)& (_hsize - 1);		\ 	_PX##lock(_ph, _buck);						\ 	_x = _PX##first(_ph, _buck);					\ 	_tmp = NULL;							\ 	for ( ; _x != NULL; _tmp = _x, _x = _PX##next(_x)) {		\ 		if (_PX##cmp(_key, _PX##val(_x)))			\ 			break;						\ 	}								\ 	if (_x != NULL) {						\ 		if (_tmp == NULL)					\ 			_PX##first(_ph, _buck) = _PX##next(_x);		\ 		else							\ 			_PX##next(_tmp) = _PX##next(_x);		\ 	}								\ 	_PX##unlock(_ph, _buck);					\ } while(0)
end_define

begin_define
define|#
directive|define
name|CHT_FOREACH_SAFE
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_PX
parameter_list|,
name|_x
parameter_list|,
name|_tmp
parameter_list|,
name|_cb
parameter_list|,
name|_arg
parameter_list|)
value|do {	\ 	for (unsigned int _i = 0; _i< _hsize; _i++) {			\ 		_PX##lock(_ph, _i);					\ 		_x = _PX##first(_ph, _i);				\ 		_tmp = NULL;						\ 		for (; _x != NULL; _tmp = _x, _x = _PX##next(_x)) {	\ 			if (_cb(_x, _arg) == 0)				\ 				continue;				\ 			if (_tmp == NULL)				\ 				_PX##first(_ph, _i) = _PX##next(_x);	\ 			else						\ 				_tmp = _PX##next(_x);			\ 		}							\ 		_PX##unlock(_ph, _i);					\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|CHT_RESIZE
parameter_list|(
name|_ph
parameter_list|,
name|_hsize
parameter_list|,
name|_nph
parameter_list|,
name|_nhsize
parameter_list|,
name|_PX
parameter_list|,
name|_x
parameter_list|,
name|_y
parameter_list|)
value|do {	\ 	unsigned int _buck;						\ 	for (unsigned int _i = 0; _i< _hsize; _i++) {			\ 		_x = _PX##first(_ph, _i);				\ 		_y = _x;						\ 		while (_y != NULL) {					\ 			_buck = _PX##hash(_PX##val(_x))& (_nhsize - 1);\ 			_y = _PX##next(_x);				\ 			_PX##next(_x) = _PX##first(_nph, _buck);	\ 			_PX##first(_nph, _buck) = _x;			\ 		}							\ 	}								\ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_FW_NAT64LSN_H_ */
end_comment

end_unit

