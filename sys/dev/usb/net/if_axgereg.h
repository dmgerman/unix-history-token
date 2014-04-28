begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Kevin Lo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|AX88179_PHY_ID
value|0x03
end_define

begin_define
define|#
directive|define
name|AXGE_MCAST_FILTER_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|AXGE_MAXGE_MCAST
value|64
end_define

begin_define
define|#
directive|define
name|AXGE_EEPROM_LEN
value|0x40
end_define

begin_define
define|#
directive|define
name|AXGE_RX_CHECKSUM
value|1
end_define

begin_define
define|#
directive|define
name|AXGE_TX_CHECKSUM
value|2
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_MAC
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_PHY
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_WAKEUP
value|0x03
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_EEPROM
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_EFUSE
value|0x05
end_define

begin_define
define|#
directive|define
name|AXGE_RELOAD_EEPROM_EFUSE
value|0x06
end_define

begin_define
define|#
directive|define
name|AXGE_WRITE_EFUSE_EN
value|0x09
end_define

begin_define
define|#
directive|define
name|AXGE_WRITE_EFUSE_DIS
value|0x0A
end_define

begin_define
define|#
directive|define
name|AXGE_ACCESS_MFAB
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_LINK_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_LINK_STATUS_USB_FS
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_LINK_STATUS_USB_HS
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_LINK_STATUS_USB_SS
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_SROM_ADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|AXGE_SROM_DATA_LOW
value|0x08
end_define

begin_define
define|#
directive|define
name|AXGE_SROM_DATA_HIGH
value|0x09
end_define

begin_define
define|#
directive|define
name|AXGE_SROM_CMD
value|0x0a
end_define

begin_define
define|#
directive|define
name|AXGE_SROM_CMD_RD
value|0x04
end_define

begin_comment
comment|/* EEprom read command */
end_comment

begin_define
define|#
directive|define
name|AXGE_SROM_CMD_WR
value|0x08
end_define

begin_comment
comment|/* EEprom write command */
end_comment

begin_define
define|#
directive|define
name|AXGE_SROM_CMD_BUSY
value|0x10
end_define

begin_comment
comment|/* EEprom access module busy */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL
value|0x0b
end_define

begin_define
define|#
directive|define
name|AXGE_RX_CTL_DROPCRCERR
value|0x0100
end_define

begin_comment
comment|/* Drop CRC error packet */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_IPE
value|0x0200
end_define

begin_comment
comment|/* 4-byte IP header alignment */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_TXPADCRC
value|0x0400
end_define

begin_comment
comment|/* Csum value in rx header 3 */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_START
value|0x0080
end_define

begin_comment
comment|/* Ethernet MAC start */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_AP
value|0x0020
end_define

begin_comment
comment|/* Accept physical address from 						  multicast array */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_AM
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXGE_RX_CTL_AB
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXGE_RX_CTL_HA8B
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXGE_RX_CTL_AMALL
value|0x0002
end_define

begin_comment
comment|/* Accept all multicast frames */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_PRO
value|0x0001
end_define

begin_comment
comment|/* Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|AXGE_RX_CTL_STOP
value|0x0000
end_define

begin_comment
comment|/* Stop MAC */
end_comment

begin_define
define|#
directive|define
name|AXGE_NODE_ID
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_MULTI_FILTER_ARRY
value|0x16
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_STATUS_MODE
value|0x22
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_GIGAMODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_FULL_DUPLEX
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_ALWAYS_ONE
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_EN_125MHZ
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_RXFLOW_CTRLEN
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_TXFLOW_CTRLEN
value|0x0020
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_RECEIVE_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_PS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AXGE_MEDIUM_JUMBO_EN
value|0x8040
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE
value|0x24
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_RWLC
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_RWMP
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_RWWF
value|0x08
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_RW_FLAG
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_PMEPOL
value|0x20
end_define

begin_define
define|#
directive|define
name|AXGE_MONITOR_MODE_PMETYPE
value|0x40
end_define

begin_define
define|#
directive|define
name|AXGE_GPIO_CTRL
value|0x25
end_define

begin_define
define|#
directive|define
name|AXGE_GPIO_CTRL_GPIO3EN
value|0x80
end_define

begin_define
define|#
directive|define
name|AXGE_GPIO_CTRL_GPIO2EN
value|0x40
end_define

begin_define
define|#
directive|define
name|AXGE_GPIO_CTRL_GPIO1EN
value|0x20
end_define

