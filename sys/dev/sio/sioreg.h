begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)comreg.h	7.2 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Receiver clock frequency for "standard" pc serial ports. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_RCLK
value|1843200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* 16 bit baud rate divisor (lower byte in dca_data, upper in dca_ier) */
end_comment

begin_define
define|#
directive|define
name|COMBRD
parameter_list|(
name|x
parameter_list|)
value|(1843200 / (16*(x)))
end_define

begin_define
define|#
directive|define
name|COMBRD_RSA
parameter_list|(
name|x
parameter_list|)
value|(14745600 / (16*(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|IER_ERXRDY
value|0x1
end_define

begin_define
define|#
directive|define
name|IER_ETXRDY
value|0x2
end_define

begin_define
define|#
directive|define
name|IER_ERLS
value|0x4
end_define

begin_define
define|#
directive|define
name|IER_EMSC
value|0x8
end_define

begin_comment
comment|/* interrupt identification register */
end_comment

begin_define
define|#
directive|define
name|IIR_IMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|IIR_RXTOUT
value|0xc
end_define

begin_define
define|#
directive|define
name|IIR_RLS
value|0x6
end_define

begin_define
define|#
directive|define
name|IIR_RXRDY
value|0x4
end_define

begin_define
define|#
directive|define
name|IIR_TXRDY
value|0x2
end_define

begin_define
define|#
directive|define
name|IIR_NOPEND
value|0x1
end_define

begin_define
define|#
directive|define
name|IIR_MLSC
value|0x0
end_define

begin_define
define|#
directive|define
name|IIR_FIFO_MASK
value|0xc0
end_define

begin_comment
comment|/* set if FIFOs are enabled */
end_comment

begin_comment
comment|/* fifo control register */
end_comment

begin_define
define|#
directive|define
name|FIFO_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFO_RCV_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|FIFO_XMT_RST
value|0x04
end_define

begin_define
define|#
directive|define
name|FIFO_DMA_MODE
value|0x08
end_define

begin_define
define|#
directive|define
name|FIFO_RX_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MEDL
value|0x40
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MEDH
value|0x80
end_define

begin_define
define|#
directive|define
name|FIFO_RX_HIGH
value|0xc0
end_define

begin_comment
comment|/* character format control register */
end_comment

begin_define
define|#
directive|define
name|CFCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|CFCR_SBREAK
value|0x40
end_define

begin_define
define|#
directive|define
name|CFCR_PZERO
value|0x30
end_define

begin_define
define|#
directive|define
name|CFCR_PONE
value|0x20
end_define

begin_define
define|#
directive|define
name|CFCR_PEVEN
value|0x10
end_define

begin_define
define|#
directive|define
name|CFCR_PODD
value|0x00
end_define

begin_define
define|#
directive|define
name|CFCR_PENAB
value|0x08
end_define

begin_define
define|#
directive|define
name|CFCR_STOPB
value|0x04
end_define

begin_define
define|#
directive|define
name|CFCR_8BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|CFCR_7BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|CFCR_6BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|CFCR_5BITS
value|0x00
end_define

begin_comment
comment|/* modem control register */
end_comment

begin_define
define|#
directive|define
name|MCR_LOOPBACK
value|0x10
end_define

begin_define
define|#
directive|define
name|MCR_IENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|MCR_DRS
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
comment|/* line status register */
end_comment

begin_define
define|#
directive|define
name|LSR_RCV_FIFO
value|0x80
end_define

begin_define
define|#
directive|define
name|LSR_TSRE
value|0x40
end_define

begin_define
define|#
directive|define
name|LSR_TXRDY
value|0x20
end_define

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

begin_define
define|#
directive|define
name|LSR_RCV_MASK
value|0x1f
end_define

begin_comment
comment|/* modem status register */
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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* Hardware extension mode register for RSB-2000/3000. */
end_comment

begin_define
define|#
directive|define
name|EMR_EXBUFF
value|0x04
end_define

begin_define
define|#
directive|define
name|EMR_CTSFLW
value|0x08
end_define

begin_define
define|#
directive|define
name|EMR_DSRFLW
value|0x10
end_define

begin_define
define|#
directive|define
name|EMR_RTSFLW
value|0x20
end_define

begin_define
define|#
directive|define
name|EMR_DTRFLW
value|0x40
end_define

begin_define
define|#
directive|define
name|EMR_EFMODE
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* speed to initialize to during chip tests */
end_comment

begin_define
define|#
directive|define
name|SIO_TEST_SPEED
value|9600
end_define

begin_comment
comment|/* default serial console speed if not set with sysctl or probed from boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONSPEED
end_ifndef

begin_define
define|#
directive|define
name|CONSPEED
value|9600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IO_COMSIZE
value|8
end_define

begin_comment
comment|/* 8250, 16x50 com controllers */
end_comment

end_unit

