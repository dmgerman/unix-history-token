begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz and Don Ahn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)clock.c	7.2 (Berkeley) 5/12/91  *	from NetBSD: Id: clock.c,v 1.6 1993/05/22 08:01:07 cgd Exp   *  *	@(#)clock.c	8.1 (Berkeley) 6/11/93  *  */
end_comment

begin_comment
comment|/*  * Primitive clock interrupt routines.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/rtc.h>
end_include

begin_comment
comment|/* these should go elsewere (timerreg.h) but to avoid admin overhead... */
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

begin_define
define|#
directive|define
name|DAYST
value|119
end_define

begin_define
define|#
directive|define
name|DAYEN
value|303
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|XTALSPEED
end_ifndef

begin_define
define|#
directive|define
name|XTALSPEED
value|1193182
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|startrtclock
argument_list|()
end_macro

begin_block
block|{
name|int
name|s
decl_stmt|;
name|findcpuspeed
argument_list|()
expr_stmt|;
comment|/* use the clock (while it's free) 					to find the cpu speed */
comment|/* initialize 8253 clock */
name|outb
argument_list|(
name|TIMER_MODE
argument_list|,
name|TIMER_SEL0
operator||
name|TIMER_RATEGEN
operator||
name|TIMER_16BIT
argument_list|)
expr_stmt|;
comment|/* Correct rounding will buy us a better precision in timekeeping */
name|outb
argument_list|(
name|IO_TIMER1
argument_list|,
operator|(
name|XTALSPEED
operator|+
name|hz
operator|/
literal|2
operator|)
operator|/
name|hz
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_TIMER1
argument_list|,
operator|(
operator|(
name|XTALSPEED
operator|+
name|hz
operator|/
literal|2
operator|)
operator|/
name|hz
operator|)
operator|/
literal|256
argument_list|)
expr_stmt|;
comment|/* initialize brain-dead battery powered clock */
name|outb
argument_list|(
name|IO_RTC
argument_list|,
name|RTC_STATUSA
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|,
literal|0x26
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
name|RTC_STATUSB
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
name|RTC_DIAG
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|=
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"RTC BIOS diagnostic error %b\n"
argument_list|,
name|s
argument_list|,
name|RTCDG_BITS
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
name|RTC_DIAG
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|unsigned
name|int
name|delaycount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calibrated loop variable (1 millisecond) */
end_comment

begin_define
define|#
directive|define
name|FIRST_GUESS
value|0x2000
end_define

begin_macro
name|findcpuspeed
argument_list|()
end_macro

begin_block
block|{
name|unsigned
name|char
name|low
decl_stmt|;
name|unsigned
name|int
name|remainder
decl_stmt|;
comment|/* Put counter in count down mode */
name|outb
argument_list|(
name|IO_TIMER1
operator|+
literal|3
argument_list|,
literal|0x34
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_TIMER1
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_TIMER1
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
name|delaycount
operator|=
name|FIRST_GUESS
expr_stmt|;
name|spinwait
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Read the value left in the counter */
name|low
operator|=
name|inb
argument_list|(
name|IO_TIMER1
argument_list|)
expr_stmt|;
comment|/* least siginifcant */
name|remainder
operator|=
name|inb
argument_list|(
name|IO_TIMER1
argument_list|)
expr_stmt|;
comment|/* most significant */
name|remainder
operator|=
operator|(
name|remainder
operator|<<
literal|8
operator|)
operator|+
name|low
expr_stmt|;
comment|/* Formula for delaycount is : 	 *  (loopcount * timer clock speed)/ (counter ticks * 1000) 	 */
name|delaycount
operator|=
operator|(
name|FIRST_GUESS
operator|*
operator|(
name|XTALSPEED
operator|/
literal|1000
operator|)
operator|)
operator|/
operator|(
literal|0xffff
operator|-
name|remainder
operator|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* convert 2 digit BCD number */
end_comment

begin_macro
name|bcd
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|i
operator|/
literal|16
operator|)
operator|*
literal|10
operator|+
operator|(
name|i
operator|%
literal|16
operator|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* convert years to seconds (from 1970) */
end_comment

begin_function
name|unsigned
name|long
name|ytos
parameter_list|(
name|y
parameter_list|)
name|int
name|y
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|long
name|ret
decl_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1970
init|;
name|i
operator|<
name|y
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|%
literal|4
condition|)
name|ret
operator|+=
literal|365
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
else|else
name|ret
operator|+=
literal|366
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* convert months to seconds */
end_comment

begin_function
name|unsigned
name|long
name|mtos
parameter_list|(
name|m
parameter_list|,
name|leap
parameter_list|)
name|int
name|m
decl_stmt|,
name|leap
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|long
name|ret
decl_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|m
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|3
case|:
case|case
literal|5
case|:
case|case
literal|7
case|:
case|case
literal|8
case|:
case|case
literal|10
case|:
case|case
literal|12
case|:
name|ret
operator|+=
literal|31
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
break|break;
case|case
literal|4
case|:
case|case
literal|6
case|:
case|case
literal|9
case|:
case|case
literal|11
case|:
name|ret
operator|+=
literal|30
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|leap
condition|)
name|ret
operator|+=
literal|29
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
else|else
name|ret
operator|+=
literal|28
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/*  * Initialize the time of day register, based on the time base which is, e.g.  * from a filesystem.  */
end_comment

begin_macro
name|inittodr
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|long
name|sec
decl_stmt|;
name|int
name|leap
decl_stmt|,
name|day_week
decl_stmt|,
name|t
decl_stmt|,
name|yd
decl_stmt|;
name|int
name|sa
decl_stmt|,
name|s
decl_stmt|;
comment|/* do we have a realtime clock present? (otherwise we loop below) */
name|sa
operator|=
name|rtcin
argument_list|(
name|RTC_STATUSA
argument_list|)
expr_stmt|;
if|if
condition|(
name|sa
operator|==
literal|0xff
operator|||
name|sa
operator|==
literal|0
condition|)
return|return;
comment|/* ready for a read? */
while|while
condition|(
operator|(
name|sa
operator|&
name|RTCSA_TUP
operator|)
operator|==
name|RTCSA_TUP
condition|)
name|sa
operator|=
name|rtcin
argument_list|(
name|RTC_STATUSA
argument_list|)
expr_stmt|;
name|sec
operator|=
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_YEAR
argument_list|)
argument_list|)
operator|+
literal|1900
expr_stmt|;
if|if
condition|(
name|sec
operator|<
literal|1970
condition|)
name|sec
operator|+=
literal|100
expr_stmt|;
name|leap
operator|=
operator|!
operator|(
name|sec
operator|%
literal|4
operator|)
expr_stmt|;
name|sec
operator|=
name|ytos
argument_list|(
name|sec
argument_list|)
expr_stmt|;
comment|/* year    */
name|yd
operator|=
name|mtos
argument_list|(
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_MONTH
argument_list|)
argument_list|)
argument_list|,
name|leap
argument_list|)
expr_stmt|;
name|sec
operator|+=
name|yd
expr_stmt|;
comment|/* month   */
name|t
operator|=
operator|(
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_DAY
argument_list|)
argument_list|)
operator|-
literal|1
operator|)
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
name|sec
operator|+=
name|t
expr_stmt|;
name|yd
operator|+=
name|t
expr_stmt|;
comment|/* date    */
name|day_week
operator|=
name|rtcin
argument_list|(
name|RTC_WDAY
argument_list|)
expr_stmt|;
comment|/* day     */
name|sec
operator|+=
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_HRS
argument_list|)
argument_list|)
operator|*
literal|60
operator|*
literal|60
expr_stmt|;
comment|/* hour    */
name|sec
operator|+=
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_MIN
argument_list|)
argument_list|)
operator|*
literal|60
expr_stmt|;
comment|/* minutes */
name|sec
operator|+=
name|bcd
argument_list|(
name|rtcin
argument_list|(
name|RTC_SEC
argument_list|)
argument_list|)
expr_stmt|;
comment|/* seconds */
comment|/* XXX off by one? Need to calculate DST on SUNDAY */
comment|/* Perhaps we should have the RTC hold GMT time to save */
comment|/* us the bother of converting. */
name|yd
operator|=
name|yd
operator|/
operator|(
literal|24
operator|*
literal|60
operator|*
literal|60
operator|)
expr_stmt|;
if|if
condition|(
operator|(
name|yd
operator|>=
name|DAYST
operator|)
operator|&&
operator|(
name|yd
operator|<=
name|DAYEN
operator|)
condition|)
block|{
name|sec
operator|-=
literal|60
operator|*
literal|60
expr_stmt|;
block|}
name|sec
operator|+=
name|tz
operator|.
name|tz_minuteswest
operator|*
literal|60
expr_stmt|;
name|time
operator|.
name|tv_sec
operator|=
name|sec
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|garbage
end_ifdef

