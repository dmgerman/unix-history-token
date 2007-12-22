begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2001-2007, Intel Corporation All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_H_
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
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
file|"ixgbe_api.h"
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
value|256
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
value|256
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
name|MAX_INTR
value|10
end_define

begin_comment
comment|/*  * This parameter controls the duration of transmit watchdog timer.  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* set to 5 seconds */
end_comment

begin_comment
comment|/*  * This parameters control when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TX_CLEANUP_THRESHOLD
value|(adapter->num_tx_desc / 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_OP_THRESHOLD
value|(adapter->num_tx_desc / 32)
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_FRAME_SIZE
value|0x3F00
end_define

begin_comment
comment|/* Flow control constants */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FC_PAUSE
value|0x680
end_define

begin_define
define|#
directive|define
name|IXGBE_FC_HI
value|0x20000
end_define

begin_define
define|#
directive|define
name|IXGBE_FC_LO
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
name|IXGBE_MAX_SCATTER
value|100
end_define

begin_define
define|#
directive|define
name|IXGBE_MMBA
value|0x0010
end_define

begin_define
define|#
directive|define
name|IXGBE_TSO_SIZE
value|65535
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_BUFFER_SIZE
value|((u32) 1514)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_HDR_SIZE
value|((u32) 256)
end_define

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|7
end_define

begin_comment
comment|/* Bits in csum flags */
end_comment

begin_comment
comment|/* The number of MSIX messages the 82598 supports */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSGS
value|18
end_define

begin_comment
comment|/* For 6.X code compatibility */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
end_if

begin_define
define|#
directive|define
name|ETHER_BPF_MTAP
value|BPF_MTAP
end_define

begin_define
define|#
directive|define
name|CSUM_TSO
value|0
end_define

begin_define
define|#
directive|define
name|IFCAP_TSO4
value|0
end_define

begin_define
define|#
directive|define
name|FILTER_STRAY
end_define

begin_define
define|#
directive|define
name|FILTER_HANDLED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interrupt Moderation parameters   * 	for now we hardcode, later  *	it would be nice to do dynamic  */
end_comment

begin_define
define|#
directive|define
name|MAX_IRQ_SEC
value|8000
end_define

begin_define
define|#
directive|define
name|DEFAULT_ITR
value|1000000000/(MAX_IRQ_SEC * 256)
end_define

begin_define
define|#
directive|define
name|LINK_ITR
value|1000000000/(1950 * 256)
end_define

begin_comment
comment|/* Used for auto RX queue configuration */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ******************************************************************************  * vendor_info_array  *   * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *  *****************************************************************************  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ixgbe_vendor_info_t
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
name|ixgbe_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ixgbe_tx_buf
block|{
name|int
name|next_eop
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
name|ixgbe_rx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|boolean_t
name|bigbuf
decl_stmt|;
comment|/* one small and one large map */
name|bus_dmamap_t
name|map
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bus dma allocation structure used by ixgbe_dma_malloc and ixgbe_dma_free.  */
end_comment

begin_struct
struct|struct
name|ixgbe_dma_alloc
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
comment|/*  * The transmit ring, one per tx queue  */
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
name|u32
name|me
decl_stmt|;
name|u32
name|msix
decl_stmt|;
name|union
name|ixgbe_adv_tx_desc
modifier|*
name|tx_base
decl_stmt|;
name|struct
name|ixgbe_dma_alloc
name|txdma
decl_stmt|;
name|u32
name|next_avail_tx_desc
decl_stmt|;
name|u32
name|next_tx_to_clean
decl_stmt|;
name|struct
name|ixgbe_tx_buf
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
comment|/* Interrupt soft stat */
name|u64
name|tx_irq
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
name|u32
name|me
decl_stmt|;
name|u32
name|msix
decl_stmt|;
name|u32
name|payload
decl_stmt|;
name|union
name|ixgbe_adv_rx_desc
modifier|*
name|rx_base
decl_stmt|;
name|struct
name|ixgbe_dma_alloc
name|rxdma
decl_stmt|;
name|unsigned
name|int
name|last_cleaned
decl_stmt|;
name|unsigned
name|int
name|next_to_check
decl_stmt|;
name|struct
name|ixgbe_rx_buf
modifier|*
name|rx_buffers
decl_stmt|;
name|bus_dma_tag_t
name|rxtag
index|[
literal|2
index|]
decl_stmt|;
name|bus_dmamap_t
name|spare_map
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|fmp
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|lmp
decl_stmt|;
comment|/* Soft stats */
name|u64
name|rx_irq
decl_stmt|;
name|u64
name|packet_count
decl_stmt|;
name|u64
name|byte_count
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
comment|/* FreeBSD operating-system-specific structures */
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
name|res_memory
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_msix
decl_stmt|;
comment|/* 	 * Interrupt resources: 	 *  Oplin has 20 MSIX messages 	 *  so allocate that for now. 	 */
name|void
modifier|*
name|tag
index|[
name|IXGBE_MSGS
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
name|IXGBE_MSGS
index|]
decl_stmt|;
name|int
name|rid
index|[
name|IXGBE_MSGS
index|]
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
name|watchdog_timer
decl_stmt|;
name|int
name|msix
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
comment|/* Dual locks for the driver */
name|struct
name|mtx
name|core_mtx
decl_stmt|;
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
comment|/* Legacy Fast Intr handling */
name|struct
name|task
name|link_task
decl_stmt|;
name|struct
name|task
name|rxtx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* Info about the board itself */
name|u32
name|part_num
decl_stmt|;
name|bool
name|link_active
decl_stmt|;
name|u16
name|max_frame_size
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|u32
name|tx_int_delay
decl_stmt|;
name|u32
name|tx_abs_int_delay
decl_stmt|;
name|u32
name|rx_int_delay
decl_stmt|;
name|u32
name|rx_abs_int_delay
decl_stmt|;
comment|/* Indicates the cluster size to use */
name|bool
name|bigbufs
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
name|int
name|num_tx_queues
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
name|int
name|num_rx_queues
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
name|mbuf_alloc_failed
decl_stmt|;
name|unsigned
name|long
name|mbuf_cluster_failed
decl_stmt|;
name|unsigned
name|long
name|no_tx_desc_avail1
decl_stmt|;
name|unsigned
name|long
name|no_tx_desc_avail2
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
name|linkvec
decl_stmt|;
name|unsigned
name|long
name|link_irq
decl_stmt|;
name|struct
name|ixgbe_hw_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_H_ */
end_comment

end_unit

