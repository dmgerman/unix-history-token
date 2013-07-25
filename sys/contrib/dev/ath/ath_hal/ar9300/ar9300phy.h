begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2002-2005 Atheros Communications, Inc.   * All Rights Reserved.  *   * Copyright (c) 2011 Qualcomm Atheros, Inc.  * All Rights Reserved.  * Qualcomm Atheros Confidential and Proprietary.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9300PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9300PHY_H_
end_define

begin_include
include|#
directive|include
file|"osprey_reg_map.h"
end_include

begin_comment
comment|/*  * BB PHY register map  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BASE
value|offsetof(struct bb_reg_map, bb_chn_reg_map)
end_define

begin_comment
comment|/* base address of phy regs */
end_comment

begin_define
define|#
directive|define
name|AR_PHY
parameter_list|(
name|_n
parameter_list|)
value|(AR_PHY_BASE + ((_n)<<2))
end_define

begin_comment
comment|/*  * Channel Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_CHAN_BASE
value|offsetof(struct bb_reg_map, bb_chn_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_CHAN_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_CHAN_BASE + offsetof(struct chn_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING1
value|AR_CHAN_OFFSET(BB_timing_controls_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2
value|AR_CHAN_OFFSET(BB_timing_controls_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING3
value|AR_CHAN_OFFSET(BB_timing_controls_3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4
value|AR_CHAN_OFFSET(BB_timing_control_4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5
value|AR_CHAN_OFFSET(BB_timing_control_5)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING6
value|AR_CHAN_OFFSET(BB_timing_control_6)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11
value|AR_CHAN_OFFSET(BB_timing_control_11)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG
value|AR_CHAN_OFFSET(BB_spur_mask_controls)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_B0
value|AR_CHAN_OFFSET(BB_rx_iq_corr_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_3
value|AR_CHAN_OFFSET(BB_txiqcal_control_3)
end_define

begin_comment
comment|/* BB_timing_control_11 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_SPUR_FREQ_SD
value|0x3FF00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_SPUR_FREQ_SD_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_SPUR_DELTA_PHASE
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_SPUR_DELTA_PHASE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_USE_SPUR_FILTER_IN_AGC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_USE_SPUR_FILTER_IN_AGC_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_USE_SPUR_FILTER_IN_SELFCOR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_USE_SPUR_FILTER_IN_SELFCOR_S
value|31
end_define

begin_comment
comment|/* BB_spur_mask_controls */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_ENABLE_NF_RSSI_SPUR_MIT
value|0x4000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_ENABLE_NF_RSSI_SPUR_MIT_S
value|26
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
name|AR_PHY_SPUR_REG_ENABLE_MASK_PPM_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_SPUR_RSSI_THRESH
value|0x000000FF
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
name|AR_PHY_SPUR_REG_EN_VIT_SPUR_RSSI
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_EN_VIT_SPUR_RSSI_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_CNTL
value|0x03FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REG_MASK_RATE_CNTL_S
value|18
end_define

