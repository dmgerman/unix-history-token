begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|_NETINET_SCTP_SYSCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_SYSCTL_H_
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_os.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_constants.h>
end_include

begin_struct
struct|struct
name|sctp_sysctl
block|{
name|uint32_t
name|sctp_sendspace
decl_stmt|;
name|uint32_t
name|sctp_recvspace
decl_stmt|;
name|uint32_t
name|sctp_auto_asconf
decl_stmt|;
name|uint32_t
name|sctp_multiple_asconfs
decl_stmt|;
name|uint32_t
name|sctp_ecn_enable
decl_stmt|;
name|uint32_t
name|sctp_pr_enable
decl_stmt|;
name|uint32_t
name|sctp_nrsack_enable
decl_stmt|;
name|uint32_t
name|sctp_fr_max_burst_default
decl_stmt|;
name|uint32_t
name|sctp_strict_sacks
decl_stmt|;
name|uint32_t
name|sctp_peer_chunk_oh
decl_stmt|;
name|uint32_t
name|sctp_max_burst_default
decl_stmt|;
name|uint32_t
name|sctp_max_chunks_on_queue
decl_stmt|;
name|uint32_t
name|sctp_hashtblsize
decl_stmt|;
name|uint32_t
name|sctp_pcbtblsize
decl_stmt|;
name|uint32_t
name|sctp_min_split_point
decl_stmt|;
name|uint32_t
name|sctp_chunkscale
decl_stmt|;
name|uint32_t
name|sctp_delayed_sack_time_default
decl_stmt|;
name|uint32_t
name|sctp_sack_freq_default
decl_stmt|;
name|uint32_t
name|sctp_system_free_resc_limit
decl_stmt|;
name|uint32_t
name|sctp_asoc_free_resc_limit
decl_stmt|;
name|uint32_t
name|sctp_heartbeat_interval_default
decl_stmt|;
name|uint32_t
name|sctp_pmtu_raise_time_default
decl_stmt|;
name|uint32_t
name|sctp_shutdown_guard_time_default
decl_stmt|;
name|uint32_t
name|sctp_secret_lifetime_default
decl_stmt|;
name|uint32_t
name|sctp_rto_max_default
decl_stmt|;
name|uint32_t
name|sctp_rto_min_default
decl_stmt|;
name|uint32_t
name|sctp_rto_initial_default
decl_stmt|;
name|uint32_t
name|sctp_init_rto_max_default
decl_stmt|;
name|uint32_t
name|sctp_valid_cookie_life_default
decl_stmt|;
name|uint32_t
name|sctp_init_rtx_max_default
decl_stmt|;
name|uint32_t
name|sctp_assoc_rtx_max_default
decl_stmt|;
name|uint32_t
name|sctp_path_rtx_max_default
decl_stmt|;
name|uint32_t
name|sctp_path_pf_threshold
decl_stmt|;
name|uint32_t
name|sctp_add_more_threshold
decl_stmt|;
name|uint32_t
name|sctp_nr_incoming_streams_default
decl_stmt|;
name|uint32_t
name|sctp_nr_outgoing_streams_default
decl_stmt|;
name|uint32_t
name|sctp_cmt_on_off
decl_stmt|;
name|uint32_t
name|sctp_cmt_use_dac
decl_stmt|;
name|uint32_t
name|sctp_use_cwnd_based_maxburst
decl_stmt|;
name|uint32_t
name|sctp_auth_disable
decl_stmt|;
name|uint32_t
name|sctp_nat_friendly
decl_stmt|;
name|uint32_t
name|sctp_L2_abc_variable
decl_stmt|;
name|uint32_t
name|sctp_mbuf_threshold_count
decl_stmt|;
name|uint32_t
name|sctp_do_drain
decl_stmt|;
name|uint32_t
name|sctp_hb_maxburst
decl_stmt|;
name|uint32_t
name|sctp_abort_if_one_2_one_hits_limit
decl_stmt|;
name|uint32_t
name|sctp_strict_data_order
decl_stmt|;
name|uint32_t
name|sctp_min_residual
decl_stmt|;
name|uint32_t
name|sctp_max_retran_chunk
decl_stmt|;
name|uint32_t
name|sctp_logging_level
decl_stmt|;
comment|/* JRS - Variable for default congestion control module */
name|uint32_t
name|sctp_default_cc_module
decl_stmt|;
comment|/* RS - Variable for default stream scheduling module */
name|uint32_t
name|sctp_default_ss_module
decl_stmt|;
name|uint32_t
name|sctp_default_frag_interleave
decl_stmt|;
name|uint32_t
name|sctp_mobility_base
decl_stmt|;
name|uint32_t
name|sctp_mobility_fasthandoff
decl_stmt|;
name|uint32_t
name|sctp_inits_include_nat_friendly
decl_stmt|;
name|uint32_t
name|sctp_rttvar_bw
decl_stmt|;
name|uint32_t
name|sctp_rttvar_rtt
decl_stmt|;
name|uint32_t
name|sctp_rttvar_eqret
decl_stmt|;
name|uint32_t
name|sctp_steady_step
decl_stmt|;
name|uint32_t
name|sctp_use_dccc_ecn
decl_stmt|;
name|uint32_t
name|sctp_diag_info_code
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SCTP_LOCAL_TRACE_BUF
argument_list|)
name|struct
name|sctp_log
name|sctp_log
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|sctp_udp_tunneling_port
decl_stmt|;
name|uint32_t
name|sctp_enable_sack_immediately
decl_stmt|;
name|uint32_t
name|sctp_vtag_time_wait
decl_stmt|;
name|uint32_t
name|sctp_buffer_splitting
decl_stmt|;
name|uint32_t
name|sctp_initial_cwnd
decl_stmt|;
name|uint32_t
name|sctp_blackhole
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SCTP_DEBUG
argument_list|)
name|uint32_t
name|sctp_debug_on
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|SCTP_SO_LOCK_TESTING
argument_list|)
name|uint32_t
name|sctp_output_unlocked
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * limits for the sysctl variables  */
end_comment

