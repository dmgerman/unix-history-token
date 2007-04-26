begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: in6.h,v 1.89 2001/05/27 13:28:35 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in.h	8.3 (Berkeley) 1/3/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KAME_NETINET_IN_H_INCLUDED_
end_ifndef

begin_error
error|#
directive|error
literal|"do not include netinet6/in6.h directly, include netinet/in.h.  see RFC2553"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_IN6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_IN6_H_
end_define

begin_comment
comment|/*  * Identification of the network protocol stack  * for *BSD-current/release: http://www.kame.net/dev/cvsweb.cgi/kame/COVERAGE  * has the table of implementation/integration differences.  */
end_comment

begin_define
define|#
directive|define
name|__KAME__
end_define

begin_define
define|#
directive|define
name|__KAME_VERSION
value|"20010528/FreeBSD"
end_define

begin_comment
comment|/*  * Local port number conventions:  *  * Ports< IPPORT_RESERVED are reserved for privileged processes (e.g. root),  * unless a kernel is compiled with IPNOPRIVPORTS defined.  *  * When a user does a bind(2) or connect(2) with a port number of zero,  * a non-conflicting local port address is chosen.  *  * The default range is IPPORT_ANONMIN to IPPORT_ANONMAX, although  * that is settable by sysctl(3); net.inet.ip.anonportmin and  * net.inet.ip.anonportmax respectively.  *  * A user may set the IPPROTO_IP option IP_PORTRANGE to change this  * default assignment range.  *  * The value IP_PORTRANGE_DEFAULT causes the default behavior.  *  * The value IP_PORTRANGE_HIGH is the same as IP_PORTRANGE_DEFAULT,  * and exists only for FreeBSD compatibility purposes.  *  * The value IP_PORTRANGE_LOW changes the range to the "low" are  * that is (by convention) restricted to privileged processes.  * This convention is based on "vouchsafe" principles only.  * It is only secure if you trust the remote host to restrict these ports.  * The range is IPPORT_RESERVEDMIN to IPPORT_RESERVEDMAX.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|IPV6PORT_RESERVED
value|1024
end_define

begin_define
define|#
directive|define
name|IPV6PORT_ANONMIN
value|49152
end_define

begin_define
define|#
directive|define
name|IPV6PORT_ANONMAX
value|65535
end_define

begin_define
define|#
directive|define
name|IPV6PORT_RESERVEDMIN
value|600
end_define

begin_define
define|#
directive|define
name|IPV6PORT_RESERVEDMAX
value|(IPV6PORT_RESERVED-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IPv6 address  */
end_comment

