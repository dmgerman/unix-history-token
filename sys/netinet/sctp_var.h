begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_var.h,v 1.24 2005/03/06 16:04:19 itojun Exp $	 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_SCTP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_VAR_H_
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_comment
comment|/* SCTP Kernel structures */
end_comment

begin_comment
comment|/*  * Names for SCTP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM
value|1
end_define

begin_comment
comment|/* max datagram size */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RECVSPACE
value|2
end_define

begin_comment
comment|/* default receive buffer space */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_AUTOASCONF
value|3
end_define

begin_comment
comment|/* auto asconf enable/disable flag */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE
value|4
end_define

begin_comment
comment|/* Is ecn allowed */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE
value|5
end_define

begin_comment
comment|/* Is ecn nonce allowed */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACK
value|6
end_define

begin_comment
comment|/* strictly require sack'd TSN's to be 					 * smaller than sndnxt. */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_NOCSUM_LO
value|7
end_define

begin_comment
comment|/* Require that the Loopback NOT have 					 * the crc32 checksum on packets 					 * routed over it. */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_INIT
value|8
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHK_OH
value|9
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST
value|10
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKONQ
value|11
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK
value|12
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HB_INTERVAL
value|13
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE
value|14
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD
value|15
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME
value|16
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX
value|17
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN
value|18
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL
value|19
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX
value|20
end_define

begin_define
define|#
directive|define
name|SCTPCTL_COOKIE_LIFE
value|21
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTX_MAX
value|22
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASSOC_RTX_MAX
value|23
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_RTX_MAX
value|24
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NR_OUTGOING_STREAMS
value|25
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF
value|26
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST
value|27
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FR
value|28
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_CC
value|29
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DET
value|30
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FR_MSEC
value|31
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK
value|32
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE
value|33
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_RANDOM_LEN
value|34
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_HMAC_ID
value|35
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABC_L_VAR
value|36
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_MBUF_CHAIN
value|37
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC
value|38
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DO_DRAIN
value|39
end_define

begin_define
define|#
directive|define
name|SCTPCTL_WARM_CRC32
value|40
end_define

