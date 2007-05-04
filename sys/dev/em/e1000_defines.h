begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_macro
name|$FreeBSD$
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_DEFINES_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_DEFINES_H_
end_define

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_IXSM
value|0x01
end_define

begin_comment
comment|/* Insert IP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_TXSM
value|0x02
end_define

begin_comment
comment|/* Insert TCP/UDP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IC
value|0x04000000
end_define

begin_comment
comment|/* Insert Checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RPS
value|0x10000000
end_define

begin_comment
comment|/* Report Packet Sent */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Descriptor extension (0 = legacy) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* Add VLAN tag */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IDE
value|0x80000000
end_define

begin_comment
comment|/* Enable Tidv register */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_DD
value|0x00000001
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_EC
value|0x00000002
end_define

begin_comment
comment|/* Excess Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_LC
value|0x00000004
end_define

begin_comment
comment|/* Late Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TU
value|0x00000008
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TCP
value|0x01000000
end_define

begin_comment
comment|/* TCP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IP
value|0x02000000
end_define

begin_comment
comment|/* IP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TSE
value|0x04000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TC
value|0x00000004
end_define

begin_comment
comment|/* Tx Underrun */
end_comment

begin_comment
comment|/* Number of Transmit and Receive Descriptors must be a multiple of 8 */
end_comment

begin_define
define|#
directive|define
name|REQ_TX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_define
define|#
directive|define
name|REQ_RX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_comment
comment|/* Definitions for power management and wakeup registers */
end_comment

begin_comment
comment|/* Wake Up Control */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_APME
value|0x00000001
end_define

begin_comment
comment|/* APM Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_PME_EN
value|0x00000002
end_define

begin_comment
comment|/* PME Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_PME_STATUS
value|0x00000004
end_define

begin_comment
comment|/* PME Status */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_APMPME
value|0x00000008
end_define

begin_comment
comment|/* Assert PME on APM Wakeup */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_SPM
value|0x80000000
end_define

begin_comment
comment|/* Enable SPM */
end_comment

begin_comment
comment|/* Wake Up Filter Control */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_LNKC
value|0x00000001
end_define

begin_comment
comment|/* Link Status Change Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_MAG
value|0x00000002
end_define

begin_comment
comment|/* Magic Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed Exact Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_MC
value|0x00000008
end_define

begin_comment
comment|/* Directed Multicast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_BC
value|0x00000010
end_define

begin_comment
comment|/* Broadcast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_ARP
value|0x00000020
end_define

begin_comment
comment|/* ARP Request Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_IPV4
value|0x00000040
end_define

begin_comment
comment|/* Directed IPv4 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_IPV6
value|0x00000080
end_define

begin_comment
comment|/* Directed IPv6 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_IGNORE_TCO
value|0x00008000
end_define

begin_comment
comment|/* Ignore WakeOn TCO packets */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX0
value|0x00010000
end_define

begin_comment
comment|/* Flexible Filter 0 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX1
value|0x00020000
end_define

begin_comment
comment|/* Flexible Filter 1 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX2
value|0x00040000
end_define

begin_comment
comment|/* Flexible Filter 2 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX3
value|0x00080000
end_define

begin_comment
comment|/* Flexible Filter 3 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_ALL_FILTERS
value|0x000F00FF
end_define

begin_comment
comment|/* Mask for all wakeup filters */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX_OFFSET
value|16
end_define

begin_comment
comment|/* Offset to the Flexible Filters bits */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX_FILTERS
value|0x000F0000
end_define

begin_comment
comment|/* Mask for the 4 flexible filters */
end_comment

begin_comment
comment|/* Wake Up Status */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_LNKC
value|E1000_WUFC_LNKC
end_define

begin_define
define|#
directive|define
name|E1000_WUS_MAG
value|E1000_WUFC_MAG
end_define

begin_define
define|#
directive|define
name|E1000_WUS_EX
value|E1000_WUFC_EX
end_define

begin_define
define|#
directive|define
name|E1000_WUS_MC
value|E1000_WUFC_MC
end_define

begin_define
define|#
directive|define
name|E1000_WUS_BC
value|E1000_WUFC_BC
end_define

begin_define
define|#
directive|define
name|E1000_WUS_ARP
value|E1000_WUFC_ARP
end_define

begin_define
define|#
directive|define
name|E1000_WUS_IPV4
value|E1000_WUFC_IPV4
end_define

begin_define
define|#
directive|define
name|E1000_WUS_IPV6
value|E1000_WUFC_IPV6
end_define

begin_define
define|#
directive|define
name|E1000_WUS_FLX0
value|E1000_WUFC_FLX0
end_define

begin_define
define|#
directive|define
name|E1000_WUS_FLX1
value|E1000_WUFC_FLX1
end_define

begin_define
define|#
directive|define
name|E1000_WUS_FLX2
value|E1000_WUFC_FLX2
end_define

begin_define
define|#
directive|define
name|E1000_WUS_FLX3
value|E1000_WUFC_FLX3
end_define

begin_define
define|#
directive|define
name|E1000_WUS_FLX_FILTERS
value|E1000_WUFC_FLX_FILTERS
end_define

begin_comment
comment|/* Wake Up Packet Length */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPL_LENGTH_MASK
value|0x0FFF
end_define

begin_comment
comment|/* Only the lower 12 bits are valid */
end_comment

begin_comment
comment|/* Four Flexible Filters are supported */
end_comment

begin_define
define|#
directive|define
name|E1000_FLEXIBLE_FILTER_COUNT_MAX
value|4
end_define

begin_comment
comment|/* Each Flexible Filter is at most 128 (0x80) bytes in length */
end_comment

begin_define
define|#
directive|define
name|E1000_FLEXIBLE_FILTER_SIZE_MAX
value|128
end_define

begin_define
define|#
directive|define
name|E1000_FFLT_SIZE
value|E1000_FLEXIBLE_FILTER_COUNT_MAX
end_define

begin_define
define|#
directive|define
name|E1000_FFMT_SIZE
value|E1000_FLEXIBLE_FILTER_SIZE_MAX
end_define

begin_define
define|#
directive|define
name|E1000_FFVT_SIZE
value|E1000_FLEXIBLE_FILTER_SIZE_MAX
end_define

begin_comment
comment|/* Extended Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI0_EN
value|0x00000001
end_define

begin_comment
comment|/* Maps SDP4 to GPI0 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI1_EN
value|0x00000002
end_define

begin_comment
comment|/* Maps SDP5 to GPI1 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PHYINT_EN
value|E1000_CTRL_EXT_GPI1_EN
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI2_EN
value|0x00000004
end_define

begin_comment
comment|/* Maps SDP6 to GPI2 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI3_EN
value|0x00000008
end_define

begin_comment
comment|/* Maps SDP7 to GPI3 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP4_DATA
value|0x00000010
end_define

begin_comment
comment|/* Value of SW Defineable Pin 4 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP5_DATA
value|0x00000020
end_define

begin_comment
comment|/* Value of SW Defineable Pin 5 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PHY_INT
value|E1000_CTRL_EXT_SDP5_DATA
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP6_DATA
value|0x00000040
end_define

begin_comment
comment|/* Value of SW Defineable Pin 6 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP7_DATA
value|0x00000080
end_define

begin_comment
comment|/* Value of SW Defineable Pin 7 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP4_DIR
value|0x00000100
end_define

begin_comment
comment|/* Direction of SDP4 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP5_DIR
value|0x00000200
end_define

begin_comment
comment|/* Direction of SDP5 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP6_DIR
value|0x00000400
end_define

begin_comment
comment|/* Direction of SDP6 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP7_DIR
value|0x00000800
end_define

begin_comment
comment|/* Direction of SDP7 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_ASDCHK
value|0x00001000
end_define

begin_comment
comment|/* Initiate an ASD sequence */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_EE_RST
value|0x00002000
end_define

begin_comment
comment|/* Reinitialize from EEPROM */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IPS
value|0x00004000
end_define

begin_comment
comment|/* Invert Power State */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SPD_BYPS
value|0x00008000
end_define

begin_comment
comment|/* Speed Select Bypass */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_RO_DIS
value|0x00020000
end_define

begin_comment
comment|/* Relaxed Ordering disable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_MASK
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_GMII
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_TBI
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_KMRN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_PCIE_SERDES
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_PCIX_SERDES
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_SGMII
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_EIAME
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IRCA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_256
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_320
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_384
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_448
value|0x03000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_CANC
value|0x04000000
end_define

begin_comment
comment|/* Interrupt delay cancellation */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_DRV_LOAD
value|0x10000000
end_define

begin_comment
comment|/* Driver loaded bit for FW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IAME
value|0x08000000
end_define

begin_comment
comment|/* Interrupt acknowledge Auto-mask */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_INT_TIMER_CLR
value|0x20000000
end_define

begin_comment
comment|/* Clear Interrupt timers after IMS clear */
end_comment

begin_define
define|#
directive|define
name|E1000_CRTL_EXT_PB_PAREN
value|0x01000000
end_define

begin_comment
comment|/* packet buffer parity error detection enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_DF_PAREN
value|0x02000000
end_define

begin_comment
comment|/* descriptor FIFO parity error detection enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GHOST_PAREN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PBA_CLR
value|0x80000000
end_define

begin_comment
comment|/* PBA Clear */
end_comment

begin_define
define|#
directive|define
name|E1000_I2CCMD_REG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_REG_ADDR
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_PHY_ADDR_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_PHY_ADDR
value|0x07000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_OPCODE_READ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_OPCODE_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_RESET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_READY
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_INTERRUPT_ENA
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_ERROR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_MAX_SGMII_PHY_REG_ADDR
value|255
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_PHY_TIMEOUT
value|200
end_define

begin_comment
comment|/* Receive Decriptor bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_DD
value|0x01
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_EOP
value|0x02
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_IXSM
value|0x04
end_define

begin_comment
comment|/* Ignore checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_VP
value|0x08
end_define

begin_comment
comment|/* IEEE VLAN Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_UDPCS
value|0x10
end_define

begin_comment
comment|/* UDP xsum caculated */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_TCPCS
value|0x20
end_define

begin_comment
comment|/* TCP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_IPCS
value|0x40
end_define

begin_comment
comment|/* IP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_PIF
value|0x80
end_define

begin_comment
comment|/* passed in-exact filter */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_CRCV
value|0x100
end_define

begin_comment
comment|/* Speculative CRC Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_IPIDV
value|0x200
end_define

begin_comment
comment|/* IP identification valid */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_UDPV
value|0x400
end_define

begin_comment
comment|/* Valid UDP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_DYNINT
value|0x800
end_define

begin_comment
comment|/* Pkt caused INT via DYNINT */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_ACK
value|0x8000
end_define

begin_comment
comment|/* ACK Packet indication */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_CE
value|0x01
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_SE
value|0x02
end_define

