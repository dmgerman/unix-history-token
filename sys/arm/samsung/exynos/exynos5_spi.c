begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Exynos 5 Serial Peripheral Interface (SPI)  */
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

begin_include
include|#
directive|include
file|<arm/samsung/exynos/exynos5_common.h>
end_include

begin_define
define|#
directive|define
name|CH_CFG
value|0x00
end_define

begin_comment
comment|/* SPI configuration */
end_comment

begin_define
define|#
directive|define
name|SW_RST
value|(1<< 5)
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|RX_CH_ON
value|(1<< 1)
end_define

begin_comment
comment|/* SPI Rx Channel On */
end_comment

begin_define
define|#
directive|define
name|TX_CH_ON
value|(1<< 0)
end_define

begin_comment
comment|/* SPI Tx Channel On */
end_comment

begin_define
define|#
directive|define
name|MODE_CFG
value|0x08
end_define

begin_comment
comment|/* FIFO control */
end_comment

begin_define
define|#
directive|define
name|CS_REG
value|0x0C
end_define

begin_comment
comment|/* slave selection control */
end_comment

begin_define
define|#
directive|define
name|NSSOUT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SPI_INT_EN
value|0x10
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SPI_STATUS
value|0x14
end_define

begin_comment
comment|/* SPI status */
end_comment

begin_define
define|#
directive|define
name|TX_FIFO_LVL_S
value|6
end_define

begin_define
define|#
directive|define
name|TX_FIFO_LVL_M
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RX_FIFO_LVL_S
value|15
end_define

begin_define
define|#
directive|define
name|RX_FIFO_LVL_M
value|0x1ff
end_define

begin_define
define|#
directive|define
name|SPI_TX_DATA
value|0x18
end_define

begin_comment
comment|/* Tx data */
end_comment

begin_define
define|#
directive|define
name|SPI_RX_DATA
value|0x1C
end_define

begin_comment
comment|/* Rx data */
end_comment

begin_define
define|#
directive|define
name|PACKET_CNT_REG
value|0x20
end_define

begin_comment
comment|/* packet count */
end_comment

begin_define
define|#
directive|define
name|PENDING_CLR_REG
value|0x24
end_define

begin_comment
comment|/* interrupt pending clear */
end_comment

begin_define
define|#
directive|define
name|SWAP_CFG
value|0x28
end_define

begin_comment
comment|/* swap configuration */
end_comment

begin_define
define|#
directive|define
name|FB_CLK_SEL
value|0x2C
end_define

begin_comment
comment|/* feedback clock selection */
end_comment

begin_define
define|#
directive|define
name|FB_CLK_180
value|0x2
end_define

begin_comment
comment|/* 180 degree phase lagging */
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
literal|2
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
name|struct
name|spi_softc
modifier|*
name|spi_sc
decl_stmt|;
end_decl_stmt

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
literal|"samsung,exynos5-spi"
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
literal|"Exynos 5 Serial Peripheral Interface (SPI)"
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
name|spi_sc
operator|=
name|sc
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|FB_CLK_SEL
argument_list|,
name|FB_CLK_180
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CH_CFG
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|RX_CH_ON
operator||
name|TX_CH_ON
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CH_CFG
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
name|reg
decl_stmt|;
name|uint32_t
name|i
decl_stmt|;
if|if
condition|(
name|bufsz
operator|==
literal|0
condition|)
block|{
comment|/* Nothing to transfer */
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Reset registers */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CH_CFG
argument_list|)
expr_stmt|;
name|reg
operator||=
name|SW_RST
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CH_CFG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|SW_RST
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CH_CFG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Assert CS */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CS_REG
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|NSSOUT
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CS_REG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
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
comment|/* TODO: Implement FIFO operation */
comment|/* Wait all the data shifted out */
while|while
condition|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_STATUS
argument_list|)
operator|&
expr|\
operator|(
name|TX_FIFO_LVL_M
operator|<<
name|TX_FIFO_LVL_S
operator|)
condition|)
continue|continue;
name|WRITE1
argument_list|(
name|sc
argument_list|,
name|SPI_TX_DATA
argument_list|,
name|out_buf
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* Wait until no data available */
while|while
condition|(
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_STATUS
argument_list|)
operator|&
expr|\
operator|(
name|RX_FIFO_LVL_M
operator|<<
name|RX_FIFO_LVL_S
operator|)
operator|)
operator|==
literal|0
condition|)
continue|continue;
name|in_buf
index|[
name|i
index|]
operator|=
name|READ1
argument_list|(
name|sc
argument_list|,
name|SPI_RX_DATA
argument_list|)
expr_stmt|;
block|}
comment|/* Deassert CS */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CS_REG
argument_list|)
expr_stmt|;
name|reg
operator||=
name|NSSOUT
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CS_REG
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

