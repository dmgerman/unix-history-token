begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2010, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IGB_H_DEFINED_
end_ifndef

begin_define
define|#
directive|define
name|_IGB_H_DEFINED_
end_define

begin_comment
comment|/* Tunables */
end_comment

begin_comment
comment|/*  * IGB_TXD: Maximum number of Transmit Descriptors  *  *   This value is the number of transmit descriptors allocated by the driver.  *   Increasing this value allows the driver to queue more transmits. Each  *   descriptor is 16 bytes.  *   Since TDLEN should be multiple of 128bytes, the number of transmit  *   desscriptors should meet the following condition.  *      (num_tx_desc * sizeof(struct e1000_tx_desc)) % 128 == 0  */
end_comment

begin_define
define|#
directive|define
name|IGB_MIN_TXD
value|80
end_define

begin_define
define|#
directive|define
name|IGB_DEFAULT_TXD
value|256
end_define

begin_define
define|#
directive|define
name|IGB_MAX_TXD
value|4096
end_define

begin_comment
comment|/*  * IGB_RXD: Maximum number of Transmit Descriptors  *  *   This value is the number of receive descriptors allocated by the driver.  *   Increasing this value allows the driver to buffer more incoming packets.  *   Each descriptor is 16 bytes.  A receive buffer is also allocated for each  *   descriptor. The maximum MTU size is 16110.  *   Since TDLEN should be multiple of 128bytes, the number of transmit  *   desscriptors should meet the following condition.  *      (num_tx_desc * sizeof(struct e1000_tx_desc)) % 128 == 0  */
end_comment

begin_define
define|#
directive|define
name|IGB_MIN_RXD
value|80
end_define

begin_define
define|#
directive|define
name|IGB_DEFAULT_RXD
value|256
end_define

begin_define
define|#
directive|define
name|IGB_MAX_RXD
value|4096
end_define

begin_comment
comment|/*  * IGB_TIDV - Transmit Interrupt Delay Value  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value delays the generation of transmit interrupts in units of  *   1.024 microseconds. Transmit interrupt reduction can improve CPU  *   efficiency if properly tuned for specific network traffic. If the  *   system is reporting dropped transmits, this value may be set too high  *   causing the driver to run out of available transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IGB_TIDV
value|64
end_define

begin_comment
comment|/*  * IGB_TADV - Transmit Absolute Interrupt Delay Value  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value, in units of 1.024 microseconds, limits the delay in which a  *   transmit interrupt is generated. Useful only if IGB_TIDV is non-zero,  *   this value ensures that an interrupt is generated after the initial  *   packet is sent on the wire within the set amount of time.  Proper tuning,  *   along with IGB_TIDV, may improve traffic throughput in specific  *   network conditions.  */
end_comment

begin_define
define|#
directive|define
name|IGB_TADV
value|64
end_define

begin_comment
comment|/*  * IGB_RDTR - Receive Interrupt Delay Timer (Packet Timer)  * Valid Range: 0-65535 (0=off)  * Default Value: 0  *   This value delays the generation of receive interrupts in units of 1.024  *   microseconds.  Receive interrupt reduction can improve CPU efficiency if  *   properly tuned for specific network traffic. Increasing this value adds  *   extra latency to frame reception and can end up decreasing the throughput  *   of TCP traffic. If the system is reporting dropped receives, this value  *   may be set too high, causing the driver to run out of available receive  *   descriptors.  *  *   CAUTION: When setting IGB_RDTR to a value other than 0, adapters  *            may hang (stop transmitting) under certain network conditions.  *            If this occurs a WATCHDOG message is logged in the system  *            event log. In addition, the controller is automatically reset,  *            restoring the network connection. To eliminate the potential  *            for the hang ensure that IGB_RDTR is set to 0.  */
end_comment

begin_define
define|#
directive|define
name|IGB_RDTR
value|0
end_define

begin_comment
comment|/*  * Receive Interrupt Absolute Delay Timer (Not valid for 82542/82543/82544)  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value, in units of 1.024 microseconds, limits the delay in which a  *   receive interrupt is generated. Useful only if IGB_RDTR is non-zero,  *   this value ensures that an interrupt is generated after the initial  *   packet is received within the set amount of time.  Proper tuning,  *   along with IGB_RDTR, may improve traffic throughput in specific network  *   conditions.  */
end_comment

