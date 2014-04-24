begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_POWER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_POWER_H_
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211vap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Power save packet queues.  There are two queues, one  * for frames coming from the net80211 layer and the other  * for frames that come from the driver. Frames from the  * driver are expected to have M_ENCAP marked to indicate  * they have already been encapsulated and are treated as  * higher priority: they are sent first when flushing the  * queue on a power save state change or in response to a  * ps-poll frame.  *  * Note that frames sent from the high priority queue are  * fed directly to the driver without going through  * ieee80211_start again; drivers that send up encap'd  * frames are required to handle them when they come back.  */
end_comment

begin_struct
struct|struct
name|ieee80211_psq
block|{
name|ieee80211_psq_lock_t
name|psq_lock
decl_stmt|;
name|int
name|psq_len
decl_stmt|;
name|int
name|psq_maxlen
decl_stmt|;
name|int
name|psq_drops
decl_stmt|;
struct|struct
name|ieee80211_psq_head
block|{
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
name|psq_head
index|[
literal|2
index|]
struct|;
comment|/* 2 priorities */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_psq_init
parameter_list|(
name|struct
name|ieee80211_psq
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_psq_cleanup
parameter_list|(
name|struct
name|ieee80211_psq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_power_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_power_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_power_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_power_vdetach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_power_latevattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_node_psq_dequeue
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|int
modifier|*
name|qlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_node_psq_drain
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_node_psq_age
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Don't call these directly from the stack; they are vap methods  * that should be overridden.  */
end_comment

begin_function_decl
name|int
name|ieee80211_pwrsave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_node_pwrsave
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sta_pwrsave
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sta_tim_notify
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|int
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_sta_ps_timer_check
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX what's this? */
end_comment

begin_function_decl
name|void
name|ieee80211_power_poll
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_POWER_H_ */
end_comment

end_unit

