begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2001-2004, Intel Corporation All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGB_H_DEFINED_
end_ifndef

begin_define
define|#
directive|define
name|_IXGB_H_DEFINED_
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<net/if_types.h>
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
file|<netinet/ip.h>
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|502000
end_if

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<dev/ixgb/ixgb_hw.h>
end_include

begin_include
include|#
directive|include
file|<dev/ixgb/ixgb_ee.h>
end_include

begin_include
include|#
directive|include
file|<dev/ixgb/ixgb_ids.h>
end_include

begin_comment
comment|/* Tunables */
end_comment

begin_comment
comment|/*  * TxDescriptors Valid Range: 64-4096 Default Value: 256 This value is the  * number of transmit descriptors allocated by the driver. Increasing this  * value allows the driver to queue more transmits. Each descriptor is 16  * bytes.  */
end_comment

begin_define
define|#
directive|define
name|IXGB_MAX_TXD
value|256
end_define

begin_comment
comment|/*  * RxDescriptors Valid Range: 64-4096 Default Value: 1024 This value is the  * number of receive descriptors allocated by the driver. Increasing this  * value allows the driver to buffer more incoming packets. Each descriptor  * is 16 bytes.  A receive buffer is also allocated for each descriptor. The  * maximum MTU size is 16110.  *   */
end_comment

begin_define
define|#
directive|define
name|IXGB_MAX_RXD
value|1024
end_define

begin_comment
comment|/*  * TxIntDelay Valid Range: 0-65535 (0=off) Default Value: 32 This value  * delays the generation of transmit interrupts in units of 1.024  * microseconds. Transmit interrupt reduction can improve CPU efficiency if  * properly tuned for specific network traffic. If the system is reporting  * dropped transmits, this value may be set too high causing the driver to  * run out of available transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|TIDV
value|32
end_define

begin_comment
comment|/*  * RxIntDelay Valid Range: 0-65535 (0=off) Default Value: 72 This value  * delays the generation of receive interrupts in units of 1.024  * microseconds.  Receive interrupt reduction can improve CPU efficiency if  * properly tuned for specific network traffic. Increasing this value adds  * extra latency to frame reception and can end up decreasing the throughput  * of TCP traffic. If the system is reporting dropped receives, this value  * may be set too high, causing the driver to run out of available receive  * descriptors.  *   */
end_comment

begin_define
define|#
directive|define
name|RDTR
value|72
end_define

begin_comment
comment|/*  * This parameter controls the maximum no of times the driver will loop in  * the isr. Minimum Value = 1  */
end_comment

begin_define
define|#
directive|define
name|IXGB_MAX_INTR
value|3
end_define

begin_comment
comment|/*  * Inform the stack about transmit checksum offload capabilities.  */
end_comment

begin_define
define|#
directive|define
name|IXGB_CHECKSUM_FEATURES
value|(CSUM_TCP | CSUM_UDP)
end_define

begin_comment
comment|/*  * This parameter controls the duration of transmit watchdog timer.  */
end_comment

begin_define
define|#
directive|define
name|IXGB_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* set to 5 seconds */
end_comment

begin_comment
comment|/*  * This parameter controls when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IXGB_TX_CLEANUP_THRESHOLD
value|IXGB_MAX_TXD / 8
end_define

begin_comment
comment|/*   * Flow Control Types.   * 1. ixgb_fc_none - Flow Control Disabled   * 2. ixgb_fc_rx_pause - Flow Control Receive Only  * 3. ixgb_fc_tx_pause - Flow Control Transmit Only  * 4. ixgb_fc_full - Flow Control Enabled  */
end_comment

begin_define
define|#
directive|define
name|FLOW_CONTROL_NONE
value|ixgb_fc_none
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_RX_PAUSE
value|ixgb_fc_rx_pause
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_TX_PAUSE
value|ixgb_fc_tx_pause
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_FULL
value|ixgb_fc_full
end_define

