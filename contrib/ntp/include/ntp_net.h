begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_net.h - definitions for NTP network stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_NET_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_NET_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_VAR_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_VAR_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_rfc2553.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sa4
decl_stmt|;
name|struct
name|sockaddr_in6
name|sa6
decl_stmt|;
block|}
name|sockaddr_u
typedef|;
end_typedef

begin_comment
comment|/*  * Utilities for manipulating sockaddr_u v4/v6 unions  */
end_comment

begin_define
define|#
directive|define
name|SOCK_ADDR4
parameter_list|(
name|psau
parameter_list|)
value|((psau)->sa4.sin_addr)
end_define

begin_define
define|#
directive|define
name|SOCK_ADDR6
parameter_list|(
name|psau
parameter_list|)
value|((psau)->sa6.sin6_addr)
end_define

begin_define
define|#
directive|define
name|PSOCK_ADDR4
parameter_list|(
name|psau
parameter_list|)
value|(&SOCK_ADDR4(psau))
end_define

begin_define
define|#
directive|define
name|PSOCK_ADDR6
parameter_list|(
name|psau
parameter_list|)
value|(&SOCK_ADDR6(psau))
end_define

begin_define
define|#
directive|define
name|AF
parameter_list|(
name|psau
parameter_list|)
value|((psau)->sa.sa_family)
end_define

begin_define
define|#
directive|define
name|IS_IPV4
parameter_list|(
name|psau
parameter_list|)
value|(AF_INET == AF(psau))
end_define

begin_define
define|#
directive|define
name|IS_IPV6
parameter_list|(
name|psau
parameter_list|)
value|(AF_INET6 == AF(psau))
end_define

begin_comment
comment|/* sockaddr_u v4 address in network byte order */
end_comment

begin_define
define|#
directive|define
name|NSRCADR
parameter_list|(
name|psau
parameter_list|)
value|(SOCK_ADDR4(psau).s_addr)
end_define

begin_comment
comment|/* sockaddr_u v4 address in host byte order */
end_comment

begin_define
define|#
directive|define
name|SRCADR
parameter_list|(
name|psau
parameter_list|)
value|(ntohl(NSRCADR(psau)))
end_define

begin_comment
comment|/* sockaddr_u v6 address in network byte order */
end_comment

begin_define
define|#
directive|define
name|NSRCADR6
parameter_list|(
name|psau
parameter_list|)
value|(SOCK_ADDR6(psau).s6_addr)
end_define

begin_comment
comment|/* assign sockaddr_u v4 address from host byte order */
end_comment

begin_define
define|#
directive|define
name|SET_ADDR4
parameter_list|(
name|psau
parameter_list|,
name|addr4
parameter_list|)
value|(NSRCADR(psau) = htonl(addr4))
end_define

begin_comment
comment|/* assign sockaddr_u v4 address from network byte order */
end_comment

begin_define
define|#
directive|define
name|SET_ADDR4N
parameter_list|(
name|psau
parameter_list|,
name|addr4n
parameter_list|)
value|(NSRCADR(psau) = (addr4n));
end_define

begin_comment
comment|/* assign sockaddr_u v6 address from network byte order */
end_comment

begin_define
define|#
directive|define
name|SET_ADDR6N
parameter_list|(
name|psau
parameter_list|,
name|s6_addr
parameter_list|)
define|\
value|(SOCK_ADDR6(psau) = (s6_addr))
end_define

begin_comment
comment|/* sockaddr_u v4/v6 port in network byte order */
end_comment

begin_define
define|#
directive|define
name|NSRCPORT
parameter_list|(
name|psau
parameter_list|)
value|((psau)->sa4.sin_port)
end_define

begin_comment
comment|/* sockaddr_u v4/v6 port in host byte order */
end_comment

begin_define
define|#
directive|define
name|SRCPORT
parameter_list|(
name|psau
parameter_list|)
value|(ntohs(NSRCPORT(psau)))
end_define

begin_comment
comment|/* assign sockaddr_u v4/v6 port from host byte order */
end_comment

begin_define
define|#
directive|define
name|SET_PORT
parameter_list|(
name|psau
parameter_list|,
name|port
parameter_list|)
value|(NSRCPORT(psau) = htons(port))
end_define

begin_comment
comment|/* sockaddr_u v6 scope */
end_comment

begin_define
define|#
directive|define
name|SCOPE_VAR
parameter_list|(
name|psau
parameter_list|)
value|((psau)->sa6.sin6_scope_id)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVESCOPEID
end_ifdef

begin_comment
comment|/* v4/v6 scope (always zero for v4) */
end_comment

begin_define
define|#
directive|define
name|SCOPE
parameter_list|(
name|psau
parameter_list|)
value|(IS_IPV4(psau)			\ 				    ? 0				\ 				    : SCOPE_VAR(psau))
end_define

