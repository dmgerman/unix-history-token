begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ns.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNS_NS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNS_NS_H_
end_define

begin_comment
comment|/*  * Constants and Structures defined by the Xerox Network Software  * per "Internet Transport Protocols", XSIS 028112, December 1981  */
end_comment

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_RI
value|1
end_define

begin_comment
comment|/* Routing Information */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_ECHO
value|2
end_define

begin_comment
comment|/* Echo Protocol */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_ERROR
value|3
end_define

begin_comment
comment|/* Error Protocol */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_PE
value|4
end_define

begin_comment
comment|/* Packet Exchange */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_SPP
value|5
end_define

begin_comment
comment|/* Sequenced Packet */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_RAW
value|255
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_define
define|#
directive|define
name|NSPROTO_MAX
value|256
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_comment
comment|/*  * Port/Socket numbers: network standard functions  */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RI
value|1
end_define

begin_comment
comment|/* Routing Information */
end_comment

begin_define
define|#
directive|define
name|NSPORT_ECHO
value|2
end_define

begin_comment
comment|/* Echo */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RE
value|3
end_define

begin_comment
comment|/* Router Error */
end_comment

begin_comment
comment|/*  * Ports< NSPORT_RESERVED are reserved for priveleged  * processes (e.g. root).  */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RESERVED
value|3000
end_define

begin_comment
comment|/* flags passed to ns_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|NS_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of idp header exists */
end_comment

begin_define
define|#
directive|define
name|NS_ROUTETOIF
value|0x10
end_define

begin_comment
comment|/* same as SO_DONTROUTE */
end_comment

begin_define
define|#
directive|define
name|NS_ALLOWBROADCAST
value|SO_BROADCAST
end_define

begin_comment
comment|/* can send broadcast packets */
end_comment

begin_define
define|#
directive|define
name|NS_MAXHOPS
value|15
end_define

begin_comment
comment|/* flags passed to get/set socket option */
end_comment

begin_define
define|#
directive|define
name|SO_HEADERS_ON_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|SO_HEADERS_ON_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|SO_DEFAULT_HEADERS
value|3
end_define

begin_define
define|#
directive|define
name|SO_LAST_HEADER
value|4
end_define

begin_define
define|#
directive|define
name|SO_NSIP_ROUTE
value|5
end_define

begin_define
define|#
directive|define
name|SO_SEQNO
value|6
end_define

begin_define
define|#
directive|define
name|SO_ALL_PACKETS
value|7
end_define

begin_define
define|#
directive|define
name|SO_MTU
value|8
end_define

begin_comment
comment|/*  * NS addressing  */
end_comment

begin_union
union|union
name|ns_host
block|{
name|u_char
name|c_host
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|s_host
index|[
literal|3
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ns_net
block|{
name|u_char
name|c_net
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|s_net
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ns_net_u
block|{
name|union
name|ns_net
name|net_e
decl_stmt|;
name|u_long
name|long_e
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ns_addr
block|{
name|union
name|ns_net
name|x_net
decl_stmt|;
name|union
name|ns_host
name|x_host
decl_stmt|;
name|u_short
name|x_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket address, Xerox style  */
end_comment

begin_struct
struct|struct
name|sockaddr_ns
block|{
name|u_char
name|sns_len
decl_stmt|;
name|u_char
name|sns_family
decl_stmt|;
name|struct
name|ns_addr
name|sns_addr
decl_stmt|;
name|char
name|sns_zero
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sns_port
value|sns_addr.x_port
end_define

begin_define
define|#
directive|define
name|ns_neteqnn
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a).s_net[0]==(b).s_net[0])&& \ 					((a).s_net[1]==(b).s_net[1]))
end_define

begin_define
define|#
directive|define
name|ns_neteq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ns_neteqnn((a).x_net, (b).x_net)
end_define

begin_define
define|#
directive|define
name|satons_addr
parameter_list|(
name|sa
parameter_list|)
value|(((struct sockaddr_ns *)&(sa))->sns_addr)
end_define

begin_define
define|#
directive|define
name|ns_hosteqnh
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s).s_host[0] == (t).s_host[0]&& \ 	(s).s_host[1] == (t).s_host[1]&& (s).s_host[2] == (t).s_host[2])
end_define

begin_define
define|#
directive|define
name|ns_hosteq
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(ns_hosteqnh((s).x_host,(t).x_host))
end_define

begin_define
define|#
directive|define
name|ns_nullhost
parameter_list|(
name|x
parameter_list|)
value|(((x).x_host.s_host[0]==0)&& \ 	((x).x_host.s_host[1]==0)&& ((x).x_host.s_host[2]==0))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|nsdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_thishost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_zerohost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_broadhost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_net
name|ns_zeronet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_net
name|ns_broadnet
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_short
name|ns_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__BEGIN_DECLS
specifier|extern
expr|struct
name|ns_addr
name|ns_addr
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|ns_ntoa
parameter_list|(
name|struct
name|ns_addr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

