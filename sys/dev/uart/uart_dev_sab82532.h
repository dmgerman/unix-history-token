begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sab82532reg.h,v 1.2 2002/04/08 17:49:42 jason Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jason L. Wright  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for SAB82532 based on "Enhanced Serial Communication  * Controller ESCC2 Version 3.2 User's Manual 07.96" from:  * http://www.infineon.com  */
end_comment

begin_define
define|#
directive|define
name|SAB_NCHAN
value|2
end_define

begin_comment
comment|/* number of channels */
end_comment

begin_define
define|#
directive|define
name|SAB_CHANLEN
value|0x40
end_define

begin_comment
comment|/* length of channel register set */
end_comment

begin_define
define|#
directive|define
name|SAB_CHAN_A
value|0x00
end_define

begin_comment
comment|/* channel A register offset */
end_comment

begin_define
define|#
directive|define
name|SAB_CHAN_B
value|0x40
end_define

begin_comment
comment|/* channel B register offset */
end_comment

begin_define
define|#
directive|define
name|SAB_RFIFO
value|0x00
end_define

begin_comment
comment|/* r: rx fifo */
end_comment

begin_define
define|#
directive|define
name|SAB_XFIFO
value|0x00
end_define

begin_comment
comment|/* w: tx fifo */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR
value|0x20
end_define

begin_comment
comment|/* r: status register */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR
value|0x20
end_define

begin_comment
comment|/* w: command register */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE
value|0x22
end_define

begin_comment
comment|/* rw: mode register */
end_comment

begin_define
define|#
directive|define
name|SAB_TIMR
value|0x23
end_define

begin_comment
comment|/* rw: timer register */
end_comment

begin_define
define|#
directive|define
name|SAB_XON
value|0x24
end_define

begin_comment
comment|/* rw: xon character */
end_comment

begin_define
define|#
directive|define
name|SAB_XOFF
value|0x25
end_define

begin_comment
comment|/* rw: xoff character */
end_comment

begin_define
define|#
directive|define
name|SAB_TCR
value|0x26
end_define

begin_comment
comment|/* rw: termination character */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO
value|0x27
end_define

begin_comment
comment|/* rw: data format */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC
value|0x28
end_define

begin_comment
comment|/* rw: rfifo control register */
end_comment

begin_define
define|#
directive|define
name|SAB_RBCL
value|0x2a
end_define

begin_comment
comment|/* r: rx byte count low */
end_comment

begin_define
define|#
directive|define
name|SAB_TBCL
value|0x2a
end_define

begin_comment
comment|/* w: tx byte count low */
end_comment

begin_define
define|#
directive|define
name|SAB_RBCH
value|0x2b
end_define

begin_comment
comment|/* r: rx byte count high */
end_comment

begin_define
define|#
directive|define
name|SAB_XBCH
value|0x2b
end_define

begin_comment
comment|/* w: tx byte count high */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0
value|0x2c
end_define

begin_comment
comment|/* rw: channel configuration register 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1
value|0x2d
end_define

begin_comment
comment|/* rw: channel configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2
value|0x2e
end_define

begin_comment
comment|/* rw: channel configuration register 2 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR3
value|0x2f
end_define

begin_comment
comment|/* rw: channel configuration register 3 */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAX
value|0x30
end_define

begin_comment
comment|/* w: time-slot assignment register tx */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAR
value|0x31
end_define

begin_comment
comment|/* w: time-slot assignment register rx */
end_comment

begin_define
define|#
directive|define
name|SAB_XCCR
value|0x32
end_define

begin_comment
comment|/* w: tx channel capacity register */
end_comment

begin_define
define|#
directive|define
name|SAB_RCCR
value|0x33
end_define

begin_comment
comment|/* w: receive channel capacity register */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR
value|0x34
end_define

begin_comment
comment|/* r: version status */
end_comment

begin_define
define|#
directive|define
name|SAB_BGR
value|0x34
end_define

begin_comment
comment|/* w: baud rate generator */
end_comment

begin_define
define|#
directive|define
name|SAB_TIC
value|0x35
end_define

begin_comment
comment|/* w: transmit immediate character */
end_comment

begin_define
define|#
directive|define
name|SAB_MXN
value|0x36
end_define

