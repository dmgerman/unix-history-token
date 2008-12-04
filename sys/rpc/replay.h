begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Isilon Inc http://www.isilon.com/  * Authors: Doug Rabson<dfr@rabson.org>  * Developed with Red Inc: Alfred Perlstein<alfred@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_REPLAY_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_REPLAY_H
end_define

begin_enum
enum|enum
name|replay_state
block|{
name|RS_NEW
block|,
comment|/* new request - caller should execute */
name|RS_DONE
block|,
comment|/* request was executed and reply sent */
name|RS_INPROGRESS
block|,
comment|/* request is being executed now */
name|RS_ERROR
comment|/* allocation or other failure */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|replay_cache
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Create a new replay cache.  */
end_comment

begin_function_decl
name|struct
name|replay_cache
modifier|*
name|replay_newcache
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the replay cache size.  */
end_comment

begin_function_decl
name|void
name|replay_setsize
parameter_list|(
name|struct
name|replay_cache
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a replay cache. Caller must ensure that no cache entries are  * in-progress.  */
end_comment

begin_function_decl
name|void
name|replay_freecache
parameter_list|(
name|struct
name|replay_cache
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check a replay cache for a message from a given address.  *  * If this is a new request, RS_NEW is returned. Caller should call  * replay_setreply with the results of the request.  *  * If this is a request which is currently executing  * (i.e. replay_setreply hasn't been called for it yet), RS_INPROGRESS  * is returned. The caller should silently drop the request.  *  * If a reply to this message already exists, *repmsg and *mp are set  * to point at the reply and, RS_DONE is returned. The caller should  * re-send this reply.  *  * If the attempt to update the replay cache or copy a replay failed  * for some reason (typically memory shortage), RS_ERROR is returned.  */
end_comment

begin_function_decl
name|enum
name|replay_state
name|replay_find
parameter_list|(
name|struct
name|replay_cache
modifier|*
name|rc
parameter_list|,
name|struct
name|rpc_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|rpc_msg
modifier|*
name|repmsg
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Call this after executing a request to record the reply.  */
end_comment

begin_function_decl
name|void
name|replay_setreply
parameter_list|(
name|struct
name|replay_cache
modifier|*
name|rc
parameter_list|,
name|struct
name|rpc_msg
modifier|*
name|repmsg
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_REPLAY_H */
end_comment

end_unit

