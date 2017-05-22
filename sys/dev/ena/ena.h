begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * BSD LICENSE  *  * Copyright (c) 2015-2017 Amazon.com, Inc. or its affiliates.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENA_H
end_ifndef

begin_define
define|#
directive|define
name|ENA_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ena-com/ena_com.h"
end_include

begin_include
include|#
directive|include
file|"ena-com/ena_eth_com.h"
end_include

begin_define
define|#
directive|define
name|DRV_MODULE_VER_MAJOR
value|0
end_define

begin_define
define|#
directive|define
name|DRV_MODULE_VER_MINOR
value|7
end_define

begin_define
define|#
directive|define
name|DRV_MODULE_VER_SUBMINOR
value|0
end_define

begin_define
define|#
directive|define
name|DRV_MODULE_NAME
value|"ena"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DRV_MODULE_VERSION
end_ifndef

begin_define
define|#
directive|define
name|DRV_MODULE_VERSION
define|\
value|__XSTRING(DRV_MODULE_VER_MAJOR) "."		\ 	__XSTRING(DRV_MODULE_VER_MINOR) "."		\ 	__XSTRING(DRV_MODULE_VER_SUBMINOR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEVICE_NAME
value|"Elastic Network Adapter (ENA)"
end_define

begin_define
define|#
directive|define
name|DEVICE_DESC
value|"ENA adapter"
end_define

begin_comment
comment|/* Calculate DMA mask - width for ena cannot exceed 48, so it is safe */
end_comment

begin_define
define|#
directive|define
name|ENA_DMA_BIT_MASK
parameter_list|(
name|x
parameter_list|)
value|((1ULL<< (x)) - 1ULL)
end_define

begin_comment
comment|/* 1 for AENQ + ADMIN */
end_comment

begin_define
define|#
directive|define
name|ENA_MAX_MSIX_VEC
parameter_list|(
name|io_queues
parameter_list|)
value|(1 + (io_queues))
end_define

begin_define
define|#
directive|define
name|ENA_REG_BAR
value|0
end_define

begin_define
define|#
directive|define
name|ENA_MEM_BAR
value|2
end_define

begin_define
define|#
directive|define
name|ENA_BUS_DMA_SEGS
value|32
end_define

begin_define
define|#
directive|define
name|ENA_DEFAULT_RING_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|ENA_DEFAULT_SMALL_PACKET_LEN
value|128
end_define

begin_define
define|#
directive|define
name|ENA_DEFAULT_MAX_RX_BUFF_ALLOC_SIZE
value|1536
end_define

begin_define
define|#
directive|define
name|ENA_RX_REFILL_THRESH_DEVIDER
value|8
end_define

begin_define
define|#
directive|define
name|ENA_MAX_PUSH_PKT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|ENA_NAME_MAX_LEN
value|20
end_define

begin_define
define|#
directive|define
name|ENA_IRQNAME_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|ENA_PKT_MAX_BUFS
value|19
end_define

begin_define
define|#
directive|define
name|ENA_STALL_TIMEOUT
value|100
end_define

begin_define
define|#
directive|define
name|ENA_RX_RSS_TABLE_LOG_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|ENA_RX_RSS_TABLE_SIZE
value|(1<< ENA_RX_RSS_TABLE_LOG_SIZE)
end_define

begin_define
define|#
directive|define
name|ENA_HASH_KEY_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|ENA_DMA_BITS_MASK
value|40
end_define

begin_define
define|#
directive|define
name|ENA_MAX_FRAME_LEN
value|10000
end_define

begin_define
define|#
directive|define
name|ENA_MIN_FRAME_LEN
value|60
end_define

begin_define
define|#
directive|define
name|ENA_RX_HASH_KEY_NUM
value|10
end_define

begin_define
define|#
directive|define
name|ENA_RX_THASH_TABLE_SIZE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ENA_TX_CLEANUP_TRESHOLD
value|128
end_define

begin_define
define|#
directive|define
name|DB_THRESHOLD
value|64
end_define

begin_define
define|#
directive|define
name|TX_COMMIT
value|32
end_define

begin_comment
comment|/*  * TX budget for cleaning. It should be half of the RX budget to reduce amount  *  of TCP retransmissions.  */
end_comment

begin_define
define|#
directive|define
name|TX_BUDGET
value|128
end_define

begin_comment
comment|/* RX cleanup budget. -1 stands for infinity. */
end_comment

begin_define
define|#
directive|define
name|RX_BUDGET
value|256
end_define

begin_comment
comment|/*  * How many times we can repeat cleanup in the io irq handling routine if the  * RX or TX budget was depleted.  */
end_comment

begin_define
define|#
directive|define
name|CLEAN_BUDGET
value|8
end_define

begin_define
define|#
directive|define
name|RX_IRQ_INTERVAL
value|20
end_define

begin_define
define|#
directive|define
name|TX_IRQ_INTERVAL
value|50
end_define

begin_define
define|#
directive|define
name|ENA_MAX_MTU
value|9216
end_define

begin_define
define|#
directive|define
name|ENA_TSO_MAXSIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|ENA_TSO_NSEGS
value|ENA_PKT_MAX_BUFS
end_define

begin_define
define|#
directive|define
name|ENA_RX_OFFSET
value|NET_SKB_PAD + NET_IP_ALIGN
end_define

begin_define
define|#
directive|define
name|ENA_MMIO_DISABLE_REG_READ
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|ENA_TX_RING_IDX_NEXT
parameter_list|(
name|idx
parameter_list|,
name|ring_size
parameter_list|)
value|(((idx) + 1)& ((ring_size) - 1))
end_define

begin_define
define|#
directive|define
name|ENA_RX_RING_IDX_NEXT
parameter_list|(
name|idx
parameter_list|,
name|ring_size
parameter_list|)
value|(((idx) + 1)& ((ring_size) - 1))
end_define

begin_define
define|#
directive|define
name|ENA_RX_RING_IDX_ADD
parameter_list|(
name|idx
parameter_list|,
name|n
parameter_list|,
name|ring_size
parameter_list|)
define|\
value|(((idx) + (n))& ((ring_size) - 1))
end_define

begin_define
define|#
directive|define
name|ENA_IO_TXQ_IDX
parameter_list|(
name|q
parameter_list|)
value|(2 * (q))
end_define

begin_define
define|#
directive|define
name|ENA_IO_RXQ_IDX
parameter_list|(
name|q
parameter_list|)
value|(2 * (q) + 1)
end_define

begin_define
define|#
directive|define
name|ENA_MGMNT_IRQ_IDX
value|0
end_define

begin_define
define|#
directive|define
name|ENA_IO_IRQ_FIRST_IDX
value|1
end_define

begin_define
define|#
directive|define
name|ENA_IO_IRQ_IDX
parameter_list|(
name|q
parameter_list|)
value|(ENA_IO_IRQ_FIRST_IDX + (q))
end_define

begin_comment
comment|/*  * ENA device should send keep alive msg every 1 sec.  * We wait for 6 sec just to be on the safe side.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_KEEP_ALIVE_TO
value|(SBT_1S * 6)
end_define

begin_comment
comment|/* Time in jiffies before concluding the transmitter is hung. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TX_CMP_TO
value|(SBT_1S * 5)
end_define

begin_comment
comment|/* Number of queues to check for missing queues per timer tick */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TX_MONITORED_QUEUES
value|(4)
end_define

begin_comment
comment|/* Max number of timeouted packets before device reset */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TX_CMP_THRESHOLD
value|(128)
end_define

begin_comment
comment|/*  * Supported PCI vendor and devices IDs  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_AMAZON
value|0x1d0f
end_define

begin_define
define|#
directive|define
name|PCI_DEV_ID_ENA_PF
value|0x0ec2
end_define

begin_define
define|#
directive|define
name|PCI_DEV_ID_ENA_LLQ_PF
value|0x1ec2
end_define

begin_define
define|#
directive|define
name|PCI_DEV_ID_ENA_VF
value|0xec20
end_define

begin_define
define|#
directive|define
name|PCI_DEV_ID_ENA_LLQ_VF
value|0xec21
end_define

begin_struct
struct|struct
name|msix_entry
block|{
name|int
name|entry
decl_stmt|;
name|int
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_ena_vendor_info_t
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
name|index
decl_stmt|;
block|}
name|ena_vendor_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ena_irq
block|{
comment|/* Interrupt resources */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|driver_intr_t
modifier|*
name|handler
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|unsigned
name|int
name|vector
decl_stmt|;
name|bool
name|requested
decl_stmt|;
name|int
name|cpu
decl_stmt|;
name|char
name|name
index|[
name|ENA_IRQNAME_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ena_que
block|{
name|struct
name|ena_adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|ena_ring
modifier|*
name|tx_ring
decl_stmt|;
name|struct
name|ena_ring
modifier|*
name|rx_ring
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|int
name|cpu
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ena_tx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* # of ena desc for this specific mbuf 	 * (includes data desc and metadata desc) */
name|unsigned
name|int
name|tx_descs
decl_stmt|;
comment|/* # of buffers used by this mbuf */
name|unsigned
name|int
name|num_of_bufs
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* Used to detect missing tx packets */
name|struct
name|bintime
name|timestamp
decl_stmt|;
name|bool
name|print_once
decl_stmt|;
name|struct
name|ena_com_buf
name|bufs
index|[
name|ENA_PKT_MAX_BUFS
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ena_rx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|struct
name|ena_com_buf
name|ena_buf
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ena_stats_tx
block|{
name|counter_u64_t
name|cnt
decl_stmt|;
name|counter_u64_t
name|bytes
decl_stmt|;
name|counter_u64_t
name|queue_stop
decl_stmt|;
name|counter_u64_t
name|prepare_ctx_err
decl_stmt|;
name|counter_u64_t
name|queue_wakeup
decl_stmt|;
name|counter_u64_t
name|dma_mapping_err
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|unsupported_desc_num
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|napi_comp
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|tx_poll
decl_stmt|;
name|counter_u64_t
name|doorbells
decl_stmt|;
name|counter_u64_t
name|missing_tx_comp
decl_stmt|;
name|counter_u64_t
name|bad_req_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ena_stats_rx
block|{
name|counter_u64_t
name|cnt
decl_stmt|;
name|counter_u64_t
name|bytes
decl_stmt|;
name|counter_u64_t
name|refil_partial
decl_stmt|;
name|counter_u64_t
name|bad_csum
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|page_alloc_fail
decl_stmt|;
name|counter_u64_t
name|mbuf_alloc_fail
decl_stmt|;
name|counter_u64_t
name|dma_mapping_err
decl_stmt|;
name|counter_u64_t
name|bad_desc_num
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|small_copy_len_pkt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ena_ring
block|{
comment|/* Holds the empty requests for TX out of order completions */
name|uint16_t
modifier|*
name|free_tx_ids
decl_stmt|;
name|struct
name|ena_com_dev
modifier|*
name|ena_dev
decl_stmt|;
name|struct
name|ena_adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|ena_com_io_cq
modifier|*
name|ena_com_io_cq
decl_stmt|;
name|struct
name|ena_com_io_sq
modifier|*
name|ena_com_io_sq
decl_stmt|;
comment|/* The maximum length the driver can push to the device (For LLQ) */
name|enum
name|ena_admin_placement_policy_type
name|tx_mem_queue_type
decl_stmt|;
name|uint16_t
name|rx_small_copy_len
decl_stmt|;
name|uint16_t
name|qid
decl_stmt|;
name|uint16_t
name|mtu
decl_stmt|;
name|uint8_t
name|tx_max_header_size
decl_stmt|;
name|struct
name|ena_com_rx_buf_info
name|ena_bufs
index|[
name|ENA_PKT_MAX_BUFS
index|]
decl_stmt|;
name|uint32_t
name|smoothed_interval
decl_stmt|;
name|enum
name|ena_intr_moder_level
name|moder_tbl_idx
decl_stmt|;
name|struct
name|ena_que
modifier|*
name|que
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|uint16_t
name|next_to_use
decl_stmt|;
name|uint16_t
name|next_to_clean
decl_stmt|;
union|union
block|{
name|struct
name|ena_tx_buffer
modifier|*
name|tx_buffer_info
decl_stmt|;
comment|/* contex of tx packet */
name|struct
name|ena_rx_buffer
modifier|*
name|rx_buffer_info
decl_stmt|;
comment|/* contex of rx packet */
block|}
union|;
name|int
name|ring_size
decl_stmt|;
comment|/* number of tx/rx_buffer_info's entries */
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* only for TX */
name|struct
name|mtx
name|ring_mtx
decl_stmt|;
name|char
name|mtx_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|task
name|enqueue_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|enqueue_tq
decl_stmt|;
name|struct
name|task
name|cmpl_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|cmpl_tq
decl_stmt|;
union|union
block|{
name|struct
name|ena_stats_tx
name|tx_stats
decl_stmt|;
name|struct
name|ena_stats_rx
name|rx_stats
decl_stmt|;
block|}
union|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ena_stats_dev
block|{
comment|/* Not counted */
name|counter_u64_t
name|tx_timeout
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|io_suspend
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|io_resume
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|wd_expired
decl_stmt|;
name|counter_u64_t
name|interface_up
decl_stmt|;
name|counter_u64_t
name|interface_down
decl_stmt|;
comment|/* Not counted */
name|counter_u64_t
name|admin_q_pause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ena_hw_stats
block|{
name|uint64_t
name|rx_packets
decl_stmt|;
name|uint64_t
name|tx_packets
decl_stmt|;
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint64_t
name|rx_drops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Board specific private data structure */
end_comment

begin_struct
struct|struct
name|ena_adapter
block|{
name|struct
name|ena_com_dev
modifier|*
name|ena_dev
decl_stmt|;
comment|/* OS defined structs */
name|if_t
name|ifp
decl_stmt|;
name|device_t
name|pdev
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* OS resources */
name|struct
name|resource
modifier|*
name|memory
decl_stmt|;
name|struct
name|resource
modifier|*
name|registers
decl_stmt|;
name|struct
name|mtx
name|global_mtx
decl_stmt|;
name|struct
name|sx
name|ioctl_sx
decl_stmt|;
comment|/* MSI-X */
name|uint32_t
name|msix_enabled
decl_stmt|;
name|struct
name|msix_entry
modifier|*
name|msix_entries
decl_stmt|;
name|int
name|msix_vecs
decl_stmt|;
comment|/* DMA tags used throughout the driver adapter for Tx and Rx */
name|bus_dma_tag_t
name|tx_buf_tag
decl_stmt|;
name|bus_dma_tag_t
name|rx_buf_tag
decl_stmt|;
name|int
name|dma_width
decl_stmt|;
comment|/* 	 * RX packets that shorter that this len will be copied to the skb 	 * header 	 */
name|unsigned
name|int
name|small_copy_len
decl_stmt|;
name|uint16_t
name|max_tx_sgl_size
decl_stmt|;
name|uint16_t
name|max_rx_sgl_size
decl_stmt|;
name|uint32_t
name|tx_offload_cap
decl_stmt|;
comment|/* Tx fast path data */
name|int
name|num_queues
decl_stmt|;
name|unsigned
name|int
name|tx_usecs
decl_stmt|,
name|rx_usecs
decl_stmt|;
comment|/* Interrupt coalescing */
name|unsigned
name|int
name|tx_ring_size
decl_stmt|;
name|unsigned
name|int
name|rx_ring_size
decl_stmt|;
comment|/* RSS*/
name|uint8_t
name|rss_ind_tbl
index|[
name|ENA_RX_RSS_TABLE_SIZE
index|]
decl_stmt|;
name|bool
name|rss_support
decl_stmt|;
name|uint32_t
name|msg_enable
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* mdio and phy*/
name|char
name|name
index|[
name|ENA_NAME_MAX_LEN
index|]
decl_stmt|;
name|bool
name|link_status
decl_stmt|;
name|bool
name|trigger_reset
decl_stmt|;
name|bool
name|up
decl_stmt|;
name|bool
name|running
decl_stmt|;
name|uint32_t
name|wol
decl_stmt|;
comment|/* Queue will represent one TX and one RX ring */
name|struct
name|ena_que
name|que
index|[
name|ENA_MAX_NUM_IO_QUEUES
index|]
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
comment|/* TX */
name|struct
name|ena_ring
name|tx_ring
index|[
name|ENA_MAX_NUM_IO_QUEUES
index|]
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
comment|/* RX */
name|struct
name|ena_ring
name|rx_ring
index|[
name|ENA_MAX_NUM_IO_QUEUES
index|]
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
name|struct
name|ena_irq
name|irq_tbl
index|[
name|ENA_MAX_MSIX_VEC
argument_list|(
name|ENA_MAX_NUM_IO_QUEUES
argument_list|)
index|]
decl_stmt|;
comment|/* Timer service */
name|struct
name|callout
name|timer_service
decl_stmt|;
name|sbintime_t
name|keep_alive_timestamp
decl_stmt|;
name|uint32_t
name|next_monitored_tx_qid
decl_stmt|;
name|struct
name|task
name|reset_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|reset_tq
decl_stmt|;
name|int
name|wd_active
decl_stmt|;
name|sbintime_t
name|keep_alive_timeout
decl_stmt|;
name|sbintime_t
name|missing_tx_timeout
decl_stmt|;
name|uint32_t
name|missing_tx_max_queues
decl_stmt|;
name|uint32_t
name|missing_tx_threshold
decl_stmt|;
comment|/* Statistics */
name|struct
name|ena_stats_dev
name|dev_stats
decl_stmt|;
name|struct
name|ena_hw_stats
name|hw_stats
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENA_DEV_LOCK
value|mtx_lock(&adapter->global_mtx)
end_define

begin_define
define|#
directive|define
name|ENA_DEV_UNLOCK
value|mtx_unlock(&adapter->global_mtx)
end_define

begin_define
define|#
directive|define
name|ENA_RING_MTX_LOCK
parameter_list|(
name|_ring
parameter_list|)
value|mtx_lock(&(_ring)->ring_mtx)
end_define

begin_define
define|#
directive|define
name|ENA_RING_MTX_TRYLOCK
parameter_list|(
name|_ring
parameter_list|)
value|mtx_trylock(&(_ring)->ring_mtx)
end_define

begin_define
define|#
directive|define
name|ENA_RING_MTX_UNLOCK
parameter_list|(
name|_ring
parameter_list|)
value|mtx_unlock(&(_ring)->ring_mtx)
end_define

begin_function_decl
name|struct
name|ena_dev
modifier|*
name|ena_efa_enadev_get
parameter_list|(
name|device_t
name|pdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ena_register_adapter
parameter_list|(
name|struct
name|ena_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ena_unregister_adapter
parameter_list|(
name|struct
name|ena_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ena_update_stats_counters
parameter_list|(
name|struct
name|ena_adapter
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|ena_mbuf_count
parameter_list|(
name|struct
name|mbuf
modifier|*
name|mbuf
parameter_list|)
block|{
name|int
name|count
init|=
literal|1
decl_stmt|;
while|while
condition|(
operator|(
name|mbuf
operator|=
name|mbuf
operator|->
name|m_next
operator|)
operator|!=
name|NULL
condition|)
operator|++
name|count
expr_stmt|;
return|return
name|count
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(ENA_H) */
end_comment

end_unit

