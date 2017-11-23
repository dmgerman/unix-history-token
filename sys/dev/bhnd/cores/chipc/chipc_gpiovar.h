begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Landon Fuller under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPC_GPIOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPC_GPIOVAR_H_
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_comment
comment|/**  * ChipCommon GPIO device quirks.  */
end_comment

begin_enum
enum|enum
block|{
comment|/** 	 * No GPIO event support. 	 *  	 * The CHIPC_GPIOEVENT, CHIPC_GPIOEVENT_INTM, and 	 * CHIPC_GPIOEVENT_INTPOLARITY registers are not available. 	 */
name|CC_GPIO_QUIRK_NO_EVENTS
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/** 	 * No GPIO duty-cycle timer support. 	 *  	 * The CHIPC_GPIOTIMERVAL and CHIPC_GPIOTIMEROUTMASK registers are not 	 * available. 	 */
name|CC_GPIO_QUIRK_NO_DCTIMER
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * No GPIO pull-up/pull-down configuration support. 	 * 	 * The CHIPC_GPIOPU and CHIPC_GPIOPD registers are not available. 	 */
name|CC_GPIO_QUIRK_NO_PULLUPDOWN
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/** 	 * Do not attach a child gpioc(4) device. 	 *  	 * This is primarily intended for use on bridged Wi-Fi adapters, where 	 * userspace modification of GPIO pin configuration could introduce 	 * significant undesirable behavior. 	 */
name|CC_GPIO_QUIRK_NO_GPIOC
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/** ChipCommon GPIO pin modes */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CC_GPIO_PIN_INPUT
block|,
name|CC_GPIO_PIN_OUTPUT
block|,
name|CC_GPIO_PIN_TRISTATE
block|}
name|chipc_gpio_pin_mode
typedef|;
end_typedef

begin_comment
comment|/**  * A single GPIO update register.  */
end_comment

begin_struct
struct|struct
name|chipc_gpio_reg
block|{
name|uint32_t
name|value
decl_stmt|;
comment|/**< register update value */
name|uint32_t
name|mask
decl_stmt|;
comment|/**< register update mask */
block|}
struct|;
end_struct

begin_comment
comment|/**  * A GPIO register update descriptor.  */
end_comment

begin_struct
struct|struct
name|chipc_gpio_update
block|{
name|struct
name|chipc_gpio_reg
name|pullup
decl_stmt|;
comment|/**< CHIPC_GPIOPU changes */
name|struct
name|chipc_gpio_reg
name|pulldown
decl_stmt|;
comment|/**< CHIPC_GPIOPD changes */
name|struct
name|chipc_gpio_reg
name|out
decl_stmt|;
comment|/**< CHIPC_GPIOOUT changes */
name|struct
name|chipc_gpio_reg
name|outen
decl_stmt|;
comment|/**< CHIPC_GPIOOUTEN changes */
name|struct
name|chipc_gpio_reg
name|timeroutmask
decl_stmt|;
comment|/**< CHIPC_GPIOTIMEROUTMASK changes */
name|struct
name|chipc_gpio_reg
name|ctrl
decl_stmt|;
comment|/**< CHIPC_GPIOCTRL changes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CC_GPIO_UPDATE
parameter_list|(
name|_upd
parameter_list|,
name|_pin
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|do {	\ 	(_upd)->_reg.mask |= (1<< (_pin));		\ 	if (_val)					\ 		(_upd)->_reg.value |= (1<< (_pin));	\ 	else						\ 		(_upd)->_reg.value&= (1<< (_pin));	\ } while(0)
end_define

begin_comment
comment|/**  * ChipCommon GPIO driver instance state.  */
end_comment

begin_struct
struct|struct
name|chipc_gpio_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|gpiobus
decl_stmt|;
comment|/**< attached gpiobus child */
name|struct
name|bhnd_resource
modifier|*
name|mem_res
decl_stmt|;
comment|/**< chipcommon register block */
name|int
name|mem_rid
decl_stmt|;
comment|/**< resource ID of mem_res */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< device quirks (see CC_GPIO_QUIRK_*) */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< lock protecting RMW register access */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CC_GPIO_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|mtx_init(&(sc)->mtx,	\     device_get_nameunit((sc)->dev), NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_LOCK_ASSERT
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
name|CC_GPIO_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_WR4
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bhnd_bus_write_4((sc)->mem_res, (off), (val))
end_define

begin_define
define|#
directive|define
name|CC_GPIO_WRFLAG
parameter_list|(
name|sc
parameter_list|,
name|pin_num
parameter_list|,
name|flag
parameter_list|,
name|val
parameter_list|)
define|\
value|CC_GPIO_WR4(sc, CHIPC_ ## flag,					\ 	    (CC_GPIO_RD4(sc, CHIPC_ ## flag)& ~(1<< pin_num)) |	\ 	     (val ? (1<< pin_num) : 0))
end_define

begin_define
define|#
directive|define
name|CC_GPIO_RD4
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bhnd_bus_read_4((sc)->mem_res, (off))
end_define

begin_define
define|#
directive|define
name|CC_GPIO_RDFLAG
parameter_list|(
name|sc
parameter_list|,
name|pin_num
parameter_list|,
name|flag
parameter_list|)
define|\
value|((CC_GPIO_RD4(sc, CHIPC_ ## flag)& (1<< pin_num)) != 0)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_NPINS
value|32
end_define

begin_define
define|#
directive|define
name|CC_GPIO_VALID_PIN
parameter_list|(
name|_pin
parameter_list|)
define|\
value|((_pin)>= 0&& (_pin)< CC_GPIO_NPINS)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_VALID_PINS
parameter_list|(
name|_first
parameter_list|,
name|_num
parameter_list|)
define|\
value|((_num)<= CC_GPIO_NPINS&& CC_GPIO_NPINS - (_num)>= _first)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_ASSERT_VALID_PIN
parameter_list|(
name|sc
parameter_list|,
name|pin_num
parameter_list|)
define|\
value|KASSERT(CC_GPIO_VALID_PIN(pin_num), ("invalid pin# %" PRIu32, pin_num));
end_define

begin_define
define|#
directive|define
name|CC_GPIO_QUIRK
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|((_sc)->quirks& CC_GPIO_QUIRK_ ## _name)
end_define

begin_define
define|#
directive|define
name|CC_GPIO_ASSERT_QUIRK
parameter_list|(
name|_sc
parameter_list|,
name|name
parameter_list|)
define|\
value|KASSERT(CC_GPIO_QUIRK((_sc), name), ("quirk " __STRING(_name) " not set"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_PWRCTL_BHND_PWRCTLVAR_H_ */
end_comment

end_unit