begin_comment
comment|/* BB_rx_iq_corr_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_B0_LOOPBACK_IQCORR_EN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_B0_LOOPBACK_IQCORR_EN_S
value|29
end_define

begin_comment
comment|/* BB_txiqcal_control_3 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_3_IQCORR_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_3_IQCORR_EN_S
value|31
end_define

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW
value|AR_CHAN_OFFSET(BB_find_signal_low)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR
value|AR_CHAN_OFFSET(BB_sfcorr)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2COUNT_THR
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2COUNT_THR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M1_THRESH
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M1_THRESH_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2_THRESH
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2_THRESH_S
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW
value|AR_CHAN_OFFSET(BB_self_corr_low)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT
value|AR_CHAN_OFFSET(BB_ext_chan_scorr_thr)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH
value|0x0000007F
end_define

begin_comment
comment|// [06:00]
end_comment

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

begin_comment
comment|// [13:07]
end_comment

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

begin_comment
comment|// [20:14]
end_comment

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

begin_comment
comment|// [27:21]
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA
value|AR_CHAN_OFFSET(BB_ext_chan_pwr_thr_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0
value|AR_CHAN_OFFSET(BB_radar_detection)
end_define

begin_comment
comment|/* radar detection settings */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1
value|AR_CHAN_OFFSET(BB_radar_detection_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_CF_BIN_THRESH
value|0x07000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_CF_BIN_THRESH_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_EXT
value|AR_CHAN_OFFSET(BB_extension_radar)
end_define

begin_comment
comment|/* extension channel radar settings */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MULTICHAIN_CTRL
value|AR_CHAN_OFFSET(BB_multichain_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD
value|AR_CHAN_OFFSET(BB_per_chain_csd)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PHASE_RAMP_0
value|AR_CHAN_OFFSET(BB_tx_phase_ramp_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_GAIN_DC_CORR_0
value|AR_CHAN_OFFSET(BB_adc_gain_dc_corr_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_0_B0
value|AR_CHAN_OFFSET(BB_iq_adc_meas_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_1_B0
value|AR_CHAN_OFFSET(BB_iq_adc_meas_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_2_B0
value|AR_CHAN_OFFSET(BB_iq_adc_meas_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_3_B0
value|AR_CHAN_OFFSET(BB_iq_adc_meas_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQ_CORR_0
value|AR_CHAN_OFFSET(BB_tx_iq_corr_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_CRC
value|AR_CHAN_OFFSET(BB_tx_crc)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TST_DAC_CONST
value|AR_CHAN_OFFSET(BB_tstdac_constant)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REPORT_0
value|AR_CHAN_OFFSET(BB_spur_report_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_TAB_0
value|AR_CHAN_OFFSET(BB_chan_info_chan_tab_b0)
end_define

begin_comment
comment|/*  * Channel Field Definitions  */
end_comment

begin_comment
comment|/* BB_timing_controls_2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_USE_FORCE_PPM
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_FORCE_PPM_VAL
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_HT_Fine_Timing_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_DC_OFFSET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING2_DC_OFFSET_S
value|27
end_define

begin_comment
comment|/* BB_timing_controls_3 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING3_DSC_MAN
value|0xFFFE0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING3_DSC_MAN_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING3_DSC_EXP
value|0x0001E000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING3_DSC_EXP_S
value|13
end_define

begin_comment
comment|/* BB_timing_control_4 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_IQCAL_LOG_COUNT_MAX
value|0xF000
end_define

begin_comment
comment|/* Mask for max number of samples (logarithmic) */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_IQCAL_LOG_COUNT_MAX_S
value|12
end_define

begin_comment
comment|/* Shift for max number of samples */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_DO_CAL
value|0x10000
end_define

begin_comment
comment|/* perform calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_PILOT_MASK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_PILOT_MASK_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_CHAN_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_CHAN_MASK_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_SPUR_FILTER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_SPUR_FILTER_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_SPUR_RSSI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_ENABLE_SPUR_RSSI_S
value|31
end_define

begin_comment
comment|/* BB_adc_gain_dc_corr_b0 */
end_comment

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

begin_comment
comment|/* BB_self_corr_low */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_USE_SELF_CORR_LOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M2COUNT_THR_LOW
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M2COUNT_THR_LOW_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M1_THRESH_LOW
value|0x001FC000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M1_THRESH_LOW_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M2_THRESH_LOW
value|0x0FE00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW_M2_THRESH_LOW_S
value|21
end_define

begin_comment
comment|/* BB_sfcorr */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2COUNT_THR
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2COUNT_THR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M1_THRESH
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M1_THRESH_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2_THRESH
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_M2_THRESH_S
value|24
end_define

begin_comment
comment|/* BB_ext_chan_scorr_thr */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M1_THRESH
value|0x0000007F
end_define

begin_comment
comment|// [06:00]
end_comment

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

begin_comment
comment|// [13:07]
end_comment

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

begin_comment
comment|// [20:14]
end_comment

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

begin_comment
comment|// [27:21]
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_M2_THRESH_LOW_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_SPUR_SUBCHANNEL_SD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_EXT_SPUR_SUBCHANNEL_SD_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_SPUR_SUBCHNL_SD_S
value|28
end_define

begin_comment
comment|/* BB_ext_chan_pwr_thr_2_b0 */
end_comment

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
name|AR_PHY_EXT_MINCCA_PWR
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_MINCCA_PWR_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CYCPWR_THR1
value|0x0000FE00L
end_define

begin_comment
comment|// [15:09]
end_comment

begin_define
define|#
directive|define
name|AR_PHY_EXT_CYCPWR_THR1_S
value|9
end_define

begin_comment
comment|/* BB_timing_control_5 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1
value|0x000000FE
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1A
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_CYCPWR_THR1A_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_RSSI_THR1A
value|(0x7F<< 16)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_RSSI_THR1A_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING5_RSSI_THR1A_ENA
value|(0x1<< 15)
end_define

begin_comment
comment|/* BB_radar_detection) */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_ENA
value|0x00000001
end_define

begin_comment
comment|/* Enable radar detection */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_FFT_ENA
value|0x80000000
end_define

begin_comment
comment|/* Enable FFT data */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_INBAND
value|0x0000003e
end_define

begin_comment
comment|/* Inband pulse threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_INBAND_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_PRSSI
value|0x00000FC0
end_define

begin_comment
comment|/* Pulse rssi threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_PRSSI_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_HEIGHT
value|0x0003F000
end_define

begin_comment
comment|/* Pulse height threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_HEIGHT_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_RRSSI
value|0x00FC0000
end_define

begin_comment
comment|/* Radar rssi threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_RRSSI_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_FIRPWR
value|0x7F000000
end_define

begin_comment
comment|/* Radar firpwr threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0_FIRPWR_S
value|24
end_define

begin_comment
comment|/* BB_radar_detection_2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELPWR_ENA
value|0x00800000
end_define

begin_comment
comment|/* enable to check radar relative power */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_USE_FIR128
value|0x00400000
end_define

begin_comment
comment|/* enable to use the average inband power                                                      * measured over 128 cycles                                                      */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELPWR_THRESH
value|0x003F0000
end_define

begin_comment
comment|/* relative pwr thresh */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELPWR_THRESH_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_BLOCK_CHECK
value|0x00008000
end_define

begin_comment
comment|/* Enable to block radar check if weak OFDM                                                      * sig or pkt is immediately after tx to rx                                                      * transition                                                      */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_MAX_RRSSI
value|0x00004000
end_define

begin_comment
comment|/* Enable to use max rssi */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELSTEP_CHECK
value|0x00002000
end_define

begin_comment
comment|/* Enable to use pulse relative step check */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELSTEP_THRESH
value|0x00001F00
end_define

begin_comment
comment|/* Pulse relative step threshold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_RELSTEP_THRESH_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_MAXLEN
value|0x000000FF
end_define

begin_comment
comment|/* Max length of radar pulse */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_1_MAXLEN_S
value|0
end_define

begin_comment
comment|/* BB_extension_radar */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_EXT_ENA
value|0x00004000
end_define

begin_comment
comment|/* Enable extension channel radar detection */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RADAR_DC_PWR_THRESH
value|0x007f8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_DC_PWR_THRESH_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_LB_DC_CAP
value|0x7f800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_LB_DC_CAP_S
value|23
end_define

begin_comment
comment|/* per chain csd*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn1_2chains
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn1_2chains_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn1_3chains
value|0x000003e0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn1_3chains_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn2_3chains
value|0x00007c00
end_define

begin_define
define|#
directive|define
name|AR_PHY_PERCHAIN_CSD_chn2_3chains_S
value|10
end_define

begin_comment
comment|/* BB_find_signal_low */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_FIRSTEP_LOW
value|(0x3f<< 6)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_FIRSTEP_LOW_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_FIRPWR
value|(0x7f<< 12)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_FIRPWR_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_FIRPWR_SIGN_BIT
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_RELSTEP
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_RELSTEP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_LOW_RELSTEP_SIGN_BIT
value|5
end_define

begin_comment
comment|/* BB_chan_info_chan_tab_b* */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_TAB_S2_READ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_TAB_S2_READ_S
value|3
end_define

begin_comment
comment|/* BB_rx_iq_corr_b* */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_IQCORR_Q_Q_COFF
value|0x0000007F
end_define

begin_comment
comment|/* Mask for kcos_theta-1 for q correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_IQCORR_Q_Q_COFF_S
value|0
end_define

begin_comment
comment|/* shift for Q_COFF */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_IQCORR_Q_I_COFF
value|0x00003F80
end_define

begin_comment
comment|/* Mask for sin_theta for i correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_IQCORR_Q_I_COFF_S
value|7
end_define

begin_comment
comment|/* Shift for sin_theta for i correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_IQCORR_ENABLE
value|0x00004000
end_define

begin_comment
comment|/* enable IQ correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_LOOPBACK_IQCORR_Q_Q_COFF
value|0x003f8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_LOOPBACK_IQCORR_Q_Q_COFF_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_LOOPBACK_IQCORR_Q_I_COFF
value|0x1fc00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_LOOPBACK_IQCORR_Q_I_COFF_S
value|22
end_define

begin_comment
comment|/*  * MRC Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_MRC_BASE
value|offsetof(struct bb_reg_map, bb_mrc_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_MRC_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_MRC_BASE + offsetof(struct mrc_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING_3A
value|AR_MRC_OFFSET(BB_timing_control_3a)
end_define

begin_define
define|#
directive|define
name|AR_PHY_LDPC_CNTL1
value|AR_MRC_OFFSET(BB_ldpc_cntl1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_LDPC_CNTL2
value|AR_MRC_OFFSET(BB_ldpc_cntl2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_SPUR_MASK
value|AR_MRC_OFFSET(BB_pilot_spur_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_SPUR_MASK
value|AR_MRC_OFFSET(BB_chan_spur_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SGI_DELTA
value|AR_MRC_OFFSET(BB_short_gi_delta_slope)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ML_CNTL_1
value|AR_MRC_OFFSET(BB_ml_cntl1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ML_CNTL_2
value|AR_MRC_OFFSET(BB_ml_cntl2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TST_ADC
value|AR_MRC_OFFSET(BB_tstadc)
end_define

begin_comment
comment|/* BB_pilot_spur_mask fields */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A
value|0x00000FE0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_SPUR_MASK_CF_PILOT_MASK_IDX_A_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_SPUR_MASK_CF_PILOT_MASK_A
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PILOT_SPUR_MASK_CF_PILOT_MASK_A_S
value|0
end_define

begin_comment
comment|/* BB_chan_spur_mask fields */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A
value|0x00000FE0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_SPUR_MASK_CF_CHAN_MASK_IDX_A_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_SPUR_MASK_CF_CHAN_MASK_A
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_SPUR_MASK_CF_CHAN_MASK_A_S
value|0
end_define

begin_comment
comment|/*  * MRC Feild Definitions  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SGI_DSC_MAN
value|0x0007FFF0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SGI_DSC_MAN_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_SGI_DSC_EXP
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SGI_DSC_EXP_S
value|0
end_define

begin_comment
comment|/*  * BBB Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_BBB_BASE
value|offsetof(struct bb_reg_map, bb_bbb_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_BBB_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_BBB_BASE + offsetof(struct bbb_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBB_RX_CTRL
parameter_list|(
name|_i
parameter_list|)
value|AR_BBB_OFFSET(BB_bbb_rx_ctrl_##_i)
end_define

begin_comment
comment|/*  * AGC Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_AGC_BASE
value|offsetof(struct bb_reg_map, bb_agc_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_AGC_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_AGC_BASE + offsetof(struct agc_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_SETTLING
value|AR_AGC_OFFSET(BB_settling_time)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCEMAX_GAINS_0
value|AR_AGC_OFFSET(BB_gain_force_max_gains_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAINS_MINOFF0
value|AR_AGC_OFFSET(BB_gains_min_offsets_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ
value|AR_AGC_OFFSET(BB_desired_sigsize)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG
value|AR_AGC_OFFSET(BB_find_signal)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC
value|AR_AGC_OFFSET(BB_agc)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_0
value|AR_AGC_OFFSET(BB_ext_atten_switch_ctl_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_0
value|AR_AGC_OFFSET(BB_cca_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA0
value|AR_AGC_OFFSET(BB_cca_ctrl_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RESTART
value|AR_AGC_OFFSET(BB_restart)
end_define

begin_define
define|#
directive|define
name|AR_PHY_MC_GAIN_CTRL
value|AR_AGC_OFFSET(BB_multichain_gain_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXTCHN_PWRTHR1
value|AR_AGC_OFFSET(BB_ext_chan_pwr_thr_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CHN_WIN
value|AR_AGC_OFFSET(BB_ext_chan_detect_win)
end_define

begin_define
define|#
directive|define
name|AR_PHY_20_40_DET_THR
value|AR_AGC_OFFSET(BB_pwr_thr_20_40_det)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RIFS_SRCH
value|AR_AGC_OFFSET(BB_rifs_srch)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PEAK_DET_CTRL_1
value|AR_AGC_OFFSET(BB_peak_det_ctrl_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PEAK_DET_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_PEAK_DET_CTRL_2
value|AR_AGC_OFFSET(BB_peak_det_ctrl_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_GAIN_BOUNDS_1
value|AR_AGC_OFFSET(BB_rx_gain_bounds_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_GAIN_BOUNDS_2
value|AR_AGC_OFFSET(BB_rx_gain_bounds_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RSSI_0
value|AR_AGC_OFFSET(BB_rssi_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_CCK_REP0
value|AR_AGC_OFFSET(BB_spur_est_cck_report_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT
value|AR_AGC_OFFSET(BB_bbb_sig_detect)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK
value|AR_AGC_OFFSET(BB_bbb_dagc_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQCORR_CTRL_CCK
value|AR_AGC_OFFSET(BB_iqcorr_ctrl_cck)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_STATUS_I_B0
value|AR_AGC_OFFSET(BB_agc_dig_dc_status_i_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_STATUS_Q_B0
value|AR_AGC_OFFSET(BB_agc_dig_dc_status_q_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C1_RES
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C1_RES_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C2_RES
value|0x0003fe00
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C2_RES_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C3_RES
value|0x07fc0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_C3_RES_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT
value|AR_AGC_OFFSET(BB_cck_spur_mit)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_SPUR_RSSI_THR
value|0x000001fe
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_SPUR_RSSI_THR_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_SPUR_FILTER_TYPE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_SPUR_FILTER_TYPE_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_USE_CCK_SPUR_MIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_USE_CCK_SPUR_MIT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_CCK_SPUR_FREQ
value|0x1ffffe00
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_SPUR_MIT_CCK_SPUR_FREQ_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_MRC_CCK_CTRL
value|AR_AGC_OFFSET(BB_mrc_cck_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_MRC_CCK_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_MRC_CCK_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_MRC_CCK_MUX_REG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_MRC_CCK_MUX_REG_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_OCGAIN
value|AR_AGC_OFFSET(BB_rx_ocgain)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_OSPREY_2GHZ
value|-110
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_OSPREY_5GHZ
value|-115
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MIN_GOOD_VAL_OSPREY_2GHZ
value|-125
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MIN_GOOD_VAL_OSPREY_5GHZ
value|-125
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MAX_GOOD_VAL_OSPREY_2GHZ
value|-95
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MAX_GOOD_VAL_OSPREY_5GHZ
value|-100
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_PEACOCK_5GHZ
value|-105
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_JUPITER_2GHZ
value|-127
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MIN_GOOD_VAL_JUPITER_2GHZ
value|-127
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_JUPITER_5GHZ
value|-127
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_MIN_GOOD_VAL_JUPITER_5GHZ
value|-127
end_define

begin_define
define|#
directive|define
name|AR_PHY_BT_COEX_4
value|AR_AGC_OFFSET(BB_bt_coex_4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BT_COEX_5
value|AR_AGC_OFFSET(BB_bt_coex_5)
end_define

begin_comment
comment|/*  * Noise floor readings at least CW_INT_DELTA above the nominal NF  * indicate that CW interference is present.  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCA_CW_INT_DELTA
value|30
end_define

begin_comment
comment|/*  * AGC Field Definitions  */
end_comment

begin_comment
comment|/* BB_ext_atten_switch_ctl_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_RXTX_MARGIN
value|0x00FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_RXTX_MARGIN_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_BSW_MARGIN
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_BSW_MARGIN_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_BSW_ATTEN
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_BSW_ATTEN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN2_MARGIN
value|0x003E0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN2_MARGIN_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN1_MARGIN
value|0x0001F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN1_MARGIN_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN2_DB
value|0x00000FC0
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN2_DB_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN1_DB
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_XATTEN1_DB_S
value|0
end_define

begin_comment
comment|/* BB_gain_force_max_gains_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN_TXRX_ATTEN
value|0x0003F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN_TXRX_ATTEN_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN_TXRX_RF_MAX
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN_TXRX_RF_MAX_S
value|18
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_RXGAIN_TXRX_ATTEN
value|0x00003F80
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_RXGAIN_TXRX_ATTEN_S
value|7
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_RXGAIN_TXRX_MARGIN
value|0x001FC000
end_define

begin_define
define|#
directive|define
name|AR9280_PHY_RXGAIN_TXRX_MARGIN_S
value|14
end_define

begin_comment
comment|/* BB_settling_time */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SETTLING_SWITCH
value|0x00003F80
end_define

begin_define
define|#
directive|define
name|AR_PHY_SETTLING_SWITCH_S
value|7
end_define

begin_comment
comment|/* BB_desired_sigsize */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_ADC
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_ADC_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_PGA
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_PGA_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_TOT_DES
value|0x0FF00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_DESIRED_SZ_TOT_DES_S
value|20
end_define

begin_comment
comment|/* BB_cca_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MINCCA_PWR
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MINCCA_PWR_S
value|20
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

begin_comment
comment|/* BB_cca_ctrl_2_b0 */
end_comment

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

begin_comment
comment|/* BB_bbb_sig_detect */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_WEAK_SIG_THR_CCK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_WEAK_SIG_THR_CCK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_ANT_SWITCH_TIME
value|0x00001FC0
end_define

begin_comment
comment|// [12:6] settling time for antenna switch
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_ANT_SWITCH_TIME_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV_S
value|13
end_define

begin_comment
comment|/* BB_bbb_dagc_ctrl */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_EN_RSSI_THR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_EN_RSSI_THR_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_RSSI_THR
value|0x0001FC00
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_RSSI_THR_S
value|10
end_define

begin_comment
comment|/* BB_rifs_srch */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RIFS_INIT_DELAY
value|0x3ff0000
end_define

begin_comment
comment|/*B_tpc_7*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_7_TX_GAIN_TABLE_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_7_TX_GAIN_TABLE_MAX_S
value|(0)
end_define

begin_comment
comment|/* BB_agc */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_QUICK_DROP_S
value|(22)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_QUICK_DROP
value|(0xf<< AR_PHY_AGC_QUICK_DROP_S)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_LOW
value|0x00007F80
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_LOW_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_HIGH
value|0x003F8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_HIGH_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_PWR_CONST
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_COARSE_PWR_CONST_S
value|0
end_define

begin_comment
comment|/* BB_find_signal */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_FIRSTEP
value|0x0003F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_FIRSTEP_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_FIRPWR
value|0x03FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_FIRPWR_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_FIRPWR_SIGN_BIT
value|25
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELPWR
value|(0x1f<< 6)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELPWR_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELPWR_SIGN_BIT
value|11
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELSTEP
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELSTEP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG_RELSTEP_SIGN_BIT
value|5
end_define

begin_comment
comment|/* BB_restart */
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

begin_define
define|#
directive|define
name|AR_PHY_RESTART_ENA
value|0x01
end_define

begin_comment
comment|/* enable restart */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DC_RESTART_DIS
value|0x40000000
end_define

begin_comment
comment|/* disable DC restart */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_OLPC_GAIN_DELTA_PAL_ON
value|0xFF000000
end_define

begin_comment
comment|//Mask BIT[31:24]
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_OLPC_GAIN_DELTA_PAL_ON_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_OLPC_GAIN_DELTA
value|0x00FF0000
end_define

begin_comment
comment|//Mask BIT[23:16]
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_OLPC_GAIN_DELTA_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_6_ERROR_EST_MODE
value|0x03000000
end_define

begin_comment
comment|//Mask BIT[25:24]
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_6_ERROR_EST_MODE_S
value|24
end_define

begin_comment
comment|/*  * SM Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_SM_BASE
value|offsetof(struct bb_reg_map, bb_sm_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_SM_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_SM_BASE + offsetof(struct sm_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_D2_CHIP_ID
value|AR_SM_OFFSET(BB_D2_chip_id)
end_define

begin_define
define|#
directive|define
name|AR_PHY_GEN_CTRL
value|AR_SM_OFFSET(BB_gen_controls)
end_define

begin_define
define|#
directive|define
name|AR_PHY_MODE
value|AR_SM_OFFSET(BB_modes_select)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE
value|AR_SM_OFFSET(BB_active)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_A
value|AR_SM_OFFSET(BB_vit_spur_mask_A)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_B
value|AR_SM_OFFSET(BB_vit_spur_mask_B)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN
value|AR_SM_OFFSET(BB_spectral_scan)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_BW_FILTER
value|AR_SM_OFFSET(BB_radar_bw_filter)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SEARCH_START_DELAY
value|AR_SM_OFFSET(BB_search_start_delay)
end_define

begin_define
define|#
directive|define
name|AR_PHY_MAX_RX_LEN
value|AR_SM_OFFSET(BB_max_rx_length)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL
value|AR_SM_OFFSET(BB_frame_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ
value|AR_SM_OFFSET(BB_rfbus_request)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_GRANT
value|AR_SM_OFFSET(BB_rfbus_grant)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RIFS
value|AR_SM_OFFSET(BB_rifs)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_CLR_DELAY
value|AR_SM_OFFSET(BB_rx_clear_delay)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY
value|AR_SM_OFFSET(BB_analog_power_on_time)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_POWERTX_RATE9
value|AR_SM_OFFSET(BB_powertx_rate9)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_7
value|AR_SM_OFFSET(BB_tpc_7)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_0_B0
value|AR_SM_OFFSET(BB_cl_map_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_1_B0
value|AR_SM_OFFSET(BB_cl_map_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_2_B0
value|AR_SM_OFFSET(BB_cl_map_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_3_B0
value|AR_SM_OFFSET(BB_cl_map_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RF_CTL
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_tx_timing_##_i)
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL
value|AR_SM_OFFSET(BB_xpa_timing_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_MISC_PA_CTL
value|AR_SM_OFFSET(BB_misc_pa_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN_0
value|AR_SM_OFFSET(BB_switch_table_chn_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_COM
value|AR_SM_OFFSET(BB_switch_table_com1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_COM_2
value|AR_SM_OFFSET(BB_switch_table_com2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_CHAINMASK
value|AR_SM_OFFSET(BB_multichain_enable)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_CHAINMASK
value|AR_SM_OFFSET(BB_cal_chain_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL
value|AR_SM_OFFSET(BB_agc_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALMODE
value|AR_SM_OFFSET(BB_iq_adc_cal_mode)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FCAL_1
value|AR_SM_OFFSET(BB_fcal_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FCAL_2_0
value|AR_SM_OFFSET(BB_fcal_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DFT_TONE_CTL_0
value|AR_SM_OFFSET(BB_dft_tone_ctrl_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_CAL_CTL
value|AR_SM_OFFSET(BB_cl_cal_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_0_1_0
value|AR_SM_OFFSET(BB_cl_bbgain_map_0_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_2_3_0
value|AR_SM_OFFSET(BB_cl_bbgain_map_2_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_0
value|AR_SM_OFFSET(BB_cl_tab_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SYNTH_CONTROL
value|AR_SM_OFFSET(BB_synth_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADDAC_CLK_SEL
value|AR_SM_OFFSET(BB_addac_clk_select)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL
value|AR_SM_OFFSET(BB_pll_cntl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ANALOG_SWAP
value|AR_SM_OFFSET(BB_analog_swap)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADDAC_PARA_CTL
value|AR_SM_OFFSET(BB_addac_parallel_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_CFG
value|AR_SM_OFFSET(BB_force_analog)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_0_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_ctrl_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_1_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_ctrl_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_2_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_ctrl_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_3_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_ctrl_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_0_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_stat_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_1_B0_10
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_10.BB_aic_stat_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_0_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_ctrl_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_1_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_ctrl_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_2_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_ctrl_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_3_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_ctrl_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_4_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_ctrl_4_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_0_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_stat_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_1_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_stat_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_2_B0_20
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_aic_stat_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_0_B1_10
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_aic_ctrl_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_1_B1_10
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_aic_ctrl_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_0_B1_10
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_aic_stat_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_1_B1_10
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_aic_stat_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_0_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_ctrl_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_1_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_ctrl_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CTRL_4_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_ctrl_4_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_0_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_stat_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_1_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_stat_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STAT_2_B1_20
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_20.BB_aic_stat_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ADDR_B0
value|AR_SM_OFFSET(BB_tables_intf_addr_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_DATA_B0
value|AR_SM_OFFSET(BB_tables_intf_data_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ADDR_B1
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_tables_intf_addr_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_DATA_B1
value|AR_SM1_OFFSET(overlay_0x4b0.Jupiter_10.BB_tables_intf_data_b1)
end_define

begin_comment
comment|/* AIC fields */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_ENABLE_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_MAX_HOP_COUNT
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_MAX_HOP_COUNT_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_MIN_VALID_COUNT
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_MIN_VALID_COUNT_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_F_WLAN
value|0x0001FC00
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_F_WLAN_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_CH_VALID_RESET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_CH_VALID_RESET_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ENABLE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_BTTX_PWR_THR
value|0x000000FE
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_BTTX_PWR_THR_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_REF_DELAY
value|0x78000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_REF_DELAY_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ROT_ATT_DB_EST_ISO
value|0x07000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ROT_ATT_DB_EST_ISO_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_COM_ATT_DB_EST_ISO
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_COM_ATT_DB_EST_ISO_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_BT_IDLE_CFG
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_BT_IDLE_CFG_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_COND
value|0x00060000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_COND_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_ROT_ATT_DB
value|0x0001F800
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_ROT_ATT_DB_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_COM_ATT_DB
value|0x00000700
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_STDBY_COM_ATT_DB_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RSSI_MAX
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RSSI_MAX_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RSSI_MIN
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RSSI_MIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RADIO_DELAY
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_RADIO_DELAY_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_STEP_SIZE_CORR
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_STEP_SIZE_CORR_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ROT_IDX_CORR
value|0x000F8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ROT_IDX_CORR_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_CONV_CHECK_FACTOR
value|0x00006000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_CONV_CHECK_FACTOR_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_ROT_IDX_COUNT_MAX
value|0x00001C00
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_ROT_IDX_COUNT_MAX_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_TOGGLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_TOGGLE_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_AFTER_BTRX
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_AFTER_BTRX_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_SETTLING
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_SYNTH_SETTLING_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_MAX_HOP_COUNT
value|0x0FE00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_MAX_HOP_COUNT_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_MIN_STALE_COUNT
value|0x001FC000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_MIN_STALE_COUNT_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PWR_EST_LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PWR_EST_LONG_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PD_TALLY_SCALING
value|0x00001800
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PD_TALLY_SCALING_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PERF_THR
value|0x000007C0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_PERF_THR_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_COM_ATT_DB_FIXED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_COM_ATT_DB_FIXED_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_TARGET_MAG_SETTING
value|0x00000018
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_TARGET_MAG_SETTING_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_PERF_CHECK_FACTOR
value|0x00000006
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_PERF_CHECK_FACTOR_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_PWR_EST_LONG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_PWR_EST_LONG_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_DONE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_DONE_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_ACTIVE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_ACTIVE_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MEAS_COUNT
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MEAS_COUNT_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ANT_ISO_EST
value|0x00FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ANT_ISO_EST_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_HOP_COUNT
value|0x0003F800
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_HOP_COUNT_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_VALID_COUNT
value|0x000007F0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_VALID_COUNT_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_TOO_WEAK_ERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_TOO_WEAK_ERR_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_TOO_STRONG_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_BT_TOO_STRONG_ERR_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_DONE_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ACTIVE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_ACTIVE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MEAS_MAG_MIN
value|0xFFC00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MEAS_MAG_MIN_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_STALE_COUNT
value|0x003F8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_STALE_COUNT_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_HOP_COUNT
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_MON_HOP_COUNT_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_AIC_SM
value|0x000000F8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_CAL_AIC_SM_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SM
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SM_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VALID_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ROT_QUAD_ATT_DB
value|0x0000007E
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ROT_QUAD_ATT_DB_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VGA_QUAD_SIGN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VGA_QUAD_SIGN_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ROT_DIR_ATT_DB
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_ROT_DIR_ATT_DB_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VGA_DIR_SIGN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_VGA_DIR_SIGN_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_COM_ATT_6DB
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AIC_SRAM_COM_ATT_6DB_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_CF_OVERLAP_WINDOW
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_CF_OVERLAP_WINDOW_S
value|0
end_define

begin_comment
comment|/* BB_cl_tab_bx */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_CARR_LK_DC_ADD_I
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_CARR_LK_DC_ADD_I_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_CARR_LK_DC_ADD_Q
value|0x0000FFE0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_CARR_LK_DC_ADD_Q_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_GAIN_MOD
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_GAIN_MOD_S
value|0
end_define

begin_comment
comment|/* BB_vit_spur_mask_A fields */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_A_CF_PUNC_MASK_IDX_A
value|0x0001FC00
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_A_CF_PUNC_MASK_IDX_A_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_A_CF_PUNC_MASK_A
value|0x3FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_MASK_A_CF_PUNC_MASK_A_S
value|0
end_define

begin_comment
comment|/* enable_flt_svd*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ENABLE_FLT_SVD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_PHY_ENABLE_FLT_SVD_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST
value|AR_SM_OFFSET(BB_test_controls)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_BBB_OBS_SEL
value|0x780000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_BBB_OBS_SEL_S
value|19
end_define

begin_comment
comment|/* bits 19 to 22 are cf_bbb_obs_sel*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_RX_OBS_SEL_BIT5_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_RX_OBS_SEL_BIT5
value|(1<< AR_PHY_TEST_RX_OBS_SEL_BIT5_S)
end_define

begin_comment
comment|// This is bit 5 for cf_rx_obs_sel
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CHAIN_SEL
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CHAIN_SEL_S
value|30
end_define

begin_comment
comment|/*bits 30 and 31 are tstdac_out_sel which selects which chain to drive out*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_STATUS
value|AR_SM_OFFSET(BB_test_controls_status)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TSTDAC_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TSTDAC_EN_S
value|0
end_define

begin_comment
comment|/*cf_tstdac_en, driver to tstdac bus, 0=disable, 1=enable*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TX_OBS_SEL
value|0x1C
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TX_OBS_SEL_S
value|2
end_define

begin_comment
comment|/* cf_tx_obs_sel, bits 2:4*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TX_OBS_MUX_SEL
value|0x60
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TX_OBS_MUX_SEL_S
value|5
end_define

begin_comment
comment|/* cf_tx_obs_sel, bits 5:6, setting to 11 selects ADC*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TSTADC_EN
value|0x100
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_TSTADC_EN_S
value|8
end_define

begin_comment
comment|/*cf_tstadc_en, driver to tstadc bus, 0=disable, 1=enable*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_RX_OBS_SEL
value|0x3C00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_RX_OBS_SEL_S
value|10
end_define

begin_comment
comment|/* cf_tx_obs_sel, bits 10:13*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_DEBUGPORT_SEL
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TEST_CTL_DEBUGPORT_SEL_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_TSTDAC
value|AR_SM_OFFSET(BB_tstdac)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_STATUS
value|AR_SM_OFFSET(BB_channel_status)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_MEMORY
value|AR_SM_OFFSET(BB_chaninfo_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHNINFO_NOISEPWR
value|AR_SM_OFFSET(BB_chan_info_noise_pwr)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHNINFO_GAINDIFF
value|AR_SM_OFFSET(BB_chan_info_gain_diff)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHNINFO_FINETIM
value|AR_SM_OFFSET(BB_chan_info_fine_timing)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_0
value|AR_SM_OFFSET(BB_chan_info_gain_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SCRAMBLER_SEED
value|AR_SM_OFFSET(BB_scrambler_seed)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_TX_CTRL
value|AR_SM_OFFSET(BB_bbb_tx_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FIR
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_bbb_txfir_##_i)
end_define

begin_define
define|#
directive|define
name|AR_PHY_HEAVYCLIP_CTL
value|AR_SM_OFFSET(BB_heavy_clip_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_HEAVYCLIP_20
value|AR_SM_OFFSET(BB_heavy_clip_20)
end_define

begin_define
define|#
directive|define
name|AR_PHY_HEAVYCLIP_40
value|AR_SM_OFFSET(BB_heavy_clip_40)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ILLEGAL_TXRATE
value|AR_SM_OFFSET(BB_illegal_tx_rate)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_powertx_rate##_i)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PWRTX_MAX
value|AR_SM_OFFSET(BB_powertx_max)
end_define

begin_comment
comment|/* TPC register */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PWRTX_MAX_TPC_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_SUB
value|AR_SM_OFFSET(BB_powertx_sub)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PER_PACKET_POWERTX_MAX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_PER_PACKET_POWERTX_MAX_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_SUB_2_DISABLE
value|0xFFFFFFC0
end_define

begin_comment
comment|/* 2 chain */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_SUB_3_DISABLE
value|0xFFFFF000
end_define

begin_comment
comment|/* 3 chain */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_tpc_##_i)
end_define

begin_comment
comment|/* values 1-3, 7-10 and 12-15 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_4_B0
value|AR_SM_OFFSET(BB_tpc_4_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_5_B0
value|AR_SM_OFFSET(BB_tpc_5_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_6_B0
value|AR_SM_OFFSET(BB_tpc_6_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_18
value|AR_SM_OFFSET(BB_tpc_18)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_19
value|AR_SM_OFFSET(BB_tpc_19)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN
value|AR_SM_OFFSET(BB_tx_forced_gain)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PDADC_TAB_0
value|AR_SM_OFFSET(BB_pdadc_tab_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_rtt_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_TABLE_SW_INTF_B0
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_rtt_table_sw_intf_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_TABLE_SW_INTF_1_B0
value|AR_SM_OFFSET(overlay_0xa580.Jupiter_20.BB_rtt_table_sw_intf_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_0
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_POSEIDON(_ah) ?                                         \         AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiqcal_control_0) : \         AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiqcal_control_0))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_1
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_POSEIDON(_ah) ?                                         \         AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiqcal_control_1) : \         AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiqcal_control_1))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_START
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_POSEIDON(_ah) ?                                         \         AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiqcal_control_0) : \         AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiqcal_start))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_STATUS_B0
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_POSEIDON(_ah) ?                                         \         AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiqcal_status_b0) : \         AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiqcal_status_b0))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_B0
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiq_corr_coeff_01_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_23_B0
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiq_corr_coeff_23_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_45_B0
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiq_corr_coeff_45_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_67_B0
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_txiq_corr_coeff_67_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_B0_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiq_corr_coeff_01_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_23_B0_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiq_corr_coeff_23_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_45_B0_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiq_corr_coeff_45_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_67_B0_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_txiq_corr_coeff_67_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_TAB
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_tx_gain_tab_##_i)
end_define

begin_comment
comment|/* values 1-22 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_TAB_PAL
parameter_list|(
name|_i
parameter_list|)
value|AR_SM_OFFSET(BB_tx_gain_tab_pal_##_i)
end_define

begin_comment
comment|/* values 1-22 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PANIC_WD_STATUS
value|AR_SM_OFFSET(BB_panic_watchdog_status)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PANIC_WD_CTL_1
value|AR_SM_OFFSET(BB_panic_watchdog_ctrl_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PANIC_WD_CTL_2
value|AR_SM_OFFSET(BB_panic_watchdog_ctrl_2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BT_CTL
value|AR_SM_OFFSET(BB_bluetooth_cntl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ONLY_WARMRESET
value|AR_SM_OFFSET(BB_phyonly_warm_reset)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ONLY_CTL
value|AR_SM_OFFSET(BB_phyonly_control)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ECO_CTRL
value|AR_SM_OFFSET(BB_eco_ctrl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_1
value|AR_SM_OFFSET(BB_therm_adc_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_4
value|AR_SM_OFFSET(BB_therm_adc_4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM
parameter_list|(
name|_field
parameter_list|)
value|offsetof(struct radio65_reg, _field)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF1
value|AR_PHY_65NM(ch0_TXRF1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2
value|AR_PHY_65NM(ch0_TXRF2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_DB2G
value|0x07000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_DB2G_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_CCK
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_CCK_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_PSK
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_PSK_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_QAM
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF2_OB2G_QAM_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF3
value|AR_PHY_65NM(ch0_TXRF3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF3_CAPDIV2G
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF3_CAPDIV2G_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF3_OLD_PAL_SPARE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TXRF3_OLD_PAL_SPARE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_TXRF1
value|AR_PHY_65NM(ch1_TXRF1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_TXRF2
value|AR_PHY_65NM(ch1_TXRF2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_TXRF3
value|AR_PHY_65NM(ch1_TXRF3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_TXRF1
value|AR_PHY_65NM(ch2_TXRF1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_TXRF2
value|AR_PHY_65NM(ch2_TXRF2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_TXRF3
value|AR_PHY_65NM(ch2_TXRF3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_SYNTH4
value|AR_PHY_65NM(ch0_SYNTH4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SYNTH4_LONG_SHIFT_SELECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_SYNTH4_LONG_SHIFT_SELECT_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_SYNTH7
value|AR_PHY_65NM(ch0_SYNTH7)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BIAS1
value|AR_PHY_65NM(ch0_BIAS1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BIAS2
value|AR_PHY_65NM(ch0_BIAS2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BIAS4
value|AR_PHY_65NM(ch0_BIAS4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX4
value|AR_PHY_65NM(ch0_RXTX4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_SYNTH12
value|AR_PHY_65NM(ch0_SYNTH12)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_SYNTH12_VREFMUL3
value|0x00780000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_SYNTH12_VREFMUL3_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_RXTX4
value|AR_PHY_65NM(ch1_RXTX4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_RXTX4
value|AR_PHY_65NM(ch2_RXTX4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_RXTX4_XLNA_BIAS
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_RXTX4_XLNA_BIAS_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TOP
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_TOP)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TOP_JUPITER
value|AR_PHY_65NM(overlay_0x16180.Jupiter.ch0_TOP1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TOP_XPABIASLVL
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TOP_XPABIASLVL_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_TOP2
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_TOP2)
end_define

begin_define
define|#
directive|define
name|AR_OSPREY_CH0_XTAL
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_XTAL)
end_define

begin_define
define|#
directive|define
name|AR_OSPREY_CHO_XTAL_CAPINDAC
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_OSPREY_CHO_XTAL_CAPINDAC_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_OSPREY_CHO_XTAL_CAPOUTDAC
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|AR_OSPREY_CHO_XTAL_CAPOUTDAC_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_THERM)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_JUPITER
value|AR_PHY_65NM(overlay_0x16180.Jupiter.ch0_THERM)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_XPABIASLVL_MSB
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_XPABIASLVL_MSB_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_XPASHORT2GND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_XPASHORT2GND_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_SAR_ADC_OUT
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_SAR_ADC_OUT_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_START
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_START_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_LOCAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_THERM_LOCAL_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX1
value|AR_PHY_65NM(ch0_RXTX1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX2
value|AR_PHY_65NM(ch0_RXTX2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX2_SYNTHON_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX2_SYNTHON_MASK_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX2_SYNTHOVR_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX2_SYNTHOVR_MASK_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX3
value|AR_PHY_65NM(ch0_RXTX3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_RXTX1
value|AR_PHY_65NM(ch1_RXTX1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_RXTX2
value|AR_PHY_65NM(ch1_RXTX2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_RXTX3
value|AR_PHY_65NM(ch1_RXTX3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_RXTX1
value|AR_PHY_65NM(ch2_RXTX1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_RXTX2
value|AR_PHY_65NM(ch2_RXTX2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_RXTX3
value|AR_PHY_65NM(ch2_RXTX3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BB1
value|AR_PHY_65NM(ch0_BB1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BB2
value|AR_PHY_65NM(ch0_BB2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_BB3
value|AR_PHY_65NM(ch0_BB3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_BB1
value|AR_PHY_65NM(ch1_BB1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_BB2
value|AR_PHY_65NM(ch1_BB2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH1_BB3
value|AR_PHY_65NM(ch1_BB3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_BB1
value|AR_PHY_65NM(ch2_BB1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH2_BB2
value|AR_PHY_65NM(ch2_BB2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_SEL_OFST_READBK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_SEL_OFST_READBK_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_OFSTCORRI2VQ
value|0x03e00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_OFSTCORRI2VQ_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_OFSTCORRI2VI
value|0x7c000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH_BB3_OFSTCORRI2VI_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX1DB_BIQUAD_LONG_SHIFT
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX1DB_BIQUAD_LONG_SHIFT_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX6DB_BIQUAD_LONG_SHIFT
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX6DB_BIQUAD_LONG_SHIFT_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_LNAGAIN_LONG_SHIFT
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_LNAGAIN_LONG_SHIFT_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_MXRGAIN_LONG_SHIFT
value|0x03000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MXRGAIN_LONG_SHIFT_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_VGAGAIN_LONG_SHIFT
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_VGAGAIN_LONG_SHIFT_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_PHY_SCFIR_GAIN_LONG_SHIFT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_SCFIR_GAIN_LONG_SHIFT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_MANRXGAIN_LONG_SHIFT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_MANRXGAIN_LONG_SHIFT_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_MANTXGAIN_LONG_SHIFT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MANTXGAIN_LONG_SHIFT_S
value|31
end_define

begin_comment
comment|/*  * SM Field Definitions  */
end_comment

begin_comment
comment|/* BB_cl_cal_ctrl - AR_PHY_CL_CAL_CTL */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CL_CAL_ENABLE
value|0x00000002
end_define

begin_comment
comment|/* do carrier leak calibration after agc_calibrate_done */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PARALLEL_CAL_ENABLE
value|0x00000001
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
name|AR_PHY_CL_MAP_HW_GEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_HW_GEN_S
value|31
end_define

begin_comment
comment|/* BB_addac_parallel_control - AR_PHY_ADDAC_PARA_CTL */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ADDAC_PARACTL_OFF_PWDADC
value|0x00008000
end_define

begin_comment
comment|/* BB_fcal_2_b0 - AR_PHY_FCAL_2_0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FCAL20_CAP_STATUS_0
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_FCAL20_CAP_STATUS_0_S
value|20
end_define

begin_comment
comment|/* BB_rfbus_request */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ_EN
value|0x00000001
end_define

begin_comment
comment|/* request for RF bus */
end_comment

begin_comment
comment|/* BB_rfbus_grant */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_GRANT_EN
value|0x00000001
end_define

begin_comment
comment|/* RF bus granted */
end_comment

begin_comment
comment|/* BB_gen_controls */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_TURBO_MODE
value|0x00000001
end_define

begin_comment
comment|/* set turbo mode bits */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_TURBO_SHORT
value|0x00000002
end_define

begin_comment
comment|/* set short symbols to turbo mode setting */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_DYN2040_EN
value|0x00000004
end_define

begin_comment
comment|/* enable dyn 20/40 mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_DYN2040_PRI_ONLY
value|0x00000008
end_define

begin_comment
comment|/* dyn 20/40 - primary only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_DYN2040_PRI_CH
value|0x00000010
end_define

begin_comment
comment|/* dyn 20/40 - primary ch offset (0=+10MHz, 1=-10MHz)*/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_DYN2040_PRI_CH_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_GC_DYN2040_EXT_CH
value|0x00000020
end_define

begin_comment
comment|/* dyn 20/40 - ext ch spacing (0=20MHz/ 1=25MHz) */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_HT_EN
value|0x00000040
end_define

begin_comment
comment|/* ht enable */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_SHORT_GI_40
value|0x00000080
end_define

begin_comment
comment|/* allow short GI for HT 40 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_WALSH
value|0x00000100
end_define

begin_comment
comment|/* walsh spatial spreading for 2 chains,2 streams TX */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_SINGLE_HT_LTF1
value|0x00000200
end_define

begin_comment
comment|/* single length (4us) 1st HT long training symbol */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_GF_DETECT_EN
value|0x00000400
end_define

begin_comment
comment|/* enable Green Field detection. Only affects rx, not tx */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GC_ENABLE_DAC_FIFO
value|0x00000800
end_define

begin_comment
comment|/* fifo between bb and dac */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MS_HALF_RATE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_PHY_MS_QUARTER_RATE
value|0x00000040
end_define

begin_comment
comment|/* BB_analog_power_on_time */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY_DELAY
value|0x00003FFF
end_define

begin_comment
comment|/* delay from wakeup to rx ena */
end_comment

begin_comment
comment|/* BB_agc_control */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_CAL
value|0x00000001
end_define

begin_comment
comment|/* do internal calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_NF
value|0x00000002
end_define

begin_comment
comment|/* do noise-floor calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_OFFSET_CAL
value|0x00000800
end_define

begin_comment
comment|/* allow offset calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_ENABLE_NF
value|0x00008000
end_define

begin_comment
comment|/* enable noise floor calibration to happen */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_FLTR_CAL
value|0x00010000
end_define

begin_comment
comment|/* allow tx filter calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_NO_UPDATE_NF
value|0x00020000
end_define

begin_comment
comment|/* don't update noise floor automatically */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_EXT_NF_PWR_MEAS
value|0x00040000
end_define

begin_comment
comment|/* extend noise floor power measurement */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_CLC_SUCCESS
value|0x00080000
end_define

begin_comment
comment|/* carrier leak calibration done */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_PKDET_CAL
value|0x00100000
end_define

begin_comment
comment|/* allow peak deteter calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_YCOK_MAX
value|0x000003c0
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_YCOK_MAX_S
value|6
end_define

begin_comment
comment|/* BB_iq_adc_cal_mode */
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
comment|/* BB_analog_swap */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SWAP_ALT_CHAIN
value|0x00000040
end_define

begin_comment
comment|/* BB_modes_select */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_OFDM
value|0x00000000
end_define

begin_comment
comment|/* OFDM */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_CCK
value|0x00000001
end_define

begin_comment
comment|/* CCK */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DYNAMIC
value|0x00000004
end_define

begin_comment
comment|/* dynamic CCK/OFDM mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DYNAMIC_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_MODE_HALF
value|0x00000020
end_define

begin_comment
comment|/* enable half rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_QUARTER
value|0x00000040
end_define

begin_comment
comment|/* enable quarter rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MAC_CLK_MODE
value|0x00000080
end_define

begin_comment
comment|/* MAC runs at 128/141MHz clock */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DYN_CCK_DISABLE
value|0x00000100
end_define

begin_comment
comment|/* Disable dynamic CCK detection */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_SVD_HALF
value|0x00000200
end_define

begin_comment
comment|/* enable svd half rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DISABLE_CCK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_PHY_MODE_DISABLE_CCK_S
value|8
end_define

begin_comment
comment|/* BB_active */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE_EN
value|0x00000001
end_define

begin_comment
comment|/* Activate PHY chips */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE_DIS
value|0x00000000
end_define

begin_comment
comment|/* Deactivate PHY chips */
end_comment

begin_comment
comment|/* BB_force_analog */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FORCE_XPA_CFG
value|0x000000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCE_XPA_CFG_S
value|0
end_define

begin_comment
comment|/* BB_xpa_timing_control */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_TX_END_XPAB_OFF
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_TX_END_XPAB_OFF_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_TX_END_XPAA_OFF
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_TX_END_XPAA_OFF_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_FRAME_XPAB_ON
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_FRAME_XPAB_ON_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_FRAME_XPAA_ON
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_XPA_TIMING_CTL_FRAME_XPAA_ON_S
value|0
end_define

begin_comment
comment|/* BB_tx_timing_3 */
end_comment

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

begin_comment
comment|/* BB_tx_timing_2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_END_DATA_START
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_END_DATA_START_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_END_PA_ON
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_END_PA_ON_S
value|8
end_define

begin_comment
comment|/* BB_tpc_5_b0 */
end_comment

begin_comment
comment|/* ar2413 power control */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_OVERLAP
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_OVERLAP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_1
value|0x000003F0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_1_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_2
value|0x0000FC00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_2_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_3
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_3_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_4
value|0x0FC00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5_PD_GAIN_BOUNDARY_4_S
value|22
end_define

begin_comment
comment|/* BB_tpc_1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_NUM_PD_GAIN
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_NUM_PD_GAIN_S
value|14
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
name|AR_PHY_TPCGR1_FORCED_DAC_GAIN
value|0x0000003e
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCGR1_FORCED_DAC_GAIN_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCGR1_FORCE_DAC_GAIN
value|0x00000001
end_define

begin_comment
comment|/* BB_tx_forced_gain */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRA
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRA_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRB
value|0x0003c000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRB_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRC
value|0x003c0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRC_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRD
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_PADVGNRD_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXMXRGAIN
value|0x000003c0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXMXRGAIN_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXBB1DBGAIN
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXBB1DBGAIN_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXBB6DBGAIN
value|0x00000030
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXGAIN_FORCED_TXBB6DBGAIN_S
value|4
end_define

begin_comment
comment|/* BB_powertx_rate1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE1
value|0x9934
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE2
value|0x9938
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE_MAX
value|AR_PHY_PWRTX_MAX
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE_MAX_TPC_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* BB_test_controls */
end_comment

begin_define
define|#
directive|define
name|PHY_AGC_CLR
value|0x10000000
end_define

begin_comment
comment|/* disable AGC to A2 */
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

begin_comment
comment|/* BB_chan_info_gain_diff */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_DIFF_PPM_MASK
value|0xFFF
end_define

begin_comment
comment|/* PPM value is 12-bit signed integer */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_DIFF_PPM_SIGNED_BIT
value|0x800
end_define

begin_comment
comment|/* Sign bit */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_DIFF_UPPER_LIMIT
value|320
end_define

begin_comment
comment|/* Maximum absolute value */
end_comment

begin_comment
comment|/* BB_chaninfo_ctrl */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_MEMORY_CAPTURE_MASK
value|0x0001
end_define

begin_comment
comment|/* BB_search_start_delay */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY_DELAY
value|0x00003FFF
end_define

begin_comment
comment|/* delay from wakeup to rx ena */
end_comment

begin_comment
comment|/* BB_bbb_tx_ctrl */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCK_TX_CTRL_JAPAN
value|0x00000010
end_define

begin_comment
comment|/* BB_spectral_scan */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable spectral scan */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_ACTIVE
value|0x00000002
end_define

begin_comment
comment|/* Activate spectral scan */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_ACTIVE_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_FFT_PERIOD
value|0x000000F0
end_define

begin_comment
comment|/* Interval for FFT reports */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_FFT_PERIOD_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_PERIOD
value|0x0000FF00
end_define

begin_comment
comment|/* Interval for FFT reports */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_PERIOD_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_COUNT
value|0x0FFF0000
end_define

begin_comment
comment|/* Number of reports */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_COUNT_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_SHORT_REPEAT
value|0x10000000
end_define

begin_comment
comment|/* Short repeat */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_SHORT_REPEAT_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_PRIORITY_HI
value|0x20000000
end_define

begin_comment
comment|/* high priority */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SPECTRAL_SCAN_PRIORITY_HI_S
value|29
end_define

begin_comment
comment|/* BB_channel_status */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHANNEL_STATUS_RX_CLEAR
value|0x00000004
end_define

begin_comment
comment|/* BB_rtt_ctrl */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_ENA_RADIO_RETENTION
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_ENA_RADIO_RETENTION_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_RESTORE_MASK
value|0x0000007E
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_RESTORE_MASK_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_FORCE_RADIO_RESTORE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_CTRL_FORCE_RADIO_RESTORE_S
value|7
end_define

begin_comment
comment|/* BB_rtt_table_sw_intf_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ACCESS_0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ACCESS_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_WRITE_0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_WRITE_0_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ADDR_0
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ADDR_0_S
value|2
end_define

begin_comment
comment|/* BB_rtt_table_sw_intf_1_b0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_DATA_0
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_DATA_0_S
value|4
end_define

begin_comment
comment|/* BB_txiqcal_control_0 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_0_ENABLE_TXIQ_CAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_0_ENABLE_TXIQ_CAL_S
value|31
end_define

begin_comment
comment|/* BB_txiqcal_control_1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_1_IQCORR_I_Q_COFF_DELPT
value|0x01fc0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CONTROL_1_IQCORR_I_Q_COFF_DELPT_S
value|18
end_define

begin_comment
comment|/* BB_txiqcal_start */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_START_DO_CAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_START_DO_CAL_S
value|0
end_define

begin_comment
comment|/* BB_txiqcal_start for Poseidon */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_START_DO_CAL_POSEIDON
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_START_DO_CAL_POSEIDON_S
value|31
end_define

begin_comment
comment|/* Generic B0, B1, B2 IQ Cal bit fields */
end_comment

begin_comment
comment|/* BB_txiqcal_status_b* */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_STATUS_FAILED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALIBRATED_GAINS_0_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_CALIBRATED_GAINS_0
value|(0x1f<<AR_PHY_CALIBRATED_GAINS_0_S)
end_define

begin_comment
comment|/* BB_txiq_corr_coeff_01_b* */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_00_COEFF_TABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_00_COEFF_TABLE
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_COEFF_TABLE_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_COEFF_TABLE
value|(0x00003fff<<AR_PHY_TX_IQCAL_CORR_COEFF_01_COEFF_TABLE_S)
end_define

begin_comment
comment|/* temp compensation */
end_comment

begin_comment
comment|/* BB_tpc_18 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_THERM_CAL_VALUE
value|0xff
end_define

begin_comment
comment|//Mask bits 7:0
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_THERM_CAL_VALUE_S
value|0
end_define

begin_comment
comment|/* BB_tpc_19 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_19_ALPHA_THERM
value|0xff
end_define

begin_comment
comment|//Mask bits 7:0
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TPC_19_ALPHA_THERM_S
value|0
end_define

begin_comment
comment|/* ch0_RXTX4 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX4_THERM_ON
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_65NM_CH0_RXTX4_THERM_ON_S
value|28
end_define

begin_comment
comment|/* BB_therm_adc_1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_1_INIT_THERM
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_1_INIT_THERM_S
value|0
end_define

begin_comment
comment|/* BB_therm_adc_4 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_4_LATEST_THERM
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_THERM_ADC_4_LATEST_THERM_S
value|0
end_define

begin_comment
comment|/* BB_switch_table_chn_b */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R0_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R1_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R12
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_TABLE_R12_S
value|8
end_define

begin_comment
comment|/*  * Channel 1 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_CHAN1_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_chn1_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_CHAN1_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_CHAN1_BASE + offsetof(struct chn1_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_1
value|AR_CHAN1_OFFSET(BB_timing_control_4_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_1
value|AR_CHAN1_OFFSET(BB_ext_chan_pwr_thr_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PHASE_RAMP_1
value|AR_CHAN1_OFFSET(BB_tx_phase_ramp_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_GAIN_DC_CORR_1
value|AR_CHAN1_OFFSET(BB_adc_gain_dc_corr_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_0_B1
value|AR_CHAN_OFFSET(BB_iq_adc_meas_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_1_B1
value|AR_CHAN_OFFSET(BB_iq_adc_meas_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_2_B1
value|AR_CHAN_OFFSET(BB_iq_adc_meas_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_3_B1
value|AR_CHAN_OFFSET(BB_iq_adc_meas_3_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQ_CORR_1
value|AR_CHAN1_OFFSET(BB_tx_iq_corr_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REPORT_1
value|AR_CHAN1_OFFSET(BB_spur_report_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_TAB_1
value|AR_CHAN1_OFFSET(BB_chan_info_chan_tab_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_B1
value|AR_CHAN1_OFFSET(BB_rx_iq_corr_b1)
end_define

begin_comment
comment|/*  * Channel 1 Field Definitions  */
end_comment

begin_comment
comment|/* BB_ext_chan_pwr_thr_2_b1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_EXT_MINCCA_PWR_S
value|16
end_define

begin_comment
comment|/*  * AGC 1 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_AGC1_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_agc1_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_AGC1_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_AGC1_BASE + offsetof(struct agc1_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCEMAX_GAINS_1
value|AR_AGC1_OFFSET(BB_gain_force_max_gains_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAINS_MINOFF_1
value|AR_AGC1_OFFSET(BB_gains_min_offsets_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_1
value|AR_AGC1_OFFSET(BB_ext_atten_switch_ctl_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_1
value|AR_AGC1_OFFSET(BB_cca_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_CTRL_1
value|AR_AGC1_OFFSET(BB_cca_ctrl_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RSSI_1
value|AR_AGC1_OFFSET(BB_rssi_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_CCK_REP_1
value|AR_AGC1_OFFSET(BB_spur_est_cck_report_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_OCGAIN_2
value|AR_AGC1_OFFSET(BB_rx_ocgain2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_STATUS_I_B1
value|AR_AGC1_OFFSET(BB_agc_dig_dc_status_i_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DIG_DC_STATUS_Q_B1
value|AR_AGC1_OFFSET(BB_agc_dig_dc_status_q_b1)
end_define

begin_comment
comment|/*  * AGC 1 Register Map for Poseidon  */
end_comment

begin_define
define|#
directive|define
name|AR_AGC1_BASE_POSEIDON
value|offsetof(struct bb_reg_map, overlay_0xa800.Poseidon.bb_agc1_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_AGC1_OFFSET_POSEIDON
parameter_list|(
name|_x
parameter_list|)
value|(AR_AGC1_BASE_POSEIDON + offsetof(struct agc1_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCEMAX_GAINS_1_POSEIDON
value|AR_AGC1_OFFSET_POSEIDON(BB_gain_force_max_gains_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_1_POSEIDON
value|AR_AGC1_OFFSET_POSEIDON(BB_ext_atten_switch_ctl_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RSSI_1_POSEIDON
value|AR_AGC1_OFFSET_POSEIDON(BB_rssi_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_OCGAIN_2_POSEIDON
value|AR_AGC1_OFFSET_POSEIDON(BB_rx_ocgain2)
end_define

begin_comment
comment|/*  * AGC 1 Field Definitions  */
end_comment

begin_comment
comment|/* BB_cca_b1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CH1_MINCCA_PWR
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_MINCCA_PWR_S
value|20
end_define

begin_comment
comment|/*  * SM 1 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_SM1_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_sm1_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_SM1_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_SM1_BASE + offsetof(struct sm1_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN_1
value|AR_SM1_OFFSET(BB_switch_table_chn_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FCAL_2_1
value|AR_SM1_OFFSET(BB_fcal_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DFT_TONE_CTL_1
value|AR_SM1_OFFSET(BB_dft_tone_ctrl_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_0_1_1
value|AR_SM1_OFFSET(BB_cl_bbgain_map_0_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_2_3_1
value|AR_SM1_OFFSET(BB_cl_bbgain_map_2_3_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_1
value|AR_SM1_OFFSET(BB_cl_tab_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_1
value|AR_SM1_OFFSET(BB_chan_info_gain_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_4_B1
value|AR_SM1_OFFSET(BB_tpc_4_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_5_B1
value|AR_SM1_OFFSET(BB_tpc_5_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_6_B1
value|AR_SM1_OFFSET(BB_tpc_6_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B1
value|AR_SM1_OFFSET(BB_tpc_11_b1)
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_PHY_TPC_19_B1
value|AR_SM1_OFFSET(overlay_b440.Scorpion.BB_tpc_19_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PDADC_TAB_1
value|AR_SM1_OFFSET(overlay_b440.BB_pdadc_tab_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_TABLE_SW_INTF_B1
value|AR_SM1_OFFSET(overlay_b440.Jupiter_20.BB_rtt_table_sw_intf_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_TABLE_SW_INTF_1_B1
value|AR_SM1_OFFSET(overlay_b440.Jupiter_20.BB_rtt_table_sw_intf_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_STATUS_B1
value|AR_SM1_OFFSET(BB_txiqcal_status_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_B1
value|AR_SM1_OFFSET(BB_txiq_corr_coeff_01_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_23_B1
value|AR_SM1_OFFSET(BB_txiq_corr_coeff_23_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_45_B1
value|AR_SM1_OFFSET(BB_txiq_corr_coeff_45_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_67_B1
value|AR_SM1_OFFSET(BB_txiq_corr_coeff_67_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_0_B1
value|AR_SM1_OFFSET(BB_cl_map_0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_1_B1
value|AR_SM1_OFFSET(BB_cl_map_1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_2_B1
value|AR_SM1_OFFSET(BB_cl_map_2_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_MAP_3_B1
value|AR_SM1_OFFSET(BB_cl_map_3_b1)
end_define

begin_comment
comment|/*  * SM 1 Field Definitions  */
end_comment

begin_comment
comment|/* BB_rtt_table_sw_intf_b1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ACCESS_1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ACCESS_1_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_WRITE_1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_WRITE_1_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ADDR_1
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_ADDR_1_S
value|2
end_define

begin_comment
comment|/* BB_rtt_table_sw_intf_1_b1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_DATA_1
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|AR_PHY_RTT_SW_RTT_TABLE_DATA_1_S
value|4
end_define

begin_comment
comment|/*  * SM 1 Register Map for Poseidon  */
end_comment

begin_define
define|#
directive|define
name|AR_SM1_BASE_POSEIDON
value|offsetof(struct bb_reg_map, overlay_0xa800.Poseidon.bb_sm1_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_SM1_OFFSET_POSEIDON
parameter_list|(
name|_x
parameter_list|)
value|(AR_SM1_BASE_POSEIDON + offsetof(struct sm1_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN_1_POSEIDON
value|AR_SM1_OFFSET_POSEIDON(BB_switch_table_chn_b1)
end_define

begin_comment
comment|/*  * Channel 2 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_CHAN2_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_chn2_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_CHAN2_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_CHAN2_BASE + offsetof(struct chn2_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING4_2
value|AR_CHAN2_OFFSET(BB_timing_control_4_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_CCA_2
value|AR_CHAN2_OFFSET(BB_ext_chan_pwr_thr_2_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PHASE_RAMP_2
value|AR_CHAN2_OFFSET(BB_tx_phase_ramp_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_GAIN_DC_CORR_2
value|AR_CHAN2_OFFSET(BB_adc_gain_dc_corr_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_0_B2
value|AR_CHAN_OFFSET(BB_iq_adc_meas_0_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_1_B2
value|AR_CHAN_OFFSET(BB_iq_adc_meas_1_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_2_B2
value|AR_CHAN_OFFSET(BB_iq_adc_meas_2_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_IQ_ADC_MEAS_3_B2
value|AR_CHAN_OFFSET(BB_iq_adc_meas_3_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQ_CORR_2
value|AR_CHAN2_OFFSET(BB_tx_iq_corr_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_REPORT_2
value|AR_CHAN2_OFFSET(BB_spur_report_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_TAB_2
value|AR_CHAN2_OFFSET(BB_chan_info_chan_tab_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_IQCAL_CORR_B2
value|AR_CHAN2_OFFSET(BB_rx_iq_corr_b2)
end_define

begin_comment
comment|/*  * Channel 2 Field Definitions  */
end_comment

begin_comment
comment|/* BB_ext_chan_pwr_thr_2_b2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_EXT_MINCCA_PWR_S
value|16
end_define

begin_comment
comment|/*  * AGC 2 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_AGC2_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_agc2_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_AGC2_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_AGC2_BASE + offsetof(struct agc2_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_FORCEMAX_GAINS_2
value|AR_AGC2_OFFSET(BB_gain_force_max_gains_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAINS_MINOFF_2
value|AR_AGC2_OFFSET(BB_gains_min_offsets_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL_2
value|AR_AGC2_OFFSET(BB_ext_atten_switch_ctl_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_2
value|AR_AGC2_OFFSET(BB_cca_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_CTRL_2
value|AR_AGC2_OFFSET(BB_cca_ctrl_2_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_RSSI_2
value|AR_AGC2_OFFSET(BB_rssi_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_SPUR_CCK_REP_2
value|AR_AGC2_OFFSET(BB_spur_est_cck_report_b2)
end_define

begin_comment
comment|/*  * AGC 2 Field Definitions  */
end_comment

begin_comment
comment|/* BB_cca_b2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CH2_MINCCA_PWR
value|0x1FF00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH2_MINCCA_PWR_S
value|20
end_define

begin_comment
comment|/*  * SM 2 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_SM2_BASE
value|offsetof(struct bb_reg_map, overlay_0xa800.Osprey.bb_sm2_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_SM2_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_SM2_BASE + offsetof(struct sm2_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN_2
value|AR_SM2_OFFSET(BB_switch_table_chn_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_FCAL_2_2
value|AR_SM2_OFFSET(BB_fcal_2_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_DFT_TONE_CTL_2
value|AR_SM2_OFFSET(BB_dft_tone_ctrl_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_0_1_2
value|AR_SM2_OFFSET(BB_cl_bbgain_map_0_1_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BBGAINMAP_2_3_2
value|AR_SM2_OFFSET(BB_cl_bbgain_map_2_3_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_2
value|AR_SM2_OFFSET(BB_cl_tab_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_GAIN_2
value|AR_SM2_OFFSET(BB_chan_info_gain_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_4_B2
value|AR_SM2_OFFSET(BB_tpc_4_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_5_B2
value|AR_SM2_OFFSET(BB_tpc_5_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_6_B2
value|AR_SM2_OFFSET(BB_tpc_6_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B2
value|AR_SM2_OFFSET(BB_tpc_11_b2)
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_PHY_TPC_19_B2
value|AR_SM2_OFFSET(overlay_c440.Scorpion.BB_tpc_19_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PDADC_TAB_2
value|AR_SM2_OFFSET(overlay_c440.BB_pdadc_tab_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_STATUS_B2
value|AR_SM2_OFFSET(BB_txiqcal_status_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_01_B2
value|AR_SM2_OFFSET(BB_txiq_corr_coeff_01_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_23_B2
value|AR_SM2_OFFSET(BB_txiq_corr_coeff_23_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_45_B2
value|AR_SM2_OFFSET(BB_txiq_corr_coeff_45_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_CORR_COEFF_67_B2
value|AR_SM2_OFFSET(BB_txiq_corr_coeff_67_b2)
end_define

begin_comment
comment|/*  * bb_chn_ext_reg_map  */
end_comment

begin_define
define|#
directive|define
name|AR_CHN_EXT_BASE_POSEIDON
value|offsetof(struct bb_reg_map, overlay_0xa800.Poseidon.bb_chn_ext_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_CHN_EXT_OFFSET_POSEIDON
parameter_list|(
name|_x
parameter_list|)
value|(AR_CHN_EXT_BASE_POSEIDON + offsetof(struct chn_ext_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_POSEIDON
value|AR_CHN_EXT_OFFSET_POSEIDON(BB_paprd_valid_obdb_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_0
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_1
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_1_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_2
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_2_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_3
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_3_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_4
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_VALID_OBDB_4_S
value|24
end_define

begin_comment
comment|/* BB_txiqcal_status_b1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TX_IQCAL_STATUS_B2_FAILED
value|0x00000001
end_define

begin_comment
comment|/*  * AGC 3 Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_AGC3_BASE
value|offsetof(struct bb_reg_map, bb_agc3_reg_map)
end_define

begin_define
define|#
directive|define
name|AR_AGC3_OFFSET
parameter_list|(
name|_x
parameter_list|)
value|(AR_AGC3_BASE + offsetof(struct agc3_reg_map, _x))
end_define

begin_define
define|#
directive|define
name|AR_PHY_RSSI_3
value|AR_AGC3_OFFSET(BB_rssi_b3)
end_define

begin_comment
comment|/*  * Misc helper defines  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHAIN_OFFSET
value|(AR_CHAN1_BASE - AR_CHAN_BASE)
end_define

begin_define
define|#
directive|define
name|AR_PHY_NEW_ADC_DC_GAIN_CORR
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_ADC_GAIN_DC_CORR_0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_SWITCH_CHAIN
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_SWITCH_CHAIN_0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_EXT_ATTEN_CTL
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_EXT_ATTEN_CTL_0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_FORCEMAX_GAINS_0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_TPC_5_B0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_PDADC_TAB
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_PDADC_TAB_0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_0
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_IQ_ADC_MEAS_0_B0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_1
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_IQ_ADC_MEAS_1_B0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_2
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_IQ_ADC_MEAS_2_B0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CAL_MEAS_3
parameter_list|(
name|_i
parameter_list|)
value|(AR_PHY_IQ_ADC_MEAS_3_B0 + (AR_PHY_CHAIN_OFFSET * (_i)))
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHIP_ID
value|0x9818
end_define

begin_comment
comment|/* PHY chip revision ID */
end_comment

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
name|AR_PHY_CHIP_ID_SOWL_REV_0
value|0xb0
end_define

begin_comment
comment|/* 9160 Rev 0 (sowl 1.0) BB */
end_comment

begin_comment
comment|/* BB Panic Watchdog control register 1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_NON_IDLE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_IDLE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_IDLE_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_NON_IDLE_MASK
value|0x0000FFFC
end_define

begin_comment
comment|/* BB Panic Watchdog control register 2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_RST_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_IRQ_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_PANIC_CNTL2_MASK
value|0xFFFFFFF9
end_define

begin_comment
comment|/* BB Panic Watchdog status register */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_STATUS
value|0x00000007
end_define

begin_comment
comment|/* snapshot of r_panic_watchdog_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_STATUS_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_DET_HANG
value|0x00000008
end_define

begin_comment
comment|/* panic_watchdog_det_hang */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_DET_HANG_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RADAR_SM
value|0x000000F0
end_define

begin_comment
comment|/* snapshot of radar state machine r_rdr_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RADAR_SM_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RX_OFDM_SM
value|0x00000F00
end_define

begin_comment
comment|/* snapshot of rx state machine (OFDM) r_rx_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RX_OFDM_SM_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RX_CCK_SM
value|0x0000F000
end_define

begin_comment
comment|/* snapshot of rx state machine (CCK) r_rx_sm_cck */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_RX_CCK_SM_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_TX_OFDM_SM
value|0x000F0000
end_define

begin_comment
comment|/* snapshot of tx state machine (OFDM) r_tx_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_TX_OFDM_SM_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_TX_CCK_SM
value|0x00F00000
end_define

begin_comment
comment|/* snapshot of tx state machine (CCK) r_tx_sm_cck */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_TX_CCK_SM_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_AGC_SM
value|0x0F000000
end_define

begin_comment
comment|/* snapshot of AGC state machine r_agc_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_AGC_SM_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_SRCH_SM
value|0xF0000000
end_define

begin_comment
comment|/* snapshot of agc search state machine r_srch_sm */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_SRCH_SM_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_WD_STATUS_CLR
value|0x00000008
end_define

begin_comment
comment|/* write 0 to reset watchdog */
end_comment

begin_comment
comment|/***** PAPRD *****/
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2AM
value|AR_CHAN_OFFSET(BB_paprd_am2am_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2AM_MASK
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2AM_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2PM
value|AR_CHAN_OFFSET(BB_paprd_am2pm_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2PM_MASK
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_AM2PM_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_HT40
value|AR_CHAN_OFFSET(BB_paprd_ht40_mask)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_HT40_MASK
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_HT40_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0
value|AR_CHAN_OFFSET(BB_paprd_ctrl0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_PAPRD_ENABLE_0
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_PAPRD_ENABLE_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_USE_SINGLE_TABLE_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_USE_SINGLE_TABLE_MASK_S
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_PAPRD_MAG_THRSH_0
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B0_PAPRD_MAG_THRSH_0_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0
value|AR_CHAN_OFFSET(BB_paprd_ctrl1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PAPRD_POWER_AT_AM2AM_CAL_0
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PAPRD_POWER_AT_AM2AM_CAL_0_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_AM2PM_ENABLE_0
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_AM2PM_ENABLE_0_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_AM2AM_ENABLE_0
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_AM2AM_ENABLE_0_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_SCALING_ENA
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_ADAPTIVE_SCALING_ENA_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PA_GAIN_SCALE_FACT_0_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PA_GAIN_SCALE_FACT_0_MASK_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PAPRD_MAG_SCALE_FACT_0
value|0x7FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B0_PAPRD_MAG_SCALE_FACT_0_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1
value|AR_CHAN1_OFFSET(BB_paprd_ctrl0_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_MAG_THRSH_1
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_MAG_THRSH_1_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_ADAPTIVE_USE_SINGLE_TABLE_1
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_ADAPTIVE_USE_SINGLE_TABLE_1_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_ENABLE_1
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B1_PAPRD_ENABLE_1_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1
value|AR_CHAN1_OFFSET(BB_paprd_ctrl1_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PAPRD_POWER_AT_AM2AM_CAL_1
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PAPRD_POWER_AT_AM2AM_CAL_1_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_AM2PM_ENABLE_1
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_AM2PM_ENABLE_1_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_AM2AM_ENABLE_1
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_AM2AM_ENABLE_1_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_SCALING_ENA
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_ADAPTIVE_SCALING_ENA_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PA_GAIN_SCALE_FACT_1_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PA_GAIN_SCALE_FACT_1_MASK_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PAPRD_MAG_SCALE_FACT_1
value|0x7FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B1_PAPRD_MAG_SCALE_FACT_1_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2
value|AR_CHAN2_OFFSET(BB_paprd_ctrl0_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_MAG_THRSH_2
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_MAG_THRSH_2_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_ADAPTIVE_USE_SINGLE_TABLE_2
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_ADAPTIVE_USE_SINGLE_TABLE_2_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_ENABLE_2
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL0_B2_PAPRD_ENABLE_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2
value|AR_CHAN2_OFFSET(BB_paprd_ctrl1_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PAPRD_POWER_AT_AM2AM_CAL_2
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PAPRD_POWER_AT_AM2AM_CAL_2_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_AM2PM_ENABLE_2
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_AM2PM_ENABLE_2_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_AM2AM_ENABLE_2
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_AM2AM_ENABLE_2_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_SCALING_ENA
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_ADAPTIVE_SCALING_ENA_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PA_GAIN_SCALE_FACT_2_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PA_GAIN_SCALE_FACT_2_MASK_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PAPRD_MAG_SCALE_FACT_2
value|0x7FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_CTRL1_B2_PAPRD_MAG_SCALE_FACT_2_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_cntl1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_cntl1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_LB_SKIP
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_LB_SKIP_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_LB_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_LB_ENABLE_S
value|11
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_TX_GAIN_FORCE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_TX_GAIN_FORCE_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_RX_BB_GAIN_FORCE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_RX_BB_GAIN_FORCE_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_IQCORR_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_IQCORR_ENABLE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_AGC2_SETTLING
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_PAPRD_AGC2_SETTLING_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_CF_PAPRD_TRAIN_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL1_CF_CF_PAPRD_TRAIN_ENABLE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL2
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_cntl2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL2_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_cntl2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL2_CF_PAPRD_INIT_RX_BB_GAIN
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL2_CF_PAPRD_INIT_RX_BB_GAIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_cntl3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_cntl3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_BBTXMIX_DISABLE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_BBTXMIX_DISABLE_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_FINE_CORR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_FINE_CORR_LEN_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_COARSE_CORR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_COARSE_CORR_LEN_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_COARSE_CORR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_COARSE_CORR_LEN_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_NUM_CORR_STAGES
value|0x7
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_NUM_CORR_STAGES_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_MIN_LOOPBACK_DEL
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_MIN_LOOPBACK_DEL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_QUICK_DROP
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_QUICK_DROP_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_ADC_DESIRED_SIZE
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL3_CF_PAPRD_ADC_DESIRED_SIZE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_cntl4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_cntl4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_NUM_TRAIN_SAMPLES
value|0x3FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_NUM_TRAIN_SAMPLES_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_SAFETY_DELTA
value|0xF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_SAFETY_DELTA_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_MIN_CORR
value|0xFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_CNTL4_CF_PAPRD_MIN_CORR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_0_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_0_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_0_B0_PAPRD_PRE_POST_SCALING_0_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_0_B0_PAPRD_PRE_POST_SCALING_0_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_1_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_1_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_1_B0_PAPRD_PRE_POST_SCALING_1_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_1_B0_PAPRD_PRE_POST_SCALING_1_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_2_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_2_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_2_B0_PAPRD_PRE_POST_SCALING_2_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_2_B0_PAPRD_PRE_POST_SCALING_2_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_3_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_3_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_3_B0_PAPRD_PRE_POST_SCALING_3_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_3_B0_PAPRD_PRE_POST_SCALING_3_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_4_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_4_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_4_B0_PAPRD_PRE_POST_SCALING_4_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_4_B0_PAPRD_PRE_POST_SCALING_4_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_5_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_5_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_5_B0_PAPRD_PRE_POST_SCALING_5_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_5_B0_PAPRD_PRE_POST_SCALING_5_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_6_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_6_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_6_B0_PAPRD_PRE_POST_SCALING_6_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_6_B0_PAPRD_PRE_POST_SCALING_6_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_7_B0
value|AR_CHAN_OFFSET(BB_paprd_pre_post_scale_7_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_7_B0_PAPRD_PRE_POST_SCALING_7_0
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_PRE_POST_SCALE_7_B0_PAPRD_PRE_POST_SCALING_7_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_stat1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_stat1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_AGC2_PWR
value|0xff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_AGC2_PWR_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_RX_GAIN_IDX
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_RX_GAIN_IDX_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_ACTIVE
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_ACTIVE_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_CORR_ERR
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_CORR_ERR_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_INCOMPLETE
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_INCOMPLETE_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_DONE
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT1_PAPRD_TRAIN_DONE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_stat2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_stat2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_FINE_IDX
value|0x3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_FINE_IDX_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_COARSE_IDX
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_COARSE_IDX_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_FINE_VAL
value|0xffff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT2_PAPRD_FINE_VAL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT3
value|AR_SM_OFFSET(overlay_0xa580.Osprey.BB_paprd_trainer_stat3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT3_POSEIDON
value|AR_SM_OFFSET(overlay_0xa580.Poseidon.BB_paprd_trainer_stat3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT3_PAPRD_TRAIN_SAMPLES_CNT
value|0xfffff
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_TRAINER_STAT3_PAPRD_TRAIN_SAMPLES_CNT_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_12
value|AR_SM_OFFSET(BB_tpc_12)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_12_DESIRED_SCALE_HT40_5
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_12_DESIRED_SCALE_HT40_5_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_19_ALT_ALPHA_VOLT
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_19_ALT_ALPHA_VOLT_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_ALT_THERM_CAL_VALUE
value|0xff
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_ALT_THERM_CAL_VALUE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_ALT_VOLT_CAL_VALUE
value|0xff
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_18_ALT_VOLT_CAL_VALUE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_THERM_ADC_4
value|AR_SM_OFFSET(BB_therm_adc_4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_THERM_ADC_4_LATEST_THERM_VALUE
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_THERM_ADC_4_LATEST_THERM_VALUE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_THERM_ADC_4_LATEST_VOLT_VALUE
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_THERM_ADC_4_LATEST_VOLT_VALUE_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B0
value|AR_SM_OFFSET(BB_tpc_11_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B0_OLPC_GAIN_DELTA_0
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B0_OLPC_GAIN_DELTA_0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B1
value|AR_SM1_OFFSET(BB_tpc_11_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B1_OLPC_GAIN_DELTA_1
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B1_OLPC_GAIN_DELTA_1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B2
value|AR_SM2_OFFSET(BB_tpc_11_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B2_OLPC_GAIN_DELTA_2
value|0xFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_11_B2_OLPC_GAIN_DELTA_2_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXBB1DBGAIN
value|0x7
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXBB1DBGAIN_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXBB6DBGAIN
value|0x3
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXBB6DBGAIN_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXMXRGAIN
value|0xf
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_TXMXRGAIN_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNA
value|0xf
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNA_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNB
value|0xf
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNB_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNC
value|0xf
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGNC_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGND
value|0x3
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_PADRVGND_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_ENABLE_PAL
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCED_ENABLE_PAL_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCE_TX_GAIN
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FORCED_GAIN_FORCE_TX_GAIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_1
value|AR_SM_OFFSET(BB_tpc_1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_1_FORCED_DAC_GAIN
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_1_FORCED_DAC_GAIN_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_1_FORCE_DAC_GAIN
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPC_1_FORCE_DAC_GAIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_MEMORY_CHANINFOMEM_S2_READ
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_CHAN_INFO_MEMORY_CHANINFOMEM_S2_READ_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_MEM_TAB_B0
value|AR_CHAN_OFFSET(BB_paprd_mem_tab_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_MEM_TAB_B1
value|AR_CHAN1_OFFSET(BB_paprd_mem_tab_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPRD_MEM_TAB_B2
value|AR_CHAN2_OFFSET(BB_paprd_mem_tab_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B0
value|AR_CHAN_OFFSET(BB_pa_gain123_b0)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B0_PA_GAIN1_0
value|0x3FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B0_PA_GAIN1_0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B1
value|AR_CHAN1_OFFSET(BB_pa_gain123_b1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B1_PA_GAIN1_1
value|0x3FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B1_PA_GAIN1_1_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B2
value|AR_CHAN2_OFFSET(BB_pa_gain123_b2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B2_PA_GAIN1_2
value|0x3FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_PA_GAIN123_B2_PA_GAIN1_2_S
value|0
end_define

begin_comment
comment|//Legacy 54M
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE2
value|AR_SM_OFFSET(BB_powertx_rate2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE2_POWERTX54M_7
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE2_POWERTX54M_7_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE5
value|AR_SM_OFFSET(BB_powertx_rate5)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE5_POWERTXHT20_0
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE5_POWERTXHT20_0_S
value|0
end_define

begin_comment
comment|//HT20 MCS5
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE5_POWERTXHT20_3
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE5_POWERTXHT20_3_S
value|24
end_define

begin_comment
comment|//HT20 MCS7
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE6
value|AR_SM_OFFSET(BB_powertx_rate6)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE6_POWERTXHT20_5
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE6_POWERTXHT20_5_S
value|8
end_define

begin_comment
comment|//HT20 MCS6
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE6_POWERTXHT20_4
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE6_POWERTXHT20_4_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE7
value|AR_SM_OFFSET(BB_powertx_rate7)
end_define

begin_comment
comment|//HT40 MCS5
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE7_POWERTXHT40_3
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE7_POWERTXHT40_3_S
value|24
end_define

begin_comment
comment|//HT40 MCS7
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE8
value|AR_SM_OFFSET(BB_powertx_rate8)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE8_POWERTXHT40_5
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE8_POWERTXHT40_5_S
value|8
end_define

begin_comment
comment|//HT40 MCS6
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE8_POWERTXHT40_4
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE8_POWERTXHT40_4_S
value|0
end_define

begin_comment
comment|//HT20 MCS15
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE10
value|AR_SM_OFFSET(BB_powertx_rate10)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE10_POWERTXHT20_9
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE10_POWERTXHT20_9_S
value|8
end_define

begin_comment
comment|//HT20 MCS23
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE11
value|AR_SM_OFFSET(BB_powertx_rate11)
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE11_POWERTXHT20_13
value|0x3F
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWERTX_RATE11_POWERTXHT20_13_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_0_CL_GAIN_MOD
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_0_CL_GAIN_MOD_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_1_CL_GAIN_MOD
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_1_CL_GAIN_MOD_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_2_CL_GAIN_MOD
value|0x1F
end_define

begin_define
define|#
directive|define
name|AR_PHY_CL_TAB_2_CL_GAIN_MOD_S
value|0
end_define

begin_comment
comment|/*  * Hornet/Poseidon Analog Registers  */
end_comment

begin_define
define|#
directive|define
name|AR_HORNET_CH0_TOP
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_TOP)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_TOP2
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_TOP2)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_TOP2_XPABIASLVL
value|0xf000
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_TOP2_XPABIASLVL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_CH0_TOP
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_TOP)
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_CH0_TOP_XPABIASLVL
value|0x3c0
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_CH0_TOP_XPABIASLVL_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_SCORPION_CH0_XTAL
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_XTAL)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_THERM
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_THERM)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_XTAL
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_XTAL)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CHO_XTAL_CAPINDAC
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CHO_XTAL_CAPINDAC_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CHO_XTAL_CAPOUTDAC
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CHO_XTAL_CAPOUTDAC_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_DDR_DPLL2
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_DDR_DPLL2)
end_define

begin_define
define|#
directive|define
name|AR_HORNET_CH0_DDR_DPLL3
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_DDR_DPLL3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCA_NOM_VAL_HORNET_2GHZ
value|-118
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_BB_DPLL1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_REFDIV
value|0xF8000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_REFDIV_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_NINI
value|0x07FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_NINI_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_NFRAC
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL1_NFRAC_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_BB_DPLL2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_RANGE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_RANGE_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_LOCAL_PLL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_LOCAL_PLL_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_KI
value|0x3C000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_KI_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_KD
value|0x03F80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_KD_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_EN_NEGTRIG
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_EN_NEGTRIG_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_SEL_1SDM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_SEL_1SDM_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_PLL_PWD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_PLL_PWD_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_OUTDIV
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_OUTDIV_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_DELTA
value|0x00001F80
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_DELTA_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_SPARE
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL2_SPARE_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_BB_DPLL3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_MEAS_AT_TXON
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_MEAS_AT_TXON_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_DO_MEAS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_DO_MEAS_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_PHASE_SHIFT
value|0x3F800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_PHASE_SHIFT_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_SQSUM_DVC
value|0x007FFFF8
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_SQSUM_DVC_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_SPARE
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL3_SPARE_S
value|0x0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4
value|AR_PHY_65NM(overlay_0x16180.Poseidon.ch0_BB_DPLL4)
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_MEAN_DVC
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_MEAN_DVC_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_VC_MEAS0
value|0x001FFFF0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_VC_MEAS0_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_MEAS_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_MEAS_DONE_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_SPARE
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_DPLL4_SPARE_S
value|0
end_define

begin_comment
comment|/*  * Wasp Analog Registers  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CONTROL
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_pll_cntl)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PLL_MODE
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_pll_mode)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PLL_BB_DPLL3
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_bb_dpll3)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PLL_BB_DPLL4
value|AR_PHY_65NM(overlay_0x16180.Osprey.ch0_bb_dpll4)
end_define

begin_comment
comment|/*  * PMU Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PMU
parameter_list|(
name|_field
parameter_list|)
value|offsetof(struct pmu_reg, _field)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PMU1
value|AR_PHY_PMU(ch0_PMU1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PMU2
value|AR_PHY_PMU(ch0_PMU2)
end_define

begin_define
define|#
directive|define
name|AR_PHY_JUPITER_PMU
parameter_list|(
name|_field
parameter_list|)
value|offsetof(struct radio65_reg, _field)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PMU1_JUPITER
value|AR_PHY_JUPITER_PMU(overlay_0x16180.Jupiter.ch0_PMU1)
end_define

begin_define
define|#
directive|define
name|AR_PHY_PMU2_JUPITER
value|AR_PHY_JUPITER_PMU(overlay_0x16180.Jupiter.ch0_PMU2)
end_define

begin_comment
comment|/*  * GLB Register Map  */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_GLB
parameter_list|(
name|_field
parameter_list|)
value|offsetof(struct glb_reg, _field)
end_define

begin_define
define|#
directive|define
name|AR_PHY_GLB_CONTROL_JUPITER
value|AR_PHY_GLB(overlap_0x20044.Jupiter.GLB_CONTROL)
end_define

begin_comment
comment|/*  * PMU Field Definitions  */
end_comment

begin_comment
comment|/* ch0_PMU1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PMU1_PWD
value|0x00000001
end_define

begin_comment
comment|/* power down switch regulator */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PMU1_PWD_S
value|0
end_define

begin_comment
comment|/* ch0_PMU2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PMU2_PGM
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_PHY_PMU2_PGM_S
value|21
end_define

begin_comment
comment|/* ch0_PHY_CTRL2 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_MAN_CAL
value|0x03C00000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_MAN_CAL_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_CAL_SEL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_CAL_SEL_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_CAL_EN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CTRL2_TX_CAL_EN_S
value|20
end_define

begin_define
define|#
directive|define
name|PCIE_CO_ERR_CTR_CTRL
value|0x40e8
end_define

begin_define
define|#
directive|define
name|PCIE_CO_ERR_CTR_CTR0
value|0x40e0
end_define

begin_define
define|#
directive|define
name|PCIE_CO_ERR_CTR_CTR1
value|0x40e4
end_define

begin_define
define|#
directive|define
name|RCVD_ERR_CTR_RUN
value|0x0001
end_define

begin_define
define|#
directive|define
name|RCVD_ERR_CTR_AUTO_STOP
value|0x0002
end_define

begin_define
define|#
directive|define
name|BAD_TLP_ERR_CTR_RUN
value|0x0004
end_define

begin_define
define|#
directive|define
name|BAD_TLP_ERR_CTR_AUTO_STOP
value|0x0008
end_define

begin_define
define|#
directive|define
name|BAD_DLLP_ERR_CTR_RUN
value|0x0010
end_define

begin_define
define|#
directive|define
name|BAD_DLLP_ERR_CTR_AUTO_STOP
value|0x0020
end_define

begin_define
define|#
directive|define
name|RPLY_TO_ERR_CTR_RUN
value|0x0040
end_define

begin_define
define|#
directive|define
name|RPLY_TO_ERR_CTR_AUTO_STOP
value|0x0080
end_define

begin_define
define|#
directive|define
name|RPLY_NUM_RO_ERR_CTR_RUN
value|0x0100
end_define

begin_define
define|#
directive|define
name|RPLY_NUM_RO_ERR_CTR_AUTO_STOP
value|0x0200
end_define

begin_define
define|#
directive|define
name|RCVD_ERR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|RCVD_ERR_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|BAD_TLP_ERR_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BAD_TLP_ERR_MASK_S
value|8
end_define

begin_define
define|#
directive|define
name|BAD_DLLP_ERR_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BAD_DLLP_ERR_MASK_S
value|16
end_define

begin_define
define|#
directive|define
name|RPLY_TO_ERR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|RPLY_TO_ERR_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|RPLY_NUM_RO_ERR_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|RPLY_NUM_RO_ERR_MASK_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_SYNTH4
value|offsetof(struct merlin2_0_radio_reg_map, SYNTH4)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_SYNTH6
value|offsetof(struct merlin2_0_radio_reg_map, SYNTH6)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_SYNTH7
value|offsetof(struct merlin2_0_radio_reg_map, SYNTH7)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_TOP0
value|offsetof(struct merlin2_0_radio_reg_map, TOP0)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_TOP1
value|offsetof(struct merlin2_0_radio_reg_map, TOP1)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_TOP2
value|offsetof(struct merlin2_0_radio_reg_map, TOP2)
end_define

begin_define
define|#
directive|define
name|AR_MERLIN_RADIO_TOP3
value|offsetof(struct merlin2_0_radio_reg_map, TOP3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR9300PHY_H_ */
end_comment

end_unit