begin_comment
comment|/* w: mask xon character */
end_comment

begin_define
define|#
directive|define
name|SAB_MXF
value|0x37
end_define

begin_comment
comment|/* w: mask xoff character */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS
value|0x38
end_define

begin_comment
comment|/* r: global interrupt status */
end_comment

begin_define
define|#
directive|define
name|SAB_IVA
value|0x38
end_define

begin_comment
comment|/* w: interrupt vector address */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC
value|0x39
end_define

begin_comment
comment|/* rw: interrupt port configuration */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0
value|0x3a
end_define

begin_comment
comment|/* r: interrupt status 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0
value|0x3a
end_define

begin_comment
comment|/* w: interrupt mask 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1
value|0x3b
end_define

begin_comment
comment|/* r: interrupt status 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1
value|0x3b
end_define

begin_comment
comment|/* w: interrupt mask 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR
value|0x3c
end_define

begin_comment
comment|/* rw: port value register */
end_comment

begin_define
define|#
directive|define
name|SAB_PIS
value|0x3d
end_define

begin_comment
comment|/* r: port interrupt status */
end_comment

begin_define
define|#
directive|define
name|SAB_PIM
value|0x3d
end_define

begin_comment
comment|/* w: port interrupt mask */
end_comment

begin_define
define|#
directive|define
name|SAB_PCR
value|0x3e
end_define

begin_comment
comment|/* w: port configuration register */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR4
value|0x3f
end_define

begin_comment
comment|/* rw: channel configuration register 4 */
end_comment

begin_comment
comment|/* SAB_STAR: status register */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_XDOV
value|0x80
end_define

begin_comment
comment|/* transmit data overflow */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_XFW
value|0x40
end_define

begin_comment
comment|/* transmit fifo write enable */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_RFNE
value|0x20
end_define

begin_comment
comment|/* rfifo not empty */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_FCS
value|0x10
end_define

begin_comment
comment|/* flow control status */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_TEC
value|0x08
end_define

begin_comment
comment|/* tx immediate char is executing */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_CEC
value|0x04
end_define

begin_comment
comment|/* command is executing */
end_comment

begin_define
define|#
directive|define
name|SAB_STAR_CTS
value|0x02
end_define

begin_comment
comment|/* cts status: 0:inactive/high,1:active/low */
end_comment

begin_comment
comment|/* SAB_CMDR: command register */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_RMC
value|0x80
end_define

begin_comment
comment|/* receive message complete */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_RRES
value|0x40
end_define

begin_comment
comment|/* receiver reset */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_RFRD
value|0x20
end_define

begin_comment
comment|/* receive fifo read enable */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_STI
value|0x10
end_define

begin_comment
comment|/* start timer */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_XF
value|0x08
end_define

begin_comment
comment|/* transmit frame */
end_comment

begin_define
define|#
directive|define
name|SAB_CMDR_XRES
value|0x01
end_define

begin_comment
comment|/* transmit reset */
end_comment

begin_comment
comment|/* SAB_MODE: mode register */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_FRTS
value|0x40
end_define

begin_comment
comment|/* flow control using rts */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_FCTS
value|0x20
end_define

begin_comment
comment|/* flow control using cts */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_FLON
value|0x10
end_define

begin_comment
comment|/* flow control on */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_RAC
value|0x08
end_define

begin_comment
comment|/* receiver active */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_RTS
value|0x04
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_TRS
value|0x02
end_define

begin_comment
comment|/* timer resolution */
end_comment

begin_define
define|#
directive|define
name|SAB_MODE_TLP
value|0x01
end_define

begin_comment
comment|/* test loop */
end_comment

begin_comment
comment|/* SAB_TIMR: timer register */
end_comment

begin_define
define|#
directive|define
name|SAB_TIMR_CNT
value|0xe0
end_define

begin_comment
comment|/* count mask */
end_comment

begin_define
define|#
directive|define
name|SAB_TIMR_VAL
value|0x1f
end_define

begin_comment
comment|/* value mask */
end_comment

begin_comment
comment|/* SAB_DAFO: data format */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_XBRK
value|0x40
end_define

begin_comment
comment|/* transmit break */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_STOP
value|0x20
end_define

