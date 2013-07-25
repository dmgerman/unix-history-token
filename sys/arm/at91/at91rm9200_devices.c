begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 M. Warner Losh.  All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91var.h>
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
file|<arm/at91/at91rm9200var.h>
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

begin_comment
comment|/*  * The AT91RM9200 uses the same silicon for both the BGA and PQFP  * packages.  There's no documented way to detect this at runtime,  * so we require the board code to register what type of SoC is on the  * board in question.  The pinouts are not quite compatible, and we  * use this information to cope with the slight differences.  */
end_comment

begin_function
name|void
name|at91rm9200_set_subtype
parameter_list|(
name|enum
name|at91_soc_subtype
name|st
parameter_list|)
block|{
switch|switch
condition|(
name|st
condition|)
block|{
case|case
name|AT91_ST_RM9200_BGA
case|:
case|case
name|AT91_ST_RM9200_PQFP
case|:
name|soc_info
operator|.
name|subtype
operator|=
name|st
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"Bad SoC subtype %d for at91rm9200_set_subtype."
argument_list|,
name|st
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
name|void
name|at91rm9200_config_uart
parameter_list|(
name|unsigned
name|devid
parameter_list|,
name|unsigned
name|unit
parameter_list|,
name|unsigned
name|pinmask
parameter_list|)
block|{
comment|/* 	 * Since the USART supports RS-485 multidrop mode, it allows the 	 * TX pins to float.  However, for RS-232 operations, we don't want 	 * these pins to float.  Instead, they should be pulled up to avoid 	 * mismatches.  Linux does something similar when it configures the 	 * TX lines.  This implies that we also allow the RX lines to float 	 * rather than be in the state they are left in by the boot loader. 	 * Since they are input pins, I think that this is the right thing 	 * to do. 	 */
comment|/* 	 * Current boards supported don't need the extras, but they should be 	 * implemented.  But that should wait until the new pin api goes in. 	 */
switch|switch
condition|(
name|devid
condition|)
block|{
case|case
name|AT91_ID_DBGU
case|:
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DRXD */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA31
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* DTXD */
break|break;
case|case
name|AT91RM9200_ID_USART0
case|:
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA17
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* TXD0 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* RXD0 */
comment|/* CTS PA20 */
comment|/* RTS -- errata #39 PA21 */
break|break;
case|case
name|AT91RM9200_ID_USART1
case|:
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB20
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* TXD1 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB21
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* RXD1 */
comment|/* RI - PB18 */
comment|/* DTR - PB19 */
comment|/* DCD - PB23 */
comment|/* CTS - PB24 */
comment|/* DSR - PB25 */
comment|/* RTS - PB26 */
break|break;
case|case
name|AT91RM9200_ID_USART2
case|:
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* RXD2 */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA23
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* TXD2 */
comment|/* CTS - PA30 B periph */
comment|/* RTS - PA31 B periph */
break|break;
case|case
name|AT91RM9200_ID_USART3
case|:
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* TXD3 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA6
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* RXD3 */
comment|/* CTS - PB0 B periph */
comment|/* RTS - PB1 B periph */
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_function
name|void
name|at91rm9200_config_mci
parameter_list|(
name|int
name|has_4wire
parameter_list|)
block|{
comment|/* XXX TODO chip changed GPIO, other slots, etc */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA27
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* MCCK */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA28
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCCDA */
name|at91_pio_use_periph_a
argument_list|(
name|AT91RM92_PIOA_BASE
argument_list|,
name|AT91C_PIO_PA29
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDA0 */
if|if
condition|(
name|has_4wire
condition|)
block|{
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDA1 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDA2 */
name|at91_pio_use_periph_b
argument_list|(
name|AT91RM92_PIOB_BASE
argument_list|,
name|AT91C_PIO_PB5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* MCDA3 */
block|}
block|}
end_function

end_unit

