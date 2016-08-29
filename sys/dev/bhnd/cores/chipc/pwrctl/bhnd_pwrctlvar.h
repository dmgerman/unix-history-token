begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_PWRCTL_BHND_PWRCTLVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_PWRCTL_BHND_PWRCTLVAR_H_
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_function_decl
name|uint32_t
name|bhnd_pwrctl_clock_rate
parameter_list|(
name|uint32_t
name|pll_type
parameter_list|,
name|uint32_t
name|n
parameter_list|,
name|uint32_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_size_t
name|bhnd_pwrctl_si_clkreg_m
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|uint8_t
name|pll_type
parameter_list|,
name|uint32_t
modifier|*
name|fixed_hz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pwrctl_si_clock_rate
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|uint32_t
name|pll_type
parameter_list|,
name|uint32_t
name|n
parameter_list|,
name|uint32_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_size_t
name|bhnd_pwrctl_cpu_clkreg_m
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|uint8_t
name|pll_type
parameter_list|,
name|uint32_t
modifier|*
name|fixed_hz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pwrctl_cpu_clock_rate
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|uint32_t
name|pll_type
parameter_list|,
name|uint32_t
name|n
parameter_list|,
name|uint32_t
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * bhnd pwrctl device quirks.  */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|PWRCTL_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * Early ChipCommon revisions do not support dynamic clock control 	 */
name|PWRCTL_QUIRK_FIXED_CLK
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/** 	 * On PCI (not PCIe) devices, early ChipCommon revisions 	 * (rev<= 5) vend xtal/pll and clock config registers via the PCI 	 * config space. 	 *  	 * Dynamic clock control is not supported on these devices. 	 */
name|PWRCTL_QUIRK_PCICLK_CTL
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
operator||
name|PWRCTL_QUIRK_FIXED_CLK
block|,
comment|/** 	 * On earliy BCM4311, BCM4321, and BCM4716 PCI(e) devices, no ALP 	 * clock is available, and the HT clock must be enabled. 	 */
name|PWRCTL_QUIRK_FORCE_HT
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/** 	 * ChipCommon revisions 6-9 use the slowclk register layout. 	 */
name|PWRCTL_QUIRK_SLOWCLK_CTL
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/** 	 * ChipCommon revisions 10-19 support the instaclk register layout. 	 */
name|PWRCTL_QUIRK_INSTACLK_CTL
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,  }
enum|;
end_enum

begin_comment
comment|/**  * device clock reservation.  */
end_comment

begin_struct
struct|struct
name|bhnd_pwrctl_clkres
block|{
name|device_t
name|owner
decl_stmt|;
comment|/**< bhnd(4) device holding this reservation */
name|bhnd_clock
name|clock
decl_stmt|;
comment|/**< requested clock */
name|STAILQ_ENTRY
argument_list|(
argument|bhnd_pwrctl_clkres
argument_list|)
name|cr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhnd pwrctl driver instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_pwrctl_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|quirks
decl_stmt|;
name|device_t
name|chipc_dev
decl_stmt|;
comment|/**< core device */
name|struct
name|bhnd_resource
modifier|*
name|res
decl_stmt|;
comment|/**< core register block. */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< state mutex */
comment|/** active clock reservations */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|bhnd_pwrctl_clkres
argument_list|)
name|clkres_list
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PWRCTL_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "bhnd pwrctl driver lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|PWRCTL_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|PWRCTL_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|PWRCTL_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|PWRCTL_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_comment
comment|/* quirk convenience macro */
end_comment

begin_define
define|#
directive|define
name|PWRCTL_QUIRK
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|((_sc)->quirks& PWRCTL_QUIRK_ ## _name)
end_define

begin_define
define|#
directive|define
name|PWRCTL_ASSERT_QUIRK
parameter_list|(
name|_sc
parameter_list|,
name|name
parameter_list|)
define|\
value|KASSERT(PWRCTL_QUIRK((_sc), name), ("quirk " __STRING(_name) " not set"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_PWRCTL_BHND_PWRCTLVAR_H_ */
end_comment

end_unit

