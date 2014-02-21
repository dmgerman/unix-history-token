begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * modified for PC9801 by M.Ishii   *			Kyoto University Microcomputer Club (KMC)  *  * modified for 8251(FIFO) by Seigo TANIMURA<tanimura@FreeBSD.org>  */
end_comment

begin_comment
comment|/* i8251 mode register */
end_comment

begin_define
define|#
directive|define
name|MOD8251_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|MOD8251_6BITS
value|0x04
end_define

begin_define
define|#
directive|define
name|MOD8251_7BITS
value|0x08
end_define

begin_define
define|#
directive|define
name|MOD8251_8BITS
value|0x0c
end_define

begin_define
define|#
directive|define
name|MOD8251_PENAB
value|0x10
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|MOD8251_PEVEN
value|0x20
end_define

begin_comment
comment|/* parity even */
end_comment

begin_define
define|#
directive|define
name|MOD8251_STOP1
value|0x40
end_define

begin_comment
comment|/* 1 stop bit */
end_comment

begin_define
define|#
directive|define
name|MOD8251_STOP15
value|0x80
end_define

begin_comment
comment|/* 1.5 stop bit */
end_comment

begin_define
define|#
directive|define
name|MOD8251_STOP2
value|0xc0
end_define

begin_comment
comment|/* 2 stop bit */
end_comment

begin_define
define|#
directive|define
name|MOD8251_CLKx1
value|0x01
end_define

begin_comment
comment|/* x1 */
end_comment

begin_define
define|#
directive|define
name|MOD8251_CLKx16
value|0x02
end_define

begin_comment
comment|/* x16 */
end_comment

begin_define
define|#
directive|define
name|MOD8251_CLKx64
value|0x03
end_define

begin_comment
comment|/* x64 */
end_comment

begin_comment
comment|/* i8251 command register */
end_comment

begin_define
define|#
directive|define
name|CMD8251_TxEN
value|0x01
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|CMD8251_DTR
value|0x02
end_define

begin_comment
comment|/* assert DTR */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RxEN
value|0x04
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_define
define|#
directive|define
name|CMD8251_SBRK
value|0x08
end_define

begin_comment
comment|/* send break */
end_comment

begin_define
define|#
directive|define
name|CMD8251_ER
value|0x10
end_define

begin_comment
comment|/* error reset */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RTS
value|0x20
end_define

begin_comment
comment|/* assert RTS */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RESET
value|0x40
end_define

begin_comment
comment|/* internal reset */
end_comment

begin_define
define|#
directive|define
name|CMD8251_EH
value|0x80
end_define

begin_comment
comment|/* enter hunt mode */
end_comment

begin_comment
comment|/* i8251 status register */
end_comment

begin_define
define|#
directive|define
name|STS8251_TxRDY
value|0x01
end_define

begin_comment
comment|/* transmit READY */
end_comment

begin_define
define|#
directive|define
name|STS8251_RxRDY
value|0x02
end_define

begin_comment
comment|/* data exists in receive buffer */
end_comment

begin_define
define|#
directive|define
name|STS8251_TxEMP
value|0x04
end_define

begin_comment
comment|/* transmit buffer EMPTY */
end_comment

begin_define
define|#
directive|define
name|STS8251_PE
value|0x08
end_define

begin_comment
comment|/* perity error */
end_comment

begin_define
define|#
directive|define
name|STS8251_OE
value|0x10
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|STS8251_FE
value|0x20
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|STS8251_BI
value|0x40
end_define

begin_comment
comment|/* break detect */
end_comment

begin_define
define|#
directive|define
name|STS8251_DSR
value|0x80
end_define

begin_comment
comment|/* DSR is asserted */
end_comment

begin_comment
comment|/* i8251F line status register */
end_comment

begin_define
define|#
directive|define
name|FLSR_TxEMP
value|0x01
end_define

begin_comment
comment|/* transmit buffer EMPTY */
end_comment

begin_define
define|#
directive|define
name|FLSR_TxRDY
value|0x02
end_define

begin_comment
comment|/* transmit READY */
end_comment

begin_define
define|#
directive|define
name|FLSR_RxRDY
value|0x04
end_define

