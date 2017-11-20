begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/bwi/if_bwireg.h,v 1.4 2007/10/19 14:27:04 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_BWIREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_BWIREG_H
end_define

begin_comment
comment|/*  * Registers for all of the register windows  */
end_comment

begin_define
define|#
directive|define
name|BWI_FLAGS
value|0xf18
end_define

begin_define
define|#
directive|define
name|BWI_FLAGS_INTR_MASK
value|__BITS(5, 0)
end_define

begin_define
define|#
directive|define
name|BWI_IMSTATE
value|0xf90
end_define

begin_define
define|#
directive|define
name|BWI_IMSTATE_INBAND_ERR
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|BWI_IMSTATE_TIMEOUT
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|BWI_INTRVEC
value|0xf94
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO
value|0xf98
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_RESET
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_DISABLE1
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_DISABLE2
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_CLOCK
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_GATED_CLOCK
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_FLAG_PHYCLKEN
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_FLAG_PHYRST
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_FLAG_PHYLNK
value|__BIT(11)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_LO_FLAGS_MASK
value|__BITS(29, 18)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI
value|0xf9c
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_SERROR
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_BUSY
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_FLAG_MAGIC1
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_FLAG_MAGIC2
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_FLAG_64BIT
value|0x1000
end_define

begin_define
define|#
directive|define
name|BWI_STATE_HI_FLAGS_MASK
value|__BITS(28, 16)
end_define

begin_define
define|#
directive|define
name|BWI_CONF_LO
value|0xfa8
end_define

begin_define
define|#
directive|define
name|BWI_CONF_LO_SERVTO_MASK
value|__BITS(2, 0)
end_define

begin_comment
comment|/* service timeout */
end_comment

begin_define
define|#
directive|define
name|BWI_CONF_LO_SERVTO
value|2
end_define

begin_define
define|#
directive|define
name|BWI_CONF_LO_REQTO_MASK
value|__BITS(6, 4)
end_define

begin_comment
comment|/* request timeout */
end_comment

begin_define
define|#
directive|define
name|BWI_CONF_LO_REQTO
value|3
end_define

begin_define
define|#
directive|define
name|BWI_ID_LO
value|0xff8
end_define

begin_define
define|#
directive|define
name|BWI_ID_LO_BUSREV_MASK
value|__BITS(31, 28)
end_define

begin_comment
comment|/* Bus revision */
end_comment

begin_define
define|#
directive|define
name|BWI_BUSREV_0
value|0
end_define

begin_define
define|#
directive|define
name|BWI_BUSREV_1
value|1
end_define

begin_define
define|#
directive|define
name|BWI_ID_HI
value|0xffc
end_define

begin_define
define|#
directive|define
name|BWI_ID_HI_REGWIN_REV
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0xf) | (((v)& 0x7000)>> 8))
end_define

begin_define
define|#
directive|define
name|BWI_ID_HI_REGWIN_TYPE
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x8ff0)>> 4)
end_define

begin_define
define|#
directive|define
name|BWI_ID_HI_REGWIN_VENDOR_MASK
value|__BITS(31, 16)
end_define

begin_comment
comment|/*  * Registers for common register window  */
end_comment

begin_define
define|#
directive|define
name|BWI_INFO
value|0x0
end_define

begin_define
define|#
directive|define
name|BWI_INFO_BBPID_MASK
value|__BITS(15, 0)
end_define

begin_define
define|#
directive|define
name|BWI_INFO_BBPREV_MASK
value|__BITS(19, 16)
end_define

begin_define
define|#
directive|define
name|BWI_INFO_BBPPKG_MASK
value|__BITS(23, 20)
end_define

begin_define
define|#
directive|define
name|BWI_INFO_NREGWIN_MASK
value|__BITS(27, 24)
end_define

begin_define
define|#
directive|define
name|BWI_CAPABILITY
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_CAP_CLKMODE
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|BWI_CONTROL
value|0x28
end_define

