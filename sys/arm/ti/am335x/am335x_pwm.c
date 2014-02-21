begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

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

begin_include
include|#
directive|include
file|<arm/ti/ti_prcm.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_scm.h>
end_include

begin_include
include|#
directive|include
file|"am335x_pwm.h"
end_include

begin_include
include|#
directive|include
file|"am335x_scm.h"
end_include

begin_comment
comment|/* In ticks */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PWM_PERIOD
value|1000
end_define

begin_define
define|#
directive|define
name|PWM_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|PWM_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|PWM_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_init(&(_sc)->sc_mtx, \     device_get_nameunit(_sc->sc_dev), "am335x_pwm softc", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|PWM_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_mtx);
end_define

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|am335x_pwm_mem_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
comment|/* PWMSS */
block|{
name|SYS_RES_MEMORY
block|,
literal|1
block|,
name|RF_ACTIVE
block|}
block|,
comment|/* eCAP */
block|{
name|SYS_RES_MEMORY
block|,
literal|2
block|,
name|RF_ACTIVE
block|}
block|,
comment|/* eQEP */
block|{
name|SYS_RES_MEMORY
block|,
literal|3
block|,
name|RF_ACTIVE
block|}
block|,
comment|/*ePWM */
block|{
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PWMSS_READ4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((_sc)->sc_mem_res[0], reg);
end_define

begin_define
define|#
directive|define
name|PWMSS_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_4((_sc)->sc_mem_res[0], reg, value);
end_define

begin_define
define|#
directive|define
name|ECAP_READ2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_2((_sc)->sc_mem_res[1], reg);
end_define

begin_define
define|#
directive|define
name|ECAP_WRITE2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_2((_sc)->sc_mem_res[1], reg, value);
end_define

begin_define
define|#
directive|define
name|ECAP_READ4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((_sc)->sc_mem_res[1], reg);
end_define

begin_define
define|#
directive|define
name|ECAP_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_4((_sc)->sc_mem_res[1], reg, value);
end_define

begin_define
define|#
directive|define
name|EPWM_READ2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_2((_sc)->sc_mem_res[3], reg);
end_define

begin_define
define|#
directive|define
name|EPWM_WRITE2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_2((_sc)->sc_mem_res[3], reg, value);
end_define

begin_define
define|#
directive|define
name|PWMSS_IDVER
value|0x00
end_define

begin_define
define|#
directive|define
name|PWMSS_SYSCONFIG
value|0x04
end_define

begin_define
define|#
directive|define
name|PWMSS_CLKCONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|CLKCONFIG_EPWMCLK_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PWMSS_CLKSTATUS
value|0x0C
end_define

begin_define
define|#
directive|define
name|ECAP_TSCTR
value|0x00
end_define

begin_define
define|#
directive|define
name|ECAP_CAP1
value|0x08
end_define

begin_define
define|#
directive|define
name|ECAP_CAP2
value|0x0C
end_define

begin_define
define|#
directive|define
name|ECAP_CAP3
value|0x10
end_define

begin_define
define|#
directive|define
name|ECAP_CAP4
value|0x14
end_define

begin_define
define|#
directive|define
name|ECAP_ECCTL2
value|0x2A
end_define

begin_define
define|#
directive|define
name|ECCTL2_MODE_APWM
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ECCTL2_SYNCO_SEL
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|ECCTL2_TSCTRSTOP_FREERUN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|EPWM_TBCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|TBCTL_FREERUN
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|TBCTL_PHDIR_UP
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|TBCTL_PHDIR_DOWN
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|TBCTL_CLKDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|TBCTL_CLKDIV_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|TBCTL_HSPCLKDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 7)
end_define

begin_define
define|#
directive|define
name|TBCTL_HSPCLKDIV_MASK
value|(3<< 7)
end_define

begin_define
define|#
directive|define
name|TBCTL_SYNCOSEL_DISABLED
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|TBCTL_PRDLD_SHADOW
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|TBCTL_PRDLD_IMMEDIATE
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|TBCTL_PHSEN_ENABLED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TBCTL_PHSEN_DISABLED
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|TBCTL_CTRMODE_MASK
value|(3)
end_define

begin_define
define|#
directive|define
name|TBCTL_CTRMODE_UP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|TBCTL_CTRMODE_DOWN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TBCTL_CTRMODE_UPDOWN
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|TBCTL_CTRMODE_FREEZE
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|EPWM_TBSTS
value|0x02
end_define

begin_define
define|#
directive|define
name|EPWM_TBPHSHR
value|0x04
end_define

