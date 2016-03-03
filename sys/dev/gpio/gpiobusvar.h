begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GPIOBUS_H__
end_ifndef

begin_define
define|#
directive|define
name|__GPIOBUS_H__
end_define

begin_include
include|#
directive|include
file|"opt_platform.h"
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
file|<sys/rman.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<gnu/dts/include/dt-bindings/gpio/gpio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gpio_if.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_define
define|#
directive|define
name|GPIOBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct gpiobus_ivar *)				\&((struct ofw_gpiobus_devinfo *)device_get_ivars(d))->opd_dinfo
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GPIOBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct gpiobus_ivar *) device_get_ivars(d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GPIOBUS_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct gpiobus_softc *) device_get_softc(d)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_init(&_sc->sc_mtx,			\ 	    device_get_nameunit(_sc->sc_dev), "gpiobus", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&_sc->sc_mtx)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_ASSERT_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_ASSERT_UNLOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&_sc->sc_mtx, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|GPIOBUS_DONTWAIT
value|2
end_define

begin_struct
struct|struct
name|gpiobus_pin_data
block|{
name|int
name|mapped
decl_stmt|;
comment|/* pin is mapped/reserved. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* pin name. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gpiobus_softc
block|{
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* bus mutex */
name|struct
name|rman
name|sc_intr_rman
decl_stmt|;
comment|/* isr resources */
name|device_t
name|sc_busdev
decl_stmt|;
comment|/* bus device */
name|device_t
name|sc_owner
decl_stmt|;
comment|/* bus owner */
name|device_t
name|sc_dev
decl_stmt|;
comment|/* driver device */
name|int
name|sc_npins
decl_stmt|;
comment|/* total pins on bus */
name|struct
name|gpiobus_pin_data
modifier|*
name|sc_pins
decl_stmt|;
comment|/* pin data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gpiobus_pin
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* gpio device */
name|uint32_t
name|flags
decl_stmt|;
comment|/* pin flags */
name|uint32_t
name|pin
decl_stmt|;
comment|/* pin number */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gpiobus_pin
modifier|*
name|gpio_pin_t
typedef|;
end_typedef

begin_struct
struct|struct
name|gpiobus_ivar
block|{
name|struct
name|resource_list
name|rl
decl_stmt|;
comment|/* isr resource list */
name|uint32_t
name|npins
decl_stmt|;
comment|/* pins total */
name|uint32_t
modifier|*
name|flags
decl_stmt|;
comment|/* pins flags */
name|uint32_t
modifier|*
name|pins
decl_stmt|;
comment|/* pins map */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_struct
struct|struct
name|ofw_gpiobus_devinfo
block|{
name|struct
name|gpiobus_ivar
name|opd_dinfo
decl_stmt|;
name|struct
name|ofw_bus_devinfo
name|opd_obdinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|gpio_map_gpios
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|phandle_t
name|dev
parameter_list|,
name|phandle_t
name|gparent
parameter_list|,
name|int
name|gcells
parameter_list|,
name|pcell_t
modifier|*
name|gpios
parameter_list|,
name|uint32_t
modifier|*
name|pin
parameter_list|,
name|uint32_t
modifier|*
name|flags
parameter_list|)
block|{
return|return
operator|(
name|GPIO_MAP_GPIOS
argument_list|(
name|bus
argument_list|,
name|dev
argument_list|,
name|gparent
argument_list|,
name|gcells
argument_list|,
name|gpios
argument_list|,
name|pin
argument_list|,
name|flags
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|device_t
name|ofw_gpiobus_add_fdt_child
parameter_list|(
name|device_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ofw_gpiobus_parse_gpios
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|gpiobus_pin
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_gpiobus_register_provider
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofw_gpiobus_unregister_provider
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Consumers interface. */
end_comment

begin_function_decl
name|int
name|gpio_pin_get_by_ofw_name
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|gpio_pin_t
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_get_by_ofw_idx
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|int
name|idx
parameter_list|,
name|gpio_pin_t
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_get_by_ofw_property
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|gpio_pin_t
modifier|*
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gpio_pin_release
parameter_list|(
name|gpio_pin_t
name|gpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_is_active
parameter_list|(
name|gpio_pin_t
name|pin
parameter_list|,
name|bool
modifier|*
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_set_active
parameter_list|(
name|gpio_pin_t
name|pin
parameter_list|,
name|bool
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpio_pin_setflags
parameter_list|(
name|gpio_pin_t
name|pin
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|gpio_check_flags
parameter_list|(
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|gpiobus_attach_bus
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpiobus_detach_bus
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpiobus_init_softc
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpiobus_alloc_ivars
parameter_list|(
name|struct
name|gpiobus_ivar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gpiobus_free_ivars
parameter_list|(
name|struct
name|gpiobus_ivar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gpiobus_map_pin
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|driver_t
name|gpiobus_driver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GPIOBUS_H__ */
end_comment

end_unit

