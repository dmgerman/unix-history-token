begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    Broadcom B43 wireless driver   IEEE 802.11n PHY data tables    Copyright (c) 2008 Michael Buesch<m@bues.ch>   Copyright (c) 2010 RafaÅ MiÅecki<zajec5@gmail.com>    This program is free software; you can redistribute it and/or modify   it under the terms of the GNU General Public License as published by   the Free Software Foundation; either version 2 of the License, or   (at your option) any later version.    This program is distributed in the hope that it will be useful,   but WITHOUT ANY WARRANTY; without even the implied warranty of   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   GNU General Public License for more details.    You should have received a copy of the GNU General Public License   along with this program; see the file COPYING.  If not, write to   the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,   Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_RADIO_2055_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_RADIO_2055_H__
end_define

begin_define
define|#
directive|define
name|B2055_GEN_SPARE
value|0x00
end_define

begin_comment
comment|/* GEN spare */
end_comment

begin_define
define|#
directive|define
name|B2055_SP_PINPD
value|0x02
end_define

begin_comment
comment|/* SP PIN PD */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_RSSI
value|0x03
end_define

begin_comment
comment|/* SP RSSI Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_PDMISC
value|0x04
end_define

begin_comment
comment|/* SP PD MISC Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_RSSI
value|0x05
end_define

begin_comment
comment|/* SP RSSI Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_PDMISC
value|0x06
end_define

begin_comment
comment|/* SP PD MISC Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_RXGC1
value|0x07
end_define

begin_comment
comment|/* SP RX GC1 Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_RXGC2
value|0x08
end_define

begin_comment
comment|/* SP RX GC2 Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_RXGC1
value|0x09
end_define

begin_comment
comment|/* SP RX GC1 Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_RXGC2
value|0x0A
end_define

begin_comment
comment|/* SP RX GC2 Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_LPFBWSEL
value|0x0B
end_define

begin_comment
comment|/* SP LPF BW select Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_LPFBWSEL
value|0x0C
end_define

begin_comment
comment|/* SP LPF BW select Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_TXGC1
value|0x0D
end_define

begin_comment
comment|/* SP TX GC1 Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_SP_TXGC2
value|0x0E
end_define

begin_comment
comment|/* SP TX GC2 Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_TXGC1
value|0x0F
end_define

begin_comment
comment|/* SP TX GC1 Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_SP_TXGC2
value|0x10
end_define

begin_comment
comment|/* SP TX GC2 Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_MASTER1
value|0x11
end_define

begin_comment
comment|/* Master control 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_MASTER2
value|0x12
end_define

begin_comment
comment|/* Master control 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_PD_LGEN
value|0x13
end_define

begin_comment
comment|/* PD LGEN */
end_comment

begin_define
define|#
directive|define
name|B2055_PD_PLLTS
value|0x14
end_define

begin_comment
comment|/* PD PLL TS */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PD_LGBUF
value|0x15
end_define

begin_comment
comment|/* PD Core 1 LGBUF */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PD_TX
value|0x16
end_define

begin_comment
comment|/* PD Core 1 TX */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PD_RXTX
value|0x17
end_define

begin_comment
comment|/* PD Core 1 RXTX */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PD_RSSIMISC
value|0x18
end_define

begin_comment
comment|/* PD Core 1 RSSI MISC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PD_LGBUF
value|0x19
end_define

begin_comment
comment|/* PD Core 2 LGBUF */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PD_TX
value|0x1A
end_define

begin_comment
comment|/* PD Core 2 TX */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PD_RXTX
value|0x1B
end_define

begin_comment
comment|/* PD Core 2 RXTX */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PD_RSSIMISC
value|0x1C
end_define

begin_comment
comment|/* PD Core 2 RSSI MISC */
end_comment

begin_define
define|#
directive|define
name|B2055_PWRDET_LGEN
value|0x1D
end_define

begin_comment
comment|/* PWRDET LGEN */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PWRDET_LGBUF
value|0x1E
end_define

begin_comment
comment|/* PWRDET LGBUF Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_PWRDET_RXTX
value|0x1F
end_define

begin_comment
comment|/* PWRDET RXTX Core 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PWRDET_LGBUF
value|0x20
end_define

begin_comment
comment|/* PWRDET LGBUF Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_PWRDET_RXTX
value|0x21
end_define

begin_comment
comment|/* PWRDET RXTX Core 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_RRCCAL_CS
value|0x22
end_define

begin_comment
comment|/* RRCCAL Control spare */
end_comment