begin_comment
comment|/* Symbol Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_SEQ
value|0x04
end_define

begin_comment
comment|/* Sequence Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_CXE
value|0x10
end_define

begin_comment
comment|/* Carrier Extension Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_TCPE
value|0x20
end_define

begin_comment
comment|/* TCP/UDP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_IPE
value|0x40
end_define

begin_comment
comment|/* IP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_RXE
value|0x80
end_define

begin_comment
comment|/* Rx Data Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_VLAN_MASK
value|0x0FFF
end_define

begin_comment
comment|/* VLAN ID is in lower 12 bits */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_PRI_MASK
value|0xE000
end_define

begin_comment
comment|/* Priority is in upper 3 bits */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_PRI_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|E1000_RXD_SPC_CFI_MASK
value|0x1000
end_define

begin_comment
comment|/* CFI is bit 12 */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_CFI_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_CE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_SE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_SEQ
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_CXE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_TCPE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_IPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_RXE
value|0x80000000
end_define

begin_comment
comment|/* mask to determine if packets should be dropped due to frame errors */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_FRAME_ERR_MASK
value|( \     E1000_RXD_ERR_CE  |                \     E1000_RXD_ERR_SE  |                \     E1000_RXD_ERR_SEQ |                \     E1000_RXD_ERR_CXE |                \     E1000_RXD_ERR_RXE)
end_define

begin_comment
comment|/* Same mask, but for extended and packet split descriptors */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDEXT_ERR_FRAME_ERR_MASK
value|( \     E1000_RXDEXT_STATERR_CE  |            \     E1000_RXDEXT_STATERR_SE  |            \     E1000_RXDEXT_STATERR_SEQ |            \     E1000_RXDEXT_STATERR_CXE |            \     E1000_RXDEXT_STATERR_RXE)
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_RSS_2Q
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_RSS_INT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV4_TCP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_TCP_EX
value|0x00040000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_EX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_TCP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_RXDPS_HDRSTAT_HDRSP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_RXDPS_HDRSTAT_HDRLEN_MASK
value|0x000003FF
end_define

begin_comment
comment|/* Management Control */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMBUS_EN
value|0x00000001
end_define

begin_comment
comment|/* SMBus Enabled - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ASF_EN
value|0x00000002
end_define

begin_comment
comment|/* ASF Enabled - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_R_ON_FORCE
value|0x00000004
end_define

begin_comment
comment|/* Reset on Force TCO - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_RMCP_EN
value|0x00000100
end_define

begin_comment
comment|/* Enable RCMP 026Fh Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_0298_EN
value|0x00000200
end_define

begin_comment
comment|/* Enable RCMP 0298h Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_IPV4_EN
value|0x00000400
end_define

begin_comment
comment|/* Enable IPv4 */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_IPV6_EN
value|0x00000800
end_define

begin_comment
comment|/* Enable IPv6 */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SNAP_EN
value|0x00001000
end_define

begin_comment
comment|/* Accept LLC/SNAP */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ARP_EN
value|0x00002000
end_define

begin_comment
comment|/* Enable ARP Request Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_NEIGHBOR_EN
value|0x00004000
end_define

begin_comment
comment|/* Enable Neighbor Discovery                                              * Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ARP_RES_EN
value|0x00008000
end_define

begin_comment
comment|/* Enable ARP response Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_TCO_RESET
value|0x00010000
end_define

begin_comment
comment|/* TCO Reset Occurred */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_RCV_TCO_EN
value|0x00020000
end_define

begin_comment
comment|/* Receive TCO Packets Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_REPORT_STATUS
value|0x00040000
end_define

begin_comment
comment|/* Status Reporting Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_RCV_ALL
value|0x00080000
end_define

begin_comment
comment|/* Receive All Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_BLK_PHY_RST_ON_IDE
value|0x00040000
end_define

begin_comment
comment|/* Block phy resets */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MAC_ADDR_FILTER
value|0x00100000
end_define

begin_comment
comment|/* Enable MAC address                                                     * filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MNG2HOST
value|0x00200000
end_define

begin_comment
comment|/* Enable MNG packets to host                                              * memory */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_IP_ADDR_FILTER
value|0x00400000
end_define

begin_comment
comment|/* Enable IP address                                                     * filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_XSUM_FILTER
value|0x00800000
end_define

begin_comment
comment|/* Enable checksum filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_BR_EN
value|0x01000000
end_define

begin_comment
comment|/* Enable broadcast filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_REQ
value|0x01000000
end_define

begin_comment
comment|/* SMBus Request */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_GNT
value|0x02000000
end_define

begin_comment
comment|/* SMBus Grant */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_IN
value|0x04000000
end_define

begin_comment
comment|/* SMBus Clock In */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_IN
value|0x08000000
end_define

begin_comment
comment|/* SMBus Data In */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_OUT
value|0x10000000
end_define

begin_comment
comment|/* SMBus Data Out */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_OUT
value|0x20000000
end_define

begin_comment
comment|/* SMBus Clock Out */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_OUT_SHIFT
value|28
end_define

begin_comment
comment|/* SMBus Data Out Shift */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_OUT_SHIFT
value|29
end_define

begin_comment
comment|/* SMBus Clock Out Shift */
end_comment

begin_comment
comment|/* Receive Control */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RST
value|0x00000001
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_EN
value|0x00000002
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SBP
value|0x00000004
end_define

begin_comment
comment|/* store bad packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_UPE
value|0x00000008
end_define

begin_comment
comment|/* unicast promiscuous enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MPE
value|0x00000010
end_define

begin_comment
comment|/* multicast promiscuous enab */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LPE
value|0x00000020
end_define

begin_comment
comment|/* long packet enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_NO
value|0x00000000
end_define

begin_comment
comment|/* no loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_MAC
value|0x00000040
end_define

begin_comment
comment|/* MAC loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_SLP
value|0x00000080
end_define

begin_comment
comment|/* serial link loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_TCVR
value|0x000000C0
end_define

begin_comment
comment|/* tcvr loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_DTYP_MASK
value|0x00000C00
end_define

begin_comment
comment|/* Descriptor type mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_DTYP_PS
value|0x00000400
end_define

begin_comment
comment|/* Packet Split descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_HALF
value|0x00000000
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_QUAT
value|0x00000100
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_EIGTH
value|0x00000200
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_SHIFT
value|12
end_define

begin_comment
comment|/* multicast offset shift */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_0
value|0x00000000
end_define

begin_comment
comment|/* multicast offset 11:0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_1
value|0x00001000
end_define

begin_comment
comment|/* multicast offset 12:1 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_2
value|0x00002000
end_define

begin_comment
comment|/* multicast offset 13:2 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_3
value|0x00003000
end_define

begin_comment
comment|/* multicast offset 15:4 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MDR
value|0x00004000
end_define

begin_comment
comment|/* multicast desc ring 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_BAM
value|0x00008000
end_define

begin_comment
comment|/* broadcast enable */
end_comment

begin_comment
comment|/* these buffer sizes are valid if E1000_RCTL_BSEX is 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_2048
value|0x00000000
end_define

begin_comment
comment|/* rx buffer size 2048 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_1024
value|0x00010000
end_define

begin_comment
comment|/* rx buffer size 1024 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_512
value|0x00020000
end_define

begin_comment
comment|/* rx buffer size 512 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_256
value|0x00030000
end_define

begin_comment
comment|/* rx buffer size 256 */
end_comment

begin_comment
comment|/* these buffer sizes are valid if E1000_RCTL_BSEX is 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_16384
value|0x00010000
end_define

begin_comment
comment|/* rx buffer size 16384 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_8192
value|0x00020000
end_define

begin_comment
comment|/* rx buffer size 8192 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_4096
value|0x00030000
end_define

begin_comment
comment|/* rx buffer size 4096 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_VFE
value|0x00040000
end_define

begin_comment
comment|/* vlan filter enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_CFIEN
value|0x00080000
end_define

begin_comment
comment|/* canonical form enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_CFI
value|0x00100000
end_define

begin_comment
comment|/* canonical form indicator */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_DPF
value|0x00400000
end_define

begin_comment
comment|/* discard pause frames */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_PMCF
value|0x00800000
end_define

begin_comment
comment|/* pass MAC control frames */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_BSEX
value|0x02000000
end_define

begin_comment
comment|/* Buffer size extension */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SECRC
value|0x04000000
end_define

begin_comment
comment|/* Strip Ethernet CRC */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_FLXBUF_MASK
value|0x78000000
end_define

begin_comment
comment|/* Flexible buffer size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_FLXBUF_SHIFT
value|27
end_define

begin_comment
comment|/* Flexible buffer shift */
end_comment

begin_comment
comment|/* Use byte values for the following shift parameters  * Usage:  *     psrctl |= (((ROUNDUP(value0, 128)>> E1000_PSRCTL_BSIZE0_SHIFT)&  *                  E1000_PSRCTL_BSIZE0_MASK) |  *                ((ROUNDUP(value1, 1024)>> E1000_PSRCTL_BSIZE1_SHIFT)&  *                  E1000_PSRCTL_BSIZE1_MASK) |  *                ((ROUNDUP(value2, 1024)<< E1000_PSRCTL_BSIZE2_SHIFT)&  *                  E1000_PSRCTL_BSIZE2_MASK) |  *                ((ROUNDUP(value3, 1024)<< E1000_PSRCTL_BSIZE3_SHIFT) |;  *                  E1000_PSRCTL_BSIZE3_MASK))  * where value0 = [128..16256],  default=256  *       value1 = [1024..64512], default=4096  *       value2 = [0..64512],    default=4096  *       value3 = [0..64512],    default=0  */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE0_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE1_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE2_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE3_MASK
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE0_SHIFT
value|7
end_define

begin_comment
comment|/* Shift _right_ 7 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE1_SHIFT
value|2
end_define

begin_comment
comment|/* Shift _right_ 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE2_SHIFT
value|6
end_define

begin_comment
comment|/* Shift _left_ 6 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE3_SHIFT
value|14
end_define

begin_comment
comment|/* Shift _left_ 14 */
end_comment

begin_comment
comment|/* SWFW_SYNC Definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_SWFW_EEP_SM
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY0_SM
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY1_SM
value|0x4
end_define

begin_comment
comment|/* Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FD
value|0x00000001
end_define

begin_comment
comment|/* Full duplex.0=half; 1=full */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_BEM
value|0x00000002
end_define

begin_comment
comment|/* Endian Mode.0=little,1=big */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PRIOR
value|0x00000004
end_define

begin_comment
comment|/* Priority on PCI. 0=rx,1=fair */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_GIO_MASTER_DISABLE
value|0x00000004
end_define

begin_comment
comment|/*Blocks new Master requests */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_LRST
value|0x00000008
end_define

begin_comment
comment|/* Link reset. 0=normal,1=reset */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_TME
value|0x00000010
end_define

begin_comment
comment|/* Test mode. 0=normal,1=test */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SLE
value|0x00000020
end_define

begin_comment
comment|/* Serial Link on 0=dis,1=en */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_ASDE
value|0x00000020
end_define

