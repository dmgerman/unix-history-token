begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015 Stefan Sperling<stsp@openbsd.org>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92C_REG_H
end_ifndef

begin_define
define|#
directive|define
name|R92C_REG_H
end_define

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_comment
comment|/* System Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL
value|0x000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN
value|0x002
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO
value|0x004
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR
value|0x008
end_define

begin_define
define|#
directive|define
name|R92C_AFE_MISC
value|0x010
end_define

begin_define
define|#
directive|define
name|R92C_SPS0_CTRL
value|0x011
end_define

begin_define
define|#
directive|define
name|R92C_SPS_OCP_CFG
value|0x018
end_define

begin_define
define|#
directive|define
name|R92C_RSV_CTRL
value|0x01c
end_define

begin_define
define|#
directive|define
name|R92C_RF_CTRL
value|0x01f
end_define

begin_define
define|#
directive|define
name|R92C_LDOA15_CTRL
value|0x020
end_define

begin_define
define|#
directive|define
name|R92C_LDOV12D_CTRL
value|0x021
end_define

begin_define
define|#
directive|define
name|R92C_LDOHCI12_CTRL
value|0x022
end_define

begin_define
define|#
directive|define
name|R92C_LPLDO_CTRL
value|0x023
end_define

begin_define
define|#
directive|define
name|R92C_AFE_XTAL_CTRL
value|0x024
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL
value|0x028
end_define

begin_define
define|#
directive|define
name|R92C_APE_PLL_CTRL_EXT
value|0x02c
end_define

begin_define
define|#
directive|define
name|R92C_MAC_PHY_CTRL
value|R92C_APE_PLL_CTRL_EXT
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL
value|0x030
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_TEST
value|0x034
end_define

begin_define
define|#
directive|define
name|R92C_PWR_DATA
value|0x038
end_define

begin_define
define|#
directive|define
name|R92C_CAL_TIMER
value|0x03c
end_define

begin_define
define|#
directive|define
name|R92C_ACLK_MON
value|0x03e
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_MUXCFG
value|0x040
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_IO_SEL
value|0x042
end_define

begin_define
define|#
directive|define
name|R92C_MAC_PINMUX_CFG
value|0x043
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_PIN_CTRL
value|0x044
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_IN
value|0x044
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_OUT
value|0x045
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_IOSEL
value|0x046
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_MOD
value|0x047
end_define

begin_define
define|#
directive|define
name|R92C_GPIO_INTM
value|0x048
end_define

begin_define
define|#
directive|define
name|R92C_LEDCFG0
value|0x04c
end_define

begin_define
define|#
directive|define
name|R92C_LEDCFG1
value|0x04d
end_define

begin_define
define|#
directive|define
name|R92C_LEDCFG2
value|0x04e
end_define

begin_define
define|#
directive|define
name|R92C_LEDCFG3
value|0x04f
end_define

begin_define
define|#
directive|define
name|R92C_FSIMR
value|0x050
end_define

begin_define
define|#
directive|define
name|R92C_FSISR
value|0x054
end_define

begin_define
define|#
directive|define
name|R92C_HSIMR
value|0x058
end_define

begin_define
define|#
directive|define
name|R92C_HSISR
value|0x05c
end_define

begin_define
define|#
directive|define
name|R92C_MULTI_FUNC_CTRL
value|0x068
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL
value|0x080
end_define

begin_define
define|#
directive|define
name|R92C_HMEBOX_EXT
parameter_list|(
name|idx
parameter_list|)
value|(0x088 + (idx) * 2)
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_ACCESS
value|0x0cf
end_define

begin_define
define|#
directive|define
name|R92C_BIST_SCAN
value|0x0d0
end_define

begin_define
define|#
directive|define
name|R92C_BIST_RPT
value|0x0d4
end_define

begin_define
define|#
directive|define
name|R92C_BIST_ROM_RPT
value|0x0d8
end_define

begin_define
define|#
directive|define
name|R92C_HPON_FSM
value|0x0ec
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG
value|0x0f0
end_define

begin_define
define|#
directive|define
name|R92C_TYPE_ID
value|0x0fc
end_define

begin_comment
comment|/* MAC General Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_CR
value|0x100
end_define

begin_define
define|#
directive|define
name|R92C_MSR
value|0x102
end_define

begin_define
define|#
directive|define
name|R92C_PBP
value|0x104
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL
value|0x10c
end_define

begin_define
define|#
directive|define
name|R92C_TRXFF_BNDY
value|0x114
end_define

begin_define
define|#
directive|define
name|R92C_TRXFF_STATUS
value|0x118
end_define

begin_define
define|#
directive|define
name|R92C_RXFF_PTR
value|0x11c
end_define

begin_define
define|#
directive|define
name|R92C_HIMR
value|0x120
end_define

begin_define
define|#
directive|define
name|R92C_HISR
value|0x124
end_define

begin_define
define|#
directive|define
name|R92C_HIMRE
value|0x128
end_define

begin_define
define|#
directive|define
name|R92C_HISRE
value|0x12c
end_define

begin_define
define|#
directive|define
name|R92C_CPWM
value|0x12f
end_define

begin_define
define|#
directive|define
name|R92C_FWIMR
value|0x130
end_define

begin_define
define|#
directive|define
name|R92C_FWISR
value|0x134
end_define

begin_define
define|#
directive|define
name|R92C_PKTBUF_DBG_CTRL
value|0x140
end_define

begin_define
define|#
directive|define
name|R92C_PKTBUF_DBG_DATA_L
value|0x144
end_define

begin_define
define|#
directive|define
name|R92C_PKTBUF_DBG_DATA_H
value|0x148
end_define

begin_define
define|#
directive|define
name|R92C_TC0_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x150 + (i) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_TCUNIT_BASE
value|0x164
end_define

begin_define
define|#
directive|define
name|R92C_MBIST_START
value|0x174
end_define

begin_define
define|#
directive|define
name|R92C_MBIST_DONE
value|0x178
end_define

begin_define
define|#
directive|define
name|R92C_MBIST_FAIL
value|0x17c
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_MSG
value|0x1a0
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_CLEAR
value|0x1af
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_MSG_TEST
value|0x1b8
end_define

begin_define
define|#
directive|define
name|R92C_MCUTST_1
value|0x1c0
end_define

begin_define
define|#
directive|define
name|R92C_FMETHR
value|0x1c8
end_define

begin_define
define|#
directive|define
name|R92C_HMETFR
value|0x1cc
end_define

begin_define
define|#
directive|define
name|R92C_HMEBOX
parameter_list|(
name|idx
parameter_list|)
value|(0x1d0 + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT
value|0x1e0
end_define

begin_define
define|#
directive|define
name|R92C_BB_ACCESS_CTRL
value|0x1e8
end_define

begin_define
define|#
directive|define
name|R92C_BB_ACCESS_DATA
value|0x1ec
end_define

begin_comment
comment|/* Tx DMA Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_RQPN
value|0x200
end_define

begin_define
define|#
directive|define
name|R92C_FIFOPAGE
value|0x204
end_define

begin_define
define|#
directive|define
name|R92C_TDECTRL
value|0x208
end_define

begin_define
define|#
directive|define
name|R92C_TXDMA_OFFSET_CHK
value|0x20c
end_define

begin_define
define|#
directive|define
name|R92C_TXDMA_STATUS
value|0x210
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_NPQ
value|0x214
end_define

begin_comment
comment|/* Rx DMA Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_RXDMA_AGG_PG_TH
value|0x280
end_define

begin_define
define|#
directive|define
name|R92C_RXPKT_NUM
value|0x284
end_define

begin_define
define|#
directive|define
name|R92C_RXDMA_STATUS
value|0x288
end_define

begin_comment
comment|/* Protocol Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_VOQ_INFORMATION
value|0x400
end_define

begin_define
define|#
directive|define
name|R92C_VIQ_INFORMATION
value|0x404
end_define

begin_define
define|#
directive|define
name|R92C_BEQ_INFORMATION
value|0x408
end_define

begin_define
define|#
directive|define
name|R92C_BKQ_INFORMATION
value|0x40c
end_define

begin_define
define|#
directive|define
name|R92C_MGQ_INFORMATION
value|0x410
end_define

begin_define
define|#
directive|define
name|R92C_HGQ_INFORMATION
value|0x414
end_define

begin_define
define|#
directive|define
name|R92C_BCNQ_INFORMATION
value|0x418
end_define

begin_define
define|#
directive|define
name|R92C_CPU_MGQ_INFORMATION
value|0x41c
end_define

begin_define
define|#
directive|define
name|R92C_FWHW_TXQ_CTRL
value|0x420
end_define

begin_define
define|#
directive|define
name|R92C_HWSEQ_CTRL
value|0x423
end_define

begin_define
define|#
directive|define
name|R92C_TXPKTBUF_BCNQ_BDNY
value|0x424
end_define

begin_define
define|#
directive|define
name|R92C_TXPKTBUF_MGQ_BDNY
value|0x425
end_define

begin_define
define|#
directive|define
name|R92C_SPEC_SIFS
value|0x428
end_define

begin_define
define|#
directive|define
name|R92C_RL
value|0x42a
end_define

begin_define
define|#
directive|define
name|R92C_DARFRC
value|0x430
end_define

begin_define
define|#
directive|define
name|R92C_RARFRC
value|0x438
end_define

begin_define
define|#
directive|define
name|R92C_RRSR
value|0x440
end_define

begin_define
define|#
directive|define
name|R92C_ARFR
parameter_list|(
name|i
parameter_list|)
value|(0x444 + (i) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_AGGLEN_LMT
value|0x458
end_define

begin_define
define|#
directive|define
name|R92C_AMPDU_MIN_SPACE
value|0x45c
end_define

begin_define
define|#
directive|define
name|R92C_TXPKTBUF_WMAC_LBK_BF_HD
value|0x45d
end_define

begin_define
define|#
directive|define
name|R92C_FAST_EDCA_CTRL
value|0x460
end_define

begin_define
define|#
directive|define
name|R92C_RD_RESP_PKT_TH
value|0x463
end_define

begin_define
define|#
directive|define
name|R92C_INIRTS_RATE_SEL
value|0x480
end_define

begin_define
define|#
directive|define
name|R92C_INIDATA_RATE_SEL
parameter_list|(
name|macid
parameter_list|)
value|(0x484 + (macid))
end_define

begin_define
define|#
directive|define
name|R92C_QUEUE_CTRL
value|0x4c6
end_define

begin_define
define|#
directive|define
name|R92C_MAX_AGGR_NUM
value|0x4ca
end_define

begin_define
define|#
directive|define
name|R92C_BAR_MODE_CTRL
value|0x4cc
end_define

begin_comment
comment|/* EDCA Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_EDCA_VO_PARAM
value|0x500
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_VI_PARAM
value|0x504
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_BE_PARAM
value|0x508
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_BK_PARAM
value|0x50c
end_define

begin_define
define|#
directive|define
name|R92C_BCNTCFG
value|0x510
end_define

begin_define
define|#
directive|define
name|R92C_PIFS
value|0x512
end_define

begin_define
define|#
directive|define
name|R92C_RDG_PIFS
value|0x513
end_define

begin_define
define|#
directive|define
name|R92C_SIFS_CCK
value|0x514
end_define

begin_define
define|#
directive|define
name|R92C_SIFS_OFDM
value|0x516
end_define

begin_define
define|#
directive|define
name|R92C_AGGR_BREAK_TIME
value|0x51a
end_define

begin_define
define|#
directive|define
name|R92C_SLOT
value|0x51b
end_define

begin_define
define|#
directive|define
name|R92C_TX_PTCL_CTRL
value|0x520
end_define

begin_define
define|#
directive|define
name|R92C_TXPAUSE
value|0x522
end_define

begin_define
define|#
directive|define
name|R92C_DIS_TXREQ_CLR
value|0x523
end_define

begin_define
define|#
directive|define
name|R92C_RD_CTRL
value|0x524
end_define

begin_define
define|#
directive|define
name|R92C_TBTT_PROHIBIT
value|0x540
end_define

begin_define
define|#
directive|define
name|R92C_RD_NAV_NXT
value|0x544
end_define

begin_define
define|#
directive|define
name|R92C_NAV_PROT_LEN
value|0x546
end_define

begin_define
define|#
directive|define
name|R92C_BCN_CTRL
parameter_list|(
name|id
parameter_list|)
value|((id) + 0x550)
end_define

begin_comment
comment|/* WARNING: R92C_USTIME_TSF == 0x55c, not 0x551 */
end_comment

