begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ar5212phy.h,v 1.7 2008/11/19 21:23:01 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5212PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5212PHY_H_
end_define

begin_comment
comment|/* PHY registers */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BASE
value|0x9800
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

begin_define
define|#
directive|define
name|AR_PHY_TEST
value|0x9800
end_define

begin_comment
comment|/* PHY test control */
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
name|AR_PHY_TESTCTRL
value|0x9808
end_define

begin_comment
comment|/* PHY Test Control/Status */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TESTCTRL_TXHOLD
value|0x3800
end_define

begin_comment
comment|/* Select Tx hold */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TESTCTRL_TXSRC_ALT
value|0x00000080
end_define

begin_comment
comment|/* Select input to tsdac along with bit 1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TESTCTRL_TXSRC_ALT_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_TESTCTRL_TXSRC_SRC
value|0x00000002
end_define

begin_comment
comment|/* Used with bit 7 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TESTCTRL_TXSRC_SRC_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TURBO
value|0x9804
end_define

begin_comment
comment|/* frame control register */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_FC_TURBO_MODE
value|0x00000001
end_define

begin_comment
comment|/* Set turbo mode bits */
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
name|AR_PHY_FC_TURBO_MIMO
value|0x00000004
end_define

begin_comment
comment|/* Set turbo for mimo mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING3
value|0x9814
end_define

begin_comment
comment|/* Timing control 3 */
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
name|AR_PHY_CHIP_ID_REV_2
value|0x42
end_define

begin_comment
comment|/* 5212 Rev 2 BB w. TPC fix */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHIP_ID_REV_3
value|0x43
end_define

begin_comment
comment|/* 5212 Rev 3 5213 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CHIP_ID_REV_4
value|0x44
end_define

begin_comment
comment|/* 5212 Rev 4 2313 and up */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE
value|0x981C
end_define

begin_comment
comment|/* activation register */
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

begin_define
define|#
directive|define
name|AR_PHY_TX_CTL
value|0x9824
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_TX_DATA_START
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_FRAME_TO_TX_DATA_START_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL
value|0x982C
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_OFF_INBUFGAIN
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_OFF_INBUFGAIN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_OFF_PWDDAC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_OFF_PWDBANDGAP
value|0x00004000
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_OFF_PWDADC
value|0x00008000
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_ON_INBUFGAIN
value|0x00030000
end_define

begin_define
define|#
directive|define
name|AR_PHY_ADC_CTL_ON_INBUFGAIN_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_XP_PA_CTL
value|0x9838
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_XPAA_ACTIVE_HIGH
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_XPAB_ACTIVE_HIGH
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_PHY_BB_XPAB_ACTIVE_HIGH_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TSTDAC_CONST
value|0x983C
end_define

begin_define
define|#
directive|define
name|AR_PHY_TSTDAC_CONST_Q
value|0x0003FE00
end_define

begin_define
define|#
directive|define
name|AR_PHY_TSTDAC_CONST_Q_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_TSTDAC_CONST_I
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|AR_PHY_SETTLING
value|0x9844
end_define

begin_define
define|#
directive|define
name|AR_PHY_SETTLING_AGC
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|AR_PHY_SETTLING_AGC_S
value|0
end_define

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

begin_define
define|#
directive|define
name|AR_PHY_RXGAIN
value|0x9848
end_define

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
name|AR_PHY_DESIRED_SZ
value|0x9850
end_define

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

begin_define
define|#
directive|define
name|AR_PHY_FIND_SIG
value|0x9858
end_define

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
name|AR_PHY_AGC_CTL1
value|0x985C
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CTL1_COARSE_LOW
value|0x00007F80
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CTL1_COARSE_LOW_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CTL1_COARSE_HIGH
value|0x003F8000
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CTL1_COARSE_HIGH_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL
value|0x9860
end_define

begin_comment
comment|/* chip calibration and noise floor setting */
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
comment|/* do noise-floor calculation */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_ENABLE_NF
value|0x00008000
end_define

begin_comment
comment|/* Enable noise floor calibration to happen */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_FLTR_CAL
value|0x00010000
end_define

begin_comment
comment|/* Allow Filter calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_NO_UPDATE_NF
value|0x00020000
end_define

begin_comment
comment|/* Don't update noise floor automatically */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SFCORR_LOW
value|0x986C
end_define

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

