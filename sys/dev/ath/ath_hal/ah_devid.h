begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_DEVID_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_DEVID_H_
end_define

begin_define
define|#
directive|define
name|ATHEROS_VENDOR_ID
value|0x168c
end_define

begin_comment
comment|/* Atheros PCI vendor ID */
end_comment

begin_comment
comment|/*  * NB: all Atheros-based devices should have a PCI vendor ID  *     of 0x168c, but some vendors, in their infinite wisdom  *     do not follow this so we must handle them specially.  */
end_comment

begin_define
define|#
directive|define
name|ATHEROS_3COM_VENDOR_ID
value|0xa727
end_define

begin_comment
comment|/* 3Com 3CRPAG175 vendor ID */
end_comment

begin_define
define|#
directive|define
name|ATHEROS_3COM2_VENDOR_ID
value|0x10b7
end_define

begin_comment
comment|/* 3Com 3CRDAG675 vendor ID */
end_comment

begin_comment
comment|/* AR5210 (for reference) */
end_comment

begin_define
define|#
directive|define
name|AR5210_DEFAULT
value|0x1107
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5210_PROD
value|0x0007
end_define

begin_comment
comment|/* Final device ID */
end_comment

begin_define
define|#
directive|define
name|AR5210_AP
value|0x0207
end_define

begin_comment
comment|/* Early AP11s */
end_comment

begin_comment
comment|/* AR5211 */
end_comment

begin_define
define|#
directive|define
name|AR5211_DEFAULT
value|0x1112
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5311_DEVID
value|0x0011
end_define

begin_comment
comment|/* Final ar5311 devid */
end_comment

begin_define
define|#
directive|define
name|AR5211_DEVID
value|0x0012
end_define

begin_comment
comment|/* Final ar5211 devid */
end_comment

begin_define
define|#
directive|define
name|AR5211_LEGACY
value|0xff12
end_define

begin_comment
comment|/* Original emulation board */
end_comment

begin_define
define|#
directive|define
name|AR5211_FPGA11B
value|0xf11b
end_define

begin_comment
comment|/* 11b emulation board */
end_comment

begin_comment
comment|/* AR5212 */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEFAULT
value|0x1113
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEVID
value|0x0013
end_define

begin_comment
comment|/* Final ar5212 devid */
end_comment

begin_define
define|#
directive|define
name|AR5212_FPGA
value|0xf013
end_define

begin_comment
comment|/* Emulation board */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEVID_IBM
value|0x1014
end_define

begin_comment
comment|/* IBM minipci ID */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR5312_REV2
value|0x0052
end_define

begin_comment
comment|/* AR5312 WMAC (AP31) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR5312_REV7
value|0x0057
end_define

begin_comment
comment|/* AR5312 WMAC (AP30-040) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2313_REV8
value|0x0058
end_define

begin_comment
comment|/* AR2313 WMAC (AP43-030) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2315_REV6
value|0x0086
end_define

begin_comment
comment|/* AR2315 WMAC (AP51-Light) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2315_REV7
value|0x0087
end_define

begin_comment
comment|/* AR2315 WMAC (AP51-Full) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2317_REV1
value|0x0090
end_define

begin_comment
comment|/* AR2317 WMAC (AP61-Light) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2317_REV2
value|0x0091
end_define

begin_comment
comment|/* AR2317 WMAC (AP61-Full) */
end_comment

begin_comment
comment|/* AR5212 compatible devid's also attach to 5212 */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEVID_0014
value|0x0014
end_define

begin_define
define|#
directive|define
name|AR5212_DEVID_0015
value|0x0015
end_define

begin_define
define|#
directive|define
name|AR5212_DEVID_0016
value|0x0016
end_define

begin_define
define|#
directive|define
name|AR5212_DEVID_0017
value|0x0017
end_define

begin_define
define|#
directive|define
name|AR5212_DEVID_0018
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR5212_DEVID_0019
value|0x0019
end_define

