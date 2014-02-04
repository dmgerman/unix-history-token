begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Bjoern A. Zeeb  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-11-C-0249)  * ("MRC2"), as part of the DARPA MRC research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IF_ATSEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IF_ATSEREG_H
end_define

begin_define
define|#
directive|define
name|ATSE_VENDOR
value|0x6af7
end_define

begin_define
define|#
directive|define
name|ATSE_DEVICE
value|0x00bd
end_define

begin_comment
comment|/* See hints file/fdt for ctrl port and Avalon FIFO addresses. */
end_comment

begin_comment
comment|/* Section 3. Parameter Settings. */
end_comment

begin_comment
comment|/*  * This is a lot of options that affect the way things are synthesized.  * We cannot really make them all hints and most of them might be stale.  */
end_comment

begin_comment
comment|/* 3-1 Core Configuration */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static const char *atse_core_core_variation[] = { 	[0] = "10/100/1000 Mbps Ethernet MAC only", 	[1] = "10/100/1000 Mbps Ethernet MAC with 1000BASE-X/SGMII PCS", 	[2] = "1000BASE-X/SGMII PCS only", 	[3] = "1000 Mbps Small MAC", 	[4] = "10/100 Mbps Small MAC", 	NULL }; static const char *atse_core_interface[] = { 	[0] = "MII",
comment|/* Core variation 4. */
end_comment

begin_comment
unit|[1] = "GMII",
comment|/* Core variation 3. */
end_comment

begin_comment
unit|[2] = "RGMII",
comment|/* Core variation 0,1,3. */
end_comment

begin_comment
unit|[3] = "MII/GMII",
comment|/* Core variation 0,1. */
end_comment

begin_endif
unit|NULL };
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CORE_CORE_VARIATION
value|1
end_define

begin_comment
comment|/* atse_core_core_variation[] */
end_comment

begin_define
define|#
directive|define
name|CORE_INTERFACE
value|3
end_define

begin_comment
comment|/* atse_core_interface[] */
end_comment

begin_define
define|#
directive|define
name|CORE_USE_INTERNAL_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|CORE_NUMBER_OF_PORTS
value|1
end_define

begin_comment
comment|/* Internal FIFO count. */
end_comment

begin_define
define|#
directive|define
name|CORE_USE_TRANSCEIVER_BLOCK
value|1
end_define

begin_comment
comment|/* SGMII PCS transceiver: 						 * LVDS I/O. */
end_comment

begin_comment
comment|/* 3-2 MAC Options. */
end_comment

begin_comment
comment|/* Ethernet MAC Options. */
end_comment

begin_define
define|#
directive|define
name|MAC_ENABLE_10_100_HDX_SUPPORT
value|0
end_define

begin_define
define|#
directive|define
name|MAC_ENABLE_RG_G_MII_LOOPBACK
value|0
end_define

begin_define
define|#
directive|define
name|MAC_ENABLE_SUPL_MAC_UCAST_ADDR
value|0
end_define

begin_comment
comment|/* Supplementary MAC unicast. */
end_comment

begin_define
define|#
directive|define
name|MAC_INCLUDE_STATISTICS_COUNTERS
value|0
end_define

begin_define
define|#
directive|define
name|MAC_STATISTICS_COUNTERS_64BIT
value|0
end_define

begin_define
define|#
directive|define
name|MAC_INCLUDE_MC_HASHTABLE
value|0
end_define

begin_comment
comment|/* Multicast. */
end_comment

begin_define
define|#
directive|define
name|MAC_ALIGN_PKTHDR_32BIT
value|1
end_define

begin_define
define|#
directive|define
name|MAC_ENABLE_FDX_FLOW_CTRL
value|0
end_define

begin_define
define|#
directive|define
name|MAC_ENABLE_VLAN_DETECTION
value|0
end_define

begin_comment
comment|/* VLAN and stacked VLANs. */
end_comment

