begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AMD 10Gb Ethernet driver  *  * This file is available to you under your choice of the following two  * licenses:  *  * License 1: GPLv2  *  * Copyright (c) 2014-2016 Advanced Micro Devices, Inc.  *  * This file is free software; you may copy, redistribute and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation, either version 2 of the License, or (at  * your option) any later version.  *  * This file is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  *  * This file incorporates work covered by the following copyright and  * permission notice:  *     The Synopsys DWC ETHER XGMAC Software Driver and documentation  *     (hereinafter "Software") is an unsupported proprietary work of Synopsys,  *     Inc. unless otherwise expressly agreed to in writing between Synopsys  *     and you.  *  *     The Software IS NOT an item of Licensed Software or Licensed Product  *     under any End User Software License Agreement or Agreement for Licensed  *     Product with Synopsys or any supplement thereto.  Permission is hereby  *     granted, free of charge, to any person obtaining a copy of this software  *     annotated with this license and the Software, to deal in the Software  *     without restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or sell copies  *     of the Software, and to permit persons to whom the Software is furnished  *     to do so, subject to the following conditions:  *  *     The above copyright notice and this permission notice shall be included  *     in all copies or substantial portions of the Software.  *  *     THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS"  *     BASIS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  *     PARTICULAR PURPOSE ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS  *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  *     THE POSSIBILITY OF SUCH DAMAGE.  *  *  * License 2: Modified BSD  *  * Copyright (c) 2014-2016 Advanced Micro Devices, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Advanced Micro Devices, Inc. nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL<COPYRIGHT HOLDER> BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file incorporates work covered by the following copyright and  * permission notice:  *     The Synopsys DWC ETHER XGMAC Software Driver and documentation  *     (hereinafter "Software") is an unsupported proprietary work of Synopsys,  *     Inc. unless otherwise expressly agreed to in writing between Synopsys  *     and you.  *  *     The Software IS NOT an item of Licensed Software or Licensed Product  *     under any End User Software License Agreement or Agreement for Licensed  *     Product with Synopsys or any supplement thereto.  Permission is hereby  *     granted, free of charge, to any person obtaining a copy of this software  *     annotated with this license and the Software, to deal in the Software  *     without restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or sell copies  *     of the Software, and to permit persons to whom the Software is furnished  *     to do so, subject to the following conditions:  *  *     The above copyright notice and this permission notice shall be included  *     in all copies or substantial portions of the Software.  *  *     THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS"  *     BASIS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  *     PARTICULAR PURPOSE ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS  *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  *     THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XGBE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XGBE_H__
end_define

begin_include
include|#
directive|include
file|"xgbe_osdep.h"
end_include

begin_comment
comment|/* From linux/dcbnl.h */
end_comment

begin_define
define|#
directive|define
name|IEEE_8021QAZ_MAX_TCS
value|8
end_define

begin_define
define|#
directive|define
name|XGBE_DRV_NAME
value|"amd-xgbe"
end_define

begin_define
define|#
directive|define
name|XGBE_DRV_VERSION
value|"1.0.2"
end_define

begin_define
define|#
directive|define
name|XGBE_DRV_DESC
value|"AMD 10 Gigabit Ethernet Driver"
end_define

begin_comment
comment|/* Descriptor related defines */
end_comment

begin_define
define|#
directive|define
name|XGBE_TX_DESC_CNT
value|512
end_define

begin_define
define|#
directive|define
name|XGBE_TX_DESC_MIN_FREE
value|(XGBE_TX_DESC_CNT>> 3)
end_define

begin_define
define|#
directive|define
name|XGBE_TX_DESC_MAX_PROC
value|(XGBE_TX_DESC_CNT>> 1)
end_define

begin_define
define|#
directive|define
name|XGBE_RX_DESC_CNT
value|512
end_define

begin_define
define|#
directive|define
name|XGBE_TX_MAX_BUF_SIZE
value|(0x3fff& ~(64 - 1))
end_define

begin_comment
comment|/* Descriptors required for maximum contiguous TSO/GSO packet */
end_comment

begin_define
define|#
directive|define
name|XGBE_TX_MAX_SPLIT
value|((GSO_MAX_SIZE / XGBE_TX_MAX_BUF_SIZE) + 1)
end_define

begin_comment
comment|/* Maximum possible descriptors needed for an SKB:  * - Maximum number of SKB frags  * - Maximum descriptors for contiguous TSO/GSO packet  * - Possible context descriptor  * - Possible TSO header descriptor  */
end_comment

begin_define
define|#
directive|define
name|XGBE_TX_MAX_DESCS
value|(MAX_SKB_FRAGS + XGBE_TX_MAX_SPLIT + 2)
end_define

begin_define
define|#
directive|define
name|XGBE_RX_MIN_BUF_SIZE
value|1522
end_define

begin_define
define|#
directive|define
name|XGBE_RX_BUF_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|XGBE_SKB_ALLOC_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|XGBE_SPH_HDSMS_SIZE
value|2
end_define

begin_comment
comment|/* Keep in sync with SKB_ALLOC_SIZE */
end_comment

begin_define
define|#
directive|define
name|XGBE_MAX_DMA_CHANNELS
value|16
end_define

