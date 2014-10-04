begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_gre.h,v 1.13 2003/11/10 08:51:52 wiz Exp $ */
end_comment

begin_comment
comment|/*	 $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved  *  * This code is derived from software contributed to The NetBSD Foundation  * by Heiko W.Rupp<hwr@pilhuhn.de>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_GRE_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_GRE_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Version of the WCCP, need to be configured manually since  * header for version 2 is the same but IP payload is prepended  * with additional 4-bytes field.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WCCP_V1
init|=
literal|0
block|,
name|WCCP_V2
block|}
name|wccp_ver_t
typedef|;
end_typedef

begin_struct
struct|struct
name|gre_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|gre_softc
argument_list|)
name|sc_list
expr_stmt|;
name|int
name|gre_unit
decl_stmt|;
name|int
name|gre_flags
decl_stmt|;
name|u_int
name|gre_fibnum
decl_stmt|;
comment|/* use this fib for envelopes */
name|struct
name|in_addr
name|g_src
decl_stmt|;
comment|/* source address of gre packets */
name|struct
name|in_addr
name|g_dst
decl_stmt|;
comment|/* destination address of gre packets */
name|struct
name|route
name|route
decl_stmt|;
comment|/* routing entry that determines, where a 				   encapsulated packet should go */
name|u_char
name|g_proto
decl_stmt|;
comment|/* protocol of encapsulator */
specifier|const
name|struct
name|encaptab
modifier|*
name|encap
decl_stmt|;
comment|/* encapsulation cookie */
name|uint32_t
name|key
decl_stmt|;
comment|/* key included in outgoing GRE packets */
comment|/* zero means none */
name|wccp_ver_t
name|wccp_ver
decl_stmt|;
comment|/* version of the WCCP */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GRE2IFP
parameter_list|(
name|sc
parameter_list|)
value|((sc)->sc_ifp)
end_define

