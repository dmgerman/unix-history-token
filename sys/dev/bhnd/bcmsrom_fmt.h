begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Broadcom Corporation  *   * This file is derived from the bcmsrom.h header distributed with Broadcom's  * brcm80211 Linux driver release, as contributed to the Linux staging  * repository.   *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BCMSROM_FMT_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BCMSROM_FMT_H_
end_define

begin_comment
comment|/* Maximum srom: 6 Kilobits == 768 bytes */
end_comment

begin_define
define|#
directive|define
name|SROM_MAX
value|768
end_define

begin_define
define|#
directive|define
name|SROM_MAXW
value|384
end_define

begin_define
define|#
directive|define
name|VARS_MAX
value|4096
end_define

begin_comment
comment|/* PCI fields */
end_comment

begin_define
define|#
directive|define
name|PCI_F0DEVID
value|48
end_define

begin_define
define|#
directive|define
name|SROM_WORDS
value|64
end_define

begin_define
define|#
directive|define
name|SROM3_SWRGN_OFF
value|28
end_define

begin_comment
comment|/* s/w region offset in words */
end_comment

begin_define
define|#
directive|define
name|SROM_SSID
value|2
end_define

begin_define
define|#
directive|define
name|SROM_WL1LHMAXP
value|29
end_define

begin_define
define|#
directive|define
name|SROM_WL1LPAB0
value|30
end_define

begin_define
define|#
directive|define
name|SROM_WL1LPAB1
value|31
end_define

begin_define
define|#
directive|define
name|SROM_WL1LPAB2
value|32
end_define

begin_define
define|#
directive|define
name|SROM_WL1HPAB0
value|33
end_define

begin_define
define|#
directive|define
name|SROM_WL1HPAB1
value|34
end_define

begin_define
define|#
directive|define
name|SROM_WL1HPAB2
value|35
end_define

begin_define
define|#
directive|define
name|SROM_MACHI_IL0
value|36
end_define

begin_define
define|#
directive|define
name|SROM_MACMID_IL0
value|37
end_define

begin_define
define|#
directive|define
name|SROM_MACLO_IL0
value|38
end_define

begin_define
define|#
directive|define
name|SROM_MACHI_ET0
value|39
end_define

begin_define
define|#
directive|define
name|SROM_MACMID_ET0
value|40
end_define

begin_define
define|#
directive|define
name|SROM_MACLO_ET0
value|41
end_define

begin_define
define|#
directive|define
name|SROM_MACHI_ET1
value|42
end_define

begin_define
define|#
directive|define
name|SROM_MACMID_ET1
value|43
end_define

begin_define
define|#
directive|define
name|SROM_MACLO_ET1
value|44
end_define

begin_define
define|#
directive|define
name|SROM3_MACHI
value|37
end_define

begin_define
define|#
directive|define
name|SROM3_MACMID
value|38
end_define

begin_define
define|#
directive|define
name|SROM3_MACLO
value|39
end_define

begin_define
define|#
directive|define
name|SROM_BXARSSI2G
value|40
end_define

begin_define
define|#
directive|define
name|SROM_BXARSSI5G
value|41
end_define

begin_define
define|#
directive|define
name|SROM_TRI52G
value|42
end_define

begin_define
define|#
directive|define
name|SROM_TRI5GHL
value|43
end_define

begin_define
define|#
directive|define
name|SROM_RXPO52G
value|45
end_define

begin_define
define|#
directive|define
name|SROM2_ENETPHY
value|45
end_define

begin_define
define|#
directive|define
name|SROM_AABREV
value|46
end_define

begin_comment
comment|/* Fields in AABREV */
end_comment

begin_define
define|#
directive|define
name|SROM_BR_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SROM_CC_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|SROM_CC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SROM_AA0_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|SROM_AA0_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SROM_AA1_MASK
value|0xc000
end_define

begin_define
define|#
directive|define
name|SROM_AA1_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|SROM_WL0PAB0
value|47
end_define

begin_define
define|#
directive|define
name|SROM_WL0PAB1
value|48
end_define

begin_define
define|#
directive|define
name|SROM_WL0PAB2
value|49
end_define

begin_define
define|#
directive|define
name|SROM_LEDBH10
value|50
end_define

begin_define
define|#
directive|define
name|SROM_LEDBH32
value|51
end_define

begin_define
define|#
directive|define
name|SROM_WL10MAXP
value|52
end_define

begin_define
define|#
directive|define
name|SROM_WL1PAB0
value|53
end_define

begin_define
define|#
directive|define
name|SROM_WL1PAB1
value|54
end_define

