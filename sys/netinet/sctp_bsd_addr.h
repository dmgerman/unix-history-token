begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_bsd_addr_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_bsd_addr_h__
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_header.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_function_decl
name|int
name|sctp_is_addr_restricted
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|sctp_ipv4_source_address_selection
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|int
name|non_asoc_addr_ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in6_addr
name|sctp_ipv6_source_address_selection
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sctp_add_addresses_to_i_ia
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|sctp_scoping
modifier|*
name|scope
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m_at
parameter_list|,
name|int
name|cnt_inits_to
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