begin_define
define|#
directive|define
name|MAC_ENABLE_MAGIC_PKT_DETECTION
value|0
end_define

begin_comment
comment|/* MDIO Module. */
end_comment

begin_define
define|#
directive|define
name|MAC_MDIO_INCLUDE_MDIO_MODULE
value|1
end_define

begin_define
define|#
directive|define
name|MAC_MDIO_HOST_CLOCK_DIVISOR
value|40
end_define

begin_comment
comment|/* Not just On/Off. */
end_comment

begin_comment
comment|/* 3-4 FIFO Options. */
end_comment

begin_comment
comment|/* Width and Memory Type. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char *fifo_memory_block[] = { 	[0] = "M4K", 	[1] = "M9K", 	[2] = "M144K", 	[3] = "MRAM", 	[4] = "AUTO", 	NULL };
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FIFO_MEMORY_BLOCK
value|4
end_define

begin_define
define|#
directive|define
name|FIFO_WITDH
value|32
end_define

begin_comment
comment|/* Other: 8 bits. */
end_comment

begin_comment
comment|/* Depth. */
end_comment

begin_define
define|#
directive|define
name|FIFO_DEPTH_TX
value|2048
end_define

begin_comment
comment|/* 64 .. 64k, 2048x32bits. */
end_comment

begin_define
define|#
directive|define
name|FIFO_DEPTH_RX
value|2048
end_define

begin_comment
comment|/* 64 .. 64k, 2048x32bits. */
end_comment

begin_define
define|#
directive|define
name|ATSE_TX_LIST_CNT
value|5
end_define

begin_comment
comment|/* Certainly not bufferbloat. */
end_comment

begin_comment
comment|/* 3-4 PCS/Transceiver Options */
end_comment

begin_comment
comment|/* PCS Options. */
end_comment

begin_define
define|#
directive|define
name|PCS_TXRX_PHY_ID
value|0x00000000
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCS_TXRX_ENABLE_SGMII_BRIDGE
value|0
end_define

begin_comment
comment|/* Transceiver Options. */
end_comment

begin_define
define|#
directive|define
name|PCS_TXRX_EXP_POWER_DOWN_SIGNAL
value|0
end_define

begin_comment
comment|/* Export power down signal. */
end_comment

begin_define
define|#
directive|define
name|PCS_TXRX_ENABLE_DYNAMIC_RECONF
value|0
end_define

begin_comment
comment|/* Dynamic trans. reconfig. */
end_comment

begin_define
define|#
directive|define
name|PCS_TXRX_STARTING_CHANNEL
value|0
end_define

begin_comment
comment|/* 0..284. */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* XXX more values based on the bitmaps provided. Cleanup. */
end_comment

