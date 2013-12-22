begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/bus.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeet.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/watchdog.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_prcm.h>
end_include

begin_define
define|#
directive|define
name|AM335X_NUM_TIMERS
value|8
end_define

begin_define
define|#
directive|define
name|DMT_TIDR
value|0x00
end_define

begin_comment
comment|/* Identification Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TIOCP_CFG
value|0x10
end_define

begin_comment
comment|/* OCP Configuration Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TIOCP_RESET
value|(1<< 0)
end_define

begin_comment
comment|/* TIOCP perform soft reset */
end_comment

begin_define
define|#
directive|define
name|DMT_IQR_EOI
value|0x20
end_define

begin_comment
comment|/* IRQ End-Of-Interrupt Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQSTATUS_RAW
value|0x24
end_define

begin_comment
comment|/* IRQSTATUS Raw Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQSTATUS
value|0x28
end_define

begin_comment
comment|/* IRQSTATUS Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQENABLE_SET
value|0x2c
end_define

begin_comment
comment|/* IRQSTATUS Set Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQENABLE_CLR
value|0x30
end_define

begin_comment
comment|/* IRQSTATUS Clear Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQWAKEEN
value|0x34
end_define

begin_comment
comment|/* IRQ Wakeup Enable Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_TCAR
value|(1<< 0)
end_define

begin_comment
comment|/* IRQ: Capture */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_OVF
value|(1<< 1)
end_define

begin_comment
comment|/* IRQ: Overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_MAT
value|(1<< 2)
end_define

begin_comment
comment|/* IRQ: Match */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_MASK
value|(DMT_IRQ_TCAR | DMT_IRQ_OVF | DMT_IRQ_MAT)
end_define

begin_define
define|#
directive|define
name|DMT_TCLR
value|0x38
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_START
value|(1<< 0)
end_define

begin_comment
comment|/* Start timer */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_AUTOLOAD
value|(1<< 1)
end_define

begin_comment
comment|/* Auto-reload on overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PRES_MASK
value|(7<< 2)
end_define

begin_comment
comment|/* Prescaler mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PRES_ENABLE
value|(1<< 5)
end_define

begin_comment
comment|/* Prescaler enable */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_COMP_ENABLE
value|(1<< 6)
end_define

begin_comment
comment|/* Compare enable */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PWM_HIGH
value|(1<< 7)
end_define

begin_comment
comment|/* PWM default output high */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_MASK
value|(3<< 8)
end_define

begin_comment
comment|/* Capture transition mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_NONE
value|(0<< 8)
end_define

begin_comment
comment|/* Capture: none */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_LOHI
value|(1<< 8)
end_define

begin_comment
comment|/* Capture lo->hi transition */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_HILO
value|(2<< 8)
end_define

begin_comment
comment|/* Capture hi->lo transition */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_BOTH
value|(3<< 8)
end_define

begin_comment
comment|/* Capture both transitions */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_MASK
value|(3<< 10)
end_define

begin_comment
comment|/* Trigger output mode mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_NONE
value|(0<< 10)
end_define

begin_comment
comment|/* Trigger off */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_OVFL
value|(1<< 10)
end_define

begin_comment
comment|/* Trigger on overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_BOTH
value|(2<< 10)
end_define

begin_comment
comment|/* Trigger on match + ovflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PWM_PTOGGLE
value|(1<< 12)
end_define

begin_comment
comment|/* PWM toggles */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAP_MODE_2ND
value|(1<< 13)
end_define

begin_comment
comment|/* Capture second event mode */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_GPO_CFG
value|(1<< 14)
end_define

begin_comment
comment|/* (no descr in datasheet) */
end_comment

begin_define
define|#
directive|define
name|DMT_TCRR
value|0x3C
end_define

begin_comment
comment|/* Counter Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TLDR
value|0x40
end_define

begin_comment
comment|/* Load Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TTGR
value|0x44
end_define

begin_comment
comment|/* Trigger Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TWPS
value|0x48
end_define

begin_comment
comment|/* Write Posted Status Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TMAR
value|0x4C
end_define

begin_comment
comment|/* Match Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TCAR1
value|0x50
end_define

begin_comment
comment|/* Capture Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TSICR
value|0x54
end_define

begin_comment
comment|/* Synchr. Interface Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TSICR_RESET
value|0x02
end_define

begin_comment
comment|/* TSICR perform soft reset */
end_comment

begin_define
define|#
directive|define
name|DMT_TCAR2
value|0x48
end_define

begin_comment
comment|/* Capture Reg */
end_comment

