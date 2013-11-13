begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Clock Controller Module (CCM)  * Chapter 10, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|CCM_CCR
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CSR
value|0x04
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCSR
value|0x08
end_define

begin_comment
comment|/* Clock Switcher Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CACRR
value|0x0C
end_define

begin_comment
comment|/* ARM Clock Root Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCMR1
value|0x10
end_define

begin_comment
comment|/* Serial Clock Multiplexer Register 1 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR1
value|0x14
end_define

begin_comment
comment|/* Serial Clock Divider Register 1 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR2
value|0x18
end_define

begin_comment
comment|/* Serial Clock Divider Register 2 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR3
value|0x1C
end_define

begin_comment
comment|/* Serial Clock Divider Register 3 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCMR2
value|0x20
end_define

begin_comment
comment|/* Serial Clock Multiplexer Register 2 */
end_comment

begin_define
define|#
directive|define
name|CCM_CTOR
value|0x28
end_define

begin_comment
comment|/* Testing Observability Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CLPCR
value|0x2C
end_define

begin_comment
comment|/* Low Power Control Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CISR
value|0x30
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CIMR
value|0x34
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCOSR
value|0x38
end_define

begin_comment
comment|/* Clock Output Source Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CGPR
value|0x3C
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCGRN
value|12
end_define

begin_define
define|#
directive|define
name|CCM_CCGR
parameter_list|(
name|n
parameter_list|)
value|(0x40 + (n * 0x04))
end_define

begin_comment
comment|/* Clock Gating Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CMEOR
parameter_list|(
name|n
parameter_list|)
value|(0x70 + (n * 0x70))
end_define

begin_comment
comment|/* Module Enable Override Reg */
end_comment

begin_define
define|#
directive|define
name|CCM_CCPGR
parameter_list|(
name|n
parameter_list|)
value|(0x90 + (n * 0x04))
end_define

begin_comment
comment|/* Platform Clock Gating Reg */
end_comment

begin_define
define|#
directive|define
name|CCM_CPPDSR
value|0x88
end_define

begin_comment
comment|/* PLL PFD Disable Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCOWR
value|0x8C
end_define

begin_comment
comment|/* CORE Wakeup Register */
end_comment

begin_define
define|#
directive|define
name|PLL3_PFD4_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD3_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD2_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD1_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD4_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD3_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD2_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD1_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD4_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD3_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD2_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD1_EN
value|(1<< 8)
end_define

begin_comment
comment|/* CCM_CCR */
end_comment

begin_define
define|#
directive|define
name|FIRC_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FXOSC_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|FXOSC_RDY
value|(1<< 5)
end_define

begin_comment
comment|/* CCM_CSCDR1 */
end_comment

begin_define
define|#
directive|define
name|ENET_TS_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RMII_CLK_EN
value|(1<< 24)
end_define

begin_struct
struct|struct
name|ccm_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|ccm_spec
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
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ccm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"fsl,mvf600-ccm"
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
literal|"Vybrid Family CCM Unit"
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
name|ccm_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|ccm_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|int
name|i
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
name|dev
operator|=
name|dev
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|ccm_spec
argument_list|,
name|sc
operator|->
name|res
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Memory interface */
name|sc
operator|->
name|bst
operator|=
name|rman_get_bustag
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Enable oscillator */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CCM_CCR
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|FIRC_EN
operator||
name|FXOSC_EN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CCM_CCR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Wait 10 times */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|CCM_CSR
argument_list|)
operator|&
name|FXOSC_RDY
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"On board oscillator is ready.\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|cpufunc_nullop
argument_list|()
expr_stmt|;
block|}
comment|/* Clock is on during all modes, except stop mode. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|CCM_CCGRN
condition|;
name|i
operator|++
control|)
block|{
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CCM_CCGR
argument_list|(
name|i
argument_list|)
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
block|}
comment|/* Enable ENET clocks */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CCM_CSCDR1
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|ENET_TS_EN
operator||
name|RMII_CLK_EN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CCM_CSCDR1
argument_list|,
name|reg
argument_list|)
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
name|ccm_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ccm_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ccm_attach
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
name|ccm_driver
init|=
block|{
literal|"ccm"
block|,
name|ccm_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ccm_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ccm_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ccm
argument_list|,
name|simplebus
argument_list|,
name|ccm_driver
argument_list|,
name|ccm_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

