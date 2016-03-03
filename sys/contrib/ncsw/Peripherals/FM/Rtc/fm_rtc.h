begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_rtc.h   @Description   Memory map and internal definitions for FM RTC IEEE1588 Timer driver.   @Cautions      None */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_RTC_H__
end_ifndef

begin_define
define|#
directive|define
name|__FM_RTC_H__
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_rtc_ext.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_FM_RTC
end_define

begin_comment
comment|/* General definitions */
end_comment

begin_define
define|#
directive|define
name|NANOSEC_PER_ONE_HZ_TICK
value|1000000000
end_define

begin_define
define|#
directive|define
name|MIN_RTC_CLK_FREQ_HZ
value|1000
end_define

begin_define
define|#
directive|define
name|MHz
value|1000000
end_define

begin_define
define|#
directive|define
name|ACCUMULATOR_OVERFLOW
value|((uint64_t)(1LL<< 32))
end_define

begin_comment
comment|/* RTC default values */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_srcClock
value|e_FM_RTC_SOURCE_CLOCK_SYSTEM
end_define

begin_define
define|#
directive|define
name|DEFAULT_bypass
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_invertInputClkPhase
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_invertOutputClkPhase
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_outputClockDivisor
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEFAULT_alarmPolarity
value|e_FM_RTC_ALARM_POLARITY_ACTIVE_HIGH
end_define

begin_define
define|#
directive|define
name|DEFAULT_triggerPolarity
value|e_FM_RTC_TRIGGER_ON_FALLING_EDGE
end_define

begin_define
define|#
directive|define
name|DEFAULT_pulseRealign
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_clockPeriod
value|1000
end_define

begin_comment
comment|/* FM RTC Registers definitions */
end_comment

begin_define
define|#
directive|define
name|TMR_CTRL_ALMP1
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_ALMP2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_FS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_PP1L
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_PP2L
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_TCLK_PERIOD_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_FRD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_SLV
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_ETEP1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_COPH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_CIPH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_TMSR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_DBG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_BYP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_TE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_CKSEL_OSC_CLK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_CKSEL_MAC_CLK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_CKSEL_EXT_CLK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TMR_CTRL_TCLK_PERIOD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_ETS2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_ETS1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_ALM2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_ALM1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_PP1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_PP2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_PP3
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TMR_TEVENT_ALL
value|(TMR_TEVENT_ETS2 | TMR_TEVENT_ETS1 | \                                          TMR_TEVENT_ALM2 | TMR_TEVENT_ALM1 | \                                          TMR_TEVENT_PP1 | TMR_TEVENT_PP2 | TMR_TEVENT_PP3)
end_define

