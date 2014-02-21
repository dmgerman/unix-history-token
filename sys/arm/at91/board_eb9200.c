begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Olivier Houchard.  All rights reserved.  * Copyright (c) 2005-2012 Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<arm/at91/at91var.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91rm9200var.h>
end_include

begin_function
name|BOARD_INIT
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
name|at91rm9200_set_subtype
argument_list|(
name|AT91_ST_RM9200_BGA
argument_list|)
expr_stmt|;
comment|/* 	 * Setup the serial ports. 	 * DBGU and USART0 are DB9 ports. 	 * USART2 is IrDA. 	 */
name|at91rm9200_config_uart
argument_list|(
name|AT91_ID_DBGU
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* DBGU just Tx and Rx */
name|at91rm9200_config_uart
argument_list|(
name|AT91RM9200_ID_USART0
argument_list|,
literal|1
argument_list|,
name|AT91_UART_CTS
operator||
name|AT91_UART_RTS
operator||
name|AT91_UART_DTR
operator||
name|AT91_UART_DSR
operator||
name|AT91_UART_DCD
operator||
name|AT91_UART_RI
argument_list|)
expr_stmt|;
name|at91rm9200_config_uart
argument_list|(
name|AT91RM9200_ID_USART1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91rm9200_config_mci
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* CFE interface */
comment|/* SPI interface */
comment|/* ethernet interface */
comment|/* USB host */
comment|/* USB device (gadget) */
comment|/* TWI */
comment|/* CF interface */
comment|/* SmartMedia Interface */
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
argument|ATEB9200
argument_list|,
literal|"Embest ATEB9200"
argument_list|)
end_macro

end_unit