begin_define
define|#
directive|define
name|B2055_RRCCAL_NOPTSEL
value|0x23
end_define

begin_comment
comment|/* RRCCAL N OPT SEL */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_MISC
value|0x24
end_define

begin_comment
comment|/* CAL MISC */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_COUT
value|0x25
end_define

begin_comment
comment|/* CAL Counter out */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_COUT2
value|0x26
end_define

begin_comment
comment|/* CAL Counter out 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_CVARCTL
value|0x27
end_define

begin_comment
comment|/* CAL CVAR Control */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_RVARCTL
value|0x28
end_define

begin_comment
comment|/* CAL RVAR Control */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_LPOCTL
value|0x29
end_define

begin_comment
comment|/* CAL LPO Control */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_TS
value|0x2A
end_define

begin_comment
comment|/* CAL TS */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_RCCALRTS
value|0x2B
end_define

begin_comment
comment|/* CAL RCCAL READ TS */
end_comment

begin_define
define|#
directive|define
name|B2055_CAL_RCALRTS
value|0x2C
end_define

begin_comment
comment|/* CAL RCAL READ TS */
end_comment

begin_define
define|#
directive|define
name|B2055_PADDRV
value|0x2D
end_define

begin_comment
comment|/* PAD driver */
end_comment

begin_define
define|#
directive|define
name|B2055_XOCTL1
value|0x2E
end_define

begin_comment
comment|/* XO Control 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_XOCTL2
value|0x2F
end_define

begin_comment
comment|/* XO Control 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_XOREGUL
value|0x30
end_define

begin_comment
comment|/* XO Regulator */
end_comment

begin_define
define|#
directive|define
name|B2055_XOMISC
value|0x31
end_define

begin_comment
comment|/* XO misc */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_LFC1
value|0x32
end_define

begin_comment
comment|/* PLL LF C1 */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_CALVTH
value|0x33
end_define

begin_comment
comment|/* PLL CAL VTH */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_LFC2
value|0x34
end_define

begin_comment
comment|/* PLL LF C2 */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_REF
value|0x35
end_define

begin_comment
comment|/* PLL reference */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_LFR1
value|0x36
end_define

begin_comment
comment|/* PLL LF R1 */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_PFDCP
value|0x37
end_define

begin_comment
comment|/* PLL PFD CP */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_IDAC_CPOPAMP
value|0x38
end_define

begin_comment
comment|/* PLL IDAC CPOPAMP */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_CPREG
value|0x39
end_define

begin_comment
comment|/* PLL CP Regulator */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_RCAL
value|0x3A
end_define

begin_comment
comment|/* PLL RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_RF_PLLMOD0
value|0x3B
end_define

begin_comment
comment|/* RF PLL MOD0 */
end_comment

begin_define
define|#
directive|define
name|B2055_RF_PLLMOD1
value|0x3C
end_define

begin_comment
comment|/* RF PLL MOD1 */
end_comment

begin_define
define|#
directive|define
name|B2055_RF_MMDIDAC1
value|0x3D
end_define

begin_comment
comment|/* RF MMD IDAC 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_RF_MMDIDAC0
value|0x3E
end_define

begin_comment
comment|/* RF MMD IDAC 0 */
end_comment

begin_define
define|#
directive|define
name|B2055_RF_MMDSP
value|0x3F
end_define

begin_comment
comment|/* RF MMD spare */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL1
value|0x40
end_define

begin_comment
comment|/* VCO cal 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL2
value|0x41
end_define

begin_comment
comment|/* VCO cal 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL3
value|0x42
end_define

begin_comment
comment|/* VCO cal 3 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL4
value|0x43
end_define

begin_comment
comment|/* VCO cal 4 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL5
value|0x44
end_define

begin_comment
comment|/* VCO cal 5 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL6
value|0x45
end_define

begin_comment
comment|/* VCO cal 6 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL7
value|0x46
end_define

begin_comment
comment|/* VCO cal 7 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL8
value|0x47
end_define

begin_comment
comment|/* VCO cal 8 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL9
value|0x48
end_define

begin_comment
comment|/* VCO cal 9 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL10
value|0x49
end_define

begin_comment
comment|/* VCO cal 10 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL11
value|0x4A
end_define

begin_comment
comment|/* VCO cal 11 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL12
value|0x4B
end_define

begin_comment
comment|/* VCO cal 12 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL13
value|0x4C
end_define

begin_comment
comment|/* VCO cal 13 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL14
value|0x4D
end_define

begin_comment
comment|/* VCO cal 14 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL15
value|0x4E
end_define

begin_comment
comment|/* VCO cal 15 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAL16
value|0x4F
end_define

begin_comment
comment|/* VCO cal 16 */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_KVCO
value|0x50
end_define

