begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998, 1999, 2000-2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the ASIX Electronics AX88172, AX88178  * and AX88772 to ethernet controllers.  */
end_comment

begin_comment
comment|/*  * Vendor specific commands.  ASIX conveniently doesn't document the 'set  * NODEID' command in their datasheet (thanks a lot guys).  * To make handling these commands easier, I added some extra data which is  * decided by the axe_cmd() routine. Commands are encoded in 16 bits, with  * the format: LDCC. L and D are both nibbles in the high byte.  L represents  * the data length (0 to 15) and D represents the direction (0 for vendor read,  * 1 for vendor write).  CC is the command byte, as specified in the manual.  */
end_comment

begin_define
define|#
directive|define
name|AXE_CMD_IS_WRITE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F00)>> 8)
end_define

begin_define
define|#
directive|define
name|AXE_CMD_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF000)>> 12)
end_define

begin_define
define|#
directive|define
name|AXE_CMD_CMD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00FF)
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_READ_RXTX_SRAM
value|0x2002
end_define

begin_define
define|#
directive|define
name|AXE_182_CMD_READ_RXTX_SRAM
value|0x8002
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_RX_SRAM
value|0x0103
end_define

begin_define
define|#
directive|define
name|AXE_182_CMD_WRITE_RXTX_SRAM
value|0x8103
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_TX_SRAM
value|0x0104
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_OPMODE_SW
value|0x0106
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_READ_REG
value|0x2007
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_WRITE_REG
value|0x2108
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_READ_OPMODE
value|0x1009
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_OPMODE_HW
value|0x010A
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_READ
value|0x200B
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WRITE
value|0x010C
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WR_ENABLE
value|0x010D
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WR_DISABLE
value|0x010E
end_define

begin_define
define|#
directive|define
name|AXE_CMD_RXCTL_READ
value|0x200F
end_define

begin_define
define|#
directive|define
name|AXE_CMD_RXCTL_WRITE
value|0x0110
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_IPG012
value|0x3011
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_IPG0
value|0x0112
end_define

begin_define
define|#
directive|define
name|AXE_178_CMD_WRITE_IPG012
value|0x0112
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_IPG1
value|0x0113
end_define

begin_define
define|#
directive|define
name|AXE_178_CMD_READ_NODEID
value|0x6013
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_IPG2
value|0x0114
end_define

begin_define
define|#
directive|define
name|AXE_178_CMD_WRITE_NODEID
value|0x6114
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_MCAST
value|0x8015
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MCAST
value|0x8116
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_READ_NODEID
value|0x6017
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_WRITE_NODEID
value|0x6118
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_PHYID
value|0x2019
end_define

begin_define
define|#
directive|define
name|AXE_172_CMD_READ_MEDIA
value|0x101A
end_define

begin_define
define|#
directive|define
name|AXE_178_CMD_READ_MEDIA
value|0x201A
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MEDIA
value|0x011B
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_MONITOR_MODE
value|0x101C
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MONITOR_MODE
value|0x011D
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_GPIO
value|0x101E
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_GPIO
value|0x011F
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SW_RESET_REG
value|0x0120
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SW_PHY_STATUS
value|0x0021
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SW_PHY_SELECT
value|0x0122
end_define

begin_comment
comment|/* AX88772A and AX88772B only. */
end_comment

begin_define
define|#
directive|define
name|AXE_CMD_READ_VLAN_CTRL
value|0x4027
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_VLAN_CTRL
value|0x4028
end_define

begin_define
define|#
directive|define
name|AXE_772B_CMD_RXCTL_WRITE_CFG
value|0x012A
end_define

begin_define
define|#
directive|define
name|AXE_772B_CMD_READ_RXCSUM
value|0x002B
end_define

begin_define
define|#
directive|define
name|AXE_772B_CMD_WRITE_RXCSUM
value|0x012C
end_define

begin_define
define|#
directive|define
name|AXE_772B_CMD_READ_TXCSUM
value|0x002D
end_define

