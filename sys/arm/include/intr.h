begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$NetBSD: intr.h,v 1.7 2003/06/16 20:01:00 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe  *	for the NetBSD Project.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_H_
end_define

begin_comment
comment|/* Define the various Interrupt Priority Levels */
end_comment

begin_comment
comment|/* Hardware Interrupt Priority Levels are not mutually exclusive. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SA1110
end_ifdef

begin_define
define|#
directive|define
name|IPL_SOFTCLOCK
value|0
end_define

begin_define
define|#
directive|define
name|IPL_SOFTNET
value|1
end_define

begin_define
define|#
directive|define
name|IPL_BIO
value|2
end_define

begin_comment
comment|/* block I/O */
end_comment

begin_define
define|#
directive|define
name|IPL_NET
value|3
end_define

begin_comment
comment|/* network */
end_comment

begin_define
define|#
directive|define
name|IPL_SOFTSERIAL
value|4
end_define

begin_define
define|#
directive|define
name|IPL_TTY
value|5
end_define

begin_comment
comment|/* terminal */
end_comment

begin_define
define|#
directive|define
name|IPL_VM
value|6
end_define

begin_comment
comment|/* memory allocation */
end_comment

begin_define
define|#
directive|define
name|IPL_AUDIO
value|7
end_define

begin_comment
comment|/* audio */
end_comment

begin_define
define|#
directive|define
name|IPL_CLOCK
value|8
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|IPL_HIGH
value|9
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|IPL_SERIAL
value|10
end_define

begin_comment
comment|/* serial */
end_comment

begin_define
define|#
directive|define
name|IPL_NONE
value|11
end_define

begin_define
define|#
directive|define
name|NIPL
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IST_UNUSABLE
value|-1
end_define

begin_comment
comment|/* interrupt cannot be used */
end_comment

begin_define
define|#
directive|define
name|IST_NONE
value|0
end_define

begin_comment
comment|/* none (dummy) */
end_comment

begin_define
define|#
directive|define
name|IST_PULSE
value|1
end_define

begin_comment
comment|/* pulsed */
end_comment

begin_define
define|#
directive|define
name|IST_EDGE
value|2
end_define

begin_comment
comment|/* edge-triggered */
end_comment

begin_define
define|#
directive|define
name|IST_LEVEL
value|3
end_define

begin_comment
comment|/* level-triggered */
end_comment

begin_comment
comment|/* Software interrupt priority levels */
end_comment

begin_define
define|#
directive|define
name|SOFTIRQ_CLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SOFTIRQ_NET
value|1
end_define

begin_define
define|#
directive|define
name|SOFTIRQ_SERIAL
value|2
end_define

begin_define
define|#
directive|define
name|SOFTIRQ_BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< x)
end_define

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_function_decl
name|void
name|set_splmasks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm_setup_irqhandler
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_INTR_H */
end_comment

end_unit

