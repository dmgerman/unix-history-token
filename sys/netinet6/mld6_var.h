begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Bruce Simpson.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_MLD6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_MLD6_VAR_H_
end_define

begin_comment
comment|/*  * Multicast Listener Discovery (MLD)  * implementation-specific definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Per-link MLD state.  */
end_comment

begin_struct
struct|struct
name|mld_ifinfo
block|{
name|LIST_ENTRY
argument_list|(
argument|mld_ifinfo
argument_list|)
name|mli_link
expr_stmt|;
name|struct
name|ifnet
modifier|*
name|mli_ifp
decl_stmt|;
comment|/* interface this instance belongs to */
name|uint32_t
name|mli_version
decl_stmt|;
comment|/* MLDv1 Host Compatibility Mode */
name|uint32_t
name|mli_v1_timer
decl_stmt|;
comment|/* MLDv1 Querier Present timer (s) */
name|uint32_t
name|mli_v2_timer
decl_stmt|;
comment|/* MLDv2 General Query (interface) timer (s)*/
name|uint32_t
name|mli_flags
decl_stmt|;
comment|/* MLD per-interface flags */
name|uint32_t
name|mli_rv
decl_stmt|;
comment|/* MLDv2 Robustness Variable */
name|uint32_t
name|mli_qi
decl_stmt|;
comment|/* MLDv2 Query Interval (s) */
name|uint32_t
name|mli_qri
decl_stmt|;
comment|/* MLDv2 Query Response Interval (s) */
name|uint32_t
name|mli_uri
decl_stmt|;
comment|/* MLDv2 Unsolicited Report Interval (s) */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|in6_multi
argument_list|)
name|mli_relinmhead
expr_stmt|;
comment|/* released groups */
name|struct
name|ifqueue
name|mli_gq
decl_stmt|;
comment|/* queue of general query responses */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLIF_SILENT
value|0x00000001
end_define

begin_comment
comment|/* Do not use MLD on this ifp */
end_comment

begin_define
define|#
directive|define
name|MLIF_USEALLOW
value|0x00000002
end_define

begin_comment
comment|/* Use ALLOW/BLOCK for joins/leaves */
end_comment

begin_define
define|#
directive|define
name|MLD_RANDOM_DELAY
parameter_list|(
name|X
parameter_list|)
value|(arc4random() % (X) + 1)
end_define

begin_define
define|#
directive|define
name|MLD_MAX_STATE_CHANGES
value|24
end_define

begin_comment
comment|/* Max pending changes per group */
end_comment

begin_comment
comment|/*  * MLD per-group states.  */
end_comment

begin_define
define|#
directive|define
name|MLD_NOT_MEMBER
value|0
end_define

begin_comment
comment|/* Can garbage collect group */
end_comment

begin_define
define|#
directive|define
name|MLD_SILENT_MEMBER
value|1
end_define

begin_comment
comment|/* Do not perform MLD for group */
end_comment

begin_define
define|#
directive|define
name|MLD_REPORTING_MEMBER
value|2
end_define

begin_comment
comment|/* MLDv1 we are reporter */
end_comment

begin_define
define|#
directive|define
name|MLD_IDLE_MEMBER
value|3
end_define

begin_comment
comment|/* MLDv1 we reported last */
end_comment

begin_define
define|#
directive|define
name|MLD_LAZY_MEMBER
value|4
end_define

begin_comment
comment|/* MLDv1 other member reporting */
end_comment

begin_define
define|#
directive|define
name|MLD_SLEEPING_MEMBER
value|5
end_define

begin_comment
comment|/* MLDv1 start query response */
end_comment

begin_define
define|#
directive|define
name|MLD_AWAKENING_MEMBER
value|6
end_define

begin_comment
comment|/* MLDv1 group timer will start */
end_comment

begin_define
define|#
directive|define
name|MLD_G_QUERY_PENDING_MEMBER
value|7
end_define

begin_comment
comment|/* MLDv2 group query pending */
end_comment

begin_define
define|#
directive|define
name|MLD_SG_QUERY_PENDING_MEMBER
value|8
end_define

begin_comment
comment|/* MLDv2 source query pending */
end_comment

begin_define
define|#
directive|define
name|MLD_LEAVING_MEMBER
value|9
end_define

begin_comment
comment|/* MLDv2 dying gasp (pending last */
end_comment

begin_comment
comment|/* retransmission of INCLUDE {}) */
end_comment

begin_comment
comment|/*  * MLD version tag.  */
end_comment

begin_define
define|#
directive|define
name|MLD_VERSION_NONE
value|0
end_define

begin_comment
comment|/* Invalid */
end_comment

begin_define
define|#
directive|define
name|MLD_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|MLD_VERSION_2
value|2
end_define

begin_comment
comment|/* Default */
end_comment

begin_comment
comment|/*  * MLDv2 protocol control variables.  */
end_comment