begin_define
define|#
directive|define
name|AR_PHY_SFCORR
value|0x9868
end_define

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

begin_define
define|#
directive|define
name|AR_PHY_SLEEP_CTR_CONTROL
value|0x9870
end_define

begin_define
define|#
directive|define
name|AR_PHY_SLEEP_CTR_LIMIT
value|0x9874
end_define

begin_define
define|#
directive|define
name|AR_PHY_SLEEP_SCAL
value|0x9878
end_define

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL
value|0x987c
end_define

begin_comment
comment|/* PLL control register */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40
value|0xaa
end_define

begin_comment
comment|/* 40 MHz */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_44
value|0xab
end_define

begin_comment
comment|/* 44 MHz for 11b, 11g */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_44_5112
value|0xeb
end_define

begin_comment
comment|/* 44 MHz for 11b, 11g */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40_5112
value|0xea
end_define

begin_comment
comment|/* 40 MHz for 11a, turbos */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40_5413
value|0x04
end_define

begin_comment
comment|/* 40 MHz for 11a, turbos with 5413 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_HALF
value|0x100
end_define

begin_comment
comment|/* Half clock for 1/2 chan width */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_QUARTER
value|0x200
end_define

begin_comment
comment|/* Quarter clock for 1/4 chan width */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK_1
value|0x9900
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK_2
value|0x9904
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK_3
value|0x9908
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK_CTL
value|0x990c
end_define

begin_comment
comment|/* What are these for?? */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MASK_CTL_MASK_4
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK_CTL_MASK_4_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK_CTL_RATE
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_MASK_CTL_RATE_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY
value|0x9914
end_define

begin_comment
comment|/* analog pow-on time (100ns) */
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

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4
value|0x9920
end_define

begin_comment
comment|/* timing control */
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
name|AR_PHY_TIMING_CTRL4_DO_IQCAL
value|0x10000
end_define

begin_comment
comment|/* perform IQ calibration */
end_comment

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
name|AR_PHY_TIMING5
value|0x9924
end_define

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
name|AR_PHY_PAPD_PROBE
value|0x9930
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_POWERTX
value|0x00007E00
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_POWERTX_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_NEXT_TX
value|0x00008000
end_define

begin_comment
comment|/* command to take next reading */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_TYPE
value|0x01800000
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_TYPE_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_TYPE_OFDM
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_TYPE_CCK
value|2
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_GAINF
value|0xFE000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_PAPD_PROBE_GAINF_S
value|25
end_define

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
value|0x993c
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE_MAX_TPC_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL
value|0x9944
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_TX_CLIP
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_TX_CLIP_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_ERR_SERV
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_ERR_SERV_S
value|29
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_EMU_M
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_EMU_S
value|31
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_WINLEN
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_PHY_FRAME_CTL_WINLEN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXPWRADJ
value|0x994C
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TXPWRADJ_CCK_GAIN_DELTA
value|0x00000FC0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXPWRADJ_CCK_GAIN_DELTA_S
value|6
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXPWRADJ_CCK_PCDAC_INDEX
value|0x00FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TXPWRADJ_CCK_PCDAC_INDEX_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_RADAR_0
value|0x9954
end_define

begin_comment
comment|/* radar detection settings */
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

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA
value|0x996C
end_define

begin_comment
comment|/* AR5312 only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_ADC_SEL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_ADC_SEL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_FILT2
value|0x000000F8
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_FILT2_S
value|3
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_FILT1
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_FILT1_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_ADC_CLIP
value|0x01FFE000
end_define

begin_define
define|#
directive|define
name|AR_PHY_SIGMA_DELTA_ADC_CLIP_S
value|13
end_define

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

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ
value|0x997C
end_define

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_REQ_REQUEST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING7
value|0x9980
end_define

begin_comment
comment|/* Spur mitigation masks */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING8
value|0x9984
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING8_PILOT_MASK_2
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING8_PILOT_MASK_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_1
value|0x9988
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_2
value|0x998c
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_3
value|0x9990
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_4
value|0x9994
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_4_MASK_4
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_BIN_MASK2_4_MASK_4_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING9
value|0x9998
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING10
value|0x999c
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING10_PILOT_MASK_2
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING10_PILOT_MASK_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11
value|0x99a0
end_define

