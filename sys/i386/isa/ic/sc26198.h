begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  * sc26198.h  -- SC26198 UART hardware info.  *  * Copyright (c) 1995-1998 Greg Ungerer (gerg@stallion.oz.au).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Greg Ungerer.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SC26198_H
end_ifndef

begin_define
define|#
directive|define
name|_SC26198_H
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the number of async ports per sc26198 uart device.  */
end_comment

begin_define
define|#
directive|define
name|SC26198_PORTS
value|8
end_define

begin_comment
comment|/*  *	Baud rate timing clocks. All derived from a master 14.7456 MHz clock.  */
end_comment

begin_define
define|#
directive|define
name|SC26198_MASTERCLOCK
value|14745600L
end_define

begin_define
define|#
directive|define
name|SC26198_DCLK
value|(SC26198_MASTERCLOCK)
end_define

begin_define
define|#
directive|define
name|SC26198_CCLK
value|(SC26198_MASTERCLOCK / 2)
end_define

begin_define
define|#
directive|define
name|SC26198_BCLK
value|(SC26198_MASTERCLOCK / 4)
end_define

begin_comment
comment|/*  *	Define internal FIFO sizes for the 26198 ports.  */
end_comment

begin_define
define|#
directive|define
name|SC26198_TXFIFOSIZE
value|16
end_define

begin_define
define|#
directive|define
name|SC26198_RXFIFOSIZE
value|16
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Global register definitions. These registers are global to each 26198  *	device, not specific ports on it.  */
end_comment

begin_define
define|#
directive|define
name|TSTR
value|0x0d
end_define

begin_define
define|#
directive|define
name|GCCR
value|0x0f
end_define

begin_define
define|#
directive|define
name|ICR
value|0x1b
end_define

begin_define
define|#
directive|define
name|WDTRCR
value|0x1d
end_define

begin_define
define|#
directive|define
name|IVR
value|0x1f
end_define

begin_define
define|#
directive|define
name|BRGTRUA
value|0x84
end_define

begin_define
define|#
directive|define
name|GPOSR
value|0x87
end_define

begin_define
define|#
directive|define
name|GPOC
value|0x8b
end_define

begin_define
define|#
directive|define
name|UCIR
value|0x8c
end_define

begin_define
define|#
directive|define
name|CIR
value|0x8c
end_define

begin_define
define|#
directive|define
name|BRGTRUB
value|0x8d
end_define

begin_define
define|#
directive|define
name|GRXFIFO
value|0x8e
end_define

begin_define
define|#
directive|define
name|GTXFIFO
value|0x8e
end_define

begin_define
define|#
directive|define
name|GCCR2
value|0x8f
end_define

begin_define
define|#
directive|define
name|BRGTRLA
value|0x94
end_define

begin_define
define|#
directive|define
name|GPOR
value|0x97
end_define

begin_define
define|#
directive|define
name|GPOD
value|0x9b
end_define

begin_define
define|#
directive|define
name|BRGTCR
value|0x9c
end_define

begin_define
define|#
directive|define
name|GICR
value|0x9c
end_define

begin_define
define|#
directive|define
name|BRGTRLB
value|0x9d
end_define

begin_define
define|#
directive|define
name|GIBCR
value|0x9d
end_define

begin_define
define|#
directive|define
name|GITR
value|0x9f
end_define

begin_comment
comment|/*  *	Per port channel registers. These are the register offsets within  *	the port address space, so need to have the port address (0 to 7)  *	inserted in bit positions 4:6.  */
end_comment

begin_define
define|#
directive|define
name|MR0
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1
value|0x01
end_define

begin_define
define|#
directive|define
name|IOPCR
value|0x02
end_define

begin_define
define|#
directive|define
name|BCRBRK
value|0x03
end_define

begin_define
define|#
directive|define
name|BCRCOS
value|0x04
end_define

begin_define
define|#
directive|define
name|BCRX
value|0x06
end_define

