begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_txpreg.h,v 1.30 2001/06/23 04:18:02 jason Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Aaron Campbell<aaron@monkey.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Aaron Campbell.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|TXP_PCI_LOMEM
value|0x14
end_define

begin_comment
comment|/* pci conf, memory map BAR */
end_comment

begin_define
define|#
directive|define
name|TXP_PCI_LOIO
value|0x10
end_define

begin_comment
comment|/* pci conf, IO map BAR */
end_comment

begin_define
define|#
directive|define
name|TXP_PCI_INTLINE
value|0x3C
end_define

begin_comment
comment|/*  * Typhoon registers.  */
end_comment

begin_define
define|#
directive|define
name|TXP_SRR
value|0x00
end_define

begin_comment
comment|/* soft reset register */
end_comment

begin_define
define|#
directive|define
name|TXP_ISR
value|0x04
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|TXP_IER
value|0x08
end_define

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|TXP_IMR
value|0x0c
end_define

begin_comment
comment|/* interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|TXP_SIR
value|0x10
end_define

begin_comment
comment|/* self interrupt register */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_7
value|0x14
end_define

begin_comment
comment|/* host->arm comm 7 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_6
value|0x18
end_define

begin_comment
comment|/* host->arm comm 6 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_5
value|0x1c
end_define

begin_comment
comment|/* host->arm comm 5 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_4
value|0x20
end_define

begin_comment
comment|/* host->arm comm 4 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_3
value|0x24
end_define

begin_comment
comment|/* host->arm comm 3 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_2
value|0x28
end_define

begin_comment
comment|/* host->arm comm 2 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_1
value|0x2c
end_define

begin_comment
comment|/* host->arm comm 1 */
end_comment

begin_define
define|#
directive|define
name|TXP_H2A_0
value|0x30
end_define

begin_comment
comment|/* host->arm comm 0 */
end_comment

begin_define
define|#
directive|define
name|TXP_A2H_3
value|0x34
end_define

begin_comment
comment|/* arm->host comm 3 */
end_comment

begin_define
define|#
directive|define
name|TXP_A2H_2
value|0x38
end_define

begin_comment
comment|/* arm->host comm 2 */
end_comment

begin_define
define|#
directive|define
name|TXP_A2H_1
value|0x3c
end_define

begin_comment
comment|/* arm->host comm 1 */
end_comment

begin_define
define|#
directive|define
name|TXP_A2H_0
value|0x40
end_define

begin_comment
comment|/* arm->host comm 0 */
end_comment

begin_comment
comment|/*  * interrupt bits (IMR, ISR, IER)  */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_RESERVED
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|TXP_INT_A2H_7
value|0x00008000
end_define

begin_comment
comment|/* arm->host comm 7 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_6
value|0x00004000
end_define

begin_comment
comment|/* arm->host comm 6 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_5
value|0x00002000
end_define

begin_comment
comment|/* arm->host comm 5 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_4
value|0x00001000
end_define

begin_comment
comment|/* arm->host comm 4 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_SELF
value|0x00000800
end_define

begin_comment
comment|/* self interrupt */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_PCI_TABORT
value|0x00000400
end_define

begin_comment
comment|/* pci target abort */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_PCI_MABORT
value|0x00000200
end_define

begin_comment
comment|/* pci master abort */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_DMA3
value|0x00000100
end_define

begin_comment
comment|/* dma3 done */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_DMA2
value|0x00000080
end_define

begin_comment
comment|/* dma2 done */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_DMA1
value|0x00000040
end_define

begin_comment
comment|/* dma1 done */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_DMA0
value|0x00000020
end_define

begin_comment
comment|/* dma0 done */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_3
value|0x00000010
end_define

begin_comment
comment|/* arm->host comm 3 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_2
value|0x00000008
end_define

begin_comment
comment|/* arm->host comm 2 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_1
value|0x00000004
end_define

begin_comment
comment|/* arm->host comm 1 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_A2H_0
value|0x00000002
end_define

begin_comment
comment|/* arm->host comm 0 */
end_comment

begin_define
define|#
directive|define
name|TXP_INT_LATCH
value|0x00000001
end_define

begin_comment
comment|/* interrupt latch */
end_comment

begin_comment
comment|/*  * soft reset register (SRR)  */
end_comment

begin_define
define|#
directive|define
name|TXP_SRR_ALL
value|0x0000007f
end_define

begin_comment
comment|/* full reset */
end_comment

begin_comment
comment|/*  * Typhoon boot commands.  */
end_comment

begin_define
define|#
directive|define
name|TXP_BOOTCMD_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|TXP_BOOTCMD_DOWNLOAD_COMPLETE
value|0xfb
end_define

begin_define
define|#
directive|define
name|TXP_BOOTCMD_SEGMENT_AVAILABLE
value|0xfc
end_define

begin_define
define|#
directive|define
name|TXP_BOOTCMD_RUNTIME_IMAGE
value|0xfd
end_define

begin_define
define|#
directive|define
name|TXP_BOOTCMD_REGISTER_BOOT_RECORD
value|0xff
end_define

begin_comment
comment|/*  * Typhoon runtime commands.  */
end_comment

begin_define
define|#
directive|define
name|TXP_CMD_GLOBAL_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|TXP_CMD_TX_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|TXP_CMD_TX_DISABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RX_ENABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RX_DISABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RX_FILTER_WRITE
value|0x05
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RX_FILTER_READ
value|0x06
end_define

