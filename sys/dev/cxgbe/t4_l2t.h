begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_L2T_H
end_ifndef

begin_define
define|#
directive|define
name|__T4_L2T_H
end_define

begin_comment
comment|/* identifies sync vs async L2T_WRITE_REQs */
end_comment

begin_define
define|#
directive|define
name|S_SYNC_WR
value|12
end_define

begin_define
define|#
directive|define
name|V_SYNC_WR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYNC_WR)
end_define

begin_define
define|#
directive|define
name|F_SYNC_WR
value|V_SYNC_WR(1)
end_define

begin_enum
enum|enum
block|{
name|L2T_SIZE
init|=
literal|4096
block|}
enum|;
end_enum

begin_comment
comment|/* # of L2T entries */
end_comment

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
name|L2T_STATE_SYNC_WRITE
block|,
comment|/* synchronous write of entry underway */
comment|/* when state is one of the below the entry is not hashed */
name|L2T_STATE_SWITCHING
block|,
comment|/* entry is being used by a switching filter */
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
index|[
literal|4
index|]
decl_stmt|;
comment|/* next hop IP or IPv6 address */
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
comment|/* VLAN TCI (id: 0-11, prio: 13-15) */
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
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|wrqe
argument_list|)
name|wr_list
expr_stmt|;
comment|/* list of WRs awaiting resolution */
name|struct
name|mtx
name|lock
decl_stmt|;
specifier|volatile
name|int
name|refcnt
decl_stmt|;
comment|/* entry reference count */
name|uint16_t
name|hash
decl_stmt|;
comment|/* hash bucket the entry is on */
name|uint8_t
name|ipv6
decl_stmt|;
comment|/* entry is for an IPv6 address */
name|uint8_t
name|lport
decl_stmt|;
comment|/* associated offload logical port */
name|uint8_t
name|dmac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* next hop's MAC address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l2t_data
block|{
name|struct
name|rwlock
name|lock
decl_stmt|;
name|u_int
name|l2t_size
decl_stmt|;
specifier|volatile
name|int
name|nfree
decl_stmt|;
comment|/* number of free entries */
name|struct
name|l2t_entry
modifier|*
name|rover
decl_stmt|;
comment|/* starting point for next allocation */
name|struct
name|l2t_entry
name|l2tab
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|t4_init_l2t
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_free_l2t
parameter_list|(
name|struct
name|l2t_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|l2t_entry
modifier|*
name|t4_alloc_l2e
parameter_list|(
name|struct
name|l2t_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|l2t_entry
modifier|*
name|t4_l2t_alloc_switching
parameter_list|(
name|struct
name|l2t_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_l2t_set_switching
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|l2t_entry
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_write_l2e
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|l2t_entry
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_l2t_write_rpl
parameter_list|(
name|struct
name|sge_iq
modifier|*
parameter_list|,
specifier|const
name|struct
name|rss_header
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|t4_l2t_release
parameter_list|(
name|struct
name|l2t_entry
modifier|*
name|e
parameter_list|)
block|{
name|struct
name|l2t_data
modifier|*
name|d
init|=
name|__containerof
argument_list|(
name|e
argument_list|,
expr|struct
name|l2t_data
argument_list|,
name|l2tab
index|[
name|e
operator|->
name|idx
index|]
argument_list|)
decl_stmt|;
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

begin_ifdef
ifdef|#
directive|ifdef
name|SBUF_DRAIN
end_ifdef

begin_function_decl
name|int
name|sysctl_l2t
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_L2T_H */
end_comment

end_unit

