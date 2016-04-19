begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Xilinx AXI_QUAD_SPI  */
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
file|<dev/spibus/spi.h>
end_include

begin_include
include|#
directive|include
file|<dev/spibus/spibusvar.h>
end_include

begin_include
include|#
directive|include
file|"spibus_if.h"
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
name|SPI_SRR
value|0x40
end_define

begin_comment
comment|/* Software reset register */
end_comment

begin_define
define|#
directive|define
name|SRR_RESET
value|0x0A
end_define

begin_comment
comment|/* The only reset value */
end_comment

begin_define
define|#
directive|define
name|SPI_CR
value|0x60
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|CR_LSB_FIRST
value|(1<< 9)
end_define

begin_comment
comment|/* LSB first */
end_comment

begin_define
define|#
directive|define
name|CR_MASTER_TI
value|(1<< 8)
end_define

begin_comment
comment|/* Master Transaction Inhibit */
end_comment

begin_define
define|#
directive|define
name|CR_MSS
value|(1<< 7)
end_define

begin_comment
comment|/* Manual Slave Select */
end_comment

begin_define
define|#
directive|define
name|CR_RST_RX
value|(1<< 6)
end_define

begin_comment
comment|/* RX FIFO Reset */
end_comment

begin_define
define|#
directive|define
name|CR_RST_TX
value|(1<< 5)
end_define

begin_comment
comment|/* TX FIFO Reset */
end_comment

begin_define
define|#
directive|define
name|CR_CPHA
value|(1<< 4)
end_define

begin_comment
comment|/* Clock phase */
end_comment

begin_define
define|#
directive|define
name|CR_CPOL
value|(1<< 3)
end_define

begin_comment
comment|/* Clock polarity */
end_comment

begin_define
define|#
directive|define
name|CR_MASTER
value|(1<< 2)
end_define

begin_comment
comment|/* Master (SPI master mode) */
end_comment

begin_define
define|#
directive|define
name|CR_SPE
value|(1<< 1)
end_define

begin_comment
comment|/* SPI system enable */
end_comment

begin_define
define|#
directive|define
name|CR_LOOP
value|(1<< 0)
end_define

begin_comment
comment|/* Local loopback mode */
end_comment

begin_define
define|#
directive|define
name|SPI_SR
value|0x64
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|SR_TX_FULL
value|(1<< 3)
end_define

begin_comment
comment|/* Transmit full */
end_comment

begin_define
define|#
directive|define
name|SR_TX_EMPTY
value|(1<< 2)
end_define

begin_comment
comment|/* Transmit empty */
end_comment

begin_define
define|#
directive|define
name|SR_RX_FULL
value|(1<< 1)
end_define

begin_comment
comment|/* Receive full */
end_comment

begin_define
define|#
directive|define
name|SR_RX_EMPTY
value|(1<< 0)
end_define

begin_comment
comment|/* Receive empty */
end_comment

begin_define
define|#
directive|define
name|SPI_DTR
value|0x68
end_define

begin_comment
comment|/* Data transmit register */
end_comment

begin_define
define|#
directive|define
name|SPI_DRR
value|0x6C
end_define

begin_comment
comment|/* Data receive register */
end_comment

begin_define
define|#
directive|define
name|SPI_SSR
value|0x70
end_define

begin_comment
comment|/* Slave select register */
end_comment

begin_define
define|#
directive|define
name|SPI_TFOR
value|0x74
end_define

begin_comment
comment|/* Transmit FIFO Occupancy Register */
end_comment

begin_define
define|#
directive|define
name|SPI_RFOR
value|0x78
end_define

begin_comment
comment|/* Receive FIFO Occupancy Register */
end_comment

begin_define
define|#
directive|define
name|SPI_DGIER
value|0x1C
end_define

begin_comment
comment|/* Device global interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|SPI_IPISR
value|0x20
end_define

begin_comment
comment|/* IP interrupt status register */
end_comment

begin_define
define|#
directive|define
name|SPI_IPIER
value|0x28
end_define

