begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Header: timerreg.h,v 1.2 93/02/28 15:08:58 mccanne Exp  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  * Register definitions for the Intel 8253 Programmable Interval Timer.  *  * This chip has three independent 16-bit down counters that can be  * read on the fly.  There are three mode registers and three countdown  * registers.  The countdown registers are addressed directly, via the  * first three I/O ports.  The three mode registers are accessed via  * the fourth I/O port, with two bits in the mode byte indicating the  * register.  (Why are hardware interfaces always so braindead?).  *  * To write a value into the countdown register, the mode register  * is first programmed with a command indicating the which byte of  * the two byte register is to be modified.  The three possibilities  * are load msb (TMR_MR_MSB), load lsb (TMR_MR_LSB), or load lsb then  * msb (TMR_MR_BOTH).  *  * To read the current value ("on the fly") from the countdown register,  * you write a "latch" command into the mode register, then read the stable  * value from the corresponding I/O port.  For example, you write  * TMR_MR_LATCH into the corresponding mode register.  Presumably,  * after doing this, a write operation to the I/O port would result  * in undefined behavior (but hopefully not fry the chip).  * Reading in this manner has no side effects.  *  * [IBM-PC]  * The outputs of the three timers are connected as follows:  *  *	 timer 0 -> irq 0  *	 timer 1 -> dma chan 0 (for dram refresh)  * 	 timer 2 -> speaker (via keyboard controller)  *  * Timer 0 is used to call hardclock.  * Timer 2 is used to generate console beeps.  *  * [PC-9801]  * The outputs of the three timers are connected as follows:  *  *	 timer 0 -> irq 0  *	 timer 1 -> speaker (via keyboard controller)  * 	 timer 2 -> RS232C  *  * Timer 0 is used to call hardclock.  * Timer 1 is used to generate console beeps.  */
end_comment

begin_comment
comment|/*  * Macros for specifying values to be written into a mode register.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_CNTR0
value|(IO_TIMER1 + 0)
end_define

begin_comment
comment|/* timer 0 counter port */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|TIMER_CNTR1
value|0x3fdb
end_define

begin_comment
comment|/* timer 1 counter port */
end_comment

begin_define
define|#
directive|define
name|TIMER_CNTR2
value|(IO_TIMER1 + 4)
end_define

begin_comment
comment|/* timer 2 counter port */
end_comment

begin_define
define|#
directive|define
name|TIMER_MODE
value|(IO_TIMER1 + 6)
end_define

begin_comment
comment|/* timer mode port */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIMER_CNTR1
value|(IO_TIMER1 + 1)
end_define

begin_comment
comment|/* timer 1 counter port */
end_comment

begin_define
define|#
directive|define
name|TIMER_CNTR2
value|(IO_TIMER1 + 2)
end_define

begin_comment
comment|/* timer 2 counter port */
end_comment

begin_define
define|#
directive|define
name|TIMER_MODE
value|(IO_TIMER1 + 3)
end_define

begin_comment
comment|/* timer mode port */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMER_SEL0
value|0x00
end_define

begin_comment
comment|/* select counter 0 */
end_comment

begin_define
define|#
directive|define
name|TIMER_SEL1
value|0x40
end_define

begin_comment
comment|/* select counter 1 */
end_comment

begin_define
define|#
directive|define
name|TIMER_SEL2
value|0x80
end_define

begin_comment
comment|/* select counter 2 */
end_comment

begin_define
define|#
directive|define
name|TIMER_INTTC
value|0x00
end_define

begin_comment
comment|/* mode 0, intr on terminal cnt */
end_comment

begin_define
define|#
directive|define
name|TIMER_ONESHOT
value|0x02
end_define

begin_comment
comment|/* mode 1, one shot */
end_comment

begin_define
define|#
directive|define
name|TIMER_RATEGEN
value|0x04
end_define

begin_comment
comment|/* mode 2, rate generator */
end_comment

begin_define
define|#
directive|define
name|TIMER_SQWAVE
value|0x06
end_define

begin_comment
comment|/* mode 3, square wave */
end_comment

begin_define
define|#
directive|define
name|TIMER_SWSTROBE
value|0x08
end_define

begin_comment
comment|/* mode 4, s/w triggered strobe */
end_comment

begin_define
define|#
directive|define
name|TIMER_HWSTROBE
value|0x0a
end_define

begin_comment
comment|/* mode 5, h/w triggered strobe */
end_comment

begin_define
define|#
directive|define
name|TIMER_LATCH
value|0x00
end_define

begin_comment
comment|/* latch counter for reading */
end_comment

begin_define
define|#
directive|define
name|TIMER_LSB
value|0x10
end_define

begin_comment
comment|/* r/w counter LSB */
end_comment

begin_define
define|#
directive|define
name|TIMER_MSB
value|0x20
end_define

begin_comment
comment|/* r/w counter MSB */
end_comment

begin_define
define|#
directive|define
name|TIMER_16BIT
value|0x30
end_define

begin_comment
comment|/* r/w counter 16 bits, LSB first */
end_comment

begin_define
define|#
directive|define
name|TIMER_BCD
value|0x01
end_define

begin_comment
comment|/* count in BCD */
end_comment

end_unit

