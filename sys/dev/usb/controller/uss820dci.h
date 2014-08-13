begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Hans Petter Selasky<hselasky@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USS820_DCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_USS820_DCI_H_
end_define

begin_define
define|#
directive|define
name|USS820_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_define
define|#
directive|define
name|USS820_EP_MAX
value|8
end_define

begin_comment
comment|/* maximum number of endpoints */
end_comment

begin_define
define|#
directive|define
name|USS820_TXDAT
value|0x00
end_define

begin_comment
comment|/* Transmit FIFO data */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCNTL
value|0x01
end_define

begin_comment
comment|/* Transmit FIFO byte count low */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCNTL_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|USS820_TXCNTH
value|0x02
end_define

begin_comment
comment|/* Transmit FIFO byte count high */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCNTH_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|USS820_TXCNTH_UNUSED
value|0xFC
end_define

begin_define
define|#
directive|define
name|USS820_TXCON
value|0x03
end_define

begin_comment
comment|/* USB transmit FIFO control */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCON_REVRP
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_ADVRM
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_ATM
value|0x04
end_define

begin_comment
comment|/* Automatic Transmit Management */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCON_TXISO
value|0x08
end_define

begin_comment
comment|/* Transmit Isochronous Data */
end_comment

begin_define
define|#
directive|define
name|USS820_TXCON_UNUSED
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_FFSZ_16_64
value|0x00
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_FFSZ_64_256
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_FFSZ_8_512
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_FFSZ_32_1024
value|0x60
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_FFSZ_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|USS820_TXCON_TXCLR
value|0x80
end_define

begin_comment
comment|/* Transmit FIFO clear */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG
value|0x04
end_define

begin_comment
comment|/* Transmit FIFO flag (Read Only) */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG_TXOVF
value|0x01
end_define

begin_comment
comment|/* TX overrun */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG_TXURF
value|0x02
end_define

begin_comment
comment|/* TX underrun */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG_TXFULL
value|0x04
end_define

begin_comment
comment|/* TX full */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG_TXEMP
value|0x08
end_define

begin_comment
comment|/* TX empty */
end_comment

begin_define
define|#
directive|define
name|USS820_TXFLG_UNUSED
value|0x30
end_define

begin_define
define|#
directive|define
name|USS820_TXFLG_TXFIF0
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_TXFLG_TXFIF1
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_RXDAT
value|0x05
end_define

begin_comment
comment|/* Receive FIFO data */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCNTL
value|0x06
end_define

begin_comment
comment|/* Receive FIFO byte count low */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCNTL_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|USS820_RXCNTH
value|0x07
end_define

begin_comment
comment|/* Receive FIFO byte count high */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCNTH_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|USS820_RXCNTH_UNUSED
value|0xFC
end_define

begin_define
define|#
directive|define
name|USS820_RXCON
value|0x08
end_define

begin_comment
comment|/* Receive FIFO control */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCON_REVWP
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_ADVWM
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_ARM
value|0x04
end_define

begin_comment
comment|/* Auto Receive Management */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCON_RXISO
value|0x08
end_define

begin_comment
comment|/* Receive Isochronous Data */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCON_RXFFRC
value|0x10
end_define

begin_comment
comment|/* FIFO Read Complete */
end_comment

begin_define
define|#
directive|define
name|USS820_RXCON_FFSZ_16_64
value|0x00
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_FFSZ_64_256
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_FFSZ_8_512
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_FFSZ_32_1024
value|0x60
end_define

begin_define
define|#
directive|define
name|USS820_RXCON_RXCLR
value|0x80
end_define

begin_comment
comment|/* Receive FIFO clear */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG
value|0x09
end_define

begin_comment
comment|/* Receive FIFO flag (Read Only) */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_RXOVF
value|0x01
end_define

begin_comment
comment|/* RX overflow */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_RXURF
value|0x02
end_define

begin_comment
comment|/* RX underflow */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_RXFULL
value|0x04
end_define

begin_comment
comment|/* RX full */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_RXEMP
value|0x08
end_define

begin_comment
comment|/* RX empty */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_RXFLUSH
value|0x10
end_define

begin_comment
comment|/* RX flush */
end_comment

begin_define
define|#
directive|define
name|USS820_RXFLG_UNUSED
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_RXFLG_RXFIF0
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_RXFLG_RXFIF1
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_EPINDEX
value|0x0a
end_define

begin_comment
comment|/* Endpoint index selection */
end_comment

begin_define
define|#
directive|define
name|USS820_EPINDEX_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|USS820_EPINDEX_UNUSED
value|0xF8
end_define

begin_define
define|#
directive|define
name|USS820_EPCON
value|0x0b
end_define