begin_comment
comment|/* maxdgram: Maximum outgoing SCTP buffer size */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM_DESC
value|"Maximum outgoing SCTP buffer size"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM_DEFAULT
value|262144
end_define

begin_comment
comment|/* 256k */
end_comment

begin_comment
comment|/* recvspace: Maximum incoming SCTP buffer size */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RECVSPACE_DESC
value|"Maximum incoming SCTP buffer size"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RECVSPACE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RECVSPACE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RECVSPACE_DEFAULT
value|262144
end_define

begin_comment
comment|/* 256k */
end_comment

begin_comment
comment|/* autoasconf: Enable SCTP Auto-ASCONF */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_AUTOASCONF_DESC
value|"Enable SCTP Auto-ASCONF"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTOASCONF_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTOASCONF_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTOASCONF_DEFAULT
value|SCTP_DEFAULT_AUTO_ASCONF
end_define

begin_comment
comment|/* autoasconf: Enable SCTP Auto-ASCONF */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MULTIPLEASCONFS_DESC
value|"Enable SCTP Muliple-ASCONFs"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MULTIPLEASCONFS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MULTIPLEASCONFS_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MULTIPLEASCONFS_DEFAULT
value|SCTP_DEFAULT_MULTIPLE_ASCONFS
end_define

begin_comment
comment|/* ecn_enable: Enable SCTP ECN */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE_DESC
value|"Enable SCTP ECN"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE_DEFAULT
value|1
end_define

begin_comment
comment|/* pr_enable: Enable PR-SCTP */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PR_ENABLE_DESC
value|"Enable PR-SCTP"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PR_ENABLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PR_ENABLE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PR_ENABLE_DEFAULT
value|1
end_define

begin_comment
comment|/* nrsack_enable: Enable NR_SACK */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_NRSACK_ENABLE_DESC
value|"Enable NR_SACK"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NRSACK_ENABLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NRSACK_ENABLE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NRSACK_ENABLE_DEFAULT
value|0
end_define

begin_comment
comment|/* strict_sacks: Enable SCTP Strict SACK checking */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACKS_DESC
value|"Enable SCTP Strict SACK checking"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACKS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACKS_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACKS_DEFAULT
value|1
end_define

begin_comment
comment|/* loopback_nocsum: Enable NO Csum on packets sent on loopback */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_LOOPBACK_NOCSUM_DESC
value|"Enable NO Csum on packets sent on loopback"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOOPBACK_NOCSUM_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOOPBACK_NOCSUM_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOOPBACK_NOCSUM_DEFAULT
value|1
end_define

begin_comment
comment|/* peer_chkoh: Amount to debit peers rwnd per chunk sent */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHKOH_DESC
value|"Amount to debit peers rwnd per chunk sent"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHKOH_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHKOH_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHKOH_DEFAULT
value|256
end_define