begin_comment
comment|/* VCO KVCO */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_CAPTAIL
value|0x51
end_define

begin_comment
comment|/* VCO CAP TAIL */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_IDACVCO
value|0x52
end_define

begin_comment
comment|/* VCO IDAC VCO */
end_comment

begin_define
define|#
directive|define
name|B2055_VCO_REG
value|0x53
end_define

begin_comment
comment|/* VCO Regulator */
end_comment

begin_define
define|#
directive|define
name|B2055_PLL_RFVTH
value|0x54
end_define

begin_comment
comment|/* PLL RF VTH */
end_comment

begin_define
define|#
directive|define
name|B2055_LGBUF_CENBUF
value|0x55
end_define

begin_comment
comment|/* LGBUF CEN BUF */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_TUNE1
value|0x56
end_define

begin_comment
comment|/* LGEN tune 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_TUNE2
value|0x57
end_define

begin_comment
comment|/* LGEN tune 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_IDAC1
value|0x58
end_define

begin_comment
comment|/* LGEN IDAC 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_IDAC2
value|0x59
end_define

begin_comment
comment|/* LGEN IDAC 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_BIASC
value|0x5A
end_define

begin_comment
comment|/* LGEN BIAS counter */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_BIASIDAC
value|0x5B
end_define

begin_comment
comment|/* LGEN BIAS IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_RCAL
value|0x5C
end_define

begin_comment
comment|/* LGEN RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_DIV
value|0x5D
end_define

begin_comment
comment|/* LGEN div */
end_comment

begin_define
define|#
directive|define
name|B2055_LGEN_SPARE2
value|0x5E
end_define

begin_comment
comment|/* LGEN spare 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_ATUNE
value|0x5F
end_define

begin_comment
comment|/* Core 1 LGBUF A tune */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_GTUNE
value|0x60
end_define

begin_comment
comment|/* Core 1 LGBUF G tune */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_DIV
value|0x61
end_define

begin_comment
comment|/* Core 1 LGBUF div */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_AIDAC
value|0x62
end_define

begin_comment
comment|/* Core 1 LGBUF A IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_GIDAC
value|0x63
end_define

begin_comment
comment|/* Core 1 LGBUF G IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_IDACFO
value|0x64
end_define

begin_comment
comment|/* Core 1 LGBUF IDAC filter override */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LGBUF_SPARE
value|0x65
end_define

begin_comment
comment|/* Core 1 LGBUF spare */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_RFSPC1
value|0x66
end_define

begin_comment
comment|/* Core 1 RX RF SPC1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_RFR1
value|0x67
end_define

begin_comment
comment|/* Core 1 RX RF reg 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_RFR2
value|0x68
end_define

begin_comment
comment|/* Core 1 RX RF reg 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_RFRCAL
value|0x69
end_define

begin_comment
comment|/* Core 1 RX RF RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_BLCMP
value|0x6A
end_define

begin_comment
comment|/* Core 1 RX Baseband BUFI LPF CMP */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_LPF
value|0x6B
end_define

begin_comment
comment|/* Core 1 RX Baseband LPF */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_MIDACHP
value|0x6C
end_define

begin_comment
comment|/* Core 1 RX Baseband MIDAC High-pass */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_VGA1IDAC
value|0x6D
end_define

begin_comment
comment|/* Core 1 RX Baseband VGA1 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_VGA2IDAC
value|0x6E
end_define

begin_comment
comment|/* Core 1 RX Baseband VGA2 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_VGA3IDAC
value|0x6F
end_define

begin_comment
comment|/* Core 1 RX Baseband VGA3 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_BUFOCTL
value|0x70
end_define

begin_comment
comment|/* Core 1 RX Baseband BUFO Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RCCALCTL
value|0x71
end_define

begin_comment
comment|/* Core 1 RX Baseband RCCAL Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RSSICTL1
value|0x72
end_define

begin_comment
comment|/* Core 1 RX Baseband RSSI Control 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RSSICTL2
value|0x73
end_define

begin_comment
comment|/* Core 1 RX Baseband RSSI Control 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RSSICTL3
value|0x74
end_define

begin_comment
comment|/* Core 1 RX Baseband RSSI Control 3 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RSSICTL4
value|0x75
end_define

begin_comment
comment|/* Core 1 RX Baseband RSSI Control 4 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_RSSICTL5
value|0x76
end_define

begin_comment
comment|/* Core 1 RX Baseband RSSI Control 5 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_REG
value|0x77
end_define

begin_comment
comment|/* Core 1 RX Baseband Regulator */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_BB_SPARE1
value|0x78
end_define

