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
name|__IF_BWN_RADIO_2057_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_RADIO_2057_H__
end_define

begin_define
define|#
directive|define
name|R2057_DACBUF_VINCM_CORE0
value|0x000
end_define

begin_define
define|#
directive|define
name|R2057_IDCODE
value|0x001
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_MASTER
value|0x002
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_CAP_SIZE
value|0x003
end_define

begin_define
define|#
directive|define
name|R2057_RCAL_CONFIG
value|0x004
end_define

begin_define
define|#
directive|define
name|R2057_GPAIO_CONFIG
value|0x005
end_define

begin_define
define|#
directive|define
name|R2057_GPAIO_SEL1
value|0x006
end_define

begin_define
define|#
directive|define
name|R2057_GPAIO_SEL0
value|0x007
end_define

begin_define
define|#
directive|define
name|R2057_CLPO_CONFIG
value|0x008
end_define

begin_define
define|#
directive|define
name|R2057_BANDGAP_CONFIG
value|0x009
end_define

begin_define
define|#
directive|define
name|R2057_BANDGAP_RCAL_TRIM
value|0x00a
end_define

begin_define
define|#
directive|define
name|R2057_AFEREG_CONFIG
value|0x00b
end_define

begin_define
define|#
directive|define
name|R2057_TEMPSENSE_CONFIG
value|0x00c
end_define

begin_define
define|#
directive|define
name|R2057_XTAL_CONFIG1
value|0x00d
end_define

begin_define
define|#
directive|define
name|R2057_XTAL_ICORE_SIZE
value|0x00e
end_define

begin_define
define|#
directive|define
name|R2057_XTAL_BUF_SIZE
value|0x00f
end_define

begin_define
define|#
directive|define
name|R2057_XTAL_PULLCAP_SIZE
value|0x010
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_MASTER
value|0x011
end_define

begin_define
define|#
directive|define
name|R2057_VCOMONITOR_VTH_L
value|0x012
end_define

begin_define
define|#
directive|define
name|R2057_VCOMONITOR_VTH_H
value|0x013
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_BIASRESET_RFPLLREG_VOUT
value|0x014
end_define

begin_define
define|#
directive|define
name|R2057_VCO_VARCSIZE_IDAC
value|0x015
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_COUNTVAL0
value|0x016
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_COUNTVAL1
value|0x017
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_INTCLK_COUNT
value|0x018
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_MASTER
value|0x019
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_NUMCAPCHANGE
value|0x01a
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_WINSIZE
value|0x01b
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_DELAY_AFTER_REFRESH
value|0x01c
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_DELAY_AFTER_CLOSELOOP
value|0x01d
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_DELAY_AFTER_OPENLOOP
value|0x01e
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_DELAY_BEFORE_OPENLOOP
value|0x01f
end_define

begin_define
define|#
directive|define
name|R2057_VCO_FORCECAPEN_FORCECAP1
value|0x020
end_define

begin_define
define|#
directive|define
name|R2057_VCO_FORCECAP0
value|0x021
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_REFMASTER_SPAREXTALSIZE
value|0x022
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_PFD_RESET_PW
value|0x023
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_LOOPFILTER_R2
value|0x024
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_LOOPFILTER_R1
value|0x025
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_LOOPFILTER_C3
value|0x026
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_LOOPFILTER_C2
value|0x027
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_LOOPFILTER_C1
value|0x028
end_define

begin_define
define|#
directive|define
name|R2057_CP_KPD_IDAC
value|0x029
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_IDACS
value|0x02a
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_MISC_EN
value|0x02b
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_MMD0
value|0x02c
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_MMD1
value|0x02d
end_define

begin_define
define|#
directive|define
name|R2057_RFPLL_MISC_CAL_RESETN
value|0x02e
end_define

begin_define
define|#
directive|define
name|R2057_JTAGXTAL_SIZE_CPBIAS_FILTRES
value|0x02f
end_define

begin_define
define|#
directive|define
name|R2057_VCO_ALCREF_BBPLLXTAL_SIZE
value|0x030
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_READCAP0
value|0x031
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_READCAP1
value|0x032
end_define

begin_define
define|#
directive|define
name|R2057_VCOCAL_STATUS
value|0x033
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_PUS
value|0x034
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_PTAT_RESETS
value|0x035
end_define

begin_define
define|#
directive|define
name|R2057_VCOBUF_IDACS
value|0x036
end_define

begin_define
define|#
directive|define
name|R2057_VCOBUF_TUNE
value|0x037
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_TX2GQ_IDACS
value|0x038
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_TX2GI_IDACS
value|0x039
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_TX5GQ_IDACS
value|0x03a
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_TX5GI_IDACS
value|0x03b
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_RX2GQ_IDACS
value|0x03c
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_RX2GI_IDACS
value|0x03d
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_RX5GQ_IDACS
value|0x03e
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_RX5GI_IDACS
value|0x03f
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_MX2G_IDACS
value|0x040
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_MX2G_TUNE
value|0x041
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_MX5G_IDACS
value|0x042
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_MX5G_TUNE
value|0x043
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_MX5G_RCCR
value|0x044
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF2G_IDAC
value|0x045
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF2G_IBOOST
value|0x046
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF2G_TUNE
value|0x047
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF5G_IDAC
value|0x048
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF5G_IBOOST
value|0x049
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_INDBUF5G_TUNE
value|0x04a
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_TX_RCCR
value|0x04b
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_RX_RCCR
value|0x04c
end_define

