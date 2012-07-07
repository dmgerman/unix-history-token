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

begin_function
name|BOARD_INIT
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Setup Ethernet Pins */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
literal|1
operator|<<
literal|7
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_gpio_input
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
literal|1
operator|<<
literal|7
argument_list|)
expr_stmt|;
name|at91_pio_gpio_set_deglitch
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
literal|1
operator|<<
literal|7
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA19
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXCK_EREFCK */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA17
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXDV */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXER */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXEN */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA12
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA13
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA21
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* EMDIO */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA20
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* EMDC */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA28
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ECRS */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA29
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ECOL */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA25
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA26
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERX3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA27
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ERXCK */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA23
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA24
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETX3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91SAM9G20_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ETXER */
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
name|NONE
argument_list|,
literal|"HOTe 201"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

