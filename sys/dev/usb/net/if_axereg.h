begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999, 2000-2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_struct
struct|struct
name|axe_sframe_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
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
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|usb2_ether_getmii(&(sc)->sc_ue)
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
name|AXE_INTR_DT_RD
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
name|usb2_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|usb2_xfer
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
name|AXE_FLAG_772
value|0x1000
comment|/* AX88772 */
define|#
directive|define
name|AXE_FLAG_178
value|0x2000
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
block|}
struct|;
end_struct

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

