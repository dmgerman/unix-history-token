begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2009, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EM_H_DEFINED_
end_ifndef

begin_define
define|#
directive|define
name|_EM_H_DEFINED_
end_define

begin_comment
comment|/* Tunables */
end_comment

begin_comment
comment|/*  * EM_TXD: Maximum number of Transmit Descriptors  * Valid Range: 80-256 for 82542 and 82543-based adapters  *              80-4096 for others  * Default Value: 256  *   This value is the number of transmit descriptors allocated by the driver.  *   Increasing this value allows the driver to queue more transmits. Each  *   descriptor is 16 bytes.  *   Since TDLEN should be multiple of 128bytes, the number of transmit  *   desscriptors should meet the following condition.  *      (num_tx_desc * sizeof(struct e1000_tx_desc)) % 128 == 0  */
end_comment

begin_define
define|#
directive|define
name|EM_MIN_TXD
value|80
end_define

begin_define
define|#
directive|define
name|EM_MAX_TXD_82543
value|256
end_define

begin_define
define|#
directive|define
name|EM_MAX_TXD
value|4096
end_define

begin_define
define|#
directive|define
name|EM_DEFAULT_TXD
value|EM_MAX_TXD_82543
end_define

begin_comment
comment|/*  * EM_RXD - Maximum number of receive Descriptors  * Valid Range: 80-256 for 82542 and 82543-based adapters  *              80-4096 for others  * Default Value: 256  *   This value is the number of receive descriptors allocated by the driver.  *   Increasing this value allows the driver to buffer more incoming packets.  *   Each descriptor is 16 bytes.  A receive buffer is also allocated for each  *   descriptor. The maximum MTU size is 16110.  *   Since TDLEN should be multiple of 128bytes, the number of transmit  *   desscriptors should meet the following condition.  *      (num_tx_desc * sizeof(struct e1000_tx_desc)) % 128 == 0  */
end_comment

begin_define
define|#
directive|define
name|EM_MIN_RXD
value|80
end_define

begin_define
define|#
directive|define
name|EM_MAX_RXD_82543
value|256
end_define

begin_define
define|#
directive|define
name|EM_MAX_RXD
value|4096
end_define

begin_define
define|#
directive|define
name|EM_DEFAULT_RXD
value|EM_MAX_RXD_82543
end_define

begin_comment
comment|/*  * EM_TIDV - Transmit Interrupt Delay Value  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value delays the generation of transmit interrupts in units of  *   1.024 microseconds. Transmit interrupt reduction can improve CPU  *   efficiency if properly tuned for specific network traffic. If the  *   system is reporting dropped transmits, this value may be set too high  *   causing the driver to run out of available transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|EM_TIDV
value|64
end_define

begin_comment
comment|/*  * EM_TADV - Transmit Absolute Interrupt Delay Value  * (Not valid for 82542/82543/82544)  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value, in units of 1.024 microseconds, limits the delay in which a  *   transmit interrupt is generated. Useful only if EM_TIDV is non-zero,  *   this value ensures that an interrupt is generated after the initial  *   packet is sent on the wire within the set amount of time.  Proper tuning,  *   along with EM_TIDV, may improve traffic throughput in specific  *   network conditions.  */
end_comment

begin_define
define|#
directive|define
name|EM_TADV
value|64
end_define

begin_comment
comment|/*  * EM_RDTR - Receive Interrupt Delay Timer (Packet Timer)  * Valid Range: 0-65535 (0=off)  * Default Value: 0  *   This value delays the generation of receive interrupts in units of 1.024  *   microseconds.  Receive interrupt reduction can improve CPU efficiency if  *   properly tuned for specific network traffic. Increasing this value adds  *   extra latency to frame reception and can end up decreasing the throughput  *   of TCP traffic. If the system is reporting dropped receives, this value  *   may be set too high, causing the driver to run out of available receive  *   descriptors.  *  *   CAUTION: When setting EM_RDTR to a value other than 0, adapters  *            may hang (stop transmitting) under certain network conditions.  *            If this occurs a WATCHDOG message is logged in the system  *            event log. In addition, the controller is automatically reset,  *            restoring the network connection. To eliminate the potential  *            for the hang ensure that EM_RDTR is set to 0.  */
end_comment

