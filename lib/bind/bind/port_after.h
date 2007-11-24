begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|port_after_h
end_ifndef

begin_define
define|#
directive|define
name|port_after_h
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/time.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SELECT_H */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_PSELECT
end_undef

begin_define
define|#
directive|define
name|HAVE_SA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MINIMUM_IFREQ
value|1
end_define

begin_undef
undef|#
directive|undef
name|NEED_DAEMON
end_undef

begin_undef
undef|#
directive|undef
name|NEED_STRSEP
end_undef

begin_undef
undef|#
directive|undef
name|NEED_STRERROR
end_undef

begin_define
define|#
directive|define
name|HAS_INET6_STRUCTS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIN6_SCOPE_ID
value|1
end_define

begin_undef
undef|#
directive|undef
name|NEED_IN6ADDR_ANY
end_undef

begin_undef
undef|#
directive|undef
name|HAS_IN_ADDR6
end_undef

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_STORAGE
value|1
end_define

begin_undef
undef|#
directive|undef
name|NEED_GETTIMEOFDAY
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_STRNDUP
end_undef

begin_undef
undef|#
directive|undef
name|USE_FIONBIO_IOCTL
end_undef

begin_undef
undef|#
directive|undef
name|USE_SYSERROR_LIST
end_undef

begin_undef
undef|#
directive|undef
name|INNETGR_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|SETNETGRENT_ARGS
end_undef

begin_define
define|#
directive|define
name|USE_IFNAMELINKID
value|1
end_define

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

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
value|24
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_IN_ADDR6
end_ifdef

begin_comment
comment|/* Map to pre-RFC structure. */
end_comment

