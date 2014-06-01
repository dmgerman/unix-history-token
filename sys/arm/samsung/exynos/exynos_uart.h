begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: s3c2xx0reg.h,v 1.4 2004/02/12 03:47:29 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Fujitsu Component Limited  * Copyright (c) 2002, 2003 Genetec Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Fujitsu Component Limited nor the name of  *    Genetec corporation may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY FUJITSU COMPONENT LIMITED AND GENETEC  * CORPORATION ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL FUJITSU COMPONENT LIMITED OR GENETEC  * CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* s3c2410-specific registers */
end_comment

begin_define
define|#
directive|define
name|UMCON_AFC
value|(1<< 4)
end_define

begin_comment
comment|/* auto flow control */
end_comment

begin_define
define|#
directive|define
name|UMSTAT_DCTS
value|(1<< 2)
end_define

begin_comment
comment|/* CTS change */
end_comment

begin_define
define|#
directive|define
name|ULCON_IR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_SHIFT
value|3
end_define

begin_comment
comment|/*  * Exynos-specific  *  * UFSTAT_TXFULL register differs between Exynos and others.  * Others have UFSTAT_TXFULL  (1<< 9)  */
end_comment

begin_define
define|#
directive|define
name|UFSTAT_TXFULL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SSCOM_UINTM
value|0x038
end_define

begin_define
define|#
directive|define
name|SSCOM_UINTP
value|0x030
end_define

begin_comment
comment|/* common for s3c2800 and s3c24x0 */
end_comment

begin_define
define|#
directive|define
name|SSCOM_ULCON
value|0x00
end_define

begin_comment
comment|/* UART line control */
end_comment