begin_define
define|#
directive|define
name|BWI_CONTROL_MAGIC0
value|0x3a4
end_define

begin_define
define|#
directive|define
name|BWI_CONTROL_MAGIC1
value|0xa4
end_define

begin_define
define|#
directive|define
name|BWI_PLL_ON_DELAY
value|0xb0
end_define

begin_define
define|#
directive|define
name|BWI_FREQ_SEL_DELAY
value|0xb4
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL
value|0xb8
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL_CLKSRC
value|__BITS(2, 0)
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL_SLOW
value|__BIT(11)
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL_IGNPLL
value|__BIT(12)
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL_NODYN
value|__BIT(13)
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_CTRL_FDIV
value|__BITS(31, 16)
end_define

begin_comment
comment|/* freq divisor */
end_comment

begin_comment
comment|/* Possible values for BWI_CLOCK_CTRL_CLKSRC */
end_comment

begin_define
define|#
directive|define
name|BWI_CLKSRC_LP_OSC
value|0
end_define

begin_comment
comment|/* Low power oscillator */
end_comment

begin_define
define|#
directive|define
name|BWI_CLKSRC_CS_OSC
value|1
end_define

begin_comment
comment|/* Crystal oscillator */
end_comment

begin_define
define|#
directive|define
name|BWI_CLKSRC_PCI
value|2
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_MAX
value|3
end_define

begin_comment
comment|/* Maximum of clock source */
end_comment

begin_comment
comment|/* Min/Max frequency for given clock source */
end_comment

begin_define
define|#
directive|define
name|BWI_CLKSRC_LP_OSC_FMIN
value|25000
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_LP_OSC_FMAX
value|43000
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_CS_OSC_FMIN
value|19800000
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_CS_OSC_FMAX
value|20200000
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_PCI_FMIN
value|25000000
end_define

begin_define
define|#
directive|define
name|BWI_CLKSRC_PCI_FMAX
value|34000000
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_INFO
value|0xc0
end_define

begin_define
define|#
directive|define
name|BWI_CLOCK_INFO_FDIV
value|__BITS(31, 16)
end_define

begin_comment
comment|/* freq divisor */
end_comment

begin_comment
comment|/*  * Registers for bus register window  */
end_comment

begin_define
define|#
directive|define
name|BWI_BUS_ADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|BWI_BUS_ADDR_MAGIC
value|0xfd8
end_define

begin_define
define|#
directive|define
name|BWI_BUS_DATA
value|0x54
end_define

begin_define
define|#
directive|define
name|BWI_BUS_CONFIG
value|0x108
end_define

begin_define
define|#
directive|define
name|BWI_BUS_CONFIG_PREFETCH
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_BUS_CONFIG_BURST
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|BWI_BUS_CONFIG_MRM
value|__BIT(5)
end_define

begin_comment
comment|/*  * Register for MAC  */
end_comment

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_STATUS_BASE
value|0x20
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_MASK_BASE
value|0x24
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_STATUS
parameter_list|(
name|i
parameter_list|)
value|(BWI_TXRX_INTR_STATUS_BASE + ((i) * 8))
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_MASK
parameter_list|(
name|i
parameter_list|)
value|(BWI_TXRX_INTR_MASK_BASE + ((i) * 8))
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS
value|0x120
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_ENABLE
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_UCODE_START
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_UCODE_JUMP0
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_IHREN
value|__BIT(10)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_GPOSEL_MASK
value|__BITS(15, 14)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_BSWAP
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_INFRA
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_OPMODE_HOSTAP
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_RFLOCK
value|__BIT(19)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PASS_BCN
value|__BIT(20)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PASS_BADPLCP
value|__BIT(21)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PASS_CTL
value|__BIT(22)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PASS_BADFCS
value|__BIT(23)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PROMISC
value|__BIT(24)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_HW_PS
value|__BIT(25)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_WAKEUP
value|__BIT(26)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_STATUS_PHYLNK
value|__BIT(31)
end_define

