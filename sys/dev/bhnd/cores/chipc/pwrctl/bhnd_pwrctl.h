begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Landon Fuller under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_PWRCTL_BHND_PWRCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_PWRCTL_BHND_PWRCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pwrctl_if.h"
end_include

begin_comment
comment|/**   * Request that @p clock (or a faster clock) be enabled on behalf of  * @p child.  *  * @param dev PWRCTL device.  * @param child The requesting bhnd(4) device.  * @param clock Clock requested.  *  * @retval 0 success  * @retval ENODEV If an unsupported clock was requested.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_request_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_PWRCTL_REQUEST_CLOCK
argument_list|(
name|dev
argument_list|,
name|child
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the transition latency required for @p clock in microseconds, if  * known.  *  * The BHND_CLOCK_HT latency value is suitable for use as the D11 core's  * 'fastpwrup_dly' value.  *  * @param	dev	PWRCTL device.  * @param	clock	The clock to be queried for transition latency.  * @param[out]	latency	On success, the transition latency of @p clock in  *			microseconds.  *   * @retval 0 success  * @retval ENODEV If the transition latency for @p clock is not available.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_get_clock_latency
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
name|BHND_PWRCTL_GET_CLOCK_LATENCY
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
comment|/**  * Return the frequency for @p clock in Hz, if known.  *  * @param	dev	PWRCTL device.  * @param	clock	The clock to be queried.  * @param[out]	freq	On success, the frequency of @p clock in Hz.  *   * @retval 0 success  * @retval ENODEV If the frequency for @p clock is not available.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_get_clock_freq
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
name|BHND_PWRCTL_GET_CLOCK_FREQ
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_PWRCTL_BHND_PWRCTL_H_ */
end_comment

end_unit