begin_define
define|#
directive|define
name|ULCON_PARITY_NONE
value|(0<< ULCON_PARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_ODD
value|(4<< ULCON_PARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_EVEN
value|(5<< ULCON_PARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_ONE
value|(6<< ULCON_PARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|ULCON_PARITY_ZERO
value|(7<< ULCON_PARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|ULCON_STOP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ULCON_LENGTH_5
value|0
end_define

begin_define
define|#
directive|define
name|ULCON_LENGTH_6
value|1
end_define

begin_define
define|#
directive|define
name|ULCON_LENGTH_7
value|2
end_define

begin_define
define|#
directive|define
name|ULCON_LENGTH_8
value|3
end_define

begin_define
define|#
directive|define
name|SSCOM_UCON
value|0x04
end_define

begin_comment
comment|/* UART control */
end_comment

begin_define
define|#
directive|define
name|UCON_TXINT_TYPE
value|(1<< 9)
end_define

begin_comment
comment|/* Tx interrupt. 0=pulse,1=level */
end_comment

begin_define
define|#
directive|define
name|UCON_TXINT_TYPE_LEVEL
value|UCON_TXINT_TYPE
end_define

begin_define
define|#
directive|define
name|UCON_TXINT_TYPE_PULSE
value|0
end_define

begin_define
define|#
directive|define
name|UCON_RXINT_TYPE
value|(1<< 8)
end_define

begin_comment
comment|/* Rx interrupt */
end_comment

begin_define
define|#
directive|define
name|UCON_RXINT_TYPE_LEVEL
value|UCON_RXINT_TYPE
end_define

begin_define
define|#
directive|define
name|UCON_RXINT_TYPE_PULSE
value|0
end_define

begin_define
define|#
directive|define
name|UCON_TOINT
value|(1<< 7)
end_define

begin_comment
comment|/* Rx timeout interrupt */
end_comment

begin_define
define|#
directive|define
name|UCON_ERRINT
value|(1<< 6)
end_define

begin_comment
comment|/* receive error interrupt */
end_comment

begin_define
define|#
directive|define
name|UCON_LOOP
value|(1<< 5)
end_define

begin_comment
comment|/* loopback */
end_comment

begin_define
define|#
directive|define
name|UCON_SBREAK
value|(1<< 4)
end_define

begin_comment
comment|/* send break */
end_comment

begin_define
define|#
directive|define
name|UCON_TXMODE_DISABLE
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|UCON_TXMODE_INT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UCON_TXMODE_DMA
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|UCON_TXMODE_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|UCON_RXMODE_DISABLE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|UCON_RXMODE_INT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|UCON_RXMODE_DMA
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|UCON_RXMODE_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|SSCOM_UFCON
value|0x08
end_define

begin_comment
comment|/* FIFO control */
end_comment

begin_define
define|#
directive|define
name|UFCON_TXTRIGGER_0
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|UFCON_TXTRIGGER_4
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|UFCON_TXTRIGGER_8
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|UFCON_TXTRIGGER_16
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|UFCON_RXTRIGGER_4
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|UFCON_RXTRIGGER_8
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|UFCON_RXTRIGGER_12
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|UFCON_RXTRIGGER_16
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|UFCON_TXFIFO_RESET
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UFCON_RXFIFO_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|UFCON_FIFO_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SSCOM_UMCON
value|0x0c
end_define

begin_comment
comment|/* MODEM control */
end_comment

begin_define
define|#
directive|define
name|UMCON_RTS
value|(1<< 0)
end_define

begin_comment
comment|/* Request to send */
end_comment

begin_define
define|#
directive|define
name|SSCOM_UTRSTAT
value|0x10
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|UTRSTAT_TXSHIFTER_EMPTY
value|( 1<< 2)
end_define

begin_define
define|#
directive|define
name|UTRSTAT_TXEMPTY
value|(1<< 1)
end_define

begin_comment
comment|/* TX fifo or buffer empty */
end_comment

begin_define
define|#
directive|define
name|UTRSTAT_RXREADY
value|(1<< 0)
end_define

begin_comment
comment|/* RX fifo or buffer is not empty */
end_comment

begin_define
define|#
directive|define
name|SSCOM_UERSTAT
value|0x14
end_define

begin_comment
comment|/* Error status register */
end_comment

begin_define
define|#
directive|define
name|UERSTAT_BREAK
value|(1<< 3)
end_define

begin_comment
comment|/* Break signal, not 2410 */
end_comment

begin_define
define|#
directive|define
name|UERSTAT_FRAME
value|(1<< 2)
end_define

begin_comment
comment|/* Frame error */
end_comment

begin_define
define|#
directive|define
name|UERSTAT_PARITY
value|(1<< 1)
end_define

begin_comment
comment|/* Parity error, not 2410 */
end_comment

begin_define
define|#
directive|define
name|UERSTAT_OVERRUN
value|(1<< 0)
end_define

begin_comment
comment|/* Overrun */
end_comment

begin_define
define|#
directive|define
name|UERSTAT_ALL_ERRORS
define|\
value|(UERSTAT_OVERRUN|UERSTAT_BREAK|UERSTAT_FRAME|UERSTAT_PARITY)
end_define

begin_define
define|#
directive|define
name|SSCOM_UFSTAT
value|0x18
end_define

begin_comment
comment|/* Fifo status register */
end_comment

begin_define
define|#
directive|define
name|UFSTAT_RXFULL
value|(1<<8)
end_define

begin_comment
comment|/* Rx fifo full */
end_comment

begin_define
define|#
directive|define
name|UFSTAT_TXCOUNT_SHIFT
value|4
end_define

begin_comment
comment|/* TX FIFO count */
end_comment

begin_define
define|#
directive|define
name|UFSTAT_TXCOUNT
value|(0x0f<< UFSTAT_TXCOUNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|UFSTAT_RXCOUNT_SHIFT
value|0
end_define

begin_comment
comment|/* RX FIFO count */
end_comment

begin_define
define|#
directive|define
name|UFSTAT_RXCOUNT
value|(0x0f<< UFSTAT_RXCOUNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSCOM_UMSTAT
value|0x1c
end_define

begin_comment
comment|/* Modem status register */
end_comment

begin_define
define|#
directive|define
name|UMSTAT_CTS
value|(1<< 0)
end_define

begin_comment
comment|/* Clear to send */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|SSCOM_UTXH
value|0x20
end_define

begin_comment
comment|/* Transmit data register */
end_comment

begin_define
define|#
directive|define
name|SSCOM_URXH
value|0x24
end_define

begin_comment
comment|/* Receive data register */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSCOM_UTXH
value|0x23
end_define

begin_comment
comment|/* Transmit data register */
end_comment

begin_define
define|#
directive|define
name|SSCOM_URXH
value|0x27
end_define

begin_comment
comment|/* Receive data register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SSCOM_UBRDIV
value|0x28
end_define

begin_comment
comment|/* baud-reate divisor */
end_comment

begin_define
define|#
directive|define
name|SSCOM_SIZE
value|0x2c
end_define

end_unit

