begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_H_
end_define

begin_comment
comment|/*  * Bus access structure. This structure holds the minimum information needed  * to access the UART. The rclk field, although not important to actually  * access the UART, is important for baudrate programming, delay loops and  * other timing related computations.  */
end_comment

begin_struct
struct|struct
name|uart_bas
block|{
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|u_int
name|chan
decl_stmt|;
name|u_int
name|rclk
decl_stmt|;
name|u_int
name|regshft
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|uart_regofs
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|)
value|((reg)<< (bas)->regshft)
end_define

begin_define
define|#
directive|define
name|uart_getreg
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((bas)->bst, (bas)->bsh, uart_regofs(bas, reg))
end_define

begin_define
define|#
directive|define
name|uart_setreg
parameter_list|(
name|bas
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((bas)->bst, (bas)->bsh, uart_regofs(bas, reg), value)
end_define

begin_comment
comment|/*  * XXX we don't know the length of the bus space address range in use by  * the UART. Since barriers don't use the length field currently, we put  * a zero there for now.  */
end_comment

begin_define
define|#
directive|define
name|uart_barrier
parameter_list|(
name|bas
parameter_list|)
define|\
value|bus_space_barrier((bas)->bst, (bas)->bsh, 0, 0,		\ 	    BUS_SPACE_BARRIER_READ|BUS_SPACE_BARRIER_WRITE)
end_define

begin_comment
comment|/*  * Device flags.  */
end_comment

begin_define
define|#
directive|define
name|UART_FLAGS_CONSOLE
parameter_list|(
name|f
parameter_list|)
value|((f)& 0x10)
end_define

begin_define
define|#
directive|define
name|UART_FLAGS_DBGPORT
parameter_list|(
name|f
parameter_list|)
value|((f)& 0x80)
end_define

begin_comment
comment|/*  * Data parity values (magical numbers related to ns8250).  */
end_comment

begin_define
define|#
directive|define
name|UART_PARITY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|UART_PARITY_ODD
value|1
end_define

begin_define
define|#
directive|define
name|UART_PARITY_EVEN
value|3
end_define

begin_define
define|#
directive|define
name|UART_PARITY_MARK
value|5
end_define

begin_define
define|#
directive|define
name|UART_PARITY_SPACE
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_H_ */
end_comment

end_unit

