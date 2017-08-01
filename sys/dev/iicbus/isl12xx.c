begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ian Lepore.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Driver for ISL12xx family i2c realtime clocks:  *  - ISL1209 = 2B sram, tamper/event timestamp  *  - ISL1218 = 8B sram, DS13xx pin compatible (but not software compatible)  *  - ISL1219 = 2B sram, tamper/event timestamp  *  - ISL1220 = 8B sram, separate Fout  *  - ISL1221 = 2B sram, separate Fout, tamper/event timestamp  *  * This driver supports only the basic RTC functionality in all these chips.  */
end_comment

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/clock.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/iicbus/iiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iicbus.h>
end_include

begin_include
include|#
directive|include
file|"clock_if.h"
end_include

begin_include
include|#
directive|include
file|"iicbus_if.h"
end_include

begin_comment
comment|/*  * All register and bit names as found in the datasheet.  When a bit name ends  * in 'B' that stands for "bar" and it is an active-low signal; something named  * "EVENB" implies 1=event-disable, 0=event-enable.  */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SC_REG
value|0x00
end_define

begin_comment
comment|/* RTC Seconds */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_REG
value|0x07
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_ARST
value|(1u<< 7)
end_define

begin_comment
comment|/*   Auto-reset on status read */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_XTOSCB
value|(1u<< 5)
end_define

begin_comment
comment|/*   Osc disable (use ext osc) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_WRTC
value|(1u<< 4)
end_define

begin_comment
comment|/*   Write RTC enable */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_EVT
value|(1u<< 3)
end_define

begin_comment
comment|/*   Event occurred (w0c) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_ALM
value|(1u<< 2)
end_define

begin_comment
comment|/*   Alarm occurred (w0c) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_BAT
value|(1u<< 1)
end_define

begin_comment
comment|/*   Running on battery (w0c) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_RTCF
value|(1u<< 0)
end_define

begin_comment
comment|/*   RTC fail (power loss) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SR_W0C_BITS
value|(ISL12XX_SR_BAT | ISL12XX_SR_ALM | ISL12XX_SR_EVT)
end_define

begin_define
define|#
directive|define
name|ISL12XX_INT_REG
value|0x08
end_define

begin_comment
comment|/* Interrupts */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_IM
value|(1u<< 7)
end_define

begin_comment
comment|/*   Alarm interrupt mode */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_ALME
value|(1u<< 6)
end_define

begin_comment
comment|/*   Alarm enable */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_LPMODE
value|(1u<< 5)
end_define

begin_comment
comment|/*   Low Power mode */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_FOBATB
value|(1u<< 4)
end_define

begin_comment
comment|/*   Fout/IRQ disabled on bat */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_FO_SHIFT
value|0
end_define

begin_comment
comment|/*   Frequency output select */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_INT_FO_MASK
value|0x0f
end_define

begin_comment
comment|/*   shift and mask. */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_REG
value|0x09
end_define

begin_comment
comment|/* Event */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_EVIENB
value|(1u<< 7)
end_define

begin_comment
comment|/*   Disable internal pullup */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_EVBATB
value|(1u<< 6)
end_define

begin_comment
comment|/*   Disable ev detect on bat */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_RTCHLT
value|(1u<< 5)
end_define

begin_comment
comment|/*   Halt RTC on event */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_EVEN
value|(1u<< 4)
end_define

begin_comment
comment|/*   Event detect enable */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_EHYS_SHIFT
value|2
end_define

begin_comment
comment|/*   Event input hysteresis */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_EHYS_MASK
value|0x03
end_define

begin_comment
comment|/*   selection; see datasheet */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_ESMP_SHIFT
value|0
end_define

begin_comment
comment|/*   Event input sample rate */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_EV_ESMP_MASK
value|0x03
end_define

begin_comment
comment|/*   selection; see datasheet */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_ATR_REG
value|0x0a
end_define

begin_comment
comment|/* Analog trim (osc adjust) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_DTR_REG
value|0x0b
end_define

begin_comment
comment|/* Digital trim (osc adjust) */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SCA_REG
value|0x0c
end_define

begin_comment
comment|/* Alarm seconds */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_USR1_REG
value|0x12
end_define

begin_comment
comment|/* User byte 1 */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_USR2_REG
value|0x13
end_define