begin_define
define|#
directive|define
name|MLD_RV_INIT
value|2
end_define

begin_comment
comment|/* Robustness Variable */
end_comment

begin_define
define|#
directive|define
name|MLD_RV_MIN
value|1
end_define

begin_define
define|#
directive|define
name|MLD_RV_MAX
value|7
end_define

begin_define
define|#
directive|define
name|MLD_QI_INIT
value|125
end_define

begin_comment
comment|/* Query Interval (s) */
end_comment

begin_define
define|#
directive|define
name|MLD_QI_MIN
value|1
end_define

begin_define
define|#
directive|define
name|MLD_QI_MAX
value|255
end_define

begin_define
define|#
directive|define
name|MLD_QRI_INIT
value|10
end_define

begin_comment
comment|/* Query Response Interval (s) */
end_comment

begin_define
define|#
directive|define
name|MLD_QRI_MIN
value|1
end_define

begin_define
define|#
directive|define
name|MLD_QRI_MAX
value|255
end_define

begin_define
define|#
directive|define
name|MLD_URI_INIT
value|3
end_define

begin_comment
comment|/* Unsolicited Report Interval (s) */
end_comment

begin_define
define|#
directive|define
name|MLD_URI_MIN
value|0
end_define

begin_define
define|#
directive|define
name|MLD_URI_MAX
value|10
end_define

begin_define
define|#
directive|define
name|MLD_MAX_GS_SOURCES
value|256
end_define

begin_comment
comment|/* # of sources in rx GS query */
end_comment

begin_define
define|#
directive|define
name|MLD_MAX_G_GS_PACKETS
value|8
end_define

begin_comment
comment|/* # of packets to answer G/GS */
end_comment

begin_define
define|#
directive|define
name|MLD_MAX_STATE_CHANGE_PACKETS
value|8
end_define

begin_comment
comment|/* # of packets per state change */
end_comment

begin_define
define|#
directive|define
name|MLD_MAX_RESPONSE_PACKETS
value|16
end_define

begin_comment
comment|/* # of packets for general query */
end_comment

begin_define
define|#
directive|define
name|MLD_MAX_RESPONSE_BURST
value|4
end_define

begin_comment
comment|/* # of responses to send at once */
end_comment

begin_define
define|#
directive|define
name|MLD_RESPONSE_BURST_INTERVAL
value|(PR_FASTHZ / 2)
end_define

begin_comment
comment|/* 500ms */
end_comment

begin_comment
comment|/*  * MLD-specific mbuf flags.  */
end_comment

begin_define
define|#
directive|define
name|M_MLDV1
value|M_PROTO1
end_define

begin_comment
comment|/* Packet is MLDv1 */
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

begin_comment
comment|/*  * Leading space for MLDv2 reports inside MTU.  *  * NOTE: This differs from IGMPv3 significantly. KAME IPv6 requires  * that a fully formed mbuf chain *without* the Router Alert option  * is passed to ip6_output(), however we must account for it in the  * MTU if we need to split an MLDv2 report into several packets.  *  * We now put the MLDv2 report header in the initial mbuf containing  * the IPv6 header.  */
end_comment

begin_define
define|#
directive|define
name|MLD_MTUSPACE
value|(sizeof(struct ip6_hdr) + sizeof(struct mld_raopt) + \ 			 sizeof(struct icmp6_hdr))
end_define

begin_comment
comment|/*  * Subsystem lock macros.  * The MLD lock is only taken with MLD. Currently it is system-wide.  * VIMAGE: The lock could be pushed to per-VIMAGE granularity in future.  */
end_comment

begin_define
define|#
directive|define
name|MLD_LOCK_INIT
parameter_list|()
value|mtx_init(&mld_mtx, "mld_mtx", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|MLD_LOCK_DESTROY
parameter_list|()
value|mtx_destroy(&mld_mtx)
end_define

begin_define
define|#
directive|define
name|MLD_LOCK
parameter_list|()
value|mtx_lock(&mld_mtx)
end_define

begin_define
define|#
directive|define
name|MLD_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&mld_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MLD_UNLOCK
parameter_list|()
value|mtx_unlock(&mld_mtx)
end_define

begin_define
define|#
directive|define
name|MLD_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&mld_mtx, MA_NOTOWNED)
end_define

begin_comment
comment|/*  * Per-link MLD context.  */
end_comment

begin_define
define|#
directive|define
name|MLD_IFINFO
parameter_list|(
name|ifp
parameter_list|)
define|\
value|(((struct in6_ifextra *)(ifp)->if_afdata[AF_INET6])->mld_ifinfo)
end_define

begin_function_decl
name|int
name|mld_change_state
parameter_list|(
name|struct
name|in6_multi
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mld_ifinfo
modifier|*
name|mld_domifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld_domifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld_fasttimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mld_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mld_input
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

begin_function_decl
name|void
name|mld_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet6_mld
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_MLD6_VAR_H_ */
end_comment

end_unit