begin_comment
comment|/* Core 1 RX Baseband spare 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_RX_TXBBRCAL
value|0x79
end_define

begin_comment
comment|/* Core 1 RX TX BB RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_SPGA
value|0x7A
end_define

begin_comment
comment|/* Core 1 TX RF SGM PGA */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_SPAD
value|0x7B
end_define

begin_comment
comment|/* Core 1 TX RF SGM PAD */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_CNTPGA1
value|0x7C
end_define

begin_comment
comment|/* Core 1 TX RF counter PGA 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_CNTPAD1
value|0x7D
end_define

begin_comment
comment|/* Core 1 TX RF counter PAD 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_PGAIDAC
value|0x7E
end_define

begin_comment
comment|/* Core 1 TX RF PGA IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_PGAPADTN
value|0x7F
end_define

begin_comment
comment|/* Core 1 TX PGA PAD TN */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_PADIDAC1
value|0x80
end_define

begin_comment
comment|/* Core 1 TX PAD IDAC 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_PADIDAC2
value|0x81
end_define

begin_comment
comment|/* Core 1 TX PAD IDAC 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_MXBGTRIM
value|0x82
end_define

begin_comment
comment|/* Core 1 TX MX B/G TRIM */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_RCAL
value|0x83
end_define

begin_comment
comment|/* Core 1 TX RF RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_PADTSSI1
value|0x84
end_define

begin_comment
comment|/* Core 1 TX RF PAD TSSI1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_PADTSSI2
value|0x85
end_define

begin_comment
comment|/* Core 1 TX RF PAD TSSI2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_SPARE
value|0x86
end_define

begin_comment
comment|/* Core 1 TX RF spare */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_IQCAL1
value|0x87
end_define

begin_comment
comment|/* Core 1 TX RF I/Q CAL 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_RF_IQCAL2
value|0x88
end_define

begin_comment
comment|/* Core 1 TX RF I/Q CAL 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TXBB_RCCAL
value|0x89
end_define

begin_comment
comment|/* Core 1 TXBB RC CAL Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TXBB_LPF1
value|0x8A
end_define

begin_comment
comment|/* Core 1 TXBB LPF 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_VOSCNCL
value|0x8B
end_define

begin_comment
comment|/* Core 1 TX VOS CNCL */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_LPF_MXGMIDAC
value|0x8C
end_define

begin_comment
comment|/* Core 1 TX LPF MXGM IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_TX_BB_MXGM
value|0x8D
end_define

begin_comment
comment|/* Core 1 TX BB MXGM */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_ATUNE
value|0x8E
end_define

begin_comment
comment|/* Core 2 LGBUF A tune */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_GTUNE
value|0x8F
end_define

begin_comment
comment|/* Core 2 LGBUF G tune */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_DIV
value|0x90
end_define

begin_comment
comment|/* Core 2 LGBUF div */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_AIDAC
value|0x91
end_define

begin_comment
comment|/* Core 2 LGBUF A IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_GIDAC
value|0x92
end_define

begin_comment
comment|/* Core 2 LGBUF G IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_IDACFO
value|0x93
end_define

begin_comment
comment|/* Core 2 LGBUF IDAC filter override */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LGBUF_SPARE
value|0x94
end_define

begin_comment
comment|/* Core 2 LGBUF spare */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_RFSPC1
value|0x95
end_define

begin_comment
comment|/* Core 2 RX RF SPC1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_RFR1
value|0x96
end_define

begin_comment
comment|/* Core 2 RX RF reg 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_RFR2
value|0x97
end_define

begin_comment
comment|/* Core 2 RX RF reg 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_RFRCAL
value|0x98
end_define

begin_comment
comment|/* Core 2 RX RF RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_BLCMP
value|0x99
end_define

begin_comment
comment|/* Core 2 RX Baseband BUFI LPF CMP */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_LPF
value|0x9A
end_define

begin_comment
comment|/* Core 2 RX Baseband LPF */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_MIDACHP
value|0x9B
end_define

begin_comment
comment|/* Core 2 RX Baseband MIDAC High-pass */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_VGA1IDAC
value|0x9C
end_define