begin_define
define|#
directive|define
name|XGBE_MAX_QUEUES
value|16
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_STOP_TIMEOUT
value|5
end_define

begin_comment
comment|/* DMA cache settings - Outer sharable, write-back, write-allocate */
end_comment

begin_define
define|#
directive|define
name|XGBE_DMA_OS_AXDOMAIN
value|0x2
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_OS_ARCACHE
value|0xb
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_OS_AWCACHE
value|0xf
end_define

begin_comment
comment|/* DMA cache settings - System, no caches used */
end_comment

begin_define
define|#
directive|define
name|XGBE_DMA_SYS_AXDOMAIN
value|0x3
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_SYS_ARCACHE
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_SYS_AWCACHE
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_INTERRUPT_MASK
value|0x31c7
end_define

begin_define
define|#
directive|define
name|XGMAC_MIN_PACKET
value|60
end_define

begin_define
define|#
directive|define
name|XGMAC_STD_PACKET_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|XGMAC_MAX_STD_PACKET
value|1518
end_define

begin_define
define|#
directive|define
name|XGMAC_JUMBO_PACKET_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|XGMAC_MAX_JUMBO_PACKET
value|9018
end_define

begin_comment
comment|/* Common property names */
end_comment

begin_define
define|#
directive|define
name|XGBE_MAC_ADDR_PROPERTY
value|"mac-address"
end_define

begin_define
define|#
directive|define
name|XGBE_PHY_MODE_PROPERTY
value|"phy-mode"
end_define

begin_define
define|#
directive|define
name|XGBE_DMA_IRQS_PROPERTY
value|"amd,per-channel-interrupt"
end_define

begin_define
define|#
directive|define
name|XGBE_SPEEDSET_PROPERTY
value|"amd,speed-set"
end_define

begin_define
define|#
directive|define
name|XGBE_BLWC_PROPERTY
value|"amd,serdes-blwc"
end_define

begin_define
define|#
directive|define
name|XGBE_CDR_RATE_PROPERTY
value|"amd,serdes-cdr-rate"
end_define

begin_define
define|#
directive|define
name|XGBE_PQ_SKEW_PROPERTY
value|"amd,serdes-pq-skew"
end_define

begin_define
define|#
directive|define
name|XGBE_TX_AMP_PROPERTY
value|"amd,serdes-tx-amp"
end_define

begin_define
define|#
directive|define
name|XGBE_DFE_CFG_PROPERTY
value|"amd,serdes-dfe-tap-config"
end_define

begin_define
define|#
directive|define
name|XGBE_DFE_ENA_PROPERTY
value|"amd,serdes-dfe-tap-enable"
end_define

begin_comment
comment|/* Device-tree clock names */
end_comment

begin_define
define|#
directive|define
name|XGBE_DMA_CLOCK
value|"dma_clk"
end_define

begin_define
define|#
directive|define
name|XGBE_PTP_CLOCK
value|"ptp_clk"
end_define

begin_comment
comment|/* ACPI property names */
end_comment

begin_define
define|#
directive|define
name|XGBE_ACPI_DMA_FREQ
value|"amd,dma-freq"
end_define

begin_define
define|#
directive|define
name|XGBE_ACPI_PTP_FREQ
value|"amd,ptp-freq"
end_define

begin_comment
comment|/* Timestamp support - values based on 50MHz PTP clock  *   50MHz => 20 nsec  */
end_comment

begin_define
define|#
directive|define
name|XGBE_TSTAMP_SSINC
value|20
end_define

begin_define
define|#
directive|define
name|XGBE_TSTAMP_SNSINC
value|0
end_define

begin_comment
comment|/* Driver PMT macros */
end_comment

begin_define
define|#
directive|define
name|XGMAC_DRIVER_CONTEXT
value|1
end_define

begin_define
define|#
directive|define
name|XGMAC_IOCTL_CONTEXT
value|2
end_define

begin_define
define|#
directive|define
name|XGBE_FIFO_MAX
value|81920
end_define

begin_define
define|#
directive|define
name|XGBE_TC_MIN_QUANTUM
value|10
end_define

begin_comment
comment|/* Helper macro for descriptor handling  *  Always use XGBE_GET_DESC_DATA to access the descriptor data  *  since the index is free-running and needs to be and-ed  *  with the descriptor count value of the ring to index to  *  the proper descriptor data.  */
end_comment

begin_define
define|#
directive|define
name|XGBE_GET_DESC_DATA
parameter_list|(
name|_ring
parameter_list|,
name|_idx
parameter_list|)
define|\
value|((_ring)->rdata +					\ 	 ((_idx)& ((_ring)->rdesc_count - 1)))
end_define

begin_comment
comment|/* Default coalescing parameters */
end_comment

begin_define
define|#
directive|define
name|XGMAC_INIT_DMA_TX_USECS
value|1000
end_define

begin_define
define|#
directive|define
name|XGMAC_INIT_DMA_TX_FRAMES
value|25
end_define

begin_define
define|#
directive|define
name|XGMAC_MAX_DMA_RIWT
value|0xff
end_define

begin_define
define|#
directive|define
name|XGMAC_INIT_DMA_RX_USECS
value|30
end_define

