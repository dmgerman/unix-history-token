begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)in_var.h	7.6 (Berkeley) 6/28/90  *	$Id: in_var.h,v 1.4 1993/11/18 00:08:17 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_VAR_H_
value|1
end_define

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each interface with an Internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|in_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
comment|/* ia_{,sub}net{,mask} in host order */
name|u_long
name|ia_net
decl_stmt|;
comment|/* network number of interface */
name|u_long
name|ia_netmask
decl_stmt|;
comment|/* mask of net part */
name|u_long
name|ia_subnet
decl_stmt|;
comment|/* subnet number, including net */
name|u_long
name|ia_subnetmask
decl_stmt|;
comment|/* mask of subnet part */
name|struct
name|in_addr
name|ia_netbroadcast
decl_stmt|;
comment|/* to recognize net broadcasts */
name|struct
name|in_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of internet addresses */
name|struct
name|sockaddr_in
name|ia_addr
decl_stmt|;
comment|/* reserve space for interface name */
name|struct
name|sockaddr_in
name|ia_dstaddr
decl_stmt|;
comment|/* reserve space for broadcast addr */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_in
name|ia_sockmask
decl_stmt|;
comment|/* reserve space for general netmask */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|in_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_in
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|ifra_broadaddr
decl_stmt|;
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
name|struct
name|sockaddr_in
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an in_ifaddr (ifaddr),  * return a pointer to the addr as a sockaddr_in.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIN
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct in_ifaddr *)(ia))->ia_addr))
end_define

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration */
end_comment

begin_typedef
typedef|typedef
name|void
name|in_input_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|in_output_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|in_ctlinput_t
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|in_ctloutput_t
parameter_list|(
name|int
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * This structure is a pun for `struct protosw'. The difference is that it  * has appropriate interprotocol hook prototypes for the Internet family.  */
end_comment

begin_struct
struct|struct
name|in_protosw
block|{
name|short
name|pr_type
decl_stmt|;
comment|/* socket type used for */
name|struct
name|domain
modifier|*
name|pr_domain
decl_stmt|;
comment|/* domain protocol a member of */
name|short
name|pr_protocol
decl_stmt|;
comment|/* protocol number */
name|short
name|pr_flags
decl_stmt|;
comment|/* see below */
comment|/* protocol-protocol hooks */
name|in_input_t
modifier|*
name|pr_input
decl_stmt|;
name|in_output_t
modifier|*
name|pr_output
decl_stmt|;
name|in_ctlinput_t
modifier|*
name|pr_ctlinput
decl_stmt|;
name|in_ctloutput_t
modifier|*
name|pr_ctloutput
decl_stmt|;
comment|/* user-protocol hook */
name|int
function_decl|(
modifier|*
name|pr_usrreq
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* utility hooks */
name|void
function_decl|(
modifier|*
name|pr_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* initialization hook */
name|void
function_decl|(
modifier|*
name|pr_fasttimo
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* fast timeout (200ms) */
name|void
function_decl|(
modifier|*
name|pr_slowtimo
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* slow timeout (500ms) */
name|void
function_decl|(
modifier|*
name|pr_drain
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* flush any excess space possible */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|in_iaonnetof
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|ifptoia
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_ifinit
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|in_ifaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_cksum
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|in_protosw
name|inetsw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|inetdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ip_protox
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|inetctlerrmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|zeroin_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From in_var.c: */
end_comment

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|subnetsarelocal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* obsolescent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ipqmaxlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
modifier|*
name|ip_ifmatrix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipforwarding
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|ipaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|route
name|ipforward_rt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipsendredirects
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MTUDISC
end_ifdef

begin_function_decl
specifier|extern
name|unsigned
name|in_nextmtu
parameter_list|(
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|in_routemtu
parameter_list|(
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_mtureduce
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|in_mtutimer
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTUDISC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_VAR_H_ */
end_comment

end_unit

