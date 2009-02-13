begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 TAKAHASHI Yoshihiro. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The outputs of the three timers are connected as follows:  *  *	 timer 0 -> irq 0  *	 timer 1 -> speaker (via keyboard controller)  * 	 timer 2 -> RS-232C  *  * Timer 0 is used to call hardclock.  * Timer 1 is used to generate console beeps.  */
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
value|0x71
end_define

begin_comment
comment|/* 8253C Timer */
end_comment

begin_define
define|#
directive|define
name|TIMER_CNTR0
value|(IO_TIMER1 + TIMER_REG_CNTR0 * 2)
end_define

begin_define
define|#
directive|define
name|TIMER_CNTR1
value|0x3fdb
end_define

begin_define
define|#
directive|define
name|TIMER_CNTR2
value|(IO_TIMER1 + TIMER_REG_CNTR2 * 2)
end_define

begin_define
define|#
directive|define
name|TIMER_MODE
value|(IO_TIMER1 + TIMER_REG_MODE * 2)
end_define

begin_define
define|#
directive|define
name|timer_spkr_acquire
parameter_list|()
define|\
value|acquire_timer1(TIMER_SEL1 | TIMER_SQWAVE | TIMER_16BIT)
end_define

begin_define
define|#
directive|define
name|timer_spkr_release
parameter_list|()
define|\
value|release_timer1()
end_define

begin_define
define|#
directive|define
name|spkr_set_pitch
parameter_list|(
name|pitch
parameter_list|)
define|\
value|do { \ 		outb(TIMER_CNTR1, (pitch)& 0xff); \ 		outb(TIMER_CNTR1, (pitch)>> 8); \ 	} while(0)
end_define

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