begin_define
define|#
directive|define
name|BCRA
value|0x07
end_define

begin_define
define|#
directive|define
name|XONCR
value|0x08
end_define

begin_define
define|#
directive|define
name|XOFFCR
value|0x09
end_define

begin_define
define|#
directive|define
name|ARCR
value|0x0a
end_define

begin_define
define|#
directive|define
name|RXCSR
value|0x0c
end_define

begin_define
define|#
directive|define
name|TXCSR
value|0x0e
end_define

begin_define
define|#
directive|define
name|MR2
value|0x80
end_define

begin_define
define|#
directive|define
name|SR
value|0x81
end_define

begin_define
define|#
directive|define
name|SCCR
value|0x81
end_define

begin_define
define|#
directive|define
name|ISR
value|0x82
end_define

begin_define
define|#
directive|define
name|IMR
value|0x82
end_define

begin_define
define|#
directive|define
name|TXFIFO
value|0x83
end_define

begin_define
define|#
directive|define
name|RXFIFO
value|0x83
end_define

begin_define
define|#
directive|define
name|IPR
value|0x84
end_define

begin_define
define|#
directive|define
name|IOPIOR
value|0x85
end_define

begin_define
define|#
directive|define
name|XISR
value|0x86
end_define

begin_comment
comment|/*  *	For any given port calculate the address to use to access a specified  *	register. This is only used for unusual access...  */
end_comment

begin_define
define|#
directive|define
name|SC26198_PORTREG
parameter_list|(
name|port
parameter_list|,
name|reg
parameter_list|)
value|((((port)& 0x07)<< 4) | (reg))
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Global configuration control register bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|GCCR_NOACK
value|0x00
end_define

begin_define
define|#
directive|define
name|GCCR_IVRACK
value|0x02
end_define

begin_define
define|#
directive|define
name|GCCR_IVRCHANACK
value|0x04
end_define

begin_define
define|#
directive|define
name|GCCR_IVRTYPCHANACK
value|0x06
end_define

begin_define
define|#
directive|define
name|GCCR_ASYNCCYCLE
value|0x00
end_define

begin_define
define|#
directive|define
name|GCCR_SYNCCYCLE
value|0x40
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Mode register 0 bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|MR0_ADDRNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_AUTOWAKE
value|0x01
end_define

begin_define
define|#
directive|define
name|MR0_AUTODOZE
value|0x02
end_define

begin_define
define|#
directive|define
name|MR0_AUTOWAKEDOZE
value|0x03
end_define

begin_define
define|#
directive|define
name|MR0_SWFNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_SWFTX
value|0x04
end_define

begin_define
define|#
directive|define
name|MR0_SWFRX
value|0x08
end_define

begin_define
define|#
directive|define
name|MR0_SWFRXTX
value|0x0c
end_define

begin_define
define|#
directive|define
name|MR0_TXMASK
value|0x30
end_define

begin_define
define|#
directive|define
name|MR0_TXEMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_TXHIGH
value|0x10
end_define

begin_define
define|#
directive|define
name|MR0_TXHALF
value|0x20
end_define

begin_define
define|#
directive|define
name|MR0_TXRDY
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_ADDRNT
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_ADDRT
value|0x40
end_define

begin_define
define|#
directive|define
name|MR0_SWFNT
value|0x00
end_define

begin_define
define|#
directive|define
name|MR0_SWFT
value|0x80
end_define

