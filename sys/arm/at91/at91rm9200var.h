begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91RM9200VAR_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91RM9200VAR_H
end_define

begin_function_decl
name|void
name|at91rm9200_set_subtype
parameter_list|(
name|enum
name|at91_soc_subtype
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AT91RM9200_ID_USART0
value|1
end_define

begin_define
define|#
directive|define
name|AT91RM9200_ID_USART1
value|2
end_define

begin_define
define|#
directive|define
name|AT91RM9200_ID_USART2
value|3
end_define

begin_define
define|#
directive|define
name|AT91RM9200_ID_USART3
value|4
end_define

begin_comment
comment|/*  * Serial port convenience routines  */
end_comment

begin_comment
comment|/* uart pins that are wired... */
end_comment

begin_define
define|#
directive|define
name|AT91_UART_CTS
value|0x01
end_define

begin_define
define|#
directive|define
name|AT91_UART_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|AT91_UART_RI
value|0x04
end_define

begin_define
define|#
directive|define
name|AT91_UART_DTR
value|0x08
end_define

begin_define
define|#
directive|define
name|AT91_UART_DCD
value|0x10
end_define

begin_define
define|#
directive|define
name|AT91_UART_DSR
value|0x20
end_define

begin_define
define|#
directive|define
name|AT91_ID_DBGU
value|0
end_define

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/*  * MCI (sd/mmc card support)  */
end_comment

begin_function_decl
name|void
name|at91rm9200_config_mci
parameter_list|(
name|int
name|has_4wire
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91RM9200VAR_H */
end_comment

end_unit