begin_define
define|#
directive|define
name|SROM_WL1PAB2
value|55
end_define

begin_define
define|#
directive|define
name|SROM_ITT
value|56
end_define

begin_define
define|#
directive|define
name|SROM_BFL
value|57
end_define

begin_define
define|#
directive|define
name|SROM_BFL2
value|28
end_define

begin_define
define|#
directive|define
name|SROM3_BFL2
value|61
end_define

begin_define
define|#
directive|define
name|SROM_AG10
value|58
end_define

begin_define
define|#
directive|define
name|SROM_CCODE
value|59
end_define

begin_define
define|#
directive|define
name|SROM_OPO
value|60
end_define

begin_define
define|#
directive|define
name|SROM3_LEDDC
value|62
end_define

begin_define
define|#
directive|define
name|SROM_CRCREV
value|63
end_define

begin_comment
comment|/* SROM Rev 4: Reallocate the software part of the srom to accommodate  * MIMO features. It assumes up to two PCIE functions and 440 bytes  * of useable srom i.e. the useable storage in chips with OTP that  * implements hardware redundancy.  */
end_comment

begin_define
define|#
directive|define
name|SROM4_WORDS
value|220
end_define

begin_define
define|#
directive|define
name|SROM4_SIGN
value|32
end_define

begin_define
define|#
directive|define
name|SROM4_SIGNATURE
value|0x5372
end_define

begin_define
define|#
directive|define
name|SROM4_BREV
value|33
end_define

begin_define
define|#
directive|define
name|SROM4_BFL0
value|34
end_define

begin_define
define|#
directive|define
name|SROM4_BFL1
value|35
end_define

begin_define
define|#
directive|define
name|SROM4_BFL2
value|36
end_define

begin_define
define|#
directive|define
name|SROM4_BFL3
value|37
end_define

begin_define
define|#
directive|define
name|SROM5_BFL0
value|37
end_define

begin_define
define|#
directive|define
name|SROM5_BFL1
value|38
end_define

begin_define
define|#
directive|define
name|SROM5_BFL2
value|39
end_define

begin_define
define|#
directive|define
name|SROM5_BFL3
value|40
end_define

begin_define
define|#
directive|define
name|SROM4_MACHI
value|38
end_define

begin_define
define|#
directive|define
name|SROM4_MACMID
value|39
end_define

begin_define
define|#
directive|define
name|SROM4_MACLO
value|40
end_define

begin_define
define|#
directive|define
name|SROM5_MACHI
value|41
end_define

begin_define
define|#
directive|define
name|SROM5_MACMID
value|42
end_define

begin_define
define|#
directive|define
name|SROM5_MACLO
value|43
end_define

begin_define
define|#
directive|define
name|SROM4_CCODE
value|41
end_define

begin_define
define|#
directive|define
name|SROM4_REGREV
value|42
end_define

begin_define
define|#
directive|define
name|SROM5_CCODE
value|34
end_define

begin_define
define|#
directive|define
name|SROM5_REGREV
value|35
end_define

begin_define
define|#
directive|define
name|SROM4_LEDBH10
value|43
end_define

begin_define
define|#
directive|define
name|SROM4_LEDBH32
value|44
end_define

begin_define
define|#
directive|define
name|SROM5_LEDBH10
value|59
end_define

begin_define
define|#
directive|define
name|SROM5_LEDBH32
value|60
end_define

begin_define
define|#
directive|define
name|SROM4_LEDDC
value|45
end_define

begin_define
define|#
directive|define
name|SROM5_LEDDC
value|45
end_define

begin_define
define|#
directive|define
name|SROM4_AA
value|46
end_define

begin_define
define|#
directive|define
name|SROM4_AA2G_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SROM4_AA2G_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SROM4_AA5G_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|SROM4_AA5G_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SROM4_AG10
value|47
end_define

begin_define
define|#
directive|define
name|SROM4_AG32
value|48
end_define

begin_define
define|#
directive|define
name|SROM4_TXPID2G
value|49
end_define

begin_define
define|#
directive|define
name|SROM4_TXPID5G
value|51
end_define

begin_define
define|#
directive|define
name|SROM4_TXPID5GL
value|53
end_define

begin_define
define|#
directive|define
name|SROM4_TXPID5GH
value|55
end_define

begin_define
define|#
directive|define
name|SROM4_TXRXC
value|61
end_define

begin_define
define|#
directive|define
name|SROM4_TXCHAIN_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|SROM4_TXCHAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SROM4_RXCHAIN_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|SROM4_RXCHAIN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SROM4_SWITCH_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|SROM4_SWITCH_SHIFT
value|8
end_define

begin_comment
comment|/* Per-path fields */
end_comment