begin_define
define|#
directive|define
name|R2057_LOGEN_SEL_PKDET
value|0x04d
end_define

begin_define
define|#
directive|define
name|R2057_CMOSBUF_SHAREIQ_PTAT
value|0x04e
end_define

begin_comment
comment|/* MISC core 0 */
end_comment

begin_define
define|#
directive|define
name|R2057_RXTXBIAS_CONFIG_CORE0
value|0x04f
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_TXRF_PUS_CORE0
value|0x050
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_IDAC_BLEED_CORE0
value|0x051
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_GAIN_CORE0
value|0x056
end_define

begin_define
define|#
directive|define
name|R2057_TXGM2G_PKDET_PUS_CORE0
value|0x057
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_PTATS_CORE0
value|0x058
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_IDACS_CORE0
value|0x059
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_BOOST_PU_CORE0
value|0x05a
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_CASCV_GAIN_CORE0
value|0x05b
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX2G_TUNE_BOOST_PU_CORE0
value|0x05c
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX2G_LODC_CORE0
value|0x05d
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_TUNE_PUS_CORE0
value|0x05e
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_GAIN_CORE0
value|0x05f
end_define

begin_define
define|#
directive|define
name|R2057_TSSI2G_SPARE1_CORE0
value|0x060
end_define

begin_define
define|#
directive|define
name|R2057_TSSI2G_SPARE2_CORE0
value|0x061
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_TUNEV_CASCV_PTAT_CORE0
value|0x062
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_IMAIN_CORE0
value|0x063
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_CASCONV_CORE0
value|0x064
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_CASCOFFV_CORE0
value|0x065
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_BIAS_FILTER_CORE0
value|0x066
end_define

begin_define
define|#
directive|define
name|R2057_TX5G_PKDET_CORE0
value|0x069
end_define

begin_define
define|#
directive|define
name|R2057_PGA_PTAT_TXGM5G_PU_CORE0
value|0x06a
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_PTATS1_CORE0
value|0x06b
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CLASS_PTATS2_CORE0
value|0x06c
end_define

begin_define
define|#
directive|define
name|R2057_PGA_BOOSTPTAT_IMAIN_CORE0
value|0x06d
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CASCV_IMAIN_CORE0
value|0x06e
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX5G_IBOOST_PAD_IAUX_CORE0
value|0x06f
end_define

begin_define
define|#
directive|define
name|R2057_PGA_BOOST_TUNE_CORE0
value|0x070
end_define

begin_define
define|#
directive|define
name|R2057_PGA_GAIN_CORE0
value|0x071
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CASCOFFV_GAIN_PUS_CORE0
value|0x072
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX5G_BOOST_TUNE_CORE0
value|0x073
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_TUNE_MISC_PUS_CORE0
value|0x074
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_IAUX_CORE0
value|0x075
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_GAIN_CORE0
value|0x076
end_define

begin_define
define|#
directive|define
name|R2057_TSSI5G_SPARE1_CORE0
value|0x077
end_define

begin_define
define|#
directive|define
name|R2057_TSSI5G_SPARE2_CORE0
value|0x078
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_CASCOFFV_PU_CORE0
value|0x079
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_PTAT_CORE0
value|0x07a
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_IMAIN_CORE0
value|0x07b
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_CASCONV_CORE0
value|0x07c
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_BIAS_FILTER_CORE0
value|0x07d
end_define

begin_define
define|#
directive|define
name|R2057_PAD_BIAS_FILTER_BWS_CORE0
value|0x080
end_define

begin_define
define|#
directive|define
name|R2057_TR2G_CONFIG1_CORE0_NU
value|0x081
end_define

begin_define
define|#
directive|define
name|R2057_TR2G_CONFIG2_CORE0_NU
value|0x082
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_RFEN_CORE0
value|0x083
end_define

begin_define
define|#
directive|define
name|R2057_TR5G_CONFIG2_CORE0_NU
value|0x084
end_define

begin_define
define|#
directive|define
name|R2057_RXRFBIAS_IBOOST_PU_CORE0
value|0x085
end_define

begin_define
define|#
directive|define
name|R2057_RXRF_IABAND_RXGM_IMAIN_PTAT_CORE0
value|0x086
end_define

begin_define
define|#
directive|define
name|R2057_RXGM_CMFBITAIL_AUXPTAT_CORE0
value|0x087
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX_ICORE_RXGM_IAUX_CORE0
value|0x088
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX_CMFBITAIL_PU_CORE0
value|0x089
end_define

