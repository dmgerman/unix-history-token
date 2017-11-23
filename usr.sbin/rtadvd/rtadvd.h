begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: rtadvd.h,v 1.26 2003/08/05 12:34:23 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1998 WIDE Project.  * Copyright (C) 2011 Hiroki Sato<hrs@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|ELM_MALLOC
parameter_list|(
name|p
parameter_list|,
name|error_action
parameter_list|)
define|\
value|do {								\ 		p = malloc(sizeof(*p));					\ 		if (p == NULL) {					\ 			syslog(LOG_ERR, "<%s> malloc failed: %s",	\ 			    __func__, strerror(errno));			\ 			error_action;					\ 		}							\ 		memset(p, 0, sizeof(*p));				\ 	} while(0)
end_define

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
name|struct
name|sockaddr_in6
name|sin6_linklocal_allnodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
name|sin6_linklocal_allrouters
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
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
name|TAILQ_ENTRY
argument_list|(
argument|prefix
argument_list|)
name|pfx_next
expr_stmt|;
name|struct
name|rainfo
modifier|*
name|pfx_rainfo
decl_stmt|;
comment|/* back pointer to the interface */
comment|/* 	 * Expiration timer.  This is used when a prefix derived from 	 * the kernel is deleted. 	 */
name|struct
name|rtadvd_timer
modifier|*
name|pfx_timer
decl_stmt|;
name|uint32_t
name|pfx_validlifetime
decl_stmt|;
comment|/* AdvValidLifetime */
name|uint32_t
name|pfx_vltimeexpire
decl_stmt|;
comment|/* Expiration of vltime */
name|uint32_t
name|pfx_preflifetime
decl_stmt|;
comment|/* AdvPreferredLifetime */
name|uint32_t
name|pfx_pltimeexpire
decl_stmt|;
comment|/* Expiration of pltime */
name|int
name|pfx_onlinkflg
decl_stmt|;
comment|/* bool: AdvOnLinkFlag */
name|int
name|pfx_autoconfflg
decl_stmt|;
comment|/* bool: AdvAutonomousFlag */
name|int
name|pfx_prefixlen
decl_stmt|;
name|int
name|pfx_origin
decl_stmt|;
comment|/* From kernel or config */
name|struct
name|in6_addr
name|pfx_prefix
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtinfo
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rtinfo
argument_list|)
name|rti_next
expr_stmt|;
name|uint32_t
name|rti_ltime
decl_stmt|;
comment|/* route lifetime */
name|int
name|rti_rtpref
decl_stmt|;
comment|/* route preference */
name|int
name|rti_prefixlen
decl_stmt|;
name|struct
name|in6_addr
name|rti_prefix
decl_stmt|;
block|}
struct|;
end_struct

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
name|uint32_t
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
name|uint32_t
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
name|TAILQ_ENTRY
argument_list|(
argument|soliciter
argument_list|)
name|sol_next
expr_stmt|;
name|struct
name|sockaddr_in6
name|sol_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rainfo
block|{
comment|/* pointer for list */
name|TAILQ_ENTRY
argument_list|(
argument|rainfo
argument_list|)
name|rai_next
expr_stmt|;
comment|/* interface information */
name|struct
name|ifinfo
modifier|*
name|rai_ifinfo
decl_stmt|;
name|int
name|rai_advlinkopt
decl_stmt|;
comment|/* bool: whether include link-layer addr opt */
name|int
name|rai_advifprefix
decl_stmt|;
comment|/* bool: gather IF prefixes? */
comment|/* Router configuration variables */
name|uint16_t
name|rai_lifetime
decl_stmt|;
comment|/* AdvDefaultLifetime */
name|uint16_t
name|rai_maxinterval
decl_stmt|;
comment|/* MaxRtrAdvInterval */
name|uint16_t
name|rai_mininterval
decl_stmt|;
comment|/* MinRtrAdvInterval */
name|int
name|rai_managedflg
decl_stmt|;
comment|/* AdvManagedFlag */
name|int
name|rai_otherflg
decl_stmt|;
comment|/* AdvOtherConfigFlag */
name|int
name|rai_rtpref
decl_stmt|;
comment|/* router preference */
name|uint32_t
name|rai_linkmtu
decl_stmt|;
comment|/* AdvLinkMTU */
name|uint32_t
name|rai_reachabletime
decl_stmt|;
comment|/* AdvReachableTime */
name|uint32_t
name|rai_retranstimer
decl_stmt|;
comment|/* AdvRetransTimer */
name|uint8_t
name|rai_hoplimit
decl_stmt|;
comment|/* AdvCurHopLimit */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|prefix
argument_list|)
name|rai_prefix
expr_stmt|;
comment|/* AdvPrefixList(link head) */
name|int
name|rai_pfxs
decl_stmt|;
comment|/* number of prefixes */
name|uint16_t
name|rai_clockskew
decl_stmt|;
comment|/* used for consisitency check of lifetimes */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rdnss
argument_list|)
name|rai_rdnss
expr_stmt|;
comment|/* DNS server list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|dnssl
argument_list|)
name|rai_dnssl
expr_stmt|;
comment|/* search domain list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rtinfo
argument_list|)
name|rai_route
expr_stmt|;
comment|/* route information option (link head) */
name|int
name|rai_routes
decl_stmt|;
comment|/* number of route information options */
comment|/* actual RA packet data and its length */
name|size_t
name|rai_ra_datalen
decl_stmt|;
name|char
modifier|*
name|rai_ra_data
decl_stmt|;
comment|/* info about soliciter */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|soliciter
argument_list|)
name|rai_soliciter
expr_stmt|;
comment|/* recent solication source */
block|}
struct|;
end_struct

