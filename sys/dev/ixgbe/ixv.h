begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2012, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXV_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXV_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
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
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|"ixgbe_api.h"
end_include

begin_include
include|#
directive|include
file|"ixgbe_vf.h"
end_include

begin_comment
comment|/* Tunables */
end_comment

begin_comment
comment|/*  * TxDescriptors Valid Range: 64-4096 Default Value: 256 This value is the  * number of transmit descriptors allocated by the driver. Increasing this  * value allows the driver to queue more transmits. Each descriptor is 16  * bytes. Performance tests have show the 2K value to be optimal for top  * performance.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TXD
value|1024
end_define

begin_define
define|#
directive|define
name|PERFORM_TXD
value|2048
end_define

begin_define
define|#
directive|define
name|MAX_TXD
value|4096
end_define

begin_define
define|#
directive|define
name|MIN_TXD
value|64
end_define

begin_comment
comment|/*  * RxDescriptors Valid Range: 64-4096 Default Value: 256 This value is the  * number of receive descriptors allocated for each RX queue. Increasing this  * value allows the driver to buffer more incoming packets. Each descriptor  * is 16 bytes.  A receive buffer is also allocated for each descriptor.   *   * Note: with 8 rings and a dual port card, it is possible to bump up   *	against the system mbuf pool limit, you can tune nmbclusters  *	to adjust for this.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RXD
value|1024
end_define

begin_define
define|#
directive|define
name|PERFORM_RXD
value|2048
end_define

begin_define
define|#
directive|define
name|MAX_RXD
value|4096
end_define

begin_define
define|#
directive|define
name|MIN_RXD
value|64
end_define

begin_comment
comment|/* Alignment for rings */
end_comment

begin_define
define|#
directive|define
name|DBA_ALIGN
value|128
end_define

begin_comment
comment|/*  * This parameter controls the maximum no of times the driver will loop in  * the isr. Minimum Value = 1  */
end_comment

begin_define
define|#
directive|define
name|MAX_LOOP
value|10
end_define

begin_comment
comment|/*  * This is the max watchdog interval, ie. the time that can  * pass between any two TX clean operations, such only happening  * when the TX hardware is functioning.  */
end_comment

begin_define
define|#
directive|define
name|IXV_WATCHDOG
value|(10 * hz)
end_define

begin_comment
comment|/*  * This parameters control when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IXV_TX_CLEANUP_THRESHOLD
value|(adapter->num_tx_desc / 8)
end_define

begin_define
define|#
directive|define
name|IXV_TX_OP_THRESHOLD
value|(adapter->num_tx_desc / 32)
end_define

begin_define
define|#
directive|define
name|IXV_MAX_FRAME_SIZE
value|0x3F00
end_define

begin_comment
comment|/* Flow control constants */
end_comment

begin_define
define|#
directive|define
name|IXV_FC_PAUSE
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXV_FC_HI
value|0x20000
end_define

begin_define
define|#
directive|define
name|IXV_FC_LO
value|0x10000
end_define

begin_comment
comment|/* Defines for printing debug information */
end_comment

begin_define
define|#
directive|define
name|DEBUG_INIT
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_IOCTL
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_HW
value|0
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n")
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|INIT_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_INIT)  printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|IOCTL_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_IOCTL) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|if (DEBUG_HW) printf(S "\n")
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|if (DEBUG_HW) printf(S "\n", A)
end_define

begin_define
define|#
directive|define
name|HW_DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|if (DEBUG_HW) printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_MULTICAST_ADDRESSES
value|128
end_define

begin_define
define|#
directive|define
name|IXV_EITR_DEFAULT
value|128
end_define

begin_define
define|#
directive|define
name|IXV_SCATTER
value|32
end_define

begin_define
define|#
directive|define
name|IXV_RX_HDR
value|128
end_define

begin_define
define|#
directive|define
name|MSIX_BAR
value|3
end_define

begin_define
define|#
directive|define
name|IXV_TSO_SIZE
value|65535
end_define

begin_define
define|#
directive|define
name|IXV_BR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|IXV_LINK_ITR
value|2000
end_define

begin_define
define|#
directive|define
name|TX_BUFFER_SIZE
value|((u32) 1514)
end_define

begin_define
define|#
directive|define
name|VFTA_SIZE
value|128
end_define

