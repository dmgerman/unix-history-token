begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, Bryan Venteicher<bryanv@daemoninthecloset.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VTNETVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_VTNETVAR_H
end_define

begin_struct
struct|struct
name|vtnet_statistics
block|{
name|unsigned
name|long
name|mbuf_alloc_failed
decl_stmt|;
name|unsigned
name|long
name|rx_frame_too_large
decl_stmt|;
name|unsigned
name|long
name|rx_enq_replacement_failed
decl_stmt|;
name|unsigned
name|long
name|rx_mergeable_failed
decl_stmt|;
name|unsigned
name|long
name|rx_csum_bad_ethtype
decl_stmt|;
name|unsigned
name|long
name|rx_csum_bad_start
decl_stmt|;
name|unsigned
name|long
name|rx_csum_bad_ipproto
decl_stmt|;
name|unsigned
name|long
name|rx_csum_bad_offset
decl_stmt|;
name|unsigned
name|long
name|rx_csum_failed
decl_stmt|;
name|unsigned
name|long
name|rx_csum_offloaded
decl_stmt|;
name|unsigned
name|long
name|rx_task_rescheduled
decl_stmt|;
name|unsigned
name|long
name|tx_csum_offloaded
decl_stmt|;
name|unsigned
name|long
name|tx_tso_offloaded
decl_stmt|;
name|unsigned
name|long
name|tx_csum_bad_ethtype
decl_stmt|;
name|unsigned
name|long
name|tx_tso_bad_ethtype
decl_stmt|;
name|unsigned
name|long
name|tx_task_rescheduled
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vtnet_softc
block|{
name|device_t
name|vtnet_dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|vtnet_ifp
decl_stmt|;
name|struct
name|mtx
name|vtnet_mtx
decl_stmt|;
name|uint32_t
name|vtnet_flags
decl_stmt|;
define|#
directive|define
name|VTNET_FLAG_LINK
value|0x0001
define|#
directive|define
name|VTNET_FLAG_SUSPENDED
value|0x0002
define|#
directive|define
name|VTNET_FLAG_CTRL_VQ
value|0x0004
define|#
directive|define
name|VTNET_FLAG_CTRL_RX
value|0x0008
define|#
directive|define
name|VTNET_FLAG_VLAN_FILTER
value|0x0010
define|#
directive|define
name|VTNET_FLAG_TSO_ECN
value|0x0020
define|#
directive|define
name|VTNET_FLAG_MRG_RXBUFS
value|0x0040
define|#
directive|define
name|VTNET_FLAG_LRO_NOMRG
value|0x0080
name|struct
name|virtqueue
modifier|*
name|vtnet_rx_vq
decl_stmt|;
name|struct
name|virtqueue
modifier|*
name|vtnet_tx_vq
decl_stmt|;
name|struct
name|virtqueue
modifier|*
name|vtnet_ctrl_vq
decl_stmt|;
name|int
name|vtnet_hdr_size
decl_stmt|;
name|int
name|vtnet_tx_size
decl_stmt|;
name|int
name|vtnet_rx_size
decl_stmt|;
name|int
name|vtnet_rx_process_limit
decl_stmt|;
name|int
name|vtnet_rx_mbuf_size
decl_stmt|;
name|int
name|vtnet_rx_mbuf_count
decl_stmt|;
name|int
name|vtnet_if_flags
decl_stmt|;
name|int
name|vtnet_watchdog_timer
decl_stmt|;
name|uint64_t
name|vtnet_features
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|vtnet_tq
decl_stmt|;
name|struct
name|task
name|vtnet_rx_intr_task
decl_stmt|;
name|struct
name|task
name|vtnet_tx_intr_task
decl_stmt|;
name|struct
name|task
name|vtnet_cfgchg_task
decl_stmt|;
name|struct
name|vtnet_statistics
name|vtnet_stats
decl_stmt|;
name|struct
name|callout
name|vtnet_tick_ch
decl_stmt|;
name|eventhandler_tag
name|vtnet_vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vtnet_vlan_detach
decl_stmt|;
name|struct
name|ifmedia
name|vtnet_media
decl_stmt|;
comment|/* 	 * Fake media type; the host does not provide us with 	 * any real media information. 	 */
define|#
directive|define
name|VTNET_MEDIATYPE
value|(IFM_ETHER | IFM_1000_T | IFM_FDX)
name|char
name|vtnet_hwaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* 	 * During reset, the host's VLAN filtering table is lost. The 	 * array below is used to restore all the VLANs configured on 	 * this interface after a reset. 	 */
define|#
directive|define
name|VTNET_VLAN_SHADOW_SIZE
value|(4096 / 32)
name|int
name|vtnet_nvlans
decl_stmt|;
name|uint32_t
name|vtnet_vlan_shadow
index|[
name|VTNET_VLAN_SHADOW_SIZE
index|]
decl_stmt|;
name|char
name|vtnet_mtx_name
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * When mergeable buffers are not negotiated, the vtnet_rx_header structure  * below is placed at the beginning of the mbuf data. Use 4 bytes of pad to  * both keep the VirtIO header and the data non-contiguous and to keep the  * frame's payload 4 byte aligned.  *  * When mergeable buffers are negotiated, the host puts the VirtIO header in  * the beginning of the first mbuf's data.  */
end_comment

begin_define
define|#
directive|define
name|VTNET_RX_HEADER_PAD
value|4
end_define

begin_struct
struct|struct
name|vtnet_rx_header
block|{
name|struct
name|virtio_net_hdr
name|vrh_hdr
decl_stmt|;
name|char
name|vrh_pad
index|[
name|VTNET_RX_HEADER_PAD
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * For each outgoing frame, the vtnet_tx_header below is allocated from  * the vtnet_tx_header_zone.  */
end_comment

begin_struct
struct|struct
name|vtnet_tx_header
block|{
union|union
block|{
name|struct
name|virtio_net_hdr
name|hdr
decl_stmt|;
name|struct
name|virtio_net_hdr_mrg_rxbuf
name|mhdr
decl_stmt|;
block|}
name|vth_uhdr
union|;
name|struct
name|mbuf
modifier|*
name|vth_mbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The VirtIO specification does not place a limit on the number of MAC  * addresses the guest driver may request to be filtered. In practice,  * the host is constrained by available resources. To simplify this driver,  * impose a reasonably high limit of MAC addresses we will filter before  * falling back to promiscuous or all-multicast modes.  */
end_comment

begin_define
define|#
directive|define
name|VTNET_MAX_MAC_ENTRIES
value|128
end_define

begin_struct
struct|struct
name|vtnet_mac_table
block|{
name|uint32_t
name|nentries
decl_stmt|;
name|uint8_t
name|macs
index|[
name|VTNET_MAX_MAC_ENTRIES
index|]
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vtnet_mac_filter
block|{
name|struct
name|vtnet_mac_table
name|vmf_unicast
decl_stmt|;
name|uint32_t
name|vmf_pad
decl_stmt|;
comment|/* Make tables non-contiguous. */
name|struct
name|vtnet_mac_table
name|vmf_multicast
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The MAC filter table is malloc(9)'d when needed. Ensure it will  * always fit in one segment.  */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vtnet_mac_filter
argument_list|)
operator|<=
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VTNET_WATCHDOG_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|VTNET_CSUM_OFFLOAD
value|(CSUM_TCP | CSUM_UDP | CSUM_SCTP)
end_define

begin_comment
comment|/* Features desired/implemented by this driver. */
end_comment

begin_define
define|#
directive|define
name|VTNET_FEATURES
define|\
value|(VIRTIO_NET_F_MAC			| \      VIRTIO_NET_F_STATUS		| \      VIRTIO_NET_F_CTRL_VQ		| \      VIRTIO_NET_F_CTRL_RX		| \      VIRTIO_NET_F_CTRL_VLAN		| \      VIRTIO_NET_F_CSUM			| \      VIRTIO_NET_F_HOST_TSO4		| \      VIRTIO_NET_F_HOST_TSO6		| \      VIRTIO_NET_F_HOST_ECN		| \      VIRTIO_NET_F_GUEST_CSUM		| \      VIRTIO_NET_F_GUEST_TSO4		| \      VIRTIO_NET_F_GUEST_TSO6		| \      VIRTIO_NET_F_GUEST_ECN		| \      VIRTIO_NET_F_MRG_RXBUF		| \      VIRTIO_RING_F_INDIRECT_DESC)
end_define

begin_comment
comment|/*  * The VIRTIO_NET_F_GUEST_TSO[46] features permit the host to send us  * frames larger than 1514 bytes. We do not yet support software LRO  * via tcp_lro_rx().  */
end_comment

begin_define
define|#
directive|define
name|VTNET_LRO_FEATURES
value|(VIRTIO_NET_F_GUEST_TSO4 | \     VIRTIO_NET_F_GUEST_TSO6 | VIRTIO_NET_F_GUEST_ECN)
end_define

begin_define
define|#
directive|define
name|VTNET_MAX_MTU
value|65536
end_define

begin_define
define|#
directive|define
name|VTNET_MAX_RX_SIZE
value|65550
end_define

begin_comment
comment|/*  * Used to preallocate the Vq indirect descriptors. The first segment  * is reserved for the header.  */
end_comment

begin_define
define|#
directive|define
name|VTNET_MIN_RX_SEGS
value|2
end_define

begin_define
define|#
directive|define
name|VTNET_MAX_RX_SEGS
value|34
end_define

begin_define
define|#
directive|define
name|VTNET_MAX_TX_SEGS
value|34
end_define

begin_comment
comment|/*  * Assert we can receive and transmit the maximum with regular  * size clusters.  */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
operator|(
name|VTNET_MAX_RX_SEGS
operator|-
literal|1
operator|)
operator|*
name|MCLBYTES
operator|)
operator|>=
name|VTNET_MAX_RX_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
operator|(
name|VTNET_MAX_TX_SEGS
operator|-
literal|1
operator|)
operator|*
name|MCLBYTES
operator|)
operator|>=
name|VTNET_MAX_MTU
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Determine how many mbufs are in each receive buffer. For LRO without  * mergeable descriptors, we must allocate an mbuf chain large enough to  * hold both the vtnet_rx_header and the maximum receivable data.  */
end_comment

begin_define
define|#
directive|define
name|VTNET_NEEDED_RX_MBUFS
parameter_list|(
name|_sc
parameter_list|)
define|\
value|((_sc)->vtnet_flags& VTNET_FLAG_LRO_NOMRG) == 0 ? 1 :		\ 	    howmany(sizeof(struct vtnet_rx_header) + VTNET_MAX_RX_SIZE,	\ 	        (_sc)->vtnet_rx_mbuf_size)
end_define

begin_define
define|#
directive|define
name|VTNET_MTX
parameter_list|(
name|_sc
parameter_list|)
value|&(_sc)->vtnet_mtx
end_define

begin_define
define|#
directive|define
name|VTNET_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(VTNET_MTX((_sc)))
end_define

begin_define
define|#
directive|define
name|VTNET_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(VTNET_MTX((_sc)))
end_define

begin_define
define|#
directive|define
name|VTNET_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(VTNET_MTX((_sc)))
end_define

begin_define
define|#
directive|define
name|VTNET_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(VTNET_MTX((_sc)), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VTNET_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(VTNET_MTX((_sc)), MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|VTNET_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {					\     snprintf((_sc)->vtnet_mtx_name, sizeof((_sc)->vtnet_mtx_name),	\         "%s", device_get_nameunit((_sc)->vtnet_dev));			\     mtx_init(VTNET_MTX((_sc)), (_sc)->vtnet_mtx_name,			\         "VTNET Core Lock", MTX_DEF);					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VTNETVAR_H */
end_comment

end_unit