begin_comment
comment|/* Auto-speed detect enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SLU
value|0x00000040
end_define

begin_comment
comment|/* Set link up (Force Link) */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_ILOS
value|0x00000080
end_define

begin_comment
comment|/* Invert Loss-Of Signal */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_SEL
value|0x00000300
end_define

begin_comment
comment|/* Speed Select Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_10
value|0x00000000
end_define

begin_comment
comment|/* Force 10Mb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_100
value|0x00000100
end_define

begin_comment
comment|/* Force 100Mb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_1000
value|0x00000200
end_define

begin_comment
comment|/* Force 1Gb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_BEM32
value|0x00000400
end_define

begin_comment
comment|/* Big Endian 32 mode */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FRCSPD
value|0x00000800
end_define

begin_comment
comment|/* Force Speed */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FRCDPX
value|0x00001000
end_define

begin_comment
comment|/* Force Duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_D_UD_EN
value|0x00002000
end_define

begin_comment
comment|/* Dock/Undock enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_D_UD_POLARITY
value|0x00004000
end_define

begin_comment
comment|/* Defined polarity of Dock/Undock indication in SDP[0] */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FORCE_PHY_RESET
value|0x00008000
end_define

begin_comment
comment|/* Reset both PHY ports, through PHYRST_N pin */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_EN
value|0x00010000
end_define

begin_comment
comment|/* enable link status from external LINK_0 and LINK_1 pins */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN0
value|0x00040000
end_define

begin_comment
comment|/* SWDPIN 0 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN1
value|0x00080000
end_define

begin_comment
comment|/* SWDPIN 1 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN2
value|0x00100000
end_define

begin_comment
comment|/* SWDPIN 2 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN3
value|0x00200000
end_define

begin_comment
comment|/* SWDPIN 3 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO0
value|0x00400000
end_define

begin_comment
comment|/* SWDPIN 0 Input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO1
value|0x00800000
end_define

begin_comment
comment|/* SWDPIN 1 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO2
value|0x01000000
end_define

begin_comment
comment|/* SWDPIN 2 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO3
value|0x02000000
end_define

begin_comment
comment|/* SWDPIN 3 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RST
value|0x04000000
end_define

begin_comment
comment|/* Global reset */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RFCE
value|0x08000000
end_define

begin_comment
comment|/* Receive Flow Control enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_TFCE
value|0x10000000
end_define

begin_comment
comment|/* Transmit flow control enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RTE
value|0x20000000
end_define

begin_comment
comment|/* Routing tag enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_VME
value|0x40000000
end_define

begin_comment
comment|/* IEEE VLAN mode enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RST
value|0x80000000
end_define

begin_comment
comment|/* PHY Reset */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SW2FW_INT
value|0x02000000
end_define

begin_comment
comment|/* Initiate an interrupt to manageability engine */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_I2C_ENA
value|0x02000000
end_define

begin_comment
comment|/* I2C enable */
end_comment

begin_comment
comment|/* Bit definitions for the Management Data IO (MDIO) and Management Data  * Clock (MDC) pins in the Device Control Register.  */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR
value|E1000_CTRL_SWDPIO0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET
value|E1000_CTRL_SWDPIN0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO_DIR
value|E1000_CTRL_SWDPIO2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO
value|E1000_CTRL_SWDPIN2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC_DIR
value|E1000_CTRL_SWDPIO3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC
value|E1000_CTRL_SWDPIN3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR4
value|E1000_CTRL_EXT_SDP4_DIR
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET4
value|E1000_CTRL_EXT_SDP4_DATA
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_ENRGSRC
value|0x4
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FLV_LINK_UP
value|1
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FSV_10
value|0
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FSV_100
value|2
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FSV_1000
value|4
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FDV_FULL
value|8
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FSD
value|0x10
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FORCE_LINK
value|0x20
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_LOW_LINK_LATCH
value|0x40
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_AN_ENABLE
value|0x10000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_AN_RESTART
value|0x20000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_AN_TIMEOUT
value|0x40000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_AN_SGMII_BYPASS
value|0x80000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_AN_SGMII_TRIGGER
value|0x100000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_FAST_LINK_TIMER
value|0x1000000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_LINK_OK_FIX
value|0x2000000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LCTL_CRS_ON_NI
value|0x4000000
end_define

begin_define
define|#
directive|define
name|E1000_ENABLE_SERDES_LOOPBACK
value|0x0410
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_LINK_OK
value|1
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_SPEED_10
value|0
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_SPEED_100
value|2
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_SPEED_1000
value|4
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_DUPLEX_FULL
value|8
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_SYNK_OK
value|0x10
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_AN_COMPLETE
value|0x10000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_AN_PAGE_RX
value|0x20000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_AN_TIMED_OUT
value|0x40000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_AN_REMOTE_FAULT
value|0x80000
end_define

begin_define
define|#
directive|define
name|E1000_PCS_LSTS_AN_ERROR_RWS
value|0x100000
end_define

begin_comment
comment|/* Device Status */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FD
value|0x00000001
end_define

begin_comment
comment|/* Full duplex.0=half,1=full */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_LU
value|0x00000002
end_define

begin_comment
comment|/* Link up.0=no,1=link */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_MASK
value|0x0000000C
end_define

begin_comment
comment|/* PCI Function Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_0
value|0x00000000
end_define

begin_comment
comment|/* Function 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_1
value|0x00000004
end_define

begin_comment
comment|/* Function 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_TXOFF
value|0x00000010
end_define

begin_comment
comment|/* transmission paused */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_TBIMODE
value|0x00000020
end_define

begin_comment
comment|/* TBI mode */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_10
value|0x00000000
end_define

begin_comment
comment|/* Speed 10Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_100
value|0x00000040
end_define

begin_comment
comment|/* Speed 100Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_1000
value|0x00000080
end_define

begin_comment
comment|/* Speed 1000Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_LAN_INIT_DONE
value|0x00000200
end_define

begin_comment
comment|/* Lan Init Completion by NVM */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_ASDV
value|0x00000300
end_define

begin_comment
comment|/* Auto speed detect value */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_DOCK_CI
value|0x00000800
end_define

begin_comment
comment|/* Change in Dock/Undock state. Clear on write '0'. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_GIO_MASTER_ENABLE
value|0x00080000
end_define

begin_comment
comment|/* Status of Master requests. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_MTXCKOK
value|0x00000400
end_define

begin_comment
comment|/* MTX clock running OK */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCI66
value|0x00000800
end_define

begin_comment
comment|/* In 66Mhz slot */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BUS64
value|0x00001000
end_define

begin_comment
comment|/* In 64 bit slot */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_MODE
value|0x00002000
end_define

begin_comment
comment|/* PCI-X mode */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED
value|0x0000C000
end_define

begin_comment
comment|/* PCI-X bus speed */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_0
value|0x00100000
end_define

begin_comment
comment|/* BMC USB redirect disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_1
value|0x00200000
end_define

begin_comment
comment|/* BMC SRAM disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_2
value|0x00400000
end_define

begin_comment
comment|/* BMC SDRAM disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_CRYPTO
value|0x00800000
end_define

begin_comment
comment|/* BMC crypto disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_LITE
value|0x01000000
end_define

begin_comment
comment|/* BMC external code execution disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_RGMII_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* RGMII disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUSE_8
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_FUSE_9
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_SERDES0_DIS
value|0x10000000
end_define

begin_comment
comment|/* SERDES disabled on port 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SERDES1_DIS
value|0x20000000
end_define

begin_comment
comment|/* SERDES disabled on port 1 */
end_comment

begin_comment
comment|/* Constants used to intrepret the masked PCI-X bus speed. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_66
value|0x00000000
end_define

begin_comment
comment|/* PCI-X bus speed  50-66 MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_100
value|0x00004000
end_define

begin_comment
comment|/* PCI-X bus speed  66-100 MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_133
value|0x00008000
end_define

begin_comment
comment|/* PCI-X bus speed 100-133 MHz */
end_comment

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|HALF_DUPLEX
value|1
end_define

begin_define
define|#
directive|define
name|FULL_DUPLEX
value|2
end_define

begin_define
define|#
directive|define
name|PHY_FORCE_TIME
value|20
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_HALF
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_HALF
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_FULL
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000_HALF
value|0x0010
end_define

begin_comment
comment|/* Not used, just FYI */
end_comment

begin_define
define|#
directive|define
name|ADVERTISE_1000_FULL
value|0x0020
end_define

begin_comment
comment|/* 1000/H is not supported, nor spec-compliant. */
end_comment