begin_define
define|#
directive|define
name|IGB_RADV
value|64
end_define

begin_comment
comment|/*  * This parameter controls the duration of transmit watchdog timer.  */
end_comment

begin_define
define|#
directive|define
name|IGB_WATCHDOG
value|(10 * hz)
end_define

begin_comment
comment|/*  * This parameter controls when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|IGB_TX_CLEANUP_THRESHOLD
value|(adapter->num_tx_desc / 8)
end_define

begin_define
define|#
directive|define
name|IGB_TX_OP_THRESHOLD
value|(adapter->num_tx_desc / 32)
end_define

begin_comment
comment|/*  * This parameter controls whether or not autonegotation is enabled.  *              0 - Disable autonegotiation  *              1 - Enable  autonegotiation  */
end_comment

begin_define
define|#
directive|define
name|DO_AUTO_NEG
value|1
end_define

begin_comment
comment|/*  * This parameter control whether or not the driver will wait for  * autonegotiation to complete.  *              1 - Wait for autonegotiation to complete  *              0 - Don't wait for autonegotiation to complete  */
end_comment

begin_define
define|#
directive|define
name|WAIT_FOR_AUTO_NEG_DEFAULT
value|0
end_define

begin_comment
comment|/* Tunables -- End */
end_comment

begin_define
define|#
directive|define
name|AUTONEG_ADV_DEFAULT
value|(ADVERTISE_10_HALF | ADVERTISE_10_FULL | \ 				ADVERTISE_100_HALF | ADVERTISE_100_FULL | \ 				ADVERTISE_1000_FULL)
end_define

begin_define
define|#
directive|define
name|AUTO_ALL_MODES
value|0
end_define

begin_comment
comment|/* PHY master/slave setting */
end_comment

begin_define
define|#
directive|define
name|IGB_MASTER_SLAVE
value|e1000_ms_hw_default
end_define

begin_comment
comment|/*  * Micellaneous constants  */
end_comment

begin_define
define|#
directive|define
name|IGB_VENDOR_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|IGB_JUMBO_PBA
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IGB_DEFAULT_PBA
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IGB_SMARTSPEED_DOWNSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IGB_SMARTSPEED_MAX
value|15
end_define

begin_define
define|#
directive|define
name|IGB_MAX_LOOP
value|10
end_define

begin_define
define|#
directive|define
name|IGB_RX_PTHRESH
value|(hw->mac.type<= e1000_82576 ? 16 : 8)
end_define

begin_define
define|#
directive|define
name|IGB_RX_HTHRESH
value|8
end_define

begin_define
define|#
directive|define
name|IGB_RX_WTHRESH
value|1
end_define

begin_define
define|#
directive|define
name|IGB_TX_PTHRESH
value|8
end_define

begin_define
define|#
directive|define
name|IGB_TX_HTHRESH
value|1
end_define

begin_define
define|#
directive|define
name|IGB_TX_WTHRESH
value|((hw->mac.type == e1000_82576&& \                                           adapter->msix_mem) ? 1 : 16)
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

begin_define
define|#
directive|define
name|IGB_TX_BUFFER_SIZE
value|((uint32_t) 1514)
end_define

begin_define
define|#
directive|define
name|IGB_FC_PAUSE_TIME
value|0x0680
end_define

begin_define
define|#
directive|define
name|IGB_EEPROM_APME
value|0x400;
end_define

begin_comment
comment|/*  * TDBA/RDBA should be aligned on 16 byte boundary. But TDLEN/RDLEN should be  * multiple of 128 bytes. So we align TDBA/RDBA on 128 byte boundary. This will  * also optimize cache line size effect. H/W supports up to cache line size 128.  */
end_comment

begin_define
define|#
directive|define
name|IGB_DBA_ALIGN
value|128
end_define

begin_define
define|#
directive|define
name|SPEED_MODE_BIT
value|(1<<21)
end_define