begin_comment
comment|/* maxburst: Default max burst for sctp endpoints */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST_DESC
value|"Default max burst for sctp endpoints"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST_DEFAULT
value|SCTP_DEF_MAX_BURST
end_define

begin_comment
comment|/* fr_maxburst: Default max burst for sctp endpoints when fast retransmitting */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_FRMAXBURST_DESC
value|"Default fr max burst for sctp endpoints"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_FRMAXBURST_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_FRMAXBURST_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_FRMAXBURST_DEFAULT
value|SCTP_DEF_FRMAX_BURST
end_define

begin_comment
comment|/* maxchunks: Default max chunks on queue per asoc */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKS_DESC
value|"Default max chunks on queue per asoc"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKS_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKS_DEFAULT
value|SCTP_ASOC_MAX_CHUNKS_ON_QUEUE
end_define

begin_comment
comment|/* tcbhashsize: Tunable for Hash table sizes */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE_DESC
value|"Tunable for TCB hash table sizes"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE_DEFAULT
value|SCTP_TCBHASHSIZE
end_define

begin_comment
comment|/* pcbhashsize: Tunable for PCB Hash table sizes */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE_DESC
value|"Tunable for PCB hash table sizes"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE_DEFAULT
value|SCTP_PCBHASHSIZE
end_define

begin_comment
comment|/* min_split_point: Minimum size when splitting a chunk */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MIN_SPLIT_POINT_DESC
value|"Minimum size when splitting a chunk"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_SPLIT_POINT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_SPLIT_POINT_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_SPLIT_POINT_DEFAULT
value|SCTP_DEFAULT_SPLIT_POINT_MIN
end_define

begin_comment
comment|/* chunkscale: Tunable for Scaling of number of chunks and messages */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE_DESC
value|"Tunable for Scaling of number of chunks and messages"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE_DEFAULT
value|SCTP_CHUNKQUEUE_SCALE
end_define

begin_comment
comment|/* delayed_sack_time: Default delayed SACK timer in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME_DESC
value|"Default delayed SACK timer in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME_DEFAULT
value|SCTP_RECV_MSEC
end_define

begin_comment
comment|/* sack_freq: Default SACK frequency */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SACK_FREQ_DESC
value|"Default SACK frequency"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_FREQ_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_FREQ_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_FREQ_DEFAULT
value|SCTP_DEFAULT_SACK_FREQ
end_define

begin_comment
comment|/* sys_resource: Max number of cached resources in the system */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SYS_RESOURCE_DESC
value|"Max number of cached resources in the system"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SYS_RESOURCE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SYS_RESOURCE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SYS_RESOURCE_DEFAULT
value|SCTP_DEF_SYSTEM_RESC_LIMIT
end_define

begin_comment
comment|/* asoc_resource: Max number of cached resources in an asoc */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ASOC_RESOURCE_DESC
value|"Max number of cached resources in an asoc"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASOC_RESOURCE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASOC_RESOURCE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASOC_RESOURCE_DEFAULT
value|SCTP_DEF_ASOC_RESC_LIMIT
end_define

begin_comment
comment|/* heartbeat_interval: Default heartbeat interval in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL_DESC
value|"Default heartbeat interval in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL_DEFAULT
value|SCTP_HB_DEFAULT_MSEC
end_define

begin_comment
comment|/* pmtu_raise_time: Default PMTU raise timer in seconds */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME_DESC
value|"Default PMTU raise timer in seconds"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME_DEFAULT
value|SCTP_DEF_PMTU_RAISE_SEC
end_define

begin_comment
comment|/* shutdown_guard_time: Default shutdown guard timer in seconds */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME_DESC
value|"Default shutdown guard timer in seconds"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME_DEFAULT
value|SCTP_DEF_MAX_SHUTDOWN_SEC
end_define

begin_comment
comment|/* secret_lifetime: Default secret lifetime in seconds */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME_DESC
value|"Default secret lifetime in seconds"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME_DEFAULT
value|SCTP_DEFAULT_SECRET_LIFE_SEC
end_define