begin_comment
comment|/* Core 2 RX Baseband VGA1 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_VGA2IDAC
value|0x9D
end_define

begin_comment
comment|/* Core 2 RX Baseband VGA2 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_VGA3IDAC
value|0x9E
end_define

begin_comment
comment|/* Core 2 RX Baseband VGA3 IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_BUFOCTL
value|0x9F
end_define

begin_comment
comment|/* Core 2 RX Baseband BUFO Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RCCALCTL
value|0xA0
end_define

begin_comment
comment|/* Core 2 RX Baseband RCCAL Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RSSICTL1
value|0xA1
end_define

begin_comment
comment|/* Core 2 RX Baseband RSSI Control 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RSSICTL2
value|0xA2
end_define

begin_comment
comment|/* Core 2 RX Baseband RSSI Control 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RSSICTL3
value|0xA3
end_define

begin_comment
comment|/* Core 2 RX Baseband RSSI Control 3 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RSSICTL4
value|0xA4
end_define

begin_comment
comment|/* Core 2 RX Baseband RSSI Control 4 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_RSSICTL5
value|0xA5
end_define

begin_comment
comment|/* Core 2 RX Baseband RSSI Control 5 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_REG
value|0xA6
end_define

begin_comment
comment|/* Core 2 RX Baseband Regulator */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_BB_SPARE1
value|0xA7
end_define

begin_comment
comment|/* Core 2 RX Baseband spare 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_RX_TXBBRCAL
value|0xA8
end_define

begin_comment
comment|/* Core 2 RX TX BB RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_SPGA
value|0xA9
end_define

begin_comment
comment|/* Core 2 TX RF SGM PGA */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_SPAD
value|0xAA
end_define

begin_comment
comment|/* Core 2 TX RF SGM PAD */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_CNTPGA1
value|0xAB
end_define

begin_comment
comment|/* Core 2 TX RF counter PGA 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_CNTPAD1
value|0xAC
end_define

begin_comment
comment|/* Core 2 TX RF counter PAD 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_PGAIDAC
value|0xAD
end_define

begin_comment
comment|/* Core 2 TX RF PGA IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_PGAPADTN
value|0xAE
end_define

begin_comment
comment|/* Core 2 TX PGA PAD TN */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_PADIDAC1
value|0xAF
end_define

begin_comment
comment|/* Core 2 TX PAD IDAC 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_PADIDAC2
value|0xB0
end_define

begin_comment
comment|/* Core 2 TX PAD IDAC 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_MXBGTRIM
value|0xB1
end_define

begin_comment
comment|/* Core 2 TX MX B/G TRIM */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_RCAL
value|0xB2
end_define

begin_comment
comment|/* Core 2 TX RF RCAL */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_PADTSSI1
value|0xB3
end_define

begin_comment
comment|/* Core 2 TX RF PAD TSSI1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_PADTSSI2
value|0xB4
end_define

begin_comment
comment|/* Core 2 TX RF PAD TSSI2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_SPARE
value|0xB5
end_define

begin_comment
comment|/* Core 2 TX RF spare */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_IQCAL1
value|0xB6
end_define

begin_comment
comment|/* Core 2 TX RF I/Q CAL 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_RF_IQCAL2
value|0xB7
end_define

begin_comment
comment|/* Core 2 TX RF I/Q CAL 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TXBB_RCCAL
value|0xB8
end_define

begin_comment
comment|/* Core 2 TXBB RC CAL Control */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TXBB_LPF1
value|0xB9
end_define

begin_comment
comment|/* Core 2 TXBB LPF 1 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_VOSCNCL
value|0xBA
end_define

begin_comment
comment|/* Core 2 TX VOS CNCL */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_LPF_MXGMIDAC
value|0xBB
end_define

begin_comment
comment|/* Core 2 TX LPF MXGM IDAC */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_TX_BB_MXGM
value|0xBC
end_define

begin_comment
comment|/* Core 2 TX BB MXGM */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP21
value|0xBD
end_define

begin_comment
comment|/* PRG GC HPVGA23 21 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP22
value|0xBE
end_define

begin_comment
comment|/* PRG GC HPVGA23 22 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP23
value|0xBF
end_define

begin_comment
comment|/* PRG GC HPVGA23 23 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP24
value|0xC0
end_define

begin_comment
comment|/* PRG GC HPVGA23 24 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP25
value|0xC1
end_define

begin_comment
comment|/* PRG GC HPVGA23 25 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP26
value|0xC2
end_define

begin_comment
comment|/* PRG GC HPVGA23 26 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP27
value|0xC3
end_define

begin_comment
comment|/* PRG GC HPVGA23 27 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP28
value|0xC4
end_define

begin_comment
comment|/* PRG GC HPVGA23 28 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP29
value|0xC5
end_define

begin_comment
comment|/* PRG GC HPVGA23 29 */
end_comment

