begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001, 2003 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_fil.h	1.35 6/5/96  * $FreeBSD$  * Id: ip_fil.h,v 2.170.2.18 2005/03/28 10:47:52 darrenr Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IP_FIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__IP_FIL_H__
end_define

begin_include
include|#
directive|include
file|"netinet/ip_compat.h"
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIOCADAFR
value|_IOW('r', 60, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMAFR
value|_IOW('r', 61, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSETFF
value|_IOW('r', 62, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFF
value|_IOR('r', 63, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFS
value|_IOWR('r', 64, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFL
value|_IOWR('r', 65, int)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFB
value|_IOR('r', 66, int)
end_define

begin_define
define|#
directive|define
name|SIOCADIFR
value|_IOW('r', 67, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMIFR
value|_IOW('r', 68, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSWAPA
value|_IOR('r', 69, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCINAFR
value|_IOW('r', 70, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCINIFR
value|_IOW('r', 71, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCFRENB
value|_IOW('r', 72, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRSYN
value|_IOW('r', 73, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRZST
value|_IOWR('r', 74, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCZRLST
value|_IOWR('r', 75, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHW
value|_IOWR('r', 76, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHR
value|_IOWR('r', 77, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCATHST
value|_IOWR('r', 78, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTLCK
value|_IOWR('r', 79, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCSTPUT
value|_IOWR('r', 80, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTGET
value|_IOWR('r', 81, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTGSZ
value|_IOWR('r', 82, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGFRST
value|_IOWR('r', 83, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSETLG
value|_IOWR('r', 84, int)
end_define

begin_define
define|#
directive|define
name|SIOCGETLG
value|_IOWR('r', 85, int)
end_define

begin_define
define|#
directive|define
name|SIOCFUNCL
value|_IOWR('r', 86, struct ipfunc_resolve)
end_define

begin_define
define|#
directive|define
name|SIOCIPFGETNEXT
value|_IOWR('r', 87, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFGET
value|_IOWR('r', 88, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFSET
value|_IOWR('r', 89, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFL6
value|_IOWR('r', 90, int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIOCADAFR
value|_IOW(r, 60, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMAFR
value|_IOW(r, 61, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSETFF
value|_IOW(r, 62, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFF
value|_IOR(r, 63, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCGETFS
value|_IOWR(r, 64, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFL
value|_IOWR(r, 65, int)
end_define

begin_define
define|#
directive|define
name|SIOCIPFFB
value|_IOR(r, 66, int)
end_define

begin_define
define|#
directive|define
name|SIOCADIFR
value|_IOW(r, 67, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCRMIFR
value|_IOW(r, 68, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSWAPA
value|_IOR(r, 69, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCINAFR
value|_IOW(r, 70, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCINIFR
value|_IOW(r, 71, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCFRENB
value|_IOW(r, 72, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRSYN
value|_IOW(r, 73, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCFRZST
value|_IOWR(r, 74, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCZRLST
value|_IOWR(r, 75, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHW
value|_IOWR(r, 76, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCAUTHR
value|_IOWR(r, 77, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCATHST
value|_IOWR(r, 78, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTLCK
value|_IOWR(r, 79, u_int)
end_define

begin_define
define|#
directive|define
name|SIOCSTPUT
value|_IOWR(r, 80, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTGET
value|_IOWR(r, 81, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSTGSZ
value|_IOWR(r, 82, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCGFRST
value|_IOWR(r, 83, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCSETLG
value|_IOWR(r, 84, int)
end_define

begin_define
define|#
directive|define
name|SIOCGETLG
value|_IOWR(r, 85, int)
end_define

begin_define
define|#
directive|define
name|SIOCFUNCL
value|_IOWR(r, 86, struct ipfunc_resolve)
end_define

begin_define
define|#
directive|define
name|SIOCIPFGETNEXT
value|_IOWR(r, 87, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFGET
value|_IOWR(r, 88, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFSET
value|_IOWR(r, 89, struct ipfobj)
end_define

begin_define
define|#
directive|define
name|SIOCIPFL6
value|_IOWR(r, 90, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCADDFR
value|SIOCADAFR
end_define

begin_define
define|#
directive|define
name|SIOCDELFR
value|SIOCRMAFR
end_define

begin_define
define|#
directive|define
name|SIOCINSFR
value|SIOCINAFR
end_define

begin_struct_decl
struct_decl|struct
name|ipscan
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|* lookupfunc_t
argument_list|)
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
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * i6addr is used as a container for both IPv4 and IPv6 addresses, as well  * as other types of objects, depending on its qualifier.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_typedef
typedef|typedef
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
name|void
modifier|*
name|vptr
index|[
literal|2
index|]
decl_stmt|;
name|lookupfunc_t
name|lptr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|i6addr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
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
name|void
modifier|*
name|vptr
index|[
literal|2
index|]
decl_stmt|;
name|lookupfunc_t
name|lptr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|i6addr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|in4_addr
value|in4.s_addr
end_define

begin_define
define|#
directive|define
name|iplookupnum
value|i6[0]
end_define

begin_define
define|#
directive|define
name|iplookuptype
value|i6[1]
end_define

begin_comment
comment|/*  * NOTE: These DO overlap the above on 64bit systems and this IS recognised.  */
end_comment

begin_define
define|#
directive|define
name|iplookupptr
value|vptr[0]
end_define

begin_define
define|#
directive|define
name|iplookupfunc
value|lptr[1]
end_define

begin_define
define|#
directive|define
name|I60
parameter_list|(
name|x
parameter_list|)
value|(((i6addr_t *)(x))->i6[0])
end_define

begin_define
define|#
directive|define
name|I61
parameter_list|(
name|x
parameter_list|)
value|(((i6addr_t *)(x))->i6[1])
end_define

begin_define
define|#
directive|define
name|I62
parameter_list|(
name|x
parameter_list|)
value|(((i6addr_t *)(x))->i6[2])
end_define

begin_define
define|#
directive|define
name|I63
parameter_list|(
name|x
parameter_list|)
value|(((i6addr_t *)(x))->i6[3])
end_define

begin_define
define|#
directive|define
name|HI60
parameter_list|(
name|x
parameter_list|)
value|ntohl(((i6addr_t *)(x))->i6[0])
end_define

begin_define
define|#
directive|define
name|HI61
parameter_list|(
name|x
parameter_list|)
value|ntohl(((i6addr_t *)(x))->i6[1])
end_define

begin_define
define|#
directive|define
name|HI62
parameter_list|(
name|x
parameter_list|)
value|ntohl(((i6addr_t *)(x))->i6[2])
end_define

begin_define
define|#
directive|define
name|HI63
parameter_list|(
name|x
parameter_list|)
value|ntohl(((i6addr_t *)(x))->i6[3])
end_define

begin_define
define|#
directive|define
name|IP6_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((I63(a) == I63(b))&& (I62(a) == I62(b))&& \ 			 (I61(a) == I61(b))&& (I60(a) == I60(b)))
end_define

begin_define
define|#
directive|define
name|IP6_NEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((I63(a) != I63(b)) || (I62(a) != I62(b)) || \ 			 (I61(a) != I61(b)) || (I60(a) != I60(b)))
end_define

begin_define
define|#
directive|define
name|IP6_ISZERO
parameter_list|(
name|a
parameter_list|)
value|((I60(a) | I61(a) | I62(a) | I63(a)) == 0)
end_define

begin_define
define|#
directive|define
name|IP6_NOTZERO
parameter_list|(
name|a
parameter_list|)
value|((I60(a) | I61(a) | I62(a) | I63(a)) != 0)
end_define

begin_define
define|#
directive|define
name|IP6_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(HI60(a)> HI60(b) || (HI60(a) == HI60(b)&& \ 			  (HI61(a)> HI61(b) || (HI61(a) == HI61(b)&& \ 			    (HI62(a)> HI62(b) || (HI62(a) == HI62(b)&& \ 			      HI63(a)> HI63(b)))))))
end_define

begin_define
define|#
directive|define
name|IP6_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(HI60(a)< HI60(b) || (HI60(a) == HI60(b)&& \ 			  (HI61(a)< HI61(b) || (HI61(a) == HI61(b)&& \ 			    (HI62(a)< HI62(b) || (HI62(a) == HI62(b)&& \ 			      HI63(a)< HI63(b)))))))
end_define

begin_define
define|#
directive|define
name|NLADD
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|htonl(ntohl(n) + (x))
end_define

begin_define
define|#
directive|define
name|IP6_INC
parameter_list|(
name|a
parameter_list|)
define|\
value|{ i6addr_t *_i6 = (i6addr_t *)(a); \ 		  _i6->i6[0] = NLADD(_i6->i6[0], 1); \ 		  if (_i6->i6[0] == 0) { \ 			_i6->i6[0] = NLADD(_i6->i6[1], 1); \ 			if (_i6->i6[1] == 0) { \ 				_i6->i6[0] = NLADD(_i6->i6[2], 1); \ 				if (_i6->i6[2] == 0) { \ 					_i6->i6[0] = NLADD(_i6->i6[3], 1); \ 				} \ 			} \ 		  } \ 		}
end_define

begin_define
define|#
directive|define
name|IP6_ADD
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|,
name|d
parameter_list|)
define|\
value|{ i6addr_t *_s = (i6addr_t *)(a); \ 		  i6addr_t *_d = (i6addr_t *)(d); \ 		  _d->i6[0] = NLADD(_s->i6[0], x); \ 		  if (ntohl(_d->i6[0])< ntohl(_s->i6[0])) { \ 			_d->i6[1] = NLADD(_d->i6[1], 1); \ 			if (ntohl(_d->i6[1])< ntohl(_s->i6[1])) { \ 				_d->i6[2] = NLADD(_d->i6[2], 1); \ 				if (ntohl(_d->i6[2])< ntohl(_s->i6[2])) { \ 					_d->i6[3] = NLADD(_d->i6[3], 1); \ 				} \ 			} \ 		  } \ 		}
end_define

begin_define
define|#
directive|define
name|IP6_AND
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|d
parameter_list|)
value|{ i6addr_t *_s1 = (i6addr_t *)(a); \ 			  i6addr_t *_s2 = (i6addr_t *)(d); \ 			  i6addr_t *_d = (i6addr_t *)(d); \ 			  _d->i6[0] = _s1->i6[0]& _s2->i6[0]; \ 			  _d->i6[1] = _s1->i6[1]& _s2->i6[1]; \ 			  _d->i6[2] = _s1->i6[2]& _s2->i6[2]; \ 			  _d->i6[3] = _s1->i6[3]& _s2->i6[3]; \ 			}
end_define

begin_define
define|#
directive|define
name|IP6_MERGE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|{ i6addr_t *_d, *_s1, *_s2; \ 			  _d = (i6addr_t *)(a); \ 			  _s1 = (i6addr_t *)(b); \ 			  _s2 = (i6addr_t *)(c); \ 			  _d->i6[0] |= _s1->i6[0]& ~_s2->i6[0]; \ 			  _d->i6[1] |= _s1->i6[1]& ~_s2->i6[1]; \ 			  _d->i6[2] |= _s1->i6[2]& ~_s2->i6[2]; \ 			  _d->i6[2] |= _s1->i6[3]& ~_s2->i6[3]; \ 			}
end_define

begin_typedef
typedef|typedef
struct|struct
name|fr_ip
block|{
name|u_32_t
name|fi_v
range|:
literal|4
decl_stmt|;
comment|/* IP version */
name|u_32_t
name|fi_xx
range|:
literal|4
decl_stmt|;
comment|/* spare */
name|u_32_t
name|fi_tos
range|:
literal|8
decl_stmt|;
comment|/* IP packet TOS */
name|u_32_t
name|fi_ttl
range|:
literal|8
decl_stmt|;
comment|/* IP packet TTL */
name|u_32_t
name|fi_p
range|:
literal|8
decl_stmt|;
comment|/* IP packet protocol */
name|u_32_t
name|fi_optmsk
decl_stmt|;
comment|/* bitmask composed from IP options */
name|i6addr_t
name|fi_src
decl_stmt|;
comment|/* source address from packet */
name|i6addr_t
name|fi_dst
decl_stmt|;
comment|/* destination address from packet */
name|u_short
name|fi_secmsk
decl_stmt|;
comment|/* bitmask composed from IP security options */
name|u_short
name|fi_auth
decl_stmt|;
comment|/* authentication code from IP sec. options */
name|u_32_t
name|fi_flx
decl_stmt|;
comment|/* packet flags */
name|u_32_t
name|fi_tcpmsk
decl_stmt|;
comment|/* TCP options set/reset */
name|u_32_t
name|fi_res1
decl_stmt|;
comment|/* RESERVED */
block|}
name|fr_ip_t
typedef|;
end_typedef

begin_comment
comment|/*  * For use in fi_flx  */
end_comment

begin_define
define|#
directive|define
name|FI_TCPUDP
value|0x0001
end_define

begin_comment
comment|/* TCP/UCP implied comparison*/
end_comment

begin_define
define|#
directive|define
name|FI_OPTIONS
value|0x0002
end_define

begin_define
define|#
directive|define
name|FI_FRAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|FI_SHORT
value|0x0008
end_define

begin_define
define|#
directive|define
name|FI_NATED
value|0x0010
end_define

begin_define
define|#
directive|define
name|FI_MULTICAST
value|0x0020
end_define

begin_define
define|#
directive|define
name|FI_BROADCAST
value|0x0040
end_define

begin_define
define|#
directive|define
name|FI_MBCAST
value|0x0080
end_define

begin_define
define|#
directive|define
name|FI_STATE
value|0x0100
end_define

begin_define
define|#
directive|define
name|FI_BADNAT
value|0x0200
end_define

begin_define
define|#
directive|define
name|FI_BAD
value|0x0400
end_define

begin_define
define|#
directive|define
name|FI_OOW
value|0x0800
end_define

begin_comment
comment|/* Out of state window, else match */
end_comment

begin_define
define|#
directive|define
name|FI_ICMPERR
value|0x1000
end_define

begin_define
define|#
directive|define
name|FI_FRAGBODY
value|0x2000
end_define

begin_define
define|#
directive|define
name|FI_BADSRC
value|0x4000
end_define

begin_define
define|#
directive|define
name|FI_LOWTTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|FI_CMP
value|0xcfe3
end_define

begin_comment
comment|/* Not FI_FRAG,FI_NATED,FI_FRAGTAIL */
end_comment

begin_define
define|#
directive|define
name|FI_ICMPCMP
value|0x0003
end_define

begin_comment
comment|/* Flags we can check for ICMP error packets */
end_comment

begin_define
define|#
directive|define
name|FI_WITH
value|0xeffe
end_define

begin_comment
comment|/* Not FI_TCPUDP */
end_comment

begin_define
define|#
directive|define
name|FI_V6EXTHDR
value|0x10000
end_define

begin_define
define|#
directive|define
name|FI_COALESCE
value|0x20000
end_define

begin_define
define|#
directive|define
name|FI_NOCKSUM
value|0x20000000
end_define

begin_comment
comment|/* don't do a L4 checksum validation */
end_comment

begin_define
define|#
directive|define
name|FI_DONTCACHE
value|0x40000000
end_define

begin_comment
comment|/* don't cache the result */
end_comment

begin_define
define|#
directive|define
name|FI_IGNORE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|fi_saddr
value|fi_src.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fi_daddr
value|fi_dst.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fi_srcnum
value|fi_src.iplookupnum
end_define

begin_define
define|#
directive|define
name|fi_dstnum
value|fi_dst.iplookupnum
end_define

begin_define
define|#
directive|define
name|fi_srctype
value|fi_src.iplookuptype
end_define

begin_define
define|#
directive|define
name|fi_dsttype
value|fi_dst.iplookuptype
end_define

begin_define
define|#
directive|define
name|fi_srcptr
value|fi_src.iplookupptr
end_define

begin_define
define|#
directive|define
name|fi_dstptr
value|fi_dst.iplookupptr
end_define

begin_define
define|#
directive|define
name|fi_srcfunc
value|fi_src.iplookupfunc
end_define

begin_define
define|#
directive|define
name|fi_dstfunc
value|fi_dst.iplookupfunc
end_define

begin_comment
comment|/*  * These are both used by the state and NAT code to indicate that one port or  * the other should be treated as a wildcard.  * NOTE: When updating, check bit masks in ip_state.h and update there too.  */
end_comment

begin_define
define|#
directive|define
name|SI_W_SPORT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SI_W_DPORT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SI_WILDP
value|(SI_W_SPORT|SI_W_DPORT)
end_define

begin_define
define|#
directive|define
name|SI_W_SADDR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SI_W_DADDR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SI_WILDA
value|(SI_W_SADDR|SI_W_DADDR)
end_define

begin_define
define|#
directive|define
name|SI_NEWFR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SI_CLONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SI_CLONED
value|0x00004000
end_define

begin_typedef
typedef|typedef
struct|struct
name|fr_info
block|{
name|void
modifier|*
name|fin_ifp
decl_stmt|;
comment|/* interface packet is `on' */
name|fr_ip_t
name|fin_fi
decl_stmt|;
comment|/* IP Packet summary */
union|union
block|{
name|u_short
name|fid_16
index|[
literal|2
index|]
decl_stmt|;
comment|/* TCP/UDP ports, ICMP code/type */
name|u_32_t
name|fid_32
decl_stmt|;
block|}
name|fin_dat
union|;
name|int
name|fin_out
decl_stmt|;
comment|/* in or out ? 1 == out, 0 == in */
name|int
name|fin_rev
decl_stmt|;
comment|/* state only: 1 = reverse */
name|u_short
name|fin_hlen
decl_stmt|;
comment|/* length of IP header in bytes */
name|u_char
name|fin_tcpf
decl_stmt|;
comment|/* TCP header flags (SYN, ACK, etc) */
name|u_char
name|fin_icode
decl_stmt|;
comment|/* ICMP error to return */
name|u_32_t
name|fin_rule
decl_stmt|;
comment|/* rule # last matched */
name|char
name|fin_group
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
comment|/* group number, -1 for none */
name|struct
name|frentry
modifier|*
name|fin_fr
decl_stmt|;
comment|/* last matching rule */
name|void
modifier|*
name|fin_dp
decl_stmt|;
comment|/* start of data past IP header */
name|int
name|fin_dlen
decl_stmt|;
comment|/* length of data portion of packet */
name|int
name|fin_plen
decl_stmt|;
name|int
name|fin_ipoff
decl_stmt|;
comment|/* # bytes from buffer start to hdr */
name|u_short
name|fin_id
decl_stmt|;
comment|/* IP packet id field */
name|u_short
name|fin_off
decl_stmt|;
name|int
name|fin_depth
decl_stmt|;
comment|/* Group nesting depth */
name|int
name|fin_error
decl_stmt|;
comment|/* Error code to return */
name|void
modifier|*
name|fin_nat
decl_stmt|;
name|void
modifier|*
name|fin_state
decl_stmt|;
name|void
modifier|*
name|fin_nattag
decl_stmt|;
name|ip_t
modifier|*
name|fin_ip
decl_stmt|;
name|mb_t
modifier|*
modifier|*
name|fin_mp
decl_stmt|;
comment|/* pointer to pointer to mbuf */
name|mb_t
modifier|*
name|fin_m
decl_stmt|;
comment|/* pointer to mbuf */
ifdef|#
directive|ifdef
name|MENTAT
name|mb_t
modifier|*
name|fin_qfm
decl_stmt|;
comment|/* pointer to mblk where pkt starts */
name|void
modifier|*
name|fin_qpi
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__sgi
name|void
modifier|*
name|fin_hbuf
decl_stmt|;
endif|#
directive|endif
block|}
name|fr_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fin_v
value|fin_fi.fi_v
end_define

begin_define
define|#
directive|define
name|fin_p
value|fin_fi.fi_p
end_define

begin_define
define|#
directive|define
name|fin_flx
value|fin_fi.fi_flx
end_define

begin_define
define|#
directive|define
name|fin_optmsk
value|fin_fi.fi_optmsk
end_define

begin_define
define|#
directive|define
name|fin_secmsk
value|fin_fi.fi_secmsk
end_define

begin_define
define|#
directive|define
name|fin_auth
value|fin_fi.fi_auth
end_define

begin_define
define|#
directive|define
name|fin_src
value|fin_fi.fi_src.in4
end_define

begin_define
define|#
directive|define
name|fin_src6
value|fin_fi.fi_src.in6
end_define

begin_define
define|#
directive|define
name|fin_saddr
value|fin_fi.fi_saddr
end_define

begin_define
define|#
directive|define
name|fin_dst
value|fin_fi.fi_dst.in4
end_define

begin_define
define|#
directive|define
name|fin_dst6
value|fin_fi.fi_dst.in6
end_define

begin_define
define|#
directive|define
name|fin_daddr
value|fin_fi.fi_daddr
end_define

begin_define
define|#
directive|define
name|fin_data
value|fin_dat.fid_16
end_define

begin_define
define|#
directive|define
name|fin_sport
value|fin_dat.fid_16[0]
end_define

begin_define
define|#
directive|define
name|fin_dport
value|fin_dat.fid_16[1]
end_define

begin_define
define|#
directive|define
name|fin_ports
value|fin_dat.fid_32
end_define

begin_define
define|#
directive|define
name|IPF_IN
value|0
end_define

begin_define
define|#
directive|define
name|IPF_OUT
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|frentry
modifier|*
argument_list|(
operator|*
name|ipfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*ipfuncinit_t
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|frentry
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipfunc_resolve
block|{
name|char
name|ipfu_name
index|[
literal|32
index|]
decl_stmt|;
name|ipfunc_t
name|ipfu_addr
decl_stmt|;
name|ipfuncinit_t
name|ipfu_init
decl_stmt|;
block|}
name|ipfunc_resolve_t
typedef|;
end_typedef

begin_comment
comment|/*  * Size for compares on fr_info structures  */
end_comment

begin_define
define|#
directive|define
name|FI_CSIZE
value|offsetof(fr_info_t, fin_icode)
end_define

begin_define
define|#
directive|define
name|FI_LCSIZE
value|offsetof(fr_info_t, fin_dp)
end_define

begin_comment
comment|/*  * Size for copying cache fr_info structure  */
end_comment

begin_define
define|#
directive|define
name|FI_COPYSIZE
value|offsetof(fr_info_t, fin_dp)
end_define

begin_comment
comment|/*  * Structure for holding IPFilter's tag information  */
end_comment

begin_define
define|#
directive|define
name|IPFTAG_LEN
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|u_32_t
name|iptu_num
index|[
literal|4
index|]
decl_stmt|;
name|char
name|iptu_tag
index|[
name|IPFTAG_LEN
index|]
decl_stmt|;
block|}
name|ipt_un
union|;
name|int
name|ipt_not
decl_stmt|;
block|}
name|ipftag_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipt_tag
value|ipt_un.iptu_tag
end_define

begin_define
define|#
directive|define
name|ipt_num
value|ipt_un.iptu_num
end_define

begin_comment
comment|/*  * This structure is used to hold information about the next hop for where  * to forward a packet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frdest
block|{
name|void
modifier|*
name|fd_ifp
decl_stmt|;
name|i6addr_t
name|fd_ip6
decl_stmt|;
name|char
name|fd_ifname
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
block|}
name|frdest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fd_ip
value|fd_ip6.in4
end_define

begin_comment
comment|/*  * This structure holds information about a port comparison.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frpcmp
block|{
name|int
name|frp_cmp
decl_stmt|;
comment|/* data for port comparisons */
name|u_short
name|frp_port
decl_stmt|;
comment|/* top port for<> and>< */
name|u_short
name|frp_top
decl_stmt|;
comment|/* top port for<> and>< */
block|}
name|frpcmp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FR_EQUAL
value|1
end_define

begin_define
define|#
directive|define
name|FR_NEQUAL
value|2
end_define

begin_define
define|#
directive|define
name|FR_LESST
value|3
end_define

begin_define
define|#
directive|define
name|FR_GREATERT
value|4
end_define

begin_define
define|#
directive|define
name|FR_LESSTE
value|5
end_define

begin_define
define|#
directive|define
name|FR_GREATERTE
value|6
end_define

begin_define
define|#
directive|define
name|FR_OUTRANGE
value|7
end_define

begin_define
define|#
directive|define
name|FR_INRANGE
value|8
end_define

begin_define
define|#
directive|define
name|FR_INCRANGE
value|9
end_define

begin_comment
comment|/*  * Structure containing all the relevant TCP things that can be checked in  * a filter rule.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frtuc
block|{
name|u_char
name|ftu_tcpfm
decl_stmt|;
comment|/* tcp flags mask */
name|u_char
name|ftu_tcpf
decl_stmt|;
comment|/* tcp flags */
name|frpcmp_t
name|ftu_src
decl_stmt|;
name|frpcmp_t
name|ftu_dst
decl_stmt|;
block|}
name|frtuc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ftu_scmp
value|ftu_src.frp_cmp
end_define

begin_define
define|#
directive|define
name|ftu_dcmp
value|ftu_dst.frp_cmp
end_define

begin_define
define|#
directive|define
name|ftu_sport
value|ftu_src.frp_port
end_define

begin_define
define|#
directive|define
name|ftu_dport
value|ftu_dst.frp_port
end_define

begin_define
define|#
directive|define
name|ftu_stop
value|ftu_src.frp_top
end_define

begin_define
define|#
directive|define
name|ftu_dtop
value|ftu_dst.frp_top
end_define

begin_define
define|#
directive|define
name|FR_TCPFMAX
value|0x3f
end_define

begin_comment
comment|/*  * This structure makes up what is considered to be the IPFilter specific  * matching components of a filter rule, as opposed to the data structures  * used to define the result which are in frentry_t and not here.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fripf
block|{
name|fr_ip_t
name|fri_ip
decl_stmt|;
name|fr_ip_t
name|fri_mip
decl_stmt|;
comment|/* mask structure */
name|u_short
name|fri_icmpm
decl_stmt|;
comment|/* data for ICMP packets (mask) */
name|u_short
name|fri_icmp
decl_stmt|;
name|frtuc_t
name|fri_tuc
decl_stmt|;
name|int
name|fri_satype
decl_stmt|;
comment|/* addres type */
name|int
name|fri_datype
decl_stmt|;
comment|/* addres type */
name|int
name|fri_sifpidx
decl_stmt|;
comment|/* doing dynamic addressing */
name|int
name|fri_difpidx
decl_stmt|;
comment|/* index into fr_ifps[] to use when */
block|}
name|fripf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fri_dstnum
value|fri_ip.fi_dstnum
end_define

begin_define
define|#
directive|define
name|fri_srcnum
value|fri_mip.fi_srcnum
end_define

begin_define
define|#
directive|define
name|fri_dstptr
value|fri_ip.fi_dstptr
end_define

begin_define
define|#
directive|define
name|fri_srcptr
value|fri_mip.fi_srcptr
end_define

begin_define
define|#
directive|define
name|FRI_NORMAL
value|0
end_define

begin_comment
comment|/* Normal address */
end_comment

begin_define
define|#
directive|define
name|FRI_DYNAMIC
value|1
end_define

begin_comment
comment|/* dynamic address */
end_comment

begin_define
define|#
directive|define
name|FRI_LOOKUP
value|2
end_define

begin_comment
comment|/* address is a pool # */
end_comment

begin_define
define|#
directive|define
name|FRI_RANGE
value|3
end_define

begin_comment
comment|/* address/mask is a range */
end_comment

begin_define
define|#
directive|define
name|FRI_NETWORK
value|4
end_define

begin_comment
comment|/* network address from if */
end_comment

begin_define
define|#
directive|define
name|FRI_BROADCAST
value|5
end_define

begin_comment
comment|/* broadcast address from if */
end_comment

begin_define
define|#
directive|define
name|FRI_PEERADDR
value|6
end_define

begin_comment
comment|/* Peer address for P-to-P */
end_comment

begin_define
define|#
directive|define
name|FRI_NETMASKED
value|7
end_define

begin_comment
comment|/* network address with netmask from if */
end_comment

begin_typedef
typedef|typedef
name|struct
name|frentry
modifier|*
argument_list|(
operator|*
name|frentfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|frentry
block|{
name|ipfmutex_t
name|fr_lock
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fr_next
decl_stmt|;
name|struct
name|frentry
modifier|*
modifier|*
name|fr_grp
decl_stmt|;
name|struct
name|ipscan
modifier|*
name|fr_isc
decl_stmt|;
name|void
modifier|*
name|fr_ifas
index|[
literal|4
index|]
decl_stmt|;
name|void
modifier|*
name|fr_ptr
decl_stmt|;
comment|/* for use with fr_arg */
name|char
modifier|*
name|fr_comment
decl_stmt|;
comment|/* text comment for rule */
name|int
name|fr_ref
decl_stmt|;
comment|/* reference count - for grouping */
name|int
name|fr_statecnt
decl_stmt|;
comment|/* state count - for limit rules */
comment|/* 	 * These are only incremented when a packet  matches this rule and 	 * it is the last match 	 */
name|U_QUAD_T
name|fr_hits
decl_stmt|;
name|U_QUAD_T
name|fr_bytes
decl_stmt|;
comment|/* 	 * For PPS rate limiting 	 */
name|struct
name|timeval
name|fr_lastpkt
decl_stmt|;
name|int
name|fr_curpps
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|fru_data
decl_stmt|;
name|caddr_t
name|fru_caddr
decl_stmt|;
name|fripf_t
modifier|*
name|fru_ipf
decl_stmt|;
name|frentfunc_t
name|fru_func
decl_stmt|;
block|}
name|fr_dun
union|;
comment|/* 	 * Fields after this may not change whilst in the kernel. 	 */
name|ipfunc_t
name|fr_func
decl_stmt|;
comment|/* call this function */
name|int
name|fr_dsize
decl_stmt|;
name|int
name|fr_pps
decl_stmt|;
name|int
name|fr_statemax
decl_stmt|;
comment|/* max reference count */
name|int
name|fr_flineno
decl_stmt|;
comment|/* line number from conf file */
name|u_32_t
name|fr_type
decl_stmt|;
name|u_32_t
name|fr_flags
decl_stmt|;
comment|/* per-rule flags&& options (see below) */
name|u_32_t
name|fr_logtag
decl_stmt|;
comment|/* user defined log tag # */
name|u_32_t
name|fr_collect
decl_stmt|;
comment|/* collection number */
name|u_int
name|fr_arg
decl_stmt|;
comment|/* misc. numeric arg for rule */
name|u_int
name|fr_loglevel
decl_stmt|;
comment|/* syslog log facility + priority */
name|u_int
name|fr_age
index|[
literal|2
index|]
decl_stmt|;
comment|/* non-TCP timeouts */
name|u_char
name|fr_v
decl_stmt|;
name|u_char
name|fr_icode
decl_stmt|;
comment|/* return ICMP code */
name|char
name|fr_group
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
comment|/* group to which this rule belongs */
name|char
name|fr_grhead
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
comment|/* group # which this rule starts */
name|ipftag_t
name|fr_nattag
decl_stmt|;
name|char
name|fr_ifnames
index|[
literal|4
index|]
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
name|char
name|fr_isctag
index|[
literal|16
index|]
decl_stmt|;
name|frdest_t
name|fr_tifs
index|[
literal|2
index|]
decl_stmt|;
comment|/* "to"/"reply-to" interface */
name|frdest_t
name|fr_dif
decl_stmt|;
comment|/* duplicate packet interface */
comment|/* 	 * This must be last and will change after loaded into the kernel. 	 */
name|u_int
name|fr_cksum
decl_stmt|;
comment|/* checksum on filter rules for performance */
block|}
name|frentry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fr_caddr
value|fr_dun.fru_caddr
end_define

begin_define
define|#
directive|define
name|fr_data
value|fr_dun.fru_data
end_define

begin_define
define|#
directive|define
name|fr_dfunc
value|fr_dun.fru_func
end_define

begin_define
define|#
directive|define
name|fr_ipf
value|fr_dun.fru_ipf
end_define

begin_define
define|#
directive|define
name|fr_ip
value|fr_ipf->fri_ip
end_define

begin_define
define|#
directive|define
name|fr_mip
value|fr_ipf->fri_mip
end_define

begin_define
define|#
directive|define
name|fr_icmpm
value|fr_ipf->fri_icmpm
end_define

begin_define
define|#
directive|define
name|fr_icmp
value|fr_ipf->fri_icmp
end_define

begin_define
define|#
directive|define
name|fr_tuc
value|fr_ipf->fri_tuc
end_define

begin_define
define|#
directive|define
name|fr_satype
value|fr_ipf->fri_satype
end_define

begin_define
define|#
directive|define
name|fr_datype
value|fr_ipf->fri_datype
end_define

begin_define
define|#
directive|define
name|fr_sifpidx
value|fr_ipf->fri_sifpidx
end_define

begin_define
define|#
directive|define
name|fr_difpidx
value|fr_ipf->fri_difpidx
end_define

begin_define
define|#
directive|define
name|fr_proto
value|fr_ip.fi_p
end_define

begin_define
define|#
directive|define
name|fr_mproto
value|fr_mip.fi_p
end_define

begin_define
define|#
directive|define
name|fr_ttl
value|fr_ip.fi_ttl
end_define

begin_define
define|#
directive|define
name|fr_mttl
value|fr_mip.fi_ttl
end_define

begin_define
define|#
directive|define
name|fr_tos
value|fr_ip.fi_tos
end_define

begin_define
define|#
directive|define
name|fr_mtos
value|fr_mip.fi_tos
end_define

begin_define
define|#
directive|define
name|fr_tcpfm
value|fr_tuc.ftu_tcpfm
end_define

begin_define
define|#
directive|define
name|fr_tcpf
value|fr_tuc.ftu_tcpf
end_define

begin_define
define|#
directive|define
name|fr_scmp
value|fr_tuc.ftu_scmp
end_define

begin_define
define|#
directive|define
name|fr_dcmp
value|fr_tuc.ftu_dcmp
end_define

begin_define
define|#
directive|define
name|fr_dport
value|fr_tuc.ftu_dport
end_define

begin_define
define|#
directive|define
name|fr_sport
value|fr_tuc.ftu_sport
end_define

begin_define
define|#
directive|define
name|fr_stop
value|fr_tuc.ftu_stop
end_define

begin_define
define|#
directive|define
name|fr_dtop
value|fr_tuc.ftu_dtop
end_define

begin_define
define|#
directive|define
name|fr_dst
value|fr_ip.fi_dst.in4
end_define

begin_define
define|#
directive|define
name|fr_daddr
value|fr_ip.fi_dst.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fr_src
value|fr_ip.fi_src.in4
end_define

begin_define
define|#
directive|define
name|fr_saddr
value|fr_ip.fi_src.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fr_dmsk
value|fr_mip.fi_dst.in4
end_define

begin_define
define|#
directive|define
name|fr_dmask
value|fr_mip.fi_dst.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fr_smsk
value|fr_mip.fi_src.in4
end_define

begin_define
define|#
directive|define
name|fr_smask
value|fr_mip.fi_src.in4.s_addr
end_define

begin_define
define|#
directive|define
name|fr_dstnum
value|fr_ip.fi_dstnum
end_define

begin_define
define|#
directive|define
name|fr_srcnum
value|fr_ip.fi_srcnum
end_define

begin_define
define|#
directive|define
name|fr_dsttype
value|fr_ip.fi_dsttype
end_define

begin_define
define|#
directive|define
name|fr_srctype
value|fr_ip.fi_srctype
end_define

begin_define
define|#
directive|define
name|fr_dstptr
value|fr_mip.fi_dstptr
end_define

begin_define
define|#
directive|define
name|fr_srcptr
value|fr_mip.fi_srcptr
end_define

begin_define
define|#
directive|define
name|fr_dstfunc
value|fr_mip.fi_dstfunc
end_define

begin_define
define|#
directive|define
name|fr_srcfunc
value|fr_mip.fi_srcfunc
end_define

begin_define
define|#
directive|define
name|fr_optbits
value|fr_ip.fi_optmsk
end_define

begin_define
define|#
directive|define
name|fr_optmask
value|fr_mip.fi_optmsk
end_define

begin_define
define|#
directive|define
name|fr_secbits
value|fr_ip.fi_secmsk
end_define

begin_define
define|#
directive|define
name|fr_secmask
value|fr_mip.fi_secmsk
end_define

begin_define
define|#
directive|define
name|fr_authbits
value|fr_ip.fi_auth
end_define

begin_define
define|#
directive|define
name|fr_authmask
value|fr_mip.fi_auth
end_define

begin_define
define|#
directive|define
name|fr_flx
value|fr_ip.fi_flx
end_define

begin_define
define|#
directive|define
name|fr_mflx
value|fr_mip.fi_flx
end_define

begin_define
define|#
directive|define
name|fr_ifname
value|fr_ifnames[0]
end_define

begin_define
define|#
directive|define
name|fr_oifname
value|fr_ifnames[2]
end_define

begin_define
define|#
directive|define
name|fr_ifa
value|fr_ifas[0]
end_define

begin_define
define|#
directive|define
name|fr_oifa
value|fr_ifas[2]
end_define

begin_define
define|#
directive|define
name|fr_tif
value|fr_tifs[0]
end_define

begin_define
define|#
directive|define
name|fr_rif
value|fr_tifs[1]
end_define

begin_define
define|#
directive|define
name|FR_NOLOGTAG
value|0
end_define

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

begin_define
define|#
directive|define
name|FR_CMPSIZ
value|(sizeof(struct frentry) - \ 			 offsetof(struct frentry, fr_func))
end_define

begin_comment
comment|/*  * fr_type  */
end_comment

begin_define
define|#
directive|define
name|FR_T_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FR_T_IPF
value|1
end_define

begin_comment
comment|/* IPF structures */
end_comment

begin_define
define|#
directive|define
name|FR_T_BPFOPC
value|2
end_define

begin_comment
comment|/* BPF opcode */
end_comment

begin_define
define|#
directive|define
name|FR_T_CALLFUNC
value|3
end_define

begin_comment
comment|/* callout to function in fr_func only */
end_comment

begin_define
define|#
directive|define
name|FR_T_COMPIPF
value|4
end_define

begin_comment
comment|/* compiled C code */
end_comment

begin_define
define|#
directive|define
name|FR_T_BUILTIN
value|0x80000000
end_define

begin_comment
comment|/* rule is in kernel space */
end_comment

begin_comment
comment|/*  * fr_flags  */
end_comment

begin_define
define|#
directive|define
name|FR_CALL
value|0x00000
end_define

begin_comment
comment|/* call rule */
end_comment

begin_define
define|#
directive|define
name|FR_BLOCK
value|0x00001
end_define

begin_comment
comment|/* do not allow packet to pass */
end_comment

begin_define
define|#
directive|define
name|FR_PASS
value|0x00002
end_define

begin_comment
comment|/* allow packet to pass */
end_comment

begin_define
define|#
directive|define
name|FR_AUTH
value|0x00003
end_define

begin_comment
comment|/* use authentication */
end_comment

begin_define
define|#
directive|define
name|FR_PREAUTH
value|0x00004
end_define

begin_comment
comment|/* require preauthentication */
end_comment

begin_define
define|#
directive|define
name|FR_ACCOUNT
value|0x00005
end_define

begin_comment
comment|/* Accounting rule */
end_comment

begin_define
define|#
directive|define
name|FR_SKIP
value|0x00006
end_define

begin_comment
comment|/* skip rule */
end_comment

begin_define
define|#
directive|define
name|FR_DIVERT
value|0x00007
end_define

begin_comment
comment|/* divert rule */
end_comment

begin_define
define|#
directive|define
name|FR_CMDMASK
value|0x0000f
end_define

begin_define
define|#
directive|define
name|FR_LOG
value|0x00010
end_define

begin_comment
comment|/* Log */
end_comment

begin_define
define|#
directive|define
name|FR_LOGB
value|0x00011
end_define

begin_comment
comment|/* Log-fail */
end_comment

begin_define
define|#
directive|define
name|FR_LOGP
value|0x00012
end_define

begin_comment
comment|/* Log-pass */
end_comment

begin_define
define|#
directive|define
name|FR_LOGMASK
value|(FR_LOG|FR_CMDMASK)
end_define

begin_define
define|#
directive|define
name|FR_CALLNOW
value|0x00020
end_define

begin_comment
comment|/* call another function (fr_func) if matches */
end_comment

begin_define
define|#
directive|define
name|FR_NOTSRCIP
value|0x00040
end_define

begin_define
define|#
directive|define
name|FR_NOTDSTIP
value|0x00080
end_define

begin_define
define|#
directive|define
name|FR_QUICK
value|0x00100
end_define

begin_comment
comment|/* match& stop processing list */
end_comment

begin_define
define|#
directive|define
name|FR_KEEPFRAG
value|0x00200
end_define

begin_comment
comment|/* keep fragment information */
end_comment

begin_define
define|#
directive|define
name|FR_KEEPSTATE
value|0x00400
end_define

begin_comment
comment|/* keep `connection' state information */
end_comment

begin_define
define|#
directive|define
name|FR_FASTROUTE
value|0x00800
end_define

begin_comment
comment|/* bypass normal routing */
end_comment

begin_define
define|#
directive|define
name|FR_RETRST
value|0x01000
end_define

begin_comment
comment|/* Return TCP RST packet - reset connection */
end_comment

begin_define
define|#
directive|define
name|FR_RETICMP
value|0x02000
end_define

begin_comment
comment|/* Return ICMP unreachable packet */
end_comment

begin_define
define|#
directive|define
name|FR_FAKEICMP
value|0x03000
end_define

begin_comment
comment|/* Return ICMP unreachable with fake source */
end_comment

begin_define
define|#
directive|define
name|FR_OUTQUE
value|0x04000
end_define

begin_comment
comment|/* outgoing packets */
end_comment

begin_define
define|#
directive|define
name|FR_INQUE
value|0x08000
end_define

begin_comment
comment|/* ingoing packets */
end_comment

begin_define
define|#
directive|define
name|FR_LOGBODY
value|0x10000
end_define

begin_comment
comment|/* Log the body */
end_comment

begin_define
define|#
directive|define
name|FR_LOGFIRST
value|0x20000
end_define

begin_comment
comment|/* Log the first byte if state held */
end_comment

begin_define
define|#
directive|define
name|FR_LOGORBLOCK
value|0x40000
end_define

begin_comment
comment|/* block the packet if it can't be logged */
end_comment

begin_define
define|#
directive|define
name|FR_DUP
value|0x80000
end_define

begin_comment
comment|/* duplicate packet */
end_comment

begin_define
define|#
directive|define
name|FR_FRSTRICT
value|0x100000
end_define

begin_comment
comment|/* strict frag. cache */
end_comment

begin_define
define|#
directive|define
name|FR_STSTRICT
value|0x200000
end_define

begin_comment
comment|/* strict keep state */
end_comment

begin_define
define|#
directive|define
name|FR_NEWISN
value|0x400000
end_define

begin_comment
comment|/* new ISN for outgoing TCP */
end_comment

begin_define
define|#
directive|define
name|FR_NOICMPERR
value|0x800000
end_define

begin_comment
comment|/* do not match ICMP errors in state */
end_comment

begin_define
define|#
directive|define
name|FR_STATESYNC
value|0x1000000
end_define

begin_comment
comment|/* synchronize state to slave */
end_comment

begin_define
define|#
directive|define
name|FR_NOMATCH
value|0x8000000
end_define

begin_comment
comment|/* no match occured */
end_comment

begin_comment
comment|/*	0x10000000 	FF_LOGPASS */
end_comment

begin_comment
comment|/*	0x20000000 	FF_LOGBLOCK */
end_comment

begin_comment
comment|/*	0x40000000 	FF_LOGNOMATCH */
end_comment

begin_comment
comment|/*	0x80000000 	FF_BLOCKNONIP */
end_comment

begin_define
define|#
directive|define
name|FR_COPIED
value|0x40000000
end_define

begin_comment
comment|/* copied from user space */
end_comment

begin_define
define|#
directive|define
name|FR_INACTIVE
value|0x80000000
end_define

begin_comment
comment|/* only used when flush'ing rules */
end_comment

begin_define
define|#
directive|define
name|FR_RETMASK
value|(FR_RETICMP|FR_RETRST|FR_FAKEICMP)
end_define

begin_define
define|#
directive|define
name|FR_ISBLOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_BLOCK)
end_define

begin_define
define|#
directive|define
name|FR_ISPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_PASS)
end_define

begin_define
define|#
directive|define
name|FR_ISAUTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_AUTH)
end_define

begin_define
define|#
directive|define
name|FR_ISPREAUTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_PREAUTH)
end_define

begin_define
define|#
directive|define
name|FR_ISACCOUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_ACCOUNT)
end_define

begin_define
define|#
directive|define
name|FR_ISSKIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& FR_CMDMASK) == FR_SKIP)
end_define

begin_define
define|#
directive|define
name|FR_ISNOMATCH
parameter_list|(
name|x
parameter_list|)
value|((x)& FR_NOMATCH)
end_define

begin_define
define|#
directive|define
name|FR_INOUT
value|(FR_INQUE|FR_OUTQUE)
end_define

begin_comment
comment|/*  * recognized flags for SIOCGETFF and SIOCSETFF, and get put in fr_flags  */
end_comment

begin_define
define|#
directive|define
name|FF_LOGPASS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FF_LOGBLOCK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FF_LOGNOMATCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FF_LOGGING
value|(FF_LOGPASS|FF_LOGBLOCK|FF_LOGNOMATCH)
end_define

begin_define
define|#
directive|define
name|FF_BLOCKNONIP
value|0x80000000
end_define

begin_comment
comment|/* Solaris2 Only */
end_comment

begin_comment
comment|/*  * Structure that passes information on what/how to flush to the kernel.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipfflush
block|{
name|int
name|ipflu_how
decl_stmt|;
name|int
name|ipflu_arg
decl_stmt|;
block|}
name|ipfflush_t
typedef|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipfgetctl
block|{
name|u_int
name|ipfg_min
decl_stmt|;
comment|/* min value */
name|u_int
name|ipfg_current
decl_stmt|;
comment|/* current value */
name|u_int
name|ipfg_max
decl_stmt|;
comment|/* max value */
name|u_int
name|ipfg_default
decl_stmt|;
comment|/* default value */
name|u_int
name|ipfg_steps
decl_stmt|;
comment|/* value increments */
name|char
name|ipfg_name
index|[
literal|40
index|]
decl_stmt|;
comment|/* tag name for this control */
block|}
name|ipfgetctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipfsetctl
block|{
name|int
name|ipfs_which
decl_stmt|;
comment|/* 0 = min 1 = current 2 = max 3 = default */
name|u_int
name|ipfs_value
decl_stmt|;
comment|/* min value */
name|char
name|ipfs_name
index|[
literal|40
index|]
decl_stmt|;
comment|/* tag name for this control */
block|}
name|ipfsetctl_t
typedef|;
end_typedef

begin_comment
comment|/*  * Some of the statistics below are in their own counters, but most are kept  * in this single structure so that they can all easily be collected and  * copied back as required.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|filterstats
block|{
name|u_long
name|fr_pass
decl_stmt|;
comment|/* packets allowed */
name|u_long
name|fr_block
decl_stmt|;
comment|/* packets denied */
name|u_long
name|fr_nom
decl_stmt|;
comment|/* packets which don't match any rule */
name|u_long
name|fr_short
decl_stmt|;
comment|/* packets which are short */
name|u_long
name|fr_ppkl
decl_stmt|;
comment|/* packets allowed and logged */
name|u_long
name|fr_bpkl
decl_stmt|;
comment|/* packets denied and logged */
name|u_long
name|fr_npkl
decl_stmt|;
comment|/* packets unmatched and logged */
name|u_long
name|fr_pkl
decl_stmt|;
comment|/* packets logged */
name|u_long
name|fr_skip
decl_stmt|;
comment|/* packets to be logged but buffer full */
name|u_long
name|fr_ret
decl_stmt|;
comment|/* packets for which a return is sent */
name|u_long
name|fr_acct
decl_stmt|;
comment|/* packets for which counting was performed */
name|u_long
name|fr_bnfr
decl_stmt|;
comment|/* bad attempts to allocate fragment state */
name|u_long
name|fr_nfr
decl_stmt|;
comment|/* new fragment state kept */
name|u_long
name|fr_cfr
decl_stmt|;
comment|/* add new fragment state but complete pkt */
name|u_long
name|fr_bads
decl_stmt|;
comment|/* bad attempts to allocate packet state */
name|u_long
name|fr_ads
decl_stmt|;
comment|/* new packet state kept */
name|u_long
name|fr_chit
decl_stmt|;
comment|/* cached hit */
name|u_long
name|fr_tcpbad
decl_stmt|;
comment|/* TCP checksum check failures */
name|u_long
name|fr_pull
index|[
literal|2
index|]
decl_stmt|;
comment|/* good and bad pullup attempts */
name|u_long
name|fr_badsrc
decl_stmt|;
comment|/* source received doesn't match route */
name|u_long
name|fr_badttl
decl_stmt|;
comment|/* TTL in packet doesn't reach minimum */
name|u_long
name|fr_bad
decl_stmt|;
comment|/* bad IP packets to the filter */
name|u_long
name|fr_ipv6
decl_stmt|;
comment|/* IPv6 packets in/out */
name|u_long
name|fr_ppshit
decl_stmt|;
comment|/* dropped because of pps ceiling */
name|u_long
name|fr_ipud
decl_stmt|;
comment|/* IP id update failures */
block|}
name|filterstats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Log structure.  Each packet header logged is prepended by one of these.  * Following this in the log records read from the device will be an ipflog  * structure which is then followed by any packet data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|iplog
block|{
name|u_32_t
name|ipl_magic
decl_stmt|;
name|u_int
name|ipl_count
decl_stmt|;
name|struct
name|timeval
name|ipl_time
decl_stmt|;
name|size_t
name|ipl_dsize
decl_stmt|;
name|struct
name|iplog
modifier|*
name|ipl_next
decl_stmt|;
block|}
name|iplog_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipl_sec
value|ipl_time.tv_sec
end_define

begin_define
define|#
directive|define
name|ipl_usec
value|ipl_time.tv_usec
end_define

begin_define
define|#
directive|define
name|IPL_MAGIC
value|0x49504c4d
end_define

begin_comment
comment|/* 'IPLM' */
end_comment

begin_define
define|#
directive|define
name|IPL_MAGIC_NAT
value|0x49504c4e
end_define

begin_comment
comment|/* 'IPLN' */
end_comment

begin_define
define|#
directive|define
name|IPL_MAGIC_STATE
value|0x49504c53
end_define

begin_comment
comment|/* 'IPLS' */
end_comment

begin_define
define|#
directive|define
name|IPLOG_SIZE
value|sizeof(iplog_t)
end_define

begin_typedef
typedef|typedef
struct|struct
name|ipflog
block|{
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
literal|199603
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
else|#
directive|else
name|u_int
name|fl_unit
decl_stmt|;
endif|#
directive|endif
name|u_32_t
name|fl_rule
decl_stmt|;
name|u_32_t
name|fl_flags
decl_stmt|;
name|u_32_t
name|fl_lflags
decl_stmt|;
name|u_32_t
name|fl_logtag
decl_stmt|;
name|ipftag_t
name|fl_nattag
decl_stmt|;
name|u_short
name|fl_plen
decl_stmt|;
comment|/* extra data after hlen */
name|u_short
name|fl_loglevel
decl_stmt|;
comment|/* syslog log level */
name|char
name|fl_group
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
name|u_char
name|fl_hlen
decl_stmt|;
comment|/* length of IP headers saved */
name|u_char
name|fl_dir
decl_stmt|;
name|u_char
name|fl_xxx
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad */
name|char
name|fl_ifname
index|[
name|LIFNAMSIZ
index|]
decl_stmt|;
block|}
name|ipflog_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|IPF_LOGGING
end_ifndef

begin_define
define|#
directive|define
name|IPF_LOGGING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPF_DEFAULT_PASS
end_ifndef

begin_define
define|#
directive|define
name|IPF_DEFAULT_PASS
value|FR_PASS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_IPFLOGSIZE
value|8192
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IPFILTER_LOGSIZE
end_ifndef

begin_define
define|#
directive|define
name|IPFILTER_LOGSIZE
value|DEFAULT_IPFLOGSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|IPFILTER_LOGSIZE
operator|<
name|DEFAULT_IPFLOGSIZE
end_if

begin_error
error|#
directive|error
error|IPFILTER_LOGSIZE too small.  Must be>= DEFAULT_IPFLOGSIZE
end_error

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
name|IPF_OPTCOPY
value|0x07ff00
end_define

begin_comment
comment|/* bit mask of copied options */
end_comment

begin_comment
comment|/*  * Device filenames for reading log information.  Use ipf on Solaris2 because  * ipl is already a name used by something else.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPL_NAME
end_ifndef

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_define
define|#
directive|define
name|IPL_NAME
value|"/dev/ipf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPL_NAME
value|"/dev/ipl"
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
comment|/*  * Pathnames for various IP Filter control devices.  Used by LKM  * and userland, so defined here.  */
end_comment

begin_define
define|#
directive|define
name|IPNAT_NAME
value|"/dev/ipnat"
end_define

begin_define
define|#
directive|define
name|IPSTATE_NAME
value|"/dev/ipstate"
end_define

begin_define
define|#
directive|define
name|IPAUTH_NAME
value|"/dev/ipauth"
end_define

begin_define
define|#
directive|define
name|IPSYNC_NAME
value|"/dev/ipsync"
end_define

begin_define
define|#
directive|define
name|IPSCAN_NAME
value|"/dev/ipscan"
end_define

begin_define
define|#
directive|define
name|IPLOOKUP_NAME
value|"/dev/iplookup"
end_define

begin_define
define|#
directive|define
name|IPL_LOGIPF
value|0
end_define

begin_comment
comment|/* Minor device #'s for accessing logs */
end_comment

begin_define
define|#
directive|define
name|IPL_LOGNAT
value|1
end_define

begin_define
define|#
directive|define
name|IPL_LOGSTATE
value|2
end_define

begin_define
define|#
directive|define
name|IPL_LOGAUTH
value|3
end_define

begin_define
define|#
directive|define
name|IPL_LOGSYNC
value|4
end_define

begin_define
define|#
directive|define
name|IPL_LOGSCAN
value|5
end_define

begin_define
define|#
directive|define
name|IPL_LOGLOOKUP
value|6
end_define

begin_define
define|#
directive|define
name|IPL_LOGCOUNT
value|7
end_define

begin_define
define|#
directive|define
name|IPL_LOGMAX
value|7
end_define

begin_define
define|#
directive|define
name|IPL_LOGSIZE
value|IPL_LOGMAX + 1
end_define

begin_define
define|#
directive|define
name|IPL_LOGALL
value|-1
end_define

begin_define
define|#
directive|define
name|IPL_LOGNONE
value|-2
end_define

begin_comment
comment|/*  * For SIOCGETFS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|friostat
block|{
name|struct
name|filterstats
name|f_st
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_ipf
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_acct
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_ipf6
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_acct6
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|frentry
modifier|*
name|f_auth
decl_stmt|;
name|struct
name|frgroup
modifier|*
name|f_groups
index|[
name|IPL_LOGSIZE
index|]
index|[
literal|2
index|]
decl_stmt|;
name|u_long
name|f_froute
index|[
literal|2
index|]
decl_stmt|;
name|u_long
name|f_ticks
decl_stmt|;
name|int
name|f_locks
index|[
name|IPL_LOGMAX
index|]
decl_stmt|;
name|size_t
name|f_kmutex_sz
decl_stmt|;
name|size_t
name|f_krwlock_sz
decl_stmt|;
name|int
name|f_defpass
decl_stmt|;
comment|/* default pass - from fr_pass */
name|int
name|f_active
decl_stmt|;
comment|/* 1 or 0 - active rule set */
name|int
name|f_running
decl_stmt|;
comment|/* 1 if running, else 0 */
name|int
name|f_logging
decl_stmt|;
comment|/* 1 if enabled, else 0 */
name|int
name|f_features
decl_stmt|;
name|char
name|f_version
index|[
literal|32
index|]
decl_stmt|;
comment|/* version string */
block|}
name|friostat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|f_fin
value|f_ipf[0]
end_define

begin_define
define|#
directive|define
name|f_fin6
value|f_ipf6[0]
end_define

begin_define
define|#
directive|define
name|f_fout
value|f_ipf[1]
end_define

begin_define
define|#
directive|define
name|f_fout6
value|f_ipf6[1]
end_define

begin_define
define|#
directive|define
name|f_acctin
value|f_acct[0]
end_define

begin_define
define|#
directive|define
name|f_acctin6
value|f_acct6[0]
end_define

begin_define
define|#
directive|define
name|f_acctout
value|f_acct[1]
end_define

begin_define
define|#
directive|define
name|f_acctout6
value|f_acct6[1]
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_LKM
value|0x001
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_LOG
value|0x002
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_LOOKUP
value|0x004
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_BPF
value|0x008
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_COMPILED
value|0x010
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_CKSUM
value|0x020
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_SYNC
value|0x040
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_SCAN
value|0x080
end_define

begin_define
define|#
directive|define
name|IPF_FEAT_IPV6
value|0x100
end_define

begin_typedef
typedef|typedef
struct|struct
name|optlist
block|{
name|u_short
name|ol_val
decl_stmt|;
name|int
name|ol_bit
decl_stmt|;
block|}
name|optlist_t
typedef|;
end_typedef

begin_comment
comment|/*  * Group list structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|frgroup
block|{
name|struct
name|frgroup
modifier|*
name|fg_next
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fg_head
decl_stmt|;
name|struct
name|frentry
modifier|*
name|fg_start
decl_stmt|;
name|u_32_t
name|fg_flags
decl_stmt|;
name|int
name|fg_ref
decl_stmt|;
name|char
name|fg_name
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
block|}
name|frgroup_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FG_NAME
parameter_list|(
name|g
parameter_list|)
value|(*(g)->fg_name == '\0' ? "" : (g)->fg_name)
end_define

begin_comment
comment|/*  * Used by state and NAT tables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|icmpinfo
block|{
name|u_short
name|ici_id
decl_stmt|;
name|u_short
name|ici_seq
decl_stmt|;
name|u_char
name|ici_type
decl_stmt|;
block|}
name|icmpinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|udpinfo
block|{
name|u_short
name|us_sport
decl_stmt|;
name|u_short
name|us_dport
decl_stmt|;
block|}
name|udpinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tcpdata
block|{
name|u_32_t
name|td_end
decl_stmt|;
name|u_32_t
name|td_maxend
decl_stmt|;
name|u_32_t
name|td_maxwin
decl_stmt|;
name|u_32_t
name|td_winscale
decl_stmt|;
name|u_32_t
name|td_maxseg
decl_stmt|;
name|int
name|td_winflags
decl_stmt|;
block|}
name|tcpdata_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCP_WSCALE_MAX
value|14
end_define

begin_define
define|#
directive|define
name|TCP_WSCALE_SEEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TCP_WSCALE_FIRST
value|0x00000002
end_define

begin_typedef
typedef|typedef
struct|struct
name|tcpinfo
block|{
name|u_short
name|ts_sport
decl_stmt|;
name|u_short
name|ts_dport
decl_stmt|;
name|tcpdata_t
name|ts_data
index|[
literal|2
index|]
decl_stmt|;
block|}
name|tcpinfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|grebits
block|{
name|u_32_t
name|grb_C
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_R
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_K
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_S
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_s
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_recur
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_A
range|:
literal|1
decl_stmt|;
name|u_32_t
name|grb_flags
range|:
literal|3
decl_stmt|;
name|u_32_t
name|grb_ver
range|:
literal|3
decl_stmt|;
name|u_short
name|grb_ptype
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|grehdr
block|{
union|union
block|{
name|struct
name|grebits
name|gru_bits
decl_stmt|;
name|u_short
name|gru_flags
decl_stmt|;
block|}
name|gr_un
union|;
name|u_short
name|gr_len
decl_stmt|;
name|u_short
name|gr_call
decl_stmt|;
block|}
name|grehdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|gr_flags
value|gr_un.gru_flags
end_define

begin_define
define|#
directive|define
name|gr_bits
value|gr_un.gru_bits
end_define

begin_define
define|#
directive|define
name|gr_ptype
value|gr_bits.grb_ptype
end_define

begin_define
define|#
directive|define
name|gr_C
value|gr_bits.grb_C
end_define

begin_define
define|#
directive|define
name|gr_R
value|gr_bits.grb_R
end_define

begin_define
define|#
directive|define
name|gr_K
value|gr_bits.grb_K
end_define

begin_define
define|#
directive|define
name|gr_S
value|gr_bits.grb_S
end_define

begin_define
define|#
directive|define
name|gr_s
value|gr_bits.grb_s
end_define

begin_define
define|#
directive|define
name|gr_recur
value|gr_bits.grb_recur
end_define

begin_define
define|#
directive|define
name|gr_A
value|gr_bits.grb_A
end_define

begin_define
define|#
directive|define
name|gr_ver
value|gr_bits.grb_ver
end_define

begin_typedef
typedef|typedef
struct|struct
name|greinfo
block|{
name|u_short
name|gs_call
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|gs_flags
decl_stmt|;
name|u_short
name|gs_ptype
decl_stmt|;
block|}
name|greinfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GRE_REV
parameter_list|(
name|x
parameter_list|)
value|((ntohs(x)>> 13)& 7)
end_define

begin_comment
comment|/*  * Timeout tail queue list member  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipftqent
block|{
name|struct
name|ipftqent
modifier|*
modifier|*
name|tqe_pnext
decl_stmt|;
name|struct
name|ipftqent
modifier|*
name|tqe_next
decl_stmt|;
name|struct
name|ipftq
modifier|*
name|tqe_ifq
decl_stmt|;
name|void
modifier|*
name|tqe_parent
decl_stmt|;
comment|/* pointer back to NAT/state struct */
name|u_long
name|tqe_die
decl_stmt|;
comment|/* when this entriy is to die */
name|u_long
name|tqe_touched
decl_stmt|;
name|int
name|tqe_flags
decl_stmt|;
name|int
name|tqe_state
index|[
literal|2
index|]
decl_stmt|;
comment|/* current state of this entry */
block|}
name|ipftqent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TQE_RULEBASED
value|0x00000001
end_define

begin_comment
comment|/*  * Timeout tail queue head for IPFilter  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipftq
block|{
name|ipfmutex_t
name|ifq_lock
decl_stmt|;
name|u_int
name|ifq_ttl
decl_stmt|;
name|ipftqent_t
modifier|*
name|ifq_head
decl_stmt|;
name|ipftqent_t
modifier|*
modifier|*
name|ifq_tail
decl_stmt|;
name|struct
name|ipftq
modifier|*
name|ifq_next
decl_stmt|;
name|struct
name|ipftq
modifier|*
modifier|*
name|ifq_pnext
decl_stmt|;
name|int
name|ifq_ref
decl_stmt|;
name|u_int
name|ifq_flags
decl_stmt|;
block|}
name|ipftq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IFQF_USER
value|0x01
end_define

begin_comment
comment|/* User defined aging */
end_comment

begin_define
define|#
directive|define
name|IFQF_DELETE
value|0x02
end_define

begin_comment
comment|/* Marked for deletion */
end_comment

begin_define
define|#
directive|define
name|IFQF_PROXY
value|0x04
end_define

begin_comment
comment|/* Timeout queue in use by a proxy */
end_comment

begin_define
define|#
directive|define
name|IPF_HZ_MULT
value|1
end_define

begin_define
define|#
directive|define
name|IPF_HZ_DIVIDE
value|2
end_define

begin_comment
comment|/* How many times a second ipfilter */
end_comment

begin_comment
comment|/* checks its timeout queues.       */
end_comment

begin_define
define|#
directive|define
name|IPF_TTLVAL
parameter_list|(
name|x
parameter_list|)
value|(((x) / IPF_HZ_MULT) * IPF_HZ_DIVIDE)
end_define

begin_comment
comment|/*  * Structure to define address for pool lookups.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|adf_len
decl_stmt|;
name|i6addr_t
name|adf_addr
decl_stmt|;
block|}
name|addrfamily_t
typedef|;
end_typedef

begin_comment
comment|/*  * Object structure description.  For passing through in ioctls.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipfobj
block|{
name|u_32_t
name|ipfo_rev
decl_stmt|;
comment|/* IPFilter version number */
name|u_32_t
name|ipfo_size
decl_stmt|;
comment|/* size of object at ipfo_ptr */
name|void
modifier|*
name|ipfo_ptr
decl_stmt|;
comment|/* pointer to object */
name|int
name|ipfo_type
decl_stmt|;
comment|/* type of object being pointed to */
name|int
name|ipfo_offset
decl_stmt|;
comment|/* bytes from ipfo_ptr where to start */
name|u_char
name|ipfo_xxxpad
index|[
literal|32
index|]
decl_stmt|;
comment|/* reserved for future use */
block|}
name|ipfobj_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPFOBJ_FRENTRY
value|0
end_define

begin_comment
comment|/* struct frentry */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_IPFSTAT
value|1
end_define

begin_comment
comment|/* struct friostat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_IPFINFO
value|2
end_define

begin_comment
comment|/* struct fr_info */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_AUTHSTAT
value|3
end_define

begin_comment
comment|/* struct fr_authstat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_FRAGSTAT
value|4
end_define

begin_comment
comment|/* struct ipfrstat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_IPNAT
value|5
end_define

begin_comment
comment|/* struct ipnat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_NATSTAT
value|6
end_define

begin_comment
comment|/* struct natstat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_STATESAVE
value|7
end_define

begin_comment
comment|/* struct ipstate_save */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_NATSAVE
value|8
end_define

begin_comment
comment|/* struct nat_save */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_NATLOOKUP
value|9
end_define

begin_comment
comment|/* struct natlookup */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_IPSTATE
value|10
end_define

begin_comment
comment|/* struct ipstate */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_STATESTAT
value|11
end_define

begin_comment
comment|/* struct ips_stat */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_FRAUTH
value|12
end_define

begin_comment
comment|/* struct frauth */
end_comment

begin_define
define|#
directive|define
name|IPFOBJ_TUNEABLE
value|13
end_define

begin_comment
comment|/* struct ipftune */
end_comment

begin_typedef
typedef|typedef
union|union
name|ipftunevalptr
block|{
name|void
modifier|*
name|ipftp_void
decl_stmt|;
name|u_long
modifier|*
name|ipftp_long
decl_stmt|;
name|u_int
modifier|*
name|ipftp_int
decl_stmt|;
name|u_short
modifier|*
name|ipftp_short
decl_stmt|;
name|u_char
modifier|*
name|ipftp_char
decl_stmt|;
block|}
name|ipftunevalptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipftuneable
block|{
name|ipftunevalptr_t
name|ipft_una
decl_stmt|;
name|char
modifier|*
name|ipft_name
decl_stmt|;
name|u_long
name|ipft_min
decl_stmt|;
name|u_long
name|ipft_max
decl_stmt|;
name|int
name|ipft_sz
decl_stmt|;
name|int
name|ipft_flags
decl_stmt|;
name|struct
name|ipftuneable
modifier|*
name|ipft_next
decl_stmt|;
block|}
name|ipftuneable_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipft_addr
value|ipft_una.ipftp_void
end_define

begin_define
define|#
directive|define
name|ipft_plong
value|ipft_una.ipftp_long
end_define

begin_define
define|#
directive|define
name|ipft_pint
value|ipft_una.ipftp_int
end_define

begin_define
define|#
directive|define
name|ipft_pshort
value|ipft_una.ipftp_short
end_define

begin_define
define|#
directive|define
name|ipft_pchar
value|ipft_una.ipftp_char
end_define

begin_define
define|#
directive|define
name|IPFT_RDONLY
value|1
end_define

begin_comment
comment|/* read-only */
end_comment

begin_define
define|#
directive|define
name|IPFT_WRDISABLED
value|2
end_define

begin_comment
comment|/* write when disabled only */
end_comment

begin_typedef
typedef|typedef
union|union
name|ipftuneval
block|{
name|u_long
name|ipftu_long
decl_stmt|;
name|u_int
name|ipftu_int
decl_stmt|;
name|u_short
name|ipftu_short
decl_stmt|;
name|u_char
name|ipftu_char
decl_stmt|;
block|}
name|ipftuneval_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ipftune
block|{
name|void
modifier|*
name|ipft_cookie
decl_stmt|;
name|ipftuneval_t
name|ipft_un
decl_stmt|;
name|u_long
name|ipft_min
decl_stmt|;
name|u_long
name|ipft_max
decl_stmt|;
name|int
name|ipft_sz
decl_stmt|;
name|int
name|ipft_flags
decl_stmt|;
name|char
name|ipft_name
index|[
literal|80
index|]
decl_stmt|;
block|}
name|ipftune_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ipft_vlong
value|ipft_un.ipftu_long
end_define

begin_define
define|#
directive|define
name|ipft_vint
value|ipft_un.ipftu_int
end_define

begin_define
define|#
directive|define
name|ipft_vshort
value|ipft_un.ipftu_short
end_define

begin_define
define|#
directive|define
name|ipft_vchar
value|ipft_un.ipftu_char
end_define

begin_comment
comment|/* ** HPUX Port */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_comment
comment|/* HP-UX locking sequence deadlock detection module lock MAJOR ID */
end_comment

begin_define
define|#
directive|define
name|IPF_SMAJ
value|0
end_define

begin_comment
comment|/* temp assignment XXX, not critical */
end_comment

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
name|CDEV_MAJOR
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
expr|\
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
end_if

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|79
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Post NetBSD 1.2 has the PFIL interface for packet filters.  This turns  * on those hooks.  We don't need any special mods in non-IP Filter code  * with this!  */
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
operator|>
literal|199609
operator|)
operator|&&
operator|(
name|NetBSD
operator|<=
literal|1991011
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|NetBSD1_2
argument_list|)
operator|&&
name|NetBSD1_2
operator|>
literal|1
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|500043
operator|)
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|NetBSD
operator|>=
literal|199905
operator|)
end_if

begin_define
define|#
directive|define
name|PFIL_HOOKS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PFIL_HOOKS
end_ifdef

begin_define
define|#
directive|define
name|NETBSD_PF
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
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|fr_check
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	int	(*fr_checkp
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipf_log
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
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
expr|\
operator|(
name|_BSDI_VERSION
operator|>=
literal|199701
operator|)
operator|||
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ioctlcmd_t
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ioctlcmd_t
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|m_freem
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* #ifndef _KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PFIL_HOOKS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|ipfilterattach
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ipl_enable
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_disable
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MENTAT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|fr_check
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|mblk_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
literal|7
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|intptr_t
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplwrite
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|,
name|cred_t
operator|*
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
name|__hpux
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|intptr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
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
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplwrite
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplselect
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ipfsync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_qout
name|__P
argument_list|(
operator|(
name|queue_t
operator|*
operator|,
name|mblk_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MENTAT */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fr_check
name|__P
argument_list|(
operator|(
expr|struct
name|ip
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	int	(*fr_checkp
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|mb_t
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|mbufchainlen
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_include
include|#
directive|include
file|<sys/cred.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplwrite
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|uio_t
operator|*
operator|,
name|cred_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfsync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipfilter_sgi_attach
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfilter_sgi_detach
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ipfilter_sgi_intfsync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_LKM
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplidentify
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|_BSDI_VERSION
operator|>=
literal|199510
operator|)
operator|||
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
operator|||
expr|\
operator|(
name|NetBSD
operator|>=
literal|199511
operator|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
operator|(
name|_BSDI_VERSION
operator|>=
literal|199701
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
operator|(
name|__FreeBSD_version
operator|>=
literal|300000
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500024
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|502116
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
expr|struct
name|cdev
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|thread
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
comment|/* __FreeBSD_version>= 502116 */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|u_long
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|proc
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
comment|/* __FreeBSD_version>= 500024 */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500024
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|502116
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
expr|struct
name|cdev
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
expr|struct
name|cdev
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|thread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|thread
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
comment|/* __FreeBSD_version>= 502116 */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|proc
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
comment|/* __FreeBSD_version>= 500024 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
expr|struct
name|file
operator|*
operator|,
name|u_int
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplclose
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplioctl
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
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

begin_comment
comment|/* (_BSDI_VERSION>= 199510) */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199306
end_if

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|502116
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
expr|struct
name|cdev
operator|*
operator|,
expr|struct
name|uio
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
name|iplwrite
name|__P
argument_list|(
operator|(
expr|struct
name|cdev
operator|*
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
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
name|iplwrite
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 502116 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|iplread
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|uio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplwrite
name|__P
argument_list|(
operator|(
name|dev_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD>= 199306 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ sgi */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MENTAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _KERNEL */
end_comment

begin_decl_stmt
specifier|extern
name|ipfmutex_t
name|ipl_mutex
decl_stmt|,
name|ipf_authmx
decl_stmt|,
name|ipf_rw
decl_stmt|,
name|ipf_hostmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfmutex_t
name|ipf_timeoutlock
decl_stmt|,
name|ipf_stinsert
decl_stmt|,
name|ipf_natio
decl_stmt|,
name|ipf_nat_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfrwlock_t
name|ipf_mutex
decl_stmt|,
name|ipf_global
decl_stmt|,
name|ip_poolrw
decl_stmt|,
name|ipf_ipidfrag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipfrwlock_t
name|ipf_frag
decl_stmt|,
name|ipf_state
decl_stmt|,
name|ipf_nat
decl_stmt|,
name|ipf_natfrag
decl_stmt|,
name|ipf_auth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memstr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
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
name|int
name|count4bits
name|__P
argument_list|(
operator|(
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frrequest
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ioctlcmd_t
operator|,
name|caddr_t
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
name|char
modifier|*
name|getifname
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

begin_decl_stmt
specifier|extern
name|int
name|iplattach
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipldetach
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|ipf_cksum
name|__P
argument_list|(
operator|(
name|u_short
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
name|copyinptr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|copyoutptr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_fastroute
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|mb_t
operator|*
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|frdest_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_inobj
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
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
name|fr_inobjsz
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
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
name|int
name|fr_ioctlswitch
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|ioctlcmd_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_ipftune
name|__P
argument_list|(
operator|(
name|ioctlcmd_t
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
name|fr_outobj
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
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
name|fr_outobjsz
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
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
name|void
modifier|*
name|fr_pullup
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_resolvedest
name|__P
argument_list|(
operator|(
expr|struct
name|frdest
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
name|fr_resolvefunc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|fr_resolvenic
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

begin_decl_stmt
specifier|extern
name|int
name|fr_send_icmp_err
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fr_info_t
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
name|fr_send_reset
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|490000
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|ppsratecheck
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|ipftq_t
modifier|*
name|fr_addtimeoutqueue
name|__P
argument_list|(
operator|(
name|ipftq_t
operator|*
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_deletequeueentry
name|__P
argument_list|(
operator|(
name|ipftqent_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_deletetimeoutqueue
name|__P
argument_list|(
operator|(
name|ipftq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_freetimeoutqueue
name|__P
argument_list|(
operator|(
name|ipftq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_movequeue
name|__P
argument_list|(
operator|(
name|ipftqent_t
operator|*
operator|,
name|ipftq_t
operator|*
operator|,
name|ipftq_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_queueappend
name|__P
argument_list|(
operator|(
name|ipftqent_t
operator|*
operator|,
name|ipftq_t
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
name|void
name|fr_queueback
name|__P
argument_list|(
operator|(
name|ipftqent_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_queuefront
name|__P
argument_list|(
operator|(
name|ipftqent_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_checkv4sum
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_checkl4sum
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_ifpfillv4addr
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_coalesce
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|fr_checkv6sum
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_ifpfillv6addr
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr_in6
operator|*
operator|,
expr|struct
name|sockaddr_in6
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|fr_addipftune
name|__P
argument_list|(
operator|(
name|ipftuneable_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_delipftune
name|__P
argument_list|(
operator|(
name|ipftuneable_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frflush
name|__P
argument_list|(
operator|(
name|minor_t
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
name|void
name|frsync
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frgroup_t
modifier|*
name|fr_addgroup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|void
operator|*
operator|,
name|u_32_t
operator|,
name|minor_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_derefrule
name|__P
argument_list|(
operator|(
name|frentry_t
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_delgroup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|minor_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frgroup_t
modifier|*
name|fr_findgroup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|minor_t
operator|,
name|int
operator|,
name|frgroup_t
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_loginit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipflog_clear
name|__P
argument_list|(
operator|(
name|minor_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipflog_read
name|__P
argument_list|(
operator|(
name|minor_t
operator|,
name|uio_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipflog
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipllog
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fr_info_t
operator|*
operator|,
name|void
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_logunload
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_acctpkt
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_copytolog
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|fr_cksum
name|__P
argument_list|(
operator|(
name|mb_t
operator|*
operator|,
name|ip_t
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_deinitialise
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_dolog
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_dstgrpmap
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_fixskip
name|__P
argument_list|(
operator|(
name|frentry_t
operator|*
operator|*
operator|,
name|frentry_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_forgetifp
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_getrulen
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_getstat
name|__P
argument_list|(
operator|(
expr|struct
name|friostat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_icmp4errortype
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
name|fr_ifpaddr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_initialise
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fr_lock
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_makefrip
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ip_t
operator|*
operator|,
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_matchtag
name|__P
argument_list|(
operator|(
name|ipftag_t
operator|*
operator|,
name|ipftag_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_matchicmpqueryreply
name|__P
argument_list|(
operator|(
name|int
operator|,
name|icmpinfo_t
operator|*
operator|,
expr|struct
name|icmp
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_32_t
name|fr_newisn
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|fr_nextipid
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_rulen
name|__P
argument_list|(
operator|(
name|int
operator|,
name|frentry_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_scanlist
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|fr_srcgrpmap
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|u_32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_tcpudpchk
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|,
name|frtuc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_verifysrc
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
name|fin
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_zerostats
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_running
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_frouteok
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_chksrc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_minttl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_refcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_control_forwarding
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fr_update_ipid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nat_logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipstate_logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_suppress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_buffer_sz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_logmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_logall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipl_logsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|fr_ticks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fr_info_t
name|frcache
index|[
literal|2
index|]
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ipfilter_version
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|iplog_t
modifier|*
modifier|*
name|iplh
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
decl_stmt|,
modifier|*
name|iplt
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iplused
index|[
name|IPL_LOGMAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frentry
modifier|*
name|ipfilter
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|,
modifier|*
name|ipacct
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_INET6
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|frentry
modifier|*
name|ipfilter6
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|,
modifier|*
name|ipacct6
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmptoicmp6types
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmptoicmp6unreach
index|[
name|ICMP_MAX_UNREACH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icmpreplytype6
index|[
name|ICMP6_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|icmpreplytype4
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frgroup
modifier|*
name|ipfgroups
index|[
name|IPL_LOGSIZE
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filterstats
name|frstats
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frentry_t
modifier|*
name|ipfrule_match
name|__P
argument_list|(
operator|(
name|fr_info_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ipf_iss_secret
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipftuneable_t
name|ipf_tuneables
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IP_FIL_H__ */
end_comment

end_unit