begin_comment
comment|/* rto_max: Default maximum retransmission timeout in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX_DESC
value|"Default maximum retransmission timeout in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX_DEFAULT
value|SCTP_RTO_UPPER_BOUND
end_define

begin_comment
comment|/* rto_min: Default minimum retransmission timeout in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN_DESC
value|"Default minimum retransmission timeout in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN_DEFAULT
value|SCTP_RTO_LOWER_BOUND
end_define

begin_comment
comment|/* rto_initial: Default initial retransmission timeout in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL_DESC
value|"Default initial retransmission timeout in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL_DEFAULT
value|SCTP_RTO_INITIAL
end_define

begin_comment
comment|/* init_rto_max: Default maximum retransmission timeout during association setup in ms */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX_DESC
value|"Default maximum retransmission timeout during association setup in ms"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX_DEFAULT
value|SCTP_RTO_UPPER_BOUND
end_define

begin_comment
comment|/* valid_cookie_life: Default cookie lifetime in sec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_VALID_COOKIE_LIFE_DESC
value|"Default cookie lifetime in seconds"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_VALID_COOKIE_LIFE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_VALID_COOKIE_LIFE_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_VALID_COOKIE_LIFE_DEFAULT
value|SCTP_DEFAULT_COOKIE_LIFE
end_define

begin_comment
comment|/* init_rtx_max: Default maximum number of retransmission for INIT chunks */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTX_MAX_DESC
value|"Default maximum number of retransmission for INIT chunks"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTX_MAX_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTX_MAX_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTX_MAX_DEFAULT
value|SCTP_DEF_MAX_INIT
end_define

begin_comment
comment|/* assoc_rtx_max: Default maximum number of retransmissions per association */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ASSOC_RTX_MAX_DESC
value|"Default maximum number of retransmissions per association"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASSOC_RTX_MAX_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASSOC_RTX_MAX_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASSOC_RTX_MAX_DEFAULT
value|SCTP_DEF_MAX_SEND
end_define

begin_comment
comment|/* path_rtx_max: Default maximum of retransmissions per path */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PATH_RTX_MAX_DESC
value|"Default maximum of retransmissions per path"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_RTX_MAX_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_RTX_MAX_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_RTX_MAX_DEFAULT
value|SCTP_DEF_MAX_PATH_RTX
end_define

begin_comment
comment|/* path_pf_threshold: threshold for considering the path potentially failed */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PATH_PF_THRESHOLD_DESC
value|"Default potentially failed threshold"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_PF_THRESHOLD_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_PF_THRESHOLD_MAX
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PATH_PF_THRESHOLD_DEFAULT
value|SCTPCTL_PATH_PF_THRESHOLD_MAX
end_define

begin_comment
comment|/* add_more_on_output: When space-wise is it worthwhile to try to add more to a socket send buffer */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT_DESC
value|"When space-wise is it worthwhile to try to add more to a socket send buffer"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT_DEFAULT
value|SCTP_DEFAULT_ADD_MORE
end_define

begin_comment
comment|/* incoming_streams: Default number of incoming streams */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_INCOMING_STREAMS_DESC
value|"Default number of incoming streams"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INCOMING_STREAMS_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INCOMING_STREAMS_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INCOMING_STREAMS_DEFAULT
value|SCTP_ISTREAM_INITIAL
end_define

begin_comment
comment|/* outgoing_streams: Default number of outgoing streams */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_OUTGOING_STREAMS_DESC
value|"Default number of outgoing streams"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTGOING_STREAMS_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTGOING_STREAMS_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTGOING_STREAMS_DEFAULT
value|SCTP_OSTREAM_INITIAL
end_define

begin_comment
comment|/* cmt_on_off: CMT on/off flag */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_DESC
value|"CMT settings"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_MIN
value|SCTP_CMT_OFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_MAX
value|SCTP_CMT_MAX
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_DEFAULT
value|SCTP_CMT_OFF
end_define

begin_comment
comment|/* cmt_use_dac: CMT DAC on/off flag */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC_DESC
value|"CMT DAC on/off flag"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC_DEFAULT
value|0
end_define

begin_comment
comment|/* cwnd_maxburst: Use a CWND adjusting maxburst */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST_DESC
value|"Use a CWND adjusting maxburst"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST_DEFAULT
value|1
end_define

begin_comment
comment|/* auth_disable: Disable SCTP AUTH function */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE_DESC
value|"Disable SCTP AUTH function"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE_DEFAULT
value|0
end_define

begin_comment
comment|/* nat_friendly: SCTP NAT friendly operation */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_DESC
value|"SCTP NAT friendly operation"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_DEFAULT
value|1
end_define

