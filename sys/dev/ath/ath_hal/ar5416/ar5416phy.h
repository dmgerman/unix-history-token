begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5416PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5416PHY_H_
end_define

begin_include
include|#
directive|include
file|"ar5212/ar5212phy.h"
end_include

begin_define
define|#
directive|define
name|AR_PHY_CHIP_ID_REV_0
value|0x80
end_define

begin_comment
comment|/* 5416 Rev 0 (owl 1.0) BB */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHIP_ID_REV_1
value|0x81
end_define

begin_comment
comment|/* 5416 Rev 1 (owl 2.0) BB */
end_comment

begin_define
define|#
directive|define
name|RFSILENT_BB
value|0x00002000
end_define

begin_comment
comment|/* shush bb */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RESTART
value|0x9970
end_define

begin_comment
comment|/* restart */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RESTART_DIV_GC
value|0x001C0000
end_define

begin_comment
comment|/* bb_ant_fast_div_gc_limit */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RESTART_DIV_GC_S
value|18
end_define

begin_comment
comment|/* PLL settling times */
end_comment

begin_define
define|#
directive|define
name|RTC_PLL_SETTLE_DELAY
value|1000
end_define

begin_comment
comment|/* 1 ms     */
end_comment

begin_define
define|#
directive|define
name|HT40_CHANNEL_CENTER_SHIFT
value|10
end_define

begin_comment
comment|/* MHz      */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ
value|0x997C
end_define

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_2040_MODE
value|0x8318
end_define

begin_define
define|#
directive|define
name|AR_2040_JOINED_RX_CLEAR
value|0x00000001
end_define

begin_comment
comment|// use ctl + ext rx_clear for cca
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_TURBO_SHORT
value|0x00000002
end_define

begin_comment
comment|/* Set short symbols to turbo mode setting */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_DYN2040_EN
value|0x00000004
end_define

begin_comment
comment|/* Enable dyn 20/40 mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_DYN2040_PRI_ONLY
value|0x00000008
end_define

begin_comment
comment|/* dyn 20/40 - primary only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_DYN2040_PRI_CH
value|0x00000010
end_define

begin_comment
comment|/* dyn 20/40 - primary ch offset (0=+10MHz, 1=-10MHz)*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_DYN2040_EXT_CH
value|0x00000020
end_define

begin_comment
comment|/* dyn 20/40 - ext ch spacing (0=20MHz/ 1=25MHz) */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_HT_EN
value|0x00000040
end_define

begin_comment
comment|/* ht enable */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_SHORT_GI_40
value|0x00000080
end_define

begin_comment
comment|/* allow short GI for HT 40 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_WALSH
value|0x00000100
end_define

begin_comment
comment|/* walsh spatial spreading for 2 chains,2 streams TX */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_SINGLE_HT_LTF1
value|0x00000200
end_define

begin_comment
comment|/* single length (4us) 1st HT long training symbol */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING2
value|0x9810
end_define

begin_comment
comment|/* Timing Control 2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_USE_FORCE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_FORCE_VAL
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_CHAIN
parameter_list|(
name|_i
parameter_list|)
define|\
value|(AR_PHY_TIMING_CTRL4 + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_DO_CAL
value|0x10000
end_define

begin_comment
comment|/* perform calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_Q_COFF
value|0x01F
end_define

begin_comment
comment|/* Mask for kcos_theta-1 for q correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_Q_COFF_S
value|0
end_define

begin_comment
comment|/* shift for Q_COFF */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_I_COFF
value|0x7E0
end_define

begin_comment
comment|/* Mask for sin_theta for i correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_I_COFF_S
value|5
end_define

begin_comment
comment|/* Shift for sin_theta for i correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_ENABLE
value|0x800
end_define

begin_comment
comment|/* enable IQ correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCAL_LOG_COUNT_MAX
value|0xF000
end_define

begin_comment
comment|/* Mask for max number of samples (logarithmic) */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCAL_LOG_COUNT_MAX_S
value|12
end_define

begin_comment
comment|/* Shift for max number of samples */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_ENABLE_SPUR_RSSI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_ENABLE_SPUR_FILTER
value|0x40000000
end_define

begin_comment
comment|/* Enable spur filter */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_ENABLE_CHAN_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_ENABLE_PILOT_MASK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_SERIAL_CTL
value|0x9830
end_define

begin_define
define|#
directive|define
name|AR_PHY_SEL_INTERNAL_ADDAC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SEL_EXTERNAL_RADIO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_BSW_MARGIN
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_BSW_MARGIN_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_BSW_ATTEN
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_BSW_ATTEN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA
value|0x99bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_CYCPWR_THR1
value|0x0000FE00
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_CYCPWR_THR1_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_MINCCA_PWR
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_MINCCA_PWR_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_THRESH62
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_THRESH62_S
value|16
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_EXT_MINCCA_PWR
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_EXT_MINCCA_PWR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_HALFGI
value|0x99D0
end_define

begin_comment
comment|/* Timing control 3 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_HALFGI_DSC_MAN
value|0x0007FFF0
end_define

begin_define
define|#
directive|define
name|AR_PHY_HALFGI_DSC_MAN_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_HALFGI_DSC_EXP
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AR_PHY_HALFGI_DSC_EXP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_HEAVY_CLIP_ENABLE
value|0x99E0
end_define

begin_define
define|#
directive|define
name|AR_PHY_M_SLEEP
value|0x99f0
end_define

begin_comment
comment|/* sleep control registers */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_REFCLKDLY
value|0x99f4
end_define