begin_comment
comment|/* data exists in receive buffer */
end_comment

begin_define
define|#
directive|define
name|FLSR_OE
value|0x10
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|FLSR_PE
value|0x20
end_define

begin_comment
comment|/* perity error */
end_comment

begin_define
define|#
directive|define
name|FLSR_BI
value|0x80
end_define

begin_comment
comment|/* break detect */
end_comment

begin_comment
comment|/* i8251F modem status register */
end_comment

begin_define
define|#
directive|define
name|MSR_DCD
value|0x80
end_define

begin_comment
comment|/* Current Data Carrier Detect */
end_comment

begin_define
define|#
directive|define
name|MSR_RI
value|0x40
end_define

begin_comment
comment|/* Current Ring Indicator */
end_comment

begin_define
define|#
directive|define
name|MSR_DSR
value|0x20
end_define

begin_comment
comment|/* Current Data Set Ready */
end_comment

begin_define
define|#
directive|define
name|MSR_CTS
value|0x10
end_define

begin_comment
comment|/* Current Clear to Send */
end_comment

begin_define
define|#
directive|define
name|MSR_DDCD
value|0x08
end_define

begin_comment
comment|/* DCD has changed state */
end_comment

begin_define
define|#
directive|define
name|MSR_TERI
value|0x04
end_define

begin_comment
comment|/* RI has toggled low to high */
end_comment

begin_define
define|#
directive|define
name|MSR_DDSR
value|0x02
end_define

begin_comment
comment|/* DSR has changed state */
end_comment

begin_define
define|#
directive|define
name|MSR_DCTS
value|0x01
end_define

begin_comment
comment|/* CTS has changed state */
end_comment

begin_comment
comment|/* i8251F interrupt identification register */
end_comment

begin_define
define|#
directive|define
name|IIR_FIFO_CK1
value|0x40
end_define

begin_define
define|#
directive|define
name|IIR_FIFO_CK2
value|0x20
end_define

begin_define
define|#
directive|define
name|IIR_IMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|IIR_RXTOUT
value|0x0c
end_define

begin_comment
comment|/* Receiver timeout */
end_comment

begin_define
define|#
directive|define
name|IIR_RLS
value|0x06
end_define

begin_comment
comment|/* Line status change */
end_comment

begin_define
define|#
directive|define
name|IIR_RXRDY
value|0x04
end_define

begin_comment
comment|/* Receiver ready */
end_comment

begin_define
define|#
directive|define
name|IIR_TXRDY
value|0x02
end_define

begin_comment
comment|/* Transmitter ready */
end_comment

begin_define
define|#
directive|define
name|IIR_NOPEND
value|0x01
end_define

begin_comment
comment|/* Transmitter ready */
end_comment

begin_define
define|#
directive|define
name|IIR_MLSC
value|0x00
end_define

begin_comment
comment|/* Modem status */
end_comment

begin_comment
comment|/* i8251F fifo control register */
end_comment

begin_define
define|#
directive|define
name|FIFO_ENABLE
value|0x01
end_define

begin_comment
comment|/* Turn the FIFO on */
end_comment

begin_define
define|#
directive|define
name|FIFO_RCV_RST
value|0x02
end_define

begin_comment
comment|/* Reset RX FIFO */
end_comment

begin_define
define|#
directive|define
name|FIFO_XMT_RST
value|0x04
end_define

begin_comment
comment|/* Reset TX FIFO */
end_comment

begin_define
define|#
directive|define
name|FIFO_LSR_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|FIFO_MSR_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|FIFO_TRIGGER_1
value|0x00
end_define

begin_comment
comment|/* Trigger RXRDY intr on 1 character */
end_comment

begin_define
define|#
directive|define
name|FIFO_TRIGGER_4
value|0x40
end_define

begin_comment
comment|/* ibid 4 */
end_comment

begin_define
define|#
directive|define
name|FIFO_TRIGGER_8
value|0x80
end_define

begin_comment
comment|/* ibid 8 */
end_comment

begin_define
define|#
directive|define
name|FIFO_TRIGGER_14
value|0xc0
end_define

begin_comment
comment|/* ibid 14 */
end_comment

end_unit

