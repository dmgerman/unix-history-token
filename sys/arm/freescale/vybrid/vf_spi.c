begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Serial Peripheral Interface (SPI)  * Chapter 47, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
name|SPI_FIFO_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|SPI_MCR
value|0x00
end_define

begin_comment
comment|/* Module Configuration */
end_comment

begin_define
define|#
directive|define
name|MCR_MSTR
value|(1<< 31)
end_define

begin_comment
comment|/* Master/Slave Mode Select */
end_comment

begin_define
define|#
directive|define
name|MCR_CONT_SCKE
value|(1<< 30)
end_define

begin_comment
comment|/* Continuous SCK Enable */
end_comment

begin_define
define|#
directive|define
name|MCR_FRZ
value|(1<< 27)
end_define

begin_comment
comment|/* Freeze */
end_comment

begin_define
define|#
directive|define
name|MCR_PCSIS_S
value|16
end_define

begin_comment
comment|/* Peripheral Chip Select */
end_comment

begin_define
define|#
directive|define
name|MCR_PCSIS_M
value|0x3f
end_define

begin_define
define|#
directive|define
name|MCR_MDIS
value|(1<< 14)
end_define

begin_comment
comment|/* Module Disable */
end_comment

begin_define
define|#
directive|define
name|MCR_CLR_TXF
value|(1<< 11)
end_define

begin_comment
comment|/* Clear TX FIFO */
end_comment

begin_define
define|#
directive|define
name|MCR_CLR_RXF
value|(1<< 10)
end_define

begin_comment
comment|/* Clear RX FIFO */
end_comment

begin_define
define|#
directive|define
name|MCR_HALT
value|(1<< 0)
end_define

begin_comment
comment|/* Starts and stops SPI transfers */
end_comment

begin_define
define|#
directive|define
name|SPI_TCR
value|0x08
end_define

begin_comment
comment|/* Transfer Count */
end_comment

begin_define
define|#
directive|define
name|SPI_CTAR0
value|0x0C
end_define

begin_comment
comment|/* Clock and Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|SPI_CTAR0_SLAVE
value|0x0C
end_define

begin_comment
comment|/* Clock and Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|SPI_CTAR1
value|0x10
end_define

begin_comment
comment|/* Clock and Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|SPI_CTAR2
value|0x14
end_define

begin_comment
comment|/* Clock and Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|SPI_CTAR3
value|0x18
end_define

begin_comment
comment|/* Clock and Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|CTAR_FMSZ_M
value|0xf
end_define

begin_define
define|#
directive|define
name|CTAR_FMSZ_S
value|27
end_define

begin_comment
comment|/* Frame Size */
end_comment

begin_define
define|#
directive|define
name|CTAR_FMSZ_8
value|0x7
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|CTAR_CPOL
value|(1<< 26)
end_define

begin_comment
comment|/* Clock Polarity */
end_comment

begin_define
define|#
directive|define
name|CTAR_CPHA
value|(1<< 25)
end_define

begin_comment
comment|/* Clock Phase */
end_comment

begin_define
define|#
directive|define
name|CTAR_LSBFE
value|(1<< 24)
end_define

begin_comment
comment|/* Less significant bit first */
end_comment

begin_define
define|#
directive|define
name|CTAR_PCSSCK_M
value|0x3
end_define

begin_define
define|#
directive|define
name|CTAR_PCSSCK_S
value|22
end_define

begin_comment
comment|/* PCS to SCK Delay Prescaler */
end_comment

begin_define
define|#
directive|define
name|CTAR_PBR_M
value|0x3
end_define

begin_define
define|#
directive|define
name|CTAR_PBR_S
value|16
end_define

begin_comment
comment|/* Baud Rate Prescaler */
end_comment

begin_define
define|#
directive|define
name|CTAR_PBR_7
value|0x3
end_define

begin_comment
comment|/* Divide by 7 */
end_comment

begin_define
define|#
directive|define
name|CTAR_CSSCK_M
value|0xf
end_define

begin_define
define|#
directive|define
name|CTAR_CSSCK_S
value|12
end_define

begin_comment
comment|/* PCS to SCK Delay Scaler */
end_comment

begin_define
define|#
directive|define
name|CTAR_BR_M
value|0xf
end_define

begin_define
define|#
directive|define
name|CTAR_BR_S
value|0
end_define

begin_comment
comment|/* Baud Rate Scaler */
end_comment

begin_define
define|#
directive|define
name|SPI_SR
value|0x2C
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|SR_TCF
value|(1<< 31)
end_define

begin_comment
comment|/* Transfer Complete Flag */
end_comment

begin_define
define|#
directive|define
name|SR_EOQF
value|(1<< 28)
end_define

begin_comment
comment|/* End of Queue Flag */
end_comment

begin_define
define|#
directive|define
name|SR_TFFF
value|(1<< 25)
end_define

begin_comment
comment|/* Transmit FIFO Fill Flag */
end_comment

begin_define
define|#
directive|define
name|SR_RFDF
value|(1<< 17)
end_define

begin_comment
comment|/* Receive FIFO Drain Flag */
end_comment

begin_define
define|#
directive|define
name|SPI_RSER
value|0x30
end_define

begin_comment
comment|/* DMA/Interrupt Select */
end_comment

begin_define
define|#
directive|define
name|RSER_EOQF_RE
value|(1<< 28)
end_define

begin_comment
comment|/* Finished Request Enable */
end_comment

begin_define
define|#
directive|define
name|SPI_PUSHR
value|0x34
end_define

begin_comment
comment|/* PUSH TX FIFO In Master Mode */
end_comment

