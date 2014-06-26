begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

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
name|E1000_WUC_PHY_WAKE
value|0x00000100
end_define

begin_comment
comment|/* if PHY supports wakeup */
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
name|E1000_WUFC_FLX0
value|0x00010000
end_define

begin_comment
comment|/* Flexible Filter 0 Enable */
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

begin_comment
comment|/* Extended Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LPCD
value|0x00000004
end_define

begin_comment
comment|/* LCD Power Cycle Done */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP4_DATA
value|0x00000010
end_define

begin_comment
comment|/* SW Definable Pin 4 data */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP6_DATA
value|0x00000040
end_define

begin_comment
comment|/* SW Definable Pin 6 data */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP3_DATA
value|0x00000080
end_define

begin_comment
comment|/* SW Definable Pin 3 data */
end_comment

begin_comment
comment|/* SDP 4/5 (bits 8,9) are reserved in>= 82575 */
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
name|E1000_CTRL_EXT_SDP6_DIR
value|0x00000400
end_define

begin_comment
comment|/* Direction of SDP6 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP3_DIR
value|0x00000800
end_define

begin_comment
comment|/* Direction of SDP3 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_FORCE_SMBUS
value|0x00000800
end_define

begin_comment
comment|/* Force SMBus mode */
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

begin_comment
comment|/* Physical Func Reset Done Indication */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PFRSTD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDLPE
value|0X00040000
end_define

begin_comment
comment|/* SerDes Low Power Enable */
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
name|E1000_CTRL_EXT_DMA_DYN_CLK_EN
value|0x00080000
end_define

begin_comment
comment|/* DMA Dynamic Clk Gating */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_MASK
value|0x00C00000
end_define

begin_comment
comment|/* Offset of the link mode field in Ctrl Ext register */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_OFFSET
value|22
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_1000BASE_KX
value|0x00400000
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
name|E1000_CTRL_EXT_LINK_MODE_PCIE_SERDES
value|0x00C00000
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
name|E1000_CTRL_EXT_DRV_LOAD
value|0x10000000
end_define

begin_comment
comment|/* Drv loaded bit for FW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IAME
value|0x08000000
end_define

begin_comment
comment|/* Int ACK Auto-mask */
end_comment

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
name|E1000_CTRL_EXT_LSECCK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PHYPDEN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_REG_ADDR_SHIFT
value|16
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
name|E1000_I2CCMD_READY
value|0x20000000
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
name|E1000_I2CCMD_SFP_DATA_ADDR
parameter_list|(
name|a
parameter_list|)
value|(0x0000 + (a))
end_define

begin_define
define|#
directive|define
name|E1000_I2CCMD_SFP_DIAG_ADDR
parameter_list|(
name|a
parameter_list|)
value|(0x0100 + (a))
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

begin_define
define|#
directive|define
name|E1000_IVAR_VALID
value|0x80
end_define

begin_define
define|#
directive|define
name|E1000_GPIE_NSICR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_GPIE_MSIX_MODE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|E1000_GPIE_EIAME
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_GPIE_PBA
value|0x80000000
end_define

begin_comment
comment|/* Receive Descriptor bit definitions */
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
comment|/* UDP xsum calculated */
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
name|E1000_RXDEXT_STATERR_TST
value|0x00000100
end_define

begin_comment
comment|/* Time Stamp taken */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_LB
value|0x00040000
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
value|( \ 	E1000_RXD_ERR_CE  |		\ 	E1000_RXD_ERR_SE  |		\ 	E1000_RXD_ERR_SEQ |		\ 	E1000_RXD_ERR_CXE |		\ 	E1000_RXD_ERR_RXE)
end_define

begin_comment
comment|/* Same mask, but for extended and packet split descriptors */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDEXT_ERR_FRAME_ERR_MASK
value|( \ 	E1000_RXDEXT_STATERR_CE  |	\ 	E1000_RXDEXT_STATERR_SE  |	\ 	E1000_RXDEXT_STATERR_SEQ |	\ 	E1000_RXDEXT_STATERR_CXE |	\ 	E1000_RXDEXT_STATERR_RXE)
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
name|E1000_MANC_ARP_EN
value|0x00002000
end_define

begin_comment
comment|/* Enable ARP Request Filtering */
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
name|E1000_MANC_BLK_PHY_RST_ON_IDE
value|0x00040000
end_define

begin_comment
comment|/* Block phy resets */
end_comment

begin_comment
comment|/* Enable MAC address filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MAC_ADDR_FILTER
value|0x00100000
end_define

begin_comment
comment|/* Enable MNG packets to host memory */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MNG2HOST
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_MANC2H_PORT_623
value|0x00000020
end_define

begin_comment
comment|/* Port 0x26f */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC2H_PORT_664
value|0x00000040
end_define

begin_comment
comment|/* Port 0x298 */
end_comment

begin_define
define|#
directive|define
name|E1000_MDEF_PORT_623
value|0x00000800
end_define

begin_comment
comment|/* Port 0x26f */
end_comment

begin_define
define|#
directive|define
name|E1000_MDEF_PORT_664
value|0x00000400
end_define

begin_comment
comment|/* Port 0x298 */
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
comment|/* unicast promisc enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MPE
value|0x00000010
end_define

begin_comment
comment|/* multicast promisc enable */
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
name|E1000_RCTL_LBM_TCVR
value|0x000000C0
end_define

begin_comment
comment|/* tcvr loopback mode */
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
comment|/* Rx desc min thresh size */
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
name|E1000_RCTL_MO_3
value|0x00003000
end_define

begin_comment
comment|/* multicast offset 15:4 */
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
comment|/* Rx buffer size 2048 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_1024
value|0x00010000
end_define

begin_comment
comment|/* Rx buffer size 1024 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_512
value|0x00020000
end_define

begin_comment
comment|/* Rx buffer size 512 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_256
value|0x00030000
end_define

begin_comment
comment|/* Rx buffer size 256 */
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
comment|/* Rx buffer size 16384 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_8192
value|0x00020000
end_define

begin_comment
comment|/* Rx buffer size 8192 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_4096
value|0x00030000
end_define

begin_comment
comment|/* Rx buffer size 4096 */
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

