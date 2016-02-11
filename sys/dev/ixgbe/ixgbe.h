begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
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

begin_ifndef
ifndef|#
directive|ifndef
name|IXGBE_LEGACY_TX
end_ifndef

begin_include
include|#
directive|include
file|<sys/buf_ring.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/sbuf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<sys/iov_schema.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pci_iov.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ixgbe_api.h"
end_include

begin_include
include|#
directive|include
file|"ixgbe_common.h"
end_include

begin_include
include|#
directive|include
file|"ixgbe_phy.h"
end_include

begin_include
include|#
directive|include
file|"ixgbe_vf.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_include
include|#
directive|include
file|"ixgbe_common.h"
end_include

begin_include
include|#
directive|include
file|"ixgbe_mbx.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * This is the max watchdog interval, ie. the time that can  * pass between any two TX clean operations, such only happening  * when the TX hardware is functioning.  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WATCHDOG
value|(10 * hz)
end_define

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

begin_comment
comment|/* These defines are used in MTU calculations */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_FRAME_SIZE
value|9728
end_define

begin_define
define|#
directive|define
name|IXGBE_MTU_HDR
value|(ETHER_HDR_LEN + ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|IXGBE_MTU_HDR_VLAN
value|(ETHER_HDR_LEN + ETHER_CRC_LEN + \ 				 ETHER_VLAN_ENCAP_LEN)
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_MTU
value|(IXGBE_MAX_FRAME_SIZE - IXGBE_MTU_HDR)
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_MTU_VLAN
value|(IXGBE_MAX_FRAME_SIZE - IXGBE_MTU_HDR_VLAN)
end_define

begin_comment
comment|/* Flow control constants */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FC_PAUSE
value|0xFFFF
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
comment|/*  * Used for optimizing small rx mbufs.  Effort is made to keep the copy  * small and aligned for the CPU L1 cache.  *   * MHLEN is typically 168 bytes, giving us 8-byte alignment.  Getting  * 32 byte alignment needed for the fast bcopy results in 8 bytes being  * wasted.  Getting 64 byte alignment, which _should_ be ideal for  * modern Intel CPUs, results in 40 bytes wasted and a significant drop  * in observed efficiency of the optimization, 97.9% -> 81.8%.  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|1002000
end_if

begin_define
define|#
directive|define
name|MPKTHSIZE
value|(sizeof(struct m_hdr) + sizeof(struct pkthdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IXGBE_RX_COPY_HDR_PADDED
value|((((MPKTHSIZE - 1) / 32) + 1) * 32)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_COPY_LEN
value|(MSIZE - IXGBE_RX_COPY_HDR_PADDED)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_COPY_ALIGN
value|(IXGBE_RX_COPY_HDR_PADDED - MPKTHSIZE)
end_define

begin_comment
comment|/* Keep older OS drivers building... */
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
name|IXGBE_82598_SCATTER
value|100
end_define

begin_define
define|#
directive|define
name|IXGBE_82599_SCATTER
value|32
end_define

begin_define
define|#
directive|define
name|MSIX_82598_BAR
value|3
end_define

begin_define
define|#
directive|define
name|MSIX_82599_BAR
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_TSO_SIZE
value|262140
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_HDR
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTA_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_BR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|IXGBE_QUEUE_MIN_FREE
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_TX_BUSY
value|10
end_define

begin_define
define|#
directive|define
name|IXGBE_QUEUE_HUNG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXV_EITR_DEFAULT
value|128
end_define

begin_comment
comment|/* Supported offload bits in mbuf flag */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1000000
end_if

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|(CSUM_IP_TSO|CSUM_IP6_TSO|CSUM_IP| \ 				 CSUM_IP_UDP|CSUM_IP_TCP|CSUM_IP_SCTP| \ 				 CSUM_IP6_UDP|CSUM_IP6_TCP|CSUM_IP6_SCTP)
end_define

begin_elif
elif|#
directive|elif
name|__FreeBSD_version
operator|>=
literal|800000
end_elif

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
comment|/* Backward compatibility items for very old versions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|pci_find_cap
end_ifndef

begin_define
define|#
directive|define
name|pci_find_cap
value|pci_find_extcap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEVMETHOD_END
end_ifndef

begin_define
define|#
directive|define
name|DEVMETHOD_END
value|{ NULL, NULL }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interrupt Moderation parameters   */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LOW_LATENCY
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_AVE_LATENCY
value|400
end_define

begin_define
define|#
directive|define
name|IXGBE_BULK_LATENCY
value|1200
end_define

begin_comment
comment|/* Using 1FF (the max value), the interval is ~1.05ms */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LINK_ITR_QUANTA
value|0x1FF
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_ITR
value|((IXGBE_LINK_ITR_QUANTA<< 3)& \ 				    IXGBE_EITR_ITR_INT_MASK)
end_define

begin_comment
comment|/* MAC type macros */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IS_X550VF
parameter_list|(
name|_adapter
parameter_list|)
define|\
value|((_adapter->hw.mac.type == ixgbe_mac_X550_vf) || \ 	 (_adapter->hw.mac.type == ixgbe_mac_X550EM_x_vf))
end_define

begin_define
define|#
directive|define
name|IXGBE_IS_VF
parameter_list|(
name|_adapter
parameter_list|)
define|\
value|(IXGBE_IS_X550VF(_adapter) || \ 	 (_adapter->hw.mac.type == ixgbe_mac_X540_vf) || \ 	 (_adapter->hw.mac.type == ixgbe_mac_82599_vf))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_define
define|#
directive|define
name|IXGBE_VF_INDEX
parameter_list|(
name|vmdq
parameter_list|)
value|((vmdq) / 32)
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_BIT
parameter_list|(
name|vmdq
parameter_list|)
value|(1<< ((vmdq) % 32))
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_MSG_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_MSGINFO
parameter_list|(
name|msg
parameter_list|)
define|\
value|(((msg)& IXGBE_VT_MSGINFO_MASK)>> IXGBE_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_GET_QUEUES_RESP_LEN
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_1_0
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_2_0
value|1
end_define

begin_comment
comment|/* Solaris API.  Not supported. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_API_VER_1_1
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_API_VER_UNKNOWN
value|UINT16_MAX
end_define

begin_enum
enum|enum
name|ixgbe_iov_mode
block|{
name|IXGBE_64_VM
block|,
name|IXGBE_32_VM
block|,
name|IXGBE_NO_VM
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_IOV */
end_comment

begin_comment
comment|/*  *****************************************************************************  * vendor_info_array  *   * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *   *****************************************************************************  */
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
name|union
name|ixgbe_adv_tx_desc
modifier|*
name|eop
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
name|buf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|fmp
decl_stmt|;
name|bus_dmamap_t
name|pmap
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|IXGBE_RX_COPY
value|0x01
name|uint64_t
name|addr
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

begin_struct
struct|struct
name|ixgbe_mc_addr
block|{
name|u8
name|addr
index|[
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u32
name|vmdq
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
name|me
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
name|int
name|busy
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
name|u32
name|tail
decl_stmt|;
name|int
name|busy
decl_stmt|;
name|union
name|ixgbe_adv_tx_desc
modifier|*
name|tx_base
decl_stmt|;
name|struct
name|ixgbe_tx_buf
modifier|*
name|tx_buffers
decl_stmt|;
name|struct
name|ixgbe_dma_alloc
name|txdma
decl_stmt|;
specifier|volatile
name|u16
name|tx_avail
decl_stmt|;
name|u16
name|next_avail_desc
decl_stmt|;
name|u16
name|next_to_clean
decl_stmt|;
name|u16
name|num_desc
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
ifndef|#
directive|ifndef
name|IXGBE_LEGACY_TX
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
name|struct
name|task
name|txq_task
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IXGBE_FDIR
name|u16
name|atr_sample
decl_stmt|;
name|u16
name|atr_count
decl_stmt|;
endif|#
directive|endif
name|u32
name|bytes
decl_stmt|;
comment|/* used for AIM */
name|u32
name|packets
decl_stmt|;
comment|/* Soft Stats */
name|unsigned
name|long
name|tso_tx
decl_stmt|;
name|unsigned
name|long
name|no_tx_map_avail
decl_stmt|;
name|unsigned
name|long
name|no_tx_dma_setup
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
name|u32
name|tail
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
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|bool
name|lro_enabled
decl_stmt|;
name|bool
name|hw_rsc
decl_stmt|;
name|bool
name|vtag_strip
decl_stmt|;
name|u16
name|next_to_refresh
decl_stmt|;
name|u16
name|next_to_check
decl_stmt|;
name|u16
name|num_desc
decl_stmt|;
name|u16
name|mbuf_sz
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|ixgbe_rx_buf
modifier|*
name|rx_buffers
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
name|rx_copies
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
name|u64
name|rsc_num
decl_stmt|;
ifdef|#
directive|ifdef
name|IXGBE_FDIR
name|u64
name|flm
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_define
define|#
directive|define
name|IXGBE_VF_CTS
value|(1<< 0)
end_define

begin_comment
comment|/* VF is clear to send. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_CAP_MAC
value|(1<< 1)
end_define

begin_comment
comment|/* VF is permitted to change MAC. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_CAP_VLAN
value|(1<< 2)
end_define

begin_comment
comment|/* VF is permitted to join vlans. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_ACTIVE
value|(1<< 3)
end_define

begin_comment
comment|/* VF is active. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_VF_MC
value|30
end_define

begin_comment
comment|/* Max number of multicast entries */
end_comment

begin_struct
struct|struct
name|ixgbe_vf
block|{
name|u_int
name|pool
decl_stmt|;
name|u_int
name|rar_index
decl_stmt|;
name|u_int
name|max_frame_size
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint8_t
name|ether_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|mc_hash
index|[
name|IXGBE_MAX_VF_MC
index|]
decl_stmt|;
name|uint16_t
name|num_mc_hashes
decl_stmt|;
name|uint16_t
name|default_vlan
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint16_t
name|api_ver
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_IOV */
end_comment

begin_comment
comment|/* Our adapter structure */
end_comment

begin_struct
struct|struct
name|adapter
block|{
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
name|ifnet
modifier|*
name|ifp
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
comment|/* 	** Shadow VFTA table, this is needed because 	** the real vlan filter table gets cleared during 	** a soft reset and the driver needs to be able 	** to repopulate it. 	*/
name|u32
name|shadow_vfta
index|[
name|IXGBE_VFTA_SIZE
index|]
decl_stmt|;
comment|/* Info about the interface */
name|u32
name|optics
decl_stmt|;
name|u32
name|fc
decl_stmt|;
comment|/* local flow ctrl setting */
name|int
name|advertise
decl_stmt|;
comment|/* link speeds */
name|bool
name|enable_aim
decl_stmt|;
comment|/* adaptive interrupt moderation */
name|bool
name|link_active
decl_stmt|;
name|u16
name|max_frame_size
decl_stmt|;
name|u16
name|num_segs
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|bool
name|link_up
decl_stmt|;
name|u32
name|vector
decl_stmt|;
name|u16
name|dmac
decl_stmt|;
name|bool
name|eee_enabled
decl_stmt|;
name|u32
name|phy_layer
decl_stmt|;
comment|/* Power management-related */
name|bool
name|wol_support
decl_stmt|;
name|u32
name|wufc
decl_stmt|;
comment|/* Mbuf cluster size */
name|u32
name|rx_mbuf_sz
decl_stmt|;
comment|/* Support for pluggable optics */
name|bool
name|sfp_probe
decl_stmt|;
name|struct
name|task
name|link_task
decl_stmt|;
comment|/* Link tasklet */
name|struct
name|task
name|mod_task
decl_stmt|;
comment|/* SFP tasklet */
name|struct
name|task
name|msf_task
decl_stmt|;
comment|/* Multispeed Fiber */
ifdef|#
directive|ifdef
name|PCI_IOV
name|struct
name|task
name|mbx_task
decl_stmt|;
comment|/* VF -> PF mailbox interrupt */
endif|#
directive|endif
comment|/* PCI_IOV */
ifdef|#
directive|ifdef
name|IXGBE_FDIR
name|int
name|fdir_reinit
decl_stmt|;
name|struct
name|task
name|fdir_task
decl_stmt|;
endif|#
directive|endif
name|struct
name|task
name|phy_task
decl_stmt|;
comment|/* PHY intr tasklet */
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
name|u32
name|num_tx_desc
decl_stmt|;
name|u32
name|tx_process_limit
decl_stmt|;
comment|/* 	 * Receive rings: 	 *	Allocated at run time, an array of rings. 	 */
name|struct
name|rx_ring
modifier|*
name|rx_rings
decl_stmt|;
name|u64
name|active_queues
decl_stmt|;
name|u32
name|num_rx_desc
decl_stmt|;
name|u32
name|rx_process_limit
decl_stmt|;
comment|/* Multicast array memory */
name|struct
name|ixgbe_mc_addr
modifier|*
name|mta
decl_stmt|;
name|int
name|num_vfs
decl_stmt|;
name|int
name|pool
decl_stmt|;
ifdef|#
directive|ifdef
name|PCI_IOV
name|struct
name|ixgbe_vf
modifier|*
name|vfs
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DEV_NETMAP
name|void
function_decl|(
modifier|*
name|init_locked
function_decl|)
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|stop_locked
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
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
name|watchdog_events
decl_stmt|;
name|unsigned
name|long
name|link_irq
decl_stmt|;
union|union
block|{
name|struct
name|ixgbe_hw_stats
name|pf
decl_stmt|;
name|struct
name|ixgbevf_hw_stats
name|vf
decl_stmt|;
block|}
name|stats
union|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100036
comment|/* counter(9) stats */
name|u64
name|ipackets
decl_stmt|;
name|u64
name|ierrors
decl_stmt|;
name|u64
name|opackets
decl_stmt|;
name|u64
name|oerrors
decl_stmt|;
name|u64
name|ibytes
decl_stmt|;
name|u64
name|obytes
decl_stmt|;
name|u64
name|imcasts
decl_stmt|;
name|u64
name|omcasts
decl_stmt|;
name|u64
name|iqdrops
decl_stmt|;
name|u64
name|noproto
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Precision Time Sync (IEEE 1588) defines */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IEEE1588
value|0x88F7
end_define

begin_define
define|#
directive|define
name|PICOSECS_PER_TICK
value|20833
end_define

begin_define
define|#
directive|define
name|TSYNC_UDP_PORT
value|319
end_define

begin_comment
comment|/* UDP port for the protocol */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TSTAMP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->core_mtx, _name, "IXGBE Core Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_trylock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->core_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IXGBE_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->tx_mtx, MA_OWNED)
end_define

begin_comment
comment|/* For backward compatibility */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PCIER_LINK_STA
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCIER_LINK_STA
value|PCIR_EXPRESS_LINK_STA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stats macros */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100036
end_if

begin_define
define|#
directive|define
name|IXGBE_SET_IPACKETS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ipackets = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IERRORS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ierrors = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OPACKETS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->opackets = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OERRORS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->oerrors = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_COLLISIONS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IBYTES
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ibytes = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OBYTES
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->obytes = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IMCASTS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->imcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OMCASTS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->omcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IQDROPS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->iqdrops = (count)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IXGBE_SET_IPACKETS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_ipackets = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IERRORS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_ierrors = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OPACKETS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_opackets = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OERRORS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_oerrors = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_COLLISIONS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_collisions = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IBYTES
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_ibytes = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OBYTES
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_obytes = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IMCASTS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_imcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_OMCASTS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_omcasts = (count)
end_define

begin_define
define|#
directive|define
name|IXGBE_SET_IQDROPS
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|)
value|(sc)->ifp->if_iqdrops = (count)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* External PHY register addresses */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PHY_CURRENT_TEMP
value|0xC820
end_define

begin_define
define|#
directive|define
name|IXGBE_PHY_OVERTEMP_STATUS
value|0xC830
end_define

begin_comment
comment|/* Sysctl help messages; displayed with sysctl -d */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SYSCTL_DESC_ADV_SPEED
define|\
value|"\nControl advertised link speed using these flags:\n" \ 	"\t0x1 - advertise 100M\n" \ 	"\t0x2 - advertise 1G\n" \ 	"\t0x4 - advertise 10G\n\n" \ 	"\t100M is only supported on certain 10GBaseT adapters.\n"
end_define

begin_define
define|#
directive|define
name|IXGBE_SYSCTL_DESC_SET_FC
define|\
value|"\nSet flow control mode using these values:\n" \ 	"\t0 - off\n" \ 	"\t1 - rx pause\n" \ 	"\t2 - tx pause\n" \ 	"\t3 - tx and rx pause"
end_define

begin_function
specifier|static
specifier|inline
name|bool
name|ixgbe_is_sfp
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
block|{
switch|switch
condition|(
name|hw
operator|->
name|phy
operator|.
name|type
condition|)
block|{
case|case
name|ixgbe_phy_sfp_avago
case|:
case|case
name|ixgbe_phy_sfp_ftl
case|:
case|case
name|ixgbe_phy_sfp_intel
case|:
case|case
name|ixgbe_phy_sfp_unknown
case|:
case|case
name|ixgbe_phy_sfp_passive_tyco
case|:
case|case
name|ixgbe_phy_sfp_passive_unknown
case|:
case|case
name|ixgbe_phy_qsfp_passive_unknown
case|:
case|case
name|ixgbe_phy_qsfp_active_unknown
case|:
case|case
name|ixgbe_phy_qsfp_intel
case|:
case|case
name|ixgbe_phy_qsfp_unknown
case|:
return|return
name|TRUE
return|;
default|default:
return|return
name|FALSE
return|;
block|}
block|}
end_function

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
name|ixgbe_rx_unrefreshed
parameter_list|(
name|struct
name|rx_ring
modifier|*
name|rxr
parameter_list|)
block|{
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
name|rxr
operator|->
name|num_desc
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

begin_comment
comment|/* ** This checks for a zero mac addr, something that will be likely ** unless the Admin on the Host has created one. */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ixv_check_ether_addr
parameter_list|(
name|u8
modifier|*
name|addr
parameter_list|)
block|{
name|bool
name|status
init|=
name|TRUE
decl_stmt|;
if|if
condition|(
operator|(
name|addr
index|[
literal|0
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|1
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|2
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|3
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|4
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|5
index|]
operator|==
literal|0
operator|)
condition|)
name|status
operator|=
name|FALSE
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Shared Prototypes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IXGBE_LEGACY_TX
end_ifdef

begin_function_decl
name|void
name|ixgbe_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_start_locked
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! IXGBE_LEGACY_TX */
end_comment

begin_function_decl
name|int
name|ixgbe_mq_start
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
name|ixgbe_mq_start_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_deferred_mq_start
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IXGBE_LEGACY_TX */
end_comment

begin_function_decl
name|int
name|ixgbe_allocate_queues
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_allocate_transmit_buffers
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_setup_transmit_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_free_transmit_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_allocate_receive_buffers
parameter_list|(
name|struct
name|rx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_setup_receive_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_free_receive_structures
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_txeof
parameter_list|(
name|struct
name|tx_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixgbe_rxeof
parameter_list|(
name|struct
name|ix_queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbe_dma_malloc
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|struct
name|ixgbe_dma_alloc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dma_free
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|ixgbe_dma_alloc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_IOV
end_ifdef

begin_function
specifier|static
specifier|inline
name|boolean_t
name|ixgbe_vf_mac_changed
parameter_list|(
name|struct
name|ixgbe_vf
modifier|*
name|vf
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|mac
parameter_list|)
block|{
return|return
operator|(
name|bcmp
argument_list|(
name|mac
argument_list|,
name|vf
operator|->
name|ether_addr
argument_list|,
name|ETHER_ADDR_LEN
argument_list|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ixgbe_send_vf_msg
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|ixgbe_vf
modifier|*
name|vf
parameter_list|,
name|u32
name|msg
parameter_list|)
block|{
if|if
condition|(
name|vf
operator|->
name|flags
operator|&
name|IXGBE_VF_CTS
condition|)
name|msg
operator||=
name|IXGBE_VT_MSGTYPE_CTS
expr_stmt|;
name|ixgbe_write_mbx
argument_list|(
operator|&
name|adapter
operator|->
name|hw
argument_list|,
operator|&
name|msg
argument_list|,
literal|1
argument_list|,
name|vf
operator|->
name|pool
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ixgbe_send_vf_ack
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|ixgbe_vf
modifier|*
name|vf
parameter_list|,
name|u32
name|msg
parameter_list|)
block|{
name|msg
operator|&=
name|IXGBE_VT_MSG_MASK
expr_stmt|;
name|ixgbe_send_vf_msg
argument_list|(
name|adapter
argument_list|,
name|vf
argument_list|,
name|msg
operator||
name|IXGBE_VT_MSGTYPE_ACK
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ixgbe_send_vf_nack
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|ixgbe_vf
modifier|*
name|vf
parameter_list|,
name|u32
name|msg
parameter_list|)
block|{
name|msg
operator|&=
name|IXGBE_VT_MSG_MASK
expr_stmt|;
name|ixgbe_send_vf_msg
argument_list|(
name|adapter
argument_list|,
name|vf
argument_list|,
name|msg
operator||
name|IXGBE_VT_MSGTYPE_NACK
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ixgbe_process_vf_ack
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|struct
name|ixgbe_vf
modifier|*
name|vf
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|vf
operator|->
name|flags
operator|&
name|IXGBE_VF_CTS
operator|)
condition|)
name|ixgbe_send_vf_nack
argument_list|(
name|adapter
argument_list|,
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|enum
name|ixgbe_iov_mode
name|ixgbe_get_iov_mode
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|)
block|{
if|if
condition|(
name|adapter
operator|->
name|num_vfs
operator|==
literal|0
condition|)
return|return
operator|(
name|IXGBE_NO_VM
operator|)
return|;
if|if
condition|(
name|adapter
operator|->
name|num_queues
operator|<=
literal|2
condition|)
return|return
operator|(
name|IXGBE_64_VM
operator|)
return|;
elseif|else
if|if
condition|(
name|adapter
operator|->
name|num_queues
operator|<=
literal|4
condition|)
return|return
operator|(
name|IXGBE_32_VM
operator|)
return|;
else|else
return|return
operator|(
name|IXGBE_NO_VM
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u16
name|ixgbe_max_vfs
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|)
block|{
comment|/* 	 * We return odd numbers below because we 	 * reserve 1 VM's worth of queues for the PF. 	 */
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|IXGBE_64_VM
case|:
return|return
operator|(
literal|63
operator|)
return|;
case|case
name|IXGBE_32_VM
case|:
return|return
operator|(
literal|31
operator|)
return|;
case|case
name|IXGBE_NO_VM
case|:
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ixgbe_vf_queues
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|)
block|{
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|IXGBE_64_VM
case|:
return|return
operator|(
literal|2
operator|)
return|;
case|case
name|IXGBE_32_VM
case|:
return|return
operator|(
literal|4
operator|)
return|;
case|case
name|IXGBE_NO_VM
case|:
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ixgbe_vf_que_index
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|,
name|u32
name|vfnum
parameter_list|,
name|int
name|num
parameter_list|)
block|{
return|return
operator|(
operator|(
name|vfnum
operator|*
name|ixgbe_vf_queues
argument_list|(
name|mode
argument_list|)
operator|)
operator|+
name|num
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ixgbe_pf_que_index
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|,
name|int
name|num
parameter_list|)
block|{
return|return
operator|(
name|ixgbe_vf_que_index
argument_list|(
name|mode
argument_list|,
name|ixgbe_max_vfs
argument_list|(
name|mode
argument_list|)
argument_list|,
name|num
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ixgbe_update_max_frame
parameter_list|(
name|struct
name|adapter
modifier|*
name|adapter
parameter_list|,
name|int
name|max_frame
parameter_list|)
block|{
if|if
condition|(
name|adapter
operator|->
name|max_frame_size
operator|<
name|max_frame
condition|)
name|adapter
operator|->
name|max_frame_size
operator|=
name|max_frame
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|ixgbe_get_mrqc
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|)
block|{
name|u32
name|mrqc
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|IXGBE_64_VM
case|:
name|mrqc
operator|=
name|IXGBE_MRQC_VMDQRSS64EN
expr_stmt|;
break|break;
case|case
name|IXGBE_32_VM
case|:
name|mrqc
operator|=
name|IXGBE_MRQC_VMDQRSS32EN
expr_stmt|;
break|break;
case|case
name|IXGBE_NO_VM
case|:
name|mrqc
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"Unexpected SR-IOV mode %d"
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|mrqc
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u32
name|ixgbe_get_mtqc
parameter_list|(
name|enum
name|ixgbe_iov_mode
name|mode
parameter_list|)
block|{
name|uint32_t
name|mtqc
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|IXGBE_64_VM
case|:
name|mtqc
operator||=
name|IXGBE_MTQC_64VF
operator||
name|IXGBE_MTQC_VT_ENA
expr_stmt|;
break|break;
case|case
name|IXGBE_32_VM
case|:
name|mtqc
operator||=
name|IXGBE_MTQC_32VF
operator||
name|IXGBE_MTQC_VT_ENA
expr_stmt|;
break|break;
case|case
name|IXGBE_NO_VM
case|:
name|mtqc
operator|=
name|IXGBE_MTQC_64Q_1PB
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"Unexpected SR-IOV mode %d"
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|mtqc
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_IOV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_H_ */
end_comment

end_unit

