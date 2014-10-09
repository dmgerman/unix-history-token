begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  * Copyright (c) 2005 Andre Oppermann, Internet Business Solutions AG.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_OPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_OPTIONS_H_
end_define

begin_struct
struct|struct
name|ipoptrt
block|{
name|struct
name|in_addr
name|dst
decl_stmt|;
comment|/* final destination */
name|char
name|nop
decl_stmt|;
comment|/* one NOP to align */
name|char
name|srcopt
index|[
name|IPOPT_OFFSET
operator|+
literal|1
index|]
decl_stmt|;
comment|/* OPTVAL, OLEN and OFFSET */
name|struct
name|in_addr
name|route
index|[
name|MAX_IPOPTLEN
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|in_addr
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipopt_tag
block|{
name|struct
name|m_tag
name|tag
decl_stmt|;
comment|/* m_tag */
name|int
name|ip_nhops
decl_stmt|;
name|struct
name|ipoptrt
name|ip_srcrt
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ip_doopts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* process or ignore IP options */
end_comment

begin_define
define|#
directive|define
name|V_ip_doopts
value|VNET(ip_doopts)
end_define

begin_function_decl
name|int
name|ip_checkrouteralert
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_dooptions
parameter_list|(
name|struct
name|mbuf
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
name|ip_insertoptions
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_optcopy
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ip_pcbopts
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_stripoptions
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|ip_srcroute
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_IP_OPTIONS_H_ */
end_comment

end_unit