begin_define
define|#
directive|define
name|EM_RDTR
value|0
end_define

begin_comment
comment|/*  * Receive Interrupt Absolute Delay Timer (Not valid for 82542/82543/82544)  * Valid Range: 0-65535 (0=off)  * Default Value: 64  *   This value, in units of 1.024 microseconds, limits the delay in which a  *   receive interrupt is generated. Useful only if EM_RDTR is non-zero,  *   this value ensures that an interrupt is generated after the initial  *   packet is received within the set amount of time.  Proper tuning,  *   along with EM_RDTR, may improve traffic throughput in specific network  *   conditions.  */
end_comment

begin_define
define|#
directive|define
name|EM_RADV
value|64
end_define

begin_comment
comment|/*  * This parameter controls the max duration of transmit watchdog.  */
end_comment

begin_define
define|#
directive|define
name|EM_WATCHDOG
value|(5 * hz)
end_define

begin_comment
comment|/*  * This parameter controls when the driver calls the routine to reclaim  * transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|EM_TX_CLEANUP_THRESHOLD
value|(adapter->num_tx_desc / 8)
end_define

begin_define
define|#
directive|define
name|EM_TX_OP_THRESHOLD
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
name|EM_MASTER_SLAVE
value|e1000_ms_hw_default
end_define

begin_comment
comment|/*  * Micellaneous constants  */
end_comment

begin_define
define|#
directive|define
name|EM_VENDOR_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|EM_FLASH
value|0x0014
end_define

begin_define
define|#
directive|define
name|EM_JUMBO_PBA
value|0x00000028
end_define

begin_define
define|#
directive|define
name|EM_DEFAULT_PBA
value|0x00000030
end_define

begin_define
define|#
directive|define
name|EM_SMARTSPEED_DOWNSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|EM_SMARTSPEED_MAX
value|15
end_define

begin_define
define|#
directive|define
name|EM_MAX_INTR
value|10
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
name|EM_FC_PAUSE_TIME
value|0x0680
end_define

begin_define
define|#
directive|define
name|EM_EEPROM_APME
value|0x400;
end_define

begin_define
define|#
directive|define
name|EM_82544_APME
value|0x0004;
end_define

begin_comment
comment|/* Code compatilbility between 6 and 7 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_BPF_MTAP
end_ifndef

begin_define
define|#
directive|define
name|ETHER_BPF_MTAP
value|BPF_MTAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TDBA/RDBA should be aligned on 16 byte boundary. But TDLEN/RDLEN should be  * multiple of 128 bytes. So we align TDBA/RDBA on 128 byte boundary. This will  * also optimize cache line size effect. H/W supports up to cache line size 128.  */
end_comment