begin_define
define|#
directive|define
name|TMR_PRSC_OCK_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Memory Mapped Registers */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description FM RTC timer alarm */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_TmrAlaram
block|{
specifier|volatile
name|uint32_t
name|tmr_alarm_h
decl_stmt|;
comment|/**<  */
specifier|volatile
name|uint32_t
name|tmr_alarm_l
decl_stmt|;
comment|/**<  */
block|}
name|_PackedType
name|t_TmrAlaram
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description FM RTC timer Ex trigger */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_TmrExtTrigger
block|{
specifier|volatile
name|uint32_t
name|tmr_etts_h
decl_stmt|;
comment|/**<  */
specifier|volatile
name|uint32_t
name|tmr_etts_l
decl_stmt|;
comment|/**<  */
block|}
name|_PackedType
name|t_TmrExtTrigger
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|tmr_id
decl_stmt|;
comment|/* Module ID and version register */
specifier|volatile
name|uint32_t
name|tmr_id2
decl_stmt|;
comment|/* Module ID and configuration register */
specifier|volatile
name|uint32_t
name|PTP_RESERVED1
index|[
literal|30
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|tmr_ctrl
decl_stmt|;
comment|/* timer control register */
specifier|volatile
name|uint32_t
name|tmr_tevent
decl_stmt|;
comment|/* timer event register */
specifier|volatile
name|uint32_t
name|tmr_temask
decl_stmt|;
comment|/* timer event mask register */
specifier|volatile
name|uint32_t
name|PTP_RESERVED2
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|tmr_cnt_h
decl_stmt|;
comment|/* timer counter high register */
specifier|volatile
name|uint32_t
name|tmr_cnt_l
decl_stmt|;
comment|/* timer counter low register */
specifier|volatile
name|uint32_t
name|tmr_add
decl_stmt|;
comment|/* timer drift compensation addend register */
specifier|volatile
name|uint32_t
name|tmr_acc
decl_stmt|;
comment|/* timer accumulator register */
specifier|volatile
name|uint32_t
name|tmr_prsc
decl_stmt|;
comment|/* timer prescale */
specifier|volatile
name|uint32_t
name|PTP_RESERVED3
decl_stmt|;
specifier|volatile
name|uint32_t
name|tmr_off_h
decl_stmt|;
comment|/* timer offset high */
specifier|volatile
name|uint32_t
name|tmr_off_l
decl_stmt|;
comment|/* timer offset low  */
specifier|volatile
name|t_TmrAlaram
name|tmr_alarm
index|[
name|FM_RTC_NUM_OF_ALARMS
index|]
decl_stmt|;
comment|/* timer alarm */
specifier|volatile
name|uint32_t
name|PTP_RESERVED4
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|tmr_fiper
index|[
name|FM_RTC_NUM_OF_PERIODIC_PULSES
index|]
decl_stmt|;
comment|/* timer fixed period interval */
specifier|volatile
name|uint32_t
name|PTP_RESERVED5
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|t_TmrExtTrigger
name|tmr_etts
index|[
name|FM_RTC_NUM_OF_EXT_TRIGGERS
index|]
decl_stmt|;
comment|/*time stamp general purpose external */
specifier|volatile
name|uint32_t
name|PTP_RESERVED6
index|[
literal|3
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmRtcMemMap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   RTC FM driver parameters structure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcDriverParam
block|{
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**<  */
name|e_FmSrcClk
name|srcClk
decl_stmt|;
comment|/**<  */
name|uint32_t
name|extSrcClkFreq
decl_stmt|;
comment|/**<  */
name|uint32_t
name|rtcFreqHz
decl_stmt|;
comment|/**<  */
name|bool
name|timerSlaveMode
decl_stmt|;
comment|/*Slave/Master Mode*/
name|bool
name|invertInputClkPhase
decl_stmt|;
name|bool
name|invertOutputClkPhase
decl_stmt|;
name|uint32_t
name|eventsMask
decl_stmt|;
name|bool
name|bypass
decl_stmt|;
comment|/**< Indicates if frequency compensation is bypassed */
name|bool
name|pulseRealign
decl_stmt|;
name|e_FmRtcAlarmPolarity
name|alarmPolarity
index|[
name|FM_RTC_NUM_OF_ALARMS
index|]
decl_stmt|;
name|e_FmRtcTriggerPolarity
name|triggerPolarity
index|[
name|FM_RTC_NUM_OF_EXT_TRIGGERS
index|]
decl_stmt|;
block|}
name|t_FmRtcDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcAlarm
block|{
name|t_FmRtcExceptionsCallback
modifier|*
name|f_AlarmCallback
decl_stmt|;
name|bool
name|clearOnExpiration
decl_stmt|;
block|}
name|t_FmRtcAlarm
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcPeriodicPulse
block|{
name|t_FmRtcExceptionsCallback
modifier|*
name|f_PeriodicPulseCallback
decl_stmt|;
block|}
name|t_FmRtcPeriodicPulse
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcExternalTrigger
block|{
name|t_FmRtcExceptionsCallback
modifier|*
name|f_ExternalTriggerCallback
decl_stmt|;
block|}
name|t_FmRtcExternalTrigger
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description RTC FM driver control structure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtc
block|{
name|t_Part
modifier|*
name|p_Part
decl_stmt|;
comment|/**< Pointer to the integration device              */
name|t_Handle
name|h_Fm
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Application handle */
name|t_FmRtcMemMap
modifier|*
name|p_MemMap
decl_stmt|;
comment|/**< Pointer to RTC memory map */
name|uint32_t
name|clockPeriodNanoSec
decl_stmt|;
comment|/**< RTC clock period in nano-seconds (for FS mode) */
name|uint32_t
name|srcClkFreqMhz
decl_stmt|;
name|uint16_t
name|outputClockDivisor
decl_stmt|;
comment|/**< Output clock divisor (for FS mode) */
name|t_FmRtcAlarm
name|alarmParams
index|[
name|FM_RTC_NUM_OF_ALARMS
index|]
decl_stmt|;
name|t_FmRtcPeriodicPulse
name|periodicPulseParams
index|[
name|FM_RTC_NUM_OF_PERIODIC_PULSES
index|]
decl_stmt|;
name|t_FmRtcExternalTrigger
name|externalTriggerParams
index|[
name|FM_RTC_NUM_OF_EXT_TRIGGERS
index|]
decl_stmt|;
name|t_FmRtcDriverParam
modifier|*
name|p_RtcDriverParam
decl_stmt|;
comment|/**< RTC Driver parameters (for Init phase) */
block|}
name|t_FmRtc
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_RTC_H__ */
end_comment

end_unit