begin_struct
struct|struct
name|am335x_dmtimer_softc
block|{
name|struct
name|resource
modifier|*
name|tmr_mem_res
index|[
name|AM335X_NUM_TIMERS
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|tmr_irq_res
index|[
name|AM335X_NUM_TIMERS
index|]
decl_stmt|;
name|uint32_t
name|sysclk_freq
decl_stmt|;
name|uint32_t
name|tc_num
decl_stmt|;
comment|/* Which timer number is tc. */
name|uint32_t
name|et_num
decl_stmt|;
comment|/* Which timer number is et. */
name|struct
name|resource
modifier|*
name|tc_memres
decl_stmt|;
comment|/* Resources for tc timer. */
name|struct
name|resource
modifier|*
name|et_memres
decl_stmt|;
comment|/* Resources for et timer. */
name|struct
name|timecounter
name|tc
decl_stmt|;
name|struct
name|eventtimer
name|et
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|am335x_dmtimer_softc
modifier|*
name|am335x_dmtimer_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|am335x_dmtimer_mem_spec
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
block|{
name|SYS_RES_MEMORY
block|,
literal|1
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|2
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|3
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|4
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|5
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|6
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|7
block|,
name|RF_ACTIVE
block|}
block|,
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

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|am335x_dmtimer_irq_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_IRQ
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|1
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|2
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|3
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|4
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|5
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|6
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|7
block|,
name|RF_ACTIVE
block|}
block|,
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

begin_function
specifier|static
specifier|inline
name|uint32_t
name|am335x_dmtimer_tc_read_4
parameter_list|(
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|bus_read_4
argument_list|(
name|sc
operator|->
name|tc_memres
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|am335x_dmtimer_tc_write_4
parameter_list|(
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_write_4
argument_list|(
name|sc
operator|->
name|tc_memres
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|am335x_dmtimer_et_read_4
parameter_list|(
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
operator|(
name|bus_read_4
argument_list|(
name|sc
operator|->
name|et_memres
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|am335x_dmtimer_et_write_4
parameter_list|(
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_write_4
argument_list|(
name|sc
operator|->
name|et_memres
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|am335x_dmtimer_tc_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|tc
operator|->
name|tc_priv
expr_stmt|;
return|return
operator|(
name|am335x_dmtimer_tc_read_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCRR
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|am335x_dmtimer_start
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|,
name|sbintime_t
name|first
parameter_list|,
name|sbintime_t
name|period
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|count
decl_stmt|,
name|load
decl_stmt|,
name|tclr
decl_stmt|;
name|sc
operator|=
name|et
operator|->
name|et_priv
expr_stmt|;
name|tclr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|period
operator|!=
literal|0
condition|)
block|{
name|load
operator|=
operator|(
operator|(
name|uint32_t
operator|)
name|et
operator|->
name|et_frequency
operator|*
name|period
operator|)
operator|>>
literal|32
expr_stmt|;
name|tclr
operator||=
name|DMT_TCLR_AUTOLOAD
expr_stmt|;
name|panic
argument_list|(
literal|"periodic timer not implemented\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|load
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|first
operator|!=
literal|0
condition|)
name|count
operator|=
operator|(
operator|(
name|uint32_t
operator|)
name|et
operator|->
name|et_frequency
operator|*
name|first
operator|)
operator|>>
literal|32
expr_stmt|;
else|else
name|count
operator|=
name|load
expr_stmt|;
comment|/* Reset Timer */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TSICR
argument_list|,
name|DMT_TSICR_RESET
argument_list|)
expr_stmt|;
comment|/* Wait for reset to complete */
while|while
condition|(
name|am335x_dmtimer_et_read_4
argument_list|(
name|sc
argument_list|,
name|DMT_TIOCP_CFG
argument_list|)
operator|&
name|DMT_TIOCP_RESET
condition|)
continue|continue;
comment|/* set load value */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TLDR
argument_list|,
literal|0xFFFFFFFE
operator|-
name|load
argument_list|)
expr_stmt|;
comment|/* set counter value */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCRR
argument_list|,
literal|0xFFFFFFFE
operator|-
name|count
argument_list|)
expr_stmt|;
comment|/* enable overflow interrupt */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_IRQENABLE_SET
argument_list|,
name|DMT_IRQ_OVF
argument_list|)
expr_stmt|;
comment|/* start timer(ST) */
name|tclr
operator||=
name|DMT_TCLR_START
expr_stmt|;
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCLR
argument_list|,
name|tclr
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
name|am335x_dmtimer_stop
parameter_list|(
name|struct
name|eventtimer
modifier|*
name|et
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|et
operator|->
name|et_priv
expr_stmt|;
comment|/* Disable all interrupts */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_IRQENABLE_CLR
argument_list|,
name|DMT_IRQ_MASK
argument_list|)
expr_stmt|;
comment|/* Stop Timer */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCLR
argument_list|,
literal|0
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
name|am335x_dmtimer_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|arg
expr_stmt|;
comment|/* Ack interrupt */
name|am335x_dmtimer_et_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_IRQSTATUS
argument_list|,
name|DMT_IRQ_OVF
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|et
operator|.
name|et_active
condition|)
name|sc
operator|->
name|et
operator|.
name|et_event_cb
argument_list|(
operator|&
name|sc
operator|->
name|et
argument_list|,
name|sc
operator|->
name|et
operator|.
name|et_arg
argument_list|)
expr_stmt|;
return|return
operator|(
name|FILTER_HANDLED
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|am335x_dmtimer_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"ti,am335x-dmtimer"
argument_list|)
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"AM335x DMTimer"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
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
name|am335x_dmtimer_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|void
modifier|*
name|ihl
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* 	 * Note that if this routine returns an error status rather than running 	 * to completion it makes no attempt to clean up allocated resources; 	 * the system is essentially dead anyway without functional timers. 	 */
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|am335x_dmtimer_sc
operator|!=
name|NULL
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Get the base clock frequency. */
name|err
operator|=
name|ti_prcm_clk_get_source_freq
argument_list|(
name|SYS_CLK
argument_list|,
operator|&
name|sc
operator|->
name|sysclk_freq
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
literal|"Error: could not get sysclk frequency\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Request the memory resources. */
name|err
operator|=
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|am335x_dmtimer_mem_spec
argument_list|,
name|sc
operator|->
name|tmr_mem_res
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
literal|"Error: could not allocate mem resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Request the IRQ resources. */
name|err
operator|=
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|am335x_dmtimer_irq_spec
argument_list|,
name|sc
operator|->
name|tmr_irq_res
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
literal|"Error: could not allocate irq resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Configure DMTimer3 as eventtimer and DMTimer4 as timecounter.  */
name|sc
operator|->
name|et_num
operator|=
literal|3
expr_stmt|;
name|sc
operator|->
name|tc_num
operator|=
literal|2
expr_stmt|;
name|sc
operator|->
name|et_memres
operator|=
name|sc
operator|->
name|tmr_mem_res
index|[
name|sc
operator|->
name|et_num
index|]
expr_stmt|;
name|sc
operator|->
name|tc_memres
operator|=
name|sc
operator|->
name|tmr_mem_res
index|[
name|sc
operator|->
name|tc_num
index|]
expr_stmt|;
name|err
operator|=
name|ti_prcm_clk_set_source
argument_list|(
name|DMTIMER0_CLK
operator|+
name|sc
operator|->
name|et_num
argument_list|,
name|SYSCLK_CLK
argument_list|)
expr_stmt|;
name|err
operator||=
name|ti_prcm_clk_enable
argument_list|(
name|DMTIMER0_CLK
operator|+
name|sc
operator|->
name|et_num
argument_list|)
expr_stmt|;
name|err
operator||=
name|ti_prcm_clk_set_source
argument_list|(
name|DMTIMER0_CLK
operator|+
name|sc
operator|->
name|tc_num
argument_list|,
name|SYSCLK_CLK
argument_list|)
expr_stmt|;
name|err
operator||=
name|ti_prcm_clk_enable
argument_list|(
name|DMTIMER0_CLK
operator|+
name|sc
operator|->
name|tc_num
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
literal|"Error: could not setup timer clock\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Set up timecounter; register tc. */
name|am335x_dmtimer_tc_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TSICR
argument_list|,
name|DMT_TSICR_RESET
argument_list|)
expr_stmt|;
while|while
condition|(
name|am335x_dmtimer_tc_read_4
argument_list|(
name|sc
argument_list|,
name|DMT_TIOCP_CFG
argument_list|)
operator|&
name|DMT_TIOCP_RESET
condition|)
continue|continue;
name|am335x_dmtimer_tc_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TLDR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|am335x_dmtimer_tc_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCRR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|am335x_dmtimer_tc_write_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCLR
argument_list|,
name|DMT_TCLR_START
operator||
name|DMT_TCLR_AUTOLOAD
argument_list|)
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_name
operator|=
literal|"AM335x Timecounter"
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_get_timecount
operator|=
name|am335x_dmtimer_tc_get_timecount
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_poll_pps
operator|=
name|NULL
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_counter_mask
operator|=
operator|~
literal|0u
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_frequency
operator|=
name|sc
operator|->
name|sysclk_freq
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_quality
operator|=
literal|1000
expr_stmt|;
name|sc
operator|->
name|tc
operator|.
name|tc_priv
operator|=
name|sc
expr_stmt|;
name|tc_init
argument_list|(
operator|&
name|sc
operator|->
name|tc
argument_list|)
expr_stmt|;
comment|/* Setup eventtimer; register et. */
if|if
condition|(
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|tmr_irq_res
index|[
name|sc
operator|->
name|et_num
index|]
argument_list|,
name|INTR_TYPE_CLK
argument_list|,
name|am335x_dmtimer_intr
argument_list|,
name|NULL
argument_list|,
name|sc
argument_list|,
operator|&
name|ihl
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|bus_release_resources
argument_list|(
name|dev
argument_list|,
name|am335x_dmtimer_irq_spec
argument_list|,
name|sc
operator|->
name|tmr_irq_res
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to setup the clock irq handler.\n"
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
name|et
operator|.
name|et_name
operator|=
literal|"AM335x Eventtimer"
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_flags
operator|=
name|ET_FLAGS_ONESHOT
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_quality
operator|=
literal|1000
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_frequency
operator|=
name|sc
operator|->
name|sysclk_freq
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_min_period
operator|=
operator|(
operator|(
literal|0x00000005LLU
operator|<<
literal|32
operator|)
operator|/
name|sc
operator|->
name|et
operator|.
name|et_frequency
operator|)
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_max_period
operator|=
operator|(
literal|0xfffffffeLLU
operator|<<
literal|32
operator|)
operator|/
name|sc
operator|->
name|et
operator|.
name|et_frequency
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_start
operator|=
name|am335x_dmtimer_start
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_stop
operator|=
name|am335x_dmtimer_stop
expr_stmt|;
name|sc
operator|->
name|et
operator|.
name|et_priv
operator|=
name|sc
expr_stmt|;
name|et_register
argument_list|(
operator|&
name|sc
operator|->
name|et
argument_list|)
expr_stmt|;
comment|/* Store a pointer to the softc for use in DELAY(). */
name|am335x_dmtimer_sc
operator|=
name|sc
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|am335x_dmtimer_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|am335x_dmtimer_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|am335x_dmtimer_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|am335x_dmtimer_driver
init|=
block|{
literal|"am335x_dmtimer"
block|,
name|am335x_dmtimer_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|am335x_dmtimer_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|am335x_dmtimer_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|am335x_dmtimer
argument_list|,
name|simplebus
argument_list|,
name|am335x_dmtimer_driver
argument_list|,
name|am335x_dmtimer_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|am335x_dmtimer
argument_list|,
name|am335x_prcm
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|cpu_initclocks
parameter_list|(
name|void
parameter_list|)
block|{
name|cpu_initclocks_bsp
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|DELAY
parameter_list|(
name|int
name|usec
parameter_list|)
block|{
name|struct
name|am335x_dmtimer_softc
modifier|*
name|sc
decl_stmt|;
name|int32_t
name|counts
decl_stmt|;
name|uint32_t
name|first
decl_stmt|,
name|last
decl_stmt|;
name|sc
operator|=
name|am335x_dmtimer_sc
expr_stmt|;
if|if
condition|(
name|sc
operator|==
name|NULL
condition|)
block|{
for|for
control|(
init|;
name|usec
operator|>
literal|0
condition|;
name|usec
operator|--
control|)
for|for
control|(
name|counts
operator|=
literal|200
init|;
name|counts
operator|>
literal|0
condition|;
name|counts
operator|--
control|)
comment|/* Prevent gcc from optimizing  out the loop */
name|cpufunc_nullop
argument_list|()
expr_stmt|;
return|return;
block|}
comment|/* Get the number of times to count */
name|counts
operator|=
operator|(
name|usec
operator|+
literal|1
operator|)
operator|*
operator|(
name|sc
operator|->
name|sysclk_freq
operator|/
literal|1000000
operator|)
expr_stmt|;
name|first
operator|=
name|am335x_dmtimer_tc_read_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCRR
argument_list|)
expr_stmt|;
while|while
condition|(
name|counts
operator|>
literal|0
condition|)
block|{
name|last
operator|=
name|am335x_dmtimer_tc_read_4
argument_list|(
name|sc
argument_list|,
name|DMT_TCRR
argument_list|)
expr_stmt|;
if|if
condition|(
name|last
operator|>
name|first
condition|)
block|{
name|counts
operator|-=
call|(
name|int32_t
call|)
argument_list|(
name|last
operator|-
name|first
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|counts
operator|-=
call|(
name|int32_t
call|)
argument_list|(
operator|(
literal|0xFFFFFFFF
operator|-
name|first
operator|)
operator|+
name|last
argument_list|)
expr_stmt|;
block|}
name|first
operator|=
name|last
expr_stmt|;
block|}
block|}
end_function

end_unit

