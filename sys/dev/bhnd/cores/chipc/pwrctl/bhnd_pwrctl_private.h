begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_PWRCTL_BHND_PWRCTL_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_PWRCTL_BHND_PWRCTL_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|"bhnd_pwrctl_hostb_if.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_pwrctlvar.h"
end_include

begin_function_decl
name|int
name|bhnd_pwrctl_init
parameter_list|(
name|struct
name|bhnd_pwrctl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pwrctl_setclk
parameter_list|(
name|struct
name|bhnd_pwrctl_softc
modifier|*
name|sc
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pwrctl_getclk_speed
parameter_list|(
name|struct
name|bhnd_pwrctl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bhnd_pwrctl_fast_pwrup_delay
parameter_list|(
name|struct
name|bhnd_pwrctl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * If supported by the chipset, return the clock source for the given clock.  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock for which a clock source will be returned.  *  * @retval	bhnd_clksrc		The clock source for @p clock.  * @retval	BHND_CLKSRC_UNKNOWN	If @p clock is unsupported, or its  *					clock source is not known to the bus.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bhnd_clksrc
name|bhnd_pwrctl_hostb_get_clksrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_PWRCTL_HOSTB_GET_CLKSRC
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * If supported by the chipset, gate @p clock  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock to be disabled.  *  * @retval 0 success  * @retval ENODEV If bus-level clock source management is not supported.  * @retval ENXIO If bus-level management of @p clock is not supported.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_hostb_gate_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_PWRCTL_HOSTB_GATE_CLOCK
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * If supported by the chipset, ungate @p clock  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock to be enabled.  *  * @retval 0 success  * @retval ENODEV If bus-level clock source management is not supported.  * @retval ENXIO If bus-level management of @p clock is not supported.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_hostb_ungate_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_PWRCTL_HOSTB_UNGATE_CLOCK
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
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
comment|/* _BHND_PWRCTL_BHND_PWRCTL_PRIVATE_H_ */
end_comment

end_unit

