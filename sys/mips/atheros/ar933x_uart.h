begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Atheros AR933x SoC UART registers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR933X_UART_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR933X_UART_H__
end_define

begin_define
define|#
directive|define
name|AR933X_UART_REGS_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|AR933X_UART_FIFO_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AR933X_UART_DATA_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CLOCK_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_EN_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|AR933X_UART_DATA_TX_RX_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AR933X_UART_DATA_RX_CSR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_DATA_TX_CSR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_PARITY_S
value|0
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_PARITY_M
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_PARITY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_PARITY_ODD
value|1
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_PARITY_EVEN
value|2
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_IF_MODE_S
value|2
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_IF_MODE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_IF_MODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_IF_MODE_DTE
value|1
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_IF_MODE_DCE
value|2
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_FLOW_CTRL_S
value|4
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_FLOW_CTRL_M
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_DMA_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_TX_READY_ORIDE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_RX_READY_ORIDE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_TX_READY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_RX_BREAK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_TX_BREAK
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_HOST_INT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_HOST_INT_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_TX_BUSY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CS_RX_BUSY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CLOCK_SCALE_M
value|0xff
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CLOCK_SCALE_S
value|16
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CLOCK_STEP_M
value|0xffff
end_define

begin_define
define|#
directive|define
name|AR933X_UART_CLOCK_STEP_S
value|0
end_define

begin_define
define|#
directive|define
name|AR933X_UART_MAX_SCALE
value|0xff
end_define

begin_define
define|#
directive|define
name|AR933X_UART_MAX_STEP
value|0xffff
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_TX_READY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_FRAMING_ERR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_OFLOW_ERR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_TX_OFLOW_ERR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_PARITY_ERR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_BREAK_ON
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_BREAK_OFF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_RX_FULL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_TX_EMPTY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_INT_ALLINTS
value|0x3ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR933X_UART_H__ */
end_comment

end_unit

