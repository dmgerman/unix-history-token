begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|__sctp_sysctl_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_sysctl_h__
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

begin_comment
comment|/*  * limits for the sysctl variables  */
end_comment

begin_comment
comment|/* maxdgram: Maximum outgoing SCTP buffer size */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXDGRAM
value|1
end_define

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
name|SCTPCTL_RECVSPACE
value|2
end_define

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
name|SCTPCTL_AUTOASCONF
value|3
end_define

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
comment|/* ecn_enable: Enable SCTP ECN */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ECN_ENABLE
value|4
end_define

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
comment|/* ecn_nonce: Enable SCTP ECN Nonce */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE
value|5
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE_DESC
value|"Enable SCTP ECN Nonce"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ECN_NONCE_DEFAULT
value|0
end_define

begin_comment
comment|/* strict_sacks: Enable SCTP Strict SACK checking */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_SACKS
value|6
end_define

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
value|0
end_define

begin_comment
comment|/* loopback_nocsum: Enable NO Csum on packets sent on loopback */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_LOOPBACK_NOCSUM
value|7
end_define

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
comment|/* strict_init: Enable strict INIT/INIT-ACK singleton enforcement */
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
name|SCTPCTL_STRICT_INIT_DESC
value|"Enable strict INIT/INIT-ACK singleton enforcement"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_INIT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_INIT_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_STRICT_INIT_DEFAULT
value|1
end_define

begin_comment
comment|/* peer_chkoh: Amount to debit peers rwnd per chunk sent */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PEER_CHKOH
value|9
end_define

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
value|0
end_define

begin_comment
comment|/* sizeof struct mbuf */
end_comment

begin_comment
comment|/* maxburst: Default max burst for sctp endpoints */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXBURST
value|10
end_define

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
value|1
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
comment|/* maxchunks: Default max chunks on queue per asoc */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAXCHUNKS
value|11
end_define

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
comment|/* tcbhashsize: Tuneable for Hash table sizes */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_TCBHASHSIZE
value|12
end_define

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
comment|/* pcbhashsize: Tuneable for PCB Hash table sizes */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PCBHASHSIZE
value|13
end_define

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
name|SCTPCTL_MIN_SPLIT_POINT
value|14
end_define

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
comment|/* chunkscale: Tuneable for Scaling of number of chunks and messages */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE
value|15
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CHUNKSCALE_DESC
value|"Tuneable for Scaling of number of chunks and messages"
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
comment|/* delayed_sack_time: Default delayed SACK timer in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME
value|16
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DELAYED_SACK_TIME_DESC
value|"Default delayed SACK timer in msec"
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
name|SCTPCTL_SACK_FREQ
value|17
end_define

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
name|SCTPCTL_SYS_RESOURCE
value|18
end_define

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
name|SCTPCTL_ASOC_RESOURCE
value|19
end_define

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
comment|/* heartbeat_interval: Default heartbeat interval in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL
value|20
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HEARTBEAT_INTERVAL_DESC
value|"Default heartbeat interval in msec"
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
comment|/* pmtu_raise_time: Default PMTU raise timer in sec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME
value|21
end_define

begin_define
define|#
directive|define
name|SCTPCTL_PMTU_RAISE_TIME_DESC
value|"Default PMTU raise timer in sec"
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
comment|/* shutdown_guard_time: Default shutdown guard timer in sec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME
value|22
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SHUTDOWN_GUARD_TIME_DESC
value|"Default shutdown guard timer in sec"
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
comment|/* secret_lifetime: Default secret lifetime in sec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME
value|23
end_define

begin_define
define|#
directive|define
name|SCTPCTL_SECRET_LIFETIME_DESC
value|"Default secret lifetime in sec"
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
comment|/* rto_max: Default maximum retransmission timeout in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX
value|24
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MAX_DESC
value|"Default maximum retransmission timeout in msec"
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
comment|/* rto_min: Default minimum retransmission timeout in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN
value|25
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_MIN_DESC
value|"Default minimum retransmission timeout in msec"
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
comment|/* rto_initial: Default initial retransmission timeout in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL
value|26
end_define

begin_define
define|#
directive|define
name|SCTPCTL_RTO_INITIAL_DESC
value|"Default initial retransmission timeout in msec"
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
comment|/* init_rto_max: Default maximum retransmission timeout during association setup in msec */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX
value|27
end_define

