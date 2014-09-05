begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_INET6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_INET6_H_
end_define

begin_function
specifier|static
specifier|inline
name|void
name|ipv6_eth_mc_map
parameter_list|(
specifier|const
name|struct
name|in6_addr
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
block|{
comment|/*  *      +-------+-------+-------+-------+-------+-------+  *      |   33  |   33  | DST13 | DST14 | DST15 | DST16 |  *      +-------+-------+-------+-------+-------+-------+  */
name|buf
index|[
literal|0
index|]
operator|=
literal|0x33
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
literal|0x33
expr_stmt|;
name|memcpy
argument_list|(
name|buf
operator|+
literal|2
argument_list|,
operator|&
name|addr
operator|->
name|s6_addr32
index|[
literal|3
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|__u32
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_INET6_H_ */
end_comment

end_unit

