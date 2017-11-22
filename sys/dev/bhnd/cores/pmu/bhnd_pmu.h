begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PMU_BHND_PMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PMU_BHND_PMU_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pmu_if.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_pmu_types.h"
end_include

begin_comment
comment|/**  * Return the current value of a PMU chipctrl register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU chipctrl register to be read.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_chipc() function.  *  * @returns The chipctrl register value, or 0 if undefined by this hardware.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|bhnd_pmu_read_chipctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_READ_CHIPCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Write @p value with @p mask to a PMU chipctrl register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU chipctrl register to be written.  * @param value The value to write.  * @param mask The mask of bits to be written from @p value.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_pmu() function.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_pmu_write_chipctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_WRITE_CHIPCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|,
name|value
argument_list|,
name|mask
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the current value of a PMU regulator control register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU regctrl register to be read.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_chipc() function.  *  * @returns The regctrl register value, or 0 if undefined by this hardware.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|bhnd_pmu_read_regctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_READ_REGCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Write @p value with @p mask to a PMU regulator control register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU regctrl register to be written.  * @param value The value to write.  * @param mask The mask of bits to be written from @p value.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_pmu() function.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_pmu_write_regctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_WRITE_REGCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|,
name|value
argument_list|,
name|mask
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the current value of a PMU PLL control register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU pllctrl register to be read.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_chipc() function.  *  * @returns The pllctrl register value, or 0 if undefined by this hardware.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|bhnd_pmu_read_pllctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_READ_PLLCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Write @p value with @p mask to a PMU PLL control register.  *  * @param dev A bhnd(4) PMU device.  * @param reg The PMU pllctrl register to be written.  * @param value The value to write.  * @param mask The mask of bits to be written from @p value.  *  * Drivers should only use function for functionality that is not  * available via another bhnd_pmu() function.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_pmu_write_pllctrl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_WRITE_PLLCTRL
argument_list|(
name|dev
argument_list|,
name|reg
argument_list|,
name|value
argument_list|,
name|mask
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Set a hardware-specific output voltage register value for @p regulator.  *  * @param dev PMU device.  * @param regulator Regulator to be configured.  * @param value The raw voltage register value.  *  * @retval 0 success  * @retval ENODEV If @p regulator is not supported by this driver.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_set_voltage_raw
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_pmu_regulator
name|regulator
parameter_list|,
name|uint32_t
name|value
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_SET_VOLTAGE_RAW
argument_list|(
name|dev
argument_list|,
name|regulator
argument_list|,
name|value
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Enable the given @p regulator.  *  * @param dev PMU device.  * @param regulator Regulator to be enabled.  *  * @retval 0 success  * @retval ENODEV If @p regulator is not supported by this driver.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_enable_regulator
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_pmu_regulator
name|regulator
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_ENABLE_REGULATOR
argument_list|(
name|dev
argument_list|,
name|regulator
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Disable the given @p regulator.  *  * @param dev PMU device.  * @param regulator Regulator to be disabled.  *  * @retval 0 success  * @retval ENODEV If @p regulator is not supported by this driver.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_disable_regulator
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_pmu_regulator
name|regulator
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_DISABLE_REGULATOR
argument_list|(
name|dev
argument_list|,
name|regulator
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the transition latency required for @p clock in microseconds, if  * known.  *  * The BHND_CLOCK_HT latency value is suitable for use as the D11 core's  * 'fastpwrup_dly' value.  *  * @param	dev	PMU device.  * @param	clock	The clock to be queried for transition latency.  * @param[out]	latency	On success, the transition latency of @p clock in  *			microseconds.  *   * @retval 0 success  * @retval ENODEV If the transition latency for @p clock is not available.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_get_clock_latency
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|,
name|u_int
modifier|*
name|latency
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_GET_CLOCK_LATENCY
argument_list|(
name|dev
argument_list|,
name|clock
argument_list|,
name|latency
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the frequency for @p clock in Hz, if known.  *  * @param dev PMU device.  * @param clock The clock to be queried.  * @param[out] freq On success, the frequency of @p clock in Hz.  *   * @retval 0 success  * @retval ENODEV If the frequency for @p clock is not available.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_get_clock_freq
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|,
name|u_int
modifier|*
name|freq
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_GET_CLOCK_FREQ
argument_list|(
name|dev
argument_list|,
name|clock
argument_list|,
name|freq
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Request that the PMU configure itself for a given hardware-specific  * spuravoid mode.  *  * @param dev PMU device.  * @param spuravoid The requested mode.  *  * @retval 0 success  * @retval ENODEV If @p regulator is not supported by this driver.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pmu_request_spuravoid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_pmu_spuravoid
name|spuravoid
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_REQUEST_SPURAVOID
argument_list|(
name|dev
argument_list|,
name|spuravoid
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the PMU's maximum state transition latency in microseconds.  *  * This upper bound may be used to busy-wait on PMU clock and resource state  * transitions.  *  * @param dev PMU device.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|bhnd_pmu_get_max_transition_latency
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_PMU_GET_MAX_TRANSITION_LATENCY
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PMU_BHND_PMU_H_ */
end_comment

end_unit