begin_comment
comment|/* stop bit: 0:1 bit, 1:2 bits */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_PAR1
value|0x10
end_define

begin_comment
comment|/* parity 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_PAR0
value|0x08
end_define

begin_comment
comment|/* parity 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_PARE
value|0x04
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_CHL1
value|0x02
end_define

begin_comment
comment|/* character length 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_CHL0
value|0x01
end_define

begin_comment
comment|/* character length 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_DAFO_CHL_CSIZE
value|(SAB_DAFO_CHL1|SAB_DAFO_CHL0)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_CHL_CS5
value|(SAB_DAFO_CHL1|SAB_DAFO_CHL0)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_CHL_CS6
value|(SAB_DAFO_CHL1)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_CHL_CS7
value|(SAB_DAFO_CHL0)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_CHL_CS8
value|(0)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PARMASK
value|(SAB_DAFO_PAR1|SAB_DAFO_PAR0|SAB_DAFO_PARE)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PAR_MARK
value|(SAB_DAFO_PAR1|SAB_DAFO_PAR0|SAB_DAFO_PARE)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PAR_EVEN
value|(SAB_DAFO_PAR1|SAB_DAFO_PARE)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PAR_ODD
value|(SAB_DAFO_PAR0|SAB_DAFO_PARE)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PAR_SPACE
value|(SAB_DAFO_PARE)
end_define

begin_define
define|#
directive|define
name|SAB_DAFO_PAR_NONE
value|(0)
end_define

begin_comment
comment|/* SAB_RFC: rfifo control register */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_DPS
value|0x40
end_define

begin_comment
comment|/* disable parity storage */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_DXS
value|0x20
end_define

begin_comment
comment|/* disable storage of xon/xoff characters */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_RFDF
value|0x10
end_define

begin_comment
comment|/* rfifo data format: 0 data,1 data+stat */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_RFTH1
value|0x08
end_define

begin_comment
comment|/* rfifo threshold level 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_RFTH0
value|0x04
end_define

begin_comment
comment|/* rfifo threshold level 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_TCDE
value|0x01
end_define

begin_comment
comment|/* termination character detection enable */
end_comment

begin_define
define|#
directive|define
name|SAB_RFC_RFTH_MASK
value|(SAB_RFC_RFTH1|SAB_RFC_RFTH0)
end_define

begin_define
define|#
directive|define
name|SAB_RFC_RFTH_32CHAR
value|(SAB_RFC_RFTH1|SAB_RFC_RFTH0)
end_define

begin_define
define|#
directive|define
name|SAB_RFC_RFTH_16CHAR
value|(SAB_RFC_RFTH1)
end_define

begin_define
define|#
directive|define
name|SAB_RFC_RFTH_4CHAR
value|(SAB_RFC_RFTH0)
end_define

begin_define
define|#
directive|define
name|SAB_RFC_RFTH_1CHAR
value|(0)
end_define

begin_comment
comment|/* SAB_RBCH: received byte count high */
end_comment

begin_define
define|#
directive|define
name|SAB_RBCH_DMA
value|0x80
end_define

begin_comment
comment|/* read back of XBCH DMA bit */
end_comment

begin_define
define|#
directive|define
name|SAB_RBCH_CAS
value|0x20
end_define

begin_comment
comment|/* read back of XBCH CAS bit */
end_comment

begin_define
define|#
directive|define
name|SAB_RBCH_CNT
value|0x0f
end_define

begin_comment
comment|/* ms 4 bits of rx byte count (not used) */
end_comment

begin_comment
comment|/* SAB_XBCH: transmit byte count high */
end_comment

begin_define
define|#
directive|define
name|SAB_XBCH_DMA
value|0x80
end_define

begin_comment
comment|/* dma mode: 1:dma, 0:interrupt */
end_comment

begin_define
define|#
directive|define
name|SAB_XBCH_CAS
value|0x20
end_define

begin_comment
comment|/* carrier detect auto-start */
end_comment

begin_define
define|#
directive|define
name|SAB_XBCH_XC
value|0x10
end_define

begin_comment
comment|/* transmit continuously */
end_comment

begin_define
define|#
directive|define
name|SAB_XBCH_CNT
value|0x0f
end_define