begin_define
define|#
directive|define
name|R2057_LNA2_IMAIN_PTAT_PU_CORE0
value|0x08a
end_define

begin_define
define|#
directive|define
name|R2057_LNA2_IAUX_PTAT_CORE0
value|0x08b
end_define

begin_define
define|#
directive|define
name|R2057_LNA1_IMAIN_PTAT_PU_CORE0
value|0x08c
end_define

begin_define
define|#
directive|define
name|R2057_LNA15G_INPUT_MATCH_TUNE_CORE0
value|0x08d
end_define

begin_define
define|#
directive|define
name|R2057_RXRFBIAS_BANDSEL_CORE0
value|0x08e
end_define

begin_define
define|#
directive|define
name|R2057_TIA_CONFIG_CORE0
value|0x08f
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IQGAIN_CORE0
value|0x090
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IBIAS2_CORE0
value|0x091
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IBIAS1_CORE0
value|0x092
end_define

begin_define
define|#
directive|define
name|R2057_TIA_SPARE_Q_CORE0
value|0x093
end_define

begin_define
define|#
directive|define
name|R2057_TIA_SPARE_I_CORE0
value|0x094
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_PUS_CORE0
value|0x095
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_VCMREFS_CORE0
value|0x096
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_LODC_QI_CORE0
value|0x097
end_define

begin_define
define|#
directive|define
name|R2057_W12G_BW_LNA2G_PUS_CORE0
value|0x098
end_define

begin_define
define|#
directive|define
name|R2057_LNA2G_GAIN_CORE0
value|0x099
end_define

begin_define
define|#
directive|define
name|R2057_LNA2G_TUNE_CORE0
value|0x09a
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_PUS_CORE0
value|0x09b
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_VCMREFS_CORE0
value|0x09c
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_LODC_QI_CORE0
value|0x09d
end_define

begin_define
define|#
directive|define
name|R2057_W15G_BW_LNA5G_PUS_CORE0
value|0x09e
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_GAIN_CORE0
value|0x09f
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_TUNE_CORE0
value|0x0a0
end_define

begin_define
define|#
directive|define
name|R2057_LPFSEL_TXRX_RXBB_PUS_CORE0
value|0x0a1
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_BIAS_MASTER_CORE0
value|0x0a2
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_VGABUF_IDACS_CORE0
value|0x0a3
end_define

begin_define
define|#
directive|define
name|R2057_LPF_VCMREF_TXBUF_VCMREF_CORE0
value|0x0a4
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_VINCM_CORE0
value|0x0a5
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_IDACS_CORE0
value|0x0a6
end_define

begin_define
define|#
directive|define
name|R2057_LPF_RESP_RXBUF_BW_CORE0
value|0x0a7
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_CC_CORE0
value|0x0a8
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE3_CORE0
value|0x0a9
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_RCCAL_HPC_CORE0
value|0x0aa
end_define

begin_define
define|#
directive|define
name|R2057_LPF_IDACS_CORE0
value|0x0ab
end_define

begin_define
define|#
directive|define
name|R2057_LPFBYP_DCLOOP_BYP_IDAC_CORE0
value|0x0ac
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_GAIN_CORE0
value|0x0ad
end_define

begin_define
define|#
directive|define
name|R2057_AFELOOPBACK_AACI_RESP_CORE0
value|0x0ae
end_define

begin_define
define|#
directive|define
name|R2057_RXBUF_DEGEN_CORE0
value|0x0af
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE2_CORE0
value|0x0b0
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE1_CORE0
value|0x0b1
end_define

begin_define
define|#
directive|define
name|R2057_RSSI_MASTER_CORE0
value|0x0b2
end_define

begin_define
define|#
directive|define
name|R2057_W2_MASTER_CORE0
value|0x0b3
end_define

begin_define
define|#
directive|define
name|R2057_NB_MASTER_CORE0
value|0x0b4
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS0_Q_CORE0
value|0x0b5
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS1_Q_CORE0
value|0x0b6
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS0_I_CORE0
value|0x0b7
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS1_I_CORE0
value|0x0b8
end_define

begin_define
define|#
directive|define
name|R2057_RSSI_GPAIOSEL_W1_IDACS_CORE0
value|0x0b9
end_define

begin_define
define|#
directive|define
name|R2057_NB_IDACS_Q_CORE0
value|0x0ba
end_define

begin_define
define|#
directive|define
name|R2057_NB_IDACS_I_CORE0
value|0x0bb
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP4_CORE0
value|0x0c1
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP3_CORE0
value|0x0c2
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP2_CORE0
value|0x0c3
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP1_CORE0
value|0x0c4
end_define

begin_define
define|#
directive|define
name|R2057_SPARE16_CORE0
value|0x0c5
end_define

begin_define
define|#
directive|define
name|R2057_SPARE15_CORE0
value|0x0c6
end_define

begin_define
define|#
directive|define
name|R2057_SPARE14_CORE0
value|0x0c7
end_define