begin_define
define|#
directive|define
name|SCTPCTL_INIT_RTO_MAX_DESC
value|"Default maximum retransmission timeout during association setup in msec"
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
name|SCTPCTL_VALID_COOKIE_LIFE
value|28
end_define

begin_define
define|#
directive|define
name|SCTPCTL_VALID_COOKIE_LIFE_DESC
value|"Default cookie lifetime in sec"
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
name|SCTPCTL_INIT_RTX_MAX
value|29
end_define

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
name|SCTPCTL_ASSOC_RTX_MAX
value|30
end_define

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
name|SCTPCTL_PATH_RTX_MAX
value|31
end_define

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
comment|/* add_more_on_output: When space wise is it worthwhile to try to add more to a socket send buffer */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT
value|32
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ADD_MORE_ON_OUTPUT_DESC
value|"When space wise is it worthwhile to try to add more to a socket send buffer"
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
comment|/* outgoing_streams: Default number of outgoing streams */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_OUTGOING_STREAMS
value|33
end_define

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
name|SCTPCTL_CMT_ON_OFF
value|34
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_DESC
value|"CMT on/off flag"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_CMT_ON_OFF_DEFAULT
value|0
end_define

begin_comment
comment|/* cwnd_maxburst: Use a CWND adjusting maxburst */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CWND_MAXBURST
value|35
end_define

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
comment|/* early_fast_retran: Early Fast Retransmit with timer */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN
value|36
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_DESC
value|"Early Fast Retransmit with timer"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_DEFAULT
value|0
end_define

begin_comment
comment|/* deadlock_detect: SMP Deadlock detection on/off */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DETECT
value|37
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DETECT_DESC
value|"SMP Deadlock detection on/off"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DETECT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DETECT_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_DEADLOCK_DETECT_DEFAULT
value|0
end_define

begin_comment
comment|/* early_fast_retran_msec: Early Fast Retransmit minimum timer value */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MSEC
value|38
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MSEC_DESC
value|"Early Fast Retransmit minimum timer value"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MSEC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MSEC_MAX
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SCTPCTL_EARLY_FAST_RETRAN_MSEC_DEFAULT
value|SCTP_MINFR_MSEC_TIMER
end_define

begin_comment
comment|/* asconf_auth_nochk: Disable SCTP ASCONF AUTH requirement */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK
value|39
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK_DESC
value|"Disable SCTP ASCONF AUTH requirement"
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK_MAX
value|1
end_define

begin_define
define|#
directive|define
name|SCTPCTL_ASCONF_AUTH_NOCHK_DEFAULT
value|0
end_define

begin_comment
comment|/* auth_disable: Disable SCTP AUTH function */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_AUTH_DISABLE
value|40
end_define

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
name|SCTPCTL_NAT_FRIENDLY
value|41
end_define

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
name|SCTPCTL_ABC_L_VAR
value|42
end_define

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
value|1
end_define

begin_comment
comment|/* max_chained_mbufs: Default max number of small mbufs on a chain */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAX_CHAINED_MBUFS
value|43
end_define

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
comment|/* cmt_use_dac: CMT DAC on/off flag */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_CMT_USE_DAC
value|44
end_define

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
comment|/* do_sctp_drain: Should SCTP respond to the drain calls */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DO_SCTP_DRAIN
value|45
end_define

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
name|SCTPCTL_HB_MAX_BURST
value|46
end_define

begin_define
define|#
directive|define
name|SCTPCTL_HB_MAX_BURST_DESC
value|"Confirmation Heartbeat max burst?"
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
value|SCTP_DEF_MAX_BURST
end_define

begin_comment
comment|/* abort_at_limit: When one-2-one hits qlimit abort */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_ABORT_AT_LIMIT
value|47
end_define

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
name|SCTPCTL_STRICT_DATA_ORDER
value|48
end_define

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
comment|/* min residual in in a data fragment leftover  */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MIN_REDIDUAL
value|49
end_define

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
comment|/* min residual in in a data fragment leftover  */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN
value|50
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_DESC
value|"Maximum times a unlucky chunk can be retran'd before assoc abort "
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|SCTPCTL_MAX_RETRAN_DEFAULT
value|30
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_DEBUG
end_ifdef