begin_define
define|#
directive|define
name|MAX_PATH_SROM
value|4
end_define

begin_define
define|#
directive|define
name|SROM4_PATH0
value|64
end_define

begin_define
define|#
directive|define
name|SROM4_PATH1
value|87
end_define

begin_define
define|#
directive|define
name|SROM4_PATH2
value|110
end_define

begin_define
define|#
directive|define
name|SROM4_PATH3
value|133
end_define

begin_define
define|#
directive|define
name|SROM4_2G_ITT_MAXP
value|0
end_define

begin_define
define|#
directive|define
name|SROM4_2G_PA
value|1
end_define

begin_define
define|#
directive|define
name|SROM4_5G_ITT_MAXP
value|5
end_define

begin_define
define|#
directive|define
name|SROM4_5GLH_MAXP
value|6
end_define

begin_define
define|#
directive|define
name|SROM4_5G_PA
value|7
end_define

begin_define
define|#
directive|define
name|SROM4_5GL_PA
value|11
end_define

begin_define
define|#
directive|define
name|SROM4_5GH_PA
value|15
end_define

begin_comment
comment|/* Fields in the ITT_MAXP and 5GLH_MAXP words */
end_comment

begin_define
define|#
directive|define
name|B2G_MAXP_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B2G_ITT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|B5G_MAXP_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B5G_ITT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|B5GH_MAXP_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B5GL_MAXP_SHIFT
value|8
end_define

begin_comment
comment|/* All the miriad power offsets */
end_comment

begin_define
define|#
directive|define
name|SROM4_2G_CCKPO
value|156
end_define

begin_define
define|#
directive|define
name|SROM4_2G_OFDMPO
value|157
end_define

begin_define
define|#
directive|define
name|SROM4_5G_OFDMPO
value|159
end_define

begin_define
define|#
directive|define
name|SROM4_5GL_OFDMPO
value|161
end_define

begin_define
define|#
directive|define
name|SROM4_5GH_OFDMPO
value|163
end_define

begin_define
define|#
directive|define
name|SROM4_2G_MCSPO
value|165
end_define

begin_define
define|#
directive|define
name|SROM4_5G_MCSPO
value|173
end_define

begin_define
define|#
directive|define
name|SROM4_5GL_MCSPO
value|181
end_define

begin_define
define|#
directive|define
name|SROM4_5GH_MCSPO
value|189
end_define

begin_define
define|#
directive|define
name|SROM4_CDDPO
value|197
end_define

begin_define
define|#
directive|define
name|SROM4_STBCPO
value|198
end_define

begin_define
define|#
directive|define
name|SROM4_BW40PO
value|199
end_define

begin_define
define|#
directive|define
name|SROM4_BWDUPPO
value|200
end_define

begin_define
define|#
directive|define
name|SROM4_CRCREV
value|219
end_define

begin_comment
comment|/* SROM Rev 8: Make space for a 48word hardware header for PCIe rev>= 6.  * This is acombined srom for both MIMO and SISO boards, usable in  * the .130 4Kilobit OTP with hardware redundancy.  */
end_comment

begin_define
define|#
directive|define
name|SROM8_SIGN
value|64
end_define

begin_define
define|#
directive|define
name|SROM8_BREV
value|65
end_define

begin_define
define|#
directive|define
name|SROM8_BFL0
value|66
end_define

begin_define
define|#
directive|define
name|SROM8_BFL1
value|67
end_define

begin_define
define|#
directive|define
name|SROM8_BFL2
value|68
end_define

begin_define
define|#
directive|define
name|SROM8_BFL3
value|69
end_define

begin_define
define|#
directive|define
name|SROM8_MACHI
value|70
end_define

begin_define
define|#
directive|define
name|SROM8_MACMID
value|71
end_define

begin_define
define|#
directive|define
name|SROM8_MACLO
value|72
end_define

begin_define
define|#
directive|define
name|SROM8_CCODE
value|73
end_define

begin_define
define|#
directive|define
name|SROM8_REGREV
value|74
end_define

begin_define
define|#
directive|define
name|SROM8_LEDBH10
value|75
end_define

begin_define
define|#
directive|define
name|SROM8_LEDBH32
value|76
end_define

begin_define
define|#
directive|define
name|SROM8_LEDDC
value|77
end_define

begin_define
define|#
directive|define
name|SROM8_AA
value|78
end_define

begin_define
define|#
directive|define
name|SROM8_AG10
value|79
end_define

begin_define
define|#
directive|define
name|SROM8_AG32
value|80
end_define

begin_define
define|#
directive|define
name|SROM8_TXRXC
value|81
end_define

