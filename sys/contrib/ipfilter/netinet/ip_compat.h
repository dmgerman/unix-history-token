begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_compat.h	1.8 1/14/96  * $Id: ip_compat.h,v 2.26.2.9 2001/01/14 14:58:01 darrenr Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_COMPAT_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
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
name|__STDC__
end_ifndef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SOLARIS
end_ifndef

begin_define
define|#
directive|define
name|SOLARIS
value|(defined(sun)&& (defined(__svr4__) || defined(__SVR4)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SOLARIS2
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOLARIS2
value|3
end_define

begin_comment
comment|/* Pick an old version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|8
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|USE_INET6
end_ifndef

begin_define
define|#
directive|define
name|USE_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|USE_INET6
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|USE_INET6
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|__KERNEL__
end_undef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a,0,b)
end_define

begin_define
define|#
directive|define
name|bcmp
value|memcmp
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memmove(b,a,c)
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
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
value|(int)((&((t *)0L)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|bsdi
argument_list|)
end_if

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|ether_addr_octet
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIFNAMSIZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IF_NAMESIZE
end_ifdef

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|IF_NAMESIZE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|IFNAMSIZ
end_ifdef

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|IFNAMSIZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIFNAMSIZ
value|16
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IPFILTER_LKM
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipfilter##ep
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipfilter
comment|/**/
value|ep
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipl##ep
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPL_EXTERN
parameter_list|(
name|ep
parameter_list|)
value|ipl
comment|/**/
value|ep
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
name|__sgi
end_ifdef

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is a workaround for<sys/uio.h> troubles on FreeBSD and OpenBSD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|ADD_KERNEL
end_define

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ADD_KERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|MTYPE
parameter_list|(
name|m
parameter_list|)
value|((m)->b_datap->db_type)
end_define

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|4
end_if

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_comment
comment|/*  * because Solaris 2 defines these in two places :-/  */
end_comment

begin_undef
undef|#
directive|undef
name|IPOPT_EOL
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_NOP
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_LSRR
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_RR
end_undef

begin_undef
undef|#
directive|undef
name|IPOPT_SSRR
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_undef
undef|#
directive|undef
name|RES_INIT
end_undef

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|8
end_if

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inet/common.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip_ire.h>
end_include

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|8
end_if

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inet/common.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip.h>
end_include

begin_include
include|#
directive|include
file|<inet/ip_ire.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|8
end_if

begin_include
include|#
directive|include
file|<inet/ip_if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_define
define|#
directive|define
name|ipif_local_addr
value|ipif_lcl_addr
end_define

begin_comment
comment|/* Only defined in private include file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|V4_PART_OF_V6
end_ifndef

begin_define
define|#
directive|define
name|V4_PART_OF_V6
parameter_list|(
name|v6
parameter_list|)
value|v6.s6_addr32[3]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|qif
block|{
name|struct
name|qif
modifier|*
name|qf_next
decl_stmt|;
name|ill_t
modifier|*
name|qf_ill
decl_stmt|;
name|kmutex_t
name|qf_lock
decl_stmt|;
name|void
modifier|*
name|qf_iptr
decl_stmt|;
name|void
modifier|*
name|qf_optr
decl_stmt|;
name|queue_t
modifier|*
name|qf_in
decl_stmt|;
name|queue_t
modifier|*
name|qf_out
decl_stmt|;
name|struct
name|qinit
modifier|*
name|qf_wqinfo
decl_stmt|;
name|struct
name|qinit
modifier|*
name|qf_rqinfo
decl_stmt|;
name|struct
name|qinit
name|qf_wqinit
decl_stmt|;
name|struct
name|qinit
name|qf_rqinit
decl_stmt|;
name|mblk_t
modifier|*
name|qf_m
decl_stmt|;
comment|/* These three fields are for passing data up from */
name|queue_t
modifier|*
name|qf_q
decl_stmt|;
comment|/* fr_qin and fr_qout to the packet processing. */
name|size_t
name|qf_off
decl_stmt|;
name|size_t
name|qf_len
decl_stmt|;
comment|/* this field is used for in ipfr_fastroute */
name|char
name|qf_name
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
comment|/* 	 * in case the ILL has disappeared... 	 */
name|size_t
name|qf_hl
decl_stmt|;
comment|/* header length */
name|int
name|qf_sap
decl_stmt|;
name|size_t
name|qf_incnt
decl_stmt|;
name|size_t
name|qf_outcnt
decl_stmt|;
block|}
name|qif_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|minor_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_define
define|#
directive|define
name|IPMINLEN
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|((i)->ip_len>= ((i)->ip_hl * 4 + sizeof(struct h)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD__
operator|>=
literal|5
operator|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_OFFMASK
end_ifndef

begin_define
define|#
directive|define
name|IP_OFFMASK
value|0x1fff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BSD
operator|>
literal|199306
end_if

begin_define
define|#
directive|define
name|USE_QUAD_T
end_define

begin_define
define|#
directive|define
name|U_QUAD_T
value|u_quad_t
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|quad_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD> 199306 */
end_comment

begin_define
define|#
directive|define
name|U_QUAD_T
value|u_long
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD> 199306 */
end_comment

begin_comment
comment|/*  * These operating systems already take care of the problem for us.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_typedef
typedef|typedef
name|u_int32_t
name|u_32_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IPFILTER_LKM
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|>=
literal|104110000
operator|)
end_if

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|400000
operator|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|USE_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Really, any arch where sizeof(long) != sizeof(int).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|_LP64
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|6
end_if

begin_typedef
typedef|typedef
name|uint32_t
name|u_32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_32_t
typedef|;
end_typedef

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

begin_comment
comment|/* __NetBSD__ || __OpenBSD__ || __FreeBSD__ || __sgi */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|ip6_hdr
name|ip6_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_union
union|union
name|i6addr
block|{
name|u_32_t
name|i6
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|in_addr
name|in4
decl_stmt|;
name|struct
name|in6_addr
name|in6
decl_stmt|;
block|}
union|;
end_union

begin_else
else|#
directive|else
end_else

begin_union
union|union
name|i6addr
block|{
name|u_32_t
name|i6
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|in_addr
name|in4
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IP6CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|bcmp((char *)&(a), (char *)&(b), sizeof(a))
end_define

begin_define
define|#
directive|define
name|IP6EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(bcmp((char *)&(a), (char *)&(b), sizeof(a)) == 0)
end_define

begin_define
define|#
directive|define
name|IP6NEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(bcmp((char *)&(a), (char *)&(b), sizeof(a)) != 0)
end_define

begin_define
define|#
directive|define
name|IP6_ISZERO
parameter_list|(
name|a
parameter_list|)
value|((((union i6addr *)(a))->i6[0] | \ 			  ((union i6addr *)(a))->i6[1] | \ 			  ((union i6addr *)(a))->i6[2] | \ 			  ((union i6addr *)(a))->i6[3]) == 0)
end_define

begin_define
define|#
directive|define
name|IP6_NOTZERO
parameter_list|(
name|a
parameter_list|)
value|((((union i6addr *)(a))->i6[0] | \ 			  ((union i6addr *)(a))->i6[1] | \ 			  ((union i6addr *)(a))->i6[2] | \ 			  ((union i6addr *)(a))->i6[3]) != 0)
end_define

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
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Security Options for Intenet Protocol (IPSO) as defined in RFC 1108.  *  * Basic Option  *  * 00000001   -   (Reserved 4)  * 00111101   -   Top Secret  * 01011010   -   Secret  * 10010110   -   Confidential  * 01100110   -   (Reserved 3)  * 11001100   -   (Reserved 2)  * 10101011   -   Unclassified  * 11110001   -   (Reserved 1)  */
end_comment

begin_define
define|#
directive|define
name|IPSO_CLASS_RES4
value|0x01
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_TOPS
value|0x3d
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_SECR
value|0x5a
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_CONF
value|0x96
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES3
value|0x66
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES2
value|0xcc
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_UNCL
value|0xab
end_define

begin_define
define|#
directive|define
name|IPSO_CLASS_RES1
value|0xf1
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_GENSER
value|0x80
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_ESI
value|0x40
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_SCI
value|0x20
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_NSA
value|0x10
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_DOE
value|0x08
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_UN
value|0x06
end_define

begin_define
define|#
directive|define
name|IPSO_AUTH_FTE
value|0x01
end_define

begin_comment
comment|/*  * IP option #defines  */
end_comment

begin_comment
comment|/*#define	IPOPT_RR	7 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ZSU
value|10
end_define

begin_comment
comment|/* ZSU */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MTUP
value|11
end_define

begin_comment
comment|/* MTUP */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MTUR
value|12
end_define

begin_comment
comment|/* MTUR */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ENCODE
value|15
end_define

begin_comment
comment|/* ENCODE */
end_comment

begin_comment
comment|/*#define	IPOPT_TS	68 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TR
value|82
end_define

begin_comment
comment|/* TR */
end_comment

begin_comment
comment|/*#define	IPOPT_SECURITY	130 */
end_comment

begin_comment
comment|/*#define	IPOPT_LSRR	131 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_E_SEC
value|133
end_define

begin_comment
comment|/* E-SEC */
end_comment

begin_define
define|#
directive|define
name|IPOPT_CIPSO
value|134
end_define

begin_comment
comment|/* CIPSO */
end_comment

begin_comment
comment|/*#define	IPOPT_SATID	136 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SID
value|IPOPT_SATID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*#define	IPOPT_SSRR	137 */
end_comment

begin_define
define|#
directive|define
name|IPOPT_ADDEXT
value|147
end_define

begin_comment
comment|/* ADDEXT */
end_comment

begin_define
define|#
directive|define
name|IPOPT_VISA
value|142
end_define

begin_comment
comment|/* VISA */
end_comment

begin_define
define|#
directive|define
name|IPOPT_IMITD
value|144
end_define

begin_comment
comment|/* IMITD */
end_comment

begin_define
define|#
directive|define
name|IPOPT_EIP
value|145
end_define

begin_comment
comment|/* EIP */
end_comment

begin_define
define|#
directive|define
name|IPOPT_FINN
value|205
end_define

begin_comment
comment|/* FINN */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD_cc_version
end_ifndef

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__FreeBSD_cc_version
operator|<
literal|430000
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ACTUALLY_LKM_NOT_KERNEL
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD_cc_version
end_ifndef

begin_include
include|#
directive|include
file|<sys/osreldate.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__FreeBSD_cc_version
operator|<
literal|430000
end_if

begin_include
include|#
directive|include
file|<sys/osreldate.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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

begin_if
if|#
directive|if
name|__FreeBSD__
operator|<
literal|3
end_if

begin_include
include|#
directive|include
file|<machine/spl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__FreeBSD__
operator|==
literal|3
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IPFILTER_LKM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACTUALLY_LKM_NOT_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACTUALLY_LKM_NOT_KERNEL
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__&& KERNEL */
end_comment

begin_comment
comment|/*  * Build some macros and #defines to enable the same code to compile anywhere  * Well, that's the idea, anyway :-)  */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_typedef
typedef|typedef
name|mblk_t
name|mb_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|7
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|ALIGN32
parameter_list|(
name|ptr
parameter_list|)
value|(ptr ? 0L : 0L)
end_define

begin_define
define|#
directive|define
name|ALIGN16
parameter_list|(
name|ptr
parameter_list|)
value|(ptr ? 0L : 0L)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALIGN32
parameter_list|(
name|ptr
parameter_list|)
value|(ptr)
end_define

begin_define
define|#
directive|define
name|ALIGN16
parameter_list|(
name|ptr
parameter_list|)
value|(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|mb_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_if
if|#
directive|if
operator|!
name|SOLARIS
operator|||
operator|(
name|SOLARIS2
operator|<
literal|6
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_INCL
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC64
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC32
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC16
value|ATOMIC_INC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DECL
value|ATOMIC_DEC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC64
value|ATOMIC_DEC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC32
value|ATOMIC_DEC
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC16
value|ATOMIC_DEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_define
define|#
directive|define
name|hz
value|HZ
end_define

begin_include
include|#
directive|include
file|<sys/ksynch.h>
end_include

begin_define
define|#
directive|define
name|IPF_LOCK_PL
value|plhi
end_define

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_undef
undef|#
directive|undef
name|kmutex_t
end_undef

begin_typedef
typedef|typedef
struct|struct
block|{
name|lock_t
modifier|*
name|l
decl_stmt|;
name|int
name|pl
decl_stmt|;
block|}
name|kmutex_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|MUTEX_INIT
end_undef

begin_undef
undef|#
directive|undef
name|MUTEX_DESTROY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_if
if|#
directive|if
name|SOLARIS2
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|<sys/atomic.h>
end_include

begin_if
if|#
directive|if
name|SOLARIS2
operator|==
literal|6
end_if

begin_define
define|#
directive|define
name|ATOMIC_INCL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long((uint32_t*)&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DECL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long((uint32_t*)&(x), -1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_INCL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long(&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DECL
parameter_list|(
name|x
parameter_list|)
value|atomic_add_long(&(x), -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATOMIC_INC64
parameter_list|(
name|x
parameter_list|)
value|atomic_add_64((uint64_t*)&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC32
parameter_list|(
name|x
parameter_list|)
value|atomic_add_32((uint32_t*)&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC16
parameter_list|(
name|x
parameter_list|)
value|atomic_add_16((uint16_t*)&(x), 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC64
parameter_list|(
name|x
parameter_list|)
value|atomic_add_64((uint64_t*)&(x), -1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC32
parameter_list|(
name|x
parameter_list|)
value|atomic_add_32((uint32_t*)&(x), -1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC16
parameter_list|(
name|x
parameter_list|)
value|atomic_add_16((uint16_t*)&(x), -1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRE_CACHE
value|IRE_ROUTE
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|{ mutex_enter(&ipf_rw); (x)++; \ 					  mutex_exit(&ipf_rw); }
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|{ mutex_enter(&ipf_rw); (x)--; \ 					  mutex_exit(&ipf_rw); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|mutex_enter(x)
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|KRWLOCK_T
value|krwlock_t
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|rw_enter(x, RW_READER)
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|rw_enter(x, RW_WRITER)
end_define

begin_define
define|#
directive|define
name|RW_UPGRADE
parameter_list|(
name|x
parameter_list|)
value|{ if (rw_tryupgrade(x) == 0) { \ 					      rw_exit(x); \ 					      rw_enter(x, RW_WRITER); } \ 					}
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|rw_downgrade(x)
end_define

begin_define
define|#
directive|define
name|RWLOCK_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|rw_init((x), (y), RW_DRIVER, (z))
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|rw_exit(x)
end_define

begin_define
define|#
directive|define
name|RW_DESTROY
parameter_list|(
name|x
parameter_list|)
value|rw_destroy(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRWLOCK_T
value|kmutex_t
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|mutex_enter(x)
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|mutex_enter(x)
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|mutex_init((x), (y), MUTEX_DRIVER, (z))
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|mutex_exit(x)
end_define

begin_define
define|#
directive|define
name|RW_DESTROY
parameter_list|(
name|x
parameter_list|)
value|mutex_destroy(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|mutex_init((x), (y), MUTEX_DRIVER, (z))
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|mutex_destroy(x)
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|mutex_exit(x)
end_define

begin_define
define|#
directive|define
name|MTOD
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|(t)((m)->b_rptr)
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyin((caddr_t)(a), (caddr_t)(b), (c))
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|copyout((caddr_t)(a), (caddr_t)(b), (c))
end_define

begin_define
define|#
directive|define
name|IRCOPYPTR
value|ircopyptr
end_define

begin_define
define|#
directive|define
name|IWCOPYPTR
value|iwcopyptr
end_define

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|m
parameter_list|)
value|freemsg(m)
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_undef
undef|#
directive|undef
name|SPL_X
end_undef

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)kmem_alloc(sizeof(*(a)), KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)kmem_alloc((c), KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|getminor(x)
end_define

begin_decl_stmt
specifier|extern
name|ill_t
modifier|*
name|get_unit
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|get_unit(n, v)
end_define

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|((ill_t *)x)->ill_name
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|{ MUTEX_ENTER(&ipf_rw); \ 					  (x)++; MUTEX_EXIT(&ipf_rw); }
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|{ MUTEX_ENTER(&ipf_rw); \ 					  (x)--; MUTEX_EXIT(&ipf_rw); }
end_define

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|(x)->pl = LOCK((x)->l, IPF_LOCK_PL);
end_define

begin_define
define|#
directive|define
name|KRWLOCK_T
value|kmutex_t
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|MUTEX_ENTER(x)
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|MUTEX_ENTER(x)
end_define

begin_define
define|#
directive|define
name|RW_UPGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|MUTEX_EXIT(x)
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|UNLOCK((x)->l, (x)->pl);
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(x)->l = LOCK_ALLOC((uchar_t)-1, IPF_LOCK_PL, (lkinfo_t *)-1, KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|LOCK_DEALLOC((x)->l)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __sgi */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|(x)++
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|(x)--
end_define

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RW_UPGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sgi */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|m
parameter_list|)
value|m_freem(m)
end_define

begin_define
define|#
directive|define
name|MTOD
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|mtod(m,t)
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((a), (b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((a), (b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|IRCOPYPTR
value|ircopyptr
end_define

begin_define
define|#
directive|define
name|IWCOPYPTR
value|iwcopyptr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_if
if|#
directive|if
operator|!
name|SOLARIS
end_if

begin_include
include|#
directive|include
file|<sys/kmem_alloc.h>
end_include

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|ifunit(n, IFNAMSIZ)
end_define

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|((struct ifnet *)x)->if_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|ifunit(n)
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199606
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|>=
literal|199603
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|((struct ifnet *)x)->if_xname
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_GETIFNAME
value|1
end_define

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|get_ifname((struct ifnet *)x)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_ifname
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

begin_comment
comment|/* sun */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uiomove((caddr_t)a,b,c,d)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|id
parameter_list|,
name|n
parameter_list|)
value|sleep((id), PZERO+1)
end_define

begin_define
define|#
directive|define
name|WAKEUP
parameter_list|(
name|id
parameter_list|)
value|wakeup(id)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|kmem_free((char *)(x), sizeof(*(x)))
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|kmem_free((char *)(x), (s))
end_define

begin_if
if|#
directive|if
operator|!
name|SOLARIS
end_if

begin_decl_stmt
specifier|extern
name|void
name|m_copydata
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|m_copyback
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_include
include|#
directive|include
file|<sys/ddi.h>
end_include

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)kmem_alloc(sizeof(*(a)), KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)kmem_alloc((c), KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|getminor(x)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)new_kmem_alloc(sizeof(*(a)), \ 							KMEM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)new_kmem_alloc((c), KMEM_NOSLEEP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun&& !linux */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GET_MINOR
end_ifndef

begin_define
define|#
directive|define
name|GET_MINOR
parameter_list|(
name|x
parameter_list|)
value|minor(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199306
operator|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|<
literal|105180000
operator|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
end_if

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

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
name|__FreeBSD__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__NetBSD_Version__
argument_list|)
operator|&&
operator|(
name|__NetBSD_Version__
operator|>=
literal|105180000
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|>=
literal|200111
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|<uvm/uvm_extern.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_decl_stmt
specifier|extern
name|vm_map_t
name|kmem_map
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__FreeBSD__ || (__FreeBSD__&& __FreeBSD__>=3) */
end_comment

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FreeBSD__ || (__FreeBSD__&& __FreeBSD__>=3) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_PFIL
end_ifdef

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MALLOC((a), b, sizeof(*(a)), M_PFIL, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MALLOC((a), b, (c), M_PFIL, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|FREE((x), M_PFIL)
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|FREE((x), M_PFIL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|MALLOC((a), b, sizeof(*(a)), M_TEMP, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|MALLOC((a), b, (c), M_TEMP, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|FREE((x), M_TEMP)
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|FREE((x), M_TEMP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_PFIL */
end_comment

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uiomove(a,b,d)
end_define

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|id
parameter_list|,
name|n
parameter_list|)
value|tsleep((id), PPAUSE|PCATCH, n, 0)
end_define

begin_define
define|#
directive|define
name|WAKEUP
parameter_list|(
name|id
parameter_list|)
value|wakeup(id)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199407
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|OpenBSD
argument_list|)
operator|&&
operator|(
name|OpenBSD
operator|>=
literal|200006
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|x = splsoftnet()
end_define

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|(void) splx(x)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|SOLARIS
operator|&&
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|x = splimp()
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|x = splnet()
end_define

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|(void) splx(x)
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
comment|/* NetBSD&& (NetBSD<= 1991011)&& (NetBSD>= 199407) */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if (x) panic y
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* KERNEL */
end_comment

begin_define
define|#
directive|define
name|SLEEP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|WAKEUP
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|x
parameter_list|)
value|(x)++
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC
parameter_list|(
name|x
parameter_list|)
value|(x)--
end_define

begin_define
define|#
directive|define
name|MUTEX_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|READ_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|WRITE_ENTER
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RW_UPGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_DOWNGRADE
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|RWLOCK_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|MUTEX_EXIT
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_undef
undef|#
directive|undef
name|SPL_X
end_undef

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)malloc(sizeof(*a))
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)malloc(c)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|free(x)
end_define

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|get_unit(x,v)
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((a), (b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|IWCOPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(bcopy((a), (b), (c)), 0)
end_define

begin_define
define|#
directive|define
name|IRCOPYPTR
value|ircopyptr
end_define

begin_define
define|#
directive|define
name|IWCOPYPTR
value|iwcopyptr
end_define

begin_define
define|#
directive|define
name|IFNAME
parameter_list|(
name|x
parameter_list|)
value|get_ifname((struct ifnet *)x)
end_define

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ipfuiomove(a,b,c,d)
end_define

begin_decl_stmt
specifier|extern
name|void
name|m_copydata
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfuiomove
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * These #ifdef's are here mainly for linux, but who knows, they may  * not be in other places or maybe one day linux will grow up and some  * of these will turn up there too.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MINLEN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MINLEN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ECHOREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ECHOREPLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PROTOCOL
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PROTOCOL
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PORT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NEEDFRAG
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NEEDFRAG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_SRCFAIL
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_SRCFAIL
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_UNKNOWN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_UNKNOWN
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_ISOLATED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_ISOLATED
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_NET_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_NET_PROHIB
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PROHIB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PROHIB
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSNET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSNET
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_TOSHOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_TOSHOST
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_ADMIN_PROHIBIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_ADMIN_PROHIBIT
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_HOST_PRECEDENCE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_HOST_PRECEDENCE
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
end_ifndef

begin_define
define|#
directive|define
name|ICMP_UNREACH_PRECEDENCE_CUTOFF
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_SOURCEQUENCH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_SOURCEQUENCH
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_NET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_NET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_HOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_HOST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_TOSNET
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSNET
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_REDIRECT_TOSHOST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_REDIRECT_TOSHOST
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ALTHOSTADDR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ALTHOSTADDR
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED_INTRANS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_INTRANS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TIMXCEED_REASS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TIMXCEED_REASS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_ERRATPTR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_ERRATPTR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_OPTABSENT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_OPTABSENT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PARAMPROB_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PARAMPROB_LENGTH
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TSTAMP
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TSTAMP
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TSTAMPREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TSTAMPREPLY
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IREQ
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IREQ
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IREQREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IREQREPLY
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MASKREQ
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MASKREQ
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MASKREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MASKREPLY
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_TRACEROUTE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_TRACEROUTE
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_DATACONVERR
end_ifndef

begin_define
define|#
directive|define
name|ICMP_DATACONVERR
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REDIRECT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IPV6_WHEREAREYOU
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IPV6_WHEREAREYOU
value|33
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_IPV6_IAMHERE
end_ifndef

begin_define
define|#
directive|define
name|ICMP_IPV6_IAMHERE
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REGREQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REGREQUEST
value|35
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_MOBILE_REGREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP_MOBILE_REGREPLY
value|36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_SKIP
end_ifndef

begin_define
define|#
directive|define
name|ICMP_SKIP
value|39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_UNKNOWN_INDEX
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_UNKNOWN_INDEX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_AUTH_FAILED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_AUTH_FAILED
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_PHOTURIS_DECRYPT_FAILED
end_ifndef

begin_define
define|#
directive|define
name|ICMP_PHOTURIS_DECRYPT_FAILED
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPVERSION
end_ifndef

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_MINOFF
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_MINOFF
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_COPIED
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|x
parameter_list|)
value|((x)&0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IP_MF
end_ifndef

begin_define
define|#
directive|define
name|IP_MF
value|((u_short)0x2000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHERTYPE_IP
end_ifndef

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|((u_short)0x0800)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_FIN
end_ifndef

begin_define
define|#
directive|define
name|TH_FIN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_SYN
end_ifndef

begin_define
define|#
directive|define
name|TH_SYN
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_RST
end_ifndef

begin_define
define|#
directive|define
name|TH_RST
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_PUSH
end_ifndef

begin_define
define|#
directive|define
name|TH_PUSH
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ACK
end_ifndef

begin_define
define|#
directive|define
name|TH_ACK
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_URG
end_ifndef

begin_define
define|#
directive|define
name|TH_URG
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_EOL
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_NOP
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_RR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_TS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECURITY
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_LSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SATID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SSRR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_UNCLASS
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|((u_short)0x0000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_CONFID
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|((u_short)0xf135)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_EFTO
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|((u_short)0x789a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_MMMM
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|((u_short)0xbc4d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_RESTR
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|((u_short)0xaf13)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_SECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|((u_short)0xd788)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_SECUR_TOPSECRET
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|((u_short)0x6bc5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPOPT_OLEN
end_ifndef

begin_define
define|#
directive|define
name|IPOPT_OLEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_GRE
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_GRE
value|47
end_define

begin_comment
comment|/* GRE encaps RFC 1701 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ESP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ESP
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_ICMPV6
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_ICMPV6
value|58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_include
include|#
directive|include
file|<linux/in_systm.h>
end_include

begin_comment
comment|/*  * TCP States  */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSED
value|0
end_define

begin_comment
comment|/* closed */
end_comment

begin_define
define|#
directive|define
name|TCPS_LISTEN
value|1
end_define

begin_comment
comment|/* listening for connection */
end_comment

begin_define
define|#
directive|define
name|TCPS_SYN_SENT
value|2
end_define

begin_comment
comment|/* active, have sent syn */
end_comment

begin_define
define|#
directive|define
name|TCPS_SYN_RECEIVED
value|3
end_define

begin_comment
comment|/* have send and received syn */
end_comment

begin_comment
comment|/* states< TCPS_ESTABLISHED are those where connections not established */
end_comment

begin_define
define|#
directive|define
name|TCPS_ESTABLISHED
value|4
end_define

begin_comment
comment|/* established */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSE_WAIT
value|5
end_define

begin_comment
comment|/* rcvd fin, waiting for close */
end_comment

begin_comment
comment|/* states> TCPS_CLOSE_WAIT are those where user has closed */
end_comment

begin_define
define|#
directive|define
name|TCPS_FIN_WAIT_1
value|6
end_define

begin_comment
comment|/* have closed, sent fin */
end_comment

begin_define
define|#
directive|define
name|TCPS_CLOSING
value|7
end_define

begin_comment
comment|/* closed xchd FIN; await FIN ACK */
end_comment

begin_define
define|#
directive|define
name|TCPS_LAST_ACK
value|8
end_define

begin_comment
comment|/* had fin and close; await FIN ACK */
end_comment

begin_comment
comment|/* states> TCPS_CLOSE_WAIT&&< TCPS_FIN_WAIT_2 await ACK of FIN */
end_comment

begin_define
define|#
directive|define
name|TCPS_FIN_WAIT_2
value|9
end_define

begin_comment
comment|/* have closed, fin is acked */
end_comment

begin_define
define|#
directive|define
name|TCPS_TIME_WAIT
value|10
end_define

begin_comment
comment|/* in 2*msl quiet wait after close */
end_comment

begin_comment
comment|/*  * file flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WRITE
end_ifdef

begin_define
define|#
directive|define
name|FWRITE
value|WRITE
end_define

begin_define
define|#
directive|define
name|FREAD
value|READ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FWRITE
value|_IOC_WRITE
end_define

begin_define
define|#
directive|define
name|FREAD
value|_IOC_READ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mbuf related problems.  */
end_comment

begin_define
define|#
directive|define
name|mtod
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|)
value|(t)((m)->data)
end_define

begin_define
define|#
directive|define
name|m_len
value|len
end_define

begin_define
define|#
directive|define
name|m_next
value|next
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IP_DF
end_ifdef

begin_undef
undef|#
directive|undef
name|IP_DF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IP_DF
value|0x4000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|th_sport
decl_stmt|;
name|__u16
name|th_dport
decl_stmt|;
name|__u32
name|th_seq
decl_stmt|;
name|__u32
name|th_ack
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
name|__u8
name|th_res
range|:
literal|4
decl_stmt|;
name|__u8
name|th_off
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|th_off
range|:
literal|4
decl_stmt|;
name|__u8
name|th_res
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|th_flags
decl_stmt|;
name|__u16
name|th_win
decl_stmt|;
name|__u16
name|th_sum
decl_stmt|;
name|__u16
name|th_urp
decl_stmt|;
block|}
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u16
name|uh_sport
decl_stmt|;
name|__u16
name|uh_dport
decl_stmt|;
name|__u16
name|uh_ulen
decl_stmt|;
name|__u16
name|uh_sum
decl_stmt|;
block|}
name|udphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|ip_v
range|:
literal|4
decl_stmt|;
name|__u8
name|ip_hl
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|ip_tos
decl_stmt|;
name|__u16
name|ip_len
decl_stmt|;
name|__u16
name|ip_id
decl_stmt|;
name|__u16
name|ip_off
decl_stmt|;
name|__u8
name|ip_ttl
decl_stmt|;
name|__u8
name|ip_p
decl_stmt|;
name|__u16
name|ip_sum
decl_stmt|;
name|struct
name|in_addr
name|ip_src
decl_stmt|;
name|struct
name|in_addr
name|ip_dst
decl_stmt|;
block|}
name|ip_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure of an icmp header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|icmp
block|{
name|__u8
name|icmp_type
decl_stmt|;
comment|/* type of message, see below */
name|__u8
name|icmp_code
decl_stmt|;
comment|/* type sub code */
name|__u16
name|icmp_cksum
decl_stmt|;
comment|/* ones complement cksum of struct */
union|union
block|{
name|__u8
name|ih_pptr
decl_stmt|;
comment|/* ICMP_PARAMPROB */
name|struct
name|in_addr
name|ih_gwaddr
decl_stmt|;
comment|/* ICMP_REDIRECT */
struct|struct
name|ih_idseq
block|{
name|__u16
name|icd_id
decl_stmt|;
name|__u16
name|icd_seq
decl_stmt|;
block|}
name|ih_idseq
struct|;
name|int
name|ih_void
decl_stmt|;
block|}
name|icmp_hun
union|;
define|#
directive|define
name|icmp_pptr
value|icmp_hun.ih_pptr
define|#
directive|define
name|icmp_gwaddr
value|icmp_hun.ih_gwaddr
define|#
directive|define
name|icmp_id
value|icmp_hun.ih_idseq.icd_id
define|#
directive|define
name|icmp_seq
value|icmp_hun.ih_idseq.icd_seq
define|#
directive|define
name|icmp_void
value|icmp_hun.ih_void
union|union
block|{
struct|struct
name|id_ts
block|{
name|n_time
name|its_otime
decl_stmt|;
name|n_time
name|its_rtime
decl_stmt|;
name|n_time
name|its_ttime
decl_stmt|;
block|}
name|id_ts
struct|;
struct|struct
name|id_ip
block|{
name|ip_t
name|idi_ip
decl_stmt|;
comment|/* options and then 64 bits of data */
block|}
name|id_ip
struct|;
name|u_long
name|id_mask
decl_stmt|;
name|char
name|id_data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|icmp_dun
union|;
define|#
directive|define
name|icmp_otime
value|icmp_dun.id_ts.its_otime
define|#
directive|define
name|icmp_rtime
value|icmp_dun.id_ts.its_rtime
define|#
directive|define
name|icmp_ttime
value|icmp_dun.id_ts.its_ttime
define|#
directive|define
name|icmp_ip
value|icmp_dun.id_ip.idi_ip
define|#
directive|define
name|icmp_mask
value|icmp_dun.id_mask
define|#
directive|define
name|icmp_data
value|icmp_dun.id_data
block|}
name|icmphdr_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_IPOVLY
end_ifndef

begin_define
define|#
directive|define
name|LINUX_IPOVLY
end_define

begin_struct
struct|struct
name|ipovly
block|{
name|caddr_t
name|ih_next
decl_stmt|,
name|ih_prev
decl_stmt|;
comment|/* for protocol sequence q's */
name|u_char
name|ih_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|ih_pr
decl_stmt|;
comment|/* protocol */
name|short
name|ih_len
decl_stmt|;
comment|/* protocol length */
name|struct
name|in_addr
name|ih_src
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|ih_dst
decl_stmt|;
comment|/* destination internet address */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|__u8
name|ether_dhost
index|[
literal|6
index|]
decl_stmt|;
name|__u8
name|ether_shost
index|[
literal|6
index|]
decl_stmt|;
name|__u16
name|ether_type
decl_stmt|;
block|}
name|ether_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|uio
block|{
name|int
name|uio_resid
decl_stmt|;
name|int
name|uio_rw
decl_stmt|;
name|caddr_t
name|uio_buf
decl_stmt|;
block|}
name|uio_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UIO_READ
value|0
end_define

begin_define
define|#
directive|define
name|UIO_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|UIOMOVE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uiomove(a,b,c,d)
end_define

begin_comment
comment|/*  * For masking struct ifnet onto struct device  */
end_comment

begin_define
define|#
directive|define
name|if_name
value|name
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|GETUNIT
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|dev_get(x)
end_define

begin_define
define|#
directive|define
name|FREE_MB_T
parameter_list|(
name|m
parameter_list|)
value|kfree_skb(m, FREE_WRITE)
end_define

begin_define
define|#
directive|define
name|uniqtime
value|do_gettimeofday
end_define

begin_undef
undef|#
directive|undef
name|INT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|UINT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|LONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|ULONG_MAX
end_undef

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_define
define|#
directive|define
name|SPL_X
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SPL_NET
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SPL_IMP
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp(a,b,c)
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy(b,a,c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|)
value|memset(a,0,c)
end_define

begin_define
define|#
directive|define
name|UNITNAME
parameter_list|(
name|n
parameter_list|)
value|dev_get((n))
end_define

begin_define
define|#
directive|define
name|KMALLOC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a) = (b)kmalloc(sizeof(*(a)), GFP_ATOMIC)
end_define

begin_define
define|#
directive|define
name|KMALLOCS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(a) = (b)kmalloc((c), GFP_ATOMIC)
end_define

begin_define
define|#
directive|define
name|KFREE
parameter_list|(
name|x
parameter_list|)
value|kfree_s((x), sizeof(*(x)))
end_define

begin_define
define|#
directive|define
name|KFREES
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|kfree_s((x), (s))
end_define

begin_define
define|#
directive|define
name|IRCOPY
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter|,
name|void
modifier|*
name|b
parameter|,
name|size_t
name|c
parameter_list|)
value|{ \ 	int error; \  	error = verify_area(VERIFY_READ, a ,c); \ 	if (!error) \ 		memcpy_fromfs(b, a, c); \ 	return error; \ }
end_define

begin_function
specifier|static
specifier|inline
name|int
name|IWCOPY
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|verify_area
argument_list|(
name|VERIFY_WRITE
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|memcpy_tofs
argument_list|(
name|b
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|IRCOPYPTR
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|caddr_t
name|ca
decl_stmt|;
name|int
name|error
decl_stmt|;
name|error
operator|=
name|verify_area
argument_list|(
name|VERIFY_READ
argument_list|,
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|ca
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|memcpy_fromfs
argument_list|(
name|ca
argument_list|,
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|ca
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|verify_area
argument_list|(
name|VERIFY_READ
argument_list|,
name|ca
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|memcpy_fromfs
argument_list|(
name|b
argument_list|,
name|ca
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|IWCOPYPTR
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
name|caddr_t
name|ca
decl_stmt|;
name|int
name|error
decl_stmt|;
name|error
operator|=
name|verify_area
argument_list|(
name|VERIFY_READ
argument_list|,
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|ca
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|memcpy_fromfs
argument_list|(
name|ca
argument_list|,
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|ca
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|verify_area
argument_list|(
name|VERIFY_WRITE
argument_list|,
name|ca
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|memcpy_tofs
argument_list|(
name|ca
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__KERNEL__
end_define

begin_undef
undef|#
directive|undef
name|INT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|UINT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|LONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|ULONG_MAX
end_undef

begin_define
define|#
directive|define
name|s8
value|__s8
end_define

begin_define
define|#
directive|define
name|u8
value|__u8
end_define

begin_define
define|#
directive|define
name|s16
value|__s16
end_define

begin_define
define|#
directive|define
name|u16
value|__u16
end_define

begin_define
define|#
directive|define
name|s32
value|__s32
end_define

begin_define
define|#
directive|define
name|u32
value|__u32
end_define

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_undef
undef|#
directive|undef
name|__KERNEL__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ifnet
value|device
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|tcphdr
name|tcphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|udphdr
name|udphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|icmp
name|icmphdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ip
name|ip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ether_header
name|ether_header_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_typedef
typedef|typedef
name|struct
name|tcpiphdr
name|tcpiphdr_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_struct
struct|struct
name|ether_addr
block|{
name|char
name|ether_addr_octet
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX - This is one of those *awful* hacks which nobody likes  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|A_A
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A_A
value|&
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BSD
operator|>=
literal|199306
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|m_act
argument_list|)
end_if

begin_define
define|#
directive|define
name|m_act
value|m_nextpkt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ROUTERADVERT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ROUTERADVERT
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP_ROUTERSOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP_ROUTERSOLICIT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ICMP_MAX_UNREACH
end_undef

begin_define
define|#
directive|define
name|ICMP_MAX_UNREACH
value|14
end_define

begin_undef
undef|#
directive|undef
name|ICMP_MAXTYPE
end_undef

begin_define
define|#
directive|define
name|ICMP_MAXTYPE
value|18
end_define

begin_comment
comment|/*  * ICMP error replies have an IP header (20 bytes), 8 bytes of ICMP data,  * another IP header and then 64 bits of data, totalling 56.  Of course,  * the last 64 bits is dependant on that being available.  */
end_comment

begin_define
define|#
directive|define
name|ICMPERR_ICMPHLEN
value|8
end_define

begin_define
define|#
directive|define
name|ICMPERR_IPICMPHLEN
value|(20 + 8)
end_define

begin_define
define|#
directive|define
name|ICMPERR_MINPKTLEN
value|(20 + 8 + 20)
end_define

begin_define
define|#
directive|define
name|ICMPERR_MAXPKTLEN
value|(20 + 8 + 20 + 8)
end_define

begin_define
define|#
directive|define
name|ICMP6_MINLEN
value|8
end_define

begin_define
define|#
directive|define
name|ICMP6ERR_MINPKTLEN
value|(40 + 8)
end_define

begin_define
define|#
directive|define
name|ICMP6ERR_IPICMPHLEN
value|(40 + 8 + 40)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PACKET_TOO_BIG
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PACKET_TOO_BIG
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEEDED
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEEDED
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAM_PROB
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAM_PROB
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ECHO_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ECHO_REQUEST
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ECHO_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ECHO_REPLY
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_QUERY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_QUERY
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_QUERY
value|130
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_REPORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REPORT
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_REPORT
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_REPORT
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MEMBERSHIP_REDUCTION
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MEMBERSHIP_REDUCTION
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_LISTENER_DONE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_LISTENER_DONE
value|132
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_ROUTER_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ND_ROUTER_SOLICIT
value|133
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_ROUTER_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ND_ROUTER_ADVERT
value|134
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_NEIGHBOR_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ND_NEIGHBOR_SOLICIT
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_NEIGHBOR_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ND_NEIGHBOR_ADVERT
value|136
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ND_REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|ND_REDIRECT
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING
value|138
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_WRUREQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_WRUREQUEST
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_WRUREPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_WRUREPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_FQDN_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_FQDN_QUERY
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_FQDN_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_FQDN_REPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_QUERY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_QUERY
value|139
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_REPLY
value|140
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE_RESP
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE_RESP
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLD6_MTRACE
end_ifndef

begin_define
define|#
directive|define
name|MLD6_MTRACE
value|201
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_HADISCOV_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REQUEST
value|202
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_HADISCOV_REPLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_HADISCOV_REPLY
value|203
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MOBILEPREFIX_SOLICIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MOBILEPREFIX_SOLICIT
value|204
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MOBILEPREFIX_ADVERT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MOBILEPREFIX_ADVERT
value|205
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_MAXTYPE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_MAXTYPE
value|205
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOROUTE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOROUTE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_ADMIN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADMIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOTNEIGHBOR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_BEYONDSCOPE
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_BEYONDSCOPE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_ADDR
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_ADDR
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_DST_UNREACH_NOPORT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_DST_UNREACH_NOPORT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEED_TRANSIT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_TRANSIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_TIME_EXCEED_REASSEMBLY
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_TIME_EXCEED_REASSEMBLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_REFUSED
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_REFUSED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_UNKNOWN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_UNKNOWN
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_COMMAND
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_RESULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_HEADER
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_HEADER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_NEXTHEADER
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_NEXTHEADER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_PARAMPROB_OPTION
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_PARAMPROB_OPTION
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_IPV6
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_FQDN
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_FQDN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ICMP6_NI_SUBJ_IPV4
end_ifndef

begin_define
define|#
directive|define
name|ICMP6_NI_SUBJ_IPV4
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ECN is a new addition to TCP - RFC 2481  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ECN
end_ifndef

begin_define
define|#
directive|define
name|TH_ECN
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_CWR
end_ifndef

begin_define
define|#
directive|define
name|TH_CWR
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TH_ECNALL
value|(TH_ECN|TH_CWR)
end_define

begin_define
define|#
directive|define
name|TCPF_ALL
value|(TH_FIN|TH_SYN|TH_RST|TH_PUSH|TH_ACK|TH_URG|TH_ECN|TH_CWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_COMPAT_H__ */
end_comment

end_unit