begin_define
define|#
directive|define
name|R2057_SPARE13_CORE0
value|0x0c8
end_define

begin_define
define|#
directive|define
name|R2057_SPARE12_CORE0
value|0x0c9
end_define

begin_define
define|#
directive|define
name|R2057_SPARE11_CORE0
value|0x0ca
end_define

begin_define
define|#
directive|define
name|R2057_TX2G_BIAS_RESETS_CORE0
value|0x0cb
end_define

begin_define
define|#
directive|define
name|R2057_TX5G_BIAS_RESETS_CORE0
value|0x0cc
end_define

begin_define
define|#
directive|define
name|R2057_IQTEST_SEL_PU
value|0x0cd
end_define

begin_define
define|#
directive|define
name|R2057_XTAL_CONFIG2
value|0x0ce
end_define

begin_define
define|#
directive|define
name|R2057_BUFS_MISC_LPFBW_CORE0
value|0x0cf
end_define

begin_define
define|#
directive|define
name|R2057_TXLPF_RCCAL_CORE0
value|0x0d0
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_GPAIOSEL_RXLPF_RCCAL_CORE0
value|0x0d1
end_define

begin_define
define|#
directive|define
name|R2057_LPF_GAIN_CORE0
value|0x0d2
end_define

begin_define
define|#
directive|define
name|R2057_DACBUF_IDACS_BW_CORE0
value|0x0d3
end_define

begin_comment
comment|/* MISC core 1 */
end_comment

begin_define
define|#
directive|define
name|R2057_RXTXBIAS_CONFIG_CORE1
value|0x0d4
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_TXRF_PUS_CORE1
value|0x0d5
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_IDAC_BLEED_CORE1
value|0x0d6
end_define

begin_define
define|#
directive|define
name|R2057_TXGM_GAIN_CORE1
value|0x0db
end_define

begin_define
define|#
directive|define
name|R2057_TXGM2G_PKDET_PUS_CORE1
value|0x0dc
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_PTATS_CORE1
value|0x0dd
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_IDACS_CORE1
value|0x0de
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_BOOST_PU_CORE1
value|0x0df
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_CASCV_GAIN_CORE1
value|0x0e0
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX2G_TUNE_BOOST_PU_CORE1
value|0x0e1
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX2G_LODC_CORE1
value|0x0e2
end_define

begin_define
define|#
directive|define
name|R2057_PAD2G_TUNE_PUS_CORE1
value|0x0e3
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_GAIN_CORE1
value|0x0e4
end_define

begin_define
define|#
directive|define
name|R2057_TSSI2G_SPARE1_CORE1
value|0x0e5
end_define

begin_define
define|#
directive|define
name|R2057_TSSI2G_SPARE2_CORE1
value|0x0e6
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_TUNEV_CASCV_PTAT_CORE1
value|0x0e7
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_IMAIN_CORE1
value|0x0e8
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_CASCONV_CORE1
value|0x0e9
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_CASCOFFV_CORE1
value|0x0ea
end_define

begin_define
define|#
directive|define
name|R2057_IPA2G_BIAS_FILTER_CORE1
value|0x0eb
end_define

begin_define
define|#
directive|define
name|R2057_TX5G_PKDET_CORE1
value|0x0ee
end_define

begin_define
define|#
directive|define
name|R2057_PGA_PTAT_TXGM5G_PU_CORE1
value|0x0ef
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_PTATS1_CORE1
value|0x0f0
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CLASS_PTATS2_CORE1
value|0x0f1
end_define

begin_define
define|#
directive|define
name|R2057_PGA_BOOSTPTAT_IMAIN_CORE1
value|0x0f2
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CASCV_IMAIN_CORE1
value|0x0f3
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX5G_IBOOST_PAD_IAUX_CORE1
value|0x0f4
end_define

begin_define
define|#
directive|define
name|R2057_PGA_BOOST_TUNE_CORE1
value|0x0f5
end_define

begin_define
define|#
directive|define
name|R2057_PGA_GAIN_CORE1
value|0x0f6
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_CASCOFFV_GAIN_PUS_CORE1
value|0x0f7
end_define

begin_define
define|#
directive|define
name|R2057_TXMIX5G_BOOST_TUNE_CORE1
value|0x0f8
end_define

begin_define
define|#
directive|define
name|R2057_PAD5G_TUNE_MISC_PUS_CORE1
value|0x0f9
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_IAUX_CORE1
value|0x0fa
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_GAIN_CORE1
value|0x0fb
end_define

begin_define
define|#
directive|define
name|R2057_TSSI5G_SPARE1_CORE1
value|0x0fc
end_define

begin_define
define|#
directive|define
name|R2057_TSSI5G_SPARE2_CORE1
value|0x0fd
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_CASCOFFV_PU_CORE1
value|0x0fe
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_PTAT_CORE1
value|0x0ff
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_IMAIN_CORE1
value|0x100
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_CASCONV_CORE1
value|0x101
end_define

