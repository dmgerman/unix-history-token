begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003, Shunsuke Akiyama<akiyama@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|RUE_CONFIG_IDX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|RUE_IFACE_IDX
value|0
end_define

begin_define
define|#
directive|define
name|RUE_INTR_PKTLEN
value|0x8
end_define

begin_define
define|#
directive|define
name|RUE_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|RUE_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/* Registers. */
end_comment

begin_define
define|#
directive|define
name|RUE_IDR0
value|0x0120
end_define

begin_define
define|#
directive|define
name|RUE_IDR1
value|0x0121
end_define

begin_define
define|#
directive|define
name|RUE_IDR2
value|0x0122
end_define

begin_define
define|#
directive|define
name|RUE_IDR3
value|0x0123
end_define

begin_define
define|#
directive|define
name|RUE_IDR4
value|0x0124
end_define

begin_define
define|#
directive|define
name|RUE_IDR5
value|0x0125
end_define

begin_define
define|#
directive|define
name|RUE_MAR0
value|0x0126
end_define

begin_define
define|#
directive|define
name|RUE_MAR1
value|0x0127
end_define

begin_define
define|#
directive|define
name|RUE_MAR2
value|0x0128
end_define

begin_define
define|#
directive|define
name|RUE_MAR3
value|0x0129
end_define

begin_define
define|#
directive|define
name|RUE_MAR4
value|0x012A
end_define

begin_define
define|#
directive|define
name|RUE_MAR5
value|0x012B
end_define

begin_define
define|#
directive|define
name|RUE_MAR6
value|0x012C
end_define

begin_define
define|#
directive|define
name|RUE_MAR7
value|0x012D
end_define

begin_define
define|#
directive|define
name|RUE_CR
value|0x012E
end_define

begin_comment
comment|/* B, R/W */
end_comment

begin_define
define|#
directive|define
name|RUE_CR_SOFT_RST
value|0x10
end_define

begin_define
define|#
directive|define
name|RUE_CR_RE
value|0x08
end_define

begin_define
define|#
directive|define
name|RUE_CR_TE
value|0x04
end_define

begin_define
define|#
directive|define
name|RUE_CR_EP3CLREN
value|0x02
end_define

begin_define
define|#
directive|define
name|RUE_TCR
value|0x012F
end_define

begin_comment
comment|/* B, R/W */
end_comment

begin_define
define|#
directive|define
name|RUE_TCR_TXRR1
value|0x80
end_define

begin_define
define|#
directive|define
name|RUE_TCR_TXRR0
value|0x40
end_define

begin_define
define|#
directive|define
name|RUE_TCR_IFG1
value|0x10
end_define

begin_define
define|#
directive|define
name|RUE_TCR_IFG0
value|0x08
end_define

begin_define
define|#
directive|define
name|RUE_TCR_NOCRC
value|0x01
end_define

begin_define
define|#
directive|define
name|RUE_TCR_CONFIG
value|(RUE_TCR_TXRR1 | RUE_TCR_TXRR0 | 	\ 				    RUE_TCR_IFG1 | RUE_TCR_IFG0)
end_define

begin_define
define|#
directive|define
name|RUE_RCR
value|0x0130
end_define

begin_comment
comment|/* W, R/W */
end_comment

begin_define
define|#
directive|define
name|RUE_RCR_TAIL
value|0x80
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AER
value|0x40
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AR
value|0x20
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AM
value|0x10
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AB
value|0x08
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AD
value|0x04
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AAM
value|0x02
end_define

begin_define
define|#
directive|define
name|RUE_RCR_AAP
value|0x01
end_define

begin_define
define|#
directive|define
name|RUE_RCR_CONFIG
value|(RUE_RCR_TAIL | RUE_RCR_AD)
end_define

begin_define
define|#
directive|define
name|RUE_TSR
value|0x0132
end_define

begin_define
define|#
directive|define
name|RUE_RSR
value|0x0133
end_define

begin_define
define|#
directive|define
name|RUE_CON0
value|0x0135
end_define

begin_define
define|#
directive|define
name|RUE_CON1
value|0x0136
end_define

begin_define
define|#
directive|define
name|RUE_MSR
value|0x0137
end_define

begin_define
define|#
directive|define
name|RUE_PHYADD
value|0x0138
end_define

begin_define
define|#
directive|define
name|RUE_PHYDAT
value|0x0139
end_define

begin_define
define|#
directive|define
name|RUE_PHYCNT
value|0x013B
end_define

begin_comment
comment|/* B, R/W */
end_comment

begin_define
define|#
directive|define
name|RUE_PHYCNT_PHYOWN
value|0x40
end_define

begin_define
define|#
directive|define
name|RUE_PHYCNT_RWCR
value|0x20
end_define

begin_define
define|#
directive|define
name|RUE_GPPC
value|0x013D
end_define