begin_define
define|#
directive|define
name|AXGE_PHYPWR_RSTCTL
value|0x26
end_define

begin_define
define|#
directive|define
name|AXGE_PHYPWR_RSTCTL_BZ
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXGE_PHYPWR_RSTCTL_IPRL
value|0x0020
end_define

begin_define
define|#
directive|define
name|AXGE_PHYPWR_RSTCTL_AUTODETACH
value|0x1000
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QCTRL
value|0x2e
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QCTRL_TIME
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QCTRL_IFG
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QCTRL_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QTIMR_LOW
value|0x2f
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QTIMR_HIGH
value|0x30
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QSIZE
value|0x31
end_define

begin_define
define|#
directive|define
name|AXGE_RX_BULKIN_QIFG
value|0x32
end_define

begin_define
define|#
directive|define
name|AXGE_CLK_SELECT
value|0x33
end_define

begin_define
define|#
directive|define
name|AXGE_CLK_SELECT_BCS
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_CLK_SELECT_ACS
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_CLK_SELECT_ACSREQ
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_CLK_SELECT_ULR
value|0x08
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_CTL
value|0x34
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_IP
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_TCP
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_UDP
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_ICMP
value|0x08
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_IGMP
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_TCPV6
value|0x20
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_UDPV6
value|0x40
end_define

begin_define
define|#
directive|define
name|AXGE_RXCOE_ICMV6
value|0x80
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_CTL
value|0x35
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_IP
value|0x01
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_TCP
value|0x02
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_UDP
value|0x04
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_ICMP
value|0x08
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_IGMP
value|0x10
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_TCPV6
value|0x20
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_UDPV6
value|0x40
end_define

begin_define
define|#
directive|define
name|AXGE_TXCOE_ICMV6
value|0x80
end_define

begin_define
define|#
directive|define
name|AXGE_PAUSE_WATERLVL_HIGH
value|0x54
end_define

begin_define
define|#
directive|define
name|AXGE_PAUSE_WATERLVL_LOW
value|0x55
end_define

begin_define
define|#
directive|define
name|AXGE_EEP_EFUSE_CORRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|AX88179_EEPROM_MAGIC
value|0x17900b95
end_define

begin_define
define|#
directive|define
name|AXGE_CONFIG_IDX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|AXGE_IFACE_IDX
value|0
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_CRC_ERR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_ERR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L3_ERR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_ICMP
value|2
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_IGMP
value|3
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_TCMPV6
value|5
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L3_TYPE_IP
value|1
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L3_TYPE_IPV6
value|2
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_MASK
value|0x1c
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_UDP
value|4
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4_TYPE_TCP
value|16
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L3CSUM_ERR
value|2
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_L4CSUM_ERR
value|1
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_CRC_ERR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_DROP_ERR
value|0x40000000
end_define

begin_struct
struct|struct
name|axge_csum_hdr
block|{
name|uint16_t
name|cstatus
decl_stmt|;
define|#
directive|define
name|AXGE_CSUM_HDR_L4_CSUM_ERR
value|0x0001
define|#
directive|define
name|AXGE_CSUM_HDR_L3_CSUM_ERR
value|0x0002
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_UDP
value|0x0004
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_ICMP
value|0x0008
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_IGMP
value|0x000C
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_TCP
value|0x0010
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_TCPV6
value|0x0014
define|#
directive|define
name|AXGE_CSUM_HDR_L4_TYPE_MASK
value|0x001C
define|#
directive|define
name|AXGE_CSUM_HDR_L3_TYPE_IPV4
value|0x0020
define|#
directive|define
name|AXGE_CSUM_HDR_L3_TYPE_IPV6
value|0x0040
define|#
directive|define
name|AXGE_CSUM_HDR_VLAN_MASK
value|0x0700
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|AXGE_CSUM_HDR_LEN_MASK
value|0x1FFF
define|#
directive|define
name|AXGE_CSUM_HDR_CRC_ERR
value|0x2000
define|#
directive|define
name|AXGE_CSUM_HDR_MII_ERR
value|0x4000
define|#
directive|define
name|AXGE_CSUM_HDR_DROP
value|0x8000
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AXGE_CSUM_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x)& AXGE_CSUM_HDR_LEN_MASK)
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
name|AXGE_BULK_DT_WR
block|,
name|AXGE_BULK_DT_RD
block|,
name|AXGE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|axge_softc
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
name|AXGE_N_TRANSFER
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
name|AXGE_FLAG_LINK
value|0x0001
comment|/* got a link */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AXGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AXGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AXGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

