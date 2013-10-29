begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Neel Natu<neel@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UART_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_UART_EMUL_H_
end_define

begin_define
define|#
directive|define
name|UART_IO_BAR_SIZE
value|8
end_define

begin_struct_decl
struct_decl|struct
name|uart_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uart_intr_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|uart_softc
modifier|*
name|uart_init
parameter_list|(
name|uart_intr_func_t
name|intr_assert
parameter_list|,
name|uart_intr_func_t
name|intr_deassert
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_legacy_alloc
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
modifier|*
name|ioaddr
parameter_list|,
name|int
modifier|*
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|uart_read
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uart_write
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
name|int
name|offset
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_set_backend
parameter_list|(
name|struct
name|uart_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