begin_comment
comment|/* Use byte values for the following shift parameters  * Usage:  *     psrctl |= (((ROUNDUP(value0, 128)>> E1000_PSRCTL_BSIZE0_SHIFT)&  *		  E1000_PSRCTL_BSIZE0_MASK) |  *		((ROUNDUP(value1, 1024)>> E1000_PSRCTL_BSIZE1_SHIFT)&  *		  E1000_PSRCTL_BSIZE1_MASK) |  *		((ROUNDUP(value2, 1024)<< E1000_PSRCTL_BSIZE2_SHIFT)&  *		  E1000_PSRCTL_BSIZE2_MASK) |  *		((ROUNDUP(value3, 1024)<< E1000_PSRCTL_BSIZE3_SHIFT) |;  *		  E1000_PSRCTL_BSIZE3_MASK))  * where value0 = [128..16256],  default=256  *       value1 = [1024..64512], default=4096  *       value2 = [0..64512],    default=4096  *       value3 = [0..64512],    default=0  */
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
value|0x01
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY0_SM
value|0x02
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY1_SM
value|0x04
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_CSR_SM
value|0x08
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY2_SM
value|0x20
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY3_SM
value|0x40
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_SW_MNG_SM
value|0x400
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
comment|/*Blocks new Master reqs */
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
name|E1000_CTRL_LANPHYPC_OVERRIDE
value|0x00010000
end_define

begin_comment
comment|/* SW control of LANPHYPC */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_LANPHYPC_VALUE
value|0x00020000
end_define

begin_comment
comment|/* SW value of LANPHYPC */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_MEHE
value|0x00080000
end_define

begin_comment
comment|/* Memory Error Handling Enable */
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
name|E1000_CTRL_ADVD3WUC
value|0x00100000
end_define

begin_comment
comment|/* D3 WUC */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EN_PHY_PWR_MGMT
value|0x00200000
end_define

begin_comment
comment|/* PHY PM enable */
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
name|E1000_CTRL_I2C_ENA
value|0x02000000
end_define

begin_comment
comment|/* I2C enable */
end_comment

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
name|E1000_CONNSW_ENRGSRC
value|0x4
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_PHYSD
value|0x400
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_PHY_PDN
value|0x800
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_SERDESD
value|0x200
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_AUTOSENSE_CONF
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_CONNSW_AUTOSENSE_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_PCS_CFG_PCS_EN
value|8
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
name|E1000_PCS_LCTL_FORCE_FCTRL
value|0x80
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
comment|/* Duplex 0=half 1=full */
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
comment|/* Lan Init Compltn by NVM */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PHYRA
value|0x00000400
end_define

begin_comment
comment|/* PHY Reset Asserted */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_GIO_MASTER_ENABLE
value|0x00080000
end_define

begin_comment
comment|/* Master request status */
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
name|E1000_STATUS_2P5_SKU
value|0x00001000
end_define

begin_comment
comment|/* Val of 2.5GBE SKU strap */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_2P5_SKU_OVER
value|0x00002000
end_define

begin_comment
comment|/* Val of 2.5GBE SKU Over */
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