begin_define
define|#
directive|define
name|EPWM_TBPHS
value|0x06
end_define

begin_define
define|#
directive|define
name|EPWM_TBCNT
value|0x08
end_define

begin_define
define|#
directive|define
name|EPWM_TBPRD
value|0x0a
end_define

begin_comment
comment|/* Counter-compare */
end_comment

begin_define
define|#
directive|define
name|EPWM_CMPCTL
value|0x0e
end_define

begin_define
define|#
directive|define
name|CMPCTL_SHDWBMODE_SHADOW
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CMPCTL_SHDWBMODE_IMMEDIATE
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|CMPCTL_SHDWAMODE_SHADOW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CMPCTL_SHDWAMODE_IMMEDIATE
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADBMODE_ZERO
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADBMODE_PRD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADBMODE_EITHER
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADBMODE_FREEZE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADAMODE_ZERO
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADAMODE_PRD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADAMODE_EITHER
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|CMPCTL_LOADAMODE_FREEZE
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|EPWM_CMPAHR
value|0x10
end_define

begin_define
define|#
directive|define
name|EPWM_CMPA
value|0x12
end_define

begin_define
define|#
directive|define
name|EPWM_CMPB
value|0x14
end_define

begin_comment
comment|/* CMPCTL_LOADAMODE_ZERO */
end_comment

begin_define
define|#
directive|define
name|EPWM_AQCTLA
value|0x16
end_define

begin_define
define|#
directive|define
name|EPWM_AQCTLB
value|0x18
end_define

begin_define
define|#
directive|define
name|AQCTL_CBU_NONE
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|AQCTL_CBU_CLEAR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AQCTL_CBU_SET
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|AQCTL_CBU_TOGGLE
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|AQCTL_CAU_NONE
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|AQCTL_CAU_CLEAR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AQCTL_CAU_SET
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|AQCTL_CAU_TOGGLE
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|AQCTL_ZRO_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|AQCTL_ZRO_CLEAR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AQCTL_ZRO_SET
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|AQCTL_ZRO_TOGGLE
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|EPWM_AQSFRC
value|0x1a
end_define

begin_define
define|#
directive|define
name|EPWM_AQCSFRC
value|0x1c
end_define

begin_comment
comment|/* Trip-Zone module */
end_comment

begin_define
define|#
directive|define
name|EPWM_TZCTL
value|0x28
end_define

begin_define
define|#
directive|define
name|EPWM_TZFLG
value|0x2C
end_define

begin_comment
comment|/* High-Resolution PWM */
end_comment

begin_define
define|#
directive|define
name|EPWM_HRCTL
value|0x40
end_define

begin_define
define|#
directive|define
name|HRCTL_DELMODE_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|HRCTL_DELMODE_FALL
value|2
end_define

begin_define
define|#
directive|define
name|HRCTL_DELMODE_RISE
value|1
end_define

