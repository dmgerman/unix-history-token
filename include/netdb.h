begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1983, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  *      @(#)netdb.h	8.1 (Berkeley) 6/2/93  *      From: Id: netdb.h,v 8.9 1996/11/19 08:39:29 vixie Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETDB_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SOCKLEN_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SOCKLEN_T_
name|socklen_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SOCKLEN_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HEQUIV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HEQUIV
value|"/etc/hosts.equiv"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_HOSTS
value|"/etc/hosts"
end_define

begin_define
define|#
directive|define
name|_PATH_NETWORKS
value|"/etc/networks"
end_define

begin_define
define|#
directive|define
name|_PATH_PROTOCOLS
value|"/etc/protocols"
end_define

begin_define
define|#
directive|define
name|_PATH_SERVICES
value|"/etc/services"
end_define

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structures returned by network data base library.  All addresses are  * supplied in host order, and returned in network order (suitable for  * use in system calls).  */
end_comment

begin_struct
struct|struct
name|hostent
block|{
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
modifier|*
name|h_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|h_addrtype
decl_stmt|;
comment|/* host address type */
name|int
name|h_length
decl_stmt|;
comment|/* length of address */
name|char
modifier|*
modifier|*
name|h_addr_list
decl_stmt|;
comment|/* list of addresses from name server */
define|#
directive|define
name|h_addr
value|h_addr_list[0]
comment|/* address, for backward compatibility */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Assumption here is that a network number  * fits in an unsigned long -- probably a poor one.  */
end_comment

begin_struct
struct|struct
name|netent
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* official name of net */
name|char
modifier|*
modifier|*
name|n_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|n_addrtype
decl_stmt|;
comment|/* net address type */
name|unsigned
name|long
name|n_net
decl_stmt|;
comment|/* network # */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|servent
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* official service name */
name|char
modifier|*
modifier|*
name|s_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|s_port
decl_stmt|;
comment|/* port # */
name|char
modifier|*
name|s_proto
decl_stmt|;
comment|/* protocol to use */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|protoent
block|{
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* official protocol name */
name|char
modifier|*
modifier|*
name|p_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|p_proto
decl_stmt|;
comment|/* protocol # */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* canonical name for hostname */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* binary address */
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* next structure in linked list */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error return codes from gethostbyname() and gethostbyaddr()  * (left in extern int h_errno).  */
end_comment

begin_define
define|#
directive|define
name|NETDB_INTERNAL
value|-1
end_define

begin_comment
comment|/* see errno */
end_comment

begin_define
define|#
directive|define
name|NETDB_SUCCESS
value|0
end_define

begin_comment
comment|/* no problem */
end_comment

begin_define
define|#
directive|define
name|HOST_NOT_FOUND
value|1
end_define

begin_comment
comment|/* Authoritative Answer Host not found */
end_comment

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_comment
comment|/* Non-Authoritative Host not found, or SERVERFAIL */
end_comment

begin_define
define|#
directive|define
name|NO_RECOVERY
value|3
end_define

begin_comment
comment|/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
end_comment

begin_define
define|#
directive|define
name|NO_DATA
value|4
end_define

begin_comment
comment|/* Valid name, no data record of requested type */
end_comment

begin_define
define|#
directive|define
name|NO_ADDRESS
value|NO_DATA
end_define

begin_comment
comment|/* no address, look for MX record */
end_comment

begin_comment
comment|/*  * Error return codes from getaddrinfo()  */
end_comment

begin_define
define|#
directive|define
name|EAI_ADDRFAMILY
value|1
end_define

begin_comment
comment|/* address family for hostname not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_AGAIN
value|2
end_define

begin_comment
comment|/* temporary failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_BADFLAGS
value|3
end_define

begin_comment
comment|/* invalid value for ai_flags */
end_comment

begin_define
define|#
directive|define
name|EAI_FAIL
value|4
end_define

begin_comment
comment|/* non-recoverable failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_FAMILY
value|5
end_define

begin_comment
comment|/* ai_family not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_MEMORY
value|6
end_define

begin_comment
comment|/* memory allocation failure */
end_comment

begin_define
define|#
directive|define
name|EAI_NODATA
value|7
end_define

begin_comment
comment|/* no address associated with hostname */
end_comment

begin_define
define|#
directive|define
name|EAI_NONAME
value|8
end_define

begin_comment
comment|/* hostname nor servname provided, or not known */
end_comment

begin_define
define|#
directive|define
name|EAI_SERVICE
value|9
end_define

begin_comment
comment|/* servname not supported for ai_socktype */
end_comment

begin_define
define|#
directive|define
name|EAI_SOCKTYPE
value|10
end_define

begin_comment
comment|/* ai_socktype not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|11
end_define

begin_comment
comment|/* system error returned in errno */
end_comment

begin_define
define|#
directive|define
name|EAI_BADHINTS
value|12
end_define

begin_define
define|#
directive|define
name|EAI_PROTOCOL
value|13
end_define

begin_define
define|#
directive|define
name|EAI_MAX
value|14
end_define

begin_comment
comment|/*  * Flag values for getaddrinfo()  */
end_comment

begin_define
define|#
directive|define
name|AI_PASSIVE
value|0x00000001
end_define

begin_comment
comment|/* get address to use bind() */
end_comment

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x00000002
end_define

begin_comment
comment|/* fill ai_canonname */
end_comment

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|0x00000004
end_define

begin_comment
comment|/* prevent name resolution */
end_comment

begin_comment
comment|/* valid flags for addrinfo */
end_comment

begin_define
define|#
directive|define
name|AI_MASK
define|\
value|(AI_PASSIVE | AI_CANONNAME | AI_NUMERICHOST | AI_ADDRCONFIG)
end_define

begin_define
define|#
directive|define
name|AI_ALL
value|0x00000100
end_define

begin_comment
comment|/* IPv6 and IPv4-mapped (with AI_V4MAPPED) */
end_comment

begin_define
define|#
directive|define
name|AI_V4MAPPED_CFG
value|0x00000200
end_define

begin_comment
comment|/* accept IPv4-mapped if kernel supports */
end_comment

begin_define
define|#
directive|define
name|AI_ADDRCONFIG
value|0x00000400
end_define

begin_comment
comment|/* only if any address is assigned */
end_comment

begin_define
define|#
directive|define
name|AI_V4MAPPED
value|0x00000800
end_define

begin_comment
comment|/* accept IPv4-mapped IPv6 address */
end_comment

begin_comment
comment|/* special recommended flags for getipnodebyname */
end_comment

begin_define
define|#
directive|define
name|AI_DEFAULT
value|(AI_V4MAPPED_CFG | AI_ADDRCONFIG)
end_define

begin_comment
comment|/*  * Constants for getnameinfo()  */
end_comment

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_comment
comment|/*  * Flag values for getnameinfo()  */
end_comment

begin_define
define|#
directive|define
name|NI_NOFQDN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NI_DGRAM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NI_WITHSCOPEID
value|0x00000020
end_define

begin_comment
comment|/*  * Scope delimit character  */
end_comment

begin_define
define|#
directive|define
name|SCOPE_DELIMITER
value|'%'
end_define

begin_function_decl
name|__BEGIN_DECLS
name|void
name|endhostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endnetgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freehostent
parameter_list|(
name|struct
name|hostent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyaddr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|getipnodebyaddr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|getipnodebyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyaddr
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|getnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getnetgrent
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotobyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotobynumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|getprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyport
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|getservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|herror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__const
name|char
modifier|*
name|hstrerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sethostent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void		sethostfile(const char *); */
end_comment

begin_function_decl
name|void
name|setnetent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setprotoent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeaddrinfo
parameter_list|(
name|struct
name|addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setnetgrent
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setservent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PRIVATE functions specific to the FreeBSD implementation  */
end_comment

begin_comment
comment|/* DO NOT USE THESE, THEY ARE SUBJECT TO CHANGE AND ARE NOT PORTABLE!!! */
end_comment

begin_function_decl
name|void
name|_sethosthtent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_endhosthtent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sethostdnsent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_endhostdnsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_setnethtent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_endnethtent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_setnetdnsent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_endnetdnsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|_gethostbynisname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|_gethostbynisaddr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_map_v4v6_address
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_map_v4v6_hostent
parameter_list|(
name|struct
name|hostent
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
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

begin_comment
comment|/* !_NETDB_H_ */
end_comment

end_unit