begin_comment
comment|/*  *	Mode register 1 bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|MR1_CS5
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_CS6
value|0x01
end_define

begin_define
define|#
directive|define
name|MR1_CS7
value|0x02
end_define

begin_define
define|#
directive|define
name|MR1_CS8
value|0x03
end_define

begin_define
define|#
directive|define
name|MR1_PAREVEN
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_PARODD
value|0x04
end_define

begin_define
define|#
directive|define
name|MR1_PARENB
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_PARFORCE
value|0x08
end_define

begin_define
define|#
directive|define
name|MR1_PARNONE
value|0x10
end_define

begin_define
define|#
directive|define
name|MR1_PARSPECIAL
value|0x18
end_define

begin_define
define|#
directive|define
name|MR1_ERRCHAR
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_ERRBLOCK
value|0x20
end_define

begin_define
define|#
directive|define
name|MR1_ISRUNMASKED
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_ISRMASKED
value|0x40
end_define

begin_define
define|#
directive|define
name|MR1_AUTORTS
value|0x80
end_define

begin_comment
comment|/*  *	Mode register 2 bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|MR2_STOP1
value|0x00
end_define

begin_define
define|#
directive|define
name|MR2_STOP15
value|0x01
end_define

begin_define
define|#
directive|define
name|MR2_STOP2
value|0x02
end_define

begin_define
define|#
directive|define
name|MR2_STOP916
value|0x03
end_define

begin_define
define|#
directive|define
name|MR2_RXFIFORDY
value|0x00
end_define

begin_define
define|#
directive|define
name|MR2_RXFIFOHALF
value|0x04
end_define

begin_define
define|#
directive|define
name|MR2_RXFIFOHIGH
value|0x08
end_define

begin_define
define|#
directive|define
name|MR2_RXFIFOFULL
value|0x0c
end_define

begin_define
define|#
directive|define
name|MR2_AUTOCTS
value|0x10
end_define

begin_define
define|#
directive|define
name|MR2_TXRTS
value|0x20
end_define

begin_define
define|#
directive|define
name|MR2_MODENORM
value|0x00
end_define

begin_define
define|#
directive|define
name|MR2_MODEAUTOECHO
value|0x40
end_define

begin_define
define|#
directive|define
name|MR2_MODELOOP
value|0x80
end_define

begin_define
define|#
directive|define
name|MR2_MODEREMECHO
value|0xc0
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Baud Rate Generator (BRG) selector values.  */
end_comment

begin_define
define|#
directive|define
name|BRG_50
value|0x00
end_define

begin_define
define|#
directive|define
name|BRG_75
value|0x01
end_define

begin_define
define|#
directive|define
name|BRG_150
value|0x02
end_define

begin_define
define|#
directive|define
name|BRG_200
value|0x03
end_define

begin_define
define|#
directive|define
name|BRG_300
value|0x04
end_define

begin_define
define|#
directive|define
name|BRG_450
value|0x05
end_define

begin_define
define|#
directive|define
name|BRG_600
value|0x06
end_define

begin_define
define|#
directive|define
name|BRG_900
value|0x07
end_define

begin_define
define|#
directive|define
name|BRG_1200
value|0x08
end_define

begin_define
define|#
directive|define
name|BRG_1800
value|0x09
end_define

begin_define
define|#
directive|define
name|BRG_2400
value|0x0a
end_define

begin_define
define|#
directive|define
name|BRG_3600
value|0x0b
end_define

begin_define
define|#
directive|define
name|BRG_4800
value|0x0c
end_define

begin_define
define|#
directive|define
name|BRG_7200
value|0x0d
end_define

begin_define
define|#
directive|define
name|BRG_9600
value|0x0e
end_define

begin_define
define|#
directive|define
name|BRG_14400
value|0x0f
end_define

begin_define
define|#
directive|define
name|BRG_19200
value|0x10
end_define

begin_define
define|#
directive|define
name|BRG_28200
value|0x11
end_define

begin_define
define|#
directive|define
name|BRG_38400
value|0x12
end_define

begin_define
define|#
directive|define
name|BRG_57600
value|0x13
end_define

begin_define
define|#
directive|define
name|BRG_115200
value|0x14
end_define

begin_define
define|#
directive|define
name|BRG_230400
value|0x15
end_define

begin_define
define|#
directive|define
name|BRG_GIN0
value|0x16
end_define

begin_define
define|#
directive|define
name|BRG_GIN1
value|0x17
end_define

