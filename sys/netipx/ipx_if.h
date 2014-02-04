begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.   * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx_if.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_IF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_IF_H_
end_define

begin_comment
comment|/*  * Interface address.  One of these structures  * is allocated for each interface with an internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|ipx_ifaddr
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
name|TAILQ_ENTRY
argument_list|(
argument|ipx_ifaddr
argument_list|)
name|ia_link
expr_stmt|;
comment|/* list of IPv6 addresses */
name|struct
name|sockaddr_ipx
name|ia_addr
decl_stmt|;
comment|/* reserve space for my address */
name|struct
name|sockaddr_ipx
name|ia_dstaddr
decl_stmt|;
comment|/* space for my broadcast address */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_ipx
name|ia_netmask
decl_stmt|;
comment|/* space for my network mask */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|ipx_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_ipx
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_ipx
name|ifra_broadaddr
decl_stmt|;
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
block|}
struct|;
end_struct

begin_comment
comment|/*  * List of ipx_ifaddr's.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ipx_ifaddrhead
argument_list|,
name|ipx_ifaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Given a pointer to an ipx_ifaddr (ifaddr),  * return a pointer to the addr as a sockadd_ipx.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIPX
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct ipx_ifaddr *)(ia))->ia_addr))
end_define

begin_comment
comment|/* This is not the right place for this but where is? */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX_8022
value|0x00e0
end_define

begin_comment
comment|/* Ethernet_802.2 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX_8023
value|0x0000
end_define

begin_comment
comment|/* Ethernet_802.3 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX_II
value|0x8137
end_define

begin_comment
comment|/* Ethernet_II */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX_SNAP
value|0x8137
end_define

begin_comment
comment|/* Ethernet_SNAP */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX
value|0x8137
end_define

begin_comment
comment|/* Only  Ethernet_II Available */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|ipx_ifaddr_rw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipx_ifaddrhead
name|ipx_ifaddrhead
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPX_IFADDR_LOCK_INIT
parameter_list|()
value|rw_init(&ipx_ifaddr_rw, "ipx_ifaddr_rw")
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_LOCK_ASSERT
parameter_list|()
value|rw_assert(&ipx_ifaddr_rw, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_RLOCK
parameter_list|()
value|rw_rlock(&ipx_ifaddr_rw)
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_RUNLOCK
parameter_list|()
value|rw_runlock(&ipx_ifaddr_rw)
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_WLOCK
parameter_list|()
value|rw_wlock(&ipx_ifaddr_rw)
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_WUNLOCK
parameter_list|()
value|rw_wunlock(&ipx_ifaddr_rw)
end_define

begin_define
define|#
directive|define
name|IPX_IFADDR_RLOCK_ASSERT
parameter_list|()
value|rw_assert(&ipx_ifaddr_rw, RA_WLOCKED)
end_define

begin_function_decl
name|struct
name|ipx_ifaddr
modifier|*
name|ipx_iaonnetof
parameter_list|(
name|struct
name|ipx_addr
modifier|*
name|dst
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

begin_comment
comment|/* !_NETIPX_IPX_IF_H_ */
end_comment

end_unit