begin_define
define|#
directive|define
name|SCTPCTL_QLIMIT_ABORT
value|41
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_ORDER
value|42
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE
value|43
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE
value|44
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE
value|45
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MINSPLIT
value|46
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE
value|47
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SYS_RESC
value|48
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASOC_RESC
value|49
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY
value|50
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG
value|51
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXID
value|51
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTPCTL_MAXID
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCTPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "autoasconf", CTLTYPE_INT }, \ 	{ "ecn_enable", CTLTYPE_INT }, \ 	{ "ecn_nonce", CTLTYPE_INT }, \ 	{ "strict_sack", CTLTYPE_INT }, \ 	{ "looback_nocsum", CTLTYPE_INT }, \ 	{ "strict_init", CTLTYPE_INT }, \ 	{ "peer_chkoh", CTLTYPE_INT }, \ 	{ "maxburst", CTLTYPE_INT }, \ 	{ "maxchunks", CTLTYPE_INT }, \ 	{ "delayed_sack_time", CTLTYPE_INT }, \ 	{ "heartbeat_interval", CTLTYPE_INT }, \ 	{ "pmtu_raise_time", CTLTYPE_INT }, \ 	{ "shutdown_guard_time", CTLTYPE_INT }, \ 	{ "secret_lifetime", CTLTYPE_INT }, \ 	{ "rto_max", CTLTYPE_INT }, \ 	{ "rto_min", CTLTYPE_INT }, \ 	{ "rto_initial", CTLTYPE_INT }, \ 	{ "init_rto_max", CTLTYPE_INT }, \ 	{ "valid_cookie_life", CTLTYPE_INT }, \ 	{ "init_rtx_max", CTLTYPE_INT }, \ 	{ "assoc_rtx_max", CTLTYPE_INT }, \ 	{ "path_rtx_max", CTLTYPE_INT }, \ 	{ "nr_outgoing_streams", CTLTYPE_INT }, \ 	{ "cmt_on_off", CTLTYPE_INT }, \ 	{ "cwnd_maxburst", CTLTYPE_INT }, \ 	{ "early_fast_retran", CTLTYPE_INT }, \ 	{ "use_rttvar_congctrl", CTLTYPE_INT }, \ 	{ "deadlock_detect", CTLTYPE_INT }, \ 	{ "early_fast_retran_msec", CTLTYPE_INT }, \ 	{ "asconf_auth_nochk", CTLTYPE_INT }, \ 	{ "auth_disable", CTLTYPE_INT }, \ 	{ "auth_random_len", CTLTYPE_INT }, \ 	{ "auth_hmac_id", CTLTYPE_INT }, \ 	{ "abc_l_var", CTLTYPE_INT }, \ 	{ "max_mbuf_chain", CTLTYPE_INT }, \ 	{ "cmt_use_dac", CTLTYPE_INT }, \ 	{ "do_sctp_drain", CTLTYPE_INT }, \ 	{ "warm_crc_table", CTLTYPE_INT }, \ 	{ "abort_at_limit", CTLTYPE_INT }, \ 	{ "strict_data_order", CTLTYPE_INT }, \ 	{ "tcbhashsize", CTLTYPE_INT }, \ 	{ "pcbhashsize", CTLTYPE_INT }, \ 	{ "chunkscale", CTLTYPE_INT }, \ 	{ "min_split_point", CTLTYPE_INT }, \ 	{ "add_more_on_output", CTLTYPE_INT }, \ 	{ "sys_resource", CTLTYPE_INT }, \ 	{ "asoc_resource", CTLTYPE_INT }, \ 	{ "nat_friendly", CTLTYPE_INT }, \ 	{ "debug", CTLTYPE_INT }, \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "autoasconf", CTLTYPE_INT }, \ 	{ "ecn_enable", CTLTYPE_INT }, \ 	{ "ecn_nonce", CTLTYPE_INT }, \ 	{ "strict_sack", CTLTYPE_INT }, \ 	{ "looback_nocsum", CTLTYPE_INT }, \ 	{ "strict_init", CTLTYPE_INT }, \ 	{ "peer_chkoh", CTLTYPE_INT }, \ 	{ "maxburst", CTLTYPE_INT }, \ 	{ "maxchunks", CTLTYPE_INT }, \ 	{ "delayed_sack_time", CTLTYPE_INT }, \ 	{ "heartbeat_interval", CTLTYPE_INT }, \ 	{ "pmtu_raise_time", CTLTYPE_INT }, \ 	{ "shutdown_guard_time", CTLTYPE_INT }, \ 	{ "secret_lifetime", CTLTYPE_INT }, \ 	{ "rto_max", CTLTYPE_INT }, \ 	{ "rto_min", CTLTYPE_INT }, \ 	{ "rto_initial", CTLTYPE_INT }, \ 	{ "init_rto_max", CTLTYPE_INT }, \ 	{ "valid_cookie_life", CTLTYPE_INT }, \ 	{ "init_rtx_max", CTLTYPE_INT }, \ 	{ "assoc_rtx_max", CTLTYPE_INT }, \ 	{ "path_rtx_max", CTLTYPE_INT }, \ 	{ "nr_outgoing_streams", CTLTYPE_INT }, \ 	{ "cmt_on_off", CTLTYPE_INT }, \ 	{ "cwnd_maxburst", CTLTYPE_INT }, \ 	{ "early_fast_retran", CTLTYPE_INT }, \ 	{ "use_rttvar_congctrl", CTLTYPE_INT }, \ 	{ "deadlock_detect", CTLTYPE_INT }, \ 	{ "early_fast_retran_msec", CTLTYPE_INT }, \ 	{ "asconf_auth_nochk", CTLTYPE_INT }, \ 	{ "auth_disable", CTLTYPE_INT }, \ 	{ "auth_random_len", CTLTYPE_INT }, \ 	{ "auth_hmac_id", CTLTYPE_INT }, \ 	{ "abc_l_var", CTLTYPE_INT }, \ 	{ "max_mbuf_chain", CTLTYPE_INT }, \ 	{ "cmt_use_dac", CTLTYPE_INT }, \ 	{ "do_sctp_drain", CTLTYPE_INT }, \ 	{ "warm_crc_table", CTLTYPE_INT }, \ 	{ "abort_at_limit", CTLTYPE_INT }, \ 	{ "strict_data_order", CTLTYPE_INT }, \ 	{ "tcbhashsize", CTLTYPE_INT }, \ 	{ "pcbhashsize", CTLTYPE_INT }, \ 	{ "chunkscale", CTLTYPE_INT }, \ 	{ "min_split_point", CTLTYPE_INT }, \ 	{ "add_more_on_output", CTLTYPE_INT }, \ 	{ "sys_resource", CTLTYPE_INT }, \ 	{ "asoc_resource", CTLTYPE_INT }, \ 	{ "nat_friendly", CTLTYPE_INT }, \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_sctp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|sctp_usrreqs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sctp_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_features |= feature)
end_define