begin_define
define|#
directive|define
name|R2057_IPA5G_BIAS_FILTER_CORE1
value|0x102
end_define

begin_define
define|#
directive|define
name|R2057_PAD_BIAS_FILTER_BWS_CORE1
value|0x105
end_define

begin_define
define|#
directive|define
name|R2057_TR2G_CONFIG1_CORE1_NU
value|0x106
end_define

begin_define
define|#
directive|define
name|R2057_TR2G_CONFIG2_CORE1_NU
value|0x107
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_RFEN_CORE1
value|0x108
end_define

begin_define
define|#
directive|define
name|R2057_TR5G_CONFIG2_CORE1_NU
value|0x109
end_define

begin_define
define|#
directive|define
name|R2057_RXRFBIAS_IBOOST_PU_CORE1
value|0x10a
end_define

begin_define
define|#
directive|define
name|R2057_RXRF_IABAND_RXGM_IMAIN_PTAT_CORE1
value|0x10b
end_define

begin_define
define|#
directive|define
name|R2057_RXGM_CMFBITAIL_AUXPTAT_CORE1
value|0x10c
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX_ICORE_RXGM_IAUX_CORE1
value|0x10d
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX_CMFBITAIL_PU_CORE1
value|0x10e
end_define

begin_define
define|#
directive|define
name|R2057_LNA2_IMAIN_PTAT_PU_CORE1
value|0x10f
end_define

begin_define
define|#
directive|define
name|R2057_LNA2_IAUX_PTAT_CORE1
value|0x110
end_define

begin_define
define|#
directive|define
name|R2057_LNA1_IMAIN_PTAT_PU_CORE1
value|0x111
end_define

begin_define
define|#
directive|define
name|R2057_LNA15G_INPUT_MATCH_TUNE_CORE1
value|0x112
end_define

begin_define
define|#
directive|define
name|R2057_RXRFBIAS_BANDSEL_CORE1
value|0x113
end_define

begin_define
define|#
directive|define
name|R2057_TIA_CONFIG_CORE1
value|0x114
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IQGAIN_CORE1
value|0x115
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IBIAS2_CORE1
value|0x116
end_define

begin_define
define|#
directive|define
name|R2057_TIA_IBIAS1_CORE1
value|0x117
end_define

begin_define
define|#
directive|define
name|R2057_TIA_SPARE_Q_CORE1
value|0x118
end_define

begin_define
define|#
directive|define
name|R2057_TIA_SPARE_I_CORE1
value|0x119
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_PUS_CORE1
value|0x11a
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_VCMREFS_CORE1
value|0x11b
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX2G_LODC_QI_CORE1
value|0x11c
end_define

begin_define
define|#
directive|define
name|R2057_W12G_BW_LNA2G_PUS_CORE1
value|0x11d
end_define

begin_define
define|#
directive|define
name|R2057_LNA2G_GAIN_CORE1
value|0x11e
end_define

begin_define
define|#
directive|define
name|R2057_LNA2G_TUNE_CORE1
value|0x11f
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_PUS_CORE1
value|0x120
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_VCMREFS_CORE1
value|0x121
end_define

begin_define
define|#
directive|define
name|R2057_RXMIX5G_LODC_QI_CORE1
value|0x122
end_define

begin_define
define|#
directive|define
name|R2057_W15G_BW_LNA5G_PUS_CORE1
value|0x123
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_GAIN_CORE1
value|0x124
end_define

begin_define
define|#
directive|define
name|R2057_LNA5G_TUNE_CORE1
value|0x125
end_define

begin_define
define|#
directive|define
name|R2057_LPFSEL_TXRX_RXBB_PUS_CORE1
value|0x126
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_BIAS_MASTER_CORE1
value|0x127
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_VGABUF_IDACS_CORE1
value|0x128
end_define

begin_define
define|#
directive|define
name|R2057_LPF_VCMREF_TXBUF_VCMREF_CORE1
value|0x129
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_VINCM_CORE1
value|0x12a
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_IDACS_CORE1
value|0x12b
end_define

begin_define
define|#
directive|define
name|R2057_LPF_RESP_RXBUF_BW_CORE1
value|0x12c
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_CC_CORE1
value|0x12d
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE3_CORE1
value|0x12e
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_RCCAL_HPC_CORE1
value|0x12f
end_define

begin_define
define|#
directive|define
name|R2057_LPF_IDACS_CORE1
value|0x130
end_define

begin_define
define|#
directive|define
name|R2057_LPFBYP_DCLOOP_BYP_IDAC_CORE1
value|0x131
end_define

begin_define
define|#
directive|define
name|R2057_TXBUF_GAIN_CORE1
value|0x132
end_define

begin_define
define|#
directive|define
name|R2057_AFELOOPBACK_AACI_RESP_CORE1
value|0x133
end_define

begin_define
define|#
directive|define
name|R2057_RXBUF_DEGEN_CORE1
value|0x134
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE2_CORE1
value|0x135
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_SPARE1_CORE1
value|0x136
end_define