begin_comment
comment|/* On PCI-E MACs only */
end_comment

begin_comment
comment|/* PCI Config defines */
end_comment

begin_define
define|#
directive|define
name|IGB_MSIX_BAR
value|3
end_define

begin_comment
comment|/* ** This is the total number of MSIX vectors you wish ** to use, it also controls the size of resources. ** The 82575 has a total of 10, 82576 has 25. Set this ** to the real amount you need to streamline data storage. */
end_comment

begin_define
define|#
directive|define
name|IGB_MSIX_VEC
value|6
end_define

begin_comment
comment|/* MSIX vectors configured */
end_comment

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
name|IGB_MAX_SCATTER
value|64
end_define

begin_define
define|#
directive|define
name|IGB_VFTA_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IGB_BR_SIZE
value|4096
end_define

begin_comment
comment|/* ring buf size */
end_comment

begin_define
define|#
directive|define
name|IGB_TSO_SIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|IGB_TSO_SEG_SIZE
value|4096
end_define

begin_comment
comment|/* Max dma segment size */
end_comment

begin_define
define|#
directive|define
name|IGB_HDR_BUF
value|128
end_define

begin_define
define|#
directive|define
name|IGB_PKTTYPE_MASK
value|0x0000FFF0
end_define

begin_define
define|#
directive|define
name|ETH_ZLEN
value|60
end_define

begin_define
define|#
directive|define
name|ETH_ADDR_LEN
value|6
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
comment|/* Define the starting Interrupt rate per Queue */
end_comment

begin_define
define|#
directive|define
name|IGB_INTS_PER_SEC
value|8000
end_define

begin_define
define|#
directive|define
name|IGB_DEFAULT_ITR
value|1000000000/(IGB_INTS_PER_SEC * 256)
end_define

begin_comment
comment|/* Header split codes for get_buf */
end_comment

begin_define
define|#
directive|define
name|IGB_CLEAN_HEADER
value|0x01
end_define

begin_define
define|#
directive|define
name|IGB_CLEAN_PAYLOAD
value|0x02
end_define

