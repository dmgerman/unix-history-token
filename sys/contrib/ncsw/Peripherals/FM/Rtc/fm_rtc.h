begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|ACCUMULATOR_OVERFLOW
value|((uint64_t)(1LL<< 32))
end_define

begin_define
define|#
directive|define
name|DEFAULT_OUTPUT_CLOCK_DIVISOR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEFAULT_BYPASS
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_CLOCK_PERIOD
value|1000
end_define

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
name|struct
name|rtc_regs
modifier|*
name|p_MemMap
decl_stmt|;
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
name|struct
name|rtc_cfg
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