begin_comment
comment|/* Endpoint control */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_TXEPEN
value|0x01
end_define

begin_comment
comment|/* Transmit Endpoint Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_TXOE
value|0x02
end_define

begin_comment
comment|/* Transmit Output Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_RXEPEN
value|0x04
end_define

begin_comment
comment|/* Receive Endpoint Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_RXIE
value|0x08
end_define

begin_comment
comment|/* Receive Input Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_RXSPM
value|0x10
end_define

begin_comment
comment|/* Receive Single-Packet Mode */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_CTLEP
value|0x20
end_define

begin_comment
comment|/* Control Endpoint */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_TXSTL
value|0x40
end_define

begin_comment
comment|/* Stall Transmit Endpoint */
end_comment

begin_define
define|#
directive|define
name|USS820_EPCON_RXSTL
value|0x80
end_define

begin_comment
comment|/* Stall Receive Endpoint */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT
value|0x0c
end_define

begin_comment
comment|/* Transmit status */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXACK
value|0x01
end_define

begin_comment
comment|/* Transmit Acknowledge */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXERR
value|0x02
end_define

begin_comment
comment|/* Transmit Error */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXVOID
value|0x04
end_define

begin_comment
comment|/* Transmit Void */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXSOVW
value|0x08
end_define

begin_comment
comment|/* Transmit Data Sequence Overwrite 					 * Bit */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXFLUSH
value|0x10
end_define

begin_comment
comment|/* Transmit FIFO Packet Flushed */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXNAKE
value|0x20
end_define

begin_comment
comment|/* Transmit NAK Mode Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXDSAM
value|0x40
end_define

begin_comment
comment|/* Transmit Data-Set-Available Mode */
end_comment

begin_define
define|#
directive|define
name|USS820_TXSTAT_TXSEQ
value|0x80
end_define

begin_comment
comment|/* Transmitter Current Sequence Bit */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT
value|0x0d
end_define

begin_comment
comment|/* Receive status */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXACK
value|0x01
end_define

begin_comment
comment|/* Receive Acknowledge */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXERR
value|0x02
end_define

begin_comment
comment|/* Receive Error */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXVOID
value|0x04
end_define

begin_comment
comment|/* Receive Void */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXSOVW
value|0x08
end_define

begin_comment
comment|/* Receive Data Sequence Overwrite Bit */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_EDOVW
value|0x10
end_define

begin_comment
comment|/* End Overwrite Flag */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_STOVW
value|0x20
end_define

begin_comment
comment|/* Start Overwrite Flag */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXSETUP
value|0x40
end_define

begin_comment
comment|/* Received SETUP token */
end_comment

begin_define
define|#
directive|define
name|USS820_RXSTAT_RXSEQ
value|0x80
end_define

begin_comment
comment|/* Receiver Endpoint Sequence Bit */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFL
value|0x0e
end_define

begin_comment
comment|/* Start Of Frame counter low */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFL_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|USS820_SOFH
value|0x0f
end_define

begin_comment
comment|/* Start Of Frame counter high */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFH_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|USS820_SOFH_SOFDIS
value|0x08
end_define

begin_comment
comment|/* SOF Pin Output Disable */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFH_FTLOCK
value|0x10
end_define

begin_comment
comment|/* Frame Timer Lock */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFH_SOFIE
value|0x20
end_define

begin_comment
comment|/* SOF Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFH_ASOF
value|0x40
end_define

begin_comment
comment|/* Any Start of Frame */
end_comment

begin_define
define|#
directive|define
name|USS820_SOFH_SOFACK
value|0x80
end_define

begin_comment
comment|/* SOF Token Received Without Error */
end_comment

begin_define
define|#
directive|define
name|USS820_FADDR
value|0x10
end_define

begin_comment
comment|/* Function Address */
end_comment

begin_define
define|#
directive|define
name|USS820_FADDR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|USS820_FADDR_UNUSED
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_SCR
value|0x11
end_define

begin_comment
comment|/* System Control */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_UNUSED
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_SCR_T_IRQ
value|0x02
end_define

begin_comment
comment|/* Global Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_IRQLVL
value|0x04
end_define

begin_comment
comment|/* Interrupt Mode */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_SRESET
value|0x08
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_IE_RESET
value|0x10
end_define

begin_comment
comment|/* Enable Reset Interrupt */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_IE_SUSP
value|0x20
end_define

begin_comment
comment|/* Enable Suspend Interrupt */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_RWUPE
value|0x40
end_define

begin_comment
comment|/* Enable Remote Wake-Up Feature */
end_comment

begin_define
define|#
directive|define
name|USS820_SCR_IRQPOL
value|0x80
end_define

