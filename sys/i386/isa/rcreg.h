begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995 by Pavel Antonov, Moscow, Russia.  * Copyright (C) 1995 by Andrey A. Chernov, Moscow, Russia.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Cirrus Logic CD180 -based RISCom/8 board definitions  */
end_comment

begin_comment
comment|/* Oscillator frequency - 19660.08Mhz / 2 */
end_comment

begin_define
define|#
directive|define
name|RC_OSCFREQ
value|9830400
end_define

begin_define
define|#
directive|define
name|RC_BRD
parameter_list|(
name|s
parameter_list|)
value|((s) == 0 ? 0 : \ 	(((RC_OSCFREQ + (s) / 2) / (s)) + CD180_CTICKS/2) / CD180_CTICKS)
end_define

begin_define
define|#
directive|define
name|RC_VALIDADDR
parameter_list|(
name|a
parameter_list|)
value|(   (a) == 0x220 || (a) == 0x240 || (a) == 0x250 \ 			 || (a) == 0x260 || (a) == 0x2A0 || (a) == 0x2B0 \ 			 || (a) == 0x300 || (a) == 0x320)
end_define

begin_define
define|#
directive|define
name|RC_VALIDIRQ
parameter_list|(
name|i
parameter_list|)
value|((i)< 16&& \ 			 "\0\0\0\1\1\1\0\1\0\0\1\1\1\0\0\1"[(i)& 0xF])
end_define

begin_comment
comment|/* Riscom/8 board ISA I/O mapping */
end_comment

begin_define
define|#
directive|define
name|RC_IOMAP
parameter_list|(
name|r
parameter_list|)
value|((((r)& 07)<< 1) | (((r)& ~07)<< 7))
end_define

begin_comment
comment|/* I/O commands */
end_comment

begin_define
define|#
directive|define
name|RC_OUT
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|,
name|d
parameter_list|)
value|outb(RC_IOMAP(i) + (p), (d))
end_define

begin_define
define|#
directive|define
name|RC_IN
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|inb (RC_IOMAP(i) + (p))
end_define

begin_comment
comment|/* Riscom on-board registers (mapping assumed) */
end_comment

begin_define
define|#
directive|define
name|RC_RIREG
value|0x100
end_define

begin_comment
comment|/* Ring Indicator Register (read-only)  */
end_comment

begin_define
define|#
directive|define
name|RC_DTREG
value|0x100
end_define

begin_comment
comment|/* DTR Register (write-only)            */
end_comment

begin_define
define|#
directive|define
name|RC_BSR
value|0x101
end_define

begin_comment
comment|/* Board Status Register (read-only)    */
end_comment

begin_define
define|#
directive|define
name|RC_CTOUT
value|0x101
end_define

begin_comment
comment|/* Clear Timeout (write-only)           */
end_comment

begin_comment
comment|/* Board Status Register */
end_comment

begin_define
define|#
directive|define
name|RC_BSR_TOUT
value|0x08
end_define

begin_comment
comment|/* Timeout                              */
end_comment

begin_define
define|#
directive|define
name|RC_BSR_RXINT
value|0x04
end_define

begin_comment
comment|/* Receiver Interrupt                   */
end_comment

begin_define
define|#
directive|define
name|RC_BSR_TXINT
value|0x02
end_define

begin_comment
comment|/* Transmitter Interrupt                */
end_comment

begin_define
define|#
directive|define
name|RC_BSR_MOINT
value|0x01
end_define

begin_comment
comment|/* Modem Control Interrupt              */
end_comment

begin_comment
comment|/* Interrupt groups */
end_comment

begin_define
define|#
directive|define
name|RC_MODEMGRP
value|0x01
end_define

begin_comment
comment|/* Modem interrupt group                */
end_comment

begin_define
define|#
directive|define
name|RC_RXGRP
value|0x02
end_define

begin_comment
comment|/* Receiver interrupt group             */
end_comment

begin_define
define|#
directive|define
name|RC_TXGRP
value|0x04
end_define

begin_comment
comment|/* Transmitter interrupt group          */
end_comment

begin_comment
comment|/* Priority Interrupt Level definitions */
end_comment

begin_define
define|#
directive|define
name|RC_PILR_MODEM
value|(0x80 | RC_MODEMGRP)
end_define

begin_define
define|#
directive|define
name|RC_PILR_RX
value|(0x80 | RC_RXGRP   )
end_define

begin_define
define|#
directive|define
name|RC_PILR_TX
value|(0x80 | RC_TXGRP   )
end_define

end_unit