begin_define
define|#
directive|define
name|XGMAC_INIT_DMA_RX_FRAMES
value|25
end_define

begin_comment
comment|/* Flow control queue count */
end_comment

begin_define
define|#
directive|define
name|XGMAC_MAX_FLOW_CONTROL_QUEUES
value|8
end_define

begin_comment
comment|/* Maximum MAC address hash table size (256 bits = 8 bytes) */
end_comment

begin_define
define|#
directive|define
name|XGBE_MAC_HASH_TABLE_SIZE
value|8
end_define

begin_comment
comment|/* Receive Side Scaling */
end_comment

begin_define
define|#
directive|define
name|XGBE_RSS_HASH_KEY_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|XGBE_RSS_MAX_TABLE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|XGBE_RSS_LOOKUP_TABLE_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|XGBE_RSS_HASH_KEY_TYPE
value|1
end_define

begin_comment
comment|/* Auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|XGBE_AN_MS_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|XGBE_LINK_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|XGBE_AN_INT_CMPLT
value|0x01
end_define

begin_define
define|#
directive|define
name|XGBE_AN_INC_LINK
value|0x02
end_define

begin_define
define|#
directive|define
name|XGBE_AN_PG_RCV
value|0x04
end_define

begin_define
define|#
directive|define
name|XGBE_AN_INT_MASK
value|0x07
end_define

begin_comment
comment|/* Rate-change complete wait/retry count */
end_comment

begin_define
define|#
directive|define
name|XGBE_RATECHANGE_COUNT
value|500
end_define

begin_comment
comment|/* Default SerDes settings */
end_comment

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_BLWC
value|0
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_CDR
value|0x7
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_PLL
value|0x1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_PQ
value|0x12
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_RATE
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_TXAMP
value|0xa
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_WORD
value|0x7
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_DFE_TAP_CONFIG
value|0x1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_10000_DFE_TAP_ENABLE
value|0x7f
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_BLWC
value|1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_CDR
value|0x2
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_PLL
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_PQ
value|0xa
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_RATE
value|0x1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_TXAMP
value|0xf
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_WORD
value|0x1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_DFE_TAP_CONFIG
value|0x3
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_2500_DFE_TAP_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_BLWC
value|1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_CDR
value|0x2
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_PLL
value|0x0
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_PQ
value|0xa
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_RATE
value|0x3
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_TXAMP
value|0xf
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_WORD
value|0x1
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_DFE_TAP_CONFIG
value|0x3
end_define

begin_define
define|#
directive|define
name|XGBE_SPEED_1000_DFE_TAP_ENABLE
value|0x0
end_define

begin_struct_decl
struct_decl|struct
name|xgbe_prv_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|xgbe_packet_data
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|unsigned
name|int
name|attributes
decl_stmt|;
name|unsigned
name|int
name|errors
decl_stmt|;
name|unsigned
name|int
name|rdesc_count
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|u64
name|rx_tstamp
decl_stmt|;
name|unsigned
name|int
name|tx_packets
decl_stmt|;
name|unsigned
name|int
name|tx_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Common Rx and Tx descriptor mapping */
end_comment