begin_define
define|#
directive|define
name|BWI_MAC_INTR_STATUS
value|0x128
end_define

begin_define
define|#
directive|define
name|BWI_MAC_INTR_MASK
value|0x12c
end_define

begin_define
define|#
directive|define
name|BWI_MAC_TMPLT_CTRL
value|0x130
end_define

begin_define
define|#
directive|define
name|BWI_MAC_TMPLT_DATA
value|0x134
end_define

begin_define
define|#
directive|define
name|BWI_MAC_PS_STATUS
value|0x140
end_define

begin_define
define|#
directive|define
name|BWI_MOBJ_CTRL
value|0x160
end_define

begin_define
define|#
directive|define
name|BWI_MOBJ_CTRL_VAL
parameter_list|(
name|objid
parameter_list|,
name|ofs
parameter_list|)
value|((objid)<< 16 | (ofs))
end_define

begin_define
define|#
directive|define
name|BWI_MOBJ_DATA
value|0x164
end_define

begin_define
define|#
directive|define
name|BWI_MOBJ_DATA_UNALIGN
value|0x166
end_define

begin_comment
comment|/*  * Memory object IDs  */
end_comment

begin_define
define|#
directive|define
name|BWI_WR_MOBJ_AUTOINC
value|0x100
end_define

begin_comment
comment|/* Auto-increment wr */
end_comment

begin_define
define|#
directive|define
name|BWI_RD_MOBJ_AUTOINC
value|0x200
end_define

begin_comment
comment|/* Auto-increment rd */
end_comment

begin_comment
comment|/* Firmware ucode object */
end_comment

begin_define
define|#
directive|define
name|BWI_FW_UCODE_MOBJ
value|0x0
end_define

begin_comment
comment|/* Common object */
end_comment

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_FWREV
value|0x0
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_FWPATCHLV
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_SLOTTIME
value|0x10
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_MACREV
value|0x16
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_TX_ACK
value|0x22
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_UCODE_STATE
value|0x40
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_SHRETRY_FB
value|0x44
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_LGRETEY_FB
value|0x46
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_TX_BEACON
value|0x54
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_KEYTABLE_OFS
value|0x56
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_TSSI_DS
value|0x58
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_HFLAGS_LO
value|0x5e
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_HFLAGS_MI
value|0x60
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_HFLAGS_HI
value|0x62
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_RF_ATTEN
value|0x64
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_RF_NOISE
value|0x6e
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_TSSI_OFDM
value|0x70
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_PROBE_RESP_TO
value|0x74
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_CHAN
value|0xa0
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_KEY_ALGO
value|0x100
end_define

begin_define
define|#
directive|define
name|BWI_COMM_MOBJ_TX_PROBE_RESP
value|0x188
end_define

begin_define
define|#
directive|define
name|BWI_HFLAG_AUTO_ANTDIV
value|0x1ULL
end_define

begin_define
define|#
directive|define
name|BWI_HFLAG_SYM_WA
value|0x2ULL
end_define

begin_comment
comment|/* ??? SYM work around */
end_comment

begin_define
define|#
directive|define
name|BWI_HFLAG_PWR_BOOST_DS
value|0x8ULL
end_define

begin_define
define|#
directive|define
name|BWI_HFLAG_GDC_WA
value|0x20ULL
end_define

begin_comment
comment|/* ??? GDC work around */
end_comment

begin_define
define|#
directive|define
name|BWI_HFLAG_OFDM_PA
value|0x40ULL
end_define

begin_define
define|#
directive|define
name|BWI_HFLAG_NOT_JAPAN
value|0x80ULL
end_define

begin_define
define|#
directive|define
name|BWI_HFLAG_MAGIC1
value|0x200ULL
end_define

begin_define
define|#
directive|define
name|BWI_UCODE_STATE_PS
value|4
end_define

begin_define
define|#
directive|define
name|BWI_LO_TSSI_MASK
value|__BITS(7, 0)
end_define

