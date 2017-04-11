begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * Copyright (c) 2014 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved  *  * This code is derived from software contributed to The NetBSD Foundation  * by Heiko W.Rupp<hwr@pilhuhn.de>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: if_gre.h,v 1.13 2003/11/10 08:51:52 wiz Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_GRE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_GRE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* GRE header according to RFC 2784 and RFC 2890 */
end_comment

begin_struct
struct|struct
name|grehdr
block|{
name|uint16_t
name|gre_flags
decl_stmt|;
comment|/* GRE flags */
define|#
directive|define
name|GRE_FLAGS_CP
value|0x8000
comment|/* checksum present */
define|#
directive|define
name|GRE_FLAGS_KP
value|0x2000
comment|/* key present */
define|#
directive|define
name|GRE_FLAGS_SP
value|0x1000
comment|/* sequence present */
define|#
directive|define
name|GRE_FLAGS_MASK
value|(GRE_FLAGS_CP|GRE_FLAGS_KP|GRE_FLAGS_SP)
name|uint16_t
name|gre_proto
decl_stmt|;
comment|/* protocol type */
name|uint32_t
name|gre_opts
index|[
literal|0
index|]
decl_stmt|;
comment|/* optional fields */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_struct
struct|struct
name|greip
block|{
name|struct
name|ip
name|gi_ip
decl_stmt|;
name|struct
name|grehdr
name|gi_gre
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_struct
struct|struct
name|greip6
block|{
name|struct
name|ip6_hdr
name|gi6_ip6
decl_stmt|;
name|struct
name|grehdr
name|gi6_gre
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|gre_softc
block|{
name|struct
name|ifnet
modifier|*
name|gre_ifp
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|gre_softc
argument_list|)
name|gre_list
expr_stmt|;
name|struct
name|rmlock
name|gre_lock
decl_stmt|;
name|int
name|gre_family
decl_stmt|;
comment|/* AF of delivery header */
name|uint32_t
name|gre_iseq
decl_stmt|;
name|uint32_t
name|gre_oseq
decl_stmt|;
name|uint32_t
name|gre_key
decl_stmt|;
name|uint32_t
name|gre_options
decl_stmt|;
name|u_int
name|gre_fibnum
decl_stmt|;
name|u_int
name|gre_hlen
decl_stmt|;
comment|/* header size */
union|union
block|{
name|void
modifier|*
name|hdr
decl_stmt|;
ifdef|#
directive|ifdef
name|INET
name|struct
name|greip
modifier|*
name|gihdr
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET6
name|struct
name|greip6
modifier|*
name|gi6hdr
decl_stmt|;
endif|#
directive|endif
block|}
name|gre_uhdr
union|;
specifier|const
name|struct
name|encaptab
modifier|*
name|gre_ecookie
decl_stmt|;
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
value|((sc)->gre_ifp)
end_define

begin_define
define|#
directive|define
name|GRE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|rm_init(&(sc)->gre_lock, "gre softc")
end_define

begin_define
define|#
directive|define
name|GRE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|rm_destroy(&(sc)->gre_lock)
end_define

begin_define
define|#
directive|define
name|GRE_RLOCK_TRACKER
value|struct rm_priotracker gre_tracker
end_define

begin_define
define|#
directive|define
name|GRE_RLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_rlock(&(sc)->gre_lock,&gre_tracker)
end_define

begin_define
define|#
directive|define
name|GRE_RUNLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_runlock(&(sc)->gre_lock,&gre_tracker)
end_define

begin_define
define|#
directive|define
name|GRE_RLOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|rm_assert(&(sc)->gre_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|GRE_WLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_wlock(&(sc)->gre_lock)
end_define

begin_define
define|#
directive|define
name|GRE_WUNLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_wunlock(&(sc)->gre_lock)
end_define

begin_define
define|#
directive|define
name|GRE_WLOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|rm_assert(&(sc)->gre_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|gre_hdr
value|gre_uhdr.hdr
end_define

begin_define
define|#
directive|define
name|gre_gihdr
value|gre_uhdr.gihdr
end_define

begin_define
define|#
directive|define
name|gre_gi6hdr
value|gre_uhdr.gi6hdr
end_define

begin_define
define|#
directive|define
name|gre_oip
value|gre_gihdr->gi_ip
end_define

begin_define
define|#
directive|define
name|gre_oip6
value|gre_gi6hdr->gi6_ip6
end_define

begin_function_decl
name|int
name|gre_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_function_decl
name|int
name|in_gre_attach
parameter_list|(
name|struct
name|gre_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_gre_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
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
name|INET6
end_ifdef

begin_function_decl
name|int
name|in6_gre_attach
parameter_list|(
name|struct
name|gre_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in6_gre_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
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
comment|/*  * CISCO uses special type for GRE tunnel created as part of WCCP  * connection, while in fact those packets are just IPv4 encapsulated  * into GRE.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_WCCP
value|0x883E
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
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

begin_define
define|#
directive|define
name|GREGOPTS
value|_IOWR('i', 109, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GRESOPTS
value|_IOW('i', 110, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GRE_ENABLE_CSUM
value|0x0001
end_define

begin_define
define|#
directive|define
name|GRE_ENABLE_SEQ
value|0x0002
end_define

begin_define
define|#
directive|define
name|GRE_OPTMASK
value|(GRE_ENABLE_CSUM|GRE_ENABLE_SEQ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_GRE_H_ */
end_comment

end_unit