begin_define
define|#
directive|define
name|BRG_CT0
value|0x18
end_define

begin_define
define|#
directive|define
name|BRG_CT1
value|0x19
end_define

begin_define
define|#
directive|define
name|BRG_RX2TX316
value|0x1b
end_define

begin_define
define|#
directive|define
name|BRG_RX2TX31
value|0x1c
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Command register command definitions.  */
end_comment

begin_define
define|#
directive|define
name|CR_NULL
value|0x04
end_define

begin_define
define|#
directive|define
name|CR_ADDRNORMAL
value|0x0c
end_define

begin_define
define|#
directive|define
name|CR_RXRESET
value|0x14
end_define

begin_define
define|#
directive|define
name|CR_TXRESET
value|0x1c
end_define

begin_define
define|#
directive|define
name|CR_CLEARRXERR
value|0x24
end_define

begin_define
define|#
directive|define
name|CR_BREAKRESET
value|0x2c
end_define

begin_define
define|#
directive|define
name|CR_TXSTARTBREAK
value|0x34
end_define

begin_define
define|#
directive|define
name|CR_TXSTOPBREAK
value|0x3c
end_define

begin_define
define|#
directive|define
name|CR_RTSON
value|0x44
end_define

begin_define
define|#
directive|define
name|CR_RTSOFF
value|0x4c
end_define

begin_define
define|#
directive|define
name|CR_ADDRINIT
value|0x5c
end_define

begin_define
define|#
directive|define
name|CR_RXERRBLOCK
value|0x6c
end_define

begin_define
define|#
directive|define
name|CR_TXSENDXON
value|0x84
end_define

begin_define
define|#
directive|define
name|CR_TXSENDXOFF
value|0x8c
end_define

begin_define
define|#
directive|define
name|CR_GANGXONSET
value|0x94
end_define

begin_define
define|#
directive|define
name|CR_GANGXOFFSET
value|0x9c
end_define

begin_define
define|#
directive|define
name|CR_GANGXONINIT
value|0xa4
end_define

begin_define
define|#
directive|define
name|CR_GANGXOFFINIT
value|0xac
end_define

begin_define
define|#
directive|define
name|CR_HOSTXON
value|0xb4
end_define

begin_define
define|#
directive|define
name|CR_HOSTXOFF
value|0xbc
end_define

begin_define
define|#
directive|define
name|CR_CANCELXOFF
value|0xc4
end_define

begin_define
define|#
directive|define
name|CR_ADDRRESET
value|0xdc
end_define

begin_define
define|#
directive|define
name|CR_RESETALLPORTS
value|0xf4
end_define

begin_define
define|#
directive|define
name|CR_RESETALL
value|0xfc
end_define

begin_define
define|#
directive|define
name|CR_RXENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|CR_TXENABLE
value|0x02
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Channel status register.  */
end_comment

begin_define
define|#
directive|define
name|SR_RXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|SR_RXFULL
value|0x02
end_define

begin_define
define|#
directive|define
name|SR_TXRDY
value|0x04
end_define

begin_define
define|#
directive|define
name|SR_TXEMPTY
value|0x08
end_define

begin_define
define|#
directive|define
name|SR_RXOVERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|SR_RXPARITY
value|0x20
end_define

begin_define
define|#
directive|define
name|SR_RXFRAMING
value|0x40
end_define

begin_define
define|#
directive|define
name|SR_RXBREAK
value|0x80
end_define

begin_define
define|#
directive|define
name|SR_RXERRS
value|(SR_RXPARITY | SR_RXFRAMING | SR_RXOVERRUN)
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Interrupt status register and interrupt mask register bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|IR_TXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|IR_RXRDY
value|0x02
end_define

begin_define
define|#
directive|define
name|IR_RXBREAK
value|0x04
end_define

begin_define
define|#
directive|define
name|IR_XONXOFF
value|0x10
end_define

