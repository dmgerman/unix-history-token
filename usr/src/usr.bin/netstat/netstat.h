begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)netstat.h	8.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|int
name|Aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show addresses of protocol control block */
end_comment

begin_decl_stmt
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show all sockets (including servers) */
end_comment

begin_decl_stmt
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show i/f dropped packets */
end_comment

begin_decl_stmt
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show group (multicast) routing or stats */
end_comment

begin_decl_stmt
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show interfaces */
end_comment

begin_decl_stmt
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show memory stats */
end_comment

begin_decl_stmt
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show addresses numerically */
end_comment

begin_decl_stmt
name|int
name|pflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show given protocol */
end_comment

begin_decl_stmt
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show routing tables (or routing stats) */
end_comment

begin_decl_stmt
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show protocol statistics */
end_comment

begin_decl_stmt
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show i/f watchdog timers */
end_comment

begin_decl_stmt
name|int
name|interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* repeat interval for i/f stats */
end_comment

begin_decl_stmt
name|char
modifier|*
name|interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired i/f for stats, or NULL for all i/fs */
end_comment

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unit number for above */
end_comment

begin_decl_stmt
name|int
name|af
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address family */
end_comment

begin_decl_stmt
name|char
modifier|*
name|prog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
name|int
name|kread
name|__P
argument_list|(
operator|(
name|u_long
name|addr
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|plural
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|plurales
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|protopr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|udp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ip_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|icmp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|protopr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mbpr
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|hostpr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|impstats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|intpr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pr_rthdr
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pr_family
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rt_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ns_phost
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|upHex
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
name|char
modifier|*
name|routename
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|netname
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ns_print
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|routepr
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nsprotopr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|idp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nserr_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|intpr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unixpr
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|esis_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clnp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cltp_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iso_protopr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iso_protopr1
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tp_protopr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tp_inproto
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tp_stats
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mroutepr
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mrt_stats
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

