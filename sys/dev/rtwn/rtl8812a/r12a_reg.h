begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R12A_REG_H
end_ifndef

begin_define
define|#
directive|define
name|R12A_REG_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/r88e_reg.h>
end_include

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_comment
comment|/* System Configuration. */
end_comment

begin_define
define|#
directive|define
name|R12A_SDIO_CTRL
value|0x070
end_define

begin_define
define|#
directive|define
name|R12A_RF_B_CTRL
value|0x076
end_define

begin_comment
comment|/* Rx DMA Configuration. */
end_comment

begin_define
define|#
directive|define
name|R12A_RXDMA_PRO
value|0x290
end_define

begin_define
define|#
directive|define
name|R12A_EARLY_MODE_CONTROL
value|0x2bc
end_define

begin_comment
comment|/* Protocol Configuration. */
end_comment

begin_define
define|#
directive|define
name|R12A_TXPKT_EMPTY
value|0x41a
end_define

begin_define
define|#
directive|define
name|R12A_ARFR_5G
parameter_list|(
name|i
parameter_list|)
value|(0x444 + (i) * 8)
end_define

begin_define
define|#
directive|define
name|R12A_CCK_CHECK
value|0x454
end_define

begin_define
define|#
directive|define
name|R12A_AMPDU_MAX_TIME
value|0x456
end_define

begin_define
define|#
directive|define
name|R12A_AMPDU_MAX_LENGTH
value|R92C_AGGLEN_LMT
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC
value|0x483
end_define

begin_define
define|#
directive|define
name|R12A_ARFR_2G
parameter_list|(
name|i
parameter_list|)
value|(0x48c + (i) * 8)
end_define

begin_define
define|#
directive|define
name|R12A_HT_SINGLE_AMPDU
value|0x4c7
end_define

begin_comment
comment|/* Bits for R92C_MAC_PHY_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R12A_MAC_PHY_CRYSTALCAP_M
value|0x7ff80000
end_define

begin_define
define|#
directive|define
name|R12A_MAC_PHY_CRYSTALCAP_S
value|19
end_define

begin_comment
comment|/* Bits for R92C_LEDCFG2. */
end_comment

begin_define
define|#
directive|define
name|R12A_LEDCFG2_ENA
value|0x20
end_define

begin_comment
comment|/* Bits for R12A_CCK_CHECK. */
end_comment

begin_define
define|#
directive|define
name|R12A_CCK_CHECK_BCN1
value|0x20
end_define

begin_define
define|#
directive|define
name|R12A_CCK_CHECK_5GHZ
value|0x80
end_define

begin_comment
comment|/* Bits for R12A_DATA_SEC. */
end_comment

begin_define
define|#
directive|define
name|R12A_DATA_SEC_NO_EXT
value|0x00
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_UP_20
value|0x01
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_DOWN_20
value|0x02
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_UPPER_20
value|0x03
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_LOWER_20
value|0x04
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_UP_40
value|0x90
end_define

begin_define
define|#
directive|define
name|R12A_DATA_SEC_PRIM_DOWN_40
value|0xa0
end_define

begin_comment
comment|/* Bits for R12A_HT_SINGLE_AMPDU. */
end_comment

begin_define
define|#
directive|define
name|R12A_HT_SINGLE_AMPDU_PKT_ENA
value|0x80
end_define

begin_comment
comment|/* Bits for R92C_RCR. */
end_comment

begin_define
define|#
directive|define
name|R12A_RCR_DIS_CHK_14
value|0x00200000
end_define

begin_define
define|#
directive|define
name|R12A_RCR_TCP_OFFLD_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|R12A_RCR_VHT_ACK
value|0x04000000
end_define

begin_comment
comment|/*  * Baseband registers.  */
end_comment

begin_define
define|#
directive|define
name|R12A_CCK_RPT_FORMAT
value|0x804
end_define

begin_define
define|#
directive|define
name|R12A_OFDMCCK_EN
value|0x808
end_define

begin_define
define|#
directive|define
name|R12A_RX_PATH
value|R12A_OFDMCCK_EN
end_define

begin_define
define|#
directive|define
name|R12A_TX_PATH
value|0x80c
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_TABLE_SELECT
value|0x82c
end_define

begin_define
define|#
directive|define
name|R12A_PWED_TH
value|0x830
end_define

begin_define
define|#
directive|define
name|R12A_BW_INDICATION
value|0x834
end_define

begin_define
define|#
directive|define
name|R12A_CCA_ON_SEC
value|0x838
end_define

begin_define
define|#
directive|define
name|R12A_L1_PEAK_TH
value|0x848
end_define

begin_define
define|#
directive|define
name|R12A_FC_AREA
value|0x860
end_define

begin_define
define|#
directive|define
name|R12A_RFMOD
value|0x8ac
end_define

begin_define
define|#
directive|define
name|R12A_HSSI_PARAM2
value|0x8b0
end_define

begin_define
define|#
directive|define
name|R12A_ADC_BUF_CLK
value|0x8c4
end_define

begin_define
define|#
directive|define
name|R12A_ANTSEL_SW
value|0x900
end_define

begin_define
define|#
directive|define
name|R12A_SINGLETONE_CONT_TX
value|0x914
end_define

begin_define
define|#
directive|define
name|R12A_CCK_RX_PATH
value|0xa04
end_define

