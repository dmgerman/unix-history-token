begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_resptype.h - response type information and classification.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file defines the response type. DNS Responses can be classified as  * one of the response types.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_RESPTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_RESPTYPE_H
end_define

begin_struct_decl
struct_decl|struct
name|dns_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The response type is used to interpret the response.  */
end_comment

begin_enum
enum|enum
name|response_type
block|{
comment|/**  	 * 'untyped' means that the type of this response hasn't been  	 * assigned.  	 */
name|RESPONSE_TYPE_UNTYPED
init|=
literal|0
block|,
comment|/**  	 * 'answer' means that the response terminates the resolution  	 * process.  	 */
name|RESPONSE_TYPE_ANSWER
block|,
comment|/** 'delegation' means that the response is a delegation. */
name|RESPONSE_TYPE_REFERRAL
block|,
comment|/** 	 * 'cname' means that the response is a cname without the final  	 * answer, and thus must be restarted. 	 */
name|RESPONSE_TYPE_CNAME
block|,
comment|/** 	 * 'throwaway' means that this particular response should be  	 * discarded and the next nameserver should be contacted 	 */
name|RESPONSE_TYPE_THROWAWAY
block|,
comment|/** 	 * 'lame' means that this particular response indicates that  	 * the nameserver knew nothing about the question. 	 */
name|RESPONSE_TYPE_LAME
block|,
comment|/** 	 * Recursion lame means that the nameserver is some sort of 	 * open recursor, and not authoritative for the question. 	 * It may know something, but not authoritatively. 	 */
name|RESPONSE_TYPE_REC_LAME
block|}
enum|;
end_enum

begin_comment
comment|/**  * Classifies a response message from cache based on the current request.  * Note that this routine assumes that THROWAWAY or LAME responses will not  * occur. Also, it will not detect REFERRAL type messages, since those are  * (currently) automatically classified based on how they came from the  * cache (findDelegation() instead of lookup()).  *  * @param msg: the message from the cache.  * @param request: the request that generated the response.  * @return the response type (CNAME or ANSWER).  */
end_comment

begin_function_decl
name|enum
name|response_type
name|response_type_from_cache
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|query_info
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Classifies a response message (from the wire) based on the current  * request.  *  * NOTE: currently this routine uses the AA bit in the response to help  * distinguish between some non-standard referrals and answers. It also  * relies somewhat on the originating zone to be accurate (for lameness  * detection, mostly).  *  * @param rdset: if RD bit was sent in query sent by unbound.  * @param msg: the message from the cache.  * @param request: the request that generated the response.  * @param dp: The delegation point that was being queried  *          when the response was returned.  * @return the response type (CNAME or ANSWER).  */
end_comment

begin_function_decl
name|enum
name|response_type
name|response_type_from_server
parameter_list|(
name|int
name|rdset
parameter_list|,
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|query_info
modifier|*
name|request
parameter_list|,
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
comment|/* ITERATOR_ITER_RESPTYPE_H */
end_comment

end_unit

