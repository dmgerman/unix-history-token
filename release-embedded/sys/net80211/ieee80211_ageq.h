begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_STAGEQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_STAGEQ_H_
end_define

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

begin_struct
struct|struct
name|ieee80211_ageq
block|{
name|ieee80211_ageq_lock_t
name|aq_lock
decl_stmt|;
name|int
name|aq_len
decl_stmt|;
comment|/* # items on queue */
name|int
name|aq_maxlen
decl_stmt|;
comment|/* max queue length */
name|int
name|aq_drops
decl_stmt|;
comment|/* frames dropped */
name|struct
name|mbuf
modifier|*
name|aq_head
decl_stmt|;
comment|/* frames linked w/ m_nextpkt */
name|struct
name|mbuf
modifier|*
name|aq_tail
decl_stmt|;
comment|/* last frame in queue */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_ageq_init
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|,
name|int
name|maxlen
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ageq_cleanup
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ageq_mfree
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_ageq_append
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
name|age
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ageq_drain
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_ageq_drain_node
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_ageq_age
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|,
name|int
name|quanta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ieee80211_ageq_remove
parameter_list|(
name|struct
name|ieee80211_ageq
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|match
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_STAGEQ_H_ */
end_comment

end_unit