begin_define
define|#
directive|define
name|R2057_RSSI_MASTER_CORE1
value|0x137
end_define

begin_define
define|#
directive|define
name|R2057_W2_MASTER_CORE1
value|0x138
end_define

begin_define
define|#
directive|define
name|R2057_NB_MASTER_CORE1
value|0x139
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS0_Q_CORE1
value|0x13a
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS1_Q_CORE1
value|0x13b
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS0_I_CORE1
value|0x13c
end_define

begin_define
define|#
directive|define
name|R2057_W2_IDACS1_I_CORE1
value|0x13d
end_define

begin_define
define|#
directive|define
name|R2057_RSSI_GPAIOSEL_W1_IDACS_CORE1
value|0x13e
end_define

begin_define
define|#
directive|define
name|R2057_NB_IDACS_Q_CORE1
value|0x13f
end_define

begin_define
define|#
directive|define
name|R2057_NB_IDACS_I_CORE1
value|0x140
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP4_CORE1
value|0x146
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP3_CORE1
value|0x147
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP2_CORE1
value|0x148
end_define

begin_define
define|#
directive|define
name|R2057_BACKUP1_CORE1
value|0x149
end_define

begin_define
define|#
directive|define
name|R2057_SPARE16_CORE1
value|0x14a
end_define

begin_define
define|#
directive|define
name|R2057_SPARE15_CORE1
value|0x14b
end_define

begin_define
define|#
directive|define
name|R2057_SPARE14_CORE1
value|0x14c
end_define

begin_define
define|#
directive|define
name|R2057_SPARE13_CORE1
value|0x14d
end_define

begin_define
define|#
directive|define
name|R2057_SPARE12_CORE1
value|0x14e
end_define

begin_define
define|#
directive|define
name|R2057_SPARE11_CORE1
value|0x14f
end_define

begin_define
define|#
directive|define
name|R2057_TX2G_BIAS_RESETS_CORE1
value|0x150
end_define

begin_define
define|#
directive|define
name|R2057_TX5G_BIAS_RESETS_CORE1
value|0x151
end_define

begin_define
define|#
directive|define
name|R2057_SPARE8_CORE1
value|0x152
end_define

begin_define
define|#
directive|define
name|R2057_SPARE7_CORE1
value|0x153
end_define

begin_define
define|#
directive|define
name|R2057_BUFS_MISC_LPFBW_CORE1
value|0x154
end_define

begin_define
define|#
directive|define
name|R2057_TXLPF_RCCAL_CORE1
value|0x155
end_define

begin_define
define|#
directive|define
name|R2057_RXBB_GPAIOSEL_RXLPF_RCCAL_CORE1
value|0x156
end_define

begin_define
define|#
directive|define
name|R2057_LPF_GAIN_CORE1
value|0x157
end_define

begin_define
define|#
directive|define
name|R2057_DACBUF_IDACS_BW_CORE1
value|0x158
end_define

begin_define
define|#
directive|define
name|R2057_DACBUF_VINCM_CORE1
value|0x159
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_START_R1_Q1_P1
value|0x15a
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_X1
value|0x15b
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_TRC0
value|0x15c
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_TRC1
value|0x15d
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_DONE_OSCCAP
value|0x15e
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_N0_0
value|0x15f
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_N0_1
value|0x160
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_N1_0
value|0x161
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_N1_1
value|0x162
end_define

begin_define
define|#
directive|define
name|R2057_RCAL_STATUS
value|0x163
end_define

begin_define
define|#
directive|define
name|R2057_XTALPUOVR_PINCTRL
value|0x164
end_define

begin_define
define|#
directive|define
name|R2057_OVR_REG0
value|0x165
end_define

begin_define
define|#
directive|define
name|R2057_OVR_REG1
value|0x166
end_define

begin_define
define|#
directive|define
name|R2057_OVR_REG2
value|0x167
end_define

begin_define
define|#
directive|define
name|R2057_OVR_REG3
value|0x168
end_define

begin_define
define|#
directive|define
name|R2057_OVR_REG4
value|0x169
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_SCAP_VAL
value|0x16a
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_BCAP_VAL
value|0x16b
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_HPC_VAL
value|0x16c
end_define

begin_define
define|#
directive|define
name|R2057_RCCAL_OVERRIDES
value|0x16d
end_define

begin_comment
comment|/* TX core 0 */
end_comment

begin_define
define|#
directive|define
name|R2057_TX0_IQCAL_GAIN_BW
value|0x170
end_define

begin_define
define|#
directive|define
name|R2057_TX0_LOFT_FINE_I
value|0x171
end_define

begin_define
define|#
directive|define
name|R2057_TX0_LOFT_FINE_Q
value|0x172
end_define

begin_define
define|#
directive|define
name|R2057_TX0_LOFT_COARSE_I
value|0x173
end_define