begin_define
define|#
directive|define
name|B2055_PRG_GCHP30
value|0xC6
end_define

begin_comment
comment|/* PRG GC HPVGA23 30 */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_LNA_GAINBST
value|0xCD
end_define

begin_comment
comment|/* Core 1 LNA GAINBST */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_B0NB_RSSIVCM
value|0xD2
end_define

begin_comment
comment|/* Core 1 B0 narrow-band RSSI VCM */
end_comment

begin_define
define|#
directive|define
name|B2055_C1_GENSPARE2
value|0xD6
end_define

begin_comment
comment|/* Core 1 GEN spare 2 */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_LNA_GAINBST
value|0xD9
end_define

begin_comment
comment|/* Core 2 LNA GAINBST */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_B0NB_RSSIVCM
value|0xDE
end_define

begin_comment
comment|/* Core 2 B0 narrow-band RSSI VCM */
end_comment

begin_define
define|#
directive|define
name|B2055_C2_GENSPARE2
value|0xE2
end_define

begin_comment
comment|/* Core 2 GEN spare 2 */
end_comment

begin_struct
struct|struct
name|bwn_nphy_channeltab_entry_rev2
block|{
comment|/* The channel number */
name|uint8_t
name|channel
decl_stmt|;
comment|/* The channel frequency in MHz */
name|uint16_t
name|freq
decl_stmt|;
comment|/* An unknown value */
name|uint16_t
name|unk2
decl_stmt|;
comment|/* Radio register values on channelswitch */
name|uint8_t
name|radio_pll_ref
decl_stmt|;
name|uint8_t
name|radio_rf_pllmod0
decl_stmt|;
name|uint8_t
name|radio_rf_pllmod1
decl_stmt|;
name|uint8_t
name|radio_vco_captail
decl_stmt|;
name|uint8_t
name|radio_vco_cal1
decl_stmt|;
name|uint8_t
name|radio_vco_cal2
decl_stmt|;
name|uint8_t
name|radio_pll_lfc1
decl_stmt|;
name|uint8_t
name|radio_pll_lfr1
decl_stmt|;
name|uint8_t
name|radio_pll_lfc2
decl_stmt|;
name|uint8_t
name|radio_lgbuf_cenbuf
decl_stmt|;
name|uint8_t
name|radio_lgen_tune1
decl_stmt|;
name|uint8_t
name|radio_lgen_tune2
decl_stmt|;
name|uint8_t
name|radio_c1_lgbuf_atune
decl_stmt|;
name|uint8_t
name|radio_c1_lgbuf_gtune
decl_stmt|;
name|uint8_t
name|radio_c1_rx_rfr1
decl_stmt|;
name|uint8_t
name|radio_c1_tx_pgapadtn
decl_stmt|;
name|uint8_t
name|radio_c1_tx_mxbgtrim
decl_stmt|;
name|uint8_t
name|radio_c2_lgbuf_atune
decl_stmt|;
name|uint8_t
name|radio_c2_lgbuf_gtune
decl_stmt|;
name|uint8_t
name|radio_c2_rx_rfr1
decl_stmt|;
name|uint8_t
name|radio_c2_tx_pgapadtn
decl_stmt|;
name|uint8_t
name|radio_c2_tx_mxbgtrim
decl_stmt|;
comment|/* PHY register values on channelswitch */
name|struct
name|bwn_phy_n_sfo_cfg
name|phy_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Upload the default register value table.  * If "ghz5" is true, we upload the 5Ghz table. Otherwise the 2.4Ghz  * table is uploaded. If "ignore_uploadflag" is true, we upload any value  * and ignore the "UPLOAD" flag. */
end_comment

begin_function_decl
name|void
name|b2055_upload_inittab
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|bool
name|ghz5
parameter_list|,
name|bool
name|ignore_uploadflag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the NPHY Channel Switch Table entry for a channel.  * Returns NULL on failure to find an entry. */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|bwn_nphy_channeltab_entry_rev2
modifier|*
name|bwn_nphy_get_chantabent_rev2
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint8_t
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_RADIO_2055_H__ */
end_comment

end_unit