begin_define
define|#
directive|define
name|EM_DBA_ALIGN
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
name|EM_BAR_TYPE
parameter_list|(
name|v
parameter_list|)
value|((v)& EM_BAR_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|EM_BAR_TYPE_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EM_BAR_TYPE_MMEM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EM_BAR_TYPE_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EM_BAR_TYPE_FLASH
value|0x0014
end_define

begin_define
define|#
directive|define
name|EM_BAR_MEM_TYPE
parameter_list|(
name|v
parameter_list|)
value|((v)& EM_BAR_MEM_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|EM_BAR_MEM_TYPE_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EM_BAR_MEM_TYPE_32BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EM_BAR_MEM_TYPE_64BIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EM_MSIX_BAR
value|3
end_define

begin_comment
comment|/* On 82575 */
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
name|EM_MAX_SCATTER
value|64
end_define

begin_define
define|#
directive|define
name|EM_VFTA_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|EM_TSO_SIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|EM_TSO_SEG_SIZE
value|4096
end_define

begin_comment
comment|/* Max dma segment size */
end_comment

begin_define
define|#
directive|define
name|EM_MSIX_MASK
value|0x01F00000
end_define

begin_comment
comment|/* For 82574 use */
end_comment

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

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|7
end_define

begin_comment
comment|/* Offload bits in mbuf flag */
end_comment

begin_comment
comment|/*  * 82574 has a nonstandard address for EIAC  * and since its only used in MSIX, and in  * the em driver only 82574 uses MSIX we can  * solve it just using this define.  */
end_comment

begin_define
define|#
directive|define
name|EM_EIAC
value|0x000DC
end_define

begin_comment
comment|/* Used in for 82547 10Mb Half workaround */
end_comment

begin_define
define|#
directive|define
name|EM_PBA_BYTES_SHIFT
value|0xA
end_define

begin_define
define|#
directive|define
name|EM_TX_HEAD_ADDR_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|EM_PBA_TX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|EM_FIFO_HDR
value|0x10
end_define

begin_define
define|#
directive|define
name|EM_82547_PKT_THRESH
value|0x3e0
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
name|em_dma_alloc
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

begin_struct_decl
struct_decl|struct
name|adapter
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|em_int_delay_info
block|{
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
comment|/* Back-pointer to the adapter struct */
name|int
name|offset
decl_stmt|;
comment|/* Register offset to read/write */
name|int
name|value
decl_stmt|;
comment|/* Current value in usecs */
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
name|struct
name|e1000_hw
name|hw
decl_stmt|;
comment|/* FreeBSD operating-system-specific structures. */
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
name|memory
decl_stmt|;
name|struct
name|resource
modifier|*
name|flash
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix
decl_stmt|;
name|struct
name|resource
modifier|*
name|ioport
decl_stmt|;
name|int
name|io_rid
decl_stmt|;
comment|/* 82574 may use 3 int vectors */
name|struct
name|resource
modifier|*
name|res
index|[
literal|3
index|]
decl_stmt|;
name|void
modifier|*
name|tag
index|[
literal|3
index|]
decl_stmt|;
name|int
name|rid
index|[
literal|3
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
name|struct
name|callout
name|tx_fifo_timer
decl_stmt|;
name|bool
name|watchdog_check
decl_stmt|;
name|int
name|watchdog_time
decl_stmt|;
name|int
name|msi
decl_stmt|;
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
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
name|struct
name|mtx
name|rx_mtx
decl_stmt|;
name|int
name|em_insert_vlan_header
decl_stmt|;
comment|/* Task for FAST handling */
name|struct
name|task
name|link_task
decl_stmt|;
name|struct
name|task
name|rxtx_task
decl_stmt|;
name|struct
name|task
name|rx_task
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* private task queue */
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|700029
name|eventhandler_tag
name|vlan_attach
decl_stmt|;
name|eventhandler_tag
name|vlan_detach
decl_stmt|;
name|u32
name|num_vlans
decl_stmt|;
endif|#
directive|endif
comment|/* Management and WOL features */
name|u32
name|wol
decl_stmt|;
name|bool
name|has_manage
decl_stmt|;
name|bool
name|has_amt
decl_stmt|;
comment|/* Info about the board itself */
name|uint8_t
name|link_active
decl_stmt|;
name|uint16_t
name|link_speed
decl_stmt|;
name|uint16_t
name|link_duplex
decl_stmt|;
name|uint32_t
name|smartspeed
decl_stmt|;
name|struct
name|em_int_delay_info
name|tx_int_delay
decl_stmt|;
name|struct
name|em_int_delay_info
name|tx_abs_int_delay
decl_stmt|;
name|struct
name|em_int_delay_info
name|rx_int_delay
decl_stmt|;
name|struct
name|em_int_delay_info
name|rx_abs_int_delay
decl_stmt|;
comment|/* 	 * Transmit definitions 	 * 	 * We have an array of num_tx_desc descriptors (handled 	 * by the controller) paired with an array of tx_buffers 	 * (at tx_buffer_area). 	 * The index of the next available descriptor is next_avail_tx_desc. 	 * The number of remaining tx_desc is num_tx_desc_avail. 	 */
name|struct
name|em_dma_alloc
name|txdma
decl_stmt|;
comment|/* bus_dma glue for tx desc */
name|struct
name|e1000_tx_desc
modifier|*
name|tx_desc_base
decl_stmt|;
name|uint32_t
name|next_avail_tx_desc
decl_stmt|;
name|uint32_t
name|next_tx_to_clean
decl_stmt|;
specifier|volatile
name|uint16_t
name|num_tx_desc_avail
decl_stmt|;
name|uint16_t
name|num_tx_desc
decl_stmt|;
name|uint16_t
name|last_hw_offload
decl_stmt|;
name|uint32_t
name|txd_cmd
decl_stmt|;
name|struct
name|em_buffer
modifier|*
name|tx_buffer_area
decl_stmt|;
name|bus_dma_tag_t
name|txtag
decl_stmt|;
comment|/* dma tag for tx */
name|uint32_t
name|tx_tso
decl_stmt|;
comment|/* last tx was tso */
comment|/*  	 * Receive definitions 	 * 	 * we have an array of num_rx_desc rx_desc (handled by the 	 * controller), and paired with an array of rx_buffers 	 * (at rx_buffer_area). 	 * The next pair to check on receive is at offset next_rx_desc_to_check 	 */
name|struct
name|em_dma_alloc
name|rxdma
decl_stmt|;
comment|/* bus_dma glue for rx desc */
name|struct
name|e1000_rx_desc
modifier|*
name|rx_desc_base
decl_stmt|;
name|uint32_t
name|next_rx_desc_to_check
decl_stmt|;
name|uint32_t
name|rx_buffer_len
decl_stmt|;
name|uint16_t
name|num_rx_desc
decl_stmt|;
name|int
name|rx_process_limit
decl_stmt|;
name|struct
name|em_buffer
modifier|*
name|rx_buffer_area
decl_stmt|;
name|bus_dma_tag_t
name|rxtag
decl_stmt|;
name|bus_dmamap_t
name|rx_sparemap
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
name|rx_overruns
decl_stmt|;
name|unsigned
name|long
name|rx_irq
decl_stmt|;
name|unsigned
name|long
name|tx_irq
decl_stmt|;
name|unsigned
name|long
name|link_irq
decl_stmt|;
comment|/* 82547 workaround */
name|uint32_t
name|tx_fifo_size
decl_stmt|;
name|uint32_t
name|tx_fifo_head
decl_stmt|;
name|uint32_t
name|tx_fifo_head_addr
decl_stmt|;
name|uint64_t
name|tx_fifo_reset_cnt
decl_stmt|;
name|uint64_t
name|tx_fifo_wrk_cnt
decl_stmt|;
name|uint32_t
name|tx_head_addr
decl_stmt|;
comment|/* For 82544 PCIX Workaround */
name|boolean_t
name|pcix_82544
decl_stmt|;
name|boolean_t
name|in_detach
decl_stmt|;
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
name|_em_vendor_info_t
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
name|em_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|em_buffer
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

begin_comment
comment|/* For 82544 PCIX  Workaround */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ADDRESS_LENGTH_PAIR
block|{
name|uint64_t
name|address
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
block|}
name|ADDRESS_LENGTH_PAIR
operator|,
typedef|*
name|PADDRESS_LENGTH_PAIR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DESCRIPTOR_PAIR
block|{
name|ADDRESS_LENGTH_PAIR
name|descriptor
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|elements
decl_stmt|;
block|}
name|DESC_ARRAY
operator|,
typedef|*
name|PDESC_ARRAY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EM_CORE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->core_mtx, _name, "EM Core Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|EM_TX_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->tx_mtx, _name, "EM TX Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|EM_RX_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->rx_mtx, _name, "EM RX Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|EM_CORE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|EM_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_CORE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|EM_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_trylock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_CORE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->core_mtx)
end_define

begin_define
define|#
directive|define
name|EM_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->tx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->rx_mtx)
end_define

begin_define
define|#
directive|define
name|EM_CORE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->core_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|EM_TX_LOCK_ASSERT
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
comment|/* _EM_H_DEFINED_ */
end_comment

end_unit

