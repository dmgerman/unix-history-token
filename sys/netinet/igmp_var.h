begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)igmp_var.h	8.1 (Berkeley) 7/19/93  * $Id: igmp_var.h,v 1.6 1995/06/13 17:51:07 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IGMP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IGMP_VAR_H_
end_define

begin_comment
comment|/*  * Internet Group Management Protocol (IGMP),  * implementation-specific definitions.  *  * Written by Steve Deering, Stanford, May 1988.  *  * MULTICAST Revisiob: 3.3.1.1  */
end_comment

begin_struct
struct|struct
name|igmpstat
block|{
name|u_int
name|igps_rcv_total
decl_stmt|;
comment|/* total IGMP messages received */
name|u_int
name|igps_rcv_tooshort
decl_stmt|;
comment|/* received with too few bytes */
name|u_int
name|igps_rcv_badsum
decl_stmt|;
comment|/* received with bad checksum */
name|u_int
name|igps_rcv_queries
decl_stmt|;
comment|/* received membership queries */
name|u_int
name|igps_rcv_badqueries
decl_stmt|;
comment|/* received invalid queries */
name|u_int
name|igps_rcv_reports
decl_stmt|;
comment|/* received membership reports */
name|u_int
name|igps_rcv_badreports
decl_stmt|;
comment|/* received invalid reports */
name|u_int
name|igps_rcv_ourreports
decl_stmt|;
comment|/* received reports for our groups */
name|u_int
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
specifier|extern
name|struct
name|igmpstat
name|igmpstat
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IGMP_RANDOM_DELAY
parameter_list|(
name|X
parameter_list|)
value|(random() % (X) + 1)
end_define

begin_decl_stmt
name|void
name|igmp_init
name|__P
argument_list|(
operator|(
name|void
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
name|int
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
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|igmp_slowtimo
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Names for IGMP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|IGMPCTL_STATS
value|1
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|IGMPCTL_MAXID
value|2
end_define

begin_define
define|#
directive|define
name|IGMPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "stats", CTLTYPE_STRUCT }, \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

