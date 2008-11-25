begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Olivier Houchard.  All rights reserved.  * Copyright (c) 2005-2008 Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<arm/at91/at91board.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91rm92reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_piovar.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pio_rm9200.h>
end_include

begin_function
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Since the USART supports RS-485 multidrop mode, it allows the 	 * TX pins to float.  However, for RS-232 operations, we don't want 	 * these pins to float.  Instead, they should be pulled up to avoid 	 * mismatches.  Linux does something similar when it configures the 	 * TX lines.  This implies that we also allow the RX lines to float 	 * rather than be in the state they are left in by the boot loader. 	 * Since they are input pins, I think that this is the right thing 	 * to do. 	 */
comment|/* PIOA's A periph: Turn USART 0 and 2's TX/RX pins */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PA18_RXD0
operator||
name|AT91C_PA22_RXD2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PA17_TXD0
operator||
name|AT91C_PA23_TXD2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* PIOA's B periph: Turn USART 3's TX/RX pins */
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PA6_RXD3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PA5_TXD3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* We're using TC0's A1 and A2 input */
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PA19_TIOA1
operator||
name|AT91C_PA21_TIOA2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* PIOB's A periph: Turn USART 1's TX/RX pins */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PB21_RXD1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PB20_TXD1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Pin assignment */
comment|/* Assert PA24 low -- talk to rubidium */
name|at91_pio_use_gpio
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA24
argument_list|)
expr_stmt|;
name|at91_pio_gpio_output
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA24
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_gpio_clear
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA24
argument_list|)
expr_stmt|;
name|at91_pio_use_gpio
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB16
operator||
name|AT91C_PIO_PB17
operator||
name|AT91C_PIO_PB18
operator||
name|AT91C_PIO_PB19
argument_list|)
expr_stmt|;
return|return
operator|(
name|at91_ramsize
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

