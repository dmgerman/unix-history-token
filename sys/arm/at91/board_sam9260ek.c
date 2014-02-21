begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Ethernut 5 board support  */
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
file|<machine/board.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pioreg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_piovar.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91board.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91sam9260reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_smc.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_gpio.h>
end_include

begin_include
include|#
directive|include
file|<dev/nand/nfc_at91.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|at91_smc_init
name|nand_smc
init|=
block|{
operator|.
name|ncs_rd_setup
operator|=
literal|0
block|,
operator|.
name|nrd_setup
operator|=
literal|1
block|,
operator|.
name|ncs_wr_setup
operator|=
literal|0
block|,
operator|.
name|nwe_setup
operator|=
literal|1
block|,
operator|.
name|ncs_rd_pulse
operator|=
literal|3
block|,
operator|.
name|nrd_pulse
operator|=
literal|3
block|,
operator|.
name|ncs_wr_pulse
operator|=
literal|3
block|,
operator|.
name|nwe_pulse
operator|=
literal|3
block|,
operator|.
name|nrd_cycle
operator|=
literal|5
block|,
operator|.
name|nwe_cycle
operator|=
literal|5
block|,
operator|.
name|mode
operator|=
name|SMC_MODE_READ
operator||
name|SMC_MODE_WRITE
operator||
name|SMC_MODE_EXNW_DISABLED
block|,
operator|.
name|tdf_cycles
operator|=
literal|2
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|at91_nand_params
name|nand_param
init|=
block|{
operator|.
name|ale
operator|=
literal|1u
operator|<<
literal|21
block|,
operator|.
name|cle
operator|=
literal|1u
operator|<<
literal|22
block|,
operator|.
name|width
operator|=
literal|8
block|,
operator|.
name|rnb_pin
operator|=
name|AT91_PIN_PC13
block|,
operator|.
name|nce_pin
operator|=
name|AT91_PIN_PC14
block|,
operator|.
name|cs
operator|=
literal|3
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|bi_dbgu
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * DBGU 	 */
comment|/* DRXD */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DTXD */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB15
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|bi_emac
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * EMAC 	 */
comment|/* ETX0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA12
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA13
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXEN */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXDV */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA17
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXER */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXCK */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA19
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* EMDC */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA20
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* EMDIO */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA21
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Not RMII */
comment|/* ETX2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA10
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA11
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXER */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA25
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA26
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXCK */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA27
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ECRS */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA28
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ECOL */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA29
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|bi_mmc
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * MMC, wired to socket B. 	 */
comment|/* MCDB0 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCCDB */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDB3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDB2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDB1 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCCK */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 	 * SPI0 and MMC are wired together, since we don't support sharing 	 * don't support the dataflash.  But if you did, you'd have to 	 * use CS0 and CS1. 	 */
block|}
end_function

begin_function
specifier|static
name|void
name|bi_iic
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * TWI.  Only one child on the iic bus, which we take care of 	 * via hints. 	 */
comment|/* TWD */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA23
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* TWCK */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA24
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|bi_usart0
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * USART0 	 */
comment|/* TXD0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* RXD0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DSR0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DCD0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB23
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DTR0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB24
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* RI0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB25
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* RTS0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB26
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* CTS0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB27
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|bi_usart1
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * USART1 	 */
comment|/* RTS1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB28
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* CTS1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB29
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* TXD1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* RXD1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9260_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB7
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|bi_nand
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Samsung 256MB SLC Flash */
comment|/* Setup Static Memory Controller */
name|at91_smc_setup
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
operator|&
name|nand_smc
argument_list|)
expr_stmt|;
name|at91_enable_nand
argument_list|(
operator|&
name|nand_param
argument_list|)
expr_stmt|;
comment|/* 	 * This assumes 	 *  - RNB is on pin PC13 	 *  - CE is on pin PC14 	 * 	 * Nothing actually uses RNB right now. 	 * 	 * For CE, this currently asserts it during board setup and leaves it 	 * that way forever. 	 * 	 * All this can go away when the gpio pin-renumbering happens... 	 */
name|at91_pio_use_gpio
argument_list|(
name|AT91SAM9260_PIOC_BASE
argument_list|,
name|AT91C_PIO_PC13
operator||
name|AT91C_PIO_PC14
argument_list|)
expr_stmt|;
name|at91_pio_gpio_input
argument_list|(
name|AT91SAM9260_PIOC_BASE
argument_list|,
name|AT91C_PIO_PC13
argument_list|)
expr_stmt|;
comment|/* RNB */
name|at91_pio_gpio_output
argument_list|(
name|AT91SAM9260_PIOC_BASE
argument_list|,
name|AT91C_PIO_PC14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* nCS */
name|at91_pio_gpio_clear
argument_list|(
name|AT91SAM9260_PIOC_BASE
argument_list|,
name|AT91C_PIO_PC14
argument_list|)
expr_stmt|;
comment|/* Assert nCS */
block|}
end_function

begin_function
name|BOARD_INIT
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
name|bi_dbgu
argument_list|()
expr_stmt|;
name|bi_emac
argument_list|()
expr_stmt|;
name|bi_mmc
argument_list|()
expr_stmt|;
comment|/* 	 * SPI1 is wired to a audio CODEC that we don't support, so 	 * give it a pass. 	 */
name|bi_iic
argument_list|()
expr_stmt|;
name|bi_usart0
argument_list|()
expr_stmt|;
name|bi_usart1
argument_list|()
expr_stmt|;
comment|/* USART2 - USART5 aren't wired up, except via PIO pins, ignore them. */
name|bi_nand
argument_list|()
expr_stmt|;
return|return
operator|(
name|at91_ramsize
argument_list|()
operator|)
return|;
block|}
end_function

begin_macro
name|ARM_BOARD
argument_list|(
argument|AT91SAM9260EK
argument_list|,
literal|"Atmel SMA9260-EK"
argument_list|)
end_macro

end_unit

