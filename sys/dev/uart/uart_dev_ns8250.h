begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/* Enhanced Feature Register. */
end_comment

begin_define
define|#
directive|define
name|EFR_CTS
value|0x80
end_define

begin_define
define|#
directive|define
name|EFR_RTS
value|0x40
end_define

begin_define
define|#
directive|define
name|EFR_SCD
value|0x20
end_define

begin_comment
comment|/* Special Character Detect. */
end_comment

begin_define
define|#
directive|define
name|EFR_EFC
value|0x10
end_define

begin_comment
comment|/* Enhanced Function Control. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_MASK
value|0x0f
end_define

begin_comment
comment|/* Software Flow Control. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_TX12
value|0x0c
end_define

begin_comment
comment|/* BIT: Transmit XON1+2/XOFF1+2. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_TX1
value|0x08
end_define

begin_comment
comment|/* BIT: Transmit XON1/XOFF1. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_TX2
value|0x04
end_define

begin_comment
comment|/* BIT: Transmit XON2/XOFF2. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_RX1
value|0x02
end_define

begin_comment
comment|/* BIT: Receive XON1/XOFF1. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_RX2
value|0x01
end_define

begin_comment
comment|/* BIT: Receive XON2/XOFF2. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_T12R12
value|0x0f
end_define

begin_comment
comment|/* VAL: TX 1+2, RX 1+2. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_T1R12
value|0x0b
end_define

begin_comment
comment|/* VAL: TX 1, RX 1+2. */
end_comment

begin_define
define|#
directive|define
name|EFR_SFC_T2R12
value|0x07
end_define

begin_comment
comment|/* VAL: TX 2, RX 1+2. */
end_comment

begin_comment
comment|/* FIFO Control Register. */
end_comment

begin_define
define|#
directive|define
name|FCR_RX_HIGH
value|0xc0
end_define

begin_define
define|#
directive|define
name|FCR_RX_MEDH
value|0x80
end_define

begin_define
define|#
directive|define
name|FCR_RX_MEDL
value|0x40
end_define

begin_define
define|#
directive|define
name|FCR_RX_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|FCR_TX_HIGH
value|0x30
end_define

begin_define
define|#
directive|define
name|FCR_TX_MEDH
value|0x20
end_define

begin_define
define|#
directive|define
name|FCR_TX_LOW
value|0x10
end_define

begin_define
define|#
directive|define
name|FCR_TX_MEDL
value|0x00
end_define

begin_define
define|#
directive|define
name|FCR_DMA
value|0x08
end_define

begin_define
define|#
directive|define
name|FCR_XMT_RST
value|0x04
end_define

begin_define
define|#
directive|define
name|FCR_RCV_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|FCR_ENABLE
value|0x01
end_define

begin_comment
comment|/* Interrupt Enable Register. */
end_comment

begin_define
define|#
directive|define
name|IER_CTS
value|0x80
end_define

begin_define
define|#
directive|define
name|IER_RTS
value|0x40
end_define

begin_define
define|#
directive|define
name|IER_XOFF
value|0x20
end_define

begin_define
define|#
directive|define
name|IER_SLEEP
value|0x10
end_define

begin_define
define|#
directive|define
name|IER_EMSC
value|0x08
end_define

begin_define
define|#
directive|define
name|IER_ERLS
value|0x04
end_define

begin_define
define|#
directive|define
name|IER_ETXRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|IER_ERXRDY
value|0x01
end_define

begin_comment
comment|/* Interrupt Identification Register. */
end_comment

begin_define
define|#
directive|define
name|IIR_FIFO_MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|IIR_RTSCTS
value|0x20
end_define

begin_define
define|#
directive|define
name|IIR_XOFF
value|0x10
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

begin_define
define|#
directive|define
name|IIR_RLS
value|0x06
end_define

begin_define
define|#
directive|define
name|IIR_RXRDY
value|0x04
end_define

begin_define
define|#
directive|define
name|IIR_TXRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|IIR_MLSC
value|0x00
end_define

begin_define
define|#
directive|define
name|IIR_NOPEND
value|0x01
end_define

begin_comment
comment|/* Line Control Register. */
end_comment

begin_define
define|#
directive|define
name|LCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|LCR_SBREAK
value|0x40
end_define

begin_define
define|#
directive|define
name|LCR_PZERO
value|0x30
end_define

begin_define
define|#
directive|define
name|LCR_PONE
value|0x20
end_define

begin_define
define|#
directive|define
name|LCR_PEVEN
value|0x10
end_define

begin_define
define|#
directive|define
name|LCR_PODD
value|0x00
end_define

begin_define
define|#
directive|define
name|LCR_PENAB
value|0x08
end_define

begin_define
define|#
directive|define
name|LCR_STOPB
value|0x04
end_define

begin_define
define|#
directive|define
name|LCR_8BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|LCR_7BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|LCR_6BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|LCR_5BITS
value|0x00
end_define

begin_comment
comment|/* Line Status Register. */
end_comment

begin_define
define|#
directive|define
name|LSR_DERR
value|0x80
end_define

begin_define
define|#
directive|define
name|LSR_TEMT
value|0x40
end_define