begin_comment
comment|/* debug: Configure debug output */
end_comment

begin_define
define|#
directive|define
name|SCTPCTL_DEBUG
value|51
end_define

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

begin_comment
comment|/*  * Names for SCTP sysctl objects variables.  * Must match the OIDs above.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCTPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "autoasconf", CTLTYPE_INT }, \ 	{ "ecn_enable", CTLTYPE_INT }, \ 	{ "ecn_nonce", CTLTYPE_INT }, \ 	{ "strict_sack", CTLTYPE_INT }, \ 	{ "looback_nocsum", CTLTYPE_INT }, \ 	{ "strict_init", CTLTYPE_INT }, \ 	{ "peer_chkoh", CTLTYPE_INT }, \ 	{ "maxburst", CTLTYPE_INT }, \ 	{ "maxchunks", CTLTYPE_INT }, \ 	{ "delayed_sack_time", CTLTYPE_INT }, \ 	{ "sack_freq", CTLTYPE_INT }, \ 	{ "heartbeat_interval", CTLTYPE_INT }, \ 	{ "pmtu_raise_time", CTLTYPE_INT }, \ 	{ "shutdown_guard_time", CTLTYPE_INT }, \ 	{ "secret_lifetime", CTLTYPE_INT }, \ 	{ "rto_max", CTLTYPE_INT }, \ 	{ "rto_min", CTLTYPE_INT }, \ 	{ "rto_initial", CTLTYPE_INT }, \ 	{ "init_rto_max", CTLTYPE_INT }, \ 	{ "valid_cookie_life", CTLTYPE_INT }, \ 	{ "init_rtx_max", CTLTYPE_INT }, \ 	{ "assoc_rtx_max", CTLTYPE_INT }, \ 	{ "path_rtx_max", CTLTYPE_INT }, \ 	{ "outgoing_streams", CTLTYPE_INT }, \ 	{ "cmt_on_off", CTLTYPE_INT }, \ 	{ "cwnd_maxburst", CTLTYPE_INT }, \ 	{ "early_fast_retran", CTLTYPE_INT }, \ 	{ "deadlock_detect", CTLTYPE_INT }, \ 	{ "early_fast_retran_msec", CTLTYPE_INT }, \ 	{ "asconf_auth_nochk", CTLTYPE_INT }, \ 	{ "auth_disable", CTLTYPE_INT }, \ 	{ "nat_friendly", CTLTYPE_INT }, \ 	{ "abc_l_var", CTLTYPE_INT }, \ 	{ "max_mbuf_chain", CTLTYPE_INT }, \ 	{ "cmt_use_dac", CTLTYPE_INT }, \ 	{ "do_sctp_drain", CTLTYPE_INT }, \ 	{ "warm_crc_table", CTLTYPE_INT }, \ 	{ "abort_at_limit", CTLTYPE_INT }, \ 	{ "strict_data_order", CTLTYPE_INT }, \ 	{ "tcbhashsize", CTLTYPE_INT }, \ 	{ "pcbhashsize", CTLTYPE_INT }, \ 	{ "chunkscale", CTLTYPE_INT }, \ 	{ "min_split_point", CTLTYPE_INT }, \ 	{ "add_more_on_output", CTLTYPE_INT }, \ 	{ "sys_resource", CTLTYPE_INT }, \ 	{ "asoc_resource", CTLTYPE_INT }, \ 	{ "min_residual", CTLTYPE_INT }, \ 	{ "max_retran_chunk", CTLTYPE_INT }, \ 	{ "debug", CTLTYPE_INT }, \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "autoasconf", CTLTYPE_INT }, \ 	{ "ecn_enable", CTLTYPE_INT }, \ 	{ "ecn_nonce", CTLTYPE_INT }, \ 	{ "strict_sack", CTLTYPE_INT }, \ 	{ "looback_nocsum", CTLTYPE_INT }, \ 	{ "strict_init", CTLTYPE_INT }, \ 	{ "peer_chkoh", CTLTYPE_INT }, \ 	{ "maxburst", CTLTYPE_INT }, \ 	{ "maxchunks", CTLTYPE_INT }, \ 	{ "delayed_sack_time", CTLTYPE_INT }, \ 	{ "sack_freq", CTLTYPE_INT }, \ 	{ "heartbeat_interval", CTLTYPE_INT }, \ 	{ "pmtu_raise_time", CTLTYPE_INT }, \ 	{ "shutdown_guard_time", CTLTYPE_INT }, \ 	{ "secret_lifetime", CTLTYPE_INT }, \ 	{ "rto_max", CTLTYPE_INT }, \ 	{ "rto_min", CTLTYPE_INT }, \ 	{ "rto_initial", CTLTYPE_INT }, \ 	{ "init_rto_max", CTLTYPE_INT }, \ 	{ "valid_cookie_life", CTLTYPE_INT }, \ 	{ "init_rtx_max", CTLTYPE_INT }, \ 	{ "assoc_rtx_max", CTLTYPE_INT }, \ 	{ "path_rtx_max", CTLTYPE_INT }, \ 	{ "outgoing_streams", CTLTYPE_INT }, \ 	{ "cmt_on_off", CTLTYPE_INT }, \ 	{ "cwnd_maxburst", CTLTYPE_INT }, \ 	{ "early_fast_retran", CTLTYPE_INT }, \ 	{ "deadlock_detect", CTLTYPE_INT }, \ 	{ "early_fast_retran_msec", CTLTYPE_INT }, \ 	{ "asconf_auth_nochk", CTLTYPE_INT }, \ 	{ "auth_disable", CTLTYPE_INT }, \ 	{ "nat_friendly", CTLTYPE_INT }, \ 	{ "abc_l_var", CTLTYPE_INT }, \ 	{ "max_mbuf_chain", CTLTYPE_INT }, \ 	{ "cmt_use_dac", CTLTYPE_INT }, \ 	{ "do_sctp_drain", CTLTYPE_INT }, \ 	{ "warm_crc_table", CTLTYPE_INT }, \ 	{ "abort_at_limit", CTLTYPE_INT }, \ 	{ "strict_data_order", CTLTYPE_INT }, \ 	{ "tcbhashsize", CTLTYPE_INT }, \ 	{ "pcbhashsize", CTLTYPE_INT }, \ 	{ "chunkscale", CTLTYPE_INT }, \ 	{ "min_split_point", CTLTYPE_INT }, \ 	{ "add_more_on_output", CTLTYPE_INT }, \ 	{ "sys_resource", CTLTYPE_INT }, \ 	{ "asoc_resource", CTLTYPE_INT }, \ 	{ "max_retran_chunk", CTLTYPE_INT }, \ 	{ "min_residual", CTLTYPE_INT }, \ }
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

begin_comment
comment|/*  * variable definitions  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_sendspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_recvspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_auto_asconf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_ecn_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_ecn_nonce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_strict_sacks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_no_csum_on_loopback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_strict_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_peer_chunk_oh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_max_burst_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_max_chunks_on_queue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_hashtblsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_pcbtblsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_min_split_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_chunkscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_delayed_sack_time_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_sack_freq_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_system_free_resc_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_asoc_free_resc_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_heartbeat_interval_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_pmtu_raise_time_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_shutdown_guard_time_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_secret_lifetime_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_rto_max_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_rto_min_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_rto_initial_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_init_rto_max_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_valid_cookie_life_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_init_rtx_max_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_assoc_rtx_max_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_path_rtx_max_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_add_more_threshold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_nr_outgoing_streams_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_cmt_on_off
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_use_cwnd_based_maxburst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_early_fr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_use_rttvar_cc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_says_check_for_deadlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_early_fr_msec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_asconf_auth_nochk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_auth_disable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_nat_friendly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_L2_abc_variable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_mbuf_threshold_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_cmt_use_dac
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_do_drain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_hb_maxburst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_abort_if_one_2_one_hits_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_strict_data_order
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_min_residual
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_max_retran_chunk
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCTP_DEBUG
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|uint32_t
name|sctp_debug_on
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|sctpstat
name|sctpstat
decl_stmt|;
end_decl_stmt

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

