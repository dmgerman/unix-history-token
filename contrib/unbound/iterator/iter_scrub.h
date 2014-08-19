begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_scrub.h - scrubbing, normalization, sanitization of DNS msgs.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file has routine(s) for cleaning up incoming DNS messages from   * possible useless or malicious junk in it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_SCRUB_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_SCRUB_H
end_define

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msg_parse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_env
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Cleanup the passed dns message.  * @param pkt: the packet itself, for resolving name compression pointers.  *	the packet buffer is unaltered.  * @param msg: the parsed packet, this structure is cleaned up.  * @param qinfo: the query info that was sent to the server. Checked.  * @param zonename: the name of the last delegation point.  *	Used to determine out of bailiwick information.  * @param regional: where to allocate (new) parts of the message.  * @param env: module environment with config settings and cache.   * @param ie: iterator module environment data.  * @return: false if the message is total waste. true if scrubbed with success.  */
end_comment

begin_function_decl
name|int
name|scrub_message
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint8_t
modifier|*
name|zonename
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|iter_env
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITER_SCRUB_H */
end_comment

end_unit