begin_comment
comment|/* IRQ polarity */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR
value|0x12
end_define

begin_comment
comment|/* System Status */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_RESET
value|0x01
end_define

begin_comment
comment|/* Reset Condition Detected on USB 					 * cable */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_SUSPEND
value|0x02
end_define

begin_comment
comment|/* Suspend Detected */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_RESUME
value|0x04
end_define

begin_comment
comment|/* Resume Detected */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_SUSPDIS
value|0x08
end_define

begin_comment
comment|/* Suspend Disable */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_SUSPPO
value|0x10
end_define

begin_comment
comment|/* Suspend Power Off */
end_comment

begin_define
define|#
directive|define
name|USS820_SSR_UNUSED
value|0xE0
end_define

begin_define
define|#
directive|define
name|USS820_UNK0
value|0x13
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|USS820_UNK0_UNUSED
value|0xFF
end_define

begin_define
define|#
directive|define
name|USS820_SBI
value|0x14
end_define

begin_comment
comment|/* Serial bus interrupt low */
end_comment

begin_define
define|#
directive|define
name|USS820_SBI_FTXD0
value|0x01
end_define

begin_comment
comment|/* Function Transmit Done, EP 0 */
end_comment

begin_define
define|#
directive|define
name|USS820_SBI_FRXD0
value|0x02
end_define

begin_comment
comment|/* Function Receive Done, EP 0 */
end_comment

begin_define
define|#
directive|define
name|USS820_SBI_FTXD1
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_SBI_FRXD1
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_SBI_FTXD2
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_SBI_FRXD2
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_SBI_FTXD3
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_SBI_FRXD3
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_SBI1
value|0x15
end_define

begin_comment
comment|/* Serial bus interrupt high */
end_comment

begin_define
define|#
directive|define
name|USS820_SBI1_FTXD4
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FRXD4
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FTXD5
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FRXD5
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FTXD6
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FRXD6
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FTXD7
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_SBI1_FRXD7
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_SBIE
value|0x16
end_define

begin_comment
comment|/* Serial bus interrupt enable low */
end_comment

begin_define
define|#
directive|define
name|USS820_SBIE_FTXIE0
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FRXIE0
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FTXIE1
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FRXIE1
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FTXIE2
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FRXIE2
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FTXIE3
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_SBIE_FRXIE3
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1
value|0x17
end_define

begin_comment
comment|/* Serial bus interrupt enable high */
end_comment

begin_define
define|#
directive|define
name|USS820_SBIE1_FTXIE4
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FRXIE4
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FTXIE5
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FRXIE5
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FTXIE6
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FRXIE6
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FTXIE7
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_SBIE1_FRXIE7
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_REV
value|0x18
end_define

begin_comment
comment|/* Hardware revision */
end_comment

begin_define
define|#
directive|define
name|USS820_REV_MIN
value|0x0F
end_define

begin_define
define|#
directive|define
name|USS820_REV_MAJ
value|0xF0
end_define

begin_define
define|#
directive|define
name|USS820_LOCK
value|0x19
end_define

begin_comment
comment|/* Suspend power-off locking */
end_comment

begin_define
define|#
directive|define
name|USS820_LOCK_UNLOCKED
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_LOCK_UNUSED
value|0xFE
end_define

begin_define
define|#
directive|define
name|USS820_PEND
value|0x1a
end_define

begin_comment
comment|/* Pend hardware status update */
end_comment

begin_define
define|#
directive|define
name|USS820_PEND_PEND
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_PEND_UNUSED
value|0xFE
end_define

begin_define
define|#
directive|define
name|USS820_SCRATCH
value|0x1b
end_define

begin_comment
comment|/* Scratch firmware information */
end_comment

begin_define
define|#
directive|define
name|USS820_SCRATCH_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|USS820_SCRATCH_IE_RESUME
value|0x80
end_define

begin_comment
comment|/* Enable Resume Interrupt */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR
value|0x1c
end_define

begin_comment
comment|/* Miscellaneous control and status */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_DPEN
value|0x01
end_define

begin_comment
comment|/* DPLS Pull-Up Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_SUSPLOE
value|0x02
end_define

begin_comment
comment|/* Suspend Lock Out Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_BDFEAT
value|0x04
end_define

begin_comment
comment|/* Board Feature Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_FEAT
value|0x08
end_define

begin_comment
comment|/* Feature Enable */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_PKGID
value|0x10
end_define

begin_comment
comment|/* Package Identification */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_SUSPS
value|0x20
end_define

begin_comment
comment|/* Suspend Status */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_INIT
value|0x40
end_define

begin_comment
comment|/* Device Initialized */
end_comment

