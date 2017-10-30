begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_RTC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_RTC_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_comment
comment|/* FM RTC Registers definitions */
end_comment

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_ALMP1
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_ALMP2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_FS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_PP1L
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_PP2L
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_TCLK_PERIOD_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_FRD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_SLV
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_ETEP1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_COPH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_CIPH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_TMSR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_DBG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_BYP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_TE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_CKSEL_OSC_CLK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_CKSEL_MAC_CLK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_CKSEL_EXT_CLK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_CTRL_TCLK_PERIOD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_ETS2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_ETS1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_ALM2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_ALM1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_PP1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_PP2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_PP3
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_TEVENT_ALL
value|(FMAN_RTC_TMR_TEVENT_ETS2 |\ 						FMAN_RTC_TMR_TEVENT_ETS1 |\ 						FMAN_RTC_TMR_TEVENT_ALM2 |\ 						FMAN_RTC_TMR_TEVENT_ALM1 |\ 						FMAN_RTC_TMR_TEVENT_PP1 |\ 						FMAN_RTC_TMR_TEVENT_PP2 |\ 						FMAN_RTC_TMR_TEVENT_PP3)
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_TMR_PRSC_OCK_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Alarm Polarity Options. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_rtc_alarm_polarity
block|{
name|E_FMAN_RTC_ALARM_POLARITY_ACTIVE_HIGH
block|,
comment|/**< Active-high output polarity */
name|E_FMAN_RTC_ALARM_POLARITY_ACTIVE_LOW
comment|/**< Active-low output polarity */
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM RTC Trigger Polarity Options. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_rtc_trigger_polarity
block|{
name|E_FMAN_RTC_TRIGGER_ON_RISING_EDGE
block|,
comment|/**< Trigger on rising edge */
name|E_FMAN_RTC_TRIGGER_ON_FALLING_EDGE
comment|/**< Trigger on falling edge */
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   IEEE1588 Timer Module FM RTC Optional Clock Sources. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_src_clock
block|{
name|E_FMAN_RTC_SOURCE_CLOCK_EXTERNAL
block|,
comment|/**< external high precision timer 						reference clock */
name|E_FMAN_RTC_SOURCE_CLOCK_SYSTEM
block|,
comment|/**< MAC system clock */
name|E_FMAN_RTC_SOURCE_CLOCK_OSCILATOR
comment|/**< RTC clock oscilator */
block|}
enum|;
end_enum

begin_comment
comment|/* RTC default values */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SRC_CLOCK
value|E_FMAN_RTC_SOURCE_CLOCK_SYSTEM
end_define

begin_define
define|#
directive|define
name|DEFAULT_INVERT_INPUT_CLK_PHASE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_INVERT_OUTPUT_CLK_PHASE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ALARM_POLARITY
value|E_FMAN_RTC_ALARM_POLARITY_ACTIVE_HIGH
end_define

begin_define
define|#
directive|define
name|DEFAULT_TRIGGER_POLARITY
value|E_FMAN_RTC_TRIGGER_ON_FALLING_EDGE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PULSE_REALIGN
value|FALSE
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_MAX_NUM_OF_ALARMS
value|3
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_MAX_NUM_OF_PERIODIC_PULSES
value|4
end_define

begin_define
define|#
directive|define
name|FMAN_RTC_MAX_NUM_OF_EXT_TRIGGERS
value|3
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

begin_struct
struct|struct
name|t_tmr_alarm
block|{
name|uint32_t
name|tmr_alarm_h
decl_stmt|;
comment|/**<  */
name|uint32_t
name|tmr_alarm_l
decl_stmt|;
comment|/**<  */
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description FM RTC timer Ex trigger */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_struct
struct|struct
name|t_tmr_ext_trigger
block|{
name|uint32_t
name|tmr_etts_h
decl_stmt|;
comment|/**<  */
name|uint32_t
name|tmr_etts_l
decl_stmt|;
comment|/**<  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_regs
block|{
name|uint32_t
name|tmr_id
decl_stmt|;
comment|/* 0x000 Module ID register */
name|uint32_t
name|tmr_id2
decl_stmt|;
comment|/* 0x004 Controller ID register */
name|uint32_t
name|reserved0008
index|[
literal|30
index|]
decl_stmt|;
name|uint32_t
name|tmr_ctrl
decl_stmt|;
comment|/* 0x0080 timer control register */
name|uint32_t
name|tmr_tevent
decl_stmt|;
comment|/* 0x0084 timer event register */
name|uint32_t
name|tmr_temask
decl_stmt|;
comment|/* 0x0088 timer event mask register */
name|uint32_t
name|reserved008c
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|tmr_cnt_h
decl_stmt|;
comment|/* 0x0098 timer counter high register */
name|uint32_t
name|tmr_cnt_l
decl_stmt|;
comment|/* 0x009c timer counter low register */
name|uint32_t
name|tmr_add
decl_stmt|;
comment|/* 0x00a0 timer drift compensation addend register */
name|uint32_t
name|tmr_acc
decl_stmt|;
comment|/* 0x00a4 timer accumulator register */
name|uint32_t
name|tmr_prsc
decl_stmt|;
comment|/* 0x00a8 timer prescale */
name|uint32_t
name|reserved00ac
decl_stmt|;
name|uint32_t
name|tmr_off_h
decl_stmt|;
comment|/* 0x00b0 timer offset high */
name|uint32_t
name|tmr_off_l
decl_stmt|;
comment|/* 0x00b4 timer offset low  */
name|struct
name|t_tmr_alarm
name|tmr_alarm
index|[
name|FMAN_RTC_MAX_NUM_OF_ALARMS
index|]
decl_stmt|;
comment|/* 0x00b8 timer 								alarm */
name|uint32_t
name|tmr_fiper
index|[
name|FMAN_RTC_MAX_NUM_OF_PERIODIC_PULSES
index|]
decl_stmt|;
comment|/* 0x00d0 timer 						fixed period interval */
name|struct
name|t_tmr_ext_trigger
name|tmr_etts
index|[
name|FMAN_RTC_MAX_NUM_OF_EXT_TRIGGERS
index|]
decl_stmt|;
comment|/* 0x00e0 time stamp general purpose external */
name|uint32_t
name|reserved00f0
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_cfg
block|{
name|enum
name|fman_src_clock
name|src_clk
decl_stmt|;
name|uint32_t
name|ext_src_clk_freq
decl_stmt|;
name|uint32_t
name|rtc_freq_hz
decl_stmt|;
name|bool
name|timer_slave_mode
decl_stmt|;
name|bool
name|invert_input_clk_phase
decl_stmt|;
name|bool
name|invert_output_clk_phase
decl_stmt|;
name|uint32_t
name|events_mask
decl_stmt|;
name|bool
name|bypass
decl_stmt|;
comment|/**< Indicates if frequency compensation 					is bypassed */
name|bool
name|pulse_realign
decl_stmt|;
name|enum
name|fman_rtc_alarm_polarity
name|alarm_polarity
index|[
name|FMAN_RTC_MAX_NUM_OF_ALARMS
index|]
decl_stmt|;
name|enum
name|fman_rtc_trigger_polarity
name|trigger_polarity
index|[
name|FMAN_RTC_MAX_NUM_OF_EXT_TRIGGERS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * fman_rtc_defconfig() - Get default RTC configuration  * @cfg:	pointer to configuration structure.  *  * Call this function to obtain a default set of configuration values for  * initializing RTC.  The user can overwrite any of the values before calling  * fman_rtc_init(), if specific configuration needs to be applied.  */
end_comment

begin_function_decl
name|void
name|fman_rtc_defconfig
parameter_list|(
name|struct
name|rtc_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_events() - Get the events  * @regs:		Pointer to RTC register block  *  * Returns: The events  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_get_events
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_interrupt_mask() - Get the events mask  * @regs:		Pointer to RTC register block  *  * Returns: The events mask  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_get_interrupt_mask
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_interrupt_mask() - Set the events mask  * @regs:		Pointer to RTC register block  * @mask:		The mask to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_interrupt_mask
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_event() - Check if specific events occurred  * @regs:		Pointer to RTC register block  * @ev_mask:	a mask of the events to check  *  * Returns: 0 if the events did not occur. Non zero if one of the events occurred  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_get_event
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_check_and_clear_event() - Clear events which are on  * @regs:		Pointer to RTC register block  *  * Returns: A mask of the events which were cleared  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_check_and_clear_event
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_ack_event() - Clear events  * @regs:		Pointer to RTC register block  * @events:		The events to disable  */
end_comment

begin_function_decl
name|void
name|fman_rtc_ack_event
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_enable_interupt() - Enable events interrupts  * @regs:		Pointer to RTC register block  * @mask:		The events to disable  */
end_comment

begin_function_decl
name|void
name|fman_rtc_enable_interupt
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_disable_interupt() - Disable events interrupts  * @regs:		Pointer to RTC register block  * @mask:		The events to disable  */
end_comment

begin_function_decl
name|void
name|fman_rtc_disable_interupt
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_timer_ctrl() - Get the control register  * @regs:		Pointer to RTC register block  *  * Returns: The control register value  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_get_timer_ctrl
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_timer_ctrl() - Set timer control register  * @regs:		Pointer to RTC register block  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_timer_ctrl
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_frequency_compensation() - Get the frequency compensation  * @regs:		Pointer to RTC register block  *  * Returns: The timer counter  */
end_comment

begin_function_decl
name|uint32_t
name|fman_rtc_get_frequency_compensation
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_frequency_compensation() - Set frequency compensation  * @regs:		Pointer to RTC register block  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_frequency_compensation
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_trigger_stamp() - Get a trigger stamp  * @regs:		Pointer to RTC register block  * @id:	The id of the trigger stamp  *  * Returns: The time stamp  */
end_comment

begin_function_decl
name|uint64_t
name|fman_rtc_get_trigger_stamp
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_timer_alarm_l() - Set timer alarm low register  * @regs:		Pointer to RTC register block  * @index:		The index of alarm to set  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_timer_alarm_l
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|index
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_timer_alarm() - Set timer alarm  * @regs:		Pointer to RTC register block  * @index:		The index of alarm to set  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_timer_alarm
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|index
parameter_list|,
name|int64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_timer_fiper() - Set timer fiper  * @regs:		Pointer to RTC register block  * @index:		The index of fiper to set  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_timer_fiper
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|index
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_timer_offset() - Set timer offset  * @regs:		Pointer to RTC register block  * @val:		The value to set  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_timer_offset
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_get_timer() - Get the timer counter  * @regs:		Pointer to RTC register block  *  * Returns: The timer counter  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint64_t
name|fman_rtc_get_timer
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
block|{
name|uint64_t
name|time
decl_stmt|;
comment|/* TMR_CNT_L must be read first to get an accurate value */
name|time
operator|=
operator|(
name|uint64_t
operator|)
name|ioread32be
argument_list|(
operator|&
name|regs
operator|->
name|tmr_cnt_l
argument_list|)
expr_stmt|;
name|time
operator||=
operator|(
operator|(
name|uint64_t
operator|)
name|ioread32be
argument_list|(
operator|&
name|regs
operator|->
name|tmr_cnt_h
argument_list|)
operator|<<
literal|32
operator|)
expr_stmt|;
return|return
name|time
return|;
block|}
end_function

begin_comment
comment|/**  * fman_rtc_set_timer() - Set timer counter  * @regs:		Pointer to RTC register block  * @val:		The value to set  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|fman_rtc_set_timer
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int64_t
name|val
parameter_list|)
block|{
name|iowrite32be
argument_list|(
operator|(
name|uint32_t
operator|)
name|val
argument_list|,
operator|&
name|regs
operator|->
name|tmr_cnt_l
argument_list|)
expr_stmt|;
name|iowrite32be
argument_list|(
call|(
name|uint32_t
call|)
argument_list|(
name|val
operator|>>
literal|32
argument_list|)
argument_list|,
operator|&
name|regs
operator|->
name|tmr_cnt_h
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * fman_rtc_timers_soft_reset() - Soft reset  * @regs:		Pointer to RTC register block  *  * Resets all the timer registers and state machines for the 1588 IP and  * the attached client 1588  */
end_comment

begin_function_decl
name|void
name|fman_rtc_timers_soft_reset
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_clear_external_trigger() - Clear an external trigger  * @regs:		Pointer to RTC register block  * @id: The id of the trigger to clear  */
end_comment

begin_function_decl
name|void
name|fman_rtc_clear_external_trigger
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_clear_periodic_pulse() - Clear periodic pulse  * @regs:		Pointer to RTC register block  * @id: The id of the fiper to clear  */
end_comment

begin_function_decl
name|void
name|fman_rtc_clear_periodic_pulse
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_enable() - Enable RTC hardware block  * @regs:		Pointer to RTC register block  */
end_comment

begin_function_decl
name|void
name|fman_rtc_enable
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|reset_clock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_is_enabled() - Is RTC hardware block enabled  * @regs:		Pointer to RTC register block  *  * Return: TRUE if enabled  */
end_comment

begin_function_decl
name|bool
name|fman_rtc_is_enabled
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_disable() - Disable RTC hardware block  * @regs:		Pointer to RTC register block  */
end_comment

begin_function_decl
name|void
name|fman_rtc_disable
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_init() - Init RTC hardware block  * @cfg:		RTC configuration data  * @regs:		Pointer to RTC register block  * @num_alarms:		Number of alarms in RTC  * @num_fipers:		Number of fipers in RTC  * @num_ext_triggers:	Number of external triggers in RTC  * @freq_compensation:		Frequency compensation  * @output_clock_divisor:		Output clock divisor  *  * This function initializes RTC and applies basic configuration.  */
end_comment

begin_function_decl
name|void
name|fman_rtc_init
parameter_list|(
name|struct
name|rtc_cfg
modifier|*
name|cfg
parameter_list|,
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|num_alarms
parameter_list|,
name|int
name|num_fipers
parameter_list|,
name|int
name|num_ext_triggers
parameter_list|,
name|bool
name|init_freq_comp
parameter_list|,
name|uint32_t
name|freq_compensation
parameter_list|,
name|uint32_t
name|output_clock_divisor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_alarm() - Set an alarm  * @regs:		Pointer to RTC register block  * @id:			id of alarm  * @val:		value to write  * @enable:		should interrupt be enabled  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_alarm
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_periodic_pulse() - Set an alarm  * @regs:		Pointer to RTC register block  * @id:			id of fiper  * @val:		value to write  * @enable:		should interrupt be enabled  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_periodic_pulse
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_rtc_set_ext_trigger() - Set an external trigger  * @regs:		Pointer to RTC register block  * @id:			id of trigger  * @enable:		should interrupt be enabled  * @use_pulse_as_input: use the pulse as input  */
end_comment

begin_function_decl
name|void
name|fman_rtc_set_ext_trigger
parameter_list|(
name|struct
name|rtc_regs
modifier|*
name|regs
parameter_list|,
name|int
name|id
parameter_list|,
name|bool
name|enable
parameter_list|,
name|bool
name|use_pulse_as_input
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|fm_rtc_alarm_params
block|{
name|uint8_t
name|alarm_id
decl_stmt|;
comment|/**< 0 or 1 */
name|uint64_t
name|alarm_time
decl_stmt|;
comment|/**< In nanoseconds, the time when the 					alarm should go off - must be a 					multiple of the RTC period */
name|void
function_decl|(
modifier|*
name|f_alarm_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|app
parameter_list|,
name|uint8_t
name|id
parameter_list|)
function_decl|;
comment|/**< This routine will 					be called when RTC reaches alarmTime */
name|bool
name|clear_on_expiration
decl_stmt|;
comment|/**< TRUE to turn off the alarm once 					expired.*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fm_rtc_periodic_pulse_params
block|{
name|uint8_t
name|periodic_pulse_id
decl_stmt|;
comment|/**< 0 or 1 */
name|uint64_t
name|periodic_pulse_period
decl_stmt|;
comment|/**< In Nanoseconds. Must be a multiple 					of the RTC period */
name|void
function_decl|(
modifier|*
name|f_periodic_pulse_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|app
parameter_list|,
name|uint8_t
name|id
parameter_list|)
function_decl|;
comment|/**< This 					routine will be called every 					periodicPulsePeriod. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_RTC_H */
end_comment

end_unit