begin_define
define|#
directive|define
name|BWI_HI_TSSI_MASK
value|__BITS(15, 8)
end_define

begin_define
define|#
directive|define
name|BWI_INVALID_TSSI
value|0x7f
end_define

begin_comment
comment|/* 802.11 object */
end_comment

begin_define
define|#
directive|define
name|BWI_80211_MOBJ
value|0x2
end_define

begin_define
define|#
directive|define
name|BWI_80211_MOBJ_CWMIN
value|0xc
end_define

begin_define
define|#
directive|define
name|BWI_80211_MOBJ_CWMAX
value|0x10
end_define

begin_define
define|#
directive|define
name|BWI_80211_MOBJ_SHRETRY
value|0x18
end_define

begin_define
define|#
directive|define
name|BWI_80211_MOBJ_LGRETRY
value|0x1c
end_define

begin_comment
comment|/* Firmware PCM object */
end_comment

begin_define
define|#
directive|define
name|BWI_FW_PCM_MOBJ
value|0x3
end_define

begin_comment
comment|/* MAC address of pairwise keys */
end_comment

begin_define
define|#
directive|define
name|BWI_PKEY_ADDR_MOBJ
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0
value|0x170
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_VALID
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_ACKED
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_FREASON_MASK
value|__BITS(4, 2)
end_define

begin_comment
comment|/* Failure reason */
end_comment

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_AMPDU
value|__BIT(5)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_PENDING
value|__BIT(6)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_PM
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_RTS_TXCNT_MASK
value|__BITS(11, 8)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_DATA_TXCNT_MASK
value|__BITS(15, 12)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS0_TXID_MASK
value|__BITS(31, 16)
end_define

begin_define
define|#
directive|define
name|BWI_TXSTATUS1
value|0x174
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_CTRL_BASE
value|0x200
end_define

begin_define
define|#
directive|define
name|BWI_TX32_CTRL
value|0x0
end_define

begin_define
define|#
directive|define
name|BWI_TX32_RINGINFO
value|0x4
end_define

begin_define
define|#
directive|define
name|BWI_TX32_INDEX
value|0x8
end_define

begin_define
define|#
directive|define
name|BWI_TX32_STATUS
value|0xc
end_define

begin_define
define|#
directive|define
name|BWI_TX32_STATUS_STATE_MASK
value|__BITS(15, 12)
end_define

begin_define
define|#
directive|define
name|BWI_TX32_STATUS_STATE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|BWI_TX32_STATUS_STATE_IDLE
value|2
end_define

begin_define
define|#
directive|define
name|BWI_TX32_STATUS_STATE_STOPPED
value|3
end_define

begin_define
define|#
directive|define
name|BWI_RX32_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|BWI_RX32_CTRL_HDRSZ_MASK
value|__BITS(7, 1)
end_define

begin_define
define|#
directive|define
name|BWI_RX32_RINGINFO
value|0x14
end_define

begin_define
define|#
directive|define
name|BWI_RX32_INDEX
value|0x18
end_define

begin_define
define|#
directive|define
name|BWI_RX32_STATUS
value|0x1c
end_define

begin_define
define|#
directive|define
name|BWI_RX32_STATUS_INDEX_MASK
value|__BITS(11, 0)
end_define

begin_define
define|#
directive|define
name|BWI_RX32_STATUS_STATE_MASK
value|__BITS(15, 12)
end_define

begin_define
define|#
directive|define
name|BWI_RX32_STATUS_STATE_DISABLED
value|0
end_define

begin_comment
comment|/* Shared by 32bit TX/RX CTRL */
end_comment

begin_define
define|#
directive|define
name|BWI_TXRX32_CTRL_ENABLE
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_TXRX32_CTRL_ADDRHI_MASK
value|__BITS(17, 16)
end_define

begin_comment
comment|/* Shared by 32bit TX/RX RINGINFO */
end_comment

begin_define
define|#
directive|define
name|BWI_TXRX32_RINGINFO_FUNC_TXRX
value|0x1
end_define