begin_define
define|#
directive|define
name|R2057_TX0_LOFT_COARSE_Q
value|0x174
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TX_SSI_MASTER
value|0x175
end_define

begin_define
define|#
directive|define
name|R2057_TX0_IQCAL_VCM_HG
value|0x176
end_define

begin_define
define|#
directive|define
name|R2057_TX0_IQCAL_IDAC
value|0x177
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TSSI_VCM
value|0x178
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TX_SSI_MUX
value|0x179
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TSSIA
value|0x17a
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TSSIG
value|0x17b
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TSSI_MISC1
value|0x17c
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TXRXCOUPLE_2G_ATTEN
value|0x17d
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TXRXCOUPLE_2G_PWRUP
value|0x17e
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TXRXCOUPLE_5G_ATTEN
value|0x17f
end_define

begin_define
define|#
directive|define
name|R2057_TX0_TXRXCOUPLE_5G_PWRUP
value|0x180
end_define

begin_comment
comment|/* TX core 1 */
end_comment

begin_define
define|#
directive|define
name|R2057_TX1_IQCAL_GAIN_BW
value|0x190
end_define

begin_define
define|#
directive|define
name|R2057_TX1_LOFT_FINE_I
value|0x191
end_define

begin_define
define|#
directive|define
name|R2057_TX1_LOFT_FINE_Q
value|0x192
end_define

begin_define
define|#
directive|define
name|R2057_TX1_LOFT_COARSE_I
value|0x193
end_define

begin_define
define|#
directive|define
name|R2057_TX1_LOFT_COARSE_Q
value|0x194
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TX_SSI_MASTER
value|0x195
end_define

begin_define
define|#
directive|define
name|R2057_TX1_IQCAL_VCM_HG
value|0x196
end_define

begin_define
define|#
directive|define
name|R2057_TX1_IQCAL_IDAC
value|0x197
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TSSI_VCM
value|0x198
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TX_SSI_MUX
value|0x199
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TSSIA
value|0x19a
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TSSIG
value|0x19b
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TSSI_MISC1
value|0x19c
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TXRXCOUPLE_2G_ATTEN
value|0x19d
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TXRXCOUPLE_2G_PWRUP
value|0x19e
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TXRXCOUPLE_5G_ATTEN
value|0x19f
end_define

begin_define
define|#
directive|define
name|R2057_TX1_TXRXCOUPLE_5G_PWRUP
value|0x1a0
end_define

begin_define
define|#
directive|define
name|R2057_AFE_VCM_CAL_MASTER_CORE0
value|0x1a1
end_define

begin_define
define|#
directive|define
name|R2057_AFE_SET_VCM_I_CORE0
value|0x1a2
end_define

begin_define
define|#
directive|define
name|R2057_AFE_SET_VCM_Q_CORE0
value|0x1a3
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_IQADC_CORE0
value|0x1a4
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_I_CORE0
value|0x1a5
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_Q_CORE0
value|0x1a6
end_define

begin_define
define|#
directive|define
name|R2057_AFE_VCM_CAL_MASTER_CORE1
value|0x1a7
end_define

begin_define
define|#
directive|define
name|R2057_AFE_SET_VCM_I_CORE1
value|0x1a8
end_define

begin_define
define|#
directive|define
name|R2057_AFE_SET_VCM_Q_CORE1
value|0x1a9
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_IQADC_CORE1
value|0x1aa
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_I_CORE1
value|0x1ab
end_define

begin_define
define|#
directive|define
name|R2057_AFE_STATUS_VCM_Q_CORE1
value|0x1ac
end_define

begin_define
define|#
directive|define
name|R2057v7_DACBUF_VINCM_CORE0
value|0x1ad
end_define

begin_define
define|#
directive|define
name|R2057v7_RCCAL_MASTER
value|0x1ae
end_define

begin_define
define|#
directive|define
name|R2057v7_TR2G_CONFIG3_CORE0_NU
value|0x1af
end_define

begin_define
define|#
directive|define
name|R2057v7_TR2G_CONFIG3_CORE1_NU
value|0x1b0
end_define

begin_define
define|#
directive|define
name|R2057v7_LOGEN_PUS1
value|0x1b1
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG5
value|0x1b2
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG6
value|0x1b3
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG7
value|0x1b4
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG8
value|0x1b5
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG9
value|0x1b6
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG10
value|0x1b7
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG11
value|0x1b8
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG12
value|0x1b9
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG13
value|0x1ba
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG14
value|0x1bb
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG15
value|0x1bc
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG16
value|0x1bd
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG1
value|0x1be
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG18
value|0x1bf
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG19
value|0x1c0
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG20
value|0x1c1
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG21
value|0x1c2
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG2
value|0x1c3
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG23
value|0x1c4
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG24
value|0x1c5
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG25
value|0x1c6
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG26
value|0x1c7
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG27
value|0x1c8
end_define

begin_define
define|#
directive|define
name|R2057v7_OVR_REG28
value|0x1c9
end_define