begin_comment
comment|/* Spur Mitigation control */
end_comment

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
name|AR_PHY_TIMING11_USE_SPUR_IN_AGC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TIMING11_USE_SPUR_IN_SELFCOR
value|0x80000000
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

begin_comment
comment|/* PHY IQ calibration results */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_IQCAL_RES_PWR_MEAS_I
value|0x9c10
end_define

begin_comment
comment|/* power measurement for I */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_IQCAL_RES_PWR_MEAS_Q
value|0x9c14
end_define

begin_comment
comment|/* power measurement for Q */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_IQCAL_RES_IQ_CORR_MEAS
value|0x9c18
end_define

begin_comment
comment|/* IQ correlation measurement */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CURRENT_RSSI
value|0x9c1c
end_define

begin_comment
comment|/* rssi of current frame rx'd */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_GNT
value|0x9c20
end_define

begin_define
define|#
directive|define
name|AR_PHY_RFBUS_GNT_GRANT
value|0x1
end_define

begin_define
define|#
directive|define
name|AR_PHY_PCDAC_TX_POWER_0
value|0xA180
end_define

begin_define
define|#
directive|define
name|AR_PHY_PCDAC_TX_POWER
parameter_list|(
name|_n
parameter_list|)
value|(AR_PHY_PCDAC_TX_POWER_0 + ((_n)<<2))
end_define

begin_define
define|#
directive|define
name|AR_PHY_MODE
value|0xA200
end_define

begin_comment
comment|/* Mode register */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_QUARTER
value|0x40
end_define

begin_comment
comment|/* Quarter Rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_HALF
value|0x20
end_define

begin_comment
comment|/* Half Rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_AR5112
value|0x08
end_define

begin_comment
comment|/* AR5112 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_AR5111
value|0x00
end_define

begin_comment
comment|/* AR5111/AR2111 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DYNAMIC
value|0x04
end_define

begin_comment
comment|/* dynamic CCK/OFDM mode */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_RF2GHZ
value|0x02
end_define

begin_comment
comment|/* 2.4 GHz */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_RF5GHZ
value|0x00
end_define

begin_comment
comment|/* 5 GHz */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_CCK
value|0x01
end_define

begin_comment
comment|/* CCK */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_OFDM
value|0x00
end_define

begin_comment
comment|/* OFDM */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_MODE_DYN_CCK_DISABLE
value|0x100
end_define

begin_comment
comment|/* Disable dynamic CCK detection */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CCK_TX_CTRL
value|0xA204
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_TX_CTRL_JAPAN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_DETECT
value|0xA208
end_define

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
name|AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV
value|0x2000
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ
value|0xA20C
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_RXTX_MARGIN
value|0x00FC0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_GAIN_2GHZ_RXTX_MARGIN_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_RXCTRL4
value|0xA21C
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_RXCTRL4_FREQ_EST_SHORT
value|0x01F80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_CCK_RXCTRL4_FREQ_EST_SHORT_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK
value|0xA228
end_define

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_EN_RSSI_THR
value|0x00000200
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_RSSI_THR
value|0x0001FC00
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_DAG_CTRLCCK_RSSI_THR_S
value|10
end_define

begin_comment
comment|/* BB Rev 4.2+ only */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE3
value|0xA234
end_define

begin_define
define|#
directive|define
name|AR_PHY_POWER_TX_RATE4
value|0xA238
end_define

begin_define
define|#
directive|define
name|AR_PHY_FAST_ADC
value|0xA24C
end_define

begin_define
define|#
directive|define
name|AR_PHY_BLUETOOTH
value|0xA254
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1
value|0xA258
end_define

begin_comment
comment|/* ar2413 power control */
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
name|AR_PHY_TPCRG1_PDGAIN_SETTING1
value|0x00030000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PDGAIN_SETTING1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PDGAIN_SETTING2
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PDGAIN_SETTING2_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PDGAIN_SETTING3
value|0x00300000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG1_PDGAIN_SETTING3_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PHY_TPCRG5
value|0xA26C
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5212PHY_H_ */
end_comment

end_unit