begin_define
define|#
directive|define
name|BWI_TXRX32_RINGINFO_FUNC_MASK
value|__BITS(31, 30)
end_define

begin_define
define|#
directive|define
name|BWI_TXRX32_RINGINFO_ADDR_MASK
value|__BITS(29, 0)
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO
value|0x3e0
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_REV_MASK
value|__BITS(3, 0)
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_MASK
value|__BITS(11, 8)
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_11A
value|0
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_11B
value|1
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_11G
value|2
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_11N
value|4
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_TYPE_11LP
value|5
end_define

begin_define
define|#
directive|define
name|BWI_PHYINFO_VER_MASK
value|__BITS(15, 12)
end_define

begin_define
define|#
directive|define
name|BWI_RF_ANTDIV
value|0x3e2
end_define

begin_comment
comment|/* Antenna Diversity?? */
end_comment

begin_define
define|#
directive|define
name|BWI_PHY_MAGIC_REG1
value|0x3e4
end_define

begin_define
define|#
directive|define
name|BWI_PHY_MAGIC_REG1_VAL1
value|0x3000
end_define

begin_define
define|#
directive|define
name|BWI_PHY_MAGIC_REG1_VAL2
value|0x9
end_define

begin_define
define|#
directive|define
name|BWI_BBP_ATTEN
value|0x3e6
end_define

begin_define
define|#
directive|define
name|BWI_BBP_ATTEN_MAGIC
value|0xf4
end_define

begin_define
define|#
directive|define
name|BWI_BBP_ATTEN_MAGIC2
value|0x8140
end_define

begin_define
define|#
directive|define
name|BWI_BPHY_CTRL
value|0x3ec
end_define

begin_define
define|#
directive|define
name|BWI_BPHY_CTRL_INIT
value|0x3f22
end_define

begin_define
define|#
directive|define
name|BWI_RF_CHAN
value|0x3f0
end_define

begin_define
define|#
directive|define
name|BWI_RF_CHAN_EX
value|0x3f4
end_define

begin_define
define|#
directive|define
name|BWI_RF_CTRL
value|0x3f6
end_define

begin_comment
comment|/* Register values for BWI_RF_CTRL */
end_comment

begin_define
define|#
directive|define
name|BWI_RF_CTRL_RFINFO
value|0x1
end_define

begin_comment
comment|/* XXX extra bits for reading from radio */
end_comment

begin_define
define|#
directive|define
name|BWI_RF_CTRL_RD_11A
value|0x40
end_define

begin_define
define|#
directive|define
name|BWI_RF_CTRL_RD_11BG
value|0x80
end_define

begin_define
define|#
directive|define
name|BWI_RF_DATA_HI
value|0x3f8
end_define

begin_define
define|#
directive|define
name|BWI_RF_DATA_LO
value|0x3fa
end_define

begin_comment
comment|/* Values read from BWI_RF_DATA_{HI,LO} after BWI_RF_CTRL_RFINFO */
end_comment

begin_define
define|#
directive|define
name|BWI_RFINFO_MANUFACT_MASK
value|__BITS(11, 0)
end_define

begin_define
define|#
directive|define
name|BWI_RF_MANUFACT_BCM
value|0x17f
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BWI_RFINFO_TYPE_MASK
value|__BITS(27, 12)
end_define

begin_define
define|#
directive|define
name|BWI_RF_T_BCM2050
value|0x2050
end_define

begin_define
define|#
directive|define
name|BWI_RF_T_BCM2053
value|0x2053
end_define

begin_define
define|#
directive|define
name|BWI_RF_T_BCM2060
value|0x2060
end_define

begin_define
define|#
directive|define
name|BWI_RFINFO_REV_MASK
value|__BITS(31, 28)
end_define

begin_define
define|#
directive|define
name|BWI_PHY_CTRL
value|0x3fc
end_define

begin_define
define|#
directive|define
name|BWI_PHY_DATA
value|0x3fe
end_define