begin_comment
comment|/* See regs above. */
end_comment

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BLOCK_DIAGRAM
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BLOCK_DIAGRAM_SHOW_SIGANLS
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_PARAM_SINGLE_RESET_MODE
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BASIC_OPTS_DEPTH
value|16
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BASIC_OPTS_ALLOW_BACKPRESSURE
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BASIC_OPTS_CLOCK_SETTING
value|"Single Clock Mode"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_BASIC_OPTS_FIFO_IMPL
value|"Construct FIFO from embedded memory blocks"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_STATUS_PORT_CREATE_STATUS_INT_FOR_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_STATUS_PORT_CREATE_STATUS_INT_FOR_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_STATUS_PORT_ENABLE_IRQ_FOR_STATUS_PORT
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_INPUT_TYPE
value|"AVALONMM_WRITE"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_OUTPUT_TYPE
value|"AVALONST_SOURCE"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_MM_PORT_SETTINGS_DATA_WIDTH
value|""
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_ST_PORT_SETTINGS_BITS_PER_SYMBOL
value|8
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_ST_PORT_SETTINGS_SYM_PER_BEAT
value|4
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_ST_PORT_SETTINGS_ERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_ST_PORT_SETTINGS_CHANNEL_WIDTH
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_TX_AVALON_ST_PORT_SETTINGS_ENABLE_PACKET_DATA
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BLOCK_DIAGRAM
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BLOCK_DIAGRAM_SHOW_SIGNALS
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_PARAM_SINGLE_RESET_MODE
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BASIC_OPTS_DEPTH
value|16
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BASIC_OPTS_ALLOW_BACKPRESSURE
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BASIC_OPTS_CLOCK_SETTING
value|"Single Clock Mode"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_BASIC_OPTS_FIFO_IMPL
value|"Construct FIFO from embedded memory blocks"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_STATUS_PORT_CREATE_STATUS_INT_FOR_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_STATUS_PORT_CREATE_STATUS_INT_FOR_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_STATUS_PORT_ENABLE_IRQ_FOR_STATUS_PORT
value|1
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_INPUT_TYPE
value|"AVALONST_SINK"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_OUTPUT_TYPE
value|"AVALONMM_READ"
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_MM_PORT_SETTINGS_DATA_WIDTH
value|""
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_ST_PORT_SETTINGS_BITS_PER_SYMBOL
value|8
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_ST_PORT_SETTINGS_SYM_PER_BEAT
value|4
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_ST_PORT_SETTINGS_ERROR_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_ST_PORT_SETTINGS_CHANNEL_WIDTH
value|0
end_define

begin_define
define|#
directive|define
name|AVALON_FIFO_RX_AVALON_ST_PORT_SETTINGS_ENABLE_PACKET_DATA
value|1
end_define

begin_comment
comment|/* -------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* 5. Configuration Register Space. */
end_comment

begin_comment
comment|/* 5-1, MAC Configuration Register Space; Dword offsets. */
end_comment

begin_comment
comment|/* 0x00 - 0x17, Base Configuration. */
end_comment

begin_define
define|#
directive|define
name|BASE_CONFIG_REV
value|0x00
end_define

begin_comment
comment|/* ro, IP Core ver. */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_REV_VER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BASE_CFG_REV_CUST_VERSION__MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|BASE_CFG_SCRATCH
value|0x01
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG
value|0x02
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_TX_ENA
value|(1<<0)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_RX_ENA
value|(1<<1)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_XON_GEN
value|(1<<2)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_ETH_SPEED
value|(1<<3)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_PROMIS_EN
value|(1<<4)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_PAD_EN
value|(1<<5)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_CRC_FWD
value|(1<<6)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_PAUSE_FWD
value|(1<<7)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_PAUSE_IGNORE
value|(1<<8)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_TX_ADDR_INS
value|(1<<9)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_HD_ENA
value|(1<<10)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_EXCESS_COL
value|(1<<11)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_LATE_COL
value|(1<<12)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_SW_RESET
value|(1<<13)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_MHASH_SEL
value|(1<<14)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_LOOP_ENA
value|(1<<15)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_TX_ADDR_SEL
value|(1<<16|1<<17|1<<18)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_MAGIC_ENA
value|(1<<19)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_SLEEP
value|(1<<20)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_WAKEUP
value|(1<<21)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_XOFF_GEN
value|(1<<22)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_CNTL_FRM_ENA
value|(1<<23)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_NO_LGTH_CHECK
value|(1<<24)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_ENA_10
value|(1<<25)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_RX_ERR_DISC
value|(1<<26)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_DISABLE_READ_TIMEOUT
value|(1<<27)
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* 28-30 Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_COMMAND_CONFIG_CNT_RESET
value|(1<<31)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_MAC_0
value|0x03
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_MAC_1
value|0x04
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_FRM_LENGTH
value|0x05
end_define

