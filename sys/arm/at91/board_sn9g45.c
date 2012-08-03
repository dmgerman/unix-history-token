begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Greg Ansley.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * DesignA Electronics Snapper9g45  * http://www.designa-electronics.com/  */
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
file|<arm/at91/at91sam9g45reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_piovar.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91_pio_sam9g45.h>
end_include

begin_function
name|BOARD_INIT
name|long
name|board_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* PIOB's A periph: Turn the debug USART's TX/RX pins */
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G45_PIOB_BASE
argument_list|,
name|AT91C_PB12_DRXD
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|at91_pio_use_periph_a
argument_list|(
name|AT91SAM9G45_PIOB_BASE
argument_list|,
name|AT91C_PB13_DTXD
argument_list|,
literal|1
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

begin_expr_stmt
name|ARM_BOARD
argument_list|(
name|SNAPPER9G45
argument_list|,
literal|"DesignA Electronics Snapper9G45"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