begin_define
define|#
directive|define
name|BWI_ADDR_FILTER_CTRL
value|0x420
end_define

begin_define
define|#
directive|define
name|BWI_ADDR_FILTER_CTRL_SET
value|0x20
end_define

begin_define
define|#
directive|define
name|BWI_ADDR_FILTER_MYADDR
value|0
end_define

begin_define
define|#
directive|define
name|BWI_ADDR_FILTER_BSSID
value|3
end_define

begin_define
define|#
directive|define
name|BWI_ADDR_FILTER_DATA
value|0x422
end_define

begin_define
define|#
directive|define
name|BWI_MAC_GPIO_CTRL
value|0x49c
end_define

begin_define
define|#
directive|define
name|BWI_MAC_GPIO_MASK
value|0x49e
end_define

begin_define
define|#
directive|define
name|BWI_MAC_PRE_TBTT
value|0x612
end_define

begin_define
define|#
directive|define
name|BWI_MAC_SLOTTIME
value|0x684
end_define

begin_define
define|#
directive|define
name|BWI_MAC_SLOTTIME_ADJUST
value|510
end_define

begin_define
define|#
directive|define
name|BWI_MAC_POWERUP_DELAY
value|0x6a8
end_define

begin_comment
comment|/*  * Special registers  */
end_comment

begin_comment
comment|/*  * GPIO control  * If common regwin exists, then it is within common regwin,  * else it is in bus regwin.  */
end_comment

begin_define
define|#
directive|define
name|BWI_GPIO_CTRL
value|0x6c
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_BROADCOM
value|0x14e4
end_define

begin_comment
comment|/* Broadcom */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_BROADCOM_BCM4309
value|0x4324
end_define

begin_comment
comment|/*  * Extended PCI registers  */
end_comment

begin_define
define|#
directive|define
name|BWI_PCIR_BAR
value|PCIR_BAR(0)
end_define

begin_define
define|#
directive|define
name|BWI_PCIR_SEL_REGWIN
value|0x80
end_define

begin_comment
comment|/* Register value for BWI_PCIR_SEL_REGWIN */
end_comment

begin_define
define|#
directive|define
name|BWI_PCIM_REGWIN
parameter_list|(
name|id
parameter_list|)
value|(((id) * 0x1000) + 0x18000000)
end_define

begin_define
define|#
directive|define
name|BWI_PCIR_GPIO_IN
value|0xb0
end_define

begin_define
define|#
directive|define
name|BWI_PCIR_GPIO_OUT
value|0xb4
end_define

begin_define
define|#
directive|define
name|BWI_PCIM_GPIO_OUT_CLKSRC
value|__BIT(4)
end_define

begin_define
define|#
directive|define
name|BWI_PCIR_GPIO_ENABLE
value|0xb8
end_define

begin_comment
comment|/* Register values for BWI_PCIR_GPIO_{IN,OUT,ENABLE} */
end_comment

begin_define
define|#
directive|define
name|BWI_PCIM_GPIO_PWR_ON
value|__BIT(6)
end_define

begin_define
define|#
directive|define
name|BWI_PCIM_GPIO_PLL_PWR_OFF
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|BWI_PCIR_INTCTL
value|0x94
end_define

begin_comment
comment|/*  * PCI subdevice IDs  */
end_comment

begin_define
define|#
directive|define
name|BWI_PCI_SUBDEVICE_BU4306
value|0x416
end_define

begin_define
define|#
directive|define
name|BWI_PCI_SUBDEVICE_BCM4309G
value|0x421
end_define

begin_define
define|#
directive|define
name|BWI_IS_BRCM_BU4306
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->sc_pci_subvid == PCI_VENDOR_BROADCOM&& \ 	 (sc)->sc_pci_subdid == BWI_PCI_SUBDEVICE_BU4306)
end_define

begin_define
define|#
directive|define
name|BWI_IS_BRCM_BCM4309G
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->sc_pci_subvid == PCI_VENDOR_BROADCOM&& \ 	 (sc)->sc_pci_subdid == BWI_PCI_SUBDEVICE_BCM4309G)
end_define