begin_define
define|#
directive|define
name|RUE_WAKECNT
value|0x013E
end_define

begin_define
define|#
directive|define
name|RUE_BMCR
value|0x0140
end_define

begin_define
define|#
directive|define
name|RUE_BMCR_SPD_SET
value|0x2000
end_define

begin_define
define|#
directive|define
name|RUE_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|RUE_BMSR
value|0x0142
end_define

begin_define
define|#
directive|define
name|RUE_ANAR
value|0x0144
end_define

begin_comment
comment|/* W, R/W */
end_comment

begin_define
define|#
directive|define
name|RUE_ANAR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|RUE_ANLP
value|0x0146
end_define

begin_comment
comment|/* W, R/O */
end_comment

begin_define
define|#
directive|define
name|RUE_ANLP_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|RUE_AER
value|0x0148
end_define

begin_define
define|#
directive|define
name|RUE_NWAYT
value|0x014A
end_define

begin_define
define|#
directive|define
name|RUE_CSCR
value|0x014C
end_define

begin_define
define|#
directive|define
name|RUE_CRC0
value|0x014E
end_define

begin_define
define|#
directive|define
name|RUE_CRC1
value|0x0150
end_define

begin_define
define|#
directive|define
name|RUE_CRC2
value|0x0152
end_define

begin_define
define|#
directive|define
name|RUE_CRC3
value|0x0154
end_define

begin_define
define|#
directive|define
name|RUE_CRC4
value|0x0156
end_define

begin_define
define|#
directive|define
name|RUE_BYTEMASK0
value|0x0158
end_define

begin_define
define|#
directive|define
name|RUE_BYTEMASK1
value|0x0160
end_define

begin_define
define|#
directive|define
name|RUE_BYTEMASK2
value|0x0168
end_define

begin_define
define|#
directive|define
name|RUE_BYTEMASK3
value|0x0170
end_define

begin_define
define|#
directive|define
name|RUE_BYTEMASK4
value|0x0178
end_define

begin_define
define|#
directive|define
name|RUE_PHY1
value|0x0180
end_define

begin_define
define|#
directive|define
name|RUE_PHY2
value|0x0184
end_define

begin_define
define|#
directive|define
name|RUE_TW1
value|0x0186
end_define

begin_define
define|#
directive|define
name|RUE_REG_MIN
value|0x0120
end_define

begin_define
define|#
directive|define
name|RUE_REG_MAX
value|0x0189
end_define

begin_comment
comment|/* EEPROM address declarations. */
end_comment

begin_define
define|#
directive|define
name|RUE_EEPROM_BASE
value|0x1200
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR0
value|(RUE_EEPROM_BASE + 0x02)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR1
value|(RUE_EEPROM_BASE + 0x03)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR2
value|(RUE_EEPROM_BASE + 0x03)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR3
value|(RUE_EEPROM_BASE + 0x03)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR4
value|(RUE_EEPROM_BASE + 0x03)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_IDR5
value|(RUE_EEPROM_BASE + 0x03)
end_define

begin_define
define|#
directive|define
name|RUE_EEPROM_INTERVAL
value|(RUE_EEPROM_BASE + 0x17)
end_define

begin_define
define|#
directive|define
name|RUE_RXSTAT_VALID
value|(0x01<< 12)
end_define

begin_define
define|#
directive|define
name|RUE_RXSTAT_RUNT
value|(0x02<< 12)
end_define

begin_define
define|#
directive|define
name|RUE_RXSTAT_PMATCH
value|(0x04<< 12)
end_define

begin_define
define|#
directive|define
name|RUE_RXSTAT_MCAST
value|(0x08<< 12)
end_define

begin_define
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|usb2_ether_getmii(&(sc)->sc_ue)
end_define

begin_struct
struct|struct
name|rue_intrpkt
block|{
name|uint8_t
name|rue_tsr
decl_stmt|;
name|uint8_t
name|rue_rsr
decl_stmt|;
name|uint8_t
name|rue_gep_msr
decl_stmt|;
name|uint8_t
name|rue_waksr
decl_stmt|;
name|uint8_t
name|rue_txok_cnt
decl_stmt|;
name|uint8_t
name|rue_rxlost_cnt
decl_stmt|;
name|uint8_t
name|rue_crcerr_cnt
decl_stmt|;
name|uint8_t
name|rue_col_cnt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|rue_type
block|{
name|uint16_t
name|rue_vid
decl_stmt|;
name|uint16_t
name|rue_did
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|RUE_BULK_DT_WR
block|,
name|RUE_BULK_DT_RD
block|,
name|RUE_INTR_DT_RD
block|,
name|RUE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|rue_softc
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
name|RUE_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|RUE_FLAG_LINK
value|0x0001
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|RUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|RUE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

