begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AT91USARTREG_H_
end_ifndef

begin_define
define|#
directive|define
name|AT91USARTREG_H_
end_define

begin_define
define|#
directive|define
name|USART_CR
value|0x00
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RSTRX
value|(1UL<< 2)
end_define

begin_comment
comment|/* Reset Receiver */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RSTTX
value|(1UL<< 3)
end_define

begin_comment
comment|/* Reset Transmitter */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RXEN
value|(1UL<< 4)
end_define

begin_comment
comment|/* Receiver Enable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RXDIS
value|(1UL<< 5)
end_define

begin_comment
comment|/* Receiver Disable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_TXEN
value|(1UL<< 6)
end_define

begin_comment
comment|/* Transmitter Enable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_TXDIS
value|(1UL<< 7)
end_define

begin_comment
comment|/* Transmitter Disable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RSTSTA
value|(1UL<< 8)
end_define

begin_comment
comment|/* Reset Status Bits */
end_comment

begin_define
define|#
directive|define
name|USART_CR_STTBRK
value|(1UL<< 9)
end_define

begin_comment
comment|/* Start Break */
end_comment

begin_define
define|#
directive|define
name|USART_CR_STPBRK
value|(1UL<< 10)
end_define

begin_comment
comment|/* Stop Break */
end_comment

begin_define
define|#
directive|define
name|USART_CR_STTTO
value|(1UL<< 11)
end_define

begin_comment
comment|/* Start Time-out */
end_comment

begin_define
define|#
directive|define
name|USART_CR_SENDA
value|(1UL<< 12)
end_define

begin_comment
comment|/* Send Address */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RSTIT
value|(1UL<< 13)
end_define

begin_comment
comment|/* Reset Iterations */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RSTNACK
value|(1UL<< 14)
end_define

begin_comment
comment|/* Reset Non Acknowledge */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RETTO
value|(1UL<< 15)
end_define

begin_comment
comment|/* Rearm Time-out */
end_comment

begin_define
define|#
directive|define
name|USART_CR_DTREN
value|(1UL<< 16)
end_define

begin_comment
comment|/* Data Terminal ready Enable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_DTRDIS
value|(1UL<< 17)
end_define

begin_comment
comment|/* Data Terminal ready Disable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RTSEN
value|(1UL<< 18)
end_define

begin_comment
comment|/* Request to Send enable */
end_comment

begin_define
define|#
directive|define
name|USART_CR_RTSDIS
value|(1UL<< 19)
end_define

begin_comment
comment|/* Request to Send Disable */
end_comment

begin_define
define|#
directive|define
name|USART_MR
value|0x04
end_define

begin_comment
comment|/* Mode register */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_NORMAL
value|0
end_define

begin_comment
comment|/* Normal/Async/3-wire rs-232 */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_RS485
value|1
end_define

begin_comment
comment|/* RS485 */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_HWFLOW
value|2
end_define

begin_comment
comment|/* Hardware flow control/handshake */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_MODEM
value|3
end_define

begin_comment
comment|/* Full modem protocol */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_ISO7816T0
value|4
end_define

begin_comment
comment|/* ISO7816 T=0 */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_ISO7816T1
value|6
end_define

begin_comment
comment|/* ISO7816 T=1 */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MODE_IRDA
value|8
end_define

begin_comment
comment|/* IrDA mode */
end_comment

begin_define
define|#
directive|define
name|USART_MR_USCLKS_MCK
value|(0U<< 4)
end_define

begin_comment
comment|/* use MCK for baudclock */
end_comment

begin_define
define|#
directive|define
name|USART_MR_USCLKS_MCKDIV
value|(1U<< 4)
end_define

begin_comment
comment|/* use MCK/DIV for baudclock */
end_comment

begin_define
define|#
directive|define
name|USART_MR_USCLKS_SCK
value|(3U<< 4)
end_define

begin_comment
comment|/* use SCK (ext) for baudclock */
end_comment

begin_define
define|#
directive|define
name|USART_MR_CHRL_5BITS
value|(0U<< 6)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHRL_6BITS
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHRL_7BITS
value|(2U<< 6)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHRL_8BITS
value|(3U<< 6)
end_define

begin_define
define|#
directive|define
name|USART_MR_SYNC
value|(1U<< 8)
end_define

begin_comment
comment|/* 1 -> sync 0 -> async */
end_comment