begin_define
define|#
directive|define
name|sctp_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_features&= ~feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_features& feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|((inp->sctp_features& feature) == 0)
end_define

begin_define
define|#
directive|define
name|sctp_sbspace
parameter_list|(
name|asoc
parameter_list|,
name|sb
parameter_list|)
value|((long) (((sb)->sb_hiwat> (asoc)->sb_cc) ? ((sb)->sb_hiwat - (asoc)->sb_cc) : 0))
end_define

begin_define
define|#
directive|define
name|sctp_sbspace_failedmsgs
parameter_list|(
name|sb
parameter_list|)
value|((long) (((sb)->sb_hiwat> (sb)->sb_cc) ? ((sb)->sb_hiwat - (sb)->sb_cc) : 0))
end_define

begin_define
define|#
directive|define
name|sctp_sbspace_sub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? (a - b) : 0)
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_asoc_free_resc_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_system_free_resc_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I tried to cache the readq entries at one  * point. But the reality is that it did not  * add any performance since this meant  * we had to lock the STCB on read. And at that point  * once you have to do an extra lock, it really does  * not matter if the lock is in the ZONE stuff or  * in our code. Note that this same problem would  * occur with an mbuf cache as well so it is  * not really worth doing, at least right now :-D  */
end_comment

begin_define
define|#
directive|define
name|sctp_free_a_readq
parameter_list|(
name|_stcb
parameter_list|,
name|_readq
parameter_list|)
value|{ \ 	SCTP_ZONE_FREE(sctppcbinfo.ipi_zone_readq, (_readq)); \ 	SCTP_DECR_READQ_COUNT(); \ }
end_define

