begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 TAKAHASHI Yoshihiro. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The outputs of the three timers are connected as follows:  *  *	 timer 0 -> irq 0  *	 timer 1 -> dma chan 0 (for dram refresh)  * 	 timer 2 -> speaker (via keyboard controller)  *  * Timer 0 is used to call hardclock.  * Timer 2 is used to generate console beeps.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TIMERREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TIMERREG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<dev/ic/i8253reg.h>
end_include

begin_define
define|#
directive|define
name|IO_TIMER1
value|0x40
end_define

begin_comment
comment|/* 8253 Timer #1 */
end_comment

begin_define
define|#
directive|define
name|TIMER_CNTR0
value|(IO_TIMER1 + TIMER_REG_CNTR0)
end_define

begin_define
define|#
directive|define
name|TIMER_CNTR1
value|(IO_TIMER1 + TIMER_REG_CNTR1)
end_define

begin_define
define|#
directive|define
name|TIMER_CNTR2
value|(IO_TIMER1 + TIMER_REG_CNTR2)
end_define

begin_define
define|#
directive|define
name|TIMER_MODE
value|(IO_TIMER1 + TIMER_REG_MODE)
end_define

begin_define
define|#
directive|define
name|timer_spkr_acquire
parameter_list|()
define|\
value|acquire_timer2(TIMER_SEL2 | TIMER_SQWAVE | TIMER_16BIT)
end_define

begin_define
define|#
directive|define
name|timer_spkr_release
parameter_list|()
define|\
value|release_timer2()
end_define

begin_function
specifier|static
name|__inline
name|void
name|spkr_set_pitch
parameter_list|(
name|u_int16_t
name|pitch
parameter_list|)
block|{
name|outb
argument_list|(
name|TIMER_CNTR2
argument_list|,
name|pitch
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TIMER_CNTR2
argument_list|,
name|pitch
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TIMERREG_H_ */
end_comment

end_unit

