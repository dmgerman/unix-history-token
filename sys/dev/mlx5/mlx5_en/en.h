begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Mellanox Technologies. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS `AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MLX5_EN_H_
end_ifndef

begin_define
define|#
directive|define
name|_MLX5_EN_H_
end_define

begin_include
include|#
directive|include
file|<linux/kmod.h>
end_include

begin_include
include|#
directive|include
file|<linux/page.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/if_vlan.h>
end_include

begin_include
include|#
directive|include
file|<linux/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<linux/vmalloc.h>
end_include

begin_include
include|#
directive|include
file|<linux/moduleparam.h>
end_include

begin_include
include|#
directive|include
file|<linux/delay.h>
end_include

begin_include
include|#
directive|include
file|<linux/netdevice.h>
end_include

begin_include
include|#
directive|include
file|<linux/etherdevice.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf_ring.h>
end_include

begin_include
include|#
directive|include
file|"opt_rss.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSS
end_ifdef

begin_include
include|#
directive|include
file|<net/rss_config.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_rss.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/driver.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/qp.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/cq.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/vport.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/mlx5_core/wq.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/mlx5_core/transobj.h>
end_include

begin_include
include|#
directive|include
file|<dev/mlx5/mlx5_core/mlx5_core.h>
end_include

begin_define
define|#
directive|define
name|MLX5E_PARAMS_MINIMUM_LOG_SQ_SIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_LOG_SQ_SIZE
value|0xa
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_MAXIMUM_LOG_SQ_SIZE
value|0xe
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_MINIMUM_LOG_RQ_SIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_LOG_RQ_SIZE
value|0xa
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_MAXIMUM_LOG_RQ_SIZE
value|0xe
end_define

begin_comment
comment|/* freeBSD HW LRO is limited by 16KB - the size of max mbuf */
end_comment

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_LRO_WQE_SZ
value|MJUM16BYTES
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_RX_CQ_MODERATION_USEC
value|0x10
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_RX_CQ_MODERATION_USEC_FROM_CQE
value|0x3
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_RX_CQ_MODERATION_PKTS
value|0x20
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_TX_CQ_MODERATION_USEC
value|0x10
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_TX_CQ_MODERATION_PKTS
value|0x20
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_MIN_RX_WQES
value|0x80
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_DEFAULT_RX_HASH_LOG_TBL_SZ
value|0x7
end_define

begin_define
define|#
directive|define
name|MLX5E_CACHELINE_SIZE
value|CACHE_LINE_SIZE
end_define

begin_define
define|#
directive|define
name|MLX5E_HW2SW_MTU
parameter_list|(
name|hwmtu
parameter_list|)
define|\
value|((hwmtu) - (ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN + ETHER_CRC_LEN))
end_define

begin_define
define|#
directive|define
name|MLX5E_SW2HW_MTU
parameter_list|(
name|swmtu
parameter_list|)
define|\
value|((swmtu) + (ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN + ETHER_CRC_LEN))
end_define

begin_define
define|#
directive|define
name|MLX5E_SW2MB_MTU
parameter_list|(
name|swmtu
parameter_list|)
define|\
value|(MLX5E_SW2HW_MTU(swmtu) + MLX5E_NET_IP_ALIGN)
end_define

begin_define
define|#
directive|define
name|MLX5E_MTU_MIN
value|72
end_define

begin_comment
comment|/* Min MTU allowed by the kernel */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MTU_MAX
value|MIN(ETHERMTU_JUMBO, MJUM16BYTES)
end_define

begin_comment
comment|/* Max MTU of Ethernet 									 * jumbo frames */
end_comment

begin_define
define|#
directive|define
name|MLX5E_BUDGET_MAX
value|8192
end_define

begin_comment
comment|/* RX and TX */
end_comment

begin_define
define|#
directive|define
name|MLX5E_RX_BUDGET_MAX
value|256
end_define

begin_define
define|#
directive|define
name|MLX5E_SQ_BF_BUDGET
value|16
end_define

begin_define
define|#
directive|define
name|MLX5E_SQ_TX_QUEUE_SIZE
value|4096
end_define

begin_comment
comment|/* SQ drbr queue size */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_NUM_TC
value|8
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_HEADER
value|128
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_PAYLOAD_SIZE
value|65536
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_MBUF_SIZE
value|65536
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_MBUF_FRAGS
define|\
value|((MLX5_SEND_WQE_MAX_WQEBBS * MLX5_SEND_WQEBB_NUM_DS) - \     (MLX5E_MAX_TX_HEADER / MLX5_SEND_WQE_DS))
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|MLX5E_MAX_TX_INLINE
define|\
value|(MLX5E_MAX_TX_HEADER - sizeof(struct mlx5e_tx_wqe) + \   sizeof(((struct mlx5e_tx_wqe *)0)->eth.inline_hdr_start))
end_define

begin_comment
comment|/* bytes */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MLX5EN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|mlx5_core_dev
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mlx5e_cq
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|mlx5e_cq_comp_t
function_decl|)
parameter_list|(
name|struct
name|mlx5_core_cq
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|MLX5E_STATS_COUNT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|MLX5E_STATS_VAR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|b;
end_define

begin_define
define|#
directive|define
name|MLX5E_STATS_DESC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|c, d,
end_define

begin_define
define|#
directive|define
name|MLX5E_VPORT_STATS
parameter_list|(
name|m
parameter_list|)
define|\
comment|/* HW counters */
define|\
value|m(+1, u64 rx_packets, "rx_packets", "Received packets")		\   m(+1, u64 rx_bytes, "rx_bytes", "Received bytes")			\   m(+1, u64 tx_packets, "tx_packets", "Transmitted packets")		\   m(+1, u64 tx_bytes, "tx_bytes", "Transmitted bytes")			\   m(+1, u64 rx_error_packets, "rx_error_packets", "Received error packets") \   m(+1, u64 rx_error_bytes, "rx_error_bytes", "Received error bytes")	\   m(+1, u64 tx_error_packets, "tx_error_packets", "Transmitted error packets") \   m(+1, u64 tx_error_bytes, "tx_error_bytes", "Transmitted error bytes") \   m(+1, u64 rx_unicast_packets, "rx_unicast_packets", "Received unicast packets") \   m(+1, u64 rx_unicast_bytes, "rx_unicast_bytes", "Received unicast bytes") \   m(+1, u64 tx_unicast_packets, "tx_unicast_packets", "Transmitted unicast packets") \   m(+1, u64 tx_unicast_bytes, "tx_unicast_bytes", "Transmitted unicast bytes") \   m(+1, u64 rx_multicast_packets, "rx_multicast_packets", "Received multicast packets") \   m(+1, u64 rx_multicast_bytes, "rx_multicast_bytes", "Received multicast bytes") \   m(+1, u64 tx_multicast_packets, "tx_multicast_packets", "Transmitted multicast packets") \   m(+1, u64 tx_multicast_bytes, "tx_multicast_bytes", "Transmitted multicast bytes") \   m(+1, u64 rx_broadcast_packets, "rx_broadcast_packets", "Received broadcast packets") \   m(+1, u64 rx_broadcast_bytes, "rx_broadcast_bytes", "Received broadcast bytes") \   m(+1, u64 tx_broadcast_packets, "tx_broadcast_packets", "Transmitted broadcast packets") \   m(+1, u64 tx_broadcast_bytes, "tx_broadcast_bytes", "Transmitted broadcast bytes") \   m(+1, u64 rx_out_of_buffer, "rx_out_of_buffer", "Receive out of buffer, no recv wqes events") \
comment|/* SW counters */
value|\   m(+1, u64 tso_packets, "tso_packets", "Transmitted TSO packets")	\   m(+1, u64 tso_bytes, "tso_bytes", "Transmitted TSO bytes")		\   m(+1, u64 lro_packets, "lro_packets", "Received LRO packets")		\   m(+1, u64 lro_bytes, "lro_bytes", "Received LRO bytes")		\   m(+1, u64 sw_lro_queued, "sw_lro_queued", "Packets queued for SW LRO")	\   m(+1, u64 sw_lro_flushed, "sw_lro_flushed", "Packets flushed from SW LRO")	\   m(+1, u64 rx_csum_good, "rx_csum_good", "Received checksum valid packets") \   m(+1, u64 rx_csum_none, "rx_csum_none", "Received no checksum packets") \   m(+1, u64 tx_csum_offload, "tx_csum_offload", "Transmit checksum offload packets") \   m(+1, u64 tx_queue_dropped, "tx_queue_dropped", "Transmit queue dropped") \   m(+1, u64 tx_defragged, "tx_defragged", "Transmit queue defragged") \   m(+1, u64 rx_wqe_err, "rx_wqe_err", "Receive WQE errors")
end_define

begin_define
define|#
directive|define
name|MLX5E_VPORT_STATS_NUM
value|(0 MLX5E_VPORT_STATS(MLX5E_STATS_COUNT))
end_define

begin_struct
struct|struct
name|mlx5e_vport_stats
block|{
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_VPORT_STATS
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
name|u32
name|rx_out_of_buffer_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_PPORT_IEEE802_3_STATS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 frames_tx, "frames_tx", "Frames transmitted")		\   m(+1, u64 frames_rx, "frames_rx", "Frames received")			\   m(+1, u64 check_seq_err, "check_seq_err", "Sequence errors")		\   m(+1, u64 alignment_err, "alignment_err", "Alignment errors")	\   m(+1, u64 octets_tx, "octets_tx", "Bytes transmitted")		\   m(+1, u64 octets_received, "octets_received", "Bytes received")	\   m(+1, u64 multicast_xmitted, "multicast_xmitted", "Multicast transmitted") \   m(+1, u64 broadcast_xmitted, "broadcast_xmitted", "Broadcast transmitted") \   m(+1, u64 multicast_rx, "multicast_rx", "Multicast received")	\   m(+1, u64 broadcast_rx, "broadcast_rx", "Broadcast received")	\   m(+1, u64 in_range_len_errors, "in_range_len_errors", "In range length errors") \   m(+1, u64 out_of_range_len, "out_of_range_len", "Out of range length errors") \   m(+1, u64 too_long_errors, "too_long_errors", "Too long errors")	\   m(+1, u64 symbol_err, "symbol_err", "Symbol errors")			\   m(+1, u64 mac_control_tx, "mac_control_tx", "MAC control transmitted") \   m(+1, u64 mac_control_rx, "mac_control_rx", "MAC control received")	\   m(+1, u64 unsupported_op_rx, "unsupported_op_rx", "Unsupported operation received") \   m(+1, u64 pause_ctrl_rx, "pause_ctrl_rx", "Pause control received")	\   m(+1, u64 pause_ctrl_tx, "pause_ctrl_tx", "Pause control transmitted")
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2819_STATS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 drop_events, "drop_events", "Dropped events")		\   m(+1, u64 octets, "octets", "Octets")					\   m(+1, u64 pkts, "pkts", "Packets")					\   m(+1, u64 broadcast_pkts, "broadcast_pkts", "Broadcast packets")	\   m(+1, u64 multicast_pkts, "multicast_pkts", "Multicast packets")	\   m(+1, u64 crc_align_errors, "crc_align_errors", "CRC alignment errors") \   m(+1, u64 undersize_pkts, "undersize_pkts", "Undersized packets")	\   m(+1, u64 oversize_pkts, "oversize_pkts", "Oversized packets")	\   m(+1, u64 fragments, "fragments", "Fragments")			\   m(+1, u64 jabbers, "jabbers", "Jabbers")				\   m(+1, u64 collisions, "collisions", "Collisions")
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2819_STATS_DEBUG
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 p64octets, "p64octets", "Bytes")				\   m(+1, u64 p65to127octets, "p65to127octets", "Bytes")			\   m(+1, u64 p128to255octets, "p128to255octets", "Bytes")		\   m(+1, u64 p256to511octets, "p256to511octets", "Bytes")		\   m(+1, u64 p512to1023octets, "p512to1023octets", "Bytes")		\   m(+1, u64 p1024to1518octets, "p1024to1518octets", "Bytes")		\   m(+1, u64 p1519to2047octets, "p1519to2047octets", "Bytes")		\   m(+1, u64 p2048to4095octets, "p2048to4095octets", "Bytes")		\   m(+1, u64 p4096to8191octets, "p4096to8191octets", "Bytes")		\   m(+1, u64 p8192to10239octets, "p8192to10239octets", "Bytes")
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2863_STATS_DEBUG
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 in_octets, "in_octets", "In octets")			\   m(+1, u64 in_ucast_pkts, "in_ucast_pkts", "In unicast packets")	\   m(+1, u64 in_discards, "in_discards", "In discards")			\   m(+1, u64 in_errors, "in_errors", "In errors")			\   m(+1, u64 in_unknown_protos, "in_unknown_protos", "In unknown protocols") \   m(+1, u64 out_octets, "out_octets", "Out octets")			\   m(+1, u64 out_ucast_pkts, "out_ucast_pkts", "Out unicast packets")	\   m(+1, u64 out_discards, "out_discards", "Out discards")		\   m(+1, u64 out_errors, "out_errors", "Out errors")			\   m(+1, u64 in_multicast_pkts, "in_multicast_pkts", "In multicast packets") \   m(+1, u64 in_broadcast_pkts, "in_broadcast_pkts", "In broadcast packets") \   m(+1, u64 out_multicast_pkts, "out_multicast_pkts", "Out multicast packets") \   m(+1, u64 out_broadcast_pkts, "out_broadcast_pkts", "Out broadcast packets")
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_PHYSICAL_LAYER_STATS_DEBUG
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 time_since_last_clear, "time_since_last_clear",				\ 			"Time since the last counters clear event (msec)")		\   m(+1, u64 symbol_errors, "symbol_errors", "Symbol errors")				\   m(+1, u64 sync_headers_errors, "sync_headers_errors", "Sync header error counter")	\   m(+1, u64 bip_errors_lane0, "edpl_bip_errors_lane0",					\ 			"Indicates the number of PRBS errors on lane 0")		\   m(+1, u64 bip_errors_lane1, "edpl_bip_errors_lane1",					\ 			"Indicates the number of PRBS errors on lane 1")		\   m(+1, u64 bip_errors_lane2, "edpl_bip_errors_lane2",					\ 			"Indicates the number of PRBS errors on lane 2")		\   m(+1, u64 bip_errors_lane3, "edpl_bip_errors_lane3",					\ 			"Indicates the number of PRBS errors on lane 3")		\   m(+1, u64 fc_corrected_blocks_lane0, "fc_corrected_blocks_lane0",			\ 			"FEC correctable block counter lane 0")				\   m(+1, u64 fc_corrected_blocks_lane1, "fc_corrected_blocks_lane1",			\ 			"FEC correctable block counter lane 1")				\   m(+1, u64 fc_corrected_blocks_lane2, "fc_corrected_blocks_lane2",			\ 			"FEC correctable block counter lane 2")				\   m(+1, u64 fc_corrected_blocks_lane3, "fc_corrected_blocks_lane3",			\ 			"FEC correctable block counter lane 3")				\   m(+1, u64 rs_corrected_blocks, "rs_corrected_blocks",					\ 			"FEC correcable block counter")					\   m(+1, u64 rs_uncorrectable_blocks, "rs_uncorrectable_blocks",				\ 			"FEC uncorrecable block counter")				\   m(+1, u64 rs_no_errors_blocks, "rs_no_errors_blocks",					\ 			"The number of RS-FEC blocks received that had no errors")	\   m(+1, u64 rs_single_error_blocks, "rs_single_error_blocks",				\ 			"The number of corrected RS-FEC blocks received that had"	\ 			"exactly 1 error symbol")					\   m(+1, u64 rs_corrected_symbols_total, "rs_corrected_symbols_total",			\ 			"Port FEC corrected symbol counter")				\   m(+1, u64 rs_corrected_symbols_lane0, "rs_corrected_symbols_lane0",			\ 			"FEC corrected symbol counter lane 0")				\   m(+1, u64 rs_corrected_symbols_lane1, "rs_corrected_symbols_lane1",			\ 			"FEC corrected symbol counter lane 1")				\   m(+1, u64 rs_corrected_symbols_lane2, "rs_corrected_symbols_lane2",			\ 			"FEC corrected symbol counter lane 2")				\   m(+1, u64 rs_corrected_symbols_lane3, "rs_corrected_symbols_lane3",			\ 			"FEC corrected symbol counter lane 3")
end_define

begin_comment
unit|\
comment|/*  * Make sure to update mlx5e_update_pport_counters()  * when adding a new MLX5E_PPORT_STATS block  */
end_comment

begin_define
define|#
directive|define
name|MLX5E_PPORT_STATS
parameter_list|(
name|m
parameter_list|)
define|\
value|MLX5E_PPORT_IEEE802_3_STATS(m)		\   MLX5E_PPORT_RFC2819_STATS(m)
end_define

begin_define
define|#
directive|define
name|MLX5E_PORT_STATS_DEBUG
parameter_list|(
name|m
parameter_list|)
define|\
value|MLX5E_PPORT_RFC2819_STATS_DEBUG(m)		\   MLX5E_PPORT_RFC2863_STATS_DEBUG(m)		\   MLX5E_PPORT_PHYSICAL_LAYER_STATS_DEBUG(m)
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_IEEE802_3_STATS_NUM
define|\
value|(0 MLX5E_PPORT_IEEE802_3_STATS(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2819_STATS_NUM
define|\
value|(0 MLX5E_PPORT_RFC2819_STATS(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_STATS_NUM
define|\
value|(0 MLX5E_PPORT_STATS(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2819_STATS_DEBUG_NUM
define|\
value|(0 MLX5E_PPORT_RFC2819_STATS_DEBUG(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_RFC2863_STATS_DEBUG_NUM
define|\
value|(0 MLX5E_PPORT_RFC2863_STATS_DEBUG(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PPORT_PHYSICAL_LAYER_STATS_DEBUG_NUM
define|\
value|(0 MLX5E_PPORT_PHYSICAL_LAYER_STATS_DEBUG(MLX5E_STATS_COUNT))
end_define

begin_define
define|#
directive|define
name|MLX5E_PORT_STATS_DEBUG_NUM
define|\
value|(0 MLX5E_PORT_STATS_DEBUG(MLX5E_STATS_COUNT))
end_define

begin_struct
struct|struct
name|mlx5e_pport_stats
block|{
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_PPORT_STATS
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_port_stats_debug
block|{
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_PORT_STATS_DEBUG
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_RQ_STATS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 packets, "packets", "Received packets")		\   m(+1, u64 csum_none, "csum_none", "Received packets")		\   m(+1, u64 lro_packets, "lro_packets", "Received packets")	\   m(+1, u64 lro_bytes, "lro_bytes", "Received packets")		\   m(+1, u64 sw_lro_queued, "sw_lro_queued", "Packets queued for SW LRO")	\   m(+1, u64 sw_lro_flushed, "sw_lro_flushed", "Packets flushed from SW LRO")	\   m(+1, u64 wqe_err, "wqe_err", "Received packets")
end_define

begin_define
define|#
directive|define
name|MLX5E_RQ_STATS_NUM
value|(0 MLX5E_RQ_STATS(MLX5E_STATS_COUNT))
end_define

begin_struct
struct|struct
name|mlx5e_rq_stats
block|{
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_RQ_STATS
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_SQ_STATS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 packets, "packets", "Transmitted packets")			\   m(+1, u64 tso_packets, "tso_packets", "Transmitted packets")		\   m(+1, u64 tso_bytes, "tso_bytes", "Transmitted bytes")		\   m(+1, u64 csum_offload_none, "csum_offload_none", "Transmitted packets")	\   m(+1, u64 defragged, "defragged", "Transmitted packets")		\   m(+1, u64 dropped, "dropped", "Transmitted packets")			\   m(+1, u64 nop, "nop", "Transmitted packets")
end_define

begin_define
define|#
directive|define
name|MLX5E_SQ_STATS_NUM
value|(0 MLX5E_SQ_STATS(MLX5E_STATS_COUNT))
end_define

begin_struct
struct|struct
name|mlx5e_sq_stats
block|{
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_SQ_STATS
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_stats
block|{
name|struct
name|mlx5e_vport_stats
name|vport
decl_stmt|;
name|struct
name|mlx5e_pport_stats
name|pport
decl_stmt|;
name|struct
name|mlx5e_port_stats_debug
name|port_stats_debug
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_rq_param
block|{
name|u32
name|rqc
index|[
name|MLX5_ST_SZ_DW
argument_list|(
name|rqc
argument_list|)
index|]
decl_stmt|;
name|struct
name|mlx5_wq_param
name|wq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_sq_param
block|{
name|u32
name|sqc
index|[
name|MLX5_ST_SZ_DW
argument_list|(
name|sqc
argument_list|)
index|]
decl_stmt|;
name|struct
name|mlx5_wq_param
name|wq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_cq_param
block|{
name|u32
name|cqc
index|[
name|MLX5_ST_SZ_DW
argument_list|(
name|cqc
argument_list|)
index|]
decl_stmt|;
name|struct
name|mlx5_wq_param
name|wq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_params
block|{
name|u8
name|log_sq_size
decl_stmt|;
name|u8
name|log_rq_size
decl_stmt|;
name|u16
name|num_channels
decl_stmt|;
name|u8
name|default_vlan_prio
decl_stmt|;
name|u8
name|num_tc
decl_stmt|;
name|u8
name|rx_cq_moderation_mode
decl_stmt|;
name|u8
name|tx_cq_moderation_mode
decl_stmt|;
name|u16
name|rx_cq_moderation_usec
decl_stmt|;
name|u16
name|rx_cq_moderation_pkts
decl_stmt|;
name|u16
name|tx_cq_moderation_usec
decl_stmt|;
name|u16
name|tx_cq_moderation_pkts
decl_stmt|;
name|u16
name|min_rx_wqes
decl_stmt|;
name|bool
name|hw_lro_en
decl_stmt|;
name|bool
name|cqe_zipping_en
decl_stmt|;
name|u32
name|lro_wqe_sz
decl_stmt|;
name|u16
name|rx_hash_log_tbl_sz
decl_stmt|;
name|u32
name|tx_pauseframe_control
decl_stmt|;
name|u32
name|rx_pauseframe_control
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_PARAMS
parameter_list|(
name|m
parameter_list|)
define|\
value|m(+1, u64 tx_queue_size_max, "tx_queue_size_max", "Max send queue size") \   m(+1, u64 rx_queue_size_max, "rx_queue_size_max", "Max receive queue size") \   m(+1, u64 tx_queue_size, "tx_queue_size", "Default send queue size")	\   m(+1, u64 rx_queue_size, "rx_queue_size", "Default receive queue size") \   m(+1, u64 channels, "channels", "Default number of channels")		\   m(+1, u64 coalesce_usecs_max, "coalesce_usecs_max", "Maximum usecs for joining packets") \   m(+1, u64 coalesce_pkts_max, "coalesce_pkts_max", "Maximum packets to join") \   m(+1, u64 rx_coalesce_usecs, "rx_coalesce_usecs", "Limit in usec for joining rx packets") \   m(+1, u64 rx_coalesce_pkts, "rx_coalesce_pkts", "Maximum number of rx packets to join") \   m(+1, u64 rx_coalesce_mode, "rx_coalesce_mode", "0: EQE mode 1: CQE mode") \   m(+1, u64 tx_coalesce_usecs, "tx_coalesce_usecs", "Limit in usec for joining tx packets") \   m(+1, u64 tx_coalesce_pkts, "tx_coalesce_pkts", "Maximum number of tx packets to join") \   m(+1, u64 tx_coalesce_mode, "tx_coalesce_mode", "0: EQE mode 1: CQE mode") \   m(+1, u64 tx_bufring_disable, "tx_bufring_disable", "0: Enable bufring 1: Disable bufring") \   m(+1, u64 tx_completion_fact, "tx_completion_fact", "1..MAX: Completion event ratio") \   m(+1, u64 tx_completion_fact_max, "tx_completion_fact_max", "Maximum completion event ratio") \   m(+1, u64 hw_lro, "hw_lro", "set to enable hw_lro") \   m(+1, u64 cqe_zipping, "cqe_zipping", "0 : CQE zipping disabled")
end_define

begin_define
define|#
directive|define
name|MLX5E_PARAMS_NUM
value|(0 MLX5E_PARAMS(MLX5E_STATS_COUNT))
end_define

begin_struct
struct|struct
name|mlx5e_params_ethtool
block|{
name|u64
name|arg
index|[
literal|0
index|]
decl_stmt|;
name|MLX5E_PARAMS
argument_list|(
argument|MLX5E_STATS_VAR
argument_list|)
block|}
struct|;
end_struct

begin_comment
comment|/* EEPROM Standards for plug in modules */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX5E_ETH_MODULE_SFF_8472
end_ifndef

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8472
value|0x1
end_define

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8472_LEN
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLX5E_ETH_MODULE_SFF_8636
end_ifndef

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8636
value|0x2
end_define

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8636_LEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MLX5E_ETH_MODULE_SFF_8436
end_ifndef

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8436
value|0x3
end_define

begin_define
define|#
directive|define
name|MLX5E_ETH_MODULE_SFF_8436_LEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EEPROM I2C Addresses */
end_comment

begin_define
define|#
directive|define
name|MLX5E_I2C_ADDR_LOW
value|0x50
end_define

begin_define
define|#
directive|define
name|MLX5E_I2C_ADDR_HIGH
value|0x51
end_define

begin_define
define|#
directive|define
name|MLX5E_EEPROM_LOW_PAGE
value|0x0
end_define

begin_define
define|#
directive|define
name|MLX5E_EEPROM_HIGH_PAGE
value|0x3
end_define

begin_define
define|#
directive|define
name|MLX5E_EEPROM_HIGH_PAGE_OFFSET
value|128
end_define

begin_define
define|#
directive|define
name|MLX5E_EEPROM_PAGE_LENGTH
value|256
end_define

begin_define
define|#
directive|define
name|MLX5E_EEPROM_INFO_BYTES
value|0x3
end_define

begin_struct
struct|struct
name|mlx5e_cq
block|{
comment|/* data path - accessed per cqe */
name|struct
name|mlx5_cqwq
name|wq
decl_stmt|;
comment|/* data path - accessed per HW polling */
name|struct
name|mlx5_core_cq
name|mcq
decl_stmt|;
comment|/* control */
name|struct
name|mlx5e_priv
modifier|*
name|priv
decl_stmt|;
name|struct
name|mlx5_wq_ctrl
name|wq_ctrl
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|MLX5E_CACHELINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_rq_mbuf
block|{
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_rq
block|{
comment|/* data path */
name|struct
name|mlx5_wq_ll
name|wq
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|u32
name|wqe_sz
decl_stmt|;
name|struct
name|mlx5e_rq_mbuf
modifier|*
name|mbuf
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|mlx5e_rq_stats
name|stats
decl_stmt|;
name|struct
name|mlx5e_cq
name|cq
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
specifier|volatile
name|int
name|enabled
decl_stmt|;
name|int
name|ix
decl_stmt|;
comment|/* control */
name|struct
name|mlx5_wq_ctrl
name|wq_ctrl
decl_stmt|;
name|u32
name|rqn
decl_stmt|;
name|struct
name|mlx5e_channel
modifier|*
name|channel
decl_stmt|;
name|struct
name|callout
name|watchdog
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|MLX5E_CACHELINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_sq_mbuf
block|{
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|u32
name|num_bytes
decl_stmt|;
name|u32
name|num_wqebbs
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|MLX5E_SQ_READY
block|,
name|MLX5E_SQ_FULL
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mlx5e_sq
block|{
comment|/* data path */
name|struct
name|mtx
name|lock
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|struct
name|mtx
name|comp_lock
decl_stmt|;
comment|/* dirtied @completion */
name|u16
name|cc
decl_stmt|;
comment|/* dirtied @xmit */
name|u16
name|pc
name|__aligned
parameter_list|(
name|MLX5E_CACHELINE_SIZE
parameter_list|)
function_decl|;
name|u16
name|bf_offset
decl_stmt|;
name|u16
name|cev_counter
decl_stmt|;
comment|/* completion event counter */
name|u16
name|cev_factor
decl_stmt|;
comment|/* completion event factor */
name|u16
name|cev_next_state
decl_stmt|;
comment|/* next completion event state */
define|#
directive|define
name|MLX5E_CEV_STATE_INITIAL
value|0
comment|/* timer not started */
define|#
directive|define
name|MLX5E_CEV_STATE_SEND_NOPS
value|1
comment|/* send NOPs */
define|#
directive|define
name|MLX5E_CEV_STATE_HOLD_NOPS
value|2
comment|/* don't send NOPs yet */
name|u16
name|stopped
decl_stmt|;
comment|/* set if SQ is stopped */
name|struct
name|callout
name|cev_callout
decl_stmt|;
union|union
block|{
name|u32
name|d32
index|[
literal|2
index|]
decl_stmt|;
name|u64
name|d64
decl_stmt|;
block|}
name|doorbell
union|;
name|struct
name|mlx5e_sq_stats
name|stats
decl_stmt|;
name|struct
name|mlx5e_cq
name|cq
decl_stmt|;
name|struct
name|task
name|sq_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sq_tq
decl_stmt|;
comment|/* pointers to per packet info: write@xmit, read@completion */
name|struct
name|mlx5e_sq_mbuf
modifier|*
name|mbuf
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* read only */
name|struct
name|mlx5_wq_cyc
name|wq
decl_stmt|;
name|struct
name|mlx5_uar
name|uar
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|u32
name|sqn
decl_stmt|;
name|u32
name|bf_buf_size
decl_stmt|;
name|u32
name|mkey_be
decl_stmt|;
comment|/* control path */
name|struct
name|mlx5_wq_ctrl
name|wq_ctrl
decl_stmt|;
name|struct
name|mlx5e_priv
modifier|*
name|priv
decl_stmt|;
name|int
name|tc
decl_stmt|;
name|unsigned
name|int
name|queue_state
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|MLX5E_CACHELINE_SIZE
argument_list|)
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|bool
name|mlx5e_sq_has_room_for
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
name|sq
parameter_list|,
name|u16
name|n
parameter_list|)
block|{
name|u16
name|cc
init|=
name|sq
operator|->
name|cc
decl_stmt|;
name|u16
name|pc
init|=
name|sq
operator|->
name|pc
decl_stmt|;
return|return
operator|(
operator|(
name|sq
operator|->
name|wq
operator|.
name|sz_m1
operator|&
operator|(
name|cc
operator|-
name|pc
operator|)
operator|)
operator|>=
name|n
operator|||
name|cc
operator|==
name|pc
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|mlx5e_channel
block|{
comment|/* data path */
name|struct
name|mlx5e_rq
name|rq
decl_stmt|;
name|struct
name|mlx5e_sq
name|sq
index|[
name|MLX5E_MAX_TX_NUM_TC
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|u32
name|mkey_be
decl_stmt|;
name|u8
name|num_tc
decl_stmt|;
comment|/* control */
name|struct
name|mlx5e_priv
modifier|*
name|priv
decl_stmt|;
name|int
name|ix
decl_stmt|;
name|int
name|cpu
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|MLX5E_CACHELINE_SIZE
argument_list|)
struct|;
end_struct

begin_enum
enum|enum
name|mlx5e_traffic_types
block|{
name|MLX5E_TT_IPV4_TCP
block|,
name|MLX5E_TT_IPV6_TCP
block|,
name|MLX5E_TT_IPV4_UDP
block|,
name|MLX5E_TT_IPV6_UDP
block|,
name|MLX5E_TT_IPV4_IPSEC_AH
block|,
name|MLX5E_TT_IPV6_IPSEC_AH
block|,
name|MLX5E_TT_IPV4_IPSEC_ESP
block|,
name|MLX5E_TT_IPV6_IPSEC_ESP
block|,
name|MLX5E_TT_IPV4
block|,
name|MLX5E_TT_IPV6
block|,
name|MLX5E_TT_ANY
block|,
name|MLX5E_NUM_TT
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|MLX5E_RQT_SPREADING
init|=
literal|0
block|,
name|MLX5E_RQT_DEFAULT_RQ
init|=
literal|1
block|,
name|MLX5E_NUM_RQT
init|=
literal|2
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|mlx5e_eth_addr_info
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
operator|+
literal|2
index|]
decl_stmt|;
name|u32
name|tt_vec
decl_stmt|;
name|u32
name|ft_ix
index|[
name|MLX5E_NUM_TT
index|]
decl_stmt|;
comment|/* flow table index per traffic type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_ETH_ADDR_HASH_SIZE
value|(1<< BITS_PER_BYTE)
end_define

begin_struct_decl
struct_decl|struct
name|mlx5e_eth_addr_hash_node
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mlx5e_eth_addr_hash_head
block|{
name|struct
name|mlx5e_eth_addr_hash_node
modifier|*
name|lh_first
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_eth_addr_db
block|{
name|struct
name|mlx5e_eth_addr_hash_head
name|if_uc
index|[
name|MLX5E_ETH_ADDR_HASH_SIZE
index|]
decl_stmt|;
name|struct
name|mlx5e_eth_addr_hash_head
name|if_mc
index|[
name|MLX5E_ETH_ADDR_HASH_SIZE
index|]
decl_stmt|;
name|struct
name|mlx5e_eth_addr_info
name|broadcast
decl_stmt|;
name|struct
name|mlx5e_eth_addr_info
name|allmulti
decl_stmt|;
name|struct
name|mlx5e_eth_addr_info
name|promisc
decl_stmt|;
name|bool
name|broadcast_enabled
decl_stmt|;
name|bool
name|allmulti_enabled
decl_stmt|;
name|bool
name|promisc_enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|MLX5E_STATE_ASYNC_EVENTS_ENABLE
block|,
name|MLX5E_STATE_OPENED
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|mlx5e_vlan_db
block|{
name|unsigned
name|long
name|active_vlans
index|[
name|BITS_TO_LONGS
argument_list|(
name|VLAN_N_VID
argument_list|)
index|]
decl_stmt|;
name|u32
name|active_vlans_ft_ix
index|[
name|VLAN_N_VID
index|]
decl_stmt|;
name|u32
name|untagged_rule_ft_ix
decl_stmt|;
name|u32
name|any_vlan_rule_ft_ix
decl_stmt|;
name|bool
name|filter_disabled
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_flow_table
block|{
name|void
modifier|*
name|vlan
decl_stmt|;
name|void
modifier|*
decl|main
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_priv
block|{
comment|/* priv data path fields - start */
name|int
name|order_base_2_num_channels
decl_stmt|;
name|int
name|queue_mapping_channel_mask
decl_stmt|;
name|int
name|num_tc
decl_stmt|;
name|int
name|default_vlan_prio
decl_stmt|;
comment|/* priv data path fields - end */
name|unsigned
name|long
name|state
decl_stmt|;
name|int
name|gone
decl_stmt|;
define|#
directive|define
name|PRIV_LOCK
parameter_list|(
name|priv
parameter_list|)
value|sx_xlock(&(priv)->state_lock)
define|#
directive|define
name|PRIV_UNLOCK
parameter_list|(
name|priv
parameter_list|)
value|sx_xunlock(&(priv)->state_lock)
define|#
directive|define
name|PRIV_LOCKED
parameter_list|(
name|priv
parameter_list|)
value|sx_xlocked(&(priv)->state_lock)
name|struct
name|sx
name|state_lock
decl_stmt|;
comment|/* Protects Interface state */
name|struct
name|mlx5_uar
name|cq_uar
decl_stmt|;
name|u32
name|pdn
decl_stmt|;
name|u32
name|tdn
decl_stmt|;
name|struct
name|mlx5_core_mr
name|mr
decl_stmt|;
name|struct
name|mlx5e_channel
modifier|*
specifier|volatile
modifier|*
name|channel
decl_stmt|;
name|u32
name|tisn
index|[
name|MLX5E_MAX_TX_NUM_TC
index|]
decl_stmt|;
name|u32
name|rqtn
decl_stmt|;
name|u32
name|tirn
index|[
name|MLX5E_NUM_TT
index|]
decl_stmt|;
name|struct
name|mlx5e_flow_table
name|ft
decl_stmt|;
name|struct
name|mlx5e_eth_addr_db
name|eth_addr
decl_stmt|;
name|struct
name|mlx5e_vlan_db
name|vlan
decl_stmt|;
name|struct
name|mlx5e_params
name|params
decl_stmt|;
name|struct
name|mlx5e_params_ethtool
name|params_ethtool
decl_stmt|;
name|struct
name|mtx
name|async_events_mtx
decl_stmt|;
comment|/* sync hw events */
name|struct
name|work_struct
name|update_stats_work
decl_stmt|;
name|struct
name|work_struct
name|update_carrier_work
decl_stmt|;
name|struct
name|work_struct
name|set_rx_mode_work
decl_stmt|;
name|MLX5_DECLARE_DOORBELL_LOCK
argument_list|(
argument|doorbell_lock
argument_list|)
name|struct
name|mlx5_core_dev
modifier|*
name|mdev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_ifnet
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_hw
decl_stmt|;
name|int
name|sysctl_debug
decl_stmt|;
name|struct
name|mlx5e_stats
name|stats
decl_stmt|;
name|int
name|counter_set_id
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|int
name|media_status_last
decl_stmt|;
name|int
name|media_active_last
decl_stmt|;
name|struct
name|callout
name|watchdog
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MLX5E_NET_IP_ALIGN
value|2
end_define

begin_struct
struct|struct
name|mlx5e_tx_wqe
block|{
name|struct
name|mlx5_wqe_ctrl_seg
name|ctrl
decl_stmt|;
name|struct
name|mlx5_wqe_eth_seg
name|eth
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_rx_wqe
block|{
name|struct
name|mlx5_wqe_srq_next_seg
name|next
decl_stmt|;
name|struct
name|mlx5_wqe_data_seg
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx5e_eeprom
block|{
name|int
name|lock_bit
decl_stmt|;
name|int
name|i2c_addr
decl_stmt|;
name|int
name|page_num
decl_stmt|;
name|int
name|device_addr
decl_stmt|;
name|int
name|module_num
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|page_valid
decl_stmt|;
name|u32
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mlx5e_link_mode
block|{
name|MLX5E_1000BASE_CX_SGMII
init|=
literal|0
block|,
name|MLX5E_1000BASE_KX
init|=
literal|1
block|,
name|MLX5E_10GBASE_CX4
init|=
literal|2
block|,
name|MLX5E_10GBASE_KX4
init|=
literal|3
block|,
name|MLX5E_10GBASE_KR
init|=
literal|4
block|,
name|MLX5E_20GBASE_KR2
init|=
literal|5
block|,
name|MLX5E_40GBASE_CR4
init|=
literal|6
block|,
name|MLX5E_40GBASE_KR4
init|=
literal|7
block|,
name|MLX5E_56GBASE_R4
init|=
literal|8
block|,
name|MLX5E_10GBASE_CR
init|=
literal|12
block|,
name|MLX5E_10GBASE_SR
init|=
literal|13
block|,
name|MLX5E_10GBASE_LR
init|=
literal|14
block|,
name|MLX5E_40GBASE_SR4
init|=
literal|15
block|,
name|MLX5E_40GBASE_LR4
init|=
literal|16
block|,
name|MLX5E_100GBASE_CR4
init|=
literal|20
block|,
name|MLX5E_100GBASE_SR4
init|=
literal|21
block|,
name|MLX5E_100GBASE_KR4
init|=
literal|22
block|,
name|MLX5E_100GBASE_LR4
init|=
literal|23
block|,
name|MLX5E_100BASE_TX
init|=
literal|24
block|,
name|MLX5E_100BASE_T
init|=
literal|25
block|,
name|MLX5E_10GBASE_T
init|=
literal|26
block|,
name|MLX5E_25GBASE_CR
init|=
literal|27
block|,
name|MLX5E_25GBASE_KR
init|=
literal|28
block|,
name|MLX5E_25GBASE_SR
init|=
literal|29
block|,
name|MLX5E_50GBASE_CR2
init|=
literal|30
block|,
name|MLX5E_50GBASE_KR2
init|=
literal|31
block|,
name|MLX5E_LINK_MODES_NUMBER
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MLX5E_PROT_MASK
parameter_list|(
name|link_mode
parameter_list|)
value|(1<< (link_mode))
end_define

begin_define
define|#
directive|define
name|MLX5E_FLD_MAX
parameter_list|(
name|typ
parameter_list|,
name|fld
parameter_list|)
value|((1ULL<< __mlx5_bit_sz(typ, fld)) - 1ULL)
end_define

begin_function_decl
name|int
name|mlx5e_xmit
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_open_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_close_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_cq_error_event
parameter_list|(
name|struct
name|mlx5_core_cq
modifier|*
name|mcq
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_rx_cq_comp
parameter_list|(
name|struct
name|mlx5_core_cq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_tx_cq_comp
parameter_list|(
name|struct
name|mlx5_core_cq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mlx5_cqe64
modifier|*
name|mlx5e_get_cqe
parameter_list|(
name|struct
name|mlx5e_cq
modifier|*
name|cq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_tx_que
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_open_flow_table
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_close_flow_table
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_set_rx_mode_core
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_set_rx_mode_work
parameter_list|(
name|struct
name|work_struct
modifier|*
name|work
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_vlan_rx_add_vid
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_vlan_rx_kill_vid
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_enable_vlan_filter
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_disable_vlan_filter
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_add_all_vlan_rules
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_del_all_vlan_rules
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|mlx5e_tx_notify_hw
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
name|sq
parameter_list|,
name|u32
modifier|*
name|wqe
parameter_list|,
name|int
name|bf_sz
parameter_list|)
block|{
name|u16
name|ofst
init|=
name|MLX5_BF_OFFSET
operator|+
name|sq
operator|->
name|bf_offset
decl_stmt|;
comment|/* ensure wqe is visible to device before updating doorbell record */
name|wmb
argument_list|()
expr_stmt|;
operator|*
name|sq
operator|->
name|wq
operator|.
name|db
operator|=
name|cpu_to_be32
argument_list|(
name|sq
operator|->
name|pc
argument_list|)
expr_stmt|;
comment|/* 	 * Ensure the doorbell record is visible to device before ringing 	 * the doorbell: 	 */
name|wmb
argument_list|()
expr_stmt|;
if|if
condition|(
name|bf_sz
condition|)
block|{
name|__iowrite64_copy
argument_list|(
name|sq
operator|->
name|uar
operator|.
name|bf_map
operator|+
name|ofst
argument_list|,
name|wqe
argument_list|,
name|bf_sz
argument_list|)
expr_stmt|;
comment|/* flush the write-combining mapped buffer */
name|wmb
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|mlx5_write64
argument_list|(
name|wqe
argument_list|,
name|sq
operator|->
name|uar
operator|.
name|map
operator|+
name|ofst
argument_list|,
name|MLX5_GET_DOORBELL_LOCK
argument_list|(
operator|&
name|sq
operator|->
name|priv
operator|->
name|doorbell_lock
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|sq
operator|->
name|bf_offset
operator|^=
name|sq
operator|->
name|bf_buf_size
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mlx5e_cq_arm
parameter_list|(
name|struct
name|mlx5e_cq
modifier|*
name|cq
parameter_list|)
block|{
name|struct
name|mlx5_core_cq
modifier|*
name|mcq
decl_stmt|;
name|mcq
operator|=
operator|&
name|cq
operator|->
name|mcq
expr_stmt|;
name|mlx5_cq_arm
argument_list|(
name|mcq
argument_list|,
name|MLX5_CQ_DB_REQ_NOT
argument_list|,
name|mcq
operator|->
name|uar
operator|->
name|map
argument_list|,
name|NULL
argument_list|,
name|cq
operator|->
name|wq
operator|.
name|cc
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ethtool_ops
name|mlx5e_ethtool_ops
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mlx5e_create_ethtool
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_create_stats
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|u64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_send_nop
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_sq_cev_timeout
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_refresh_channel_params
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_open_cq
parameter_list|(
name|struct
name|mlx5e_priv
modifier|*
parameter_list|,
name|struct
name|mlx5e_cq_param
modifier|*
parameter_list|,
name|struct
name|mlx5e_cq
modifier|*
parameter_list|,
name|mlx5e_cq_comp_t
modifier|*
parameter_list|,
name|int
name|eq_ix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_close_cq
parameter_list|(
name|struct
name|mlx5e_cq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_free_sq_db
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_alloc_sq_db
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_enable_sq
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|,
name|struct
name|mlx5e_sq_param
modifier|*
parameter_list|,
name|int
name|tis_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5e_modify_sq
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|,
name|int
name|curr_state
parameter_list|,
name|int
name|next_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_disable_sq
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_drain_sq
parameter_list|(
name|struct
name|mlx5e_sq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MLX5_EN_H_ */
end_comment

end_unit