begin_comment
comment|/* Transmitter Empty. */
end_comment

begin_define
define|#
directive|define
name|LSR_THRE
value|0x20
end_define

begin_comment
comment|/* Transmitter Holding Register Empty. */
end_comment

begin_define
define|#
directive|define
name|LSR_BI
value|0x10
end_define

begin_define
define|#
directive|define
name|LSR_FE
value|0x08
end_define

begin_define
define|#
directive|define
name|LSR_PE
value|0x04
end_define

begin_define
define|#
directive|define
name|LSR_OE
value|0x02
end_define

begin_define
define|#
directive|define
name|LSR_RXRDY
value|0x01
end_define

begin_comment
comment|/* Modem Control Register. */
end_comment

begin_define
define|#
directive|define
name|MCR_CS
value|0x80
end_define

begin_define
define|#
directive|define
name|MCR_IRE
value|0x40
end_define

begin_define
define|#
directive|define
name|MCR_ISEL
value|0x20
end_define

begin_define
define|#
directive|define
name|MCR_LOOPBACK
value|0x10
end_define

begin_define
define|#
directive|define
name|MCR_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|MCR_LBDCD
value|MCR_IE
end_define

begin_define
define|#
directive|define
name|MCR_LBRI
value|0x04
end_define

begin_define
define|#
directive|define
name|MCR_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|MCR_DTR
value|0x01
end_define

begin_comment
comment|/* Modem Status Register. */
end_comment

begin_define
define|#
directive|define
name|MSR_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MSR_RI
value|0x40
end_define

begin_define
define|#
directive|define
name|MSR_DSR
value|0x20
end_define

begin_define
define|#
directive|define
name|MSR_CTS
value|0x10
end_define

begin_define
define|#
directive|define
name|MSR_DDCD
value|0x08
end_define

begin_define
define|#
directive|define
name|MSR_TERI
value|0x04
end_define

begin_define
define|#
directive|define
name|MSR_DDSR
value|0x02
end_define

begin_define
define|#
directive|define
name|MSR_DCTS
value|0x01
end_define

begin_comment
comment|/* General registers. */
end_comment

begin_define
define|#
directive|define
name|REG_DATA
value|0
end_define

begin_comment
comment|/* Data Register. */
end_comment

begin_define
define|#
directive|define
name|REG_RBR
value|REG_DATA
end_define

begin_comment
comment|/* Receiver Buffer Register (R). */
end_comment

begin_define
define|#
directive|define
name|REG_THR
value|REG_DATA
end_define

begin_comment
comment|/* Transmitter Holding Register (W). */
end_comment

begin_define
define|#
directive|define
name|REG_IER
value|1
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|REG_IIR
value|2
end_define

begin_comment
comment|/* Interrupt Ident. Register (R). */
end_comment

begin_define
define|#
directive|define
name|REG_FCR
value|2
end_define

begin_comment
comment|/* FIFO Control Register (W). */
end_comment

begin_define
define|#
directive|define
name|REG_LCR
value|3
end_define

begin_comment
comment|/* Line Control Register. */
end_comment

begin_define
define|#
directive|define
name|REG_MCR
value|4
end_define

begin_comment
comment|/* Modem Control Register. */
end_comment

begin_define
define|#
directive|define
name|REG_LSR
value|5
end_define

begin_comment
comment|/* Line Status Register. */
end_comment

begin_define
define|#
directive|define
name|REG_MSR
value|6
end_define

begin_comment
comment|/* Modem Status Register. */
end_comment

begin_define
define|#
directive|define
name|REG_SPR
value|7
end_define

begin_comment
comment|/* Scratch Pad Register. */
end_comment

begin_comment
comment|/* Baudrate registers (LCR[7] = 1). */
end_comment

begin_define
define|#
directive|define
name|REG_DLBL
value|0
end_define

begin_comment
comment|/* Divisor Latch (LSB). */
end_comment

begin_define
define|#
directive|define
name|REG_DLBH
value|1
end_define

begin_comment
comment|/* Divisor Latch (MSB). */
end_comment

begin_define
define|#
directive|define
name|REG_DL
value|REG_DLBL
end_define

begin_comment
comment|/* Divisor Latch (16-bit I/O). */
end_comment

begin_comment
comment|/* Enhanced registers (LCR = 0xBF). */
end_comment

begin_define
define|#
directive|define
name|REG_EFR
value|2
end_define

begin_comment
comment|/* Enhanced Feature Register. */
end_comment

begin_define
define|#
directive|define
name|REG_XON1
value|4
end_define

begin_comment
comment|/* XON character 1. */
end_comment

begin_define
define|#
directive|define
name|REG_XON2
value|5
end_define

begin_comment
comment|/* XON character 2. */
end_comment

begin_define
define|#
directive|define
name|REG_XOFF1
value|6
end_define

begin_comment
comment|/* XOFF character 1. */
end_comment

begin_define
define|#
directive|define
name|REG_XOFF2
value|7
end_define

begin_comment
comment|/* XOFF character 2. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_DEV_NS8250_H_ */
end_comment

end_unit