begin_comment
comment|/*  * Set the flow control type. Assign one of the above flow control types to be enabled.  * Default Value: FLOW_CONTROL_FULL     */
end_comment

begin_define
define|#
directive|define
name|FLOW_CONTROL
value|FLOW_CONTROL_FULL
end_define

begin_comment
comment|/*  * Receive Flow control low threshold (when we send a resume frame) (FCRTL)  * Valid Range: 64 - 262,136 (0x40 - 0x3FFF8, 8 byte granularity) must be  * less than high threshold by at least 8 bytes Default Value:  163,840  * (0x28000)  */
end_comment

begin_define
define|#
directive|define
name|FCRTL
value|0x28000
end_define

begin_comment
comment|/*  * Receive Flow control high threshold (when we send a pause frame) (FCRTH)  * Valid Range: 1,536 - 262,136 (0x600 - 0x3FFF8, 8 byte granularity) Default  * Value: 196,608 (0x30000)  */
end_comment

begin_define
define|#
directive|define
name|FCRTH
value|0x30000
end_define

begin_comment
comment|/*  * Flow control request timeout (how long to pause the link partner's tx)  * (PAP 15:0) Valid Range: 1 - 65535 Default Value:  256 (0x100)  */
end_comment

begin_define
define|#
directive|define
name|FCPAUSE
value|0x100
end_define

begin_comment
comment|/* Tunables -- End */
end_comment

begin_define
define|#
directive|define
name|IXGB_VENDOR_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|IXGB_MMBA
value|0x0010
end_define

begin_comment
comment|/* Mem base address */
end_comment

begin_define
define|#
directive|define
name|IXGB_ROUNDUP
parameter_list|(
name|size
parameter_list|,
name|unit
parameter_list|)
value|(((size) + (unit) - 1)& ~((unit) - 1))
end_define

begin_define
define|#
directive|define
name|IOCTL_CMD_TYPE
value|u_long
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
name|PCI_ANY_ID
value|(~0U)
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
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
name|_SV_
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

begin_comment
comment|/* Supported RX Buffer Sizes */
end_comment

begin_define
define|#
directive|define
name|IXGB_RXBUFFER_2048
value|2048
end_define

begin_define
define|#
directive|define
name|IXGB_RXBUFFER_4096
value|4096
end_define

begin_define
define|#
directive|define
name|IXGB_RXBUFFER_8192
value|8192
end_define

begin_define
define|#
directive|define
name|IXGB_RXBUFFER_16384
value|16384
end_define

begin_define
define|#
directive|define
name|IXGB_MAX_SCATTER
value|100
end_define

begin_comment
comment|/*  * ******************************************************************************  * vendor_info_array  *   * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *  *****************************************************************************  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ixgb_vendor_info_t
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
name|ixgb_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ixgb_buffer
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* bus_dma map for packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bus dma allocation structure used by ixgb_dma_malloc and ixgb_dma_free.  */
end_comment

begin_struct
struct|struct
name|ixgb_dma_alloc
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