begin_define
define|#
directive|define
name|USS820_MCSR_RWUPR
value|0x80
end_define

begin_comment
comment|/* Remote Wakeup-Up Remember */
end_comment

begin_define
define|#
directive|define
name|USS820_DSAV
value|0x1d
end_define

begin_comment
comment|/* Data set available low (Read Only) */
end_comment

begin_define
define|#
directive|define
name|USS820_DSAV_TXAV0
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_RXAV0
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_TXAV1
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_RXAV1
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_TXAV2
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_RXAV2
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_TXAV3
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_DSAV_RXAV3
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1
value|0x1e
end_define

begin_comment
comment|/* Data set available high */
end_comment

begin_define
define|#
directive|define
name|USS820_DSAV1_TXAV4
value|0x01
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_RXAV4
value|0x02
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_TXAV5
value|0x04
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_RXAV5
value|0x08
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_TXAV6
value|0x10
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_RXAV6
value|0x20
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_TXAV7
value|0x40
end_define

begin_define
define|#
directive|define
name|USS820_DSAV1_RXAV7
value|0x80
end_define

begin_define
define|#
directive|define
name|USS820_UNK1
value|0x1f
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|USS820_UNK1_UNKNOWN
value|0xFF
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USS820_REG_STRIDE
end_ifndef

begin_define
define|#
directive|define
name|USS820_REG_STRIDE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USS820_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (reg) * USS820_REG_STRIDE)
end_define

begin_define
define|#
directive|define
name|USS820_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (reg) * USS820_REG_STRIDE, (data))
end_define

begin_struct_decl
struct_decl|struct
name|uss820dci_td
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uss820dci_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|uss820dci_cmd_t
function_decl|)
parameter_list|(
name|struct
name|uss820dci_softc
modifier|*
parameter_list|,
name|struct
name|uss820dci_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|uss820dci_td
block|{
name|struct
name|uss820dci_td
modifier|*
name|obj_next
decl_stmt|;
name|uss820dci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|remainder
decl_stmt|;
name|uint16_t
name|max_packet_size
decl_stmt|;
name|uint8_t
name|ep_index
decl_stmt|;
name|uint8_t
name|error
range|:
literal|1
decl_stmt|;
name|uint8_t
name|alt_next
range|:
literal|1
decl_stmt|;
name|uint8_t
name|short_pkt
range|:
literal|1
decl_stmt|;
name|uint8_t
name|support_multi_buffer
range|:
literal|1
decl_stmt|;
name|uint8_t
name|did_stall
range|:
literal|1
decl_stmt|;
name|uint8_t
name|did_enable
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uss820_std_temp
block|{
name|uss820dci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|uss820dci_td
modifier|*
name|td
decl_stmt|;
name|struct
name|uss820dci_td
modifier|*
name|td_next
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint8_t
name|short_pkt
decl_stmt|;
comment|/*          * short_pkt = 0: transfer should be short terminated          * short_pkt = 1: transfer should not be short terminated          */
name|uint8_t
name|setup_alt_next
decl_stmt|;
name|uint8_t
name|did_stall
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uss820dci_config_desc
block|{
name|struct
name|usb_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|uss820_hub_temp
block|{
name|uWord
name|wValue
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|uss820_flags
block|{
name|uint8_t
name|change_connect
range|:
literal|1
decl_stmt|;
name|uint8_t
name|change_suspend
range|:
literal|1
decl_stmt|;
name|uint8_t
name|status_suspend
range|:
literal|1
decl_stmt|;
comment|/* set if suspended */
name|uint8_t
name|status_vbus
range|:
literal|1
decl_stmt|;
comment|/* set if present */
name|uint8_t
name|status_bus_reset
range|:
literal|1
decl_stmt|;
comment|/* set if reset complete */
name|uint8_t
name|clocks_off
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_enabled
range|:
literal|1
decl_stmt|;
name|uint8_t
name|d_pulled_up
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mcsr_feat
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uss820dci_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|uss820_hub_temp
name|sc_hub_temp
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|USS820_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|uint32_t
name|sc_xfer_complete
decl_stmt|;
name|uint8_t
name|sc_rt_addr
decl_stmt|;
comment|/* root HUB address */
name|uint8_t
name|sc_dv_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root HUB config */
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|uss820_flags
name|sc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|usb_error_t
name|uss820dci_init
parameter_list|(
name|struct
name|uss820dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uss820dci_uninit
parameter_list|(
name|struct
name|uss820dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_filter_t
name|uss820dci_filter_interrupt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_intr_t
name|uss820dci_interrupt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USS820_DCI_H_ */
end_comment

end_unit

