begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family 12-bit Analog to Digital Converter (ADC)  * Chapter 37, Vybrid Reference Manual, Rev. 5, 07/2013  */
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

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_adc.h>
end_include

begin_define
define|#
directive|define
name|ADC_HC0
value|0x00
end_define

begin_comment
comment|/* Ctrl reg for hardware triggers */
end_comment

begin_define
define|#
directive|define
name|ADC_HC1
value|0x04
end_define

begin_comment
comment|/* Ctrl reg for hardware triggers */
end_comment

begin_define
define|#
directive|define
name|HC_AIEN
value|(1<< 7)
end_define

begin_comment
comment|/* Conversion Complete Int Control */
end_comment

begin_define
define|#
directive|define
name|HC_ADCH_M
value|0x1f
end_define

begin_comment
comment|/* Input Channel Select Mask */
end_comment

begin_define
define|#
directive|define
name|HC_ADCH_S
value|0
end_define

begin_comment
comment|/* Input Channel Select Shift */
end_comment

begin_define
define|#
directive|define
name|ADC_HS
value|0x08
end_define

begin_comment
comment|/* Status register for HW triggers */
end_comment

begin_define
define|#
directive|define
name|HS_COCO0
value|(1<< 0)
end_define

begin_comment
comment|/* Conversion Complete Flag */
end_comment

begin_define
define|#
directive|define
name|HS_COCO1
value|(1<< 1)
end_define

begin_comment
comment|/* Conversion Complete Flag */
end_comment

begin_define
define|#
directive|define
name|ADC_R0
value|0x0C
end_define

begin_comment
comment|/* Data result reg for HW triggers */
end_comment

begin_define
define|#
directive|define
name|ADC_R1
value|0x10
end_define

begin_comment
comment|/* Data result reg for HW triggers */
end_comment

begin_define
define|#
directive|define
name|ADC_CFG
value|0x14
end_define

begin_comment
comment|/* Configuration register */
end_comment

begin_define
define|#
directive|define
name|CFG_OVWREN
value|(1<< 16)
end_define

begin_comment
comment|/* Data Overwrite Enable */
end_comment

begin_define
define|#
directive|define
name|CFG_AVGS_M
value|0x3
end_define

begin_comment
comment|/* Hardware Average select Mask */
end_comment

begin_define
define|#
directive|define
name|CFG_AVGS_S
value|14
end_define

begin_comment
comment|/* Hardware Average select Shift */
end_comment

begin_define
define|#
directive|define
name|CFG_ADTRG
value|(1<< 13)
end_define

begin_comment
comment|/* Conversion Trigger Select */
end_comment

begin_define
define|#
directive|define
name|CFG_REFSEL_M
value|0x3
end_define

begin_comment
comment|/* Voltage Reference Select Mask */
end_comment

begin_define
define|#
directive|define
name|CFG_REFSEL_S
value|11
end_define

begin_comment
comment|/* Voltage Reference Select Shift */
end_comment

begin_define
define|#
directive|define
name|CFG_ADHSC
value|(1<< 10)
end_define

begin_comment
comment|/* High Speed Configuration */
end_comment

begin_define
define|#
directive|define
name|CFG_ADSTS_M
value|0x3
end_define

begin_comment
comment|/* Defines the sample time duration */
end_comment

begin_define
define|#
directive|define
name|CFG_ADSTS_S
value|8
end_define

begin_comment
comment|/* Defines the sample time duration */
end_comment

begin_define
define|#
directive|define
name|CFG_ADLPC
value|(1<< 7)
end_define

begin_comment
comment|/* Low-Power Configuration */
end_comment

begin_define
define|#
directive|define
name|CFG_ADIV_M
value|0x3
end_define

begin_comment
comment|/* Clock Divide Select */
end_comment

begin_define
define|#
directive|define
name|CFG_ADIV_S
value|5
end_define

begin_comment
comment|/* Clock Divide Select */
end_comment

begin_define
define|#
directive|define
name|CFG_ADLSMP
value|(1<< 4)
end_define

begin_comment
comment|/* Long Sample Time Configuration */
end_comment

begin_define
define|#
directive|define
name|CFG_MODE_M
value|0x3
end_define

begin_comment
comment|/* Conversion Mode Selection Mask */
end_comment

begin_define
define|#
directive|define
name|CFG_MODE_S
value|2
end_define

begin_comment
comment|/* Conversion Mode Selection Shift */
end_comment

begin_define
define|#
directive|define
name|CFG_MODE_12
value|0x2
end_define

begin_comment
comment|/* 12-bit mode */
end_comment

begin_define
define|#
directive|define
name|CFG_ADICLK_M
value|0x3
end_define

begin_comment
comment|/* Input Clock Select Mask */
end_comment

begin_define
define|#
directive|define
name|CFG_ADICLK_S
value|0
end_define

begin_comment
comment|/* Input Clock Select Shift */
end_comment

begin_define
define|#
directive|define
name|ADC_GC
value|0x18
end_define

begin_comment
comment|/* General control register */
end_comment

begin_define
define|#
directive|define
name|GC_CAL
value|(1<< 7)
end_define

begin_comment
comment|/* Calibration */
end_comment

begin_define
define|#
directive|define
name|GC_ADCO
value|(1<< 6)
end_define

begin_comment
comment|/* Continuous Conversion Enable */
end_comment

begin_define
define|#
directive|define
name|GC_AVGE
value|(1<< 5)
end_define

begin_comment
comment|/* Hardware average enable */
end_comment

begin_define
define|#
directive|define
name|GC_ACFE
value|(1<< 4)
end_define