begin_comment
comment|/* rw/ro, 1518 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_PAUSE_QUANT
value|0x06
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_RX_SECTION_EMPTY
value|0x07
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_RX_SECTION_FULL
value|0x08
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_TX_SECTION_EMPTY
value|0x09
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_TX_SECTION_FULL
value|0x0A
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_RX_ALMOST_EMPTY
value|0x0B
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_RX_ALMOST_FULL
value|0x0C
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_TX_ALMOST_EMPTY
value|0x0D
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_TX_ALMOST_FULL
value|0x0E
end_define

begin_comment
comment|/* rw/ro, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_MDIO_ADDR0
value|0x0F
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_MDIO_ADDR1
value|0x10
end_define

begin_comment
comment|/* rw, 1 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_HOLDOFF_QUANT
value|0x11
end_define

begin_comment
comment|/* rw, 0xFFFF */
end_comment

begin_comment
comment|/* 0x12-0x16 Reserved. */
end_comment

begin_comment
comment|/* -, 0 */
end_comment

begin_define
define|#
directive|define
name|BASE_CFG_TX_IPG_LENGTH
value|0x17
end_define

begin_comment
comment|/* rw, 0 */
end_comment

begin_comment
comment|/* 0x18 - 0x38, Statistics Counters. */
end_comment

begin_define
define|#
directive|define
name|STATS_A_MAC_ID_0
value|0x18
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_MAC_ID_1
value|0x19
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_FRAMES_TX_OK
value|0x1A
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_FRAMES_RX_OK
value|0x1B
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_FCS_ERRORS
value|0x1C
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_ALIGNMENT_ERRORS
value|0x1D
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_OCTETS_TX_OK
value|0x1E
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_OCTETS_RX_OK
value|0x1F
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_TX_PAUSE_MAX_CTRL_FRAME
value|0x20
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_A_RX_PAUSE_MAX_CTRL_FRAME
value|0x21
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_IN_ERRORS
value|0x22
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_OUT_ERRORS
value|0x23
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_IN_UCAST_PKTS
value|0x24
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_IN_MULTICAST_PKTS
value|0x25
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_IN_BROADCAST_PKTS
value|0x26
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_OUT_DISCARDS
value|0x27
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_OUT_UCAST_PKTS
value|0x28
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_OUT_MULTICAST_PKTS
value|0x29
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_IF_OUT_BROADCAST_PKTS
value|0x2A
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_DROP_EVENT
value|0x2B
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_OCTETS
value|0x2C
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS
value|0x2D
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_USIZE_PKTS
value|0x2E
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_OSIZE_PKTS
value|0x2F
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_64_OCTETS
value|0x30
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_65_TO_127_OCTETS
value|0x31
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_128_TO_255_OCTETS
value|0x32
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_256_TO_511_OCTETS
value|0x33
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_512_TO_1023_OCTETS
value|0x34
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_1024_TO_1518_OCTETS
value|0x35
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_PKTS_1519_TO_X_OCTETS
value|0x36
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_JABBERS
value|0x37
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|STATS_ETHER_STATS_FRAGMENTS
value|0x38
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* 0x39, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_comment
comment|/* 0x3A, Transmit Command. */
end_comment

begin_define
define|#
directive|define
name|TX_CMD_STAT
value|0x3A
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|TX_CMD_STAT_OMIT_CRC
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|TX_CMD_STAT_TX_SHIFT16
value|(1<<18)
end_define

begin_comment
comment|/* 0x3B, Receive Command. */
end_comment

begin_define
define|#
directive|define
name|RX_CMD_STAT
value|0x3B
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|RX_CMD_STAT_RX_SHIFT16
value|(1<<25)
end_define

begin_comment
comment|/* 0x3C - 0x3E, Extended Statistics Counters. */
end_comment

begin_define
define|#
directive|define
name|ESTATS_MSB_A_OCTETS_TX_OK
value|0x3C
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|ESTATS_MSB_A_OCTETS_RX_OK
value|0x3D
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|ESTATS_MSB_ETHER_STATS_OCTETS
value|0x3E
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* 0x3F, Reserved. */
end_comment

begin_comment
comment|/* 0x40 - 0x7F, Multicast Hash Table. */
end_comment