begin_define
define|#
directive|define
name|AXE_772B_CMD_WRITE_TXCSUM
value|0x012E
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_CLEAR
value|0x00
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_RR
value|0x01
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_RT
value|0x02
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_PRTE
value|0x04
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_PRL
value|0x08
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_BZ
value|0x10
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_IPRL
value|0x20
end_define

begin_define
define|#
directive|define
name|AXE_SW_RESET_IPPD
value|0x40
end_define

begin_comment
comment|/* AX88178 documentation says to always write this bit... */
end_comment

begin_define
define|#
directive|define
name|AXE_178_RESET_MAGIC
value|0x40
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_GMII
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_MEDIA_FULL_DUPLEX
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_172_MEDIA_TX_ABORT_ALLOW
value|0x0004
end_define

begin_comment
comment|/* AX88178/88772 documentation says to always write 1 to bit 2 */
end_comment

begin_define
define|#
directive|define
name|AXE_178_MEDIA_MAGIC
value|0x0004
end_define

begin_comment
comment|/* AX88772 documentation says to always write 0 to bit 3 */
end_comment

begin_define
define|#
directive|define
name|AXE_178_MEDIA_ENCK
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_172_MEDIA_FLOW_CONTROL_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_RXFLOW_CONTROL_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_TXFLOW_CONTROL_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_JUMBO_EN
value|0x0040
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_LTPF_ONLY
value|0x0080
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_RX_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_100TX
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_SBP
value|0x0800
end_define

begin_define
define|#
directive|define
name|AXE_178_MEDIA_SUPERMAC
value|0x1000
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_PROMISC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_ALLMULTI
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_172_RXCMD_UNICAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_KEEP_INVALID_CRC
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_BROADCAST
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_MULTICAST
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_ACCEPT_RUNT
value|0x0040
end_define

begin_comment
comment|/* AX88772B */
end_comment

begin_define
define|#
directive|define
name|AXE_RXCMD_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_MFB_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_MFB_2048
value|0x0000
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_MFB_4096
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_MFB_8192
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_178_RXCMD_MFB_16384
value|0x0300
end_define

begin_define
define|#
directive|define
name|AXE_772B_RXCMD_HDR_TYPE_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|AXE_772B_RXCMD_HDR_TYPE_1
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_772B_RXCMD_IPHDR_ALIGN
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_772B_RXCMD_ADD_CHKSUM
value|0x0400
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_LOOPBACK
value|0x1000
end_define

begin_comment
comment|/* AX88772A/AX88772B */
end_comment

begin_define
define|#
directive|define
name|AXE_PHY_SEL_PRI
value|1
end_define

begin_define
define|#
directive|define
name|AXE_PHY_SEL_SEC
value|0
end_define

begin_define
define|#
directive|define
name|AXE_PHY_TYPE_MASK
value|0xE0
end_define

begin_define
define|#
directive|define
name|AXE_PHY_TYPE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AXE_PHY_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& AXE_PHY_TYPE_MASK)>> AXE_PHY_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHY_TYPE_100_HOME
value|0
end_define

begin_comment
comment|/* 10/100 or 1M HOME PHY */
end_comment

begin_define
define|#
directive|define
name|PHY_TYPE_GIG
value|1
end_define

begin_comment
comment|/* Gigabit PHY */
end_comment

begin_define
define|#
directive|define
name|PHY_TYPE_SPECIAL
value|4
end_define

begin_comment
comment|/* Special case */
end_comment

begin_define
define|#
directive|define
name|PHY_TYPE_RSVD
value|5
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PHY_TYPE_NON_SUP
value|7
end_define

begin_comment
comment|/* Non-supported PHY */
end_comment

begin_define
define|#
directive|define
name|AXE_PHY_NO_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|AXE_PHY_NO
parameter_list|(
name|x
parameter_list|)
value|((x)& AXE_PHY_NO_MASK)
end_define

begin_define
define|#
directive|define
name|AXE_772_PHY_NO_EPHY
value|0x10
end_define

begin_comment
comment|/* Embedded 10/100 PHY of AX88772 */
end_comment

begin_define
define|#
directive|define
name|AXE_GPIO0_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|AXE_GPIO0
value|0x02
end_define