begin_comment
comment|/* User byte 2 */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_SCT_REG
value|0x14
end_define

begin_comment
comment|/* Timestamp (event) seconds */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_24HR_FLAG
value|(1u<< 7)
end_define

begin_comment
comment|/* Hours register 24-hr mode */
end_comment

begin_define
define|#
directive|define
name|ISL12XX_PM_FLAG
value|(1u<< 5)
end_define

begin_comment
comment|/* Hours register PM flag */
end_comment

begin_define
define|#
directive|define
name|ISL12xx_12HR_MASK
value|0x1f
end_define

begin_comment
comment|/* Hours mask in AM/PM mode */
end_comment

begin_define
define|#
directive|define
name|ISL12xx_24HR_MASK
value|0x3f
end_define

begin_comment
comment|/* Hours mask in 24-hr mode */
end_comment

begin_comment
comment|/*  * A struct laid out in the same order as the time registers in the chip.  */
end_comment

begin_struct
struct|struct
name|time_regs
block|{
name|uint8_t
name|sec
decl_stmt|,
name|min
decl_stmt|,
name|hour
decl_stmt|,
name|day
decl_stmt|,
name|month
decl_stmt|,
name|year
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isl12xx_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|busdev
decl_stmt|;
name|struct
name|intr_config_hook
name|init_hook
decl_stmt|;
name|bool
name|use_ampm
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|ofw_compat_data
name|compat_data
index|[]
init|=
block|{
block|{
literal|"isil,isl1209"
block|,
literal|1
block|}
block|,
block|{
literal|"isil,isl1218"
block|,
literal|1
block|}
block|,
block|{
literal|"isil,isl1219"
block|,
literal|1
block|}
block|,
block|{
literal|"isil,isl1220"
block|,
literal|1
block|}
block|,
block|{
literal|"isil,isl1221"
block|,
literal|1
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|int
name|isl12xx_read1
parameter_list|(
name|struct
name|isl12xx_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|)
block|{
return|return
operator|(
name|iicdev_readfrom
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
name|data
argument_list|,
literal|1
argument_list|,
name|IIC_WAIT
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|isl12xx_write1
parameter_list|(
name|struct
name|isl12xx_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
return|return
operator|(
name|iicdev_writeto
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
operator|&
name|val
argument_list|,
literal|1
argument_list|,
name|IIC_WAIT
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|isl12xx_init
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|isl12xx_softc
modifier|*
name|sc
init|=
name|arg
decl_stmt|;
name|uint8_t
name|sreg
decl_stmt|;
name|config_intrhook_disestablish
argument_list|(
operator|&
name|sc
operator|->
name|init_hook
argument_list|)
expr_stmt|;
comment|/* 	 * Check the clock-stopped/power-fail bit, just so we can report it to 	 * the user at boot time. 	 */
name|isl12xx_read1
argument_list|(
name|sc
argument_list|,
name|ISL12XX_SR_REG
argument_list|,
operator|&
name|sreg
argument_list|)
expr_stmt|;
if|if
condition|(
name|sreg
operator|&
name|ISL12XX_SR_RTCF
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"RTC clock stopped; check battery\n"
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Register as a system realtime clock. 	 */
name|clock_register_flags
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|1000000
argument_list|,
name|CLOCKF_SETTIME_NO_ADJ
argument_list|)
expr_stmt|;
name|clock_schedule
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|isl12xx_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|FDT
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|ofw_bus_search_compatible
argument_list|(
name|dev
argument_list|,
name|compat_data
argument_list|)
operator|->
name|ocd_data
operator|!=
literal|0
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Intersil ISL12xx RTC"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
endif|#
directive|endif
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|isl12xx_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|isl12xx_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|sc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
name|sc
operator|->
name|busdev
operator|=
name|device_get_parent
argument_list|(
name|sc
operator|->
name|dev
argument_list|)
expr_stmt|;
comment|/* 	 * Chip init must wait until interrupts are enabled.  Often i2c access 	 * works only when the interrupts are available. 	 */
name|sc
operator|->
name|init_hook
operator|.
name|ich_func
operator|=
name|isl12xx_init
expr_stmt|;
name|sc
operator|->
name|init_hook
operator|.
name|ich_arg
operator|=
name|sc
expr_stmt|;
if|if
condition|(
name|config_intrhook_establish
argument_list|(
operator|&
name|sc
operator|->
name|init_hook
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENOMEM
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|isl12xx_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|clock_unregister
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|isl12xx_gettime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
name|struct
name|isl12xx_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|struct
name|clocktime
name|ct
decl_stmt|;
name|struct
name|time_regs
name|tregs
decl_stmt|;
name|int
name|err
decl_stmt|;
name|uint8_t
name|hourmask
decl_stmt|,
name|sreg
decl_stmt|;
comment|/* If power failed, we can't provide valid time. */
if|if
condition|(
operator|(
name|err
operator|=
name|isl12xx_read1
argument_list|(
name|sc
argument_list|,
name|ISL12XX_SR_REG
argument_list|,
operator|&
name|sreg
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|err
operator|)
return|;
if|if
condition|(
name|sreg
operator|&
name|ISL12XX_SR_RTCF
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Read the bcd time registers. */
if|if
condition|(
operator|(
name|err
operator|=
name|iicdev_readfrom
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|ISL12XX_SC_REG
argument_list|,
operator|&
name|tregs
argument_list|,
sizeof|sizeof
argument_list|(
name|tregs
argument_list|)
argument_list|,
name|IIC_WAIT
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* If chip is in AM/PM mode remember that for when we set time. */
if|if
condition|(
name|tregs
operator|.
name|hour
operator|&
name|ISL12XX_24HR_FLAG
condition|)
block|{
name|hourmask
operator|=
name|ISL12xx_24HR_MASK
expr_stmt|;
block|}
else|else
block|{
name|sc
operator|->
name|use_ampm
operator|=
name|true
expr_stmt|;
name|hourmask
operator|=
name|ISL12xx_12HR_MASK
expr_stmt|;
block|}
name|ct
operator|.
name|nsec
operator|=
literal|0
expr_stmt|;
name|ct
operator|.
name|sec
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|sec
argument_list|)
expr_stmt|;
name|ct
operator|.
name|min
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|min
argument_list|)
expr_stmt|;
name|ct
operator|.
name|hour
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|hour
operator|&
name|hourmask
argument_list|)
expr_stmt|;
name|ct
operator|.
name|day
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|day
argument_list|)
expr_stmt|;
name|ct
operator|.
name|mon
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|month
argument_list|)
expr_stmt|;
name|ct
operator|.
name|year
operator|=
name|FROMBCD
argument_list|(
name|tregs
operator|.
name|year
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|use_ampm
condition|)
block|{
if|if
condition|(
name|ct
operator|.
name|hour
operator|==
literal|12
condition|)
name|ct
operator|.
name|hour
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tregs
operator|.
name|hour
operator|&
name|ISL12XX_PM_FLAG
condition|)
name|ct
operator|.
name|hour
operator|+=
literal|12
expr_stmt|;
block|}
return|return
operator|(
name|clock_ct_to_ts
argument_list|(
operator|&
name|ct
argument_list|,
name|ts
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|isl12xx_settime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
name|struct
name|isl12xx_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|struct
name|clocktime
name|ct
decl_stmt|;
name|struct
name|time_regs
name|tregs
decl_stmt|;
name|int
name|err
decl_stmt|;
name|uint8_t
name|ampmflags
decl_stmt|,
name|sreg
decl_stmt|;
comment|/* 	 * We request a timespec with no resolution-adjustment.  That also 	 * disables utc adjustment, so apply that ourselves. 	 */
name|ts
operator|->
name|tv_sec
operator|-=
name|utc_offset
argument_list|()
expr_stmt|;
name|ts
operator|->
name|tv_nsec
operator|=
literal|0
expr_stmt|;
name|clock_ts_to_ct
argument_list|(
name|ts
argument_list|,
operator|&
name|ct
argument_list|)
expr_stmt|;
comment|/* If the chip is in AM/PM mode, adjust hour and set flags as needed. */
if|if
condition|(
operator|!
name|sc
operator|->
name|use_ampm
condition|)
block|{
name|ampmflags
operator|=
name|ISL12XX_24HR_FLAG
expr_stmt|;
block|}
else|else
block|{
name|ampmflags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ct
operator|.
name|hour
operator|>=
literal|12
condition|)
block|{
name|ct
operator|.
name|hour
operator|-=
literal|12
expr_stmt|;
name|ampmflags
operator||=
name|ISL12XX_PM_FLAG
expr_stmt|;
block|}
if|if
condition|(
name|ct
operator|.
name|hour
operator|==
literal|0
condition|)
name|ct
operator|.
name|hour
operator|=
literal|12
expr_stmt|;
block|}
name|tregs
operator|.
name|sec
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|sec
argument_list|)
expr_stmt|;
name|tregs
operator|.
name|min
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|min
argument_list|)
expr_stmt|;
name|tregs
operator|.
name|hour
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|hour
argument_list|)
operator||
name|ampmflags
expr_stmt|;
name|tregs
operator|.
name|day
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|day
argument_list|)
expr_stmt|;
name|tregs
operator|.
name|month
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|mon
argument_list|)
expr_stmt|;
name|tregs
operator|.
name|year
operator|=
name|TOBCD
argument_list|(
name|ct
operator|.
name|year
operator|%
literal|100
argument_list|)
expr_stmt|;
comment|/* 	 * To set the time we have to set the WRTC enable bit in the control 	 * register, then write the time regs, then clear the WRTC bit.  While 	 * doing so we have to be careful to not write a 0 to any sreg bit which 	 * is "write 0 to clear". One of those bits could get set between 	 * reading and writing the register.  All those bits ignore attempts to 	 * write a 1, so just always OR-in all the W0C bits to be sure we never 	 * accidentally clear one.  We hold ownership of the i2c bus for the 	 * whole read-modify-write sequence. 	 */
if|if
condition|(
operator|(
name|err
operator|=
name|iicbus_request_bus
argument_list|(
name|sc
operator|->
name|busdev
argument_list|,
name|sc
operator|->
name|dev
argument_list|,
name|IIC_WAIT
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|err
operator|)
return|;
if|if
condition|(
operator|(
name|err
operator|=
name|isl12xx_read1
argument_list|(
name|sc
argument_list|,
name|ISL12XX_SR_REG
argument_list|,
operator|&
name|sreg
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|sreg
operator||=
name|ISL12XX_SR_WRTC
operator||
name|ISL12XX_SR_W0C_BITS
expr_stmt|;
if|if
condition|(
operator|(
name|err
operator|=
name|isl12xx_write1
argument_list|(
name|sc
argument_list|,
name|ISL12XX_SR_REG
argument_list|,
name|sreg
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|err
operator|=
name|iicdev_writeto
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|ISL12XX_SC_REG
argument_list|,
operator|&
name|tregs
argument_list|,
sizeof|sizeof
argument_list|(
name|tregs
argument_list|)
argument_list|,
name|IIC_WAIT
argument_list|)
expr_stmt|;
name|sreg
operator|&=
operator|~
name|ISL12XX_SR_WRTC
expr_stmt|;
name|isl12xx_write1
argument_list|(
name|sc
argument_list|,
name|ISL12XX_SR_REG
argument_list|,
name|sreg
argument_list|)
expr_stmt|;
block|}
block|}
name|iicbus_release_bus
argument_list|(
name|sc
operator|->
name|busdev
argument_list|,
name|sc
operator|->
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|isl12xx_methods
index|[]
init|=
block|{
comment|/* device_if methods */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|isl12xx_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|isl12xx_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|isl12xx_detach
argument_list|)
block|,
comment|/* clock_if methods */
name|DEVMETHOD
argument_list|(
name|clock_gettime
argument_list|,
name|isl12xx_gettime
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|clock_settime
argument_list|,
name|isl12xx_settime
argument_list|)
block|,
name|DEVMETHOD_END
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|isl12xx_driver
init|=
block|{
literal|"isl12xx"
block|,
name|isl12xx_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|isl12xx_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|isl12xx_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|isl12xx
argument_list|,
name|iicbus
argument_list|,
name|isl12xx_driver
argument_list|,
name|isl12xx_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|isl12xx
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|isl12xx
argument_list|,
name|iicbus
argument_list|,
name|IICBUS_MINVER
argument_list|,
name|IICBUS_PREFVER
argument_list|,
name|IICBUS_MAXVER
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