begin_define
define|#
directive|define
name|MHASH_START
value|0x40
end_define

begin_define
define|#
directive|define
name|MHASH_LEN
value|0x3F
end_define

begin_comment
comment|/* 0x80 - 0x9F, MDIO Space 0 or PCS Function Configuration. */
end_comment

begin_define
define|#
directive|define
name|MDIO_0_START
value|0x80
end_define

begin_comment
comment|/* The following are offsets to the first PCS register at 0x80. */
end_comment

begin_comment
comment|/* See sys/dev/mii/mii.h. */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL
value|0x00
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Bits 0:4, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_UNIDIRECTIONAL_ENABLE
value|(1<<5)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_SPEED_SELECTION
value|(1<<6|1<<13)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_COLLISION_TEST
value|(1<<7)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_DUPLEX_MODE
value|(1<<8)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_RESTART_AUTO_NEGOTIATION
value|(1<<9)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_ISOLATE
value|(1<<10)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_POWERDOWN
value|(1<<11)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_AUTO_NEGOTIATION_ENABLE
value|(1<<12)
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* See bit 6 above. */
end_comment

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_LOOPBACK
value|(1<<14)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_CONTROL_RESET
value|(1<<15)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS
value|0x01
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_EXTENDED_CAPABILITY
value|(1<<0)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_JABBER_DETECT
value|(1<<1)
end_define

begin_comment
comment|/* -, 0 */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_LINK_STATUS
value|(1<<2)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_AUTO_NEGOTIATION_ABILITY
value|(1<<3)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_REMOTE_FAULT
value|(1<<4)
end_define

begin_comment
comment|/* -, 0 */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_AUTO_NEGOTIATION_COMPLETE
value|(1<<5)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_MF_PREAMBLE_SUPPRESSION
value|(1<<6)
end_define

begin_comment
comment|/* -, 0 */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_UNIDIRECTIONAL_ABILITY
value|(1<<7)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_EXTENDED_STATUS
value|(1<<8)
end_define

begin_comment
comment|/* -, 0 */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_100BASET2_HALF_DUPLEX
value|(1<<9)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_100BASET2_FULL_DUPLEX
value|(1<<10)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_10MBPS_HALF_DUPLEX
value|(1<<11)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_10MBPS_FULL_DUPLEX
value|(1<<12)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_100BASE_X_HALF_DUPLEX
value|(1<<13)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_100BASE_X_FULL_DUPLEX
value|(1<<14)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_STATUS_100BASE_T4
value|(1<<15)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PHY_IDENTIFIER_0
value|0x02
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PHY_IDENTIFIER_1
value|0x03
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY
value|0x04
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* 1000BASE-X */
end_comment

begin_comment
comment|/* Bits 0:4, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_FD
value|(1<<5)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_HD
value|(1<<6)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_PS1
value|(1<<7)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_PS2
value|(1<<8)
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Bits 9:11, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_RF1
value|(1<<12)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_RF2
value|(1<<13)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_ACK
value|(1<<14)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_DEV_ABILITY_1000BASE_X_NP
value|(1<<15)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY
value|0x05
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* 1000BASE-X */
end_comment

begin_comment
comment|/* Bits 0:4, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_FD
value|(1<<5)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_HD
value|(1<<6)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_PS1
value|(1<<7)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_PS2
value|(1<<8)
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Bits 9:11, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_RF1
value|(1<<12)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_RF2
value|(1<<13)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_ACK
value|(1<<14)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_1000BASE_X_NP
value|(1<<15)
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* SGMII */
end_comment