begin_define
define|#
directive|define
name|PUSHR_CONT
value|(1<< 31)
end_define

begin_comment
comment|/* Continuous Peripheral CS */
end_comment

begin_define
define|#
directive|define
name|PUSHR_EOQ
value|(1<< 27)
end_define

begin_comment
comment|/* End Of Queue */
end_comment

begin_define
define|#
directive|define
name|PUSHR_CTCNT
value|(1<< 26)
end_define

begin_comment
comment|/* Clear Transfer Counter */
end_comment

begin_define
define|#
directive|define
name|PUSHR_PCS_M
value|0x3f
end_define

begin_define
define|#
directive|define
name|PUSHR_PCS_S
value|16
end_define

begin_comment
comment|/* Select PCS signals */
end_comment

begin_define
define|#
directive|define
name|SPI_PUSHR_SLAVE
value|0x34
end_define

begin_comment
comment|/* PUSH TX FIFO Register In Slave Mode */
end_comment

begin_define
define|#
directive|define
name|SPI_POPR
value|0x38
end_define

begin_comment
comment|/* POP RX FIFO Register */
end_comment

begin_define
define|#
directive|define
name|SPI_TXFR0
value|0x3C
end_define

begin_comment
comment|/* Transmit FIFO Registers */
end_comment

begin_define
define|#
directive|define
name|SPI_TXFR1
value|0x40
end_define

begin_define
define|#
directive|define
name|SPI_TXFR2
value|0x44
end_define

begin_define
define|#
directive|define
name|SPI_TXFR3
value|0x48
end_define

begin_define
define|#
directive|define
name|SPI_RXFR0
value|0x7C
end_define

begin_comment
comment|/* Receive FIFO Registers */
end_comment

begin_define
define|#
directive|define
name|SPI_RXFR1
value|0x80
end_define

begin_define
define|#
directive|define
name|SPI_RXFR2
value|0x84
end_define

begin_define
define|#
directive|define
name|SPI_RXFR3
value|0x88
end_define

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
literal|"fsl,mvf600-spi"
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
literal|"Vybrid Family Serial Peripheral Interface"
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
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_MCR
argument_list|)
expr_stmt|;
name|reg
operator||=
name|MCR_MSTR
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|MCR_CONT_SCKE
operator||
name|MCR_MDIS
operator||
name|MCR_FRZ
operator|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|MCR_PCSIS_M
operator|<<
name|MCR_PCSIS_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|MCR_PCSIS_M
operator|<<
name|MCR_PCSIS_S
operator|)
expr_stmt|;
comment|/* PCS Active low */
name|reg
operator||=
operator|(
name|MCR_CLR_TXF
operator||
name|MCR_CLR_RXF
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_MCR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_RSER
argument_list|)
expr_stmt|;
name|reg
operator||=
name|RSER_EOQF_RE
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_RSER
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_MCR
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|MCR_HALT
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_MCR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_CTAR0
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|CTAR_FMSZ_M
operator|<<
name|CTAR_FMSZ_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|CTAR_FMSZ_8
operator|<<
name|CTAR_FMSZ_S
operator|)
expr_stmt|;
comment|/* 	 * TODO: calculate BR 	 * SCK baud rate = ( fsys / PBR ) * (1 + DBR) / BR 	 * 	 * reg&= ~(CTAR_BR_M<< CTAR_BR_S); 	 */
name|reg
operator|&=
operator|~
name|CTAR_CPOL
expr_stmt|;
comment|/* Polarity */
name|reg
operator||=
name|CTAR_CPHA
expr_stmt|;
comment|/* 	 * Set LSB (Less significant bit first) 	 * must be used for some applications, e.g. some LCDs 	 */
name|reg
operator||=
name|CTAR_LSBFE
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_CTAR0
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_CTAR0
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|CTAR_PBR_M
operator|<<
name|CTAR_PBR_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|CTAR_PBR_7
operator|<<
name|CTAR_PBR_S
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_CTAR0
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
decl_stmt|,
name|wreg
decl_stmt|;
name|uint32_t
name|txcnt
decl_stmt|;
name|uint32_t
name|i
decl_stmt|;
name|txcnt
operator|=
literal|0
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
name|txcnt
operator|++
expr_stmt|;
name|wreg
operator|=
name|out_buf
index|[
name|i
index|]
expr_stmt|;
name|wreg
operator||=
name|PUSHR_CONT
expr_stmt|;
name|wreg
operator||=
operator|(
name|cs
operator|<<
name|PUSHR_PCS_S
operator|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|wreg
operator||=
name|PUSHR_CTCNT
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|(
name|bufsz
operator|-
literal|1
operator|)
operator|||
name|txcnt
operator|==
name|SPI_FIFO_SIZE
condition|)
name|wreg
operator||=
name|PUSHR_EOQ
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_PUSHR
argument_list|,
name|wreg
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|(
name|bufsz
operator|-
literal|1
operator|)
operator|||
name|txcnt
operator|==
name|SPI_FIFO_SIZE
condition|)
block|{
name|txcnt
operator|=
literal|0
expr_stmt|;
comment|/* Wait last entry in a queue to be transmitted */
while|while
condition|(
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_SR
argument_list|)
operator|&
name|SR_EOQF
operator|)
operator|==
literal|0
condition|)
continue|continue;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_SR
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|SR_TCF
operator||
name|SR_EOQF
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|SPI_SR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
comment|/* Wait until RX FIFO is empty */
while|while
condition|(
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|SPI_SR
argument_list|)
operator|&
name|SR_RFDF
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
name|SPI_POPR
argument_list|)
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

