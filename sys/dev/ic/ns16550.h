begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ns16550.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
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
name|REG_DATA
value|com_data
end_define

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
name|REG_IER
value|com_ier
end_define

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
name|REG_IIR
value|com_iir
end_define

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
name|com_lcr
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|com_lcr
end_define

begin_comment
comment|/* character format control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|REG_LCR
value|com_lcr
end_define

begin_define
define|#
directive|define
name|LCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|CFCR_DLAB
value|LCR_DLAB
end_define

begin_define
define|#
directive|define
name|LCR_EFR_ENABLE
value|0xbf
end_define

begin_comment
comment|/* magic to enable EFR on 16650 up */
end_comment

begin_define
define|#
directive|define
name|CFCR_EFR_ENABLE
value|LCR_EFR_ENABLE
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
name|CFCR_SBREAK
value|LCR_SBREAK
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
name|CFCR_PZERO
value|LCR_PZERO
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
name|CFCR_PONE
value|LCR_PONE
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
name|CFCR_PEVEN
value|LCR_PEVEN
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
name|CFCR_PODD
value|LCR_PODD
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
name|CFCR_PENAB
value|LCR_PENAB
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
name|CFCR_STOPB
value|LCR_STOPB
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
name|CFCR_8BITS
value|LCR_8BITS
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
name|CFCR_7BITS
value|LCR_7BITS
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
name|CFCR_6BITS
value|LCR_6BITS
end_define

begin_define
define|#
directive|define
name|LCR_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|CFCR_5BITS
value|LCR_5BITS
end_define

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
name|REG_MCR
value|com_mcr
end_define

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
name|MCR_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|MCR_IENABLE
value|MCR_IE
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
name|REG_LSR
value|com_lsr
end_define

begin_define
define|#
directive|define
name|LSR_RCV_FIFO
value|0x80
end_define

begin_define
define|#
directive|define
name|LSR_TEMT
value|0x40
end_define

begin_define
define|#
directive|define
name|LSR_TSRE
value|LSR_TEMT
end_define

begin_define
define|#
directive|define
name|LSR_THRE
value|0x20
end_define

begin_define
define|#
directive|define
name|LSR_TXRDY
value|LSR_THRE
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
name|REG_MSR
value|com_msr
end_define

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
name|com_dll
value|0
end_define

begin_comment
comment|/* divisor latch low (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|com_dll
end_define

begin_define
define|#
directive|define
name|com_dlm
value|1
end_define

begin_comment
comment|/* divisor latch high (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|com_dlm
end_define

begin_define
define|#
directive|define
name|REG_DLL
value|com_dll
end_define

begin_define
define|#
directive|define
name|REG_DLH
value|com_dlm
end_define

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
name|com_fcr
value|2
end_define

begin_comment
comment|/* FIFO control register (W) */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|com_fcr
end_define

begin_define
define|#
directive|define
name|REG_FCR
value|com_fcr
end_define

begin_define
define|#
directive|define
name|FCR_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FIFO_ENABLE
value|FCR_ENABLE
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
name|FIFO_RCV_RST
value|FCR_RCV_RST
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
name|FIFO_XMT_RST
value|FCR_XMT_RST
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
name|FIFO_DMA_MODE
value|FCR_DMA
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
name|FIFO_RX_LOW
value|FCR_RX_LOW
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
name|FIFO_RX_MEDL
value|FCR_RX_MEDL
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
name|FIFO_RX_MEDH
value|FCR_RX_MEDH
end_define

begin_define
define|#
directive|define
name|FCR_RX_HIGH
value|0xc0
end_define

begin_define
define|#
directive|define
name|FIFO_RX_HIGH
value|FCR_RX_HIGH
end_define

begin_comment
comment|/* 16650 registers #2,[4-7].  Access enabled by LCR_EFR_ENABLE. */
end_comment

begin_define
define|#
directive|define
name|com_efr
value|2
end_define

begin_comment
comment|/* enhanced features register (R/W) */
end_comment

begin_define
define|#
directive|define
name|REG_EFR
value|com_efr
end_define

begin_define
define|#
directive|define
name|EFR_CTS
value|0x80
end_define

begin_define
define|#
directive|define
name|EFR_AUTOCTS
value|EFR_CTS
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
name|EFR_AUTORTS
value|EFR_RTS
end_define

begin_define
define|#
directive|define
name|EFR_EFE
value|0x10
end_define

begin_comment
comment|/* enhanced functions enable */
end_comment

begin_define
define|#
directive|define
name|com_xon1
value|4
end_define

begin_comment
comment|/* XON 1 character (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_xon2
value|5
end_define

begin_comment
comment|/* XON 2 character (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_xoff1
value|6
end_define

begin_comment
comment|/* XOFF 1 character (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_xoff2
value|7
end_define

begin_comment
comment|/* XOFF 2 character (R/W) */
end_comment

begin_comment
comment|/* 16950 register #1.  Access enabled by ACR[7].  Also requires !LCR[7]. */
end_comment

begin_define
define|#
directive|define
name|com_asr
value|1
end_define

begin_comment
comment|/* additional status register (R[0-7]/W[0-1]) */
end_comment

begin_comment
comment|/* 16950 register #3.  R/W access enabled by ACR[7]. */
end_comment

begin_define
define|#
directive|define
name|com_rfl
value|3
end_define

begin_comment
comment|/* receiver fifo level (R) */
end_comment

begin_comment
comment|/*  * 16950 register #4.  Access enabled by ACR[7].  Also requires  * !LCR_EFR_ENABLE.  */
end_comment

begin_define
define|#
directive|define
name|com_tfl
value|4
end_define

begin_comment
comment|/* transmitter fifo level (R) */
end_comment

begin_comment
comment|/*  * 16950 register #5.  Accessible if !LCR_EFR_ENABLE.  Read access also  * requires ACR[6].  */
end_comment

begin_define
define|#
directive|define
name|com_icr
value|5
end_define

begin_comment
comment|/* index control register (R/W) */
end_comment

begin_comment
comment|/*  * 16950 register #7.  It is the same as com_scr except it has a different  * abbreviation in the manufacturer's data sheet and it also serves as an  * index into the Indexed Control register set.  */
end_comment

begin_define
define|#
directive|define
name|com_spr
value|com_scr
end_define

begin_comment
comment|/* scratch pad (and index) register (R/W) */
end_comment

begin_define
define|#
directive|define
name|REG_SPR
value|com_scr
end_define

begin_comment
comment|/*  * 16950 indexed control registers #[0-0x13].  Access is via index in SPR,  * data in ICR (if ICR is accessible).  */
end_comment

begin_define
define|#
directive|define
name|com_acr
value|0
end_define

begin_comment
comment|/* additional control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|ACR_ASE
value|0x80
end_define

begin_comment
comment|/* ASR/RFL/TFL enable */
end_comment

begin_define
define|#
directive|define
name|ACR_ICRE
value|0x40
end_define

begin_comment
comment|/* ICR enable */
end_comment

begin_define
define|#
directive|define
name|ACR_TLE
value|0x20
end_define

begin_comment
comment|/* TTL/RTL enable */
end_comment

begin_define
define|#
directive|define
name|com_cpr
value|1
end_define

begin_comment
comment|/* clock prescaler register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_tcr
value|2
end_define

begin_comment
comment|/* times clock register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_ttl
value|4
end_define

begin_comment
comment|/* transmitter trigger level (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_rtl
value|5
end_define

begin_comment
comment|/* receiver trigger level (R/W) */
end_comment

begin_comment
comment|/* ... */
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

