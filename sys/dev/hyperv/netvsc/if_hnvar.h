begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_HNVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_HNVAR_H_
end_define

begin_define
define|#
directive|define
name|HN_USE_TXDESC_BUFRING
end_define

begin_define
define|#
directive|define
name|HN_CHIM_SIZE
value|(15 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|HN_RXBUF_SIZE
value|(16 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|HN_RXBUF_SIZE_COMPAT
value|(15 * 1024 * 1024)
end_define

begin_comment
comment|/* Claimed to be 12232B */
end_comment

begin_define
define|#
directive|define
name|HN_MTU_MAX
value|(9 * 1024)
end_define

begin_define
define|#
directive|define
name|HN_TXBR_SIZE
value|(128 * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|HN_RXBR_SIZE
value|(128 * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|HN_XACT_REQ_PGCNT
value|2
end_define

begin_define
define|#
directive|define
name|HN_XACT_RESP_PGCNT
value|2
end_define

begin_define
define|#
directive|define
name|HN_XACT_REQ_SIZE
value|(HN_XACT_REQ_PGCNT * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|HN_XACT_RESP_SIZE
value|(HN_XACT_RESP_PGCNT * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|HN_GPACNT_MAX
value|32
end_define

begin_struct_decl
struct_decl|struct
name|hn_txdesc
struct_decl|;
end_struct_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HN_USE_TXDESC_BUFRING
end_ifndef

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|hn_txdesc_list
argument_list|,
name|hn_txdesc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|buf_ring
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|hn_tx_ring
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hn_rx_ring
block|{
name|struct
name|ifnet
modifier|*
name|hn_ifp
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|hn_rxvf_ifp
decl_stmt|;
comment|/* SR-IOV VF for RX */
name|struct
name|hn_tx_ring
modifier|*
name|hn_txr
decl_stmt|;
name|void
modifier|*
name|hn_pktbuf
decl_stmt|;
name|int
name|hn_pktbuf_len
decl_stmt|;
name|uint8_t
modifier|*
name|hn_rxbuf
decl_stmt|;
comment|/* shadow sc->hn_rxbuf */
name|int
name|hn_rx_idx
decl_stmt|;
comment|/* Trust csum verification on host side */
name|int
name|hn_trust_hcsum
decl_stmt|;
comment|/* HN_TRUST_HCSUM_ */
name|struct
name|lro_ctrl
name|hn_lro
decl_stmt|;
name|u_long
name|hn_csum_ip
decl_stmt|;
name|u_long
name|hn_csum_tcp
decl_stmt|;
name|u_long
name|hn_csum_udp
decl_stmt|;
name|u_long
name|hn_csum_trusted
decl_stmt|;
name|u_long
name|hn_lro_tried
decl_stmt|;
name|u_long
name|hn_small_pkts
decl_stmt|;
name|u_long
name|hn_pkts
decl_stmt|;
name|u_long
name|hn_rss_pkts
decl_stmt|;
name|u_long
name|hn_ack_failed
decl_stmt|;
comment|/* Rarely used stuffs */
name|struct
name|sysctl_oid
modifier|*
name|hn_rx_sysctl_tree
decl_stmt|;
name|int
name|hn_rx_flags
decl_stmt|;
name|void
modifier|*
name|hn_br
decl_stmt|;
comment|/* TX/RX bufring */
name|struct
name|hyperv_dma
name|hn_br_dma
decl_stmt|;
name|struct
name|vmbus_channel
modifier|*
name|hn_chan
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|HN_TRUST_HCSUM_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_TRUST_HCSUM_TCP
value|0x0002
end_define

begin_define
define|#
directive|define
name|HN_TRUST_HCSUM_UDP
value|0x0004
end_define

begin_define
define|#
directive|define
name|HN_RX_FLAG_ATTACHED
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_RX_FLAG_BR_REF
value|0x0002
end_define

begin_struct
struct|struct
name|hn_tx_ring
block|{
ifndef|#
directive|ifndef
name|HN_USE_TXDESC_BUFRING
name|struct
name|mtx
name|hn_txlist_spin
decl_stmt|;
name|struct
name|hn_txdesc_list
name|hn_txlist
decl_stmt|;
else|#
directive|else
name|struct
name|buf_ring
modifier|*
name|hn_txdesc_br
decl_stmt|;
endif|#
directive|endif
name|int
name|hn_txdesc_cnt
decl_stmt|;
name|int
name|hn_txdesc_avail
decl_stmt|;
name|u_short
name|hn_has_txeof
decl_stmt|;
name|u_short
name|hn_txdone_cnt
decl_stmt|;
name|int
name|hn_sched_tx
decl_stmt|;
name|void
function_decl|(
modifier|*
name|hn_txeof
function_decl|)
parameter_list|(
name|struct
name|hn_tx_ring
modifier|*
parameter_list|)
function_decl|;
name|struct
name|taskqueue
modifier|*
name|hn_tx_taskq
decl_stmt|;
name|struct
name|task
name|hn_tx_task
decl_stmt|;
name|struct
name|task
name|hn_txeof_task
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|hn_mbuf_br
decl_stmt|;
name|int
name|hn_oactive
decl_stmt|;
name|int
name|hn_tx_idx
decl_stmt|;
name|int
name|hn_tx_flags
decl_stmt|;
name|struct
name|mtx
name|hn_tx_lock
decl_stmt|;
name|struct
name|hn_softc
modifier|*
name|hn_sc
decl_stmt|;
name|struct
name|vmbus_channel
modifier|*
name|hn_chan
decl_stmt|;
name|int
name|hn_direct_tx_size
decl_stmt|;
name|int
name|hn_chim_size
decl_stmt|;
name|bus_dma_tag_t
name|hn_tx_data_dtag
decl_stmt|;
name|uint64_t
name|hn_csum_assist
decl_stmt|;
comment|/* Applied packet transmission aggregation limits. */
name|int
name|hn_agg_szmax
decl_stmt|;
name|short
name|hn_agg_pktmax
decl_stmt|;
name|short
name|hn_agg_align
decl_stmt|;
comment|/* Packet transmission aggregation states. */
name|struct
name|hn_txdesc
modifier|*
name|hn_agg_txd
decl_stmt|;
name|int
name|hn_agg_szleft
decl_stmt|;
name|short
name|hn_agg_pktleft
decl_stmt|;
name|struct
name|rndis_packet_msg
modifier|*
name|hn_agg_prevpkt
decl_stmt|;
comment|/* Temporary stats for each sends. */
name|int
name|hn_stat_size
decl_stmt|;
name|short
name|hn_stat_pkts
decl_stmt|;
name|short
name|hn_stat_mcasts
decl_stmt|;
name|int
function_decl|(
modifier|*
name|hn_sendpkt
function_decl|)
parameter_list|(
name|struct
name|hn_tx_ring
modifier|*
parameter_list|,
name|struct
name|hn_txdesc
modifier|*
parameter_list|)
function_decl|;
name|int
name|hn_suspended
decl_stmt|;
name|int
name|hn_gpa_cnt
decl_stmt|;
name|struct
name|vmbus_gpa
name|hn_gpa
index|[
name|HN_GPACNT_MAX
index|]
decl_stmt|;
name|u_long
name|hn_no_txdescs
decl_stmt|;
name|u_long
name|hn_send_failed
decl_stmt|;
name|u_long
name|hn_txdma_failed
decl_stmt|;
name|u_long
name|hn_tx_collapsed
decl_stmt|;
name|u_long
name|hn_tx_chimney_tried
decl_stmt|;
name|u_long
name|hn_tx_chimney
decl_stmt|;
name|u_long
name|hn_pkts
decl_stmt|;
name|u_long
name|hn_sends
decl_stmt|;
name|u_long
name|hn_flush_failed
decl_stmt|;
comment|/* Rarely used stuffs */
name|struct
name|hn_txdesc
modifier|*
name|hn_txdesc
decl_stmt|;
name|bus_dma_tag_t
name|hn_tx_rndis_dtag
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|hn_tx_sysctl_tree
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|HN_TX_FLAG_ATTACHED
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_TX_FLAG_HASHVAL
value|0x0002
end_define

begin_comment
comment|/* support HASHVAL pktinfo */
end_comment

begin_comment
comment|/*  * Device-specific softc structure  */
end_comment

begin_struct
struct|struct
name|hn_softc
block|{
name|struct
name|ifnet
modifier|*
name|hn_ifp
decl_stmt|;
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|hn_vf_ifp
decl_stmt|;
comment|/* SR-IOV VF */
name|struct
name|ifmedia
name|hn_media
decl_stmt|;
name|device_t
name|hn_dev
decl_stmt|;
name|int
name|hn_if_flags
decl_stmt|;
name|struct
name|sx
name|hn_lock
decl_stmt|;
name|struct
name|vmbus_channel
modifier|*
name|hn_prichan
decl_stmt|;
name|int
name|hn_rx_ring_cnt
decl_stmt|;
name|int
name|hn_rx_ring_inuse
decl_stmt|;
name|struct
name|hn_rx_ring
modifier|*
name|hn_rx_ring
decl_stmt|;
name|int
name|hn_tx_ring_cnt
decl_stmt|;
name|int
name|hn_tx_ring_inuse
decl_stmt|;
name|struct
name|hn_tx_ring
modifier|*
name|hn_tx_ring
decl_stmt|;
name|uint8_t
modifier|*
name|hn_chim
decl_stmt|;
name|u_long
modifier|*
name|hn_chim_bmap
decl_stmt|;
name|int
name|hn_chim_bmap_cnt
decl_stmt|;
name|int
name|hn_chim_cnt
decl_stmt|;
name|int
name|hn_chim_szmax
decl_stmt|;
name|int
name|hn_cpu
decl_stmt|;
name|struct
name|taskqueue
modifier|*
modifier|*
name|hn_tx_taskqs
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|hn_tx_sysctl_tree
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|hn_rx_sysctl_tree
decl_stmt|;
name|struct
name|vmbus_xact_ctx
modifier|*
name|hn_xact
decl_stmt|;
name|uint32_t
name|hn_nvs_ver
decl_stmt|;
name|uint32_t
name|hn_rx_filter
decl_stmt|;
comment|/* Packet transmission aggregation user settings. */
name|int
name|hn_agg_size
decl_stmt|;
name|int
name|hn_agg_pkts
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|hn_mgmt_taskq
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|hn_mgmt_taskq0
decl_stmt|;
name|struct
name|task
name|hn_link_task
decl_stmt|;
name|struct
name|task
name|hn_netchg_init
decl_stmt|;
name|struct
name|timeout_task
name|hn_netchg_status
decl_stmt|;
name|uint32_t
name|hn_link_flags
decl_stmt|;
comment|/* HN_LINK_FLAG_ */
name|uint32_t
name|hn_caps
decl_stmt|;
comment|/* HN_CAP_ */
name|uint32_t
name|hn_flags
decl_stmt|;
comment|/* HN_FLAG_ */
name|u_int
name|hn_pollhz
decl_stmt|;
name|void
modifier|*
name|hn_rxbuf
decl_stmt|;
name|uint32_t
name|hn_rxbuf_gpadl
decl_stmt|;
name|struct
name|hyperv_dma
name|hn_rxbuf_dma
decl_stmt|;
name|uint32_t
name|hn_chim_gpadl
decl_stmt|;
name|struct
name|hyperv_dma
name|hn_chim_dma
decl_stmt|;
name|uint32_t
name|hn_rndis_rid
decl_stmt|;
name|uint32_t
name|hn_ndis_ver
decl_stmt|;
name|int
name|hn_ndis_tso_szmax
decl_stmt|;
name|int
name|hn_ndis_tso_sgmin
decl_stmt|;
name|uint32_t
name|hn_rndis_agg_size
decl_stmt|;
name|uint32_t
name|hn_rndis_agg_pkts
decl_stmt|;
name|uint32_t
name|hn_rndis_agg_align
decl_stmt|;
name|int
name|hn_rss_ind_size
decl_stmt|;
name|uint32_t
name|hn_rss_hash
decl_stmt|;
comment|/* NDIS_HASH_ */
name|struct
name|ndis_rssprm_toeplitz
name|hn_rss
decl_stmt|;
name|eventhandler_tag
name|hn_ifaddr_evthand
decl_stmt|;
name|eventhandler_tag
name|hn_ifnet_evthand
decl_stmt|;
name|eventhandler_tag
name|hn_ifnet_atthand
decl_stmt|;
name|eventhandler_tag
name|hn_ifnet_dethand
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HN_FLAG_RXBUF_CONNECTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_FLAG_CHIM_CONNECTED
value|0x0002
end_define

begin_define
define|#
directive|define
name|HN_FLAG_HAS_RSSKEY
value|0x0004
end_define

begin_define
define|#
directive|define
name|HN_FLAG_HAS_RSSIND
value|0x0008
end_define

begin_define
define|#
directive|define
name|HN_FLAG_SYNTH_ATTACHED
value|0x0010
end_define

begin_define
define|#
directive|define
name|HN_FLAG_NO_SLEEPING
value|0x0020
end_define

begin_define
define|#
directive|define
name|HN_FLAG_RXBUF_REF
value|0x0040
end_define

begin_define
define|#
directive|define
name|HN_FLAG_CHIM_REF
value|0x0080
end_define

begin_define
define|#
directive|define
name|HN_FLAG_VF
value|0x0100
end_define

begin_define
define|#
directive|define
name|HN_FLAG_ERRORS
value|(HN_FLAG_RXBUF_REF | HN_FLAG_CHIM_REF)
end_define

begin_define
define|#
directive|define
name|HN_NO_SLEEPING
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {						\ 	(sc)->hn_flags |= HN_FLAG_NO_SLEEPING;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|HN_SLEEPING_OK
parameter_list|(
name|sc
parameter_list|)
define|\
value|do {						\ 	(sc)->hn_flags&= ~HN_FLAG_NO_SLEEPING;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|HN_CAN_SLEEP
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->hn_flags& HN_FLAG_NO_SLEEPING) == 0)
end_define

begin_define
define|#
directive|define
name|HN_CAP_VLAN
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_CAP_MTU
value|0x0002
end_define

begin_define
define|#
directive|define
name|HN_CAP_IPCS
value|0x0004
end_define

begin_define
define|#
directive|define
name|HN_CAP_TCP4CS
value|0x0008
end_define

begin_define
define|#
directive|define
name|HN_CAP_TCP6CS
value|0x0010
end_define

begin_define
define|#
directive|define
name|HN_CAP_UDP4CS
value|0x0020
end_define

begin_define
define|#
directive|define
name|HN_CAP_UDP6CS
value|0x0040
end_define

begin_define
define|#
directive|define
name|HN_CAP_TSO4
value|0x0080
end_define

begin_define
define|#
directive|define
name|HN_CAP_TSO6
value|0x0100
end_define

begin_define
define|#
directive|define
name|HN_CAP_HASHVAL
value|0x0200
end_define

begin_comment
comment|/* Capability description for use with printf(9) %b identifier. */
end_comment

begin_define
define|#
directive|define
name|HN_CAP_BITS
define|\
value|"\020\1VLAN\2MTU\3IPCS\4TCP4CS\5TCP6CS"	\ 	"\6UDP4CS\7UDP6CS\10TSO4\11TSO6\12HASHVAL"
end_define

begin_define
define|#
directive|define
name|HN_LINK_FLAG_LINKUP
value|0x0001
end_define

begin_define
define|#
directive|define
name|HN_LINK_FLAG_NETCHG
value|0x0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_HNVAR_H_ */
end_comment

end_unit

