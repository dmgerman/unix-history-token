begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: uart.h,v 1.1 2007/03/20 08:52:02 dyoung Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADMUART_H
end_ifndef

begin_define
define|#
directive|define
name|_ADMUART_H
end_define

begin_comment
comment|/* UART registers */
end_comment

begin_define
define|#
directive|define
name|UART_DR_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|UART_RSR_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_RSR_FE
value|0x01
end_define

begin_define
define|#
directive|define
name|UART_RSR_PE
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_RSR_BE
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_RSR_OE
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_ECR_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_ECR_RSR
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_LCR_H_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_LCR_H_FEN
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_LCR_M_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|UART_LCR_L_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_CR_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|UART_CR_PORT_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|UART_CR_SIREN
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_CR_SIRLP
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_CR_MODEM_STATUS_INT_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_CR_RX_INT_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_CR_TX_INT_EN
value|0x20
end_define

begin_define
define|#
directive|define
name|UART_CR_RX_TIMEOUT_INT_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_CR_LOOPBACK_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_FR_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|UART_FR_CTS
value|0x01
end_define

begin_define
define|#
directive|define
name|UART_FR_DSR
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_FR_DCD
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_FR_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_FR_RX_FIFO_EMPTY
value|0x10
end_define

begin_define
define|#
directive|define
name|UART_FR_TX_FIFO_FULL
value|0x20
end_define

begin_define
define|#
directive|define
name|UART_FR_RX_FIFO_FULL
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_FR_TX_FIFO_EMPTY
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_IR_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|UART_IR_MODEM_STATUS_INT
value|0x01
end_define

begin_define
define|#
directive|define
name|UART_IR_RX_INT
value|0x02
end_define

begin_define
define|#
directive|define
name|UART_IR_TX_INT
value|0x04
end_define

begin_define
define|#
directive|define
name|UART_IR_RX_TIMEOUT_INT
value|0x08
end_define

begin_define
define|#
directive|define
name|UART_IR_INT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|UART_IR_UICR
value|0x80
end_define

begin_define
define|#
directive|define
name|UART_ILPR_REG
value|0x20
end_define

begin_comment
comment|/* UART interrupts */
end_comment

begin_function_decl
name|int
name|uart_cnattach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADMUART_H */
end_comment

end_unit