begin_define
define|#
directive|define
name|USART_MR_PAR_EVEN
value|(0U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_PAR_ODD
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_PAR_SPACE
value|(2U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_PAR_MARK
value|(3U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_PAR_NONE
value|(4U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_PAR_MULTIDROP
value|(6U<< 9)
end_define

begin_define
define|#
directive|define
name|USART_MR_NBSTOP_1
value|(0U<< 12)
end_define

begin_define
define|#
directive|define
name|USART_MR_NBSTOP_1_5
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|USART_MR_NBSTOP_2
value|(2U<< 12)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHMODE_NORMAL
value|(0U<< 14)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHMODE_ECHO
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHMODE_LOOP
value|(2U<< 14)
end_define

begin_define
define|#
directive|define
name|USART_MR_CHMODE_REMLOOP
value|(3U<< 14)
end_define

begin_define
define|#
directive|define
name|USART_MR_MSBF
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|USART_MR_MODE9
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|USART_MR_CKLO_SCK
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|USART_MR_OVER16
value|0
end_define

begin_define
define|#
directive|define
name|USART_MR_OVER8
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|USART_MR_INACK
value|(1U<< 20)
end_define

begin_comment
comment|/* Inhibit NACK generation */
end_comment

begin_define
define|#
directive|define
name|USART_MR_DSNACK
value|(1U<< 21)
end_define

begin_comment
comment|/* Disable Successive NACK */
end_comment

begin_define
define|#
directive|define
name|USART_MR_MAXITERATION
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|USART_MR_FILTER
value|(1U<< 28)
end_define

begin_comment
comment|/* Filters for Ir lines */
end_comment

begin_define
define|#
directive|define
name|USART_IER
value|0x08
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|USART_IDR
value|0x0c
end_define

begin_comment
comment|/* Interrupt disable register */
end_comment

begin_define
define|#
directive|define
name|USART_IMR
value|0x10
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|USART_CSR
value|0x14
end_define

begin_comment
comment|/* Channel status register */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_RXRDY
value|(1UL<< 0)
end_define

begin_comment
comment|/* Receiver ready */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_TXRDY
value|(1UL<< 1)
end_define

begin_comment
comment|/* Transmitter ready */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_RXBRK
value|(1UL<< 2)
end_define

begin_comment
comment|/* Break received */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_ENDRX
value|(1UL<< 3)
end_define

begin_comment
comment|/* End of Transfer RX from PDC */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_ENDTX
value|(1UL<< 4)
end_define

begin_comment
comment|/* End of Transfer TX from PDC */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_OVRE
value|(1UL<< 5)
end_define

begin_comment
comment|/* Overrun error */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_FRAME
value|(1UL<< 6)
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_PARE
value|(1UL<< 7)
end_define

begin_comment
comment|/* Parity Error */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_TIMEOUT
value|(1UL<< 8)
end_define

begin_comment
comment|/* Timeout since start-timeout */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_TXEMPTY
value|(1UL<< 9)
end_define

begin_comment
comment|/* Transmitter empty */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_ITERATION
value|(1UL<< 10)
end_define

begin_comment
comment|/* max repetitions since RSIT */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_TXBUFE
value|(1UL<< 11)
end_define

begin_comment
comment|/* Buffer empty from PDC */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_RXBUFF
value|(1UL<< 12)
end_define

begin_comment
comment|/* Buffer full from PDC */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_NACK
value|(1UL<< 13)
end_define

begin_comment
comment|/* NACK since last RSTNACK */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_RIIC
value|(1UL<< 16)
end_define

begin_comment
comment|/* RI delta since last csr read */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_DSRIC
value|(1UL<< 17)
end_define

begin_comment
comment|/* DSR delta */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_DCDIC
value|(1UL<< 18)
end_define

begin_comment
comment|/* DCD delta */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_CTSIC
value|(1UL<< 19)
end_define

begin_comment
comment|/* CTS delta */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_RI
value|(1UL<< 20)
end_define

begin_comment
comment|/* RI status */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_DSR
value|(1UL<< 21)
end_define

begin_comment
comment|/* DSR status */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_DCD
value|(1UL<< 22)
end_define

begin_comment
comment|/* DCD status */
end_comment

begin_define
define|#
directive|define
name|USART_CSR_CTS
value|(1UL<< 23)
end_define

begin_comment
comment|/* CTS status */
end_comment

begin_define
define|#
directive|define
name|USART_RHR
value|0x18
end_define

begin_comment
comment|/* Receiver holding register */
end_comment

begin_define
define|#
directive|define
name|USART_THR
value|0x1c
end_define

begin_comment
comment|/* Transmitter holding register */
end_comment

begin_define
define|#
directive|define
name|USART_BRGR
value|0x20
end_define

begin_comment
comment|/* Baud rate generator register */
end_comment

begin_define
define|#
directive|define
name|USART_RTOR
value|0x24
end_define

begin_comment
comment|/* Receiver time-out register */
end_comment

begin_define
define|#
directive|define
name|USART_TTR
value|0x28
end_define

begin_comment
comment|/* Transmitter timeguard register */
end_comment

begin_comment
comment|/* 0x2c to 0x3c reserved */
end_comment

begin_define
define|#
directive|define
name|USART_FDRR
value|0x40
end_define

begin_comment
comment|/* FI DI ratio register */
end_comment

begin_define
define|#
directive|define
name|USART_NER
value|0x44
end_define

begin_comment
comment|/* Number of errors register */
end_comment

begin_comment
comment|/* 0x48 reserved */
end_comment

begin_define
define|#
directive|define
name|USART_IFR
value|0x48
end_define

begin_comment
comment|/* IrDA filter register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AT91RM92REG_H_ */
end_comment

end_unit

