begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR5416_CAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR5416_CAL_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADC_DC_INIT_CAL
init|=
literal|0x1
block|,
name|ADC_GAIN_CAL
init|=
literal|0x2
block|,
name|ADC_DC_CAL
init|=
literal|0x4
block|,
name|IQ_MISMATCH_CAL
init|=
literal|0x8
block|}
name|HAL_CAL_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Calibrate state */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAL_INACTIVE
block|,
name|CAL_WAITING
block|,
name|CAL_RUNNING
block|,
name|CAL_DONE
block|}
name|HAL_CAL_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint32_t
name|u
decl_stmt|;
name|int32_t
name|s
decl_stmt|;
block|}
name|HAL_CAL_SAMPLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIN_CAL_SAMPLES
value|1
end_define

begin_define
define|#
directive|define
name|MAX_CAL_SAMPLES
value|64
end_define

begin_define
define|#
directive|define
name|INIT_LOG_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|PER_MIN_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|PER_MAX_LOG_COUNT
value|10
end_define

begin_comment
comment|/* Per Calibration data structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|per_cal_data
block|{
specifier|const
name|char
modifier|*
name|calName
decl_stmt|;
comment|/* for diagnostics */
name|HAL_CAL_TYPE
name|calType
decl_stmt|;
comment|/* Type of calibration */
name|uint32_t
name|calNumSamples
decl_stmt|;
comment|/* # SW samples to collect */
name|uint32_t
name|calCountMax
decl_stmt|;
comment|/* # HW samples to collect */
name|void
function_decl|(
modifier|*
name|calCollect
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
comment|/* Accumulator function */
comment|/* Post-processing function */
name|void
function_decl|(
modifier|*
name|calPostProc
function_decl|)
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
block|}
name|HAL_PERCAL_DATA
typedef|;
end_typedef

begin_comment
comment|/* List structure for calibration data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cal_list
block|{
name|struct
name|cal_list
modifier|*
name|calNext
decl_stmt|;
name|HAL_CAL_STATE
name|calState
decl_stmt|;
specifier|const
name|HAL_PERCAL_DATA
modifier|*
name|calData
decl_stmt|;
block|}
name|HAL_CAL_LIST
typedef|;
end_typedef

begin_struct
struct|struct
name|ar5416PerCal
block|{
comment|/* 	 * Periodic calibration state. 	 */
name|HAL_CAL_TYPE
name|suppCals
decl_stmt|;
name|HAL_CAL_LIST
name|iqCalData
decl_stmt|;
name|HAL_CAL_LIST
name|adcGainCalData
decl_stmt|;
name|HAL_CAL_LIST
name|adcDcCalInitData
decl_stmt|;
name|HAL_CAL_LIST
name|adcDcCalData
decl_stmt|;
name|HAL_CAL_LIST
modifier|*
name|cal_list
decl_stmt|;
name|HAL_CAL_LIST
modifier|*
name|cal_last
decl_stmt|;
name|HAL_CAL_LIST
modifier|*
name|cal_curr
decl_stmt|;
define|#
directive|define
name|AR5416_MAX_CHAINS
value|3
comment|/* XXX dup's eeprom def */
name|HAL_CAL_SAMPLE
name|caldata
index|[
literal|4
index|]
index|[
name|AR5416_MAX_CHAINS
index|]
decl_stmt|;
name|int
name|calSamples
decl_stmt|;
comment|/* 	 * Noise floor cal histogram support. 	 * XXX be nice to re-use space in ar5212 	 */
define|#
directive|define
name|AR5416_NUM_NF_READINGS
value|6
comment|/* (3 chains * (ctl + ext) */
name|struct
name|ar5212NfCalHist
name|nfCalHist
index|[
name|AR5416_NUM_NF_READINGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INIT_CAL
parameter_list|(
name|_perCal
parameter_list|)
value|do {						\ 	(_perCal)->calState = CAL_WAITING;				\ 	(_perCal)->calNext = AH_NULL;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_CAL
parameter_list|(
name|_cal
parameter_list|,
name|_perCal
parameter_list|)
value|do {					\ 	if ((_cal)->cal_last == AH_NULL) {				\ 		(_cal)->cal_list = (_cal)->cal_last = (_perCal);	\ 		((_cal)->cal_last)->calNext = (_perCal);		\ 	} else {							\ 		((_cal)->cal_last)->calNext = (_perCal);		\ 		(_cal)->cal_last = (_perCal);				\ 		(_perCal)->calNext = (_cal)->cal_list;			\ 	}								\ } while (0)
end_define

begin_function_decl
name|HAL_BOOL
name|ar5416InitCal
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_BOOL
name|ar5416PerCalibration
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|HAL_BOOL
modifier|*
name|isIQdone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_BOOL
name|ar5416PerCalibrationN
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|u_int
name|chainMask
parameter_list|,
name|HAL_BOOL
name|longCal
parameter_list|,
name|HAL_BOOL
modifier|*
name|isCalDone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_BOOL
name|ar5416ResetCalValid
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416IQCalCollect
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416IQCalibration
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint8_t
name|numChains
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416AdcGainCalCollect
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416AdcGainCalibration
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint8_t
name|numChains
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416AdcDcCalCollect
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416AdcDcCalibration
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|uint8_t
name|numChains
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar5416InitNfHistBuff
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ar5212NfCalHist
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR5416_CAL_H_ */
end_comment

end_unit