begin_comment
comment|/*  * Initialze the time of day register, based on the time base which is, e.g.  * from a filesystem.  */
end_comment

begin_macro
name|test_inittodr
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|9
argument_list|)
expr_stmt|;
comment|/* year    */
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|/* month   */
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|/* day     */
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* hour    */
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* minutes */
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_RTC
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* seconds */
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|bcd
argument_list|(
name|inb
argument_list|(
name|IO_RTC
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|time
operator|.
name|tv_sec
operator|=
name|base
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Restart the clock.  */
end_comment

begin_macro
name|resettodr
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/*  * Wire clock interrupt in.  */
end_comment

begin_define
define|#
directive|define
name|V
parameter_list|(
name|s
parameter_list|)
value|__CONCAT(V, s)
end_define

begin_function_decl
specifier|extern
name|V
function_decl|(
name|clk
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|enablertclock
argument_list|()
end_macro

begin_block
block|{
name|INTREN
argument_list|(
name|IRQ0
argument_list|)
expr_stmt|;
name|setidt
argument_list|(
name|ICU_OFFSET
operator|+
literal|0
argument_list|,
operator|&
name|V
argument_list|(
name|clk
argument_list|)
argument_list|,
name|SDT_SYS386IGT
argument_list|,
name|SEL_KPL
argument_list|)
expr_stmt|;
name|splnone
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|spinwait
argument_list|(
argument|millisecs
argument_list|)
end_macro

begin_decl_stmt
name|int
name|millisecs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of milliseconds to delay */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|millisecs
condition|;
name|i
operator|++
control|)
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|delaycount
condition|;
name|j
operator|++
control|)
empty_stmt|;
block|}
end_block

end_unit