begin_comment
comment|/* ms 4 bits of tx byte count */
end_comment

begin_comment
comment|/* SAB_CCR0: channel configuration register 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_PU
value|0x80
end_define

begin_comment
comment|/* 0:power-down, 1:power-up */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_MCE
value|0x40
end_define

begin_comment
comment|/* master clock enable */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SC2
value|0x10
end_define

begin_comment
comment|/* serial port config 2, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SC1
value|0x08
end_define

begin_comment
comment|/* serial port config 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SC0
value|0x04
end_define

begin_comment
comment|/* serial port config 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SM1
value|0x02
end_define

begin_comment
comment|/* serial mode 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SM0
value|0x01
end_define

begin_comment
comment|/* serial mode 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR0_SC_MASK
value|(SAB_CCR0_SC2|SAB_CCR0_SC1|SAB_CCR0_SC0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SC_NRZ
value|(0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SC_NRZI
value|(SAB_CCR0_SC1)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SC_FM0
value|(SAB_CCR0_SC2)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SC_FM1
value|(SAB_CCR0_SC2|SAB_CCR0_SC0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SC_MANCHESTER
value|(SAB_CCR0_SC2|SAB_CCR0_SC1)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SM_MASK
value|(SAB_CCR0_SM1|SAB_CCR0_SM0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SM_DLC
value|(0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SM_DLCLOOP
value|(SAB_CCR0_SM0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SM_BISYNC
value|(SAB_CCR0_SM1)
end_define

begin_define
define|#
directive|define
name|SAB_CCR0_SM_ASYNC
value|(SAB_CCR0_SM1|SAB_CCR0_SM0)
end_define

begin_comment
comment|/* SAB_CCR1: channel configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_ODS
value|0x10
end_define

begin_comment
comment|/* Output driver select:1:pushpull,0:odrain */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_BCR
value|0x08
end_define

begin_comment
comment|/* bit clock rate: 1:async, 0:isochronous */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_CM2
value|0x04
end_define

begin_comment
comment|/* clock mode 2, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_CM1
value|0x02
end_define

begin_comment
comment|/* clock mode 1, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_CM0
value|0x01
end_define

begin_comment
comment|/* clock mode 0, see below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR1_CM_MASK
value|(SAB_CCR1_CM2|SAB_CCR1_CM1|SAB_CCR1_CM0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR1_CM_7
value|(SAB_CCR1_CM2|SAB_CCR1_CM1|SAB_CCR1_CM0)
end_define

begin_comment
comment|/* SAB_CCR2: channel configuration register 2, depends on clock mode above */
end_comment