begin_define
define|#
directive|define
name|IR_ADDRRECOG
value|0x20
end_define

begin_define
define|#
directive|define
name|IR_RXWATCHDOG
value|0x40
end_define

begin_define
define|#
directive|define
name|IR_IOPORT
value|0x80
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Interrupt vector register field definitions.  */
end_comment

begin_define
define|#
directive|define
name|IVR_CHANMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|IVR_TYPEMASK
value|0x18
end_define

begin_define
define|#
directive|define
name|IVR_CONSTMASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|IVR_RXDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|IVR_RXBADDATA
value|0x18
end_define

begin_define
define|#
directive|define
name|IVR_TXDATA
value|0x08
end_define

begin_define
define|#
directive|define
name|IVR_OTHER
value|0x00
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	BRG timer control register bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|BRGCTCR_DISABCLK0
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGCTCR_ENABCLK0
value|0x08
end_define

begin_define
define|#
directive|define
name|BRGCTCR_DISABCLK1
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGCTCR_ENABCLK1
value|0x80
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0SCLK16
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0SCLK32
value|0x01
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0SCLK64
value|0x02
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0SCLK128
value|0x03
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0X1
value|0x04
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0X12
value|0x05
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0IO1A
value|0x06
end_define

begin_define
define|#
directive|define
name|BRGCTCR_0GIN0
value|0x07
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1SCLK16
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1SCLK32
value|0x10
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1SCLK64
value|0x20
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1SCLK128
value|0x30
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1X1
value|0x40
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1X12
value|0x50
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1IO1B
value|0x60
end_define

begin_define
define|#
directive|define
name|BRGCTCR_1GIN1
value|0x70
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Watch dog timer enable register.  */
end_comment

begin_define
define|#
directive|define
name|WDTRCR_ENABALL
value|0xff
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	XON/XOFF interrupt status register.  */
end_comment

begin_define
define|#
directive|define
name|XISR_TXCHARMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|XISR_TXCHARNORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|XISR_TXWAIT
value|0x01
end_define

begin_define
define|#
directive|define
name|XISR_TXXOFFPEND
value|0x02
end_define

begin_define
define|#
directive|define
name|XISR_TXXONPEND
value|0x03
end_define

begin_define
define|#
directive|define
name|XISR_TXFLOWMASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|XISR_TXNORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|XISR_TXSTOPPEND
value|0x04
end_define

begin_define
define|#
directive|define
name|XISR_TXSTARTED
value|0x08
end_define

begin_define
define|#
directive|define
name|XISR_TXSTOPPED
value|0x0c
end_define

begin_define
define|#
directive|define
name|XISR_RXFLOWMASK
value|0x30
end_define

begin_define
define|#
directive|define
name|XISR_RXFLOWNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|XISR_RXXONSENT
value|0x10
end_define

begin_define
define|#
directive|define
name|XISR_RXXOFFSENT
value|0x20
end_define

begin_define
define|#
directive|define
name|XISR_RXXONGOT
value|0x40
end_define

begin_define
define|#
directive|define
name|XISR_RXXOFFGOT
value|0x80
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Current interrupt register.  */
end_comment

begin_define
define|#
directive|define
name|CIR_TYPEMASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|CIR_TYPEOTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|CIR_TYPETX
value|0x40
end_define

begin_define
define|#
directive|define
name|CIR_TYPERXGOOD
value|0x80
end_define

begin_define
define|#
directive|define
name|CIR_TYPERXBAD
value|0xc0
end_define

begin_define
define|#
directive|define
name|CIR_RXDATA
value|0x80
end_define

begin_define
define|#
directive|define
name|CIR_RXBADDATA
value|0x40
end_define

begin_define
define|#
directive|define
name|CIR_TXDATA
value|0x40
end_define

begin_define
define|#
directive|define
name|CIR_CHANMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|CIR_CNTMASK
value|0x38
end_define

