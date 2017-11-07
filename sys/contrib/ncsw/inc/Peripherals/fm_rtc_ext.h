begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_rtc_ext.h   @Description   External definitions and API for FM RTC IEEE1588 Timer Module.   @Cautions      None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_RTC_EXT_H__
end_ifndef

begin_define
define|#
directive|define
name|__FM_RTC_EXT_H__
end_define

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman_rtc.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         fm_rtc_grp FM RTC   @Description   FM RTC functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         fm_rtc_init_grp FM RTC Initialization Unit   @Description   FM RTC initialization API.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Alarm Polarity Options. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmRtcAlarmPolarity
block|{
name|e_FM_RTC_ALARM_POLARITY_ACTIVE_HIGH
init|=
name|E_FMAN_RTC_ALARM_POLARITY_ACTIVE_HIGH
block|,
comment|/**< Active-high output polarity */
name|e_FM_RTC_ALARM_POLARITY_ACTIVE_LOW
init|=
name|E_FMAN_RTC_ALARM_POLARITY_ACTIVE_LOW
comment|/**< Active-low output polarity */
block|}
name|e_FmRtcAlarmPolarity
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Trigger Polarity Options. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmRtcTriggerPolarity
block|{
name|e_FM_RTC_TRIGGER_ON_RISING_EDGE
init|=
name|E_FMAN_RTC_TRIGGER_ON_RISING_EDGE
block|,
comment|/**< Trigger on rising edge */
name|e_FM_RTC_TRIGGER_ON_FALLING_EDGE
init|=
name|E_FMAN_RTC_TRIGGER_ON_FALLING_EDGE
comment|/**< Trigger on falling edge */
block|}
name|e_FmRtcTriggerPolarity
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   IEEE1588 Timer Module FM RTC Optional Clock Sources. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmSrcClock
block|{
name|e_FM_RTC_SOURCE_CLOCK_EXTERNAL
init|=
name|E_FMAN_RTC_SOURCE_CLOCK_EXTERNAL
block|,
comment|/**< external high precision timer reference clock */
name|e_FM_RTC_SOURCE_CLOCK_SYSTEM
init|=
name|E_FMAN_RTC_SOURCE_CLOCK_SYSTEM
block|,
comment|/**< MAC system clock */
name|e_FM_RTC_SOURCE_CLOCK_OSCILATOR
init|=
name|E_FMAN_RTC_SOURCE_CLOCK_OSCILATOR
comment|/**< RTC clock oscilator */
block|}
name|e_FmSrcClk
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC configuration parameters structure.                  This structure should be passed to FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcParams
block|{
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< FM Handle*/
name|uintptr_t
name|baseAddress
decl_stmt|;
comment|/**< Base address of FM RTC registers */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                       be passed by the driver upon calling the above callbacks */
block|}
name|t_FmRtcParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_Config   @Description   Configures the FM RTC module according to user's parameters.                  The driver assigns default values to some FM RTC parameters.                 These parameters can be overwritten using the advanced                 configuration routines.   @Param[in]     p_FmRtcParam    - FM RTC configuration parameters.   @Return        Handle to the new FM RTC object; NULL pointer on failure.   @Cautions      None */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_RTC_Config
parameter_list|(
name|t_FmRtcParams
modifier|*
name|p_FmRtcParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_Init   @Description   Initializes the FM RTC driver and hardware.   @Param[in]     h_FmRtc - Handle to FM RTC object.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_Init
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_Free   @Description   Frees the FM RTC object and all allocated resources.   @Param[in]     h_FmRtc - Handle to FM RTC object.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_Free
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         fm_rtc_adv_config_grp  FM RTC Advanced Configuration Unit   @Description   FM RTC advanced configuration functions.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigPeriod   @Description   Configures the period of the timestamp if different than                 default [DEFAULT_clockPeriod].   @Param[in]     h_FmRtc         - Handle to FM RTC object.  @Param[in]     period          - Period in nano-seconds.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigPeriod
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint32_t
name|period
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigSourceClock   @Description   Configures the source clock of the RTC.   @Param[in]     h_FmRtc         - Handle to FM RTC object.  @Param[in]     srcClk          - Source clock selection.  @Param[in]     freqInMhz       - the source-clock frequency (in MHz).   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigSourceClock
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|e_FmSrcClk
name|srcClk
parameter_list|,
name|uint32_t
name|freqInMhz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigPulseRealignment   @Description   Configures the RTC to automatic FIPER pulse realignment in                 response to timer adjustments [DEFAULT_pulseRealign]                  In this mode, the RTC clock is identical to the source clock.                 This feature can be useful when the system contains an external                 RTC with inherent frequency compensation.   @Param[in]     h_FmRtc     - Handle to FM RTC object.  @Param[in]     enable      - TRUE to enable automatic realignment.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigPulseRealignment
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigFrequencyBypass   @Description   Configures the RTC to bypass the frequency compensation                 mechanism. [DEFAULT_bypass]                  In this mode, the RTC clock is identical to the source clock.                 This feature can be useful when the system contains an external                 RTC with inherent frequency compensation.   @Param[in]     h_FmRtc     - Handle to FM RTC object.  @Param[in]     enabled     - TRUE to bypass frequency compensation;                               FALSE otherwise.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigFrequencyBypass
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigInvertedInputClockPhase   @Description   Configures the RTC to invert the source clock phase on input.                 [DEFAULT_invertInputClkPhase]   @Param[in]     h_FmRtc  - Handle to FM RTC object.  @Param[in]     inverted    - TRUE to invert the source clock phase on input.                               FALSE otherwise.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigInvertedInputClockPhase
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|bool
name|inverted
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigInvertedOutputClockPhase   @Description   Configures the RTC to invert the output clock phase.                 [DEFAULT_invertOutputClkPhase]   @Param[in]     h_FmRtc  - Handle to FM RTC object.  @Param[in]     inverted    - TRUE to invert the output clock phase.                               FALSE otherwise.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigInvertedOutputClockPhase
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|bool
name|inverted
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigOutputClockDivisor   @Description   Configures the divisor for generating the output clock from                 the RTC clock. [DEFAULT_outputClockDivisor]   @Param[in]     h_FmRtc  - Handle to FM RTC object.  @Param[in]     divisor     - Divisor for generation of the output clock.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigOutputClockDivisor
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint16_t
name|divisor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigAlarmPolarity   @Description   Configures the polarity (active-high/active-low) of a specific                 alarm signal. [DEFAULT_alarmPolarity]   @Param[in]     h_FmRtc      - Handle to FM RTC object.  @Param[in]     alarmId         - Alarm ID.  @Param[in]     alarmPolarity   - Alarm polarity.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigAlarmPolarity
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint8_t
name|alarmId
parameter_list|,
name|e_FmRtcAlarmPolarity
name|alarmPolarity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ConfigExternalTriggerPolarity   @Description   Configures the polarity (rising/falling edge) of a specific                 external trigger signal. [DEFAULT_triggerPolarity]   @Param[in]     h_FmRtc      - Handle to FM RTC object.  @Param[in]     triggerId       - Trigger ID.  @Param[in]     triggerPolarity - Trigger polarity.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously created using FM_RTC_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ConfigExternalTriggerPolarity
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint8_t
name|triggerId
parameter_list|,
name|e_FmRtcTriggerPolarity
name|triggerPolarity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of fm_rtc_adv_config_grp */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of fm_rtc_init_grp */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         fm_rtc_control_grp FM RTC Control Unit   @Description   FM RTC runtime control API.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmRtcExceptionsCallback   @Description   Exceptions user callback routine, used for RTC different mechanisms.   @Param[in]     h_App       - User's application descriptor.  @Param[in]     id          - source id. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmRtcExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|uint8_t
name|id
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC alarm parameters. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcAlarmParams
block|{
name|uint8_t
name|alarmId
decl_stmt|;
comment|/**< 0 or 1 */
name|uint64_t
name|alarmTime
decl_stmt|;
comment|/**< In nanoseconds, the time when the alarm                                                          should go off - must be a multiple of                                                          the RTC period */
name|t_FmRtcExceptionsCallback
modifier|*
name|f_AlarmCallback
decl_stmt|;
comment|/**< This routine will be called when RTC                                                          reaches alarmTime */
name|bool
name|clearOnExpiration
decl_stmt|;
comment|/**< TRUE to turn off the alarm once expired. */
block|}
name|t_FmRtcAlarmParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Periodic Pulse parameters. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcPeriodicPulseParams
block|{
name|uint8_t
name|periodicPulseId
decl_stmt|;
comment|/**< 0 or 1 */
name|uint64_t
name|periodicPulsePeriod
decl_stmt|;
comment|/**< In Nanoseconds. Must be                                                                  a multiple of the RTC period */
name|t_FmRtcExceptionsCallback
modifier|*
name|f_PeriodicPulseCallback
decl_stmt|;
comment|/**< This routine will be called every                                                                  periodicPulsePeriod. */
block|}
name|t_FmRtcPeriodicPulseParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Periodic Pulse parameters. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmRtcExternalTriggerParams
block|{
name|uint8_t
name|externalTriggerId
decl_stmt|;
comment|/**< 0 or 1 */
name|bool
name|usePulseAsInput
decl_stmt|;
comment|/**< Use the pulse interrupt instead of                                                                      an external signal */
name|t_FmRtcExceptionsCallback
modifier|*
name|f_ExternalTriggerCallback
decl_stmt|;
comment|/**< This routine will be called every                                                                      periodicPulsePeriod. */
block|}
name|t_FmRtcExternalTriggerParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_Enable   @Description   Enable the RTC (time count is started).                  The user can select to resume the time count from previous                 point, or to restart the time count.   @Param[in]     h_FmRtc     - Handle to FM RTC object.  @Param[in]     resetClock  - Restart the time count from zero.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_Enable
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|bool
name|resetClock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_Disable   @Description   Disables the RTC (time count is stopped).   @Param[in]     h_FmRtc - Handle to FM RTC object.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_Disable
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetClockOffset   @Description   Sets the clock offset (usually relative to another clock).                  The user can pass a negative offset value.   @Param[in]     h_FmRtc  - Handle to FM RTC object.  @Param[in]     offset   - New clock offset (in nanoseconds).   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetClockOffset
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|int64_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetAlarm   @Description   Schedules an alarm event to a given RTC time.   @Param[in]     h_FmRtc             - Handle to FM RTC object.  @Param[in]     p_FmRtcAlarmParams  - Alarm parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init().                 Must be called only prior to FM_RTC_Enable(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetAlarm
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|t_FmRtcAlarmParams
modifier|*
name|p_FmRtcAlarmParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetPeriodicPulse   @Description   Sets a periodic pulse.   @Param[in]     h_FmRtc                         - Handle to FM RTC object.  @Param[in]     p_FmRtcPeriodicPulseParams      - Periodic pulse parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init().                 Must be called only prior to FM_RTC_Enable(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetPeriodicPulse
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|t_FmRtcPeriodicPulseParams
modifier|*
name|p_FmRtcPeriodicPulseParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ClearPeriodicPulse   @Description   Clears a periodic pulse.   @Param[in]     h_FmRtc                         - Handle to FM RTC object.  @Param[in]     periodicPulseId                 - Periodic pulse id.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ClearPeriodicPulse
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint8_t
name|periodicPulseId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetExternalTrigger   @Description   Sets an external trigger indication and define a callback                 routine to be called on such event.   @Param[in]     h_FmRtc                         - Handle to FM RTC object.  @Param[in]     p_FmRtcExternalTriggerParams    - External Trigger parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetExternalTrigger
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|t_FmRtcExternalTriggerParams
modifier|*
name|p_FmRtcExternalTriggerParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_ClearExternalTrigger   @Description   Clears external trigger indication.   @Param[in]     h_FmRtc                         - Handle to FM RTC object.  @Param[in]     id                              - External Trigger id.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_ClearExternalTrigger
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint8_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_GetExternalTriggerTimeStamp   @Description   Reads the External Trigger TimeStamp.   @Param[in]     h_FmRtc                 - Handle to FM RTC object.  @Param[in]     triggerId               - External Trigger id.  @Param[out]    p_TimeStamp             - External Trigger timestamp (in nanoseconds).   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_GetExternalTriggerTimeStamp
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint8_t
name|triggerId
parameter_list|,
name|uint64_t
modifier|*
name|p_TimeStamp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_GetCurrentTime   @Description   Returns the current RTC time.   @Param[in]     h_FmRtc - Handle to FM RTC object.  @Param[out]    p_Ts - returned time stamp (in nanoseconds).   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_GetCurrentTime
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint64_t
modifier|*
name|p_Ts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetCurrentTime   @Description   Sets the current RTC time.   @Param[in]     h_FmRtc - Handle to FM RTC object.  @Param[in]     ts - The new time stamp (in nanoseconds).   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetCurrentTime
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint64_t
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_GetFreqCompensation   @Description   Retrieves the frequency compensation value   @Param[in]     h_FmRtc         - Handle to FM RTC object.  @Param[out]    p_Compensation  - A pointer to the returned value of compensation.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_GetFreqCompensation
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint32_t
modifier|*
name|p_Compensation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_SetFreqCompensation   @Description   Sets a new frequency compensation value.   @Param[in]     h_FmRtc             - Handle to FM RTC object.  @Param[in]     freqCompensation    - The new frequency compensation value to set.   @Return        E_OK on success; Error code otherwise.   @Cautions      h_FmRtc must have been previously initialized using FM_RTC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_SetFreqCompensation
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint32_t
name|freqCompensation
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PTP_1588_CLOCK_DPAA
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** *@Function      FM_RTC_EnableInterrupt * *@Description   Enable interrupt of FM RTC. * *@Param[in]     h_FmRtc             - Handle to FM RTC object. *@Param[in]     events              - Interrupt events. * *@Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_EnableInterrupt
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint32_t
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** *@Function      FM_RTC_DisableInterrupt * *@Description   Disable interrupt of FM RTC. * *@Param[in]     h_FmRtc             - Handle to FM RTC object. *@Param[in]     events              - Interrupt events. * *@Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_DisableInterrupt
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|,
name|uint32_t
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RTC_DumpRegs   @Description   Dumps all FM registers   @Param[in]     h_FmRtc      A handle to an FM RTC Module.   @Return        E_OK on success;   @Cautions      Allowed only FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_RTC_DumpRegs
parameter_list|(
name|t_Handle
name|h_FmRtc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& ... */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of fm_rtc_control_grp */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of fm_rtc_grp */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_RTC_EXT_H__ */
end_comment

end_unit