begin_define
define|#
directive|define
name|AXE_GPIO1_EN
value|0x04
end_define

begin_define
define|#
directive|define
name|AXE_GPIO1
value|0x08
end_define

begin_define
define|#
directive|define
name|AXE_GPIO2_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|AXE_GPIO2
value|0x20
end_define

begin_define
define|#
directive|define
name|AXE_GPIO_RELOAD_EEPROM
value|0x80
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_MARVELL
value|0x00
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_CICADA
value|0x01
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_AGERE
value|0x02
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_CICADA_V2
value|0x05
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_AGERE_GMII
value|0x06
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_CICADA_V2_ASIX
value|0x09
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_REALTEK_8211CL
value|0x0C
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_REALTEK_8211BN
value|0x0D
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_REALTEK_8251CL
value|0x0E
end_define

begin_define
define|#
directive|define
name|AXE_PHY_MODE_ATTANSIC
value|0x40
end_define

begin_comment
comment|/* AX88772A/AX88772B only. */
end_comment

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_EXT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_EMBEDDED
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_AUTO
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_SS_MII
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_SS_RVRS_MII
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_SS_RVRS_RMII
value|0x000C
end_define

begin_define
define|#
directive|define
name|AXE_SW_PHY_SELECT_SS_ENB
value|0x0010
end_define

begin_comment
comment|/* AX88772A/AX88772B VLAN control. */
end_comment

begin_define
define|#
directive|define
name|AXE_VLAN_CTRL_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AXE_VLAN_CTRL_STRIP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AXE_VLAN_CTRL_VID1_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|AXE_VLAN_CTRL_VID2_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_IPVE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_IPV6E
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_TCP
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_UDP
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_ICMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_IGMP
value|0x0040
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_ICMP6
value|0x0080
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_TCPV6
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_UDPV6
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_ICMPV6
value|0x0400
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_IGMPV6
value|0x0800
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_ICMP6V6
value|0x1000
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_FOPC
value|0x8000
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_64TE
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_PPPOE
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_RXCSUM_RPCE
value|0x8000
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_TCP
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_UDP
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_ICMP
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_IGMP
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_ICMP6
value|0x0020
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_TCPV6
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_UDPV6
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_ICMPV6
value|0x0400
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_IGMPV6
value|0x0800
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_ICMP6V6
value|0x1000
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_64TE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_TXCSUM_PPPOE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_BULK_BUF_SIZE
value|16384
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|AXE_CTL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|AXE_CTL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|AXE_CONFIG_IDX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|AXE_IFACE_IDX
value|0
end_define

begin_comment
comment|/* EEPROM Map. */
end_comment

begin_define
define|#
directive|define
name|AXE_EEPROM_772B_NODE_ID
value|0x04
end_define

begin_define
define|#
directive|define
name|AXE_EEPROM_772B_PHY_PWRCFG
value|0x18
end_define

