begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2006-2009, Myricom Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Myricom Inc, nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$ ***************************************************************************/
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

begin_if
if|#
directive|if
name|defined
name|MXGEFW
operator|&&
operator|!
name|defined
name|_stdint_h_
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|MXGEFW_NDIS
end_ifdef

begin_comment
comment|/* 8-byte descriptor, exclusively used by NDIS drivers. */
end_comment

begin_struct
struct|struct
name|mcp_slot_8
block|{
comment|/* Place hash value at the top so it gets written before length.    * The driver polls length.    */
name|uint32_t
name|hash
decl_stmt|;
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
name|mcp_slot_8
name|mcp_slot_8_t
typedef|;
end_typedef

begin_comment
comment|/* Two bits of length in mcp_slot are used to indicate hash type. */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_RSS_HASH_NULL
value|(0<< 14)
end_define

begin_comment
comment|/* bit 15:14 = 00 */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_RSS_HASH_IPV4
value|(1<< 14)
end_define

begin_comment
comment|/* bit 15:14 = 01 */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_RSS_HASH_TCP_IPV4
value|(2<< 14)
end_define

begin_comment
comment|/* bit 15:14 = 10 */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_RSS_HASH_MASK
value|(3<< 14)
end_define

begin_comment
comment|/* bit 15:14 = 11 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|MXGEFW_ETH_SEND_GO
value|0x380000
end_define

begin_define
define|#
directive|define
name|MXGEFW_ETH_SEND_STOP
value|0x3C0000
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
init|=
literal|1
block|,
comment|/* get the version number of the current firmware..      (may be available in the eeprom strings..? */
name|MXGEFW_GET_MCP_VERSION
init|=
literal|2
block|,
comment|/* Parameters which must be set by the driver before it can      issue MXGEFW_CMD_ETHERNET_UP. They persist until the next      MXGEFW_CMD_RESET is issued */
name|MXGEFW_CMD_SET_INTRQ_DMA
init|=
literal|3
block|,
comment|/* data0 = LSW of the host address    * data1 = MSW of the host address    * data2 = slice number if multiple slices are used    */
name|MXGEFW_CMD_SET_BIG_BUFFER_SIZE
init|=
literal|4
block|,
comment|/* in bytes, power of 2 */
name|MXGEFW_CMD_SET_SMALL_BUFFER_SIZE
init|=
literal|5
block|,
comment|/* in bytes */
comment|/* Parameters which refer to lanai SRAM addresses where the       driver must issue PIO writes for various things */
name|MXGEFW_CMD_GET_SEND_OFFSET
init|=
literal|6
block|,
name|MXGEFW_CMD_GET_SMALL_RX_OFFSET
init|=
literal|7
block|,
name|MXGEFW_CMD_GET_BIG_RX_OFFSET
init|=
literal|8
block|,
comment|/* data0 = slice number if multiple slices are used */
name|MXGEFW_CMD_GET_IRQ_ACK_OFFSET
init|=
literal|9
block|,
name|MXGEFW_CMD_GET_IRQ_DEASSERT_OFFSET
init|=
literal|10
block|,
comment|/* Parameters which refer to rings stored on the MCP,      and whose size is controlled by the mcp */
name|MXGEFW_CMD_GET_SEND_RING_SIZE
init|=
literal|11
block|,
comment|/* in bytes */
name|MXGEFW_CMD_GET_RX_RING_SIZE
init|=
literal|12
block|,
comment|/* in bytes */
comment|/* Parameters which refer to rings stored in the host,      and whose size is controlled by the host.  Note that      all must be physically contiguous and must contain       a power of 2 number of entries.  */
name|MXGEFW_CMD_SET_INTRQ_SIZE
init|=
literal|13
block|,
comment|/* in bytes */
define|#
directive|define
name|MXGEFW_CMD_SET_INTRQ_SIZE_FLAG_NO_STRICT_SIZE_CHECK
value|(1U<< 31)
comment|/* command to bring ethernet interface up.  Above parameters      (plus mtu& mac address) must have been exchanged prior      to issuing this command  */
name|MXGEFW_CMD_ETHERNET_UP
init|=
literal|14
block|,
comment|/* command to bring ethernet interface down.  No further sends      or receives may be processed until an MXGEFW_CMD_ETHERNET_UP      is issued, and all interrupt queues must be flushed prior      to ack'ing this command */
name|MXGEFW_CMD_ETHERNET_DOWN
init|=
literal|15
block|,
comment|/* commands the driver may issue live, without resetting      the nic.  Note that increasing the mtu "live" should      only be done if the driver has already supplied buffers      sufficiently large to handle the new mtu.  Decreasing      the mtu live is safe */
name|MXGEFW_CMD_SET_MTU
init|=
literal|16
block|,
name|MXGEFW_CMD_GET_INTR_COAL_DELAY_OFFSET
init|=
literal|17
block|,
comment|/* in microseconds */
name|MXGEFW_CMD_SET_STATS_INTERVAL
init|=
literal|18
block|,
comment|/* in microseconds */
name|MXGEFW_CMD_SET_STATS_DMA_OBSOLETE
init|=
literal|19
block|,
comment|/* replaced by SET_STATS_DMA_V2 */
name|MXGEFW_ENABLE_PROMISC
init|=
literal|20
block|,
name|MXGEFW_DISABLE_PROMISC
init|=
literal|21
block|,
name|MXGEFW_SET_MAC_ADDRESS
init|=
literal|22
block|,
name|MXGEFW_ENABLE_FLOW_CONTROL
init|=
literal|23
block|,
name|MXGEFW_DISABLE_FLOW_CONTROL
init|=
literal|24
block|,
comment|/* do a DMA test      data0,data1 = DMA address      data2       = RDMA length (MSH), WDMA length (LSH)      command return data = repetitions (MSH), 0.5-ms ticks (LSH)   */
name|MXGEFW_DMA_TEST
init|=
literal|25
block|,
name|MXGEFW_ENABLE_ALLMULTI
init|=
literal|26
block|,
name|MXGEFW_DISABLE_ALLMULTI
init|=
literal|27
block|,
comment|/* returns MXGEFW_CMD_ERROR_MULTICAST      if there is no room in the cache      data0,MSH(data1) = multicast group address */
name|MXGEFW_JOIN_MULTICAST_GROUP
init|=
literal|28
block|,
comment|/* returns MXGEFW_CMD_ERROR_MULTICAST      if the address is not in the cache,      or is equal to FF-FF-FF-FF-FF-FF      data0,MSH(data1) = multicast group address */
name|MXGEFW_LEAVE_MULTICAST_GROUP
init|=
literal|29
block|,
name|MXGEFW_LEAVE_ALL_MULTICAST_GROUPS
init|=
literal|30
block|,
name|MXGEFW_CMD_SET_STATS_DMA_V2
init|=
literal|31
block|,
comment|/* data0, data1 = bus addr,    * data2 = sizeof(struct mcp_irq_data) from driver point of view, allows    * adding new stuff to mcp_irq_data without changing the ABI    *    * If multiple slices are used, data2 contains both the size of the    * structure (in the lower 16 bits) and the slice number    * (in the upper 16 bits).    */
name|MXGEFW_CMD_UNALIGNED_TEST
init|=
literal|32
block|,
comment|/* same than DMA_TEST (same args) but abort with UNALIGNED on unaligned      chipset */
name|MXGEFW_CMD_UNALIGNED_STATUS
init|=
literal|33
block|,
comment|/* return data = boolean, true if the chipset is known to be unaligned */
name|MXGEFW_CMD_ALWAYS_USE_N_BIG_BUFFERS
init|=
literal|34
block|,
comment|/* data0 = number of big buffers to use.  It must be 0 or a power of 2.    * 0 indicates that the NIC consumes as many buffers as they are required    * for packet. This is the default behavior.    * A power of 2 number indicates that the NIC always uses the specified    * number of buffers for each big receive packet.    * It is up to the driver to ensure that this value is big enough for    * the NIC to be able to receive maximum-sized packets.    */
name|MXGEFW_CMD_GET_MAX_RSS_QUEUES
init|=
literal|35
block|,
name|MXGEFW_CMD_ENABLE_RSS_QUEUES
init|=
literal|36
block|,
comment|/* data0 = number of slices n (0, 1, ..., n-1) to enable    * data1 = interrupt mode | use of multiple transmit queues.    * 0=share one INTx/MSI.    * 1=use one MSI-X per queue.    * If all queues share one interrupt, the driver must have set    * RSS_SHARED_INTERRUPT_DMA before enabling queues.    * 2=enable both receive and send queues.    * Without this bit set, only one send queue (slice 0's send queue)    * is enabled.  The receive queues are always enabled.    */
define|#
directive|define
name|MXGEFW_SLICE_INTR_MODE_SHARED
value|0x0
define|#
directive|define
name|MXGEFW_SLICE_INTR_MODE_ONE_PER_SLICE
value|0x1
define|#
directive|define
name|MXGEFW_SLICE_ENABLE_MULTIPLE_TX_QUEUES
value|0x2
name|MXGEFW_CMD_GET_RSS_SHARED_INTERRUPT_MASK_OFFSET
init|=
literal|37
block|,
name|MXGEFW_CMD_SET_RSS_SHARED_INTERRUPT_DMA
init|=
literal|38
block|,
comment|/* data0, data1 = bus address lsw, msw */
name|MXGEFW_CMD_GET_RSS_TABLE_OFFSET
init|=
literal|39
block|,
comment|/* get the offset of the indirection table */
name|MXGEFW_CMD_SET_RSS_TABLE_SIZE
init|=
literal|40
block|,
comment|/* set the size of the indirection table */
name|MXGEFW_CMD_GET_RSS_KEY_OFFSET
init|=
literal|41
block|,
comment|/* get the offset of the secret key */
name|MXGEFW_CMD_RSS_KEY_UPDATED
init|=
literal|42
block|,
comment|/* tell nic that the secret key's been updated */
name|MXGEFW_CMD_SET_RSS_ENABLE
init|=
literal|43
block|,
comment|/* data0 = enable/disable rss    * 0: disable rss.  nic does not distribute receive packets.    * 1: enable rss.  nic distributes receive packets among queues.    * data1 = hash type    * 1: IPV4            (required by RSS)    * 2: TCP_IPV4        (required by RSS)    * 3: IPV4 | TCP_IPV4 (required by RSS)    * 4: source port    * 5: source port + destination port    */
define|#
directive|define
name|MXGEFW_RSS_HASH_TYPE_IPV4
value|0x1
define|#
directive|define
name|MXGEFW_RSS_HASH_TYPE_TCP_IPV4
value|0x2
define|#
directive|define
name|MXGEFW_RSS_HASH_TYPE_SRC_PORT
value|0x4
define|#
directive|define
name|MXGEFW_RSS_HASH_TYPE_SRC_DST_PORT
value|0x5
define|#
directive|define
name|MXGEFW_RSS_HASH_TYPE_MAX
value|0x5
name|MXGEFW_CMD_GET_MAX_TSO6_HDR_SIZE
init|=
literal|44
block|,
comment|/* Return data = the max. size of the entire headers of a IPv6 TSO packet.    * If the header size of a IPv6 TSO packet is larger than the specified    * value, then the driver must not use TSO.    * This size restriction only applies to IPv6 TSO.    * For IPv4 TSO, the maximum size of the headers is fixed, and the NIC    * always has enough header buffer to store maximum-sized headers.    */
name|MXGEFW_CMD_SET_TSO_MODE
init|=
literal|45
block|,
comment|/* data0 = TSO mode.    * 0: Linux/FreeBSD style (NIC default)    * 1: NDIS/NetBSD style    */
define|#
directive|define
name|MXGEFW_TSO_MODE_LINUX
value|0
define|#
directive|define
name|MXGEFW_TSO_MODE_NDIS
value|1
name|MXGEFW_CMD_MDIO_READ
init|=
literal|46
block|,
comment|/* data0 = dev_addr (PMA/PMD or PCS ...), data1 = register/addr */
name|MXGEFW_CMD_MDIO_WRITE
init|=
literal|47
block|,
comment|/* data0 = dev_addr,  data1 = register/addr, data2 = value  */
name|MXGEFW_CMD_I2C_READ
init|=
literal|48
block|,
comment|/* Starts to get a fresh copy of one byte or of the module i2c table, the    * obtained data is cached inside the xaui-xfi chip :    *   data0 :  0 => get one byte, 1=> get 256 bytes    *   data1 :  If data0 == 0: location to refresh    *               bit 7:0  register location    *               bit 8:15 is the i2c slave addr (0 is interpreted as 0xA1)    *               bit 23:16 is the i2c bus number (for multi-port NICs)    *            If data0 == 1: unused    * The operation might take ~1ms for a single byte or ~65ms when refreshing all 256 bytes    * During the i2c operation,  MXGEFW_CMD_I2C_READ or MXGEFW_CMD_I2C_BYTE attempts    *  will return MXGEFW_CMD_ERROR_BUSY    */
name|MXGEFW_CMD_I2C_BYTE
init|=
literal|49
block|,
comment|/* Return the last obtained copy of a given byte in the xfp i2c table    * (copy cached during the last relevant MXGEFW_CMD_I2C_READ)    *   data0 : index of the desired table entry    *  Return data = the byte stored at the requested index in the table    */
name|MXGEFW_CMD_GET_VPUMP_OFFSET
init|=
literal|50
block|,
comment|/* Return data = NIC memory offset of mcp_vpump_public_global */
name|MXGEFW_CMD_RESET_VPUMP
init|=
literal|51
block|,
comment|/* Resets the VPUMP state */
name|MXGEFW_CMD_SET_RSS_MCP_SLOT_TYPE
init|=
literal|52
block|,
comment|/* data0 = mcp_slot type to use.    * 0 = the default 4B mcp_slot    * 1 = 8B mcp_slot_8    */
define|#
directive|define
name|MXGEFW_RSS_MCP_SLOT_TYPE_MIN
value|0
define|#
directive|define
name|MXGEFW_RSS_MCP_SLOT_TYPE_WITH_HASH
value|1
name|MXGEFW_CMD_SET_THROTTLE_FACTOR
init|=
literal|53
block|,
comment|/* set the throttle factor for ethp_z8e      data0 = throttle_factor      throttle_factor = 256 * pcie-raw-speed / tx_speed      tx_speed = 256 * pcie-raw-speed / throttle_factor       For PCI-E x8: pcie-raw-speed == 16Gb/s      For PCI-E x4: pcie-raw-speed == 8Gb/s       ex1: throttle_factor == 0x1a0 (416), tx_speed == 1.23GB/s == 9.846 Gb/s      ex2: throttle_factor == 0x200 (512), tx_speed == 1.0GB/s == 8 Gb/s       with tx_boundary == 2048, max-throttle-factor == 8191 => min-speed == 500Mb/s      with tx_boundary == 4096, max-throttle-factor == 4095 => min-speed == 1Gb/s   */
name|MXGEFW_CMD_VPUMP_UP
init|=
literal|54
block|,
comment|/* Allocates VPump Connection, Send Request and Zero copy buffer address tables */
name|MXGEFW_CMD_GET_VPUMP_CLK
init|=
literal|55
block|,
comment|/* Get the lanai clock */
name|MXGEFW_CMD_GET_DCA_OFFSET
init|=
literal|56
block|,
comment|/* offset of dca control for WDMAs */
comment|/* VMWare NetQueue commands */
name|MXGEFW_CMD_NETQ_GET_FILTERS_PER_QUEUE
init|=
literal|57
block|,
name|MXGEFW_CMD_NETQ_ADD_FILTER
init|=
literal|58
block|,
comment|/* data0 = filter_id<< 16 | queue<< 8 | type */
comment|/* data1 = MS4 of MAC Addr */
comment|/* data2 = LS2_MAC<< 16 | VLAN_tag */
name|MXGEFW_CMD_NETQ_DEL_FILTER
init|=
literal|59
block|,
comment|/* data0 = filter_id */
name|MXGEFW_CMD_NETQ_QUERY1
init|=
literal|60
block|,
name|MXGEFW_CMD_NETQ_QUERY2
init|=
literal|61
block|,
name|MXGEFW_CMD_NETQ_QUERY3
init|=
literal|62
block|,
name|MXGEFW_CMD_NETQ_QUERY4
init|=
literal|63
block|,
name|MXGEFW_CMD_RELAX_RXBUFFER_ALIGNMENT
init|=
literal|64
block|,
comment|/* When set, small receive buffers can cross page boundaries.    * Both small and big receive buffers may start at any address.    * This option has performance implications, so use with caution.    */
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
init|=
literal|1
block|,
name|MXGEFW_CMD_ERROR_RANGE
init|=
literal|2
block|,
name|MXGEFW_CMD_ERROR_BUSY
init|=
literal|3
block|,
name|MXGEFW_CMD_ERROR_EMPTY
init|=
literal|4
block|,
name|MXGEFW_CMD_ERROR_CLOSED
init|=
literal|5
block|,
name|MXGEFW_CMD_ERROR_HASH_ERROR
init|=
literal|6
block|,
name|MXGEFW_CMD_ERROR_BAD_PORT
init|=
literal|7
block|,
name|MXGEFW_CMD_ERROR_RESOURCES
init|=
literal|8
block|,
name|MXGEFW_CMD_ERROR_MULTICAST
init|=
literal|9
block|,
name|MXGEFW_CMD_ERROR_UNALIGNED
init|=
literal|10
block|,
name|MXGEFW_CMD_ERROR_NO_MDIO
init|=
literal|11
block|,
name|MXGEFW_CMD_ERROR_I2C_FAILURE
init|=
literal|12
block|,
name|MXGEFW_CMD_ERROR_I2C_ABSENT
init|=
literal|13
block|,
name|MXGEFW_CMD_ERROR_BAD_PCIE_LINK
init|=
literal|14
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

begin_ifdef
ifdef|#
directive|ifdef
name|MXGEFW_NDIS
end_ifdef

begin_comment
comment|/* Exclusively used by NDIS drivers */
end_comment

begin_struct
struct|struct
name|mcp_rss_shared_interrupt
block|{
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|queue
decl_stmt|;
name|uint8_t
name|valid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* definitions for NETQ filter type */
end_comment

begin_define
define|#
directive|define
name|MXGEFW_NETQ_FILTERTYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MXGEFW_NETQ_FILTERTYPE_MACADDR
value|1
end_define

begin_define
define|#
directive|define
name|MXGEFW_NETQ_FILTERTYPE_VLAN
value|2
end_define

begin_define
define|#
directive|define
name|MXGEFW_NETQ_FILTERTYPE_VLANMACADDR
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _myri10ge_mcp_h */
end_comment

end_unit