begin_comment
comment|/* clock mode 0a, 1, 4, 5 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_SOC1
value|0x80
end_define

begin_comment
comment|/* special output 1, below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_SOC0
value|0x40
end_define

begin_comment
comment|/* special output 0, below */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_SOC_MASK
value|(SAB_CCR2_SOC1|SAB_CCR2_SOC0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR2_SOC_RTSHIGH
value|(SAB_CCR2_SOC1)
end_define

begin_define
define|#
directive|define
name|SAB_CCR2_SOC_RTSNORM
value|(0)
end_define

begin_define
define|#
directive|define
name|SAB_CCR2_SOC_RTSRX
value|(SAB_CCR2_SOC1|SAB_CCR2_SOC0)
end_define

begin_comment
comment|/* clock mode 0b, 2, 3, 6, 7 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_BR9
value|0x80
end_define

begin_comment
comment|/* baud rate bit 9 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_BR8
value|0x40
end_define

begin_comment
comment|/* baud rate bit 8 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_BDF
value|0x20
end_define

begin_comment
comment|/* baud rate division factor: 0:1: 1:BRG */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_SSEL
value|0x10
end_define

begin_comment
comment|/* clock source select */
end_comment

begin_comment
comment|/* clock mode 5 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_XCS0
value|0x20
end_define

begin_comment
comment|/* tx clock shift, bit 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_RCS0
value|0x10
end_define

begin_comment
comment|/* rx clock shift, bit 0 */
end_comment

begin_comment
comment|/* clock mode 0b, 2, 3, 4, 5, 6, 7 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_TOE
value|0x08
end_define

begin_comment
comment|/* tx clock output enable */
end_comment

begin_comment
comment|/* clock mode 0a, 0b, 1, 2, 3, 4, 5, 6, 7 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_RWX
value|0x04
end_define

begin_comment
comment|/* read/write exchange (dma mode only) */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR2_DIV
value|0x01
end_define

begin_comment
comment|/* data inversion (nrz) */
end_comment

begin_comment
comment|/* SAB_CCR3: channel configuration register 3 (v2 or greater) */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR3_PSD
value|0x01
end_define

begin_comment
comment|/* dpll phase shift disable (nrz/nrzi) */
end_comment

begin_comment
comment|/* SAB_TSAX: time-slot assignment register transmit (clock mode 5 only) */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAX_TSNX
value|0xfc
end_define

begin_comment
comment|/* time-slot number transmit */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAX_XCS2
value|0x02
end_define

begin_comment
comment|/* transmit clock shift bit 2 */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAX_XCS1
value|0x01
end_define

begin_comment
comment|/* transmit clock shift bit 1 */
end_comment

begin_comment
comment|/* SAB_TSAR: time-slot assignment register receive (clock mode 5 only) */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAR_TSNR
value|0xfc
end_define

begin_comment
comment|/* time-slot number receive */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAR_RCS2
value|0x02
end_define

begin_comment
comment|/* receive clock shift bit 2 */
end_comment

begin_define
define|#
directive|define
name|SAB_TSAR_RCS1
value|0x01
end_define

begin_comment
comment|/* receive clock shift bit 1 */
end_comment

begin_comment
comment|/* SAB_VSTR: version status register */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_CD
value|0x80
end_define

begin_comment
comment|/* carrier detect status */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_DPLA
value|0x40
end_define

begin_comment
comment|/* dpll asynchronous */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_VMASK
value|0x0f
end_define

begin_comment
comment|/* chip version mask: */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_V_1
value|0x00
end_define

begin_comment
comment|/*   version 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_V_2
value|0x01
end_define

begin_comment
comment|/*   version 2 */
end_comment

begin_define
define|#
directive|define
name|SAB_VSTR_V_32
value|0x02
end_define

begin_comment
comment|/*   version 3.2 */
end_comment

begin_comment
comment|/* SAB_GIS: global interrupt status register */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS_PI
value|0x80
end_define

begin_comment
comment|/* universal port interrupt */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS_ISA1
value|0x08
end_define

begin_comment
comment|/* interrupt status a1 */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS_ISA0
value|0x04
end_define

begin_comment
comment|/* interrupt status a0 */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS_ISB1
value|0x02
end_define

begin_comment
comment|/* interrupt status b1 */
end_comment

begin_define
define|#
directive|define
name|SAB_GIS_ISB0
value|0x01
end_define

begin_comment
comment|/* interrupt status b0 */
end_comment

begin_comment
comment|/* SAB_IVA: interrupt vector address */
end_comment

begin_define
define|#
directive|define
name|SAB_IVA_MASK
value|0xf8
end_define

begin_comment
comment|/* interrupt vector address mask */
end_comment

begin_comment
comment|/* SAB_IPC: interrupt port configuration */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_VIS
value|0x80
end_define

begin_comment
comment|/* masked interrupt bits visible */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_SLAMASK
value|0x18
end_define

begin_comment
comment|/* slave address mask */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_CASM
value|0x04
end_define

begin_comment
comment|/* cascading mode */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_ICMASK
value|0x03
end_define

begin_comment
comment|/* port config mask: */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_ICOD
value|0x00
end_define

begin_comment
comment|/*   open drain output */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_ICPL
value|0x01
end_define

begin_comment
comment|/*   push/pull active low output */
end_comment

begin_define
define|#
directive|define
name|SAB_IPC_ICPH
value|0x03
end_define

begin_comment
comment|/*   push/pull active high output */
end_comment

begin_comment
comment|/* SAB_ISR0: interrupt status 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_TCD
value|0x80
end_define

begin_comment
comment|/* termination character detected */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_TIME
value|0x40
end_define

begin_comment
comment|/* time-out limit exceeded */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_PERR
value|0x20
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_FERR
value|0x10
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_PLLA
value|0x08
end_define

begin_comment
comment|/* dpll asynchronous */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_CDSC
value|0x04
end_define

begin_comment
comment|/* carrier detect status change */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_RFO
value|0x02
end_define

begin_comment
comment|/* rfifo overflow */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR0_RPF
value|0x01
end_define

begin_comment
comment|/* receive pool full */
end_comment

begin_comment
comment|/* SAB_ISR1: interrupt status 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_BRK
value|0x80
end_define

begin_comment
comment|/* break detected */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_BRKT
value|0x40
end_define

begin_comment
comment|/* break terminated */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_ALLS
value|0x20
end_define

begin_comment
comment|/* all sent */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_XOFF
value|0x10
end_define

begin_comment
comment|/* xoff detected */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_TIN
value|0x08
end_define

begin_comment
comment|/* timer interrupt */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_CSC
value|0x04
end_define

begin_comment
comment|/* clear to send status change */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_XON
value|0x02
end_define

begin_comment
comment|/* xon detected */
end_comment

begin_define
define|#
directive|define
name|SAB_ISR1_XPR
value|0x01
end_define

begin_comment
comment|/* transmit pool ready */
end_comment

begin_comment
comment|/* SAB_IMR0: interrupt mask 0 */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_TCD
value|0x80
end_define

begin_comment
comment|/* termination character detected */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_TIME
value|0x40
end_define

begin_comment
comment|/* time-out limit exceeded */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_PERR
value|0x20
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_FERR
value|0x10
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_PLLA
value|0x08
end_define

begin_comment
comment|/* dpll asynchronous */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_CDSC
value|0x04
end_define

begin_comment
comment|/* carrier detect status change */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_RFO
value|0x02
end_define

begin_comment
comment|/* rfifo overflow */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR0_RPF
value|0x01
end_define

begin_comment
comment|/* receive pool full */
end_comment

begin_comment
comment|/* SAB_ISR1: interrupt mask 1 */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_BRK
value|0x80
end_define

begin_comment
comment|/* break detected */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_BRKT
value|0x40
end_define

begin_comment
comment|/* break terminated */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_ALLS
value|0x20
end_define

begin_comment
comment|/* all sent */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_XDU
value|0x10
end_define

begin_comment
comment|/* xoff detected */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_TIN
value|0x08
end_define

begin_comment
comment|/* timer interrupt */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_CSC
value|0x04
end_define

begin_comment
comment|/* clear to send status change */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_XMR
value|0x02
end_define

begin_comment
comment|/* xon detected */
end_comment

begin_define
define|#
directive|define
name|SAB_IMR1_XPR
value|0x01
end_define

begin_comment
comment|/* transmit pool ready */
end_comment

begin_comment
comment|/* SAB_PVR: port value register */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR_DSR_A
value|0x01
end_define

begin_comment
comment|/* port A DSR */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR_DTR_A
value|0x02
end_define

begin_comment
comment|/* port A DTR */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR_DTR_B
value|0x04
end_define

begin_comment
comment|/* port B DTR */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR_DSR_B
value|0x08
end_define

begin_comment
comment|/* port B DSR */
end_comment

begin_define
define|#
directive|define
name|SAB_PVR_MAGIC
value|0x10
end_define

begin_comment
comment|/* dunno... */
end_comment

begin_comment
comment|/* SAB_CCR4: channel configuration register 4 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR4_MCK4
value|0x80
end_define

begin_comment
comment|/* master clock divide by 4 */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR4_EBRG
value|0x40
end_define

begin_comment
comment|/* enhanced baud rate generator mode */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR4_TST1
value|0x20
end_define

begin_comment
comment|/* test pin */
end_comment

begin_define
define|#
directive|define
name|SAB_CCR4_ICD
value|0x10
end_define

begin_comment
comment|/* invert polarity of carrier detect */
end_comment

begin_comment
comment|/* Receive status byte */
end_comment

begin_define
define|#
directive|define
name|SAB_RSTAT_PE
value|0x80
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|SAB_RSTAT_FE
value|0x40
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|SAB_RSTAT_PAR
value|0x01
end_define

begin_comment
comment|/* parity bit */
end_comment

end_unit