begin_typedef
typedef|typedef
enum|enum
name|_XSUM_CONTEXT_T
block|{
name|OFFLOAD_NONE
block|,
name|OFFLOAD_TCP_IP
block|,
name|OFFLOAD_UDP_IP
block|}
name|XSUM_CONTEXT_T
typedef|;
end_typedef

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
name|adapter
modifier|*
name|next
decl_stmt|;
name|struct
name|adapter
modifier|*
name|prev
decl_stmt|;
name|struct
name|ixgb_hw
name|hw
decl_stmt|;
comment|/* FreeBSD operating-system-specific structures */
name|struct
name|ixgb_osdep
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
name|res_ioport
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_interrupt
decl_stmt|;
name|void
modifier|*
name|int_handler_tag
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
name|io_rid
decl_stmt|;
name|int
name|tx_timer
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* Info about the board itself */
name|u_int32_t
name|part_num
decl_stmt|;
name|u_int8_t
name|link_active
decl_stmt|;
name|u_int16_t
name|link_speed
decl_stmt|;
name|u_int16_t
name|link_duplex
decl_stmt|;
name|u_int32_t
name|tx_int_delay
decl_stmt|;
name|u_int32_t
name|tx_abs_int_delay
decl_stmt|;
name|u_int32_t
name|rx_int_delay
decl_stmt|;
name|u_int32_t
name|rx_abs_int_delay
decl_stmt|;
name|int
name|raidc
decl_stmt|;
name|XSUM_CONTEXT_T
name|active_checksum_context
decl_stmt|;
comment|/* 	 * Transmit definitions 	 *  	 * We have an array of num_tx_desc descriptors (handled by the 	 * controller) paired with an array of tx_buffers (at 	 * tx_buffer_area). The index of the next available descriptor is 	 * next_avail_tx_desc. The number of remaining tx_desc is 	 * num_tx_desc_avail. 	 */
name|struct
name|ixgb_dma_alloc
name|txdma
decl_stmt|;
comment|/* bus_dma glue for tx desc */
name|struct
name|ixgb_tx_desc
modifier|*
name|tx_desc_base
decl_stmt|;
name|u_int32_t
name|next_avail_tx_desc
decl_stmt|;
name|u_int32_t
name|oldest_used_tx_desc
decl_stmt|;
specifier|volatile
name|u_int16_t
name|num_tx_desc_avail
decl_stmt|;
name|u_int16_t
name|num_tx_desc
decl_stmt|;
name|u_int32_t
name|txd_cmd
decl_stmt|;
name|struct
name|ixgb_buffer
modifier|*
name|tx_buffer_area
decl_stmt|;
name|bus_dma_tag_t
name|txtag
decl_stmt|;
comment|/* dma tag for tx */
comment|/* 	 * Receive definitions 	 *  	 * we have an array of num_rx_desc rx_desc (handled by the controller), 	 * and paired with an array of rx_buffers (at rx_buffer_area). The 	 * next pair to check on receive is at offset next_rx_desc_to_check 	 */
name|struct
name|ixgb_dma_alloc
name|rxdma
decl_stmt|;
comment|/* bus_dma glue for rx desc */
name|struct
name|ixgb_rx_desc
modifier|*
name|rx_desc_base
decl_stmt|;
name|u_int32_t
name|next_rx_desc_to_check
decl_stmt|;
name|u_int16_t
name|num_rx_desc
decl_stmt|;
name|u_int32_t
name|rx_buffer_len
decl_stmt|;
name|struct
name|ixgb_buffer
modifier|*
name|rx_buffer_area
decl_stmt|;
name|bus_dma_tag_t
name|rxtag
decl_stmt|;
comment|/* dma tag for Rx */
name|u_int32_t
name|next_rx_desc_to_use
decl_stmt|;
comment|/* Jumbo frame */
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
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
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
name|boolean_t
name|in_detach
decl_stmt|;
comment|/* Board specific private data */
ifdef|#
directive|ifdef
name|_SV_
struct|struct
name|ixgb_sv_stats
block|{
name|uint64_t
name|icr_rxdmt0
decl_stmt|;
name|uint64_t
name|icr_rxo
decl_stmt|;
name|uint64_t
name|icr_rxt0
decl_stmt|;
name|uint64_t
name|icr_TXDW
decl_stmt|;
block|}
name|sv_stats
struct|;
name|unsigned
name|long
name|no_pkts_avail
decl_stmt|;
name|unsigned
name|long
name|clean_tx_interrupts
decl_stmt|;
endif|#
directive|endif
name|struct
name|ixgb_hw_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGB_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->mtx, _name, MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IXGB_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXGB_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXGB_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|IXGB_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGB_H_DEFINED_ */
end_comment

end_unit