begin_define
define|#
directive|define
name|sctp_alloc_a_readq
parameter_list|(
name|_stcb
parameter_list|,
name|_readq
parameter_list|)
value|{ \ 	(_readq) = SCTP_ZONE_GET(sctppcbinfo.ipi_zone_readq, struct sctp_queued_to_read); \ 	if ((_readq)) { \  	     SCTP_INCR_READQ_COUNT(); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_a_strmoq
parameter_list|(
name|_stcb
parameter_list|,
name|_strmoq
parameter_list|)
value|{ \ 	if (((_stcb)->asoc.free_strmoq_cnt> sctp_asoc_free_resc_limit) || \ 	    (sctppcbinfo.ipi_free_strmoq> sctp_system_free_resc_limit)) { \ 		SCTP_ZONE_FREE(sctppcbinfo.ipi_zone_strmoq, (_strmoq)); \ 		SCTP_DECR_STRMOQ_COUNT(); \ 	} else { \ 		TAILQ_INSERT_TAIL(&(_stcb)->asoc.free_strmoq, (_strmoq), next); \ 		(_stcb)->asoc.free_strmoq_cnt++; \ 		atomic_add_int(&sctppcbinfo.ipi_free_strmoq, 1); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_alloc_a_strmoq
parameter_list|(
name|_stcb
parameter_list|,
name|_strmoq
parameter_list|)
value|{ \ 	if (TAILQ_EMPTY(&(_stcb)->asoc.free_strmoq))  { \ 		(_strmoq) = SCTP_ZONE_GET(sctppcbinfo.ipi_zone_strmoq, struct sctp_stream_queue_pending); \ 		if ((_strmoq)) { \ 			SCTP_INCR_STRMOQ_COUNT(); \ 		} \ 	} else { \ 		(_strmoq) = TAILQ_FIRST(&(_stcb)->asoc.free_strmoq); \ 		TAILQ_REMOVE(&(_stcb)->asoc.free_strmoq, (_strmoq), next); \ 		atomic_subtract_int(&sctppcbinfo.ipi_free_strmoq, 1); \ 		(_stcb)->asoc.free_strmoq_cnt--; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_a_chunk
parameter_list|(
name|_stcb
parameter_list|,
name|_chk
parameter_list|)
value|{ \ 	if (((_stcb)->asoc.free_chunk_cnt> sctp_asoc_free_resc_limit) || \ 	    (sctppcbinfo.ipi_free_chunks> sctp_system_free_resc_limit)) { \ 		SCTP_ZONE_FREE(sctppcbinfo.ipi_zone_chunk, (_chk)); \ 		SCTP_DECR_CHK_COUNT(); \ 	} else { \ 		TAILQ_INSERT_TAIL(&(_stcb)->asoc.free_chunks, (_chk), sctp_next); \ 		(_stcb)->asoc.free_chunk_cnt++; \ 		atomic_add_int(&sctppcbinfo.ipi_free_chunks, 1); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_alloc_a_chunk
parameter_list|(
name|_stcb
parameter_list|,
name|_chk
parameter_list|)
value|{ \ 	if (TAILQ_EMPTY(&(_stcb)->asoc.free_chunks))  { \ 		(_chk) = SCTP_ZONE_GET(sctppcbinfo.ipi_zone_chunk, struct sctp_tmit_chunk); \ 		if ((_chk)) { \ 			SCTP_INCR_CHK_COUNT(); \ 		} \ 	} else { \ 		(_chk) = TAILQ_FIRST(&(_stcb)->asoc.free_chunks); \ 		TAILQ_REMOVE(&(_stcb)->asoc.free_chunks, (_chk), sctp_next); \ 		atomic_subtract_int(&sctppcbinfo.ipi_free_chunks, 1); \ 		(_stcb)->asoc.free_chunk_cnt--; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_remote_addr
parameter_list|(
name|__net
parameter_list|)
value|{ \ 	if ((__net)) { \ 		if (atomic_fetchadd_int(&(__net)->ref_count, -1) == 1) { \ 			SCTP_OS_TIMER_STOP(&(__net)->rxt_timer.timer); \ 			SCTP_OS_TIMER_STOP(&(__net)->pmtu_timer.timer); \ 			SCTP_OS_TIMER_STOP(&(__net)->fr_timer.timer); \ 			(__net)->dest_state = SCTP_ADDR_NOT_REACHABLE; \ 			SCTP_ZONE_FREE(sctppcbinfo.ipi_zone_net, (__net)); \ 			SCTP_DECR_RADDR_COUNT(); \ 		} \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_sbfree
parameter_list|(
name|ctl
parameter_list|,
name|stcb
parameter_list|,
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	uint32_t val; \ 	val = atomic_fetchadd_int(&(sb)->sb_cc,-(SCTP_BUF_LEN((m)))); \ 	if (val< SCTP_BUF_LEN((m))) { \ 	   panic("sb_cc goes negative"); \ 	} \ 	val = atomic_fetchadd_int(&(sb)->sb_mbcnt,-(MSIZE)); \ 	if (val< MSIZE) { \ 	    panic("sb_mbcnt goes negative"); \ 	} \ 	if (SCTP_BUF_IS_EXTENDED(m)) { \ 		val = atomic_fetchadd_int(&(sb)->sb_mbcnt,-(SCTP_BUF_EXTEND_SIZE(m))); \ 		if (val< SCTP_BUF_EXTEND_SIZE(m)) { \ 		    panic("sb_mbcnt goes negative2"); \ 		} \ 	} \ 	if (((ctl)->do_not_ref_stcb == 0)&& stcb) {\ 	  val = atomic_fetchadd_int(&(stcb)->asoc.sb_cc,-(SCTP_BUF_LEN((m)))); \ 	  if (val< SCTP_BUF_LEN((m))) {\ 	     panic("stcb->sb_cc goes negative"); \ 	  } \ 	  val = atomic_fetchadd_int(&(stcb)->asoc.sb_mbcnt,-(MSIZE)); \ 	  if (val< MSIZE) { \ 	     panic("asoc->mbcnt goes negative"); \ 	  } \ 	  if (SCTP_BUF_IS_EXTENDED(m)) { \ 		val = atomic_fetchadd_int(&(stcb)->asoc.sb_mbcnt,-(SCTP_BUF_EXTEND_SIZE(m))); \ 		if (val< SCTP_BUF_EXTEND_SIZE(m)) { \ 		   panic("assoc stcb->mbcnt would go negative"); \ 		} \ 	  } \ 	} \ 	if (SCTP_BUF_TYPE(m) != MT_DATA&& SCTP_BUF_TYPE(m) != MT_HEADER&& \ 	    SCTP_BUF_TYPE(m) != MT_OOBDATA) \ 		atomic_subtract_int(&(sb)->sb_ctl,SCTP_BUF_LEN((m))); \ }
end_define

begin_define
define|#
directive|define
name|sctp_sballoc
parameter_list|(
name|stcb
parameter_list|,
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	atomic_add_int(&(sb)->sb_cc,SCTP_BUF_LEN((m))); \ 	atomic_add_int(&(sb)->sb_mbcnt, MSIZE); \ 	if (SCTP_BUF_IS_EXTENDED(m)) \ 		atomic_add_int(&(sb)->sb_mbcnt,SCTP_BUF_EXTEND_SIZE(m)); \ 	if (stcb) { \ 		atomic_add_int(&(stcb)->asoc.sb_cc,SCTP_BUF_LEN((m))); \ 		atomic_add_int(&(stcb)->asoc.sb_mbcnt, MSIZE); \ 		if (SCTP_BUF_IS_EXTENDED(m)) \ 			atomic_add_int(&(stcb)->asoc.sb_mbcnt,SCTP_BUF_EXTEND_SIZE(m)); \ 	} \ 	if (SCTP_BUF_TYPE(m) != MT_DATA&& SCTP_BUF_TYPE(m) != MT_HEADER&& \ 	    SCTP_BUF_TYPE(m) != MT_OOBDATA) \ 		atomic_add_int(&(sb)->sb_ctl,SCTP_BUF_LEN((m))); \ }
end_define

begin_define
define|#
directive|define
name|sctp_ucount_incr
parameter_list|(
name|val
parameter_list|)
value|{ \ 	val++; \ }
end_define

begin_define
define|#
directive|define
name|sctp_ucount_decr
parameter_list|(
name|val
parameter_list|)
value|{ \ 	if (val> 0) { \ 		val--; \ 	} else { \ 		val = 0; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_mbuf_crush
parameter_list|(
name|data
parameter_list|)
value|do { \ 	struct mbuf *_m; \ 	_m = (data); \ 	while(_m&& (SCTP_BUF_LEN(_m) == 0)) { \ 		(data)  = SCTP_BUF_NEXT(_m); \ 		SCTP_BUF_NEXT(_m) = NULL; \ 		sctp_m_free(_m); \ 		_m = (data); \ 	} \ } while (0)
end_define

begin_comment
comment|/*  * some sysctls  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sctp_sendspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sctp_recvspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sctp_ecn_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sctp_ecn_nonce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sctp_use_cwnd_based_maxburst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|sctp_cmt_on_off
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|sctp_cmt_use_dac
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|sctp_cmt_sockopt_on_off
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_nat_friendly
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sctp_nets
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctp_inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctp_tcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctphdr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|sctp_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_ctloutput
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|sockopt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sctp_input
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
name|sctp_drain
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
name|sctp_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sctp_pcbinfo_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|sctp_shutdown
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sctp_notify
name|__P
argument_list|(
operator|(
expr|struct
name|sctp_inpcb
operator|*
operator|,
name|int
operator|,
expr|struct
name|sctphdr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sctp_tcb
operator|*
operator|,
expr|struct
name|sctp_nets
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INET6
argument_list|)
end_if

begin_decl_stmt
name|void
name|ip_2_ip6_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|ip6_hdr
operator|*
operator|,
expr|struct
name|ip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|sctp_bindx
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* can't use sctp_assoc_t here */
end_comment

begin_function_decl
name|int
name|sctp_peeloff
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sctp_assoc_t
name|sctp_getassocid
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_ingetaddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_peeraddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_listen
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_accept
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_NETINET_SCTP_VAR_H_ */
end_comment

end_unit

