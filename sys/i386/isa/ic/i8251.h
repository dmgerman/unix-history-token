begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ns16550.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * modified for PC9801 by M.Ishii   *			Kyoto University Microcomputer Club (KMC)  */
end_comment

begin_comment
comment|/*  * modified for 8251(FIFO) by Seigo TANIMURA<tanimura@FreeBSD.org>  */
end_comment

begin_comment
comment|/* define command and status code */
end_comment

begin_define
define|#
directive|define
name|CMD8251_TxEN
value|0x01
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|CMD8251_DTR
value|0x02
end_define

begin_comment
comment|/* assert DTR */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RxEN
value|0x04
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_define
define|#
directive|define
name|CMD8251_SBRK
value|0x08
end_define

begin_comment
comment|/* send break */
end_comment

begin_define
define|#
directive|define
name|CMD8251_ER
value|0x10
end_define

begin_comment
comment|/* error reset */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RTS
value|0x20
end_define

begin_comment
comment|/* assert RTS */
end_comment

begin_define
define|#
directive|define
name|CMD8251_RESET
value|0x40
end_define

begin_comment
comment|/* internal reset */
end_comment

begin_define
define|#
directive|define
name|CMD8251_EH
value|0x80
end_define

begin_comment
comment|/* enter hunt mode (only synchronous mode)*/
end_comment

begin_define
define|#
directive|define
name|STS8251_TxRDY
value|0x01
end_define

begin_comment
comment|/* transmit READY */
end_comment

begin_define
define|#
directive|define
name|STS8251_RxRDY
value|0x02
end_define

begin_comment
comment|/* data exists in receive buffer */
end_comment

begin_define
define|#
directive|define
name|STS8251_TxEMP
value|0x04
end_define

begin_comment
comment|/* transmit buffer EMPTY */
end_comment

begin_define
define|#
directive|define
name|STS8251_PE
value|0x08
end_define

begin_comment
comment|/* perity error */
end_comment

begin_define
define|#
directive|define
name|STS8251_OE
value|0x10
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|STS8251_FE
value|0x20
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|STS8251_BD_SD
value|0x40
end_define

begin_comment
comment|/* break detect (async) / sync detect (sync) */
end_comment

begin_define
define|#
directive|define
name|STS8251_DSR
value|0x80
end_define

begin_comment
comment|/* DSR is asserted */
end_comment

begin_define
define|#
directive|define
name|STS8251F_TxEMP
value|0x01
end_define

begin_comment
comment|/* transmit buffer EMPTY */
end_comment

begin_define
define|#
directive|define
name|STS8251F_TxRDY
value|0x02
end_define

begin_comment
comment|/* transmit READY */
end_comment

begin_define
define|#
directive|define
name|STS8251F_RxRDY
value|0x04
end_define

begin_comment
comment|/* data exists in receive buffer */
end_comment

begin_define
define|#
directive|define
name|STS8251F_OE
value|0x10
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|STS8251F_PE
value|0x20
end_define

begin_comment
comment|/* perity error */
end_comment

begin_define
define|#
directive|define
name|STS8251F_BD_SD
value|0x80
end_define

begin_comment
comment|/* break detect (async) / sync detect (sync) */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_DTCT
value|0x60
end_define

begin_comment
comment|/* FIFO detection mask */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_INTRV
value|0x0e
end_define

begin_comment
comment|/* interrupt event */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_TO
value|0x0c
end_define

begin_comment
comment|/* receive timeout */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_LSTS
value|0x06
end_define

begin_comment
comment|/* line status */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_RxRDY
value|0x04
end_define

begin_comment
comment|/* receive READY */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_TxRDY
value|0x02
end_define

begin_comment
comment|/* transmit READY */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_ISEV
value|0x01
end_define

begin_comment
comment|/* event occured */
end_comment

begin_define
define|#
directive|define
name|INTR8251F_MSTS
value|0x00
end_define

begin_comment
comment|/* modem status */
end_comment

begin_define
define|#
directive|define
name|CTRL8251F_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable FIFO */
end_comment

begin_define
define|#
directive|define
name|CTRL8251F_RCV_RST
value|0x02
end_define

begin_comment
comment|/* reset receive FIFO */
end_comment

begin_define
define|#
directive|define
name|CTRL8251F_XMT_RST
value|0x04
end_define

begin_comment
comment|/* reset transmit FIFO */
end_comment

begin_define
define|#
directive|define
name|MOD8251_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|MOD8251_6BITS
value|0x04
end_define

begin_define
define|#
directive|define
name|MOD8251_7BITS
value|0x08
end_define

begin_define
define|#
directive|define
name|MOD8251_8BITS
value|0x0c
end_define

begin_define
define|#
directive|define
name|MOD8251_PDISAB
value|0x00
end_define

begin_comment
comment|/* parity disable */
end_comment

begin_define
define|#
directive|define
name|MOD8251_PODD
value|0x10
end_define

begin_comment
comment|/* parity odd */
end_comment

begin_define
define|#
directive|define
name|MOD8251_PEVEN
value|0x30
end_define

begin_comment
comment|/* parity even */
end_comment

begin_define
define|#
directive|define
name|MOD8251_STOP1
value|0x40
end_define

begin_comment
comment|/* stop bit len = 1bit */
end_comment

begin_define
define|#
directive|define
name|MOD8251_STOP2
value|0xc0
end_define

begin_comment
comment|/* stop bit len = 2bit */
end_comment

begin_define
define|#
directive|define
name|MOD8251_CLKX16
value|0x02
end_define

begin_comment
comment|/* x16 */
end_comment

begin_define
define|#
directive|define
name|MOD8251_CLKX1
value|0x01
end_define

begin_comment
comment|/* x1 */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CD
value|0x20
end_define

begin_comment
comment|/* CD */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CS
value|0x40
end_define

begin_comment
comment|/* CS */
end_comment

begin_define
define|#
directive|define
name|CICSCD_CI
value|0x80
end_define

begin_comment
comment|/* CI */
end_comment

begin_define
define|#
directive|define
name|CICSCDF_CS
value|0x10
end_define

begin_comment
comment|/* CS */
end_comment

begin_define
define|#
directive|define
name|CICSCDF_DR
value|0x20
end_define

begin_comment
comment|/* DR */
end_comment

begin_define
define|#
directive|define
name|CICSCDF_CI
value|0x40
end_define

begin_comment
comment|/* CI */
end_comment

begin_define
define|#
directive|define
name|CICSCDF_CD
value|0x80
end_define

begin_comment
comment|/* CD */
end_comment

begin_comment
comment|/* interrupt mask control */
end_comment

begin_define
define|#
directive|define
name|IEN_Rx
value|0x01
end_define

begin_define
define|#
directive|define
name|IEN_TxEMP
value|0x02
end_define

begin_define
define|#
directive|define
name|IEN_Tx
value|0x04
end_define

end_unit

