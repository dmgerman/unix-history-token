begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, Myricom Inc.  * Copyright (c) 2008, Intel Corporation.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCP_LRO_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCP_LRO_H_
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_struct
struct|struct
name|lro_entry
block|{
name|SLIST_ENTRY
argument_list|(
argument|lro_entry
argument_list|)
name|next
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_tail
decl_stmt|;
union|union
block|{
name|struct
name|ip
modifier|*
name|ip4
decl_stmt|;
name|struct
name|ip6_hdr
modifier|*
name|ip6
decl_stmt|;
block|}
name|leip
union|;
union|union
block|{
name|in_addr_t
name|s_ip4
decl_stmt|;
name|struct
name|in6_addr
name|s_ip6
decl_stmt|;
block|}
name|lesource
union|;
union|union
block|{
name|in_addr_t
name|d_ip4
decl_stmt|;
name|struct
name|in6_addr
name|d_ip6
decl_stmt|;
block|}
name|ledest
union|;
name|uint16_t
name|source_port
decl_stmt|;
name|uint16_t
name|dest_port
decl_stmt|;
name|uint16_t
name|eh_type
decl_stmt|;
comment|/* EthernetHeader type. */
name|uint16_t
name|append_cnt
decl_stmt|;
name|uint32_t
name|p_len
decl_stmt|;
comment|/* IP header payload length. */
name|uint32_t
name|ulp_csum
decl_stmt|;
comment|/* TCP, etc. checksum. */
name|uint32_t
name|next_seq
decl_stmt|;
comment|/* tcp_seq */
name|uint32_t
name|ack_seq
decl_stmt|;
comment|/* tcp_seq */
name|uint32_t
name|tsval
decl_stmt|;
name|uint32_t
name|tsecr
decl_stmt|;
name|uint16_t
name|window
decl_stmt|;
name|uint16_t
name|timestamp
decl_stmt|;
comment|/* flag, not a TCP hdr field. */
name|struct
name|timeval
name|mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|lro_head
argument_list|,
name|lro_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|le_ip4
value|leip.ip4
end_define

begin_define
define|#
directive|define
name|le_ip6
value|leip.ip6
end_define

begin_define
define|#
directive|define
name|source_ip4
value|lesource.s_ip4
end_define

begin_define
define|#
directive|define
name|dest_ip4
value|ledest.d_ip4
end_define

begin_define
define|#
directive|define
name|source_ip6
value|lesource.s_ip6
end_define

begin_define
define|#
directive|define
name|dest_ip6
value|ledest.d_ip6
end_define

begin_comment
comment|/* NB: This is part of driver structs. */
end_comment

begin_struct
struct|struct
name|lro_ctrl
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|lro_queued
decl_stmt|;
name|int
name|lro_flushed
decl_stmt|;
name|int
name|lro_bad_csum
decl_stmt|;
name|int
name|lro_cnt
decl_stmt|;
name|struct
name|lro_head
name|lro_active
decl_stmt|;
name|struct
name|lro_head
name|lro_free
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|tcp_lro_init
parameter_list|(
name|struct
name|lro_ctrl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_lro_free
parameter_list|(
name|struct
name|lro_ctrl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_lro_flush_inactive
parameter_list|(
name|struct
name|lro_ctrl
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_lro_flush
parameter_list|(
name|struct
name|lro_ctrl
modifier|*
parameter_list|,
name|struct
name|lro_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_lro_rx
parameter_list|(
name|struct
name|lro_ctrl
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TCP_LRO_CANNOT
value|-1
end_define

begin_define
define|#
directive|define
name|TCP_LRO_NOT_SUPPORTED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TCP_LRO_H_ */
end_comment

end_unit