begin_define
define|#
directive|define
name|TXP_CMD_READ_STATISTICS
value|0x07
end_define

begin_define
define|#
directive|define
name|TXP_CMD_CYCLE_STATISTICS
value|0x08
end_define

begin_define
define|#
directive|define
name|TXP_CMD_CLEAR_STATISTICS
value|0x09
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MEMORY_READ
value|0x0a
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MEMORY_WRITE_SINGLE
value|0x0b
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VARIABLE_SECTION_READ
value|0x0c
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VARIABLE_SECTION_WRITE
value|0x0d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATIC_SECTION_READ
value|0x0e
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATIC_SECTION_WRITE
value|0x0f
end_define

begin_define
define|#
directive|define
name|TXP_CMD_IMAGE_SECTION_PROGRAM
value|0x10
end_define

begin_define
define|#
directive|define
name|TXP_CMD_NVRAM_PAGE_READ
value|0x11
end_define

begin_define
define|#
directive|define
name|TXP_CMD_NVRAM_PAGE_WRITE
value|0x12
end_define

begin_define
define|#
directive|define
name|TXP_CMD_XCVR_SELECT
value|0x13
end_define

begin_define
define|#
directive|define
name|TXP_CMD_TEST_MUX
value|0x14
end_define

begin_define
define|#
directive|define
name|TXP_CMD_PHYLOOPBACK_ENABLE
value|0x15
end_define

begin_define
define|#
directive|define
name|TXP_CMD_PHYLOOPBACK_DISABLE
value|0x16
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MAC_CONTROL_READ
value|0x17
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MAC_CONTROL_WRITE
value|0x18
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MAX_PKT_SIZE_READ
value|0x19
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MAX_PKT_SIZE_WRITE
value|0x1a
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MEDIA_STATUS_READ
value|0x1b
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MEDIA_STATUS_WRITE
value|0x1c
end_define

begin_define
define|#
directive|define
name|TXP_CMD_NETWORK_DIAGS_READ
value|0x1d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_NETWORK_DIAGS_WRITE
value|0x1e
end_define

begin_define
define|#
directive|define
name|TXP_CMD_PHY_MGMT_READ
value|0x1f
end_define

begin_define
define|#
directive|define
name|TXP_CMD_PHY_MGMT_WRITE
value|0x20
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VARIABLE_PARAMETER_READ
value|0x21
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VARIABLE_PARAMETER_WRITE
value|0x22
end_define

begin_define
define|#
directive|define
name|TXP_CMD_GOTO_SLEEP
value|0x23
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FIREWALL_CONTROL
value|0x24
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MCAST_HASH_MASK_WRITE
value|0x25
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATION_ADDRESS_WRITE
value|0x26
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATION_ADDRESS_READ
value|0x27
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATION_MASK_WRITE
value|0x28
end_define

begin_define
define|#
directive|define
name|TXP_CMD_STATION_MASK_READ
value|0x29
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VLAN_ETHER_TYPE_READ
value|0x2a
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VLAN_ETHER_TYPE_WRITE
value|0x2b
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VLAN_MASK_READ
value|0x2c
end_define

begin_define
define|#
directive|define
name|TXP_CMD_VLAN_MASK_WRITE
value|0x2d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_BCAST_THROTTLE_WRITE
value|0x2e
end_define

begin_define
define|#
directive|define
name|TXP_CMD_BCAST_THROTTLE_READ
value|0x2f
end_define

begin_define
define|#
directive|define
name|TXP_CMD_DHCP_PREVENT_WRITE
value|0x30
end_define

begin_define
define|#
directive|define
name|TXP_CMD_DHCP_PREVENT_READ
value|0x31
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RECV_BUFFER_CONTROL
value|0x32
end_define

begin_define
define|#
directive|define
name|TXP_CMD_SOFTWARE_RESET
value|0x33
end_define

begin_define
define|#
directive|define
name|TXP_CMD_CREATE_SA
value|0x34
end_define

begin_define
define|#
directive|define
name|TXP_CMD_DELETE_SA
value|0x35
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ENABLE_RX_IP_OPTION
value|0x36
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RANDOM_NUMBER_CONTROL
value|0x37
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RANDOM_NUMBER_READ
value|0x38
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MATRIX_TABLE_MODE_WRITE
value|0x39
end_define

begin_define
define|#
directive|define
name|TXP_CMD_MATRIX_DETAIL_READ
value|0x3a
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_ARRAY_READ
value|0x3b
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_DETAIL_READ
value|0x3c
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_TABLE_MODE_WRITE
value|0x3d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_TCL_WRITE
value|0x3e
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_TBL_READ
value|0x3f
end_define

begin_define
define|#
directive|define
name|TXP_CMD_FILTER_DEFINE
value|0x45
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ADD_WAKEUP_PKT
value|0x46
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ADD_SLEEP_PKT
value|0x47
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ENABLE_SLEEP_EVENTS
value|0x48
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ENABLE_WAKEUP_EVENTS
value|0x49
end_define

begin_define
define|#
directive|define
name|TXP_CMD_GET_IP_ADDRESS
value|0x4a
end_define

begin_define
define|#
directive|define
name|TXP_CMD_READ_PCI_REG
value|0x4c
end_define

begin_define
define|#
directive|define
name|TXP_CMD_WRITE_PCI_REG
value|0x4d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_OFFLOAD_READ
value|0x4e
end_define