begin_struct
struct|struct
name|ax88772b_mfb
block|{
name|int
name|byte_cnt
decl_stmt|;
name|int
name|threshold
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AX88772B_MFB_2K
value|0
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_4K
value|1
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_6K
value|2
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_8K
value|3
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_16K
value|4
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_20K
value|5
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_24K
value|6
end_define

begin_define
define|#
directive|define
name|AX88772B_MFB_32K
value|7
end_define

begin_struct
struct|struct
name|axe_sframe_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|AXE_HDR_LEN_MASK
value|0xFFFF
name|uint16_t
name|ilen
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AXE_TX_CSUM_PSEUDO_HDR
value|0x4000
end_define

begin_define
define|#
directive|define
name|AXE_TX_CSUM_DIS
value|0x8000
end_define

begin_comment
comment|/*  * When RX checksum offloading is enabled, AX88772B uses new RX header  * format and it's not compatible with previous RX header format.  In  * addition, IP header align option should be enabled to get correct  * frame size including RX header.  Total transferred size including  * the RX header is multiple of 4 and controller will pad necessary  * bytes if the length is not multiple of 4.  * This driver does not enable partial checksum feature which will  * compute 16bit checksum from 14th byte to the end of the frame.  If  * this feature is enabled, computed checksum value is embedded into  * RX header which in turn means it uses different RX header format.  */
end_comment

begin_struct
struct|struct
name|axe_csum_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|AXE_CSUM_HDR_LEN_MASK
value|0x07FF
define|#
directive|define
name|AXE_CSUM_HDR_CRC_ERR
value|0x1000
define|#
directive|define
name|AXE_CSUM_HDR_MII_ERR
value|0x2000
define|#
directive|define
name|AXE_CSUM_HDR_RUNT
value|0x4000
define|#
directive|define
name|AXE_CSUM_HDR_BMCAST
value|0x8000
name|uint16_t
name|ilen
decl_stmt|;
name|uint16_t
name|cstatus
decl_stmt|;
define|#
directive|define
name|AXE_CSUM_HDR_VLAN_MASK
value|0x0007
define|#
directive|define
name|AXE_CSUM_HDR_VLAN_STRIP
value|0x0008
define|#
directive|define
name|AXE_CSUM_HDR_VLAN_PRI_MASK
value|0x0070
define|#
directive|define
name|AXE_CSUM_HDR_L4_CSUM_ERR
value|0x0100
define|#
directive|define
name|AXE_CSUM_HDR_L3_CSUM_ERR
value|0x0200
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_UDP
value|0x0400
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_ICMP
value|0x0800
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_IGMP
value|0x0C00
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_TCP
value|0x1000
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_TCPV6
value|0x1400
define|#
directive|define
name|AXE_CSUM_HDR_L4_TYPE_MASK
value|0x1C00
define|#
directive|define
name|AXE_CSUM_HDR_L3_TYPE_IPV4
value|0x2000
define|#
directive|define
name|AXE_CSUM_HDR_L3_TYPE_IPV6
value|0x4000
ifdef|#
directive|ifdef
name|AXE_APPEND_PARTIAL_CSUM
comment|/* 	 * These members present only when partial checksum 	 * offloading is enabled.  The checksum value is simple 	 * 16bit sum of received frame starting at offset 14 of 	 * the frame to the end of the frame excluding FCS bytes. 	 */
name|uint16_t
name|csum_value
decl_stmt|;
name|uint16_t
name|dummy
decl_stmt|;
endif|#
directive|endif
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AXE_CSUM_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x)& AXE_CSUM_HDR_LEN_MASK)
end_define

begin_define
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|uether_getmii(&(sc)->sc_ue)
end_define

begin_comment
comment|/* The interrupt endpoint is currently unused by the ASIX part. */
end_comment

begin_enum
enum|enum
block|{
name|AXE_BULK_DT_WR
block|,
name|AXE_BULK_DT_RD
block|,
name|AXE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|axe_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|AXE_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_phyno
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|AXE_FLAG_LINK
value|0x0001
define|#
directive|define
name|AXE_FLAG_STD_FRAME
value|0x0010
define|#
directive|define
name|AXE_FLAG_CSUM_FRAME
value|0x0020
define|#
directive|define
name|AXE_FLAG_772
value|0x1000
comment|/* AX88772 */
define|#
directive|define
name|AXE_FLAG_772A
value|0x2000
comment|/* AX88772A */
define|#
directive|define
name|AXE_FLAG_772B
value|0x4000
comment|/* AX88772B */
define|#
directive|define
name|AXE_FLAG_178
value|0x8000
comment|/* AX88178 */
name|uint8_t
name|sc_ipgs
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|sc_phyaddrs
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|sc_pwrcfg
decl_stmt|;
name|uint16_t
name|sc_lenmask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AXE_IS_178_FAMILY
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->sc_flags& (AXE_FLAG_772 | AXE_FLAG_772A | AXE_FLAG_772B | \ 	AXE_FLAG_178))
end_define

begin_define
define|#
directive|define
name|AXE_IS_772
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->sc_flags& (AXE_FLAG_772 | AXE_FLAG_772A | AXE_FLAG_772B))
end_define

begin_define
define|#
directive|define
name|AXE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AXE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AXE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

