begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2013-2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AMLOGIC_AML8726_UART_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AMLOGIC_AML8726_UART_H
end_define

begin_define
define|#
directive|define
name|AML_UART_WFIFO_REG
value|0
end_define

begin_define
define|#
directive|define
name|AML_UART_RFIFO_REG
value|4
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_REG
value|8
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_TX_INT_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_RX_INT_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_CLR_ERR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_RX_RST
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_TX_RST
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_DB_MASK
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_8_DB
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_7_DB
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_6_DB
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_5_DB
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_P_MASK
value|(3<< 18)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_P_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_P_EVEN
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_P_ODD
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_SB_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_1_SB
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_2_SB
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_TWO_WIRE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_RX_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_TX_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_BAUD_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|AML_UART_CONTROL_BAUD_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_REG
value|12
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RECV_BUSY
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_XMIT_BUSY
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RX_FIFO_OVERFLOW
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_TX_FIFO_EMPTY
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_TX_FIFO_FULL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RX_FIFO_EMPTY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RX_FIFO_FULL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_TX_FIFO_WRITE_ERR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_FRAME_ERR
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_PARITY_ERR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_TX_FIFO_CNT_MASK
value|(0x7f<< 8)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_TX_FIFO_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RX_FIFO_CNT_MASK
value|(0x7f<< 0)
end_define

begin_define
define|#
directive|define
name|AML_UART_STATUS_RX_FIFO_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_REG
value|16
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_OLD_RX_BAUD
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_BAUD_EXT_MASK
value|(0xf<< 20)
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_BAUD_EXT_SHIFT
value|20
end_define

begin_comment
comment|/*  * The documentation appears to be incorrect as the  * IRQ is actually generated when TX FIFO count is  * * equal to * or less than the selected threshold.  */
end_comment

begin_define
define|#
directive|define
name|AML_UART_MISC_XMIT_IRQ_CNT_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_XMIT_IRQ_CNT_SHIFT
value|8
end_define

begin_comment
comment|/*  * The documentation appears to be incorrect as the  * IRQ is actually generated when RX FIFO count is  * * equal to * or greater than the selected threshold.  */
end_comment

begin_define
define|#
directive|define
name|AML_UART_MISC_RECV_IRQ_CNT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|AML_UART_MISC_RECV_IRQ_CNT_SHIFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AMLOGIC_AML8726_UART_H */
end_comment

end_unit