begin_comment
comment|/*  * EEPROM start address  */
end_comment

begin_define
define|#
directive|define
name|BWI_SPROM_START
value|0x1000
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_11BG_EADDR
value|0x48
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_11A_EADDR
value|0x54
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_CARD_INFO
value|0x5c
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_CARD_INFO_LOCALE
value|__BITS(11, 8)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_LOCALE_JAPAN
value|5
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_PA_PARAM_11BG
value|0x5e
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO01
value|0x64
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO_0
value|__BITS(7, 0)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO_1
value|__BITS(15, 8)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO23
value|0x66
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO_2
value|__BITS(7, 0)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_GPIO_3
value|__BITS(15, 8)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_MAX_TXPWR
value|0x68
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_MAX_TXPWR_MASK_11BG
value|__BITS(7, 0)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BWI_SPROM_MAX_TXPWR_MASK_11A
value|__BITS(15, 8)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BWI_SPROM_PA_PARAM_11A
value|0x6a
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_IDLE_TSSI
value|0x70
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_IDLE_TSSI_MASK_11BG
value|__BITS(7, 0)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BWI_SPROM_IDLE_TSSI_MASK_11A
value|__BITS(15, 8)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BWI_SPROM_CARD_FLAGS
value|0x72
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_ANT_GAIN
value|0x74
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_ANT_GAIN_MASK_11A
value|__BITS(7, 0)
end_define

begin_define
define|#
directive|define
name|BWI_SPROM_ANT_GAIN_MASK_11BG
value|__BITS(15, 8)
end_define

begin_comment
comment|/*  * SPROM card flags  */
end_comment

begin_define
define|#
directive|define
name|BWI_CARD_F_BT_COEXIST
value|__BIT(0)
end_define

begin_comment
comment|/* Bluetooth coexist */
end_comment

begin_define
define|#
directive|define
name|BWI_CARD_F_PA_GPIO9
value|__BIT(1)
end_define

begin_comment
comment|/* GPIO 9 controls PA */
end_comment

begin_define
define|#
directive|define
name|BWI_CARD_F_SW_NRSSI
value|__BIT(3)
end_define

begin_define
define|#
directive|define
name|BWI_CARD_F_NO_SLOWCLK
value|__BIT(5)
end_define

begin_comment
comment|/* no slow clock */
end_comment

begin_define
define|#
directive|define
name|BWI_CARD_F_EXT_LNA
value|__BIT(12)
end_define

begin_comment
comment|/* external LNA */
end_comment

begin_define
define|#
directive|define
name|BWI_CARD_F_ALT_IQ
value|__BIT(15)
end_define

begin_comment
comment|/* alternate I/Q */
end_comment

begin_comment
comment|/*  * SPROM GPIO  */
end_comment

begin_define
define|#
directive|define
name|BWI_LED_ACT_LOW
value|__BIT(7)
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_MASK
value|__BITS(6, 0)
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_ON
value|1
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_BLINK
value|2
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_RF_ENABLED
value|3
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_5GHZ
value|4
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_2GHZ
value|5
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_11G
value|6
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_BLINK_SLOW
value|7
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_BLINK_POLL
value|8
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_UNKN
value|9
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_ASSOC
value|10
end_define

begin_define
define|#
directive|define
name|BWI_LED_ACT_NULL
value|11
end_define

begin_define
define|#
directive|define
name|BWI_VENDOR_LED_ACT_COMPAQ
define|\
value|BWI_LED_ACT_RF_ENABLED,		\ 	BWI_LED_ACT_2GHZ,		\ 	BWI_LED_ACT_5GHZ,		\ 	BWI_LED_ACT_OFF
end_define

begin_define
define|#
directive|define
name|BWI_VENDOR_LED_ACT_LINKSYS
define|\
value|BWI_LED_ACT_ASSOC,		\ 	BWI_LED_ACT_2GHZ,		\ 	BWI_LED_ACT_5GHZ,		\ 	BWI_LED_ACT_OFF
end_define