begin_decl_stmt
specifier|static
name|device_probe_t
name|am335x_pwm_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_attach_t
name|am335x_pwm_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_detach_t
name|am335x_pwm_detach
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|am335x_pwm_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
index|[
literal|4
index|]
decl_stmt|;
name|int
name|sc_id
decl_stmt|;
comment|/* sysctl for configuration */
name|struct
name|sysctl_oid
modifier|*
name|sc_period_oid
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_chanA_oid
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_chanB_oid
decl_stmt|;
name|uint32_t
name|sc_pwm_period
decl_stmt|;
name|uint32_t
name|sc_pwm_dutyA
decl_stmt|;
name|uint32_t
name|sc_pwm_dutyB
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|device_method_t
name|am335x_pwm_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|am335x_pwm_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|am335x_pwm_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|am335x_pwm_detach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|am335x_pwm_driver
init|=
block|{
literal|"am335x_pwm"
block|,
name|am335x_pwm_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|am335x_pwm_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|am335x_pwm_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * API function to set period/duty cycles for ECASx   */
end_comment

begin_function
name|int
name|am335x_pwm_config_ecas
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|period
parameter_list|,
name|int
name|duty
parameter_list|)
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|am335x_pwm_softc
modifier|*
name|sc
decl_stmt|;
name|uint16_t
name|reg
decl_stmt|;
name|dev
operator|=
name|devclass_get_device
argument_list|(
name|am335x_pwm_devclass
argument_list|,
name|unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|dev
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
name|duty
operator|>
name|period
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
name|period
operator|==
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|PWM_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|reg
operator|=
name|ECAP_READ2
argument_list|(
name|sc
argument_list|,
name|ECAP_ECCTL2
argument_list|)
expr_stmt|;
name|reg
operator||=
name|ECCTL2_MODE_APWM
operator||
name|ECCTL2_TSCTRSTOP_FREERUN
operator||
name|ECCTL2_SYNCO_SEL
expr_stmt|;
name|ECAP_WRITE2
argument_list|(
name|sc
argument_list|,
name|ECAP_ECCTL2
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* CAP3 in APWM mode is APRD shadow register */
name|ECAP_WRITE4
argument_list|(
name|sc
argument_list|,
name|ECAP_CAP3
argument_list|,
name|period
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* CAP4 in APWM mode is ACMP shadow register */
name|ECAP_WRITE4
argument_list|(
name|sc
argument_list|,
name|ECAP_CAP4
argument_list|,
name|duty
argument_list|)
expr_stmt|;
comment|/* Restart counter */
name|ECAP_WRITE4
argument_list|(
name|sc
argument_list|,
name|ECAP_TSCTR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|PWM_UNLOCK
argument_list|(
name|sc
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
name|am335x_pwm_sysctl_duty
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|struct
name|am335x_pwm_softc
modifier|*
name|sc
init|=
operator|(
expr|struct
name|am335x_pwm_softc
operator|*
operator|)
name|arg1
decl_stmt|;
name|int
name|error
decl_stmt|;
name|uint32_t
name|duty
decl_stmt|;
if|if
condition|(
name|oidp
operator|==
name|sc
operator|->
name|sc_chanA_oid
condition|)
name|duty
operator|=
name|sc
operator|->
name|sc_pwm_dutyA
expr_stmt|;
else|else
name|duty
operator|=
name|sc
operator|->
name|sc_pwm_dutyB
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|duty
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
operator|||
name|req
operator|->
name|newptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|duty
operator|>
name|sc
operator|->
name|sc_pwm_period
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"Duty cycle can't be greater then period\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|PWM_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|oidp
operator|==
name|sc
operator|->
name|sc_chanA_oid
condition|)
block|{
name|sc
operator|->
name|sc_pwm_dutyA
operator|=
name|duty
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_CMPA
argument_list|,
name|sc
operator|->
name|sc_pwm_dutyA
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sc
operator|->
name|sc_pwm_dutyB
operator|=
name|duty
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_CMPB
argument_list|,
name|sc
operator|->
name|sc_pwm_dutyB
argument_list|)
expr_stmt|;
block|}
name|PWM_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|am335x_pwm_sysctl_period
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|struct
name|am335x_pwm_softc
modifier|*
name|sc
init|=
operator|(
expr|struct
name|am335x_pwm_softc
operator|*
operator|)
name|arg1
decl_stmt|;
name|int
name|error
decl_stmt|;
name|uint32_t
name|period
decl_stmt|;
name|period
operator|=
name|sc
operator|->
name|sc_pwm_period
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|period
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
operator|||
name|req
operator|->
name|newptr
operator|==
name|NULL
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|period
operator|<
literal|1
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
operator|(
name|period
operator|<
name|sc
operator|->
name|sc_pwm_dutyA
operator|)
operator|||
operator|(
name|period
operator|<
name|sc
operator|->
name|sc_pwm_dutyB
operator|)
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"Period can't be less then duty cycle\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|PWM_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_pwm_period
operator|=
name|period
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_TBPRD
argument_list|,
name|period
operator|-
literal|1
argument_list|)
expr_stmt|;
name|PWM_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|am335x_pwm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
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
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"ti,am335x-pwm"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"AM335x PWM"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|am335x_pwm_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|am335x_pwm_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|err
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
name|pcell_t
name|did
decl_stmt|;
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|tree
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_dev
operator|=
name|dev
expr_stmt|;
comment|/* Get the PWM module id */
name|node
operator|=
name|ofw_bus_get_node
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|OF_getprop
argument_list|(
name|node
argument_list|,
literal|"pwm-device-id"
argument_list|,
operator|&
name|did
argument_list|,
sizeof|sizeof
argument_list|(
name|did
argument_list|)
argument_list|)
operator|)
operator|<=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"missing pwm-device-id attribute in FDT\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|sc
operator|->
name|sc_id
operator|=
name|fdt32_to_cpu
argument_list|(
name|did
argument_list|)
expr_stmt|;
name|PWM_LOCK_INIT
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|err
operator|=
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|am335x_pwm_mem_spec
argument_list|,
name|sc
operator|->
name|sc_mem_res
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"cannot allocate memory resources\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|ti_prcm_clk_enable
argument_list|(
name|PWMSS0_CLK
operator|+
name|sc
operator|->
name|sc_id
argument_list|)
expr_stmt|;
name|ti_scm_reg_read_4
argument_list|(
name|SCM_PWMSS_CTRL
argument_list|,
operator|&
name|reg
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|1
operator|<<
name|sc
operator|->
name|sc_id
operator|)
expr_stmt|;
name|ti_scm_reg_write_4
argument_list|(
name|SCM_PWMSS_CTRL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Init backlight interface */
name|ctx
operator|=
name|device_get_sysctl_ctx
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|)
expr_stmt|;
name|tree
operator|=
name|device_get_sysctl_tree
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_period_oid
operator|=
name|SYSCTL_ADD_PROC
argument_list|(
name|ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"period"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|sc
argument_list|,
literal|0
argument_list|,
name|am335x_pwm_sysctl_period
argument_list|,
literal|"I"
argument_list|,
literal|"PWM period"
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_chanA_oid
operator|=
name|SYSCTL_ADD_PROC
argument_list|(
name|ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"dutyA"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|sc
argument_list|,
literal|0
argument_list|,
name|am335x_pwm_sysctl_duty
argument_list|,
literal|"I"
argument_list|,
literal|"Channel A duty cycles"
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_chanB_oid
operator|=
name|SYSCTL_ADD_PROC
argument_list|(
name|ctx
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|tree
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"dutyB"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
name|sc
argument_list|,
literal|0
argument_list|,
name|am335x_pwm_sysctl_duty
argument_list|,
literal|"I"
argument_list|,
literal|"Channel B duty cycles"
argument_list|)
expr_stmt|;
comment|/* CONFIGURE EPWM1 */
name|reg
operator|=
name|EPWM_READ2
argument_list|(
name|sc
argument_list|,
name|EPWM_TBCTL
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|TBCTL_CLKDIV_MASK
operator||
name|TBCTL_HSPCLKDIV_MASK
operator|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_TBCTL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_pwm_period
operator|=
name|DEFAULT_PWM_PERIOD
expr_stmt|;
name|sc
operator|->
name|sc_pwm_dutyA
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_pwm_dutyB
operator|=
literal|0
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_TBPRD
argument_list|,
name|sc
operator|->
name|sc_pwm_period
operator|-
literal|1
argument_list|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_CMPA
argument_list|,
name|sc
operator|->
name|sc_pwm_dutyA
argument_list|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_CMPB
argument_list|,
name|sc
operator|->
name|sc_pwm_dutyB
argument_list|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_AQCTLA
argument_list|,
operator|(
name|AQCTL_ZRO_SET
operator||
name|AQCTL_CAU_CLEAR
operator|)
argument_list|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_AQCTLB
argument_list|,
operator|(
name|AQCTL_ZRO_SET
operator||
name|AQCTL_CBU_CLEAR
operator|)
argument_list|)
expr_stmt|;
comment|/* START EPWM */
name|reg
operator|&=
operator|~
name|TBCTL_CTRMODE_MASK
expr_stmt|;
name|reg
operator||=
name|TBCTL_CTRMODE_UP
operator||
name|TBCTL_FREERUN
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_TBCTL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|EPWM_WRITE2
argument_list|(
name|sc
argument_list|,
name|EPWM_TZCTL
argument_list|,
literal|0xf
argument_list|)
expr_stmt|;
name|reg
operator|=
name|EPWM_READ2
argument_list|(
name|sc
argument_list|,
name|EPWM_TZFLG
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|fail
label|:
name|PWM_LOCK_DESTROY
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_mem_res
index|[
literal|0
index|]
condition|)
name|bus_release_resources
argument_list|(
name|dev
argument_list|,
name|am335x_pwm_mem_spec
argument_list|,
name|sc
operator|->
name|sc_mem_res
argument_list|)
expr_stmt|;
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
name|am335x_pwm_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|am335x_pwm_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|PWM_LOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_mem_res
index|[
literal|0
index|]
condition|)
name|bus_release_resources
argument_list|(
name|dev
argument_list|,
name|am335x_pwm_mem_spec
argument_list|,
name|sc
operator|->
name|sc_mem_res
argument_list|)
expr_stmt|;
name|PWM_UNLOCK
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|PWM_LOCK_DESTROY
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|am335x_pwm
argument_list|,
name|simplebus
argument_list|,
name|am335x_pwm_driver
argument_list|,
name|am335x_pwm_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|am335x_pwm
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|am335x_pwm
argument_list|,
name|simplebus
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

