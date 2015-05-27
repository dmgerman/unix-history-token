begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD */
end_comment

begin_comment
comment|/*  * Skeleton of this file was based on respective code for ARM  * code written by Olivier Houchard.  */
end_comment

begin_comment
comment|/*  * XLRMIPS: This file is hacked from arm/...  */
end_comment

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FDT
end_ifndef

begin_comment
comment|/* use FDT uart when fdt is enable */
end_comment

begin_include
include|#
directive|include
file|"opt_uart.h"
end_include

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
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart_cpu.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/haldefs.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/iomap.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/mips-extns.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/hal/uart.h>
end_include

begin_include
include|#
directive|include
file|<mips/nlm/board.h>
end_include

begin_decl_stmt
name|bus_space_tag_t
name|uart_bus_space_io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_space_tag_t
name|uart_bus_space_mem
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|uart_cpu_eqres
parameter_list|(
name|struct
name|uart_bas
modifier|*
name|b1
parameter_list|,
name|struct
name|uart_bas
modifier|*
name|b2
parameter_list|)
block|{
return|return
operator|(
name|b1
operator|->
name|bsh
operator|==
name|b2
operator|->
name|bsh
operator|&&
name|b1
operator|->
name|bst
operator|==
name|b2
operator|->
name|bst
operator|)
return|;
block|}
end_function

begin_function
name|int
name|uart_cpu_getdev
parameter_list|(
name|int
name|devtype
parameter_list|,
name|struct
name|uart_devinfo
modifier|*
name|di
parameter_list|)
block|{
name|di
operator|->
name|ops
operator|=
name|uart_getops
argument_list|(
operator|&
name|uart_ns8250_class
argument_list|)
expr_stmt|;
name|di
operator|->
name|bas
operator|.
name|chan
operator|=
literal|0
expr_stmt|;
name|di
operator|->
name|bas
operator|.
name|bst
operator|=
name|rmi_uart_bus_space
expr_stmt|;
name|di
operator|->
name|bas
operator|.
name|bsh
operator|=
name|nlm_get_uart_regbase
argument_list|(
literal|0
argument_list|,
name|BOARD_CONSOLE_UART
argument_list|)
expr_stmt|;
name|di
operator|->
name|bas
operator|.
name|regshft
operator|=
literal|2
expr_stmt|;
comment|/* divisor = rclk / (baudrate * 16); */
name|di
operator|->
name|bas
operator|.
name|rclk
operator|=
name|XLP_IO_CLK
expr_stmt|;
name|di
operator|->
name|baudrate
operator|=
name|BOARD_CONSOLE_SPEED
expr_stmt|;
name|di
operator|->
name|databits
operator|=
literal|8
expr_stmt|;
name|di
operator|->
name|stopbits
operator|=
literal|1
expr_stmt|;
name|di
operator|->
name|parity
operator|=
name|UART_PARITY_NONE
expr_stmt|;
name|uart_bus_space_io
operator|=
name|NULL
expr_stmt|;
name|uart_bus_space_mem
operator|=
name|rmi_uart_bus_space
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