begin_comment
comment|/* abc_l_var: SCTP ABC max increase per SACK (L) */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ABC_L_VAR_DESC
value|"SCTP ABC max increase per SACK (L)"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABC_L_VAR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABC_L_VAR_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABC_L_VAR_DEFAULT
value|2
end_define

begin_comment
comment|/* max_chained_mbufs: Default max number of small mbufs on a chain */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAX_CHAINED_MBUFS_DESC
value|"Default max number of small mbufs on a chain"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_CHAINED_MBUFS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_CHAINED_MBUFS_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_CHAINED_MBUFS_DEFAULT
value|SCTP_DEFAULT_MBUFS_IN_CHAIN
end_define

begin_comment
comment|/* do_sctp_drain: Should SCTP respond to the drain calls */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DO_SCTP_DRAIN_DESC
value|"Should SCTP respond to the drain calls"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DO_SCTP_DRAIN_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DO_SCTP_DRAIN_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DO_SCTP_DRAIN_DEFAULT
value|1
end_define

begin_comment
comment|/* hb_max_burst: Confirmation Heartbeat max burst? */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_HB_MAX_BURST_DESC
value|"Confirmation Heartbeat max burst"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HB_MAX_BURST_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HB_MAX_BURST_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HB_MAX_BURST_DEFAULT
value|SCTP_DEF_HBMAX_BURST
end_define

begin_comment
comment|/* abort_at_limit: When one-2-one hits qlimit abort */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ABORT_AT_LIMIT_DESC
value|"When one-2-one hits qlimit abort"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABORT_AT_LIMIT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABORT_AT_LIMIT_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ABORT_AT_LIMIT_DEFAULT
value|0
end_define

begin_comment
comment|/* strict_data_order: Enforce strict data ordering, abort if control inside data */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_DATA_ORDER_DESC
value|"Enforce strict data ordering, abort if control inside data"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_DATA_ORDER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_DATA_ORDER_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_DATA_ORDER_DEFAULT
value|0
end_define

begin_comment
comment|/* min_residual: min residual in a data fragment leftover */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MIN_RESIDUAL_DESC
value|"Minimum residual data chunk in second part of split"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_RESIDUAL_MIN
value|20
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_RESIDUAL_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MIN_RESIDUAL_DEFAULT
value|1452
end_define

begin_comment
comment|/* max_retran_chunk: max chunk retransmissions */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_CHUNK_DESC
value|"Maximum times an unlucky chunk can be retran'd before assoc abort"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_CHUNK_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_CHUNK_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_CHUNK_DEFAULT
value|30
end_define

begin_comment
comment|/* sctp_logging: This gives us logging when the options are enabled */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_LOGGING_LEVEL_DESC
value|"Ltrace/KTR trace logging level"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOGGING_LEVEL_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOGGING_LEVEL_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|SCTPCTL_LOGGING_LEVEL_DEFAULT
value|0
end_define

begin_comment
comment|/* JRS - default congestion control module sysctl */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_CC_MODULE_DESC
value|"Default congestion control module"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_CC_MODULE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_CC_MODULE_MAX
value|2
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_CC_MODULE_DEFAULT
value|0
end_define

begin_comment
comment|/* RS - default stream scheduling module sysctl */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_SS_MODULE_DESC
value|"Default stream scheduling module"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_SS_MODULE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_SS_MODULE_MAX
value|5
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_SS_MODULE_DEFAULT
value|0
end_define

begin_comment
comment|/* RRS - default fragment interleave */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_FRAG_INTERLEAVE_DESC
value|"Default fragment interleave level"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_FRAG_INTERLEAVE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_FRAG_INTERLEAVE_MAX
value|2
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEFAULT_FRAG_INTERLEAVE_DEFAULT
value|1
end_define

begin_comment
comment|/* mobility_base: Enable SCTP mobility support */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_BASE_DESC
value|"Enable SCTP base mobility"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_BASE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_BASE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_BASE_DEFAULT
value|SCTP_DEFAULT_MOBILITY_BASE
end_define

begin_comment
comment|/* mobility_fasthandoff: Enable SCTP fast handoff support */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_FASTHANDOFF_DESC
value|"Enable SCTP fast handoff"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_FASTHANDOFF_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_FASTHANDOFF_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MOBILITY_FASTHANDOFF_DEFAULT
value|SCTP_DEFAULT_MOBILITY_FASTHANDOFF
end_define

