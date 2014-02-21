begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family System Reset Controller (SRC)  * Chapter 18, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|<arm/freescale/vybrid/vf_src.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|SRC_SCR
value|0x00
end_define

begin_comment
comment|/* SRC Control Register */
end_comment

begin_define
define|#
directive|define
name|SRC_SBMR1
value|0x04
end_define

begin_comment
comment|/* SRC Boot Mode Register 1 */
end_comment

begin_define
define|#
directive|define
name|SRC_SRSR
value|0x08
end_define

begin_comment
comment|/* SRC Status Register */
end_comment

begin_define
define|#
directive|define
name|SRC_SECR
value|0x0C
end_define

begin_comment
comment|/* SRC_SECR */
end_comment

begin_define
define|#
directive|define
name|SRC_SICR
value|0x14
end_define

begin_comment
comment|/* SRC Reset Interrupt Configuration Register */
end_comment

begin_define
define|#
directive|define
name|SRC_SIMR
value|0x18
end_define

begin_comment
comment|/* SRC Interrupt Masking Register */
end_comment

begin_define
define|#
directive|define
name|SRC_SBMR2
value|0x1C
end_define

begin_comment
comment|/* SRC Boot Mode Register 2 */
end_comment

begin_define
define|#
directive|define
name|SRC_GPR0
value|0x20
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|SRC_GPR1
value|0x24
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|SRC_GPR2
value|0x28
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|SRC_GPR3
value|0x2C
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|SRC_GPR4
value|0x30
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|SRC_MISC0
value|0x4C
end_define

begin_comment
comment|/* MISC0 */
end_comment

begin_define
define|#
directive|define
name|SRC_MISC1
value|0x50
end_define

begin_comment
comment|/* MISC1 */
end_comment

begin_define
define|#
directive|define
name|SRC_MISC2
value|0x54
end_define

begin_comment
comment|/* MISC2 */
end_comment

begin_define
define|#
directive|define
name|SRC_MISC3
value|0x58
end_define

begin_comment
comment|/* MISC3 */
end_comment

begin_struct
struct|struct
name|src_softc
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
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|src_softc
modifier|*
name|src_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|src_spec
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
name|int
name|src_swreset
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|src_sc
operator|==
name|NULL
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|WRITE4
argument_list|(
name|src_sc
argument_list|,
name|SRC_SCR
argument_list|,
name|SW_RST
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
name|src_probe
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
literal|"fsl,mvf600-src"
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
literal|"Vybrid Family System Reset Controller"
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
name|src_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|src_softc
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
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|src_spec
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
name|src_sc
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
name|src_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|src_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|src_attach
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
name|src_driver
init|=
block|{
literal|"src"
block|,
name|src_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|src_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|src_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|src
argument_list|,
name|simplebus
argument_list|,
name|src_driver
argument_list|,
name|src_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