begin_comment
comment|/* Offload bits in mbuf flag */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800000
end_if

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|(CSUM_IP|CSUM_TCP|CSUM_UDP|CSUM_SCTP)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|(CSUM_IP|CSUM_TCP|CSUM_UDP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *****************************************************************************  * vendor_info_array  *   * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *   *****************************************************************************  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ixv_vendor_info_t
block|{
name|unsigned
name|int
name|vendor_id
decl_stmt|;
name|unsigned
name|int
name|device_id
decl_stmt|;
name|unsigned
name|int
name|subvendor_id
decl_stmt|;
name|unsigned
name|int
name|subdevice_id
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|ixv_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ixv_tx_buf
block|{
name|u32
name|eop_index
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixv_rx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_pack
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|fmp
decl_stmt|;
name|bus_dmamap_t
name|hmap
decl_stmt|;
name|bus_dmamap_t
name|pmap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bus dma allocation structure used by ixv_dma_malloc and ixv_dma_free.  */
end_comment

begin_struct
struct|struct
name|ixv_dma_alloc
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
name|bus_dma_segment_t
name|dma_seg
decl_stmt|;
name|bus_size_t
name|dma_size
decl_stmt|;
name|int
name|dma_nseg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Driver queue struct: this is the interrupt container **  for the associated tx and rx ring. */
end_comment

begin_struct
struct|struct
name|ix_queue
block|{
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|u32
name|msix
decl_stmt|;
comment|/* This queue's MSIX vector */
name|u32
name|eims
decl_stmt|;
comment|/* This queue's EIMS bit */
name|u32
name|eitr_setting
decl_stmt|;
name|u32
name|eitr
decl_stmt|;
comment|/* cached reg */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
name|struct
name|tx_ring
modifier|*
name|txr
decl_stmt|;
name|struct
name|rx_ring
modifier|*
name|rxr
decl_stmt|;
name|struct
name|task
name|que_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|u64
name|irqs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The transmit ring, one per queue  */
end_comment

begin_struct
struct|struct
name|tx_ring
block|{
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
name|u32
name|me
decl_stmt|;
name|bool
name|watchdog_check
decl_stmt|;
name|int
name|watchdog_time
decl_stmt|;
name|union
name|ixgbe_adv_tx_desc
modifier|*
name|tx_base
decl_stmt|;
name|struct
name|ixv_dma_alloc
name|txdma
decl_stmt|;
name|u32
name|next_avail_desc
decl_stmt|;
name|u32
name|next_to_clean
decl_stmt|;
name|struct
name|ixv_tx_buf
modifier|*
name|tx_buffers
decl_stmt|;
specifier|volatile
name|u16
name|tx_avail
decl_stmt|;
name|u32
name|txd_cmd
decl_stmt|;
name|bus_dma_tag_t
name|txtag
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* Soft Stats */
name|u32
name|bytes
decl_stmt|;
name|u32
name|packets
decl_stmt|;
name|u64
name|no_desc_avail
decl_stmt|;
name|u64
name|total_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The Receive ring, one per rx queue  */
end_comment

begin_struct
struct|struct
name|rx_ring
block|{
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|mtx
name|rx_mtx
decl_stmt|;
name|u32
name|me
decl_stmt|;
name|union
name|ixgbe_adv_rx_desc
modifier|*
name|rx_base
decl_stmt|;
name|struct
name|ixv_dma_alloc
name|rxdma
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|bool
name|lro_enabled
decl_stmt|;
name|bool
name|hdr_split
decl_stmt|;
name|bool
name|discard
decl_stmt|;
name|u32
name|next_to_refresh
decl_stmt|;
name|u32
name|next_to_check
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|ixv_rx_buf
modifier|*
name|rx_buffers
decl_stmt|;
name|bus_dma_tag_t
name|htag
decl_stmt|;
name|bus_dma_tag_t
name|ptag
decl_stmt|;
name|u32
name|bytes
decl_stmt|;
comment|/* Used for AIM calc */
name|u32
name|packets
decl_stmt|;
comment|/* Soft stats */
name|u64
name|rx_irq
decl_stmt|;
name|u64
name|rx_split_packets
decl_stmt|;
name|u64
name|rx_packets
decl_stmt|;
name|u64
name|rx_bytes
decl_stmt|;
name|u64
name|rx_discarded
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Our adapter structure */
end_comment

begin_struct
struct|struct
name|adapter
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ixgbe_hw
name|hw
decl_stmt|;
name|struct
name|ixgbe_osdep
name|osdep
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_mem
decl_stmt|;
comment|/* 	 * Interrupt resources: this set is 	 * either used for legacy, or for Link 	 * when doing MSIX 	 */
name|void
modifier|*
name|tag
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|int
name|msix
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|mtx
name|core_mtx
decl_stmt|;
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|u16
name|num_vlans
decl_stmt|;
name|u16
name|num_queues
decl_stmt|;
comment|/* Info about the board itself */
name|bool
name|link_active
decl_stmt|;
name|u16
name|max_frame_size
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|bool
name|link_up
decl_stmt|;
name|u32
name|mbxvec
decl_stmt|;
comment|/* Mbuf cluster size */
name|u32
name|rx_mbuf_sz
decl_stmt|;
comment|/* Support for pluggable optics */
name|struct
name|task
name|mbx_task
decl_stmt|;
comment|/* Mailbox tasklet */
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* 	** Queues:  	**   This is the irq holder, it has 	**   and RX/TX pair or rings associated 	**   with it. 	*/
name|struct
name|ix_queue
modifier|*
name|queues
decl_stmt|;
comment|/* 	 * Transmit rings: 	 *	Allocated at run time, an array of rings. 	 */
name|struct
name|tx_ring
modifier|*
name|tx_rings
decl_stmt|;
name|int
name|num_tx_desc
decl_stmt|;
comment|/* 	 * Receive rings: 	 *	Allocated at run time, an array of rings. 	 */
name|struct
name|rx_ring
modifier|*
name|rx_rings
decl_stmt|;
name|int
name|num_rx_desc
decl_stmt|;
name|u64
name|que_mask
decl_stmt|;
name|u32
name|rx_process_limit
decl_stmt|;
comment|/* Misc stats maintained by the driver */
name|unsigned
name|long
name|dropped_pkts
decl_stmt|;
name|unsigned
name|long
name|mbuf_defrag_failed
decl_stmt|;
name|unsigned
name|long
name|mbuf_header_failed
decl_stmt|;
name|unsigned
name|long
name|mbuf_packet_failed
decl_stmt|;
name|unsigned
name|long
name|no_tx_map_avail
decl_stmt|;
name|unsigned
name|long
name|no_tx_dma_setup
decl_stmt|;
name|unsigned
name|long
name|watchdog_events
decl_stmt|;
name|unsigned
name|long
name|tso_tx
decl_stmt|;
name|unsigned
name|long
name|mbx_irq
decl_stmt|;
name|struct
name|ixgbevf_hw_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXV_CORE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->core_mtx, _name, "IXV Core Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IXV_CORE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_CORE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_trylock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_CORE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXV_CORE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->core_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IXV_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->tx_mtx, MA_OWNED)
end_define

begin_comment
comment|/* Workaround to make 8.0 buildable */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800000
operator|&&
name|__FreeBSD_version
operator|<
literal|800504
end_if

begin_function
specifier|static
name|__inline
name|int
name|drbr_needs_enqueue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|buf_ring
modifier|*
name|br
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ALTQ
if|if
condition|(
name|ALTQ_IS_ENABLED
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
operator|!
name|buf_ring_empty
argument_list|(
name|br
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** Find the number of unrefreshed RX descriptors */
end_comment

begin_function
specifier|static
specifier|inline
name|u16
name|ixv_rx_unrefreshed
parameter_list|(
name|struct
name|rx_ring
modifier|*
name|rxr
parameter_list|)
block|{
name|struct
name|adapter
modifier|*
name|adapter
init|=
name|rxr
operator|->
name|adapter
decl_stmt|;
if|if
condition|(
name|rxr
operator|->
name|next_to_check
operator|>
name|rxr
operator|->
name|next_to_refresh
condition|)
return|return
operator|(
name|rxr
operator|->
name|next_to_check
operator|-
name|rxr
operator|->
name|next_to_refresh
operator|-
literal|1
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|adapter
operator|->
name|num_rx_desc
operator|+
name|rxr
operator|->
name|next_to_check
operator|)
operator|-
name|rxr
operator|->
name|next_to_refresh
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXV_H_ */
end_comment

end_unit

