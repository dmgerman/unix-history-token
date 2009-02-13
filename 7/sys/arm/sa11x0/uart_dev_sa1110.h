begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_DEV_SA1110_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_DEV_SA1110_H_
end_define

begin_define
define|#
directive|define
name|SACOM_FREQ
value|(3686400 / 16)
end_define

begin_define
define|#
directive|define
name|SACOMSPEED
parameter_list|(
name|b
parameter_list|)
value|(SACOM_FREQ / (b) - 1)
end_define

begin_comment
comment|/* UART control register 0 */
end_comment

begin_define
define|#
directive|define
name|SACOM_CR0
value|0x00
end_define

begin_define
define|#
directive|define
name|CR0_PE
value|0x01
end_define

begin_comment
comment|/* Parity enable */
end_comment

begin_define
define|#
directive|define
name|CR0_OES
value|0x02
end_define

begin_comment
comment|/* Odd/even parity select */
end_comment

begin_define
define|#
directive|define
name|CR0_SBS
value|0x04
end_define

begin_comment
comment|/* Stop bit select */
end_comment

begin_define
define|#
directive|define
name|CR0_DSS
value|0x08
end_define

begin_comment
comment|/* Data size select */
end_comment

begin_define
define|#
directive|define
name|CR0_SCE
value|0x10
end_define

begin_comment
comment|/* Sample clock enable */
end_comment

begin_define
define|#
directive|define
name|CR0_RCE
value|0x20
end_define

begin_comment
comment|/* Receive clock edge enable */
end_comment

begin_define
define|#
directive|define
name|CR0_TCE
value|0x40
end_define

begin_comment
comment|/* Transmit clock edge enable */
end_comment

begin_comment
comment|/* UART control register 1 and 2 - baud rate divisor */
end_comment

begin_define
define|#
directive|define
name|SACOM_CR1
value|0x04
end_define

begin_define
define|#
directive|define
name|SACOM_CR2
value|0x08
end_define

begin_comment
comment|/* UART control register 3 */
end_comment

begin_define
define|#
directive|define
name|SACOM_CR3
value|0x0C
end_define

begin_define
define|#
directive|define
name|CR3_RXE
value|0x01
end_define

begin_comment
comment|/* Receiver enable */
end_comment

begin_define
define|#
directive|define
name|CR3_TXE
value|0x02
end_define

begin_comment
comment|/* Transmitter enable */
end_comment

begin_define
define|#
directive|define
name|CR3_BRK
value|0x04
end_define

begin_comment
comment|/* Break */
end_comment

begin_define
define|#
directive|define
name|CR3_RIE
value|0x08
end_define

begin_comment
comment|/* Receive FIFO interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CR3_TIE
value|0x10
end_define

begin_comment
comment|/* Transmit FIFO interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CR3_LBM
value|0x20
end_define

begin_comment
comment|/* Loopback mode */
end_comment

begin_comment
comment|/* UART data register */
end_comment

begin_define
define|#
directive|define
name|SACOM_DR
value|0x14
end_define

begin_define
define|#
directive|define
name|DR_PRE
value|0x100
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|DR_FRE
value|0x200
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|DR_ROR
value|0x400
end_define

begin_comment
comment|/* Receiver overrun */
end_comment

begin_comment
comment|/* UART status register 0 */
end_comment

begin_define
define|#
directive|define
name|SACOM_SR0
value|0x1C
end_define

begin_define
define|#
directive|define
name|SR0_TFS
value|0x01
end_define

begin_comment
comment|/* Transmit FIFO service request */
end_comment

begin_define
define|#
directive|define
name|SR0_RFS
value|0x02
end_define

begin_comment
comment|/* Receive FIFO service request */
end_comment

begin_define
define|#
directive|define
name|SR0_RID
value|0x04
end_define

begin_comment
comment|/* Receiver idle */
end_comment

begin_define
define|#
directive|define
name|SR0_RBB
value|0x08
end_define

begin_comment
comment|/* Receiver begin of break */
end_comment

begin_define
define|#
directive|define
name|SR0_REB
value|0x10
end_define

begin_comment
comment|/* Receiver end of break */
end_comment

begin_define
define|#
directive|define
name|SR0_EIF
value|0x20
end_define

begin_comment
comment|/* Error in FIFO */
end_comment

begin_comment
comment|/* UART status register 1 */
end_comment

begin_define
define|#
directive|define
name|SACOM_SR1
value|0x20
end_define

begin_define
define|#
directive|define
name|SR1_TBY
value|0x01
end_define

begin_comment
comment|/* Transmitter busy */
end_comment

begin_define
define|#
directive|define
name|SR1_RNE
value|0x02
end_define

begin_comment
comment|/* Receive FIFO not empty */
end_comment

begin_define
define|#
directive|define
name|SR1_TNF
value|0x04
end_define

begin_comment
comment|/* Transmit FIFO not full */
end_comment

begin_define
define|#
directive|define
name|SR1_PRE
value|0x08
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|SR1_FRE
value|0x10
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|SR1_ROR
value|0x20
end_define

begin_comment
comment|/* Receive FIFO overrun */
end_comment

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)& (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