begin_define
define|#
directive|define
name|CIR_SUBTYPEMASK
value|0x38
end_define

begin_define
define|#
directive|define
name|CIR_SUBNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|CIR_SUBCOS
value|0x08
end_define

begin_define
define|#
directive|define
name|CIR_SUBADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|CIR_SUBXONXOFF
value|0x18
end_define

begin_define
define|#
directive|define
name|CIR_SUBBREAK
value|0x28
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Global interrupting channel register.  */
end_comment

begin_define
define|#
directive|define
name|GICR_CHANMASK
value|0x07
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Global interrupting byte count register.  */
end_comment

begin_define
define|#
directive|define
name|GICR_COUNTMASK
value|0x0f
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Global interrupting type register.  */
end_comment

begin_define
define|#
directive|define
name|GITR_RXMASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|GITR_RXNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GITR_RXBADDATA
value|0x80
end_define

begin_define
define|#
directive|define
name|GITR_RXGOODDATA
value|0xc0
end_define

begin_define
define|#
directive|define
name|GITR_TXDATA
value|0x20
end_define

begin_define
define|#
directive|define
name|GITR_SUBTYPEMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|GITR_SUBNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GITR_SUBCOS
value|0x01
end_define

begin_define
define|#
directive|define
name|GITR_SUBADDR
value|0x02
end_define

begin_define
define|#
directive|define
name|GITR_SUBXONXOFF
value|0x03
end_define

begin_define
define|#
directive|define
name|GITR_SUBBREAK
value|0x05
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Input port change register.  */
end_comment

begin_define
define|#
directive|define
name|IPR_CTS
value|0x01
end_define

begin_define
define|#
directive|define
name|IPR_DTR
value|0x02
end_define

begin_define
define|#
directive|define
name|IPR_RTS
value|0x04
end_define

begin_define
define|#
directive|define
name|IPR_DCD
value|0x08
end_define

begin_define
define|#
directive|define
name|IPR_CTSCHANGE
value|0x10
end_define

begin_define
define|#
directive|define
name|IPR_DTRCHANGE
value|0x20
end_define

begin_define
define|#
directive|define
name|IPR_RTSCHANGE
value|0x40
end_define

begin_define
define|#
directive|define
name|IPR_DCDCHANGE
value|0x80
end_define

begin_define
define|#
directive|define
name|IPR_CHANGEMASK
value|0xf0
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	IO port interrupt and output register.  */
end_comment

begin_define
define|#
directive|define
name|IOPR_CTS
value|0x01
end_define

begin_define
define|#
directive|define
name|IOPR_DTR
value|0x02
end_define

begin_define
define|#
directive|define
name|IOPR_RTS
value|0x04
end_define

begin_define
define|#
directive|define
name|IOPR_DCD
value|0x08
end_define

begin_define
define|#
directive|define
name|IOPR_CTSCOS
value|0x10
end_define

begin_define
define|#
directive|define
name|IOPR_DTRCOS
value|0x20
end_define

begin_define
define|#
directive|define
name|IOPR_RTSCOS
value|0x40
end_define

begin_define
define|#
directive|define
name|IOPR_DCDCOS
value|0x80
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	IO port configuration register.  */
end_comment

begin_define
define|#
directive|define
name|IOPCR_SETCTS
value|0x00
end_define

begin_define
define|#
directive|define
name|IOPCR_SETDTR
value|0x04
end_define

begin_define
define|#
directive|define
name|IOPCR_SETRTS
value|0x10
end_define

begin_define
define|#
directive|define
name|IOPCR_SETDCD
value|0x00
end_define

begin_define
define|#
directive|define
name|IOPCR_SETSIGS
value|(IOPCR_SETRTS | IOPCR_SETRTS | IOPCR_SETDTR | IOPCR_SETDCD)
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	General purpose output select register.  */
end_comment

begin_define
define|#
directive|define
name|GPORS_TXC1XA
value|0x08
end_define