begin_define
define|#
directive|define
name|SROM8_BXARSSI2G
value|82
end_define

begin_define
define|#
directive|define
name|SROM8_BXARSSI5G
value|83
end_define

begin_define
define|#
directive|define
name|SROM8_TRI52G
value|84
end_define

begin_define
define|#
directive|define
name|SROM8_TRI5GHL
value|85
end_define

begin_define
define|#
directive|define
name|SROM8_RXPO52G
value|86
end_define

begin_define
define|#
directive|define
name|SROM8_FEM2G
value|87
end_define

begin_define
define|#
directive|define
name|SROM8_FEM5G
value|88
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_ANTSWLUT_MASK
value|0xf800
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_ANTSWLUT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_TR_ISO_MASK
value|0x0700
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_TR_ISO_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_PDET_RANGE_MASK
value|0x00f8
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_PDET_RANGE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_EXTPA_GAIN_MASK
value|0x0006
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_EXTPA_GAIN_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_TSSIPOS_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|SROM8_FEM_TSSIPOS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SROM8_THERMAL
value|89
end_define

begin_comment
comment|/* Temp sense related entries */
end_comment

begin_define
define|#
directive|define
name|SROM8_MPWR_RAWTS
value|90
end_define

begin_define
define|#
directive|define
name|SROM8_TS_SLP_OPT_CORRX
value|91
end_define

begin_comment
comment|/* FOC: freiquency offset correction, HWIQ: H/W IOCAL enable, IQSWP: IQ CAL swap disable */
end_comment

begin_define
define|#
directive|define
name|SROM8_FOC_HWIQ_IQSWP
value|92
end_define

begin_comment
comment|/* Temperature delta for PHY calibration */
end_comment

begin_define
define|#
directive|define
name|SROM8_PHYCAL_TEMPDELTA
value|93
end_define

begin_comment
comment|/* Per-path offsets& fields */
end_comment

begin_define
define|#
directive|define
name|SROM8_PATH0
value|96
end_define

begin_define
define|#
directive|define
name|SROM8_PATH1
value|112
end_define

begin_define
define|#
directive|define
name|SROM8_PATH2
value|128
end_define

begin_define
define|#
directive|define
name|SROM8_PATH3
value|144
end_define

begin_define
define|#
directive|define
name|SROM8_2G_ITT_MAXP
value|0
end_define

begin_define
define|#
directive|define
name|SROM8_2G_PA
value|1
end_define

begin_define
define|#
directive|define
name|SROM8_5G_ITT_MAXP
value|4
end_define

begin_define
define|#
directive|define
name|SROM8_5GLH_MAXP
value|5
end_define

begin_define
define|#
directive|define
name|SROM8_5G_PA
value|6
end_define

begin_define
define|#
directive|define
name|SROM8_5GL_PA
value|9
end_define

begin_define
define|#
directive|define
name|SROM8_5GH_PA
value|12
end_define

begin_comment
comment|/* All the miriad power offsets */
end_comment

begin_define
define|#
directive|define
name|SROM8_2G_CCKPO
value|160
end_define

begin_define
define|#
directive|define
name|SROM8_2G_OFDMPO
value|161
end_define

begin_define
define|#
directive|define
name|SROM8_5G_OFDMPO
value|163
end_define

begin_define
define|#
directive|define
name|SROM8_5GL_OFDMPO
value|165
end_define

begin_define
define|#
directive|define
name|SROM8_5GH_OFDMPO
value|167
end_define

begin_define
define|#
directive|define
name|SROM8_2G_MCSPO
value|169
end_define

begin_define
define|#
directive|define
name|SROM8_5G_MCSPO
value|177
end_define

begin_define
define|#
directive|define
name|SROM8_5GL_MCSPO
value|185
end_define

begin_define
define|#
directive|define
name|SROM8_5GH_MCSPO
value|193
end_define

begin_define
define|#
directive|define
name|SROM8_CDDPO
value|201
end_define

begin_define
define|#
directive|define
name|SROM8_STBCPO
value|202
end_define

begin_define
define|#
directive|define
name|SROM8_BW40PO
value|203
end_define

begin_define
define|#
directive|define
name|SROM8_BWDUPPO
value|204
end_define

begin_comment
comment|/* SISO PA parameters are in the path0 spaces */
end_comment

begin_define
define|#
directive|define
name|SROM8_SISO
value|96
end_define

begin_comment
comment|/* Legacy names for SISO PA paramters */
end_comment

begin_define
define|#
directive|define
name|SROM8_W0_ITTMAXP
value|(SROM8_SISO + SROM8_2G_ITT_MAXP)
end_define

