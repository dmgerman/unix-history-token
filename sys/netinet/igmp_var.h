begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-a  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)igmp_var.h	8.1 (Berkeley) 7/19/93  * $FreeBSD$  */
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
comment|/*  * Internet Group Management Protocol (IGMP),  * implementation-specific definitions.  *  * Written by Steve Deering, Stanford, May 1988.  *  * MULTICAST Revision: 3.5.1.3  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BURN_BRIDGES
end_ifndef

begin_comment
comment|/*  * Pre-IGMPV3 igmpstat structure.  */
end_comment

begin_struct
struct|struct
name|oigmpstat
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
name|u_int
name|igps_rcv_toolong
decl_stmt|;
comment|/* received with too many bytes */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IGMPv3 protocol statistics.  */
end_comment

begin_struct
struct|struct
name|igmpstat
block|{
comment|/* 	 * Structure header (to insulate ABI changes). 	 */
name|uint32_t
name|igps_version
decl_stmt|;
comment|/* version of this structure */
name|uint32_t
name|igps_len
decl_stmt|;
comment|/* length of this structure */
comment|/* 	 * Message statistics. 	 */
name|uint64_t
name|igps_rcv_total
decl_stmt|;
comment|/* total IGMP messages received */
name|uint64_t
name|igps_rcv_tooshort
decl_stmt|;
comment|/* received with too few bytes */
name|uint64_t
name|igps_rcv_badttl
decl_stmt|;
comment|/* received with ttl other than 1 */
name|uint64_t
name|igps_rcv_badsum
decl_stmt|;
comment|/* received with bad checksum */
comment|/* 	 * Query statistics. 	 */
name|uint64_t
name|igps_rcv_v1v2_queries
decl_stmt|;
comment|/* received IGMPv1/IGMPv2 queries */
name|uint64_t
name|igps_rcv_v3_queries
decl_stmt|;
comment|/* received IGMPv3 queries */
name|uint64_t
name|igps_rcv_badqueries
decl_stmt|;
comment|/* received invalid queries */
name|uint64_t
name|igps_rcv_gen_queries
decl_stmt|;
comment|/* received general queries */
name|uint64_t
name|igps_rcv_group_queries
decl_stmt|;
comment|/* received group queries */
name|uint64_t
name|igps_rcv_gsr_queries
decl_stmt|;
comment|/* received group-source queries */
name|uint64_t
name|igps_drop_gsr_queries
decl_stmt|;
comment|/* dropped group-source queries */
comment|/* 	 * Report statistics. 	 */
name|uint64_t
name|igps_rcv_reports
decl_stmt|;
comment|/* received membership reports */
name|uint64_t
name|igps_rcv_badreports
decl_stmt|;
comment|/* received invalid reports */
name|uint64_t
name|igps_rcv_ourreports
decl_stmt|;
comment|/* received reports for our groups */
name|uint64_t
name|igps_rcv_nora
decl_stmt|;
comment|/* received w/o Router Alert option */
name|uint64_t
name|igps_snd_reports
decl_stmt|;
comment|/* sent membership reports */
comment|/* 	 * Padding for future additions. 	 */
name|uint64_t
name|__igps_pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGPS_VERSION_3
value|3
end_define

begin_comment
comment|/* as of FreeBSD 8.x */
end_comment

begin_define
define|#
directive|define
name|IGPS_VERSION3_LEN
value|168
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IGMPSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|V_igmpstat.name += (val)
end_define

begin_define
define|#
directive|define
name|IGMPSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|IGMPSTAT_ADD(name, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|igmpstat
argument_list|)
operator|==
literal|168
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IGMP_RANDOM_DELAY
parameter_list|(
name|X
parameter_list|)
value|(random() % (X) + 1)
end_define

begin_define
define|#
directive|define
name|IGMP_MAX_STATE_CHANGES
value|24
end_define

begin_comment
comment|/* Max pending changes per group */
end_comment

begin_comment
comment|/*  * IGMP per-group states.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_NOT_MEMBER
value|0
end_define

begin_comment
comment|/* Can garbage collect in_multi */
end_comment

begin_define
define|#
directive|define
name|IGMP_SILENT_MEMBER
value|1
end_define

begin_comment
comment|/* Do not perform IGMP for group */
end_comment

begin_define
define|#
directive|define
name|IGMP_REPORTING_MEMBER
value|2
end_define

begin_comment
comment|/* IGMPv1/2/3 we are reporter */
end_comment

begin_define
define|#
directive|define
name|IGMP_IDLE_MEMBER
value|3
end_define

begin_comment
comment|/* IGMPv1/2 we reported last */
end_comment

begin_define
define|#
directive|define
name|IGMP_LAZY_MEMBER
value|4
end_define

begin_comment
comment|/* IGMPv1/2 other member reporting */
end_comment

begin_define
define|#
directive|define
name|IGMP_SLEEPING_MEMBER
value|5
end_define

begin_comment
comment|/* IGMPv1/2 start query response */
end_comment

begin_define
define|#
directive|define
name|IGMP_AWAKENING_MEMBER
value|6
end_define

begin_comment
comment|/* IGMPv1/2 group timer will start */
end_comment

begin_define
define|#
directive|define
name|IGMP_G_QUERY_PENDING_MEMBER
value|7
end_define

begin_comment
comment|/* IGMPv3 group query pending */
end_comment

begin_define
define|#
directive|define
name|IGMP_SG_QUERY_PENDING_MEMBER
value|8
end_define

begin_comment
comment|/* IGMPv3 source query pending */
end_comment

begin_define
define|#
directive|define
name|IGMP_LEAVING_MEMBER
value|9
end_define

begin_comment
comment|/* IGMPv3 dying gasp (pending last */
end_comment

begin_comment
comment|/* retransmission of INCLUDE {}) */
end_comment

begin_comment
comment|/*  * IGMP version tag.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_VERSION_NONE
value|0
end_define

begin_comment
comment|/* Invalid */
end_comment

begin_define
define|#
directive|define
name|IGMP_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_VERSION_2
value|2
end_define

begin_define
define|#
directive|define
name|IGMP_VERSION_3
value|3
end_define

begin_comment
comment|/* Default */
end_comment

begin_comment
comment|/*  * IGMPv3 protocol control variables.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_RV_INIT
value|2
end_define

begin_comment
comment|/* Robustness Variable */
end_comment

begin_define
define|#
directive|define
name|IGMP_RV_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_RV_MAX
value|7
end_define

begin_define
define|#
directive|define
name|IGMP_QI_INIT
value|125
end_define

begin_comment
comment|/* Query Interval (s) */
end_comment

begin_define
define|#
directive|define
name|IGMP_QI_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_QI_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IGMP_QRI_INIT
value|10
end_define

begin_comment
comment|/* Query Response Interval (s) */
end_comment

begin_define
define|#
directive|define
name|IGMP_QRI_MIN
value|1
end_define

begin_define
define|#
directive|define
name|IGMP_QRI_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IGMP_URI_INIT
value|3
end_define

begin_comment
comment|/* Unsolicited Report Interval (s) */
end_comment

begin_define
define|#
directive|define
name|IGMP_URI_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IGMP_URI_MAX
value|10
end_define

begin_define
define|#
directive|define
name|IGMP_MAX_G_GS_PACKETS
value|8
end_define

begin_comment
comment|/* # of packets to answer G/GS */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_STATE_CHANGE_PACKETS
value|8
end_define

begin_comment
comment|/* # of packets per state change */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_RESPONSE_PACKETS
value|16
end_define

begin_comment
comment|/* # of packets for general query */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_RESPONSE_BURST
value|4
end_define

begin_comment
comment|/* # of responses to send at once */
end_comment

begin_define
define|#
directive|define
name|IGMP_RESPONSE_BURST_INTERVAL
value|(PR_FASTHZ / 2)
end_define

begin_comment
comment|/* 500ms */
end_comment

begin_comment
comment|/*  * IGMP-specific mbuf flags.  */
end_comment

begin_define
define|#
directive|define
name|M_IGMPV2
value|M_PROTO1
end_define

begin_comment
comment|/* Packet is IGMPv2 */
end_comment

begin_define
define|#
directive|define
name|M_IGMPV3_HDR
value|M_PROTO2
end_define

begin_comment
comment|/* Packet has IGMPv3 headers */
end_comment

begin_define
define|#
directive|define
name|M_GROUPREC
value|M_PROTO3
end_define

begin_comment
comment|/* mbuf chain is a group record */
end_comment

begin_define
define|#
directive|define
name|M_IGMP_LOOP
value|M_PROTO4
end_define

begin_comment
comment|/* transmit on loif, not real ifp */
end_comment

begin_comment
comment|/*  * Default amount of leading space for IGMPv3 to allocate at the  * beginning of its mbuf packet chains, to avoid fragmentation and  * unnecessary allocation of leading mbufs.  */
end_comment

begin_define
define|#
directive|define
name|RAOPT_LEN
value|4
end_define

begin_comment
comment|/* Length of IP Router Alert option */
end_comment

begin_define
define|#
directive|define
name|IGMP_LEADINGSPACE
define|\
value|(sizeof(struct ip) + RAOPT_LEN + sizeof(struct igmp_report))
end_define

begin_comment
comment|/*  * Subsystem lock macros.  * The IGMP lock is only taken with IGMP. Currently it is system-wide.  * VIMAGE: The lock could be pushed to per-VIMAGE granularity in future.  */
end_comment

begin_define
define|#
directive|define
name|IGMP_LOCK_INIT
parameter_list|()
value|mtx_init(&igmp_mtx, "igmp_mtx", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IGMP_LOCK_DESTROY
parameter_list|()
value|mtx_destroy(&igmp_mtx)
end_define

begin_define
define|#
directive|define
name|IGMP_LOCK
parameter_list|()
value|mtx_lock(&igmp_mtx)
end_define

begin_define
define|#
directive|define
name|IGMP_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&igmp_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IGMP_UNLOCK
parameter_list|()
value|mtx_unlock(&igmp_mtx)
end_define

begin_define
define|#
directive|define
name|IGMP_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&igmp_mtx, MA_NOTOWNED)
end_define

begin_struct_decl
struct_decl|struct
name|igmp_ifinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|igmp_change_state
parameter_list|(
name|struct
name|in_multi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|igmp_fasttimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|igmp_ifinfo
modifier|*
name|igmp_domifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|igmp_domifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|igmp_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|igmp_input
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

begin_function_decl
name|void
name|igmp_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_igmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Identifiers for IGMP sysctl nodes  */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