begin_struct
struct|struct
name|in6_addr
block|{
union|union
block|{
name|uint8_t
name|__u6_addr8
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|__u6_addr16
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|__u6_addr32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__u6_addr
union|;
comment|/* 128-bit IP6 address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|s6_addr
value|__u6_addr.__u6_addr8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX nonstandard */
end_comment

begin_define
define|#
directive|define
name|s6_addr8
value|__u6_addr.__u6_addr8
end_define

begin_define
define|#
directive|define
name|s6_addr16
value|__u6_addr.__u6_addr16
end_define

begin_define
define|#
directive|define
name|s6_addr32
value|__u6_addr.__u6_addr32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_comment
comment|/*  * XXX missing POSIX.1-2001 macro IPPROTO_IPV6.  */
end_comment

begin_comment
comment|/*  * Socket address for IPv6  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIN6_LEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sockaddr_in6
block|{
name|uint8_t
name|sin6_len
decl_stmt|;
comment|/* length of this struct */
name|sa_family_t
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 */
name|in_port_t
name|sin6_port
decl_stmt|;
comment|/* Transport layer port # */
name|uint32_t
name|sin6_flowinfo
decl_stmt|;
comment|/* IP6 flow information */
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
comment|/* IP6 address */
name|uint32_t
name|sin6_scope_id
decl_stmt|;
comment|/* scope zone index */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Local definition for masks  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX nonstandard */
end_comment

begin_define
define|#
directive|define
name|IN6MASK0
value|{{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }}}
end_define

begin_define
define|#
directive|define
name|IN6MASK32
value|{{{ 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, \ 			    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_define
define|#
directive|define
name|IN6MASK64
value|{{{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \ 			    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_define
define|#
directive|define
name|IN6MASK96
value|{{{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \ 			    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_define
define|#
directive|define
name|IN6MASK128
value|{{{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \ 			    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sockaddr_in6
name|sa6_any
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6mask0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6mask32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6mask64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6mask96
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6mask128
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Macros started with IPV6_ADDR is KAME local  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX nonstandard */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_ONE
value|1
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_TWO
value|2
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_MNL
value|0xff010000
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_MLL
value|0xff020000
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_SMP
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_ULL
value|0xfe80
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_USL
value|0xfec0
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_MLL
value|0xff02
end_define

begin_elif
elif|#
directive|elif
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_ONE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_TWO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_MNL
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_MLL
value|0x000002ff
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_SMP
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_ULL
value|0x80fe
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_USL
value|0xc0fe
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_INT16_MLL
value|0x02ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definition of some useful macros to handle IP6 addresses  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
define|\
value|{{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
define|\
value|{{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_NODELOCAL_ALLNODES_INIT
define|\
value|{{{ 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_INTFACELOCAL_ALLNODES_INIT
define|\
value|{{{ 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLNODES_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLROUTERS_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 }}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_any
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_loopback
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_nodelocal_allnodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_linklocal_allnodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_linklocal_allrouters
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Equality  * NOTE: Some of kernel programming environment (for example, openbsd/sparc)  * does not supply memcmp().  For userland memcmp() is preferred as it is  * in ANSI standard.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IN6_ARE_ADDR_EQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(bcmp(&(a)->s6_addr[0],&(b)->s6_addr[0], sizeof(struct in6_addr)) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|IN6_ARE_ADDR_EQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(memcmp(&(a)->s6_addr[0],&(b)->s6_addr[0], sizeof(struct in6_addr)) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* non standard */
end_comment

begin_comment
comment|/* see if two addresses are equal in a scope-conscious manner. */
end_comment

begin_define
define|#
directive|define
name|SA6_ARE_ADDR_EQUAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)->sin6_scope_id == 0 || (b)->sin6_scope_id == 0 || \ 	  ((a)->sin6_scope_id == (b)->sin6_scope_id))&& \ 	 (bcmp(&(a)->sin6_addr,&(b)->sin6_addr, sizeof(struct in6_addr)) == 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unspecified  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_UNSPECIFIED
parameter_list|(
name|a
parameter_list|)
define|\
value|((*(const u_int32_t *)(const void *)(&(a)->s6_addr[0]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[4]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[8]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[12]) == 0))
end_define

begin_comment
comment|/*  * Loopback  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|((*(const u_int32_t *)(const void *)(&(a)->s6_addr[0]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[4]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[8]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[12]) == ntohl(1)))
end_define

begin_comment
comment|/*  * IPv4 compatible  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4COMPAT
parameter_list|(
name|a
parameter_list|)
define|\
value|((*(const u_int32_t *)(const void *)(&(a)->s6_addr[0]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[4]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[8]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[12]) != 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[12]) != ntohl(1)))
end_define

begin_comment
comment|/*  * Mapped  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|a
parameter_list|)
define|\
value|((*(const u_int32_t *)(const void *)(&(a)->s6_addr[0]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[4]) == 0)&&	\ 	 (*(const u_int32_t *)(const void *)(&(a)->s6_addr[8]) == ntohl(0x0000ffff)))
end_define

begin_comment
comment|/*  * KAME Scope Values  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX nonstandard */
end_comment

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_NODELOCAL
value|0x01
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_INTFACELOCAL
value|0x01
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_LINKLOCAL
value|0x02
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_SITELOCAL
value|0x05
end_define

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_ORGLOCAL
value|0x08
end_define

begin_comment
comment|/* just used in this file */
end_comment

begin_define
define|#
directive|define
name|IPV6_ADDR_SCOPE_GLOBAL
value|0x0e
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_NODELOCAL
value|0x01
end_define

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_INTFACELOCAL
value|0x01
end_define

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_LINKLOCAL
value|0x02
end_define

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_SITELOCAL
value|0x05
end_define

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_ORGLOCAL
value|0x08
end_define

begin_comment
comment|/* just used in this file */
end_comment

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_GLOBAL
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Unicast Scope  * Note that we must check topmost 10 bits only, not 16 bits (see RFC2373).  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0x80))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)->s6_addr[0] == 0xfe)&& (((a)->s6_addr[1]& 0xc0) == 0xc0))
end_define

begin_comment
comment|/*  * Multicast  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|((a)->s6_addr[0] == 0xff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* XXX nonstandard */
end_comment

begin_define
define|#
directive|define
name|IPV6_ADDR_MC_SCOPE
parameter_list|(
name|a
parameter_list|)
value|((a)->s6_addr[1]& 0x0f)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__IPV6_ADDR_MC_SCOPE
parameter_list|(
name|a
parameter_list|)
value|((a)->s6_addr[1]& 0x0f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Multicast Scope  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* refers nonstandard items */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_NODELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_NODELOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_INTFACELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_INTFACELOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_LINKLOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&& 	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_SITELOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_ORGLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_ORGLOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_GLOBAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (IPV6_ADDR_MC_SCOPE(a) == IPV6_ADDR_SCOPE_GLOBAL))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_NODELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_NODELOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_LINKLOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&& 	\ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_SITELOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_ORGLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_ORGLOCAL))
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_GLOBAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&	\ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_GLOBAL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* nonstandard */
end_comment

begin_comment
comment|/*  * KAME Scope  */
end_comment

begin_define
define|#
directive|define
name|IN6_IS_SCOPE_LINKLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|((IN6_IS_ADDR_LINKLOCAL(a)) ||	\ 	 (IN6_IS_ADDR_MC_LINKLOCAL(a)))
end_define

begin_define
define|#
directive|define
name|IFA6_IS_DEPRECATED
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)->ia6_lifetime.ia6t_preferred != 0&& \ 	 (a)->ia6_lifetime.ia6t_preferred< time_second)
end_define

begin_define
define|#
directive|define
name|IFA6_IS_INVALID
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)->ia6_lifetime.ia6t_expire != 0&& \ 	 (a)->ia6_lifetime.ia6t_expire< time_second)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * IP6 route structure  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_struct
struct|struct
name|route_in6
block|{
name|struct
name|rtentry
modifier|*
name|ro_rt
decl_stmt|;
name|struct
name|sockaddr_in6
name|ro_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Options for use with [gs]etsockopt at the IPV6 level.  * First word of comment is data type; bool is stored in int.  */
end_comment

begin_comment
comment|/* no hdrincl */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* the followings are relic in IPv4 and hence are disabled */
end_comment

begin_define
define|#
directive|define
name|IPV6_OPTIONS
value|1
end_define

begin_comment
comment|/* buf/ip6_opts; set/get IP6 options */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVOPTS
value|5
end_define

begin_comment
comment|/* bool; receive all IP6 opts w/dgram */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVRETOPTS
value|6
end_define

begin_comment
comment|/* bool; receive IP6 opts for response */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVDSTADDR
value|7
end_define

begin_comment
comment|/* bool; receive IP6 dst addr w/dgram */
end_comment

begin_define
define|#
directive|define
name|IPV6_RETOPTS
value|8
end_define

begin_comment
comment|/* ip6_opts; set/get IP6 options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6_SOCKOPT_RESERVED1
value|3
end_define

begin_comment
comment|/* reserved for future use */
end_comment

begin_define
define|#
directive|define
name|IPV6_UNICAST_HOPS
value|4
end_define

begin_comment
comment|/* int; IP6 hops */
end_comment

begin_define
define|#
directive|define
name|IPV6_MULTICAST_IF
value|9
end_define

begin_comment
comment|/* u_int; set/get IP6 multicast i/f  */
end_comment

begin_define
define|#
directive|define
name|IPV6_MULTICAST_HOPS
value|10
end_define

begin_comment
comment|/* int; set/get IP6 multicast hops */
end_comment

begin_define
define|#
directive|define
name|IPV6_MULTICAST_LOOP
value|11
end_define

begin_comment
comment|/* u_int; set/get IP6 multicast loopback */
end_comment

begin_define
define|#
directive|define
name|IPV6_JOIN_GROUP
value|12
end_define

begin_comment
comment|/* ip6_mreq; join a group membership */
end_comment

begin_define
define|#
directive|define
name|IPV6_LEAVE_GROUP
value|13
end_define

begin_comment
comment|/* ip6_mreq; leave a group membership */
end_comment

begin_define
define|#
directive|define
name|IPV6_PORTRANGE
value|14
end_define

begin_comment
comment|/* int; range to choose for unspec port */
end_comment

begin_define
define|#
directive|define
name|ICMP6_FILTER
value|18
end_define

begin_comment
comment|/* icmp6_filter; icmp6 filter */
end_comment

begin_comment
comment|/* RFC2292 options */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IPV6_2292PKTINFO
value|19
end_define

begin_comment
comment|/* bool; send/recv if, src/dst addr */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292HOPLIMIT
value|20
end_define

begin_comment
comment|/* bool; hop limit */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292NEXTHOP
value|21
end_define

begin_comment
comment|/* bool; next hop addr */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292HOPOPTS
value|22
end_define

begin_comment
comment|/* bool; hop-by-hop option */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292DSTOPTS
value|23
end_define

begin_comment
comment|/* bool; destinaion option */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292RTHDR
value|24
end_define

begin_comment
comment|/* bool; routing header */
end_comment

begin_define
define|#
directive|define
name|IPV6_2292PKTOPTIONS
value|25
end_define

begin_comment
comment|/* buf/cmsghdr; set/get IPv6 options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6_CHECKSUM
value|26
end_define

begin_comment
comment|/* int; checksum offset for raw socket */
end_comment

begin_define
define|#
directive|define
name|IPV6_V6ONLY
value|27
end_define

begin_comment
comment|/* bool; make AF_INET6 sockets v6 only */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|IPV6_BINDV6ONLY
value|IPV6_V6ONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* IPSEC */
end_comment

begin_define
define|#
directive|define
name|IPV6_IPSEC_POLICY
value|28
end_define

begin_comment
comment|/* struct; get/set security policy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6_FAITH
value|29
end_define

begin_comment
comment|/* bool; accept FAITH'ed connections */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* IPV6FIREWALL */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_ADD
value|30
end_define

begin_comment
comment|/* add a firewall rule to chain */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_DEL
value|31
end_define

begin_comment
comment|/* delete a firewall rule from chain */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_FLUSH
value|32
end_define

begin_comment
comment|/* flush firewall rule chain */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_ZERO
value|33
end_define

begin_comment
comment|/* clear single/all firewall counter(s) */
end_comment

begin_define
define|#
directive|define
name|IPV6_FW_GET
value|34
end_define

begin_comment
comment|/* get entire firewall rule chain */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* new socket options introduced in RFC3542 */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDRDSTOPTS
value|35
end_define

begin_comment
comment|/* ip6_dest; send dst option before rthdr */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVPKTINFO
value|36
end_define

begin_comment
comment|/* bool; recv if, dst addr */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVHOPLIMIT
value|37
end_define

begin_comment
comment|/* bool; recv hop limit */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVRTHDR
value|38
end_define

begin_comment
comment|/* bool; recv routing header */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVHOPOPTS
value|39
end_define

begin_comment
comment|/* bool; recv hop-by-hop option */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVDSTOPTS
value|40
end_define

begin_comment
comment|/* bool; recv dst option after rthdr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IPV6_RECVRTHDRDSTOPTS
value|41
end_define

begin_comment
comment|/* bool; recv dst option before rthdr */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6_USE_MIN_MTU
value|42
end_define

begin_comment
comment|/* bool; send packets at the minimum MTU */
end_comment

begin_define
define|#
directive|define
name|IPV6_RECVPATHMTU
value|43
end_define

begin_comment
comment|/* bool; notify an according MTU */
end_comment

begin_define
define|#
directive|define
name|IPV6_PATHMTU
value|44
end_define

begin_comment
comment|/* mtuinfo; get the current path MTU (sopt), 				      4 bytes int; MTU notification (cmsg) */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*obsoleted during 2292bis -> 3542*/
end_comment

begin_define
define|#
directive|define
name|IPV6_REACHCONF
value|45
end_define

begin_comment
comment|/* no data; ND reachability confirm 				      (cmsg only/not in of RFC3542) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* more new socket options introduced in RFC3542 */
end_comment

begin_define
define|#
directive|define
name|IPV6_PKTINFO
value|46
end_define

begin_comment
comment|/* in6_pktinfo; send if, src addr */
end_comment

begin_define
define|#
directive|define
name|IPV6_HOPLIMIT
value|47
end_define

begin_comment
comment|/* int; send hop limit */
end_comment

begin_define
define|#
directive|define
name|IPV6_NEXTHOP
value|48
end_define

begin_comment
comment|/* sockaddr; next hop addr */
end_comment

begin_define
define|#
directive|define
name|IPV6_HOPOPTS
value|49
end_define

begin_comment
comment|/* ip6_hbh; send hop-by-hop option */
end_comment

begin_define
define|#
directive|define
name|IPV6_DSTOPTS
value|50
end_define

begin_comment
comment|/* ip6_dest; send dst option befor rthdr */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDR
value|51
end_define

begin_comment
comment|/* ip6_rthdr; send routing header */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|IPV6_PKTOPTIONS
value|52
end_define

begin_comment
comment|/* buf/cmsghdr; set/get IPv6 options */
end_comment

begin_comment
comment|/* obsoleted by RFC3542 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6_RECVTCLASS
value|57
end_define

begin_comment
comment|/* bool; recv traffic class values */
end_comment

begin_define
define|#
directive|define
name|IPV6_AUTOFLOWLABEL
value|59
end_define

begin_comment
comment|/* bool; attach flowlabel automagically */
end_comment

begin_define
define|#
directive|define
name|IPV6_TCLASS
value|61
end_define

begin_comment
comment|/* int; send traffic class value */
end_comment

begin_define
define|#
directive|define
name|IPV6_DONTFRAG
value|62
end_define

begin_comment
comment|/* bool; disable IPv6 fragmentation */
end_comment

begin_define
define|#
directive|define
name|IPV6_PREFER_TEMPADDR
value|63
end_define

begin_comment
comment|/* int; prefer temporary addresses as 				    * the source address. 				    */
end_comment

begin_comment
comment|/* to define items, should talk with KAME guys first, for *BSD compatibility */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDR_LOOSE
value|0
end_define

begin_comment
comment|/* this hop need not be a neighbor. XXX old spec */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDR_STRICT
value|1
end_define

begin_comment
comment|/* this hop must be a neighbor. XXX old spec */
end_comment

begin_define
define|#
directive|define
name|IPV6_RTHDR_TYPE_0
value|0
end_define

begin_comment
comment|/* IPv6 routing header type 0 */
end_comment

begin_comment
comment|/*  * Defaults and limits for options  */
end_comment

begin_define
define|#
directive|define
name|IPV6_DEFAULT_MULTICAST_HOPS
value|1
end_define

begin_comment
comment|/* normally limit m'casts to 1 hop */
end_comment

begin_define
define|#
directive|define
name|IPV6_DEFAULT_MULTICAST_LOOP
value|1
end_define

begin_comment
comment|/* normally hear sends if a member */
end_comment

begin_comment
comment|/*  * Argument structure for IPV6_JOIN_GROUP and IPV6_LEAVE_GROUP.  */
end_comment

begin_struct
struct|struct
name|ipv6_mreq
block|{
name|struct
name|in6_addr
name|ipv6mr_multiaddr
decl_stmt|;
name|unsigned
name|int
name|ipv6mr_interface
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IPV6_PKTINFO: Packet information(RFC2292 sec 5)  */
end_comment

begin_struct
struct|struct
name|in6_pktinfo
block|{
name|struct
name|in6_addr
name|ipi6_addr
decl_stmt|;
comment|/* src/dst IPv6 address */
name|unsigned
name|int
name|ipi6_ifindex
decl_stmt|;
comment|/* send/recv interface index */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control structure for IPV6_RECVPATHMTU socket option.  */
end_comment

begin_struct
struct|struct
name|ip6_mtuinfo
block|{
name|struct
name|sockaddr_in6
name|ip6m_addr
decl_stmt|;
comment|/* or sockaddr_storage? */
name|uint32_t
name|ip6m_mtu
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Argument for IPV6_PORTRANGE:  * - which range to search when port is unspecified at bind() or connect()  */
end_comment

begin_define
define|#
directive|define
name|IPV6_PORTRANGE_DEFAULT
value|0
end_define

begin_comment
comment|/* default range */
end_comment

begin_define
define|#
directive|define
name|IPV6_PORTRANGE_HIGH
value|1
end_define

begin_comment
comment|/* "high" - request firewall bypass */
end_comment

begin_define
define|#
directive|define
name|IPV6_PORTRANGE_LOW
value|2
end_define

begin_comment
comment|/* "low" - vouchsafe security */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * Definitions for inet6 sysctl operations.  *  * Third level is protocol number.  * Fourth level is desired variable within that protocol.  */
end_comment

begin_define
define|#
directive|define
name|IPV6PROTO_MAXID
value|(IPPROTO_PIM + 1)
end_define

begin_comment
comment|/* don't list to IPV6PROTO_MAX */
end_comment

begin_comment
comment|/*  * Names for IP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_FORWARDING
value|1
end_define

begin_comment
comment|/* act as router */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_SENDREDIRECTS
value|2
end_define

begin_comment
comment|/* may send redirects when forwarding*/
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_DEFHLIM
value|3
end_define

begin_comment
comment|/* default Hop-Limit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|IPV6CTL_DEFMTU
value|4
end_define

begin_comment
comment|/* default MTU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6CTL_FORWSRCRT
value|5
end_define

begin_comment
comment|/* forward source-routed dgrams */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_STATS
value|6
end_define

begin_comment
comment|/* stats */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_MRTSTATS
value|7
end_define

begin_comment
comment|/* multicast forwarding stats */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_MRTPROTO
value|8
end_define

begin_comment
comment|/* multicast routing protocol */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_MAXFRAGPACKETS
value|9
end_define

begin_comment
comment|/* max packets reassembly queue */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_SOURCECHECK
value|10
end_define

begin_comment
comment|/* verify source route and intf */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_SOURCECHECK_LOGINT
value|11
end_define

begin_comment
comment|/* minimume logging interval */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_ACCEPT_RTADV
value|12
end_define

begin_define
define|#
directive|define
name|IPV6CTL_KEEPFAITH
value|13
end_define

begin_define
define|#
directive|define
name|IPV6CTL_LOG_INTERVAL
value|14
end_define

begin_define
define|#
directive|define
name|IPV6CTL_HDRNESTLIMIT
value|15
end_define

begin_define
define|#
directive|define
name|IPV6CTL_DAD_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|IPV6CTL_AUTO_FLOWLABEL
value|17
end_define

begin_define
define|#
directive|define
name|IPV6CTL_DEFMCASTHLIM
value|18
end_define

begin_define
define|#
directive|define
name|IPV6CTL_GIF_HLIM
value|19
end_define

begin_comment
comment|/* default HLIM for gif encap packet */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_KAME_VERSION
value|20
end_define

begin_define
define|#
directive|define
name|IPV6CTL_USE_DEPRECATED
value|21
end_define

begin_comment
comment|/* use deprecated addr (RFC2462 5.5.4) */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_RR_PRUNE
value|22
end_define

begin_comment
comment|/* walk timer for router renumbering */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_MAPPED_ADDR
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPV6CTL_V6ONLY
value|24
end_define

begin_define
define|#
directive|define
name|IPV6CTL_RTEXPIRE
value|25
end_define

begin_comment
comment|/* cloned route expiration time */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_RTMINEXPIRE
value|26
end_define

begin_comment
comment|/* min value for expiration time */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_RTMAXCACHE
value|27
end_define

begin_comment
comment|/* trigger level for dynamic expire */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_USETEMPADDR
value|32
end_define

begin_comment
comment|/* use temporary addresses (RFC3041) */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_TEMPPLTIME
value|33
end_define

begin_comment
comment|/* preferred lifetime for tmpaddrs */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_TEMPVLTIME
value|34
end_define

begin_comment
comment|/* valid lifetime for tmpaddrs */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_AUTO_LINKLOCAL
value|35
end_define

begin_comment
comment|/* automatic link-local addr assign */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_RIP6STATS
value|36
end_define

begin_comment
comment|/* raw_ip6 stats */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_PREFER_TEMPADDR
value|37
end_define

begin_comment
comment|/* prefer temporary addr as src */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_ADDRCTLPOLICY
value|38
end_define

begin_comment
comment|/* get/set address selection policy */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_MAXFRAGS
value|41
end_define

begin_comment
comment|/* max fragments */
end_comment

begin_comment
comment|/* New entries should be added here from current IPV6CTL_MAXID value. */
end_comment

begin_comment
comment|/* to define items, should talk with KAME guys first, for *BSD compatibility */
end_comment

begin_comment
comment|/* 42-44 is already used in KAME */
end_comment

begin_define
define|#
directive|define
name|IPV6CTL_STEALTH
value|45
end_define

begin_define
define|#
directive|define
name|IPV6CTL_RTHDR0_ALLOWED
value|46
end_define

begin_define
define|#
directive|define
name|IPV6CTL_MAXID
value|47
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * Redefinition of mbuf flags  */
end_comment

begin_define
define|#
directive|define
name|M_AUTHIPHDR
value|M_PROTO2
end_define

begin_define
define|#
directive|define
name|M_DECRYPTED
value|M_PROTO3
end_define

begin_define
define|#
directive|define
name|M_LOOP
value|M_PROTO4
end_define

begin_define
define|#
directive|define
name|M_AUTHIPDGM
value|M_PROTO5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|cmsghdr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|in6_cksum
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|u_int8_t
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_localaddr
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in6_addrscope
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in6_ifaddr
modifier|*
name|in6_ifawithifp
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|in6_if_up
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|u_char
name|ip6_protox
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_sin6_2_sin
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
name|sin
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sin6
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_sin_2_v4mapsin6
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
name|sin
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sin6
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_sin6_2_sin_in_sock
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in6_sin_2_v4mapsin6_in_sock
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addrsel_policy_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|satosin6
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in6 *)(sa))
end_define

begin_define
define|#
directive|define
name|sin6tosa
parameter_list|(
name|sin6
parameter_list|)
value|((struct sockaddr *)(sin6))
end_define

begin_define
define|#
directive|define
name|ifatoia6
parameter_list|(
name|ifa
parameter_list|)
value|((struct in6_ifaddr *)(ifa))
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|faithprefix_p
function_decl|)
parameter_list|(
name|struct
name|in6_addr
modifier|*
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SOCKLEN_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__socklen_t
name|socklen_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SOCKLEN_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|cmsghdr
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|inet6_option_space
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_option_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|cmsghdr
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_option_append
name|__P
argument_list|(
operator|(
expr|struct
name|cmsghdr
operator|*
operator|,
specifier|const
name|uint8_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
modifier|*
name|inet6_option_alloc
name|__P
argument_list|(
operator|(
expr|struct
name|cmsghdr
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_option_next
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmsghdr
operator|*
operator|,
name|uint8_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_option_find
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmsghdr
operator|*
operator|,
name|uint8_t
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|inet6_rthdr_space
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmsghdr
modifier|*
name|inet6_rthdr_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rthdr_add
name|__P
argument_list|(
operator|(
expr|struct
name|cmsghdr
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rthdr_lasthop
name|__P
argument_list|(
operator|(
expr|struct
name|cmsghdr
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not implemented yet */
end_comment

begin_endif
unit|extern int inet6_rthdr_reverse __P((const struct cmsghdr *, struct cmsghdr *));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|inet6_rthdr_segments
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmsghdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in6_addr
modifier|*
name|inet6_rthdr_getaddr
name|__P
argument_list|(
operator|(
expr|struct
name|cmsghdr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rthdr_getflags
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|cmsghdr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_append
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|int
operator|,
name|uint8_t
operator|,
name|socklen_t
operator|,
name|uint8_t
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_finish
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_set_val
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|socklen_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_next
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|int
operator|,
name|uint8_t
operator|*
operator|,
name|socklen_t
operator|*
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_find
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|int
operator|,
name|uint8_t
operator|,
name|socklen_t
operator|*
operator|,
name|void
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_opt_get_val
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|socklen_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|socklen_t
name|inet6_rth_space
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|inet6_rth_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rth_add
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rth_reverse
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_rth_segments
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in6_addr
modifier|*
name|inet6_rth_getaddr
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET6_IN6_H_ */
end_comment

end_unit