begin_define
define|#
directive|define
name|in6_addr
value|in_addr6
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

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
define|\
value|{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
define|\
value|{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_INET6_STRUCTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_IN6ADDR_INIT_MACROS
end_ifdef

begin_undef
undef|#
directive|undef
name|IN6ADDR_ANY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|IN6ADDR_LOOPBACK_INIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_ANY_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
value|{{{ 0, 0, 0, 0 }}}
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

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{{{ 0, 0, 0, 1 }}}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
value|{{{0, 0, 0, 0x01000000}}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_ANY_INIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|s6_addr
end_ifdef

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
define|\
value|{{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_ANY_INIT
define|\
value|{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_LOOPBACK_INIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|s6_addr
end_ifdef

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
define|\
value|{{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN6ADDR_LOOPBACK_INIT
define|\
value|{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \ 	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SOCKADDR_STORAGE
end_ifndef

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

begin_comment
comment|/*  * IN6_ARE_ADDR_EQUAL, IN6_IS_ADDR_UNSPECIFIED, IN6_IS_ADDR_V4COMPAT and  * IN6_IS_ADDR_V4MAPPED are broken in glibc 2.1.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GLIBC__
end_ifdef

begin_if
if|#
directive|if
name|__GLIBC__
operator|<
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|<
literal|2
operator|)
end_if

begin_undef
undef|#
directive|undef
name|IN6_ARE_ADDR_EQUAL
end_undef

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_UNSPECIFIED
end_undef

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_V4COMPAT
end_undef

begin_undef
undef|#
directive|undef
name|IN6_IS_ADDR_V4MAPPED
end_undef

begin_endif
endif|#
directive|endif
end_endif

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
name|IN6_IS_ADDR_LOOPBACK
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|in6_addr
name|isc_in6addr_loopback
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|IN6_ARE_ADDR_EQUAL(a,&isc_in6addr_loopback)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_V4MAPPED
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)->s6_addr[0] == 0x00&& (a)->s6_addr[1] == 0x00&& \ 	(a)->s6_addr[2] == 0x00&& (a)->s6_addr[3] == 0x00&& \ 	(a)->s6_addr[4] == 0x00&& (a)->s6_addr[5] == 0x00&& \ 	(a)->s6_addr[6] == 0x00&& (a)->s6_addr[9] == 0x00&& \ 	(a)->s6_addr[8] == 0x00&& (a)->s6_addr[9] == 0x00&& \ 	(a)->s6_addr[10] == 0xff&& (a)->s6_addr[11] == 0xff)
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
name|IN6_IS_ADDR_LINKLOCAL
end_ifndef

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
name|INADDR_NONE
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
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

begin_comment
comment|/* sizeof("aaaa:bbbb:cccc:dddd:eeee:ffff:123.123.123.123") */
end_comment

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
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<= (y)) ? (x) : (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)>= (y)) ? (x) : (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DAEMON
end_ifdef

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
name|nochdir
parameter_list|,
name|int
name|noclose
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_STRSEP
end_ifdef

begin_function_decl
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN
end_ifndef

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((uintptr_t)(p) + (sizeof(long) - 1))& ~(sizeof(long) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETGROUPENT
end_ifdef

begin_function_decl
name|int
name|setgroupent
parameter_list|(
name|int
name|stayopen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETGROUPLIST
end_ifdef

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
name|GETGROUPLIST_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_GETGRNAM_R
end_ifdef

begin_function_decl
name|int
name|__posix_getgrnam_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|group
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|group
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETGRNAM_R
end_ifdef

begin_function_decl
name|int
name|getgrnam_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|group
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|group
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_GETGRGID_R
end_ifdef

begin_function_decl
name|int
name|__posix_getgrgid_r
parameter_list|(
name|gid_t
parameter_list|,
name|struct
name|group
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|group
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETGRGID_R
end_ifdef

begin_function_decl
name|int
name|getgrgid_r
parameter_list|(
name|gid_t
parameter_list|,
name|struct
name|group
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|group
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETGRENT_R
end_ifdef

begin_function_decl
name|GROUP_R_RETURN
name|getgrent_r
parameter_list|(
name|struct
name|group
modifier|*
name|gptr
parameter_list|,
name|GROUP_R_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETGRENT_R
end_ifdef

begin_function_decl
name|GROUP_R_SET_RETURN
name|setgrent_r
parameter_list|(
name|GROUP_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_ENDGRENT_R
end_ifdef

begin_function_decl
name|GROUP_R_END_RETURN
name|endgrent_r
parameter_list|(
name|GROUP_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NEED_INNETGR_R
argument_list|)
operator|&&
name|defined
argument_list|(
name|NGR_R_RETURN
argument_list|)
end_if

begin_function_decl
name|NGR_R_RETURN
name|innetgr_r
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETNETGRENT_R
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NGR_R_ENT_ARGS
end_ifdef

begin_function_decl
name|NGR_R_SET_RETURN
name|setnetgrent_r
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
name|NGR_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|NGR_R_SET_RETURN
name|setnetgrent_r
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_ENDNETGRENT_R
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NGR_R_ENT_ARGS
end_ifdef

begin_function_decl
name|NGR_R_END_RETURN
name|endnetgrent_r
parameter_list|(
name|NGR_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|NGR_R_END_RETURN
name|endnetgrent_r
parameter_list|(
name|void
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

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_GETPWNAM_R
end_ifdef

begin_function_decl
name|int
name|__posix_getpwnam_r
parameter_list|(
specifier|const
name|char
modifier|*
name|login
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwptr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETPWNAM_R
end_ifdef

begin_function_decl
name|int
name|getpwnam_r
parameter_list|(
specifier|const
name|char
modifier|*
name|login
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwptr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_GETPWUID_R
end_ifdef

begin_function_decl
name|int
name|__posix_getpwuid_r
parameter_list|(
name|uid_t
name|uid
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwptr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETPWUID_R
end_ifdef

begin_function_decl
name|int
name|getpwuid_r
parameter_list|(
name|uid_t
name|uid
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwptr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|struct
name|passwd
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETPWENT_R
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PASS_R_ENT_ARGS
end_ifdef

begin_function_decl
name|PASS_R_SET_RETURN
name|setpwent_r
parameter_list|(
name|PASS_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|PASS_R_SET_RETURN
name|setpwent_r
parameter_list|(
name|void
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETPASSENT_R
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PASS_R_ENT_ARGS
end_ifdef

begin_function_decl
name|PASS_R_SET_RETURN
name|setpassent_r
parameter_list|(
name|int
name|stayopen
parameter_list|,
name|PASS_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|PASS_R_SET_RETURN
name|setpassent_r
parameter_list|(
name|int
name|stayopen
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETPWENT_R
end_ifdef

begin_function_decl
name|PASS_R_RETURN
name|getpwent_r
parameter_list|(
name|struct
name|passwd
modifier|*
name|pwptr
parameter_list|,
name|PASS_R_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_ENDPWENT_R
end_ifdef

begin_function_decl
name|void
name|endpwent_r
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETPASSENT
end_ifdef

begin_function_decl
name|int
name|setpassent
parameter_list|(
name|int
name|stayopen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gettimeofday
value|isc__gettimeofday
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETTIMEOFDAY
end_ifdef

begin_function_decl
name|int
name|isc__gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|struct
name|_TIMEZONE
modifier|*
name|tzp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|isc__gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tp
parameter_list|,
name|struct
name|timezone
modifier|*
name|tzp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|getnetgrent
parameter_list|(
name|char
modifier|*
modifier|*
name|machinep
parameter_list|,
name|char
modifier|*
modifier|*
name|userp
parameter_list|,
name|char
modifier|*
modifier|*
name|domainp
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NGR_R_ARGS
end_ifdef

begin_function_decl
name|int
name|getnetgrent_r
parameter_list|(
name|char
modifier|*
modifier|*
name|machinep
parameter_list|,
name|char
modifier|*
modifier|*
name|userp
parameter_list|,
name|char
modifier|*
modifier|*
name|domainp
parameter_list|,
name|NGR_R_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETNETGRENT_ARGS
end_ifdef

begin_function_decl
name|void
name|setnetgrent
parameter_list|(
name|SETNETGRENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|setnetgrent
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|endnetgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INNETGR_ARGS
end_ifdef

begin_function_decl
name|int
name|innetgr
parameter_list|(
name|INNETGR_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
specifier|const
name|char
modifier|*
name|machine
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NGR_R_ENT_ARGS
end_ifdef

begin_function_decl
name|NGR_R_SET_RETURN
name|setnetgrent_r
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
name|NGR_R_ENT_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|NGR_R_SET_RETURN
name|setnetgrent_r
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
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