begin_define
define|#
directive|define
name|BWI_VENDOR_LED_ACT_DEFAULT
define|\
value|BWI_LED_ACT_BLINK,		\ 	BWI_LED_ACT_2GHZ,		\ 	BWI_LED_ACT_5GHZ,		\ 	BWI_LED_ACT_OFF
end_define

begin_comment
comment|/*  * BBP IDs  */
end_comment

begin_define
define|#
directive|define
name|BWI_BBPID_BCM4301
value|0x4301
end_define

begin_define
define|#
directive|define
name|BWI_BBPID_BCM4306
value|0x4306
end_define

begin_define
define|#
directive|define
name|BWI_BBPID_BCM4317
value|0x4317
end_define

begin_define
define|#
directive|define
name|BWI_BBPID_BCM4320
value|0x4320
end_define

begin_define
define|#
directive|define
name|BWI_BBPID_BCM4321
value|0x4321
end_define

begin_comment
comment|/*  * Register window types  */
end_comment

begin_define
define|#
directive|define
name|BWI_REGWIN_T_COM
value|0x800
end_define

begin_define
define|#
directive|define
name|BWI_REGWIN_T_BUSPCI
value|0x804
end_define

begin_define
define|#
directive|define
name|BWI_REGWIN_T_MAC
value|0x812
end_define

begin_define
define|#
directive|define
name|BWI_REGWIN_T_BUSPCIE
value|0x820
end_define

begin_comment
comment|/*  * MAC interrupts  */
end_comment

begin_define
define|#
directive|define
name|BWI_INTR_READY
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_BEACON
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_TBTT
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_EO_ATIM
value|__BIT(5)
end_define

begin_comment
comment|/* End of ATIM */
end_comment

begin_define
define|#
directive|define
name|BWI_INTR_PMQ
value|__BIT(6)
end_define

begin_comment
comment|/* XXX?? */
end_comment

begin_define
define|#
directive|define
name|BWI_INTR_MAC_TXERR
value|__BIT(9)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_PHY_TXERR
value|__BIT(11)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_TIMER1
value|__BIT(14)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_RX_DONE
value|__BIT(15)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_TX_FIFO
value|__BIT(16)
end_define

begin_comment
comment|/* XXX?? */
end_comment

begin_define
define|#
directive|define
name|BWI_INTR_NOISE
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_RF_DISABLED
value|__BIT(28)
end_define

begin_define
define|#
directive|define
name|BWI_INTR_TX_DONE
value|__BIT(29)
end_define

begin_define
define|#
directive|define
name|BWI_INIT_INTRS
define|\
value|(BWI_INTR_READY | BWI_INTR_BEACON | BWI_INTR_TBTT | \ 	 BWI_INTR_EO_ATIM | BWI_INTR_PMQ | BWI_INTR_MAC_TXERR | \ 	 BWI_INTR_PHY_TXERR | BWI_INTR_RX_DONE | BWI_INTR_TX_FIFO | \ 	 BWI_INTR_NOISE | BWI_INTR_RF_DISABLED | BWI_INTR_TX_DONE)
end_define

begin_define
define|#
directive|define
name|BWI_ALL_INTRS
value|0xffffffff
end_define

begin_comment
comment|/*  * TX/RX interrupts  */
end_comment

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_ERROR
value|(__BIT(15) | __BIT(14) | __BITS(12, 10))
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_INTR_RX
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_TX_INTRS
value|BWI_TXRX_INTR_ERROR
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_RX_INTRS
value|(BWI_TXRX_INTR_ERROR | BWI_TXRX_INTR_RX)
end_define

begin_define
define|#
directive|define
name|BWI_TXRX_IS_RX
parameter_list|(
name|i
parameter_list|)
value|((i) % 3 == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_BWIREG_H */
end_comment

end_unit