begin_define
define|#
directive|define
name|R2057v7_IQTEST_SEL_PU2
value|0x1ca
end_define

begin_define
define|#
directive|define
name|R2057_VCM_MASK
value|0x7
end_define

begin_struct
struct|struct
name|bwn_nphy_chantabent_rev7
block|{
comment|/* The channel frequency in MHz */
name|uint16_t
name|freq
decl_stmt|;
comment|/* Radio regs values on channelswitch */
name|uint8_t
name|radio_vcocal_countval0
decl_stmt|;
name|uint8_t
name|radio_vcocal_countval1
decl_stmt|;
name|uint8_t
name|radio_rfpll_refmaster_sparextalsize
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_r1
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_c2
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_c1
decl_stmt|;
name|uint8_t
name|radio_cp_kpd_idac
decl_stmt|;
name|uint8_t
name|radio_rfpll_mmd0
decl_stmt|;
name|uint8_t
name|radio_rfpll_mmd1
decl_stmt|;
name|uint8_t
name|radio_vcobuf_tune
decl_stmt|;
name|uint8_t
name|radio_logen_mx2g_tune
decl_stmt|;
name|uint8_t
name|radio_logen_mx5g_tune
decl_stmt|;
name|uint8_t
name|radio_logen_indbuf2g_tune
decl_stmt|;
name|uint8_t
name|radio_logen_indbuf5g_tune
decl_stmt|;
name|uint8_t
name|radio_txmix2g_tune_boost_pu_core0
decl_stmt|;
name|uint8_t
name|radio_pad2g_tune_pus_core0
decl_stmt|;
name|uint8_t
name|radio_pga_boost_tune_core0
decl_stmt|;
name|uint8_t
name|radio_txmix5g_boost_tune_core0
decl_stmt|;
name|uint8_t
name|radio_pad5g_tune_misc_pus_core0
decl_stmt|;
name|uint8_t
name|radio_lna2g_tune_core0
decl_stmt|;
name|uint8_t
name|radio_lna5g_tune_core0
decl_stmt|;
name|uint8_t
name|radio_txmix2g_tune_boost_pu_core1
decl_stmt|;
name|uint8_t
name|radio_pad2g_tune_pus_core1
decl_stmt|;
name|uint8_t
name|radio_pga_boost_tune_core1
decl_stmt|;
name|uint8_t
name|radio_txmix5g_boost_tune_core1
decl_stmt|;
name|uint8_t
name|radio_pad5g_tune_misc_pus_core1
decl_stmt|;
name|uint8_t
name|radio_lna2g_tune_core1
decl_stmt|;
name|uint8_t
name|radio_lna5g_tune_core1
decl_stmt|;
comment|/* PHY res values on channelswitch */
name|struct
name|bwn_phy_n_sfo_cfg
name|phy_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bwn_nphy_chantabent_rev7_2g
block|{
comment|/* The channel frequency in MHz */
name|uint16_t
name|freq
decl_stmt|;
comment|/* Radio regs values on channelswitch */
name|uint8_t
name|radio_vcocal_countval0
decl_stmt|;
name|uint8_t
name|radio_vcocal_countval1
decl_stmt|;
name|uint8_t
name|radio_rfpll_refmaster_sparextalsize
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_r1
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_c2
decl_stmt|;
name|uint8_t
name|radio_rfpll_loopfilter_c1
decl_stmt|;
name|uint8_t
name|radio_cp_kpd_idac
decl_stmt|;
name|uint8_t
name|radio_rfpll_mmd0
decl_stmt|;
name|uint8_t
name|radio_rfpll_mmd1
decl_stmt|;
name|uint8_t
name|radio_vcobuf_tune
decl_stmt|;
name|uint8_t
name|radio_logen_mx2g_tune
decl_stmt|;
name|uint8_t
name|radio_logen_indbuf2g_tune
decl_stmt|;
name|uint8_t
name|radio_txmix2g_tune_boost_pu_core0
decl_stmt|;
name|uint8_t
name|radio_pad2g_tune_pus_core0
decl_stmt|;
name|uint8_t
name|radio_lna2g_tune_core0
decl_stmt|;
name|uint8_t
name|radio_txmix2g_tune_boost_pu_core1
decl_stmt|;
name|uint8_t
name|radio_pad2g_tune_pus_core1
decl_stmt|;
name|uint8_t
name|radio_lna2g_tune_core1
decl_stmt|;
comment|/* PHY regs values on channelswitch */
name|struct
name|bwn_phy_n_sfo_cfg
name|phy_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|r2057_upload_inittabs
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r2057_get_chantabent_rev7
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|uint16_t
name|freq
parameter_list|,
specifier|const
name|struct
name|bwn_nphy_chantabent_rev7
modifier|*
modifier|*
name|tabent_r7
parameter_list|,
specifier|const
name|struct
name|bwn_nphy_chantabent_rev7_2g
modifier|*
modifier|*
name|tabent_r7_2g
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_BWN_RADIO_2057_H_ */
end_comment

end_unit