begin_comment
comment|/* Bits 0:9, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_SGMII_COPPER_SPEED0
value|(1<<10)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_SGMII_COPPER_SPEED1
value|(1<<11)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_SGMII_COPPER_DUPLEX_STATUS
value|(1<<12)
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Bit 13, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_SGMII_ACK
value|(1<<14)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_ABILITY_SGMII_COPPER_LINK_STATUS
value|(1<<15)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_AN_EXPANSION
value|0x06
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_AN_EXPANSION_LINK_PARTNER_AUTO_NEGOTIATION_ABLE
value|(1<<0)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_AN_EXPANSION_PAGE_RECEIVE
value|(1<<1)
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_AN_EXPANSION_NEXT_PAGE_ABLE
value|(1<<2)
end_define

begin_comment
comment|/* -, 0 */
end_comment

begin_comment
comment|/* Bits 3:15, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_DEVICE_NEXT_PAGE
value|0x07
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_PARTNER_NEXT_PAGE
value|0x08
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_MASTER_SLAVE_CNTL
value|0x09
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_MASTER_SLAVE_STAT
value|0x0A
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* 0x0B - 0x0E, Reserved */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_EXTENDED_STATUS
value|0x0F
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Specific Extended Registers. */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_SCRATCH
value|0x10
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_REV
value|0x11
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_LINK_TIMER_0
value|0x12
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_LINK_TIMER_1
value|0x13
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE
value|0x14
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE_SGMII_ENA
value|(1<<0)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE_USE_SGMII_AN
value|(1<<1)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE_SGMII_SPEED1
value|(1<<2)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE_SGMII_SPEED0
value|(1<<3)
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_IF_MODE_SGMII_DUPLEX
value|(1<<4)
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Bits 5:15, Reserved. */
end_comment

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_DISABLE_READ_TIMEOUT
value|0x15
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|PCS_EXT_READ_TIMEOUT
value|0x16
end_define

begin_comment
comment|/* r0 */
end_comment

begin_comment
comment|/* 0x17-0x1F, Reserved. */
end_comment

begin_comment
comment|/* 0xA0 - 0xBF, MDIO Space 1. */
end_comment

begin_define
define|#
directive|define
name|MDIO_1_START
value|0xA0
end_define

begin_define
define|#
directive|define
name|ATSE_BMCR
value|MDIO_1_START
end_define

begin_comment
comment|/* 0xC0 - 0xC7, Supplementary Address. */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_0_0
value|0xC0
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_0_1
value|0xC1
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_1_0
value|0xC2
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_1_1
value|0xC3
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_2_0
value|0xC4
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_2_1
value|0xC5
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_3_0
value|0xC6
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SUPPL_ADDR_SMAC_3_1
value|0xC7
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* 0xC8 - 0xCF, Reserved; set to zero, ignore on read. */
end_comment

begin_comment
comment|/* 0xD7 - 0xFF, Reserved; set to zero, ignore on read. */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* DE4 Intel Strata Flash Ethernet Option Bits area. */
end_comment

begin_comment
comment|/* XXX-BZ this is something a loader will have to handle for us. */
end_comment

begin_define
define|#
directive|define
name|ALTERA_ETHERNET_OPTION_BITS_OFF
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ALTERA_ETHERNET_OPTION_BITS_LEN
value|0x00007fff
end_define

