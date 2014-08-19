begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Kevin Lo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_comment
comment|/* Physical link status register */
end_comment

begin_define
define|#
directive|define
name|AXGE_PLSR
value|0x02
end_define

begin_define
define|#
directive|define
name|PLSR_USB_FS
value|0x01
end_define

begin_define
define|#
directive|define
name|PLSR_USB_HS
value|0x02
end_define

begin_define
define|#
directive|define
name|PLSR_USB_SS
value|0x04
end_define

begin_comment
comment|/* EEPROM address register */
end_comment

begin_define
define|#
directive|define
name|AXGE_EAR
value|0x07
end_define

begin_comment
comment|/* EEPROM data low register */
end_comment

begin_define
define|#
directive|define
name|AXGE_EDLR
value|0x08
end_define

begin_comment
comment|/* EEPROM data high register */
end_comment

begin_define
define|#
directive|define
name|AXGE_EDHR
value|0x09
end_define

begin_comment
comment|/* EEPROM command register */
end_comment

begin_define
define|#
directive|define
name|AXGE_ECR
value|0x0a
end_define

begin_comment
comment|/* Rx control register */
end_comment

begin_define
define|#
directive|define
name|AXGE_RCR
value|0x0b
end_define

begin_define
define|#
directive|define
name|RCR_STOP
value|0x0000
end_define

begin_define
define|#
directive|define
name|RCR_PRO
value|0x0001
end_define

begin_define
define|#
directive|define
name|RCR_AMALL
value|0x0002
end_define

begin_define
define|#
directive|define
name|RCR_AB
value|0x0008
end_define

begin_define
define|#
directive|define
name|RCR_AM
value|0x0010
end_define

begin_define
define|#
directive|define
name|RCR_AP
value|0x0020
end_define

begin_define
define|#
directive|define
name|RCR_SO
value|0x0080
end_define

begin_define
define|#
directive|define
name|RCR_DROP_CRCE
value|0x0100
end_define

begin_define
define|#
directive|define
name|RCR_IPE
value|0x0200
end_define

begin_define
define|#
directive|define
name|RCR_TX_CRC_PAD
value|0x0400
end_define

begin_comment
comment|/* Node id register */
end_comment

begin_define
define|#
directive|define
name|AXGE_NIDR
value|0x10
end_define

begin_comment
comment|/* Multicast filter array */
end_comment

begin_define
define|#
directive|define
name|AXGE_MFA
value|0x16
end_define

begin_comment
comment|/* Medium status register */
end_comment

begin_define
define|#
directive|define
name|AXGE_MSR
value|0x22
end_define

begin_define
define|#
directive|define
name|MSR_GM
value|0x0001
end_define

begin_define
define|#
directive|define
name|MSR_FD
value|0x0002
end_define

begin_define
define|#
directive|define
name|MSR_EN_125MHZ
value|0x0008
end_define

begin_define
define|#
directive|define
name|MSR_RFC
value|0x0010
end_define

begin_define
define|#
directive|define
name|MSR_TFC
value|0x0020
end_define

begin_define
define|#
directive|define
name|MSR_RE
value|0x0100
end_define

begin_define
define|#
directive|define
name|MSR_PS
value|0x0200
end_define

begin_comment
comment|/* Monitor mode status register */
end_comment

begin_define
define|#
directive|define
name|AXGE_MMSR
value|0x24
end_define

begin_define
define|#
directive|define
name|MMSR_RWLC
value|0x02
end_define

begin_define
define|#
directive|define
name|MMSR_RWMP
value|0x04
end_define

begin_define
define|#
directive|define
name|MMSR_RWWF
value|0x08
end_define

begin_define
define|#
directive|define
name|MMSR_RW_FLAG
value|0x10
end_define

begin_define
define|#
directive|define
name|MMSR_PME_POL
value|0x20
end_define

begin_define
define|#
directive|define
name|MMSR_PME_TYPE
value|0x40
end_define

begin_define
define|#
directive|define
name|MMSR_PME_IND
value|0x80
end_define

begin_comment
comment|/* GPIO control/status register */
end_comment

begin_define
define|#
directive|define
name|AXGE_GPIOCR
value|0x25
end_define

begin_comment
comment|/* Ethernet PHY power& reset control register */
end_comment

begin_define
define|#
directive|define
name|AXGE_EPPRCR
value|0x26
end_define

begin_define
define|#
directive|define
name|EPPRCR_BZ
value|0x0010
end_define

begin_define
define|#
directive|define
name|EPPRCR_IPRL
value|0x0020
end_define

begin_define
define|#
directive|define
name|EPPRCR_AUTODETACH
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

begin_comment
comment|/* COE Rx control register */
end_comment

begin_define
define|#
directive|define
name|AXGE_CRCR
value|0x34
end_define

begin_define
define|#
directive|define
name|CRCR_IP
value|0x01
end_define

begin_define
define|#
directive|define
name|CRCR_TCP
value|0x02
end_define

begin_define
define|#
directive|define
name|CRCR_UDP
value|0x04
end_define

begin_define
define|#
directive|define
name|CRCR_ICMP
value|0x08
end_define

begin_define
define|#
directive|define
name|CRCR_IGMP
value|0x10
end_define

begin_define
define|#
directive|define
name|CRCR_TCPV6
value|0x20
end_define

begin_define
define|#
directive|define
name|CRCR_UDPV6
value|0x40
end_define

begin_define
define|#
directive|define
name|CRCR_ICMPV6
value|0x80
end_define

begin_comment
comment|/* COE Tx control register */
end_comment

begin_define
define|#
directive|define
name|AXGE_CTCR
value|0x35
end_define

begin_define
define|#
directive|define
name|CTCR_IP
value|0x01
end_define

begin_define
define|#
directive|define
name|CTCR_TCP
value|0x02
end_define

begin_define
define|#
directive|define
name|CTCR_UDP
value|0x04
end_define

begin_define
define|#
directive|define
name|CTCR_ICMP
value|0x08
end_define

begin_define
define|#
directive|define
name|CTCR_IGMP
value|0x10
end_define

begin_define
define|#
directive|define
name|CTCR_TCPV6
value|0x20
end_define

begin_define
define|#
directive|define
name|CTCR_UDPV6
value|0x40
end_define

begin_define
define|#
directive|define
name|CTCR_ICMPV6
value|0x80
end_define

begin_comment
comment|/* Pause water level high register */
end_comment

begin_define
define|#
directive|define
name|AXGE_PWLHR
value|0x54
end_define

begin_comment
comment|/* Pause water level low register */
end_comment

begin_define
define|#
directive|define
name|AXGE_PWLLR
value|0x55
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
name|AXGE_RXHDR_L4_TYPE_MASK
value|0x1c
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
name|AXGE_RXHDR_L3CSUM_ERR
value|2
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
name|AXGE_RXHDR_CRC_ERR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AXGE_RXHDR_DROP_ERR
value|0x80000000
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

