begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2006 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5211PHY_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5211PHY_H
end_define

begin_comment
comment|/*  * Definitions for the PHY on the Atheros AR5211/5311 chipset.  */
end_comment

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
comment|/* PHY registers base address */
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
name|AR_PHY_TURBO
value|0x9804
end_define

begin_comment
comment|/* PHY frame control register */
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
name|AR_PHY_CHIP_ID
value|0x9818
end_define

begin_comment
comment|/* PHY chip revision ID */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ACTIVE
value|0x981C
end_define

begin_comment
comment|/* PHY activation register */
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
name|AR_PHY_AGC_CONTROL
value|0x9860
end_define

begin_comment
comment|/* PHY chip calibration and noise floor setting */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_CAL
value|0x00000001
end_define

begin_comment
comment|/* Perform PHY chip internal calibration */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_AGC_CONTROL_NF
value|0x00000002
end_define

begin_comment
comment|/* Perform PHY chip noise-floor calculation */
end_comment

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
name|AR_PHY_PLL_CTL_44
value|0x19
end_define

begin_comment
comment|/* 44 MHz for 11b channels and FPGA */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_40
value|0x18
end_define

begin_comment
comment|/* 40 MHz */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_PLL_CTL_20
value|0x13
end_define

begin_comment
comment|/* 20 MHz half rate 11a for emulation */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY
value|0x9914
end_define

begin_comment
comment|/* PHY analog_power_on_time, in 100ns increments */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_RX_DELAY_M
value|0x00003FFF
end_define

begin_comment
comment|/* Mask for delay from active assertion (wake up) */
end_comment

begin_comment
comment|/* to enable_receiver */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4
value|0x9920
end_define

begin_comment
comment|/* PHY */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_Q_COFF_M
value|0x0000001F
end_define

begin_comment
comment|/* Mask for kcos_theta-1 for q correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCORR_Q_I_COFF_M
value|0x000007E0
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
value|0x00000800
end_define

begin_comment
comment|/* enable IQ correction */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_TIMING_CTRL4_IQCAL_LOG_COUNT_MAX_M
value|0x0000F000
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
value|0x00010000
end_define

begin_comment
comment|/* perform IQ calibration */
end_comment

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
name|AR_PHY_RADAR_0
value|0x9954
end_define

begin_comment
comment|/* PHY radar detection settings */
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
name|AR_PHY_IQCAL_RES_PWR_MEAS_I
value|0x9c10
end_define

begin_comment
comment|/*PHY IQ calibration results - power measurement for I */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_IQCAL_RES_PWR_MEAS_Q
value|0x9c14
end_define

begin_comment
comment|/*PHY IQ calibration results - power measurement for Q */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_IQCAL_RES_IQ_CORR_MEAS
value|0x9c18
end_define

begin_comment
comment|/*PHY IQ calibration results - IQ correlation measurement */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_CURRENT_RSSI
value|0x9c1c
end_define

begin_comment
comment|/* rssi of current frame being received */
end_comment

begin_define
define|#
directive|define
name|AR5211_PHY_MODE
value|0xA200
end_define

begin_comment
comment|/* Mode register */
end_comment

begin_define
define|#
directive|define
name|AR5211_PHY_MODE_OFDM
value|0x0
end_define

begin_comment
comment|/* bit 0 = 0 for OFDM */
end_comment

begin_define
define|#
directive|define
name|AR5211_PHY_MODE_CCK
value|0x1
end_define

begin_comment
comment|/* bit 0 = 1 for CCK */
end_comment

begin_define
define|#
directive|define
name|AR5211_PHY_MODE_RF5GHZ
value|0x0
end_define

begin_comment
comment|/* bit 1 = 0 for 5 GHz */
end_comment

begin_define
define|#
directive|define
name|AR5211_PHY_MODE_RF2GHZ
value|0x2
end_define

begin_comment
comment|/* bit 1 = 1 for 2.4 GHz */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5211PHY_H */
end_comment

end_unit

