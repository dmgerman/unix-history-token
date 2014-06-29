begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Tsubai Masanari  * Copyright (c) 2013 Bryan Venteicher<bryanv@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VMXVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_VMXVAR_H
end_define

begin_struct_decl
struct_decl|struct
name|vmxnet3_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|vmxnet3_dma_alloc
block|{
name|bus_addr_t
name|dma_paddr
decl_stmt|;
name|caddr_t
name|dma_vaddr
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|bus_size_t
name|dma_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The number of Rx/Tx queues this driver prefers.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_DEF_RX_QUEUES
value|8
end_define

begin_define
define|#
directive|define
name|VMXNET3_DEF_TX_QUEUES
value|8
end_define

begin_comment
comment|/*  * The number of Rx rings in each Rx queue.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_RXRINGS_PERQ
value|2
end_define

begin_comment
comment|/*  * The number of descriptors in each Rx/Tx ring.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_DEF_TX_NDESC
value|512
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_TX_NDESC
value|4096
end_define

begin_define
define|#
directive|define
name|VMXNET3_MIN_TX_NDESC
value|32
end_define

begin_define
define|#
directive|define
name|VMXNET3_MASK_TX_NDESC
value|0x1F
end_define

begin_define
define|#
directive|define
name|VMXNET3_DEF_RX_NDESC
value|256
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_RX_NDESC
value|2048
end_define

begin_define
define|#
directive|define
name|VMXNET3_MIN_RX_NDESC
value|32
end_define

begin_define
define|#
directive|define
name|VMXNET3_MASK_RX_NDESC
value|0x1F
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_TX_NCOMPDESC
value|VMXNET3_MAX_TX_NDESC
end_define

begin_define
define|#
directive|define
name|VMXNET3_MAX_RX_NCOMPDESC
define|\
value|(VMXNET3_MAX_RX_NDESC * VMXNET3_RXRINGS_PERQ)
end_define

begin_struct
struct|struct
name|vmxnet3_txbuf
block|{
name|bus_dmamap_t
name|vtxb_dmamap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vtxb_m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_txring
block|{
name|struct
name|vmxnet3_txbuf
modifier|*
name|vxtxr_txbuf
decl_stmt|;
name|u_int
name|vxtxr_head
decl_stmt|;
name|u_int
name|vxtxr_next
decl_stmt|;
name|u_int
name|vxtxr_ndesc
decl_stmt|;
name|int
name|vxtxr_gen
decl_stmt|;
name|bus_dma_tag_t
name|vxtxr_txtag
decl_stmt|;
name|struct
name|vmxnet3_txdesc
modifier|*
name|vxtxr_txd
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vxtxr_dma
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|int
name|VMXNET3_TXRING_AVAIL
parameter_list|(
name|struct
name|vmxnet3_txring
modifier|*
name|txr
parameter_list|)
block|{
name|int
name|avail
init|=
name|txr
operator|->
name|vxtxr_next
operator|-
name|txr
operator|->
name|vxtxr_head
operator|-
literal|1
decl_stmt|;
return|return
operator|(
name|avail
operator|<
literal|0
condition|?
name|txr
operator|->
name|vxtxr_ndesc
operator|+
name|avail
else|:
name|avail
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|vmxnet3_rxbuf
block|{
name|bus_dmamap_t
name|vrxb_dmamap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vrxb_m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_rxring
block|{
name|struct
name|vmxnet3_rxbuf
modifier|*
name|vxrxr_rxbuf
decl_stmt|;
name|struct
name|vmxnet3_rxdesc
modifier|*
name|vxrxr_rxd
decl_stmt|;
name|u_int
name|vxrxr_fill
decl_stmt|;
name|u_int
name|vxrxr_ndesc
decl_stmt|;
name|int
name|vxrxr_gen
decl_stmt|;
name|int
name|vxrxr_rid
decl_stmt|;
name|bus_dma_tag_t
name|vxrxr_rxtag
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vxrxr_dma
decl_stmt|;
name|bus_dmamap_t
name|vxrxr_spare_dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|vmxnet3_rxr_increment_fill
parameter_list|(
name|struct
name|vmxnet3_rxring
modifier|*
name|rxr
parameter_list|)
block|{
if|if
condition|(
operator|++
name|rxr
operator|->
name|vxrxr_fill
operator|==
name|rxr
operator|->
name|vxrxr_ndesc
condition|)
block|{
name|rxr
operator|->
name|vxrxr_fill
operator|=
literal|0
expr_stmt|;
name|rxr
operator|->
name|vxrxr_gen
operator|^=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_struct
struct|struct
name|vmxnet3_comp_ring
block|{
union|union
block|{
name|struct
name|vmxnet3_txcompdesc
modifier|*
name|txcd
decl_stmt|;
name|struct
name|vmxnet3_rxcompdesc
modifier|*
name|rxcd
decl_stmt|;
block|}
name|vxcr_u
union|;
name|u_int
name|vxcr_next
decl_stmt|;
name|u_int
name|vxcr_ndesc
decl_stmt|;
name|int
name|vxcr_gen
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vxcr_dma
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_txq_stats
block|{
name|uint64_t
name|vmtxs_opackets
decl_stmt|;
comment|/* if_opackets */
name|uint64_t
name|vmtxs_obytes
decl_stmt|;
comment|/* if_obytes */
name|uint64_t
name|vmtxs_omcasts
decl_stmt|;
comment|/* if_omcasts */
name|uint64_t
name|vmtxs_csum
decl_stmt|;
name|uint64_t
name|vmtxs_tso
decl_stmt|;
name|uint64_t
name|vmtxs_full
decl_stmt|;
name|uint64_t
name|vmtxs_offload_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_txqueue
block|{
name|struct
name|mtx
name|vxtxq_mtx
decl_stmt|;
name|struct
name|vmxnet3_softc
modifier|*
name|vxtxq_sc
decl_stmt|;
ifndef|#
directive|ifndef
name|VMXNET3_TX_LEGACY
name|struct
name|buf_ring
modifier|*
name|vxtxq_br
decl_stmt|;
endif|#
directive|endif
name|int
name|vxtxq_id
decl_stmt|;
name|int
name|vxtxq_intr_idx
decl_stmt|;
name|int
name|vxtxq_watchdog
decl_stmt|;
name|struct
name|vmxnet3_txring
name|vxtxq_cmd_ring
decl_stmt|;
name|struct
name|vmxnet3_comp_ring
name|vxtxq_comp_ring
decl_stmt|;
name|struct
name|vmxnet3_txq_stats
name|vxtxq_stats
decl_stmt|;
name|struct
name|vmxnet3_txq_shared
modifier|*
name|vxtxq_ts
decl_stmt|;
name|struct
name|sysctl_oid_list
modifier|*
name|vxtxq_sysctl
decl_stmt|;
ifndef|#
directive|ifndef
name|VMXNET3_TX_LEGACY
name|struct
name|task
name|vxtxq_defrtask
decl_stmt|;
endif|#
directive|endif
name|char
name|vxtxq_name
index|[
literal|16
index|]
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
name|VMXNET3_TXQ_LOCK
parameter_list|(
name|_txq
parameter_list|)
value|mtx_lock(&(_txq)->vxtxq_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_TXQ_TRYLOCK
parameter_list|(
name|_txq
parameter_list|)
value|mtx_trylock(&(_txq)->vxtxq_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_TXQ_UNLOCK
parameter_list|(
name|_txq
parameter_list|)
value|mtx_unlock(&(_txq)->vxtxq_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_TXQ_LOCK_ASSERT
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_assert(&(_txq)->vxtxq_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VMXNET3_TXQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_assert(&(_txq)->vxtxq_mtx, MA_NOTOWNED)
end_define

begin_struct
struct|struct
name|vmxnet3_rxq_stats
block|{
name|uint64_t
name|vmrxs_ipackets
decl_stmt|;
comment|/* if_ipackets */
name|uint64_t
name|vmrxs_ibytes
decl_stmt|;
comment|/* if_ibytes */
name|uint64_t
name|vmrxs_iqdrops
decl_stmt|;
comment|/* if_iqdrops */
name|uint64_t
name|vmrxs_ierrors
decl_stmt|;
comment|/* if_ierrors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_rxqueue
block|{
name|struct
name|mtx
name|vxrxq_mtx
decl_stmt|;
name|struct
name|vmxnet3_softc
modifier|*
name|vxrxq_sc
decl_stmt|;
name|int
name|vxrxq_id
decl_stmt|;
name|int
name|vxrxq_intr_idx
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vxrxq_mhead
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vxrxq_mtail
decl_stmt|;
name|struct
name|vmxnet3_rxring
name|vxrxq_cmd_ring
index|[
name|VMXNET3_RXRINGS_PERQ
index|]
decl_stmt|;
name|struct
name|vmxnet3_comp_ring
name|vxrxq_comp_ring
decl_stmt|;
name|struct
name|vmxnet3_rxq_stats
name|vxrxq_stats
decl_stmt|;
name|struct
name|vmxnet3_rxq_shared
modifier|*
name|vxrxq_rs
decl_stmt|;
name|struct
name|sysctl_oid_list
modifier|*
name|vxrxq_sysctl
decl_stmt|;
name|char
name|vxrxq_name
index|[
literal|16
index|]
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
name|VMXNET3_RXQ_LOCK
parameter_list|(
name|_rxq
parameter_list|)
value|mtx_lock(&(_rxq)->vxrxq_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXQ_UNLOCK
parameter_list|(
name|_rxq
parameter_list|)
value|mtx_unlock(&(_rxq)->vxrxq_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXQ_LOCK_ASSERT
parameter_list|(
name|_rxq
parameter_list|)
define|\
value|mtx_assert(&(_rxq)->vxrxq_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VMXNET3_RXQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|_rxq
parameter_list|)
define|\
value|mtx_assert(&(_rxq)->vxrxq_mtx, MA_NOTOWNED)
end_define

begin_struct
struct|struct
name|vmxnet3_statistics
block|{
name|uint32_t
name|vmst_defragged
decl_stmt|;
name|uint32_t
name|vmst_defrag_failed
decl_stmt|;
name|uint32_t
name|vmst_mgetcl_failed
decl_stmt|;
name|uint32_t
name|vmst_mbuf_load_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_interrupt
block|{
name|struct
name|resource
modifier|*
name|vmxi_irq
decl_stmt|;
name|int
name|vmxi_rid
decl_stmt|;
name|void
modifier|*
name|vmxi_handler
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxnet3_softc
block|{
name|device_t
name|vmx_dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|vmx_ifp
decl_stmt|;
name|struct
name|vmxnet3_driver_shared
modifier|*
name|vmx_ds
decl_stmt|;
name|uint32_t
name|vmx_flags
decl_stmt|;
define|#
directive|define
name|VMXNET3_FLAG_NO_MSIX
value|0x0001
define|#
directive|define
name|VMXNET3_FLAG_RSS
value|0x0002
name|struct
name|vmxnet3_rxqueue
modifier|*
name|vmx_rxq
decl_stmt|;
name|struct
name|vmxnet3_txqueue
modifier|*
name|vmx_txq
decl_stmt|;
name|struct
name|resource
modifier|*
name|vmx_res0
decl_stmt|;
name|bus_space_tag_t
name|vmx_iot0
decl_stmt|;
name|bus_space_handle_t
name|vmx_ioh0
decl_stmt|;
name|struct
name|resource
modifier|*
name|vmx_res1
decl_stmt|;
name|bus_space_tag_t
name|vmx_iot1
decl_stmt|;
name|bus_space_handle_t
name|vmx_ioh1
decl_stmt|;
name|struct
name|resource
modifier|*
name|vmx_msix_res
decl_stmt|;
name|int
name|vmx_link_active
decl_stmt|;
name|int
name|vmx_link_speed
decl_stmt|;
name|int
name|vmx_if_flags
decl_stmt|;
name|int
name|vmx_ntxqueues
decl_stmt|;
name|int
name|vmx_nrxqueues
decl_stmt|;
name|int
name|vmx_ntxdescs
decl_stmt|;
name|int
name|vmx_nrxdescs
decl_stmt|;
name|int
name|vmx_max_rxsegs
decl_stmt|;
name|int
name|vmx_rx_max_chain
decl_stmt|;
name|struct
name|vmxnet3_statistics
name|vmx_stats
decl_stmt|;
name|int
name|vmx_intr_type
decl_stmt|;
name|int
name|vmx_intr_mask_mode
decl_stmt|;
name|int
name|vmx_event_intr_idx
decl_stmt|;
name|int
name|vmx_nintrs
decl_stmt|;
name|struct
name|vmxnet3_interrupt
name|vmx_intrs
index|[
name|VMXNET3_MAX_INTRS
index|]
decl_stmt|;
name|struct
name|mtx
name|vmx_mtx
decl_stmt|;
ifndef|#
directive|ifndef
name|VMXNET3_LEGACY_TX
name|struct
name|taskqueue
modifier|*
name|vmx_tq
decl_stmt|;
endif|#
directive|endif
name|uint8_t
modifier|*
name|vmx_mcast
decl_stmt|;
name|void
modifier|*
name|vmx_qs
decl_stmt|;
name|struct
name|vmxnet3_rss_shared
modifier|*
name|vmx_rss
decl_stmt|;
name|struct
name|callout
name|vmx_tick
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vmx_ds_dma
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vmx_qs_dma
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vmx_mcast_dma
decl_stmt|;
name|struct
name|vmxnet3_dma_alloc
name|vmx_rss_dma
decl_stmt|;
name|struct
name|ifmedia
name|vmx_media
decl_stmt|;
name|int
name|vmx_max_ntxqueues
decl_stmt|;
name|int
name|vmx_max_nrxqueues
decl_stmt|;
name|eventhandler_tag
name|vmx_vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vmx_vlan_detach
decl_stmt|;
name|uint32_t
name|vmx_vlan_filter
index|[
literal|4096
operator|/
literal|32
index|]
decl_stmt|;
name|uint8_t
name|vmx_lladdr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VMXNET3_CORE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->vmx_mtx, _name, "VMXNET3 Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CORE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->vmx_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CORE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->vmx_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CORE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->vmx_mtx)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CORE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->vmx_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CORE_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(&(_sc)->vmx_mtx, MA_NOTOWNED)
end_define

begin_comment
comment|/*  * Our driver version we report to the hypervisor; we just keep  * this value constant.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_DRIVER_VERSION
value|0x00010000
end_define

begin_comment
comment|/*  * Max descriptors per Tx packet. We must limit the size of the  * any TSO packets based on the number of segments.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_TX_MAXSEGS
value|32
end_define

begin_define
define|#
directive|define
name|VMXNET3_TX_MAXSIZE
value|(VMXNET3_TX_MAXSEGS * MCLBYTES)
end_define

begin_define
define|#
directive|define
name|VMXNET3_TSO_MAXSIZE
define|\
value|(VMXNET3_TX_MAXSIZE - sizeof(struct ether_vlan_header))
end_define

begin_comment
comment|/*  * Maximum support Tx segments size. The length field in the  * Tx descriptor is 14 bits.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_TX_MAXSEGSIZE
value|(1<< 14)
end_define

begin_comment
comment|/*  * The maximum number of Rx segments we accept. When LRO is enabled,  * this allows us to receive the maximum sized frame with one MCLBYTES  * cluster followed by 16 MJUMPAGESIZE clusters.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_MAX_RX_SEGS
value|17
end_define

begin_comment
comment|/*  * Predetermined size of the multicast MACs filter table. If the  * number of multicast addresses exceeds this size, then the  * ALL_MULTI mode is use instead.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_MULTICAST_MAX
value|32
end_define

begin_comment
comment|/*  * Our Tx watchdog timeout.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_WATCHDOG_TIMEOUT
value|5
end_define

begin_comment
comment|/*  * Number of slots in the Tx bufrings. This value matches most other  * multiqueue drivers.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_DEF_BUFRING_SIZE
value|4096
end_define

begin_comment
comment|/*  * IP protocols that we can perform Tx checksum offloading of.  */
end_comment

begin_define
define|#
directive|define
name|VMXNET3_CSUM_OFFLOAD
value|(CSUM_TCP | CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CSUM_OFFLOAD_IPV6
value|(CSUM_TCP_IPV6 | CSUM_UDP_IPV6)
end_define

begin_define
define|#
directive|define
name|VMXNET3_CSUM_ALL_OFFLOAD
define|\
value|(VMXNET3_CSUM_OFFLOAD | VMXNET3_CSUM_OFFLOAD_IPV6 | CSUM_TSO)
end_define

begin_comment
comment|/*  * Compat macros to keep this driver compiling on old releases.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYSCTL_ADD_UQUAD
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSCTL_ADD_UQUAD
value|SYSCTL_ADD_QUAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IFCAP_TXCSUM_IPV6
argument_list|)
end_if

begin_define
define|#
directive|define
name|IFCAP_TXCSUM_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IFCAP_RXCSUM_IPV6
argument_list|)
end_if

begin_define
define|#
directive|define
name|IFCAP_RXCSUM_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CSUM_TCP_IPV6
argument_list|)
end_if

begin_define
define|#
directive|define
name|CSUM_TCP_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CSUM_UDP_IPV6
argument_list|)
end_if

begin_define
define|#
directive|define
name|CSUM_UDP_IPV6
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VMXVAR_H */
end_comment

end_unit

