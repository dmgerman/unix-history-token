begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007-2009, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHELSIO_L2T_H
end_ifndef

begin_define
define|#
directive|define
name|_CHELSIO_L2T_H
end_define

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_enum
enum|enum
block|{
name|L2T_SIZE
init|=
literal|2048
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|L2T_STATE_VALID
block|,
comment|/* entry is up to date */
name|L2T_STATE_STALE
block|,
comment|/* entry may be used but needs revalidation */
name|L2T_STATE_RESOLVING
block|,
comment|/* entry needs address resolution */
name|L2T_STATE_FAILED
block|,
comment|/* failed to resolve */
name|L2T_STATE_UNUSED
comment|/* entry not in use */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Each L2T entry plays multiple roles.  First of all, it keeps state for the  * corresponding entry of the HW L2 table and maintains a queue of offload  * packets awaiting address resolution.  Second, it is a node of a hash table  * chain, where the nodes of the chain are linked together through their next  * pointer.  Finally, each node is a bucket of a hash table, pointing to the  * first element in its chain through its first pointer.  */
end_comment

begin_struct
struct|struct
name|l2t_entry
block|{
name|uint16_t
name|state
decl_stmt|;
comment|/* entry state */
name|uint16_t
name|idx
decl_stmt|;
comment|/* entry index */
name|uint32_t
name|addr
decl_stmt|;
comment|/* nexthop IP address */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* outgoing interface */
name|uint16_t
name|smt_idx
decl_stmt|;
comment|/* SMT index */
name|uint16_t
name|vlan
decl_stmt|;
comment|/* VLAN TCI (id: bits 0-11, prio: 13-15 */
name|struct
name|l2t_entry
modifier|*
name|first
decl_stmt|;
comment|/* start of hash chain */
name|struct
name|l2t_entry
modifier|*
name|next
decl_stmt|;
comment|/* next l2t_entry on chain */
name|struct
name|mbuf
modifier|*
name|arpq_head
decl_stmt|;
comment|/* queue of packets awaiting resolution */
name|struct
name|mbuf
modifier|*
name|arpq_tail
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
specifier|volatile
name|uint32_t
name|refcnt
decl_stmt|;
comment|/* entry reference count */
name|uint8_t
name|dmac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* nexthop's MAC address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l2t_data
block|{
name|unsigned
name|int
name|nentries
decl_stmt|;
comment|/* number of entries */
name|struct
name|l2t_entry
modifier|*
name|rover
decl_stmt|;
comment|/* starting point for next allocation */
specifier|volatile
name|uint32_t
name|nfree
decl_stmt|;
comment|/* number of free entries */
name|struct
name|rwlock
name|lock
decl_stmt|;
name|struct
name|l2t_entry
name|l2tab
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|t3_l2e_free
parameter_list|(
name|struct
name|l2t_data
modifier|*
parameter_list|,
name|struct
name|l2t_entry
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_l2_update
parameter_list|(
name|struct
name|toedev
modifier|*
name|tod
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|uint8_t
modifier|*
name|lladdr
parameter_list|,
name|uint16_t
name|vtag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|l2t_entry
modifier|*
name|t3_l2t_get
parameter_list|(
name|struct
name|port_info
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_l2t_send_slow
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|l2t_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|l2t_data
modifier|*
name|t3_init_l2t
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_free_l2t
parameter_list|(
name|struct
name|l2t_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_init_l2t_cpl_handlers
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|l2t_send
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|l2t_entry
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|__predict_true
argument_list|(
name|e
operator|->
name|state
operator|==
name|L2T_STATE_VALID
argument_list|)
condition|)
return|return
name|t3_offload_tx
argument_list|(
name|sc
argument_list|,
name|m
argument_list|)
return|;
else|else
return|return
name|t3_l2t_send_slow
argument_list|(
name|sc
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|l2t_release
parameter_list|(
name|struct
name|l2t_data
modifier|*
name|d
parameter_list|,
name|struct
name|l2t_entry
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|atomic_fetchadd_int
argument_list|(
operator|&
name|e
operator|->
name|refcnt
argument_list|,
operator|-
literal|1
argument_list|)
operator|==
literal|1
condition|)
comment|/* 1 -> 0 transition */
name|atomic_add_int
argument_list|(
operator|&
name|d
operator|->
name|nfree
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|l2t_hold
parameter_list|(
name|struct
name|l2t_data
modifier|*
name|d
parameter_list|,
name|struct
name|l2t_entry
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|atomic_fetchadd_int
argument_list|(
operator|&
name|e
operator|->
name|refcnt
argument_list|,
literal|1
argument_list|)
operator|==
literal|0
condition|)
comment|/* 0 -> 1 transition */
name|atomic_add_int
argument_list|(
operator|&
name|d
operator|->
name|nfree
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