begin_comment
comment|/* RA information list */
end_comment

begin_extern
extern|extern TAILQ_HEAD(railist_head_t
operator|,
extern|rainfo
end_extern

begin_expr_stmt
unit|)
name|railist
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * ifi_state:  *  *           (INIT)  *              |  *              | update_ifinfo()  *              | update_persist_ifinfo()  *              v  *         UNCONFIGURED  *               |  ^  *   loadconfig()|  |rm_ifinfo(), ra_output()  *      (MC join)|  |(MC leave)  *               |  |  *               |  |  *               v  |  *         TRANSITIVE  *               |  ^  *    ra_output()|  |getconfig()  *               |  |  *               |  |  *               |  |  *               v  |  *         CONFIGURED  *  *  */
end_comment

begin_define
define|#
directive|define
name|IFI_STATE_UNCONFIGURED
value|0
end_define

begin_define
define|#
directive|define
name|IFI_STATE_CONFIGURED
value|1
end_define

begin_define
define|#
directive|define
name|IFI_STATE_TRANSITIVE
value|2
end_define

begin_struct
struct|struct
name|ifinfo
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ifinfo
argument_list|)
name|ifi_next
expr_stmt|;
name|uint16_t
name|ifi_state
decl_stmt|;
name|uint16_t
name|ifi_persist
decl_stmt|;
name|uint16_t
name|ifi_ifindex
decl_stmt|;
name|char
name|ifi_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|uint8_t
name|ifi_type
decl_stmt|;
name|uint16_t
name|ifi_flags
decl_stmt|;
name|uint32_t
name|ifi_nd_flags
decl_stmt|;
name|uint32_t
name|ifi_phymtu
decl_stmt|;
name|struct
name|sockaddr_dl
name|ifi_sdl
decl_stmt|;
name|struct
name|rainfo
modifier|*
name|ifi_rainfo
decl_stmt|;
name|struct
name|rainfo
modifier|*
name|ifi_rainfo_trans
decl_stmt|;
name|uint16_t
name|ifi_burstcount
decl_stmt|;
name|uint32_t
name|ifi_burstinterval
decl_stmt|;
name|struct
name|rtadvd_timer
modifier|*
name|ifi_ra_timer
decl_stmt|;
comment|/* timestamp when the latest RA was sent */
name|struct
name|timespec
name|ifi_ra_lastsent
decl_stmt|;
name|uint16_t
name|ifi_rs_waitcount
decl_stmt|;
comment|/* statistics */
name|uint64_t
name|ifi_raoutput
decl_stmt|;
comment|/* # of RAs sent */
name|uint64_t
name|ifi_rainput
decl_stmt|;
comment|/* # of RAs received */
name|uint64_t
name|ifi_rainconsistent
decl_stmt|;
comment|/* # of inconsistent recv'd RAs  */
name|uint64_t
name|ifi_rsinput
decl_stmt|;
comment|/* # of RSs received */
block|}
struct|;
end_struct

begin_comment
comment|/* Interface list */
end_comment

begin_extern
extern|extern TAILQ_HEAD(ifilist_head_t
operator|,
extern|ifinfo
end_extern

begin_expr_stmt
unit|)
name|ifilist
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mcastif
decl_stmt|;
end_decl_stmt

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
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ra_output
parameter_list|(
name|struct
name|ifinfo
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
name|ifinfo
modifier|*
name|if_indextoifinfo
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

begin_function_decl
name|void
name|rtadvd_set_reload
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtadvd_set_shutdown
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

