begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PORT_AFTER_H
end_ifndef

begin_define
define|#
directive|define
name|PORT_AFTER_H
end_define

begin_define
define|#
directive|define
name|USE_POSIX
end_define

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|USE_WAITPID
end_define

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
end_define

begin_define
define|#
directive|define
name|NEED_PSELECT
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_define
define|#
directive|define
name|SETPWENT_VOID
end_define

begin_define
define|#
directive|define
name|RLIMIT_TYPE
value|rlim_t
end_define

begin_define
define|#
directive|define
name|RLIMIT_LONGLONG
end_define

begin_define
define|#
directive|define
name|RLIMIT_FILE_INFINITY
end_define

begin_define
define|#
directive|define
name|HAVE_MINIMUM_IFREQ
end_define

begin_define
define|#
directive|define
name|HAVE_CHROOT
end_define

begin_define
define|#
directive|define
name|CAN_CHANGE_ID
end_define

begin_define
define|#
directive|define
name|MISSING_IN6ADDR_ANY
end_define

begin_define
define|#
directive|define
name|_TIMEZONE
value|timezone
end_define

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|PORT_WOULDBLK
value|EWOULDBLOCK
end_define

begin_define
define|#
directive|define
name|WAIT_T
value|int
end_define

begin_define
define|#
directive|define
name|KSYMS
value|"/kernel"
end_define

begin_define
define|#
directive|define
name|KMEM
value|"/dev/kmem"
end_define

begin_define
define|#
directive|define
name|UDPSUM
value|"udpcksum"
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|)
operator|||
operator|(
name|BSD
operator|<
literal|199306
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__KAME__
end_ifdef

begin_define
define|#
directive|define
name|HAS_INET6_STRUCTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * We need to know the IPv6 address family number even on IPv4-only systems.  * Note that this is NOT a protocol constant, and that if the system has its  * own AF_INET6, different from ours below, all of BIND's libraries and  * executables will need to be recompiled after the system<sys/socket.h>  * has had this type added.  The type number below is correct on most BSD-  * derived systems for which AF_INET6 is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_define
define|#
directive|define
name|AF_INET6
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIN6_LEN
end_ifdef

begin_define
define|#
directive|define
name|HAS_INET6_STRUCTS
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PF_INET6
end_ifndef

begin_define
define|#
directive|define
name|PF_INET6
value|AF_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_INET6_STRUCTS
end_ifndef

begin_comment
comment|/* Replace with structure from later rev of O/S if known. */
end_comment

begin_struct
struct|struct
name|in6_addr
block|{
name|u_int8_t
name|s6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Replace with structure from later rev of O/S if known. */
end_comment

begin_struct
struct|struct
name|sockaddr_in6
block|{
ifdef|#
directive|ifdef
name|HAVE_SA_LEN
name|u_int8_t
name|sin6_len
decl_stmt|;
comment|/* length of this struct */
name|u_int8_t
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 */
else|#
directive|else
name|u_int16_t
name|sin6_family
decl_stmt|;
comment|/* AF_INET6 */
endif|#
directive|endif
name|u_int16_t
name|sin6_port
decl_stmt|;
comment|/* transport layer port # */
name|u_int32_t
name|sin6_flowinfo
decl_stmt|;
comment|/* IPv6 flow information */
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
comment|/* IPv6 address */
name|u_int32_t
name|sin6_scope_id
decl_stmt|;
comment|/* set of interfaces for a scope */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_ANY_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_LOOPBACK_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}}
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
comment|/* HAS_INET6_STRUCTS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NEED_SOCKADDR_STORAGE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAS_INET6_STRUCTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SS_MAXSIZE
value|128
end_define

begin_define
define|#
directive|define
name|__SS_ALLIGSIZE
value|(sizeof (long))
end_define

begin_struct
struct|struct
name|sockaddr_storage
block|{
ifdef|#
directive|ifdef
name|HAVE_SA_LEN
name|u_int8_t
name|ss_len
decl_stmt|;
comment|/* address length */
name|u_int8_t
name|ss_family
decl_stmt|;
comment|/* address family */
name|char
name|__ss_pad1
index|[
name|__SS_ALLIGSIZE
operator|-
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|u_int8_t
argument_list|)
index|]
decl_stmt|;
name|long
name|__ss_align
decl_stmt|;
name|char
name|__ss_pad2
index|[
name|__SS_MAXSIZE
operator|-
literal|2
operator|*
name|__SS_ALLIGSIZE
index|]
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ss_family
decl_stmt|;
comment|/* address family */
name|char
name|__ss_pad1
index|[
name|__SS_ALLIGSIZE
operator|-
sizeof|sizeof
argument_list|(
name|u_int16_t
argument_list|)
index|]
decl_stmt|;
name|long
name|__ss_align
decl_stmt|;
name|char
name|__ss_pad2
index|[
name|__SS_MAXSIZE
operator|-
literal|2
operator|*
name|__SS_ALLIGSIZE
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_INET6_STRUCTS
argument_list|)
operator|||
name|defined
argument_list|(
name|NEED_IN6ADDR_ANY
argument_list|)
end_if

begin_define
define|#
directive|define
name|in6addr_any
value|isc_in6addr_any
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|in6addr_any
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_ARE_ADDR_EQUAL
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_UNSPECIFIED
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_UNSPECIFIED
parameter_list|(
name|a
parameter_list|)
define|\
value|IN6_ARE_ADDR_EQUAL(a,&in6addr_any)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_SITELOCAL
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_MULTICAST
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MULTICAST
parameter_list|(
name|a
parameter_list|)
value|((a)->s6_addr[0] == 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__IPV6_ADDR_MC_SCOPE
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|__IPV6_ADDR_SCOPE_SITELOCAL
end_ifndef

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_SITELOCAL
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__IPV6_ADDR_SCOPE_ORGLOCAL
end_ifndef

begin_define
define|#
directive|define
name|__IPV6_ADDR_SCOPE_ORGLOCAL
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_MC_SITELOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_SITELOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&    \ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_SITELOCAL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_MC_ORGLOCAL
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_MC_ORGLOCAL
parameter_list|(
name|a
parameter_list|)
define|\
value|(IN6_IS_ADDR_MULTICAST(a)&&    \ 	 (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_ORGLOCAL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_FACILITY
end_ifndef

begin_define
define|#
directive|define
name|ISC_FACILITY
value|LOG_DAEMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|(x) = (x)
end_define

begin_define
define|#
directive|define
name|DE_CONST
parameter_list|(
name|konst
parameter_list|,
name|var
parameter_list|)
define|\
value|do { \ 		union { const void *k; void *v; } _u; \ 		_u.k = konst; \ 		var = _u.v; \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! PORT_AFTER_H */
end_comment

end_unit

