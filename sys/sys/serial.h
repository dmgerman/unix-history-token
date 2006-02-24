begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This file contains definitions which pertain to serial ports as such,  * (both async and sync), but which do not necessarily have anything to  * do with tty processing.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SERIAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SERIAL_H_
end_define

begin_comment
comment|/*  * Indentification of modem control signals.  These definitions match  * the TIOCMGET definitions in<sys/ttycom.h> shifted a bit down, and  * that identity is enforced with CTASSERT at the bottom of kern/tty.c  * Both the modem bits and delta bits must fit in 16 bit.  */
end_comment

begin_define
define|#
directive|define
name|SER_DTR
value|0x0001
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|SER_RTS
value|0x0002
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|SER_STX
value|0x0004
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|SER_SRX
value|0x0008
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|SER_CTS
value|0x0010
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|SER_DCD
value|0x0020
end_define

begin_comment
comment|/* data carrier detect */
end_comment

begin_define
define|#
directive|define
name|SER_RI
value|0x0040
end_define

begin_comment
comment|/* ring indicate */
end_comment

begin_define
define|#
directive|define
name|SER_DSR
value|0x0080
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_define
define|#
directive|define
name|SER_MASK_STATE
value|0x00ff
end_define

begin_comment
comment|/* Delta bits, used to indicate which signals should/was affected */
end_comment

begin_define
define|#
directive|define
name|SER_DELTA
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SER_DDTR
value|SER_DELTA(SER_DTR)
end_define

begin_define
define|#
directive|define
name|SER_DRTS
value|SER_DELTA(SER_RTS)
end_define

begin_define
define|#
directive|define
name|SER_DSTX
value|SER_DELTA(SER_STX)
end_define

begin_define
define|#
directive|define
name|SER_DSRX
value|SER_DELTA(SER_SRX)
end_define

begin_define
define|#
directive|define
name|SER_DCTS
value|SER_DELTA(SER_CTS)
end_define

begin_define
define|#
directive|define
name|SER_DDCD
value|SER_DELTA(SER_DCD)
end_define

begin_define
define|#
directive|define
name|SER_DRI
value|SER_DELTA(SER_RI)
end_define

begin_define
define|#
directive|define
name|SER_DDSR
value|SER_DELTA(SER_DSR)
end_define

begin_define
define|#
directive|define
name|SER_MASK_DELTA
value|SER_DELTA(SER_MASK_STATE)
end_define

begin_comment
comment|/*  * Specification of interrupt sources typical for serial ports. These are  * useful when some umbrella driver like scc(4) has enough knowledge of  * the hardware to obtain the set of pending interrupts but does not itself  * handle the interrupt. Each interrupt source can be given an interrupt  * resource for which inferior drivers can install handlers. The lower 16  * bits are kept free for the signals above.  */
end_comment

begin_define
define|#
directive|define
name|SER_INT_OVERRUN
value|0x010000
end_define

begin_define
define|#
directive|define
name|SER_INT_BREAK
value|0x020000
end_define

begin_define
define|#
directive|define
name|SER_INT_RXREADY
value|0x040000
end_define

begin_define
define|#
directive|define
name|SER_INT_SIGCHG
value|0x080000
end_define

begin_define
define|#
directive|define
name|SER_INT_TXIDLE
value|0x100000
end_define

begin_define
define|#
directive|define
name|SER_INT_MASK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|SER_INT_SIGMASK
value|(SER_MASK_DELTA | SER_MASK_STATE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SERIAL_H_ */
end_comment

end_unit