begin_comment
comment|/* Constants used to interpret the masked PCI-X bus speed. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_66
value|0x00000000
end_define

begin_comment
comment|/* PCI-X bus spd 50-66MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_100
value|0x00004000
end_define

begin_comment
comment|/* PCI-X bus spd 66-100MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_133
value|0x00008000
end_define

begin_comment
comment|/* PCI-X bus spd 100-133MHz*/
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
name|SPEED_2500
value|2500
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
value|( \ 	ADVERTISE_10_HALF | ADVERTISE_10_FULL | ADVERTISE_100_HALF | \ 	ADVERTISE_100_FULL | ADVERTISE_1000_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_NOT_GIG
value|( \ 	ADVERTISE_10_HALF | ADVERTISE_10_FULL | ADVERTISE_100_HALF | \ 	ADVERTISE_100_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_100_SPEED
value|(ADVERTISE_100_HALF | ADVERTISE_100_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_10_SPEED
value|(ADVERTISE_10_HALF | ADVERTISE_10_FULL)
end_define

begin_define
define|#
directive|define
name|E1000_ALL_HALF_DUPLEX
value|(ADVERTISE_10_HALF | ADVERTISE_100_HALF)
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
name|E1000_PHY_LED0_MODE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|E1000_PHY_LED0_IVRT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_PHY_LED0_MASK
value|0x0000001F
end_define

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
name|E1000_LEDCTL_MODE_LINK_UP
value|0x2
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
comment|/* Desc extension (0 = legacy) */
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

begin_define
define|#
directive|define
name|E1000_TXD_EXTCMD_TSTAMP
value|0x00000010
end_define

begin_comment
comment|/* IEEE1588 Timestamp packet */
end_comment

begin_comment
comment|/* Transmit Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EN
value|0x00000002
end_define

begin_comment
comment|/* enable Tx */
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
name|E1000_TCTL_RTLC
value|0x01000000
end_define

begin_comment
comment|/* Re-transmit on late collision */
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

begin_define
define|#
directive|define
name|E1000_SCTL_ENABLE_SERDES_LOOPBACK
value|0x0410
end_define

begin_comment
comment|/* Receive Checksum Control */
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
name|E1000_RFCTL_ACK_DIS
value|0x00001000
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

begin_define
define|#
directive|define
name|E1000_RFCTL_LEF
value|0x00040000
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

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGT
value|10
end_define

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
name|DEFAULT_82542_TIPG_IPGR1
value|2
end_define

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

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGR2
value|10
end_define

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

begin_define
define|#
directive|define
name|E1000_TX_PTR_GAP
value|0x1F
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
name|E1000_EXTCNF_CTRL_OEM_WRITE_ENABLE
value|0x00000008
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
name|E1000_EXTCNF_CTRL_GATE_PHY_CFG
value|0x00000080
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
comment|/* Low Power IDLE Control */
end_comment

begin_define
define|#
directive|define
name|E1000_LPIC_LPIET_SHIFT
value|24
end_define

begin_comment
comment|/* Low Power Idle Entry Time */
end_comment

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
comment|/* 8KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_10K
value|0x000A
end_define

begin_comment
comment|/* 10KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_12K
value|0x000C
end_define

begin_comment
comment|/* 12KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_14K
value|0x000E
end_define

begin_comment
comment|/* 14KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_16K
value|0x0010
end_define

begin_comment
comment|/* 16KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_18K
value|0x0012
end_define

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
name|E1000_PBA_26K
value|0x001A
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
name|E1000_PBA_35K
value|0x0023
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
comment|/* 48KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_64K
value|0x0040
end_define

begin_comment
comment|/* 64KB */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_RXA_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|E1000_PBS_16K
value|E1000_PBA_16K
end_define

begin_comment
comment|/* Uncorrectable/correctable ECC Error counts and enable bits */
end_comment

begin_define
define|#
directive|define
name|E1000_PBECCSTS_CORR_ERR_CNT_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|E1000_PBECCSTS_UNCORR_ERR_CNT_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|E1000_PBECCSTS_UNCORR_ERR_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_PBECCSTS_ECC_ENABLE
value|0x00010000
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
name|E1000_SWSM_DRV_LOAD
value|0x00000008
end_define

begin_comment
comment|/* Driver Loaded Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM2_LOCK
value|0x00000002
end_define

begin_comment
comment|/* Secondary driver semaphore bit */
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
comment|/* Rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXDMT0
value|0x00000010
end_define

begin_comment
comment|/* Rx desc min. threshold (0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXO
value|0x00000040
end_define

begin_comment
comment|/* Rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXT0
value|0x00000080
end_define

begin_comment
comment|/* Rx timer intr (ring 0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_VMMB
value|0x00000100
end_define

begin_comment
comment|/* VM MB event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXCFG
value|0x00000400
end_define

begin_comment
comment|/* Rx /c/ ordered set */
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
name|E1000_ICR_MNG
value|0x00040000
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_ECCER
value|0x00400000
end_define

begin_comment
comment|/* Uncorrectable ECC Error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TS
value|0x00080000
end_define

begin_comment
comment|/* Time Sync Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_DRSTA
value|0x40000000
end_define

begin_comment
comment|/* Device Reset Asserted */
end_comment

begin_comment
comment|/* If this bit asserted, the driver should claim the interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_INT_ASSERTED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_ICR_DOUTSYNC
value|0x10000000
end_define

begin_comment
comment|/* NIC DMA out of sync */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXQ0
value|0x00100000
end_define

begin_comment
comment|/* Rx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXQ1
value|0x00200000
end_define

begin_comment
comment|/* Rx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXQ0
value|0x00400000
end_define

begin_comment
comment|/* Tx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXQ1
value|0x00800000
end_define

begin_comment
comment|/* Tx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_OTHER
value|0x01000000
end_define

begin_comment
comment|/* Other Interrupts */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_FER
value|0x00400000
end_define

begin_comment
comment|/* Fatal Error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_THS
value|0x00800000
end_define

begin_comment
comment|/* ICR.THS: Thermal Sensor Event*/
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_MDDET
value|0x10000000
end_define

begin_comment
comment|/* Malicious Driver Detect */
end_comment

begin_define
define|#
directive|define
name|E1000_ITR_MASK
value|0x000FFFFF
end_define

begin_comment
comment|/* ITR value bitfield */
end_comment

begin_define
define|#
directive|define
name|E1000_ITR_MULT
value|256
end_define

begin_comment
comment|/* ITR mulitplier in nsec */
end_comment

begin_comment
comment|/* PBA ECC Register */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC_COUNTER_MASK
value|0xFFF00000
end_define

begin_comment
comment|/* ECC counter mask */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC_COUNTER_SHIFT
value|20
end_define

begin_comment
comment|/* ECC counter shift value */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC_CORR_EN
value|0x00000001
end_define

begin_comment
comment|/* Enable ECC error correction */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC_STAT_CLR
value|0x00000002
end_define

begin_comment
comment|/* Clear ECC error counter */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC_INT_EN
value|0x00000004
end_define

begin_comment
comment|/* Enable ICR bit 5 on ECC error */
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
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXT0   = Receiver Timer Interrupt (ring 0)  *   o TXDW   = Transmit Descriptor Written Back  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error  *   o LSC    = Link Status Change  */
end_comment

begin_define
define|#
directive|define
name|IMS_ENABLE_MASK
value|( \ 	E1000_IMS_RXT0   |    \ 	E1000_IMS_TXDW   |    \ 	E1000_IMS_RXDMT0 |    \ 	E1000_IMS_RXSEQ  |    \ 	E1000_IMS_LSC)
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
comment|/* Tx desc written back */
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
name|E1000_IMS_VMMB
value|E1000_ICR_VMMB
end_define

begin_comment
comment|/* Mail box activity */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* Rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* Rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* Rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* Rx timer intr */
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
name|E1000_IMS_ECCER
value|E1000_ICR_ECCER
end_define

begin_comment
comment|/* Uncorrectable ECC Error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TS
value|E1000_ICR_TS
end_define

begin_comment
comment|/* Time Sync Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DRSTA
value|E1000_ICR_DRSTA
end_define

begin_comment
comment|/* Device Reset Asserted */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DOUTSYNC
value|E1000_ICR_DOUTSYNC
end_define

begin_comment
comment|/* NIC DMA out of sync */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXQ0
value|E1000_ICR_RXQ0
end_define

begin_comment
comment|/* Rx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXQ1
value|E1000_ICR_RXQ1
end_define

begin_comment
comment|/* Rx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXQ0
value|E1000_ICR_TXQ0
end_define

begin_comment
comment|/* Tx Queue 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXQ1
value|E1000_ICR_TXQ1
end_define

begin_comment
comment|/* Tx Queue 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_OTHER
value|E1000_ICR_OTHER
end_define

begin_comment
comment|/* Other Interrupts */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_FER
value|E1000_ICR_FER
end_define

begin_comment
comment|/* Fatal Error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_THS
value|E1000_ICR_THS
end_define

begin_comment
comment|/* ICR.TS: Thermal Sensor Event*/
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_MDDET
value|E1000_ICR_MDDET
end_define

begin_comment
comment|/* Malicious Driver Detect */
end_comment

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
comment|/* Rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* Rx desc min. threshold */
end_comment

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

begin_define
define|#
directive|define
name|E1000_EITR_ITR_INT_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* E1000_EITR_CNT_IGNR is only for 82576 and newer */
end_comment

begin_define
define|#
directive|define
name|E1000_EITR_CNT_IGNR
value|0x80000000
end_define

begin_comment
comment|/* Don't reset counters on write */
end_comment

begin_define
define|#
directive|define
name|E1000_EITR_INTERVAL
value|0x00007FFC
end_define

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

begin_comment
comment|/* Enable the counting of descriptors still to be processed. */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_COUNT_DESC
value|0x00400000
end_define

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
comment|/* Receive Address  * Number of high/low register pairs in the RAR. The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor.  * Technically, we have 16 spots.  However, we reserve one of these spots  * (RAR[15]) for our directed address used by controllers with  * manageability enabled, allowing us room for 15 multicast addresses.  */
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

begin_define
define|#
directive|define
name|E1000_RAL_MAC_ADDR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|E1000_RAH_MAC_ADDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|E1000_RAH_QUEUE_MASK_82575
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|E1000_RAH_POOL_1
value|0x00040000
end_define

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

begin_define
define|#
directive|define
name|E1000_ERR_MBX
value|15
end_define

begin_define
define|#
directive|define
name|E1000_ERR_INVALID_ARGUMENT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_ERR_NO_SPACE
value|17
end_define

begin_define
define|#
directive|define
name|E1000_ERR_NVM_PBA_SECTION
value|18
end_define

begin_define
define|#
directive|define
name|E1000_ERR_I2C
value|19
end_define

begin_define
define|#
directive|define
name|E1000_ERR_INVM_VALUE_NOT_FOUND
value|20
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
name|E1000_RXCW_IV
value|0x08000000
end_define

begin_comment
comment|/* Receive config invalid */
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
name|E1000_TSYNCTXCTL_VALID
value|0x00000001
end_define

begin_comment
comment|/* Tx timestamp valid */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCTXCTL_ENABLED
value|0x00000010
end_define

begin_comment
comment|/* enable Tx timestamping */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_VALID
value|0x00000001
end_define

begin_comment
comment|/* Rx timestamp valid */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_MASK
value|0x0000000E
end_define

begin_comment
comment|/* Rx type mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_L2_V2
value|0x00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_L4_V1
value|0x02
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_L2_L4_V2
value|0x04
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_ALL
value|0x08
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_TYPE_EVENT_V2
value|0x0A
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_ENABLED
value|0x00000010
end_define

begin_comment
comment|/* enable Rx timestamping */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL_SYSCFI
value|0x00000020
end_define

begin_comment
comment|/* Sys clock frequency */
end_comment

begin_define
define|#
directive|define
name|E1000_RXMTRL_PTP_V1_SYNC_MESSAGE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_RXMTRL_PTP_V1_DELAY_REQ_MESSAGE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_RXMTRL_PTP_V2_SYNC_MESSAGE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_RXMTRL_PTP_V2_DELAY_REQ_MESSAGE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_CTRLT_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_SYNC_MESSAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_DELAY_REQ_MESSAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_FOLLOWUP_MESSAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_DELAY_RESP_MESSAGE
value|0x03
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V1_MANAGEMENT_MESSAGE
value|0x04
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_MSGID_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_SYNC_MESSAGE
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_DELAY_REQ_MESSAGE
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_PATH_DELAY_REQ_MESSAGE
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_PATH_DELAY_RESP_MESSAGE
value|0x0300
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_FOLLOWUP_MESSAGE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_DELAY_RESP_MESSAGE
value|0x0900
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_PATH_DELAY_FOLLOWUP_MESSAGE
value|0x0A00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_ANNOUNCE_MESSAGE
value|0x0B00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_SIGNALLING_MESSAGE
value|0x0C00
end_define

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG_PTP_V2_MANAGEMENT_MESSAGE
value|0x0D00
end_define

begin_define
define|#
directive|define
name|E1000_TIMINCA_16NS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_TIMINCA_INCPERIOD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_TIMINCA_INCVALUE_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|E1000_TSICR_TXTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_TSIM_TXTS
value|0x00000002
end_define

begin_comment
comment|/* TUPLE Filtering Configuration */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_DISABLE_MASK
value|0xF0008000
end_define

begin_comment
comment|/* TTQF Disable Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_QUEUE_ENABLE
value|0x100
end_define

begin_comment
comment|/* TTQF Queue Enable Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_PROTOCOL_MASK
value|0xFF
end_define

begin_comment
comment|/* TTQF Protocol Mask */
end_comment

begin_comment
comment|/* TTQF TCP Bit, shift with E1000_TTQF_PROTOCOL SHIFT */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_PROTOCOL_TCP
value|0x0
end_define

begin_comment
comment|/* TTQF UDP Bit, shift with E1000_TTQF_PROTOCOL_SHIFT */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_PROTOCOL_UDP
value|0x1
end_define

begin_comment
comment|/* TTQF SCTP Bit, shift with E1000_TTQF_PROTOCOL_SHIFT */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_PROTOCOL_SCTP
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_TTQF_PROTOCOL_SHIFT
value|5
end_define

begin_comment
comment|/* TTQF Protocol Shift */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_QUEUE_SHIFT
value|16
end_define

begin_comment
comment|/* TTQF Queue Shfit */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_RX_QUEUE_MASK
value|0x70000
end_define

begin_comment
comment|/* TTQF Queue Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF_MASK_ENABLE
value|0x10000000
end_define

begin_comment
comment|/* TTQF Mask Enable Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR_CLEAR_MASK
value|0xF001FFFF
end_define

begin_comment
comment|/* IMIR Reg Clear Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR_PORT_BYPASS
value|0x20000
end_define

begin_comment
comment|/* IMIR Port Bypass Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR_PRIORITY_SHIFT
value|29
end_define

begin_comment
comment|/* IMIR Priority Shift */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT_CLEAR_MASK
value|0x7FFFF
end_define

begin_comment
comment|/* IMIREXT Reg Clear Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_MDICNFG_EXT_MDIO
value|0x80000000
end_define

begin_comment
comment|/* MDI ext/int destination */
end_comment

begin_define
define|#
directive|define
name|E1000_MDICNFG_COM_MDIO
value|0x40000000
end_define

begin_comment
comment|/* MDI shared w/ lan 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_MDICNFG_PHY_MASK
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|E1000_MDICNFG_PHY_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|E1000_MEDIA_PORT_COPPER
value|1
end_define

begin_define
define|#
directive|define
name|E1000_MEDIA_PORT_OTHER
value|2
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_AUTO_COPPER_SGMII
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_AUTO_COPPER_BASEX
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_STATUS_LINK
value|0x0004
end_define

begin_comment
comment|/* Interface Link Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_M88E1112_MAC_CTRL_1
value|0x10
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_MAC_CTRL_1_MODE_MASK
value|0x0380
end_define

begin_comment
comment|/* Mode Select */
end_comment

begin_define
define|#
directive|define
name|E1000_M88E1112_MAC_CTRL_1_MODE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_PAGE_ADDR
value|0x16
end_define

begin_define
define|#
directive|define
name|E1000_M88E1112_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|E1000_THSTAT_LOW_EVENT
value|0x20000000
end_define

begin_comment
comment|/* Low thermal threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_THSTAT_MID_EVENT
value|0x00200000
end_define

begin_comment
comment|/* Mid thermal threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_THSTAT_HIGH_EVENT
value|0x00002000
end_define

begin_comment
comment|/* High thermal threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_THSTAT_PWR_DOWN
value|0x00000001
end_define

begin_comment
comment|/* Power Down Event */
end_comment

begin_define
define|#
directive|define
name|E1000_THSTAT_LINK_THROTTLE
value|0x00000002
end_define

begin_comment
comment|/* Link Spd Throttle Event */
end_comment

begin_comment
comment|/* I350 EEE defines */
end_comment

begin_define
define|#
directive|define
name|E1000_IPCNFG_EEE_1G_AN
value|0x00000008
end_define

begin_comment
comment|/* IPCNFG EEE Ena 1G AN */
end_comment

begin_define
define|#
directive|define
name|E1000_IPCNFG_EEE_100M_AN
value|0x00000004
end_define

begin_comment
comment|/* IPCNFG EEE Ena 100M AN */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_TX_LPI_EN
value|0x00010000
end_define

begin_comment
comment|/* EEER Tx LPI Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_RX_LPI_EN
value|0x00020000
end_define

begin_comment
comment|/* EEER Rx LPI Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_LPI_FC
value|0x00040000
end_define

begin_comment
comment|/* EEER Ena on Flow Cntrl */
end_comment

begin_comment
comment|/* EEE status */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_EEE_NEG
value|0x20000000
end_define

begin_comment
comment|/* EEE capability nego */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_RX_LPI_STATUS
value|0x40000000
end_define

begin_comment
comment|/* Rx in LPI state */
end_comment

begin_define
define|#
directive|define
name|E1000_EEER_TX_LPI_STATUS
value|0x80000000
end_define

begin_comment
comment|/* Tx in LPI state */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_LP_ADV_ADDR_I350
value|0x040F
end_define

begin_comment
comment|/* EEE LP Advertisement */
end_comment

begin_define
define|#
directive|define
name|E1000_M88E1543_PAGE_ADDR
value|0x16
end_define

begin_comment
comment|/* Page Offset Register */
end_comment

begin_define
define|#
directive|define
name|E1000_M88E1543_EEE_CTRL_1
value|0x0
end_define

begin_define
define|#
directive|define
name|E1000_M88E1543_EEE_CTRL_1_MS
value|0x0001
end_define

begin_comment
comment|/* EEE Master/Slave */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_ADV_DEV_I354
value|7
end_define

begin_define
define|#
directive|define
name|E1000_EEE_ADV_ADDR_I354
value|60
end_define

begin_define
define|#
directive|define
name|E1000_EEE_ADV_100_SUPPORTED
value|(1<< 1)
end_define

begin_comment
comment|/* 100BaseTx EEE Supported */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_ADV_1000_SUPPORTED
value|(1<< 2)
end_define

begin_comment
comment|/* 1000BaseT EEE Supported */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_STATUS_DEV_I354
value|3
end_define

begin_define
define|#
directive|define
name|E1000_PCS_STATUS_ADDR_I354
value|1
end_define

begin_define
define|#
directive|define
name|E1000_PCS_STATUS_RX_LPI_RCVD
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_PCS_STATUS_TX_LPI_RCVD
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_M88E1512_CFG_REG_1
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_M88E1512_CFG_REG_2
value|0x0011
end_define

begin_define
define|#
directive|define
name|E1000_M88E1512_CFG_REG_3
value|0x0007
end_define

begin_define
define|#
directive|define
name|E1000_M88E1512_MODE
value|0x0014
end_define

begin_define
define|#
directive|define
name|E1000_EEE_SU_LPI_CLK_STP
value|0x00800000
end_define

begin_comment
comment|/* EEE LPI Clock Stop */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_LP_ADV_DEV_I210
value|7
end_define

begin_comment
comment|/* EEE LP Adv Device */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_LP_ADV_ADDR_I210
value|61
end_define

begin_comment
comment|/* EEE LP Adv Register */
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
name|E1000_GCR_CMPL_TMOUT_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|E1000_GCR_CMPL_TMOUT_10ms
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_GCR_CMPL_TMOUT_RESEND
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_GCR_CAP_VER2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIE_NO_SNOOP_ALL
value|(E1000_GCR_RXD_NO_SNOOP | \ 				 E1000_GCR_RXDSCW_NO_SNOOP | \ 				 E1000_GCR_RXDSCR_NO_SNOOP | \ 				 E1000_GCR_TXD_NO_SNOOP    | \ 				 E1000_GCR_TXDSCW_NO_SNOOP | \ 				 E1000_GCR_TXDSCR_NO_SNOOP)
end_define

begin_define
define|#
directive|define
name|E1000_MMDAC_FUNC_DATA
value|0x4000
end_define

begin_comment
comment|/* Data, no post increment */
end_comment

begin_comment
comment|/* mPHY address control and data registers */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_ADDR_CTL
value|0x0024
end_define

begin_comment
comment|/* Address Control Reg */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_ADDR_CTL_OFFSET_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|E1000_MPHY_DATA
value|0x0E10
end_define

begin_comment
comment|/* Data Register */
end_comment

begin_comment
comment|/* AFE CSR Offset for PCS CLK */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_PCS_CLK_REG_OFFSET
value|0x0004
end_define

begin_comment
comment|/* Override for near end digital loopback. */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_PCS_CLK_REG_DIGINELBEN
value|0x10
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
comment|/* LP 10T Half Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* LP 10T Full Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* LP 100TX Half Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* LP 100TX Full Dplx Capable */
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
comment|/* LP Asym Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* LP detected Remote Fault */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_comment
comment|/* LP rx'd link code word */
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
comment|/* LP 10T Half Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_NEXT_PAGE_CAPS
value|0x0004
end_define

begin_comment
comment|/* LP 10T Full Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NEXT_PAGE_CAPS
value|0x0008
end_define

begin_comment
comment|/* LP 100TX Half Dplx Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAR_DETECT_FAULT
value|0x0010
end_define

begin_comment
comment|/* LP 100TX Full Dplx Capable */
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

begin_comment
comment|/* 1=Repeater/switch device port 0=DTE device */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_REPEATER_DTE
value|0x0400
end_define

begin_comment
comment|/* 1=Configure PHY as Master 0=Configure PHY as Slave */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_VALUE
value|0x0800
end_define

begin_comment
comment|/* 1=Master/Slave manual config value 0=Automatic Master/Slave config */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_ENABLE
value|0x1000
end_define

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
comment|/* Num idle err since last rd */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_comment
comment|/* LP asym pause direction bit */
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
comment|/* 1=Local Tx Master, 0=Slave */
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
comment|/* Status Register */
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
comment|/* Next Page Tx */
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

begin_define
define|#
directive|define
name|PHY_CONTROL_LB
value|0x4000
end_define

begin_comment
comment|/* PHY Loopback bit */
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
name|E1000_EECD_BLOCKED
value|0x00008000
end_define

begin_comment
comment|/* Bit banging access blocked flag */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_ABORT
value|0x00010000
end_define

begin_comment
comment|/* NVM operation aborted flag */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_TIMEOUT
value|0x00020000
end_define

begin_comment
comment|/* NVM read operation timeout flag */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_ERROR_CLR
value|0x00040000
end_define

begin_comment
comment|/* NVM error status clear bit */
end_comment

begin_comment
comment|/* NVM Addressing bits based on type 0=small, 1=large */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_ADDR_BITS
value|0x00000400
end_define

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
comment|/* Ena Auto FLASH update */
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
name|E1000_EECD_SEC1VAL_VALID_MASK
value|(E1000_EECD_AUTO_RD | E1000_EECD_PRES)
end_define

begin_define
define|#
directive|define
name|E1000_EECD_FLUPD_I210
value|0x00800000
end_define

begin_comment
comment|/* Update FLASH */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FLUDONE_I210
value|0x04000000
end_define

begin_comment
comment|/* Update FLASH done */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FLASH_DETECTED_I210
value|0x00080000
end_define

begin_comment
comment|/* FLASH detected */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SEC1VAL_I210
value|0x02000000
end_define

begin_comment
comment|/* Sector One Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_FLUDONE_ATTEMPTS
value|20000
end_define

begin_define
define|#
directive|define
name|E1000_EERD_EEWR_MAX_COUNT
value|512
end_define

begin_comment
comment|/* buffered EEPROM words rw */
end_comment

begin_define
define|#
directive|define
name|E1000_I210_FIFO_SEL_RX
value|0x00
end_define

begin_define
define|#
directive|define
name|E1000_I210_FIFO_SEL_TX_QAV
parameter_list|(
name|_i
parameter_list|)
value|(0x02 + (_i))
end_define

begin_define
define|#
directive|define
name|E1000_I210_FIFO_SEL_TX_LEGACY
value|E1000_I210_FIFO_SEL_TX_QAV(0)
end_define

begin_define
define|#
directive|define
name|E1000_I210_FIFO_SEL_BMC2OS_TX
value|0x06
end_define

begin_define
define|#
directive|define
name|E1000_I210_FIFO_SEL_BMC2OS_RX
value|0x01
end_define

begin_define
define|#
directive|define
name|E1000_I210_FLASH_SECTOR_SIZE
value|0x1000
end_define

begin_comment
comment|/* 4KB FLASH sector unit size */
end_comment

begin_comment
comment|/* Secure FLASH mode requires removing MSb */
end_comment

begin_define
define|#
directive|define
name|E1000_I210_FW_PTR_MASK
value|0x7FFF
end_define

begin_comment
comment|/* Firmware code revision field word offset*/
end_comment

begin_define
define|#
directive|define
name|E1000_I210_FW_VER_OFFSET
value|328
end_define

begin_define
define|#
directive|define
name|E1000_NVM_RW_REG_DATA
value|16
end_define

begin_comment
comment|/* Offset to data in NVM read/write regs */
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
name|NVM_SERDES_AMPLITUDE
value|0x0006
end_define

begin_comment
comment|/* SERDES output amplitude */
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
name|E1000_I210_NVM_FW_MODULE_PTR
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_I350_NVM_FW_MODULE_PTR
value|0x0051
end_define

begin_define
define|#
directive|define
name|NVM_FUTURE_INIT_WORD1
value|0x0019
end_define

begin_define
define|#
directive|define
name|NVM_MAC_ADDR
value|0x0000
end_define

begin_define
define|#
directive|define
name|NVM_SUB_DEV_ID
value|0x000B
end_define

begin_define
define|#
directive|define
name|NVM_SUB_VEN_ID
value|0x000C
end_define

begin_define
define|#
directive|define
name|NVM_DEV_ID
value|0x000D
end_define

begin_define
define|#
directive|define
name|NVM_VEN_ID
value|0x000E
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_2
value|0x000F
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_4
value|0x0013
end_define

begin_define
define|#
directive|define
name|NVM_LED_1_CFG
value|0x001C
end_define

begin_define
define|#
directive|define
name|NVM_LED_0_2_CFG
value|0x001F
end_define

begin_define
define|#
directive|define
name|NVM_COMPAT_VALID_CSUM
value|0x0001
end_define

begin_define
define|#
directive|define
name|NVM_FUTURE_INIT_WORD1_VALID_CSUM
value|0x0040
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
name|NVM_ALT_MAC_ADDR_PTR
value|0x0037
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
name|NVM_COMPATIBILITY_REG_3
value|0x0003
end_define

begin_define
define|#
directive|define
name|NVM_COMPATIBILITY_BIT_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_0
value|0x040000
end_define

begin_comment
comment|/* MNG config cycle done */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_1
value|0x080000
end_define

begin_comment
comment|/* ...for second port */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_2
value|0x100000
end_define

begin_comment
comment|/* ...for third port */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_CFG_DONE_PORT_3
value|0x200000
end_define

begin_comment
comment|/* ...for fourth port */
end_comment

begin_define
define|#
directive|define
name|NVM_82580_LAN_FUNC_OFFSET
parameter_list|(
name|a
parameter_list|)
value|((a) ? (0x40 + (0x40 * (a))) : 0)
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x24 of the NVM */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD24_COM_MDIO
value|0x0008
end_define

begin_comment
comment|/* MDIO interface shared */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD24_EXT_MDIO
value|0x0004
end_define

begin_comment
comment|/* MDIO accesses routed extrnl */
end_comment

begin_comment
comment|/* Offset of Link Mode bits for 82575/82576 */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD24_LNK_MODE_OFFSET
value|8
end_define

begin_comment
comment|/* Offset of Link Mode bits for 82580 up */
end_comment

begin_define
define|#
directive|define
name|NVM_WORD24_82580_LNK_MODE_OFFSET
value|4
end_define

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
name|NVM_WORD0F_SWPDIO_EXT_MASK
value|0x00F0
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
comment|/* Mask bits for fields in Word 0x03 of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|NVM_COMPAT_LOM
value|0x0800
end_define

begin_comment
comment|/* length of string needed to store PBA number */
end_comment

begin_define
define|#
directive|define
name|E1000_PBANUM_LENGTH
value|11
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

begin_comment
comment|/* PBA (printed board assembly) number words */
end_comment

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
name|NVM_PBA_PTR_GUARD
value|0xFAFA
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
comment|/* NVM erase/write disable */
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
name|NVM_RDSR_OPCODE_SPI
value|0x05
end_define

begin_comment
comment|/* NVM read Status register */
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
value|((ID_LED_OFF1_ON2<< 12) | \ 				 (ID_LED_OFF1_OFF2<<  8) | \ 				 (ID_LED_DEF1_DEF2<<  4) | \ 				 (ID_LED_DEF1_DEF2))
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
name|PCIE_DEVICE_CONTROL2
value|0x28
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

begin_define
define|#
directive|define
name|PCIE_LINK_SPEED_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCIE_LINK_SPEED_2500
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIE_LINK_SPEED_5000
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIE_DEVICE_CONTROL2_16ms
value|0x0005
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
comment|/* Bit definitions for valid PHY IDs.  * I = Integrated  * E = External  */
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
name|M88E1111_I_PHY_ID
value|0x01410CC0
end_define

begin_define
define|#
directive|define
name|M88E1543_E_PHY_ID
value|0x01410EA0
end_define

begin_define
define|#
directive|define
name|M88E1512_E_PHY_ID
value|0x01410DD0
end_define

begin_define
define|#
directive|define
name|M88E1112_E_PHY_ID
value|0x01410C90
end_define

begin_define
define|#
directive|define
name|I347AT4_E_PHY_ID
value|0x01410DC0
end_define

begin_define
define|#
directive|define
name|M88E1340M_E_PHY_ID
value|0x01410DF0
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
name|BME1000_E_PHY_ID
value|0x01410CB0
end_define

begin_define
define|#
directive|define
name|BME1000_E_PHY_ID_R2
value|0x01410CB1
end_define

begin_define
define|#
directive|define
name|I82577_E_PHY_ID
value|0x01540050
end_define

begin_define
define|#
directive|define
name|I82578_E_PHY_ID
value|0x004DD040
end_define

begin_define
define|#
directive|define
name|I82579_E_PHY_ID
value|0x01540090
end_define

begin_define
define|#
directive|define
name|I217_E_PHY_ID
value|0x015400A0
end_define

begin_define
define|#
directive|define
name|I82580_I_PHY_ID
value|0x015403A0
end_define

begin_define
define|#
directive|define
name|I350_I_PHY_ID
value|0x015403B0
end_define

begin_define
define|#
directive|define
name|I210_I_PHY_ID
value|0x01410C00
end_define

begin_define
define|#
directive|define
name|IGP04E1000_E_PHY_ID
value|0x02A80391
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
comment|/* PHY Specific Control Reg */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_STATUS
value|0x11
end_define

begin_comment
comment|/* PHY Specific Status Reg */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EXT_PHY_SPEC_CTRL
value|0x14
end_define

begin_comment
comment|/* Extended PHY Specific Cntrl */
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
comment|/* Reg 29 for pg number setting */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_GEN_CONTROL
value|0x1E
end_define

begin_comment
comment|/* meaning depends on reg 29 */
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
name|M88E1000_PSCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reverse enabled */
end_comment

begin_comment
comment|/* MDI Crossover Mode bits 6:5 Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_comment
comment|/* Manual MDIX configuration */
end_comment

begin_comment
comment|/* 1000BASE-T: Auto crossover, 100BASE-TX/10BASE-T: MDI Mode */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_1000T
value|0x0040
end_define

begin_comment
comment|/* Auto crossover enabled all speeds */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE
value|0x0060
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_comment
comment|/* 1=Assert CRS on Tx */
end_comment

begin_comment
comment|/* M88E1000 PHY Specific Status Register */
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

begin_comment
comment|/* 0 =<50M  * 1 = 50-80M  * 2 = 80-110M  * 3 = 110-140M  * 4 =>140M  */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH
value|0x0380
end_define

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
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the master  */
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

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the slave  */
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
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_1X
value|0x0100
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_25
value|0x0070
end_define

begin_comment
comment|/* 25  MHz TX_CLK */
end_comment

begin_comment
comment|/* Intel I347AT4 Registers */
end_comment

begin_define
define|#
directive|define
name|I347AT4_PCDL
value|0x10
end_define

begin_comment
comment|/* PHY Cable Diagnostics Length */
end_comment

begin_define
define|#
directive|define
name|I347AT4_PCDC
value|0x15
end_define

begin_comment
comment|/* PHY Cable Diagnostics Control */
end_comment

begin_define
define|#
directive|define
name|I347AT4_PAGE_SELECT
value|0x16
end_define

begin_comment
comment|/* I347AT4 Extended PHY Specific Control Register */
end_comment

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the master  */
end_comment

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_ENABLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_1X
value|0x0000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_2X
value|0x1000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_3X
value|0x2000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_4X
value|0x3000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_5X
value|0x4000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_6X
value|0x5000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_7X
value|0x6000
end_define

begin_define
define|#
directive|define
name|I347AT4_PSCR_DOWNSHIFT_8X
value|0x7000
end_define

begin_comment
comment|/* I347AT4 PHY Cable Diagnostics Control */
end_comment

begin_define
define|#
directive|define
name|I347AT4_PCDC_CABLE_LENGTH_UNIT
value|0x0400
end_define

begin_comment
comment|/* 0=cm 1=meters */
end_comment

begin_comment
comment|/* M88E1112 only registers */
end_comment

begin_define
define|#
directive|define
name|M88E1112_VCT_DSP_DISTANCE
value|0x001A
end_define

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
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_5X
value|0x0800
end_define

begin_define
define|#
directive|define
name|I82578_EPSCR_DOWNSHIFT_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|I82578_EPSCR_DOWNSHIFT_COUNTER_MASK
value|0x001C
end_define

begin_comment
comment|/* BME1000 PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|BME1000_PSCR_ENABLE_DOWNSHIFT
value|0x0800
end_define

begin_comment
comment|/* 1 = enable downshift */
end_comment

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
value|GG82563_REG(0, 16)
end_define

begin_comment
comment|/* PHY Spec Cntrl */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT
value|GG82563_REG(0, 22)
end_define

begin_comment
comment|/* Page Select */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_CTRL_2
value|GG82563_REG(0, 26)
end_define

begin_comment
comment|/* PHY Spec Cntrl2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT_ALT
value|GG82563_REG(0, 29)
end_define

begin_comment
comment|/* Alt Page Select */
end_comment

begin_comment
comment|/* MAC Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_MAC_SPEC_CTRL
value|GG82563_REG(2, 21)
end_define

begin_define
define|#
directive|define
name|GG82563_PHY_DSP_DISTANCE
value|GG82563_REG(5, 26)
end_define

begin_comment
comment|/* DSP Distance */
end_comment

begin_comment
comment|/* Page 193 - Port Control Registers */
end_comment

begin_comment
comment|/* Kumeran Mode Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_MODE_CTRL
value|GG82563_REG(193, 16)
end_define

begin_define
define|#
directive|define
name|GG82563_PHY_PWR_MGMT_CTRL
value|GG82563_REG(193, 20)
end_define

begin_comment
comment|/* Pwr Mgt Ctrl */
end_comment

begin_comment
comment|/* Page 194 - KMRN Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_INBAND_CTRL
value|GG82563_REG(194, 18)
end_define

begin_comment
comment|/* Inband Ctrl */
end_comment

begin_comment
comment|/* MDI Control */
end_comment

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
name|E1000_MDIC_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_DEST
value|0x80000000
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

begin_comment
comment|/* LinkSec register fields */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXCAP_SUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCAP_SUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCAP_SUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCAP_SUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_EN_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_AUTH
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_AUTH_ENCRYPT
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_AISCI
value|0x00000020
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_PNTHRSH_MASK
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL_RSV_MASK
value|0x000000D8
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_EN_MASK
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_CHECK
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_STRICT
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_DROP
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_PLSH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_RP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL_RSV_MASK
value|0xFFFFFF33
end_define

begin_comment
comment|/* Tx Rate-Scheduler Config fields */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNRC_RS_ENA
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_RTTBCNRC_RF_DEC_MASK
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|E1000_RTTBCNRC_RF_INT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|E1000_RTTBCNRC_RF_INT_MASK
define|\
value|(E1000_RTTBCNRC_RF_DEC_MASK<< E1000_RTTBCNRC_RF_INT_SHIFT)
end_define

begin_comment
comment|/* DMA Coalescing register fields */
end_comment

begin_comment
comment|/* DMA Coalescing Watchdog Timer */
end_comment

begin_define
define|#
directive|define
name|E1000_DMACR_DMACWT_MASK
value|0x00003FFF
end_define

begin_comment
comment|/* DMA Coalescing Rx Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DMACR_DMACTHR_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_DMACR_DMACTHR_SHIFT
value|16
end_define

begin_comment
comment|/* Lx when no PCIe transactions */
end_comment

begin_define
define|#
directive|define
name|E1000_DMACR_DMAC_LX_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|E1000_DMACR_DMAC_LX_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|E1000_DMACR_DMAC_EN
value|0x80000000
end_define

begin_comment
comment|/* Enable DMA Coalescing */
end_comment

begin_comment
comment|/* DMA Coalescing BMC-to-OS Watchdog Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_DMACR_DC_BMC2OSW_EN
value|0x00008000
end_define

begin_comment
comment|/* DMA Coalescing Transmit Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCTXTH_DMCTTHR_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|E1000_DMCTLX_TTLX_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* Time to LX request */
end_comment

begin_comment
comment|/* Rx Traffic Rate Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCRTRH_UTRESH_MASK
value|0x0007FFFF
end_define

begin_comment
comment|/* Rx packet rate in current window */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCRTRH_LRPRCW
value|0x80000000
end_define

begin_comment
comment|/* DMA Coal Rx Traffic Current Count */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCCNT_CCOUNT_MASK
value|0x01FFFFFF
end_define

begin_comment
comment|/* Flow ctrl Rx Threshold High val */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTC_RTH_COAL_MASK
value|0x0003FFF0
end_define

begin_define
define|#
directive|define
name|E1000_FCRTC_RTH_COAL_SHIFT
value|4
end_define

begin_comment
comment|/* Lx power decision based on DMA coal */
end_comment

begin_define
define|#
directive|define
name|E1000_PCIEMISC_LX_DECISION
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_RXPBS_CFG_TS_EN
value|0x80000000
end_define

begin_comment
comment|/* Timestamp in Rx buffer */
end_comment

begin_define
define|#
directive|define
name|E1000_RXPBS_SIZE_I210_MASK
value|0x0000003F
end_define

begin_comment
comment|/* Rx packet buffer size */
end_comment

begin_define
define|#
directive|define
name|E1000_TXPB0S_SIZE_I210_MASK
value|0x0000003F
end_define

begin_comment
comment|/* Tx packet buffer 0 size */
end_comment

begin_define
define|#
directive|define
name|I210_RXPBSIZE_DEFAULT
value|0x000000A2
end_define

begin_comment
comment|/* RXPBSIZE default */
end_comment

begin_define
define|#
directive|define
name|I210_TXPBSIZE_DEFAULT
value|0x04000014
end_define

begin_comment
comment|/* TXPBSIZE default */
end_comment

begin_define
define|#
directive|define
name|E1000_DOBFFCTL_OBFFTHR_MASK
value|0x000000FF
end_define

begin_comment
comment|/* OBFF threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DOBFFCTL_EXIT_ACT_MASK
value|0x01000000
end_define

begin_comment
comment|/* Exit active CB */
end_comment

begin_comment
comment|/* Proxy Filter Control */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_D0
value|0x00000001
end_define

begin_comment
comment|/* Enable offload in D0 */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed exact proxy */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_MC
value|0x00000008
end_define

begin_comment
comment|/* Directed MC Proxy */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_BC
value|0x00000010
end_define

begin_comment
comment|/* Broadcast Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_ARP_DIRECTED
value|0x00000020
end_define

begin_comment
comment|/* Directed ARP Proxy Ena */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_IPV4
value|0x00000040
end_define

begin_comment
comment|/* Directed IPv4 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_IPV6
value|0x00000080
end_define

begin_comment
comment|/* Directed IPv6 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_NS
value|0x00000200
end_define

begin_comment
comment|/* IPv6 Neighbor Solicitation */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYFC_ARP
value|0x00000800
end_define

begin_comment
comment|/* ARP Request Proxy Ena */
end_comment

begin_comment
comment|/* Proxy Status */
end_comment

begin_define
define|#
directive|define
name|E1000_PROXYS_CLEAR
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Clear */
end_comment

begin_comment
comment|/* Firmware Status */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSTS_FWRI
value|0x80000000
end_define

begin_comment
comment|/* FW Reset Indication */
end_comment

begin_comment
comment|/* VF Control */
end_comment

begin_define
define|#
directive|define
name|E1000_VTCTRL_RST
value|0x04000000
end_define

begin_comment
comment|/* Reset VF */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_LAN_ID_MASK
value|0x00000000C
end_define

begin_comment
comment|/* Mask for Lan ID field */
end_comment

begin_comment
comment|/* Lan ID bit field offset in status register */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_LAN_ID_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRIES
value|128
end_define

begin_define
define|#
directive|define
name|E1000_UNUSEDARG
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ERROR_REPORT
end_ifndef

begin_define
define|#
directive|define
name|ERROR_REPORT
parameter_list|(
name|fmt
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERROR_REPORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E1000_DEFINES_H_ */
end_comment

end_unit

