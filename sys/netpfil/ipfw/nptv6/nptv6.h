begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Yandex LLC  * Copyright (c) 2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_FW_NPTV6_H_
end_ifndef

begin_define
define|#
directive|define
name|_IP_FW_NPTV6_H_
end_define

begin_include
include|#
directive|include
file|<netinet6/ip_fw_nptv6.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|NPTV6STATS
value|(sizeof(struct ipfw_nptv6_stats) / sizeof(uint64_t))
end_define

begin_define
define|#
directive|define
name|NPTV6STAT_ADD
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|counter_u64_add((c)->stats[		\ 	offsetof(struct ipfw_nptv6_stats, f) / sizeof(uint64_t)], (v))
end_define

begin_define
define|#
directive|define
name|NPTV6STAT_INC
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|NPTV6STAT_ADD(c, f, 1)
end_define

begin_define
define|#
directive|define
name|NPTV6STAT_FETCH
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|counter_u64_fetch((c)->stats[	\ 	offsetof(struct ipfw_nptv6_stats, f) / sizeof(uint64_t)])
end_define

begin_struct
struct|struct
name|nptv6_cfg
block|{
name|struct
name|named_object
name|no
decl_stmt|;
name|struct
name|in6_addr
name|internal
decl_stmt|;
comment|/* Internal IPv6 prefix */
name|struct
name|in6_addr
name|external
decl_stmt|;
comment|/* External IPv6 prefix */
name|struct
name|in6_addr
name|mask
decl_stmt|;
comment|/* IPv6 prefix mask */
name|uint16_t
name|adjustment
decl_stmt|;
comment|/* Checksum adjustment value */
name|uint8_t
name|plen
decl_stmt|;
comment|/* Prefix length */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Flags for internal use */
define|#
directive|define
name|NPTV6_48PLEN
value|0x0001
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* Instance name */
name|counter_u64_t
name|stats
index|[
name|NPTV6STATS
index|]
decl_stmt|;
comment|/* Statistics counters */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NPTV6_FLAGSMASK
value|0
end_define

begin_function_decl
name|int
name|nptv6_init
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nptv6_uninit
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_FW_NPTV6_H_ */
end_comment

end_unit