begin_define
define|#
directive|define
name|GPORS_TXC16XA
value|0x09
end_define

begin_define
define|#
directive|define
name|GPORS_RXC16XA
value|0x0a
end_define

begin_define
define|#
directive|define
name|GPORS_TXC16XB
value|0x0b
end_define

begin_define
define|#
directive|define
name|GPORS_GPOR3
value|0x0c
end_define

begin_define
define|#
directive|define
name|GPORS_GPOR2
value|0x0d
end_define

begin_define
define|#
directive|define
name|GPORS_GPOR1
value|0x0e
end_define

begin_define
define|#
directive|define
name|GPORS_GPOR0
value|0x0f
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	General purpose output register.  */
end_comment

begin_define
define|#
directive|define
name|GPOR_0
value|0x01
end_define

begin_define
define|#
directive|define
name|GPOR_1
value|0x02
end_define

begin_define
define|#
directive|define
name|GPOR_2
value|0x04
end_define

begin_define
define|#
directive|define
name|GPOR_3
value|0x08
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	General purpose output clock register.  */
end_comment

begin_define
define|#
directive|define
name|GPORC_0NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GPORC_0GIN0
value|0x01
end_define

begin_define
define|#
directive|define
name|GPORC_0GIN1
value|0x02
end_define

begin_define
define|#
directive|define
name|GPORC_0IO3A
value|0x02
end_define

begin_define
define|#
directive|define
name|GPORC_1NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GPORC_1GIN0
value|0x04
end_define

begin_define
define|#
directive|define
name|GPORC_1GIN1
value|0x08
end_define

begin_define
define|#
directive|define
name|GPORC_1IO3C
value|0x0c
end_define

begin_define
define|#
directive|define
name|GPORC_2NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GPORC_2GIN0
value|0x10
end_define

begin_define
define|#
directive|define
name|GPORC_2GIN1
value|0x20
end_define

begin_define
define|#
directive|define
name|GPORC_2IO3E
value|0x20
end_define

begin_define
define|#
directive|define
name|GPORC_3NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|GPORC_3GIN0
value|0x40
end_define

begin_define
define|#
directive|define
name|GPORC_3GIN1
value|0x80
end_define

begin_define
define|#
directive|define
name|GPORC_3IO3G
value|0xc0
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	General purpose output data register.  */
end_comment

begin_define
define|#
directive|define
name|GPOD_0MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|GPOD_0SET1
value|0x00
end_define

begin_define
define|#
directive|define
name|GPOD_0SET0
value|0x01
end_define

begin_define
define|#
directive|define
name|GPOD_0SETR0
value|0x02
end_define

begin_define
define|#
directive|define
name|GPOD_0SETIO3B
value|0x03
end_define

begin_define
define|#
directive|define
name|GPOD_1MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|GPOD_1SET1
value|0x00
end_define

begin_define
define|#
directive|define
name|GPOD_1SET0
value|0x04
end_define

begin_define
define|#
directive|define
name|GPOD_1SETR0
value|0x08
end_define

begin_define
define|#
directive|define
name|GPOD_1SETIO3D
value|0x0c
end_define

begin_define
define|#
directive|define
name|GPOD_2MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|GPOD_2SET1
value|0x00
end_define

begin_define
define|#
directive|define
name|GPOD_2SET0
value|0x10
end_define

begin_define
define|#
directive|define
name|GPOD_2SETR0
value|0x20
end_define

begin_define
define|#
directive|define
name|GPOD_2SETIO3F
value|0x30
end_define

begin_define
define|#
directive|define
name|GPOD_3MASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|GPOD_3SET1
value|0x00
end_define

begin_define
define|#
directive|define
name|GPOD_3SET0
value|0x40
end_define

begin_define
define|#
directive|define
name|GPOD_3SETR0
value|0x80
end_define

begin_define
define|#
directive|define
name|GPOD_3SETIO3H
value|0xc0
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

