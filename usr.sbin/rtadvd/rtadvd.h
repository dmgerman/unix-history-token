begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rtadvd.h,v 1.16 2001/04/10 15:08:31 suz Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ALLNODES
value|"ff02::1"
end_define

begin_define
define|#
directive|define
name|ALLROUTERS_LINK
value|"ff02::2"
end_define

begin_define
define|#
directive|define
name|ALLROUTERS_SITE
value|"ff05::2"
end_define

begin_define
define|#
directive|define
name|ANY
value|"::"
end_define

begin_define
define|#
directive|define
name|RTSOLLEN
value|8
end_define

begin_comment
comment|/* protocol constants and default values */
end_comment

begin_define
define|#
directive|define
name|DEF_MAXRTRADVINTERVAL
value|600
end_define

begin_define
define|#
directive|define
name|DEF_ADVLINKMTU
value|0
end_define

begin_define
define|#
directive|define
name|DEF_ADVREACHABLETIME
value|0
end_define

begin_define
define|#
directive|define
name|DEF_ADVRETRANSTIMER
value|0
end_define

begin_define
define|#
directive|define
name|DEF_ADVCURHOPLIMIT
value|64
end_define

begin_define
define|#
directive|define
name|DEF_ADVVALIDLIFETIME
value|2592000
end_define

begin_define
define|#
directive|define
name|DEF_ADVPREFERREDLIFETIME
value|604800
end_define

begin_comment
comment|/*XXX int-to-double comparison for INTERVAL items */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIP6
end_ifndef

begin_define
define|#
directive|define
name|mobileip6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXROUTERLIFETIME
value|9000
end_define

begin_define
define|#
directive|define
name|MIN_MAXINTERVAL
value|(mobileip6 ? 1.5 : 4.0)
end_define

begin_define
define|#
directive|define
name|MAX_MAXINTERVAL
value|1800
end_define

begin_define
define|#
directive|define
name|MIN_MININTERVAL
value|(mobileip6 ? 0.5 : 3)
end_define

begin_define
define|#
directive|define
name|MAXREACHABLETIME
value|3600000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MIP6
end_ifndef

begin_undef
undef|#
directive|undef
name|miobileip6
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_INITIAL_RTR_ADVERT_INTERVAL
value|16
end_define

begin_define
define|#
directive|define
name|MAX_INITIAL_RTR_ADVERTISEMENTS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_FINAL_RTR_ADVERTISEMENTS
value|3
end_define

begin_define
define|#
directive|define
name|MIN_DELAY_BETWEEN_RAS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_RA_DELAY_TIME
value|500000
end_define

begin_comment
comment|/* usec */
end_comment

begin_define
define|#
directive|define
name|PREFIX_FROM_KERNEL
value|1
end_define

begin_define
define|#
directive|define
name|PREFIX_FROM_CONFIG
value|2
end_define

begin_define
define|#
directive|define
name|PREFIX_FROM_DYNAMIC
value|3
end_define