begin_comment
comment|/* Compare Function Enable */
end_comment

begin_define
define|#
directive|define
name|GC_ACFGT
value|(1<< 3)
end_define

begin_comment
comment|/* Compare Function Greater Than En */
end_comment

begin_define
define|#
directive|define
name|GC_ACREN
value|(1<< 2)
end_define

begin_comment
comment|/* Compare Function Range En */
end_comment

begin_define
define|#
directive|define
name|GC_DMAEN
value|(1<< 1)
end_define

begin_comment
comment|/* DMA Enable */
end_comment

begin_define
define|#
directive|define
name|GC_ADACKEN
value|(1<< 0)
end_define

begin_comment
comment|/* Asynchronous clock output enable */
end_comment

begin_define
define|#
directive|define
name|ADC_GS
value|0x1C
end_define

begin_comment
comment|/* General status register */
end_comment

begin_define
define|#
directive|define
name|GS_AWKST
value|(1<< 2)
end_define

begin_comment
comment|/* Asynchronous wakeup int status */
end_comment

begin_define
define|#
directive|define
name|GS_CALF
value|(1<< 1)
end_define

begin_comment
comment|/* Calibration Failed Flag */
end_comment

begin_define
define|#
directive|define
name|GS_ADACT
value|(1<< 0)
end_define

begin_comment
comment|/* Conversion Active */
end_comment

begin_define
define|#
directive|define
name|ADC_CV
value|0x20
end_define

begin_comment
comment|/* Compare value register */
end_comment

begin_define
define|#
directive|define
name|CV_CV2_M
value|0xfff
end_define

begin_comment
comment|/* Compare Value 2 Mask */
end_comment

begin_define
define|#
directive|define
name|CV_CV2_S
value|16
end_define

begin_comment
comment|/* Compare Value 2 Shift */
end_comment

begin_define
define|#
directive|define
name|CV_CV1_M
value|0xfff
end_define

begin_comment
comment|/* Compare Value 1 Mask */
end_comment

begin_define
define|#
directive|define
name|CV_CV1_S
value|0
end_define

begin_comment
comment|/* Compare Value 1 Shift */
end_comment

begin_define
define|#
directive|define
name|ADC_OFS
value|0x24
end_define

begin_comment
comment|/* Offset correction value register */
end_comment

begin_define
define|#
directive|define
name|OFS_SIGN
value|12
end_define

begin_comment
comment|/* Sign bit */
end_comment

begin_define
define|#
directive|define
name|OFS_M
value|0xfff
end_define

begin_comment
comment|/* Offset value Mask */
end_comment

begin_define
define|#
directive|define
name|OFS_S
value|0
end_define

begin_comment
comment|/* Offset value Shift */
end_comment

begin_define
define|#
directive|define
name|ADC_CAL
value|0x28
end_define

begin_comment
comment|/* Calibration value register */
end_comment

begin_define
define|#
directive|define
name|CAL_CODE_M
value|0xf
end_define

begin_comment
comment|/* Calibration Result Value Mask */
end_comment

begin_define
define|#
directive|define
name|CAL_CODE_S
value|0
end_define

begin_comment
comment|/* Calibration Result Value Shift */
end_comment

begin_define
define|#
directive|define
name|ADC_PCTL
value|0x30
end_define

begin_comment
comment|/* Pin control register */
end_comment

begin_struct
struct|struct
name|adc_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|adc_softc
modifier|*
name|adc_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|adc_spec
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
name|SYS_RES_IRQ
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
name|adc_probe
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
literal|"fsl,mvf600-adc"
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
literal|"Vybrid Family "
literal|"12-bit Analog to Digital Converter"
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
name|void
name|adc_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|adc_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|arg
expr_stmt|;
comment|/* Conversation complete */
block|}
end_function

begin_function
name|uint32_t
name|adc_read
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|adc_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|adc_sc
expr_stmt|;
if|if
condition|(
name|sc
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|ADC_R0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|adc_enable
parameter_list|(
name|int
name|channel
parameter_list|)
block|{
name|struct
name|adc_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|sc
operator|=
name|adc_sc
expr_stmt|;
if|if
condition|(
name|sc
operator|==
name|NULL
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|ADC_HC0
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|HC_ADCH_M
operator|<<
name|HC_ADCH_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|channel
operator|<<
name|HC_ADCH_S
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|ADC_HC0
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

begin_function
specifier|static
name|int
name|adc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|adc_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|err
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|adc_spec
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
name|adc_sc
operator|=
name|sc
expr_stmt|;
comment|/* Setup interrupt handler */
name|err
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|res
index|[
literal|1
index|]
argument_list|,
name|INTR_TYPE_BIO
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|adc_intr
argument_list|,
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|ih
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
literal|"Unable to alloc interrupt resource.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Configure 12-bit mode */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|ADC_CFG
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|CFG_MODE_M
operator|<<
name|CFG_MODE_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|CFG_MODE_12
operator|<<
name|CFG_MODE_S
operator|)
expr_stmt|;
comment|/* 12bit */
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|ADC_CFG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Configure for continuous conversion */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|ADC_GC
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|GC_ADCO
operator||
name|GC_AVGE
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|ADC_GC
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Disable interrupts */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|ADC_HC0
argument_list|)
expr_stmt|;
name|reg
operator|&=
name|HC_AIEN
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|ADC_HC0
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
name|adc_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|adc_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|adc_attach
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
name|adc_driver
init|=
block|{
literal|"adc"
block|,
name|adc_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|adc_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|adc_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|adc
argument_list|,
name|simplebus
argument_list|,
name|adc_driver
argument_list|,
name|adc_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

