begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * %sccs.include.redist.c%  *  *	@(#)igmp_var.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Internet Group Management Protocol (IGMP),  * implementation-specific definitions.  *  * Written by Steve Deering, Stanford, May 1988.  *  * MULTICAST 1.1  */
end_comment

begin_struct
struct|struct
name|igmpstat
block|{
name|u_long
name|igps_rcv_total
decl_stmt|;
comment|/* total IGMP messages received */
name|u_long
name|igps_rcv_tooshort
decl_stmt|;
comment|/* received with too few bytes */
name|u_long
name|igps_rcv_badsum
decl_stmt|;
comment|/* received with bad checksum */
name|u_long
name|igps_rcv_queries
decl_stmt|;
comment|/* received membership queries */
name|u_long
name|igps_rcv_badqueries
decl_stmt|;
comment|/* received invalid queries */
name|u_long
name|igps_rcv_reports
decl_stmt|;
comment|/* received membership reports */
name|u_long
name|igps_rcv_badreports
decl_stmt|;
comment|/* received invalid reports */
name|u_long
name|igps_rcv_ourreports
decl_stmt|;
comment|/* received reports for our groups */
name|u_long
name|igps_snd_reports
decl_stmt|;
comment|/* sent membership reports */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|igmpstat
name|igmpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Macro to compute a random timer value between 1 and (IGMP_MAX_REPORTING_  * DELAY * countdown frequency).  We generate a "random" number by adding  * the total number of IP packets received, our primary IP address, and the  * multicast address being timed-out.  The 4.3 random() routine really  * ought to be available in the kernel!  */
end_comment

begin_define
define|#
directive|define
name|IGMP_RANDOM_DELAY
parameter_list|(
name|multiaddr
parameter_list|)
define|\
comment|/* struct in_addr multiaddr; */
define|\
value|( (ipstat.ips_total + \ 	   ntohl(IA_SIN(in_ifaddr)->sin_addr.s_addr) + \ 	   ntohl((multiaddr).s_addr) \ 	  ) \ 	  % (IGMP_MAX_HOST_REPORT_DELAY * PR_FASTHZ) + 1 \ 	)
end_define

begin_decl_stmt
name|void
name|igmp_init
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_joingroup
name|__P
argument_list|(
operator|(
expr|struct
name|in_multi
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_leavegroup
name|__P
argument_list|(
operator|(
expr|struct
name|in_multi
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_fasttimo
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