begin_define
define|#
directive|define
name|SROM8_W0_PAB0
value|(SROM8_SISO + SROM8_2G_PA)
end_define

begin_define
define|#
directive|define
name|SROM8_W0_PAB1
value|(SROM8_SISO + SROM8_2G_PA + 1)
end_define

begin_define
define|#
directive|define
name|SROM8_W0_PAB2
value|(SROM8_SISO + SROM8_2G_PA + 2)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_ITTMAXP
value|(SROM8_SISO + SROM8_5G_ITT_MAXP)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_MAXP_LCHC
value|(SROM8_SISO + SROM8_5GLH_MAXP)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB0
value|(SROM8_SISO + SROM8_5G_PA)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB1
value|(SROM8_SISO + SROM8_5G_PA + 1)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB2
value|(SROM8_SISO + SROM8_5G_PA + 2)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB0_LC
value|(SROM8_SISO + SROM8_5GL_PA)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB1_LC
value|(SROM8_SISO + SROM8_5GL_PA + 1)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB2_LC
value|(SROM8_SISO + SROM8_5GL_PA + 2)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB0_HC
value|(SROM8_SISO + SROM8_5GH_PA)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB1_HC
value|(SROM8_SISO + SROM8_5GH_PA + 1)
end_define

begin_define
define|#
directive|define
name|SROM8_W1_PAB2_HC
value|(SROM8_SISO + SROM8_5GH_PA + 2)
end_define

begin_define
define|#
directive|define
name|SROM8_CRCREV
value|219
end_define

begin_comment
comment|/* SROM REV 9 */
end_comment

begin_define
define|#
directive|define
name|SROM9_2GPO_CCKBW20
value|160
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_CCKBW20UL
value|161
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_LOFDMBW20
value|162
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_LOFDMBW20UL
value|164
end_define

begin_define
define|#
directive|define
name|SROM9_5GLPO_LOFDMBW20
value|166
end_define

begin_define
define|#
directive|define
name|SROM9_5GLPO_LOFDMBW20UL
value|168
end_define

begin_define
define|#
directive|define
name|SROM9_5GMPO_LOFDMBW20
value|170
end_define

begin_define
define|#
directive|define
name|SROM9_5GMPO_LOFDMBW20UL
value|172
end_define

begin_define
define|#
directive|define
name|SROM9_5GHPO_LOFDMBW20
value|174
end_define

begin_define
define|#
directive|define
name|SROM9_5GHPO_LOFDMBW20UL
value|176
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_MCSBW20
value|178
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_MCSBW20UL
value|180
end_define

begin_define
define|#
directive|define
name|SROM9_2GPO_MCSBW40
value|182
end_define

begin_define
define|#
directive|define
name|SROM9_5GLPO_MCSBW20
value|184
end_define

begin_define
define|#
directive|define
name|SROM9_5GLPO_MCSBW20UL
value|186
end_define

begin_define
define|#
directive|define
name|SROM9_5GLPO_MCSBW40
value|188
end_define

begin_define
define|#
directive|define
name|SROM9_5GMPO_MCSBW20
value|190
end_define

begin_define
define|#
directive|define
name|SROM9_5GMPO_MCSBW20UL
value|192
end_define

begin_define
define|#
directive|define
name|SROM9_5GMPO_MCSBW40
value|194
end_define

begin_define
define|#
directive|define
name|SROM9_5GHPO_MCSBW20
value|196
end_define

begin_define
define|#
directive|define
name|SROM9_5GHPO_MCSBW20UL
value|198
end_define

begin_define
define|#
directive|define
name|SROM9_5GHPO_MCSBW40
value|200
end_define

begin_define
define|#
directive|define
name|SROM9_PO_MCS32
value|202
end_define

begin_define
define|#
directive|define
name|SROM9_PO_LOFDM40DUP
value|203
end_define

begin_define
define|#
directive|define
name|SROM9_REV_CRC
value|219
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u8
name|tssipos
decl_stmt|;
comment|/* TSSI positive slope, 1: positive, 0: negative */
name|u8
name|extpagain
decl_stmt|;
comment|/* Ext PA gain-type: full-gain: 0, pa-lite: 1, no_pa: 2 */
name|u8
name|pdetrange
decl_stmt|;
comment|/* support 32 combinations of different Pdet dynamic ranges */
name|u8
name|triso
decl_stmt|;
comment|/* TR switch isolation */
name|u8
name|antswctrllut
decl_stmt|;
comment|/* antswctrl lookup table configuration: 32 possible choices */
block|}
name|srom_fem_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BCMSROM_TBL_H_ */
end_comment

end_unit