begin_comment
comment|/* Enable SCTP/UDP tunneling port */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_UDP_TUNNELING_PORT_DESC
value|"Set the SCTP/UDP tunneling port"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_UDP_TUNNELING_PORT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_UDP_TUNNELING_PORT_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_UDP_TUNNELING_PORT_DEFAULT
value|0
end_define

begin_comment
comment|/* Enable sending of the SACK-IMMEDIATELY bit */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SACK_IMMEDIATELY_ENABLE_DESC
value|"Enable sending of the SACK-IMMEDIATELY-bit."
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_IMMEDIATELY_ENABLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_IMMEDIATELY_ENABLE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SACK_IMMEDIATELY_ENABLE_DEFAULT
value|SCTPCTL_SACK_IMMEDIATELY_ENABLE_MIN
end_define

begin_comment
comment|/* Enable sending of the NAT-FRIENDLY message */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_INITS_DESC
value|"Enable sending of the nat-friendly SCTP option on INITs."
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_INITS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_INITS_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_NAT_FRIENDLY_INITS_DEFAULT
value|SCTPCTL_NAT_FRIENDLY_INITS_MIN
end_define

begin_comment
comment|/* Vtag time wait in seconds */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_TIME_WAIT_DESC
value|"Vtag time wait time in seconds, 0 disables it."
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TIME_WAIT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TIME_WAIT_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|SCTPCTL_TIME_WAIT_DEFAULT
value|SCTP_TIME_WAIT
end_define

begin_comment
comment|/* Enable Send/Receive buffer splitting */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_BUFFER_SPLITTING_DESC
value|"Enable send/receive buffer splitting."
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BUFFER_SPLITTING_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BUFFER_SPLITTING_MAX
value|0x3
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BUFFER_SPLITTING_DEFAULT
value|SCTPCTL_BUFFER_SPLITTING_MIN
end_define

begin_comment
comment|/* Initial congestion window in MTU */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_INITIAL_CWND_DESC
value|"Initial congestion window in MTUs"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INITIAL_CWND_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INITIAL_CWND_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INITIAL_CWND_DEFAULT
value|3
end_define

begin_comment
comment|/* rttvar smooth avg for bw calc  */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_BW_DESC
value|"Shift amount for bw smoothing on rtt calc"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_BW_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_BW_MAX
value|32
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_BW_DEFAULT
value|4
end_define

begin_comment
comment|/* rttvar smooth avg for bw calc  */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_RTT_DESC
value|"Shift amount for rtt smoothing on rtt calc"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_RTT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_RTT_MAX
value|32
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_RTT_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_EQRET_DESC
value|"What to return when rtt and bw are unchanged"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_EQRET_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_EQRET_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_EQRET_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_STEADYS_DESC
value|"How many the sames it takes to try step down of cwnd"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_STEADYS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_STEADYS_MAX
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_STEADYS_DEFAULT
value|20
end_define

begin_comment
comment|/* 0 means disable feature */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_DCCCECN_DESC
value|"Enable for RTCC CC datacenter ECN"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_DCCCECN_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_DCCCECN_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTTVAR_DCCCECN_DEFAULT
value|1
end_define

begin_comment
comment|/* 0 means disable feature */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_BLACKHOLE_DESC
value|"Enable SCTP blackholing"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BLACKHOLE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BLACKHOLE_MAX
value|2
end_define

begin_define
define|#
directive|define
name|SCTPCTL_BLACKHOLE_DEFAULT
value|SCTPCTL_BLACKHOLE_MIN
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DIAG_INFO_CODE_DESC
value|"Diagnostic information error cause code"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DIAG_INFO_CODE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DIAG_INFO_CODE_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DIAG_INFO_CODE_DEFAULT
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCTP_DEBUG
argument_list|)
end_if

begin_comment
comment|/* debug: Configure debug output */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG_DESC
value|"Configure debug output"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG_DEFAULT
value|0
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
name|__APPLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|SCTP_SO_LOCK_TESTING
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTPCTL_OUTPUT_UNLOCKED_DESC
value|"Unlock socket when sending packets down to IP."
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTPUT_UNLOCKED_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTPUT_UNLOCKED_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_OUTPUT_UNLOCKED_DEFAULT
value|SCTPCTL_OUTPUT_UNLOCKED_MIN
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
operator|||
name|defined
argument_list|(
name|__Userspace__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSCTL_DECL
argument_list|)
end_if

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

begin_function_decl
name|void
name|sctp_init_sysctls
parameter_list|(
name|void
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
comment|/* __sctp_sysctl_h__ */
end_comment

end_unit