begin_struct
struct|struct
name|xgbe_ring_desc
block|{
name|__le32
name|desc0
decl_stmt|;
name|__le32
name|desc1
decl_stmt|;
name|__le32
name|desc2
decl_stmt|;
name|__le32
name|desc3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tx-related ring data */
end_comment

begin_struct
struct|struct
name|xgbe_tx_ring_data
block|{
name|unsigned
name|int
name|packets
decl_stmt|;
comment|/* BQL packet count */
name|unsigned
name|int
name|bytes
decl_stmt|;
comment|/* BQL byte count */
block|}
struct|;
end_struct

begin_comment
comment|/* Rx-related ring data */
end_comment

begin_struct
struct|struct
name|xgbe_rx_ring_data
block|{
name|unsigned
name|short
name|hdr_len
decl_stmt|;
comment|/* Length of received header */
name|unsigned
name|short
name|len
decl_stmt|;
comment|/* Length of received packet */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure used to hold information related to the descriptor  * and the packet associated with the descriptor (always use  * use the XGBE_GET_DESC_DATA macro to access this data from the ring)  */
end_comment

begin_struct
struct|struct
name|xgbe_ring_data
block|{
name|struct
name|xgbe_ring_desc
modifier|*
name|rdesc
decl_stmt|;
comment|/* Virtual address of descriptor */
name|bus_addr_t
name|rdata_paddr
decl_stmt|;
name|bus_dma_tag_t
name|mbuf_dmat
decl_stmt|;
name|bus_dmamap_t
name|mbuf_map
decl_stmt|;
name|bus_addr_t
name|mbuf_hdr_paddr
decl_stmt|;
name|bus_addr_t
name|mbuf_data_paddr
decl_stmt|;
name|bus_size_t
name|mbuf_len
decl_stmt|;
name|int
name|mbuf_free
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
name|struct
name|xgbe_tx_ring_data
name|tx
decl_stmt|;
comment|/* Tx-related data */
name|struct
name|xgbe_rx_ring_data
name|rx
decl_stmt|;
comment|/* Rx-related data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_ring
block|{
comment|/* Ring lock - used just for TX rings at the moment */
name|spinlock_t
name|lock
decl_stmt|;
comment|/* Per packet related information */
name|struct
name|xgbe_packet_data
name|packet_data
decl_stmt|;
comment|/* Virtual/DMA addresses and count of allocated descriptor memory */
name|struct
name|xgbe_ring_desc
modifier|*
name|rdesc
decl_stmt|;
name|bus_dmamap_t
name|rdesc_map
decl_stmt|;
name|bus_dma_tag_t
name|rdesc_dmat
decl_stmt|;
name|bus_addr_t
name|rdesc_paddr
decl_stmt|;
name|unsigned
name|int
name|rdesc_count
decl_stmt|;
name|bus_dma_tag_t
name|mbuf_dmat
decl_stmt|;
name|bus_dmamap_t
name|mbuf_map
decl_stmt|;
comment|/* Array of descriptor data corresponding the descriptor memory 	 * (always use the XGBE_GET_DESC_DATA macro to access this data) 	 */
name|struct
name|xgbe_ring_data
modifier|*
name|rdata
decl_stmt|;
comment|/* Ring index values 	 *  cur   - Tx: index of descriptor to be used for current transfer 	 *          Rx: index of descriptor to check for packet availability 	 *  dirty - Tx: index of descriptor to check for transfer complete 	 *          Rx: index of descriptor to check for buffer reallocation 	 */
name|unsigned
name|int
name|cur
decl_stmt|;
name|unsigned
name|int
name|dirty
decl_stmt|;
comment|/* Coalesce frame count used for interrupt bit setting */
name|unsigned
name|int
name|coalesce_count
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|unsigned
name|int
name|queue_stopped
decl_stmt|;
name|unsigned
name|int
name|xmit_more
decl_stmt|;
name|unsigned
name|short
name|cur_mss
decl_stmt|;
name|unsigned
name|short
name|cur_vlan_ctag
decl_stmt|;
block|}
name|tx
struct|;
block|}
union|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Structure used to describe the descriptor rings associated with  * a DMA channel.  */
end_comment

begin_struct
struct|struct
name|xgbe_channel
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* Address of private data area for device */
name|struct
name|xgbe_prv_data
modifier|*
name|pdata
decl_stmt|;
comment|/* Queue index and base address of queue's DMA registers */
name|unsigned
name|int
name|queue_index
decl_stmt|;
name|bus_space_tag_t
name|dma_tag
decl_stmt|;
name|bus_space_handle_t
name|dma_handle
decl_stmt|;
comment|/* Per channel interrupt irq number */
name|struct
name|resource
modifier|*
name|dma_irq_res
decl_stmt|;
name|void
modifier|*
name|dma_irq_tag
decl_stmt|;
name|unsigned
name|int
name|saved_ier
decl_stmt|;
name|struct
name|xgbe_ring
modifier|*
name|tx_ring
decl_stmt|;
name|struct
name|xgbe_ring
modifier|*
name|rx_ring
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_enum
enum|enum
name|xgbe_state
block|{
name|XGBE_DOWN
block|,
name|XGBE_LINK_INIT
block|,
name|XGBE_LINK_ERR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_int
block|{
name|XGMAC_INT_DMA_CH_SR_TI
block|,
name|XGMAC_INT_DMA_CH_SR_TPS
block|,
name|XGMAC_INT_DMA_CH_SR_TBU
block|,
name|XGMAC_INT_DMA_CH_SR_RI
block|,
name|XGMAC_INT_DMA_CH_SR_RBU
block|,
name|XGMAC_INT_DMA_CH_SR_RPS
block|,
name|XGMAC_INT_DMA_CH_SR_TI_RI
block|,
name|XGMAC_INT_DMA_CH_SR_FBE
block|,
name|XGMAC_INT_DMA_ALL
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_int_state
block|{
name|XGMAC_INT_STATE_SAVE
block|,
name|XGMAC_INT_STATE_RESTORE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_speed
block|{
name|XGBE_SPEED_1000
init|=
literal|0
block|,
name|XGBE_SPEED_2500
block|,
name|XGBE_SPEED_10000
block|,
name|XGBE_SPEEDS
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_an
block|{
name|XGBE_AN_READY
init|=
literal|0
block|,
name|XGBE_AN_PAGE_RECEIVED
block|,
name|XGBE_AN_INCOMPAT_LINK
block|,
name|XGBE_AN_COMPLETE
block|,
name|XGBE_AN_NO_LINK
block|,
name|XGBE_AN_ERROR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_rx
block|{
name|XGBE_RX_BPA
init|=
literal|0
block|,
name|XGBE_RX_XNP
block|,
name|XGBE_RX_COMPLETE
block|,
name|XGBE_RX_ERROR
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_mode
block|{
name|XGBE_MODE_KR
init|=
literal|0
block|,
name|XGBE_MODE_KX
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|xgbe_speedset
block|{
name|XGBE_SPEEDSET_1000_10000
init|=
literal|0
block|,
name|XGBE_SPEEDSET_2500_10000
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|xgbe_phy
block|{
name|u32
name|supported
decl_stmt|;
name|u32
name|advertising
decl_stmt|;
name|u32
name|lp_advertising
decl_stmt|;
name|int
name|address
decl_stmt|;
name|int
name|autoneg
decl_stmt|;
name|int
name|speed
decl_stmt|;
name|int
name|duplex
decl_stmt|;
name|int
name|link
decl_stmt|;
name|int
name|pause_autoneg
decl_stmt|;
name|int
name|tx_pause
decl_stmt|;
name|int
name|rx_pause
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_mmc_stats
block|{
comment|/* Tx Stats */
name|u64
name|txoctetcount_gb
decl_stmt|;
name|u64
name|txframecount_gb
decl_stmt|;
name|u64
name|txbroadcastframes_g
decl_stmt|;
name|u64
name|txmulticastframes_g
decl_stmt|;
name|u64
name|tx64octets_gb
decl_stmt|;
name|u64
name|tx65to127octets_gb
decl_stmt|;
name|u64
name|tx128to255octets_gb
decl_stmt|;
name|u64
name|tx256to511octets_gb
decl_stmt|;
name|u64
name|tx512to1023octets_gb
decl_stmt|;
name|u64
name|tx1024tomaxoctets_gb
decl_stmt|;
name|u64
name|txunicastframes_gb
decl_stmt|;
name|u64
name|txmulticastframes_gb
decl_stmt|;
name|u64
name|txbroadcastframes_gb
decl_stmt|;
name|u64
name|txunderflowerror
decl_stmt|;
name|u64
name|txoctetcount_g
decl_stmt|;
name|u64
name|txframecount_g
decl_stmt|;
name|u64
name|txpauseframes
decl_stmt|;
name|u64
name|txvlanframes_g
decl_stmt|;
comment|/* Rx Stats */
name|u64
name|rxframecount_gb
decl_stmt|;
name|u64
name|rxoctetcount_gb
decl_stmt|;
name|u64
name|rxoctetcount_g
decl_stmt|;
name|u64
name|rxbroadcastframes_g
decl_stmt|;
name|u64
name|rxmulticastframes_g
decl_stmt|;
name|u64
name|rxcrcerror
decl_stmt|;
name|u64
name|rxrunterror
decl_stmt|;
name|u64
name|rxjabbererror
decl_stmt|;
name|u64
name|rxundersize_g
decl_stmt|;
name|u64
name|rxoversize_g
decl_stmt|;
name|u64
name|rx64octets_gb
decl_stmt|;
name|u64
name|rx65to127octets_gb
decl_stmt|;
name|u64
name|rx128to255octets_gb
decl_stmt|;
name|u64
name|rx256to511octets_gb
decl_stmt|;
name|u64
name|rx512to1023octets_gb
decl_stmt|;
name|u64
name|rx1024tomaxoctets_gb
decl_stmt|;
name|u64
name|rxunicastframes_g
decl_stmt|;
name|u64
name|rxlengtherror
decl_stmt|;
name|u64
name|rxoutofrangetype
decl_stmt|;
name|u64
name|rxpauseframes
decl_stmt|;
name|u64
name|rxfifooverflow
decl_stmt|;
name|u64
name|rxvlanframes_gb
decl_stmt|;
name|u64
name|rxwatchdogerror
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_ext_stats
block|{
name|u64
name|tx_tso_packets
decl_stmt|;
name|u64
name|rx_split_header_packets
decl_stmt|;
name|u64
name|rx_buffer_unavailable
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_hw_if
block|{
name|int
function_decl|(
modifier|*
name|tx_complete
function_decl|)
parameter_list|(
name|struct
name|xgbe_ring_desc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_mac_address
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_rx_mode
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_rx_csum
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|disable_rx_csum
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_rx_vlan_stripping
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|disable_rx_vlan_stripping
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_rx_vlan_filtering
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|disable_rx_vlan_filtering
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|update_vlan_hash_table
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|read_mmd_regs
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|write_mmd_regs
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_gmii_speed
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_gmii_2500_speed
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set_xgmii_speed
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_tx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_tx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_rx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_rx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|powerup_tx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|powerdown_tx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|powerup_rx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|powerdown_rx
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|exit
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_int
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|,
name|enum
name|xgbe_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|disable_int
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|,
name|enum
name|xgbe_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dev_xmit
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dev_read
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tx_desc_init
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rx_desc_init
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tx_desc_reset
function_decl|)
parameter_list|(
name|struct
name|xgbe_ring_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rx_desc_reset
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|struct
name|xgbe_ring_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_last_desc
function_decl|)
parameter_list|(
name|struct
name|xgbe_ring_desc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_context_desc
function_decl|)
parameter_list|(
name|struct
name|xgbe_ring_desc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tx_start_xmit
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|,
name|struct
name|xgbe_ring
modifier|*
parameter_list|)
function_decl|;
comment|/* For FLOW ctrl */
name|int
function_decl|(
modifier|*
name|config_tx_flow_control
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_rx_flow_control
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For RX coalescing */
name|int
function_decl|(
modifier|*
name|config_rx_coalesce
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_tx_coalesce
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|usec_to_riwt
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|riwt_to_usec
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
comment|/* For RX and TX threshold config */
name|int
function_decl|(
modifier|*
name|config_rx_threshold
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_tx_threshold
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
comment|/* For RX and TX Store and Forward Mode config */
name|int
function_decl|(
modifier|*
name|config_rsf_mode
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_tsf_mode
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
comment|/* For TX DMA Operate on Second Frame config */
name|int
function_decl|(
modifier|*
name|config_osp_mode
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For RX and TX PBL config */
name|int
function_decl|(
modifier|*
name|config_rx_pbl_val
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_rx_pbl_val
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_tx_pbl_val
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_tx_pbl_val
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|config_pblx8
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For MMC statistics */
name|void
function_decl|(
modifier|*
name|rx_mmc_int
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tx_mmc_int
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|read_mmc_stats
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For Receive Side Scaling */
name|int
function_decl|(
modifier|*
name|disable_rss
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_phy_if
block|{
comment|/* For initial PHY setup */
name|void
function_decl|(
modifier|*
name|phy_init
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For PHY support when setting device up/down */
name|int
function_decl|(
modifier|*
name|phy_reset
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|phy_start
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|phy_stop
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
comment|/* For PHY support while device is up */
name|void
function_decl|(
modifier|*
name|phy_status
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|phy_config_aneg
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_desc_if
block|{
name|int
function_decl|(
modifier|*
name|alloc_ring_resources
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|free_ring_resources
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|map_tx_skb
function_decl|)
parameter_list|(
name|struct
name|xgbe_channel
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|map_rx_buffer
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|struct
name|xgbe_ring
modifier|*
parameter_list|,
name|struct
name|xgbe_ring_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|unmap_rdata
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|,
name|struct
name|xgbe_ring_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wrapper_tx_desc_init
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wrapper_rx_desc_init
function_decl|)
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure contains flags that indicate what hardware features  * or configurations are present in the device.  */
end_comment

begin_struct
struct|struct
name|xgbe_hw_features
block|{
comment|/* HW Version */
name|unsigned
name|int
name|version
decl_stmt|;
comment|/* HW Feature Register0 */
name|unsigned
name|int
name|gmii
decl_stmt|;
comment|/* 1000 Mbps support */
name|unsigned
name|int
name|vlhash
decl_stmt|;
comment|/* VLAN Hash Filter */
name|unsigned
name|int
name|sma
decl_stmt|;
comment|/* SMA(MDIO) Interface */
name|unsigned
name|int
name|rwk
decl_stmt|;
comment|/* PMT remote wake-up packet */
name|unsigned
name|int
name|mgk
decl_stmt|;
comment|/* PMT magic packet */
name|unsigned
name|int
name|mmc
decl_stmt|;
comment|/* RMON module */
name|unsigned
name|int
name|aoe
decl_stmt|;
comment|/* ARP Offload */
name|unsigned
name|int
name|ts
decl_stmt|;
comment|/* IEEE 1588-2008 Advanced Timestamp */
name|unsigned
name|int
name|eee
decl_stmt|;
comment|/* Energy Efficient Ethernet */
name|unsigned
name|int
name|tx_coe
decl_stmt|;
comment|/* Tx Checksum Offload */
name|unsigned
name|int
name|rx_coe
decl_stmt|;
comment|/* Rx Checksum Offload */
name|unsigned
name|int
name|addn_mac
decl_stmt|;
comment|/* Additional MAC Addresses */
name|unsigned
name|int
name|ts_src
decl_stmt|;
comment|/* Timestamp Source */
name|unsigned
name|int
name|sa_vlan_ins
decl_stmt|;
comment|/* Source Address or VLAN Insertion */
comment|/* HW Feature Register1 */
name|unsigned
name|int
name|rx_fifo_size
decl_stmt|;
comment|/* MTL Receive FIFO Size */
name|unsigned
name|int
name|tx_fifo_size
decl_stmt|;
comment|/* MTL Transmit FIFO Size */
name|unsigned
name|int
name|adv_ts_hi
decl_stmt|;
comment|/* Advance Timestamping High Word */
name|unsigned
name|int
name|dma_width
decl_stmt|;
comment|/* DMA width */
name|unsigned
name|int
name|dcb
decl_stmt|;
comment|/* DCB Feature */
name|unsigned
name|int
name|sph
decl_stmt|;
comment|/* Split Header Feature */
name|unsigned
name|int
name|tso
decl_stmt|;
comment|/* TCP Segmentation Offload */
name|unsigned
name|int
name|dma_debug
decl_stmt|;
comment|/* DMA Debug Registers */
name|unsigned
name|int
name|rss
decl_stmt|;
comment|/* Receive Side Scaling */
name|unsigned
name|int
name|tc_cnt
decl_stmt|;
comment|/* Number of Traffic Classes */
name|unsigned
name|int
name|hash_table_size
decl_stmt|;
comment|/* Hash Table Size */
name|unsigned
name|int
name|l3l4_filter_num
decl_stmt|;
comment|/* Number of L3-L4 Filters */
comment|/* HW Feature Register2 */
name|unsigned
name|int
name|rx_q_cnt
decl_stmt|;
comment|/* Number of MTL Receive Queues */
name|unsigned
name|int
name|tx_q_cnt
decl_stmt|;
comment|/* Number of MTL Transmit Queues */
name|unsigned
name|int
name|rx_ch_cnt
decl_stmt|;
comment|/* Number of DMA Receive Channels */
name|unsigned
name|int
name|tx_ch_cnt
decl_stmt|;
comment|/* Number of DMA Transmit Channels */
name|unsigned
name|int
name|pps_out_num
decl_stmt|;
comment|/* Number of PPS outputs */
name|unsigned
name|int
name|aux_snap_num
decl_stmt|;
comment|/* Number of Aux snapshot inputs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xgbe_prv_data
block|{
name|struct
name|ifnet
modifier|*
name|netdev
decl_stmt|;
name|struct
name|platform_device
modifier|*
name|pdev
decl_stmt|;
name|struct
name|acpi_device
modifier|*
name|adev
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
comment|/* ACPI or DT flag */
name|unsigned
name|int
name|use_acpi
decl_stmt|;
comment|/* XGMAC/XPCS related mmio registers */
name|struct
name|resource
modifier|*
name|xgmac_res
decl_stmt|;
comment|/* XGMAC CSRs */
name|struct
name|resource
modifier|*
name|xpcs_res
decl_stmt|;
comment|/* XPCS MMD registers */
name|struct
name|resource
modifier|*
name|rxtx_res
decl_stmt|;
comment|/* SerDes Rx/Tx CSRs */
name|struct
name|resource
modifier|*
name|sir0_res
decl_stmt|;
comment|/* SerDes integration registers (1/2) */
name|struct
name|resource
modifier|*
name|sir1_res
decl_stmt|;
comment|/* SerDes integration registers (2/2) */
comment|/* DMA tag */
name|bus_dma_tag_t
name|dmat
decl_stmt|;
comment|/* XPCS indirect addressing lock */
name|spinlock_t
name|xpcs_lock
decl_stmt|;
comment|/* Flags representing xgbe_state */
name|unsigned
name|long
name|dev_state
decl_stmt|;
name|struct
name|resource
modifier|*
name|dev_irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|chan_irq_res
index|[
literal|4
index|]
decl_stmt|;
name|void
modifier|*
name|dev_irq_tag
decl_stmt|;
name|unsigned
name|int
name|per_channel_irq
decl_stmt|;
name|struct
name|xgbe_hw_if
name|hw_if
decl_stmt|;
name|struct
name|xgbe_phy_if
name|phy_if
decl_stmt|;
name|struct
name|xgbe_desc_if
name|desc_if
decl_stmt|;
comment|/* AXI DMA settings */
name|unsigned
name|int
name|coherent
decl_stmt|;
name|unsigned
name|int
name|axdomain
decl_stmt|;
name|unsigned
name|int
name|arcache
decl_stmt|;
name|unsigned
name|int
name|awcache
decl_stmt|;
comment|/* Service routine support */
name|struct
name|taskqueue
modifier|*
name|dev_workqueue
decl_stmt|;
name|struct
name|task
name|service_work
decl_stmt|;
name|struct
name|callout
name|service_timer
decl_stmt|;
comment|/* Rings for Tx/Rx on a DMA channel */
name|struct
name|xgbe_channel
modifier|*
name|channel
decl_stmt|;
name|unsigned
name|int
name|channel_count
decl_stmt|;
name|unsigned
name|int
name|tx_ring_count
decl_stmt|;
name|unsigned
name|int
name|tx_desc_count
decl_stmt|;
name|unsigned
name|int
name|rx_ring_count
decl_stmt|;
name|unsigned
name|int
name|rx_desc_count
decl_stmt|;
name|unsigned
name|int
name|tx_q_count
decl_stmt|;
name|unsigned
name|int
name|rx_q_count
decl_stmt|;
comment|/* Tx/Rx common settings */
name|unsigned
name|int
name|pblx8
decl_stmt|;
comment|/* Tx settings */
name|unsigned
name|int
name|tx_sf_mode
decl_stmt|;
name|unsigned
name|int
name|tx_threshold
decl_stmt|;
name|unsigned
name|int
name|tx_pbl
decl_stmt|;
name|unsigned
name|int
name|tx_osp_mode
decl_stmt|;
comment|/* Rx settings */
name|unsigned
name|int
name|rx_sf_mode
decl_stmt|;
name|unsigned
name|int
name|rx_threshold
decl_stmt|;
name|unsigned
name|int
name|rx_pbl
decl_stmt|;
comment|/* Tx coalescing settings */
name|unsigned
name|int
name|tx_usecs
decl_stmt|;
name|unsigned
name|int
name|tx_frames
decl_stmt|;
comment|/* Rx coalescing settings */
name|unsigned
name|int
name|rx_riwt
decl_stmt|;
name|unsigned
name|int
name|rx_usecs
decl_stmt|;
name|unsigned
name|int
name|rx_frames
decl_stmt|;
comment|/* Current Rx buffer size */
name|unsigned
name|int
name|rx_buf_size
decl_stmt|;
comment|/* Flow control settings */
name|unsigned
name|int
name|pause_autoneg
decl_stmt|;
name|unsigned
name|int
name|tx_pause
decl_stmt|;
name|unsigned
name|int
name|rx_pause
decl_stmt|;
comment|/* Receive Side Scaling settings */
name|u8
name|rss_key
index|[
name|XGBE_RSS_HASH_KEY_SIZE
index|]
decl_stmt|;
name|u32
name|rss_table
index|[
name|XGBE_RSS_MAX_TABLE_SIZE
index|]
decl_stmt|;
name|u32
name|rss_options
decl_stmt|;
comment|/* Netdev related settings */
name|unsigned
name|char
name|mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|struct
name|xgbe_mmc_stats
name|mmc_stats
decl_stmt|;
name|struct
name|xgbe_ext_stats
name|ext_stats
decl_stmt|;
comment|/* Device clocks */
name|struct
name|clk
modifier|*
name|sysclk
decl_stmt|;
name|unsigned
name|long
name|sysclk_rate
decl_stmt|;
name|struct
name|clk
modifier|*
name|ptpclk
decl_stmt|;
name|unsigned
name|long
name|ptpclk_rate
decl_stmt|;
comment|/* DCB support */
name|unsigned
name|int
name|q2tc_map
index|[
name|XGBE_MAX_QUEUES
index|]
decl_stmt|;
name|unsigned
name|int
name|prio2q_map
index|[
name|IEEE_8021QAZ_MAX_TCS
index|]
decl_stmt|;
name|u8
name|num_tcs
decl_stmt|;
comment|/* Hardware features of the device */
name|struct
name|xgbe_hw_features
name|hw_feat
decl_stmt|;
comment|/* Device restart work structure */
name|struct
name|task
name|restart_work
decl_stmt|;
comment|/* Keeps track of power mode */
name|unsigned
name|int
name|power_down
decl_stmt|;
comment|/* Network interface message level setting */
name|u32
name|msg_enable
decl_stmt|;
comment|/* Current PHY settings */
name|int
name|phy_link
decl_stmt|;
name|int
name|phy_speed
decl_stmt|;
comment|/* MDIO/PHY related settings */
name|struct
name|xgbe_phy
name|phy
decl_stmt|;
name|int
name|mdio_mmd
decl_stmt|;
name|unsigned
name|long
name|link_check
decl_stmt|;
name|char
name|an_name
index|[
name|IFNAMSIZ
operator|+
literal|32
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|an_irq_res
decl_stmt|;
name|void
modifier|*
name|an_irq_tag
decl_stmt|;
name|unsigned
name|int
name|speed_set
decl_stmt|;
comment|/* SerDes UEFI configurable settings. 	 *   Switching between modes/speeds requires new values for some 	 *   SerDes settings.  The values can be supplied as device 	 *   properties in array format.  The first array entry is for 	 *   1GbE, second for 2.5GbE and third for 10GbE 	 */
name|u32
name|serdes_blwc
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
name|u32
name|serdes_cdr_rate
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
name|u32
name|serdes_pq_skew
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
name|u32
name|serdes_tx_amp
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
name|u32
name|serdes_dfe_tap_cfg
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
name|u32
name|serdes_dfe_tap_ena
index|[
name|XGBE_SPEEDS
index|]
decl_stmt|;
comment|/* Auto-negotiation state machine support */
name|unsigned
name|int
name|an_int
decl_stmt|;
name|struct
name|sx
name|an_mutex
decl_stmt|;
name|enum
name|xgbe_an
name|an_result
decl_stmt|;
name|enum
name|xgbe_an
name|an_state
decl_stmt|;
name|enum
name|xgbe_rx
name|kr_state
decl_stmt|;
name|enum
name|xgbe_rx
name|kx_state
decl_stmt|;
name|unsigned
name|int
name|an_supported
decl_stmt|;
name|unsigned
name|int
name|parallel_detect
decl_stmt|;
name|unsigned
name|int
name|fec_ability
decl_stmt|;
name|unsigned
name|long
name|an_start
decl_stmt|;
name|unsigned
name|int
name|lpm_ctrl
decl_stmt|;
comment|/* CTRL1 for resume */
block|}
struct|;
end_struct

begin_comment
comment|/* Function prototypes*/
end_comment

begin_function_decl
name|int
name|xgbe_open
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgbe_close
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgbe_xmit
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
name|xgbe_change_mtu
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_init_function_ptrs_dev
parameter_list|(
name|struct
name|xgbe_hw_if
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_init_function_ptrs_phy
parameter_list|(
name|struct
name|xgbe_phy_if
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_init_function_ptrs_desc
parameter_list|(
name|struct
name|xgbe_desc_if
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_get_all_hw_features
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_init_rx_coalesce
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgbe_init_tx_coalesce
parameter_list|(
name|struct
name|xgbe_prv_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: Uncomment for function trace log messages in KERNEL LOG */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|YDEBUG
end_define

begin_define
define|#
directive|define
name|YDEBUG_MDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For debug prints */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|YDEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBGPR
parameter_list|(
name|x
modifier|...
parameter_list|)
value|printf(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGPR
parameter_list|(
name|x
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YDEBUG_MDIO
end_ifdef

begin_define
define|#
directive|define
name|DBGPR_MDIO
parameter_list|(
name|x
modifier|...
parameter_list|)
value|printf(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGPR_MDIO
parameter_list|(
name|x
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