begin_comment
comment|/* -------------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atse_softc
block|{
name|struct
name|ifnet
modifier|*
name|atse_ifp
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|atse_rx_m
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|atse_tx_m
decl_stmt|;
name|uint8_t
modifier|*
name|atse_tx_buf
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_rx_irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_rx_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_rxc_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_tx_irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_tx_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|atse_txc_mem_res
decl_stmt|;
name|device_t
name|atse_miibus
decl_stmt|;
name|device_t
name|atse_dev
decl_stmt|;
name|int
name|atse_unit
decl_stmt|;
name|int
name|atse_mem_rid
decl_stmt|;
name|int
name|atse_rx_irq_rid
decl_stmt|;
name|int
name|atse_rx_mem_rid
decl_stmt|;
name|int
name|atse_rxc_mem_rid
decl_stmt|;
name|int
name|atse_tx_irq_rid
decl_stmt|;
name|int
name|atse_tx_mem_rid
decl_stmt|;
name|int
name|atse_txc_mem_rid
decl_stmt|;
name|int
name|atse_phy_addr
decl_stmt|;
name|int
name|atse_if_flags
decl_stmt|;
name|int
name|atse_rx_irq
decl_stmt|;
name|int
name|atse_tx_irq
decl_stmt|;
name|u_long
name|atse_rx_maddr
decl_stmt|;
name|u_long
name|atse_rx_msize
decl_stmt|;
name|u_long
name|atse_tx_maddr
decl_stmt|;
name|u_long
name|atse_tx_msize
decl_stmt|;
name|u_long
name|atse_rxc_maddr
decl_stmt|;
name|u_long
name|atse_rxc_msize
decl_stmt|;
name|u_long
name|atse_txc_maddr
decl_stmt|;
name|u_long
name|atse_txc_msize
decl_stmt|;
name|void
modifier|*
name|atse_rx_intrhand
decl_stmt|;
name|void
modifier|*
name|atse_tx_intrhand
decl_stmt|;
name|bus_addr_t
name|atse_bmcr0
decl_stmt|;
name|bus_addr_t
name|atse_bmcr1
decl_stmt|;
name|uint32_t
name|atse_flags
decl_stmt|;
define|#
directive|define
name|ATSE_FLAGS_LINK
value|0x00000001
define|#
directive|define
name|ATSE_FLAGS_ERROR
value|0x00000002
define|#
directive|define
name|ATSE_FLAGS_SOP_SEEN
value|0x00000004
name|uint8_t
name|atse_eth_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
define|#
directive|define
name|ATSE_ETH_ADDR_DEF
value|0x01
define|#
directive|define
name|ATSE_ETH_ADDR_SUPP1
value|0x02
define|#
directive|define
name|ATSE_ETH_ADDR_SUPP2
value|0x04
define|#
directive|define
name|ATSE_ETH_ADDR_SUPP3
value|0x08
define|#
directive|define
name|ATSE_ETH_ADDR_SUPP4
value|0x10
define|#
directive|define
name|ATSE_ETH_ADDR_ALL
value|0x1f
name|uint16_t
name|atse_watchdog_timer
decl_stmt|;
name|uint16_t
name|atse_tx_m_offset
decl_stmt|;
name|uint16_t
name|atse_tx_buf_len
decl_stmt|;
name|uint16_t
name|atse_rx_buf_len
decl_stmt|;
name|int16_t
name|atse_rx_cycles
decl_stmt|;
comment|/* POLLING */
define|#
directive|define
name|RX_CYCLES_IN_INTR
value|5
name|uint32_t
name|atse_rx_err
index|[
literal|6
index|]
decl_stmt|;
define|#
directive|define
name|ATSE_RX_ERR_FIFO_THRES_EOP
value|0
comment|/* FIFO threshold reached, on EOP. */
define|#
directive|define
name|ATSE_RX_ERR_ELEN
value|1
comment|/* Frame/payload length not valid. */
define|#
directive|define
name|ATSE_RX_ERR_CRC32
value|2
comment|/* CRC-32 error. */
define|#
directive|define
name|ATSE_RX_ERR_FIFO_THRES_TRUNC
value|3
comment|/* FIFO thresh., truncated frame. */
define|#
directive|define
name|ATSE_RX_ERR_4
value|4
comment|/* ? */
define|#
directive|define
name|ATSE_RX_ERR_5
value|5
comment|/* / */
define|#
directive|define
name|ATSE_RX_ERR_MAX
value|6
name|struct
name|callout
name|atse_tick
decl_stmt|;
name|struct
name|mtx
name|atse_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|atse_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atse_detach_dev
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atse_detach_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atse_miibus_readreg
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atse_miibus_writereg
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atse_miibus_statchg
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|atse_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IF_ATSEREG_H */
end_comment

begin_comment
comment|/* end */
end_comment

end_unit

