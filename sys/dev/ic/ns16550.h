begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ns16550.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * NS8250... UART registers.  */
end_comment

begin_comment
comment|/* 8250 registers #[0-6]. */
end_comment

begin_define
define|#
directive|define
name|com_data
value|0
end_define

begin_comment
comment|/* data register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_ier
value|1
end_define

begin_comment
comment|/* interrupt enable register (W) */
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

begin_define
define|#
directive|define
name|com_iir
value|2
end_define

begin_comment
comment|/* interrupt identification register (R) */
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

begin_define
define|#
directive|define
name|com_lctl
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|3
end_define

begin_comment
comment|/* character format control register (R/W) */
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

begin_define
define|#
directive|define
name|CFCR_EFR_ENABLE
value|0xbf
end_define

begin_comment
comment|/* magic to enable EFR on 16650 up */
end_comment

begin_define
define|#
directive|define
name|com_mcr
value|4
end_define

begin_comment
comment|/* modem control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|MCR_PRESCALE
value|0x80
end_define

begin_comment
comment|/* only available on 16650 up */
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

begin_define
define|#
directive|define
name|com_lsr
value|5
end_define

begin_comment
comment|/* line status register (R/W) */
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

begin_define
define|#
directive|define
name|com_msr
value|6
end_define

begin_comment
comment|/* modem status register (R/W) */
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
comment|/* 8250 multiplexed registers #[0-1].  Access enabled by LCR[7]. */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|0
end_define

begin_comment
comment|/* divisor latch low (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|1
end_define

begin_comment
comment|/* divisor latch high (W) */
end_comment

begin_comment
comment|/* 16450 register #7.  Not multiplexed. */
end_comment

begin_define
define|#
directive|define
name|com_scr
value|7
end_define

begin_comment
comment|/* scratch register (R/W) */
end_comment

begin_comment
comment|/* 16550 register #2.  Not multiplexed. */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|2
end_define

begin_comment
comment|/* FIFO control register (W) */
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
comment|/* 16650 registers #2,[4-7].  Access enabled by LCR_EFR_ENABLE. */
end_comment

begin_define
define|#
directive|define
name|com_efr
value|com_fifo
end_define

begin_comment
comment|/* enhanced feature register (R/W) */
end_comment

begin_define
define|#
directive|define
name|EFR_EFE
value|0x10
end_define

begin_comment
comment|/* enhanced functions enable */
end_comment

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
name|com_emr
value|com_msr
end_define

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

end_unit