begin_struct
struct|struct
name|gre_h
block|{
name|u_int16_t
name|flags
decl_stmt|;
comment|/* GRE flags */
name|u_int16_t
name|ptype
decl_stmt|;
comment|/* protocol type of payload typically 				   Ether protocol type*/
name|uint32_t
name|options
index|[
literal|0
index|]
decl_stmt|;
comment|/* optional options */
comment|/*  *  from here on: fields are optional, presence indicated by flags  * 	u_int_16 checksum	checksum (one-complements of GRE header 				and payload 				Present if (ck_pres | rt_pres == 1). 				Valid if (ck_pres == 1). 	u_int_16 offset		offset from start of routing filed to 				first octet of active SRE (see below). 				Present if (ck_pres | rt_pres == 1). 				Valid if (rt_pres == 1). 	u_int_32 key		inserted by encapsulator e.g. for 				authentication 				Present if (key_pres ==1 ). 	u_int_32 seq_num	Sequence number to allow for packet order 				Present if (seq_pres ==1 ). 	struct gre_sre[] routing Routing fileds (see below) 				Present if (rt_pres == 1)  */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|greip
block|{
name|struct
name|ip
name|gi_i
decl_stmt|;
name|struct
name|gre_h
name|gi_g
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|gi_pr
value|gi_i.ip_p
end_define

begin_define
define|#
directive|define
name|gi_len
value|gi_i.ip_len
end_define

begin_define
define|#
directive|define
name|gi_src
value|gi_i.ip_src
end_define

begin_define
define|#
directive|define
name|gi_dst
value|gi_i.ip_dst
end_define

begin_define
define|#
directive|define
name|gi_ptype
value|gi_g.ptype
end_define

begin_define
define|#
directive|define
name|gi_flags
value|gi_g.flags
end_define

begin_define
define|#
directive|define
name|gi_options
value|gi_g.options
end_define

begin_define
define|#
directive|define
name|GRE_CP
value|0x8000
end_define

begin_comment
comment|/* Checksum Present */
end_comment

begin_define
define|#
directive|define
name|GRE_RP
value|0x4000
end_define

begin_comment
comment|/* Routing Present */
end_comment

begin_define
define|#
directive|define
name|GRE_KP
value|0x2000
end_define

begin_comment
comment|/* Key Present */
end_comment

begin_define
define|#
directive|define
name|GRE_SP
value|0x1000
end_define

begin_comment
comment|/* Sequence Present */
end_comment

begin_define
define|#
directive|define
name|GRE_SS
value|0x0800
end_define

begin_comment
comment|/* Strict Source Route */
end_comment

begin_comment
comment|/*  * CISCO uses special type for GRE tunnel created as part of WCCP  * connection, while in fact those packets are just IPv4 encapsulated  * into GRE.  */
end_comment

begin_define
define|#
directive|define
name|WCCP_PROTOCOL_TYPE
value|0x883E
end_define

begin_comment
comment|/*  * gre_sre defines a Source route Entry. These are needed if packets  * should be routed over more than one tunnel hop by hop  */
end_comment

begin_struct
struct|struct
name|gre_sre
block|{
name|u_int16_t
name|sre_family
decl_stmt|;
comment|/* address family */
name|u_char
name|sre_offset
decl_stmt|;
comment|/* offset to first octet of active entry */
name|u_char
name|sre_length
decl_stmt|;
comment|/* number of octets in the SRE. 				   sre_lengthl==0 -> last entry. */
name|u_char
modifier|*
name|sre_rtinfo
decl_stmt|;
comment|/* the routing information */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|greioctl
block|{
name|int
name|unit
decl_stmt|;
name|struct
name|in_addr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for mobile encaps */
end_comment

begin_struct
struct|struct
name|mobile_h
block|{
name|u_int16_t
name|proto
decl_stmt|;
comment|/* protocol and S-bit */
name|u_int16_t
name|hcrc
decl_stmt|;
comment|/* header checksum */
name|u_int32_t
name|odst
decl_stmt|;
comment|/* original destination address */
name|u_int32_t
name|osrc
decl_stmt|;
comment|/* original source addr, if S-bit set */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mobip_h
block|{
name|struct
name|ip
name|mi
decl_stmt|;
name|struct
name|mobile_h
name|mh
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MOB_H_SIZ_S
value|(sizeof(struct mobile_h) - sizeof(u_int32_t))
end_define

begin_define
define|#
directive|define
name|MOB_H_SIZ_L
value|(sizeof(struct mobile_h))
end_define

begin_define
define|#
directive|define
name|MOB_H_SBIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|GRE_TTL
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * ioctls needed to manipulate the interface  */
end_comment

begin_define
define|#
directive|define
name|GRESADDRS
value|_IOW('i', 101, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GRESADDRD
value|_IOW('i', 102, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GREGADDRS
value|_IOWR('i', 103, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GREGADDRD
value|_IOWR('i', 104, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GRESPROTO
value|_IOW('i' , 105, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GREGPROTO
value|_IOWR('i', 106, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GREGKEY
value|_IOWR('i', 107, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GRESKEY
value|_IOW('i', 108, struct ifreq)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|gre_softc_head
argument_list|,
name|gre_softc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|gre_softc_head
argument_list|,
name|gre_softc_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_gre_softc_list
value|VNET(gre_softc_list)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|mtx
argument_list|,
name|gre_mtx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_gre_mtx
value|VNET(gre_mtx)
end_define

begin_define
define|#
directive|define
name|GRE_LIST_LOCK_INIT
parameter_list|(
name|x
parameter_list|)
value|mtx_init(&V_gre_mtx, "gre_mtx", NULL, \ 					    MTX_DEF)
end_define

begin_define
define|#
directive|define
name|GRE_LIST_LOCK_DESTROY
parameter_list|(
name|x
parameter_list|)
value|mtx_destroy(&V_gre_mtx)
end_define

begin_define
define|#
directive|define
name|GRE_LIST_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(&V_gre_mtx)
end_define

begin_define
define|#
directive|define
name|GRE_LIST_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(&V_gre_mtx)
end_define

begin_function_decl
name|u_int16_t
name|gre_in_cksum
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|,
name|u_int
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