begin_comment
comment|/* IP interrupt enable register */
end_comment

begin_struct
struct|struct
name|spi_softc
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
name|spi_spec
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
name|spi_probe
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
literal|"xlnx,xps-spi-3.2"
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
literal|"Xilinx Quad SPI"
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
name|spi_chip_select
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
block|{
name|struct
name|spi_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|cs
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|spibus_get_cs
argument_list|(
name|child
argument_list|,
operator|&
name|cs
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_SSR
argument_list|,
operator|~
operator|(
literal|1
operator|<<
name|cs
operator|)
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
name|spi_chip_deselect
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
block|{
name|struct
name|spi_softc
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
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_SSR
argument_list|,
operator|~
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
name|spi_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|spi_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
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
name|spi_spec
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
comment|/* Reset */
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_SRR
argument_list|,
name|SRR_RESET
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
name|CR_MASTER
operator||
name|CR_MSS
operator||
name|CR_RST_RX
operator||
name|CR_RST_TX
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_CR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_DGIER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Disable interrupts */
name|reg
operator|=
operator|(
name|CR_MASTER
operator||
name|CR_MSS
operator||
name|CR_SPE
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_CR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"spibus"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|bus_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|spi_txrx
parameter_list|(
name|struct
name|spi_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|out_buf
parameter_list|,
name|uint8_t
modifier|*
name|in_buf
parameter_list|,
name|int
name|bufsz
parameter_list|,
name|int
name|cs
parameter_list|)
block|{
name|uint32_t
name|data
decl_stmt|;
name|uint32_t
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|bufsz
condition|;
name|i
operator|++
control|)
block|{
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_DTR
argument_list|,
name|out_buf
index|[
name|i
index|]
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_SR
argument_list|)
operator|&
name|SR_TX_EMPTY
operator|)
condition|)
continue|continue;
name|data
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_DRR
argument_list|)
expr_stmt|;
if|if
condition|(
name|in_buf
condition|)
name|in_buf
index|[
name|i
index|]
operator|=
operator|(
name|data
operator|&
literal|0xff
operator|)
expr_stmt|;
block|}
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
name|spi_transfer
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|spi_command
modifier|*
name|cmd
parameter_list|)
block|{
name|struct
name|spi_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|cs
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|->
name|tx_cmd_sz
operator|==
name|cmd
operator|->
name|rx_cmd_sz
argument_list|,
operator|(
literal|"%s: TX/RX command sizes should be equal"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|->
name|tx_data_sz
operator|==
name|cmd
operator|->
name|rx_data_sz
argument_list|,
operator|(
literal|"%s: TX/RX data sizes should be equal"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
comment|/* get the proper chip select */
name|spibus_get_cs
argument_list|(
name|child
argument_list|,
operator|&
name|cs
argument_list|)
expr_stmt|;
comment|/* Command */
name|spi_txrx
argument_list|(
name|sc
argument_list|,
name|cmd
operator|->
name|tx_cmd
argument_list|,
name|cmd
operator|->
name|rx_cmd
argument_list|,
name|cmd
operator|->
name|tx_cmd_sz
argument_list|,
name|cs
argument_list|)
expr_stmt|;
comment|/* Data */
name|spi_txrx
argument_list|(
name|sc
argument_list|,
name|cmd
operator|->
name|tx_data
argument_list|,
name|cmd
operator|->
name|rx_data
argument_list|,
name|cmd
operator|->
name|tx_data_sz
argument_list|,
name|cs
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
name|spi_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|spi_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|spi_attach
argument_list|)
block|,
comment|/* SPI interface */
name|DEVMETHOD
argument_list|(
name|spibus_transfer
argument_list|,
name|spi_transfer
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|spibus_chip_select
argument_list|,
name|spi_chip_select
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|spibus_chip_deselect
argument_list|,
name|spi_chip_deselect
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|spi_driver
init|=
block|{
literal|"spi"
block|,
name|spi_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|spi_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|spi_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|spi
argument_list|,
name|simplebus
argument_list|,
name|spi_driver
argument_list|,
name|spi_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

