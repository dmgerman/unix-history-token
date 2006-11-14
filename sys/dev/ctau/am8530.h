begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * AMD Am83C30 serial communication controller registers.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: am8530.h,v 1.1.2.2 2003/11/12 17:31:21 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Read/write registers.  */
end_comment

begin_define
define|#
directive|define
name|AM_IVR
value|2
end_define

begin_comment
comment|/* rw2 - interrupt vector register */
end_comment

begin_define
define|#
directive|define
name|AM_DAT
value|8
end_define

begin_comment
comment|/* rw8 - data buffer register */
end_comment

begin_define
define|#
directive|define
name|AM_TCL
value|12
end_define

begin_comment
comment|/* rw12 - time constant low */
end_comment

begin_define
define|#
directive|define
name|AM_TCH
value|13
end_define

begin_comment
comment|/* rw13 - time constant high */
end_comment

begin_define
define|#
directive|define
name|AM_SICR
value|15
end_define

begin_comment
comment|/* rw15 - status interrupt control reg */
end_comment

begin_comment
comment|/*  * Write only registers.  */
end_comment

begin_define
define|#
directive|define
name|AM_CR
value|0
end_define

begin_comment
comment|/* w0 - command register */
end_comment

begin_define
define|#
directive|define
name|AM_IMR
value|1
end_define

begin_comment
comment|/* w1 - interrupt mode register */
end_comment

begin_define
define|#
directive|define
name|AM_RCR
value|3
end_define

begin_comment
comment|/* w3 - receive control register */
end_comment

begin_define
define|#
directive|define
name|AM_PMR
value|4
end_define

begin_comment
comment|/* w4 - tx/rx parameters and modes reg */
end_comment

begin_define
define|#
directive|define
name|AM_TCR
value|5
end_define

begin_comment
comment|/* w5 - transmit control register */
end_comment

begin_define
define|#
directive|define
name|AM_SAF
value|6
end_define

begin_comment
comment|/* w6 - sync address field */
end_comment

begin_define
define|#
directive|define
name|AM_SFR
value|7
end_define

begin_comment
comment|/* w7 - sync flag register */
end_comment

begin_define
define|#
directive|define
name|AM_MICR
value|9
end_define

begin_comment
comment|/* w9 - master interrupt control reg */
end_comment

begin_define
define|#
directive|define
name|AM_MCR
value|10
end_define

begin_comment
comment|/* w10 - misc control register */
end_comment

begin_define
define|#
directive|define
name|AM_CMR
value|11
end_define

begin_comment
comment|/* w11 - clock mode register */
end_comment

begin_define
define|#
directive|define
name|AM_BCR
value|14
end_define

begin_comment
comment|/* w14 - baud rate control register */
end_comment

begin_comment
comment|/*  * Read only registers.  */
end_comment

begin_define
define|#
directive|define
name|AM_SR
value|0
end_define

begin_comment
comment|/* r0 - status register */
end_comment

begin_define
define|#
directive|define
name|AM_RSR
value|1
end_define

begin_comment
comment|/* r1 - receive status register */
end_comment

begin_define
define|#
directive|define
name|AM_IPR
value|3
end_define

begin_comment
comment|/* r3 - interrupt pending register */
end_comment

begin_define
define|#
directive|define
name|AM_MSR
value|10
end_define

begin_comment
comment|/* r10 - misc status register */
end_comment

begin_comment
comment|/*  * Enhanced mode registers.  * In enhanced mode registers PMR(w4), TCR(w5) become readable.  */
end_comment

begin_define
define|#
directive|define
name|AM_FBCL
value|6
end_define

begin_comment
comment|/* r6 - frame byte count low */
end_comment

begin_define
define|#
directive|define
name|AM_FBCH
value|7
end_define

begin_comment
comment|/* r7 - frame byte count high */
end_comment

begin_define
define|#
directive|define
name|AM_RCR_R
value|9
end_define

begin_comment
comment|/* r9 - read RCR(w3) */
end_comment

begin_define
define|#
directive|define
name|AM_MCR_R
value|11
end_define

begin_comment
comment|/* r11 - read MCR(w10) */
end_comment

begin_define
define|#
directive|define
name|AM_SFR_R
value|14
end_define

begin_comment
comment|/* r14 - read SFR(w7') */
end_comment

begin_define
define|#
directive|define
name|AM_A
value|32
end_define

begin_comment
comment|/* channel A offset */
end_comment

