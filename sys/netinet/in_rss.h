begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Juniper Networks, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson under contract  * to Juniper Networks, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_RSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_RSS_H_
end_define

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* in_addr_t */
end_comment

begin_comment
comment|/*  * Network stack interface to generate a hash for a protocol tuple.  */
end_comment

begin_function_decl
name|uint32_t
name|rss_hash_ip4_4tuple
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|u_short
name|srcport
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|,
name|u_short
name|dstport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|rss_hash_ip4_2tuple
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to calculate a software RSS hash for a given mbuf or  * packet detail.  */
end_comment

begin_function_decl
name|int
name|rss_mbuf_software_hash_v4
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|dir
parameter_list|,
name|uint32_t
modifier|*
name|hashval
parameter_list|,
name|uint32_t
modifier|*
name|hashtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rss_proto_software_hash_v4
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|,
name|u_short
name|src_port
parameter_list|,
name|u_short
name|dst_port
parameter_list|,
name|int
name|proto
parameter_list|,
name|uint32_t
modifier|*
name|hashval
parameter_list|,
name|uint32_t
modifier|*
name|hashtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|rss_soft_m2cpuid
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|u_int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_IN_RSS_H_ */
end_comment

end_unit

