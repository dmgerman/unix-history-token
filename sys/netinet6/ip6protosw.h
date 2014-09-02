begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$KAME: ip6protosw.h,v 1.25 2001/09/26 06:13:03 keiichi Exp $  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)protosw.h	8.1 (Berkeley) 6/2/93  *	BSDI protosw.h,v 2.3 1996/10/11 16:02:40 pjd Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IP6PROTOSW_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IP6PROTOSW_H_
end_define

begin_comment
comment|/*  * Protocol switch table for IPv6.  * All other definitions should refer to sys/protosw.h  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|domain
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip6_hdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|icmp6_hdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in6_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pr_usrreqs
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * argument type for the last arg of pr_ctlinput().  * should be consulted only with AF_INET6 family.  *  * IPv6 ICMP IPv6 [exthdrs] finalhdr payload  * ^    ^    ^              ^  * |    |    ip6c_ip6       ip6c_off  * |    ip6c_icmp6  * ip6c_m  *  * ip6c_finaldst usually points to ip6c_ip6->ip6_dst.  if the original  * (internal) packet carries a routing header, it may point the final  * dstination address in the routing header.  *  * ip6c_src: ip6c_ip6->ip6_src + scope info + flowlabel in ip6c_ip6  *	(beware of flowlabel, if you try to compare it against others)  * ip6c_dst: ip6c_finaldst + scope info  */
end_comment

begin_struct
struct|struct
name|ip6ctlparam
block|{
name|struct
name|mbuf
modifier|*
name|ip6c_m
decl_stmt|;
comment|/* start of mbuf chain */
name|struct
name|icmp6_hdr
modifier|*
name|ip6c_icmp6
decl_stmt|;
comment|/* icmp6 header of target packet */
name|struct
name|ip6_hdr
modifier|*
name|ip6c_ip6
decl_stmt|;
comment|/* ip6 header of target packet */
name|int
name|ip6c_off
decl_stmt|;
comment|/* offset of the target proto header */
name|struct
name|sockaddr_in6
modifier|*
name|ip6c_src
decl_stmt|;
comment|/* srcaddr w/ additional info */
name|struct
name|sockaddr_in6
modifier|*
name|ip6c_dst
decl_stmt|;
comment|/* (final) dstaddr w/ additional info */
name|struct
name|in6_addr
modifier|*
name|ip6c_finaldst
decl_stmt|;
comment|/* final destination address */
name|void
modifier|*
name|ip6c_cmdarg
decl_stmt|;
comment|/* control command dependent data */
name|u_int8_t
name|ip6c_nxt
decl_stmt|;
comment|/* final next header field */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|inet6sw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET6_IP6PROTOSW_H_ */
end_comment

end_unit