begin_define
define|#
directive|define
name|E1000_ALL_SPEED_DUPLEX
value|( ADVERTISE_10_HALF |   ADVERTISE_10_FULL | \                                 ADVERTISE_100_HALF |  ADVERTISE_100_FULL | \                                                      ADVERTISE_1000_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_NOT_GIG
value|( ADVERTISE_10_HALF |   ADVERTISE_10_FULL | \                                 ADVERTISE_100_HALF |  ADVERTISE_100_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_100_SPEED
value|(ADVERTISE_100_HALF |  ADVERTISE_100_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_10_SPEED
value|(ADVERTISE_10_HALF |   ADVERTISE_10_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_FULL_DUPLEX
value|(ADVERTISE_10_FULL |  ADVERTISE_100_FULL | \                                                      ADVERTISE_1000_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_HALF_DUPLEX
value|(ADVERTISE_10_HALF |  ADVERTISE_100_HALF)
end_define

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_SPEED_DEFAULT
value|E1000_ALL_SPEED_DUPLEX
end_define

begin_comment
comment|/* LED Control */
end_comment

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_MODE_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_BLINK_RATE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_IVRT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_BLINK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_MODE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_MODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_BLINK_RATE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_IVRT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_BLINK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_MODE_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_BLINK_RATE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_IVRT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_BLINK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_MODE_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_MODE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_BLINK_RATE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_IVRT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_BLINK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_10_1000
value|0x0
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_100_1000
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_UP
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_ACTIVITY
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_ACTIVITY
value|0x4
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_10
value|0x5
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_100
value|0x6
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_1000
value|0x7
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_PCIX_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_FULL_DUPLEX
value|0x9
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_COLLISION
value|0xA
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_BUS_SPEED
value|0xB
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_BUS_SIZE
value|0xC
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_PAUSED
value|0xD
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LED_ON
value|0xE
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LED_OFF
value|0xF
end_define

begin_comment
comment|/* Transmit Descriptor bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_D
value|0x00100000
end_define

begin_comment
comment|/* Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_C
value|0x00000000
end_define

begin_comment
comment|/* Context Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_IXSM
value|0x01
end_define

begin_comment
comment|/* Insert IP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_TXSM
value|0x02
end_define

begin_comment
comment|/* Insert TCP/UDP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IC
value|0x04000000
end_define

begin_comment
comment|/* Insert Checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RPS
value|0x10000000
end_define

begin_comment
comment|/* Report Packet Sent */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Descriptor extension (0 = legacy) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* Add VLAN tag */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IDE
value|0x80000000
end_define

begin_comment
comment|/* Enable Tidv register */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_DD
value|0x00000001
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_EC
value|0x00000002
end_define

begin_comment
comment|/* Excess Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_LC
value|0x00000004
end_define

begin_comment
comment|/* Late Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TU
value|0x00000008
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TCP
value|0x01000000
end_define

begin_comment
comment|/* TCP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IP
value|0x02000000
end_define

begin_comment
comment|/* IP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TSE
value|0x04000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TC
value|0x00000004
end_define

begin_comment
comment|/* Tx Underrun */
end_comment

begin_comment
comment|/* Transmit Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_RST
value|0x00000001
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EN
value|0x00000002
end_define

begin_comment
comment|/* enable tx */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_BCE
value|0x00000004
end_define

begin_comment
comment|/* busy check enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_PSP
value|0x00000008
end_define

begin_comment
comment|/* pad short packets */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_CT
value|0x00000ff0
end_define

begin_comment
comment|/* collision threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_COLD
value|0x003ff000
end_define

begin_comment
comment|/* collision distance */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_SWXOFF
value|0x00400000
end_define

begin_comment
comment|/* SW Xoff transmission */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_PBE
value|0x00800000
end_define

begin_comment
comment|/* Packet Burst Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_RTLC
value|0x01000000
end_define

begin_comment
comment|/* Re-transmit on late collision */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_NRTU
value|0x02000000
end_define

begin_comment
comment|/* No Re-transmit on underrun */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_MULR
value|0x10000000
end_define

begin_comment
comment|/* Multiple request support */
end_comment

begin_comment
comment|/* Transmit Arbitration Count */
end_comment

begin_define
define|#
directive|define
name|E1000_TARC0_ENABLE
value|0x00000400
end_define

begin_comment
comment|/* Enable Tx Queue 0 */
end_comment

begin_comment
comment|/* SerDes Control */
end_comment

begin_define
define|#
directive|define
name|E1000_SCTL_DISABLE_SERDES_LOOPBACK
value|0x0400
end_define

begin_comment
comment|/* Receive Checksum Control */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_PCSS_MASK
value|0x000000FF
end_define

begin_comment
comment|/* Packet Checksum Start */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPOFL
value|0x00000100
end_define

begin_comment
comment|/* IPv4 checksum offload */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_TUOFL
value|0x00000200
end_define

begin_comment
comment|/* TCP / UDP checksum offload */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPV6OFL
value|0x00000400
end_define

begin_comment
comment|/* IPv6 checksum offload */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_CRCOFL
value|0x00000800
end_define

begin_comment
comment|/* CRC32 offload enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPPCSE
value|0x00001000
end_define

begin_comment
comment|/* IP payload checksum enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_PCSD
value|0x00002000
end_define

begin_comment
comment|/* packet checksum disabled */
end_comment

begin_comment
comment|/* Header split receive */
end_comment

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DWC_MASK
value|0x0000003E
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DWC_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFSW_DIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFSR_DIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFS_VER_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFS_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_DIS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_XSUM_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ACK_DIS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ACKD_DIS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPFRSP_DIS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_EXTEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_EX_DIS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NEW_IPV6_EXT_DIS
value|0x00020000
end_define

begin_comment
comment|/* Collision related configuration parameters */
end_comment

begin_define
define|#
directive|define
name|E1000_COLLISION_THRESHOLD
value|15
end_define

begin_define
define|#
directive|define
name|E1000_CT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|E1000_COLLISION_DISTANCE
value|63
end_define

begin_define
define|#
directive|define
name|E1000_COLD_SHIFT
value|12
end_define

begin_comment
comment|/* Default values for the transmit IPG register */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_82542_SUPPORT
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGT_FIBER
value|9
end_define

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGT_COPPER
value|8
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGT_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR1_MASK
value|0x000FFC00
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR2_MASK
value|0x3FF00000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_82542_SUPPORT
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGR1
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGR1
value|8
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR1_SHIFT
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_82542_SUPPORT
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGR2
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGR2
value|6
end_define

begin_define
define|#
directive|define
name|DEFAULT_80003ES2LAN_TIPG_IPGR2
value|7
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR2_SHIFT
value|20
end_define

begin_comment
comment|/* Ethertype field values */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_IEEE_VLAN_TYPE
value|0x8100
end_define

begin_comment
comment|/* 802.3ac packet */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_FCS_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|MAX_JUMBO_FRAME_SIZE
value|0x3F00
end_define

begin_comment
comment|/* Extended Configuration Control and Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_MDIO_SW_OWNERSHIP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_LCD_WRITE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_SWFLAG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE_EXT_PCIE_LENGTH_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE_EXT_PCIE_LENGTH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_EXT_CNF_POINTER_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_EXT_CNF_POINTER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_SPD_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_D0A_LPLU
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_NOND0A_LPLU
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_NOND0A_GBE_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_GBE_DISABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_KABGTXD_BGSQLBIAS
value|0x00050000
end_define

begin_comment
comment|/* PBA constants */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_8K
value|0x0008
end_define

begin_comment
comment|/* 8KB, default Rx allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_12K
value|0x000C
end_define

begin_comment
comment|/* 12KB, default Rx allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_16K
value|0x0010
end_define

begin_comment
comment|/* 16KB, default TX allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_20K
value|0x0014
end_define

begin_define
define|#
directive|define
name|E1000_PBA_22K
value|0x0016
end_define

begin_define
define|#
directive|define
name|E1000_PBA_24K
value|0x0018
end_define

begin_define
define|#
directive|define
name|E1000_PBA_30K
value|0x001E
end_define

begin_define
define|#
directive|define
name|E1000_PBA_32K
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_PBA_34K
value|0x0022
end_define

begin_define
define|#
directive|define
name|E1000_PBA_38K
value|0x0026
end_define

begin_define
define|#
directive|define
name|E1000_PBA_40K
value|0x0028
end_define

begin_define
define|#
directive|define
name|E1000_PBA_48K
value|0x0030
end_define

begin_comment
comment|/* 48KB, default RX allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBS_16K
value|E1000_PBA_16K
end_define

begin_define
define|#
directive|define
name|E1000_PBS_24K
value|E1000_PBA_24K
end_define

begin_define
define|#
directive|define
name|IFS_MAX
value|80
end_define

begin_define
define|#
directive|define
name|IFS_MIN
value|40
end_define

begin_define
define|#
directive|define
name|IFS_RATIO
value|4
end_define

begin_define
define|#
directive|define
name|IFS_STEP
value|10
end_define

begin_define
define|#
directive|define
name|MIN_NUM_XMITS
value|1000
end_define

begin_comment
comment|/* SW Semaphore Register */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_SMBI
value|0x00000001
end_define

begin_comment
comment|/* Driver Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_SWESMBI
value|0x00000002
end_define

begin_comment
comment|/* FW Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_WMNG
value|0x00000004
end_define

begin_comment
comment|/* Wake MNG Clock */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_DRV_LOAD
value|0x00000008
end_define

begin_comment
comment|/* Driver Loaded Bit */
end_comment

begin_comment
comment|/* Interrupt Cause Read */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXDW
value|0x00000001
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXQE
value|0x00000002
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_LSC
value|0x00000004
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXSEQ
value|0x00000008
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXDMT0
value|0x00000010
end_define

begin_comment
comment|/* rx desc min. threshold (0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXO
value|0x00000040
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXT0
value|0x00000080
end_define

begin_comment
comment|/* rx timer intr (ring 0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_MDAC
value|0x00000200
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXCFG
value|0x00000400
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN0
value|0x00000800
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN1
value|0x00001000
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN2
value|0x00002000
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN3
value|0x00004000
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_LOW
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_ICR_SRPD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_ICR_ACK
value|0x00020000
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_MNG
value|0x00040000
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_DOCK
value|0x00080000
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_INT_ASSERTED
value|0x80000000
end_define

begin_comment
comment|/* If this bit asserted, the driver should claim the interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXD_FIFO_PAR0
value|0x00100000
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_FIFO_PAR0
value|0x00200000
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_HOST_ARB_PAR
value|0x00400000
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_PB_PAR
value|0x00800000
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXD_FIFO_PAR1
value|0x01000000
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_FIFO_PAR1
value|0x02000000
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_ALL_PARITY
value|0x03F00000
end_define

begin_comment
comment|/* all parity error bits */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_DSW
value|0x00000020
end_define

begin_comment
comment|/* FW changed the status of DISSW bit in the FWSM */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_PHYINT
value|0x00001000
end_define

begin_comment
comment|/* LAN connected device generates an interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_EPRST
value|0x00100000
end_define

begin_comment
comment|/* ME handware reset occurs */
end_comment

begin_comment
comment|/* Extended Interrupt Cause Read */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_RX_QUEUE0
value|0x00000001
end_define

begin_comment
comment|/* Rx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_RX_QUEUE1
value|0x00000002
end_define

begin_comment
comment|/* Rx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_RX_QUEUE2
value|0x00000004
end_define

begin_comment
comment|/* Rx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_RX_QUEUE3
value|0x00000008
end_define

begin_comment
comment|/* Rx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_TX_QUEUE0
value|0x00000100
end_define

begin_comment
comment|/* Tx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_TX_QUEUE1
value|0x00000200
end_define

begin_comment
comment|/* Tx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_TX_QUEUE2
value|0x00000400
end_define

begin_comment
comment|/* Tx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_TX_QUEUE3
value|0x00000800
end_define

begin_comment
comment|/* Tx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_TCP_TIMER
value|0x40000000
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR_OTHER
value|0x80000000
end_define

begin_comment
comment|/* Interrupt Cause Active */
end_comment

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|E1000_TCPTIMER_KS
value|0x00000100
end_define

begin_comment
comment|/* KickStart */
end_comment

begin_define
define|#
directive|define
name|E1000_TCPTIMER_COUNT_ENABLE
value|0x00000200
end_define

begin_comment
comment|/* Count Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TCPTIMER_COUNT_FINISH
value|0x00000400
end_define

begin_comment
comment|/* Count finish */
end_comment

begin_define
define|#
directive|define
name|E1000_TCPTIMER_LOOP
value|0x00000800
end_define

begin_comment
comment|/* Loop */
end_comment

begin_comment
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error  */
end_comment

begin_define
define|#
directive|define
name|POLL_IMS_ENABLE_MASK
value|( \     E1000_IMS_RXDMT0 |    \     E1000_IMS_RXSEQ)
end_define

begin_comment
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXT0   = Receiver Timer Interrupt (ring 0)  *   o TXDW   = Transmit Descriptor Written Back  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error  *   o LSC    = Link Status Change  */
end_comment

begin_define
define|#
directive|define
name|IMS_ENABLE_MASK
value|( \     E1000_IMS_RXT0   |    \     E1000_IMS_TXDW   |    \     E1000_IMS_RXDMT0 |    \     E1000_IMS_RXSEQ  |    \     E1000_IMS_LSC)
end_define

begin_comment
comment|/* Interrupt Mask Set */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXDW
value|E1000_ICR_TXDW
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXQE
value|E1000_ICR_TXQE
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_LSC
value|E1000_ICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* rx timer intr */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_MDAC
value|E1000_ICR_MDAC
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXCFG
value|E1000_ICR_RXCFG
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN0
value|E1000_ICR_GPI_EN0
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN1
value|E1000_ICR_GPI_EN1
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN2
value|E1000_ICR_GPI_EN2
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN3
value|E1000_ICR_GPI_EN3
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_LOW
value|E1000_ICR_TXD_LOW
end_define

begin_define
define|#
directive|define
name|E1000_IMS_SRPD
value|E1000_ICR_SRPD
end_define

begin_define
define|#
directive|define
name|E1000_IMS_ACK
value|E1000_ICR_ACK
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_MNG
value|E1000_ICR_MNG
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DOCK
value|E1000_ICR_DOCK
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXD_FIFO_PAR0
value|E1000_ICR_RXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_FIFO_PAR0
value|E1000_ICR_TXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_HOST_ARB_PAR
value|E1000_ICR_HOST_ARB_PAR
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_PB_PAR
value|E1000_ICR_PB_PAR
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXD_FIFO_PAR1
value|E1000_ICR_RXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_FIFO_PAR1
value|E1000_ICR_TXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DSW
value|E1000_ICR_DSW
end_define

begin_define
define|#
directive|define
name|E1000_IMS_PHYINT
value|E1000_ICR_PHYINT
end_define

begin_define
define|#
directive|define
name|E1000_IMS_EPRST
value|E1000_ICR_EPRST
end_define

begin_comment
comment|/* Extended Interrupt Mask Set */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_RX_QUEUE0
value|E1000_EICR_RX_QUEUE0
end_define

begin_comment
comment|/* Rx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_RX_QUEUE1
value|E1000_EICR_RX_QUEUE1
end_define

begin_comment
comment|/* Rx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_RX_QUEUE2
value|E1000_EICR_RX_QUEUE2
end_define

begin_comment
comment|/* Rx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_RX_QUEUE3
value|E1000_EICR_RX_QUEUE3
end_define

begin_comment
comment|/* Rx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_TX_QUEUE0
value|E1000_EICR_TX_QUEUE0
end_define

begin_comment
comment|/* Tx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_TX_QUEUE1
value|E1000_EICR_TX_QUEUE1
end_define

begin_comment
comment|/* Tx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_TX_QUEUE2
value|E1000_EICR_TX_QUEUE2
end_define

begin_comment
comment|/* Tx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_TX_QUEUE3
value|E1000_EICR_TX_QUEUE3
end_define

begin_comment
comment|/* Tx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_TCP_TIMER
value|E1000_EICR_TCP_TIMER
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS_OTHER
value|E1000_EICR_OTHER
end_define

begin_comment
comment|/* Interrupt Cause Active */
end_comment

begin_comment
comment|/* Interrupt Cause Set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXDW
value|E1000_ICR_TXDW
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXQE
value|E1000_ICR_TXQE
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_LSC
value|E1000_ICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* rx timer intr */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_MDAC
value|E1000_ICR_MDAC
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXCFG
value|E1000_ICR_RXCFG
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN0
value|E1000_ICR_GPI_EN0
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN1
value|E1000_ICR_GPI_EN1
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN2
value|E1000_ICR_GPI_EN2
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN3
value|E1000_ICR_GPI_EN3
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_LOW
value|E1000_ICR_TXD_LOW
end_define

begin_define
define|#
directive|define
name|E1000_ICS_SRPD
value|E1000_ICR_SRPD
end_define

begin_define
define|#
directive|define
name|E1000_ICS_ACK
value|E1000_ICR_ACK
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_MNG
value|E1000_ICR_MNG
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_DOCK
value|E1000_ICR_DOCK
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXD_FIFO_PAR0
value|E1000_ICR_RXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_FIFO_PAR0
value|E1000_ICR_TXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_HOST_ARB_PAR
value|E1000_ICR_HOST_ARB_PAR
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_PB_PAR
value|E1000_ICR_PB_PAR
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXD_FIFO_PAR1
value|E1000_ICR_RXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_FIFO_PAR1
value|E1000_ICR_TXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_DSW
value|E1000_ICR_DSW
end_define

begin_define
define|#
directive|define
name|E1000_ICS_PHYINT
value|E1000_ICR_PHYINT
end_define

begin_define
define|#
directive|define
name|E1000_ICS_EPRST
value|E1000_ICR_EPRST
end_define

begin_comment
comment|/* Extended Interrupt Cause Set */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_RX_QUEUE0
value|E1000_EICR_RX_QUEUE0
end_define

begin_comment
comment|/* Rx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_RX_QUEUE1
value|E1000_EICR_RX_QUEUE1
end_define

begin_comment
comment|/* Rx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_RX_QUEUE2
value|E1000_EICR_RX_QUEUE2
end_define

begin_comment
comment|/* Rx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_RX_QUEUE3
value|E1000_EICR_RX_QUEUE3
end_define

begin_comment
comment|/* Rx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_TX_QUEUE0
value|E1000_EICR_TX_QUEUE0
end_define

begin_comment
comment|/* Tx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_TX_QUEUE1
value|E1000_EICR_TX_QUEUE1
end_define

begin_comment
comment|/* Tx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_TX_QUEUE2
value|E1000_EICR_TX_QUEUE2
end_define

begin_comment
comment|/* Tx Queue 2 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_TX_QUEUE3
value|E1000_EICR_TX_QUEUE3
end_define

begin_comment
comment|/* Tx Queue 3 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_TCP_TIMER
value|E1000_EICR_TCP_TIMER
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|E1000_EICS_OTHER
value|E1000_EICR_OTHER
end_define

begin_comment
comment|/* Interrupt Cause Active */
end_comment

begin_comment
comment|/* Transmit Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_PTHRESH
value|0x0000003F
end_define

begin_comment
comment|/* TXDCTL Prefetch Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_HTHRESH
value|0x00003F00
end_define

begin_comment
comment|/* TXDCTL Host Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_WTHRESH
value|0x003F0000
end_define

begin_comment
comment|/* TXDCTL Writeback Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_GRAN
value|0x01000000
end_define

begin_comment
comment|/* TXDCTL Granularity */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_LWTHRESH
value|0xFE000000
end_define

begin_comment
comment|/* TXDCTL Low Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_FULL_TX_DESC_WB
value|0x01010000
end_define

begin_comment
comment|/* GRAN=1, WTHRESH=1 */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_MAX_TX_DESC_PREFETCH
value|0x0100001F
end_define

begin_comment
comment|/* GRAN=1, PTHRESH=31 */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_COUNT_DESC
value|0x00400000
end_define

begin_comment
comment|/* Enable the counting of desc.                                               still to be processed. */
end_comment

begin_comment
comment|/* Flow Control Constants */
end_comment

begin_define
define|#
directive|define
name|FLOW_CONTROL_ADDRESS_LOW
value|0x00C28001
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_ADDRESS_HIGH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_TYPE
value|0x8808
end_define

begin_comment
comment|/* 802.1q VLAN Packet Size */
end_comment

begin_define
define|#
directive|define
name|VLAN_TAG_SIZE
value|4
end_define

begin_comment
comment|/* 802.3ac tag (not DMA'd) */
end_comment

begin_define
define|#
directive|define
name|E1000_VLAN_FILTER_TBL_SIZE
value|128
end_define

begin_comment
comment|/* VLAN Filter Table (4096 bits) */
end_comment

begin_comment
comment|/* Receive Address */
end_comment

begin_comment
comment|/* Number of high/low register pairs in the RAR. The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor.  * Technically, we have 16 spots.  However, we reserve one of these spots  * (RAR[15]) for our directed address used by controllers with  * manageability enabled, allowing us room for 15 multicast addresses.  */
end_comment

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES
value|15
end_define

begin_define
define|#
directive|define
name|E1000_RAH_AV
value|0x80000000
end_define

begin_comment
comment|/* Receive descriptor valid */
end_comment

begin_comment
comment|/* Error Codes */
end_comment

begin_define
define|#
directive|define
name|E1000_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|E1000_ERR_NVM
value|1
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PHY
value|2
end_define

begin_define
define|#
directive|define
name|E1000_ERR_CONFIG
value|3
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PARAM
value|4
end_define

begin_define
define|#
directive|define
name|E1000_ERR_MAC_INIT
value|5
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PHY_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|E1000_ERR_RESET
value|9
end_define

begin_define
define|#
directive|define
name|E1000_ERR_MASTER_REQUESTS_PENDING
value|10
end_define

begin_define
define|#
directive|define
name|E1000_ERR_HOST_INTERFACE_COMMAND
value|11
end_define

begin_define
define|#
directive|define
name|E1000_BLK_PHY_RESET
value|12
end_define

begin_define
define|#
directive|define
name|E1000_ERR_SWFW_SYNC
value|13
end_define

begin_define
define|#
directive|define
name|E1000_NOT_IMPLEMENTED
value|14
end_define

begin_comment
comment|/* Loop limit on how long we wait for auto-negotiation to complete */
end_comment

begin_define
define|#
directive|define
name|FIBER_LINK_UP_LIMIT
value|50
end_define

begin_define
define|#
directive|define
name|COPPER_LINK_UP_LIMIT
value|10
end_define

begin_define
define|#
directive|define
name|PHY_AUTO_NEG_LIMIT
value|45
end_define

begin_define
define|#
directive|define
name|PHY_FORCE_LIMIT
value|20
end_define

begin_comment
comment|/* Number of 100 microseconds we wait for PCI Express master disable */
end_comment

begin_define
define|#
directive|define
name|MASTER_DISABLE_TIMEOUT
value|800
end_define

begin_comment
comment|/* Number of milliseconds we wait for PHY configuration done after MAC reset */
end_comment

begin_define
define|#
directive|define
name|PHY_CFG_TIMEOUT
value|100
end_define

begin_comment
comment|/* Number of 2 milliseconds we wait for acquiring MDIO ownership. */
end_comment

begin_define
define|#
directive|define
name|MDIO_OWNERSHIP_TIMEOUT
value|10
end_define

begin_comment
comment|/* Number of milliseconds for NVM auto read done after MAC reset. */
end_comment

begin_define
define|#
directive|define
name|AUTO_READ_DONE_TIMEOUT
value|10
end_define

begin_comment
comment|/* Flow Control */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH_RTH
value|0x0000FFF8
end_define

begin_comment
comment|/* Mask Bits[15:3] for RTH */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH_XFCE
value|0x80000000
end_define

begin_comment
comment|/* External Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL_RTL
value|0x0000FFF8
end_define

begin_comment
comment|/* Mask Bits[15:3] for RTL */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL_XONE
value|0x80000000
end_define

begin_comment
comment|/* Enable XON frame transmission */
end_comment

begin_comment
comment|/* Transmit Configuration Word */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_FD
value|0x00000020
end_define

begin_comment
comment|/* TXCW full duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_HD
value|0x00000040
end_define

begin_comment
comment|/* TXCW half duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_PAUSE
value|0x00000080
end_define

begin_comment
comment|/* TXCW sym pause request */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_ASM_DIR
value|0x00000100
end_define

begin_comment
comment|/* TXCW astm pause direction */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_PAUSE_MASK
value|0x00000180
end_define

begin_comment
comment|/* TXCW pause request mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_RF
value|0x00003000
end_define

begin_comment
comment|/* TXCW remote fault */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_NP
value|0x00008000
end_define

begin_comment
comment|/* TXCW next page */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_CW
value|0x0000ffff
end_define

begin_comment
comment|/* TxConfigWord mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_TXC
value|0x40000000
end_define

begin_comment
comment|/* Transmit Config control */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_ANE
value|0x80000000
end_define

begin_comment
comment|/* Auto-neg enable */
end_comment

begin_comment
comment|/* Receive Configuration Word */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_CW
value|0x0000ffff
end_define

begin_comment
comment|/* RxConfigWord mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_NC
value|0x04000000
end_define

begin_comment
comment|/* Receive config no carrier */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_IV
value|0x08000000
end_define

begin_comment
comment|/* Receive config invalid */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_CC
value|0x10000000
end_define

begin_comment
comment|/* Receive config change */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_C
value|0x20000000
end_define

begin_comment
comment|/* Receive config */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_SYNCH
value|0x40000000
end_define

begin_comment
comment|/* Receive config synch */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_ANC
value|0x80000000
end_define

begin_comment
comment|/* Auto-neg complete */
end_comment

begin_comment
comment|/* PCI Express Control */
end_comment

begin_define
define|#
directive|define
name|E1000_GCR_RXD_NO_SNOOP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_GCR_RXDSCW_NO_SNOOP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_GCR_RXDSCR_NO_SNOOP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXD_NO_SNOOP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXDSCW_NO_SNOOP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXDSCR_NO_SNOOP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIE_NO_SNOOP_ALL
value|(E1000_GCR_RXD_NO_SNOOP         | \                            E1000_GCR_RXDSCW_NO_SNOOP      | \                            E1000_GCR_RXDSCR_NO_SNOOP      | \                            E1000_GCR_TXD_NO_SNOOP         | \                            E1000_GCR_TXDSCW_NO_SNOOP      | \                            E1000_GCR_TXDSCR_NO_SNOOP)
end_define

begin_comment
comment|/* PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_MSB
value|0x0040
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_COLL_TEST_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_FULL_DUPLEX
value|0x0100
end_define

begin_comment
comment|/* FDX =1, half duplex =0 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESTART_AUTO_NEG
value|0x0200
end_define

begin_comment
comment|/* Restart auto negotiation */
end_comment

begin_define
define|#
directive|define
name|MII_CR_ISOLATE
value|0x0400
end_define

begin_comment
comment|/* Isolate PHY from MII */
end_comment

begin_define
define|#
directive|define
name|MII_CR_POWER_DOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|MII_CR_AUTO_NEG_EN
value|0x1000
end_define

begin_comment
comment|/* Auto Neg Enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_LSB
value|0x2000
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 0 = normal, 1 = loopback */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESET
value|0x8000
end_define

begin_comment
comment|/* 0 = normal, 1 = PHY reset */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_10
value|0x0000
end_define

begin_comment
comment|/* PHY Status Register */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_CAPS
value|0x0001
end_define

begin_comment
comment|/* Extended register capabilities */
end_comment

begin_define
define|#
directive|define
name|MII_SR_JABBER_DETECT
value|0x0002
end_define

begin_comment
comment|/* Jabber Detected */
end_comment

begin_define
define|#
directive|define
name|MII_SR_LINK_STATUS
value|0x0004
end_define

begin_comment
comment|/* Link Status 1 = link */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_CAPS
value|0x0008
end_define

begin_comment
comment|/* Auto Neg Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_REMOTE_FAULT
value|0x0010
end_define

begin_comment
comment|/* Remote Fault Detect */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_COMPLETE
value|0x0020
end_define

begin_comment
comment|/* Auto Neg Complete */
end_comment

begin_define
define|#
directive|define
name|MII_SR_PREAMBLE_SUPPRESS
value|0x0040
end_define

begin_comment
comment|/* Preamble may be suppressed */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_STATUS
value|0x0100
end_define

begin_comment
comment|/* Ext. status info in Reg 0x0F */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_HD_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T2 Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_FD_CAPS
value|0x0400
end_define

begin_comment
comment|/* 100T2 Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_HD_CAPS
value|0x0800
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_FD_CAPS
value|0x1000
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_HD_CAPS
value|0x2000
end_define

begin_comment
comment|/* 100X  Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_FD_CAPS
value|0x4000
end_define

begin_comment
comment|/* 100X  Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T4_CAPS
value|0x8000
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_comment
comment|/* Autoneg Advertisement Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_SELECTOR_FIELD
value|0x0001
end_define

begin_comment
comment|/* indicates IEEE 802.3 CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* Remote Fault detected */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Link Partner Ability Register (Base Page) */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_SELECTOR_FIELD
value|0x0000
end_define

begin_comment
comment|/* LP protocol selector field */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* LP is 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* LP Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* LP Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* LP has detected Remote Fault */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_comment
comment|/* LP has rx'd link code word */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Autoneg Expansion Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NWAY_CAPS
value|0x0001
end_define

begin_comment
comment|/* LP has Auto Neg Capability */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAGE_RXD
value|0x0002
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_NEXT_PAGE_CAPS
value|0x0004
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NEXT_PAGE_CAPS
value|0x0008
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAR_DETECT_FAULT
value|0x0010
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_comment
comment|/* 1000BASE-T Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_ASYM_PAUSE
value|0x0080
end_define

begin_comment
comment|/* Advertise asymmetric pause bit */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_HD_CAPS
value|0x0100
end_define

begin_comment
comment|/* Advertise 1000T HD capability */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_FD_CAPS
value|0x0200
end_define

begin_comment
comment|/* Advertise 1000T FD capability  */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_REPEATER_DTE
value|0x0400
end_define

begin_comment
comment|/* 1=Repeater/switch device port */
end_comment

begin_comment
comment|/* 0=DTE device */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_VALUE
value|0x0800
end_define

begin_comment
comment|/* 1=Configure PHY as Master */
end_comment

begin_comment
comment|/* 0=Configure PHY as Slave */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_ENABLE
value|0x1000
end_define

begin_comment
comment|/* 1=Master/Slave manual config value */
end_comment

begin_comment
comment|/* 0=Automatic Master/Slave config */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_NORMAL
value|0x0000
end_define

begin_comment
comment|/* Normal Operation */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_1
value|0x2000
end_define

begin_comment
comment|/* Transmit Waveform test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_2
value|0x4000
end_define

begin_comment
comment|/* Master Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_3
value|0x6000
end_define

begin_comment
comment|/* Slave Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_4
value|0x8000
end_define

begin_comment
comment|/* Transmitter Distortion test */
end_comment

begin_comment
comment|/* 1000BASE-T Status Register */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_IDLE_ERROR_CNT
value|0x00FF
end_define

begin_comment
comment|/* Num idle errors since last read */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_comment
comment|/* LP asymmetric pause direction bit */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_HD_CAPS
value|0x0400
end_define

begin_comment
comment|/* LP is 1000T HD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_FD_CAPS
value|0x0800
end_define

begin_comment
comment|/* LP is 1000T FD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS
value|0x2000
end_define

begin_comment
comment|/* Local receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_RES
value|0x4000
end_define

begin_comment
comment|/* 1=Local TX is Master, 0=Slave */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_FAULT
value|0x8000
end_define

begin_comment
comment|/* Master/Slave config fault */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_PHY_EXCESSIVE_IDLE_ERR_COUNT
value|5
end_define

begin_comment
comment|/* PHY 1000 MII Register/Bit Definitions */
end_comment

begin_comment
comment|/* PHY Registers defined by IEEE */
end_comment

begin_define
define|#
directive|define
name|PHY_CONTROL
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_STATUS
value|0x01
end_define

begin_comment
comment|/* Status Regiser */
end_comment

begin_define
define|#
directive|define
name|PHY_ID1
value|0x02
end_define

begin_comment
comment|/* Phy Id Reg (word 1) */
end_comment

begin_define
define|#
directive|define
name|PHY_ID2
value|0x03
end_define

begin_comment
comment|/* Phy Id Reg (word 2) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_ADV
value|0x04
end_define

begin_comment
comment|/* Autoneg Advertisement */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_ABILITY
value|0x05
end_define

begin_comment
comment|/* Link Partner Ability (Base Page) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_EXP
value|0x06
end_define

begin_comment
comment|/* Autoneg Expansion Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_NEXT_PAGE_TX
value|0x07
end_define

begin_comment
comment|/* Next Page TX */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_NEXT_PAGE
value|0x08
end_define

begin_comment
comment|/* Link Partner Next Page */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_CTRL
value|0x09
end_define

begin_comment
comment|/* 1000Base-T Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_STATUS
value|0x0A
end_define

begin_comment
comment|/* 1000Base-T Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_EXT_STATUS
value|0x0F
end_define

begin_comment
comment|/* Extended Status Reg */
end_comment

begin_comment
comment|/* NVM Control */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SK
value|0x00000001
end_define

begin_comment
comment|/* NVM Clock */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_CS
value|0x00000002
end_define

begin_comment
comment|/* NVM Chip Select */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_DI
value|0x00000004
end_define

begin_comment
comment|/* NVM Data In */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_DO
value|0x00000008
end_define

begin_comment
comment|/* NVM Data Out */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|E1000_EECD_FWE_DIS
value|0x00000010
end_define

begin_comment
comment|/* Disable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_EN
value|0x00000020
end_define

begin_comment
comment|/* Enable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|E1000_EECD_REQ
value|0x00000040
end_define

begin_comment
comment|/* NVM Access Request */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_GNT
value|0x00000080
end_define

begin_comment
comment|/* NVM Access Grant */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_PRES
value|0x00000100
end_define

begin_comment
comment|/* NVM Present */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SIZE
value|0x00000200
end_define

begin_comment
comment|/* NVM Size (0=64 word 1=256 word) */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_ADDR_BITS
value|0x00000400
end_define

begin_comment
comment|/* NVM Addressing bits based on type                                          * (0-small, 1-large) */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_TYPE
value|0x00002000
end_define

begin_comment
comment|/* NVM Type (1-SPI, 0-Microwire) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E1000_NVM_GRANT_ATTEMPTS
end_ifndef

begin_define
define|#
directive|define
name|E1000_NVM_GRANT_ATTEMPTS
value|1000
end_define

begin_comment
comment|/* NVM # attempts to gain grant */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|E1000_EECD_AUTO_RD
value|0x00000200
end_define

begin_comment
comment|/* NVM Auto Read done */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SIZE_EX_MASK
value|0x00007800
end_define

begin_comment
comment|/* NVM Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SIZE_EX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|E1000_EECD_NVADDS
value|0x00018000
end_define

begin_comment
comment|/* NVM Address Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SELSHAD
value|0x00020000
end_define

begin_comment
comment|/* Select Shadow RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_INITSRAM
value|0x00040000
end_define

begin_comment
comment|/* Initialize Shadow RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FLUPD
value|0x00080000
end_define

begin_comment
comment|/* Update FLASH */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_AUPDEN
value|0x00100000
end_define

begin_comment
comment|/* Enable Autonomous FLASH update */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SHADV
value|0x00200000
end_define

begin_comment
comment|/* Shadow RAM Data Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SEC1VAL
value|0x00400000
end_define

begin_comment
comment|/* Sector One Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SECVAL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|E1000_NVM_SWDPIN0
value|0x0001
end_define

begin_comment
comment|/* SWDPIN 0 NVM Value */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_LED_LOGIC
value|0x0020
end_define

begin_comment
comment|/* Led Logic Word */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_RW_REG_DATA
value|16
end_define

begin_comment
comment|/* Offset to data in NVM read/write registers */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_RW_REG_DONE
value|2
end_define

begin_comment
comment|/* Offset to READ/WRITE done bit */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_RW_REG_START
value|1
end_define

begin_comment
comment|/* Start operation */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_RW_ADDR_SHIFT
value|2
end_define

begin_comment
comment|/* Shift to the address bits */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_POLL_WRITE
value|1
end_define

begin_comment
comment|/* Flag for polling for write complete */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_POLL_READ
value|0
end_define

begin_comment
comment|/* Flag for polling for read complete */
end_comment

begin_define
define|#
directive|define
name|E1000_FLASH_UPDATES
value|2000
end_define

begin_comment
comment|/* NVM Word Offsets */
end_comment

begin_define
define|#
directive|define
name|NVM_COMPAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|NVM_ID_LED_SETTINGS
value|0x0004
end_define

begin_define
define|#
directive|define
name|NVM_VERSION
value|0x0005
end_define

begin_define
define|#
directive|define
name|NVM_SERDES_AMPLITUDE
value|0x0006
end_define

begin_comment
comment|/* For SERDES output amplitude adjustment. */
end_comment

begin_define
define|#
directive|define
name|NVM_PHY_CLASS_WORD
value|0x0007
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CONTROL1_REG
value|0x000A
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CONTROL2_REG
value|0x000F
end_define

begin_define
define|#
directive|define
name|NVM_SWDEF_PINS_CTRL_PORT_1
value|0x0010
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CONTROL3_PORT_B
value|0x0014
end_define

begin_define
define|#
directive|define
name|NVM_INIT_3GIO_3
value|0x001A
end_define

begin_define
define|#
directive|define
name|NVM_SWDEF_PINS_CTRL_PORT_0
value|0x0020
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CONTROL3_PORT_A
value|0x0024
end_define

begin_define
define|#
directive|define
name|NVM_CFG
value|0x0012
end_define

begin_define
define|#
directive|define
name|NVM_FLASH_VERSION
value|0x0032
end_define

begin_define
define|#
directive|define
name|NVM_CHECKSUM_REG
value|0x003F
end_define

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_0
value|0x40000
end_define

begin_comment
comment|/* MNG config cycle done */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_1
value|0x80000
end_define

begin_comment
comment|/* ...for second port */
end_comment

begin_comment
comment|/* Mask bits for fields in Word 0x0f of the NVM */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD0F_PAUSE_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|NVM_WORD0F_PAUSE
value|0x1000
end_define

begin_define
define|#
directive|define
name|NVM_WORD0F_ASM_DIR
value|0x2000
end_define

begin_define
define|#
directive|define
name|NVM_WORD0F_ANE
value|0x0800
end_define

begin_define
define|#
directive|define
name|NVM_WORD0F_SWPDIO_EXT_MASK
value|0x00F0
end_define

begin_define
define|#
directive|define
name|NVM_WORD0F_LPLU
value|0x0001
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x1a of the NVM */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD1A_ASPM_MASK
value|0x000C
end_define

begin_comment
comment|/* For checksumming, the sum of all words in the NVM should equal 0xBABA. */
end_comment

begin_define
define|#
directive|define
name|NVM_SUM
value|0xBABA
end_define

begin_define
define|#
directive|define
name|NVM_MAC_ADDR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|NVM_PBA_OFFSET_0
value|8
end_define

begin_define
define|#
directive|define
name|NVM_PBA_OFFSET_1
value|9
end_define

begin_define
define|#
directive|define
name|NVM_RESERVED_WORD
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|NVM_PHY_CLASS_A
value|0x8000
end_define

begin_define
define|#
directive|define
name|NVM_SERDES_AMPLITUDE_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|NVM_SIZE_MASK
value|0x1C00
end_define

begin_define
define|#
directive|define
name|NVM_SIZE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|NVM_WORD_SIZE_BASE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|NVM_SWDPIO_EXT_SHIFT
value|4
end_define

begin_comment
comment|/* NVM Commands - Microwire */
end_comment

begin_define
define|#
directive|define
name|NVM_READ_OPCODE_MICROWIRE
value|0x6
end_define

begin_comment
comment|/* NVM read opcode */
end_comment

begin_define
define|#
directive|define
name|NVM_WRITE_OPCODE_MICROWIRE
value|0x5
end_define

begin_comment
comment|/* NVM write opcode */
end_comment

begin_define
define|#
directive|define
name|NVM_ERASE_OPCODE_MICROWIRE
value|0x7
end_define

begin_comment
comment|/* NVM erase opcode */
end_comment

begin_define
define|#
directive|define
name|NVM_EWEN_OPCODE_MICROWIRE
value|0x13
end_define

begin_comment
comment|/* NVM erase/write enable */
end_comment

begin_define
define|#
directive|define
name|NVM_EWDS_OPCODE_MICROWIRE
value|0x10
end_define

begin_comment
comment|/* NVM erast/write disable */
end_comment

begin_comment
comment|/* NVM Commands - SPI */
end_comment

begin_define
define|#
directive|define
name|NVM_MAX_RETRY_SPI
value|5000
end_define

begin_comment
comment|/* Max wait of 5ms, for RDY signal */
end_comment

begin_define
define|#
directive|define
name|NVM_READ_OPCODE_SPI
value|0x03
end_define

begin_comment
comment|/* NVM read opcode */
end_comment

begin_define
define|#
directive|define
name|NVM_WRITE_OPCODE_SPI
value|0x02
end_define

begin_comment
comment|/* NVM write opcode */
end_comment

begin_define
define|#
directive|define
name|NVM_A8_OPCODE_SPI
value|0x08
end_define

begin_comment
comment|/* opcode bit-3 = address bit-8 */
end_comment

begin_define
define|#
directive|define
name|NVM_WREN_OPCODE_SPI
value|0x06
end_define

begin_comment
comment|/* NVM set Write Enable latch */
end_comment

begin_define
define|#
directive|define
name|NVM_WRDI_OPCODE_SPI
value|0x04
end_define

begin_comment
comment|/* NVM reset Write Enable latch */
end_comment

begin_define
define|#
directive|define
name|NVM_RDSR_OPCODE_SPI
value|0x05
end_define

begin_comment
comment|/* NVM read Status register */
end_comment

begin_define
define|#
directive|define
name|NVM_WRSR_OPCODE_SPI
value|0x01
end_define

begin_comment
comment|/* NVM write Status register */
end_comment

begin_comment
comment|/* SPI NVM Status Register */
end_comment

begin_define
define|#
directive|define
name|NVM_STATUS_RDY_SPI
value|0x01
end_define

begin_define
define|#
directive|define
name|NVM_STATUS_WEN_SPI
value|0x02
end_define

begin_define
define|#
directive|define
name|NVM_STATUS_BP0_SPI
value|0x04
end_define

begin_define
define|#
directive|define
name|NVM_STATUS_BP1_SPI
value|0x08
end_define

begin_define
define|#
directive|define
name|NVM_STATUS_WPEN_SPI
value|0x80
end_define

begin_comment
comment|/* Word definitions for ID LED Settings */
end_comment

begin_define
define|#
directive|define
name|ID_LED_RESERVED_0000
value|0x0000
end_define

begin_define
define|#
directive|define
name|ID_LED_RESERVED_FFFF
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT
value|((ID_LED_OFF1_ON2<< 12) | \                               (ID_LED_OFF1_OFF2<<  8) | \                               (ID_LED_DEF1_DEF2<<  4) | \                               (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_DEF2
value|0x1
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_ON2
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_OFF2
value|0x3
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_DEF2
value|0x4
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_ON2
value|0x5
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_OFF2
value|0x6
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_DEF2
value|0x7
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_ON2
value|0x8
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_OFF2
value|0x9
end_define

begin_define
define|#
directive|define
name|IGP_ACTIVITY_LED_MASK
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|IGP_ACTIVITY_LED_ENABLE
value|0x0300
end_define

begin_define
define|#
directive|define
name|IGP_LED3_MODE
value|0x07000000
end_define

begin_comment
comment|/* PCI/PCI-X/PCI-EX Config space */
end_comment

begin_define
define|#
directive|define
name|PCIX_COMMAND_REGISTER
value|0xE6
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_REGISTER_LO
value|0xE8
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_REGISTER_HI
value|0xEA
end_define

begin_define
define|#
directive|define
name|PCI_HEADER_TYPE_REGISTER
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCIE_LINK_STATUS
value|0x12
end_define

begin_define
define|#
directive|define
name|PCIX_COMMAND_MMRBC_MASK
value|0x000C
end_define

begin_define
define|#
directive|define
name|PCIX_COMMAND_MMRBC_SHIFT
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_SHIFT
value|0x5
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_4K
value|0x3
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_2K
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_LO_FUNC_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|PCI_HEADER_TYPE_MULTIFUNC
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIE_LINK_WIDTH_MASK
value|0x3F0
end_define

begin_define
define|#
directive|define
name|PCIE_LINK_WIDTH_SHIFT
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_ADDR_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETH_ADDR_LEN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PHY_REVISION_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|MAX_PHY_REG_ADDRESS
value|0x1F
end_define

begin_comment
comment|/* 5 bit address bus (0-0x1F) */
end_comment

begin_define
define|#
directive|define
name|MAX_PHY_MULTI_PAGE_REG
value|0xF
end_define

begin_comment
comment|/* Bit definitions for valid PHY IDs. */
end_comment

begin_comment
comment|/* I = Integrated  * E = External  */
end_comment

begin_define
define|#
directive|define
name|M88E1000_E_PHY_ID
value|0x01410C50
end_define

begin_define
define|#
directive|define
name|M88E1000_I_PHY_ID
value|0x01410C30
end_define

begin_define
define|#
directive|define
name|M88E1011_I_PHY_ID
value|0x01410C20
end_define

begin_define
define|#
directive|define
name|IGP01E1000_I_PHY_ID
value|0x02A80380
end_define

begin_define
define|#
directive|define
name|M88E1011_I_REV_4
value|0x04
end_define

begin_define
define|#
directive|define
name|M88E1111_I_PHY_ID
value|0x01410CC0
end_define

begin_define
define|#
directive|define
name|GG82563_E_PHY_ID
value|0x01410CA0
end_define

begin_define
define|#
directive|define
name|IGP03E1000_E_PHY_ID
value|0x02A80390
end_define

begin_define
define|#
directive|define
name|IFE_E_PHY_ID
value|0x02A80330
end_define

begin_define
define|#
directive|define
name|IFE_PLUS_E_PHY_ID
value|0x02A80320
end_define

begin_define
define|#
directive|define
name|IFE_C_E_PHY_ID
value|0x02A80310
end_define

begin_define
define|#
directive|define
name|M88_VENDOR
value|0x0141
end_define

begin_comment
comment|/* M88E1000 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_CTRL
value|0x10
end_define

begin_comment
comment|/* PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_STATUS
value|0x11
end_define

begin_comment
comment|/* PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_ENABLE
value|0x12
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_STATUS
value|0x13
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EXT_PHY_SPEC_CTRL
value|0x14
end_define

begin_comment
comment|/* Extended PHY Specific Control */
end_comment

begin_define
define|#
directive|define
name|M88E1000_RX_ERR_CNTR
value|0x15
end_define

begin_comment
comment|/* Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_EXT_CTRL
value|0x1A
end_define

begin_comment
comment|/* PHY extend control register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_PAGE_SELECT
value|0x1D
end_define

begin_comment
comment|/* Reg 29 for page number setting */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_GEN_CONTROL
value|0x1E
end_define

begin_comment
comment|/* Its meaning depends on reg 29 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_VCO_REG_BIT8
value|0x100
end_define

begin_comment
comment|/* Bits 8& 11 are adjusted for */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_VCO_REG_BIT11
value|0x800
end_define

begin_comment
comment|/* improved BER performance */
end_comment

begin_comment
comment|/* M88E1000 PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_JABBER_DISABLE
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber Function disabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reversal enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SQE_TEST
value|0x0004
end_define

begin_comment
comment|/* 1=SQE Test enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_CLK125_DISABLE
value|0x0010
end_define

begin_comment
comment|/* 1=CLK125 low,                                                 * 0=CLK125 toggling                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_comment
comment|/* MDI Crossover Mode bits 6:5 */
end_comment

begin_comment
comment|/* Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_comment
comment|/* Manual MDIX configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_1000T
value|0x0040
end_define

begin_comment
comment|/* 1000BASE-T: Auto crossover,                                                 *  100BASE-TX/10BASE-T:                                                 *  MDI Mode                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE
value|0x0060
end_define

begin_comment
comment|/* Auto crossover enabled                                                 * all speeds.                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_EN_10BT_EXT_DIST
value|0x0080
end_define

begin_comment
comment|/* 1=Enable Extended 10BASE-T distance                                          * (Lower 10BASE-T RX Threshold)                                          * 0=Normal 10BASE-T RX Threshold */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_comment
comment|/* 1=5-Bit interface in 100BASE-TX                                          * 0=MII interface in 100BASE-TX */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_comment
comment|/* 1=Scrambler disable */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_comment
comment|/* 1=Force link good */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_comment
comment|/* 1=Assert CRS on Transmit */
end_comment

begin_comment
comment|/* M88E1000 PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_REV_POLARITY
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity reversed */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_DOWNSHIFT
value|0x0020
end_define

begin_comment
comment|/* 1=Downshifted */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_MDIX
value|0x0040
end_define

begin_comment
comment|/* 1=MDIX; 0=MDI */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH
value|0x0380
end_define

begin_comment
comment|/* 0=<50M;1=50-80M;2=80-110M;                                             * 3=110-140M;4=>140M */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_LINK
value|0x0400
end_define

begin_comment
comment|/* 1=Link up, 0=Link down */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_comment
comment|/* 1=Speed& Duplex resolved */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_PAGE_RCVD
value|0x1000
end_define

begin_comment
comment|/* 1=Page received */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_DPLX
value|0x2000
end_define

begin_comment
comment|/* 1=Duplex 0=Half Duplex */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPEED
value|0xC000
end_define

begin_comment
comment|/* Speed, bits 14:15 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_10MBS
value|0x0000
end_define

begin_comment
comment|/* 00=10Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_100MBS
value|0x4000
end_define

begin_comment
comment|/* 01=100Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_1000MBS
value|0x8000
end_define

begin_comment
comment|/* 10=1000Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH_SHIFT
value|7
end_define

begin_comment
comment|/* M88E1000 Extended PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_FIBER_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 1=Fiber loopback */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_DOWN_NO_IDLE
value|0x8000
end_define

begin_comment
comment|/* 1=Lost lock detect enabled.                                               * Will assert lost lock and bring                                               * link down if idle not seen                                               * within 1ms in 1000BASE-T                                               */
end_comment

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the master */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_1X
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_2X
value|0x0400
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_3X
value|0x0800
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_4X
value|0x0C00
end_define

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the slave */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_DIS
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_1X
value|0x0100
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_2X
value|0x0200
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_3X
value|0x0300
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_2_5
value|0x0060
end_define

begin_comment
comment|/* 2.5 MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_25
value|0x0070
end_define

begin_comment
comment|/* 25  MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_0
value|0x0000
end_define

begin_comment
comment|/* NO  TX_CLK */
end_comment

begin_comment
comment|/* M88EC018 Rev 2 specific DownShift settings */
end_comment

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_MASK
value|0x0E00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_1X
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_2X
value|0x0200
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_3X
value|0x0400
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_4X
value|0x0600
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_5X
value|0x0800
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_6X
value|0x0A00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_7X
value|0x0C00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_8X
value|0x0E00
end_define

begin_comment
comment|/* Bits...  * 15-5: page  * 4-0: register offset  */
end_comment

begin_define
define|#
directive|define
name|GG82563_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|GG82563_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((page)<< GG82563_PAGE_SHIFT) | ((reg)& MAX_PHY_REG_ADDRESS))
end_define

begin_define
define|#
directive|define
name|GG82563_MIN_ALT_REG
value|30
end_define

begin_comment
comment|/* GG82563 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_CTRL
define|\
value|GG82563_REG(0, 16)
end_define

begin_comment
comment|/* PHY Specific Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_STATUS
define|\
value|GG82563_REG(0, 17)
end_define

begin_comment
comment|/* PHY Specific Status */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_INT_ENABLE
define|\
value|GG82563_REG(0, 18)
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_STATUS_2
define|\
value|GG82563_REG(0, 19)
end_define

begin_comment
comment|/* PHY Specific Status 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_RX_ERR_CNTR
define|\
value|GG82563_REG(0, 21)
end_define

begin_comment
comment|/* Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT
define|\
value|GG82563_REG(0, 22)
end_define

begin_comment
comment|/* Page Select */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_CTRL_2
define|\
value|GG82563_REG(0, 26)
end_define

begin_comment
comment|/* PHY Specific Control 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT_ALT
define|\
value|GG82563_REG(0, 29)
end_define

begin_comment
comment|/* Alternate Page Select */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_TEST_CLK_CTRL
define|\
value|GG82563_REG(0, 30)
end_define

begin_comment
comment|/* Test Clock Control (use reg. 29 to select) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_MAC_SPEC_CTRL
define|\
value|GG82563_REG(2, 21)
end_define

begin_comment
comment|/* MAC Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_MAC_SPEC_CTRL_2
define|\
value|GG82563_REG(2, 26)
end_define

begin_comment
comment|/* MAC Specific Control 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_DSP_DISTANCE
define|\
value|GG82563_REG(5, 26)
end_define

begin_comment
comment|/* DSP Distance */
end_comment

begin_comment
comment|/* Page 193 - Port Control Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_MODE_CTRL
define|\
value|GG82563_REG(193, 16)
end_define

begin_comment
comment|/* Kumeran Mode Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PORT_RESET
define|\
value|GG82563_REG(193, 17)
end_define

begin_comment
comment|/* Port Reset */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_REVISION_ID
define|\
value|GG82563_REG(193, 18)
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_DEVICE_ID
define|\
value|GG82563_REG(193, 19)
end_define

begin_comment
comment|/* Device ID */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PWR_MGMT_CTRL
define|\
value|GG82563_REG(193, 20)
end_define

begin_comment
comment|/* Power Management Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_RATE_ADAPT_CTRL
define|\
value|GG82563_REG(193, 25)
end_define

begin_comment
comment|/* Rate Adaptation Control */
end_comment

begin_comment
comment|/* Page 194 - KMRN Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_FIFO_CTRL_STAT
define|\
value|GG82563_REG(194, 16)
end_define

begin_comment
comment|/* FIFO's Control/Status */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_CTRL
define|\
value|GG82563_REG(194, 17)
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_INBAND_CTRL
define|\
value|GG82563_REG(194, 18)
end_define

begin_comment
comment|/* Inband Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_DIAGNOSTIC
define|\
value|GG82563_REG(194, 19)
end_define

begin_comment
comment|/* Diagnostic */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ACK_TIMEOUTS
define|\
value|GG82563_REG(194, 20)
end_define

begin_comment
comment|/* Acknowledge Timeouts */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ADV_ABILITY
define|\
value|GG82563_REG(194, 21)
end_define

begin_comment
comment|/* Advertised Ability */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_LINK_PARTNER_ADV_ABILITY
define|\
value|GG82563_REG(194, 23)
end_define

begin_comment
comment|/* Link Partner Advertised Ability */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ADV_NEXT_PAGE
define|\
value|GG82563_REG(194, 24)
end_define

begin_comment
comment|/* Advertised Next Page */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_LINK_PARTNER_ADV_NEXT_PAGE
define|\
value|GG82563_REG(194, 25)
end_define

begin_comment
comment|/* Link Partner Advertised Next page */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_MISC
define|\
value|GG82563_REG(194, 26)
end_define

begin_comment
comment|/* Misc. */
end_comment

begin_comment
comment|/* MDI Control */
end_comment

begin_define
define|#
directive|define
name|E1000_MDIC_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_REG_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_REG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_PHY_MASK
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_PHY_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_OP_WRITE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_OP_READ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_READY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_INT_EN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_ERROR
value|0x40000000
end_define

begin_comment
comment|/* SerDes Control */
end_comment

begin_define
define|#
directive|define
name|E1000_GEN_CTL_READY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_GEN_CTL_ADDRESS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_GEN_POLL_TIMEOUT
value|640
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

