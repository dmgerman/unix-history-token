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
name|__IF_BWN_RADIO_2056_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_RADIO_2056_H__
end_define

begin_define
define|#
directive|define
name|B2056_SYN
value|(0x0<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_TX0
value|(0x2<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_TX1
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_RX0
value|(0x6<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_RX1
value|(0x7<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_ALLTX
value|(0xE<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_ALLRX
value|(0xF<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_SYN_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_GPIO_MASTER1
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_SYN_GPIO_MASTER2
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TOPBIAS_MASTER
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TOPBIAS_RCAL
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_SYN_AFEREG
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSE
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSEIDAC
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSERCAL
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LPO
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_MASTER
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_STATUS
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCAL_MASTER
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCAL_CODE_OUT
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL0
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL1
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL2
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL3
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL4
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL5
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL6
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL7
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL8
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL9
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL10
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL11
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_SYN_ZCAL_SPARE1
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_ZCAL_SPARE2
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST1
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST2
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST3
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_BIAS_RESET
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL0
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL1
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL3
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL4
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL5
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL6
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_REFDIV
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_PFD
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP1
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP2
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP3
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER1
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER2
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER3
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER4
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER5
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MMD1
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MMD2
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCO1
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCO2
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MONITOR1
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MONITOR2
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL1
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL2
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL4
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL5
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL6
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL7
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL8
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL9
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL10
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL11
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL12
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL13
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VREG
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS1
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS2
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS3
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU0
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU1
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU2
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU3
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU5
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU6
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU7
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU8
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BIAS_RESET
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RCCR1
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF1
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER1
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER2
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF1
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGENBUF2
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF3
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF4
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV1
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV2
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV3
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL1
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL2
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL3
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL4
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL5
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL6
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLOUT
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL1
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL2
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL3
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_SYN_CALEN
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PEAKDET1
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CORE_ACL_OVR
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_DIFF_ACL_OVR
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_DIFF_ACL_OVR
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_CMOS_ACL_OVR
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_CMOS_ACL_OVR
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF2
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER3
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF5
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF6
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX1
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX2
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX3
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX4
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX1
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX2
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX3
value|0x95
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX4
value|0x96
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX1
value|0x97
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX2
value|0x98
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX3
value|0x99
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX4
value|0x9A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX1
value|0x9B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX2
value|0x9C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX3
value|0x9D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX4
value|0x9E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF2_OVRVAL
value|0x9F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER3_OVRVAL
value|0xA0
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF5_OVRVAL
value|0xA1
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF6_OVRVAL
value|0xA2
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX1_OVRVAL
value|0xA3
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX2_OVRVAL
value|0xA4
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX3_OVRVAL
value|0xA5
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX4_OVRVAL
value|0xA6
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX1_OVRVAL
value|0xA7
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX2_OVRVAL
value|0xA8
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX3_OVRVAL
value|0xA9
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX4_OVRVAL
value|0xAA
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX1_OVRVAL
value|0xAB
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX2_OVRVAL
value|0xAC
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX3_OVRVAL
value|0xAD
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX4_OVRVAL
value|0xAE
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX1_OVRVAL
value|0xAF
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX2_OVRVAL
value|0xB0
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX3_OVRVAL
value|0xB1
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX4_OVRVAL
value|0xB2
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL_WAITCNT
value|0xB3
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CORE_CALVALID
value|0xB4
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_CMOS_CALVALID
value|0xB5
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_CMOS_VALID
value|0xB6
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_TX_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_GAIN_BW
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_FINE_I
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_FINE_Q
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_COARSE_I
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_COARSE_Q
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_COM_MASTER1
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_COM_MASTER2
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_TX_RXIQCAL_TXMUX
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_SSI_MASTER
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_VCM_HG
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_VCM
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_AMP_DET
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_SSI_MUX
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSIA
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSIG
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC1
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC2
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC3
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_TX_PA_SPARE1
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_TX_PA_SPARE2
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_MASTER
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_GAIN
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_BOOST_TUNE
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IAUX_STAT
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IAUX_DYN
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IMAIN_STAT
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IMAIN_DYN
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_CASCBIAS
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_PASLOPE
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_PA_MISC
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_MASTER
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_GAIN
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_BOOST_TUNE
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IAUX_STAT
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IAUX_DYN
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IMAIN_STAT
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IMAIN_DYN
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_CASCBIAS
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_PASLOPE
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_PA_MISC
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_MASTER
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_IDAC
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_CASCBIAS
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_GAIN
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_BOOST_TUNE
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_SLOPE
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_MASTER
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_IDAC
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_CASCBIAS
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_GAIN
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_BOOST_TUNE
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_SLOPE
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_MASTER
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_IDAC
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_GAIN
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_BOOST_TUNE
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_SLOPE
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_MISC
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_MASTER
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_IDAC
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_GAIN
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_BOOST_TUNE
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_SLOPE
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_MISC
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXA_MASTER
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXA_BOOST_TUNE
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXG
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXG_BOOST_TUNE
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_TX_BB_GM_MASTER
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_GM
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_MASTER
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF0
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF1
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF2
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF3
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF4
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF5
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF6
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_BW
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_GAIN
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_0
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_1
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_2
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_3
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_4
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_5
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_6
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_OPAMP_IDAC
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_MISC
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE1
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE2
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE3
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE4
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE5
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE6
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE7
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE8
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE9
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE10
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE11
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE12
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE13
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE14
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE15
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE16
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_INTPA_GAIN
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_PAD_GAIN
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_PGA_GAIN
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_GM_TXLPF_GAIN
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_TXLPF_BW
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_TXLPF_RC
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC0
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC1
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC2
value|0x95
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC3
value|0x96
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC4
value|0x97
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC5
value|0x98
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC6
value|0x99
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC7
value|0x9A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_RX_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXIQCAL_RXMUX
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_PU
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_SEL
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_GAIN
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_NB_IDAC
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2I_IDAC_1
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2I_IDAC_2
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2Q_IDAC_1
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2Q_IDAC_2
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_POLE
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB1_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_MISC
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_MASTER
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_TUNE
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_GAIN
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA_A_SLOPE
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_RX_BIASPOLE_LNAA1_IDAC
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA2_IDAC
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA1A_MISC
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_MASTER
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_TUNE
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_GAIN
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA_G_SLOPE
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_RX_BIASPOLE_LNAG1_IDAC
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG2_IDAC
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA1G_MISC
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_MASTER
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_VCM
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CTRLPTAT
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_LOB_BIAS
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CORE_IDAC
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CMFB_IDAC
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_AUX
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_MAIN
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_MISC
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_MAST_BIAS
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_MASTER
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_VCM
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CTRLPTAT
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_LOB_BIAS
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CORE_IDAC
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CMFB_IDAC
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_AUX
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_MAIN
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_MISC
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_MAST_BIAS
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_MASTER
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_IOPAMP
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_QOPAMP
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_IMISC
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_QMISC
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_GAIN
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_SPARE1
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_SPARE2
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_RX_BB_LPF_MASTER
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_RX_AACI_MASTER
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_IDAC
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OPAMPBIAS_LOWQ
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OPAMPBIAS_HIGHQ
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_BIAS_DCCANCEL
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OUTVCM
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_INVCM_BODY
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_CC_OP
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_GAIN
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_Q_BW
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_HP_CORNER_BW
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_RCCAL_HPC
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF0
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF1
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF2
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF3
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF4
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF5
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF6
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF7
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_RCCAL_LPC
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_0
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_1
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_2
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_3
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_4
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_RX_UNUSED
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_MASTER
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_BIAS
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_BIAS_DCCANCEL
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_GAIN
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_HP_CORNER_BW
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGABUF_BIAS
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGABUF_GAIN_BW
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_RX_TXFBMIX_A
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_RX_TXFBMIX_G
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE1
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE2
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE3
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE4
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE5
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE6
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE7
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE8
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE9
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE10
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE11
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE12
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE13
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE14
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE15
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE16
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_LNAA_GAIN
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_LNAG_GAIN
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_MIXTIA_GAIN
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_GAIN
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_VGA_BUF_GAIN
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_Q
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_BUF_BW
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_VGA_HPC
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_RC
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_HPC_RC
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_LNA1_A_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_LNA2_A_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_LNA1_G_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_LNA2_G_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_I
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_GM
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_I
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_GM
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_TIA_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_BB_LPF_PU
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_W1_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_W2_PU
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_NB_PU
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_W1_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_W2_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_NB_SEL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_VCM_MASK
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_VCM_SHIFT
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_SYN
value|(0x0<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_TX0
value|(0x2<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_TX1
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_RX0
value|(0x6<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_RX1
value|(0x7<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_ALLTX
value|(0xE<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_ALLRX
value|(0xF<< 12)
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_SYN_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_GPIO_MASTER1
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_SYN_GPIO_MASTER2
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TOPBIAS_MASTER
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TOPBIAS_RCAL
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_SYN_AFEREG
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSE
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSEIDAC
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_SYN_TEMPPROCSENSERCAL
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LPO
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_MASTER
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_VDDCAL_STATUS
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCAL_MASTER
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCAL_CODE_OUT
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL0
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL1
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL2
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL3
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL4
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL5
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL6
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL7
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL8
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL9
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL10
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_SYN_RCCAL_CTRL11
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_SYN_ZCAL_SPARE1
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_ZCAL_SPARE2
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST1
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST2
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MAST3
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_BIAS_RESET
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL0
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL1
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL3
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL4
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL5
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_XTAL6
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_REFDIV
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_PFD
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP1
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP2
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_CP3
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER1
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER2
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER3
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER4
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_LOOPFILTER5
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MMD1
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MMD2
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCO1
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCO2
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MONITOR1
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_MONITOR2
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL1
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL2
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL4
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL5
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL6
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL7
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL8
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL9
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL10
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL11
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL12
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VCOCAL13
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_VREG
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS1
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS2
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_SYN_PLL_STATUS3
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU0
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU1
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU2
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU3
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU5
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU6
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU7
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PU8
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BIAS_RESET
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RCCR1
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF1
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER1
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER2
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF1
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGENBUF2
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF3
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF4
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV1
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV2
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_DIV3
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL1
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL2
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL3
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL4
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL5
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL6
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLOUT
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL1
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL2
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACLCAL3
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_SYN_CALEN
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_PEAKDET1
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CORE_ACL_OVR
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_DIFF_ACL_OVR
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_DIFF_ACL_OVR
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_CMOS_ACL_OVR
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_CMOS_ACL_OVR
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF2
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER3
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF5
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF6
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX1
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX2
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX3
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX4
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX1
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX2
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX3
value|0x95
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX4
value|0x96
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX1
value|0x97
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX2
value|0x98
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX3
value|0x99
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX4
value|0x9A
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX1
value|0x9B
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX2
value|0x9C
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX3
value|0x9D
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX4
value|0x9E
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_VCOBUF2_OVRVAL
value|0x9F
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_MIXER3_OVRVAL
value|0xA0
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF5_OVRVAL
value|0xA1
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_BUF6_OVRVAL
value|0xA2
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX1_OVRVAL
value|0xA3
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX2_OVRVAL
value|0xA4
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX3_OVRVAL
value|0xA5
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFRX4_OVRVAL
value|0xA6
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX1_OVRVAL
value|0xA7
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX2_OVRVAL
value|0xA8
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX3_OVRVAL
value|0xA9
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CBUFTX4_OVRVAL
value|0xAA
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX1_OVRVAL
value|0xAB
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX2_OVRVAL
value|0xAC
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX3_OVRVAL
value|0xAD
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSRX4_OVRVAL
value|0xAE
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX1_OVRVAL
value|0xAF
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX2_OVRVAL
value|0xB0
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX3_OVRVAL
value|0xB1
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CMOSTX4_OVRVAL
value|0xB2
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_ACL_WAITCNT
value|0xB3
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_CORE_CALVALID
value|0xB4
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_RX_CMOS_CALVALID
value|0xB5
end_define

begin_define
define|#
directive|define
name|B2056_SYN_LOGEN_TX_CMOS_VALID
value|0xB6
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_TX_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_TX_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_TX_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_GAIN_BW
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_FINE_I
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_FINE_Q
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_COARSE_I
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_TX_LOFT_COARSE_Q
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_COM_MASTER1
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_COM_MASTER2
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_TX_RXIQCAL_TXMUX
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_SSI_MASTER
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_VCM_HG
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_TX_IQCAL_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_VCM
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_AMP_DET
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TX_SSI_MUX
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSIA
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSIG
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC1
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC2
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_TX_TSSI_MISC3
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_TX_PA_SPARE1
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_TX_PA_SPARE2
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_MASTER
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_GAIN
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_BOOST_TUNE
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IAUX_STAT
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IAUX_DYN
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IMAIN_STAT
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_IMAIN_DYN
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_CASCBIAS
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_PASLOPE
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAA_PA_MISC
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_MASTER
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_GAIN
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_BOOST_TUNE
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IAUX_STAT
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IAUX_DYN
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IMAIN_STAT
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_IMAIN_DYN
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_CASCBIAS
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_PASLOPE
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_TX_INTPAG_PA_MISC
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_MASTER
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_IDAC
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_CASCBIAS
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_GAIN
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_BOOST_TUNE
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADA_SLOPE
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_MASTER
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_IDAC
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_CASCBIAS
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_GAIN
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_BOOST_TUNE
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_TX_PADG_SLOPE
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_MASTER
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_IDAC
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_GAIN
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_BOOST_TUNE
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_SLOPE
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAA_MISC
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_MASTER
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_IDAC
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_GAIN
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_BOOST_TUNE
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_SLOPE
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_TX_PGAG_MISC
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXA_MASTER
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXA_BOOST_TUNE
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXG
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_TX_MIXG_BOOST_TUNE
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_TX_BB_GM_MASTER
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_GM
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_MASTER
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF0
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF1
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF2
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF3
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF4
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF5
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_RCCAL_OFF6
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_BW
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_GAIN
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_0
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_1
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_2
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_3
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_4
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_5
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_IDAC_6
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_OPAMP_IDAC
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXLPF_MISC
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE1
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE2
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE3
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE4
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE5
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE6
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE7
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE8
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE9
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE10
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE11
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE12
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE13
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE14
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE15
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_TX_TXSPARE16
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_INTPA_GAIN
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_PAD_GAIN
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_PGA_GAIN
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_GM_TXLPF_GAIN
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_TXLPF_BW
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_TX_STATUS_TXLPF_RC
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC0
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC1
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC2
value|0x95
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC3
value|0x96
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC4
value|0x97
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC5
value|0x98
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC6
value|0x99
end_define

begin_define
define|#
directive|define
name|B2056_TX_GMBB_IDAC7
value|0x9A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR0
value|0x00
end_define

begin_define
define|#
directive|define
name|B2056_RX_IDCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR2
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR3
value|0x03
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR4
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR5
value|0x05
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR6
value|0x06
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR7
value|0x07
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_PU
value|0x09
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_OVR
value|0x0A
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RESET
value|0x0B
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RCAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_RXLPF
value|0x0D
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_TXLPF
value|0x0E
end_define

begin_define
define|#
directive|define
name|B2056_RX_COM_RC_RXHPF
value|0x0F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR16
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR17
value|0x11
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR18
value|0x12
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR19
value|0x13
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR20
value|0x14
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR21
value|0x15
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR22
value|0x16
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR23
value|0x17
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR24
value|0x18
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR25
value|0x19
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR26
value|0x1A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR27
value|0x1B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR28
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR29
value|0x1D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR30
value|0x1E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RESERVED_ADDR31
value|0x1F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXIQCAL_RXMUX
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_PU
value|0x21
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_SEL
value|0x22
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_GAIN
value|0x23
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_NB_IDAC
value|0x24
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2I_IDAC_1
value|0x25
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2I_IDAC_2
value|0x26
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2Q_IDAC_1
value|0x27
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB2Q_IDAC_2
value|0x28
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_POLE
value|0x29
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_WB1_IDAC
value|0x2A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RSSI_MISC
value|0x2B
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_MASTER
value|0x2C
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_TUNE
value|0x2D
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA_GAIN
value|0x2E
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA_A_SLOPE
value|0x2F
end_define

begin_define
define|#
directive|define
name|B2056_RX_BIASPOLE_LNAA1_IDAC
value|0x30
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAA2_IDAC
value|0x31
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA1A_MISC
value|0x32
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_MASTER
value|0x33
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_TUNE
value|0x34
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG_GAIN
value|0x35
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA_G_SLOPE
value|0x36
end_define

begin_define
define|#
directive|define
name|B2056_RX_BIASPOLE_LNAG1_IDAC
value|0x37
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNAG2_IDAC
value|0x38
end_define

begin_define
define|#
directive|define
name|B2056_RX_LNA1G_MISC
value|0x39
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_MASTER
value|0x3A
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_VCM
value|0x3B
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CTRLPTAT
value|0x3C
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_LOB_BIAS
value|0x3D
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CORE_IDAC
value|0x3E
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_CMFB_IDAC
value|0x3F
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_AUX
value|0x40
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_MAIN
value|0x41
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_BIAS_MISC
value|0x42
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXA_MAST_BIAS
value|0x43
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_MASTER
value|0x44
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_VCM
value|0x45
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CTRLPTAT
value|0x46
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_LOB_BIAS
value|0x47
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CORE_IDAC
value|0x48
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_CMFB_IDAC
value|0x49
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_AUX
value|0x4A
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_MAIN
value|0x4B
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_BIAS_MISC
value|0x4C
end_define

begin_define
define|#
directive|define
name|B2056_RX_MIXG_MAST_BIAS
value|0x4D
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_MASTER
value|0x4E
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_IOPAMP
value|0x4F
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_QOPAMP
value|0x50
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_IMISC
value|0x51
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_QMISC
value|0x52
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_GAIN
value|0x53
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_SPARE1
value|0x54
end_define

begin_define
define|#
directive|define
name|B2056_RX_TIA_SPARE2
value|0x55
end_define

begin_define
define|#
directive|define
name|B2056_RX_BB_LPF_MASTER
value|0x56
end_define

begin_define
define|#
directive|define
name|B2056_RX_AACI_MASTER
value|0x57
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_IDAC
value|0x58
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OPAMPBIAS_LOWQ
value|0x59
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OPAMPBIAS_HIGHQ
value|0x5A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_BIAS_DCCANCEL
value|0x5B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OUTVCM
value|0x5C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_INVCM_BODY
value|0x5D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_CC_OP
value|0x5E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_GAIN
value|0x5F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_Q_BW
value|0x60
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_HP_CORNER_BW
value|0x61
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_RCCAL_HPC
value|0x62
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF0
value|0x63
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF1
value|0x64
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF2
value|0x65
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF3
value|0x66
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF4
value|0x67
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF5
value|0x68
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF6
value|0x69
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXHPF_OFF7
value|0x6A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_RCCAL_LPC
value|0x6B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_0
value|0x6C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_1
value|0x6D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_2
value|0x6E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_3
value|0x6F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXLPF_OFF_4
value|0x70
end_define

begin_define
define|#
directive|define
name|B2056_RX_UNUSED
value|0x71
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_MASTER
value|0x72
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_BIAS
value|0x73
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_BIAS_DCCANCEL
value|0x74
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_GAIN
value|0x75
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGA_HP_CORNER_BW
value|0x76
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGABUF_BIAS
value|0x77
end_define

begin_define
define|#
directive|define
name|B2056_RX_VGABUF_GAIN_BW
value|0x78
end_define

begin_define
define|#
directive|define
name|B2056_RX_TXFBMIX_A
value|0x79
end_define

begin_define
define|#
directive|define
name|B2056_RX_TXFBMIX_G
value|0x7A
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE1
value|0x7B
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE2
value|0x7C
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE3
value|0x7D
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE4
value|0x7E
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE5
value|0x7F
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE6
value|0x80
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE7
value|0x81
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE8
value|0x82
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE9
value|0x83
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE10
value|0x84
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE11
value|0x85
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE12
value|0x86
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE13
value|0x87
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE14
value|0x88
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE15
value|0x89
end_define

begin_define
define|#
directive|define
name|B2056_RX_RXSPARE16
value|0x8A
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_LNAA_GAIN
value|0x8B
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_LNAG_GAIN
value|0x8C
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_MIXTIA_GAIN
value|0x8D
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_GAIN
value|0x8E
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_VGA_BUF_GAIN
value|0x8F
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_Q
value|0x90
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_BUF_BW
value|0x91
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_VGA_HPC
value|0x92
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_RXLPF_RC
value|0x93
end_define

begin_define
define|#
directive|define
name|B2056_RX_STATUS_HPC_RC
value|0x94
end_define

begin_define
define|#
directive|define
name|B2056_LNA1_A_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_LNA2_A_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_LNA1_G_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_LNA2_G_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_I
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXA_PU_GM
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_I
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_Q
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_MIXG_PU_GM
value|0x10
end_define

begin_define
define|#
directive|define
name|B2056_TIA_PU
value|0x01
end_define

begin_define
define|#
directive|define
name|B2056_BB_LPF_PU
value|0x20
end_define

begin_define
define|#
directive|define
name|B2056_W1_PU
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_W2_PU
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_NB_PU
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_W1_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_W2_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_NB_SEL
value|0x08
end_define

begin_define
define|#
directive|define
name|B2056_VCM_MASK
value|0x1C
end_define

begin_define
define|#
directive|define
name|B2056_RSSI_VCM_SHIFT
value|0x02
end_define

begin_struct
struct|struct
name|bwn_nphy_channeltab_entry_rev3
block|{
comment|/* The channel frequency in MHz */
name|uint16_t
name|freq
decl_stmt|;
comment|/* Radio register values on channelswitch */
name|uint8_t
name|radio_syn_pll_vcocal1
decl_stmt|;
name|uint8_t
name|radio_syn_pll_vcocal2
decl_stmt|;
name|uint8_t
name|radio_syn_pll_refdiv
decl_stmt|;
name|uint8_t
name|radio_syn_pll_mmd2
decl_stmt|;
name|uint8_t
name|radio_syn_pll_mmd1
decl_stmt|;
name|uint8_t
name|radio_syn_pll_loopfilter1
decl_stmt|;
name|uint8_t
name|radio_syn_pll_loopfilter2
decl_stmt|;
name|uint8_t
name|radio_syn_pll_loopfilter3
decl_stmt|;
name|uint8_t
name|radio_syn_pll_loopfilter4
decl_stmt|;
name|uint8_t
name|radio_syn_pll_loopfilter5
decl_stmt|;
name|uint8_t
name|radio_syn_reserved_addr27
decl_stmt|;
name|uint8_t
name|radio_syn_reserved_addr28
decl_stmt|;
name|uint8_t
name|radio_syn_reserved_addr29
decl_stmt|;
name|uint8_t
name|radio_syn_logen_vcobuf1
decl_stmt|;
name|uint8_t
name|radio_syn_logen_mixer2
decl_stmt|;
name|uint8_t
name|radio_syn_logen_buf3
decl_stmt|;
name|uint8_t
name|radio_syn_logen_buf4
decl_stmt|;
name|uint8_t
name|radio_rx0_lnaa_tune
decl_stmt|;
name|uint8_t
name|radio_rx0_lnag_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_intpaa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_intpag_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_pada_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_padg_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_pgaa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_pgag_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_mixa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx0_mixg_boost_tune
decl_stmt|;
name|uint8_t
name|radio_rx1_lnaa_tune
decl_stmt|;
name|uint8_t
name|radio_rx1_lnag_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_intpaa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_intpag_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_pada_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_padg_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_pgaa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_pgag_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_mixa_boost_tune
decl_stmt|;
name|uint8_t
name|radio_tx1_mixg_boost_tune
decl_stmt|;
comment|/* PHY register values on channelswitch */
name|struct
name|bwn_phy_n_sfo_cfg
name|phy_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|b2056_upload_inittabs
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

begin_function_decl
name|void
name|b2056_upload_syn_pll_cp2
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|bool
name|ghz5
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the NPHY Channel Switch Table entry for a channel.  * Returns NULL on failure to find an entry. */
end_comment

begin_function_decl
specifier|const
name|struct
name|bwn_nphy_channeltab_entry_rev3
modifier|*
name|bwn_nphy_get_chantabent_rev3
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint16_t
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_RADIO_2056_H__ */
end_comment

end_unit