begin_define
define|#
directive|define
name|IGB_CLEAN_BOTH
value|(IGB_CLEAN_HEADER | IGB_CLEAN_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|IGB_LINK_ITR
value|2000
end_define

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
name|TSYNC_PORT
value|319
end_define

begin_comment
comment|/* UDP port for the protocol */
end_comment

begin_comment
comment|/*  * Bus dma allocation structure used by  * e1000_dma_malloc and e1000_dma_free.  */
end_comment

begin_struct
struct|struct
name|igb_dma_alloc
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
name|igb_queue
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
comment|/*  * Transmit ring: one per queue  */
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
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|igb_dma_alloc
name|txdma
decl_stmt|;
name|struct
name|e1000_tx_desc
modifier|*
name|tx_base
decl_stmt|;
name|u32
name|next_avail_desc
decl_stmt|;
name|u32
name|next_to_clean
decl_stmt|;
specifier|volatile
name|u16
name|tx_avail
decl_stmt|;
name|struct
name|igb_tx_buffer
modifier|*
name|tx_buffers
decl_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|800000
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
endif|#
directive|endif
name|bus_dma_tag_t
name|txtag
decl_stmt|;
name|u32
name|bytes
decl_stmt|;
name|u32
name|packets
decl_stmt|;
name|bool
name|watchdog_check
decl_stmt|;
name|int
name|watchdog_time
decl_stmt|;
name|u64
name|no_desc_avail
decl_stmt|;
name|u64
name|tx_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive ring: one per queue  */
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
name|struct
name|igb_dma_alloc
name|rxdma
decl_stmt|;
name|union
name|e1000_adv_rx_desc
modifier|*
name|rx_base
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
name|struct
name|mtx
name|rx_mtx
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|u32
name|last_cleaned
decl_stmt|;
name|u32
name|next_to_check
decl_stmt|;
name|struct
name|igb_rx_buf
modifier|*
name|rx_buffers
decl_stmt|;
name|bus_dma_tag_t
name|rx_htag
decl_stmt|;
comment|/* dma tag for rx head */
name|bus_dmamap_t
name|rx_hspare_map
decl_stmt|;
name|bus_dma_tag_t
name|rx_ptag
decl_stmt|;
comment|/* dma tag for rx packet */
name|bus_dmamap_t
name|rx_pspare_map
decl_stmt|;
comment|/* 	 * First/last mbuf pointers, for 	 * collecting multisegment RX packets. 	 */
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
name|u32
name|bytes
decl_stmt|;
name|u32
name|packets
decl_stmt|;
comment|/* Soft stats */
name|u64
name|rx_split_packets
decl_stmt|;
name|u64
name|rx_discarded
decl_stmt|;
name|u64
name|rx_packets
decl_stmt|;
name|u64
name|rx_bytes
decl_stmt|;
block|}
struct|;
end_struct

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
name|e1000_hw
name|hw
decl_stmt|;
name|struct
name|e1000_osdep
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
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
name|u32
name|eims_mask
decl_stmt|;
name|int
name|linkvec
decl_stmt|;
name|int
name|link_mask
decl_stmt|;
name|int
name|link_irq
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
comment|/* total vectors allocated */
name|int
name|if_flags
decl_stmt|;
name|int
name|max_frame_size
decl_stmt|;
name|int
name|min_frame_size
decl_stmt|;
name|struct
name|mtx
name|core_mtx
decl_stmt|;
name|int
name|igb_insert_vlan_header
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
comment|/* private task queue */
name|u16
name|num_queues
decl_stmt|;
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|u32
name|num_vlans
decl_stmt|;
comment|/* Management and WOL features */
name|int
name|wol
decl_stmt|;
name|int
name|has_manage
decl_stmt|;
comment|/* Info about the board itself */
name|u8
name|link_active
decl_stmt|;
name|u16
name|link_speed
decl_stmt|;
name|u16
name|link_duplex
decl_stmt|;
name|u32
name|smartspeed
decl_stmt|;
comment|/* Interface queues */
name|struct
name|igb_queue
modifier|*
name|queues
decl_stmt|;
comment|/* 	 * Transmit rings 	 */
name|struct
name|tx_ring
modifier|*
name|tx_rings
decl_stmt|;
name|u16
name|num_tx_desc
decl_stmt|;
comment|/*  	 * Receive rings 	 */
name|struct
name|rx_ring
modifier|*
name|rx_rings
decl_stmt|;
name|bool
name|rx_hdr_split
decl_stmt|;
name|u16
name|num_rx_desc
decl_stmt|;
name|int
name|rx_process_limit
decl_stmt|;
name|u32
name|rx_mbuf_sz
decl_stmt|;
name|u32
name|rx_mask
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
name|rx_overruns
decl_stmt|;
name|boolean_t
name|in_detach
decl_stmt|;
ifdef|#
directive|ifdef
name|IGB_IEEE1588
comment|/* IEEE 1588 precision time support */
name|struct
name|cyclecounter
name|cycles
decl_stmt|;
name|struct
name|nettimer
name|clock
decl_stmt|;
name|struct
name|nettime_compare
name|compare
decl_stmt|;
name|struct
name|hwtstamp_ctrl
name|hwtstamp
decl_stmt|;
endif|#
directive|endif
name|struct
name|e1000_hw_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ******************************************************************************  * vendor_info_array  *  * This array contains the list of Subvendor/Subdevice IDs on which the driver  * should load.  *  * ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_igb_vendor_info_t
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
name|igb_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|igb_tx_buffer
block|{
name|int
name|next_eop
decl_stmt|;
comment|/* Index of the desc to watch */
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

begin_struct
struct|struct
name|igb_rx_buf
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
name|bus_dmamap_t
name|head_map
decl_stmt|;
comment|/* bus_dma map for packet */
name|bus_dmamap_t
name|pack_map
decl_stmt|;
comment|/* bus_dma map for packet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IGB_CORE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->core_mtx, _name, "IGB Core Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IGB_CORE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_CORE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_CORE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_CORE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->core_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IGB_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_trylock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->tx_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IGB_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|IGB_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->tx_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IGB_H_DEFINED_ */
end_comment

end_unit