begin_define
define|#
directive|define
name|R92C_MBID_NUM
value|0x552
end_define

begin_define
define|#
directive|define
name|R92C_DUAL_TSF_RST
value|0x553
end_define

begin_define
define|#
directive|define
name|R92C_BCN_INTERVAL
parameter_list|(
name|id
parameter_list|)
value|(0x554 + (id) * 2)
end_define

begin_define
define|#
directive|define
name|R92C_DRVERLYINT
value|0x558
end_define

begin_define
define|#
directive|define
name|R92C_BCNDMATIM
value|0x559
end_define

begin_define
define|#
directive|define
name|R92C_ATIMWND
value|0x55a
end_define

begin_define
define|#
directive|define
name|R92C_USTIME_TSF
value|0x55c
end_define

begin_define
define|#
directive|define
name|R92C_BCN_MAX_ERR
value|0x55d
end_define

begin_define
define|#
directive|define
name|R92C_RXTSF_OFFSET_CCK
value|0x55e
end_define

begin_define
define|#
directive|define
name|R92C_RXTSF_OFFSET_OFDM
value|0x55f
end_define

begin_define
define|#
directive|define
name|R92C_TSFTR
parameter_list|(
name|i
parameter_list|)
value|(0x560 + (i) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_PSTIMER
value|0x580
end_define

begin_define
define|#
directive|define
name|R92C_TIMER0
value|0x584
end_define

begin_define
define|#
directive|define
name|R92C_TIMER1
value|0x588
end_define

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL
value|0x5c0
end_define

begin_define
define|#
directive|define
name|R92C_ACMRSTCTRL
value|0x5c1
end_define

begin_define
define|#
directive|define
name|R92C_ACMAVG
value|0x5c2
end_define

begin_define
define|#
directive|define
name|R92C_VO_ADMTIME
value|0x5c4
end_define

begin_define
define|#
directive|define
name|R92C_VI_ADMTIME
value|0x5c6
end_define

begin_define
define|#
directive|define
name|R92C_BE_ADMTIME
value|0x5c8
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_RANDOM_GEN
value|0x5cc
end_define

begin_define
define|#
directive|define
name|R92C_SCH_TXCMD
value|0x5d0
end_define

begin_comment
comment|/* WMAC Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_APSD_CTRL
value|0x600
end_define

begin_define
define|#
directive|define
name|R92C_BWOPMODE
value|0x603
end_define

begin_define
define|#
directive|define
name|R92C_TCR
value|0x604
end_define

begin_define
define|#
directive|define
name|R92C_RCR
value|0x608
end_define

begin_define
define|#
directive|define
name|R92C_RX_PKT_LIMIT
value|0x60c
end_define

begin_define
define|#
directive|define
name|R92C_RX_DRVINFO_SZ
value|0x60f
end_define

begin_define
define|#
directive|define
name|R92C_MACID0
value|0x610
end_define

begin_define
define|#
directive|define
name|R92C_BSSID0
value|0x618
end_define

begin_define
define|#
directive|define
name|R92C_MAR
value|0x620
end_define

begin_define
define|#
directive|define
name|R92C_USTIME_EDCA
value|0x638
end_define

begin_define
define|#
directive|define
name|R92C_MAC_SPEC_SIFS
value|0x63a
end_define

begin_define
define|#
directive|define
name|R92C_R2T_SIFS
value|0x63c
end_define

begin_define
define|#
directive|define
name|R92C_T2T_SIFS
value|0x63e
end_define

begin_define
define|#
directive|define
name|R92C_ACKTO
value|0x640
end_define

begin_define
define|#
directive|define
name|R92C_NAV_UPPER
value|0x652
end_define

begin_define
define|#
directive|define
name|R92C_WMAC_TRXPTCL_CTL
value|0x668
end_define

begin_define
define|#
directive|define
name|R92C_CAMCMD
value|0x670
end_define

begin_define
define|#
directive|define
name|R92C_CAMWRITE
value|0x674
end_define

begin_define
define|#
directive|define
name|R92C_CAMREAD
value|0x678
end_define

begin_define
define|#
directive|define
name|R92C_CAMDBG
value|0x67c
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG
value|0x680
end_define

begin_define
define|#
directive|define
name|R92C_RXFLTMAP0
value|0x6a0
end_define

begin_define
define|#
directive|define
name|R92C_RXFLTMAP1
value|0x6a2
end_define

begin_define
define|#
directive|define
name|R92C_RXFLTMAP2
value|0x6a4
end_define

begin_define
define|#
directive|define
name|R92C_BCN_PSR_RPT
value|0x6a8
end_define

begin_define
define|#
directive|define
name|R92C_MACID1
value|0x700
end_define

begin_define
define|#
directive|define
name|R92C_BSSID1
value|0x708
end_define

begin_define
define|#
directive|define
name|R92C_MACID
parameter_list|(
name|id
parameter_list|)
value|((id) == 0 ? R92C_MACID0 : R92C_MACID1)
end_define

begin_define
define|#
directive|define
name|R92C_BSSID
parameter_list|(
name|id
parameter_list|)
value|((id) == 0 ? R92C_BSSID0 : R92C_BSSID1)
end_define

begin_comment
comment|/* Bits for R92C_SYS_ISO_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_MD2PP
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_UA2USB
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_UD2CORE
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_PA2PCIE
value|0x0008
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_PD2CORE
value|0x0010
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_IP2MAC
value|0x0020
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_DIOP
value|0x0040
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_DIOE
value|0x0080
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_EB2CORE
value|0x0100
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_DIOR
value|0x0200
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_PWC_EV25V
value|0x4000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_ISO_CTRL_PWC_EV12V
value|0x8000
end_define

begin_comment
comment|/* Bits for R92C_SYS_FUNC_EN. */
end_comment

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_BBRSTB
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_BB_GLB_RST
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_USBA
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_UPLL
value|0x0008
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_USBD
value|0x0010
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_DIO_PCIE
value|0x0020
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_PCIEA
value|0x0040
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_PPLL
value|0x0080
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_PCIED
value|0x0100
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_DIOE
value|0x0200
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_CPUEN
value|0x0400
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_DCORE
value|0x0800
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_ELDR
value|0x1000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_DIO_RF
value|0x2000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_HWPDN
value|0x4000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_FUNC_EN_MREGEN
value|0x8000
end_define

begin_comment
comment|/* Bits for R92C_APS_FSMCO. */
end_comment

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PFM_LDALL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PFM_ALDN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PFM_LDKP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PFM_WOWL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PDN_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_PDN_PL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APFM_ONMAC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APFM_OFF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APFM_RSM
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_AFSM_HSUS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_AFSM_PCIE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APDM_MAC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APDM_HOST
value|0x00004000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_APDM_HPDN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_RDY_MACON
value|0x00010000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SUS_HOST
value|0x00020000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_ROP_ALD
value|0x00100000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_ROP_PWR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_ROP_SPS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_MRST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_FUSE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_ABG
value|0x08000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_AMB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_RCK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_SOP_A8M
value|0x40000000
end_define

begin_define
define|#
directive|define
name|R92C_APS_FSMCO_XOP_BTCK
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92C_SYS_CLKR. */
end_comment

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_ANAD16V_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_ANA8M
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_MACSLP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_LOADER_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_80M_SSC_DIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_80M_SSC_EN_HO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_PHY_SSC_RSTB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_SEC_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_MAC_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_SYS_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CLKR_RING_EN
value|0x00002000
end_define

begin_comment
comment|/* Bits for R92C_RF_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_RF_CTRL_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_RF_CTRL_RSTB
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_RF_CTRL_SDMRSTB
value|0x04
end_define

begin_comment
comment|/* Bits for R92C_LDOA15_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_LDOA15_CTRL_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_LDOA15_CTRL_STBY
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_LDOA15_CTRL_OBUF
value|0x04
end_define

begin_define
define|#
directive|define
name|R92C_LDOA15_CTRL_REG_VOS
value|0x08
end_define

begin_comment
comment|/* Bits for R92C_LDOV12D_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_LDOV12D_CTRL_LDV12_EN
value|0x01
end_define

begin_comment
comment|/* Bits for R92C_LPLDO_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_LPLDO_CTRL_SLEEP
value|0x10
end_define

begin_comment
comment|/* Bits for R92C_AFE_XTAL_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_AFE_XTAL_CTRL_ADDR_M
value|0x007ff800
end_define

begin_define
define|#
directive|define
name|R92C_AFE_XTAL_CTRL_ADDR_S
value|11
end_define

begin_comment
comment|/* Bits for R92C_AFE_PLL_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_320_EN
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_FREF_SEL
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_EDGE_SEL
value|0x0008
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_WDOGB
value|0x0010
end_define

begin_define
define|#
directive|define
name|R92C_AFE_PLL_CTRL_LPFEN
value|0x0020
end_define

begin_comment
comment|/* Bits for R92C_EFUSE_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL_DATA_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL_DATA_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL_ADDR_M
value|0x0003ff00
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL_ADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_CTRL_VALID
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92C_GPIO_MUXCFG. */
end_comment

begin_define
define|#
directive|define
name|R92C_GPIO_MUXCFG_ENBT
value|0x0020
end_define

begin_comment
comment|/* Bits for R92C_LEDCFG0. */
end_comment

begin_define
define|#
directive|define
name|R92C_LEDCFG0_DIS
value|0x08
end_define

begin_comment
comment|/* Bits for R92C_MULTI_FUNC_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_MULTI_BT_FUNC_EN
value|0x00040000
end_define

begin_comment
comment|/* Bits for R92C_MCUFWDL. */
end_comment

begin_define
define|#
directive|define
name|R92C_MCUFWDL_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_RDY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_CHKSUM_RPT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_MACINI_RDY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_BBINI_RDY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_RFINI_RDY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_WINTINI_RDY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_RAM_DL_SEL
value|0x00000080
end_define

begin_comment
comment|/* 1: RAM, 0: ROM */
end_comment

begin_define
define|#
directive|define
name|R92C_MCUFWDL_PAGE_M
value|0x00070000
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_PAGE_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_ROM_DLEN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|R92C_MCUFWDL_CPRST
value|0x00800000
end_define

begin_comment
comment|/* Bits for R92C_EFUSE_ACCESS. */
end_comment

begin_define
define|#
directive|define
name|R92C_EFUSE_ACCESS_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_ACCESS_ON
value|0x69
end_define

begin_comment
comment|/* Bits for R92C_HPON_FSM. */
end_comment

begin_define
define|#
directive|define
name|R92C_HPON_FSM_CHIP_BONDING_ID_S
value|22
end_define

begin_define
define|#
directive|define
name|R92C_HPON_FSM_CHIP_BONDING_ID_M
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|R92C_HPON_FSM_CHIP_BONDING_ID_92C_1T2R
value|1
end_define

begin_comment
comment|/* Bits for R92C_SYS_CFG. */
end_comment

begin_define
define|#
directive|define
name|R92C_SYS_CFG_XCLK_VLD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_ACLK_VLD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_UCLK_VLD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_PCLK_VLD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_PCIRSTB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_V15_VLD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_TRP_B15V_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_SIC_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_BD_MAC2
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_BD_MAC1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_IC_MACPHY_MODE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_CHIP_VER_RTL_M
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_CHIP_VER_RTL_S
value|12
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_BT_FUNC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_VENDOR_UMC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_PAD_HWPD_IDN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_TRP_VAUX_EN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_TRP_BT_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_BD_PKG_SEL
value|0x02000000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_BD_HCI_SEL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|R92C_SYS_CFG_TYPE_92C
value|0x08000000
end_define

begin_comment
comment|/* Bits for R92C_CR. */
end_comment

begin_define
define|#
directive|define
name|R92C_CR_HCI_TXDMA_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92C_CR_HCI_RXDMA_EN
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_CR_TXDMA_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_CR_RXDMA_EN
value|0x0008
end_define

begin_define
define|#
directive|define
name|R92C_CR_PROTOCOL_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|R92C_CR_SCHEDULE_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|R92C_CR_MACTXEN
value|0x0040
end_define

begin_define
define|#
directive|define
name|R92C_CR_MACRXEN
value|0x0080
end_define

begin_define
define|#
directive|define
name|R92C_CR_ENSWBCN
value|0x0100
end_define

begin_define
define|#
directive|define
name|R92C_CR_ENSEC
value|0x0200
end_define

begin_define
define|#
directive|define
name|R92C_CR_CALTMR_EN
value|0x0400
end_define

begin_comment
comment|/* Bits for R92C_MSR. */
end_comment

begin_define
define|#
directive|define
name|R92C_MSR_NOLINK
value|0x00
end_define

begin_define
define|#
directive|define
name|R92C_MSR_ADHOC
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_MSR_INFRA
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_MSR_AP
value|0x03
end_define

begin_define
define|#
directive|define
name|R92C_MSR_MASK
value|(R92C_MSR_AP)
end_define

begin_comment
comment|/* Bits for R92C_PBP. */
end_comment

begin_define
define|#
directive|define
name|R92C_PBP_PSRX_M
value|0x0f
end_define

begin_define
define|#
directive|define
name|R92C_PBP_PSRX_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_PBP_PSTX_M
value|0xf0
end_define

begin_define
define|#
directive|define
name|R92C_PBP_PSTX_S
value|4
end_define

begin_define
define|#
directive|define
name|R92C_PBP_64
value|0
end_define

begin_define
define|#
directive|define
name|R92C_PBP_128
value|1
end_define

begin_define
define|#
directive|define
name|R92C_PBP_256
value|2
end_define

begin_define
define|#
directive|define
name|R92C_PBP_512
value|3
end_define

begin_define
define|#
directive|define
name|R92C_PBP_1024
value|4
end_define

begin_comment
comment|/* Bits for R92C_TRXDMA_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_RX_SHIFT_EN
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_RXDMA_AGG_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_VOQ_MAP_M
value|0x0030
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_VOQ_MAP_S
value|4
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_VIQ_MAP_M
value|0x00c0
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_VIQ_MAP_S
value|6
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_BEQ_MAP_M
value|0x0300
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_BEQ_MAP_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_BKQ_MAP_M
value|0x0c00
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_BKQ_MAP_S
value|10
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_MGQ_MAP_M
value|0x3000
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_MGQ_MAP_S
value|12
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_HIQ_MAP_M
value|0xc000
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_TXDMA_HIQ_MAP_S
value|14
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QUEUE_LOW
value|1
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QUEUE_NORMAL
value|2
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QUEUE_HIGH
value|3
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_M
value|0xfff0
end_define

begin_comment
comment|/* Shortcuts. */
end_comment

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_3EP
value|0xf5b0
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_HQ_LQ
value|0xf5f0
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_HQ_NQ
value|0xfaf0
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_LQ
value|0x5550
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_NQ
value|0xaaa0
end_define

begin_define
define|#
directive|define
name|R92C_TRXDMA_CTRL_QMAP_HQ
value|0xfff0
end_define

begin_comment
comment|/* Bits for R92C_C2H_EVT_CLEAR. */
end_comment

begin_define
define|#
directive|define
name|R92C_C2H_EVT_HOST_CLOSE
value|0x00
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_FW_CLOSE
value|0xff
end_define

begin_comment
comment|/* Bits for R92C_LLT_INIT. */
end_comment

begin_define
define|#
directive|define
name|R92C_LLT_INIT_DATA_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_DATA_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_ADDR_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_ADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_OP_M
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_OP_S
value|30
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_OP_NO_ACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|R92C_LLT_INIT_OP_WRITE
value|1
end_define

begin_comment
comment|/* Bits for R92C_RQPN. */
end_comment

begin_define
define|#
directive|define
name|R92C_RQPN_HPQ_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_HPQ_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_LPQ_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_LPQ_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_PUBQ_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_PUBQ_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_RQPN_LD
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92C_TDECTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_TDECTRL_BLK_DESC_NUM_M
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|R92C_TDECTRL_BLK_DESC_NUM_S
value|4
end_define

begin_define
define|#
directive|define
name|R92C_TDECTRL_BCN_VALID
value|0x00010000
end_define

begin_comment
comment|/* Bits for R92C_TXDMA_OFFSET_CHK. */
end_comment

begin_define
define|#
directive|define
name|R92C_TXDMA_OFFSET_DROP_DATA_EN
value|0x00000200
end_define

begin_comment
comment|/* Bits for R92C_FWHW_TXQ_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_FWHW_TXQ_CTRL_AMPDU_RTY_NEW
value|0x80
end_define

begin_define
define|#
directive|define
name|R92C_FWHW_TXQ_CTRL_REAL_BEACON
value|0x400000
end_define

begin_comment
comment|/* Bits for R92C_SPEC_SIFS. */
end_comment

begin_define
define|#
directive|define
name|R92C_SPEC_SIFS_CCK_M
value|0x00ff
end_define

begin_define
define|#
directive|define
name|R92C_SPEC_SIFS_CCK_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_SPEC_SIFS_OFDM_M
value|0xff00
end_define

begin_define
define|#
directive|define
name|R92C_SPEC_SIFS_OFDM_S
value|8
end_define

begin_comment
comment|/* Bits for R92C_RL. */
end_comment

begin_define
define|#
directive|define
name|R92C_RL_LRL_M
value|0x003f
end_define

begin_define
define|#
directive|define
name|R92C_RL_LRL_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_RL_SRL_M
value|0x3f00
end_define

begin_define
define|#
directive|define
name|R92C_RL_SRL_S
value|8
end_define

begin_comment
comment|/* Size of R92C_DARFRC. */
end_comment

begin_define
define|#
directive|define
name|R92C_DARFRC_SIZE
value|8
end_define

begin_comment
comment|/* Bits for R92C_RRSR. */
end_comment

begin_define
define|#
directive|define
name|R92C_RRSR_RATE_BITMAP_M
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_RATE_BITMAP_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_RATE_CCK_ONLY_1M
value|0xffff1
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_RATE_ALL
value|0xfffff
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_RSC_LOWSUBCHNL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_RSC_UPSUBCHNL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R92C_RRSR_SHORT
value|0x00800000
end_define

begin_comment
comment|/* Bits for R92C_EDCA_XX_PARAM. */
end_comment

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_AIFS_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_AIFS_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_ECWMIN_M
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_ECWMIN_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_ECWMAX_M
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_ECWMAX_S
value|12
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_TXOP_M
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|R92C_EDCA_PARAM_TXOP_S
value|16
end_define

begin_comment
comment|/* Bits for R92C_HWSEQ_CTRL / R92C_TXPAUSE. */
end_comment

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_VO
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_VI
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_BE
value|0x04
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_BK
value|0x08
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_MGT
value|0x10
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_HIGH
value|0x20
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_BCN
value|0x40
end_define

begin_comment
comment|/* Shortcuts. */
end_comment

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_AC
define|\
value|(R92C_TX_QUEUE_VO | R92C_TX_QUEUE_VI |	\ 	 R92C_TX_QUEUE_BE | R92C_TX_QUEUE_BK)
end_define

begin_define
define|#
directive|define
name|R92C_TX_QUEUE_ALL
define|\
value|(R92C_TX_QUEUE_AC | R92C_TX_QUEUE_MGT |	\ 	 R92C_TX_QUEUE_HIGH | R92C_TX_QUEUE_BCN | 0x80)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* Bits for R92C_BCN_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_BCN_CTRL_EN_MBSSID
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_BCN_CTRL_TXBCN_RPT
value|0x04
end_define

begin_define
define|#
directive|define
name|R92C_BCN_CTRL_EN_BCN
value|0x08
end_define

begin_define
define|#
directive|define
name|R92C_BCN_CTRL_DIS_TSF_UDT0
value|0x10
end_define

begin_comment
comment|/* Bits for R92C_DUAL_TSF_RST. */
end_comment

begin_define
define|#
directive|define
name|R92C_DUAL_TSF_RESET
parameter_list|(
name|id
parameter_list|)
value|(0x01<< (id))
end_define

begin_define
define|#
directive|define
name|R92C_DUAL_TSF_RST_TXOK
value|0x20
end_define

begin_comment
comment|/* Bits for R92C_ACMHWCTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL_BE
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL_VI
value|0x04
end_define

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL_VO
value|0x08
end_define

begin_define
define|#
directive|define
name|R92C_ACMHWCTRL_ACM_MASK
value|0x0f
end_define

begin_comment
comment|/* Bits for R92C_APSD_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92C_APSD_CTRL_OFF
value|0x40
end_define

begin_define
define|#
directive|define
name|R92C_APSD_CTRL_OFF_STATUS
value|0x80
end_define

begin_comment
comment|/* Bits for R92C_BWOPMODE. */
end_comment

begin_define
define|#
directive|define
name|R92C_BWOPMODE_11J
value|0x01
end_define

begin_define
define|#
directive|define
name|R92C_BWOPMODE_5G
value|0x02
end_define

begin_define
define|#
directive|define
name|R92C_BWOPMODE_20MHZ
value|0x04
end_define

begin_comment
comment|/* Bits for R92C_TCR. */
end_comment

begin_define
define|#
directive|define
name|R92C_TCR_TSFRST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_TCR_DIS_GCLK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_TCR_PAD_SEL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R92C_TCR_PWR_ST
value|0x00000040
end_define

begin_define
define|#
directive|define
name|R92C_TCR_PWRBIT_OW_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|R92C_TCR_ACRC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R92C_TCR_CFENDFORM
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_TCR_ICV
value|0x00000400
end_define

begin_comment
comment|/* Bits for R92C_RCR. */
end_comment

begin_define
define|#
directive|define
name|R92C_RCR_AAP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_RCR_AM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R92C_RCR_AB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R92C_RCR_ADD3
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APWRMGT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R92C_RCR_CBSSID_DATA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|R92C_RCR_CBSSID_BCN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|R92C_RCR_ACRC32
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R92C_RCR_AICV
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_RCR_ADF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R92C_RCR_ACF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_AMF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_HTC_LOC_CTRL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_MFBEN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_LSIGEN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_ENMBID
value|0x01000000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APP_BA_SSN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APP_PHYSTS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APP_ICV
value|0x20000000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APP_MIC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|R92C_RCR_APPFCS
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92C_RX_DRVINFO_SZ. */
end_comment

begin_comment
comment|/* XXX other values will not work */
end_comment

begin_define
define|#
directive|define
name|R92C_RX_DRVINFO_SZ_DEF
value|((RTWN_PHY_STATUS_SIZE) / 8)
end_define

begin_comment
comment|/* Bits for R92C_WMAC_TRXPTCL_CTL. */
end_comment

begin_define
define|#
directive|define
name|R92C_WMAC_TRXPTCL_SHPRE
value|0x00020000
end_define

begin_comment
comment|/* Bits for R92C_CAMCMD. */
end_comment

begin_define
define|#
directive|define
name|R92C_CAMCMD_ADDR_M
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|R92C_CAMCMD_ADDR_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_CAMCMD_WRITE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|R92C_CAMCMD_CLR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|R92C_CAMCMD_POLLING
value|0x80000000
end_define

begin_comment
comment|/*  * CAM entries.  */
end_comment

begin_define
define|#
directive|define
name|R92C_CAM_CTL0
parameter_list|(
name|entry
parameter_list|)
value|((entry) * 8 + 0)
end_define

begin_define
define|#
directive|define
name|R92C_CAM_CTL1
parameter_list|(
name|entry
parameter_list|)
value|((entry) * 8 + 1)
end_define

begin_define
define|#
directive|define
name|R92C_CAM_KEY
parameter_list|(
name|entry
parameter_list|,
name|i
parameter_list|)
value|((entry) * 8 + 2 + (i))
end_define

begin_define
define|#
directive|define
name|R92C_CAM_CTL6
parameter_list|(
name|entry
parameter_list|)
value|((entry) * 8 + 6)
end_define

begin_define
define|#
directive|define
name|R92C_CAM_CTL7
parameter_list|(
name|entry
parameter_list|)
value|((entry) * 8 + 7)
end_define

begin_comment
comment|/* Bits for R92C_CAM_CTL0(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_CAM_KEYID_M
value|0x00000003
end_define

begin_define
define|#
directive|define
name|R92C_CAM_KEYID_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_M
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_S
value|2
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_WEP40
value|1
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_TKIP
value|2
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_AES
value|4
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ALGO_WEP104
value|5
end_define

begin_define
define|#
directive|define
name|R92C_CAM_VALID
value|0x00008000
end_define

begin_define
define|#
directive|define
name|R92C_CAM_MACLO_M
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|R92C_CAM_MACLO_S
value|16
end_define

begin_comment
comment|/* Bits for R92C_SECCFG. */
end_comment

begin_define
define|#
directive|define
name|R92C_SECCFG_TXUCKEY_DEF
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_RXUCKEY_DEF
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_TXENC_ENA
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_RXDEC_ENA
value|0x0008
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_CMP_A2
value|0x0010
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_MC_SRCH_DIS
value|0x0020
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_TXBCKEY_DEF
value|0x0040
end_define

begin_define
define|#
directive|define
name|R92C_SECCFG_RXBCKEY_DEF
value|0x0080
end_define

begin_comment
comment|/* Bits for R92C_RXFLTMAP*. */
end_comment

begin_define
define|#
directive|define
name|R92C_RXFLTMAP_SUBTYPE
parameter_list|(
name|subtype
parameter_list|)
define|\
value|(1<< ((subtype)>> IEEE80211_FC0_SUBTYPE_SHIFT))
end_define

begin_comment
comment|/*  * Baseband registers.  */
end_comment

begin_define
define|#
directive|define
name|R92C_FPGA0_RFMOD
value|0x800
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_TXINFO
value|0x804
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM1
parameter_list|(
name|chain
parameter_list|)
value|(0x820 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2
parameter_list|(
name|chain
parameter_list|)
value|(0x824 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE18_06
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe00 : 0x830)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE54_24
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe04 : 0x834)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK1_MCS32
value|0xe08
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK1_55_MCS32
value|0x838
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK11_A_CCK2_11
value|0x86c
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS03_MCS00
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe10 : 0x83c)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS07_MCS04
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe14 : 0x848)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS11_MCS08
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe18 : 0x84c)
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS15_MCS12
parameter_list|(
name|i
parameter_list|)
value|(((i) == 0) ? 0xe1c : 0x868)
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_PARAM
parameter_list|(
name|chain
parameter_list|)
value|(0x840 + (chain) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_RFIFACEOE
parameter_list|(
name|chain
parameter_list|)
value|(0x860 + (chain) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_RFIFACESW
parameter_list|(
name|idx
parameter_list|)
value|(0x870 + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_RFPARAM
parameter_list|(
name|idx
parameter_list|)
value|(0x878 + (idx) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_ANAPARAM2
value|0x884
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_READBACK
parameter_list|(
name|chain
parameter_list|)
value|(0x8a0 + (chain) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_HSPI_READBACK
parameter_list|(
name|chain
parameter_list|)
value|(0x8b8 + (chain) * 4)
end_define

begin_define
define|#
directive|define
name|R92C_FPGA1_RFMOD
value|0x900
end_define

begin_define
define|#
directive|define
name|R92C_FPGA1_TXINFO
value|0x90c
end_define

begin_define
define|#
directive|define
name|R92C_CCK0_SYSTEM
value|0xa00
end_define

begin_define
define|#
directive|define
name|R92C_CCK0_AFESETTING
value|0xa04
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_TRXPATHENA
value|0xc04
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_TRMUXPAR
value|0xc08
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_RXIQIMBALANCE
parameter_list|(
name|chain
parameter_list|)
value|(0xc14 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_ECCATHRESHOLD
value|0xc4c
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_AGCCORE1
parameter_list|(
name|chain
parameter_list|)
value|(0xc50 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_AGCPARAM1
value|0xc70
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_AGCRSSITABLE
value|0xc78
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_TXIQIMBALANCE
parameter_list|(
name|chain
parameter_list|)
value|(0xc80 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_TXAFE
parameter_list|(
name|chain
parameter_list|)
value|(0xc94 + (chain) * 8)
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_RXIQEXTANTA
value|0xca0
end_define

begin_define
define|#
directive|define
name|R92C_OFDM1_LSTF
value|0xd00
end_define

begin_comment
comment|/* Bits for R92C_FPGA[01]_RFMOD. */
end_comment

begin_define
define|#
directive|define
name|R92C_RFMOD_40MHZ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R92C_RFMOD_JAPAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R92C_RFMOD_CCK_TXSC
value|0x00000030
end_define

begin_define
define|#
directive|define
name|R92C_RFMOD_CCK_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|R92C_RFMOD_OFDM_EN
value|0x02000000
end_define

begin_comment
comment|/* Bits for R92C_HSSI_PARAM1(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM1_PI
value|0x00000100
end_define

begin_comment
comment|/* Bits for R92C_HSSI_PARAM2(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_CCK_HIPWR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_ADDR_LENGTH
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_DATA_LENGTH
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_READ_ADDR_M
value|0x7f800000
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_READ_ADDR_S
value|23
end_define

begin_define
define|#
directive|define
name|R92C_HSSI_PARAM2_READ_EDGE
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_A_CCK1_MCS32. */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK1_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK1_S
value|8
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_B_CCK11_A_CCK2_11. */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK11_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK11_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK2_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK2_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK55_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK55_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK11_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_A_CCK11_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_B_CCK1_55_MCS32. */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK1_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK1_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK2_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK2_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK55_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_B_CCK55_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_RATE18_06(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE06_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE06_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE09_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE09_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE12_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE12_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE18_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE18_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_RATE54_24(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE24_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE24_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE36_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE36_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE48_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE48_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE54_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_RATE54_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_MCS03_MCS00(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS00_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS00_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS01_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS01_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS02_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS02_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS03_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS03_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_MCS07_MCS04(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS04_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS04_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS05_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS05_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS06_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS06_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS07_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS07_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_MCS11_MCS08(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS08_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS08_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS09_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS09_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS10_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS10_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS11_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS11_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_TXAGC_MCS15_MCS12(x). */
end_comment

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS12_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS12_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS13_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS13_S
value|8
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS14_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS14_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS15_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92C_TXAGC_MCS15_S
value|24
end_define

begin_comment
comment|/* Bits for R92C_LSSI_PARAM(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_LSSI_PARAM_DATA_M
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_PARAM_DATA_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_PARAM_ADDR_M
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_PARAM_ADDR_S
value|20
end_define

begin_comment
comment|/* Bits for R92C_FPGA0_RFIFACEOE(0). */
end_comment

begin_define
define|#
directive|define
name|R92C_FPGA0_RFIFACEOE0_ANT_M
value|0x00000300
end_define

begin_define
define|#
directive|define
name|R92C_FPGA0_RFIFACEOE0_ANT_S
value|8
end_define

begin_comment
comment|/* Bits for R92C_FPGA0_ANAPARAM2. */
end_comment

begin_define
define|#
directive|define
name|R92C_FPGA0_ANAPARAM2_CBW20
value|0x00000400
end_define

begin_comment
comment|/* Bits for R92C_LSSI_READBACK(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_LSSI_READBACK_DATA_M
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|R92C_LSSI_READBACK_DATA_S
value|0
end_define

begin_comment
comment|/* Bits for R92C_OFDM0_AGCCORE1(i). */
end_comment

begin_define
define|#
directive|define
name|R92C_OFDM0_AGCCORE1_GAIN_M
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|R92C_OFDM0_AGCCORE1_GAIN_S
value|0
end_define

begin_comment
comment|/*  * RF (6052) registers.  */
end_comment

begin_define
define|#
directive|define
name|R92C_RF_AC
value|0x00
end_define

begin_define
define|#
directive|define
name|R92C_RF_IQADJ_G
parameter_list|(
name|i
parameter_list|)
value|(0x01 + (i))
end_define

begin_define
define|#
directive|define
name|R92C_RF_POW_TRSW
value|0x05
end_define

begin_define
define|#
directive|define
name|R92C_RF_GAIN_RX
value|0x06
end_define

begin_define
define|#
directive|define
name|R92C_RF_GAIN_TX
value|0x07
end_define

begin_define
define|#
directive|define
name|R92C_RF_TXM_IDAC
value|0x08
end_define

begin_define
define|#
directive|define
name|R92C_RF_BS_IQGEN
value|0x0f
end_define

begin_define
define|#
directive|define
name|R92C_RF_MODE1
value|0x10
end_define

begin_define
define|#
directive|define
name|R92C_RF_MODE2
value|0x11
end_define

begin_define
define|#
directive|define
name|R92C_RF_RX_AGC_HP
value|0x12
end_define

begin_define
define|#
directive|define
name|R92C_RF_TX_AGC
value|0x13
end_define

begin_define
define|#
directive|define
name|R92C_RF_BIAS
value|0x14
end_define

begin_define
define|#
directive|define
name|R92C_RF_IPA
value|0x15
end_define

begin_define
define|#
directive|define
name|R92C_RF_POW_ABILITY
value|0x17
end_define

begin_define
define|#
directive|define
name|R92C_RF_CHNLBW
value|0x18
end_define

begin_define
define|#
directive|define
name|R92C_RF_RX_G1
value|0x1a
end_define

begin_define
define|#
directive|define
name|R92C_RF_RX_G2
value|0x1b
end_define

begin_define
define|#
directive|define
name|R92C_RF_RX_BB2
value|0x1c
end_define

begin_define
define|#
directive|define
name|R92C_RF_RX_BB1
value|0x1d
end_define

begin_define
define|#
directive|define
name|R92C_RF_RCK1
value|0x1e
end_define

begin_define
define|#
directive|define
name|R92C_RF_RCK2
value|0x1f
end_define

begin_define
define|#
directive|define
name|R92C_RF_TX_G
parameter_list|(
name|i
parameter_list|)
value|(0x20 + (i))
end_define

begin_define
define|#
directive|define
name|R92C_RF_TX_BB1
value|0x23
end_define

begin_define
define|#
directive|define
name|R92C_RF_T_METER
value|0x24
end_define

begin_define
define|#
directive|define
name|R92C_RF_SYN_G
parameter_list|(
name|i
parameter_list|)
value|(0x25 + (i))
end_define

begin_define
define|#
directive|define
name|R92C_RF_RCK_OS
value|0x30
end_define

begin_define
define|#
directive|define
name|R92C_RF_TXPA_G
parameter_list|(
name|i
parameter_list|)
value|(0x31 + (i))
end_define

begin_comment
comment|/* Bits for R92C_RF_AC. */
end_comment

begin_define
define|#
directive|define
name|R92C_RF_AC_MODE_M
value|0x70000
end_define

begin_define
define|#
directive|define
name|R92C_RF_AC_MODE_S
value|16
end_define

begin_define
define|#
directive|define
name|R92C_RF_AC_MODE_STANDBY
value|1
end_define

begin_comment
comment|/* Bits for R92C_RF_CHNLBW. */
end_comment

begin_define
define|#
directive|define
name|R92C_RF_CHNLBW_CHNL_M
value|0x003ff
end_define

begin_define
define|#
directive|define
name|R92C_RF_CHNLBW_CHNL_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_RF_CHNLBW_BW20
value|0x00400
end_define

begin_define
define|#
directive|define
name|R92C_RF_CHNLBW_LCSTART
value|0x08000
end_define

begin_comment
comment|/* Bits for R92C_RF_T_METER. */
end_comment

begin_define
define|#
directive|define
name|R92C_RF_T_METER_START
value|0x60
end_define

begin_define
define|#
directive|define
name|R92C_RF_T_METER_VAL_M
value|0x1f
end_define

begin_define
define|#
directive|define
name|R92C_RF_T_METER_VAL_S
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R92C_REG_H */
end_comment

end_unit

