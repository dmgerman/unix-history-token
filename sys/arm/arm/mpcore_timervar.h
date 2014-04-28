begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_MPCORE_TIMERVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_MPCORE_TIMERVAR_H_
end_define

begin_comment
comment|/*  * This value, passed to arm_tmr_change_frequency() any time before the mpcore  * timer device attaches, informs the driver that the mpcore clock frequency can  * change on the fly, and thus can't be used as a timecounter.  The hardware can  * still be used as an eventtimer, as long as each frequency change is  * communicated to it with calls to arm_tmr_change_frequency().  */
end_comment

begin_define
define|#
directive|define
name|ARM_TMR_FREQUENCY_VARIES
value|-1ULL
end_define

begin_comment
comment|/*  * Inform the mpcore timer driver of a new clock frequency.  This can be called  * both before and after the mpcore timer driver attaches.  */
end_comment

begin_function_decl
name|void
name|arm_tmr_change_frequency
parameter_list|(
name|uint64_t
name|newfreq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