begin_comment
comment|/* are two v6 sockaddr_u scopes equal? */
end_comment

begin_define
define|#
directive|define
name|SCOPE_EQ
parameter_list|(
name|psau1
parameter_list|,
name|psau2
parameter_list|)
define|\
value|(SCOPE_VAR(psau1) == SCOPE_VAR(psau2))
end_define

begin_comment
comment|/* assign scope if supported */
end_comment

begin_define
define|#
directive|define
name|SET_SCOPE
parameter_list|(
name|psau
parameter_list|,
name|s
parameter_list|)
define|\
value|do							\ 		if (IS_IPV6(psau))				\ 			SCOPE_VAR(psau) = (s);			\ 	while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_HAVESCOPEID not defined */
end_comment

begin_define
define|#
directive|define
name|SCOPE
parameter_list|(
name|psau
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|SCOPE_EQ
parameter_list|(
name|psau1
parameter_list|,
name|psau2
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|SET_SCOPE
parameter_list|(
name|psau
parameter_list|,
name|s
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_HAVESCOPEID */
end_comment

begin_comment
comment|/* v4/v6 is multicast address */
end_comment

begin_define
define|#
directive|define
name|IS_MCAST
parameter_list|(
name|psau
parameter_list|)
define|\
value|(IS_IPV4(psau)						\ 	    ? IN_CLASSD(SRCADR(psau))				\ 	    : IN6_IS_ADDR_MULTICAST(PSOCK_ADDR6(psau)))
end_define

begin_comment
comment|/* v6 is interface ID scope universal, as with MAC-derived addresses */
end_comment

begin_define
define|#
directive|define
name|IS_IID_UNIV
parameter_list|(
name|psau
parameter_list|)
define|\
value|(!!(0x02& NSRCADR6(psau)[8]))
end_define

begin_define
define|#
directive|define
name|SIZEOF_INADDR
parameter_list|(
name|fam
parameter_list|)
define|\
value|((AF_INET == (fam))					\ 	    ? sizeof(struct in_addr)				\ 	    : sizeof(struct in6_addr))
end_define

begin_define
define|#
directive|define
name|SIZEOF_SOCKADDR
parameter_list|(
name|fam
parameter_list|)
define|\
value|((AF_INET == (fam))					\ 	    ? sizeof(struct sockaddr_in)			\ 	    : sizeof(struct sockaddr_in6))
end_define

begin_define
define|#
directive|define
name|SOCKLEN
parameter_list|(
name|psau
parameter_list|)
define|\
value|(IS_IPV4(psau)						\ 	    ? sizeof((psau)->sa4)				\ 	    : sizeof((psau)->sa6))
end_define

begin_define
define|#
directive|define
name|ZERO_SOCK
parameter_list|(
name|psau
parameter_list|)
define|\
value|ZERO(*(psau))
end_define

begin_comment
comment|/* blast a byte value across sockaddr_u v6 address */
end_comment

begin_define
define|#
directive|define
name|MEMSET_ADDR6
parameter_list|(
name|psau
parameter_list|,
name|v
parameter_list|)
define|\
value|memset((psau)->sa6.sin6_addr.s6_addr, (v),		\ 		sizeof((psau)->sa6.sin6_addr.s6_addr))
end_define

begin_define
define|#
directive|define
name|SET_ONESMASK
parameter_list|(
name|psau
parameter_list|)
define|\
value|do {							\ 		if (IS_IPV6(psau))				\ 			MEMSET_ADDR6((psau), 0xff);		\ 		else						\ 			NSRCADR(psau) = 0xffffffff;		\ 	} while(0)
end_define

begin_comment
comment|/* zero sockaddr_u, fill in family and all-ones (host) mask */
end_comment

begin_define
define|#
directive|define
name|SET_HOSTMASK
parameter_list|(
name|psau
parameter_list|,
name|family
parameter_list|)
define|\
value|do {							\ 		ZERO_SOCK(psau);				\ 		AF(psau) = (family);				\ 		SET_ONESMASK(psau);				\ 	} while (0)
end_define

begin_comment
comment|/*   * compare two in6_addr returning negative, 0, or positive.  * ADDR6_CMP is negative if *pin6A is lower than *pin6B, zero if they  * are equal, positive if *pin6A is higher than *pin6B.  IN6ADDR_ANY  * is the lowest address (128 zero bits).  */
end_comment

begin_define
define|#
directive|define
name|ADDR6_CMP
parameter_list|(
name|pin6A
parameter_list|,
name|pin6B
parameter_list|)
define|\
value|memcmp((pin6A)->s6_addr, (pin6B)->s6_addr,		\ 	       sizeof(pin6A)->s6_addr)
end_define

begin_comment
comment|/* compare two in6_addr for equality only */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|in_addr6
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDR6_EQ
parameter_list|(
name|pin6A
parameter_list|,
name|pin6B
parameter_list|)
define|\
value|(!ADDR6_CMP(pin6A, pin6B))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ADDR6_EQ
parameter_list|(
name|pin6A
parameter_list|,
name|pin6B
parameter_list|)
define|\
value|IN6_ADDR_EQUAL(pin6A, pin6B)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* compare a in6_addr with socket address */
end_comment

begin_define
define|#
directive|define
name|S_ADDR6_EQ
parameter_list|(
name|psau
parameter_list|,
name|pin6
parameter_list|)
define|\
value|ADDR6_EQ(&(psau)->sa6.sin6_addr, pin6)
end_define

begin_comment
comment|/* are two sockaddr_u's addresses equal? (port excluded) */
end_comment

begin_define
define|#
directive|define
name|SOCK_EQ
parameter_list|(
name|psau1
parameter_list|,
name|psau2
parameter_list|)
define|\
value|((AF(psau1) != AF(psau2))				\ 	     ? 0						\ 	     : IS_IPV4(psau1)					\ 		   ? (NSRCADR(psau1) == NSRCADR(psau2))		\ 		   : (S_ADDR6_EQ((psau1), PSOCK_ADDR6(psau2))	\&& SCOPE_EQ((psau1), (psau2))))
end_define

begin_comment
comment|/* are two sockaddr_u's addresses and ports equal? */
end_comment

begin_define
define|#
directive|define
name|ADDR_PORT_EQ
parameter_list|(
name|psau1
parameter_list|,
name|psau2
parameter_list|)
define|\
value|((NSRCPORT(psau1) != NSRCPORT(psau2)			\ 	     ? 0						\ 	     : SOCK_EQ((psau1), (psau2))))
end_define

begin_comment
comment|/* is sockaddr_u address unspecified? */
end_comment

begin_define
define|#
directive|define
name|SOCK_UNSPEC
parameter_list|(
name|psau
parameter_list|)
define|\
value|(IS_IPV4(psau)						\ 	    ? !NSRCADR(psau)					\ 	    : IN6_IS_ADDR_UNSPECIFIED(PSOCK_ADDR6(psau)))
end_define

begin_comment
comment|/* just how unspecified do you mean? (scope 0/unspec too) */
end_comment

begin_define
define|#
directive|define
name|SOCK_UNSPEC_S
parameter_list|(
name|psau
parameter_list|)
define|\
value|(SOCK_UNSPEC(psau)&& !SCOPE(psau))
end_define

begin_comment
comment|/* choose a default net interface (struct interface) for v4 or v6 */
end_comment

begin_define
define|#
directive|define
name|ANY_INTERFACE_BYFAM
parameter_list|(
name|family
parameter_list|)
define|\
value|((AF_INET == family)					\ 	     ? any_interface					\ 	     : any6_interface)
end_define

begin_comment
comment|/* choose a default interface for addresses' protocol (addr family) */
end_comment

begin_define
define|#
directive|define
name|ANY_INTERFACE_CHOOSE
parameter_list|(
name|psau
parameter_list|)
define|\
value|ANY_INTERFACE_BYFAM(AF(psau))
end_define

begin_comment
comment|/*  * We tell reference clocks from real peers by giving the reference  * clocks an address of the form 127.127.t.u, where t is the type and  * u is the unit number.  We define some of this here since we will need  * some sanity checks to make sure this address isn't interpretted as  * that of a normal peer.  */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK_ADDR
value|0x7f7f0000
end_define

begin_comment
comment|/* 127.127.0.0 */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK_MASK
value|0xffff0000
end_define

begin_comment
comment|/* 255.255.0.0 */
end_comment

begin_define
define|#
directive|define
name|ISREFCLOCKADR
parameter_list|(
name|srcadr
parameter_list|)
define|\
value|(IS_IPV4(srcadr)&&					\ 	 (SRCADR(srcadr)& REFCLOCK_MASK) == REFCLOCK_ADDR)
end_define

begin_comment
comment|/*  * Macro for checking for invalid addresses.  This is really, really  * gross, but is needed so no one configures a host on net 127 now that  * we're encouraging it the the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|LOOPBACKADR
value|0x7f000001
end_define

begin_define
define|#
directive|define
name|LOOPNETMASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|ISBADADR
parameter_list|(
name|srcadr
parameter_list|)
define|\
value|(IS_IPV4(srcadr)					\&& ((SRCADR(srcadr)& LOOPNETMASK)			\ 	     == (LOOPBACKADR& LOOPNETMASK))			\&& SRCADR(srcadr) != LOOPBACKADR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_NET_H */
end_comment

end_unit

