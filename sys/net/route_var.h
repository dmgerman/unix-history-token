begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016  * 	Alexander V. Chernikov<melifaro@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_ROUTE_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_ROUTE_VAR_H_
end_define

begin_struct
struct|struct
name|rib_head
block|{
name|struct
name|radix_head
name|head
decl_stmt|;
name|rn_matchaddr_f_t
modifier|*
name|rnh_matchaddr
decl_stmt|;
comment|/* longest match for sockaddr */
name|rn_addaddr_f_t
modifier|*
name|rnh_addaddr
decl_stmt|;
comment|/* add based on sockaddr*/
name|rn_deladdr_f_t
modifier|*
name|rnh_deladdr
decl_stmt|;
comment|/* remove based on sockaddr */
name|rn_lookup_f_t
modifier|*
name|rnh_lookup
decl_stmt|;
comment|/* exact match for sockaddr */
name|rn_walktree_t
modifier|*
name|rnh_walktree
decl_stmt|;
comment|/* traverse tree */
name|rn_walktree_from_t
modifier|*
name|rnh_walktree_from
decl_stmt|;
comment|/* traverse tree below a */
name|rn_close_t
modifier|*
name|rnh_close
decl_stmt|;
comment|/*do something when the last ref drops*/
name|rt_gen_t
name|rnh_gen
decl_stmt|;
comment|/* generation counter */
name|int
name|rnh_multipath
decl_stmt|;
comment|/* multipath capable ? */
name|struct
name|radix_node
name|rnh_nodes
index|[
literal|3
index|]
decl_stmt|;
comment|/* empty tree for common case */
name|struct
name|rwlock
name|rib_lock
decl_stmt|;
comment|/* config/data path lock */
name|struct
name|radix_mask_head
name|rmhead
decl_stmt|;
comment|/* masks radix head */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RIB_RLOCK
parameter_list|(
name|rh
parameter_list|)
value|rw_rlock(&(rh)->rib_lock)
end_define

begin_define
define|#
directive|define
name|RIB_RUNLOCK
parameter_list|(
name|rh
parameter_list|)
value|rw_runlock(&(rh)->rib_lock)
end_define

begin_define
define|#
directive|define
name|RIB_WLOCK
parameter_list|(
name|rh
parameter_list|)
value|rw_wlock(&(rh)->rib_lock)
end_define

begin_define
define|#
directive|define
name|RIB_WUNLOCK
parameter_list|(
name|rh
parameter_list|)
value|rw_wunlock(&(rh)->rib_lock)
end_define

begin_define
define|#
directive|define
name|RIB_LOCK_ASSERT
parameter_list|(
name|rh
parameter_list|)
value|rw_assert(&(rh)->rib_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|RIB_WLOCK_ASSERT
parameter_list|(
name|rh
parameter_list|)
value|rw_assert(&(rh)->rib_lock, RA_WLOCKED)
end_define

begin_function_decl
name|struct
name|rib_head
modifier|*
name|rt_tables_get_rnh
parameter_list|(
name|int
name|fib
parameter_list|,
name|int
name|family
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rte<>nhop translation */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|fib_rte_to_nh_flags
parameter_list|(
name|int
name|rt_flags
parameter_list|)
block|{
name|uint16_t
name|res
decl_stmt|;
name|res
operator|=
operator|(
name|rt_flags
operator|&
name|RTF_REJECT
operator|)
condition|?
name|NHF_REJECT
else|:
literal|0
expr_stmt|;
name|res
operator||=
operator|(
name|rt_flags
operator|&
name|RTF_BLACKHOLE
operator|)
condition|?
name|NHF_BLACKHOLE
else|:
literal|0
expr_stmt|;
name|res
operator||=
operator|(
name|rt_flags
operator|&
operator|(
name|RTF_DYNAMIC
operator||
name|RTF_MODIFIED
operator|)
operator|)
condition|?
name|NHF_REDIRECT
else|:
literal|0
expr_stmt|;
name|res
operator||=
operator|(
name|rt_flags
operator|&
name|RTF_BROADCAST
operator|)
condition|?
name|NHF_BROADCAST
else|:
literal|0
expr_stmt|;
name|res
operator||=
operator|(
name|rt_flags
operator|&
name|RTF_GATEWAY
operator|)
condition|?
name|NHF_GATEWAY
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

