begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rtsold.h,v 1.19 2003/04/16 09:48:15 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|script_msg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|script_msg
argument_list|)
name|sm_next
expr_stmt|;
name|char
modifier|*
name|sm_msg
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|script_msg_head_t
argument_list|,
name|script_msg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ra_opt
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ra_opt
argument_list|)
name|rao_next
expr_stmt|;
name|u_int8_t
name|rao_type
decl_stmt|;
name|struct
name|timespec
name|rao_expire
decl_stmt|;
name|size_t
name|rao_len
decl_stmt|;
name|void
modifier|*
name|rao_msg
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|rainfo_head
argument_list|,
name|ra_opt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|rainfo
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rainfo
argument_list|)
name|rai_next
expr_stmt|;
name|struct
name|ifinfo
modifier|*
name|rai_ifinfo
decl_stmt|;
name|struct
name|sockaddr_in6
name|rai_saddr
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ra_opt
argument_list|)
name|rai_ra_opt
expr_stmt|;
block|}
struct|;
end_struct

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
comment|/* pointer to the next interface */
name|struct
name|sockaddr_dl
modifier|*
name|sdl
decl_stmt|;
comment|/* link-layer address */
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name */
name|u_int32_t
name|linkid
decl_stmt|;
comment|/* link ID of this interface */
name|int
name|active
decl_stmt|;
comment|/* interface status */
name|int
name|probeinterval
decl_stmt|;
comment|/* interval of probe timer (if necessary) */
name|int
name|probetimer
decl_stmt|;
comment|/* rest of probe timer */
name|int
name|mediareqok
decl_stmt|;
comment|/* whether the IF supports SIOCGIFMEDIA */
name|int
name|otherconfig
decl_stmt|;
comment|/* need a separate protocol for the "other" 				 * configuration */
name|int
name|state
decl_stmt|;
name|int
name|probes
decl_stmt|;
name|int
name|dadcount
decl_stmt|;
name|struct
name|timespec
name|timer
decl_stmt|;
name|struct
name|timespec
name|expire
decl_stmt|;
name|int
name|errors
decl_stmt|;
comment|/* # of errors we've got - detect wedge */
define|#
directive|define
name|IFI_DNSOPT_STATE_NOINFO
value|0
define|#
directive|define
name|IFI_DNSOPT_STATE_RECEIVED
value|1
name|int
name|ifi_rdnss
decl_stmt|;
comment|/* RDNSS option state */
name|int
name|ifi_dnssl
decl_stmt|;
comment|/* DNSSL option state */
name|int
name|racnt
decl_stmt|;
comment|/* total # of valid RAs it have got */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|rainfo
argument_list|)
name|ifi_rainfo
expr_stmt|;
name|size_t
name|rs_datalen
decl_stmt|;
name|u_char
modifier|*
name|rs_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* per interface status */
end_comment

begin_define
define|#
directive|define
name|IFS_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|IFS_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|IFS_PROBE
value|2
end_define

begin_define
define|#
directive|define
name|IFS_DOWN
value|3
end_define

begin_define
define|#
directive|define
name|IFS_TENTATIVE
value|4
end_define

begin_comment
comment|/* Interface list */
end_comment

begin_extern
extern|extern TAILQ_HEAD(ifinfo_head_t
operator|,
extern|ifinfo
end_extern

begin_expr_stmt
unit|)
name|ifinfo_head
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DNSINFO_ORIGIN_LABEL
value|"slaac"
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|IN6ADDR_LINKLOCAL_ALLROUTERS_INIT
end_ifndef

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLROUTERS_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	\ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 }}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TS_CMP
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(((tsp)->tv_sec == (usp)->tv_sec) ?				\ 	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\ 	    ((tsp)->tv_sec cmp (usp)->tv_sec))
end_define

begin_define
define|#
directive|define
name|TS_ADD
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec + (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec + (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec>= 1000000000L) {			\ 			(vsp)->tv_sec++;				\ 			(vsp)->tv_nsec -= 1000000000L;			\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_SUB
parameter_list|(
name|tsp
parameter_list|,
name|usp
parameter_list|,
name|vsp
parameter_list|)
define|\
value|do {								\ 		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\ 		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\ 		if ((vsp)->tv_nsec< 0) {				\ 			(vsp)->tv_sec--;				\ 			(vsp)->tv_nsec += 1000000000L;			\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* rtsold.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timespec
name|tm_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Fflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|otherconf_script
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|resolvconf_script
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ifconfig
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iflist_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifinfo
modifier|*
name|find_ifinfo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rainfo
modifier|*
name|find_rainfo
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|,
name|struct
name|sockaddr_in6
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtsol_timer_update
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warnmsg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|autoifprobe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ra_opt_handler
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ifinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|interface_up
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|interface_status
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lladdropt_length
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lladdropt_fill
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|,
name|struct
name|nd_opt_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sockaddr_dl
modifier|*
name|if_nametosdl
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getinet6sysctl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setinet6sysctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rtsol.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rssock
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|sockopen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sendpacket
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtsol_input
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* probe.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|probe_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|defrouter_probe
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dump.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|rtsold_dump_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|sec2str
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rtsock.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|rtsock_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtsock_input
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