begin_define
define|#
directive|define
name|AR_PHY_REFCLKPD
value|0x99f8
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALMODE
value|0x99f0
end_define

begin_comment
comment|/* Calibration Types */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CALMODE_IQ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALMODE_ADC_GAIN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALMODE_ADC_DC_PER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALMODE_ADC_DC_INIT
value|0x00000003
end_define

begin_comment
comment|/* Calibration results */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_0
parameter_list|(
name|_i
parameter_list|)
value|(0x9c10 + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_1
parameter_list|(
name|_i
parameter_list|)
value|(0x9c14 + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_2
parameter_list|(
name|_i
parameter_list|)
value|(0x9c18 + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_3
parameter_list|(
name|_i
parameter_list|)
value|(0x9c1c + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA
value|0x9864
end_define

begin_define
define|#
directive|define
name|AR_PHY_MINCCA_PWR
value|0x0FF80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MINCCA_PWR_S
value|19
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_MINCCA_PWR
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_MINCCA_PWR_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CCA_THRESH62
value|0x000FF000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CCA_THRESH62_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_CCA
value|0xa864
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_MINCCA_PWR
value|0x0FF80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_MINCCA_PWR_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_THRESH62
value|0x0007F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_THRESH62_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CH1_MINCCA_PWR
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CH1_MINCCA_PWR_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_CCA
value|0xb864
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_MINCCA_PWR
value|0x0FF80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_MINCCA_PWR_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_CCA
value|0xa9bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CH1_EXT_MINCCA_PWR
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_CH1_EXT_MINCCA_PWR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_CCA
value|0xb9bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_CHAINMASK
value|0x99a4
end_define

begin_define
define|#
directive|define
name|AR_PHY_NEW_ADC_DC_GAIN_CORR
parameter_list|(
name|_i
parameter_list|)
value|(0x99b4 + ((_i)<< 12))
end_define

begin_define
define|#
directive|define
name|AR_PHY_NEW_ADC_GAIN_CORR_ENABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_NEW_ADC_DC_OFFSET_CORR_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MULTICHAIN_GAIN_CTL
value|0x99ac
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA0
value|0x99b8
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA0_THRESH62
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA0_THRESH62_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_CCA
value|0xa9bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_CCA
value|0xb9bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_ANALOG_SWAP
value|0xa268
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWAP_ALT_CHAIN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_CHAINMASK
value|0xa39c
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN_0
value|0x9960
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_COM
value|0x9964
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL2
value|0x9824
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_DATA_START
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_DATA_START_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_PA_ON
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_PA_ON_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL3
value|0x9828
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_END_TO_A2_RX_ON
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_END_TO_A2_RX_ON_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4
value|0x9834
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_TX_END_XPAB_OFF
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_TX_END_XPAB_OFF_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_TX_END_XPAA_OFF
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_TX_END_XPAA_OFF_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_FRAME_XPAB_ON
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_FRAME_XPAB_ON_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_FRAME_XPAA_ON
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL4_FRAME_XPAA_ON_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SYNTH_CONTROL
value|0x9874
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCE_CLKEN_CCK
value|0xA22C
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCE_CLKEN_CCK_MRC_MUX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_SUB
value|0xA3C8
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE5
value|0xA38C
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE6
value|0xA390
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE7
value|0xA3CC
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE8
value|0xA3D0
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE9
value|0xA3D4
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_1
value|0x00030000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_2
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_2_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_3
value|0x00300000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_GAIN_3_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_CAL_ENABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PD_CAL_ENABLE_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_VIT_MASK2_M_46_61
value|0xa3a0
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_M_31_45
value|0xa3a4
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_M_16_30
value|0xa3a8
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_M_00_15
value|0xa3ac
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_P_15_01
value|0xa3b8
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_P_30_16
value|0xa3bc
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_P_45_31
value|0xa3c0
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK2_P_61_45
value|0xa3c4
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG
value|0x994c
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT
value|0x99c0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M2_THRESH
value|0x00003F80
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M2_THRESH_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH_LOW
value|0x001FC000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH_LOW_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M2_THRESH_LOW
value|0x0FE00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M2_THRESH_LOW_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_SPUR_SUBCHNL_SD_S
value|28
end_define

begin_comment
comment|/* enable vit puncture per rate, 8 bits, lsb is low rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_CNTL
value|(0xFF<< 18)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_CNTL_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_ENABLE_MASK_PPM
value|0x20000
end_define

begin_comment
comment|/* bins move with freq offset */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_SELECT
value|(0xFF<< 9)
end_define

begin_comment
comment|/* use mask1 or mask2, one per rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_SELECT_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_ENABLE_VIT_SPUR_RSSI
value|0x100
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_SPUR_RSSI_THRESH
value|0x7F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_SPUR_RSSI_THRESH_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_MASK_01_30
value|0xa3b0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_MASK_31_60
value|0xa3b4
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHANNEL_MASK_01_30
value|0x99d4
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHANNEL_MASK_31_60
value|0x99d8
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_CAL_CTL
value|0xA358
end_define

begin_comment
comment|/* carrier leak cal control */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CL_CAL_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_PARALLEL_CAL_ENABLE
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5416PHY_H_ */
end_comment

end_unit