begin_define
define|#
directive|define
name|TXP_CMD_OFFLOAD_WRITE
value|0x4f
end_define

begin_define
define|#
directive|define
name|TXP_CMD_HELLO_RESPONSE
value|0x57
end_define

begin_define
define|#
directive|define
name|TXP_CMD_ENABLE_RX_FILTER
value|0x58
end_define

begin_define
define|#
directive|define
name|TXP_CMD_RX_FILTER_CAPABILITY
value|0x59
end_define

begin_define
define|#
directive|define
name|TXP_CMD_HALT
value|0x5d
end_define

begin_define
define|#
directive|define
name|TXP_CMD_READ_IPSEC_INFO
value|0x54
end_define

begin_define
define|#
directive|define
name|TXP_CMD_GET_IPSEC_ENABLE
value|0x67
end_define

begin_define
define|#
directive|define
name|TXP_CMD_INVALID
value|0xffff
end_define

begin_define
define|#
directive|define
name|TXP_FRAGMENT
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_TXFRAME
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_COMMAND
value|0x0002
end_define

begin_define
define|#
directive|define
name|TXP_OPTION
value|0x0003
end_define

begin_define
define|#
directive|define
name|TXP_RECEIVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|TXP_RESPONSE
value|0x0005
end_define

begin_define
define|#
directive|define
name|TXP_TYPE_IPSEC
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_TYPE_TCPSEGMENT
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_NOCRC
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_IPCKSUM
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_TCPCKSUM
value|0x0002
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_TCPSEGMENT
value|0x0004
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_INSERTVLAN
value|0x0008
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_IPSEC
value|0x0010
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_PRIORITY
value|0x0020
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_UDPCKSUM
value|0x0040
end_define

begin_define
define|#
directive|define
name|TXP_PFLAG_PADFRAME
value|0x0080
end_define

begin_define
define|#
directive|define
name|TXP_MISC_FIRSTDESC
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_MISC_LASTDESC
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_ERR_INTERNAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_ERR_FIFOUNDERRUN
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_ERR_BADSSD
value|0x0002
end_define

begin_define
define|#
directive|define
name|TXP_ERR_RUNT
value|0x0003
end_define

begin_define
define|#
directive|define
name|TXP_ERR_CRC
value|0x0004
end_define

begin_define
define|#
directive|define
name|TXP_ERR_OVERSIZE
value|0x0005
end_define

begin_define
define|#
directive|define
name|TXP_ERR_ALIGNMENT
value|0x0006
end_define

begin_define
define|#
directive|define
name|TXP_ERR_DRIBBLEBIT
value|0x0007
end_define

begin_define
define|#
directive|define
name|TXP_PROTO_UNKNOWN
value|0x0000
end_define

begin_define
define|#
directive|define
name|TXP_PROTO_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_PROTO_IPX
value|0x0002
end_define

begin_define
define|#
directive|define
name|TXP_PROTO_RESERVED
value|0x0003
end_define

begin_define
define|#
directive|define
name|TXP_STAT_PROTO
value|0x0001
end_define

begin_define
define|#
directive|define
name|TXP_STAT_VLAN
value|0x0002
end_define

begin_define
define|#
directive|define
name|TXP_STAT_IPFRAGMENT
value|0x0004
end_define

begin_define
define|#
directive|define
name|TXP_STAT_IPSEC
value|0x0008
end_define

begin_define
define|#
directive|define
name|TXP_STAT_IPCKSUMBAD
value|0x0010
end_define

begin_define
define|#
directive|define
name|TXP_STAT_TCPCKSUMBAD
value|0x0020
end_define

begin_define
define|#
directive|define
name|TXP_STAT_UDPCKSUMBAD
value|0x0040
end_define

begin_define
define|#
directive|define
name|TXP_STAT_IPCKSUMGOOD
value|0x0080
end_define

begin_define
define|#
directive|define
name|TXP_STAT_TCPCKSUMGOOD
value|0x0100
end_define

begin_define
define|#
directive|define
name|TXP_STAT_UDPCKSUMGOOD
value|0x0200
end_define