begin_define
define|#
directive|define
name|AR5212_AR2413
value|0x001a
end_define

begin_comment
comment|/* AR2413 aka Griffin-lite */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR5413
value|0x001b
end_define

begin_comment
comment|/* Eagle */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR5424
value|0x001c
end_define

begin_comment
comment|/* Condor (PCI express) */
end_comment

begin_define
define|#
directive|define
name|AR5212_AR2417
value|0x001d
end_define

begin_comment
comment|/* Nala, PCI */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEVID_FF19
value|0xff19
end_define

begin_comment
comment|/* XXX PCI express */
end_comment

begin_comment
comment|/* AR5213 */
end_comment

begin_define
define|#
directive|define
name|AR5213_SREV_1_0
value|0x0055
end_define

begin_define
define|#
directive|define
name|AR5213_SREV_REG
value|0x4020
end_define

begin_comment
comment|/* AR5416 compatible devid's  */
end_comment

begin_define
define|#
directive|define
name|AR5416_DEVID_PCI
value|0x0023
end_define

begin_comment
comment|/* AR5416 PCI (MB/CB) Owl */
end_comment

begin_define
define|#
directive|define
name|AR5416_DEVID_PCIE
value|0x0024
end_define

begin_comment
comment|/* AR5418 PCI-E (XB) Owl */
end_comment

begin_define
define|#
directive|define
name|AR5416_AR9130_DEVID
value|0x000b
end_define

begin_comment
comment|/* AR9130 SoC WiMAC */
end_comment

begin_define
define|#
directive|define
name|AR9160_DEVID_PCI
value|0x0027
end_define

begin_comment
comment|/* AR9160 PCI Sowl */
end_comment

begin_define
define|#
directive|define
name|AR9280_DEVID_PCI
value|0x0029
end_define

begin_comment
comment|/* AR9280 PCI Merlin */
end_comment

begin_define
define|#
directive|define
name|AR9280_DEVID_PCIE
value|0x002a
end_define

begin_comment
comment|/* AR9220 PCI-E Merlin */
end_comment

begin_define
define|#
directive|define
name|AR9285_DEVID_PCIE
value|0x002b
end_define

begin_comment
comment|/* AR9285 PCI-E Kite */
end_comment

begin_define
define|#
directive|define
name|AR2427_DEVID_PCIE
value|0x002c
end_define

begin_comment
comment|/* AR2427 PCI-E w/ 802.11n bonded out */
end_comment

begin_define
define|#
directive|define
name|AR9287_DEVID_PCI
value|0x002d
end_define

begin_comment
comment|/* AR9227 PCI Kiwi */
end_comment

begin_define
define|#
directive|define
name|AR9287_DEVID_PCIE
value|0x002e
end_define

begin_comment
comment|/* AR9287 PCI-E Kiwi */
end_comment

begin_comment
comment|/* AR9300 */
end_comment

begin_define
define|#
directive|define
name|AR9300_DEVID_AR9380_PCIE
value|0x0030
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_EMU_PCIE
value|0xabcd
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR9340
value|0x0031
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR9485_PCIE
value|0x0032
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR9580_PCIE
value|0x0033
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR946X_PCIE
value|0x0034
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR9330
value|0x0035
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_QCA9565
value|0x0036
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_AR1111_PCIE
value|0x0037
end_define

begin_define
define|#
directive|define
name|AR9300_DEVID_QCA955X
value|0x0039
end_define

begin_define
define|#
directive|define
name|AR_SUBVENDOR_ID_NOG
value|0x0e11
end_define

begin_comment
comment|/* No 11G subvendor ID */
end_comment

begin_define
define|#
directive|define
name|AR_SUBVENDOR_ID_NEW_A
value|0x7065
end_define

begin_comment
comment|/* Update device to new RD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_DEVID_H */
end_comment

end_unit

