begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Greg Ansley.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*   * This board file can be used for both:  * SAM9X26EK board  */
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
file|<arm/at91/at91board.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91var.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91sam9g20reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_piovar.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pio_sam9g20.h>
end_include

begin_comment
comment|//#include<arm/at91/at91_led.h>
end_comment

begin_function
name|BOARD_INIT
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/* PIOB's A periph: Turn USART 0's TX/RX pins */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB14_DRXD, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB15_DTXD, 1);
comment|/* PIOB's A periph: Turn USART 0's TX/RX pins */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB4_TXD0, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB5_RXD0, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB22_DSR0, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB23_DCD0, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB24_DTR0, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB25_RI0, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB26_RTS0, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB27_CTS0, 0);
comment|/* PIOB's A periph: Turn USART 1's TX/RX pins */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB6_TXD1, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB7_RXD1, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB28_RTS1, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOB_BASE, AT91C_PB29_CTS1, 0);
comment|/*  TWI Two-wire Serial Data */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA23_TWD,  1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA24_TWCK, 1);
if|#
directive|if
literal|1
comment|/*  	 * Turn off Clock to DataFlash, conflicts with MCI clock. 	 */
block|at91_pio_use_gpio(AT91SAM9G20_PIOA_BASE,AT91C_PIO_PA2); 	at91_pio_gpio_input(AT91SAM9G20_PIOA_BASE,AT91C_PIO_PA2);
comment|/* Turn off chip select to DataFlash */
block|at91_pio_gpio_output(AT91SAM9G20_PIOC_BASE,AT91C_PIO_PC11, 0); 	at91_pio_gpio_set(AT91SAM9G20_PIOC_BASE,AT91C_PIO_PC11); 	at91_pio_use_gpio(AT91SAM9G20_PIOC_BASE,AT91C_PIO_PC11);
comment|/*  Multimedia Card  */
block|at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA0_MCDB0, 1); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA1_MCCDB, 1); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA3_MCDB3, 1); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA4_MCDB2, 1); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA5_MCDB1, 1); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA8_MCCK,  1); 	at91_pio_use_gpio(AT91SAM9G20_PIOC_BASE, AT91C_PIO_PC9);
else|#
directive|else
comment|/* SPI0 to DataFlash */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE, AT91C_PIO_PA0, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE, AT91C_PIO_PA1, 0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE, AT91C_PIO_PA2, 0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOC_BASE, AT91C_PIO_PC11,0);  	at91_pio_gpio_input(AT91SAM9G20_PIOA_BASE,AT91C_PIO_PA8); 	at91_pio_use_gpio(AT91SAM9G20_PIOA_BASE,AT91C_PIO_PA8);
endif|#
directive|endif
comment|/* EMAC */
block|at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA12_ETX0 ,  0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA13_ETX1,   0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA14_ERX0,   0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA15_ERX1,   0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA16_ETXEN,  0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA17_ERXDV,  0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA18_ERXER,  0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA19_ETXCK,  0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA20_EMDC,   0); 	at91_pio_use_periph_a(AT91SAM9G20_PIOA_BASE,AT91C_PA21_EMDIO,  0);  	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA10_ETX2_0, 0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA11_ETX3_0, 0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA22_ETXER,  0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA25_ERX2,   0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA26_ERX3,   0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA27_ERXCK,  0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA28_ECRS,   0); 	at91_pio_use_periph_b(AT91SAM9G20_PIOA_BASE,AT91C_PA29_ECOL,   0);
endif|#
directive|endif
return|return
operator|(
name|at91_ramsize
argument_list|()
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|ARM_BOARD
argument_list|(
name|AT91SAM9X5EK
argument_list|,
literal|"Atmel AT91SAM9x-EK Evaluation Board"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