begin_struct
struct|struct
name|txp_tx_desc
block|{
specifier|volatile
name|u_int8_t
name|tx_flags
decl_stmt|;
comment|/* type/descriptor flags */
specifier|volatile
name|u_int8_t
name|tx_numdesc
decl_stmt|;
comment|/* number of descriptors */
specifier|volatile
name|u_int16_t
name|tx_totlen
decl_stmt|;
comment|/* total packet length */
specifier|volatile
name|u_int32_t
name|tx_addrlo
decl_stmt|;
comment|/* virt addr low word */
specifier|volatile
name|u_int32_t
name|tx_addrhi
decl_stmt|;
comment|/* virt addr high word */
specifier|volatile
name|u_int32_t
name|tx_pflags
decl_stmt|;
comment|/* processing flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_M
value|0x07
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_FRAG
value|0x00
end_define

begin_comment
comment|/* type: fragment */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* type: data frame */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_CMD
value|0x02
end_define

begin_comment
comment|/* type: command frame */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_OPT
value|0x03
end_define

begin_comment
comment|/* type: options */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_RX
value|0x04
end_define

begin_comment
comment|/* type: command */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_TYPE_RESP
value|0x05
end_define

begin_comment
comment|/* type: response */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_RESP
value|0x40
end_define

begin_comment
comment|/* response requested */
end_comment

begin_define
define|#
directive|define
name|TX_FLAGS_VALID
value|0x80
end_define

begin_comment
comment|/* valid descriptor */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_DNAC
value|0x00000001
end_define

begin_comment
comment|/* do not add crc */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_IPCKSUM
value|0x00000002
end_define

begin_comment
comment|/* ip checksum */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_TCPCKSUM
value|0x00000004
end_define

begin_comment
comment|/* tcp checksum */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_TCPSEG
value|0x00000008
end_define

begin_comment
comment|/* tcp segmentation */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_VLAN
value|0x00000010
end_define

begin_comment
comment|/* insert vlan */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_IPSEC
value|0x00000020
end_define

begin_comment
comment|/* perform ipsec */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_PRIO
value|0x00000040
end_define

begin_comment
comment|/* priority field valid */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_UDPCKSUM
value|0x00000080
end_define

begin_comment
comment|/* udp checksum */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_PADFRAME
value|0x00000100
end_define

begin_comment
comment|/* pad frame */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_VLANTAG_M
value|0x0ffff000
end_define

begin_comment
comment|/* vlan tag mask */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_VLANPRI_M
value|0x00700000
end_define

begin_comment
comment|/* vlan priority mask */
end_comment

begin_define
define|#
directive|define
name|TX_PFLAGS_VLANTAG_S
value|12
end_define

begin_comment
comment|/* amount to shift tag */
end_comment

begin_struct
struct|struct
name|txp_rx_desc
block|{
specifier|volatile
name|u_int8_t
name|rx_flags
decl_stmt|;
comment|/* type/descriptor flags */
specifier|volatile
name|u_int8_t
name|rx_numdesc
decl_stmt|;
comment|/* number of descriptors */
specifier|volatile
name|u_int16_t
name|rx_len
decl_stmt|;
comment|/* frame length */
ifdef|#
directive|ifdef
name|notdef
specifier|volatile
name|u_int32_t
name|rx_vaddrlo
decl_stmt|;
comment|/* virtual address, lo word */
specifier|volatile
name|u_int32_t
name|rx_vaddrhi
decl_stmt|;
comment|/* virtual address, hi word */
endif|#
directive|endif
union|union
block|{
name|struct
name|txp_swdesc
modifier|*
name|rx_sd
decl_stmt|;
name|u_int64_t
name|rx_dummy
decl_stmt|;
block|}
name|txp_rx_u
union|;
specifier|volatile
name|u_int32_t
name|rx_stat
decl_stmt|;
comment|/* status */
specifier|volatile
name|u_int16_t
name|rx_filter
decl_stmt|;
comment|/* filter status */
specifier|volatile
name|u_int16_t
name|rx_hash
decl_stmt|;
comment|/* hash status */
specifier|volatile
name|u_int32_t
name|rx_vlan
decl_stmt|;
comment|/* vlan tag/priority */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rx_sd
value|txp_rx_u.rx_sd
end_define

begin_comment
comment|/* txp_rx_desc.rx_flags */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_M
value|0x07
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_FRAG
value|0x00
end_define

begin_comment
comment|/* type: fragment */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* type: data frame */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_CMD
value|0x02
end_define

begin_comment
comment|/* type: command frame */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_OPT
value|0x03
end_define

begin_comment
comment|/* type: options */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_RX
value|0x04
end_define

begin_comment
comment|/* type: command */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_TYPE_RESP
value|0x05
end_define

begin_comment
comment|/* type: response */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_RCV_TYPE_M
value|0x18
end_define

begin_comment
comment|/* rcvtype mask */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_RCV_TYPE_RX
value|0x00
end_define

begin_comment
comment|/* rcvtype: receive */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_RCV_TYPE_RSP
value|0x08
end_define

begin_comment
comment|/* rcvtype: response */
end_comment

begin_define
define|#
directive|define
name|RX_FLAGS_ERROR
value|0x40
end_define

begin_comment
comment|/* error in packet */
end_comment

begin_comment
comment|/* txp_rx_desc.rx_stat (if rx_flags& RX_FLAGS_ERROR bit set) */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_ADAPTER
value|0x00000000
end_define

begin_comment
comment|/* adapter internal error */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_FIFO
value|0x00000001
end_define

begin_comment
comment|/* fifo underrun */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_BADSSD
value|0x00000002
end_define

begin_comment
comment|/* bad ssd */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_RUNT
value|0x00000003
end_define

begin_comment
comment|/* runt packet */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_CRC
value|0x00000004
end_define

begin_comment
comment|/* bad crc */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_OVERSIZE
value|0x00000005
end_define

begin_comment
comment|/* oversized packet */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_ALIGN
value|0x00000006
end_define

begin_comment
comment|/* alignment error */
end_comment

begin_define
define|#
directive|define
name|RX_ERROR_DRIBBLE
value|0x00000007
end_define

begin_comment
comment|/* dribble bit */
end_comment

begin_comment
comment|/* txp_rx_desc.rx_stat (if rx_flags& RX_FLAGS_ERROR not bit set) */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_PROTO_M
value|0x00000003
end_define

begin_comment
comment|/* protocol mask */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_PROTO_UK
value|0x00000000
end_define

begin_comment
comment|/* unknown protocol */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_PROTO_IPX
value|0x00000001
end_define

begin_comment
comment|/* IPX */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_PROTO_IP
value|0x00000002
end_define

begin_comment
comment|/* IP */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_PROTO_RSV
value|0x00000003
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_VLAN
value|0x00000004
end_define

begin_comment
comment|/* vlan tag (in rxd) */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_IPFRAG
value|0x00000008
end_define

begin_comment
comment|/* fragment, ipsec not done */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_IPSEC
value|0x00000010
end_define

begin_comment
comment|/* ipsec decoded packet */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_IPCKSUMBAD
value|0x00000020
end_define

begin_comment
comment|/* ip checksum failed */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_UDPCKSUMBAD
value|0x00000040
end_define

begin_comment
comment|/* udp checksum failed */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_TCPCKSUMBAD
value|0x00000080
end_define

begin_comment
comment|/* tcp checksum failed */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_IPCKSUMGOOD
value|0x00000100
end_define

begin_comment
comment|/* ip checksum succeeded */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_UDPCKSUMGOOD
value|0x00000200
end_define

begin_comment
comment|/* udp checksum succeeded */
end_comment

begin_define
define|#
directive|define
name|RX_STAT_TCPCKSUMGOOD
value|0x00000400
end_define

begin_comment
comment|/* tcp checksum succeeded */
end_comment

begin_struct
struct|struct
name|txp_rxbuf_desc
block|{
specifier|volatile
name|u_int32_t
name|rb_paddrlo
decl_stmt|;
specifier|volatile
name|u_int32_t
name|rb_paddrhi
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
specifier|volatile
name|u_int32_t
name|rb_vaddrlo
decl_stmt|;
specifier|volatile
name|u_int32_t
name|rb_vaddrhi
decl_stmt|;
endif|#
directive|endif
union|union
block|{
name|struct
name|txp_swdesc
modifier|*
name|rb_sd
decl_stmt|;
name|u_int64_t
name|rb_dummy
decl_stmt|;
block|}
name|txp_rb_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rb_sd
value|txp_rb_u.rb_sd
end_define

begin_comment
comment|/* Extension descriptor */
end_comment

begin_struct
struct|struct
name|txp_ext_desc
block|{
specifier|volatile
name|u_int32_t
name|ext_1
decl_stmt|;
specifier|volatile
name|u_int32_t
name|ext_2
decl_stmt|;
specifier|volatile
name|u_int32_t
name|ext_3
decl_stmt|;
specifier|volatile
name|u_int32_t
name|ext_4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_cmd_desc
block|{
specifier|volatile
name|u_int8_t
name|cmd_flags
decl_stmt|;
specifier|volatile
name|u_int8_t
name|cmd_numdesc
decl_stmt|;
specifier|volatile
name|u_int16_t
name|cmd_id
decl_stmt|;
specifier|volatile
name|u_int16_t
name|cmd_seq
decl_stmt|;
specifier|volatile
name|u_int16_t
name|cmd_par1
decl_stmt|;
specifier|volatile
name|u_int32_t
name|cmd_par2
decl_stmt|;
specifier|volatile
name|u_int32_t
name|cmd_par3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_M
value|0x07
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_FRAG
value|0x00
end_define

begin_comment
comment|/* type: fragment */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* type: data frame */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_CMD
value|0x02
end_define

begin_comment
comment|/* type: command frame */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_OPT
value|0x03
end_define

begin_comment
comment|/* type: options */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_RX
value|0x04
end_define

begin_comment
comment|/* type: command */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_TYPE_RESP
value|0x05
end_define

begin_comment
comment|/* type: response */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_RESP
value|0x40
end_define

begin_comment
comment|/* response requested */
end_comment

begin_define
define|#
directive|define
name|CMD_FLAGS_VALID
value|0x80
end_define

begin_comment
comment|/* valid descriptor */
end_comment

begin_struct
struct|struct
name|txp_rsp_desc
block|{
specifier|volatile
name|u_int8_t
name|rsp_flags
decl_stmt|;
specifier|volatile
name|u_int8_t
name|rsp_numdesc
decl_stmt|;
specifier|volatile
name|u_int16_t
name|rsp_id
decl_stmt|;
specifier|volatile
name|u_int16_t
name|rsp_seq
decl_stmt|;
specifier|volatile
name|u_int16_t
name|rsp_par1
decl_stmt|;
specifier|volatile
name|u_int32_t
name|rsp_par2
decl_stmt|;
specifier|volatile
name|u_int32_t
name|rsp_par3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_M
value|0x07
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_FRAG
value|0x00
end_define

begin_comment
comment|/* type: fragment */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* type: data frame */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_CMD
value|0x02
end_define

begin_comment
comment|/* type: command frame */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_OPT
value|0x03
end_define

begin_comment
comment|/* type: options */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_RX
value|0x04
end_define

begin_comment
comment|/* type: command */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_TYPE_RESP
value|0x05
end_define

begin_comment
comment|/* type: response */
end_comment

begin_define
define|#
directive|define
name|RSP_FLAGS_ERROR
value|0x40
end_define

begin_comment
comment|/* response error */
end_comment

begin_struct
struct|struct
name|txp_frag_desc
block|{
specifier|volatile
name|u_int8_t
name|frag_flags
decl_stmt|;
comment|/* type/descriptor flags */
specifier|volatile
name|u_int8_t
name|frag_rsvd1
decl_stmt|;
specifier|volatile
name|u_int16_t
name|frag_len
decl_stmt|;
comment|/* bytes in this fragment */
specifier|volatile
name|u_int32_t
name|frag_addrlo
decl_stmt|;
comment|/* phys addr low word */
specifier|volatile
name|u_int32_t
name|frag_addrhi
decl_stmt|;
comment|/* phys addr high word */
specifier|volatile
name|u_int32_t
name|frag_rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_M
value|0x07
end_define

begin_comment
comment|/* type mask */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_FRAG
value|0x00
end_define

begin_comment
comment|/* type: fragment */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_DATA
value|0x01
end_define

begin_comment
comment|/* type: data frame */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_CMD
value|0x02
end_define

begin_comment
comment|/* type: command frame */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_OPT
value|0x03
end_define

begin_comment
comment|/* type: options */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_RX
value|0x04
end_define

begin_comment
comment|/* type: command */
end_comment

begin_define
define|#
directive|define
name|FRAG_FLAGS_TYPE_RESP
value|0x05
end_define

begin_comment
comment|/* type: response */
end_comment

begin_struct
struct|struct
name|txp_opt_desc
block|{
name|u_int8_t
name|opt_desctype
range|:
literal|3
decl_stmt|,
name|opt_rsvd
range|:
literal|1
decl_stmt|,
name|opt_type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|opt_num
decl_stmt|;
name|u_int16_t
name|opt_dep1
decl_stmt|;
name|u_int32_t
name|opt_dep2
decl_stmt|;
name|u_int32_t
name|opt_dep3
decl_stmt|;
name|u_int32_t
name|opt_dep4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_ipsec_desc
block|{
name|u_int8_t
name|ipsec_desctpe
range|:
literal|3
decl_stmt|,
name|ipsec_rsvd
range|:
literal|1
decl_stmt|,
name|ipsec_type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|ipsec_num
decl_stmt|;
name|u_int16_t
name|ipsec_flags
decl_stmt|;
name|u_int16_t
name|ipsec_ah1
decl_stmt|;
name|u_int16_t
name|ipsec_esp1
decl_stmt|;
name|u_int16_t
name|ipsec_ah2
decl_stmt|;
name|u_int16_t
name|ipsec_esp2
decl_stmt|;
name|u_int32_t
name|ipsec_rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_tcpseg_desc
block|{
name|u_int8_t
name|tcpseg_desctype
range|:
literal|3
decl_stmt|,
name|tcpseg_rsvd
range|:
literal|1
decl_stmt|,
name|tcpseg_type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|tcpseg_num
decl_stmt|;
name|u_int16_t
name|tcpseg_mss
range|:
literal|12
decl_stmt|,
name|tcpseg_misc
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|tcpseg_respaddr
decl_stmt|;
name|u_int32_t
name|tcpseg_txbytes
decl_stmt|;
name|u_int32_t
name|tcpseg_lss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transceiver types  */
end_comment

begin_define
define|#
directive|define
name|TXP_XCVR_10_HDX
value|0
end_define

begin_define
define|#
directive|define
name|TXP_XCVR_10_FDX
value|1
end_define

begin_define
define|#
directive|define
name|TXP_XCVR_100_HDX
value|2
end_define

begin_define
define|#
directive|define
name|TXP_XCVR_100_FDX
value|3
end_define

begin_define
define|#
directive|define
name|TXP_XCVR_AUTO
value|4
end_define

begin_define
define|#
directive|define
name|TXP_MEDIA_CRC
value|0x0004
end_define

begin_comment
comment|/* crc strip disable */
end_comment

begin_define
define|#
directive|define
name|TXP_MEDIA_CD
value|0x0010
end_define

begin_comment
comment|/* collision detection */
end_comment

begin_define
define|#
directive|define
name|TXP_MEDIA_CS
value|0x0020
end_define

begin_comment
comment|/* carrier sense */
end_comment

begin_define
define|#
directive|define
name|TXP_MEDIA_POL
value|0x0400
end_define

begin_comment
comment|/* polarity reversed */
end_comment

begin_define
define|#
directive|define
name|TXP_MEDIA_NOLINK
value|0x0800
end_define

begin_comment
comment|/* 0 = link, 1 = no link */
end_comment

begin_comment
comment|/*  * receive filter bits (par1 to TXP_CMD_RX_FILTER_{READ|WRITE}  */
end_comment

begin_define
define|#
directive|define
name|TXP_RXFILT_DIRECT
value|0x0001
end_define

begin_comment
comment|/* directed packets */
end_comment

begin_define
define|#
directive|define
name|TXP_RXFILT_ALLMULTI
value|0x0002
end_define

begin_comment
comment|/* all multicast packets */
end_comment

begin_define
define|#
directive|define
name|TXP_RXFILT_BROADCAST
value|0x0004
end_define

begin_comment
comment|/* broadcast packets */
end_comment

begin_define
define|#
directive|define
name|TXP_RXFILT_PROMISC
value|0x0008
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|TXP_RXFILT_HASHMULTI
value|0x0010
end_define

begin_comment
comment|/* use multicast filter */
end_comment

begin_comment
comment|/* multicast polynomial */
end_comment

begin_define
define|#
directive|define
name|TXP_POLYNOMIAL
value|0x04c11db7
end_define

begin_comment
comment|/*  * boot record (pointers to rings)  */
end_comment

begin_struct
struct|struct
name|txp_boot_record
block|{
specifier|volatile
name|u_int32_t
name|br_hostvar_lo
decl_stmt|;
comment|/* host ring pointer */
specifier|volatile
name|u_int32_t
name|br_hostvar_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_txlopri_lo
decl_stmt|;
comment|/* tx low pri ring */
specifier|volatile
name|u_int32_t
name|br_txlopri_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_txlopri_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_txhipri_lo
decl_stmt|;
comment|/* tx high pri ring */
specifier|volatile
name|u_int32_t
name|br_txhipri_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_txhipri_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxlopri_lo
decl_stmt|;
comment|/* rx low pri ring */
specifier|volatile
name|u_int32_t
name|br_rxlopri_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxlopri_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxbuf_lo
decl_stmt|;
comment|/* rx buffer ring */
specifier|volatile
name|u_int32_t
name|br_rxbuf_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxbuf_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_cmd_lo
decl_stmt|;
comment|/* command ring */
specifier|volatile
name|u_int32_t
name|br_cmd_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_cmd_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_resp_lo
decl_stmt|;
comment|/* response ring */
specifier|volatile
name|u_int32_t
name|br_resp_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_resp_siz
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_zero_lo
decl_stmt|;
comment|/* zero word */
specifier|volatile
name|u_int32_t
name|br_zero_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxhipri_lo
decl_stmt|;
comment|/* rx high pri ring */
specifier|volatile
name|u_int32_t
name|br_rxhipri_hi
decl_stmt|;
specifier|volatile
name|u_int32_t
name|br_rxhipri_siz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * hostvar structure (shared with typhoon)  */
end_comment

begin_struct
struct|struct
name|txp_hostvar
block|{
specifier|volatile
name|u_int32_t
name|hv_rx_hi_read_idx
decl_stmt|;
comment|/* host->arm */
specifier|volatile
name|u_int32_t
name|hv_rx_lo_read_idx
decl_stmt|;
comment|/* host->arm */
specifier|volatile
name|u_int32_t
name|hv_rx_buf_write_idx
decl_stmt|;
comment|/* host->arm */
specifier|volatile
name|u_int32_t
name|hv_resp_read_idx
decl_stmt|;
comment|/* host->arm */
specifier|volatile
name|u_int32_t
name|hv_tx_lo_desc_read_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_tx_hi_desc_read_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_rx_lo_write_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_rx_buf_read_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_cmd_read_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_resp_write_idx
decl_stmt|;
comment|/* arm->host */
specifier|volatile
name|u_int32_t
name|hv_rx_hi_write_idx
decl_stmt|;
comment|/* arm->host */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TYPHOON status register state (in TXP_A2H_0)  */
end_comment

begin_define
define|#
directive|define
name|STAT_ROM_CODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|STAT_ROM_EEPROM_LOAD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|STAT_WAITING_FOR_BOOT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|STAT_RUNNING
value|0x00000009
end_define

begin_define
define|#
directive|define
name|STAT_WAITING_FOR_HOST_REQUEST
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|STAT_WAITING_FOR_SEGMENT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|STAT_SLEEPING
value|0x00000011
end_define

begin_define
define|#
directive|define
name|STAT_HALTED
value|0x00000014
end_define

begin_define
define|#
directive|define
name|TX_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|RX_ENTRIES
value|128
end_define

begin_define
define|#
directive|define
name|RXBUF_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|CMD_ENTRIES
value|32
end_define

begin_define
define|#
directive|define
name|RSP_ENTRIES
value|32
end_define

begin_define
define|#
directive|define
name|OFFLOAD_TCPCKSUM
value|0x00000002
end_define

begin_comment
comment|/* tcp checksum */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_UDPCKSUM
value|0x00000004
end_define

begin_comment
comment|/* udp checksum */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_IPCKSUM
value|0x00000008
end_define

begin_comment
comment|/* ip checksum */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_IPSEC
value|0x00000010
end_define

begin_comment
comment|/* ipsec enable */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_BCAST
value|0x00000020
end_define

begin_comment
comment|/* broadcast throttle */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_DHCP
value|0x00000040
end_define

begin_comment
comment|/* dhcp prevention */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_VLAN
value|0x00000080
end_define

begin_comment
comment|/* vlan enable */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_FILTER
value|0x00000100
end_define

begin_comment
comment|/* filter enable */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_TCPSEG
value|0x00000200
end_define

begin_comment
comment|/* tcp segmentation */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_MASK
value|0xfffffffe
end_define

begin_comment
comment|/* mask off low bit */
end_comment

begin_comment
comment|/*  * Macros for converting array indices to offsets within the descriptor  * arrays.  The chip operates on offsets, but it's much easier for us  * to operate on indices.  Assumes descriptor entries are 16 bytes.  */
end_comment

begin_define
define|#
directive|define
name|TXP_IDX2OFFSET
parameter_list|(
name|idx
parameter_list|)
value|((idx)<< 4)
end_define

begin_define
define|#
directive|define
name|TXP_OFFSET2IDX
parameter_list|(
name|off
parameter_list|)
value|((off)>> 4)
end_define

begin_struct
struct|struct
name|txp_cmd_ring
block|{
name|struct
name|txp_cmd_desc
modifier|*
name|base
decl_stmt|;
name|u_int32_t
name|lastwrite
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_rsp_ring
block|{
name|struct
name|txp_rsp_desc
modifier|*
name|base
decl_stmt|;
name|u_int32_t
name|lastwrite
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_tx_ring
block|{
name|struct
name|txp_tx_desc
modifier|*
name|r_desc
decl_stmt|;
comment|/* base address of descs */
name|u_int32_t
name|r_reg
decl_stmt|;
comment|/* register to activate */
name|u_int32_t
name|r_prod
decl_stmt|;
comment|/* producer */
name|u_int32_t
name|r_cons
decl_stmt|;
comment|/* consumer */
name|u_int32_t
name|r_cnt
decl_stmt|;
comment|/* # descs in use */
specifier|volatile
name|u_int32_t
modifier|*
name|r_off
decl_stmt|;
comment|/* hostvar index pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_swdesc
block|{
name|struct
name|mbuf
modifier|*
name|sd_mbuf
decl_stmt|;
name|bus_dmamap_t
name|sd_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_rx_ring
block|{
name|struct
name|txp_rx_desc
modifier|*
name|r_desc
decl_stmt|;
comment|/* base address of descs */
specifier|volatile
name|u_int32_t
modifier|*
name|r_roff
decl_stmt|;
comment|/* hv read offset ptr */
specifier|volatile
name|u_int32_t
modifier|*
name|r_woff
decl_stmt|;
comment|/* hv write offset ptr */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_ldata
block|{
name|struct
name|txp_boot_record
name|txp_boot
decl_stmt|;
name|struct
name|txp_hostvar
name|txp_hostvar
decl_stmt|;
name|struct
name|txp_tx_desc
name|txp_txhiring
index|[
name|TX_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_tx_desc
name|txp_txloring
index|[
name|TX_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_rxbuf_desc
name|txp_rxbufs
index|[
name|RXBUF_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_rx_desc
name|txp_rxhiring
index|[
name|RX_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_rx_desc
name|txp_rxloring
index|[
name|RX_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_cmd_desc
name|txp_cmdring
index|[
name|CMD_ENTRIES
index|]
decl_stmt|;
name|struct
name|txp_rsp_desc
name|txp_rspring
index|[
name|RSP_ENTRIES
index|]
decl_stmt|;
name|u_int32_t
name|txp_zero
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_softc
block|{
name|struct
name|arpcom
name|sc_arpcom
decl_stmt|;
comment|/* ethernet common */
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|txp_hostvar
modifier|*
name|sc_hostvar
decl_stmt|;
name|struct
name|txp_boot_record
modifier|*
name|sc_boot
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
comment|/* bus handle (regs) */
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
comment|/* bus tag (regs) */
name|struct
name|resource
modifier|*
name|sc_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_intrhand
decl_stmt|;
name|struct
name|txp_ldata
modifier|*
name|sc_ldata
decl_stmt|;
name|void
modifier|*
name|sc_fwbuf
decl_stmt|;
name|int
name|sc_rxbufprod
decl_stmt|;
name|struct
name|txp_cmd_ring
name|sc_cmdring
decl_stmt|;
name|struct
name|txp_rsp_ring
name|sc_rspring
decl_stmt|;
name|struct
name|txp_swdesc
name|sc_txd
index|[
name|TX_ENTRIES
index|]
decl_stmt|;
name|struct
name|callout_handle
name|sc_tick
decl_stmt|;
name|struct
name|ifmedia
name|sc_ifmedia
decl_stmt|;
name|struct
name|txp_tx_ring
name|sc_txhir
decl_stmt|,
name|sc_txlor
decl_stmt|;
name|struct
name|txp_rxbuf_desc
modifier|*
name|sc_rxbufs
decl_stmt|;
name|struct
name|txp_rx_ring
name|sc_rxhir
decl_stmt|,
name|sc_rxlor
decl_stmt|;
name|u_int16_t
name|sc_xcvr
decl_stmt|;
name|u_int16_t
name|sc_seq
decl_stmt|;
name|int
name|sc_cold
decl_stmt|;
name|u_int32_t
name|sc_rx_capability
decl_stmt|,
name|sc_tx_capability
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TXP_DEVNAME
parameter_list|(
name|sc
parameter_list|)
value|((sc)->sc_cold ? "" : (sc)->sc_dev.dv_xname)
end_define

begin_struct
struct|struct
name|txp_fw_file_header
block|{
name|u_int8_t
name|magicid
index|[
literal|8
index|]
decl_stmt|;
comment|/* TYPHOON\0 */
name|u_int32_t
name|version
decl_stmt|;
name|u_int32_t
name|nsections
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|txp_fw_section_header
block|{
name|u_int32_t
name|nbytes
decl_stmt|;
name|u_int16_t
name|cksum
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TXP_MAX_SEGLEN
value|0xffff
end_define

begin_define
define|#
directive|define
name|TXP_MAX_PKTLEN
value|0x0800
end_define

begin_define
define|#
directive|define
name|WRITE_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bt, (sc)->sc_bh, reg, val)
end_define

begin_define
define|#
directive|define
name|READ_REG
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bt, (sc)->sc_bh, reg)
end_define

begin_comment
comment|/*  * 3Com PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|TXP_VENDORID_3COM
value|0x10B7
end_define

begin_comment
comment|/*  * 3cR990 device IDs  */
end_comment

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990_TX_95
value|0x9902
end_define

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990_TX_97
value|0x9903
end_define

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990B_TXM
value|0x9904
end_define

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990_SRV_95
value|0x9908
end_define

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990_SRV_97
value|0x9909
end_define

begin_define
define|#
directive|define
name|TXP_DEVICEID_3CR990B_SRV
value|0x990A
end_define

begin_struct
struct|struct
name|txp_type
block|{
name|u_int16_t
name|txp_vid
decl_stmt|;
name|u_int16_t
name|txp_did
decl_stmt|;
name|char
modifier|*
name|txp_name
decl_stmt|;
block|}
struct|;
end_struct

end_unit

