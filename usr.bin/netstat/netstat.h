begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)netstat.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|satosin
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in *)(sa))
end_define

begin_define
define|#
directive|define
name|satosin6
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in6 *)(sa))
end_define

begin_define
define|#
directive|define
name|sin6tosa
parameter_list|(
name|sin6
parameter_list|)
value|((struct sockaddr *)(sin6))
end_define

begin_decl_stmt
specifier|extern
name|int
name|Aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show addresses of protocol control block */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show all sockets (including servers) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show i/f total bytes in/out */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show i/f dropped packets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show group (multicast) routing or stats */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show counters in human readable format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show size of listen queues */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show memory stats */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|noutputs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how much outputs before we exit */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numeric_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show addresses numerically */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numeric_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show ports numerically */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show routing tables (or routing stats) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show flowid / RSS information */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show protocol statistics */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show TCP control block info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Wflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wide display */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extended display, includes all socket buffer info */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero stats */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* repeat interval for i/f stats */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired i/f for stats, or NULL for all i/fs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unit number for above */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|live
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we are examining a live system */
end_comment

begin_typedef
typedef|typedef
name|int
name|kreadfn_t
parameter_list|(
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|fetch_stats
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|kreadfn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_stats_ro
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|kreadfn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kread
parameter_list|(
name|u_long
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|kread_counter
parameter_list|(
name|u_long
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kread_counters
parameter_list|(
name|u_long
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kset_dpcpu
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|plural
parameter_list|(
name|uintmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|plurales
parameter_list|(
name|uintmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pluralies
parameter_list|(
name|uintmax_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xsocket
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|sotoxsocket
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|xsocket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|protopr
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP
end_ifdef

begin_function_decl
name|void
name|sctp_protopr
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
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

begin_function_decl
name|void
name|arp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|icmp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|igmp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pim_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|carp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfsync_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_function_decl
name|void
name|ipsec_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|esp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ah_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipcomp_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
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
name|INET
end_ifdef

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|inetname
parameter_list|(
name|struct
name|in_addr
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
name|INET6
end_ifdef

begin_struct_decl
struct_decl|struct
name|in6_addr
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|inet6name
parameter_list|(
name|struct
name|in6_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip6_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip6_ifstats
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|icmp6_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|icmp6_ifstats
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pim6_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rip6_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mroute6pr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mrt6_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in6
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in6_addr
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|in6_fillscopeid
parameter_list|(
name|struct
name|sockaddr_in6
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inet6print
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|in6_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
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
comment|/*INET6*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_function_decl
name|void
name|pfkey_stats
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
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

begin_function_decl
name|void
name|mbpr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostpr
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|impstats
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intpr
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pr_family
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rt_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|routename
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|netname
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|routepr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_function_decl
name|void
name|netgraphprotopr
parameter_list|(
name|u_long
parameter_list|,
specifier|const
name|char
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

begin_function_decl
name|void
name|unixpr
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mroutepr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mrt_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_stats
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