begin_define
define|#
directive|define
name|R12A_HSSI_PARAM1
parameter_list|(
name|chain
parameter_list|)
value|(0xc00 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TX_SCALE
parameter_list|(
name|chain
parameter_list|)
value|(0xc1c + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK11_1
parameter_list|(
name|chain
parameter_list|)
value|(0xc20 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM18_6
parameter_list|(
name|chain
parameter_list|)
value|(0xc24 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM54_24
parameter_list|(
name|chain
parameter_list|)
value|(0xc28 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS3_0
parameter_list|(
name|chain
parameter_list|)
value|(0xc2c + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS7_4
parameter_list|(
name|chain
parameter_list|)
value|(0xc30 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS11_8
parameter_list|(
name|chain
parameter_list|)
value|(0xc34 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS15_12
parameter_list|(
name|chain
parameter_list|)
value|(0xc38 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_NSS1IX3_1IX0
parameter_list|(
name|chain
parameter_list|)
value|(0xc3c + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_NSS1IX7_1IX4
parameter_list|(
name|chain
parameter_list|)
value|(0xc40 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_NSS2IX1_1IX8
parameter_list|(
name|chain
parameter_list|)
value|(0xc44 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_NSS2IX5_2IX2
parameter_list|(
name|chain
parameter_list|)
value|(0xc48 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_NSS2IX9_2IX6
parameter_list|(
name|chain
parameter_list|)
value|(0xc4c + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_INITIAL_GAIN
parameter_list|(
name|chain
parameter_list|)
value|(0xc50 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_AFE_POWER_1
parameter_list|(
name|chain
parameter_list|)
value|(0xc60 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_AFE_POWER_2
parameter_list|(
name|chain
parameter_list|)
value|(0xc64 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_SLEEP_NAV
parameter_list|(
name|chain
parameter_list|)
value|(0xc80 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_PMPD
parameter_list|(
name|chain
parameter_list|)
value|(0xc84 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_LSSI_PARAM
parameter_list|(
name|chain
parameter_list|)
value|(0xc90 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_RFE_PINMUX
parameter_list|(
name|chain
parameter_list|)
value|(0xcb0 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_RFE_INV
parameter_list|(
name|chain
parameter_list|)
value|(0xcb4 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_RFE
parameter_list|(
name|chain
parameter_list|)
value|(0xcb8 + (chain) * 0x200)
end_define

begin_define
define|#
directive|define
name|R12A_HSPI_READBACK
parameter_list|(
name|chain
parameter_list|)
value|(0xd04 + (chain) * 0x40)
end_define

begin_define
define|#
directive|define
name|R12A_LSSI_READBACK
parameter_list|(
name|chain
parameter_list|)
value|(0xd08 + (chain) * 0x40)
end_define

begin_comment
comment|/* Bits for R12A_CCK_RPT_FORMAT. */
end_comment

begin_define
define|#
directive|define
name|R12A_CCK_RPT_FORMAT_HIPWR
value|0x00010000
end_define

begin_comment
comment|/* Bits for R12A_OFDMCCK_EN. */
end_comment

begin_define
define|#
directive|define
name|R12A_OFDMCCK_EN_CCK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|R12A_OFDMCCK_EN_OFDM
value|0x20000000
end_define

begin_comment
comment|/* Bits for R12A_CCA_ON_SEC. */
end_comment

begin_define
define|#
directive|define
name|R12A_CCA_ON_SEC_EXT_CHAN_M
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|R12A_CCA_ON_SEC_EXT_CHAN_S
value|28
end_define

begin_comment
comment|/* Bits for R12A_RFE_PINMUX(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_RFE_PINMUX_PA_A_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|R12A_RFE_PINMUX_LNA_MASK
value|0x0000f000
end_define

begin_comment
comment|/* Bits for R12A_RFMOD. */
end_comment

begin_define
define|#
directive|define
name|R12A_RFMOD_EXT_CHAN_M
value|0x3C
end_define

begin_define
define|#
directive|define
name|R12A_RFMOD_EXT_CHAN_S
value|2
end_define

begin_comment
comment|/* Bits for R12A_HSSI_PARAM2. */
end_comment

begin_define
define|#
directive|define
name|R12A_HSSI_PARAM2_READ_ADDR_MASK
value|0xff
end_define

begin_comment
comment|/* Bits for R12A_HSSI_PARAM1(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_HSSI_PARAM1_PI
value|0x00000004
end_define

begin_comment
comment|/* Bits for R12A_TX_SCALE(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TX_SCALE_SWING_M
value|0xffe00000
end_define

begin_define
define|#
directive|define
name|R12A_TX_SCALE_SWING_S
value|21
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_CCK11_1(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK1_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK1_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK2_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK2_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK55_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK55_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK11_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_CCK11_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_OFDM18_6(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM06_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM06_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM09_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM09_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM12_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM12_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM18_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM18_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_OFDM54_24(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM24_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM24_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM36_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM36_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM48_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM48_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM54_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_OFDM54_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_MCS3_0(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS0_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS0_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS1_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS1_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS2_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS2_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS3_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS3_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_MCS7_4(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS4_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS4_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS5_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS5_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS6_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS6_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS7_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS7_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_MCS11_8(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS8_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS8_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS9_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS9_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS10_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS10_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS11_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS11_S
value|24
end_define

begin_comment
comment|/* Bits for R12A_TXAGC_MCS15_12(i). */
end_comment

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS12_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS12_S
value|0
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS13_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS13_S
value|8
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS14_M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS14_S
value|16
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS15_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R12A_TXAGC_MCS15_S
value|24
end_define

begin_comment
comment|/*  * RF (6052) registers.  */
end_comment

begin_define
define|#
directive|define
name|R12A_RF_LCK
value|0xb4
end_define

begin_comment
comment|/* Bits for R12A_RF_LCK. */
end_comment

begin_define
define|#
directive|define
name|R12A_RF_LCK_MODE
value|0x4000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R12A_REG_H */
end_comment

end_unit