begin_comment
comment|/*  * Interrupt vector register  */
end_comment

begin_define
define|#
directive|define
name|IVR_A
value|0x08
end_define

begin_comment
comment|/* channel A status */
end_comment

begin_define
define|#
directive|define
name|IVR_REASON
value|0x06
end_define

begin_comment
comment|/* interrupt reason mask */
end_comment

begin_define
define|#
directive|define
name|IVR_TXRDY
value|0x00
end_define

begin_comment
comment|/* transmit buffer empty */
end_comment

begin_define
define|#
directive|define
name|IVR_STATUS
value|0x02
end_define

begin_comment
comment|/* external status interrupt */
end_comment

begin_define
define|#
directive|define
name|IVR_RX
value|0x04
end_define

begin_comment
comment|/* receive character available */
end_comment

begin_define
define|#
directive|define
name|IVR_RXERR
value|0x06
end_define

begin_comment
comment|/* special receive condition */
end_comment

begin_comment
comment|/*  * Interrupt mask register  */
end_comment

begin_define
define|#
directive|define
name|IMR_EXT
value|0x01
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_TX
value|0x02
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_PARITY
value|0x04
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RX_FIRST
value|0x08
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RX_ALL
value|0x10
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_RX_ERR
value|0x18
end_define

begin_comment
comment|/* ext interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IMR_WD_RX
value|0x20
end_define

begin_comment
comment|/* wait/request follows receiver fifo */
end_comment

begin_define
define|#
directive|define
name|IMR_WD_REQ
value|0x40
end_define

begin_comment
comment|/* wait/request function as request */
end_comment

begin_define
define|#
directive|define
name|IMR_WD_ENABLE
value|0x80
end_define

begin_comment
comment|/* wait/request pin enable */
end_comment

begin_comment
comment|/*  * Master interrupt control register  */
end_comment

begin_define
define|#
directive|define
name|MICR_VIS
value|0x01
end_define

begin_comment
comment|/* vector includes status */
end_comment

begin_define
define|#
directive|define
name|MICR_NV
value|0x02
end_define

begin_comment
comment|/* no interrupt vector */
end_comment

begin_define
define|#
directive|define
name|MICR_DLC
value|0x04
end_define

begin_comment
comment|/* disable lower chain */
end_comment

begin_define
define|#
directive|define
name|MICR_MIE
value|0x08
end_define

begin_comment
comment|/* master interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MICR_HIGH
value|0x10
end_define

begin_comment
comment|/* status high */
end_comment

begin_define
define|#
directive|define
name|MICR_NINTACK
value|0x20
end_define

begin_comment
comment|/* interrupt masking without INTACK */
end_comment

begin_define
define|#
directive|define
name|MICR_RESET_A
value|0x80
end_define

begin_comment
comment|/* channel reset A */
end_comment

begin_define
define|#
directive|define
name|MICR_RESET_B
value|0x40
end_define

begin_comment
comment|/* channel reset B */
end_comment

begin_define
define|#
directive|define
name|MICR_RESET_HW
value|0xc0
end_define

begin_comment
comment|/* force hardware reset */
end_comment

begin_comment
comment|/*  * Receive status register  */
end_comment

begin_define
define|#
directive|define
name|RSR_FRME
value|0x10
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|RSR_RXOVRN
value|0x20
end_define

begin_comment
comment|/* rx overrun error */
end_comment

begin_comment
comment|/*  * Command register  */
end_comment

begin_define
define|#
directive|define
name|CR_RST_EXTINT
value|0x10
end_define

begin_comment
comment|/* reset external/status irq */
end_comment

begin_define
define|#
directive|define
name|CR_TX_ABORT
value|0x18
end_define

begin_comment
comment|/* send abort (SDLC) */
end_comment

begin_define
define|#
directive|define
name|CR_RX_NXTINT
value|0x20
end_define

begin_comment
comment|/* enable irq on next rx character */
end_comment

begin_define
define|#
directive|define
name|CR_RST_TXINT
value|0x28
end_define

begin_comment
comment|/* reset tx irq pending */
end_comment

begin_define
define|#
directive|define
name|CR_RST_ERROR
value|0x30
end_define

begin_comment
comment|/* error reset */
end_comment

begin_define
define|#
directive|define
name|CR_RST_HIUS
value|0x38
end_define

begin_comment
comment|/* reset highest irq under service */
end_comment

end_unit

