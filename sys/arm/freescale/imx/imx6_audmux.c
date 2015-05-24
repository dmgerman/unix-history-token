begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * i.MX6 Digital Audio Multiplexer (AUDMUX)  * Chapter 16, i.MX 6Dual/6Quad Applications Processor Reference Manual,  * Rev. 1, 04/2013  */
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
file|<sys/endian.h>
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

begin_define
define|#
directive|define
name|READ4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_4(_sc->bst, _sc->bsh, _reg)
end_define

begin_define
define|#
directive|define
name|WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4(_sc->bst, _sc->bsh, _reg, _val)
end_define

begin_define
define|#
directive|define
name|AUDMUX_PTCR
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n - 1))
end_define

begin_comment
comment|/* Port Timing Control Register */
end_comment

begin_define
define|#
directive|define
name|PTCR_TFS_DIR
value|(1<< 31)
end_define

begin_comment
comment|/* Transmit Frame Sync Direction Control */
end_comment

begin_define
define|#
directive|define
name|PTCR_TFSEL_S
value|27
end_define

begin_comment
comment|/* Transmit Frame Sync Select */
end_comment

begin_define
define|#
directive|define
name|PTCR_TFSEL_M
value|0xf
end_define

begin_define
define|#
directive|define
name|PTCR_TCLKDIR
value|(1<< 26)
end_define

begin_comment
comment|/* Transmit Clock Direction Control */
end_comment

begin_define
define|#
directive|define
name|PTCR_TCSEL_S
value|22
end_define

begin_comment
comment|/* Transmit Clock Select. */
end_comment

begin_define
define|#
directive|define
name|PTCR_TCSEL_M
value|0xf
end_define

begin_define
define|#
directive|define
name|PTCR_RFS_DIR
value|(1<< 21)
end_define

begin_comment
comment|/* Receive Frame Sync Direction Control */
end_comment

begin_define
define|#
directive|define
name|PTCR_SYN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AUDMUX_PDCR
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n - 1) + 0x4)
end_define

begin_comment
comment|/* Port Data Control Reg */
end_comment

begin_define
define|#
directive|define
name|PDCR_RXDSEL_S
value|13
end_define

begin_comment
comment|/* Receive Data Select */
end_comment

begin_define
define|#
directive|define
name|PDCR_RXDSEL_M
value|0x3
end_define

begin_define
define|#
directive|define
name|PDCR_RXDSEL_PORT
parameter_list|(
name|n
parameter_list|)
value|(n - 1)
end_define

begin_struct
struct|struct
name|audmux_softc
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
name|void
modifier|*
name|ih
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|audmux_spec
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
name|audmux_probe
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
literal|"fsl,imx6q-audmux"
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
literal|"i.MX6 Digital Audio Multiplexer"
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
name|audmux_configure
parameter_list|(
name|struct
name|audmux_softc
modifier|*
name|sc
parameter_list|,
name|int
name|ssi_port
parameter_list|,
name|int
name|audmux_port
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
comment|/* Direction: output */
name|reg
operator|=
operator|(
name|PTCR_TFS_DIR
operator||
name|PTCR_TCLKDIR
operator||
name|PTCR_SYN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|AUDMUX_PTCR
argument_list|(
name|audmux_port
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Select source */
name|reg
operator|=
operator|(
name|PDCR_RXDSEL_PORT
argument_list|(
name|ssi_port
argument_list|)
operator|<<
name|PDCR_RXDSEL_S
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|AUDMUX_PDCR
argument_list|(
name|audmux_port
argument_list|)
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
name|audmux_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|audmux_softc
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
name|audmux_spec
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
comment|/* 	 * Direct SSI1 output to AUDMUX5 pins. 	 * TODO: dehardcore this. 	 */
name|audmux_configure
argument_list|(
name|sc
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|device_method_t
name|audmux_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|audmux_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|audmux_attach
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
name|audmux_driver
init|=
block|{
literal|"audmux"
block|,
name|audmux_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|audmux_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|audmux_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|audmux
argument_list|,
name|simplebus
argument_list|,
name|audmux_driver
argument_list|,
name|audmux_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

