begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: rtadvd.h,v 1.26 2003/08/05 12:34:23 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLNODES_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	\ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLROUTERS_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	\ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 }}}
end_define

begin_define
define|#
directive|define
name|IN6ADDR_SITELOCAL_ALLROUTERS_INIT
define|\
value|{{{ 0xff, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	\ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 }}}
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sockaddr_in6
name|sin6_linklocal_allnodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sockaddr_in6
name|sin6_linklocal_allrouters
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sockaddr_in6
name|sin6_sitelocal_allrouters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * RFC 3542 API deprecates IPV6_PKTINFO in favor of  * IPV6_RECVPKTINFO  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6_RECVPKTINFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IPV6_PKTINFO
end_ifdef

begin_define
define|#
directive|define
name|IPV6_RECVPKTINFO
value|IPV6_PKTINFO
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
comment|/*  * RFC 3542 API deprecates IPV6_HOPLIMIT in favor of  * IPV6_RECVHOPLIMIT  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6_RECVHOPLIMIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IPV6_HOPLIMIT
end_ifdef

begin_define
define|#
directive|define
name|IPV6_RECVHOPLIMIT
value|IPV6_HOPLIMIT
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
value|4
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
value|3
end_define

begin_define
define|#
directive|define
name|MAXREACHABLETIME
value|3600000
end_define

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
name|struct
name|rainfo
modifier|*
name|rainfo
decl_stmt|;
comment|/* back pointer to the interface */
name|struct
name|rtadvd_timer
modifier|*
name|timer
decl_stmt|;
comment|/* expiration timer.  used when a prefix 				     * derived from the kernel is deleted. 				     */
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
name|int
name|prefixlen
decl_stmt|;
name|int
name|origin
decl_stmt|;
comment|/* from kernel or config */
name|struct
name|in6_addr
name|prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ROUTEINFO
end_ifdef

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
comment|/* route preference */
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

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|rdnss_addr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rdnss_addr
argument_list|)
name|ra_next
expr_stmt|;
name|struct
name|in6_addr
name|ra_dns
decl_stmt|;
comment|/* DNS server entry */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdnss
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rdnss
argument_list|)
name|rd_next
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rdnss_addr
argument_list|)
name|rd_list
expr_stmt|;
comment|/* list of DNS servers */
name|int
name|rd_cnt
decl_stmt|;
comment|/* number of DNS servers */
name|u_int32_t
name|rd_ltime
decl_stmt|;
comment|/* number of seconds valid */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The maximum length of a domain name in a DNS search list is calculated  * by a domain name + length fields per 63 octets + a zero octet at  * the tail and adding 8 octet boundary padding.  */
end_comment

begin_define
define|#
directive|define
name|_DNAME_LABELENC_MAXLEN
define|\
value|(NI_MAXHOST + (NI_MAXHOST / 64 + 1) + 1)
end_define

begin_define
define|#
directive|define
name|DNAME_LABELENC_MAXLEN
define|\
value|(_DNAME_LABELENC_MAXLEN + 8 - _DNAME_LABELENC_MAXLEN % 8)
end_define

begin_struct
struct|struct
name|dnssl_addr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|dnssl_addr
argument_list|)
name|da_next
expr_stmt|;
name|int
name|da_len
decl_stmt|;
comment|/* length of entry */
name|char
name|da_dom
index|[
name|DNAME_LABELENC_MAXLEN
index|]
decl_stmt|;
comment|/* search domain name entry */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dnssl
block|{
name|TAILQ_ENTRY
argument_list|(
argument|dnssl
argument_list|)
name|dn_next
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dnssl_addr
argument_list|)
name|dn_list
expr_stmt|;
comment|/* list of search domains */
name|u_int32_t
name|dn_ltime
decl_stmt|;
comment|/* number of seconds valid */
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
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rdnss
argument_list|)
name|rdnss
expr_stmt|;
comment|/* DNS server list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dnssl
argument_list|)
name|dnssl
expr_stmt|;
comment|/* search domain list */
name|long
name|clockskew
decl_stmt|;
comment|/* used for consisitency check of lifetimes */
ifdef|#
directive|ifdef
name|ROUTEINFO
name|struct
name|rtinfo
name|route
decl_stmt|;
comment|/* route information option (link head) */
name|int
name|routes
decl_stmt|;
comment|/* number of route information options */
endif|#
directive|endif
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

begin_function_decl
name|struct
name|rtadvd_timer
modifier|*
name|ra_timeout
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ra_timer_update
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prefix_match
parameter_list|(
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rainfo
modifier|*
name|if_indextorainfo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|prefix
modifier|*
name|find_prefix
parameter_list|(
name|struct
name|rainfo
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|in6_addr
name|in6a_site_allrouters
decl_stmt|;
end_decl_stmt

end_unit