begin_struct
struct|struct
name|prefix
block|{
name|struct
name|prefix
modifier|*
name|next
decl_stmt|;
comment|/* forward link */
name|struct
name|prefix
modifier|*
name|prev
decl_stmt|;
comment|/* previous link */
name|u_int32_t
name|validlifetime
decl_stmt|;
comment|/* AdvValidLifetime */
name|long
name|vltimeexpire
decl_stmt|;
comment|/* expiration of vltime; decrement case only */
name|u_int32_t
name|preflifetime
decl_stmt|;
comment|/* AdvPreferredLifetime */
name|long
name|pltimeexpire
decl_stmt|;
comment|/* expiration of pltime; decrement case only */
name|u_int
name|onlinkflg
decl_stmt|;
comment|/* bool: AdvOnLinkFlag */
name|u_int
name|autoconfflg
decl_stmt|;
comment|/* bool: AdvAutonomousFlag */
ifdef|#
directive|ifdef
name|MIP6
name|u_int
name|routeraddr
decl_stmt|;
comment|/* bool: RouterAddress */
endif|#
directive|endif
name|int
name|prefixlen
decl_stmt|;
name|int
name|origin
decl_stmt|;
comment|/* from kernel or cofig */
name|struct
name|in6_addr
name|prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtinfo
block|{
name|struct
name|rtinfo
modifier|*
name|prev
decl_stmt|;
comment|/* previous link */
name|struct
name|rtinfo
modifier|*
name|next
decl_stmt|;
comment|/* forward link */
name|u_int32_t
name|ltime
decl_stmt|;
comment|/* route lifetime */
name|u_int
name|rtpref
decl_stmt|;
comment|/* router preference */
name|int
name|prefixlen
decl_stmt|;
name|struct
name|in6_addr
name|prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|soliciter
block|{
name|struct
name|soliciter
modifier|*
name|next
decl_stmt|;
name|struct
name|sockaddr_in6
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rainfo
block|{
comment|/* pointer for list */
name|struct
name|rainfo
modifier|*
name|next
decl_stmt|;
comment|/* timer related parameters */
name|struct
name|rtadvd_timer
modifier|*
name|timer
decl_stmt|;
name|int
name|initcounter
decl_stmt|;
comment|/* counter for the first few advertisements */
name|struct
name|timeval
name|lastsent
decl_stmt|;
comment|/* timestamp when the latest RA was sent */
name|int
name|waiting
decl_stmt|;
comment|/* number of RS waiting for RA */
comment|/* interface information */
name|int
name|ifindex
decl_stmt|;
name|int
name|advlinkopt
decl_stmt|;
comment|/* bool: whether include link-layer addr opt */
name|struct
name|sockaddr_dl
modifier|*
name|sdl
decl_stmt|;
name|char
name|ifname
index|[
literal|16
index|]
decl_stmt|;
name|int
name|phymtu
decl_stmt|;
comment|/* mtu of the physical interface */
comment|/* Router configuration variables */
name|u_short
name|lifetime
decl_stmt|;
comment|/* AdvDefaultLifetime */
name|u_int
name|maxinterval
decl_stmt|;
comment|/* MaxRtrAdvInterval */
name|u_int
name|mininterval
decl_stmt|;
comment|/* MinRtrAdvInterval */
name|int
name|managedflg
decl_stmt|;
comment|/* AdvManagedFlag */
name|int
name|otherflg
decl_stmt|;
comment|/* AdvOtherConfigFlag */
ifdef|#
directive|ifdef
name|MIP6
name|int
name|haflg
decl_stmt|;
comment|/* HAFlag */
endif|#
directive|endif
name|int
name|rtpref
decl_stmt|;
comment|/* router preference */
name|u_int32_t
name|linkmtu
decl_stmt|;
comment|/* AdvLinkMTU */
name|u_int32_t
name|reachabletime
decl_stmt|;
comment|/* AdvReachableTime */
name|u_int32_t
name|retranstimer
decl_stmt|;
comment|/* AdvRetransTimer */
name|u_int
name|hoplimit
decl_stmt|;
comment|/* AdvCurHopLimit */
name|struct
name|prefix
name|prefix
decl_stmt|;
comment|/* AdvPrefixList(link head) */
name|int
name|pfxs
decl_stmt|;
comment|/* number of prefixes */
name|long
name|clockskew
decl_stmt|;
comment|/* used for consisitency check of lifetimes */
ifdef|#
directive|ifdef
name|MIP6
name|u_short
name|hapref
decl_stmt|;
comment|/* Home Agent Preference */
name|u_short
name|hatime
decl_stmt|;
comment|/* Home Agent Lifetime */
endif|#
directive|endif
name|struct
name|rtinfo
name|route
decl_stmt|;
comment|/* route information option (link head) */
name|int
name|routes
decl_stmt|;
comment|/* number of route information options */
comment|/* actual RA packet data and its length */
name|size_t
name|ra_datalen
decl_stmt|;
name|u_char
modifier|*
name|ra_data
decl_stmt|;
comment|/* statistics */
name|u_quad_t
name|raoutput
decl_stmt|;
comment|/* number of RAs sent */
name|u_quad_t
name|rainput
decl_stmt|;
comment|/* number of RAs received */
name|u_quad_t
name|rainconsistent
decl_stmt|;
comment|/* number of RAs inconsistent with ours */
name|u_quad_t
name|rsinput
decl_stmt|;
comment|/* number of RSs received */
comment|/* info about soliciter */
name|struct
name|soliciter
modifier|*
name|soliciter
decl_stmt|;
comment|/* recent solication source */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|ra_timeout
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
name|void
name|ra_timer_update
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prefix_match
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rainfo
modifier|*
name|if_indextorainfo
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
name|struct
name|in6_addr
name|in6a_site_allrouters
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MIP6
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|mobileip6
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

