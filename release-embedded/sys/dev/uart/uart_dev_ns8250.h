begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_DEV_NS8250_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_DEV_NS8250_H_
end_define

begin_comment
comment|/*  * High-level UART interface.  */
end_comment

begin_struct
struct|struct
name|ns8250_softc
block|{
name|struct
name|uart_softc
name|base
decl_stmt|;
name|uint8_t
name|fcr
decl_stmt|;
name|uint8_t
name|ier
decl_stmt|;
name|uint8_t
name|mcr
decl_stmt|;
name|uint8_t
name|ier_mask
decl_stmt|;
name|uint8_t
name|ier_rxbits
decl_stmt|;
name|uint8_t
name|busy_detect
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|uart_ops
name|uart_ns8250_ops
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ns8250_bus_attach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_detach
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_flush
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_getsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_ioctl
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_ipend
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_param
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_probe
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_receive
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_setsig
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns8250_bus_transmit
parameter_list|(
name|struct
name|uart_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_DEV_NS8250_H_ */
end_comment

end_unit

