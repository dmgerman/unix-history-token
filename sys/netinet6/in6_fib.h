begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015  * 	Alexander V. Chernikov<melifaro@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IN6_FIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IN6_FIB_H_
end_define

begin_comment
comment|/* Basic nexthop info used for uRPF/mtu checks */
end_comment

begin_struct
struct|struct
name|nhop6_basic
block|{
name|struct
name|ifnet
modifier|*
name|nh_ifp
decl_stmt|;
comment|/* Logical egress interface */
name|uint16_t
name|nh_mtu
decl_stmt|;
comment|/* nexthop mtu */
name|uint16_t
name|nh_flags
decl_stmt|;
comment|/* nhop flags */
name|uint8_t
name|spare
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|in6_addr
name|nh_addr
decl_stmt|;
comment|/* GW/DST IPv4 address */
block|}
struct|;
end_struct

begin_comment
comment|/* Does not differ from nhop6_basic */
end_comment

begin_struct
struct|struct
name|nhop6_extended
block|{
name|struct
name|ifnet
modifier|*
name|nh_ifp
decl_stmt|;
comment|/* Logical egress interface */
name|uint16_t
name|nh_mtu
decl_stmt|;
comment|/* nexthop mtu */
name|uint16_t
name|nh_flags
decl_stmt|;
comment|/* nhop flags */
name|uint8_t
name|spare
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|in6_addr
name|nh_addr
decl_stmt|;
comment|/* GW/DST IPv6 address */
name|uint64_t
name|spare2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|fib6_lookup_nh_basic
parameter_list|(
name|uint32_t
name|fibnum
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
name|dst
parameter_list|,
name|uint32_t
name|scopeid
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|uint32_t
name|flowid
parameter_list|,
name|struct
name|nhop6_basic
modifier|*
name|pnh6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fib6_lookup_nh_ext
parameter_list|(
name|uint32_t
name|fibnum
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
name|dst
parameter_list|,
name|uint32_t
name|scopeid
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|uint32_t
name|flowid
parameter_list|,
name|struct
name|nhop6_extended
modifier|*
name|pnh6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fib6_free_nh_ext
parameter_list|(
name|uint32_t
name|fibnum
parameter_list|,
name|struct
name|nhop6_extended
modifier|*
name|pnh6
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

