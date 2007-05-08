begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2006, Myricom Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Myricom Inc, nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$ ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_myri10ge_mcp_h
end_ifndef

begin_define
define|#
directive|define
name|_myri10ge_mcp_h
end_define

begin_define
define|#
directive|define
name|MXGEFW_VERSION_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|MXGEFW_VERSION_MINOR
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MXGEFW
end_ifdef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 8 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_dma_addr
block|{
name|uint32_t
name|high
decl_stmt|;
name|uint32_t
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_dma_addr
name|mcp_dma_addr_t
typedef|;
end_typedef

begin_comment
comment|/* 4 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_slot
block|{
name|uint16_t
name|checksum
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_slot
name|mcp_slot_t
typedef|;
end_typedef

begin_comment
comment|/* 64 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_cmd
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|data0
decl_stmt|;
comment|/* will be low portion if data> 32 bits */
comment|/* 8 */
name|uint32_t
name|data1
decl_stmt|;
comment|/* will be high portion if data> 32 bits */
name|uint32_t
name|data2
decl_stmt|;
comment|/* currently unused.. */
comment|/* 16 */
name|struct
name|mcp_dma_addr
name|response_addr
decl_stmt|;
comment|/* 24 */
name|uint8_t
name|pad
index|[
literal|40
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_cmd
name|mcp_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* 8 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_cmd_response
block|{
name|uint32_t
name|data
decl_stmt|;
name|uint32_t
name|result
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_cmd_response
name|mcp_cmd_response_t
typedef|;
end_typedef

begin_comment
comment|/*     flags used in mcp_kreq_ether_send_t:     The SMALL flag is only needed in the first segment. It is raised    for packets that are total less or equal 512 bytes.     The CKSUM flag must be set in all segments.     The PADDED flags is set if the packet needs to be padded, and it    must be set for all segments.     The  MXGEFW_FLAGS_ALIGN_ODD must be set if the cumulative    length of all previous segments was odd. */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_SMALL
value|0x1
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_TSO_HDR
value|0x1
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_FIRST
value|0x2
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_ALIGN_ODD
value|0x4
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_CKSUM
value|0x8
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_TSO_LAST
value|0x8
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_NO_TSO
value|0x10
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_TSO_CHOP
value|0x10
end_define

begin_define
define|#
directive|define
name|MXGEFW_FLAGS_TSO_PLD
value|0x20
end_define

begin_define
define|#
directive|define
name|MXGEFW_SEND_SMALL_SIZE
value|1520
end_define

begin_define
define|#
directive|define
name|MXGEFW_MAX_MTU
value|9400
end_define

begin_union
union|union
name|mcp_pso_or_cumlen
block|{
name|uint16_t
name|pseudo_hdr_offset
decl_stmt|;
name|uint16_t
name|cum_len
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|mcp_pso_or_cumlen
name|mcp_pso_or_cumlen_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MXGEFW_MAX_SEND_DESC
value|12
end_define

begin_define
define|#
directive|define
name|MXGEFW_PAD
value|2
end_define

begin_comment
comment|/* 16 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_kreq_ether_send
block|{
name|uint32_t
name|addr_high
decl_stmt|;
name|uint32_t
name|addr_low
decl_stmt|;
name|uint16_t
name|pseudo_hdr_offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
name|uint8_t
name|rdma_count
decl_stmt|;
name|uint8_t
name|cksum_offset
decl_stmt|;
comment|/* where to start computing cksum */
name|uint8_t
name|flags
decl_stmt|;
comment|/* as defined above */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_kreq_ether_send
name|mcp_kreq_ether_send_t
typedef|;
end_typedef

begin_comment
comment|/* 8 Bytes */
end_comment

begin_struct
struct|struct
name|mcp_kreq_ether_recv
block|{
name|uint32_t
name|addr_high
decl_stmt|;
name|uint32_t
name|addr_low
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_kreq_ether_recv
name|mcp_kreq_ether_recv_t
typedef|;
end_typedef

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_BOOT_HANDOFF
value|0xfc0000
end_define

begin_define
define|#
directive|define
name|MXGEFW_BOOT_DUMMY_RDMA
value|0xfc01c0
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_CMD
value|0xf80000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_4
value|0x200000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_1
value|0x240000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_2
value|0x280000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_3
value|0x2c0000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_RECV_SMALL
value|0x300000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_RECV_BIG
value|0x340000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND
parameter_list|(
name|n
parameter_list|)
value|(0x200000 + (((n)& 0x03) * 0x40000))
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_OFFSET
parameter_list|(
name|n
parameter_list|)
value|(MXGEFW_ETH_SEND(n) - MXGEFW_ETH_SEND_4)
end_define

begin_enum
enum|enum
name|myri10ge_mcp_cmd_type
block|{
name|MXGEFW_CMD_NONE
init|=
literal|0
block|,
comment|/* Reset the mcp, it is left in a safe state, waiting      for the driver to set all its parameters */
name|MXGEFW_CMD_RESET
block|,
comment|/* get the version number of the current firmware..      (may be available in the eeprom strings..? */
name|MXGEFW_GET_MCP_VERSION
block|,
comment|/* Parameters which must be set by the driver before it can      issue MXGEFW_CMD_ETHERNET_UP. They persist until the next      MXGEFW_CMD_RESET is issued */
name|MXGEFW_CMD_SET_INTRQ_DMA
block|,
name|MXGEFW_CMD_SET_BIG_BUFFER_SIZE
block|,
comment|/* in bytes, power of 2 */
name|MXGEFW_CMD_SET_SMALL_BUFFER_SIZE
block|,
comment|/* in bytes */
comment|/* Parameters which refer to lanai SRAM addresses where the       driver must issue PIO writes for various things */
name|MXGEFW_CMD_GET_SEND_OFFSET
block|,
name|MXGEFW_CMD_GET_SMALL_RX_OFFSET
block|,
name|MXGEFW_CMD_GET_BIG_RX_OFFSET
block|,
name|MXGEFW_CMD_GET_IRQ_ACK_OFFSET
block|,
name|MXGEFW_CMD_GET_IRQ_DEASSERT_OFFSET
block|,
comment|/* Parameters which refer to rings stored on the MCP,      and whose size is controlled by the mcp */
name|MXGEFW_CMD_GET_SEND_RING_SIZE
block|,
comment|/* in bytes */
name|MXGEFW_CMD_GET_RX_RING_SIZE
block|,
comment|/* in bytes */
comment|/* Parameters which refer to rings stored in the host,      and whose size is controlled by the host.  Note that      all must be physically contiguous and must contain       a power of 2 number of entries.  */
name|MXGEFW_CMD_SET_INTRQ_SIZE
block|,
comment|/* in bytes */
comment|/* command to bring ethernet interface up.  Above parameters      (plus mtu& mac address) must have been exchanged prior      to issuing this command  */
name|MXGEFW_CMD_ETHERNET_UP
block|,
comment|/* command to bring ethernet interface down.  No further sends      or receives may be processed until an MXGEFW_CMD_ETHERNET_UP      is issued, and all interrupt queues must be flushed prior      to ack'ing this command */
name|MXGEFW_CMD_ETHERNET_DOWN
block|,
comment|/* commands the driver may issue live, without resetting      the nic.  Note that increasing the mtu "live" should      only be done if the driver has already supplied buffers      sufficiently large to handle the new mtu.  Decreasing      the mtu live is safe */
name|MXGEFW_CMD_SET_MTU
block|,
name|MXGEFW_CMD_GET_INTR_COAL_DELAY_OFFSET
block|,
comment|/* in microseconds */
name|MXGEFW_CMD_SET_STATS_INTERVAL
block|,
comment|/* in microseconds */
name|MXGEFW_CMD_SET_STATS_DMA_OBSOLETE
block|,
comment|/* replaced by SET_STATS_DMA_V2 */
name|MXGEFW_ENABLE_PROMISC
block|,
name|MXGEFW_DISABLE_PROMISC
block|,
name|MXGEFW_SET_MAC_ADDRESS
block|,
name|MXGEFW_ENABLE_FLOW_CONTROL
block|,
name|MXGEFW_DISABLE_FLOW_CONTROL
block|,
comment|/* do a DMA test      data0,data1 = DMA address      data2       = RDMA length (MSH), WDMA length (LSH)      command return data = repetitions (MSH), 0.5-ms ticks (LSH)   */
name|MXGEFW_DMA_TEST
block|,
name|MXGEFW_ENABLE_ALLMULTI
block|,
name|MXGEFW_DISABLE_ALLMULTI
block|,
comment|/* returns MXGEFW_CMD_ERROR_MULTICAST      if there is no room in the cache      data0,MSH(data1) = multicast group address */
name|MXGEFW_JOIN_MULTICAST_GROUP
block|,
comment|/* returns MXGEFW_CMD_ERROR_MULTICAST      if the address is not in the cache,      or is equal to FF-FF-FF-FF-FF-FF      data0,MSH(data1) = multicast group address */
name|MXGEFW_LEAVE_MULTICAST_GROUP
block|,
name|MXGEFW_LEAVE_ALL_MULTICAST_GROUPS
block|,
name|MXGEFW_CMD_SET_STATS_DMA_V2
block|,
comment|/* data0, data1 = bus addr,      data2 = sizeof(struct mcp_irq_data) from driver point of view, allows      adding new stuff to mcp_irq_data without changing the ABI */
name|MXGEFW_CMD_UNALIGNED_TEST
block|,
comment|/* same than DMA_TEST (same args) but abort with UNALIGNED on unaligned      chipset */
name|MXGEFW_CMD_UNALIGNED_STATUS
comment|/* return data = boolean, true if the chipset is known to be unaligned */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|myri10ge_mcp_cmd_type
name|myri10ge_mcp_cmd_type_t
typedef|;
end_typedef

begin_enum
enum|enum
name|myri10ge_mcp_cmd_status
block|{
name|MXGEFW_CMD_OK
init|=
literal|0
block|,
name|MXGEFW_CMD_UNKNOWN
block|,
name|MXGEFW_CMD_ERROR_RANGE
block|,
name|MXGEFW_CMD_ERROR_BUSY
block|,
name|MXGEFW_CMD_ERROR_EMPTY
block|,
name|MXGEFW_CMD_ERROR_CLOSED
block|,
name|MXGEFW_CMD_ERROR_HASH_ERROR
block|,
name|MXGEFW_CMD_ERROR_BAD_PORT
block|,
name|MXGEFW_CMD_ERROR_RESOURCES
block|,
name|MXGEFW_CMD_ERROR_MULTICAST
block|,
name|MXGEFW_CMD_ERROR_UNALIGNED
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|myri10ge_mcp_cmd_status
name|myri10ge_mcp_cmd_status_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MXGEFW_OLD_IRQ_DATA_LEN
value|40
end_define

begin_struct
struct|struct
name|mcp_irq_data
block|{
comment|/* add new counters at the beginning */
name|uint32_t
name|future_use
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|dropped_pause
decl_stmt|;
name|uint32_t
name|dropped_unicast_filtered
decl_stmt|;
name|uint32_t
name|dropped_bad_crc32
decl_stmt|;
name|uint32_t
name|dropped_bad_phy
decl_stmt|;
name|uint32_t
name|dropped_multicast_filtered
decl_stmt|;
comment|/* 40 Bytes */
name|uint32_t
name|send_done_count
decl_stmt|;
define|#
directive|define
name|MXGEFW_LINK_DOWN
value|0
define|#
directive|define
name|MXGEFW_LINK_UP
value|1
define|#
directive|define
name|MXGEFW_LINK_MYRINET
value|2
define|#
directive|define
name|MXGEFW_LINK_UNKNOWN
value|3
name|uint32_t
name|link_up
decl_stmt|;
name|uint32_t
name|dropped_link_overflow
decl_stmt|;
name|uint32_t
name|dropped_link_error_or_filtered
decl_stmt|;
name|uint32_t
name|dropped_runt
decl_stmt|;
name|uint32_t
name|dropped_overrun
decl_stmt|;
name|uint32_t
name|dropped_no_small_buffer
decl_stmt|;
name|uint32_t
name|dropped_no_big_buffer
decl_stmt|;
name|uint32_t
name|rdma_tags_available
decl_stmt|;
name|uint8_t
name|tx_stopped
decl_stmt|;
name|uint8_t
name|link_down
decl_stmt|;
name|uint8_t
name|stats_updated
decl_stmt|;
name|uint8_t
name|valid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mcp_irq_data
name|mcp_irq_data_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _myri10ge_mcp_h */
end_comment

end_unit

